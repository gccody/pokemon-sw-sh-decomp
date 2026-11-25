// Scope: common
// common::SocketStreamBase's destructor and setters, common::Packet::Header's
// serializer (RTTI N2nn3pia6common6Packet6HeaderE; its vf4 is in
// lib/nx_middleware/class/nn_pia_common_Packet_Header.cpp) and the class that
// holds a Header, its payload and two station addresses (placeholder name
// after its constructor; probably common::Packet). Member names are
// placeholders (vf<slot>, lib/pia/README.md).
#include <string.h>

#include "pia/common/Unk_165fb10.h"

namespace nn {
namespace pia {
namespace common {

// 0x710165ff30 (D2), 0x710165ff50 (D0)
SocketStreamBase::~SocketStreamBase() {
    field_10 = nullptr;
}

// 0x710165ff70
Unk_165e060 SocketStreamBase::Unk_165ff70() {
    field_8 = true;
    return Unk_165e060Value<0>();
}

// 0x710165ffe0
Unk_165e060 SocketStreamBase::Unk_165ffe0(void* value) {
    field_10 = value;
    return Unk_165e060Value<0>();
}

namespace Packet {

// Big-endian values in a buffer.
static inline void WriteU32(u8* p, u32 value) {
    p[0] = value >> 24;
    p[1] = value >> 16;
    p[2] = value >> 8;
    p[3] = value;
}

static inline void WriteU16(u8* p, u16 value) {
    p[0] = value >> 8;
    p[1] = value;
}

static inline u32 ReadU32(const u8* p) {
    return (p[0] << 24) | (p[1] << 16) | (p[2] << 8) | p[3];
}

static inline u16 ReadU16(const u8* p) {
    return (p[0] << 8) | p[1];
}

// A packet's header: 0x20 bytes on the wire, big-endian.
class Header {
public:
    virtual ~Header() {}
    virtual Unk_165e060 vf2(u8* buffer, u32* size, u32 capacity);
    virtual Unk_165e060 vf3(const u8* buffer, u32 size);
    virtual u32 vf4();

    u32 field_8;
    u8 field_c;
    u8 field_d;
    u16 field_e;
    u8 field_10[0x8];
    u8 field_18[0x10];
};
PKMN_OFFSET_ASSERT(Header, field_8, 0x8);
PKMN_OFFSET_ASSERT(Header, field_c, 0xc);
PKMN_OFFSET_ASSERT(Header, field_e, 0xe);
PKMN_OFFSET_ASSERT(Header, field_10, 0x10);
PKMN_OFFSET_ASSERT(Header, field_18, 0x18);
PKMN_SIZE_ASSERT(Header, 0x28);

// 0x7101660070
Unk_165e060 Header::vf2(u8* buffer, u32* size, u32 capacity) {
    if (buffer == nullptr || size == nullptr) {
        return Unk_165e060Value<0x10c07>();
    }
    if (capacity < 0x20) {
        return Unk_165e060Value<0x10c07>();
    }
    WriteU32(&buffer[0], field_8);
    buffer[4] = field_c;
    buffer[5] = field_d;
    WriteU16(&buffer[6], field_e);
    for (u32 i = 0; i < sizeof(field_10); ++i) {
        buffer[0x8 + i] = field_10[i];
    }
    for (u32 i = 0; i < sizeof(field_18); ++i) {
        buffer[0x10 + i] = field_18[i];
    }
    *size = 0x20;
    return Unk_165e060Value<0>();
}

// 0x7101660220
Unk_165e060 Header::vf3(const u8* buffer, u32 size) {
    if (buffer == nullptr) {
        return Unk_165e060Value<0x10c07>();
    }
    if (size < 0x20) {
        return Unk_165e060Value<0x10c07>();
    }
    field_8 = ReadU32(&buffer[0]);
    field_c = buffer[4];
    field_d = buffer[5];
    field_e = ReadU16(&buffer[6]);
    for (u32 i = 0; i < sizeof(field_10); ++i) {
        field_10[i] = buffer[0x8 + i];
    }
    for (u32 i = 0; i < sizeof(field_18); ++i) {
        field_18[i] = buffer[0x10 + i];
    }
    return Unk_165e060Value<0>();
}

}  // namespace Packet
}  // namespace common

// A Packet::Header with the payload after it (the header's 0x20 bytes, then
// the data) and two station addresses.
class Unk_1660390 {
public:
    Unk_1660390();
    ~Unk_1660390();

