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

// Pokemon SwSh decomp: PxFoundation's Nintendo Switch mutex and read-write lock
// (not public), reconstructed from the binary. The Unix version,
// PsUnixMutex.cpp, with the nn::os mutex; the owner check in unlock() is always on.

#include "foundation/PxAssert.h"
#include "foundation/PxErrorCallback.h"

#include "Ps.h"
#include "PsFoundation.h"
#include "PsUserAllocated.h"
#include "PsMutex.h"
#include "PsAtomic.h"
#include "PsThread.h"

#include <nn/os.h>

namespace physx
{
namespace shdfnd
{

namespace
{
struct MutexSwitchImpl
{
	nn::os::MutexType lock;
	Thread::Id owner;
};

MutexSwitchImpl* getMutex(MutexImpl* impl)
{
	return reinterpret_cast<MutexSwitchImpl*>(impl);
}
}

MutexImpl::MutexImpl()
{
	nn::os::InitializeMutex(&getMutex(this)->lock, true, 0);
}

MutexImpl::~MutexImpl()
{
	nn::os::FinalizeMutex(&getMutex(this)->lock);
}

void MutexImpl::lock()
{
	nn::os::LockMutex(&getMutex(this)->lock);
	getMutex(this)->owner = Thread::getId();
}

bool MutexImpl::trylock()
{
	bool success = nn::os::TryLockMutex(&getMutex(this)->lock);
	if(success)
		getMutex(this)->owner = Thread::getId();
	return success;
}

// The original's __LINE__ values: the error below is on line 98, PX_ALLOC on 124.
#line 94
void MutexImpl::unlock()
{
	if(getMutex(this)->owner != Thread::getId())
	{
		shdfnd::getFoundation().error(PxErrorCode::eINVALID_OPERATION, __FILE__, __LINE__,
		                              "Mutex must be unlocked only by thread that has already acquired lock");
		return;
	}

	nn::os::UnlockMutex(&getMutex(this)->lock);
}

uint32_t MutexImpl::getSize()
{
	return sizeof(MutexSwitchImpl);
}

class ReadWriteLockImpl
{
	PX_NOCOPY(ReadWriteLockImpl)
  public:
	ReadWriteLockImpl() : readerCounter(0)
	{
	}
	Mutex mutex;
	volatile int readerCounter;
};

#line 122
ReadWriteLock::ReadWriteLock()
{
	mImpl = reinterpret_cast<ReadWriteLockImpl*>(PX_ALLOC(sizeof(ReadWriteLockImpl), "ReadWriteLockImpl"));
	PX_PLACEMENT_NEW(mImpl, ReadWriteLockImpl);
}

ReadWriteLock::~ReadWriteLock()
{
	mImpl->~ReadWriteLockImpl();
	PX_FREE(mImpl);
}

void ReadWriteLock::lockReader(bool takeLock)
{
	if(takeLock)
		mImpl->mutex.lock();

	__sync_add_and_fetch(&mImpl->readerCounter, 1);

	if(takeLock)
		mImpl->mutex.unlock();
}

void ReadWriteLock::lockWriter()
{
	mImpl->mutex.lock();

	// wait until no readers
	while(__atomic_load_n(&mImpl->readerCounter, __ATOMIC_SEQ_CST))
		nn::os::SleepThread(nn::TimeSpan{ 1 });
}

void ReadWriteLock::unlockReader()
{
	__sync_sub_and_fetch(&mImpl->readerCounter, 1);
}

void ReadWriteLock::unlockWriter()
{
	mImpl->mutex.unlock();
}

// Layouts, as the binary uses them.
static_assert(sizeof(MutexSwitchImpl) == 0x28, "MutexSwitchImpl");
static_assert(offsetof(MutexSwitchImpl, owner) == 0x20, "MutexSwitchImpl::owner");
static_assert(sizeof(ReadWriteLockImpl) == 0x10, "ReadWriteLockImpl");
static_assert(offsetof(ReadWriteLockImpl, readerCounter) == 0x8, "ReadWriteLockImpl::readerCounter");

} // namespace shdfnd
} // namespace physx
