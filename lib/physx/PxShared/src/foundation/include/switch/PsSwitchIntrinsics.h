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

// Pokemon SwSh decomp: stand-in for the Nintendo Switch platform header,
// which NVIDIA ships only to Switch licensees. It is the Unix header, except that highestSetBitUnsafe and
// lowestSetBitUnsafe are De Bruijn multiplies with a table, as the binary has them.
// See docs/compiler.md, section PhysX, "What the sweep doesn't reproduce".

#ifndef PSFOUNDATION_PSSWITCHINTRINSICS_H
#define PSFOUNDATION_PSSWITCHINTRINSICS_H

#include "Ps.h"
#include "foundation/PxAssert.h"
#include <math.h>

#if PX_ANDROID || (PX_LINUX && !(PX_X64 || PX_X64)) // x86[_64] Linux uses inline assembly for debug break
#include <signal.h> // for Ns::debugBreak() { raise(SIGTRAP); }
#endif

#if 0
#include <libkern/OSAtomic.h>
#endif

// this file is for internal intrinsics - that is, intrinsics that are used in
// cross platform code but do not appear in the API

#if !(PX_LINUX || PX_ANDROID || PX_PS4 || PX_APPLE_FAMILY)
#endif

namespace physx
{
namespace shdfnd
{

PX_FORCE_INLINE void memoryBarrier()
{
	__sync_synchronize();
}

/*!
Return the index of the highest set bit. Undefined for zero arg.
*/
PX_INLINE uint32_t highestSetBitUnsafe(uint32_t v)
{

	static const uint32_t table[32] = { 0, 9, 1, 10, 13, 21, 2, 29, 11, 14, 16, 18, 22, 25, 3, 30,
	                                    8, 12, 20, 28, 15, 17, 24, 7, 19, 27, 23, 6, 26, 5, 4, 31 };
	v |= v >> 1;
	v |= v >> 2;
	v |= v >> 4;
	v |= v >> 8;
	v |= v >> 16;
	return table[(v * 0x07C4ACDDu) >> 27];
}

/*!
Return the index of the highest set bit. Undefined for zero arg.
*/
PX_INLINE int32_t lowestSetBitUnsafe(uint32_t v)
{
	static const uint32_t table[32] = { 0, 1, 28, 2, 29, 14, 24, 3, 30, 22, 20, 15, 25, 17, 4, 8,
	                                    31, 27, 13, 23, 21, 19, 16, 7, 26, 12, 18, 6, 11, 5, 10, 9 };
	return int32_t(table[((v & (0 - v)) * 0x077CB531u) >> 27]);
}

/*!
Returns the index of the highest set bit. Returns 32 for v=0.
*/
PX_INLINE uint32_t countLeadingZeros(uint32_t v)
{
	if(v)
		return __builtin_clz(v);
	else
		return 32;
}

/*!
Prefetch aligned 64B x86, 32b ARM around \c ptr+offset.
*/
PX_FORCE_INLINE void prefetchLine(const void* ptr, uint32_t offset = 0)
{
	__builtin_prefetch(reinterpret_cast<const char* PX_RESTRICT>(ptr) + offset, 0, 3);
}

/*!
Prefetch \c count bytes starting at \c ptr.
*/
#if PX_ANDROID || PX_IOS
PX_FORCE_INLINE void prefetch(const void* ptr, uint32_t count = 1)
{
	const char* cp = static_cast<const char*>(ptr);
	size_t p = reinterpret_cast<size_t>(ptr);
	uint32_t startLine = uint32_t(p >> 5), endLine = uint32_t((p + count - 1) >> 5);
	uint32_t lines = endLine - startLine + 1;
	do
	{
		prefetchLine(cp);
		cp += 32;
	} while(--lines);
}
#else
PX_FORCE_INLINE void prefetch(const void* ptr, uint32_t count = 1)
{
	const char* cp = reinterpret_cast<const char*>(ptr);
	uint64_t p = size_t(ptr);
	uint64_t startLine = p >> 6, endLine = (p + count - 1) >> 6;
	uint64_t lines = endLine - startLine + 1;
	do
	{
		prefetchLine(cp);
		cp += 64;
	} while(--lines);
}
#endif

//! \brief platform-specific reciprocal
PX_CUDA_CALLABLE PX_FORCE_INLINE float recipFast(float a)
{
	return 1.0f / a;
}

//! \brief platform-specific fast reciprocal square root
PX_CUDA_CALLABLE PX_FORCE_INLINE float recipSqrtFast(float a)
{
	return 1.0f / ::sqrtf(a);
}

//! \brief platform-specific floor
PX_CUDA_CALLABLE PX_FORCE_INLINE float floatFloor(float x)
{
	return ::floorf(x);
}

#define NS_EXPECT_TRUE(x) x
#define NS_EXPECT_FALSE(x) x

} // namespace shdfnd
} // namespace physx

#endif // #ifndef PSFOUNDATION_PSSWITCHINTRINSICS_H
