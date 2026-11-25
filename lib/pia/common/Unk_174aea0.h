#pragma once
// transport::StationManager (vtable 0x7102460d88, RTTI
// N2nn3pia9transport14StationManagerE), transport::ThreadStreamManager
// (0x7102460e50, N2nn3pia9transport19ThreadStreamManagerE) and the thread
// streams it owns: transport::TransportThreadStream (0x7102461070,
// N2nn3pia9transport21TransportThreadStreamE) and its two derived classes,
// SendThreadStream (0x7102460e88) and ReceiveThreadStream (0x7102460ee8), as
// these members use them. Member names are placeholders (lib/pia/README.md).
// pia/common/Unk_16a90f0.h declares StationManager with fewer members, so a
// file includes one header or the other.
#include "pia/common/Unk_1734ed0.h"
#include "pia/common/Unk_1749070.h"

// The object behind the global Unk_27fc2d8 (no RTTI here) and the leaf getter
// (lib/nx_middleware/leaf) of what it holds: the factory of the streams'
// buffers (placeholder).
struct Unk_174de50;
struct Unk_174e330;
extern Unk_174de50* Unk_27fc2d8;

// The queue of packets to send (a leaf, lib/nx_middleware/leaf, resets it:
// Unk_173bd40_set).
struct Unk_173bd40 {
    u8 _0[0x8];
    u32 field_8;
    u32 field_c;
    s32 field_10;  // the packets in it
};
PKMN_OFFSET_ASSERT(Unk_173bd40, field_10, 0x10);

namespace nn {
namespace pia {

// An nn::os::MutexType (recursive) and its owner's other member, a random
// number generator seeded from the system tick (placeholders, after their
// constructors).
class Unk_1655c60 {
public:
    explicit Unk_1655c60(s32 arg);
    ~Unk_1655c60();

    u8 _0[0x20];
};
PKMN_SIZE_ASSERT(Unk_1655c60, 0x20);

class Unk_171e0e0 {
public:
    Unk_171e0e0();

    u32 field_0[4];
};
PKMN_SIZE_ASSERT(Unk_171e0e0, 0x10);

// A Packet::Header with the payload after it (lib/pia/common/Unk_165ff30.cpp
// declares it whole).
class Unk_1660390 {
public:
    Unk_1660390();
    ~Unk_1660390();

    void Unk_1660040();
    void Unk_1660440();

    u8 _0[0x5e8];
    u32 field_5e8;  // the end of the data
    u8 _5ec[0x658 - 0x5ec];
};
PKMN_OFFSET_ASSERT(Unk_1660390, field_5e8, 0x5e8);
PKMN_SIZE_ASSERT(Unk_1660390, 0x658);

}  // namespace pia
}  // namespace nn

namespace nn {
namespace pia {
namespace transport {

class Unk_174b620_arg1;

class Unk_174e330_object {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
    virtual void vf14();
    virtual void vf15();
    virtual void vf16();
    virtual void vf17();
    virtual void vf18();
    virtual void* vf19();  // the receive side's buffer
    virtual Unk_174b620_arg1* vf20();  // the send side's buffer
    virtual void vf21(void* buffer);  // frees vf19's
    virtual void vf22(Unk_174b620_arg1* buffer);  // frees vf20's
};

}  // namespace transport
}  // namespace pia
}  // namespace nn

nn::pia::transport::Unk_174e330_object* Unk_174e330_get(const Unk_174e330* self);

namespace nn {
namespace pia {
namespace transport {

// A node of StationManager's list of stations.
struct StationManagerLink {
    StationManagerLink* prev;
    StationManagerLink* next;
};
struct StationManagerNode : StationManagerLink {
    Station* station;
};
PKMN_OFFSET_ASSERT(StationManagerNode, station, 0x10);

class StationManager {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual Station* vf10(u8 index);
    virtual void vf11();
    virtual void vf12();
    virtual Station* vf13(const Unk_1652c70* address);
    virtual Station* vf14(const Unk_1652c70* address);
    virtual Station* vf15(u64 id);
    virtual Station* vf16(u64 id);
    virtual void vf17();
    virtual void vf18();
    virtual void vf19();
    virtual bool vf20(u8 index);  // a valid station index

