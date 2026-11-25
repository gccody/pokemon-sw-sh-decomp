// Scope: common
// transport::SendThreadStream and its packet pool, Unk_174bc30
// (lib/pia/common/Unk_174aea0.h). The constructor (0x710174b5a0) is here
// too: ThreadStreamManager's file calls it, so the two can't share a file.
// 0x710174b770, 0x710174be00 and 0x710174be10 are leaf functions
// (lib/nx_middleware/leaf/Unk_1721740.cpp).
#include "pia/common/Unk_174aea0.h"

#include "pia/common/Unk_17162d0.h"

struct Unk_165d8e0_arg0;
struct Unk_165d9b0_arg0;
struct Unk_174be00;

// A table of 12 0x68-byte entries (an entry by its index, null past the end)
// and an entry's name (up to 63 characters).
Unk_165d9b0_arg0* Unk_165d8e0(Unk_165d8e0_arg0* self, s32 index);
void Unk_165d9b0(Unk_165d9b0_arg0* self, const char* name);
extern Unk_165d8e0_arg0* Unk_27fb008;

// The object behind the global Unk_27fac38 (placeholder): its byte at 0x2b6
// is set from SendThreadStream's field_c4.
struct Unk_174b970_global {
    u8 _0[0x2b6];
    u8 field_2b6;
};
PKMN_OFFSET_ASSERT(Unk_174b970_global, field_2b6, 0x2b6);
extern Unk_174b970_global Unk_27fac38;

void Unk_174be00_set(Unk_174be00* self, u64 value);  // the pool's field_50
nn::pia::Unk_1660390* Unk_173bb40(Unk_173bd40* self, u32 index);
nn::pia::Unk_1660390* Unk_173bc90(Unk_173bd40* self);
void Unk_173bd40_set(Unk_173bd40* self);
u64 Unk_17163e0(void* memory);  // called on an array before it's freed

namespace nn {
namespace pia {
namespace transport {

// 0x710174b5a0
SendThreadStream::SendThreadStream() : field_4f0(nullptr), field_4f8(0), field_500(0) {}

// 0x710174b5e0 (and 0x710174b5f0, deleting)
SendThreadStream::~SendThreadStream() {}

// 0x710174b620
Unk_165e060 SendThreadStream::Unk_174b620(Unk_174b620_arg1* buffer, u32 arg2, u32 arg3, u32 arg4,
                                          bool arg5) {
    if (field_4f0 != nullptr) {
        return Unk_165e060Value<0x10c02>();
    }
    if (buffer == nullptr) {
        return Unk_165e060Value<0x10c07>();
    }
    if (Unk_27fb008 != nullptr) {
        Unk_165d9b0(Unk_165d8e0(Unk_27fb008, 0), "SendThreadStream buffer num");
    }
    Unk_165e060 result = Unk_174f430("Pia SendThreadStream", arg3, arg2, arg4, arg5, 0);
    if (result.m_Value != 0) {
        return result;
    }
    if (field_d8 != nullptr) {
        Unk_174be00_set(reinterpret_cast<Unk_174be00*>(field_d8), reinterpret_cast<u64>(buffer));
    }
    field_4f0 = buffer;
    field_4f8 = 0;
    field_500 = 0;
    return Unk_165e060Value<0>();
}

// 0x710174b7a0
// NON_MATCHING: block layout: the original tests the packet once, after both calls, and keeps
// the error return last; the same instructions otherwise.
Unk_165e060 SendThreadStream::vf1() {
    Unk_1660390* packet =
        field_30.field_10 > 0 ? Unk_173bb40(&field_30, 0) : Unk_173bc90(&field_30);
    if (packet == nullptr) {
        return Unk_165e060Value<0x2c09>();
    }
    packet->Unk_1660040();
    field_4f8++;
    field_500 += packet->field_5e8;
    Unk_165e060 result(0);
    if (Unk_174fb80(Unk_1652c70())) {
        Unk_173bd40_set(&field_30);
        result = Unk_165e060(0);
    } else {
        if (field_d8 != nullptr) {
            result = field_d8->Unk_174bfc0(packet);
        } else {
            result = field_4f0->vf4(packet);
        }
        if (result.m_Value == 0) {
            Unk_173bd40_set(&field_30);
        } else {
            // The original builds this result and drops it.
            Unk_165e060 dropped(0x4c0d);
        }
    }
    return result;
}

// 0x710174b970
void SendThreadStream::Unk_174b970() {
    u32 value = field_c4;
    Unk_27fac38.field_2b6 = value >= 1 && value <= 0xfe ? value : 0xff;
}

// 0x710174b9a0: TransportThreadStream::vf0, inline.

// 0x710174b9b0
template <typename T, u32 N>
Unk_174b9b0<T, N>::Unk_174b9b0() {
    this->m_Entries = reinterpret_cast<Entry*>(m_Buffer);
    this->m_Capacity = N;
    for (u32 i = 0; i < N; i++) {
        this->AddToPool(&this->m_Entries[i]);
    }
}

// 0x710174bc30
Unk_174bc30::Unk_174bc30(u32 capacity) : field_48(0), field_50(0), field_58(-1) {
    field_40 = nullptr;
    Unk_174bcc0(capacity);
}

// 0x710174bdb0
Unk_174bc30::~Unk_174bc30() {
    u32* memory = field_40;
    if (memory != nullptr) {
        Unk_17163e0(memory);
        Unk_1716390(memory);
        field_40 = nullptr;
    }
}

}  // namespace transport
}  // namespace pia
}  // namespace nn
