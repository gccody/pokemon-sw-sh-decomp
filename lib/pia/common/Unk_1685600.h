#pragma once
// local::LdnConnectionStatus (RTTI N2nn3pia5local19LdnConnectionStatusE,
// vtable 0x71024597c8), derived from local::LocalConnectionStatus (RTTI
// N2nn3pia5local21LocalConnectionStatusE, vtable 0x7102459c78): the state of
// the LDN network, what nn::ldn reports (lib/pia/common/Unk_1685600.cpp and
// Unk_1685990.cpp). The small getters the leaf generator wrote are in
// lib/nx_middleware/class/nn_pia_local_LdnConnectionStatus.cpp.
//
// Both destructors are implicit: LdnConnectionStatus's vtable holds
// LocalConnectionStatus's destructor, emitted in this TU. Member names are
// placeholders (vf<slot>, field_<offset>), the nn::ldn types' names their
// imports' (_ZN2nn3ldn14GetNetworkInfoEPNS0_11NetworkInfoE,
// _ZN2nn3ldn14GetIpv4AddressEPNS0_11Ipv4AddressEPNS0_10SubnetMaskE).
#include "pia/common/Unk_165e060.h"

namespace nn {
namespace ldn {

struct Ipv4Address {
    u32 field_0;
};
PKMN_SIZE_ASSERT(Ipv4Address, 0x4);

struct SubnetMask {
    u32 field_0;
};
PKMN_SIZE_ASSERT(SubnetMask, 0x4);

// What GetNetworkInfo fills in (LdnConnectionStatus clears its 0x480 bytes):
// only the fields Pia reads, and its 8 nodes.
struct NetworkInfo {
    struct Node {
        Ipv4Address field_0;  // the node's address
        u8 _4[0xb - 0x4];
        u8 field_b;  // whether the node is connected
        u8 _c[0x40 - 0xc];
    };

    u8 _0[0x48];
    s16 field_48;
    s8 field_4a;
    u8 field_4b;
    u8 _4c[0x67 - 0x4c];
    u8 field_67;
    Node field_68[8];
    u8 _268[0x480 - 0x268];
};
PKMN_OFFSET_ASSERT(NetworkInfo::Node, field_b, 0xb);
PKMN_SIZE_ASSERT(NetworkInfo::Node, 0x40);
PKMN_OFFSET_ASSERT(NetworkInfo, field_48, 0x48);
PKMN_OFFSET_ASSERT(NetworkInfo, field_4a, 0x4a);
PKMN_OFFSET_ASSERT(NetworkInfo, field_4b, 0x4b);
PKMN_OFFSET_ASSERT(NetworkInfo, field_67, 0x67);
PKMN_OFFSET_ASSERT(NetworkInfo, field_68, 0x68);
PKMN_SIZE_ASSERT(NetworkInfo, 0x480);

// The SDK imports (the return types: how Pia uses the results).
s32 GetState();
s32 GetDisconnectReason();
Result GetNetworkInfo(NetworkInfo* info);
Result GetIpv4Address(Ipv4Address* address, SubnetMask* mask);

}  // namespace ldn

namespace pia {

// common::InetAddress (RTTI N2nn3pia6common11InetAddressE; lib/pia/common/Unk_1654a80.h
// and Unk_165fb10.h have its other members).
class Unk_1652c70 {
public:
    // Inline: an IPv4 address and a port.
    Unk_1652c70(u32 address, u16 port) {
        Unk_1652d50(address);
        field_18 = port;
    }
    virtual ~Unk_1652c70();

    void Unk_1652d50(u32 address);  // sets an IPv4 address
    Unk_165e060 Unk_1652de0(u32* address) const;  // gets it

    u8 field_8[0x10];
    u16 field_18;
};
PKMN_OFFSET_ASSERT(Unk_1652c70, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_1652c70, field_18, 0x18);
PKMN_SIZE_ASSERT(Unk_1652c70, 0x20);

namespace local {

// RTTI N2nn3pia5local12LocalAddressE: what LdnConnectionStatus fills in.
class LocalAddress {
public:
    Unk_165e060 Unk_1687370(const Unk_1652c70& address);  // sets the address
    Unk_165e060 Unk_1687310(u16 value);                   // sets field_28
};

// RTTI N2nn3pia5local11LdnProtocolE: its function between its vf59 and vf64
// that turns an SDK result into Pia's (it doesn't read the protocol).
class LdnProtocol {
public:
    Unk_165e060 Unk_167fab0(const Result& result);
};

class LocalConnectionStatus {
public:
    virtual ~LocalConnectionStatus() {}

    virtual void vf2();  // clears it
    virtual bool vf3(LdnProtocol* protocol) = 0;
    virtual u8 vf4(s32 index) = 0;
    virtual bool vf5(s32 index, LocalAddress* address) = 0;
    virtual bool vf6(const Unk_1652c70* address) = 0;
    virtual bool vf7() = 0;
    virtual bool vf8() = 0;
    virtual u8 vf9() = 0;
    virtual u16 vf10() = 0;
    virtual const u8* vf11() = 0;
    virtual s32 vf12() = 0;
    virtual s32 vf13() = 0;
    virtual bool vf14() = 0;
    virtual u32 vf15() = 0;
    virtual bool vf16() = 0;
    virtual u32 vf17() = 0;
    virtual void vf18();
    // Slots 19 to 21 are LdnConnectionStatus's too (the leaf generator named
    // 19 and 20 after it).
    virtual u16 vf19();
    virtual const u8* vf20();
    virtual Unk_165e060 vf21();  // its result

    u16 field_8;  // the state (nn::ldn::GetState)
    Unk_1652c70 field_10;
    Unk_165e060 field_30;
};
PKMN_OFFSET_ASSERT(LocalConnectionStatus, field_8, 0x8);
PKMN_OFFSET_ASSERT(LocalConnectionStatus, field_10, 0x10);
PKMN_OFFSET_ASSERT(LocalConnectionStatus, field_30, 0x30);
PKMN_SIZE_ASSERT(LocalConnectionStatus, 0x40);

class LdnConnectionStatus : public LocalConnectionStatus {
public:
    void vf2() override;
    bool vf3(LdnProtocol* protocol) override;
    u8 vf4(s32 index) override;
    bool vf5(s32 index, LocalAddress* address) override;
    bool vf6(const Unk_1652c70* address) override;
    bool vf7() override;
    bool vf8() override;
    u8 vf9() override;
    u16 vf10() override;
    const u8* vf11() override;
    s32 vf12() override;
    s32 vf13() override;
    bool vf14() override;
    u32 vf15() override;
    bool vf16() override;
    u32 vf17() override;
    void vf18() override;

    ldn::NetworkInfo field_40;
    s32 field_4c0;  // the disconnect reason, -1 for none
};
PKMN_OFFSET_ASSERT(LdnConnectionStatus, field_40, 0x40);
PKMN_OFFSET_ASSERT(LdnConnectionStatus, field_4c0, 0x4c0);
PKMN_SIZE_ASSERT(LdnConnectionStatus, 0x4c8);

}  // namespace local
}  // namespace pia
}  // namespace nn
