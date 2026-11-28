// Scope: common
// transport::StationManager's station lookups and transport::ThreadStreamManager
// (lib/pia/common/Unk_174aea0.h). StationManager::vf19 and
// ThreadStreamManager::vf2 are in lib/nx_middleware/class.
#include "pia/common/Unk_174aea0.h"

#include "pia/common/Unk_17162d0.h"

struct Unk_174b770;
struct Unk_174c7a0;
void Unk_174b770_call(Unk_174b770* self);  // SendThreadStream's, clears its buffer
void Unk_174c7a0_call(Unk_174c7a0* self);  // ReceiveThreadStream's, clears its buffer
u64 Unk_17163e0(void* memory);              // called on memory before it's freed

// What StationManager's slots 7 and 8 look a station's index up from (placeholder).
struct Unk_174fd20_arg0;
u8 Unk_174fd20(const Unk_174fd20_arg0* arg);  // the station index (0xfd: none)

namespace nn {
namespace pia {
namespace transport {

// StationManager as its slots 2-12 use it. pia/common/Unk_174aea0.h, a
// shared header, declares those slots without their parameters and the two
// pools as one link, so they are placeholder free functions over this view of
// it. Each pool keeps its entries' memory at field_8 or field_10: the first
// holds the stations in use, the second the stations to reuse.
class Unk_2460d78_self {
public:
    typedef Unk_174b9b0_base<Station*> Pool;
    typedef Pool::Entry Entry;

    virtual void vf0();
    virtual void vf1();
    virtual Unk_165e060 vf2(void* arg1, u32 capacity);
    virtual void vf3();
    virtual Station* vf4();
    virtual void vf5(Station* station);
    virtual void vf6();
    virtual Station* vf7(const Unk_174fd20_arg0* arg);
    virtual Station* vf8(const Unk_174fd20_arg0* arg);
    virtual Station* vf9(u8 index);
    virtual Station* vf10(u8 index);
    virtual Station* vf11(const Unk_165fb30& address);
    virtual Station* vf12(const Unk_165fb30& address);
    virtual void vf13();
    virtual void vf14();
    virtual void vf15();
    virtual void vf16();
    virtual void vf17();
    virtual void vf18();
    virtual void vf19();
    virtual bool vf20(u8 index);  // a valid station index

