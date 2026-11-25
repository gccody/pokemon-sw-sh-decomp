#pragma once
// transport::ReceiveThreadStream (vtable 0x7102460ee8, RTTI
// N2nn3pia9transport19ReceiveThreadStreamE), its base TransportThreadStream
// and SendThreadStream's packet pool, Unk_174bc30, with the members their
// functions here use. pia/common/Unk_174aea0.h declares the same classes with
// the members of ThreadStreamManager's and SendThreadStream's files (it has
// none of the pool's delay members, Unk_1660390's copy or the mutex's lock),
// so a file includes one header or the other. Placeholder names
// (lib/pia/README.md).
#include "pia/common/Unk_1734ed0.h"

// The reserved placement form (<new>; Pia builds without libc++'s headers).
inline void* operator new(size_t, void* where) noexcept {
    return where;
}

// The system tick (lib/nx_middleware/leaf/Unk_16598a0.cpp) and the ticks in a
// millisecond.
struct Unk_165c600 {
    u64 field_0;
};
PKMN_SIZE_ASSERT(Unk_165c600, 0x8);
void Unk_165c600_call(Unk_165c600* self);  // reads the tick
const s64* Unk_165c6b0();

// The queue of received packets (its leaf functions: lib/nx_middleware/leaf).
struct Unk_173bc80;
struct Unk_173bd40 {
    u8 _0[0x8];
    u32 field_8;
    u32 field_c;
    s32 field_10;  // the packets in it
};
PKMN_OFFSET_ASSERT(Unk_173bd40, field_10, 0x10);
namespace nn {
namespace pia {
class Unk_1660390;
}  // namespace pia
}  // namespace nn
nn::pia::Unk_1660390* Unk_173bb40(Unk_173bd40* self, u32 index);
nn::pia::Unk_1660390* Unk_173bb80(Unk_173bd40* self);
void Unk_173bb30_update(u64 arg0, void* arg1);  // empty
void Unk_173bc80_set(Unk_173bc80* self);

// What ReceiveThreadStream passes Unk_173bb30_update when it has no packet.
struct Unk_173bb30_arg1 {
    u32 field_0;
    u32 field_4;
    u32 field_8;
};

// A table of 12 0x68-byte entries (an entry by its index, null past the end)
// and an entry's name (up to 63 characters).
struct Unk_165d8e0_arg0;
struct Unk_165d9b0_arg0;
Unk_165d9b0_arg0* Unk_165d8e0(Unk_165d8e0_arg0* self, s32 index);
void Unk_165d9b0(Unk_165d9b0_arg0* self, const char* name);
extern Unk_165d8e0_arg0* Unk_27fb008;

// The object behind the global Unk_27fac38 (placeholder): the stream threads'
// settings.
struct Unk_174c7d0_global {
    u8 _0[0x2ac];
    u32 field_2ac;
    u8 _2b0[0x2b7 - 0x2b0];
    u8 field_2b7;
};
PKMN_OFFSET_ASSERT(Unk_174c7d0_global, field_2ac, 0x2ac);
PKMN_OFFSET_ASSERT(Unk_174c7d0_global, field_2b7, 0x2b7);
extern Unk_174c7d0_global Unk_27fac38;

// The leaf setters of the pool's two buffers (lib/nx_middleware/leaf).
struct Unk_174be10;
void Unk_174be10_set(Unk_174be10* self, u64 value);

// A string over a buffer of its own (pia/common/Unk_165fb10.h).
class Unk_23a2c98 {
public:
    Unk_23a2c98() : field_18(0) {}
    virtual ~Unk_23a2c98() {}
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();

    char* field_8;
    u32 field_10;
    u32 field_14;
    u32 field_18;
};
PKMN_OFFSET_ASSERT(Unk_23a2c98, field_18, 0x18);

namespace nn {
namespace pia {
namespace common {

// RTTI N2nn3pia6common11FixedStringILj48EEE (pia/common/Unk_165fb10.h).
template <u32 N>
class FixedString : public Unk_23a2c98 {
public:
    FixedString() {
        field_8 = m_Buffer;
        field_10 = N * 4;
        field_14 = 0;
        for (u32 i = 0; i < sizeof(m_Buffer); ++i) {
            m_Buffer[i] = '\0';
        }
        field_14 = 0;
        field_18 = 0;
    }
    virtual ~FixedString() {}
    virtual void vf3();
    virtual void vf5();

