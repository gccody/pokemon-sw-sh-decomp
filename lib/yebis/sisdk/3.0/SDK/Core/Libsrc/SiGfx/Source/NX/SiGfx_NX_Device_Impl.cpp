// Scope: common
// SiSDK3::SiGfxNXDevice: the device of SiGfx's NVN back end. It makes the
// pools of each kind of resource and the objects that aren't pooled (command
// lists, pipeline states, memory heaps, ...), and holds the default canvases.
// The reference counts are its header's.
#define UNK_SIGFX_NX_DEVICE_IMPL
#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiGfx/Source/NX/SiGfx_NX_Device_Impl.h>

#include <nx_middleware/gfx/nvn.h>
#include <string.h>

#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/Unk_Alloc.h>
#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiGfx/Source/NX/SiGfx_NX_Manager_Impl.h>
#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiGfx/Source/NX/Unk_DeviceObjects.h>
#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiGfx/Source/NX/Unk_Pools.h>

// 0x71004cbf40 (leafgen's name and type): SiGfx's kernel
u64 Unk_4cbf40_get();
// 0x71004c5a90: snprintf
int Unk_4c5a90(char* buffer, size_t size, const char* format, ...);
// 0x7100539890 (leafgen's name and type): what the device's shutdown ends with
void Unk_539890_update();
// 0x71005644d0 (leafgen's name; it is the vertex format pool's function, and
// takes the pool)
u64 Unk_5644d0_get(u64 pool);
// 0x71004cddb0 (leafgen's name and types): takes a device out of the object
// that keeps the resources to destroy later
struct Unk_4cddb0;
struct Unk_4cddb0_arg1;
void Unk_4cddb0_call(Unk_4cddb0* self, Unk_4cddb0_arg1* value);
// 0x7100539840: loads NVN's entry points (it takes an allocator and a number
// it doesn't use: the device passes them)
bool Unk_539840(SiSDK3::ISiAllocator* pAllocator, s32 a2);
// 0x71004f7190 (leafgen's name and type): the NVN device's debug callback
void Unk_4f7190_update();
// 0x71004ecf40: the format of a kind's case (Unk_4ecbc0.cpp)
u32 Unk_4ecf40(s32 kind, s32 index);
// 0x71004cbec0: that object (Unk_RefCountDeferred.h's declaration)
void* Unk_4cbec0();

// NVN's entry points that only the device calls (nvn.h has them without
// their types).
inline void Unk_nvnDeviceSetWindowOriginMode(void* device, int mode) {
    reinterpret_cast<void (*)(void*, int)>(Unk_27fc6e0)(device, mode);
}
inline void Unk_nvnDeviceSetDepthMode(void* device, int mode) {
    reinterpret_cast<void (*)(void*, int)>(Unk_27fc6e8)(device, mode);
}
inline void Unk_nvnDeviceInstallDebugCallback(void* device, void (*callback)(), void* user, int enable) {
    reinterpret_cast<void (*)(void*, void (*)(), void*, int)>(Unk_27fc6d0)(device, callback, user, enable);
}
inline int Unk_nvnDeviceGetWindowOriginMode(void* device) {
    return reinterpret_cast<int (*)(void*)>(Unk_27fc710)(device);
}
inline int Unk_nvnDeviceGetDepthMode(void* device) {
    return reinterpret_cast<int (*)(void*)>(Unk_27fc718)(device);
}

// Releases an object and clears the pointer to it (placeholder name).
#define UNK_SAFE_RELEASE(p)   \
    if ((p) != nullptr) {     \
        (p)->vf3();           \
        (p) = nullptr;        \
    }

// What the functions of other translation units that the device calls are
// declared as here (placeholder names; the classes they are members of are
// those translation units').
// 0x71004fb4b0
template bool SiSDK3::SiArray<SiSDK3::SiGfxNXMemoryHeap*, 16>::Unk_4bf190(size_t, bool);

