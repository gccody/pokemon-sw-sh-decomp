#pragma once

// NintendoSDK_gfx 7.3.2 for NVN: the structs that more than one of its TUs
// use. Neither the files nor the classes are named in the executable (no
// RTTI, no strings), so they're placeholders, with only the fields the
// decompiled functions touch.
#include <nn/os.h>
#include <types.h>
#include "nx_middleware/gfx/nvn.h"

namespace nn {
namespace detail {
// _ZN2nn6detail21UnexpectedDefaultImplEPKcS2_i: the SDK's NN_UNEXPECTED_DEFAULT,
// which a release build calls with empty strings and line 0.
[[noreturn]] void UnexpectedDefaultImpl(const char* condition, const char* function, int line) noexcept;
}  // namespace detail
}  // namespace nn

// A byte of flags, set one bit at a time.
struct Unk_1787ac0_Flags {
    u8 field_0;

    void Set(u8 mask, bool on) {
        if (on) {
            field_0 |= mask;
        } else {
            field_0 &= ~mask;
        }
    }
    bool Test(u8 mask) const { return (field_0 & mask) != 0; }
    int GetBit(int position) const { return (field_0 >> position) & 1; }
};

// The device: its NVN device (in field_8), a state, flags and its features
// (Unk_178d780).
struct Unk_1791080_Device {
    void* field_0;
    u8 field_8[0x3000];
    u8 field_3008;
    Unk_1787ac0_Flags field_3009;
    u8 _300a[0x2];
    u32 field_300c;
};
PKMN_OFFSET_ASSERT(Unk_1791080_Device, field_3008, 0x3008);
PKMN_OFFSET_ASSERT(Unk_1791080_Device, field_300c, 0x300c);

// What the buffer and command buffer calls take of a memory pool.
struct Unk_1787ac0_Pool {
    void* field_0;
};

// A GPU address: the NVN address and a second word.
struct Unk_178d730_Address {
    u64 field_0;
    u64 field_8;
};
PKMN_SIZE_ASSERT(Unk_178d730_Address, 0x10);

// A buffer: a state, flags (bit 1: CPU cached) and its NVN buffer.
struct Unk_1787ac0_Buffer {
    u8 field_0;
    Unk_1787ac0_Flags field_1;
    u8 _2[0x6];
    void* field_8;
    u8 field_10[0x30];
};
PKMN_OFFSET_ASSERT(Unk_1787ac0_Buffer, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_1787ac0_Buffer, field_10, 0x10);

// A command buffer: a state, flags, the device, its NVN command buffer, the
// handle of the last recording and the two out-of-memory callbacks.
struct Unk_1787d90_CommandBuffer;
struct Unk_1787d90_Event {
    size_t field_0;
};
using Unk_1787d90_Callback = void (*)(Unk_1787d90_CommandBuffer* self, Unk_1787d90_Event* event);

struct Unk_1787d90_CommandBuffer {
    u8 field_0;
    Unk_1787ac0_Flags field_1;
    u8 _2[0x6];
    Unk_1791080_Device* field_8;
    u8 _10[0x8];
    u8 field_18[0xa0];
    void* field_b8;
    u64 field_c0;
    u8 _c8[0x8];
    Unk_1787d90_Callback field_d0;
    Unk_1787d90_Callback field_d8;
};
PKMN_OFFSET_ASSERT(Unk_1787d90_CommandBuffer, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_1787d90_CommandBuffer, field_18, 0x18);
PKMN_OFFSET_ASSERT(Unk_1787d90_CommandBuffer, field_b8, 0xb8);
PKMN_OFFSET_ASSERT(Unk_1787d90_CommandBuffer, field_c0, 0xc0);
PKMN_OFFSET_ASSERT(Unk_1787d90_CommandBuffer, field_d0, 0xd0);
PKMN_OFFSET_ASSERT(Unk_1787d90_CommandBuffer, field_d8, 0xd8);

// A rasterizer state: NVN's polygon and multisample states, the sample mask,
// the polygon offset and flags (bit 0: sample mask, bit 1: no depth clamp,
// bit 2: no rasterizer discard, bit 3: conservative raster).
struct Unk_1788210_State {
    u32 field_0;
    u8 field_4[0x18];
    u32 field_1c;
    f32 field_20;
    f32 field_24;
    f32 field_28;
    u8 field_2c;
    Unk_1787ac0_Flags field_2d;
};
PKMN_OFFSET_ASSERT(Unk_1788210_State, field_4, 0x4);
PKMN_OFFSET_ASSERT(Unk_1788210_State, field_1c, 0x1c);
PKMN_OFFSET_ASSERT(Unk_1788210_State, field_20, 0x20);
PKMN_OFFSET_ASSERT(Unk_1788210_State, field_2d, 0x2d);

// A blend state: one NVN blend state per target, then the channel mask, color
// and blend color.
struct Unk_1788310_State {
    u64* field_0;
    u32 field_8;
    u32 field_c;
    f32 field_10[4];
    u8 _20[0x4];
    u8 field_24;
    u8 field_25;
};
PKMN_OFFSET_ASSERT(Unk_1788310_State, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_1788310_State, field_c, 0xc);
PKMN_OFFSET_ASSERT(Unk_1788310_State, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_1788310_State, field_25, 0x25);

// A depth stencil state: NVN's state, the stencil masks and references, and
// flags (bit 3: depth bounds test).
struct Unk_17883c0_State {
    u64 field_0;
    u32 field_8;
    u32 field_c;
    u32 field_10;
    u32 field_14;
    u8 field_18;
    u8 _19;
    u16 field_1a;
};
PKMN_OFFSET_ASSERT(Unk_17883c0_State, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_17883c0_State, field_14, 0x14);
PKMN_OFFSET_ASSERT(Unk_17883c0_State, field_1a, 0x1a);

// A texture's info: flags (bit 0: packaged layout, bit 2: sparse), image
// dimension, tile mode (1: linear), a second word, mip levels, samples, image format, GPU
// access, size, array length and the packaged layout.
struct Unk_178dac0_Info {
    u8 field_0;
    u8 field_1;
    u16 field_2;
    u16 field_4;
    u16 field_6;
    u16 field_8;
    u8 _a[0x2];
    s32 field_c;
    s32 field_10;
    s32 field_14;
    s32 field_18;
    s32 field_1c;
    s32 field_20;
    u8 field_24[0x1c];
};
PKMN_SIZE_ASSERT(Unk_178dac0_Info, 0x40);
PKMN_OFFSET_ASSERT(Unk_178dac0_Info, field_6, 0x6);
PKMN_OFFSET_ASSERT(Unk_178dac0_Info, field_c, 0xc);
PKMN_OFFSET_ASSERT(Unk_178dac0_Info, field_20, 0x20);
PKMN_OFFSET_ASSERT(Unk_178dac0_Info, field_24, 0x24);

// A memory pool's info: NVN flags, size and memory.
struct Unk_178da60_Info {
    s32 field_0;
    u32 field_4;
    void* field_8;
};
PKMN_SIZE_ASSERT(Unk_178da60_Info, 0x10);

// The image format queries (Unk_1787740.cpp), called from the other TUs.
int Unk_1787750(int format);
int Unk_1787780(int format);
bool Unk_17877b0(int format);
int Unk_17877c0(int format);

// The enum conversions (Unk_178d620.cpp).
int Unk_178d6b0(int topology);
int Unk_178d6d0(int stages);
int Unk_178d710(int indexFormat);
u64 Unk_178d730(Unk_178d730_Address address);
