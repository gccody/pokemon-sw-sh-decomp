#pragma once
// NEX 4.6.8's data classes whose type names are "LocationData" and
// "SubscriptionData" (the strings their type functions return and compare),
// derived from the data classes' base (type name "Data"), and the client of
// their protocol (vtable 0x7102456528). They have no RTTI: the structs are
// placeholders named after the stream functions that write them
// (lib/nex/ddl/Calls.cpp's inputs), and their slots are written as
// placeholder free functions over them (lib/nex/Unk_164e150.cpp,
// lib/nex/Unk_164e830.cpp). Each class has a vtable of its own fields'
// class (_DDL_-style, the one its D0s store) and one of the class itself.
#include <nn/nex/ByteStream.h>
#include <nn/nex/Call.h>
#include <nn/nex/RefCountedObject.h>
#include <nn/nex/String.h>

// 0x71015cf190: a qBuffer of `capacity` bytes (at least 10), its data starting
// `offset` bytes in.
void Unk_15cf190(nn::nex::qBuffer* self, size_t capacity, size_t offset);
// 0x71015cf360: assigns another qBuffer.
nn::nex::qBuffer* Unk_15cf360(nn::nex::qBuffer* self, const nn::nex::qBuffer& other);
// 0x71015cf460: moves the qBuffer's positions back to where its data starts.
void Unk_15cf460(nn::nex::qBuffer* self);

// 0x710162fa40: the data classes' base constructor (a version at +8, cleared).
void Unk_162fa40(void* self);
// 0x7101630750: the base's assignment (it has nothing to copy).
void Unk_1630750_update(u64, u64);
// 0x7101638210: the base's destructor.
void Unk_1638210(void* self);

// The vtables (data: a vptr is its vtable's address point, two words in).
extern void* Unk_24566d8[];  // LocationData's fields
extern void* Unk_2417e68[];  // LocationData
extern void* Unk_2456628[];  // SubscriptionData's fields
extern void* Unk_2417e18[];  // SubscriptionData
extern void* Unk_2456518[];  // the protocol's client

// The data class whose type name is "LocationData" (the call input of
// lib/nex/ddl/Calls.cpp's Unk_164d300 and Unk_164d510). Its constructor and
// assignment are what the clone (slot 2) inlines; the qBuffer is constructed
// and destroyed by hand (the anonymous union keeps C++ from doing it).
struct Unk_164e020 {
    static void* operator new(size_t size) noexcept { return Unk_15b6dc0(size); }

    Unk_164e020() {
        Unk_162fa40(this);
        m_vtable = Unk_24566d8 + 2;
        m_version = 0;
        Unk_15cf190(&field_28, 0, 0);
        m_vtable = Unk_2417e68 + 2;
        field_10 = 0;
        field_18 = 0;
        field_1c = 0;
        field_20 = 0;
        field_24 = 0;
        Unk_15cf460(&field_28);
    }

    Unk_164e020& operator=(const Unk_164e020& other) {
        Unk_1630750_update(reinterpret_cast<u64>(this), reinterpret_cast<u64>(&other));
        m_version = other.m_version;
        field_10 = other.field_10;
        field_18 = other.field_18;
        field_1c = other.field_1c;
        field_20 = other.field_20;
        field_24 = other.field_24;
        // qBuffer's operator=, its source evaluated first (as C++17 does).
        const nn::nex::qBuffer& buffer = other.field_28;
        Unk_15cf360(&field_28, buffer);
        return *this;
    }

    // The fields' class's destructor (what the D0s inline).
    ~Unk_164e020() {
        m_vtable = Unk_24566d8 + 2;
        field_28.~qBuffer();
        Unk_1638210(this);
    }

    void** m_vtable;
    u8 m_baseVersion;  // the base's
    u8 m_version;
    u64 field_10;
    u32 field_18;
    u32 field_1c;
    u32 field_20;
    u32 field_24;
    union {
        nn::nex::qBuffer field_28;
    };
};
PKMN_SIZE_ASSERT(Unk_164e020, 0x60);
PKMN_OFFSET_ASSERT(Unk_164e020, m_version, 0x9);
PKMN_OFFSET_ASSERT(Unk_164e020, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_164e020, field_24, 0x24);
PKMN_OFFSET_ASSERT(Unk_164e020, field_28, 0x28);