    Unk_165e060 Unk_174b020(Unk_165fb30* address, u8 index);  // the address of a station
    u32 Unk_174b0f0(bool withOwn);  // the mask of the connected stations

    u8 _8[0x18 - 0x8];
    StationManagerLink field_18;  // the stations
    u8 _28[0x98 - 0x28];
    Station* field_98;  // this station
};
PKMN_OFFSET_ASSERT(StationManager, field_18, 0x18);
PKMN_OFFSET_ASSERT(StationManager, field_98, 0x98);

// A pool of entries over common::Unk_16580b0's lists (as Unk_16c1200's): the
// ones in use and the free ones, then the entries and their count. Not
// polymorphic and no RTTI: placeholder names, after the fixed pool's
// constructor.
template <typename T>
class Unk_174b9b0_base {
public:
    struct Entry {
        common::Unk_16580b0_node node;
        T data;
    };

    Unk_174b9b0_base() {
        m_List.m_Root.prev = nullptr;
        m_List.m_Root.next = nullptr;
        m_List.Unk_16580b0_init();
        m_Pool.m_Root.prev = nullptr;
        m_Pool.m_Root.next = nullptr;
        m_Pool.Unk_16580b0_init();
        m_Entries = nullptr;
        m_Capacity = 0;
        m_Pool.m_Offset = 0;
    }

    void AddToPool(Entry* entry) {
        entry->node.prev = nullptr;
        entry->node.next = nullptr;
        m_Pool.Unk_16580c0(&m_Pool.m_Root,
                           reinterpret_cast<common::Unk_16580b0_node*>(
                               reinterpret_cast<uintptr_t>(entry) + m_Pool.m_Offset));
    }

    common::Unk_16580b0 m_List;
    common::Unk_16580b0 m_Pool;
    Entry* m_Entries;
    u32 m_Capacity;
};

// The pool with its N entries in the object.
template <typename T, u32 N>
class Unk_174b9b0 : public Unk_174b9b0_base<T> {
public:
    typedef typename Unk_174b9b0_base<T>::Entry Entry;

    Unk_174b9b0();

    u8 m_Buffer[sizeof(Entry) * N];
};

struct Unk_174b9b0_data {
    u8 _0[0x28];
};

// The packet the send buffer pool keeps besides its entries.
struct Unk_174bc30_packet {
    Unk_174bc30_packet() : field_658(0) { packet.Unk_1660440(); }

    Unk_1660390 packet;
    u64 field_658;
};
PKMN_SIZE_ASSERT(Unk_174bc30_packet, 0x660);

// SendThreadStream's packet pool (placeholder, after its constructor).
class Unk_174bc30 : public Unk_174b9b0_base<Unk_174bc30_packet> {
public:
    explicit Unk_174bc30(u32 capacity);
    ~Unk_174bc30();

    bool Unk_174bcc0(u32 capacity);
    Unk_165e060 Unk_174bfc0(Unk_1660390* packet);