namespace SiSDK3 {

class SiGfxNXBuffer;
class SiGfxNXFont;
class SiGfxNXQuery;
class SiGfxNXRenderTarget;
class SiGfxNXSampler;
class SiGfxNXShader;
class SiGfxNXShaderProgram;
class SiGfxNXSurface;
class SiGfxNXTexture;
class SiGfxNXVertexFormat;

// each pool's function that makes a resource
SiGfxNXVertexFormat* Unk_563810(SiGfxNXVertexFormatPool* pool, ISiAllocator* pAllocator, const void* desc);
SiGfxNXShader* Unk_559500(SiGfxNXShaderPool* pool, ISiAllocator* pAllocator, u32 a1, const void* desc);
SiGfxNXShaderProgram* Unk_5598b0(SiGfxNXShaderProgramPool* pool, ISiAllocator* pAllocator, const void* desc);
SiGfxNXTexture* Unk_55d6c0(SiGfxNXTexturePool* pool, ISiAllocator* pAllocator, u32 a1, const void* desc);
SiGfxNXSampler* Unk_5589e0(SiGfxNXSamplerPool* pool, ISiAllocator* pAllocator, const void* desc, u64 a2);
SiGfxNXFont* Unk_4fed10(SiGfxNXFontPool* pool, ISiAllocator* pAllocator, const void* desc);
SiGfxNXBuffer* Unk_536dc0(SiGfxNXBufferPool* pool, ISiAllocator* pAllocator, const void* desc);
SiGfxNXCanvas* Unk_538f60(SiGfxNXCanvasPool* pool, ISiAllocator* pAllocator, const void* desc);
SiGfxNXQuery* Unk_5545f0(SiGfxNXQueryPool* pool, ISiAllocator* pAllocator, const void* desc);
SiGfxNXSurface* Unk_55c330(SiGfxNXSurfacePool* pool, ISiAllocator* pAllocator, const void* desc);
SiGfxNXRenderTarget* Unk_555450(SiGfxNXRenderTargetPool* pool, ISiAllocator* pAllocator, const void* desc);
// 0x7100539160: the canvas pool's canvas of a window
SiGfxNXCanvas* Unk_539160(SiGfxNXCanvasPool* pool, u64 window);
// 0x71004e7680: tells the shader effects that a device is going away
void Unk_4e7680(void* effects, SiGfxNXDevice* pDevice);

// The shader programs' pool as the device uses it (its class has the slots
// its own translation unit shows): what slots 78 and 79 of the device call.
class Unk_4fa530_Pool {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
    virtual void vf14();
    virtual void vf15();
    virtual void vf16();
    virtual void vf17();
    virtual void vf18();
    virtual void vf19();
};
inline Unk_4fa530_Pool* Unk_View(SiGfxNXShaderProgramPool* pool) {
    return reinterpret_cast<Unk_4fa530_Pool*>(pool);
}

// A resource as the device uses it: slot 8 is what tells its kind.
class Unk_4f9640_Resource {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual const u32* vf8();
};

// The single-object delete of a pointer that isn't null, which its caller
// clears (inline in every caller: placeholder names).
template <class T>
inline void Unk_Delete(ISiAllocator* pAllocator, T* p, const char* file, int line) {
    if (pAllocator != nullptr) {
        p->~T();
        pAllocator->vf9(p, file, line);
    }
}
#define UNK_SAFE_DELETE(allocator, p)                              \
    if ((p) != nullptr) {                                          \
        ::SiSDK3::Unk_Delete(allocator, p, __FILE__, __LINE__);    \
        (p) = nullptr;                                             \
    }

// SiGfx's kernel as the device uses it.
class Unk_4fa470_Kernel {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();
    virtual void* vf12();
    virtual void vf13();
    virtual void vf14();
    virtual void vf15();
    virtual void vf16();
    virtual void vf17();
    virtual void vf18();
    virtual void vf19();
    virtual void vf20();
    virtual void vf21();
    virtual void vf22();
    virtual void vf23();
    virtual void vf24();
    virtual void vf25();
    virtual void vf26();
    virtual void vf27();
    virtual void vf28();
    virtual void vf29();
    virtual void vf30();
    virtual void vf31();
    virtual void vf32();
    virtual void vf33();
    virtual void vf34();
    virtual void vf35();
    virtual void vf36();
};
inline Unk_4fa470_Kernel* Unk_GfxKernel() {
    return reinterpret_cast<Unk_4fa470_Kernel*>(Unk_4cbf40_get());
}

// 0x71004f71a0
SiGfxNXDevice::SiGfxNXDevice(SiGfxNXManager* pManager)
    : field_8(pManager->field_8.m_pAllocator), field_18(pManager), field_20(0), field_108(0), field_230(0),
      field_238(0), field_240(0), field_244(0xc000), field_248(true), field_250(nullptr), field_258(nullptr),
      field_260(nullptr), field_268(nullptr), field_270(0), field_2b8(nullptr), field_2c0(-1), field_2c4(-1),
      field_2c8(false), field_2c9(false), field_338(nullptr), field_340(nullptr), field_348(nullptr),
      field_350(nullptr), field_358(nullptr), field_360(nullptr), field_368(nullptr), field_370(nullptr),
      field_378(nullptr), field_380(nullptr), field_388(nullptr), field_390(nullptr), field_398(nullptr),
      field_650(pManager->field_8.m_pAllocator), field_6a0(pManager->field_8.m_pAllocator),
      field_6f0(pManager->field_8.m_pAllocator), field_740(false), field_741(false) {
    memset(&field_50, 0, sizeof(field_50));
    for (s32 i = 0; i < 13; i++) {
        field_2d0[i] = nullptr;
    }
    for (s32 i = 0; i < 8; i++) {
        field_278[i] = nullptr;
    }
    field_3a0 = nullptr;
    memset(field_3a8, 0, sizeof(field_3a8));
    memset(field_4f8, 0, sizeof(field_4f8));
    field_748 = nullptr;
    field_750 = nullptr;
    field_760 = nullptr;
    field_768 = nullptr;
    field_770 = nullptr;
    field_778 = nullptr;
    field_780 = 0;
    field_788 = 0;
    field_790 = 0;
    field_798 = 0;
    field_7a0 = nullptr;
    field_7a8 = 0;
    field_7b0 = 0;
    field_7b8 = 0;
}

// 0x71004f7600 (D2), 0x71004f7890 (D0)
SiGfxNXDevice::~SiGfxNXDevice() {
    Unk_4f7760();
    if (field_18 != nullptr) {
        field_18->Unk_4f6d80(this);
        field_18 = nullptr;
    }
}

// 0x71004f7760
void SiGfxNXDevice::Unk_4f7760() {
    vf8();
    UNK_SAFE_RELEASE(field_268);
    UNK_SAFE_RELEASE(field_260);
    UNK_SAFE_RELEASE(field_258);
    UNK_SAFE_RELEASE(field_398);
    Unk_4f7960();
    Unk_4f7b20();
    UNK_SAFE_RELEASE(field_250);
}

// 0x71004f78c0
bool SiGfxNXDevice::Unk_4f78c0() {
#line 239
    field_250 = UNK_SI_NEW(Unk_Allocator(), 0x10) SiGfxNXDeviceInfo(this);
    if (field_250 == nullptr) {
        return false;
    }
    if (!field_250->Unk_Init()) {
        UNK_SAFE_RELEASE(field_250);
        return false;
    }
    return true;
}

// 0x71004f7960
void SiGfxNXDevice::Unk_4f7960() {
    UNK_SAFE_RELEASE(field_350);
    UNK_SAFE_RELEASE(field_348);
    UNK_SAFE_RELEASE(field_340);
    UNK_SAFE_RELEASE(field_338);
    UNK_SAFE_RELEASE(field_358);
    UNK_SAFE_RELEASE(field_350);
    UNK_SAFE_RELEASE(field_360);
    UNK_SAFE_RELEASE(field_338);
    UNK_SAFE_RELEASE(field_378);
    UNK_SAFE_RELEASE(field_370);
    UNK_SAFE_RELEASE(field_340);
    UNK_SAFE_RELEASE(field_380);
    UNK_SAFE_RELEASE(field_388);
    UNK_SAFE_RELEASE(field_390);
    UNK_SAFE_RELEASE(field_368);
    memset(field_2d0, 0, sizeof(field_2d0));
}

// 0x71004f7b20
void SiGfxNXDevice::Unk_4f7b20() {
    Unk_ReleaseAll(&field_6f0);
    Unk_ReleaseAll(&field_6a0);
    Unk_ReleaseAll(&field_650);
}

// 0x71004f7cd0
s32 SiGfxNXDevice::vf89() {
    return Unk_nvnDeviceGetWindowOriginMode(field_2b8);
}

// 0x71004f7cf0
s32 SiGfxNXDevice::vf90() {
    return Unk_nvnDeviceGetDepthMode(field_2b8);
}

// 0x71004f7d30
void SiGfxNXDevice::vf95(s32* a1, s32* a2) {
    *a1 = field_748->Unk_Count() + 2;
    *a2 = 0x100;
}

// 0x71004f7d70
void SiGfxNXDevice::vf96(s32* a1, s32* a2) {
    *a1 = field_750->Unk_Count() + 2;
    *a2 = 0x100;
}

// Its FreeType manager, if its description asks for one (inline in slots 5
// and 88: placeholder name; its line is past both in the original's file).
inline void SiGfxNXDevice::Unk_MakeFreeTypeManager() {
    if (field_50.field_53) {
#line 2312
        field_398 = UNK_SI_NEW(Unk_Allocator(), 0x10) SiGfxNXFreeTypeManager(this);
        field_398->vf5();
    }
}

// 0x71004f7db0: sets the device up: its NVN device (with the debug layer's
// callback if the description asks for it), its descriptor pools, its
// resources and its canvases (one of 1280 by 720 without descriptions)
bool SiGfxNXDevice::vf5(u64 a1, const Unk_4f96c0_Desc* desc, s32 canvasCount, const Unk_4f96e0_Desc* canvasDescs) {
    field_230 = a1;
    memcpy(&field_50, desc, 0xb6);
    field_2c9 = false;
    if (!Unk_539840(Unk_Allocator(), 0)) {
        return false;
    }
#line 372
    field_2b8 = Unk_Allocator()->vf7(0x3000, 0x10, __FILE__, __LINE__);
    if (field_2b8 == nullptr) {
        return false;
    }
    s32 flags = (desc->field_8 & 2) ? 0x75 : 0;
    u8 builder[0x40] = {};
    nvnDeviceBuilderSetDefaults(builder);
    nvnDeviceBuilderSetFlags(builder, flags);
    if (nvnDeviceInitialize(field_2b8, builder) != 1) {
        return false;
    }
    Unk_nvnDeviceSetWindowOriginMode(field_2b8, 1);
    Unk_nvnDeviceSetDepthMode(field_2b8, 1);
    nvnDeviceGetInteger(field_2b8, 0, &field_2c0);
    nvnDeviceGetInteger(field_2b8, 1, &field_2c4);
    if (field_2c0 != 0x35 || field_2c4 < 0x137) {
        return false;
    }
    field_2c8 = true;
    if (flags & 1) {
        Unk_nvnDeviceInstallDebugCallback(field_2b8, Unk_4f7190_update, nullptr, 1);
    }
    s32 a24;
    s32 a25;
    s32 a11;
    s32 a12;
    nvnDeviceGetInteger(field_2b8, 0x24, &a24);
    nvnDeviceGetInteger(field_2b8, 0x25, &a25);
    nvnDeviceGetInteger(field_2b8, 0x11, &a11);
    nvnDeviceGetInteger(field_2b8, 0x12, &a12);
    s32 size11 = a11 + 0xd80;
    s32 size12 = a12 + 0xd80;
#line 457
    field_748 = UNK_SI_NEW(Unk_Allocator(), 0x10) Unk_5518d0_Pool();
    if (field_748 == nullptr || !field_748->Unk_551a50(this, size11, a11)) {
        return false;
    }
#line 464
    field_750 = UNK_SI_NEW(Unk_Allocator(), 0x10) Unk_5520b0_Pool();
    if (field_750 == nullptr || !field_750->Unk_552230(this, size12, a12)) {
        return false;
    }
#line 471
    field_758 = UNK_SI_NEW(Unk_Allocator(), 0x10) Unk_5518d0_Pool();
    if (field_758 == nullptr || !field_758->Unk_551a50(this, size11, a11)) {
        return false;
    }
    field_760 = nullptr;
    field_768 = nullptr;
    field_770 = nullptr;
    field_778 = nullptr;
    field_780 = 0;
    field_788 = 0;
    field_790 = 0;
    field_798 = 0;
    Unk_4f82a0();
    Unk_MakeFreeTypeManager();
    if (!Unk_4f8660()) {
        return false;
    }
    if (canvasCount < 1) {
        field_108 = 1;
        Unk_4f96e0_Desc* canvas = &field_10c[0];
        canvas->field_4 = 0;
        canvas->field_8 = 0;
        canvas->field_c = 1280;
        canvas->field_10 = 720;
        canvas->field_14 = 1280;
        canvas->field_18 = 720;
        canvas->field_1c = 1;
        canvas->field_20 = 0x1c;
        canvas->field_24 = 0x2d;
        canvas->field_30 = 0;
        canvas->field_34 = 0;
        canvas->field_38 = 1;
        canvas->field_3c = 1;
        canvas->field_40 = 0;
        canvas->field_44 = true;
        canvas->field_45 = false;
    } else {
        for (s32 i = 0; i < canvasCount; i++) {
            field_10c[i] = canvasDescs[i];
        }
        field_108 = canvasCount;
    }
    Unk_4f87b0();
    Unk_4f88f0();
    return true;
}

// 0x71004f82a0
bool SiGfxNXDevice::Unk_4f82a0() {
#line 1375
    field_338 = UNK_SI_NEW(field_8, 0x10) SiGfxNXSurfacePool(this);
    field_338->vf5(field_50.field_60);
    field_2d0[3] = field_338;
#line 1379
    field_340 = UNK_SI_NEW(field_8, 0x10) SiGfxNXTexturePool(this);
    field_340->vf5(field_50.field_58);
    field_2d0[1] = field_340;
#line 1383
    field_348 = UNK_SI_NEW(field_8, 0x10) SiGfxNXCanvasPool(this);
    field_348->vf5(field_50.field_68);
    field_2d0[5] = field_348;
#line 1387
    field_350 = UNK_SI_NEW(field_8, 0x10) SiGfxNXRenderTargetPool(this);
    field_350->vf5(field_50.field_80);
    field_2d0[11] = field_350;
#line 1391
    field_360 = UNK_SI_NEW(field_8, 0x10) SiGfxNXVolumePool(this);
    field_360->vf5(field_50.field_64);
    field_2d0[4] = field_360;
#line 1395
    field_368 = UNK_SI_NEW(field_8, 0x10) SiGfxNXVertexFormatPool(this);
    field_368->vf5(field_50.field_6c);
    field_2d0[6] = field_368;
#line 1399
    field_370 = UNK_SI_NEW(field_8, 0x10) SiGfxNXShaderPool(this);
    field_370->vf5(field_50.field_74);
    field_2d0[7] = field_370;
#line 1403
    field_378 = UNK_SI_NEW(field_8, 0x10) SiGfxNXShaderProgramPool(this);
    field_378->vf5(field_50.field_78);
    field_2d0[8] = reinterpret_cast<SiGfxResourcePool*>(field_378);
#line 1407
    field_380 = UNK_SI_NEW(field_8, 0x10) SiGfxNXFontPool(this);
    field_380->vf5(field_50.field_5c);
    field_2d0[2] = field_380;
#line 1411
    field_358 = UNK_SI_NEW(field_8, 0x10) SiGfxNXBufferPool(this);
    field_358->vf5(field_50.field_70);
    field_2d0[10] = field_358;
#line 1415
    field_388 = UNK_SI_NEW(field_8, 0x10) SiGfxNXQueryPool(this);
    field_388->vf5(field_50.field_7c);
    field_2d0[9] = field_388;
#line 1419
    field_390 = UNK_SI_NEW(field_8, 0x10) SiGfxNXSamplerPool(this);
    field_390->vf5(0x1000);
    field_2d0[12] = field_390;
    return true;
}

// 0x71004f8660
bool SiGfxNXDevice::Unk_4f8660() {
    ISiAllocator* pAllocator = Unk_Allocator();
#line 1015
    field_258 = UNK_SI_NEW(pAllocator, 0x10) SiGfxNXCommandQueue(pAllocator, this);
    if (field_258 == nullptr) {
        return false;
    }
    if (!field_258->Unk_54de30()) {
        UNK_SAFE_RELEASE(field_258);
        return false;
    }
#line 1030
    field_260 = UNK_SI_NEW(Unk_Allocator(), 0x10) SiGfxNXCommandQueue(Unk_Allocator(), this);
    if (field_260 == nullptr) {
        return false;
    }
    if (!field_260->Unk_54de30()) {
        UNK_SAFE_RELEASE(field_260);
        return false;
    }
#line 1043
    field_268 = UNK_SI_NEW(Unk_Allocator(), 0x10) SiGfxNXCommandList(Unk_Allocator(), this, nullptr);
    field_268->Unk_53a000(1);
    return true;
}

// 0x71004f87b0
bool SiGfxNXDevice::Unk_4f87b0() {
    for (s64 i = 0; i < field_108; i++) {
        SiGfxNXCanvas* canvas = field_278[i];
        if (canvas != nullptr) {
            canvas->vf19();
            canvas->vf3();
        }
        field_278[i] = nullptr;
    }
    for (s64 i = 0; i < field_108; i++) {
#line 1469
        SiGfxNXCanvas* canvas = UNK_SI_NEW(Unk_Allocator(), 0x10) SiGfxNXCanvas(Unk_Allocator(), this);
        char name[0x80];
        Unk_4c5a90(name, sizeof(name), "DefaultCanvas_%d", static_cast<s32>(i));
        canvas->vf51(name);
        canvas->Unk_4fbb20(field_230, &field_10c[i]);
        field_278[i] = canvas;
    }
    return true;
}

// 0x71004f88f0
void SiGfxNXDevice::Unk_4f88f0() {
    if (field_250 != nullptr) {
        field_250->Unk_539650();
    }
    Unk_4fb090();
    for (s32 i = 0; i < 13; i++) {
        if (field_2d0[i] != nullptr) {
            field_2d0[i]->vf7();
        }
    }
    if (field_398 != nullptr) {
        field_398->vf7();
    }
    Unk_4fa590();
    if (field_378 != nullptr) {
        field_648.field_0 = Unk_559d30_get(reinterpret_cast<const Unk_559d30*>(field_378));
    }
}

// 0x71004f8a80: sets the device up for another's NVN device, which gives its
// own functions for descriptors
bool SiGfxNXDevice::vf88(const Unk_4f96c0_Desc* desc, void* nvnDevice, u64 window, u64 a4, u64 a5, u64 a6, u64 a7, u64 a8,
                         u64 a9, u64 a10, u64 a11) {
    Unk_4f7760();
    memcpy(&field_50, desc, 0xb6);
    field_2b8 = nvnDevice;
    field_2c8 = true;
    field_2c9 = true;
    field_760 = reinterpret_cast<s32 (*)(u64, u64, u64)>(a4);
    field_768 = reinterpret_cast<u64 (*)(u64, u64)>(a5);
    field_770 = reinterpret_cast<u64 (*)(u32, u64)>(a6);
    field_778 = reinterpret_cast<u64 (*)(u32, u64)>(a7);
    field_780 = a8;
    field_788 = a9;
    field_790 = a10;
    field_798 = a11;
    Unk_4f82a0();
    Unk_MakeFreeTypeManager();
    if (!Unk_4f8660()) {
        return false;
    }
    if (!Unk_4f8c90()) {
        return false;
    }
    SiGfxNXCanvas* canvas;
    s32 count;
    if (window != 0) {
        Unk_4f96e0_Desc canvasDesc;
#line 676
        canvas = UNK_SI_NEW(Unk_Allocator(), 0x10) SiGfxNXCanvas(Unk_Allocator(), this);
        if (canvas == nullptr) {
            return false;
        }
        char name[0x400];
        Unk_4c5a90(name, sizeof(name), "DefaultCanvas");
        canvas->vf51(name);
        if (!canvas->Unk_4fc8a0(window, &canvasDesc)) {
            canvas->vf3();
            return false;
        }
        count = 1;
    } else {
        canvas = nullptr;
        count = 0;
    }
    field_108 = count;
    field_278[0] = canvas;
    field_240 = count;
    Unk_4f88f0();
    return true;
}

// One kind's heaps (inline in Unk_4f8c90: placeholder name): makes count heaps
// of a size and keeps the ones that could be made. False if a heap couldn't
// be allocated.
#define UNK_MAKE_HEAPS(array, size, count, a10, a18, a1c)                                             \
    array.Unk_ReserveAtLeast(count);                                                                  \
    for (s32 i = 0; i < count; i++) {                                                                 \
        SiGfxNXMemoryHeap* heap = UNK_SI_NEW(Unk_Allocator(), 0x10) SiGfxNXMemoryHeap(Unk_Allocator(), this); \
        if (heap == nullptr) {                                                                        \
            return false;                                                                             \
        }                                                                                             \
        Unk_NXMemoryHeapDesc desc(0, 1);                                                              \
        desc.field_18 = a18;                                                                          \
        desc.field_10 = a10;                                                                          \
        desc.field_14 = 1;                                                                            \
        desc.field_20 = 0;                                                                            \
        desc.field_1c = a1c;                                                                          \
        desc.field_0 = size;                                                                          \
        if (heap->vf8(&desc)) {                                                                       \
            array.Unk_Add(heap);                                                                      \
        } else {                                                                                      \
            heap->vf3();                                                                              \
        }                                                                                             \
    }

// 0x71004f8c90
bool SiGfxNXDevice::Unk_4f8c90() {
    {
        s32 size = field_50.field_84 < 0x100000 ? field_50.field_84 : 0x100000;
        s32 count = field_50.field_88;
#line 2643
        UNK_MAKE_HEAPS(field_650, size, count, 2, 4, 0x10000);
    }
    {
        s32 size = field_50.field_8c < 0x400000 ? field_50.field_8c : 0x400000;
        s32 count = field_50.field_90;
#line 2677
        UNK_MAKE_HEAPS(field_6a0, size, count, 1, 1, 0);
    }
    {
        s32 size = field_50.field_94 < 0x400000 ? field_50.field_94 : 0x400000;
        s32 count = field_50.field_98;
#line 2711
        UNK_MAKE_HEAPS(field_6f0, size, count, 1, 2, 0);
    }
    return true;
}

// 0x71004f92a0: releases everything the device made
void SiGfxNXDevice::vf8() {
    Unk_4cddb0_call(static_cast<Unk_4cddb0*>(Unk_4cbec0()), reinterpret_cast<Unk_4cddb0_arg1*>(this));
    Unk_4f9480();
    for (s64 i = 0; i < field_108; i++) {
        SiGfxNXCanvas* canvas = field_278[i];
        if (canvas != nullptr) {
            canvas->vf19();
            canvas->vf3();
        }
        field_278[i] = nullptr;
    }
    UNK_SAFE_RELEASE(field_268);
    UNK_SAFE_RELEASE(field_260);
    UNK_SAFE_RELEASE(field_258);
    Unk_4f7960();
    UNK_SAFE_RELEASE(field_398);
    Unk_4f7b20();
    UNK_SAFE_RELEASE(field_250);
#line 771
    UNK_SAFE_DELETE(Unk_Allocator(), field_748);
    UNK_SAFE_DELETE(Unk_Allocator(), field_750);
    if (!field_2c9 && field_2b8 != nullptr) {
        nvnDeviceFinalize(field_2b8);
        if (field_2b8 != nullptr) {
#line 777
            UNK_FREE(Unk_Allocator(), field_2b8);
        }
        field_2b8 = nullptr;
        field_2c8 = false;
    }
    Unk_539890_update();
}

// 0x71004f9480
void SiGfxNXDevice::Unk_4f9480() {
    memset(field_3a8, 0, 0x2a8);
    UNK_SAFE_RELEASE(field_3a0);
    if (field_398 != nullptr) {
        field_398->vf8();
    }
    void* effects = Unk_GfxKernel()->vf12();
    if (effects != nullptr) {
        Unk_4e7680(effects, this);
    }
    if (field_250 != nullptr) {
        field_250->Unk_Reset();
    }
    for (s32 i = 0; i < 13; i++) {
        if (field_2d0[i] != nullptr) {
            field_2d0[i]->vf8();
        }
    }
    if (field_7a0 != nullptr) {
        field_7a0->Unk_553010(field_7b0);
        UNK_SAFE_RELEASE(field_7a0);
        field_7b0 = 0;
        field_7b8 = 0;
    }
}

// 0x71004f9640
void SiGfxNXDevice::Unk_4f9640(ISiGfxResource* resource) {
    SiGfxResourcePool* pool = field_2d0[*reinterpret_cast<Unk_4f9640_Resource*>(resource)->vf8()];
    if (pool != nullptr) {
        pool->vf13(reinterpret_cast<Unk_534460_Resource*>(resource));
    }
}

// 0x71004f96e0
Unk_4f96e0_Desc* SiGfxNXDevice::vf13(s32 index) {
    return &field_10c[index];
}

// The device's functions that make an object that isn't pooled, in the
// device's allocator unless another is given.

// 0x71004f9780
ISiGfxDrawContext* SiGfxNXDevice::vf21(u32 a1, u64 a2, const void* desc, ISiAllocator* pAllocator) {
    if (pAllocator == nullptr) {
        pAllocator = Unk_Allocator();
    }
#line 985
    SiGfxNXDrawContext* p = UNK_SI_NEW(pAllocator, 0x10) SiGfxNXDrawContext(pAllocator, this);
    if (p != nullptr) {
        Unk_53b680_Desc defaults;
        if (!p->Unk_53b680(a1, desc == nullptr ? &defaults : static_cast<const Unk_53b680_Desc*>(desc))) {
            p->vf3();
            p = nullptr;
        }
    }
    return reinterpret_cast<ISiGfxDrawContext*>(p);
}

// 0x71004f9840
ISiGfxCommandList* SiGfxNXDevice::vf22(u32 a1, u64 a2, ISiAllocator* pAllocator) {
    if (pAllocator == nullptr) {
        pAllocator = Unk_Allocator();
    }
#line 1081
    SiGfxNXCommandList* p = UNK_SI_NEW(pAllocator, 0x10) SiGfxNXCommandList(pAllocator, this, nullptr);
    if (p != nullptr) {
        if (!p->Unk_53a000(a1)) {
            p->vf3();
            p = nullptr;
        }
    }
    return reinterpret_cast<ISiGfxCommandList*>(p);
}

// 0x71004f98e0
ISiGfxCommandListPool* SiGfxNXDevice::vf23(u32 a1, u64 a2, ISiAllocator* pAllocator) {
    if (pAllocator == nullptr) {
        pAllocator = Unk_Allocator();
    }
#line 1114
    SiGfxNXCommandListPool* p = UNK_SI_NEW(pAllocator, 0x10) SiGfxNXCommandListPool(pAllocator, this);
    if (p != nullptr) {
        if (!p->Unk_Init(a1)) {
            p->vf3();
            p = nullptr;
        }
    }
    return reinterpret_cast<ISiGfxCommandListPool*>(p);
}

// 0x71004f9980
ISiGfxCommandCache* SiGfxNXDevice::vf24(u32 a1, u64 a2, ISiAllocator* pAllocator) {
    if (pAllocator == nullptr) {
        pAllocator = Unk_Allocator();
    }
#line 1149
    SiGfxNXCommandCache* p = UNK_SI_NEW(pAllocator, 0x10) SiGfxNXCommandCache(pAllocator, this);
    if (p != nullptr) {
        if (!p->Unk_54d660(a1)) {
            p->vf3();
            p = nullptr;
        }
    }
    return reinterpret_cast<ISiGfxCommandCache*>(p);
}

// 0x71004f9a20
ISiGfxPipelineState* SiGfxNXDevice::vf25(u32 a1, u64 a2, ISiAllocator* pAllocator) {
    if (pAllocator == nullptr) {
        pAllocator = Unk_Allocator();
    }
#line 1184
    SiGfxNXPipelineState* p = UNK_SI_NEW(pAllocator, 0x10) SiGfxNXPipelineState(pAllocator, this);
    if (p != nullptr) {
        if (!p->Unk_Init(a1)) {
            p->vf3();
            p = nullptr;
        }
    }
    return reinterpret_cast<ISiGfxPipelineState*>(p);
}

// 0x71004f9ac0
ISiGfxRootSignature* SiGfxNXDevice::vf26(u32 a1, u32 a2, ISiAllocator* pAllocator) {
    if (pAllocator == nullptr) {
        pAllocator = Unk_Allocator();
    }
#line 1220
    SiGfxNXRootSignature* p = UNK_SI_NEW(pAllocator, 0x10) SiGfxNXRootSignature(pAllocator, this);
    if (p != nullptr) {
        if (!p->Unk_Init(a1)) {
            p->vf3();
            p = nullptr;
        }
    }
    return reinterpret_cast<ISiGfxRootSignature*>(p);
}

// 0x71004f9b60
ISiGfxDescriptorTable* SiGfxNXDevice::vf27(u32 a1, u32 a2, ISiAllocator* pAllocator) {
    if (pAllocator == nullptr) {
        pAllocator = Unk_Allocator();
    }
#line 1254
    SiGfxNXDescriptorTable* p = UNK_SI_NEW(pAllocator, 0x10) SiGfxNXDescriptorTable(pAllocator, this);
    if (p != nullptr) {
        if (!p->Unk_550030(a1)) {
            p->vf3();
            p = nullptr;
        }
    }
    return reinterpret_cast<ISiGfxDescriptorTable*>(p);
}

// 0x71004f9c00
ISiGfxDescriptorSet* SiGfxNXDevice::vf28(u32 a1, u64 a2, ISiAllocator* pAllocator) {
    if (pAllocator == nullptr) {
        pAllocator = Unk_Allocator();
    }
#line 1290
    SiGfxNXDescriptorSet* p = UNK_SI_NEW(pAllocator, 0x10) SiGfxNXDescriptorSet(pAllocator, this);
    if (p != nullptr) {
        if (!p->Unk_Init(a1)) {
            p->vf3();
            p = nullptr;
        }
    }
    return reinterpret_cast<ISiGfxDescriptorSet*>(p);
}

// 0x71004f9ca0
ISiGfxRenderPassState* SiGfxNXDevice::vf29(u32 a1, u64 a2, ISiAllocator* pAllocator) {
    if (pAllocator == nullptr) {
        pAllocator = Unk_Allocator();
    }
#line 1324
    SiGfxNXRenderPassState* p = UNK_SI_NEW(pAllocator, 0x10) SiGfxNXRenderPassState(pAllocator, this);
    if (p != nullptr) {
        if (!p->Unk_Init(a1)) {
            p->vf3();
            p = nullptr;
        }
    }
    return reinterpret_cast<ISiGfxRenderPassState*>(p);
}

// 0x71004f9d40
ISiGfxMemoryHeap* SiGfxNXDevice::vf30(u32 a1, ISiAllocator* pAllocator) {
    if (pAllocator == nullptr) {
        pAllocator = Unk_Allocator();
    }
#line 1355
    SiGfxNXMemoryHeap* p = UNK_SI_NEW(pAllocator, 0x10) SiGfxNXMemoryHeap(pAllocator, this);
    if (p != nullptr) {
        if (!Unk_552af0_get(reinterpret_cast<u64>(p))) {
            p->vf3();
            p = nullptr;
        }
    }
    return reinterpret_cast<ISiGfxMemoryHeap*>(p);
}

// 0x71004f9de0: one of its own canvases. (The count is tested first in the
// source: its load is what lets the two tests be one condition, which the
// original's single `mov x0, xzr` ahead of both shows.)
ISiGfxCanvas* SiGfxNXDevice::vf32(s32 index) {
    if (index < 0) {
        return nullptr;
    }
    if (index >= field_108 || index >= 8) {
        return nullptr;
    }
    return reinterpret_cast<ISiGfxCanvas*>(field_278[index]);
}

// 0x71004f9e20
ISiGfxCanvas* SiGfxNXDevice::vf33(s32 index) {
    if (index < 0) {
        return nullptr;
    }
    if (index >= field_108 || index >= 8) {
        return nullptr;
    }
    return reinterpret_cast<ISiGfxCanvas*>(field_278[index]);
}

// The three functions the device has for each kind of pooled resource: a new
// one (in the device's allocator unless another is given), the one of an
// index, and the one of a name.

// 0x71004f9ea0
ISiGfxVertexFormat* SiGfxNXDevice::vf38(const void* desc, u64 a2, ISiAllocator* pAllocator) {
    if (field_368 == nullptr) {
        return nullptr;
    }
    return reinterpret_cast<ISiGfxVertexFormat*>(
        Unk_563810(field_368, pAllocator != nullptr ? pAllocator : Unk_Allocator(), desc));
}

// 0x71004f9ed0
ISiGfxVertexFormat* SiGfxNXDevice::vf39(size_t index) {
    if (field_368 == nullptr) {
        return nullptr;
    }
    return reinterpret_cast<ISiGfxVertexFormat*>(field_368->Unk_534780(index));
}

// 0x71004f9ef0
ISiGfxVertexFormat* SiGfxNXDevice::vf40(const char* name) {
    if (field_368 == nullptr) {
        return nullptr;
    }
    return reinterpret_cast<ISiGfxVertexFormat*>(field_368->Unk_534900(name));
}

// 0x71004f9f10
u64 SiGfxNXDevice::vf41() {
    if (field_368 == nullptr) {
        return 0;
    }
    return Unk_5644d0_get(reinterpret_cast<u64>(field_368));
}

// 0x71004f9f20
ISiGfxTexture* SiGfxNXDevice::vf49(u32 a1, const void* desc, u32 a3, ISiAllocator* pAllocator) {
    if (field_340 == nullptr) {
        return nullptr;
    }
    return reinterpret_cast<ISiGfxTexture*>(
        Unk_55d6c0(field_340, pAllocator != nullptr ? pAllocator : Unk_Allocator(), a1, desc));
}

// 0x71004f9f60
ISiGfxTexture* SiGfxNXDevice::vf50(size_t index) {
    if (field_340 == nullptr) {
        return nullptr;
    }
    return reinterpret_cast<ISiGfxTexture*>(field_340->Unk_534780(index));
}

// 0x71004f9f80
ISiGfxTexture* SiGfxNXDevice::vf51(const char* name) {
    if (field_340 == nullptr) {
        return nullptr;
    }
    return reinterpret_cast<ISiGfxTexture*>(field_340->Unk_534900(name));
}

// 0x71004f9fa0
ISiGfxSampler* SiGfxNXDevice::vf52(const void* desc, u64 a2, u64 a3, ISiAllocator* pAllocator) {
    if (field_390 == nullptr) {
        return nullptr;
    }
    return reinterpret_cast<ISiGfxSampler*>(
        Unk_5589e0(field_390, pAllocator != nullptr ? pAllocator : Unk_Allocator(), desc, a2));
}

// 0x71004f9fe0
ISiGfxSampler* SiGfxNXDevice::vf53(size_t index) {
    if (field_390 == nullptr) {
        return nullptr;
    }
    return reinterpret_cast<ISiGfxSampler*>(field_390->Unk_534780(index));
}

// 0x71004fa000
ISiGfxSampler* SiGfxNXDevice::vf54(const char* name) {
    if (field_390 == nullptr) {
        return nullptr;
    }
    return reinterpret_cast<ISiGfxSampler*>(field_390->Unk_534900(name));
}

// 0x71004fa020
ISiGfxFont* SiGfxNXDevice::vf55(const void* desc, u64 a2, ISiAllocator* pAllocator) {
    if (field_380 == nullptr) {
        return nullptr;
    }
    return reinterpret_cast<ISiGfxFont*>(Unk_4fed10(field_380, pAllocator != nullptr ? pAllocator : Unk_Allocator(), desc));
}

// 0x71004fa050
ISiGfxFont* SiGfxNXDevice::vf56(size_t index) {
    if (field_380 == nullptr) {
        return nullptr;
    }
    return reinterpret_cast<ISiGfxFont*>(field_380->Unk_534780(index));
}

// 0x71004fa070
ISiGfxFont* SiGfxNXDevice::vf57(const char* name) {
    if (field_380 == nullptr) {
        return nullptr;
    }
    return reinterpret_cast<ISiGfxFont*>(field_380->Unk_534900(name));
}

// 0x71004fa090
f32 SiGfxNXDevice::vf58() {
    return 0.0f;
}

// 0x71004fa0a0
ISiGfxBuffer* SiGfxNXDevice::vf59(const void* desc, u64 a2, ISiAllocator* pAllocator) {
    if (field_358 == nullptr) {
        return nullptr;
    }
    return reinterpret_cast<ISiGfxBuffer*>(Unk_536dc0(field_358, pAllocator != nullptr ? pAllocator : Unk_Allocator(), desc));
}

// 0x71004fa0d0
ISiGfxBuffer* SiGfxNXDevice::vf60(size_t index) {
    if (field_358 == nullptr) {
        return nullptr;
    }
    return reinterpret_cast<ISiGfxBuffer*>(field_358->Unk_534780(index));
}

// 0x71004fa0f0
ISiGfxBuffer* SiGfxNXDevice::vf61(const char* name) {
    if (field_358 == nullptr) {
        return nullptr;
    }
    return reinterpret_cast<ISiGfxBuffer*>(field_358->Unk_534900(name));
}

// 0x71004fa110
ISiGfxCanvas* SiGfxNXDevice::vf62(const void* desc, u64 a2, ISiAllocator* pAllocator) {
    if (field_348 == nullptr) {
        return nullptr;
    }
    return reinterpret_cast<ISiGfxCanvas*>(Unk_538f60(field_348, pAllocator != nullptr ? pAllocator : Unk_Allocator(), desc));
}

// 0x71004fa140
ISiGfxCanvas* SiGfxNXDevice::vf63(size_t index) {
    if (field_348 == nullptr) {
        return nullptr;
    }
    return reinterpret_cast<ISiGfxCanvas*>(field_348->Unk_534780(index));
}

// 0x71004fa160
ISiGfxCanvas* SiGfxNXDevice::vf64(const char* name) {
    if (field_348 == nullptr) {
        return nullptr;
    }
    return reinterpret_cast<ISiGfxCanvas*>(field_348->Unk_534900(name));
}

// 0x71004fa180: the canvas of a window, one of its own first
ISiGfxCanvas* SiGfxNXDevice::vf65(u64 window) {
    for (s64 i = 0; i < field_108; i++) {
        if (field_278[i]->vf21() == window) {
            return reinterpret_cast<ISiGfxCanvas*>(field_278[i]);
        }
    }
    if (field_348 == nullptr) {
        return nullptr;
    }
    return reinterpret_cast<ISiGfxCanvas*>(Unk_539160(field_348, window));
}

// 0x71004fa210
ISiGfxQuery* SiGfxNXDevice::vf66(const void* desc, u64 a2, ISiAllocator* pAllocator) {
    if (field_388 == nullptr) {
        return nullptr;
    }
    return reinterpret_cast<ISiGfxQuery*>(Unk_5545f0(field_388, pAllocator != nullptr ? pAllocator : Unk_Allocator(), desc));
}

// 0x71004fa240
ISiGfxQuery* SiGfxNXDevice::vf67(size_t index) {
    if (field_388 == nullptr) {
        return nullptr;
    }
    return reinterpret_cast<ISiGfxQuery*>(field_388->Unk_534780(index));
}

// 0x71004fa260
ISiGfxQuery* SiGfxNXDevice::vf68(const char* name) {
    if (field_388 == nullptr) {
        return nullptr;
    }
    return reinterpret_cast<ISiGfxQuery*>(field_388->Unk_534900(name));
}

// 0x71004fa280
ISiGfxShader* SiGfxNXDevice::vf42(u32 a1, const void* desc, u64 a3, ISiAllocator* pAllocator) {
    if (field_370 == nullptr) {
        return nullptr;
    }
    return reinterpret_cast<ISiGfxShader*>(
        Unk_559500(field_370, pAllocator != nullptr ? pAllocator : Unk_Allocator(), a1, desc));
}

// 0x71004fa2c0
ISiGfxShader* SiGfxNXDevice::vf43(size_t index) {
    if (field_370 == nullptr) {
        return nullptr;
    }
    return reinterpret_cast<ISiGfxShader*>(field_370->Unk_534780(index));
}

// 0x71004fa2e0
ISiGfxShader* SiGfxNXDevice::vf44(const char* name) {
    if (field_370 == nullptr) {
        return nullptr;
    }
    return reinterpret_cast<ISiGfxShader*>(field_370->Unk_534900(name));
}

// 0x71004fa300
ISiGfxShaderProgram* SiGfxNXDevice::vf45(const void* desc, u64 a2, ISiAllocator* pAllocator) {
    if (field_378 == nullptr) {
        return nullptr;
    }
    return reinterpret_cast<ISiGfxShaderProgram*>(
        Unk_5598b0(field_378, pAllocator != nullptr ? pAllocator : Unk_Allocator(), desc));
}

// 0x71004fa330
ISiGfxShaderProgram* SiGfxNXDevice::vf46(size_t index) {
    if (field_378 == nullptr) {
        return nullptr;
    }
    return reinterpret_cast<ISiGfxShaderProgram*>(reinterpret_cast<SiGfxResourcePool*>(field_378)->Unk_534780(index));
}

// 0x71004fa350
ISiGfxShaderProgram* SiGfxNXDevice::vf47(const char* name) {
    if (field_378 == nullptr) {
        return nullptr;
    }
    return reinterpret_cast<ISiGfxShaderProgram*>(reinterpret_cast<SiGfxResourcePool*>(field_378)->Unk_534900(name));
}

// 0x71004fa390
ISiGfxSurface* SiGfxNXDevice::vf69(const void* desc, u64 a2, ISiAllocator* pAllocator) {
    if (field_338 == nullptr) {
        return nullptr;
    }
    return reinterpret_cast<ISiGfxSurface*>(Unk_55c330(field_338, pAllocator != nullptr ? pAllocator : Unk_Allocator(), desc));
}

// 0x71004fa3c0
ISiGfxSurface* SiGfxNXDevice::vf70(size_t index) {
    if (field_338 == nullptr) {
        return nullptr;
    }
    return reinterpret_cast<ISiGfxSurface*>(field_338->Unk_534780(index));
}

// 0x71004fa3e0
ISiGfxSurface* SiGfxNXDevice::vf71(const char* name) {
    if (field_338 == nullptr) {
        return nullptr;
    }
    return reinterpret_cast<ISiGfxSurface*>(field_338->Unk_534900(name));
}

// 0x71004fa400
ISiGfxRenderTarget* SiGfxNXDevice::vf72(const void* desc, u64 a2, ISiAllocator* pAllocator) {
    if (field_350 == nullptr) {
        return nullptr;
    }
    return reinterpret_cast<ISiGfxRenderTarget*>(
        Unk_555450(field_350, pAllocator != nullptr ? pAllocator : Unk_Allocator(), desc));
}

// 0x71004fa430
ISiGfxRenderTarget* SiGfxNXDevice::vf73(size_t index) {
    if (field_350 == nullptr) {
        return nullptr;
    }
    return reinterpret_cast<ISiGfxRenderTarget*>(field_350->Unk_534780(index));
}

// 0x71004fa450
ISiGfxRenderTarget* SiGfxNXDevice::vf74(const char* name) {
    if (field_350 == nullptr) {
        return nullptr;
    }
    return reinterpret_cast<ISiGfxRenderTarget*>(field_350->Unk_534900(name));
}

// 0x71004fa470: a new size for its canvases
void SiGfxNXDevice::vf75(u64 a1, u32 a2, u32 a3) {
    Unk_GfxKernel()->vf36();
    for (s64 i = 0; i < field_108; i++) {
        if (field_278[i] != nullptr) {
            field_278[i]->vf26(a2, a3);
        }
    }
}

// 0x71004fa500
s64 SiGfxNXDevice::vf76(u64 a1, u64 a2, s32 a3, s32 a4, s32* a5, u32* a6) {
    *a5 = a3;
    *a6 = 0;
    return a4 * a3;
}

// 0x71004fa530
bool SiGfxNXDevice::vf78() {
    if (field_378 != nullptr) {
        Unk_View(field_378)->vf18();
    }
    memset(field_3a8, 0, 0x2a0);
    UNK_SAFE_RELEASE(field_3a0);
    return Unk_4fa590();
}

// Defined inline (not an exact definition to IPSCCP): the original's callers
// tail-call it (slots 78 and 79), so its result, always true, wasn't a
// constant to them. The format's cases are written one by one: with the
// case groups the loop over them is small enough for LoopUnswitch to
// unswitch it twice (kinds 1 and 2); the original's is unswitched once (kind
// 1, its seven cases unrolled) and keeps a jump table for kinds 2 to 5.
// 0x71004fa590: makes the root signature of its own drawing, then the
// shader program and vertex format of each of 6 by 7 cases
inline bool SiGfxNXDevice::Unk_4fa590() {
    SiGfxNXRootSignature* signature = reinterpret_cast<SiGfxNXRootSignature*>(vf26(1, 0, nullptr));
    signature->vf8();
    signature->vf10(2);
    signature->vf12(0, 2, 3, 0, 0);
    signature->vf14(1, 2, 1);
    signature->vf15(1, 0, 1, 0, 0, 1, 0xffffffff);
    signature->vf16(1);
    SiGfxNXRootSignature::Unk_SamplerDesc sampler(4);
    signature->vf18(0, 2, 0, 0, &sampler);
    signature->vf9();
    field_3a0 = signature;
    for (s32 i = 0; i < 6; i++) {
        for (s32 j = 0; j < 7; j++) {
            u32 id = Unk_4ecf40(i, j);
            if (id != 0) {
                ISiGfxShaderProgram* program = vf46(id);
                if (program != nullptr) {
                    ISiGfxVertexFormat* format = nullptr;
                    switch (i) {
                    case 1:
                        format = vf39(5);
                        break;
                    case 2:
                        format = vf39(5);
                        break;
                    case 3:
                        format = vf39(6);
                        break;
                    case 4:
                        format = vf39(6);
                        break;
                    case 5:
                        format = vf39(6);
                        break;
                    }
                    if (format != nullptr) {
                        field_3a8[i][j] = program;
                        field_4f8[i][j] = format;
                    }
                }
            }
        }
    }
    return true;
}

// 0x71004faa10
bool SiGfxNXDevice::vf79() {
    if (field_378 != nullptr) {
        Unk_View(field_378)->vf19();
    }
    memset(field_3a8, 0, 0x2a0);
    UNK_SAFE_RELEASE(field_3a0);
    return Unk_4fa590();
}

// Room for a request in one of a kind's heaps, in a new heap of at least the
// kind's size if the others have none (inline in the three functions below:
// placeholder name).
#define UNK_HEAP_ALLOC(array, SIZE)                                                                   \
    Unk_596640 lock(reinterpret_cast<SiOSSyncObject*>(&field_20), true);                              \
    *offset = 0;                                                                                      \
    for (s64 i = 0; i < static_cast<s32>(array.m_itemCount); i++) {                                   \
        SiGfxNXMemoryHeap* heap = array.m_pData[i];                                                   \
        if (heap->Unk_552f50(reinterpret_cast<const SiGfxNXMemoryHeap::Unk_552f50_Arg*>(request), offset)) { \
            return heap;                                                                              \
        }                                                                                             \
    }                                                                                                 \
    SiGfxNXMemoryHeap* heap = UNK_SI_NEW(Unk_Allocator(), 0x10) SiGfxNXMemoryHeap(Unk_Allocator(), this); \
    if (heap != nullptr) {                                                                            \
        s32 size = SIZE;                                                                              \
        size = request->field_4 > size ? request->field_4 : size;                                     \
        Unk_NXMemoryHeapDesc desc(0, 1);                                                              \
        desc.field_18 = request->field_1c;                                                            \
        desc.field_10 = request->field_18;                                                            \
        desc.field_14 = 1;                                                                            \
        desc.field_20 = request->field_24;                                                            \
        desc.field_1c = request->field_20;                                                            \
        desc.field_0 = size;                                                                          \
        if (heap->vf8(&desc) &&                                                                       \
            heap->Unk_552f50(reinterpret_cast<const SiGfxNXMemoryHeap::Unk_552f50_Arg*>(request), offset)) { \
            array.Unk_Add(heap);                                                                      \
        } else {                                                                                      \
            heap->vf3();                                                                              \
            heap = nullptr;                                                                           \
        }                                                                                             \
    }                                                                                                 \
    return heap;

// 0x71004faac0
SiGfxNXMemoryHeap* SiGfxNXDevice::Unk_4faac0(const Unk_4faac0_Request* request, s64* offset) {
#line 2775
    UNK_HEAP_ALLOC(field_650, field_50.field_84 < 0x100000 ? field_50.field_84 : 0x100000)
}

// 0x71004facb0
SiGfxNXMemoryHeap* SiGfxNXDevice::Unk_4facb0(const Unk_4faac0_Request* request, s64* offset) {
#line 2916
    UNK_HEAP_ALLOC(field_6a0, field_50.field_8c > 0x400000 ? field_50.field_8c : 0x400000)
}

// 0x71004faea0
SiGfxNXMemoryHeap* SiGfxNXDevice::Unk_4faea0(const Unk_4faac0_Request* request, s64* offset) {
#line 2980
    UNK_HEAP_ALLOC(field_6f0, field_50.field_94 > 0x400000 ? field_50.field_94 : 0x400000)
}

// 0x71004fb090: the memory its own drawing uses
bool SiGfxNXDevice::Unk_4fb090() {
    void* nvnDevice = field_2b8;
    s32 alignment = 0;
    field_7a8 = field_50.field_a4;
    if (field_7a8 >= 1) {
        s32 minSize = 0;
        nvnDeviceGetInteger(nvnDevice, 0x1a, &minSize);
        nvnDeviceGetInteger(nvnDevice, 0x19, &alignment);
        s32 m = minSize;
        field_7a8 = field_7a8 > m ? field_7a8 : m;
        field_7a0 = reinterpret_cast<SiGfxNXMemoryHeap*>(vf30(0, nullptr));
        size_t heapSize = Unk_NXAlign(field_7a8, alignment);
        Unk_NXMemoryHeapDesc desc(heapSize);
        desc.field_30 = 0xa1;
        if (!field_7a0->vf8(&desc)) {
            return false;
        }
        if (!field_7a0->Unk_552fc0(static_cast<s32>(heapSize), alignment, reinterpret_cast<s64*>(&field_7b0))) {
            return false;
        }
        field_7b8 = Unk_NXAlign(field_7b0, alignment);
    }
    return true;
}

// 0x71004fb1d0
s32 SiGfxNXDevice::Unk_4fb1d0(u64 a1, u64 a2) {
    if (field_2c9) {
        return field_760(a1, a2, field_780);
    }
    return field_748->Unk_551ed0(a1, a2, false);
}

// 0x71004fb200
s32 SiGfxNXDevice::Unk_4fb200(u64 a1, u64 a2) {
    if (field_2c9) {
        return field_760(a1, a2, field_780);
    }
    return field_748->Unk_551ed0(a1, a2, true);
}

// 0x71004fb230
s32 SiGfxNXDevice::Unk_4fb230(u64 a1, u64 a2) {
    if (field_2c9) {
        return field_760(a1, a2, field_780);
    }
    return field_758->Unk_551ed0(a1, a2, true);
}

// 0x71004fb260
u64 SiGfxNXDevice::Unk_4fb260(u64 a1) {
    if (field_2c9) {
        return field_768(a1, field_788);
    }
    return field_750->Unk_5526b0(a1);
}

// 0x71004fb290
u64 SiGfxNXDevice::Unk_4fb290(u32 a1) {
    if (field_2c9) {
        return field_770(a1, field_790);
    }
    return field_748->Unk_551fd0(a1);
}

// 0x71004fb2c0
u64 SiGfxNXDevice::Unk_4fb2c0(u32 a1) {
    if (field_2c9) {
        return field_770(a1, field_790);
    }
    return field_758->Unk_551fd0(a1);
}

// 0x71004fb2f0
u64 SiGfxNXDevice::Unk_4fb2f0(u32 a1) {
    if (field_2c9) {
        return field_778(a1, field_798);
    }
    return field_750->Unk_552790(a1);
}

// 0x71004fb380
s32 SiGfxNXDevice::Unk_4fb380(u64 a1, u64 a2) {
    return field_760(a1, a2, field_780);
}

}  // namespace SiSDK3
