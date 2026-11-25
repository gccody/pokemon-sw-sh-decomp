// Scope: common
// transport::ReceiveThreadStream's members (lib/pia/common/Unk_174be20.h),
// its vtable with them. The constructor and destructor are in Unk_174be20.cpp;
// 0x710174c7a0 is a leaf function (lib/nx_middleware/leaf/Unk_1721740.cpp).
#include "pia/common/Unk_174be20.h"

namespace nn {
namespace pia {
namespace transport {

// 0x710174c650
Unk_165e060 ReceiveThreadStream::Unk_174c650(void* buffer, u32 arg2, u32 arg3, u32 arg4,
                                             bool arg5) {
    if (field_4f0 != nullptr) {
        return Unk_165e060Value<0x10c02>();
    }
    if (buffer == nullptr) {
        return Unk_165e060Value<0x10c07>();
    }
    if (Unk_27fb008 != nullptr) {
        Unk_165d9b0(Unk_165d8e0(Unk_27fb008, 1), "ReceiveThreadStream buffer num");
    }
    Unk_165e060 result = Unk_174f430("Pia ReceiveThreadStream", arg3, arg2, arg4, arg5, 1);
    if (result.m_Value != 0) {
        return result;
    }
    if (field_d8 != nullptr) {
        Unk_174be10_set(reinterpret_cast<Unk_174be10*>(field_d8), reinterpret_cast<u64>(buffer));
    }
    field_4f0 = static_cast<Unk_174c650_arg1*>(buffer);
    field_4f8 = 0;
    field_500 = 0;
    return Unk_165e060Value<0>();
}

// 0x710174c7d0
void ReceiveThreadStream::vf0() {
    Unk_27fac38.field_2ac = 0;
}

// 0x710174c7e0
// NON_MATCHING: stack slots: the original puts the last three results in
// `result`'s slot (and the packet info with them), so the failed-receive path
// doesn't share its tail with the others; the same logic and calls.
Unk_165e060 ReceiveThreadStream::vf1() {
    Unk_1660390* packet;
    if (field_18.field_10 > 0) {
        packet = Unk_173bb40(&field_18, 0);
    } else {
        packet = Unk_173bb80(&field_18);
        if (packet == nullptr) {
            Unk_173bb30_arg1 info;
            info.field_0 = 0;
            info.field_4 = 0x20;
            info.field_8 = 0;
            Unk_173bb30_update(reinterpret_cast<u64>(field_8), &info);
            return Unk_165e060Value<0x4c0d>();
        }
    }
    Unk_165e060 result(0);
    if (field_d8 != nullptr) {
        result = field_d8->Unk_174be80(packet);
    } else {
        result = field_4f0->vf2(packet);
    }
    if (result.m_Value != 0) {
        // The original builds this result and drops it.
        Unk_165e060 dropped(0x2c09);
        return result;
    }
    packet->Unk_16601f0();
    packet->field_623 = packet->field_c >> 7;
    if (Unk_174fb80(packet->field_628.field_8)) {
        return Unk_165e060Value<0x2c09>();
    }
    field_4f8++;
    field_500 += packet->field_5e8;
    if (packet->Unk_1660500()) {
        Unk_173bc80_set(reinterpret_cast<Unk_173bc80*>(&field_18));
        return Unk_165e060Value<0>();
    }
    return Unk_165e060Value<0x2c03>();
}

// 0x710174c9c0
void ReceiveThreadStream::Unk_174c9c0() {
    u32 value = field_c4;
    Unk_27fac38.field_2b7 = value >= 1 && value <= 0xfe ? value : 0xff;
}

}  // namespace transport
}  // namespace pia
}  // namespace nn
