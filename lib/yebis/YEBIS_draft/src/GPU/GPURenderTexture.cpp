// Scope: common
// PPFX::CRenderTexture (lib/yebis/YEBIS_draft/src/GPU/GPURenderTexture.h).
#include <string.h>

#include <yebis/YEBIS_draft/src/GPU/GPUInterfaceDevice.h>
#include <yebis/YEBIS_draft/src/GPU/GPURenderTexture.h>
#include <yebis/YEBIS_draft/src/GPU/Unk_Statics.h>

#define PPFX_FILE "C:/workspace/YEBIS_draft/src/GPU/GPURenderTexture.cpp"
#include <yebis/YEBIS_draft/src/GPU/Unk_Log.h>

#define UNK_LOG PPFX_LOG

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

namespace PPFX {
// 0x7100447010 (Unk_447050.cpp)
bool Unk_447010(s32 width, s32 height);
}  // namespace PPFX

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
    u8 _2c[0x14f00 - 0x2c];
    Unk_49b230_Object* field_14f00[8];  // the targets that are set
};

// 0x7101b61484: the class's name
extern const char Unk_1b61484[];
const char Unk_1b61484[] = "CRenderTexture";
// What the render textures share: 0x71024e53a0 the targets in use,
// 0x710238d228, 0x71024e53e0, 0x71024e5408 how many textures have the
// device, 0x71024e5410 the device, 0x71024e5420 a setting
extern CRenderTexture* Unk_24e53a0[8];
extern u32 Unk_238d228[8];
extern void* Unk_24e53e0;
extern s32 Unk_24e5408;
extern IGPUDevice* Unk_24e5410;
extern bool Unk_24e5420;
// The tiling's state: 0x71024e53e8 whether BeginTiling was called, then its
// arguments (0x71024e53ec, 0x71024e53f4, 0x71024e5404, 0x710238d248) and the
// number of targets it found (0x71024e53f0)
extern bool Unk_24e53e8;
extern s32 Unk_24e53ec;
extern s32 Unk_24e53f0;
CRenderTexture::Unk_Tile Unk_24e53f4;
extern s32 Unk_24e5404;
extern f32 Unk_238d248;
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
    Unk_UpdateSize();
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
    UNK_DELETE(field_f0[0]);
    UNK_DELETE(field_f0[1]);
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
    if (field_a8 != nullptr && field_b8[0] != nullptr)
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
    if (field_d0[0] != nullptr) {
        for (u32 i = 0; i < field_98; i++)
            UNK_RELEASE(field_d0[0][i]);
        UNK_DELETE_ARRAY(field_d0[0]);
    }
    if (field_d0[1] != nullptr) {
        for (u32 i = 0; i < field_98; i++)
            UNK_RELEASE(field_d0[1][i]);
        UNK_DELETE_ARRAY(field_d0[1]);
    }
    UNK_RELEASE(field_b8[0]);
    UNK_RELEASE(field_b8[1]);
    for (u32 i = 0; i < field_98; i++)
        UNK_RELEASE(field_c8[i]);
    UNK_DELETE_ARRAY(field_c8);
    UNK_RELEASE(field_b0);
    UNK_RELEASE(field_a8);
    UNK_DELETE_ARRAY(field_80);
    if (field_e0[0] != nullptr) {
        for (u32 i = 0; i < field_98; i++)
            UNK_DELETE(field_e0[0][i]);
        UNK_DELETE_ARRAY(field_e0[0]);
    }
    if (field_e0[1] != nullptr) {
        for (u32 i = 0; i < field_98; i++)
            UNK_DELETE(field_e0[1][i]);
        UNK_DELETE_ARRAY(field_e0[1]);
    }
    UNK_DELETE_ARRAY(field_68);
    field_78 = 0;
    field_98 = 0;
    field_9c = 0;
    field_80 = nullptr;
    field_a8 = nullptr;
    field_e0[0] = nullptr;
    field_e0[1] = nullptr;
    field_d0[0] = nullptr;
    field_d0[1] = nullptr;
    field_b8[1] = nullptr;
    field_c8 = nullptr;
    field_b0 = nullptr;
    field_b8[0] = nullptr;
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
    UNK_DELETE(field_f0[0]);
    UNK_DELETE(field_f0[1]);
    Unk_Reset();
    s32 result = CGPUResourceManage::vf3();
    return result < 0 ? result : 0;
}

