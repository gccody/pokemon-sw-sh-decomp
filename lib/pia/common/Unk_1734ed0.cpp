// Scope: common
#include "pia/common/Unk_1734ed0.h"

// The reserved placement form (<new>; Pia builds without libc++'s headers).
inline void* operator new(size_t, void* where) noexcept {
    return where;
}

namespace nn {
namespace pia {
namespace common {

// 0x7101734ed0
// NON_MATCHING: the bool parameter's mask (`and #1`) is computed at entry instead of after the
// insert call, which shifts the register allocation; the rest is the same.
Unk_165e060 Unk_1734ed0::Unk_1734ed0_add(u64 id, u32 field_18, u32 field_0, bool field_9) {
    if (m_Pool.m_Count == 0) {
        return Unk_165e060Value<0xc10>();
    }
    Unk_16580b0& list = m_List;
    Unk_16580b0_node* node = m_Pool.Unk_16581f0();
    Entry* entry = node != nullptr
                       ? reinterpret_cast<Entry*>(reinterpret_cast<u8*>(node) - m_Pool.m_Offset)
                       : nullptr;
    new (&entry->data) Data();
    list.Unk_16580c0(&list.m_Root, &entry->node);
    entry->data.field_8 = true;
    entry->data.field_9 = field_9;
    entry->data.field_10 = id;
    entry->data.field_0 = field_0;
    entry->data.field_4 = 0;
    entry->data.field_18 = field_18;
    entry->data.field_1c = false;
    entry->data.field_1e = false;
    entry->data.field_1f = false;
    return Unk_165e060Value<0>();
}

// 0x7101734fd0
Unk_165e060 Unk_1734ed0::Unk_1734fd0(u64 id) {
    for (Unk_16580b0_node* node = m_List.m_Root.next; node != &m_List.m_Root; node = node->next) {
        Entry* entry = ToEntry(node);
        if (entry->data.field_10 == id) {
            entry->data.field_8 = false;
            entry->data.field_9 = false;
            entry->data.field_0 = 0;
            entry->data.field_4 = 0;
            entry->data.field_10 = 0;
            entry->data.field_18 = 0;
            entry->data.field_1c = false;
            entry->data.field_1d = 0xfd;
            entry->data.field_1e = false;
            entry->data.field_1f = false;
            m_List.Unk_1658120(&entry->node);
            m_Pool.Unk_16580f0(&m_Pool.m_Root, reinterpret_cast<Unk_16580b0_node*>(
                                                    reinterpret_cast<u8*>(entry) + m_Pool.m_Offset));
            return Unk_165e060Value<0>();
        }
    }
    return Unk_165e060Value<0x2c0a>();
}

// 0x71017350a0
Unk_1734ed0::Data* Unk_1734ed0::Unk_17350a0(u64 id) {
    for (Unk_16580b0_node* node = m_List.m_Root.next; node != &m_List.m_Root; node = node->next) {
        Entry* entry = ToEntry(node);
        if (entry->data.field_10 == id) {
            return &entry->data;
        }
    }
    return nullptr;
}

// 0x71017350e0
void Unk_1734ed0::Unk_17350e0() {
    for (Unk_16580b0_node* node = m_List.m_Root.next; node != &m_List.m_Root; node = node->next) {
        ToEntry(node)->data.field_0 = 0;
    }
}

// 0x7101735110
void Unk_1734ed0::Unk_1735110(u64 id, bool value) {
    for (Unk_16580b0_node* node = m_List.m_Root.next; node != &m_List.m_Root; node = node->next) {
        Entry* entry = ToEntry(node);
        if (entry->data.field_10 == id) {
            entry->data.field_0 = value ? 2 : 1;
            return;
        }
    }
}

// 0x7101735150
u32 Unk_1734ed0::Unk_1735150(const u64* ids, u16 count) const {
    bool any = false;
    for (Unk_16580b0_node* node = m_List.m_Root.next; node != &m_List.m_Root; node = node->next) {
        Entry* entry = ToEntry(node);
        if (ids != nullptr && count != 0) {
            bool found = false;
            for (u16 i = 0; i < count; i++) {
                if (entry->data.field_10 == ids[i]) {
                    found = true;
                    break;
                }
            }
            if (!found) {
                continue;
            }
        }
        if (entry->data.field_0 == 1) {
            return 2;
        }
        any |= entry->data.field_0 == 0;
    }
    return any;
}

// 0x7101735220
u32 Unk_1734ed0::Unk_1735220(u64 id) const {
    for (Unk_16580b0_node* node = m_List.m_Root.next; node != &m_List.m_Root; node = node->next) {
        Entry* entry = ToEntry(node);
        if (entry->data.field_10 == id) {
            return entry->data.field_0;
        }
    }
    return 0;
}

// 0x7101735260
void Unk_1734ed0::Unk_1735260() {
    for (Unk_16580b0_node* node = m_List.m_Root.next; node != &m_List.m_Root; node = node->next) {
        ToEntry(node)->data.field_8 = false;
    }
}

// 0x7101735290
void Unk_1734ed0::Unk_1735290(u64 id, bool value) {
    for (Unk_16580b0_node* node = m_List.m_Root.next; node != &m_List.m_Root; node = node->next) {
        Entry* entry = ToEntry(node);
        if (entry->data.field_10 == id) {
            entry->data.field_8 = value;
        }
    }
}

// 0x71017352d0
bool Unk_1734ed0::Unk_17352d0(const u64* ids, u16 count) const {
    for (Unk_16580b0_node* node = m_List.m_Root.next; node != &m_List.m_Root; node = node->next) {
        Entry* entry = ToEntry(node);
        for (u16 i = 0; i < count; i++) {
            if (entry->data.field_10 == ids[i]) {
                if (entry->data.field_8 == 0) {
                    return false;
                }
                break;
            }
        }
    }
    return true;
}

// 0x7101735350
bool Unk_1734ed0::Unk_1735350(u64 id) const {
    for (Unk_16580b0_node* node = m_List.m_Root.next; node != &m_List.m_Root; node = node->next) {
        Entry* entry = ToEntry(node);
        if (entry->data.field_10 == id) {
            return entry->data.field_8 != 0;
        }
    }
    return false;
}

// 0x71017353a0
bool Unk_1734ed0::Unk_17353a0(u64 id, bool value) {
    for (Unk_16580b0_node* node = m_List.m_Root.next; node != &m_List.m_Root; node = node->next) {
        Entry* entry = ToEntry(node);
        if (entry->data.field_10 == id) {
            entry->data.field_1e = value;
            return true;
        }
    }
    return false;
}

// 0x71017353f0
bool Unk_1734ed0::Unk_17353f0(u64 id) const {
    for (Unk_16580b0_node* node = m_List.m_Root.next; node != &m_List.m_Root; node = node->next) {
        Entry* entry = ToEntry(node);
        if (entry->data.field_10 == id) {
            return entry->data.field_1e != 0;
        }
    }
    return false;
}

// 0x7101735440
void Unk_1734ed0::Unk_1735440() {
    for (Unk_16580b0_node* node = m_List.m_Root.next; node != &m_List.m_Root; node = node->next) {
        ToEntry(node)->data.field_1e = false;
    }
}

// 0x7101735470
bool Unk_1734ed0::Unk_1735470(u64 id, bool value) {
    for (Unk_16580b0_node* node = m_List.m_Root.next; node != &m_List.m_Root; node = node->next) {
        Entry* entry = ToEntry(node);
        if (entry->data.field_10 == id) {
            entry->data.field_1f = value;
            return true;
        }
    }
    return false;
}

// 0x71017354c0
bool Unk_1734ed0::Unk_17354c0(u64 id) const {
    for (Unk_16580b0_node* node = m_List.m_Root.next; node != &m_List.m_Root; node = node->next) {
        Entry* entry = ToEntry(node);
        if (entry->data.field_10 == id) {
            return entry->data.field_1f != 0;
        }
    }
    return false;
}

}  // namespace common
}  // namespace pia
}  // namespace nn
