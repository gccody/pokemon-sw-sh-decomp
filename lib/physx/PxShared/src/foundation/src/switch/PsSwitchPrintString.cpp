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

// Pokemon SwSh decomp: PxFoundation's Nintendo Switch printString (not
// public), reconstructed from the binary: the string, then a newline, each
// through the SDK's log.

#include "PsString.h"

#include <nn/os.h>

// The SDK's log macro: the metadata is assigned member by member (no
// zero-filled padding), then passed to LogImpl.
#define PX_SWITCH_LOG(...)                                                                      \
	do                                                                                             \
	{                                                                                              \
		nn::diag::LogMetaData logMetaData;                                                            \
		logMetaData.field_0 = __LINE__;                                                               \
		logMetaData.field_8 = __FILE__;                                                               \
		logMetaData.field_10 = __func__;                                                              \
		logMetaData.field_18 = "";                                                                    \
		logMetaData.field_20 = 1;                                                                     \
		logMetaData.field_24 = 0;                                                                     \
		logMetaData.field_28 = false;                                                                 \
		logMetaData.field_30 = NULL;                                                                  \
		logMetaData.field_38 = 0;                                                                     \
		nn::diag::detail::LogImpl(logMetaData, __VA_ARGS__);                                          \
	} while(0)

namespace physx
{
namespace shdfnd
{

// The original's __LINE__ values: the two log calls are on lines 44 and 45.
#line 42
void printString(const char* str)
{
	PX_SWITCH_LOG(str);
	PX_SWITCH_LOG("\n");
}

} // namespace shdfnd
} // namespace physx