    u32* field_8;   // field_18's entries
    u32* field_10;  // field_58's entries
    Pool field_18;  // the stations
    Pool field_58;  // the stations to reuse
    Station* field_98;  // this station
    u8 field_a0;
};
PKMN_SIZE_ASSERT(Unk_2460d78_self::Entry, 0x18);
PKMN_OFFSET_ASSERT(Unk_2460d78_self, field_18, 0x18);
PKMN_OFFSET_ASSERT(Unk_2460d78_self, field_58, 0x58);
PKMN_OFFSET_ASSERT(Unk_2460d78_self, field_98, 0x98);
PKMN_OFFSET_ASSERT(Unk_2460d78_self, field_a0, 0xa0);

typedef Unk_2460d78_self::Pool StationPool;
typedef Unk_2460d78_self::Entry StationEntry;

static u32* NewEntries(u32 size) {
    u32* memory = static_cast<u32*>(operator new(size, Unk_1652bd0()));
    if (memory != nullptr) {
        for (size_t i = 0; i < size / sizeof(u32); i++) {
            memory[i] = 0;
        }
    }
    return memory;
}

static void DeleteEntries(u32*& entries) {
    u32* memory = entries;
    if (memory != nullptr) {
        Unk_17163e0(memory);
        Unk_1716390(memory);
        entries = nullptr;
    }
}

static void Init(StationPool& pool, u32* memory, u32 capacity) {
    if (capacity != 0) {
        pool.m_Entries = reinterpret_cast<StationEntry*>(memory);
        pool.m_Capacity = capacity;
        for (u32 i = 0; i < capacity; i++) {
            pool.AddToPool(&pool.m_Entries[i]);
        }
    }
}

static void Clear(StationPool& pool) {
    common::Unk_16580b0_node* node = pool.m_List.m_Root.next;
    while (node != &pool.m_List.m_Root) {
        common::Unk_16580b0_node* next = node->next;
        node->prev = nullptr;
        node->next = nullptr;
        pool.m_Pool.Unk_16580f0(&pool.m_Pool.m_Root, reinterpret_cast<common::Unk_16580b0_node*>(
                                                         reinterpret_cast<uintptr_t>(node) + pool.m_Pool.m_Offset));
        node = next;
    }
    pool.m_List.Unk_16580b0_init();
}

static Station** Find(StationPool& pool, Station* station) {
    for (common::Unk_16580b0_node* node = pool.m_List.m_Root.next; node != &pool.m_List.m_Root;
         node = node->next) {
        StationEntry* entry = reinterpret_cast<StationEntry*>(node);
        if (entry->data == station) {
            return &entry->data;
        }
    }
    return nullptr;
}

static Station** Back(StationPool& pool) {
    common::Unk_16580b0_node* node = pool.m_List.m_Root.prev;
    return node != nullptr ? &reinterpret_cast<StationEntry*>(node)->data : nullptr;
}

static void Erase(StationPool& pool, Station** data) {
    StationEntry* entry =
        reinterpret_cast<StationEntry*>(reinterpret_cast<u8*>(data) - sizeof(common::Unk_16580b0_node));
    pool.m_List.Unk_1658120(&entry->node);
    pool.m_Pool.Unk_16580f0(&pool.m_Pool.m_Root, reinterpret_cast<common::Unk_16580b0_node*>(
                                                     reinterpret_cast<u8*>(entry) + pool.m_Pool.m_Offset));
}

static void PushBack(StationPool& pool, Station* station) {
    common::Unk_16580b0_node* node = pool.m_Pool.Unk_16581f0();
    StationEntry* entry =
        node != nullptr ? reinterpret_cast<StationEntry*>(reinterpret_cast<u8*>(node) - pool.m_Pool.m_Offset)
                        : nullptr;
    entry->data = nullptr;
    pool.m_List.Unk_16580c0(&pool.m_List.m_Root, &entry->node);
    entry->data = station;
}

// 0x710174a6b0
Station* Unk_174a6b0(Unk_2460d78_self* self) {
    if (self->field_98 != nullptr) {
        return nullptr;
    }
    self->field_98 = self->vf4();
    return self->field_98;
}

// 0x710174a6f0
// NON_MATCHING: the original clears each pool's memory one word at a time, a byte offset compared
// with the size after testing the size and then the pointer; clang 7 unrolls this loop and tests
// the pointer first (as in Unk_174bc30::Unk_174bcc0). The rest is the same code.
Unk_165e060 Unk_174a6f0(Unk_2460d78_self* self, void* arg1, u32 capacity) {
    u32 size = capacity * sizeof(StationEntry);
    self->field_8 = NewEntries(size);
    if (self->field_8 == nullptr) {
        return Unk_165e060Value<0x10c01>();
    }
    Init(self->field_18, self->field_8, capacity);
    Clear(self->field_18);
    self->field_10 = NewEntries(size);
    if (self->field_10 == nullptr) {
        return Unk_165e060Value<0x10c01>();
    }
    Init(self->field_58, self->field_10, capacity);
    Clear(self->field_58);
    return Unk_165e060Value<0>();
}

// 0x710174a970
void Unk_174a970(Unk_2460d78_self* self) {
    while (self->field_18.m_List.m_Count != 0) {
        Station** data = Back(self->field_18);
        if (data == nullptr) {
            break;
        }
        Erase(self->field_18, data);
    }
    while (self->field_58.m_List.m_Count != 0) {
        Station** data = Back(self->field_58);
        if (data == nullptr) {
            break;
        }
        Erase(self->field_58, data);
    }
    DeleteEntries(self->field_10);
    DeleteEntries(self->field_8);
}

// 0x710174aa50
Station* Unk_174aa50(Unk_2460d78_self* self) {
    if (self->field_58.m_List.m_Count == 0 || self->field_18.m_Pool.m_Count == 0) {
        return nullptr;
    }
    Station** data = Back(self->field_58);
    Station* station = *data;
    if (station != nullptr) {
        Erase(self->field_58, data);
        PushBack(self->field_18, station);
    }
    return station;
}

// 0x710174ab10
void Unk_174ab10(Unk_2460d78_self* self, Station* station) {
    if (station == nullptr || Find(self->field_18, station) == nullptr) {
        return;
    }
    if (self->field_58.m_Pool.m_Count == 0) {
        return;
    }
    PushBack(self->field_58, station);
    Station** data = Find(self->field_18, station);
    if (data == nullptr) {
        return;
    }
    Erase(self->field_18, data);
    if (self->field_98 == station) {
        self->field_98 = nullptr;
    }
}

// 0x710174ac20
Station* Unk_174ac20(Unk_2460d78_self* self, const Unk_174fd20_arg0* arg) {
    return self->vf9(Unk_174fd20(arg));
}

// 0x710174ac60
Station* Unk_174ac60(Unk_2460d78_self* self, const Unk_174fd20_arg0* arg) {
    return self->vf10(Unk_174fd20(arg));
}

// 0x710174aca0
Station* Unk_174aca0(Unk_2460d78_self* self, u8 index) {
    if (!self->vf20(index)) {
        return nullptr;
    }
    for (common::Unk_16580b0_node* node = self->field_18.m_List.m_Root.next;
         node != &self->field_18.m_List.m_Root; node = node->next) {
        Station* station = reinterpret_cast<StationEntry*>(node)->data;
        if (station->field_38 == index) {
            return station;
        }
    }
    return nullptr;
}

// 0x710174ad20
Station* Unk_174ad20(Unk_2460d78_self* self, u8 index) {
    if (!self->vf20(index)) {
        return nullptr;
    }
    for (common::Unk_16580b0_node* node = self->field_18.m_List.m_Root.next;
         node != &self->field_18.m_List.m_Root; node = node->next) {
        Station* station = reinterpret_cast<StationEntry*>(node)->data;
        if (station->field_38 == index) {
            return station;
        }
    }
    return nullptr;
}

// 0x710174ada0
Station* Unk_174ada0(Unk_2460d78_self* self, const Unk_165fb30& address) {
    for (common::Unk_16580b0_node* node = self->field_18.m_List.m_Root.next;
         node != &self->field_18.m_List.m_Root; node = node->next) {
        StationEntry* entry = reinterpret_cast<StationEntry*>(node);
        if (entry->data->field_10.Unk_165fd40(address)) {
            return entry->data;
        }
    }
    return nullptr;
}

// 0x710174ae20
Station* Unk_174ae20(Unk_2460d78_self* self, const Unk_165fb30& address) {
    for (common::Unk_16580b0_node* node = self->field_18.m_List.m_Root.next;
         node != &self->field_18.m_List.m_Root; node = node->next) {
        StationEntry* entry = reinterpret_cast<StationEntry*>(node);
        if (entry->data->field_10.Unk_165fd40(address)) {
            return entry->data;
        }
    }
    return nullptr;
}

// 0x710174aea0
Station* StationManager::vf13(const Unk_1652c70* address) {
    for (StationManagerLink* link = field_18.next; link != &field_18; link = link->next) {
        StationManagerNode* node = static_cast<StationManagerNode*>(link);
        if (Unk_1653b50(reinterpret_cast<const Unk_1653890_arg0*>(&node->station->field_10.field_8),
                        reinterpret_cast<const Unk_1653890_arg0*>(address))) {
            return node->station;
        }
    }
    return nullptr;
}

// 0x710174af20
Station* StationManager::vf14(const Unk_1652c70* address) {
    for (StationManagerLink* link = field_18.next; link != &field_18; link = link->next) {
        StationManagerNode* node = static_cast<StationManagerNode*>(link);
        if (Unk_1653b50(reinterpret_cast<const Unk_1653890_arg0*>(&node->station->field_10.field_8),
                        reinterpret_cast<const Unk_1653890_arg0*>(address))) {
            return node->station;
        }
    }
    return nullptr;
}

// 0x710174afa0
Station* StationManager::vf15(u64 id) {
    for (StationManagerLink* link = field_18.next; link != &field_18; link = link->next) {
        Station* station = static_cast<StationManagerNode*>(link)->station;
        if (station->field_40 == id) {
            return station;
        }
    }
    return nullptr;
}

// 0x710174afe0
Station* StationManager::vf16(u64 id) {
    for (StationManagerLink* link = field_18.next; link != &field_18; link = link->next) {
        Station* station = static_cast<StationManagerNode*>(link)->station;
        if (station->field_40 == id) {
            return station;
        }
    }
    return nullptr;
}

// 0x710174b020
Unk_165e060 StationManager::Unk_174b020(Unk_165fb30* address, u8 index) {
    if (address == nullptr || !vf20(index)) {
        return Unk_165e060Value<0x10c07>();
    }
    Station* station = vf10(index);
    if (station == nullptr) {
        return Unk_165e060Value<0x2c0a>();
    }
    *address = station->field_10;
    return Unk_165e060Value<0>();
}

// 0x710174b0f0
u32 StationManager::Unk_174b0f0(bool withOwn) {
    u32 mask = 0;
    for (StationManagerLink* link = field_18.next; link != &field_18; link = link->next) {
        Station* station = static_cast<StationManagerNode*>(link)->station;
        if (station->field_38 < 0x20 && station->field_48 == 5) {
            mask |= 1u << station->field_38;
        }
    }
    if (!withOwn && field_98 != nullptr && field_98->field_38 < 0x20) {
        mask &= ~(1u << field_98->field_38);
    }
    return mask;
}

// 0x710174b180
ThreadStreamManager::ThreadStreamManager(Unk_174e330_object* factory, u32 sendArg2, u32 receiveArg2,
                                         u32 sendArg4, u32 receiveArg4, bool arg5)
    : field_8(nullptr), field_10(nullptr), field_18(nullptr), field_20(nullptr) {
    Unk_165e060 result(0);
    field_8 = factory->vf19();
    field_18 = new (Unk_1652bd0()) ReceiveThreadStream();
    result = field_18->Unk_174c650(field_8, receiveArg2, 10, receiveArg4, arg5);
    field_18->field_c4 = 5;
    field_10 = factory->vf20();
    field_20 = new (Unk_1652bd0()) SendThreadStream();
    result = field_20->Unk_174b620(field_10, sendArg2, 10, sendArg4, arg5);
    field_20->field_c4 = 5;
}

// 0x710174b2f0 (and 0x710174b3e0, deleting)
ThreadStreamManager::~ThreadStreamManager() {
    if (field_20 != nullptr) {
        Unk_174b770_call(reinterpret_cast<Unk_174b770*>(field_20));
        SendThreadStream* stream = field_20;
        if (stream != nullptr) {
            stream->~SendThreadStream();
            Unk_1716390(stream);
        }
        field_20 = nullptr;
    }
    if (field_18 != nullptr) {
        Unk_174c7a0_call(reinterpret_cast<Unk_174c7a0*>(field_18));
        ReceiveThreadStream* stream = field_18;
        if (stream != nullptr) {
            stream->~ReceiveThreadStream();
            Unk_1716390(stream);
        }
        field_18 = nullptr;
    }
    if (field_10 != nullptr) {
        Unk_174e330_get(reinterpret_cast<const Unk_174e330*>(Unk_27fc2d8))->vf22(field_10);
        field_10 = nullptr;
    }
    if (field_8 != nullptr) {
        Unk_174e330_get(reinterpret_cast<const Unk_174e330*>(Unk_27fc2d8))->vf21(field_8);
        field_8 = nullptr;
    }
}

// 0x710174b410
Unk_165e060 ThreadStreamManager::Unk_174b410() {
    if (field_18 == nullptr || field_20 == nullptr) {
        return Unk_165e060Value<0x10c08>();
    }
    Unk_165e060 result(0);
    result = field_18->Unk_174f810();
    result = field_20->Unk_174f810();
    return Unk_165e060Value<0>();
}

// 0x710174b510
void ThreadStreamManager::Unk_174b510() {
    if (field_18 != nullptr) {
        field_18->Unk_174f970();
    }
    if (field_20 != nullptr) {
        field_20->Unk_174f970();
    }
}

// 0x710174b550
void ThreadStreamManager::Unk_174b550() {
    if (field_20 != nullptr) {
        field_20->Unk_174b970();
    }
    if (field_18 != nullptr) {
        field_18->Unk_174c9c0();
    }
}

}  // namespace transport
}  // namespace pia
}  // namespace nn
