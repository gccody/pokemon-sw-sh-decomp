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

// Pokemon SwSh decomp: PxFoundation's Nintendo Switch event (not public),
// reconstructed from the binary. PsUnixSync.cpp's logic on an nn::os
// condition variable and mutex; a timed wait counts system ticks.

#include "foundation/PxAssert.h"

#include "Ps.h"
#include "PsUserAllocated.h"
#include "PsSync.h"

#include <nn/os.h>

namespace physx
{
namespace shdfnd
{

namespace
{
class _SyncImpl
{
  public:
	nn::os::ConditionVariableType cond;
	nn::os::MutexType mutex;
	volatile int setCounter;
	volatile bool is_set;
};

_SyncImpl* getSync(SyncImpl* impl)
{
	return reinterpret_cast<_SyncImpl*>(impl);
}
}

uint32_t SyncImpl::getSize()
{
	return sizeof(_SyncImpl);
}

struct PxSwitchScopeLock
{
	PxSwitchScopeLock(nn::os::MutexType& m) : mMutex(m)
	{
		nn::os::LockMutex(&mMutex);
	}

	~PxSwitchScopeLock()
	{
		nn::os::UnlockMutex(&mMutex);
	}

  private:
	nn::os::MutexType& mMutex;
};

SyncImpl::SyncImpl()
{
	nn::os::InitializeMutex(&getSync(this)->mutex, false, 0);
	nn::os::InitializeConditionVariable(&getSync(this)->cond);
	getSync(this)->setCounter = 0;
	getSync(this)->is_set = false;
}

SyncImpl::~SyncImpl()
{
	nn::os::FinalizeConditionVariable(&getSync(this)->cond);
	nn::os::FinalizeMutex(&getSync(this)->mutex);
}

void SyncImpl::reset()
{
	PxSwitchScopeLock lock(getSync(this)->mutex);
	getSync(this)->is_set = false;
}

void SyncImpl::set()
{
	PxSwitchScopeLock lock(getSync(this)->mutex);
	if(!getSync(this)->is_set)
	{
		getSync(this)->setCounter++;
		getSync(this)->is_set = true;
		nn::os::BroadcastConditionVariable(&getSync(this)->cond);
	}
}

bool SyncImpl::wait(uint32_t ms)
{
	PxSwitchScopeLock lock(getSync(this)->mutex);
	int lastSetCounter = getSync(this)->setCounter;
	if(!getSync(this)->is_set)
	{
		if(ms == uint32_t(-1))
		{
			// have to loop here and check is_set since a wait can return
			// even if it was not signaled by BroadcastConditionVariable
			while(!getSync(this)->is_set && (lastSetCounter == getSync(this)->setCounter))
				nn::os::WaitConditionVariable(&getSync(this)->cond, &getSync(this)->mutex);
		}
		else
		{
			const int64_t frequency = nn::os::GetSystemTickFrequency();
			const nn::os::Tick start = nn::os::GetSystemTick();
			const nn::os::Tick timeout = { frequency * ms / 1000 };
			const int64_t end = start.field_0 + timeout.field_0;
			// The original compares the tick count with this, not with end itself.
			const int64_t limit = end + 1 - (end >> 4);
			bool waiting = true;
			while(!getSync(this)->is_set && (lastSetCounter == getSync(this)->setCounter) && waiting)
			{
				nn::os::TimedWaitConditionVariable(&getSync(this)->cond, &getSync(this)->mutex,
				                                   nn::os::ConvertToTimeSpan(timeout));
				waiting = nn::os::GetSystemTick().field_0 <= limit;
			}
		}
	}
	return getSync(this)->is_set || (lastSetCounter != getSync(this)->setCounter);
}

// Layouts, as the binary uses them.
static_assert(sizeof(_SyncImpl) == 0x30, "_SyncImpl");
static_assert(offsetof(_SyncImpl, mutex) == 0x8, "_SyncImpl::mutex");
static_assert(offsetof(_SyncImpl, setCounter) == 0x28, "_SyncImpl::setCounter");
static_assert(offsetof(_SyncImpl, is_set) == 0x2c, "_SyncImpl::is_set");

} // namespace shdfnd
} // namespace physx
