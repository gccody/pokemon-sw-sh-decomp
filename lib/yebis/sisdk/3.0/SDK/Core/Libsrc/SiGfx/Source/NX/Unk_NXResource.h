// What SiGfx's NX (NVN) resource classes share (placeholder header and
// names): the device and the memory heap as the resources call them, the
// functions of other translation units they use, and the members every
// resource starts with.
#pragma once

#include <nx_middleware/gfx/nvn.h>
#include <string.h>

#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/SiCore_String.h>
#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/Unk_4bf660.h>
#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/Unk_NamedObject.h>
#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiGfx/Source/NX/SiGfx_NX_Device_Impl.h>

// 0x71004c3510: a string's hash
u32 Unk_4c3510(const SiSDK3::SiString<char>* s);
// 0x71004c4700: assigns a string (Unk_StringFuncs.h's declaration)
SiSDK3::SiString<char>& Unk_4c4700(void*, void*);
// 0x71004c5a90: snprintf
int Unk_4c5a90(char* buffer, size_t size, const char* format, ...);
// 0x71004cbf40: SiGfx's kernel (leafgen's name and type)
u64 Unk_4cbf40_get();
// 0x7100563620: an NVN memory pool's flags for a kind of resource and its
// usage
u32 Unk_563620(u32 kind, u32 a1, u32 a2, u32 a3);

// nvnBufferInitialize as SiSDK3 calls it: it compares NVN's boolean, a byte,
// with 1 (nvn.h has the entry point with the type its other callers show).
inline NvnBoolean Unk_nvnBufferInitialize(void* buffer, const void* builder) {
    return reinterpret_cast<NvnBoolean (*)(void*, const void*)>(Unk_27fca90)(buffer, builder);
}

// nvnCommandBufferInitialize, likewise.
inline NvnBoolean Unk_nvnCommandBufferInitialize(void* commandBuffer, void* device) {
    return reinterpret_cast<NvnBoolean (*)(void*, void*)>(Unk_27fd168)(commandBuffer, device);
}

namespace SiSDK3 {

class SiGfxNXMemoryHeap;

// SiSDK3::ISiInterface as the NX classes derive from it (placeholder name:
// Unk_Interface.h has the interface under its own name, next to an
// ISiNamedObject that SiGfx_ResourcePool.h also defines, so the pools'
// translation units can't include it).
class Unk_NXInterface {
public:
    virtual ~Unk_NXInterface() {}
    virtual u32 vf2() = 0;  // one reference more
    virtual u32 vf3() = 0;  // one less
    virtual u32 vf4() = 0;  // how many there are
};

// A size or an offset rounded up to an alignment (placeholder name).
inline size_t Unk_NXAlign(size_t value, size_t alignment) {
    return (value + (alignment - 1)) & ~(alignment - 1);
}

// What the device's slot 11 returns (placeholder name): its settings.
struct Unk_NXDeviceSettings {
    u8 field_0[0x52];
    bool field_52;  // whether the pools make their own resources (slot 7)
    u8 field_53[0x62];
    bool field_b5;  // whether resources get a name when they're made
};

// A memory heap's description (placeholder name): what its slot 8 takes. Its
// constructor takes the size: SiGfxNXQuery's and SiGfxNXCommandCache's code
// shows it as a 64-bit value that is truncated here (their other use of it
// keeps it from being narrowed). It also takes field_24: SiGfxNXDevice's code
// for its own heaps has its 1 where the constructor's stores are, ahead of
// the stores of the fields the device assigns (0x71004faac0). The zeros up to
// field_24 are its initialisers, the rest is assigned in its body: so the
// first 0x24 bytes are one memset and the rest its own stores when the
// constructor is inlined (the surface's colour buffer 0x710055cfd0 and the
// command list's heaps show the original's pairs of 8-byte stores; all
// initialisers, or all assignments, give other pairs).
struct Unk_NXMemoryHeapDesc {
    explicit Unk_NXMemoryHeapDesc(size_t size = 0, s32 count = 4)
        : field_0(0), field_4(0), field_8(0), field_10(0), field_14(0), field_18(0), field_1c(0), field_20(0) {
        field_0 = static_cast<s32>(size);
        field_24 = count;
        field_28 = 0;
        field_30 = 0;
        field_34 = 0;
        field_38 = 0;
        field_40 = nullptr;
        field_48 = -1;
        field_50 = -1;
    }

