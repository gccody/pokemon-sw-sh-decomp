#pragma once
// Reading a value from a sound bank's data: the values aren't aligned, and
// reading one moves the pointer past it.
#include <types.h>

template <class T>
inline T Unk_ReadBank(u8*& data) {
    struct Unaligned {
        T value;
    } __attribute__((packed));
    T value = reinterpret_cast<const Unaligned*>(data)->value;
    data += sizeof(T);
    return value;
}
