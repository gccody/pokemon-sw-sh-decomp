// Scope: common
// local::LdnConnectionStatus's members that call out (lib/pia/common/Unk_1685600.h).
#include "pia/common/Unk_1685600.h"

#include <string.h>

namespace nn {
namespace pia {
namespace local {

// 0x7101685600
void LdnConnectionStatus::vf2() {
    LocalConnectionStatus::vf2();
    field_8 = 0;
    memset(&field_40, 0, sizeof(field_40));
    field_4c0 = -1;
}

// 0x7101685640
bool LdnConnectionStatus::vf5(s32 index, LocalAddress* address) {
    Unk_1652c70 node(field_40.field_68[index].field_0.field_0, 12345);
    address->Unk_1687370(node);
    address->Unk_1687310(0);
    return true;
}

// 0x71016856c0
bool LdnConnectionStatus::vf3(LdnProtocol* protocol) {
    field_8 = ldn::GetState();
    s32 reason = ldn::GetDisconnectReason();
    field_4c0 = reason == 0xff ? -1 : reason;

    Result result = ldn::GetNetworkInfo(&field_40);
    Unk_165e060 error = protocol->Unk_167fab0(result);
    if (error.m_Value != 0) {
        field_30 = error;
        return false;
    }

    ldn::Ipv4Address address;
    ldn::SubnetMask mask;
    result = ldn::GetIpv4Address(&address, &mask);
    if (!result.IsSuccess()) {
        return false;
    }
    field_10.Unk_1652d50(address.field_0);
    field_10.field_18 = 12345;
    return true;
}

// 0x7101685790
// NON_MATCHING: the address local sits at x29-8 in the original, x29-4 here (the
// original object is 8 bytes or 8-aligned: its type is unknown)
bool LdnConnectionStatus::vf6(const Unk_1652c70* address) {
    u32 value = 0;
    address->Unk_1652de0(&value);
    for (s32 i = 0; i < 8; i++) {
        if (value == field_40.field_68[i].field_0.field_0) {
            return true;
        }
    }
    return false;
}

// 0x7101685880
bool LdnConnectionStatus::vf16() {
    switch (field_8) {
    case 0:
    case 1:
    case 2:
    case 4:
        return true;
    default:
        return false;
    }
}

// 0x71016858b0
void LdnConnectionStatus::vf18() {
    LocalConnectionStatus::vf18();
}

// 0x7101685920
u8 LdnConnectionStatus::vf4(s32 index) {
    return field_40.field_68[index].field_b;
}

// The destructors are implicit: 0x71016858c0 is LocalConnectionStatus's (in
// both vtables), 0x71016858e0 LdnConnectionStatus's deleting one.

}  // namespace local
}  // namespace pia
}  // namespace nn