    s32 field_0;  // its size
    u32 field_4;
    u64 field_8;
    u32 field_10;
    u32 field_14;
    u32 field_18;
    u32 field_1c;
    u32 field_20;
    s32 field_24;  // how many block headers its allocator starts with
    u64 field_28;
    u32 field_30;       // the NVN memory pool's flags (0: from field_10, field_18 and field_1c)
    s32 field_34;       // field_40's size
    u64 field_38;
    const void* field_40;  // what its memory starts as (null: zeroes)
    s64 field_48;
    s64 field_50;
};
PKMN_SIZE_ASSERT(Unk_NXMemoryHeapDesc, 0x58);

// The device (SiGfxNXDevice, 97 slots) as the resources call it: slot 11 is
// its settings, slot 30 makes a memory heap, slot 46 is the shader program of
// an index, slot 81 tells whether resources
// are destroyed later (Unk_RefCountDeferred.h), slot 85 is the NVN device.
class Unk_NXDeviceInterface {
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
    virtual const Unk_NXDeviceSettings* vf11();
    virtual void vf12();
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
    virtual SiGfxNXMemoryHeap* vf30(u32 kind, ISiAllocator* pAllocator);
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
    virtual void* vf46(size_t index);
    virtual void vf47();
    virtual void vf48();
    virtual void vf49();
    virtual void vf50();
    virtual void vf51();
    virtual void vf52();
    virtual void vf53();
    virtual void vf54();
    virtual void vf55();
    virtual void vf56();
    virtual void vf57();
    virtual void vf58();
    virtual void vf59();
    virtual void vf60();
    virtual void vf61();
    virtual void vf62();
    virtual void vf63();
    virtual void vf64();
    virtual void vf65();
    virtual void vf66();
    virtual void vf67();
    virtual void vf68();
    virtual void vf69();
    virtual void vf70();
    virtual void vf71();
    virtual void vf72();
    virtual void vf73();
    virtual void vf74();
    virtual void vf75();
    virtual void vf76();
    virtual void vf77();
    virtual void vf78();
    virtual void vf79();
    virtual void vf80();
    virtual bool vf81();
    virtual void vf82();
    virtual void vf83();
    virtual void vf84();
    virtual void* vf85();
};

// A resource keeps its device as the class the pools hand it; its virtual
// functions are called through the interface above (the device's own header
// declares its slots as its own functions show them, which isn't always what
// their callers pass).
inline Unk_NXDeviceInterface* Unk_NXDevice(SiGfxNXDevice* pDevice) {
    return reinterpret_cast<Unk_NXDeviceInterface*>(pDevice);
}

// A resource as the device's functions take it (RTTI: ISiGfxResource is what
// the resources' interfaces derive from; the device's header declares it).
inline ISiGfxResource* Unk_NXResource(void* resource) {
    return reinterpret_cast<ISiGfxResource*>(resource);
}

// SiGfx's kernel as the NX classes call it (placeholder names): slot 6 is its
// allocator, slot 37 is an
// object whose slot 6 is the allocator of the memory heaps' memory, if it has
// one.
class Unk_NXKernelAllocatorSource {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual ISiAllocator* vf6();
};
// What the kernel's slot 27 returns (placeholder name): its settings, as
// far as SiGfxShaderProgramPoolBase's slot 7 reads them.
struct Unk_NXKernelSettings {
    u8 field_0[0x30];
    SiString<char> field_30;  // the directory the font pool's own font is in
    bool field_60;
    bool field_61;  // whether the font pool makes its own font
};
class Unk_NXKernelInterface {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual ISiAllocator* vf6();
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
    virtual void vf20();
    virtual void vf21();
    virtual void vf22();
    virtual void vf23();
    virtual void vf24();
    virtual void vf25();
    virtual void vf26();
    virtual const Unk_NXKernelSettings* vf27();
    virtual void vf28();
    virtual void vf29();
    virtual void vf30();
    virtual void vf31();
    virtual void vf32();
    virtual void vf33();
    virtual void vf34();
    virtual void vf35();
    virtual void vf36();
    virtual Unk_NXKernelAllocatorSource* vf37();
};
inline Unk_NXKernelInterface* Unk_NXKernel() {
    return reinterpret_cast<Unk_NXKernelInterface*>(Unk_4cbf40_get());
}

// Four floats that are copied one by one (placeholder name): a sampler's
// border colour.
struct Unk_NXColor {
    Unk_NXColor() {}
    Unk_NXColor(const Unk_NXColor& other) {
        field_0[0] = other.field_0[0];
        field_0[1] = other.field_0[1];
        field_0[2] = other.field_0[2];
        field_0[3] = other.field_0[3];
    }

    f32 field_0[4];
};

// A string with its characters' buffer in itself (placeholder name): the
// buffer's address is the string's plus 0x30 where one is a local variable
// (`mov x8, sp ; add x8, x8, #0x30`).
// (Buffers, textures and other resources have their names in one of 64
// characters.)
template <int N>
class Unk_NXString : public SiString<char> {
public:
    explicit Unk_NXString(ISiAllocator* pAllocator) : SiString<char>(pAllocator, field_30, N) {}

    char field_30[N];
};

// What a resource's slot 8 returns (placeholder name): its kind, which is
// the index of its pool in the device.
struct Unk_NXResourceInfo {
    u32 field_0;
    u32 field_4[4];
};
PKMN_SIZE_ASSERT(Unk_NXResourceInfo, 0x14);

}  // namespace SiSDK3
