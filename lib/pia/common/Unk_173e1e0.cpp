// Scope: common
// transport::ProtocolMessageAccessor::Header (RTTI
// N2nn3pia9transport23ProtocolMessageAccessor6HeaderE, derived from
// common::ISerializable; vtable 0x7102460840): its reader and size. And the
// object that holds two of them (no RTTI: Unk_173e5e0, the placeholder
// lib/pia/common/Unk_16a90f0.h declares with fewer members), the message a
// PacketReader parses out of a received packet: its constructor, destructor,
// parser and readers. And ProtocolManager::Unk_173e1e0 before them.
// Member names are placeholders (lib/pia/README.md).
//
// The Header's D0 (0x710173e7d0, a bare `b operator delete`) goes with its
// vtable, in the TU of its first out-of-line virtual function, vf2
// (0x710173e7e0).
#include <string.h>

#include "pia/common/Unk_165e060.h"
#include "pia/common/Unk_165fb10.h"
#include "pia/common/Unk_173d9d0.h"

namespace nn {
namespace pia {
namespace common {

// The base of what Pia writes into a buffer and reads back (RTTI
// N2nn3pia6common13ISerializableE). Slots 2 to 4: write, read, size.
class ISerializable {
public:
    virtual ~ISerializable() {}

    virtual Unk_165e060 vf2(u8* buffer, u32* size, u32 bufferSize) const = 0;
    virtual Unk_165e060 vf3(const u8* buffer, u32 bufferSize) = 0;
    virtual u32 vf4() = 0;
};

// A packet's header (lib/pia/common/Unk_165ff30.cpp): what the message
// parser reads of it.
namespace Packet {
class Header {
public:
    virtual ~Header() {}

    u32 field_8;
    u8 field_c;
    u8 field_d;  // 1: from this station
    u16 field_e;
    u8 field_10[0x8];
    u8 field_18[0x10];
};
PKMN_OFFSET_ASSERT(Header, field_d, 0xd);
PKMN_SIZE_ASSERT(Header, 0x28);
}  // namespace Packet

}  // namespace common

// A Packet::Header with the payload after it (lib/pia/common/Unk_165ff30.cpp
// declares it whole).
class Unk_1660390 {
public:
    u8* Unk_1660380(u32 offset);

    common::Packet::Header m_Header;
    u8 m_Buffer[0x5c0];
    u32 field_5e8;  // the end of the data in m_Buffer
    u8 _5ec[0x620 - 0x5ec];
    u8 field_620;
    u8 field_621;
    u8 field_622;
    u8 field_623;
    u8 field_624;
    Unk_165fb30 field_628;  // the sender
    u8 field_650;
};
PKMN_OFFSET_ASSERT(Unk_1660390, field_5e8, 0x5e8);
PKMN_OFFSET_ASSERT(Unk_1660390, field_620, 0x620);
PKMN_OFFSET_ASSERT(Unk_1660390, field_623, 0x623);
PKMN_OFFSET_ASSERT(Unk_1660390, field_628, 0x628);
PKMN_SIZE_ASSERT(Unk_1660390, 0x658);

namespace transport {

class ProtocolMessageAccessor {
public:
    // A message's header, 1 to 0x18 bytes on the wire, big-endian: a byte
    // of flags, then the fields whose bit is set (bit 0: field_9, 1:
    // field_a, the payload's size, 2: field_c, 3: field_10, 4: field_18).
    class Header : public common::ISerializable {
    public:
        Header() : field_8(0), field_9(0), field_a(0), field_c(0), field_10(0), field_18(0) {}

        Unk_165e060 vf2(u8* buffer, u32* size, u32 bufferSize) const override;
        Unk_165e060 vf3(const u8* buffer, u32 bufferSize) override;
        u32 vf4() override;

        Header& operator=(const Header& other) {
            field_8 = other.field_8;
            field_9 = other.field_9;
            field_a = other.field_a;
            field_c = other.field_c;
            field_10 = other.field_10;
            field_18 = other.field_18;
            return *this;
        }

