// Scope: common
// PPFX::CRenderTexture (lib/yebis/YEBIS_draft/src/GPU/GPURenderTexture.h).
#include <string.h>

#include <yebis/YEBIS_draft/src/GPU/GPURenderTexture.h>

// log switch: PPFX_LOG's
extern s32 Unk_24e0008;

#define UNK_LOG(...)                                                                                 \
    do {                                                                                             \
        if (Unk_238c1e0 != 0 && Unk_24e0008 != 0) {                                                  \
            Unk_417a30("C:/workspace/YEBIS_draft/src/GPU/GPURenderTexture.cpp(%d) : PPFX: ", __LINE__); \
            Unk_417a30(__VA_ARGS__);                                                                 \
        }                                                                                            \
    } while (0)

// one reference less, and the pointer cleared
#define UNK_RELEASE(object)        \
    do {                           \
        if ((object) != nullptr) { \
            (object)->vf1();       \
            (object) = nullptr;    \
        }                          \
    } while (0)

// 0x71024e1500: PPFX's settings; field_10 is the number of frame slots
struct Unk_24e1500_Settings {
    u8 _0[0x10];
    u32 field_10;
};
extern Unk_24e1500_Settings Unk_24e1500;

// 0x710049e3a0
void Unk_49e3a0(u32 arg0, s32 arg1, s32 arg2, void* arg3, void* arg4, s32 arg5, void* arg6, void* arg7, f32 arg8);

namespace PPFX {

// PPFX::IGPUDevice, as this file calls it
struct Unk_49b230_Device {
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7(u32 index, Unk_49b230_Object* target, u32 arg2);  // a render target
    virtual s32 vf8(Unk_49b230_Object* depth);
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12(Unk_49b230_Object** target);  // the back buffer

    u8 _8[0x20];
    u32 field_28;  // the frame's number
};

// 0x7101b61484: the class's name
extern const char Unk_1b61484[];
const char Unk_1b61484[] = "CRenderTexture";
// What the render textures share: 0x71024e53a0 the targets in use,
// 0x710238d228, 0x71024e53e0, 0x71024e5408 how many textures have the
// device, 0x71024e5410 the device, 0x71024e5420 a setting
extern CRenderTexture* Unk_24e53a0[8];
extern u64 Unk_238d228[4];
extern void* Unk_24e53e0;
extern s32 Unk_24e5408;
extern IGPUDevice* Unk_24e5410;
extern bool Unk_24e5420;
// 0x71024e55b0: the device (GPUResourceManage.cpp)
extern IGPUDevice* Unk_24e55b0;

// inline in the functions that take or give up the device
static inline void Unk_ClearShared() {
    memset(Unk_24e53a0, 0, sizeof(Unk_24e53a0));
    memset(Unk_238d228, 0, sizeof(Unk_238d228));
    Unk_24e53e0 = nullptr;
}

static inline u32 Unk_FrameSlots() {
    return Unk_24e1500.field_10 > 1 ? Unk_24e1500.field_10 : 1;
}

// the current frame's slot of the viewport's history
inline CRenderTexture::Unk_Viewport& CRenderTexture::Unk_Slot() {
    return field_68[static_cast<s32>(reinterpret_cast<Unk_49b230_Device*>(field_20)->field_28 % Unk_FrameSlots())];
}

// every slot gets the viewport
inline void CRenderTexture::Unk_StoreViewport() {
    if (field_20 != nullptr) {
        s32 count = Unk_FrameSlots();
        for (s32 i = 0; i < count; i++) {
            field_68[i].field_0 = field_54;
            field_68[i].field_4 = field_58;
            field_68[i].field_8 = field_5c;
            field_68[i].field_c = field_60;
        }
    }
}

// 0x710049a890
Unk_49a890& Unk_49a890::operator=(const Unk_49a890& other) {
    if (this == &other)
        return *this;
    field_0 = other.field_0;
#line 123
    field_8 = UNK_NEW_ARRAY(Unk_Rect, other.field_0);
    for (u32 i = 0; i < other.field_0; i++)
        memmove(&field_8[i], &other.field_8[i], sizeof(Unk_Rect));
    field_10 = 0;
    field_14 = 0;
    u32 count = field_0;
    for (u32 i = 0; i < count; i++) {
        u32 width = field_8[i].field_10 - field_8[i].field_0;
        u32 height = field_8[i].field_18 - field_8[i].field_8;
        field_10 = field_10 > width ? field_10 : width;
        field_14 = field_14 > height ? field_14 : height;
    }
    return *this;
}

// 0x710049a9c0
CRenderTexture::CRenderTexture(const char* name) : CGPUResourceManage(nullptr) {
    Unk_49aa20(name);
}

// 0x710049aa20
s32 CRenderTexture::Unk_49aa20(const char* name) {
    if (name != nullptr && name[0] != '\0')
        field_10 = Unk_TFXString(Unk_1b61484) + " " + name;
    else
        field_10 = Unk_1b61484;
    field_68 = nullptr;
    Unk_Reset();
    return 0;
}

// 0x710049ab20
s32 CRenderTexture::Unk_49ab20(const Unk_49ab20_Desc* desc) {
    IGPUDevice* device = field_20;
    Unk_49ec80();
    field_2c = *desc;
    u32 flags = field_2c.field_0;
    u32 usage = (flags & 0x100) << 20;
    if (flags & 0x4000)
        usage |= 0x3200000;
    usage |= (flags >> 8) & 0x13000;
    if (flags & 0x2000000)
        usage |= 0x240000;
    usage |= (flags >> 4) & 0x1000000;
    field_50 = usage;
    if (field_2c.field_1c == 0)
        field_2c.field_1c = field_2c.field_c;
    ::Unk_49ad30(reinterpret_cast<Unk_RenderTexture*>(this), 0, 0, 0, 0);
    Unk_StoreViewport();
    field_70 = 0.0f;
    field_74 = 1.0f;
    field_100 = 0;
    field_108.clear();
    UNK_DELETE(field_f0);
    UNK_DELETE(field_f8);
    field_120 = nullptr;
    return Unk_49ec30(device);
}

}  // namespace PPFX