    u32* field_40;  // the entries' memory
    u64 field_48;
    u64 field_50;
    Unk_1655c60 field_58;
    Unk_171e0e0 field_78;
    Unk_174bc30_packet field_88;
    Unk_174b9b0<Unk_174b9b0_data, 17> field_6e8;
};
PKMN_SIZE_ASSERT(Unk_174bc30::Entry, 0x670);
PKMN_OFFSET_ASSERT(Unk_174bc30, m_Pool, 0x18);
PKMN_OFFSET_ASSERT(Unk_174bc30, m_Entries, 0x30);
PKMN_OFFSET_ASSERT(Unk_174bc30, m_Capacity, 0x38);
PKMN_OFFSET_ASSERT(Unk_174bc30, field_40, 0x40);
PKMN_OFFSET_ASSERT(Unk_174bc30, field_58, 0x58);
PKMN_OFFSET_ASSERT(Unk_174bc30, field_78, 0x78);
PKMN_OFFSET_ASSERT(Unk_174bc30, field_88, 0x88);
PKMN_OFFSET_ASSERT(Unk_174bc30, field_6e8, 0x6e8);

// Where SendThreadStream sends its packets (vf20 of the factory, placeholder).
class Unk_174b620_arg1 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual Unk_165e060 vf4(Unk_1660390* packet);
};

class TransportThreadStream {
public:
    TransportThreadStream();
    virtual void vf0() {}
    virtual Unk_165e060 vf1() = 0;
    virtual ~TransportThreadStream();

    Unk_165e060 Unk_174f430(const char* name, u32 arg2, u32 arg3, u32 arg4, bool arg5, u32 arg6);
    Unk_165e060 Unk_174f810();
    void Unk_174f970();
    bool Unk_174fb80(const Unk_1652c70& address);

    u8 _8[0x30 - 0x8];
    Unk_173bd40 field_30;
    u8 _44[0xc4 - 0x44];
    u32 field_c4;
    u8 _c8[0xd8 - 0xc8];
    Unk_174bc30* field_d8;
    u8 _e0[0x4f0 - 0xe0];
};
PKMN_OFFSET_ASSERT(TransportThreadStream, field_30, 0x30);
PKMN_OFFSET_ASSERT(TransportThreadStream, field_c4, 0xc4);
PKMN_OFFSET_ASSERT(TransportThreadStream, field_d8, 0xd8);
PKMN_SIZE_ASSERT(TransportThreadStream, 0x4f0);

class SendThreadStream : public TransportThreadStream {
public:
    SendThreadStream();
    virtual Unk_165e060 vf1();
    virtual ~SendThreadStream();

    Unk_165e060 Unk_174b620(Unk_174b620_arg1* buffer, u32 arg2, u32 arg3, u32 arg4, bool arg5);
    void Unk_174b970();

    Unk_174b620_arg1* field_4f0;
    u32 field_4f8;  // packets sent
    u64 field_500;  // bytes sent
};
PKMN_OFFSET_ASSERT(SendThreadStream, field_4f0, 0x4f0);
PKMN_OFFSET_ASSERT(SendThreadStream, field_4f8, 0x4f8);
PKMN_OFFSET_ASSERT(SendThreadStream, field_500, 0x500);
PKMN_SIZE_ASSERT(SendThreadStream, 0x508);

class ReceiveThreadStream : public TransportThreadStream {
public:
    ReceiveThreadStream();
    virtual Unk_165e060 vf1();
    virtual ~ReceiveThreadStream();

    Unk_165e060 Unk_174c650(void* buffer, u32 arg2, u32 arg3, u32 arg4, bool arg5);
    void Unk_174c9c0();

    void* field_4f0;
    u32 field_4f8;
    u64 field_500;
};
PKMN_SIZE_ASSERT(ReceiveThreadStream, 0x508);

class ThreadStreamManager {
public:
    ThreadStreamManager(Unk_174e330_object* factory, u32 sendArg2, u32 receiveArg2, u32 sendArg4,
                        u32 receiveArg4, bool arg5);
    virtual ~ThreadStreamManager();
    virtual void vf2();

    Unk_165e060 Unk_174b410();
    void Unk_174b510();
    void Unk_174b550();

    void* field_8;   // the receive stream's buffer
    Unk_174b620_arg1* field_10;  // the send stream's buffer
    ReceiveThreadStream* field_18;
    SendThreadStream* field_20;
};
PKMN_SIZE_ASSERT(ThreadStreamManager, 0x28);

}  // namespace transport
}  // namespace pia
}  // namespace nn