        // Takes the fields this header leaves out from the one before it.
        void Fill(Header previous) {
            if (!(field_8 & 1)) {
                field_9 = previous.field_9;
            }
            if (!(field_8 & 2)) {
                field_a = previous.field_a;
            }
            if (!(field_8 & 4)) {
                field_c = previous.field_c;
            }
            if (!(field_8 & 8)) {
                field_10 = previous.field_10;
            }
            if (!(field_8 & 0x10)) {
                field_18 = previous.field_18;
            }
        }

        u8 field_8;
        u8 field_9;
        u16 field_a;
        u32 field_c;
        u64 field_10;
        u64 field_18;
    };
};
PKMN_OFFSET_ASSERT(ProtocolMessageAccessor::Header, field_8, 0x8);
PKMN_OFFSET_ASSERT(ProtocolMessageAccessor::Header, field_9, 0x9);
PKMN_OFFSET_ASSERT(ProtocolMessageAccessor::Header, field_a, 0xa);
PKMN_OFFSET_ASSERT(ProtocolMessageAccessor::Header, field_c, 0xc);
PKMN_OFFSET_ASSERT(ProtocolMessageAccessor::Header, field_10, 0x10);
PKMN_OFFSET_ASSERT(ProtocolMessageAccessor::Header, field_18, 0x18);
PKMN_SIZE_ASSERT(ProtocolMessageAccessor::Header, 0x20);

}  // namespace transport
}  // namespace pia
}  // namespace nn

// The placeholder of the received packet a message is parsed out of
// (lib/pia/common/Unk_16a90f0.h): an Unk_1660390.
struct Unk_173ad90_arg1 : nn::pia::Unk_1660390 {};

// A message in a received packet: its payload's size and data, the previous
// message's header and its own (the fields its flags leave out are the
// previous one's), and where it came from.
class Unk_173e5e0 {
public:
    typedef nn::pia::transport::ProtocolMessageAccessor::Header Header;

    Unk_173e5e0();
    ~Unk_173e5e0();

    void Unk_173e5b0();                        // clears it
    void Unk_173e5f0(void* out);         // copies the payload
    u8 Unk_173e650(u32 offset);                // the payload's bytes, big-endian
    u16 Unk_173e6a0(u32 offset);
    u32 Unk_173e700(u32 offset);
    u64 Unk_173e760(u32 offset);

    u32 field_0;            // the payload's size
    const u8* field_8;      // the message (its header, then the payload)
    Header field_10;        // the previous message's header
    Header field_30;
    bool field_50;          // the end of the packet's messages
    nn::pia::Unk_165fb30 field_58;  // the sender
    u8 field_80;
    u8 field_81;
    u8 field_82;
};
PKMN_OFFSET_ASSERT(Unk_173e5e0, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_173e5e0, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_173e5e0, field_30, 0x30);
PKMN_OFFSET_ASSERT(Unk_173e5e0, field_50, 0x50);
PKMN_OFFSET_ASSERT(Unk_173e5e0, field_58, 0x58);
PKMN_OFFSET_ASSERT(Unk_173e5e0, field_80, 0x80);
PKMN_OFFSET_ASSERT(Unk_173e5e0, field_82, 0x82);
PKMN_SIZE_ASSERT(Unk_173e5e0, 0x88);

// 0x710173e240
// NON_MATCHING: the zero stores of the two headers pair up in another order
// (stp xzr, xzr, [x0, #0x40] before the vtable pointers).
Unk_173e5e0::Unk_173e5e0() : field_0(0), field_8(nullptr), field_50(false), field_80(0), field_81(0), field_82(0) {}

// 0x710173e2a0
Unk_173e5e0::~Unk_173e5e0() {}