// 0x710049c760
s32 CRenderTexture::Unk_49c760(s32 set, u32 slot, u32 width, u32 height, s32 format, s32 msaa, u32 quality,
                               s32 tiled, IGPUInterface** surface) {
    s32 index = set < 0 ? field_a0 : set;
    Unk_49a890* tiles;
    if (field_f0[index] == nullptr) {
        tiles = Unk_49c8e0(width, height, format, msaa, tiled);
    } else {
        Unk_49a890* source = Unk_SetTiles(index);
#line 1944
        tiles = UNK_NEW(Unk_49a890)(*source);
    }
    field_e0[set][slot] = tiles;
    Unk_49a890* slotTiles = Unk_SlotTiles(set, slot);
    u32 w = width;
    u32 h = height;
    if (slotTiles != nullptr) {
        w = slotTiles->field_10;
        h = slotTiles->field_14;
    }
    u32 flags = field_50;
    if (tiled == 0)
        flags &= ~0x10000000;
    s32 result = field_20->vf64(w, h, format, msaa, quality, surface, flags, nullptr, field_2c.field_c, false);
    return result < 0 ? result : 0;
}

// whether the device's target `slot` is the texture's (inline)
inline s32 CRenderTexture::Unk_CheckTarget(u32 slot, u32 level, u32 arg3, u32 arg4, s32 arg5, bool force,
                                           void* arg7, s32 arg8, void* arg9, s32 arg10, bool* done, f32 arg11,
                                           f32 arg12) {
    if (done != nullptr)
        *done = false;
    if (level == 0xffffffff)
        level = Unk_238d228[slot];
    Unk_49b230_Object* current = reinterpret_cast<Unk_49b230_Device*>(field_20)->field_14f00[slot];
    s32 result = 0;
    if (current != nullptr && current != field_d0[field_a0][level])
        result = -6;
    if (Unk_24e53a0[slot] != this)
        result = -6;
    if (!force && result < 0)
        return result;
    Unk_447010(field_d0[field_a0][level]->field_54, field_d0[field_a0][level]->field_58);
    return 0;
}

// 0x710049cfa0
s32 CRenderTexture::Unk_49cfa0(u32 slot, u32 level, u32 arg3, u32 arg4, s32 arg5, bool force, void* arg7, s32 arg8,
                               void* arg9, s32 arg10, bool* done, f32 arg11, f32 arg12) {
    if (done != nullptr)
        *done = false;
    if (level == 0xffffffff)
        level = Unk_238d228[slot];
    Unk_49a890* tiles = Unk_SlotTiles(-1, level);
    s32 result = 0;
    if (tiles == nullptr) {
        result = Unk_CheckTarget(slot, level, arg3, arg4, arg5, force, arg7, arg8, arg9, arg10, done, arg11, arg12);
    } else {
        for (u32 i = 0; i < tiles->field_0; i++)
            result = Unk_CheckTarget(slot, level, arg3, arg4, arg5, force, arg7, arg8, arg9, arg10, done, arg11,
                                     arg12);
    }
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

// 0x710049d7d0
s32 CRenderTexture::BeginTiling(s32 mode, const Unk_Tile* tile, s32 arg2, f32 arg3) {
    if (Unk_24e53e8) {
#line 4587
        PPFX_ERROR("CRenderTexture::BeginTiling(): CRenderTexture::BeginTiling() has already been called.\nYou have "
                   "to call EndTiling() before next BeginTiling().\n");
        return -3;
    }
    Unk_24e53f0 = 0;
    u32 index = 0;
    CRenderTexture* target = nullptr;
    for (u32 i = 0; i < 8; i++) {
        if (Unk_24e53a0[i] != nullptr) {
            Unk_24e53f0++;
            if (target == nullptr) {
                target = Unk_24e53a0[i];
                index = i;
            }
        }
    }
    if (Unk_24e53f0 == 0) {
#line 4613
        PPFX_ERROR("CRenderTexture::BeginTiling(): Any render target textures not found.\n");
        return -3;
    }
    if (static_cast<s32>(target->field_2c.field_0) < 0 ||
        target->Unk_Tiles(Unk_238d228[index]) == nullptr) {
#line 4625
        PPFX_ERROR("CRenderTexture::BeginTiling(): Current render texture(s) must have tiling informations.\n");
        return -3;
    }
    Unk_24e53ec = mode;
    if (tile != nullptr)
        Unk_24e53f4 = *tile;
    else
        Unk_24e53f4 = Unk_Tile();
    Unk_238d248 = arg3;
    Unk_24e5404 = arg2;
    Unk_24e53e8 = true;
    return 0;
}

// What the tiling does with a tile (inline): only asks the context for an
// object on NX. Its arguments are used until it is inlined, which is why the
// callers of the functions that call it still pass them.
inline s32 Unk_DrawTile(const Unk_49a890::Unk_Rect* rect, u32 flags, s32 arg2, s32 arg3, s32 arg4,
                               bool* done, f32 arg6, f32 arg7) {
    if (done != nullptr)
        *done = false;
    if (Unk_24e53e0 == nullptr)
        return -6;
    Unk_49b230_Object* object;
    static_cast<Unk_49df00_Context*>(Unk_24e53e0)->vf23(0, &object);
    object->vf1();
    return 0;
}

}  // namespace PPFX

