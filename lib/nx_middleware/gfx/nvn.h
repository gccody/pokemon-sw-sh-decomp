#pragma once

// NVN's C entry points, as NintendoSDK_gfx 7.3.2 keeps them: one global
// function pointer each, filled by the loader at 0x7101789d10 (Unk_1789d10.cpp)
// through the device's GetProcAddress. The globals are placeholders named
// after their Sword addresses; the comment is the name the loader looks up.
// An entry point whose callers are decompiled has the parameter types they
// show (NVN objects are opaque: void*) and an inline function of that name
// that calls it, so that, as in the original, the arguments are evaluated
// before the pointer is loaded. The others are NvnProc.
#include <types.h>

using NvnProc = void (*)();
// NVN's booleans are bytes: a negated flag is passed as `(flag ^ 1)`.
using NvnBoolean = u8;

extern void (*Unk_27fc668)(void* builder);  // nvnDeviceBuilderSetDefaults
inline void nvnDeviceBuilderSetDefaults(void* builder) {
    Unk_27fc668(builder);
}
extern void (*Unk_27fc670)(void* builder, int flags);  // nvnDeviceBuilderSetFlags
inline void nvnDeviceBuilderSetFlags(void* builder, int flags) {
    Unk_27fc670(builder, flags);
}
extern NvnProc Unk_27fc678;  // nvnDeviceBuilderGetFlags
extern NvnBoolean (*Unk_27fc680)(void* device, const void* builder);  // nvnDeviceInitialize
inline NvnBoolean nvnDeviceInitialize(void* device, const void* builder) {
    return Unk_27fc680(device, builder);
}
extern void (*Unk_27fc688)(void* device);  // nvnDeviceFinalize
inline void nvnDeviceFinalize(void* device) {
    Unk_27fc688(device);
}
extern NvnProc Unk_27fc690;  // nvnDeviceSetDebugLabel
extern NvnProc Unk_27fc698;  // nvnDeviceGetProcAddress
extern void (*Unk_27fc6a0)(void* device, int name, int* value);  // nvnDeviceGetInteger
inline void nvnDeviceGetInteger(void* device, int name, int* value) {
    Unk_27fc6a0(device, name, value);
}
extern NvnProc Unk_27fc6a8;  // nvnDeviceGetCurrentTimestampInNanoseconds
extern NvnProc Unk_27fc6b0;  // nvnDeviceSetIntermediateShaderCache
extern u64 (*Unk_27fc6b8)(const void* device, int textureId, int samplerId);  // nvnDeviceGetTextureHandle
inline u64 nvnDeviceGetTextureHandle(const void* device, int textureId, int samplerId) {
    return Unk_27fc6b8(device, textureId, samplerId);
}
extern u64 (*Unk_27fc6c0)(const void* device, int textureId);  // nvnDeviceGetTexelFetchHandle
inline u64 nvnDeviceGetTexelFetchHandle(const void* device, int textureId) {
    return Unk_27fc6c0(device, textureId);
}
extern NvnProc Unk_27fc6c8;  // nvnDeviceGetImageHandle
extern NvnProc Unk_27fc6d0;  // nvnDeviceInstallDebugCallback
extern NvnProc Unk_27fc6d8;  // nvnDeviceGenerateDebugDomainId
extern NvnProc Unk_27fc6e0;  // nvnDeviceSetWindowOriginMode
extern NvnProc Unk_27fc6e8;  // nvnDeviceSetDepthMode
extern NvnProc Unk_27fc6f0;  // nvnDeviceRegisterFastClearColor
extern NvnProc Unk_27fc6f8;  // nvnDeviceRegisterFastClearColori
extern NvnProc Unk_27fc700;  // nvnDeviceRegisterFastClearColorui
extern NvnProc Unk_27fc708;  // nvnDeviceRegisterFastClearDepth
extern NvnProc Unk_27fc710;  // nvnDeviceGetWindowOriginMode
extern NvnProc Unk_27fc718;  // nvnDeviceGetDepthMode
extern NvnProc Unk_27fc720;  // nvnDeviceGetTimestampInNanoseconds
extern NvnProc Unk_27fc728;  // nvnDeviceApplyDeferredFinalizes
extern void (*Unk_27fc730)(void* device, u64 handle);  // nvnDeviceFinalizeCommandHandle
inline void nvnDeviceFinalizeCommandHandle(void* device, u64 handle) {
    Unk_27fc730(device, handle);
}
extern NvnProc Unk_27fc738;  // nvnDeviceWalkDebugDatabase
extern NvnProc Unk_27fc740;  // nvnDeviceGetSeparateTextureHandle
extern NvnProc Unk_27fc748;  // nvnDeviceGetSeparateSamplerHandle
extern NvnProc Unk_27fc750;  // nvnDeviceIsExternalDebuggerAttached
extern NvnProc Unk_27fc758;  // nvnQueueGetError
extern NvnProc Unk_27fc760;  // nvnQueueGetTotalCommandMemoryUsed
extern NvnProc Unk_27fc768;  // nvnQueueGetTotalControlMemoryUsed
extern NvnProc Unk_27fc770;  // nvnQueueGetTotalComputeMemoryUsed
extern NvnProc Unk_27fc778;  // nvnQueueResetMemoryUsageCounts
extern NvnProc Unk_27fc780;  // nvnQueueBuilderSetDevice
extern NvnProc Unk_27fc788;  // nvnQueueBuilderSetDefaults
extern NvnProc Unk_27fc790;  // nvnQueueBuilderSetFlags
extern NvnProc Unk_27fc798;  // nvnQueueBuilderSetCommandMemorySize
extern NvnProc Unk_27fc7a0;  // nvnQueueBuilderSetComputeMemorySize
extern NvnProc Unk_27fc7a8;  // nvnQueueBuilderSetControlMemorySize
extern NvnProc Unk_27fc7b0;  // nvnQueueBuilderGetQueueMemorySize
extern NvnProc Unk_27fc7b8;  // nvnQueueBuilderSetQueueMemory
extern NvnProc Unk_27fc7c0;  // nvnQueueBuilderSetCommandFlushThreshold
extern NvnProc Unk_27fc7c8;  // nvnQueueBuilderSetQueuePriority
extern NvnProc Unk_27fc7d0;  // nvnQueueBuilderGetQueuePriority
extern NvnProc Unk_27fc7d8;  // nvnQueueBuilderGetDevice
extern NvnProc Unk_27fc7e0;  // nvnQueueBuilderGetFlags
extern NvnProc Unk_27fc7e8;  // nvnQueueBuilderGetCommandMemorySize
extern NvnProc Unk_27fc7f0;  // nvnQueueBuilderGetComputeMemorySize
extern NvnProc Unk_27fc7f8;  // nvnQueueBuilderGetControlMemorySize
extern NvnProc Unk_27fc800;  // nvnQueueBuilderGetCommandFlushThreshold
extern NvnProc Unk_27fc808;  // nvnQueueBuilderGetMemorySize
extern NvnProc Unk_27fc810;  // nvnQueueBuilderGetMemory
extern NvnProc Unk_27fc818;  // nvnQueueInitialize
extern NvnProc Unk_27fc820;  // nvnQueueFinalize
extern NvnProc Unk_27fc828;  // nvnQueueSetDebugLabel
extern void (*Unk_27fc830)(void* queue, int count, const u64* handles);  // nvnQueueSubmitCommands
inline void nvnQueueSubmitCommands(void* queue, int count, const u64* handles) {
    Unk_27fc830(queue, count, handles);
}
extern NvnProc Unk_27fc838;  // nvnQueueFlush
extern void (*Unk_27fc840)(void* queue);  // nvnQueueFinish
inline void nvnQueueFinish(void* queue) {
    Unk_27fc840(queue);
}
extern void (*Unk_27fc848)(void* queue, void* window, int index);  // nvnQueuePresentTexture
inline void nvnQueuePresentTexture(void* queue, void* window, int index) {
    Unk_27fc848(queue, window, index);
}
extern int (*Unk_27fc850)(void* queue, void* window, int* index);  // nvnQueueAcquireTexture
inline int nvnQueueAcquireTexture(void* queue, void* window, int* index) {
    return Unk_27fc850(queue, window, index);
}
extern NvnProc Unk_27fc858;  // nvnWindowBuilderSetDevice
extern NvnProc Unk_27fc860;  // nvnWindowBuilderSetDefaults
extern NvnProc Unk_27fc868;  // nvnWindowBuilderSetNativeWindow
extern NvnProc Unk_27fc870;  // nvnWindowBuilderSetTextures
extern NvnProc Unk_27fc878;  // nvnWindowBuilderSetPresentInterval
extern NvnProc Unk_27fc880;  // nvnWindowBuilderSetNumActiveTextures
extern NvnProc Unk_27fc888;  // nvnWindowBuilderGetDevice
extern NvnProc Unk_27fc890;  // nvnWindowBuilderGetNumTextures
extern NvnProc Unk_27fc898;  // nvnWindowBuilderGetTexture
extern NvnProc Unk_27fc8a0;  // nvnWindowBuilderGetNativeWindow
extern NvnProc Unk_27fc8a8;  // nvnWindowBuilderGetPresentInterval
extern NvnProc Unk_27fc8b0;  // nvnWindowBuilderGetNumActiveTextures
extern NvnProc Unk_27fc8b8;  // nvnWindowInitialize
extern void (*Unk_27fc8c0)(void* window);  // nvnWindowFinalize
inline void nvnWindowFinalize(void* window) {
    Unk_27fc8c0(window);
}
extern NvnProc Unk_27fc8c8;  // nvnWindowSetDebugLabel
extern int (*Unk_27fc8d0)(void* window, void* sync, int* index);  // nvnWindowAcquireTexture
inline int nvnWindowAcquireTexture(void* window, void* sync, int* index) {
    return Unk_27fc8d0(window, sync, index);
}
extern NvnProc Unk_27fc8d8;  // nvnWindowGetNativeWindow
extern int (*Unk_27fc8e0)(const void* window);  // nvnWindowGetPresentInterval
inline int nvnWindowGetPresentInterval(const void* window) {
    return Unk_27fc8e0(window);
}
extern void (*Unk_27fc8e8)(void* window, int interval);  // nvnWindowSetPresentInterval
inline void nvnWindowSetPresentInterval(void* window, int interval) {
    Unk_27fc8e8(window, interval);
}
extern NvnProc Unk_27fc8f0;  // nvnWindowSetCrop
extern NvnProc Unk_27fc8f8;  // nvnWindowGetCrop
extern NvnProc Unk_27fc900;  // nvnWindowSetNumActiveTextures
extern NvnProc Unk_27fc908;  // nvnWindowGetNumActiveTextures
extern NvnProc Unk_27fc910;  // nvnWindowGetNumTextures
extern NvnProc Unk_27fc918;  // nvnProgramInitialize
extern NvnProc Unk_27fc920;  // nvnProgramFinalize
extern NvnProc Unk_27fc928;  // nvnProgramSetDebugLabel
extern NvnProc Unk_27fc930;  // nvnProgramSetShaders
extern NvnProc Unk_27fc938;  // nvnProgramSetShadersExt
extern NvnProc Unk_27fc940;  // nvnProgramSetSampleShading
extern void (*Unk_27fc948)(void* builder, void* device);  // nvnMemoryPoolBuilderSetDevice
inline void nvnMemoryPoolBuilderSetDevice(void* builder, void* device) {
    Unk_27fc948(builder, device);
}
extern void (*Unk_27fc950)(void* builder);  // nvnMemoryPoolBuilderSetDefaults
inline void nvnMemoryPoolBuilderSetDefaults(void* builder) {
    Unk_27fc950(builder);
}
extern void (*Unk_27fc958)(void* builder, void* memory, size_t size);  // nvnMemoryPoolBuilderSetStorage
inline void nvnMemoryPoolBuilderSetStorage(void* builder, void* memory, size_t size) {
    Unk_27fc958(builder, memory, size);
}
extern void (*Unk_27fc960)(void* builder, int flags);  // nvnMemoryPoolBuilderSetFlags
inline void nvnMemoryPoolBuilderSetFlags(void* builder, int flags) {
    Unk_27fc960(builder, flags);
}
extern NvnProc Unk_27fc968;  // nvnMemoryPoolBuilderGetDevice
extern NvnProc Unk_27fc970;  // nvnMemoryPoolBuilderGetMemory
extern NvnProc Unk_27fc978;  // nvnMemoryPoolBuilderGetSize
extern NvnProc Unk_27fc980;  // nvnMemoryPoolBuilderGetFlags
extern NvnBoolean (*Unk_27fc988)(void* pool, const void* builder);  // nvnMemoryPoolInitialize
inline NvnBoolean nvnMemoryPoolInitialize(void* pool, const void* builder) {
    return Unk_27fc988(pool, builder);
}
extern void (*Unk_27fc990)(void* pool, const char* label);  // nvnMemoryPoolSetDebugLabel
inline void nvnMemoryPoolSetDebugLabel(void* pool, const char* label) {
    Unk_27fc990(pool, label);
}
extern void (*Unk_27fc998)(void* pool);  // nvnMemoryPoolFinalize
inline void nvnMemoryPoolFinalize(void* pool) {
    Unk_27fc998(pool);
}
extern void* (*Unk_27fc9a0)(const void* pool);  // nvnMemoryPoolMap
inline void* nvnMemoryPoolMap(const void* pool) {
    return Unk_27fc9a0(pool);
}
extern NvnProc Unk_27fc9a8;  // nvnMemoryPoolFlushMappedRange
extern NvnProc Unk_27fc9b0;  // nvnMemoryPoolInvalidateMappedRange
extern NvnProc Unk_27fc9b8;  // nvnMemoryPoolGetBufferAddress
extern NvnProc Unk_27fc9c0;  // nvnMemoryPoolMapVirtual
extern NvnProc Unk_27fc9c8;  // nvnMemoryPoolGetSize
extern int (*Unk_27fc9d0)(const void* pool);  // nvnMemoryPoolGetFlags
inline int nvnMemoryPoolGetFlags(const void* pool) {
    return Unk_27fc9d0(pool);
}
extern NvnBoolean (*Unk_27fc9d8)(void* pool, void* memoryPool, s64 offset, int numDescriptors);  // nvnTexturePoolInitialize
inline NvnBoolean nvnTexturePoolInitialize(void* pool, void* memoryPool, s64 offset, int numDescriptors) {
    return Unk_27fc9d8(pool, memoryPool, offset, numDescriptors);
}
extern NvnProc Unk_27fc9e0;  // nvnTexturePoolSetDebugLabel
extern void (*Unk_27fc9e8)(void* pool);  // nvnTexturePoolFinalize
inline void nvnTexturePoolFinalize(void* pool) {
    Unk_27fc9e8(pool);
}
extern void (*Unk_27fc9f0)(void* pool, int id, const void* texture, const void* view);  // nvnTexturePoolRegisterTexture
inline void nvnTexturePoolRegisterTexture(void* pool, int id, const void* texture, const void* view) {
    Unk_27fc9f0(pool, id, texture, view);
}
extern NvnProc Unk_27fc9f8;  // nvnTexturePoolRegisterImage
extern NvnProc Unk_27fca00;  // nvnTexturePoolGetMemoryPool
extern NvnProc Unk_27fca08;  // nvnTexturePoolGetMemoryOffset
extern NvnProc Unk_27fca10;  // nvnTexturePoolGetSize
extern NvnBoolean (*Unk_27fca18)(void* pool, void* memoryPool, s64 offset, int numDescriptors);  // nvnSamplerPoolInitialize
inline NvnBoolean nvnSamplerPoolInitialize(void* pool, void* memoryPool, s64 offset, int numDescriptors) {
    return Unk_27fca18(pool, memoryPool, offset, numDescriptors);
}
extern NvnProc Unk_27fca20;  // nvnSamplerPoolSetDebugLabel
extern void (*Unk_27fca28)(void* pool);  // nvnSamplerPoolFinalize
inline void nvnSamplerPoolFinalize(void* pool) {
    Unk_27fca28(pool);
}
extern void (*Unk_27fca30)(void* pool, int id, const void* sampler);  // nvnSamplerPoolRegisterSampler
inline void nvnSamplerPoolRegisterSampler(void* pool, int id, const void* sampler) {
    Unk_27fca30(pool, id, sampler);
}
extern NvnProc Unk_27fca38;  // nvnSamplerPoolRegisterSamplerBuilder
extern NvnProc Unk_27fca40;  // nvnSamplerPoolGetMemoryPool
extern NvnProc Unk_27fca48;  // nvnSamplerPoolGetMemoryOffset
extern NvnProc Unk_27fca50;  // nvnSamplerPoolGetSize
extern void (*Unk_27fca58)(void* builder, void* device);  // nvnBufferBuilderSetDevice
inline void nvnBufferBuilderSetDevice(void* builder, void* device) {
    Unk_27fca58(builder, device);
}
extern void (*Unk_27fca60)(void* builder);  // nvnBufferBuilderSetDefaults
inline void nvnBufferBuilderSetDefaults(void* builder) {
    Unk_27fca60(builder);
}
extern void (*Unk_27fca68)(void* builder, void* pool, s64 offset, size_t size);  // nvnBufferBuilderSetStorage
inline void nvnBufferBuilderSetStorage(void* builder, void* pool, s64 offset, size_t size) {
    Unk_27fca68(builder, pool, offset, size);
}
extern NvnProc Unk_27fca70;  // nvnBufferBuilderGetDevice
extern NvnProc Unk_27fca78;  // nvnBufferBuilderGetMemoryPool
extern NvnProc Unk_27fca80;  // nvnBufferBuilderGetMemoryOffset
extern NvnProc Unk_27fca88;  // nvnBufferBuilderGetSize
extern bool (*Unk_27fca90)(void* buffer, const void* builder);  // nvnBufferInitialize
inline bool nvnBufferInitialize(void* buffer, const void* builder) {
    return Unk_27fca90(buffer, builder);
}
extern void (*Unk_27fca98)(void* buffer, const char* label);  // nvnBufferSetDebugLabel
inline void nvnBufferSetDebugLabel(void* buffer, const char* label) {
    Unk_27fca98(buffer, label);
}
extern void (*Unk_27fcaa0)(void* buffer);  // nvnBufferFinalize
inline void nvnBufferFinalize(void* buffer) {
    Unk_27fcaa0(buffer);
}
extern void* (*Unk_27fcaa8)(const void* buffer);  // nvnBufferMap
inline void* nvnBufferMap(const void* buffer) {
    return Unk_27fcaa8(buffer);
}
extern u64 (*Unk_27fcab0)(const void* buffer);  // nvnBufferGetAddress
inline u64 nvnBufferGetAddress(const void* buffer) {
    return Unk_27fcab0(buffer);
}
extern void (*Unk_27fcab8)(const void* buffer, s64 offset, size_t size);  // nvnBufferFlushMappedRange
inline void nvnBufferFlushMappedRange(const void* buffer, s64 offset, size_t size) {
    Unk_27fcab8(buffer, offset, size);
}
extern void (*Unk_27fcac0)(const void* buffer, s64 offset, size_t size);  // nvnBufferInvalidateMappedRange
inline void nvnBufferInvalidateMappedRange(const void* buffer, s64 offset, size_t size) {
    Unk_27fcac0(buffer, offset, size);
}
extern NvnProc Unk_27fcac8;  // nvnBufferGetMemoryPool
extern NvnProc Unk_27fcad0;  // nvnBufferGetMemoryOffset
extern NvnProc Unk_27fcad8;  // nvnBufferGetSize
extern NvnProc Unk_27fcae0;  // nvnBufferGetDebugID
extern void (*Unk_27fcae8)(void* builder, void* device);  // nvnTextureBuilderSetDevice
inline void nvnTextureBuilderSetDevice(void* builder, void* device) {
    Unk_27fcae8(builder, device);
}
extern void (*Unk_27fcaf0)(void* builder);  // nvnTextureBuilderSetDefaults
inline void nvnTextureBuilderSetDefaults(void* builder) {
    Unk_27fcaf0(builder);
}
extern void (*Unk_27fcaf8)(void* builder, int flags);  // nvnTextureBuilderSetFlags
inline void nvnTextureBuilderSetFlags(void* builder, int flags) {
    Unk_27fcaf8(builder, flags);
}
extern void (*Unk_27fcb00)(void* builder, int target);  // nvnTextureBuilderSetTarget
inline void nvnTextureBuilderSetTarget(void* builder, int target) {
    Unk_27fcb00(builder, target);
}
extern void (*Unk_27fcb08)(void* builder, int width);  // nvnTextureBuilderSetWidth
inline void nvnTextureBuilderSetWidth(void* builder, int width) {
    Unk_27fcb08(builder, width);
}
extern void (*Unk_27fcb10)(void* builder, int height);  // nvnTextureBuilderSetHeight
inline void nvnTextureBuilderSetHeight(void* builder, int height) {
    Unk_27fcb10(builder, height);
}
extern void (*Unk_27fcb18)(void* builder, int depth);  // nvnTextureBuilderSetDepth
inline void nvnTextureBuilderSetDepth(void* builder, int depth) {
    Unk_27fcb18(builder, depth);
}
extern NvnProc Unk_27fcb20;  // nvnTextureBuilderSetSize1D
extern NvnProc Unk_27fcb28;  // nvnTextureBuilderSetSize2D
extern NvnProc Unk_27fcb30;  // nvnTextureBuilderSetSize3D
extern void (*Unk_27fcb38)(void* builder, int levels);  // nvnTextureBuilderSetLevels
inline void nvnTextureBuilderSetLevels(void* builder, int levels) {
    Unk_27fcb38(builder, levels);
}
extern void (*Unk_27fcb40)(void* builder, int format);  // nvnTextureBuilderSetFormat
inline void nvnTextureBuilderSetFormat(void* builder, int format) {
    Unk_27fcb40(builder, format);
}
extern void (*Unk_27fcb48)(void* builder, int samples);  // nvnTextureBuilderSetSamples
inline void nvnTextureBuilderSetSamples(void* builder, int samples) {
    Unk_27fcb48(builder, samples);
}
extern NvnProc Unk_27fcb50;  // nvnTextureBuilderSetSwizzle
extern NvnProc Unk_27fcb58;  // nvnTextureBuilderSetDepthStencilMode
extern size_t (*Unk_27fcb60)(const void* builder);  // nvnTextureBuilderGetStorageSize
inline size_t nvnTextureBuilderGetStorageSize(const void* builder) {
    return Unk_27fcb60(builder);
}
extern size_t (*Unk_27fcb68)(const void* builder);  // nvnTextureBuilderGetStorageAlignment
inline size_t nvnTextureBuilderGetStorageAlignment(const void* builder) {
    return Unk_27fcb68(builder);
}
extern void (*Unk_27fcb70)(void* builder, void* pool, s64 offset);  // nvnTextureBuilderSetStorage
inline void nvnTextureBuilderSetStorage(void* builder, void* pool, s64 offset) {
    Unk_27fcb70(builder, pool, offset);
}
extern NvnProc Unk_27fcb78;  // nvnTextureBuilderSetPackagedTextureData
extern void (*Unk_27fcb80)(void* builder, const void* layout);  // nvnTextureBuilderSetPackagedTextureLayout
inline void nvnTextureBuilderSetPackagedTextureLayout(void* builder, const void* layout) {
    Unk_27fcb80(builder, layout);
}
extern void (*Unk_27fcb88)(void* builder, s64 stride);  // nvnTextureBuilderSetStride
inline void nvnTextureBuilderSetStride(void* builder, s64 stride) {
    Unk_27fcb88(builder, stride);
}
extern NvnProc Unk_27fcb90;  // nvnTextureBuilderSetGLTextureName
extern NvnProc Unk_27fcb98;  // nvnTextureBuilderGetStorageClass
extern NvnProc Unk_27fcba0;  // nvnTextureBuilderGetDevice
extern NvnProc Unk_27fcba8;  // nvnTextureBuilderGetFlags
extern NvnProc Unk_27fcbb0;  // nvnTextureBuilderGetTarget
extern NvnProc Unk_27fcbb8;  // nvnTextureBuilderGetWidth
extern NvnProc Unk_27fcbc0;  // nvnTextureBuilderGetHeight
extern NvnProc Unk_27fcbc8;  // nvnTextureBuilderGetDepth
extern NvnProc Unk_27fcbd0;  // nvnTextureBuilderGetLevels
extern NvnProc Unk_27fcbd8;  // nvnTextureBuilderGetFormat
extern NvnProc Unk_27fcbe0;  // nvnTextureBuilderGetSamples
extern NvnProc Unk_27fcbe8;  // nvnTextureBuilderGetSwizzle
extern NvnProc Unk_27fcbf0;  // nvnTextureBuilderGetDepthStencilMode
extern NvnProc Unk_27fcbf8;  // nvnTextureBuilderGetPackagedTextureData
extern NvnProc Unk_27fcc00;  // nvnTextureBuilderGetPackagedTextureLayout
extern NvnProc Unk_27fcc08;  // nvnTextureBuilderGetStride
extern NvnProc Unk_27fcc10;  // nvnTextureBuilderGetSparseTileLayout
extern NvnProc Unk_27fcc18;  // nvnTextureBuilderGetGLTextureName
extern NvnProc Unk_27fcc20;  // nvnTextureBuilderGetZCullStorageSize
extern NvnProc Unk_27fcc28;  // nvnTextureBuilderGetMemoryPool
extern NvnProc Unk_27fcc30;  // nvnTextureBuilderGetMemoryOffset
extern NvnProc Unk_27fcc38;  // nvnTextureBuilderGetRawStorageClass
extern void (*Unk_27fcc40)(void* view);  // nvnTextureViewSetDefaults
inline void nvnTextureViewSetDefaults(void* view) {
    Unk_27fcc40(view);
}
extern void (*Unk_27fcc48)(void* view, int baseLevel, int numLevels);  // nvnTextureViewSetLevels
inline void nvnTextureViewSetLevels(void* view, int baseLevel, int numLevels) {
    Unk_27fcc48(view, baseLevel, numLevels);
}
extern void (*Unk_27fcc50)(void* view, int minLayer, int numLayers);  // nvnTextureViewSetLayers
inline void nvnTextureViewSetLayers(void* view, int minLayer, int numLayers) {
    Unk_27fcc50(view, minLayer, numLayers);
}
extern void (*Unk_27fcc58)(void* view, int format);  // nvnTextureViewSetFormat
inline void nvnTextureViewSetFormat(void* view, int format) {
    Unk_27fcc58(view, format);
}
extern void (*Unk_27fcc60)(void* view, int r, int g, int b, int a);  // nvnTextureViewSetSwizzle
inline void nvnTextureViewSetSwizzle(void* view, int r, int g, int b, int a) {
    Unk_27fcc60(view, r, g, b, a);
}
extern void (*Unk_27fcc68)(void* view, int mode);  // nvnTextureViewSetDepthStencilMode
inline void nvnTextureViewSetDepthStencilMode(void* view, int mode) {
    Unk_27fcc68(view, mode);
}
extern void (*Unk_27fcc70)(void* view, int target);  // nvnTextureViewSetTarget
inline void nvnTextureViewSetTarget(void* view, int target) {
    Unk_27fcc70(view, target);
}
extern NvnBoolean (*Unk_27fcc78)(const void* view, int* baseLevel, int* numLevels);  // nvnTextureViewGetLevels
inline NvnBoolean nvnTextureViewGetLevels(const void* view, int* baseLevel, int* numLevels) {
    return Unk_27fcc78(view, baseLevel, numLevels);
}
extern NvnBoolean (*Unk_27fcc80)(const void* view, int* minLayer, int* numLayers);  // nvnTextureViewGetLayers
inline NvnBoolean nvnTextureViewGetLayers(const void* view, int* minLayer, int* numLayers) {
    return Unk_27fcc80(view, minLayer, numLayers);
}
extern NvnProc Unk_27fcc88;  // nvnTextureViewGetFormat
extern NvnProc Unk_27fcc90;  // nvnTextureViewGetSwizzle
extern NvnProc Unk_27fcc98;  // nvnTextureViewGetDepthStencilMode
extern NvnBoolean (*Unk_27fcca0)(const void* view, int* target);  // nvnTextureViewGetTarget
inline NvnBoolean nvnTextureViewGetTarget(const void* view, int* target) {
    return Unk_27fcca0(view, target);
}
extern NvnProc Unk_27fcca8;  // nvnTextureViewCompare
extern NvnBoolean (*Unk_27fccb0)(void* texture, const void* builder);  // nvnTextureInitialize
inline NvnBoolean nvnTextureInitialize(void* texture, const void* builder) {
    return Unk_27fccb0(texture, builder);
}
extern NvnProc Unk_27fccb8;  // nvnTextureGetZCullStorageSize
extern void (*Unk_27fccc0)(void* texture);  // nvnTextureFinalize
inline void nvnTextureFinalize(void* texture) {
    Unk_27fccc0(texture);
}
extern NvnProc Unk_27fccc8;  // nvnTextureSetDebugLabel
extern NvnProc Unk_27fccd0;  // nvnTextureGetStorageClass
extern NvnProc Unk_27fccd8;  // nvnTextureGetViewOffset
extern NvnProc Unk_27fcce0;  // nvnTextureGetFlags
extern int (*Unk_27fcce8)(const void* texture);  // nvnTextureGetTarget
inline int nvnTextureGetTarget(const void* texture) {
    return Unk_27fcce8(texture);
}
extern int (*Unk_27fccf0)(const void* texture);  // nvnTextureGetWidth
inline int nvnTextureGetWidth(const void* texture) {
    return Unk_27fccf0(texture);
}
extern int (*Unk_27fccf8)(const void* texture);  // nvnTextureGetHeight
inline int nvnTextureGetHeight(const void* texture) {
    return Unk_27fccf8(texture);
}
extern int (*Unk_27fcd00)(const void* texture);  // nvnTextureGetDepth
inline int nvnTextureGetDepth(const void* texture) {
    return Unk_27fcd00(texture);
}
extern NvnProc Unk_27fcd08;  // nvnTextureGetLevels
extern int (*Unk_27fcd10)(const void* texture);  // nvnTextureGetFormat
inline int nvnTextureGetFormat(const void* texture) {
    return Unk_27fcd10(texture);
}
extern NvnProc Unk_27fcd18;  // nvnTextureGetSamples
extern NvnProc Unk_27fcd20;  // nvnTextureGetSwizzle
extern NvnProc Unk_27fcd28;  // nvnTextureGetDepthStencilMode
extern NvnProc Unk_27fcd30;  // nvnTextureGetStride
extern NvnProc Unk_27fcd38;  // nvnTextureGetTextureAddress
extern NvnProc Unk_27fcd40;  // nvnTextureGetSparseTileLayout
extern NvnProc Unk_27fcd48;  // nvnTextureWriteTexels
extern NvnProc Unk_27fcd50;  // nvnTextureWriteTexelsStrided
extern NvnProc Unk_27fcd58;  // nvnTextureReadTexels
extern NvnProc Unk_27fcd60;  // nvnTextureReadTexelsStrided
extern NvnProc Unk_27fcd68;  // nvnTextureFlushTexels
extern NvnProc Unk_27fcd70;  // nvnTextureInvalidateTexels
extern NvnProc Unk_27fcd78;  // nvnTextureGetMemoryPool
extern NvnProc Unk_27fcd80;  // nvnTextureGetMemoryOffset
extern NvnProc Unk_27fcd88;  // nvnTextureGetStorageSize
extern NvnProc Unk_27fcd90;  // nvnTextureCompare
extern NvnProc Unk_27fcd98;  // nvnTextureGetDebugID
extern NvnProc Unk_27fcda0;  // nvnTextureGetRawStorageClass
extern void (*Unk_27fcda8)(void* builder, void* device);  // nvnSamplerBuilderSetDevice
inline void nvnSamplerBuilderSetDevice(void* builder, void* device) {
    Unk_27fcda8(builder, device);
}
extern void (*Unk_27fcdb0)(void* builder);  // nvnSamplerBuilderSetDefaults
inline void nvnSamplerBuilderSetDefaults(void* builder) {
    Unk_27fcdb0(builder);
}
extern void (*Unk_27fcdb8)(void* builder, int minFilter, int magFilter);  // nvnSamplerBuilderSetMinMagFilter
inline void nvnSamplerBuilderSetMinMagFilter(void* builder, int minFilter, int magFilter) {
    Unk_27fcdb8(builder, minFilter, magFilter);
}
extern void (*Unk_27fcdc0)(void* builder, int s, int t, int r);  // nvnSamplerBuilderSetWrapMode
inline void nvnSamplerBuilderSetWrapMode(void* builder, int s, int t, int r) {
    Unk_27fcdc0(builder, s, t, r);
}
extern void (*Unk_27fcdc8)(void* builder, float minimum, float maximum);  // nvnSamplerBuilderSetLodClamp
inline void nvnSamplerBuilderSetLodClamp(void* builder, float minimum, float maximum) {
    Unk_27fcdc8(builder, minimum, maximum);
}
extern void (*Unk_27fcdd0)(void* builder, float bias);  // nvnSamplerBuilderSetLodBias
inline void nvnSamplerBuilderSetLodBias(void* builder, float bias) {
    Unk_27fcdd0(builder, bias);
}
extern void (*Unk_27fcdd8)(void* builder, int mode, int function);  // nvnSamplerBuilderSetCompare
inline void nvnSamplerBuilderSetCompare(void* builder, int mode, int function) {
    Unk_27fcdd8(builder, mode, function);
}
extern void (*Unk_27fcde0)(void* builder, const float* color);  // nvnSamplerBuilderSetBorderColor
inline void nvnSamplerBuilderSetBorderColor(void* builder, const float* color) {
    Unk_27fcde0(builder, color);
}
extern NvnProc Unk_27fcde8;  // nvnSamplerBuilderSetBorderColori
extern NvnProc Unk_27fcdf0;  // nvnSamplerBuilderSetBorderColorui
extern void (*Unk_27fcdf8)(void* builder, float maximum);  // nvnSamplerBuilderSetMaxAnisotropy
inline void nvnSamplerBuilderSetMaxAnisotropy(void* builder, float maximum) {
    Unk_27fcdf8(builder, maximum);
}
extern void (*Unk_27fce00)(void* builder, int filter);  // nvnSamplerBuilderSetReductionFilter
inline void nvnSamplerBuilderSetReductionFilter(void* builder, int filter) {
    Unk_27fce00(builder, filter);
}
extern NvnProc Unk_27fce08;  // nvnSamplerBuilderSetLodSnap
extern NvnProc Unk_27fce10;  // nvnSamplerBuilderGetDevice
extern NvnProc Unk_27fce18;  // nvnSamplerBuilderGetMinMagFilter
extern NvnProc Unk_27fce20;  // nvnSamplerBuilderGetWrapMode
extern NvnProc Unk_27fce28;  // nvnSamplerBuilderGetLodClamp
extern NvnProc Unk_27fce30;  // nvnSamplerBuilderGetLodBias
extern NvnProc Unk_27fce38;  // nvnSamplerBuilderGetCompare
extern NvnProc Unk_27fce40;  // nvnSamplerBuilderGetBorderColor
extern NvnProc Unk_27fce48;  // nvnSamplerBuilderGetBorderColori
extern NvnProc Unk_27fce50;  // nvnSamplerBuilderGetBorderColorui
extern NvnProc Unk_27fce58;  // nvnSamplerBuilderGetMaxAnisotropy
extern NvnProc Unk_27fce60;  // nvnSamplerBuilderGetReductionFilter
extern NvnProc Unk_27fce68;  // nvnSamplerBuilderGetLodSnap
extern NvnBoolean (*Unk_27fce70)(void* sampler, const void* builder);  // nvnSamplerInitialize
inline NvnBoolean nvnSamplerInitialize(void* sampler, const void* builder) {
    return Unk_27fce70(sampler, builder);
}
extern void (*Unk_27fce78)(void* sampler);  // nvnSamplerFinalize
inline void nvnSamplerFinalize(void* sampler) {
    Unk_27fce78(sampler);
}
extern void (*Unk_27fce80)(void* sampler, const char* label);  // nvnSamplerSetDebugLabel
inline void nvnSamplerSetDebugLabel(void* sampler, const char* label) {
    Unk_27fce80(sampler, label);
}
extern NvnProc Unk_27fce88;  // nvnSamplerGetMinMagFilter
extern NvnProc Unk_27fce90;  // nvnSamplerGetWrapMode
extern NvnProc Unk_27fce98;  // nvnSamplerGetLodClamp
extern NvnProc Unk_27fcea0;  // nvnSamplerGetLodBias
extern NvnProc Unk_27fcea8;  // nvnSamplerGetCompare
extern NvnProc Unk_27fceb0;  // nvnSamplerGetBorderColor
extern NvnProc Unk_27fceb8;  // nvnSamplerGetBorderColori
extern NvnProc Unk_27fcec0;  // nvnSamplerGetBorderColorui
extern NvnProc Unk_27fcec8;  // nvnSamplerGetMaxAnisotropy
extern NvnProc Unk_27fced0;  // nvnSamplerGetReductionFilter
extern NvnProc Unk_27fced8;  // nvnSamplerCompare
extern NvnProc Unk_27fcee0;  // nvnSamplerGetDebugID
extern void (*Unk_27fcee8)(void* state);  // nvnBlendStateSetDefaults
inline void nvnBlendStateSetDefaults(void* state) {
    Unk_27fcee8(state);
}
extern void (*Unk_27fcef0)(void* state, int index);  // nvnBlendStateSetBlendTarget
inline void nvnBlendStateSetBlendTarget(void* state, int index) {
    Unk_27fcef0(state, index);
}
extern void (*Unk_27fcef8)(void* state, int srcColor, int dstColor, int srcAlpha, int dstAlpha);  // nvnBlendStateSetBlendFunc
inline void nvnBlendStateSetBlendFunc(void* state, int srcColor, int dstColor, int srcAlpha, int dstAlpha) {
    Unk_27fcef8(state, srcColor, dstColor, srcAlpha, dstAlpha);
}
extern void (*Unk_27fcf00)(void* state, int color, int alpha);  // nvnBlendStateSetBlendEquation
inline void nvnBlendStateSetBlendEquation(void* state, int color, int alpha) {
    Unk_27fcf00(state, color, alpha);
}
extern NvnProc Unk_27fcf08;  // nvnBlendStateSetAdvancedMode
extern NvnProc Unk_27fcf10;  // nvnBlendStateSetAdvancedOverlap
extern NvnProc Unk_27fcf18;  // nvnBlendStateSetAdvancedPremultipliedSrc
extern NvnProc Unk_27fcf20;  // nvnBlendStateSetAdvancedNormalizedDst
extern NvnProc Unk_27fcf28;  // nvnBlendStateGetBlendTarget
extern NvnProc Unk_27fcf30;  // nvnBlendStateGetBlendFunc
extern NvnProc Unk_27fcf38;  // nvnBlendStateGetBlendEquation
extern NvnProc Unk_27fcf40;  // nvnBlendStateGetAdvancedMode
extern NvnProc Unk_27fcf48;  // nvnBlendStateGetAdvancedOverlap
extern NvnProc Unk_27fcf50;  // nvnBlendStateGetAdvancedPremultipliedSrc
extern NvnProc Unk_27fcf58;  // nvnBlendStateGetAdvancedNormalizedDst
extern void (*Unk_27fcf60)(void* state);  // nvnColorStateSetDefaults
inline void nvnColorStateSetDefaults(void* state) {
    Unk_27fcf60(state);
}
extern void (*Unk_27fcf68)(void* state, int index, NvnBoolean enable);  // nvnColorStateSetBlendEnable
inline void nvnColorStateSetBlendEnable(void* state, int index, NvnBoolean enable) {
    Unk_27fcf68(state, index, enable);
}
extern void (*Unk_27fcf70)(void* state, int op);  // nvnColorStateSetLogicOp
inline void nvnColorStateSetLogicOp(void* state, int op) {
    Unk_27fcf70(state, op);
}
extern NvnProc Unk_27fcf78;  // nvnColorStateSetAlphaTest
extern NvnProc Unk_27fcf80;  // nvnColorStateGetBlendEnable
extern NvnProc Unk_27fcf88;  // nvnColorStateGetLogicOp
extern NvnProc Unk_27fcf90;  // nvnColorStateGetAlphaTest
extern void (*Unk_27fcf98)(void* state);  // nvnChannelMaskStateSetDefaults
inline void nvnChannelMaskStateSetDefaults(void* state) {
    Unk_27fcf98(state);
}
extern void (*Unk_27fcfa0)(void* state, int index, NvnBoolean r, NvnBoolean g, NvnBoolean b, NvnBoolean a);  // nvnChannelMaskStateSetChannelMask
inline void nvnChannelMaskStateSetChannelMask(void* state, int index, NvnBoolean r, NvnBoolean g, NvnBoolean b, NvnBoolean a) {
    Unk_27fcfa0(state, index, r, g, b, a);
}
extern NvnProc Unk_27fcfa8;  // nvnChannelMaskStateGetChannelMask
extern void (*Unk_27fcfb0)(void* state);  // nvnMultisampleStateSetDefaults
inline void nvnMultisampleStateSetDefaults(void* state) {
    Unk_27fcfb0(state);
}
extern void (*Unk_27fcfb8)(void* state, NvnBoolean enable);  // nvnMultisampleStateSetMultisampleEnable
inline void nvnMultisampleStateSetMultisampleEnable(void* state, NvnBoolean enable) {
    Unk_27fcfb8(state, enable);
}
extern void (*Unk_27fcfc0)(void* state, int samples);  // nvnMultisampleStateSetSamples
inline void nvnMultisampleStateSetSamples(void* state, int samples) {
    Unk_27fcfc0(state, samples);
}
extern void (*Unk_27fcfc8)(void* state, NvnBoolean enable);  // nvnMultisampleStateSetAlphaToCoverageEnable
inline void nvnMultisampleStateSetAlphaToCoverageEnable(void* state, NvnBoolean enable) {
    Unk_27fcfc8(state, enable);
}
extern NvnProc Unk_27fcfd0;  // nvnMultisampleStateSetAlphaToCoverageDither
extern NvnProc Unk_27fcfd8;  // nvnMultisampleStateGetMultisampleEnable
extern NvnProc Unk_27fcfe0;  // nvnMultisampleStateGetSamples
extern NvnProc Unk_27fcfe8;  // nvnMultisampleStateGetAlphaToCoverageEnable
extern NvnProc Unk_27fcff0;  // nvnMultisampleStateGetAlphaToCoverageDither
extern NvnProc Unk_27fcff8;  // nvnMultisampleStateSetRasterSamples
extern NvnProc Unk_27fd000;  // nvnMultisampleStateGetRasterSamples
extern NvnProc Unk_27fd008;  // nvnMultisampleStateSetCoverageModulationMode
extern NvnProc Unk_27fd010;  // nvnMultisampleStateGetCoverageModulationMode
extern NvnProc Unk_27fd018;  // nvnMultisampleStateSetCoverageToColorEnable
extern NvnProc Unk_27fd020;  // nvnMultisampleStateGetCoverageToColorEnable
extern NvnProc Unk_27fd028;  // nvnMultisampleStateSetCoverageToColorOutput
extern NvnProc Unk_27fd030;  // nvnMultisampleStateGetCoverageToColorOutput
extern NvnProc Unk_27fd038;  // nvnMultisampleStateSetSampleLocationsEnable
extern NvnProc Unk_27fd040;  // nvnMultisampleStateGetSampleLocationsEnable
extern NvnProc Unk_27fd048;  // nvnMultisampleStateGetSampleLocationsGrid
extern NvnProc Unk_27fd050;  // nvnMultisampleStateSetSampleLocationsGridEnable
extern NvnProc Unk_27fd058;  // nvnMultisampleStateGetSampleLocationsGridEnable
extern NvnProc Unk_27fd060;  // nvnMultisampleStateSetSampleLocations
extern void (*Unk_27fd068)(void* state);  // nvnPolygonStateSetDefaults
inline void nvnPolygonStateSetDefaults(void* state) {
    Unk_27fd068(state);
}
extern void (*Unk_27fd070)(void* state, int face);  // nvnPolygonStateSetCullFace
inline void nvnPolygonStateSetCullFace(void* state, int face) {
    Unk_27fd070(state, face);
}
extern void (*Unk_27fd078)(void* state, int face);  // nvnPolygonStateSetFrontFace
inline void nvnPolygonStateSetFrontFace(void* state, int face) {
    Unk_27fd078(state, face);
}
extern void (*Unk_27fd080)(void* state, int mode);  // nvnPolygonStateSetPolygonMode
inline void nvnPolygonStateSetPolygonMode(void* state, int mode) {
    Unk_27fd080(state, mode);
}
extern void (*Unk_27fd088)(void* state, int enables);  // nvnPolygonStateSetPolygonOffsetEnables
inline void nvnPolygonStateSetPolygonOffsetEnables(void* state, int enables) {
    Unk_27fd088(state, enables);
}
extern NvnProc Unk_27fd090;  // nvnPolygonStateGetCullFace
extern NvnProc Unk_27fd098;  // nvnPolygonStateGetFrontFace
extern NvnProc Unk_27fd0a0;  // nvnPolygonStateGetPolygonMode
extern NvnProc Unk_27fd0a8;  // nvnPolygonStateGetPolygonOffsetEnables
extern void (*Unk_27fd0b0)(void* state);  // nvnDepthStencilStateSetDefaults
inline void nvnDepthStencilStateSetDefaults(void* state) {
    Unk_27fd0b0(state);
}
extern void (*Unk_27fd0b8)(void* state, NvnBoolean enable);  // nvnDepthStencilStateSetDepthTestEnable
inline void nvnDepthStencilStateSetDepthTestEnable(void* state, NvnBoolean enable) {
    Unk_27fd0b8(state, enable);
}
extern void (*Unk_27fd0c0)(void* state, NvnBoolean enable);  // nvnDepthStencilStateSetDepthWriteEnable
inline void nvnDepthStencilStateSetDepthWriteEnable(void* state, NvnBoolean enable) {
    Unk_27fd0c0(state, enable);
}
extern void (*Unk_27fd0c8)(void* state, int function);  // nvnDepthStencilStateSetDepthFunc
inline void nvnDepthStencilStateSetDepthFunc(void* state, int function) {
    Unk_27fd0c8(state, function);
}
extern void (*Unk_27fd0d0)(void* state, NvnBoolean enable);  // nvnDepthStencilStateSetStencilTestEnable
inline void nvnDepthStencilStateSetStencilTestEnable(void* state, NvnBoolean enable) {
    Unk_27fd0d0(state, enable);
}
extern void (*Unk_27fd0d8)(void* state, int faces, int function);  // nvnDepthStencilStateSetStencilFunc
inline void nvnDepthStencilStateSetStencilFunc(void* state, int faces, int function) {
    Unk_27fd0d8(state, faces, function);
}
extern void (*Unk_27fd0e0)(void* state, int faces, int fail, int depthFail, int depthPass);  // nvnDepthStencilStateSetStencilOp
inline void nvnDepthStencilStateSetStencilOp(void* state, int faces, int fail, int depthFail, int depthPass) {
    Unk_27fd0e0(state, faces, fail, depthFail, depthPass);
}
extern NvnProc Unk_27fd0e8;  // nvnDepthStencilStateGetDepthTestEnable
extern NvnProc Unk_27fd0f0;  // nvnDepthStencilStateGetDepthWriteEnable
extern NvnProc Unk_27fd0f8;  // nvnDepthStencilStateGetDepthFunc
extern NvnProc Unk_27fd100;  // nvnDepthStencilStateGetStencilTestEnable
extern NvnProc Unk_27fd108;  // nvnDepthStencilStateGetStencilFunc
extern NvnProc Unk_27fd110;  // nvnDepthStencilStateGetStencilOp
extern NvnProc Unk_27fd118;  // nvnVertexAttribStateSetDefaults
extern NvnProc Unk_27fd120;  // nvnVertexAttribStateSetFormat
extern NvnProc Unk_27fd128;  // nvnVertexAttribStateSetStreamIndex
extern NvnProc Unk_27fd130;  // nvnVertexAttribStateGetFormat
extern NvnProc Unk_27fd138;  // nvnVertexAttribStateGetStreamIndex
extern NvnProc Unk_27fd140;  // nvnVertexStreamStateSetDefaults
extern NvnProc Unk_27fd148;  // nvnVertexStreamStateSetStride
extern NvnProc Unk_27fd150;  // nvnVertexStreamStateSetDivisor
extern NvnProc Unk_27fd158;  // nvnVertexStreamStateGetStride
extern NvnProc Unk_27fd160;  // nvnVertexStreamStateGetDivisor
extern bool (*Unk_27fd168)(void* commandBuffer, void* device);  // nvnCommandBufferInitialize
inline bool nvnCommandBufferInitialize(void* commandBuffer, void* device) {
    return Unk_27fd168(commandBuffer, device);
}
extern void (*Unk_27fd170)(void* commandBuffer);  // nvnCommandBufferFinalize
inline void nvnCommandBufferFinalize(void* commandBuffer) {
    Unk_27fd170(commandBuffer);
}
extern NvnProc Unk_27fd178;  // nvnCommandBufferSetDebugLabel
extern void (*Unk_27fd180)(void* commandBuffer, void (*callback)(void* commandBuffer, int event, size_t minSize, void* data));  // nvnCommandBufferSetMemoryCallback
inline void nvnCommandBufferSetMemoryCallback(void* commandBuffer, void (*callback)(void* commandBuffer, int event, size_t minSize, void* data)) {
    Unk_27fd180(commandBuffer, callback);
}
extern void (*Unk_27fd188)(void* commandBuffer, void* data);  // nvnCommandBufferSetMemoryCallbackData
inline void nvnCommandBufferSetMemoryCallbackData(void* commandBuffer, void* data) {
    Unk_27fd188(commandBuffer, data);
}
extern NvnProc Unk_27fd190;  // nvnCommandBufferSetCommandMemoryCallbackEnabled
extern void (*Unk_27fd198)(void* commandBuffer, const void* pool, s64 offset, size_t size);  // nvnCommandBufferAddCommandMemory
inline void nvnCommandBufferAddCommandMemory(void* commandBuffer, const void* pool, s64 offset, size_t size) {
    Unk_27fd198(commandBuffer, pool, offset, size);
}
extern void (*Unk_27fd1a0)(void* commandBuffer, void* memory, size_t size);  // nvnCommandBufferAddControlMemory
inline void nvnCommandBufferAddControlMemory(void* commandBuffer, void* memory, size_t size) {
    Unk_27fd1a0(commandBuffer, memory, size);
}
extern NvnProc Unk_27fd1a8;  // nvnCommandBufferGetCommandMemorySize
extern NvnProc Unk_27fd1b0;  // nvnCommandBufferGetCommandMemoryUsed
extern NvnProc Unk_27fd1b8;  // nvnCommandBufferGetCommandMemoryFree
extern NvnProc Unk_27fd1c0;  // nvnCommandBufferGetControlMemorySize
extern NvnProc Unk_27fd1c8;  // nvnCommandBufferGetControlMemoryUsed
extern NvnProc Unk_27fd1d0;  // nvnCommandBufferGetControlMemoryFree
extern void (*Unk_27fd1d8)(void* commandBuffer);  // nvnCommandBufferBeginRecording
inline void nvnCommandBufferBeginRecording(void* commandBuffer) {
    Unk_27fd1d8(commandBuffer);
}
extern u64 (*Unk_27fd1e0)(void* commandBuffer);  // nvnCommandBufferEndRecording
inline u64 nvnCommandBufferEndRecording(void* commandBuffer) {
    return Unk_27fd1e0(commandBuffer);
}
extern void (*Unk_27fd1e8)(void* commandBuffer, int count, const u64* handles);  // nvnCommandBufferCallCommands
inline void nvnCommandBufferCallCommands(void* commandBuffer, int count, const u64* handles) {
    Unk_27fd1e8(commandBuffer, count, handles);
}
extern NvnProc Unk_27fd1f0;  // nvnCommandBufferCopyCommands
extern void (*Unk_27fd1f8)(void* commandBuffer, const void* state);  // nvnCommandBufferBindBlendState
inline void nvnCommandBufferBindBlendState(void* commandBuffer, const void* state) {
    Unk_27fd1f8(commandBuffer, state);
}
extern void (*Unk_27fd200)(void* commandBuffer, const void* state);  // nvnCommandBufferBindChannelMaskState
inline void nvnCommandBufferBindChannelMaskState(void* commandBuffer, const void* state) {
    Unk_27fd200(commandBuffer, state);
}
extern void (*Unk_27fd208)(void* commandBuffer, const void* state);  // nvnCommandBufferBindColorState
inline void nvnCommandBufferBindColorState(void* commandBuffer, const void* state) {
    Unk_27fd208(commandBuffer, state);
}
extern void (*Unk_27fd210)(void* commandBuffer, const void* state);  // nvnCommandBufferBindMultisampleState
inline void nvnCommandBufferBindMultisampleState(void* commandBuffer, const void* state) {
    Unk_27fd210(commandBuffer, state);
}
extern void (*Unk_27fd218)(void* commandBuffer, const void* state);  // nvnCommandBufferBindPolygonState
inline void nvnCommandBufferBindPolygonState(void* commandBuffer, const void* state) {
    Unk_27fd218(commandBuffer, state);
}
extern void (*Unk_27fd220)(void* commandBuffer, const void* state);  // nvnCommandBufferBindDepthStencilState
inline void nvnCommandBufferBindDepthStencilState(void* commandBuffer, const void* state) {
    Unk_27fd220(commandBuffer, state);
}
extern void (*Unk_27fd228)(void* commandBuffer, int count, const void* states);  // nvnCommandBufferBindVertexAttribState
inline void nvnCommandBufferBindVertexAttribState(void* commandBuffer, int count, const void* states) {
    Unk_27fd228(commandBuffer, count, states);
}
extern void (*Unk_27fd230)(void* commandBuffer, int count, const void* states);  // nvnCommandBufferBindVertexStreamState
inline void nvnCommandBufferBindVertexStreamState(void* commandBuffer, int count, const void* states) {
    Unk_27fd230(commandBuffer, count, states);
}
extern void (*Unk_27fd238)(void* commandBuffer, const void* program, int stages);  // nvnCommandBufferBindProgram
inline void nvnCommandBufferBindProgram(void* commandBuffer, const void* program, int stages) {
    Unk_27fd238(commandBuffer, program, stages);
}
extern void (*Unk_27fd240)(void* commandBuffer, int index, u64 address, size_t size);  // nvnCommandBufferBindVertexBuffer
inline void nvnCommandBufferBindVertexBuffer(void* commandBuffer, int index, u64 address, size_t size) {
    Unk_27fd240(commandBuffer, index, address, size);
}
extern NvnProc Unk_27fd248;  // nvnCommandBufferBindVertexBuffers
extern void (*Unk_27fd250)(void* commandBuffer, int stage, int index, u64 address, size_t size);  // nvnCommandBufferBindUniformBuffer
inline void nvnCommandBufferBindUniformBuffer(void* commandBuffer, int stage, int index, u64 address, size_t size) {
    Unk_27fd250(commandBuffer, stage, index, address, size);
}
extern NvnProc Unk_27fd258;  // nvnCommandBufferBindUniformBuffers
extern NvnProc Unk_27fd260;  // nvnCommandBufferBindTransformFeedbackBuffer
extern NvnProc Unk_27fd268;  // nvnCommandBufferBindTransformFeedbackBuffers
extern void (*Unk_27fd270)(void* commandBuffer, int stage, int index, u64 address, size_t size);  // nvnCommandBufferBindStorageBuffer
inline void nvnCommandBufferBindStorageBuffer(void* commandBuffer, int stage, int index, u64 address, size_t size) {
    Unk_27fd270(commandBuffer, stage, index, address, size);
}
extern NvnProc Unk_27fd278;  // nvnCommandBufferBindStorageBuffers
extern void (*Unk_27fd280)(void* commandBuffer, int stage, int index, u64 handle);  // nvnCommandBufferBindTexture
inline void nvnCommandBufferBindTexture(void* commandBuffer, int stage, int index, u64 handle) {
    Unk_27fd280(commandBuffer, stage, index, handle);
}
extern NvnProc Unk_27fd288;  // nvnCommandBufferBindTextures
extern NvnProc Unk_27fd290;  // nvnCommandBufferBindImage
extern NvnProc Unk_27fd298;  // nvnCommandBufferBindImages
extern NvnProc Unk_27fd2a0;  // nvnCommandBufferSetPatchSize
extern NvnProc Unk_27fd2a8;  // nvnCommandBufferSetInnerTessellationLevels
extern NvnProc Unk_27fd2b0;  // nvnCommandBufferSetOuterTessellationLevels
extern NvnProc Unk_27fd2b8;  // nvnCommandBufferSetPrimitiveRestart
extern NvnProc Unk_27fd2c0;  // nvnCommandBufferBeginTransformFeedback
extern NvnProc Unk_27fd2c8;  // nvnCommandBufferEndTransformFeedback
extern NvnProc Unk_27fd2d0;  // nvnCommandBufferPauseTransformFeedback
extern NvnProc Unk_27fd2d8;  // nvnCommandBufferResumeTransformFeedback
extern NvnProc Unk_27fd2e0;  // nvnCommandBufferDrawTransformFeedback
extern void (*Unk_27fd2e8)(void* commandBuffer, int mode, int first, int count);  // nvnCommandBufferDrawArrays
inline void nvnCommandBufferDrawArrays(void* commandBuffer, int mode, int first, int count) {
    Unk_27fd2e8(commandBuffer, mode, first, count);
}
extern NvnProc Unk_27fd2f0;  // nvnCommandBufferDrawElements
extern void (*Unk_27fd2f8)(void* commandBuffer, int mode, int type, int count, u64 indexBuffer, int baseVertex);  // nvnCommandBufferDrawElementsBaseVertex
inline void nvnCommandBufferDrawElementsBaseVertex(void* commandBuffer, int mode, int type, int count, u64 indexBuffer, int baseVertex) {
    Unk_27fd2f8(commandBuffer, mode, type, count, indexBuffer, baseVertex);
}
extern void (*Unk_27fd300)(void* commandBuffer, int mode, int first, int count, int baseInstance, int instanceCount);  // nvnCommandBufferDrawArraysInstanced
inline void nvnCommandBufferDrawArraysInstanced(void* commandBuffer, int mode, int first, int count, int baseInstance, int instanceCount) {
    Unk_27fd300(commandBuffer, mode, first, count, baseInstance, instanceCount);
}
extern void (*Unk_27fd308)(void* commandBuffer, int mode, int type, int count, u64 indexBuffer, int baseVertex, int baseInstance, int instanceCount);  // nvnCommandBufferDrawElementsInstanced
inline void nvnCommandBufferDrawElementsInstanced(void* commandBuffer, int mode, int type, int count, u64 indexBuffer, int baseVertex, int baseInstance, int instanceCount) {
    Unk_27fd308(commandBuffer, mode, type, count, indexBuffer, baseVertex, baseInstance, instanceCount);
}
extern NvnProc Unk_27fd310;  // nvnCommandBufferDrawArraysIndirect
extern NvnProc Unk_27fd318;  // nvnCommandBufferDrawElementsIndirect
extern NvnProc Unk_27fd320;  // nvnCommandBufferMultiDrawArraysIndirectCount
extern NvnProc Unk_27fd328;  // nvnCommandBufferMultiDrawElementsIndirectCount
extern NvnProc Unk_27fd330;  // nvnCommandBufferClearColor
extern NvnProc Unk_27fd338;  // nvnCommandBufferClearColori
extern NvnProc Unk_27fd340;  // nvnCommandBufferClearColorui
extern void (*Unk_27fd348)(void* commandBuffer, float depth, NvnBoolean depthMask, int stencil, int stencilMask);  // nvnCommandBufferClearDepthStencil
inline void nvnCommandBufferClearDepthStencil(void* commandBuffer, float depth, NvnBoolean depthMask, int stencil, int stencilMask) {
    Unk_27fd348(commandBuffer, depth, depthMask, stencil, stencilMask);
}
extern void (*Unk_27fd350)(void* commandBuffer, int x, int y, int z);  // nvnCommandBufferDispatchCompute
inline void nvnCommandBufferDispatchCompute(void* commandBuffer, int x, int y, int z) {
    Unk_27fd350(commandBuffer, x, y, z);
}
extern NvnProc Unk_27fd358;  // nvnCommandBufferDispatchComputeIndirect
extern NvnProc Unk_27fd360;  // nvnCommandBufferSetViewport
extern void (*Unk_27fd368)(void* commandBuffer, int first, int count, const float* viewports);  // nvnCommandBufferSetViewports
inline void nvnCommandBufferSetViewports(void* commandBuffer, int first, int count, const float* viewports) {
    Unk_27fd368(commandBuffer, first, count, viewports);
}
extern NvnProc Unk_27fd370;  // nvnCommandBufferSetViewportSwizzles
extern void (*Unk_27fd378)(void* commandBuffer, int x, int y, int width, int height);  // nvnCommandBufferSetScissor
inline void nvnCommandBufferSetScissor(void* commandBuffer, int x, int y, int width, int height) {
    Unk_27fd378(commandBuffer, x, y, width, height);
}
extern void (*Unk_27fd380)(void* commandBuffer, int first, int count, const int* rects);  // nvnCommandBufferSetScissors
inline void nvnCommandBufferSetScissors(void* commandBuffer, int first, int count, const int* rects) {
    Unk_27fd380(commandBuffer, first, count, rects);
}
extern void (*Unk_27fd388)(void* commandBuffer, float n, float f);  // nvnCommandBufferSetDepthRange
inline void nvnCommandBufferSetDepthRange(void* commandBuffer, float n, float f) {
    Unk_27fd388(commandBuffer, n, f);
}
extern void (*Unk_27fd390)(void* commandBuffer, NvnBoolean enable, float minimum, float maximum);  // nvnCommandBufferSetDepthBounds
inline void nvnCommandBufferSetDepthBounds(void* commandBuffer, NvnBoolean enable, float minimum, float maximum) {
    Unk_27fd390(commandBuffer, enable, minimum, maximum);
}
extern void (*Unk_27fd398)(void* commandBuffer, int first, int count, const float* ranges);  // nvnCommandBufferSetDepthRanges
inline void nvnCommandBufferSetDepthRanges(void* commandBuffer, int first, int count, const float* ranges) {
    Unk_27fd398(commandBuffer, first, count, ranges);
}
extern NvnProc Unk_27fd3a0;  // nvnCommandBufferSetTiledCacheAction
extern NvnProc Unk_27fd3a8;  // nvnCommandBufferSetTiledCacheTileSize
extern NvnProc Unk_27fd3b0;  // nvnCommandBufferBindSeparateTexture
extern NvnProc Unk_27fd3b8;  // nvnCommandBufferBindSeparateSampler
extern NvnProc Unk_27fd3c0;  // nvnCommandBufferBindSeparateTextures
extern NvnProc Unk_27fd3c8;  // nvnCommandBufferBindSeparateSamplers
extern void (*Unk_27fd3d0)(void* commandBuffer, int faces, int mask);  // nvnCommandBufferSetStencilValueMask
inline void nvnCommandBufferSetStencilValueMask(void* commandBuffer, int faces, int mask) {
    Unk_27fd3d0(commandBuffer, faces, mask);
}
extern void (*Unk_27fd3d8)(void* commandBuffer, int faces, int mask);  // nvnCommandBufferSetStencilMask
inline void nvnCommandBufferSetStencilMask(void* commandBuffer, int faces, int mask) {
    Unk_27fd3d8(commandBuffer, faces, mask);
}
extern void (*Unk_27fd3e0)(void* commandBuffer, int faces, int ref);  // nvnCommandBufferSetStencilRef
inline void nvnCommandBufferSetStencilRef(void* commandBuffer, int faces, int ref) {
    Unk_27fd3e0(commandBuffer, faces, ref);
}
extern void (*Unk_27fd3e8)(void* commandBuffer, const float* color);  // nvnCommandBufferSetBlendColor
inline void nvnCommandBufferSetBlendColor(void* commandBuffer, const float* color) {
    Unk_27fd3e8(commandBuffer, color);
}
extern NvnProc Unk_27fd3f0;  // nvnCommandBufferSetPointSize
extern void (*Unk_27fd3f8)(void* commandBuffer, float width);  // nvnCommandBufferSetLineWidth
inline void nvnCommandBufferSetLineWidth(void* commandBuffer, float width) {
    Unk_27fd3f8(commandBuffer, width);
}
extern void (*Unk_27fd400)(void* commandBuffer, float factor, float units, float clamp);  // nvnCommandBufferSetPolygonOffsetClamp
inline void nvnCommandBufferSetPolygonOffsetClamp(void* commandBuffer, float factor, float units, float clamp) {
    Unk_27fd400(commandBuffer, factor, units, clamp);
}
extern NvnProc Unk_27fd408;  // nvnCommandBufferSetAlphaRef
extern void (*Unk_27fd410)(void* commandBuffer, int mask);  // nvnCommandBufferSetSampleMask
inline void nvnCommandBufferSetSampleMask(void* commandBuffer, int mask) {
    Unk_27fd410(commandBuffer, mask);
}
extern void (*Unk_27fd418)(void* commandBuffer, NvnBoolean enable);  // nvnCommandBufferSetRasterizerDiscard
inline void nvnCommandBufferSetRasterizerDiscard(void* commandBuffer, NvnBoolean enable) {
    Unk_27fd418(commandBuffer, enable);
}
extern void (*Unk_27fd420)(void* commandBuffer, NvnBoolean enable);  // nvnCommandBufferSetDepthClamp
inline void nvnCommandBufferSetDepthClamp(void* commandBuffer, NvnBoolean enable) {
    Unk_27fd420(commandBuffer, enable);
}
extern void (*Unk_27fd428)(void* commandBuffer, NvnBoolean enable);  // nvnCommandBufferSetConservativeRasterEnable
inline void nvnCommandBufferSetConservativeRasterEnable(void* commandBuffer, NvnBoolean enable) {
    Unk_27fd428(commandBuffer, enable);
}
extern NvnProc Unk_27fd430;  // nvnCommandBufferSetConservativeRasterDilate
extern NvnProc Unk_27fd438;  // nvnCommandBufferSetSubpixelPrecisionBias
extern void (*Unk_27fd440)(void* commandBuffer, u64 buffer, const void* texture, const void* view, const void* region, int flags);  // nvnCommandBufferCopyBufferToTexture
inline void nvnCommandBufferCopyBufferToTexture(void* commandBuffer, u64 buffer, const void* texture, const void* view, const void* region, int flags) {
    Unk_27fd440(commandBuffer, buffer, texture, view, region, flags);
}
extern void (*Unk_27fd448)(void* commandBuffer, const void* texture, const void* view, const void* region, u64 buffer, int flags);  // nvnCommandBufferCopyTextureToBuffer
inline void nvnCommandBufferCopyTextureToBuffer(void* commandBuffer, const void* texture, const void* view, const void* region, u64 buffer, int flags) {
    Unk_27fd448(commandBuffer, texture, view, region, buffer, flags);
}
extern void (*Unk_27fd450)(void* commandBuffer, const void* src, const void* srcView, const void* srcRegion, const void* dst, const void* dstView, const void* dstRegion, int flags);  // nvnCommandBufferCopyTextureToTexture
inline void nvnCommandBufferCopyTextureToTexture(void* commandBuffer, const void* src, const void* srcView, const void* srcRegion, const void* dst, const void* dstView, const void* dstRegion, int flags) {
    Unk_27fd450(commandBuffer, src, srcView, srcRegion, dst, dstView, dstRegion, flags);
}
extern void (*Unk_27fd458)(void* commandBuffer, u64 src, u64 dst, size_t size, int flags);  // nvnCommandBufferCopyBufferToBuffer
inline void nvnCommandBufferCopyBufferToBuffer(void* commandBuffer, u64 src, u64 dst, size_t size, int flags) {
    Unk_27fd458(commandBuffer, src, dst, size, flags);
}
extern NvnProc Unk_27fd460;  // nvnCommandBufferClearBuffer
extern void (*Unk_27fd468)(void* commandBuffer, const void* texture, const void* view, const void* region, const float* color, int mask);  // nvnCommandBufferClearTexture
inline void nvnCommandBufferClearTexture(void* commandBuffer, const void* texture, const void* view, const void* region, const float* color, int mask) {
    Unk_27fd468(commandBuffer, texture, view, region, color, mask);
}
extern NvnProc Unk_27fd470;  // nvnCommandBufferClearTexturei
extern NvnProc Unk_27fd478;  // nvnCommandBufferClearTextureui
extern NvnProc Unk_27fd480;  // nvnCommandBufferUpdateUniformBuffer
extern void (*Unk_27fd488)(void* commandBuffer, int counter, u64 address);  // nvnCommandBufferReportCounter
inline void nvnCommandBufferReportCounter(void* commandBuffer, int counter, u64 address) {
    Unk_27fd488(commandBuffer, counter, address);
}
extern NvnProc Unk_27fd490;  // nvnCommandBufferResetCounter
extern NvnProc Unk_27fd498;  // nvnCommandBufferReportValue
extern NvnProc Unk_27fd4a0;  // nvnCommandBufferSetRenderEnable
extern NvnProc Unk_27fd4a8;  // nvnCommandBufferSetRenderEnableConditional
extern void (*Unk_27fd4b0)(void* commandBuffer, int count, void* const* colors, void* const* colorViews, void* depthStencil, void* depthStencilView);  // nvnCommandBufferSetRenderTargets
inline void nvnCommandBufferSetRenderTargets(void* commandBuffer, int count, void* const* colors, void* const* colorViews, void* depthStencil, void* depthStencilView) {
    Unk_27fd4b0(commandBuffer, count, colors, colorViews, depthStencil, depthStencilView);
}
extern NvnProc Unk_27fd4b8;  // nvnCommandBufferDiscardColor
extern NvnProc Unk_27fd4c0;  // nvnCommandBufferDiscardDepthStencil
extern void (*Unk_27fd4c8)(void* commandBuffer, const void* src, const void* dst);  // nvnCommandBufferDownsample
inline void nvnCommandBufferDownsample(void* commandBuffer, const void* src, const void* dst) {
    Unk_27fd4c8(commandBuffer, src, dst);
}
extern NvnProc Unk_27fd4d0;  // nvnCommandBufferTiledDownsample
extern NvnProc Unk_27fd4d8;  // nvnCommandBufferDownsampleTextureView
extern NvnProc Unk_27fd4e0;  // nvnCommandBufferTiledDownsampleTextureView
extern void (*Unk_27fd4e8)(void* commandBuffer, int barrier);  // nvnCommandBufferBarrier
inline void nvnCommandBufferBarrier(void* commandBuffer, int barrier) {
    Unk_27fd4e8(commandBuffer, barrier);
}
extern NvnProc Unk_27fd4f0;  // nvnCommandBufferWaitSync
extern NvnProc Unk_27fd4f8;  // nvnCommandBufferFenceSync
extern void (*Unk_27fd500)(void* commandBuffer, const void* pool);  // nvnCommandBufferSetTexturePool
inline void nvnCommandBufferSetTexturePool(void* commandBuffer, const void* pool) {
    Unk_27fd500(commandBuffer, pool);
}
extern void (*Unk_27fd508)(void* commandBuffer, const void* pool);  // nvnCommandBufferSetSamplerPool
inline void nvnCommandBufferSetSamplerPool(void* commandBuffer, const void* pool) {
    Unk_27fd508(commandBuffer, pool);
}
extern NvnProc Unk_27fd510;  // nvnCommandBufferSetShaderScratchMemory
extern NvnProc Unk_27fd518;  // nvnCommandBufferSaveZCullData
extern NvnProc Unk_27fd520;  // nvnCommandBufferRestoreZCullData
extern void (*Unk_27fd528)(void* commandBuffer, s64 stride);  // nvnCommandBufferSetCopyRowStride
inline void nvnCommandBufferSetCopyRowStride(void* commandBuffer, s64 stride) {
    Unk_27fd528(commandBuffer, stride);
}
extern void (*Unk_27fd530)(void* commandBuffer, s64 stride);  // nvnCommandBufferSetCopyImageStride
inline void nvnCommandBufferSetCopyImageStride(void* commandBuffer, s64 stride) {
    Unk_27fd530(commandBuffer, stride);
}
extern NvnProc Unk_27fd538;  // nvnCommandBufferGetCopyRowStride
extern NvnProc Unk_27fd540;  // nvnCommandBufferGetCopyImageStride
extern NvnProc Unk_27fd548;  // nvnCommandBufferDrawTexture
extern NvnProc Unk_27fd550;  // nvnProgramSetSubroutineLinkage
extern NvnProc Unk_27fd558;  // nvnCommandBufferSetProgramSubroutines
extern NvnProc Unk_27fd560;  // nvnCommandBufferBindCoverageModulationTable
extern NvnProc Unk_27fd568;  // nvnCommandBufferResolveDepthBuffer
extern NvnProc Unk_27fd570;  // nvnCommandBufferSetColorReductionEnable
extern NvnProc Unk_27fd578;  // nvnCommandBufferSetColorReductionThresholds
extern NvnProc Unk_27fd580;  // nvnCommandBufferPushDebugGroupStatic
extern NvnProc Unk_27fd588;  // nvnCommandBufferPushDebugGroupDynamic
extern NvnProc Unk_27fd590;  // nvnCommandBufferPushDebugGroup
extern NvnProc Unk_27fd598;  // nvnCommandBufferPopDebugGroup
extern NvnProc Unk_27fd5a0;  // nvnCommandBufferPopDebugGroupId
extern NvnProc Unk_27fd5a8;  // nvnCommandBufferInsertDebugMarkerStatic
extern NvnProc Unk_27fd5b0;  // nvnCommandBufferInsertDebugMarkerDynamic
extern NvnProc Unk_27fd5b8;  // nvnCommandBufferInsertDebugMarker
extern NvnProc Unk_27fd5c0;  // nvnCommandBufferGetMemoryCallback
extern NvnProc Unk_27fd5c8;  // nvnCommandBufferGetMemoryCallbackData
extern NvnProc Unk_27fd5d0;  // nvnCommandBufferIsRecording
extern NvnBoolean (*Unk_27fd5d8)(void* sync, void* device);  // nvnSyncInitialize
inline NvnBoolean nvnSyncInitialize(void* sync, void* device) {
    return Unk_27fd5d8(sync, device);
}
extern void (*Unk_27fd5e0)(void* sync);  // nvnSyncFinalize
inline void nvnSyncFinalize(void* sync) {
    Unk_27fd5e0(sync);
}
extern NvnProc Unk_27fd5e8;  // nvnSyncSetDebugLabel
extern void (*Unk_27fd5f0)(void* queue, void* sync, int condition, int flags);  // nvnQueueFenceSync
inline void nvnQueueFenceSync(void* queue, void* sync, int condition, int flags) {
    Unk_27fd5f0(queue, sync, condition, flags);
}
extern int (*Unk_27fd5f8)(const void* sync, u64 timeout);  // nvnSyncWait
inline int nvnSyncWait(const void* sync, u64 timeout) {
    return Unk_27fd5f8(sync, timeout);
}
extern void (*Unk_27fd600)(void* queue, const void* sync);  // nvnQueueWaitSync
inline void nvnQueueWaitSync(void* queue, const void* sync) {
    Unk_27fd600(queue, sync);
}
extern NvnProc Unk_27fd608;  // nvnSyncInitializeFromFencedGLSync
extern NvnProc Unk_27fd610;  // nvnSyncCreateGLSync
extern NvnProc Unk_27fd618;  // nvnEventBuilderSetDefaults
extern NvnProc Unk_27fd620;  // nvnEventBuilderSetStorage
extern NvnProc Unk_27fd628;  // nvnEventBuilderGetStorage
extern NvnProc Unk_27fd630;  // nvnEventInitialize
extern NvnProc Unk_27fd638;  // nvnEventFinalize
extern NvnProc Unk_27fd640;  // nvnEventGetValue
extern NvnProc Unk_27fd648;  // nvnEventSignal
extern NvnProc Unk_27fd650;  // nvnCommandBufferWaitEvent
extern NvnProc Unk_27fd658;  // nvnCommandBufferSignalEvent
extern NvnProc Unk_27fd660;  // nvnCommandBufferSetStencilCullCriteria
