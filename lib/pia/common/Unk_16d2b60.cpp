// Scope: common
// nn::pia::nex::NexInputStream (RTTI N2nn3pia3nex14NexInputStreamE: a
// common::SocketStreamBase and a common::IPacketInput at 0x18) and
// nn::pia::nex::NexJoinRandomSessionSetting (RTTI
// N2nn3pia3nex27NexJoinRandomSessionSettingE, derived from
// session::JoinRandomSessionSetting). Member names are placeholders (vf<slot>,
// lib/pia/README.md); the members tools/leafgen.py matched are in
// lib/nx_middleware/class/nn_pia_nex_NexJoinRandomSessionSetting.cpp.
#include <string.h>

#include "pia/common/Unk_165c960.h"
#include "pia/common/Unk_165e060.h"

namespace nn {
namespace pia {

// nn::pia::common::InetAddress (RTTI N2nn3pia6common11InetAddressE; the
// placeholder of lib/pia/common/Unk_1749cd0.h): a 16-byte host and a port.
class Unk_1652c70 {
public:
    Unk_1652c70();
    virtual ~Unk_1652c70();

    Unk_1652c70& Unk_1652cf0(const Unk_1652c70& other);  // copies both fields
    void Unk_16538d0();                                  // clears both fields

    u8 field_8[0x10];
    u16 field_18;
};
PKMN_OFFSET_ASSERT(Unk_1652c70, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_1652c70, field_18, 0x18);
PKMN_SIZE_ASSERT(Unk_1652c70, 0x20);

}  // namespace pia
}  // namespace nn

// Two addresses, defined in lib/pia/common/Unk_16d26c0.cpp.
extern nn::pia::Unk_1652c70 Unk_27fb438[2];

// The object behind the global Unk_27fb310 (no RTTI name known; see
// lib/pia/common/Unk_16d8140.cpp).
struct Unk_27fb310_type {
    u8 _0[0x58];
    u32 field_58;  // an id in the low 24 bits
};
PKMN_OFFSET_ASSERT(Unk_27fb310_type, field_58, 0x58);

extern Unk_27fb310_type* Unk_27fb310;

namespace nn {
namespace pia {
namespace common {

// RTTI N2nn3pia6common16SocketStreamBaseE.
class SocketStreamBase {
public:
    SocketStreamBase();
    virtual ~SocketStreamBase();

    bool field_8;
    void* field_10;
};
PKMN_OFFSET_ASSERT(SocketStreamBase, field_8, 0x8);
PKMN_OFFSET_ASSERT(SocketStreamBase, field_10, 0x10);
PKMN_SIZE_ASSERT(SocketStreamBase, 0x18);

}  // namespace common

namespace nex {

// What NexInputStream reads a packet into, and what it writes a header from
// (placeholders: their types aren't known yet).
struct Unk_16d2c70_arg1;

struct Unk_16d3060_arg3 {
    u8 _0[0xd];
    u8 field_d;
    u8 _e[0x10 - 0xe];
    u8 field_10[0x8];
};
PKMN_OFFSET_ASSERT(Unk_16d3060_arg3, field_d, 0xd);
PKMN_OFFSET_ASSERT(Unk_16d3060_arg3, field_10, 0x10);

}  // namespace nex

namespace common {

// RTTI N2nn3pia6common12IPacketInputE: slots 2 and 3.
class IPacketInput {
public:
    virtual ~IPacketInput() {}

    virtual Unk_165e060 vf2(nex::Unk_16d2c70_arg1* packet) = 0;
    virtual Unk_165e060 vf3(u8* buffer, u32 bufferSize, const nex::Unk_16d3060_arg3* header) = 0;
};

}  // namespace common

namespace nex {

// 0x71016d2b60
void Unk_16d2b60(const Unk_1652c70& first, const Unk_1652c70& second) {
    Unk_27fb438[0].Unk_1652cf0(first);
    Unk_27fb438[1].Unk_1652cf0(second);
}

class NexInputStream : public common::SocketStreamBase, public common::IPacketInput {
public:
    NexInputStream();
    ~NexInputStream() override;

    Unk_165e060 vf2(Unk_16d2c70_arg1* packet) override;
    Unk_165e060 vf3(u8* buffer, u32 bufferSize, const Unk_16d3060_arg3* header) override;

