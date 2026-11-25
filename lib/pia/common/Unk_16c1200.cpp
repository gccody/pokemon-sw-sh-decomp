// Scope: common
// Unk_16c1200's members up to 0x71016c19c0 (lib/pia/common/Unk_16c1200.h).
#include "pia/common/Unk_16c1200.h"
#include "pia/common/Unk_17162d0.h"

// The reserved placement form (<new>; Pia builds without libc++'s headers).
inline void* operator new(size_t, void* where) noexcept {
    return where;
}

// Called on an array before it's freed (lib/pia/common/Unk_16d8140.h).
u64 Unk_17163e0(void* memory);

namespace nn {
namespace pia {
namespace common {

// 0x71016c1200
Unk_16c1200::Unk_16c1200() {
    m_List.m_Root.prev = nullptr;
    m_List.m_Root.next = nullptr;
    m_List.Unk_16580b0_init();
    m_Pool.m_Root.prev = nullptr;
    m_Pool.m_Root.next = nullptr;
    m_Pool.Unk_16580b0_init();
    m_Entries = nullptr;
    m_Capacity = 0;
    m_Pool.m_Offset = 0;
    m_Memory = nullptr;
}

// 0x71016c1250
// NON_MATCHING: Unk_16c12f0 inlined, with its difference.
Unk_16c1200::~Unk_16c1200() {
    Unk_16c12f0();
}

// 0x71016c12f0
// NON_MATCHING: when there are no entries, the original still tests the memory again before
// freeing it (the path isn't threaded); the same code otherwise.
void Unk_16c1200::Unk_16c12f0() {
    if (m_Memory != nullptr) {
        Unk_16c1530();
        u64* memory = m_Memory;
        if (memory != nullptr) {
            Unk_17163e0(memory);
            Unk_1716390(memory);
        }
        m_Memory = nullptr;
    }
}

// 0x71016c1390
// NON_MATCHING: block layout: the original keeps each return's result store in its own block and
// puts the shared result copy last, after the success path; the same instructions otherwise.
Unk_165e060 Unk_16c1200::Unk_16c1390(u32 capacity) {
    if (capacity == 0) {
        return Unk_165e060Value<0x10c07>();
    }
    if (m_Memory != nullptr) {
        return Unk_165e060Value<0x10c02>();
    }
    u32 size = capacity * sizeof(Entry);
    u32 count = size / sizeof(u64);
    u64* memory = static_cast<u64*>(operator new(sizeof(u64) * count, Unk_1652bd0()));
    if (memory != nullptr) {
        for (size_t i = 0; i != count; i++) {
            memory[i] = 0;
        }
    }
    m_Memory = memory;
    if (m_Memory == nullptr) {
        return Unk_165e060Value<0x10c01>();
    }
    m_Entries = reinterpret_cast<Entry*>(m_Memory);
    m_Capacity = capacity;
    for (u32 i = 0; i < capacity; i++) {
        Entry* entry = &m_Entries[i];
        entry->node.prev = nullptr;
        entry->node.next = nullptr;
        m_Pool.Unk_16580c0(&m_Pool.m_Root, reinterpret_cast<Unk_16580b0_node*>(
                                               reinterpret_cast<uintptr_t>(entry) + m_Pool.m_Offset));
    }
    field_48 = capacity;
    return Unk_165e060Value<0>();
}

// 0x71016c1530
void Unk_16c1200::Unk_16c1530() {
    if (m_Entries != nullptr) {
        Unk_16580b0_node* node = m_List.m_Root.next;
        while (node != &m_List.m_Root) {
            Unk_16580b0_node* next = node->next;
            node->prev = nullptr;
            node->next = nullptr;
            m_Pool.Unk_16580f0(&m_Pool.m_Root, reinterpret_cast<Unk_16580b0_node*>(
                                                   reinterpret_cast<uintptr_t>(node) + m_Pool.m_Offset));
            node = next;
        }
        m_List.Unk_16580b0_init();
    }
    field_48 = m_Capacity;
}

// 0x71016c15b0
Unk_165e060 Unk_16c1200::Unk_16c15b0(u64 field_0, u8 field_8, u64 field_10) {
    if (m_Pool.m_Count == 0) {
        return Unk_165e060Value<0xc10>();
    }
    Unk_16580b0_node* node = m_Pool.Unk_16581f0();
    Entry* entry = node != nullptr
                       ? reinterpret_cast<Entry*>(reinterpret_cast<u8*>(node) - m_Pool.m_Offset)
                       : nullptr;
    new (&entry->data) Data();
    m_List.Unk_16580c0(&m_List.m_Root, &entry->node);
    entry->data.field_0 = field_0;
    entry->data.field_8 = field_8;
    entry->data.field_10 = field_10;
    entry->data.field_18 = false;
    return Unk_165e060Value<0>();
}

// 0x71016c1690
void Unk_16c1200::Unk_16c1690(u64 field_0, bool value) {
    Data* data = Unk_16c16d0(static_cast<Unk_16c16d0_arg0*>(this), field_0);
    if (data != nullptr) {
        data->field_18 = value;
    }
}

}  // namespace common
}  // namespace pia
}  // namespace nn

