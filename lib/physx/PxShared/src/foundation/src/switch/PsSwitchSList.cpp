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

// Pokemon SwSh decomp: PxFoundation's Nintendo Switch lock-protected list (not
// public), reconstructed from the binary. The code is PsUnixSList.cpp's
// spin-lock version.

#include "PsAllocator.h"
#include "PsAtomic.h"
#include "PsSList.h"
#include "PsThread.h"

namespace physx
{
namespace shdfnd
{
namespace
{
struct ScopedSpinLock
{
	PX_FORCE_INLINE ScopedSpinLock(volatile int32_t& lock) : mLock(lock)
	{
		while(__sync_lock_test_and_set(&mLock, 1))
		{
			// spinning without atomics is usually
			// causing less bus traffic. -> only one
			// CPU is modifying the cache line.
			while(lock)
				PxSpinLockPause();
		}
	}

	PX_FORCE_INLINE ~ScopedSpinLock()
	{
		__sync_lock_release(&mLock);
	}

  private:
	volatile int32_t& mLock;
};

typedef ScopedSpinLock ScopedLock;

struct SListDetail
{
	SListEntry* head;
	volatile int32_t lock;
};

template <typename T>
SListDetail* getDetail(T* impl)
{
	return reinterpret_cast<SListDetail*>(impl);
}
}

SListImpl::SListImpl()
{
	getDetail(this)->head = NULL;
	getDetail(this)->lock = 0; // 0 == unlocked
}

SListImpl::~SListImpl()
{
}

void SListImpl::push(SListEntry* entry)
{
	ScopedLock lock(getDetail(this)->lock);
	entry->mNext = getDetail(this)->head;
	getDetail(this)->head = entry;
}

SListEntry* SListImpl::pop()
{
	ScopedLock lock(getDetail(this)->lock);
	SListEntry* result = getDetail(this)->head;
	if(result != NULL)
		getDetail(this)->head = result->mNext;
	return result;
}

SListEntry* SListImpl::flush()
{
	ScopedLock lock(getDetail(this)->lock);
	SListEntry* result = getDetail(this)->head;
	getDetail(this)->head = NULL;
	return result;
}

uint32_t SListImpl::getSize()
{
	return sizeof(SListDetail);
}

} // namespace shdfnd
} // namespace physx