    Unk_165e060 Unk_16d2cf0(Unk_16d2c70_arg1* packet);
};
PKMN_SIZE_ASSERT(NexInputStream, 0x20);

// 0x71016d2ba0
NexInputStream::NexInputStream() {
    Unk_27fb438[0].Unk_16538d0();
    Unk_27fb438[1].Unk_16538d0();
}

// 0x71016d2bf0 (0x71016d2c00 from IPacketInput; 0x71016d2c10 and 0x71016d2c40,
// deleting)
NexInputStream::~NexInputStream() {}

// 0x71016d2c70 (0x71016d2fe0 from IPacketInput)
Unk_165e060 NexInputStream::vf2(Unk_16d2c70_arg1* packet) {
    if (!field_8) {
        return Unk_165e060Value<0x2c09>();
    }
    return Unk_16d2cf0(packet);
}

// 0x71016d3060 (0x71016d3120 from IPacketInput)
Unk_165e060 NexInputStream::vf3(u8* buffer, u32 bufferSize, const Unk_16d3060_arg3* header) {
    if (bufferSize < 0xc) {
        return Unk_165e060Value<0x10c07>();
    }
    u32 id = Unk_27fb310 != nullptr ? Unk_27fb310->field_58 & 0xffffff : 0;
    Unk_165c9b0_set(reinterpret_cast<Unk_165c9b0*>(buffer), id | header->field_d << 24);
    memcpy(buffer + 4, header->field_10, sizeof(header->field_10));
    return Unk_165e060Value<0>();
}

}  // namespace nex

namespace session {

// RTTI N2nn3pia7session24JoinRandomSessionSettingE.
class JoinRandomSessionSetting {
public:
    virtual ~JoinRandomSessionSetting() {}
};

}  // namespace session

namespace nex {

// RTTI N2nn3pia3nex23NexCreateSessionSettingE (0x640 bytes). Its small members
// are in lib/nx_middleware/class/nn_pia_nex_NexCreateSessionSetting.cpp.
class NexCreateSessionSetting {
public:
    NexCreateSessionSetting();
    virtual ~NexCreateSessionSetting();

    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual u32 vf6();
    virtual u32 vf7();
    virtual void vf8();  // resets it

    void Unk_16c45e0(const NexCreateSessionSetting& other);  // copies it

    u8 _8[0x640 - 0x8];
};
PKMN_SIZE_ASSERT(NexCreateSessionSetting, 0x640);

// RTTI N2nn3pia3nex24NexSessionSearchCriteriaE (0xd38 bytes).
class NexSessionSearchCriteria {
public:
    NexSessionSearchCriteria();
    virtual ~NexSessionSearchCriteria();

    virtual void vf2();
    virtual void vf3();  // resets it

    u8 _8[0xd38 - 0x8];
};
PKMN_SIZE_ASSERT(NexSessionSearchCriteria, 0xd38);

class NexJoinRandomSessionSetting : public session::JoinRandomSessionSetting {
public:
    NexJoinRandomSessionSetting();
    ~NexJoinRandomSessionSetting() override;

    virtual Unk_165e060 vf2(const NexCreateSessionSetting* setting);
    virtual void vf3();
    virtual void vf4();  // resets it
    virtual void vf5();
    virtual const u8* vf6();
    virtual NexSessionSearchCriteria* vf7(u64 index);
    virtual const u8* vf8();
    virtual NexSessionSearchCriteria* vf9(u64 index);
    virtual u32 vf10();

    NexCreateSessionSetting field_8;
    NexSessionSearchCriteria field_648[2];
    u32 field_20b8;
    bool field_20bc;
    bool field_20bd;
    bool field_20be;
};
PKMN_OFFSET_ASSERT(NexJoinRandomSessionSetting, field_8, 0x8);
PKMN_OFFSET_ASSERT(NexJoinRandomSessionSetting, field_648, 0x648);
PKMN_OFFSET_ASSERT(NexJoinRandomSessionSetting, field_20b8, 0x20b8);
PKMN_OFFSET_ASSERT(NexJoinRandomSessionSetting, field_20bc, 0x20bc);
PKMN_OFFSET_ASSERT(NexJoinRandomSessionSetting, field_20be, 0x20be);
PKMN_SIZE_ASSERT(NexJoinRandomSessionSetting, 0x20c0);

// 0x71016d3130
NexJoinRandomSessionSetting::NexJoinRandomSessionSetting()
    : field_20b8(0), field_20bc(true), field_20bd(true), field_20be(false) {
    field_8.vf8();
    for (s32 i = 0; i < 2; i++) {
        field_648[i].vf3();
    }
}

// 0x71016d31d0 (and 0x71016d3220, deleting)
NexJoinRandomSessionSetting::~NexJoinRandomSessionSetting() {}

// 0x71016d32e0
Unk_165e060 NexJoinRandomSessionSetting::vf2(const NexCreateSessionSetting* setting) {
    if (setting == nullptr) {
        return Unk_165e060Value<0x10c07>();
    }
    field_8.Unk_16c45e0(*setting);
    return Unk_165e060Value<0>();
}

// 0x71016d3280
void NexJoinRandomSessionSetting::vf4() {
    field_8.vf8();
    for (s32 i = 0; i < 2; i++) {
        field_648[i].vf3();
    }
    field_20b8 = 0;
    field_20bc = true;
    field_20bd = true;
    field_20be = false;
}

}  // namespace nex
}  // namespace pia
}  // namespace nn