// 0x710173e2c0
void Unk_173e2c0(Unk_173e5e0* self, const Unk_173ad90_arg1* buffer, u32 offset) {
    Unk_173ad90_arg1* packet = const_cast<Unk_173ad90_arg1*>(buffer);
    u32 end = buffer->field_5e8 - 0x20;
    if (offset >= end) {
        self->field_8 = nullptr;
        self->field_50 = false;
        return;
    }
    if (*packet->Unk_1660380(offset) == 0xff) {
        self->field_8 = nullptr;
        self->field_50 = true;
        return;
    }
    self->field_50 = false;
    const u8* data = packet->Unk_1660380(offset);
    self->field_10 = self->field_30;
    self->field_30.vf3(data, 0x18);
    self->field_30.Fill(self->field_10);
    u32 headerEnd = self->field_30.vf4() + offset;
    if (headerEnd > end) {
        self->field_8 = nullptr;
        return;
    }
    self->field_0 = self->field_30.field_a;
    if (headerEnd + self->field_0 > end) {
        self->field_8 = nullptr;
        return;
    }
    self->field_8 = data;
    u8 fromThisStation;
    u8 value;
    if (!(self->field_30.field_9 & 4)) {
        self->field_58 = buffer->field_628;
        fromThisStation = buffer->m_Header.field_d;
        value = buffer->field_620;
    } else {
        self->field_58.Unk_165fb70();
        fromThisStation = 0;
        value = 0;
    }
    self->field_80 = fromThisStation;
    self->field_81 = value;
    self->field_82 = buffer->field_623;
}

namespace nn {
namespace pia {
namespace transport {

// 0x710173e1e0
bool ProtocolManager::Unk_173e1e0(u8 type) const {
    for (s32 i = 0; i < field_4c; ++i) {
        if (field_29[i] == type) {
            return false;
        }
    }
    return true;
}

// 0x710173e470
Unk_165e060 ProtocolMessageAccessor::Header::vf3(const u8* buffer, u32 bufferSize) {
    if (buffer == nullptr) {
        return Unk_165e060Value<0x10c07>();
    }
    if (bufferSize < 0x18) {
        return Unk_165e060Value<0x10c07>();
    }
    const u8* p = buffer;
    field_8 = *p++;
    if (field_8 & 1) {
        field_9 = *p;
        p++;
    }
    if (field_8 & 2) {
        field_a = __builtin_bswap16(*reinterpret_cast<const u16*>(p));
        p += 2;
    }
    if (field_8 & 4) {
        field_c = __builtin_bswap32(*reinterpret_cast<const u32*>(p));
        p += 4;
    }
    if (field_8 & 8) {
        field_10 = __builtin_bswap64(*reinterpret_cast<const u64*>(p));
        p += 8;
    }
    if (field_8 & 0x10) {
        field_18 = __builtin_bswap64(*reinterpret_cast<const u64*>(p));
    }
    return Unk_165e060Value<0>();
}

// 0x710173e560
u32 ProtocolMessageAccessor::Header::vf4() {
    u32 size = 1;
    if (field_8 & 1) {
        size += 1;
    }
    if (field_8 & 2) {
        size += 2;
    }
    if (field_8 & 4) {
        size += 4;
    }
    if (field_8 & 8) {
        size += 8;
    }
    if (field_8 & 0x10) {
        size += 8;
    }
    return size;
}

}  // namespace transport
}  // namespace pia
}  // namespace nn

// 0x710173e5b0
void Unk_173e5e0::Unk_173e5b0() {
    field_8 = nullptr;
    field_58.Unk_165fb70();
    field_80 = 0;
    field_0 = 0;
}

// 0x710173e5f0
void Unk_173e5e0::Unk_173e5f0(void* out) {
    memcpy(out, field_8 + field_30.vf4(), field_0);
}

// 0x710173e650
u8 Unk_173e5e0::Unk_173e650(u32 offset) {
    return field_8[field_30.vf4() + offset];
}

// 0x710173e6a0
u16 Unk_173e5e0::Unk_173e6a0(u32 offset) {
    return __builtin_bswap16(*reinterpret_cast<const u16*>(&field_8[field_30.vf4() + offset]));
}

// 0x710173e700
u32 Unk_173e5e0::Unk_173e700(u32 offset) {
    return __builtin_bswap32(*reinterpret_cast<const u32*>(&field_8[field_30.vf4() + offset]));
}

// 0x710173e760
u64 Unk_173e5e0::Unk_173e760(u32 offset) {
    return __builtin_bswap64(*reinterpret_cast<const u64*>(&field_8[field_30.vf4() + offset]));
}
