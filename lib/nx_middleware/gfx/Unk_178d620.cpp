// Scope: common
// NintendoSDK_gfx 7.3.2 for NVN: conversions of gfx enums to NVN's values,
// table lookups. Placeholder names (see Unk_1787740.cpp).
#include "nx_middleware/gfx/gfx.h"

// Enum conversions to NVN's values.
static const int Unk_1f48860[] = {0, 1, 2, 8, 3, 4, 5, 6, 9, 7};
static const int Unk_1f48888[] = {1, 2, 3, 4, 5};
static const int Unk_1f4889c[] = {1, 2, 3, 4, 9, 10, 5, 6, 7, 8, 97, 98, 99, 100, 11, 16, 17, 18, 19};
static const int Unk_1f488e8[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
static const int Unk_1f48928[] = {0, 1, 3, 4, 5, 10, 11, 12, 13, 14};
static const int Unk_1f48964[] = {0, 3, 4, 2, 1, 5};
static const int Unk_1f4897c[] = {0, 1, 2};
static const int Unk_1b15a3c[] = {1, 0};

// 0x710178d620
int Unk_178d620(u32 value) {
    return Unk_1f48860[value];
}

// 0x710178d660
int Unk_178d660(u32 value) {
    return Unk_1f48888[value];
}

// 0x710178d670
int Unk_178d670(u32 value) {
    return Unk_1f4889c[value];
}

// 0x710178d680
int Unk_178d680(u32 value) {
    return Unk_1f488e8[value];
}

// 0x710178d690
int Unk_178d690(u32 value) {
    return Unk_1b15a3c[value];
}

// 0x710178d6a0
int Unk_178d6a0(u32 value) {
    return Unk_1f4897c[value];
}

// 0x710178d6b0
int Unk_178d6b0(int topology) {
    return Unk_1f48928[static_cast<u32>(topology)];
}

// 0x710178d6c0
int Unk_178d6c0(u32 value) {
    return Unk_1f48964[value];
}

// 0x710178d710
int Unk_178d710(int indexFormat) {
    return Unk_1f4897c[static_cast<u32>(indexFormat)];
}

// 0x710178d720
int Unk_178d720(u32 value) {
    return Unk_1f4897c[value];
}

// 0x710178d730
u64 Unk_178d730(Unk_178d730_Address address) {
    return address.field_0;
}

// A conversion table entry: a gfx value and the NVN value it maps to. The
// tables are sorted by gfx value and searched with a binary search (libc++'s
// std::lower_bound, written out here: lib/nx_middleware has no libc++). They
// aren't reproduced: they're declared at their addresses.
struct Unk_178d540_Pair {
    s32 field_0;
    s32 field_4;
};
extern const Unk_178d540_Pair Unk_246ad28[0x62] __attribute__((visibility("hidden")));
extern const Unk_178d540_Pair Unk_1f486a0[0x38] __attribute__((visibility("hidden")));
extern const Unk_178d540_Pair Unk_1f489b8[] __attribute__((visibility("hidden")));

static inline const Unk_178d540_Pair* Unk_178d540_LowerBound(const Unk_178d540_Pair* first,
                                                            const Unk_178d540_Pair* last,
                                                            int value) {
    s64 length = last - first;
    while (length != 0) {
        s64 half = length / 2;
        const Unk_178d540_Pair* middle = first + half;
        if (middle->field_0 < value) {
            first = middle + 1;
            length -= half + 1;
        } else {
            length = half;
        }
    }
    return first;
}

static inline int Unk_178d540_Find(const Unk_178d540_Pair* first, const Unk_178d540_Pair* last,
                                   int value) {
    const Unk_178d540_Pair* found = Unk_178d540_LowerBound(first, last, value);
    if (found != last && !(value < found->field_0)) {
        return found->field_4;
    }
    return 0;
}

// 0x710178d540: an image format to NVN's.
int Unk_178d540(int format) {
    return Unk_178d540_Find(Unk_246ad28, Unk_246ad28 + 0x62, format);
}

// 0x710178d5b0: an attribute format to NVN's.
int Unk_178d5b0(int format) {
    return Unk_178d540_Find(Unk_1f486a0, Unk_1f486a0 + 0x38, format);
}

// 0x710178da40: an NVN format to an image format.
int Unk_178da40(u32 format) {
    return Unk_1f489b8[format].field_0;
}

// The NVN comparison functions (merged by the linker with other copies of
// the same constants).
static const int Unk_1b16320[] = {1, 2, 3, 4, 5, 6, 7, 8};
static const int Unk_1f48950[] = {1, 6, 7, 5, 3};
static const f32 Unk_1f48988[][4] = {{1.0f, 1.0f, 1.0f, 1.0f}, {0.0f, 0.0f, 0.0f, 0.0f}, {0.0f, 0.0f, 0.0f, 1.0f}};

// 0x710178d630
int Unk_178d630(u32 value) {
    return Unk_1b16320[value];
}

// 0x710178d640
int Unk_178d640(u32 value) {
    return Unk_1b16320[value];
}

// 0x710178d650
int Unk_178d650(u32 value) {
    return Unk_1b16320[value];
}

struct Unk_178d740_In {
    s32 _0;
    s32 field_4;
    s32 field_8;
    s32 field_c;
};

// 0x710178d740
void Unk_178d740(Unk_178dac0_Info* out, const Unk_178d740_In* in) {
    out->field_1 = 2;
    out->field_2 = 0;
    out->field_4 = 0;
    out->field_6 = 1;
    out->field_8 = 1;
    out->field_c = in->field_4;
    out->field_10 = 0x480;
    out->field_14 = in->field_8;
    out->field_18 = in->field_c;
    out->field_1c = 1;
    out->field_20 = 1;
}

static inline void Unk_178d780_Set(u32* flags, u32 mask, bool on) {
    *flags = on ? (*flags | mask) : (*flags & ~mask);
}

// 0x710178d780: the device's features, one bit per NVN device query.
u32 Unk_178d780(void* device) {
    u32 flags = 0;
    int value;
    nvnDeviceGetInteger(device, 0x28, &value);
    Unk_178d780_Set(&flags, 0x1, value != 0);
    nvnDeviceGetInteger(device, 0x29, &value);
    Unk_178d780_Set(&flags, 0x2, value != 0);
    nvnDeviceGetInteger(device, 0x2a, &value);
    Unk_178d780_Set(&flags, 0x4, value != 0);
    nvnDeviceGetInteger(device, 0x32, &value);
    Unk_178d780_Set(&flags, 0x8, value != 0);
    nvnDeviceGetInteger(device, 0x3b, &value);
    Unk_178d780_Set(&flags, 0x10, value != 0);
    nvnDeviceGetInteger(device, 0x42, &value);
    Unk_178d780_Set(&flags, 0x20, value != 0);
    nvnDeviceGetInteger(device, 0x43, &value);
    Unk_178d780_Set(&flags, 0x40, value != 0);
    nvnDeviceGetInteger(device, 0x44, &value);
    Unk_178d780_Set(&flags, 0x80, value != 0);
    nvnDeviceGetInteger(device, 0x45, &value);
    Unk_178d780_Set(&flags, 0x100, value != 0);
    nvnDeviceGetInteger(device, 0x47, &value);
    Unk_178d780_Set(&flags, 0x200, value != 0);
    nvnDeviceGetInteger(device, 0x48, &value);
    Unk_178d780_Set(&flags, 0x400, value != 0);
    nvnDeviceGetInteger(device, 0x49, &value);
    Unk_178d780_Set(&flags, 0x800, value != 0);
    nvnDeviceGetInteger(device, 0x4a, &value);
    Unk_178d780_Set(&flags, 0x1000, value != 0);
    nvnDeviceGetInteger(device, 0x4b, &value);
    Unk_178d780_Set(&flags, 0x2000, value != 0);
    nvnDeviceGetInteger(device, 0x4c, &value);
    Unk_178d780_Set(&flags, 0x4000, value != 0);
    nvnDeviceGetInteger(device, 0x57, &value);
    Unk_178d780_Set(&flags, 0x8000, value != 0);
    nvnDeviceGetInteger(device, 0x5a, &value);
    Unk_178d780_Set(&flags, 0x10000, value != 0);
    return flags;
}


// 0x710178da60
void Unk_178da60(void* builder, const Unk_178da60_Info* info) {
    nvnMemoryPoolBuilderSetDefaults(builder);
    nvnMemoryPoolBuilderSetFlags(builder, info->field_0);
    nvnMemoryPoolBuilderSetStorage(builder, info->field_8, info->field_4);
}

int Unk_17878f0(int type, bool isArray, bool isMultisample);
size_t Unk_1787830(u32 width, int format);

// 0x710178dac0
// NON_MATCHING: the two selects of the flags take their constants in the
// other order (`csel 4, 0xc, eq` against our `csel 0xc, 4, ne`); every way of
// writing the condition that keeps the tile mode tested first gives ours.
void Unk_178dac0(void* builder, const Unk_178dac0_Info& info) {
    int arrayLength = info.field_20;
    int target = Unk_17878f0(info.field_1, arrayLength > 1, info.field_8 > 1);
    int nvnTarget = Unk_178d620(target);
    nvnTextureBuilderSetDefaults(builder);
    nvnTextureBuilderSetWidth(builder, info.field_14);
    nvnTextureBuilderSetHeight(builder, target == 4 ? arrayLength : info.field_18);
    nvnTextureBuilderSetDepth(builder,
                              nvnTarget == 4 || nvnTarget == 6 ? arrayLength : info.field_1c);
    nvnTextureBuilderSetLevels(builder, info.field_6);
    if (info.field_8 > 1) {
        nvnTextureBuilderSetSamples(builder, info.field_8);
    }
    nvnTextureBuilderSetTarget(builder, nvnTarget);
    nvnTextureBuilderSetFormat(builder, Unk_178d540(info.field_c));
    bool renderTarget = (info.field_10 & 0x180) != 0;
    int flags = info.field_2 != 1 && renderTarget ? 0xc : 0x4;
    if (info.field_10 & 0x400) {
        flags |= 0x1;
    }
    if (info.field_0 & 0x4) {
        flags |= 0x20;
    }
    if (info.field_2 == 1) {
        s64 alignment = renderTarget ? 0x80 : 0x20;
        flags |= renderTarget ? 0x40 : 0x10;
        s64 stride = Unk_1787830(info.field_14, info.field_c >> 8);
        nvnTextureBuilderSetStride(builder, (stride + alignment - 1) & -alignment);
    }
    nvnTextureBuilderSetFlags(builder, flags);
    if (info.field_0 & 0x1) {
        nvnTextureBuilderSetPackagedTextureLayout(builder, info.field_24);
    }
}

// A sampler's info: wrap modes, comparison function, border color, maximum
// anisotropy, filter mode (bits 0-1: min, 2-3: mag, 4-5: mip, 6: anisotropic,
// 7: comparison, 8-9: reduction) and LOD clamp and bias.
struct Unk_178dd30_Info {
    u8 field_0;
    u8 field_1;
    u8 field_2;
    u8 field_3;
    u8 field_4;
    u8 field_5;
    u16 field_6;
    f32 field_8;
    f32 field_c;
    f32 field_10;
};
PKMN_SIZE_ASSERT(Unk_178dd30_Info, 0x14);

// 0x710178dd30
// NON_MATCHING: the original tests the min filter again after the mip filter
// switch (`and #3; cmp #1` there) and dispatches the mag filter switch on 1
// first; here the test is merged with the cases' and the switch tests 2 first.
void Unk_178dd30(void* builder, const Unk_178dd30_Info& info) {
    nvnSamplerBuilderSetDefaults(builder);
    int filter = info.field_6;
    int nvnMinFilter;
    switch ((filter >> 4) & 3) {
    case 1:
        nvnMinFilter = (filter & 3) == 1 ? 2 : ((filter & 3) == 2 ? 4 : 0);
        break;
    case 2:
        nvnMinFilter = (filter & 3) == 1 ? 3 : ((filter & 3) == 2 ? 5 : 1);
        break;
    default:
        nn::detail::UnexpectedDefaultImpl("", "", 0);
    }
    int nvnMagFilter;
    switch ((filter >> 2) & 3) {
    case 1:
        nvnMagFilter = 0;
        break;
    case 2:
        nvnMagFilter = 1;
        break;
    default:
        nn::detail::UnexpectedDefaultImpl("", "", 0);
    }    nvnSamplerBuilderSetMinMagFilter(builder, nvnMinFilter, nvnMagFilter);
    nvnSamplerBuilderSetWrapMode(builder, Unk_1f48950[info.field_0], Unk_1f48950[info.field_1],
                                 Unk_1f48950[info.field_2]);
    nvnSamplerBuilderSetLodClamp(builder, info.field_8, info.field_c);
    nvnSamplerBuilderSetLodBias(builder, info.field_10);
    nvnSamplerBuilderSetCompare(builder, (info.field_6 >> 7) & 1, Unk_1b16320[info.field_3]);
    nvnSamplerBuilderSetBorderColor(builder, Unk_1f48988[info.field_4]);
    if (info.field_6 & 0x40) {
        nvnSamplerBuilderSetMaxAnisotropy(builder, info.field_5);
    }
    nvnSamplerBuilderSetReductionFilter(builder, Unk_1f4897c[(info.field_6 >> 8) & 3]);
}

// 0x710178d6d0: shader stage bits to NVN's (vertex, hull, domain, geometry,
// pixel, compute to vertex, tessellation control and evaluation, geometry,
// fragment, compute).
int Unk_178d6d0(int stages) {
    static const int nvnStageBits[] = {0x1, 0x8, 0x10, 0x4, 0x2, 0x20};
    int nvnStages = 0;
    for (int i = 0; i < 6; i++) {
        if (stages & (1 << i)) {
            nvnStages |= nvnStageBits[i];
        }
    }
    return nvnStages;
}