namespace PPFX {

// 0x710049c8e0
Unk_49a890* Unk_49c8e0(u32 width, u32 height, s32 format, s32 msaa, s32 tiled) {
    s32 tileFormat = format;
    u32 tileWidth;
    u32 tileHeight;
    s32 count = Unk_446e20(&tileWidth, &tileHeight, width, height, 1, &tileFormat, tiled, msaa, 0);
    Unk_49a890* tiles = nullptr;
    if (count > 1) {
#line 1814
        tiles = UNK_NEW(Unk_49a890);
        tiles->field_0 = count;
#line 1816
        tiles->field_8 = UNK_NEW_ARRAY(Unk_49a890::Unk_Rect, count);
        for (s32 i = 0; i < count; i++) {
            Unk_49a890::Unk_Rect rect;
            rect.field_0 = 0;
            rect.field_10 = tileWidth;
            rect.field_8 = i * tileHeight;
            u64 bottom = rect.field_8 + tileHeight;
            rect.field_18 = bottom < height ? bottom : height;
            tiles->field_8[i] = rect;
        }
        tiles->Unk_UpdateSize();
    }
    return tiles;
}

// 0x710049df00
s32 Unk_49df00(CRenderTexture* target, u32 flags, s32 arg2, s32 arg3, s32 arg4, bool* done, f32 arg6, f32 arg7) {
    if (done != nullptr)
        *done = false;
    Unk_49a890* tiles;
    s32 result = 0;
    if (static_cast<s32>(target->field_2c.field_0) < 0 ||
        (tiles = target->Unk_Tiles(0)) == nullptr) {
        result = Unk_DrawTile(nullptr, flags, arg2, arg3, arg4, done, arg6, arg7);
    } else {
        for (u32 i = 0; i < tiles->field_0; i++)
            result = Unk_DrawTile(&tiles->field_8[i], flags, arg2, arg3, arg4, done, arg6, arg7);
    }
    return result < 0 ? result : 0;
}

// What EndTiling does with its arguments on other platforms (nothing on NX;
// inline): they are used until it is inlined, so its callers pass them.
inline void Unk_EndTiles(void* arg0, s32 arg1, s32* arg2, bool* arg3, f32 arg4) {}

// 0x710049e080
// NON_MATCHING: the search for the first target. The original turns it into
// two selects per element (the element's test outside, the target's inside);
// here clang ands the two tests and makes one select (or exits the loop
// early, with `&&`). The rest is the original's.
s32 CRenderTexture::EndTiling(void* arg0, s32 arg1, s32* arg2, bool* arg3, f32 arg4) {
    Unk_EndTiles(arg0, arg1, arg2, arg3, arg4);
    if (!Unk_24e53e8) {
#line 4928
        PPFX_ERROR("CRenderTexture::EndTiling(): CRenderTexture::BeginTiling() was never called.\nEndTiling() must be "
                   "called after BeginTiling().\n");
        return -3;
    }
    u32 index = 0;
    CRenderTexture* target = nullptr;
    for (u32 i = 0; i < 8; i++) {
        if (Unk_24e53a0[i] != nullptr) {
            if (target == nullptr) {
                target = Unk_24e53a0[i];
                index = i;
            }
        }
    }
    if (static_cast<s32>(target->field_2c.field_0) < 0 ||
        target->Unk_Tiles(Unk_238d228[index]) == nullptr) {
#line 4959
        PPFX_ERROR("CRenderTexture::EndTiling(): Current render texture(s) must have tiling informations.\n");
        return -3;
    }
    Unk_ClearShared();
    Unk_24e53e8 = false;
    Unk_24e53ec = 0;
    return 0;
}

// 0x710049e290
// NON_MATCHING: the original tests both conditions of the first `if` in one
// block (`ccmp`) and bit 20 of the flags again after the call, which clang
// folds here; the paths are the same.
s32 Unk_49e290(u32 flags, CRenderTexture* target, s32 arg2, bool* done, f32 arg4) {
    if (!Unk_24e53e8 || !(flags & 0x100000)) {
        s32 result = CRenderTexture::EndTiling(nullptr, arg2, nullptr, done, arg4);
        return result < 0 ? result : 0;
    }
    if (done != nullptr)
        *done = false;
    if (Unk_24e53e0 == nullptr)
        return 0;
    if (target == nullptr) {
        for (s32 i = 0; i < 8; i++) {
            target = Unk_24e53a0[i];
            if (target != nullptr)
                break;
        }
    }
    if (target != nullptr) {
        s32 result = Unk_49df00(target, flags, 1, arg2, arg2, done, arg4, arg4);
        if ((flags & 0x100000) || result < 0)
            return result < 0 ? result : 0;
    }
    Unk_24e53e0 = nullptr;
    return 0;
}

}  // namespace PPFX

// 0x710049e890: _GLOBAL__sub_I_GPURenderTexture.cpp
