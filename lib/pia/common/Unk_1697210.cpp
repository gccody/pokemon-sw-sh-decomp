// Scope: common
// The end of local::LocalProtocol's members (RTTI N2nn3pia5local13LocalProtocolE)
// and local::LocalMessage (RTTI N2nn3pia5local12LocalMessageE) with the four
// messages derived from it (LocalUpdateSessionMessage,
// LocalDestroyNetworkMessage, LocalStartHostMigrationMessage, LocalAckMessage:
// their vtables' RTTI). Member names are placeholders (vf<slot>,
// lib/pia/README.md). The messages' vf3 (reading the header back) are in
// lib/nx_middleware/class/nn_pia_local_*Message.cpp.
//
// The messages are one TU: every derived vtable's slot 0 is LocalMessage's
// (empty) D2, and their D0s are a bare `b operator delete`, so the base's
// destructor is defined where their vtables are emitted.
#include <string.h>

#include "pia/common/Unk_165e060.h"

// An address with a 16-byte host and a port (placeholder: no RTTI found yet).
struct Unk_1653890_arg0 {
    u8 _0[0x8];
    u8 m_Host[0x10];
    u16 m_Port;
    u8 _1a[0x6];
};
PKMN_OFFSET_ASSERT(Unk_1653890_arg0, m_Host, 0x8);
PKMN_OFFSET_ASSERT(Unk_1653890_arg0, m_Port, 0x18);
PKMN_SIZE_ASSERT(Unk_1653890_arg0, 0x20);

bool Unk_1653890(const Unk_1653890_arg0* self);                                // set host and port
bool Unk_1653b50(const Unk_1653890_arg0* self, const Unk_1653890_arg0* other);  // equal
u8 Unk_1695c30(void* self);

// What a message writes itself into and reads itself from (placeholder: called
// through its vtable, slots 2 to 4).
class Unk_1697380_arg1 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual nn::pia::Unk_165e060 vf2(u8* buffer, u32* size, u32 capacity);
    virtual nn::pia::Unk_165e060 vf3(const u8* buffer, u32 capacity);
    virtual u16 vf4();
};

// What an update describes (placeholder).
struct Unk_1697550_40 {
    u8 _0[0x374];
    u32 field_374;
    u8 _378[0x16f8 - 0x378];
    u32 field_16f8;
    u32 field_16fc;
    u64 field_1700;
};
PKMN_OFFSET_ASSERT(Unk_1697550_40, field_374, 0x374);
PKMN_OFFSET_ASSERT(Unk_1697550_40, field_16f8, 0x16f8);
PKMN_OFFSET_ASSERT(Unk_1697550_40, field_16fc, 0x16fc);
PKMN_OFFSET_ASSERT(Unk_1697550_40, field_1700, 0x1700);

namespace nn {
namespace pia {
namespace local {

class LocalProtocol {
public:
    bool vf52();

    u8 _0[0x2a0];
    Unk_1653890_arg0 field_2a0;
    Unk_1653890_arg0 field_2c0;
    u8 _2e0[0x418 - 0x2e0];
    u32 field_418;
    u8 _41c[0x47d - 0x41c];
    u8 field_47d;
};
PKMN_OFFSET_ASSERT(LocalProtocol, field_2a0, 0x2a0);
PKMN_OFFSET_ASSERT(LocalProtocol, field_2c0, 0x2c0);
PKMN_OFFSET_ASSERT(LocalProtocol, field_418, 0x418);
PKMN_OFFSET_ASSERT(LocalProtocol, field_47d, 0x47d);

// 0x7101697220
bool LocalProtocol::vf52() {
    if (!field_47d) {
        return false;
    }
    if (field_418 != 0) {
        return false;
    }
    if (Unk_1653890(&field_2c0) && Unk_1653890(&field_2a0) && Unk_1653b50(&field_2a0, &field_2c0)) {
        return false;
    }
    if (!Unk_1653890(&field_2c0) || !Unk_1653890(&field_2a0)) {
        return true;
    }
    return Unk_1653b50(&field_2a0, &field_2c0);
}

// A message in a buffer: a header (a version, 1, the message's type and the
// payload's size), the fixed part of the message up to m_HeaderSize, then a
// payload of m_PayloadSize bytes.
class LocalMessage {
public:
    LocalMessage(u8* buffer, u16 bufferSize);
    virtual ~LocalMessage();

