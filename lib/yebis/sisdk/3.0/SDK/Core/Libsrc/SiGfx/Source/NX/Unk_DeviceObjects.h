// The classes whose objects SiGfxNXDevice makes, as far as the device's
// translation unit uses them: their sizes, their constructors and the
// functions it calls (RTTI names the classes). A placeholder header of the
// device's translation unit alone: each class's own header is its own
// translation unit's, and replaces its stand-in here once it has the class's
// size and constructor (SiGfxNXMemoryHeap's does already).
#pragma once

#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiGfx/Source/NX/SiGfx_NX_Device_Impl.h>
#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiGfx/Source/NX/SiGfx_NX_MemoryHeap_Impl.h>

// The initialisation functions that lib/yebis/leaf names (their types are
// leafgen's; they return whether they succeeded).
struct Unk_54f420;
struct Unk_553680;
struct Unk_556fe0;
struct Unk_54ea20;
struct Unk_555160;
struct Unk_5518d0;
struct Unk_5520b0;
struct Unk_552080;
struct Unk_552840;
struct Unk_539700;
struct Unk_559d30;
bool Unk_54f420_update(Unk_54f420* self, u32 value);
bool Unk_553680_update(Unk_553680* self, u32 value);
bool Unk_556fe0_update(Unk_556fe0* self, u32 value);
bool Unk_54ea20_update(Unk_54ea20* self, u32 value);
bool Unk_555160_update(Unk_555160* self, u32 value);
bool Unk_552af0_get(u64 self);
bool Unk_5393f0_get(u64 self);
void Unk_539700_set(Unk_539700* self);
// the constructors of the device's two kinds of descriptor pool
void Unk_5518d0_call(Unk_5518d0* self);
void Unk_5520b0_call(Unk_5520b0* self);
// how many descriptors each has
u32 Unk_552080_get(const Unk_552080* self);
u32 Unk_552840_get(const Unk_552840* self);
// 0x7100559d30: the shader program pool's field_250
u64 Unk_559d30_get(const Unk_559d30* self);

namespace SiSDK3 {

// Slots 2 to 4 of every class: the reference count.
#define UNK_DEVICE_OBJECT_SLOTS \
    virtual void vf0();         \
    virtual void vf1();         \
    virtual u32 vf2();          \
    virtual u32 vf3();          \
    virtual u32 vf4()

// What the draw context's initialisation takes (placeholder name): two flags,
// both set by default.
struct Unk_53b680_Desc {
    Unk_53b680_Desc() : field_0(true), field_1(true) {}

    bool field_0;
    bool field_1;
};

class SiGfxNXDrawContext {
public:
    SiGfxNXDrawContext(ISiAllocator* pAllocator, SiGfxNXDevice* pDevice);  // 0x710053b200
    UNK_DEVICE_OBJECT_SLOTS;
    bool Unk_53b680(u32 a1, const Unk_53b680_Desc* desc);

    u8 field_8[0x3fe8];
};
PKMN_SIZE_ASSERT(SiGfxNXDrawContext, 0x3ff0);

class SiGfxNXCommandList {
public:
    SiGfxNXCommandList(ISiAllocator* pAllocator, SiGfxNXDevice* pDevice, void* a3);  // 0x7100539920
    UNK_DEVICE_OBJECT_SLOTS;
    bool Unk_53a000(u32 a1);

    u8 field_8[0x1e8];
};
PKMN_SIZE_ASSERT(SiGfxNXCommandList, 0x1f0);

class SiGfxNXCommandListPool {
public:
    SiGfxNXCommandListPool(ISiAllocator* pAllocator, SiGfxNXDevice* pDevice);  // 0x710054f170
    UNK_DEVICE_OBJECT_SLOTS;
    bool Unk_Init(u32 a1) { return Unk_54f420_update(reinterpret_cast<Unk_54f420*>(this), a1); }

    u8 field_8[0x78];
};
PKMN_SIZE_ASSERT(SiGfxNXCommandListPool, 0x80);

class SiGfxNXCommandCache {
public:
    SiGfxNXCommandCache(ISiAllocator* pAllocator, SiGfxNXDevice* pDevice);  // 0x710054d430
    UNK_DEVICE_OBJECT_SLOTS;
    bool Unk_54d660(u32 a1);

    u8 field_8[0xf0];
};
PKMN_SIZE_ASSERT(SiGfxNXCommandCache, 0xf8);

class SiGfxNXPipelineState {
public:
    SiGfxNXPipelineState(ISiAllocator* pAllocator, SiGfxNXDevice* pDevice);  // 0x7100553180
    UNK_DEVICE_OBJECT_SLOTS;
    bool Unk_Init(u32 a1) { return Unk_553680_update(reinterpret_cast<Unk_553680*>(this), a1); }

    u8 field_8[0x6d0];
};
PKMN_SIZE_ASSERT(SiGfxNXPipelineState, 0x6d8);

class SiGfxNXRootSignature {
public:
    SiGfxNXRootSignature(ISiAllocator* pAllocator, SiGfxNXDevice* pDevice);  // 0x7100556cf0
    UNK_DEVICE_OBJECT_SLOTS;
    bool Unk_Init(u32 a1) { return Unk_556fe0_update(reinterpret_cast<Unk_556fe0*>(this), a1); }

    u8 field_8[0x330];
};
PKMN_SIZE_ASSERT(SiGfxNXRootSignature, 0x338);

class SiGfxNXDescriptorTable {
public:
    SiGfxNXDescriptorTable(ISiAllocator* pAllocator, SiGfxNXDevice* pDevice);  // 0x710054fa00
    UNK_DEVICE_OBJECT_SLOTS;
    bool Unk_550030(u32 a1);