    char m_Buffer[N * 4 + 1];
};

}  // namespace common

// common::InetAddress (RTTI N2nn3pia6common11InetAddressE; placeholder name,
// as in pia/common/Unk_165fb10.h, which declares it without the host
// constructor): an IPv4 host in 16 bytes and a port.
class Unk_1652c70 {
public:
    Unk_1652c70();
    Unk_1652c70(u32 host, u16 port) {
        Unk_1652d50(host);
        field_18 = port;
    }
    virtual ~Unk_1652c70();

    void Unk_1652d50(u32 host);  // sets the host (the first 4 of the 16 bytes)
    void Unk_1652fe0(Unk_23a2c98* out) const;  // writes itself as text

    u8 field_8[0x10];
    u16 field_18;
};
PKMN_OFFSET_ASSERT(Unk_1652c70, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_1652c70, field_18, 0x18);
PKMN_SIZE_ASSERT(Unk_1652c70, 0x20);

// common::StationAddress (N2nn3pia6common14StationAddressE): one
// InetAddress.
class Unk_165fb30 {
public:
    virtual ~Unk_165fb30();

    Unk_1652c70 field_8;
};
PKMN_SIZE_ASSERT(Unk_165fb30, 0x28);

// An nn::os::MutexType (recursive, pia/common/Unk_174aea0.h): locks and
// unlocks it (each a tail call through a PLT stub).
class Unk_1655c60 {
public:
    explicit Unk_1655c60(s32 arg);
    ~Unk_1655c60();

    void Unk_1655c80();
    void Unk_1655c90();

    u8 _0[0x20];
};
PKMN_SIZE_ASSERT(Unk_1655c60, 0x20);

// A random number generator (xorshift128), seeded from the system tick.
class Unk_171e0e0 {
public:
    Unk_171e0e0();

    u32 Unk_171e1e0();  // the next number

    u32 field_0[4];
};
PKMN_SIZE_ASSERT(Unk_171e0e0, 0x10);

// A Packet::Header with the payload after it (lib/pia/common/Unk_165ff30.cpp
// declares it whole): the members and fields used here.
class Unk_1660390 {
public:
    Unk_1660390();
    ~Unk_1660390();

    void Unk_1660570(const Unk_1660390& other);  // copies it
    void Unk_16601f0();                          // reads the header
    void Unk_1660440();
    bool Unk_1660500() const;

    u8 _0[0xc];
    u8 field_c;  // the header's flags
    u8 _d[0x5e8 - 0xd];
    u32 field_5e8;  // the end of the data
    u8 _5ec[0x623 - 0x5ec];
    u8 field_623;
    u8 _624[0x628 - 0x624];
    Unk_165fb30 field_628;  // the source
    u8 field_650;
};
PKMN_OFFSET_ASSERT(Unk_1660390, field_5e8, 0x5e8);
PKMN_OFFSET_ASSERT(Unk_1660390, field_623, 0x623);
PKMN_OFFSET_ASSERT(Unk_1660390, field_628, 0x628);
PKMN_SIZE_ASSERT(Unk_1660390, 0x658);

namespace transport {

// A pool of entries over common::Unk_16580b0's lists: the ones in use and the
// free ones, then the entries and their count (pia/common/Unk_174aea0.h).
template <typename T>
class Unk_174b9b0_base {
public:
    struct Entry {
        common::Unk_16580b0_node node;
        T data;
    };

    // Takes an entry from the pool (the caller checks it isn't empty) and
    // puts it in the list.
    T* Alloc() {
        common::Unk_16580b0_node* node = m_Pool.Unk_16581f0();
        Entry* entry =
            node != nullptr
                ? reinterpret_cast<Entry*>(reinterpret_cast<uintptr_t>(node) - m_Pool.m_Offset)
                : nullptr;
        new (&entry->data) T();
        m_List.Unk_16580c0(&m_List.m_Root, &entry->node);
        return &entry->data;
    }

    // Puts an entry of the list back in the pool.
    void Free(T* data) {
        Entry* entry = reinterpret_cast<Entry*>(reinterpret_cast<uintptr_t>(data) -
                                                sizeof(common::Unk_16580b0_node));
        data->~T();
        m_List.Unk_1658120(&entry->node);
        m_Pool.Unk_16580f0(&m_Pool.m_Root, reinterpret_cast<common::Unk_16580b0_node*>(
                                               reinterpret_cast<uintptr_t>(entry) + m_Pool.m_Offset));
    }

