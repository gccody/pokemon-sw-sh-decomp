//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions
// are met:
//  * Redistributions of source code must retain the above copyright
//    notice, this list of conditions and the following disclaimer.
//  * Redistributions in binary form must reproduce the above copyright
//    notice, this list of conditions and the following disclaimer in the
//    documentation and/or other materials provided with the distribution.
//  * Neither the name of NVIDIA CORPORATION nor the names of its
//    contributors may be used to endorse or promote products derived
//    from this software without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS ``AS IS'' AND ANY
// EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
// PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT OWNER OR
// CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
// EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
// PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
// PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY
// OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
// OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//
// Copyright (c) 2008-2018 NVIDIA Corporation. All rights reserved.
// Copyright (c) 2004-2008 AGEIA Technologies, Inc. All rights reserved.
// Copyright (c) 2001-2004 NovodeX AG. All rights reserved.

// Pokemon SwSh decomp: PxFoundation's Nintendo Switch thread and TLS (not
// public), reconstructed from the binary. PsUnixThread.cpp's structure on
// nn::os threads: the thread object is the first member, the stack is
// allocated here (4 KiB aligned), and the priority, core mask and name are
// kept until the thread is started.

#include "foundation/PxAssert.h"
#include "foundation/PxErrorCallback.h"

#include "Ps.h"
#include "PsFoundation.h"
#include "PsAtomic.h"
#include "PsThread.h"
#include "PsAlignedMalloc.h"

#include <nn/os.h>