    u8 field_8[0x190];
};
PKMN_SIZE_ASSERT(SiGfxNXDescriptorTable, 0x198);

class SiGfxNXDescriptorSet {
public:
    SiGfxNXDescriptorSet(ISiAllocator* pAllocator, SiGfxNXDevice* pDevice);  // 0x710054e790
    UNK_DEVICE_OBJECT_SLOTS;
    bool Unk_Init(u32 a1) { return Unk_54ea20_update(reinterpret_cast<Unk_54ea20*>(this), a1); }

    u8 field_8[0x80];
};
PKMN_SIZE_ASSERT(SiGfxNXDescriptorSet, 0x88);

class SiGfxNXRenderPassState {
public:
    SiGfxNXRenderPassState(ISiAllocator* pAllocator, SiGfxNXDevice* pDevice);  // 0x71005550c0
    UNK_DEVICE_OBJECT_SLOTS;
    bool Unk_Init(u32 a1) { return Unk_555160_update(reinterpret_cast<Unk_555160*>(this), a1); }

    u8 field_8[0x28];
};
PKMN_SIZE_ASSERT(SiGfxNXRenderPassState, 0x30);

class SiGfxNXDeviceInfo {
public:
    explicit SiGfxNXDeviceInfo(SiGfxNXDevice* pDevice);  // 0x7100539270
    UNK_DEVICE_OBJECT_SLOTS;
    bool Unk_Init() { return Unk_5393f0_get(reinterpret_cast<u64>(this)); }
    void Unk_539650();
    void Unk_Reset() { Unk_539700_set(reinterpret_cast<Unk_539700*>(this)); }

    u8 field_8[0xa0];
};
PKMN_SIZE_ASSERT(SiGfxNXDeviceInfo, 0xa8);

class SiGfxNXCommandQueue {
public:
    SiGfxNXCommandQueue(ISiAllocator* pAllocator, SiGfxNXDevice* pDevice);  // 0x710054d9d0
    UNK_DEVICE_OBJECT_SLOTS;
    bool Unk_54de30();

    u8 field_8[0x20a8];
};
PKMN_SIZE_ASSERT(SiGfxNXCommandQueue, 0x20b0);

class SiGfxNXFreeTypeManager {
public:
    explicit SiGfxNXFreeTypeManager(SiGfxNXDevice* pDevice);  // 0x7100551300
    UNK_DEVICE_OBJECT_SLOTS;
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();

    u8 field_8[0x70];
};
PKMN_SIZE_ASSERT(SiGfxNXFreeTypeManager, 0x78);

class SiGfxNXCanvas {
public:
    SiGfxNXCanvas(ISiAllocator* pAllocator, SiGfxNXDevice* pDevice);  // 0x71004fb6d0
    UNK_DEVICE_OBJECT_SLOTS;
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
    virtual void vf19();  // releases what it made
    virtual void vf20();
    virtual u64 vf21();  // its window
    virtual void vf22();
    virtual void vf23();
    virtual void vf24();
    virtual void vf25();
    virtual void vf26(u32 width, u32 height);
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
    virtual void vf37();
    virtual void vf38();
    virtual void vf39();
    virtual void vf40();
    virtual void vf41();
    virtual void vf42();
    virtual void vf43();
    virtual void vf44();
    virtual void vf45();
    virtual void vf46();
    virtual void vf47();
    virtual void vf48();
    virtual void vf49();
    virtual void vf50();
    virtual void vf51(const char* name);
    // 0x71004fbb20: makes it for a window
    bool Unk_4fbb20(u64 window, const Unk_4f96e0_Desc* desc);
    // 0x71004fc8a0: makes it for a window that isn't the device's
    bool Unk_4fc8a0(u64 window, const Unk_4f96e0_Desc* desc);

    u8 field_8[0x398];
};
PKMN_SIZE_ASSERT(SiGfxNXCanvas, 0x3a0);

// The device's pools of NVN descriptors (placeholder names, after their
// constructors, which have leafgen's names): 0x78 bytes each.
class Unk_5518d0_Pool {
public:
    Unk_5518d0_Pool() { Unk_5518d0_call(reinterpret_cast<Unk_5518d0*>(this)); }
    ~Unk_5518d0_Pool() { Unk_551910(); }
    void Unk_551910();
    bool Unk_551a50(SiGfxNXDevice* pDevice, s32 a2, s32 a3);
    u64 Unk_551ed0(u64 a1, u64 a2, bool a3);
    u64 Unk_551fd0(u32 a1);
    u32 Unk_Count() const { return Unk_552080_get(reinterpret_cast<const Unk_552080*>(this)); }

    u8 field_0[0x78];
};
class Unk_5520b0_Pool {
public:
    Unk_5520b0_Pool() { Unk_5520b0_call(reinterpret_cast<Unk_5520b0*>(this)); }
    ~Unk_5520b0_Pool() { Unk_5520f0(); }
    void Unk_5520f0();
    bool Unk_552230(SiGfxNXDevice* pDevice, s32 a2, s32 a3);
    u64 Unk_5526b0(u64 a1);
    u64 Unk_552790(u32 a1);
    u32 Unk_Count() const { return Unk_552840_get(reinterpret_cast<const Unk_552840*>(this)); }

    u8 field_0[0x78];
};

#undef UNK_DEVICE_OBJECT_SLOTS

}  // namespace SiSDK3