    common::Unk_16580b0 m_List;
    common::Unk_16580b0 m_Pool;
    Entry* m_Entries;
    u32 m_Capacity;
};

template <typename T, u32 N>
class Unk_174b9b0 : public Unk_174b9b0_base<T> {
public:
    typedef typename Unk_174b9b0_base<T>::Entry Entry;

    u8 m_Buffer[sizeof(Entry) * N];
};

// The pool's delays per host (its field_6e8 entries): a random delay, in
// milliseconds, in [field_0, field_4) for the packets of field_8.
struct Unk_174c120_data {
    u32 field_0;
    u32 field_4;
    Unk_1652c70 field_8;
};
PKMN_OFFSET_ASSERT(Unk_174c120_data, field_8, 0x8);
PKMN_SIZE_ASSERT(Unk_174c120_data, 0x28);

// A packet of the pool and when it's due.
struct Unk_174bc30_packet {
    Unk_174bc30_packet() : field_658(0) { packet.Unk_1660440(); }

    Unk_1660390 packet;
    u64 field_658;  // the tick it's due
};
PKMN_SIZE_ASSERT(Unk_174bc30_packet, 0x660);

// Where SendThreadStream sends its packets (vf20 of the factory, placeholder).
class Unk_174b620_arg1 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual Unk_165e060 vf4(Unk_1660390* packet);
};

// Where ReceiveThreadStream receives its packets from (vf19 of the factory,
// placeholder).
class Unk_174c650_arg1 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual Unk_165e060 vf2(Unk_1660390* packet);
};

// The thread streams' packet pool (placeholder, after its constructor): the
// packets sent or received wait in the list for a delay (field_6e8's, by
// host) before they go on.
class Unk_174bc30 : public Unk_174b9b0_base<Unk_174bc30_packet> {
public:
    explicit Unk_174bc30(u32 capacity);
    ~Unk_174bc30();

    void Unk_174be20();                                  // empties the list
    Unk_165e060 Unk_174be80(Unk_1660390* packet);        // takes a due packet
    Unk_165e060 Unk_174bfc0(Unk_1660390* packet);        // adds a packet to send
    s32 Unk_174c120(const Unk_1652c70& address);         // a delay for a host
    Unk_165e060 Unk_174c230();                           // receives or sends
    Unk_165e060 Unk_174c2d0();                           // sends the due packets
    Unk_165e060 Unk_174c420();                           // receives packets

    u32* field_40;  // the entries' memory
    Unk_174c650_arg1* field_48;  // the receive side's buffer
    Unk_174b620_arg1* field_50;  // the send side's buffer
    Unk_1655c60 field_58;
    Unk_171e0e0 field_78;
    Unk_174bc30_packet field_88;
    Unk_174b9b0<Unk_174c120_data, 17> field_6e8;
};
PKMN_OFFSET_ASSERT(Unk_174bc30, m_Pool, 0x18);
PKMN_OFFSET_ASSERT(Unk_174bc30, field_48, 0x48);
PKMN_OFFSET_ASSERT(Unk_174bc30, field_58, 0x58);
PKMN_OFFSET_ASSERT(Unk_174bc30, field_78, 0x78);
PKMN_OFFSET_ASSERT(Unk_174bc30, field_88, 0x88);
PKMN_OFFSET_ASSERT(Unk_174bc30, field_6e8, 0x6e8);

class TransportThreadStream {
public:
    TransportThreadStream();
    virtual void vf0() {}
    virtual Unk_165e060 vf1() = 0;
    virtual ~TransportThreadStream();

    Unk_165e060 Unk_174f430(const char* name, u32 arg2, u32 arg3, u32 arg4, bool arg5, u32 arg6);
    bool Unk_174fb80(const Unk_1652c70& address);

    u8 field_8[0x10];
    Unk_173bd40 field_18;  // the received packets
    u8 _2c[0x30 - 0x2c];
    Unk_173bd40 field_30;  // the packets to send
    u8 _44[0xc4 - 0x44];
    u32 field_c4;
    u8 _c8[0xd8 - 0xc8];
    Unk_174bc30* field_d8;
    u8 _e0[0x4f0 - 0xe0];
};
PKMN_OFFSET_ASSERT(TransportThreadStream, field_18, 0x18);
PKMN_OFFSET_ASSERT(TransportThreadStream, field_30, 0x30);
PKMN_OFFSET_ASSERT(TransportThreadStream, field_c4, 0xc4);
PKMN_OFFSET_ASSERT(TransportThreadStream, field_d8, 0xd8);
PKMN_SIZE_ASSERT(TransportThreadStream, 0x4f0);

class ReceiveThreadStream : public TransportThreadStream {
public:
    ReceiveThreadStream();
    virtual void vf0();
    virtual Unk_165e060 vf1();
    virtual ~ReceiveThreadStream();