    void Unk_1660570(const Unk_1660390& other);
    void Unk_1660040();
    void Unk_16601f0();
    u8* Unk_1660380(u32 offset);
    void Unk_1660440();
    bool Unk_1660500() const;
    u8* Unk_1660540(u32 size);

    common::Packet::Header m_Header;
    u8 m_Buffer[0x5c0];
    u32 field_5e8;  // the end of the data in m_Buffer
    u8 field_5ec;
    u32 field_5f0;
    Unk_165fb30 field_5f8;
    u8 field_620;
    u8 field_621;
    u8 field_622;
    u8 field_623;
    u8 field_624;
    Unk_165fb30 field_628;
    u8 field_650;
};
PKMN_OFFSET_ASSERT(Unk_1660390, m_Buffer, 0x28);
PKMN_OFFSET_ASSERT(Unk_1660390, field_5e8, 0x5e8);
PKMN_OFFSET_ASSERT(Unk_1660390, field_5ec, 0x5ec);
PKMN_OFFSET_ASSERT(Unk_1660390, field_5f0, 0x5f0);
PKMN_OFFSET_ASSERT(Unk_1660390, field_5f8, 0x5f8);
PKMN_OFFSET_ASSERT(Unk_1660390, field_620, 0x620);
PKMN_OFFSET_ASSERT(Unk_1660390, field_624, 0x624);
PKMN_OFFSET_ASSERT(Unk_1660390, field_628, 0x628);
PKMN_OFFSET_ASSERT(Unk_1660390, field_650, 0x650);
PKMN_SIZE_ASSERT(Unk_1660390, 0x658);

// 0x7101660040
void Unk_1660390::Unk_1660040() {
    u32 size = 0;
    m_Header.vf2(m_Buffer, &size, sizeof(m_Buffer));
}

// 0x71016601f0
void Unk_1660390::Unk_16601f0() {
    m_Header.vf3(m_Buffer, sizeof(m_Buffer));
}

// 0x7101660380
u8* Unk_1660390::Unk_1660380(u32 offset) {
    return &m_Buffer[offset + 0x20];
}

// 0x7101660390
Unk_1660390::Unk_1660390() {
    Unk_1660440();
}

// 0x7101660440
void Unk_1660390::Unk_1660440() {
    m_Header.field_8 = 0x32ab9864;
    m_Header.field_c = 4;
    m_Header.field_d = 0;
    m_Header.field_e = 0;
    memset(m_Header.field_10, 0, sizeof(m_Header.field_10));
    memset(m_Header.field_18, 0, sizeof(m_Header.field_18));
    field_5e8 = 0x20;
    field_5ec = 0xfd;
    field_5f0 = 0;
    field_5f8.Unk_165fb70();
    field_620 = 0;
    field_621 = 0;
    field_622 = 0;
    field_623 = 0;
    field_624 = 1;
    field_628.Unk_165fb70();
    field_650 = 0;
}

// 0x71016604c0
Unk_1660390::~Unk_1660390() {}

// 0x7101660500
bool Unk_1660390::Unk_1660500() const {
    return m_Header.field_8 == 0x32ab9864 && (m_Header.field_c & 0x7f) == 4 && field_5e8 >= 0x20 &&
           field_5e8 <= sizeof(m_Buffer);
}

// 0x7101660540
u8* Unk_1660390::Unk_1660540(u32 size) {
    u32 end = field_5e8 + size;
    if (end > sizeof(m_Buffer)) {
        return nullptr;
    }
    u8* data = &m_Buffer[field_5e8];
    field_5e8 = end;
    return data;
}

// 0x7101660570
void Unk_1660390::Unk_1660570(const Unk_1660390& other) {
    m_Header.field_8 = other.m_Header.field_8;
    m_Header.field_c = other.m_Header.field_c;
    m_Header.field_d = other.m_Header.field_d;
    m_Header.field_e = other.m_Header.field_e;
    for (u32 i = 0; i < sizeof(m_Header.field_10); ++i) {
        m_Header.field_10[i] = other.m_Header.field_10[i];
    }
    memcpy(m_Buffer, other.m_Buffer, sizeof(m_Buffer));
    field_5e8 = other.field_5e8;
    field_5ec = other.field_5ec;
    field_5f0 = other.field_5f0;
    field_5f8 = other.field_5f8;
    field_620 = other.field_620;
    field_621 = other.field_621;
    field_622 = other.field_622;
    field_623 = other.field_623;
    field_624 = other.field_624;
    field_628 = other.field_628;
    field_650 = other.field_650;
}

}  // namespace pia
}  // namespace nn