    virtual void vf2();  // writes the header
    virtual u32 vf3();   // reads it back

    bool Unk_1697380(Unk_1697380_arg1* data);
    bool Unk_1697410(Unk_1697380_arg1* data);
    void Unk_1697490(const void* data, u16 size);
    void Unk_16974f0(void* out, s32 offset, u16 size);

protected:
    LocalMessage(u8* buffer, u16 bufferSize, u8 type, u16 headerSize)
        : m_Buffer(buffer), m_BufferSize(bufferSize), m_Type(type), m_HeaderSize(headerSize),
          m_PayloadSize(0), m_ReadOffset(0) {}

public:
    u8* m_Buffer;
    u16 m_BufferSize;
    u8 m_Type;
    u16 m_HeaderSize;
    u16 m_PayloadSize;
    u16 m_ReadOffset;
};
PKMN_OFFSET_ASSERT(LocalMessage, m_Buffer, 0x8);
PKMN_OFFSET_ASSERT(LocalMessage, m_BufferSize, 0x10);
PKMN_OFFSET_ASSERT(LocalMessage, m_Type, 0x12);
PKMN_OFFSET_ASSERT(LocalMessage, m_HeaderSize, 0x14);
PKMN_OFFSET_ASSERT(LocalMessage, m_PayloadSize, 0x16);
PKMN_OFFSET_ASSERT(LocalMessage, m_ReadOffset, 0x18);
PKMN_SIZE_ASSERT(LocalMessage, 0x20);

// 0x7101697300
LocalMessage::LocalMessage(u8* buffer, u16 bufferSize) : LocalMessage(buffer, bufferSize, 1, 0xc) {}

// 0x71016978a0 (and 0x7101697880, deleting)
LocalMessage::~LocalMessage() {}

// 0x7101697330
void LocalMessage::vf2() {
    u8* buffer = m_Buffer;
    buffer[0] = 1;
    buffer[1] = m_Type;
    *reinterpret_cast<u16*>(buffer + 2) = m_PayloadSize;
    memset(buffer + 4, 0, 6);
}

// 0x7101697380
bool LocalMessage::Unk_1697380(Unk_1697380_arg1* data) {
    u32 size = 0;
    data->vf2(m_Buffer + (m_HeaderSize + m_PayloadSize), &size,
              m_BufferSize - (m_HeaderSize + m_PayloadSize));
    m_PayloadSize += size;
    vf2();
    return true;
}

// 0x7101697410
bool LocalMessage::Unk_1697410(Unk_1697380_arg1* data) {
    data->vf3(m_Buffer + (m_HeaderSize + m_ReadOffset), m_BufferSize - (m_HeaderSize + m_ReadOffset));
    m_ReadOffset += data->vf4();
    return true;
}

// 0x7101697490
void LocalMessage::Unk_1697490(const void* data, u16 size) {
    memcpy(m_Buffer + (m_HeaderSize + m_PayloadSize), data, size);
    m_PayloadSize += size;
    vf2();
}

// 0x71016974f0
void LocalMessage::Unk_16974f0(void* out, s32 offset, u16 size) {
    memcpy(out, m_Buffer + (m_HeaderSize + offset), size);
}

class LocalUpdateSessionMessage : public LocalMessage {
public:
    LocalUpdateSessionMessage(u8* buffer, u16 bufferSize, u32 arg3, u32 arg4, u32 arg5, u64 arg6,
                              Unk_1697550_40* arg7);

    void vf2() override;
    u32 vf3() override;

