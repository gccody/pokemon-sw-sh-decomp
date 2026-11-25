// Scope: common
// A serialisable local::LocalAddress with one more byte (Unk_169a170: its
// vtable 0x710245b358 has no RTTI), then local::LocalResendMessageJob (RTTI
// N2nn3pia5local21LocalResendMessageJobE, derived from common::StepSequenceJob):
// its constructor, destructors and its step, which sends a message again until
// every station has acknowledged it. Names are placeholders
// (lib/pia/README.md), except the step stored with its name. The job's vf5 is
// in lib/nx_middleware/class/nn_pia_local_LocalResendMessageJob.cpp.
#include "pia/common/Unk_16998e0.h"

#include "pia/common/Unk_17162d0.h"

// Called on an array before it's freed (lib/pia/common/Unk_16d8140.h).
u64 Unk_17163e0(void* memory);

// The serialized size of a LocalAddress (8): a free function's placeholder name
// taking the address as a number.
u32 Unk_1687070_get(u64 self);

// A message to send: its buffer, its capacity, its size and its type
// (lib/pia/common/Unk_1697700.cpp). Unk_1697830_set constructs one.
struct Unk_1697830 {
    u8* m_Buffer;
    u32 m_Capacity;
    u16 m_Size;
    u32 m_Type;
};
PKMN_OFFSET_ASSERT(Unk_1697830, m_Capacity, 0x8);
PKMN_OFFSET_ASSERT(Unk_1697830, m_Size, 0xc);
PKMN_OFFSET_ASSERT(Unk_1697830, m_Type, 0x10);
PKMN_SIZE_ASSERT(Unk_1697830, 0x18);
void Unk_1697830_set(Unk_1697830* self, u64 buffer, u32 capacity);
void Unk_1697840(Unk_1697830* self, const void* data, u16 size, u32 type);

// A system tick (Unk_165c600_call reads nn::os::GetSystemTick into it) and the
// ticks in a millisecond (a static computed once).
struct Unk_165c600 {
    u64 field_0;
};
void Unk_165c600_call(Unk_165c600* self);
const s64* Unk_165c6b0();

// Inline: the current tick.
static inline s64 CurrentTick() {
    Unk_165c600 tick = {0};
    Unk_165c600_call(&tick);
    return tick.field_0;
}

// What the job sends through (placeholder: its constructor's argument).
struct Unk_169a460_arg1;
void Unk_1694530(Unk_169a460_arg1* self, Unk_1697830* message);

namespace nn {
namespace pia {
namespace local {

// RTTI N2nn3pia5local12LocalAddressE (vtable 0x7102459bb8). Its destructor is
// inline: callers store its vtable and destroy the Unk_1652c70.
class LocalAddress {
public:
    LocalAddress();
    virtual ~LocalAddress() {}

    virtual void vf2();

    Unk_165e060 Unk_1687080(u8* buffer, u32* size, u32 capacity);
    Unk_165e060 Unk_1687180(const u8* buffer, u32 capacity);

    void Clear() {
        Unk_1653900(&m_Address);
        field_28 = 0;
    }

    Unk_1652c70 m_Address;
    u16 field_28;
};
PKMN_OFFSET_ASSERT(LocalAddress, m_Address, 0x8);
PKMN_OFFSET_ASSERT(LocalAddress, field_28, 0x28);
PKMN_SIZE_ASSERT(LocalAddress, 0x30);

// LocalMessage (lib/pia/common/Unk_1697210.cpp): only its fields are read.
class LocalMessage {
public:
    virtual ~LocalMessage();

    u8* m_Buffer;
    u16 m_BufferSize;
    u8 m_Type;
    u16 m_HeaderSize;
    u16 m_PayloadSize;
    u16 m_ReadOffset;
};
PKMN_OFFSET_ASSERT(LocalMessage, m_Type, 0x12);
PKMN_OFFSET_ASSERT(LocalMessage, m_HeaderSize, 0x14);
PKMN_OFFSET_ASSERT(LocalMessage, m_PayloadSize, 0x16);

}  // namespace local

class Unk_169a170 {
public:
    Unk_169a170();
    virtual ~Unk_169a170();