// 0x710049ad30: a render texture's viewport (0: the whole texture, negative:
// unchanged). The name is the one GPUPostEffect.h, which calls it, gave it.
// NON_MATCHING: 4 instructions, ordering only. The original keeps the result
// in w8 to its last block (`mov w8, wzr` ... `mov w0, w8`), sets it to 1
// between the two viewport stores of the path without a device, and adds
// y and field_9c with the operands the other way round.
s32 Unk_49ad30(PPFX::Unk_RenderTexture* texture, s32 width, s32 height, s32 x, s32 y) {
    using namespace PPFX;
    CRenderTexture* self = reinterpret_cast<CRenderTexture*>(texture);
    if (width == 0)
        width = self->field_2c.field_4;
    if (height == 0)
        height = self->field_2c.field_8;
    if (width < 0)
        width = self->field_54;
    if (height < 0)
        height = self->field_58;
    if (x < 0)
        x = self->field_5c;
    if (y < 0)
        y = self->field_60;
    if (x + width > self->field_2c.field_4)
        return -4;
    if (y + height > self->field_2c.field_8)
        return -4;
    for (s32 i = 0; i < 8; i++) {
        if (Unk_24e53a0[i] == self)
            return -3;
    }
    s32 result = 1;
    if (self->field_20 != nullptr) {
        self->Unk_Slot().field_0 = CRenderTexture::Unk_Max(self->Unk_Slot().field_0, static_cast<u32>(self->field_54));
        self->Unk_Slot().field_4 = CRenderTexture::Unk_Max(self->Unk_Slot().field_4, static_cast<u32>(self->field_58));
        self->Unk_Slot().field_8 = CRenderTexture::Unk_Max(self->Unk_Slot().field_8, static_cast<u32>(self->field_5c));
        self->Unk_Slot().field_c = CRenderTexture::Unk_Max(self->Unk_Slot().field_c, static_cast<u32>(self->field_60));
        result = 0;
    }
    self->field_54 = width;
    self->field_58 = height;
    self->field_5c = x;
    self->field_60 = y;
    if (self->field_20 != nullptr) {
        if (Unk_24e5420 && (self->field_78 & 1)) {
            self->field_88 = 1.0f;
            self->field_8c = 1.0f;
        } else {
            self->field_88 = 1.0f / static_cast<f32>(self->field_80->field_8);
            self->field_8c = 1.0f / static_cast<f32>(self->field_80->field_c);
        }
        self->field_90 = self->field_88 * static_cast<f32>(static_cast<u32>(self->field_9c + x));
        self->field_94 = self->field_8c * static_cast<f32>(static_cast<u32>(y + self->field_9c));
    } else {
        self->field_88 = 0.0f;
        self->field_8c = 0.0f;
        self->field_90 = 0.0f;
        self->field_94 = 0.0f;
    }
    return result;
}