// 0x71016c16d0
nn::pia::common::Unk_16c1200::Data* Unk_16c16d0(Unk_16c16d0_arg0* self, u64 field_0) {
    using nn::pia::common::Unk_16580b0_node;
    for (Unk_16580b0_node* node = self->m_List.m_Root.next; node != &self->m_List.m_Root;
         node = node->next) {
        Unk_16c16d0_arg0::Entry* entry = Unk_16c16d0_arg0::ToEntry(node);
        if (entry->data.field_0 == field_0) {
            return &entry->data;
        }
    }
    return nullptr;
}

namespace nn {
namespace pia {
namespace common {

// 0x71016c1710
void Unk_16c1200::Unk_16c1710(u8 field_8, bool value) {
    Data* data = Unk_16c1750(field_8);
    if (data != nullptr) {
        data->field_18 = value;
    }
}

// 0x71016c1750
Unk_16c1200::Data* Unk_16c1200::Unk_16c1750(u8 field_8) {
    for (Unk_16580b0_node* node = m_List.m_Root.next; node != &m_List.m_Root; node = node->next) {
        Entry* entry = ToEntry(node);
        if (entry->data.field_8 == field_8) {
            return &entry->data;
        }
    }
    return nullptr;
}

// 0x71016c1790
bool Unk_16c1200::Unk_16c1790(u64 field_0) const {
    for (Unk_16580b0_node* node = m_List.m_Root.next; node != &m_List.m_Root; node = node->next) {
        Entry* entry = ToEntry(node);
        if (entry->data.field_0 == field_0) {
            return entry->data.field_18;
        }
    }
    return false;
}

// 0x71016c17e0
Unk_165e060 Unk_16c1200::Unk_16c17e0(u64 field_0) {
    return Unk_16c1820(Unk_16c16d0(static_cast<Unk_16c16d0_arg0*>(this), field_0));
}

// 0x71016c1820
Unk_165e060 Unk_16c1200::Unk_16c1820(Data* data) {
    if (data == nullptr) {
        return Unk_165e060Value<0x2c0a>();
    }
    data->field_0 = 0;
    data->field_8 = 0xfd;
    data->field_10 = 0;
    data->field_18 = false;
    Entry* entry = reinterpret_cast<Entry*>(reinterpret_cast<u8*>(data) - sizeof(Unk_16580b0_node));
    m_List.Unk_1658120(&entry->node);
    m_Pool.Unk_16580f0(&m_Pool.m_Root, reinterpret_cast<Unk_16580b0_node*>(
                                           reinterpret_cast<u8*>(entry) + m_Pool.m_Offset));
    return Unk_165e060Value<0>();
}

// 0x71016c18d0
Unk_16c1200::Data* Unk_16c1200::Unk_16c18d0(u64 field_10) {
    for (Unk_16580b0_node* node = m_List.m_Root.next; node != &m_List.m_Root; node = node->next) {
        Entry* entry = ToEntry(node);
        if (entry->data.field_10 == field_10) {
            return &entry->data;
        }
    }
    return nullptr;
}

// 0x71016c1910
Unk_165e060 Unk_16c1200::Unk_16c1910(Data* out, u8 field_8) {
    if (out == nullptr) {
        return Unk_165e060Value<0x10c07>();
    }
    const Data* data = Unk_16c1750(field_8);
    if (data == nullptr) {
        return Unk_165e060Value<0x2c0a>();
    }
    *out = *data;
    return Unk_165e060Value<0>();
}

// 0x71016c19c0
Unk_165e060 Unk_16c1200::Unk_16c19c0(Data* out, u64 field_0) {
    if (out == nullptr) {
        return Unk_165e060Value<0x10c07>();
    }
    for (Unk_16580b0_node* node = m_List.m_Root.next; node != &m_List.m_Root; node = node->next) {
        Entry* entry = ToEntry(node);
        if (entry->data.field_0 == field_0) {
            *out = entry->data;
            return Unk_165e060Value<0>();
        }
    }
    return Unk_165e060Value<0x2c0a>();
}

}  // namespace common
}  // namespace pia
}  // namespace nn