    virtual Unk_165e060 vf2(u8* buffer, u32* size, u32 capacity);
    virtual Unk_165e060 vf3(const u8* buffer, u32 capacity);
    virtual u32 vf4();
    virtual void vf5();

    local::LocalAddress m_Address;
    u32 field_38;
    u8 field_3c;
    u8 field_3d;
};
PKMN_OFFSET_ASSERT(Unk_169a170, m_Address, 0x8);
PKMN_OFFSET_ASSERT(Unk_169a170, field_38, 0x38);
PKMN_OFFSET_ASSERT(Unk_169a170, field_3c, 0x3c);
PKMN_OFFSET_ASSERT(Unk_169a170, field_3d, 0x3d);
PKMN_SIZE_ASSERT(Unk_169a170, 0x40);

// 0x710169a170
Unk_169a170::Unk_169a170() : field_38(0), field_3c(0), field_3d(0xff) {
    m_Address.Clear();
}

// 0x710169a1c0 (and 0x710169a1e0, deleting)
// NON_MATCHING: 0x710169a1c0 only (the deleting one matches). The two vtable
// stores and the `add x0, x0, #0x10` for the Unk_1652c70's destructor aren't
// merged into the original's post-index `stp x8, x9, [x0], #0x10`: with -g, the
// inlined ~LocalAddress's `this` (DBG_VALUE x0+8) sits between them and blocks
// aarch64-ldst-opt (docs/compiler.md, "Debug info").
Unk_169a170::~Unk_169a170() {}

// 0x710169a220
Unk_165e060 Unk_169a170::vf2(u8* buffer, u32* size, u32 capacity) {
    if (buffer == nullptr || size == nullptr || vf4() > capacity) {
        return Unk_165e060Value<0x10c07>();
    }
    u8* p = buffer;
    u32 written;
    Unk_165e060 result = m_Address.Unk_1687080(p, &written, Unk_1687070_get(reinterpret_cast<u64>(&m_Address)));
    p += Unk_1687070_get(reinterpret_cast<u64>(&m_Address));
    if (result.m_Value != 0) {
        return result;
    }
    *p++ = field_3d;
    *size = p - buffer;
    return Unk_165e060Value<0>();
}

// 0x710169a330
Unk_165e060 Unk_169a170::vf3(const u8* buffer, u32 capacity) {
    if (buffer == nullptr) {
        return Unk_165e060Value<0x10c07>();
    }
    const u8* p = buffer;
    Unk_165e060 result = m_Address.Unk_1687180(p, capacity);
    p += Unk_1687070_get(reinterpret_cast<u64>(&m_Address));
    if (result.m_Value != 0) {
        return result;
    }
    field_3d = *p;
    p++;
    u32 size = p - buffer;
    if (size > capacity) {
        return Unk_165e060Value<0x10c07>();
    }
    return Unk_165e060Value<0>();
}

// 0x710169a430
void Unk_169a170::vf5() {
    m_Address.vf2();
}

// 0x710169a440
u32 Unk_169a170::vf4() {
    return Unk_1687070_get(reinterpret_cast<u64>(&m_Address)) + 1;
}

namespace local {

class LocalResendMessageJob : public common::StepSequenceJob {
public:
    explicit LocalResendMessageJob(Unk_169a460_arg1* owner);
    ~LocalResendMessageJob() override;

    void vf5() override;

    Unk_165e060 Unk_169a5e0();
    common::Unk_165bb20_result ResendMessage();
    Unk_165e060 Unk_169a700(const LocalMessage* message, u32 id, u32 stations);
    void Unk_169a7b0(u32 station, u32 id);