namespace PPFX {

// 0x710049afd0, 0x710049b020
CRenderTexture::~CRenderTexture() {
    Unk_49ec80();
}

// 0x710049b080
s32 CRenderTexture::vf0(IGPUDevice* device) {
#line 623
    UNK_LOG("==== CRenderTexture::InitializeDevice() ====\n");
    UNK_LOG("Instance name: %s\n", field_10.field_8);
    if (static_cast<s32>(field_2c.field_0) < 0)
        return 1;
    IGPUDevice* previous = field_20;
    s32 result = CGPUResourceManage::vf0(device);
    if (result < 0)
        return result;
    if (device != nullptr && previous != field_20) {
        if (Unk_24e5408 == 0) {
            Unk_24e5410 = device;
            Unk_ClearShared();
        }
        Unk_24e5408++;
    }
    if (field_20 == nullptr)
        return 0;
    if (field_2c.field_c == 0)
        return 0;
    if (field_a8 != nullptr && field_b8 != nullptr)
        return 0;
    result = Unk_49b230();
    return result < 0 ? result : 0;
}

// 0x710049c0b0
s32 CRenderTexture::vf1() {
    if (field_20 != nullptr) {
        Unk_49e3a0(0x1f, 0, 0, nullptr, nullptr, 0, nullptr, nullptr, 1.0f);
        Unk_ClearShared();
        Unk_49b230_Object* target;
        reinterpret_cast<Unk_49b230_Device*>(field_20)->vf12(&target);
        reinterpret_cast<Unk_49b230_Device*>(field_20)->vf7(0, target, 0);
        target->vf1();
        reinterpret_cast<Unk_49b230_Device*>(field_20)->vf7(1, nullptr, 0);
        reinterpret_cast<Unk_49b230_Device*>(field_20)->vf7(2, nullptr, 0);
        reinterpret_cast<Unk_49b230_Device*>(field_20)->vf7(3, nullptr, 0);
        reinterpret_cast<Unk_49b230_Device*>(field_20)->vf8(nullptr);
    }
    if (field_d0 != nullptr) {
        for (u32 i = 0; i < field_98; i++)
            UNK_RELEASE(field_d0[i]);
        UNK_DELETE_ARRAY(field_d0);
    }
    if (field_d8 != nullptr) {
        for (u32 i = 0; i < field_98; i++)
            UNK_RELEASE(field_d8[i]);
        UNK_DELETE_ARRAY(field_d8);
    }
    UNK_RELEASE(field_b8);
    UNK_RELEASE(field_c0);
    for (u32 i = 0; i < field_98; i++)
        UNK_RELEASE(field_c8[i]);
    UNK_DELETE_ARRAY(field_c8);
    UNK_RELEASE(field_b0);
    UNK_RELEASE(field_a8);
    UNK_DELETE_ARRAY(field_80);
    if (field_e0 != nullptr) {
        for (u32 i = 0; i < field_98; i++)
            UNK_DELETE(field_e0[i]);
        UNK_DELETE_ARRAY(field_e0);
    }
    if (field_e8 != nullptr) {
        for (u32 i = 0; i < field_98; i++)
            UNK_DELETE(field_e8[i]);
        UNK_DELETE_ARRAY(field_e8);
    }
    UNK_DELETE_ARRAY(field_68);
    field_78 = 0;
    field_98 = 0;
    field_9c = 0;
    field_80 = nullptr;
    field_a8 = nullptr;
    field_e0 = nullptr;
    field_e8 = nullptr;
    field_d0 = nullptr;
    field_d8 = nullptr;
    field_c0 = nullptr;
    field_c8 = nullptr;
    field_b0 = nullptr;
    field_b8 = nullptr;
    while (field_a0 != 0)
        field_a0--;
    IGPUDevice* previous = field_20;
    s32 result = CGPUResourceManage::vf1();
    if (previous != nullptr && field_20 == nullptr) {
        if (--Unk_24e5408 == 0) {
            Unk_24e5410 = nullptr;
            Unk_ClearShared();
        }
    }
    return result;
}

// 0x710049c610
s32 CRenderTexture::vf2() {
    s32 result = CGPUResourceManage::vf2();
    if (result < 0)
        return result;
    return field_2c.field_c == 0 ? -1 : 0;
}

// 0x710049c640
s32 CRenderTexture::vf3() {
    UNK_DELETE(field_f0);
    UNK_DELETE(field_f8);
    Unk_Reset();
    s32 result = CGPUResourceManage::vf3();
    return result < 0 ? result : 0;
}

// 0x710049cf50: the depth target of the device every texture shares
s32 CRenderTexture::Unk_49cf50(Unk_49b230_Object* depth, void* owner) {
    s32 result = reinterpret_cast<Unk_49b230_Device*>(Unk_24e55b0)->vf8(depth);
    if (result < 0)
        return result;
    Unk_24e53e0 = owner;
    return 0;
}

}  // namespace PPFX