namespace physx
{
namespace shdfnd
{

namespace
{

typedef enum
{
	_PxThreadNotStarted,
	_PxThreadStarted,
	_PxThreadStopped
} PxThreadState;

class _ThreadImpl
{
  public:
	nn::os::ThreadType thread;
	const char* name;
	uint8_t field_1b0[0x10];
	void* stack;
	int32_t affinityMask; // -1: not set
	volatile int32_t quitNow;
	volatile int32_t state;
	ThreadImpl::ExecuteFn fn;
	void* arg;
};

typedef AlignedAllocator<4096, RawAllocator> StackAllocator;

_ThreadImpl* getThread(ThreadImpl* impl)
{
	return reinterpret_cast<_ThreadImpl*>(impl);
}

void PxThreadStart(void* arg)
{
	_ThreadImpl* impl = getThread(reinterpret_cast<ThreadImpl*>(arg));

	// run either the passed in function or execute from the derived class (Runnable).
	if(impl->fn)
		(*impl->fn)(impl->arg);
	else if(impl->arg)
		(reinterpret_cast<Runnable*>(impl->arg))->execute();
}
}

uint32_t ThreadImpl::getSize()
{
	return sizeof(_ThreadImpl);
}

ThreadImpl::Id ThreadImpl::getId()
{
	return Id(nn::os::GetCurrentThread());
}

ThreadImpl::ThreadImpl()
{
	getThread(this)->thread.field_44 = nn::os::DefaultThreadPriority;
	getThread(this)->name = NULL;
	getThread(this)->state = _PxThreadNotStarted;
	__atomic_store_n(&getThread(this)->quitNow, 0, __ATOMIC_SEQ_CST);
	getThread(this)->affinityMask = -1;
	getThread(this)->stack = NULL;
	getThread(this)->fn = NULL;
	getThread(this)->arg = NULL;
}

ThreadImpl::~ThreadImpl()
{
	if(getThread(this)->state != _PxThreadNotStarted && getThread(this)->stack)
	{
		nn::os::DestroyThread(&getThread(this)->thread);
		StackAllocator().deallocate(getThread(this)->stack);
	}
}

void ThreadImpl::start(uint32_t stackSize, Runnable* runnable)
{
	if(getThread(this)->state != _PxThreadNotStarted)
		return;
	getThread(this)->state = _PxThreadStarted;

	if(stackSize == 0)
		stackSize = getDefaultStackSize();

	void* stack = StackAllocator().allocate(stackSize, __FILE__, __LINE__);
	if(!stack)
		return;
	getThread(this)->stack = stack;

	if(runnable && !getThread(this)->arg && !getThread(this)->fn)
		getThread(this)->arg = runnable;

	if(!nn::os::CreateThread(&getThread(this)->thread, PxThreadStart, this, stack, stackSize,
	                         getThread(this)->thread.field_44).IsSuccess())
	{
		StackAllocator().deallocate(stack);
		getThread(this)->stack = NULL;
		return;
	}

	// apply the stored affinity mask, or allow every core
	const int32_t affinityMask = getThread(this)->affinityMask;
	nn::os::SetThreadCoreMask(&getThread(this)->thread, -1,
	                          affinityMask == -1 ? nn::os::GetThreadAvailableCoreMask() : uint64_t(affinityMask));
	if(getThread(this)->name)
		nn::os::SetThreadNamePointer(&getThread(this)->thread, getThread(this)->name);

	nn::os::StartThread(&getThread(this)->thread);
}

uint32_t ThreadImpl::getDefaultStackSize()
{
	return 0x80000;
}

void ThreadImpl::signalQuit()
{
	__sync_add_and_fetch(&getThread(this)->quitNow, 1);
}

bool ThreadImpl::waitForQuit()
{
	if(getThread(this)->state == _PxThreadNotStarted)
		return false;

	nn::os::WaitThread(&getThread(this)->thread);
	return true;
}

bool ThreadImpl::quitIsSignalled()
{
	return !__sync_bool_compare_and_swap(&getThread(this)->quitNow, 0, 0);
}

void ThreadImpl::quit()
{
	getThread(this)->state = _PxThreadStopped;
}

void ThreadImpl::sleep(uint32_t ms)
{
	nn::os::SleepThread(nn::TimeSpan{ int64_t(ms) * 1000000 });
}

void ThreadImpl::yield()
{
	nn::os::YieldThread();
}

uint32_t ThreadImpl::setAffinityMask(uint32_t mask)
{
	if(getThread(this)->state != _PxThreadNotStarted)
	{
		uint64_t prevMask;
		nn::os::GetThreadCoreMask(NULL, &prevMask, &getThread(this)->thread);
		nn::os::SetThreadCoreMask(&getThread(this)->thread, -1, mask);
		return uint32_t(prevMask);
	}

	const int32_t prevMask = getThread(this)->affinityMask;
	getThread(this)->affinityMask = int32_t(mask);
	return prevMask == -1 ? 0 : uint32_t(prevMask);
}

void ThreadImpl::setName(const char* name)
{
	if(getThread(this)->state == _PxThreadStarted)
		nn::os::SetThreadNamePointer(&getThread(this)->thread, name);
	else
		getThread(this)->name = name;
}

uint32_t TlsAlloc()
{
	nn::os::TlsSlot slot;
	if(!nn::os::AllocateTlsSlot(&slot, NULL).IsSuccess())
		return 0xFFFFFFFF;
	return slot.field_0;
}

void TlsFree(uint32_t index)
{
	nn::os::FreeTlsSlot(nn::os::TlsSlot{ index });
}

size_t TlsGetValue(uint32_t index)
{
	return nn::os::GetTlsValue(nn::os::TlsSlot{ index });
}

uint32_t TlsSetValue(uint32_t index, size_t value)
{
	nn::os::SetTlsValue(nn::os::TlsSlot{ index }, value);
	return 1;
}

// Layouts, as the binary uses them.
static_assert(sizeof(_ThreadImpl) == 0x1e8, "_ThreadImpl");
static_assert(offsetof(_ThreadImpl, name) == 0x1a8, "_ThreadImpl::name");
static_assert(offsetof(_ThreadImpl, stack) == 0x1c0, "_ThreadImpl::stack");
static_assert(offsetof(_ThreadImpl, affinityMask) == 0x1c8, "_ThreadImpl::affinityMask");
static_assert(offsetof(_ThreadImpl, quitNow) == 0x1cc, "_ThreadImpl::quitNow");
static_assert(offsetof(_ThreadImpl, state) == 0x1d0, "_ThreadImpl::state");
static_assert(offsetof(_ThreadImpl, fn) == 0x1d8, "_ThreadImpl::fn");
static_assert(offsetof(_ThreadImpl, arg) == 0x1e0, "_ThreadImpl::arg");

} // namespace shdfnd
} // namespace physx