    u32 m_Id;
    u32 m_Stations;  // a bit per station that hasn't acknowledged it yet
    s64 m_SentTick;
    u32 m_Interval;  // in milliseconds
    Unk_1697830* m_Message;
    u32* m_Buffer;
    Unk_169a460_arg1* m_Owner;
};
PKMN_OFFSET_ASSERT(LocalResendMessageJob, m_Id, 0x58);
PKMN_OFFSET_ASSERT(LocalResendMessageJob, m_Stations, 0x5c);
PKMN_OFFSET_ASSERT(LocalResendMessageJob, m_SentTick, 0x60);
PKMN_OFFSET_ASSERT(LocalResendMessageJob, m_Interval, 0x68);
PKMN_OFFSET_ASSERT(LocalResendMessageJob, m_Message, 0x70);
PKMN_OFFSET_ASSERT(LocalResendMessageJob, m_Buffer, 0x78);
PKMN_OFFSET_ASSERT(LocalResendMessageJob, m_Owner, 0x80);
PKMN_SIZE_ASSERT(LocalResendMessageJob, 0x88);

// 0x710169a460
LocalResendMessageJob::LocalResendMessageJob(Unk_169a460_arg1* owner)
    : m_Id(0), m_Stations(0), m_SentTick(0), m_Interval(100), m_Message(nullptr), m_Buffer(nullptr),
      m_Owner(owner) {
    u32* buffer = static_cast<u32*>(operator new(0x5d8, Unk_1652bd0()));
    if (buffer != nullptr) {
        for (size_t i = 0; i < 0x5d8 / sizeof(u32); i++) {
            buffer[i] = 0;
        }
    }
    m_Buffer = buffer;
    Unk_1697830* message = static_cast<Unk_1697830*>(operator new(sizeof(Unk_1697830), Unk_1652bd0()));
    if (message != nullptr) {
        Unk_1697830_set(message, reinterpret_cast<u64>(buffer), 0x5d8);
    }
    m_Message = message;
}

// 0x710169a510 (and 0x710169a570, deleting)
LocalResendMessageJob::~LocalResendMessageJob() {
    u32* buffer = m_Buffer;
    if (buffer != nullptr) {
        Unk_17163e0(buffer);
        Unk_1716390(buffer);
        m_Buffer = nullptr;
    }
    if (m_Message != nullptr) {
        Unk_1716390(m_Message);
        m_Message = nullptr;
    }
    m_Owner = nullptr;
}

// 0x710169a5e0
Unk_165e060 LocalResendMessageJob::Unk_169a5e0() {
    SetStep(&LocalResendMessageJob::ResendMessage, "LocalResendMessageJob::ResendMessage");
    return Unk_165e060Value<0>();
}

// 0x710169a650
common::Unk_165bb20_result LocalResendMessageJob::ResendMessage() {
    if (m_Stations == 0) {
        return {5};
    }
    s64 elapsed = (CurrentTick() - m_SentTick) / *Unk_165c6b0();
    if (elapsed < m_Interval) {
        return {5};
    }
    Unk_1694530(m_Owner, m_Message);
    m_SentTick = CurrentTick();
    return {4, 0, static_cast<u16>(m_Interval)};
}

// 0x710169a700
Unk_165e060 LocalResendMessageJob::Unk_169a700(const LocalMessage* message, u32 id, u32 stations) {
    Unk_1697840(m_Message, message->m_Buffer, message->m_HeaderSize + message->m_PayloadSize, message->m_Type);
    m_Id = id;
    m_Stations = stations;
    Unk_1694530(m_Owner, m_Message);
    m_SentTick = CurrentTick();
    return Unk_165e060Value<0>();
}

// 0x710169a7b0
void LocalResendMessageJob::Unk_169a7b0(u32 station, u32 id) {
    if (m_Id == id) {
        m_Stations &= ~(1 << station);
    }
}

}  // namespace local
}  // namespace pia
}  // namespace nn
