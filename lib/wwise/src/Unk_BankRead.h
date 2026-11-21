#pragma once
// Reading the data of a bank: values at any alignment, and numbers of a
// variable size (7 bits a byte, the high bit set on all but the last).
#include <types.h>

template <class T>
static inline T Unk_ReadBank(u8*& data) {
    T value = *reinterpret_cast<T*>(data);
    data += sizeof(T);
    return value;
}

static inline u32 Unk_ReadBankVar(u8*& data) {
    u8 byte = Unk_ReadBank<u8>(data);
    u32 value = byte & 0x7f;
    while (byte & 0x80) {
        byte = Unk_ReadBank<u8>(data);
        value = (value << 7) | (byte & 0x7f);
    }
    return value;
}

static inline void Unk_SkipBank(u8*& data, u32& size, u64 count) {
    data += count;
    size -= count;
}