    u32 field_1c;
    u32 field_20;
    u32 field_24;
    u32 field_28;
    u64 field_30;
    u8 field_38;
    Unk_1697550_40* field_40;
};
PKMN_OFFSET_ASSERT(LocalUpdateSessionMessage, field_1c, 0x1c);
PKMN_OFFSET_ASSERT(LocalUpdateSessionMessage, field_30, 0x30);
PKMN_OFFSET_ASSERT(LocalUpdateSessionMessage, field_38, 0x38);
PKMN_OFFSET_ASSERT(LocalUpdateSessionMessage, field_40, 0x40);
PKMN_SIZE_ASSERT(LocalUpdateSessionMessage, 0x48);

// 0x7101697510
LocalUpdateSessionMessage::LocalUpdateSessionMessage(u8* buffer, u16 bufferSize, u32 arg3, u32 arg4,
                                                     u32 arg5, u64 arg6, Unk_1697550_40* arg7)
    : LocalMessage(buffer, bufferSize), field_1c(arg3), field_24(arg4), field_28(arg5), field_30(arg6),
      field_40(arg7) {
    m_Type = 0x11;
    m_HeaderSize = 0x30;
}

// 0x7101697550
void LocalUpdateSessionMessage::vf2() {
    LocalMessage::vf2();
    u8* buffer = m_Buffer;
    *reinterpret_cast<u32*>(buffer + 0xc) = field_1c;
    Unk_1697550_40* session = field_40;
    *reinterpret_cast<u32*>(buffer + 0x10) = session->field_374;
    *reinterpret_cast<u32*>(buffer + 0x14) = session->field_16f8;
    *reinterpret_cast<u32*>(buffer + 0x18) = session->field_16fc;
    *reinterpret_cast<u64*>(buffer + 0x20) = session->field_1700;
    buffer[0x28] = Unk_1695c30(session);
    memset(buffer + 0x29, 0, 7);
}

class LocalDestroyNetworkMessage : public LocalMessage {
public:
    LocalDestroyNetworkMessage(u8* buffer, u16 bufferSize);

    void vf2() override;
    u32 vf3() override;
};

// 0x7101697630
LocalDestroyNetworkMessage::LocalDestroyNetworkMessage(u8* buffer, u16 bufferSize)
    : LocalMessage(buffer, bufferSize) {
    m_Type = 0x12;
    m_HeaderSize = 0x10;
}

// 0x7101697660
void LocalDestroyNetworkMessage::vf2() {
    LocalMessage::vf2();
    *reinterpret_cast<u32*>(m_Buffer + 0xc) = 0;
}

class LocalStartHostMigrationMessage : public LocalMessage {
public:
    LocalStartHostMigrationMessage(u8* buffer, u16 bufferSize);

    void vf2() override;
    u32 vf3() override;
};

// 0x71016976d0
LocalStartHostMigrationMessage::LocalStartHostMigrationMessage(u8* buffer, u16 bufferSize)
    : LocalMessage(buffer, bufferSize) {
    m_Type = 0x13;
    m_HeaderSize = 0x10;
}

// 0x7101697700
void LocalStartHostMigrationMessage::vf2() {
    LocalMessage::vf2();
    *reinterpret_cast<u32*>(m_Buffer + 0xc) = 0;
}

class LocalAckMessage : public LocalMessage {
public:
    LocalAckMessage(u8* buffer, u16 bufferSize, u8 type, u32 arg4);

    void vf2() override;
    u32 vf3() override;

    u32 field_1c;
};
PKMN_OFFSET_ASSERT(LocalAckMessage, field_1c, 0x1c);

// 0x7101697770
LocalAckMessage::LocalAckMessage(u8* buffer, u16 bufferSize, u8 type, u32 arg4)
    : LocalMessage(buffer, bufferSize), field_1c(arg4) {
    m_Type = type;
    m_HeaderSize = 0x14;
}

// 0x71016977a0
void LocalAckMessage::vf2() {
    LocalMessage::vf2();
    u8* buffer = m_Buffer;
    *reinterpret_cast<u32*>(buffer + 0xc) = field_1c;
    *reinterpret_cast<u32*>(buffer + 0x10) = 0;
}

// The derived messages' deleting destructors, emitted with their vtables:
// 0x7101697890 (LocalUpdateSessionMessage), 0x71016978b0
// (LocalDestroyNetworkMessage), 0x71016978c0 (LocalStartHostMigrationMessage),
// 0x71016978d0 (LocalAckMessage).

}  // namespace local
}  // namespace pia
}  // namespace nn
