// Scope: common
// A packed 64-bit value: bits 0-2 are a kind (1-4), bits 3-7 a 5-bit index,
// and the rest depends on the kind (6-bit fields at bits 8 and 14, a 16-bit
// field at bit 14, or one at bit 20 for kind 4). Placeholder names until the
// owner is known.
#include <types.h>

// 0x71007f87a0
u64 Unk_7f87a0(u8 index, u8 b) {
    return (u64)(((index & 0x1f) << 3) | 2) | ((b << 8) & 0x3f00);
}

// 0x71007f87c0
u64 Unk_7f87c0(u8 index, u8 b, u16 c) {
    u64 head = ((index & 0x1f) << 3) | 2;
    u64 low = (b << 8) & 0x3f00;
    u64 high = (u64)(c & 0xffff) << 14;
    return head | low | high;
}

// 0x71007f87f0
u64 Unk_7f87f0(u8 index, u8 b) {
    return (u64)(((index & 0x1f) << 3) | 3) | ((u64)(b & 0x3f) << 8);
}

// 0x71007f8810
u64 Unk_7f8810(u8 index) {
    return ((index & 0x1f) << 3) | 1;
}

// 0x71007f8820
u64 Unk_7f8820(u8 index, u16 c) {
    return (u64)(((index & 0x1f) << 3) | 1) | ((u64)c << 14);
}

// 0x71007f8840
u64 Unk_7f8840(u8 index, u8 b, u16 c) {
    u64 head = ((index & 0x1f) << 3) | 1;
    u64 low = (b << 8) & 0x3f00;
    u64 high = (u64)c << 14;
    return head | low | high;
}

// 0x71007f8870
u64 Unk_7f8870(u8 index, u8 b, u8 c) {
    return (u64)(((index & 0x1f) << 3) | 4) | ((c << 8) & 0x3f00) | ((u64)(b & 0x3f) << 14);
}

// 0x71007f88a0
u64 Unk_7f88a0(u8 index) {
    return (u64)(((index & 0x1f) << 3) | 1) | (0xf << 8);
}

// 0x71007f88e0
u32 Unk_7f88e0(const u64* value) {
    switch (*value & 7) {
        case 3:
            return (*value >> 8) & 0x3f;
        case 4:
            return (*value >> 14) & 0x3f;
        default:
            return 0x1f;
    }
}

// 0x71007f8910
void Unk_7f8910(u64* value, u8 field) {
    switch (*value & 7) {
        case 3:
            *value = ((u64)(field & 0x3f) << 8) | (*value & ~((u64)0x3f << 8));
            break;
        case 4:
            *value = ((u64)(field & 0x3f) << 14) | (*value & ~((u64)0x3f << 14));
            break;
    }
}

// 0x71007f8960
u32 Unk_7f8960(const u64* value) {
    u64 bits = *value;
    switch (bits & 7) {
        case 2:
            return (bits >> 8) & 0x3f;
        case 4:
            return (u32)bits >> 8 & 0x3f;
        default:
            return 0;
    }
}

// 0x71007f8990
void Unk_7f8990(void* self, u16 field) {
    u64* value = static_cast<u64*>(self);
    switch (*value & 7) {
        case 1:
        case 2:
        case 3:
            *value = ((u64)(u16)field << 14) | (*value & ~((u64)0xffff << 14));
            break;
        case 4:
            *value = ((u64)(u16)field << 20) | (*value & ~((u64)0xffff << 20));
            break;
    }
}

// 0x71007f89e0
u16 Unk_7f89e0(const u64* value) {
    switch (*value & 7) {
        case 1:
            return *value >> 14;
        case 2:
            return *value >> 14;
        case 3:
            return *value >> 14;
        case 4:
            return *value >> 20;
        default:
            return 0;
    }
}