    Unk_165e060 Unk_174c650(void* buffer, u32 arg2, u32 arg3, u32 arg4, bool arg5);
    void Unk_174c9c0();

    Unk_174c650_arg1* field_4f0;
    u32 field_4f8;  // packets received
    u64 field_500;  // bytes received
};
PKMN_OFFSET_ASSERT(ReceiveThreadStream, field_4f0, 0x4f0);
PKMN_OFFSET_ASSERT(ReceiveThreadStream, field_4f8, 0x4f8);
PKMN_OFFSET_ASSERT(ReceiveThreadStream, field_500, 0x500);
PKMN_SIZE_ASSERT(ReceiveThreadStream, 0x508);

}  // namespace transport
}  // namespace pia
}  // namespace nn

namespace pead {
class Heap;
}

pead::Heap* Unk_1652bd0();
void* operator new(size_t size, pead::Heap* heap, s32 alignment) noexcept;
void Unk_1716390(void* memory);  // frees through the heap that holds it
u64 Unk_17163e0(void* memory);   // called on memory before it's freed

bool Unk_17363e0_get();
bool Unk_17363f0_get();

namespace nn {
namespace pia {
namespace transport {

// RTTI N2nn3pia9transport15ProtocolManagerE (vtable 0x7102460818).
class ProtocolManager {
public:
    ProtocolManager();
    virtual ~ProtocolManager();
    virtual void vf2();

    u8 _8[0x50 - 0x8];
};
PKMN_SIZE_ASSERT(ProtocolManager, 0x50);

// What creating Unk_174c9f0 takes (placeholder, after the function).
struct Unk_174cac0_arg0 {
    void* field_0;
    u16 field_8;
    u32 field_c;
    u32 field_10;
    s32 field_14;
};
PKMN_OFFSET_ASSERT(Unk_174cac0_arg0, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_174cac0_arg0, field_14, 0x14);

// The system tick when it's constructed.
struct Unk_174c9f0_tick : Unk_165c600 {
    Unk_174c9f0_tick() {
        field_0 = 0;
        Unk_165c600_call(this);
    }
};

// The object behind the global Unk_27fc2d8 (pia/common/Unk_174aea0.h calls it
// Unk_174de50, after its leaf getter): created once, in memory kept in
// Unk_27fc2e0, with a ProtocolManager. No RTTI: placeholder name, after its
// constructor.
class Unk_174c9f0 {
public:
    Unk_174c9f0();

    static Unk_165e060 Unk_174cac0(const Unk_174cac0_arg0& setting);  // creates it
    Unk_165e060 Unk_174cc70(const Unk_174cac0_arg0& setting);         // initializes it

    Unk_174c9f0_tick field_0;
    u64 field_8;
    ProtocolManager field_10;
    u64 field_60;
    u64 field_68;
    u32 field_70;
    Unk_165e060 field_74;
    u64 field_88;
    u64 field_90;
    u8 _98[0xa0 - 0x98];
    u64 field_a0;
    u64 field_a8;
    u32 field_b0;
    u64 field_b8;
    u16 field_c0;
    u32 field_c4;
    u64 field_c8;
    u8 field_d0;
    Unk_165e060 field_d4;
};
PKMN_OFFSET_ASSERT(Unk_174c9f0, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_174c9f0, field_60, 0x60);
PKMN_OFFSET_ASSERT(Unk_174c9f0, field_74, 0x74);
PKMN_OFFSET_ASSERT(Unk_174c9f0, field_88, 0x88);
PKMN_OFFSET_ASSERT(Unk_174c9f0, field_a0, 0xa0);
PKMN_OFFSET_ASSERT(Unk_174c9f0, field_b8, 0xb8);
PKMN_OFFSET_ASSERT(Unk_174c9f0, field_c4, 0xc4);
PKMN_OFFSET_ASSERT(Unk_174c9f0, field_d0, 0xd0);
PKMN_OFFSET_ASSERT(Unk_174c9f0, field_d4, 0xd4);
PKMN_SIZE_ASSERT(Unk_174c9f0, 0xe8);

}  // namespace transport
}  // namespace pia
}  // namespace nn

extern nn::pia::transport::Unk_174c9f0* Unk_27fc2d8;  // the instance
extern u32* Unk_27fc2e0;                              // its memory