// The data class whose type name is "SubscriptionData" (the call input of
// lib/nex/Unk_164c460.cpp's protocol calls), likewise.
struct Unk_164da60 {
    static void* operator new(size_t size) noexcept { return Unk_15b6dc0(size); }

    Unk_164da60() {
        Unk_162fa40(this);
        m_vtable = Unk_2456628 + 2;
        m_version = 0;
        Unk_15cf190(&field_18, 0, 0);
        m_vtable = Unk_2417e18 + 2;
        field_10 = 0;
    }

    Unk_164da60& operator=(const Unk_164da60& other) {
        Unk_1630750_update(reinterpret_cast<u64>(this), reinterpret_cast<u64>(&other));
        m_version = other.m_version;
        field_10 = other.field_10;
        const nn::nex::qBuffer& buffer = other.field_18;
        Unk_15cf360(&field_18, buffer);
        return *this;
    }

    ~Unk_164da60() {
        m_vtable = Unk_2456628 + 2;
        field_18.~qBuffer();
        Unk_1638210(this);
    }

    void** m_vtable;
    u8 m_baseVersion;  // the base's
    u8 m_version;
    u64 field_10;
    union {
        nn::nex::qBuffer field_18;
    };
};
PKMN_SIZE_ASSERT(Unk_164da60, 0x50);
PKMN_OFFSET_ASSERT(Unk_164da60, m_version, 0x9);
PKMN_OFFSET_ASSERT(Unk_164da60, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_164da60, field_18, 0x18);

// The protocol's client: its virtual functions, only as far as its
// constructor calls them (slot 22 makes a new client of the protocol).
struct Unk_164e720_Client {
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
    virtual void vf19();
    virtual void vf20();
    virtual void vf21();
    virtual nn::nex::ClientProtocol* vf22();
};

// 0x710162eed0: the protocol clients' base constructor.
void Unk_162eed0(nn::nex::ClientProtocol* self, u32 arg1);

struct Unk_1630a10;
// 0x7101630a10: sets the protocol's ID.
void Unk_1630a10_set(Unk_1630a10* self, u16 value);

// What the instance table (InstanceTable.h) holds at +0x70, the default
// instance's, and at +0x68 of a thread's entry: the protocols' registry.
struct Unk_1647560_t;
struct Unk_ProtocolsHolder {
    u8 _0[0x10];
    Unk_1647560_t* m_registry;
};
struct Unk_Protocols {
    u8 _0[0x10];
    Unk_ProtocolsHolder* m_holder;
};
struct Unk_ProtocolsEntry {
    u8 _0[0x68];
    Unk_Protocols* m_protocols;
};
struct Unk_ProtocolsTable {
    u8 _0[0x70];
    Unk_Protocols* m_default;
    u8 _78[0x28];
    nn::nex::qVector<Unk_ProtocolsEntry*>* m_threads;
};
PKMN_OFFSET_ASSERT(Unk_ProtocolsTable, m_threads, 0xa0);

inline Unk_Protocols* GetProtocols() {
    Unk_ProtocolsTable& table = reinterpret_cast<Unk_ProtocolsTable&>(Unk_27f3770);
    Unk_Protocols** slot = &table.m_default;
    if (Unk_27f3838) {
        u32 index = *Unk_6a5230(Unk_27f3830);
        if (index != 0) {
            nn::nex::qVector<Unk_ProtocolsEntry*>& threads = *table.m_threads;
            if (index >= threads.size()) {
                Unk_15b8dc0(NEX_INSTANCE_TABLE_H, 71, 0xe0000003, 0);
                return nullptr;
            }
            slot = &threads[index]->m_protocols;
        }
    }
    return *slot;
}

// 0x7101647560: registers the protocol's client under its ID.
void Unk_1647560(Unk_1647560_t* self, u16 protocolId, nn::nex::ClientProtocol* client);

// The client's constructor (0x710164e720), which the factory (slot 22) inlines.
inline void Unk_164e720_init(nn::nex::ClientProtocol* self, u16 protocolId) {
    Unk_162eed0(self, 1);
    *reinterpret_cast<void***>(self) = Unk_2456518 + 2;
    if (protocolId != 0) {
        Unk_1630a10_set(reinterpret_cast<Unk_1630a10*>(self), protocolId);
        Unk_1647560(GetProtocols()->m_holder->m_registry, self->m_protocolId,
                    reinterpret_cast<Unk_164e720_Client*>(self)->vf22());
    }
}
