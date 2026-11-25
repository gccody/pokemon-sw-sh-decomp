// Scope: common
#include "pia/common/Unk_1734ed0.h"

namespace nn {
namespace pia {
namespace common {

// 0x7101735510
void Unk_1734ed0::Unk_1735510() {
    for (Unk_16580b0_node* node = m_List.m_Root.next; node != &m_List.m_Root; node = node->next) {
        ToEntry(node)->data.field_1f = false;
    }
}

// 0x7101735540
bool Unk_1734ed0::Unk_1735540(u64 id, bool value) {
    for (Unk_16580b0_node* node = m_List.m_Root.next; node != &m_List.m_Root; node = node->next) {
        Entry* entry = ToEntry(node);
        if (entry->data.field_10 == id) {
            entry->data.field_4 = value ? 1 : 2;
            return true;
        }
    }
    return false;
}

// 0x7101735590
u32 Unk_1734ed0::Unk_1735590(u64 id) const {
    for (Unk_16580b0_node* node = m_List.m_Root.next; node != &m_List.m_Root; node = node->next) {
        Entry* entry = ToEntry(node);
        if (entry->data.field_10 == id) {
            return entry->data.field_4;
        }
    }
    return 0;
}

// 0x71017355d0
void Unk_1734ed0::Unk_17355d0() {
    for (Unk_16580b0_node* node = m_List.m_Root.next; node != &m_List.m_Root; node = node->next) {
        ToEntry(node)->data.field_4 = 0;
    }
}

// 0x7101735600
void Unk_1734ed0::Unk_1735600(u64 id, bool value) {
    for (Unk_16580b0_node* node = m_List.m_Root.next; node != &m_List.m_Root; node = node->next) {
        Entry* entry = ToEntry(node);
        if (entry->data.field_10 == id) {
            entry->data.field_9 = value;
        }
    }
}

// 0x7101735640
bool Unk_1734ed0::Unk_1735640(u64 id) const {
    for (Unk_16580b0_node* node = m_List.m_Root.next; node != &m_List.m_Root; node = node->next) {
        Entry* entry = ToEntry(node);
        if (entry->data.field_10 == id) {
            return entry->data.field_9 != 0;
        }
    }
    return false;
}

// 0x7101735690
void Unk_1734ed0::Unk_1735690() {
    Unk_172c3e0_arg0* owner = Unk_27fc0a8;
    u64 id = owner->field_f0;
    if (!Unk_1735640(id)) {
        Unk_172c3e0(owner, id);
        Unk_172c450(owner, id);
        Unk_1735600(id, true);
    }
    id = owner->field_f8;
    // Unk_1735350(id), which is in the other file.
    bool field_8 = false;
    for (Unk_16580b0_node* node = m_List.m_Root.next; node != &m_List.m_Root; node = node->next) {
        Entry* entry = ToEntry(node);
        if (entry->data.field_10 == id) {
            field_8 = entry->data.field_8 != 0;
            break;
        }
    }
    if (!Unk_1735640(id) && field_8) {
        Unk_172c3e0(owner, id);
        Unk_172c450(owner, id);
        Unk_1735600(id, true);
    }
    for (Unk_16580b0_node* node = m_List.m_Root.next; node != &m_List.m_Root; node = node->next) {
        Entry* entry = ToEntry(node);
        if (entry->data.field_9 == 0) {
            Unk_172c3e0(owner, entry->data.field_10);
            Unk_172c450(owner, entry->data.field_10);
            entry->data.field_9 = true;
        }
    }
}

// 0x7101735990
bool Unk_1734ed0::Unk_1735990(const Unk_1735990_arg0* peer) const {
    if (peer == nullptr || peer->field_8 == 0xfe) {
        return false;
    }
    Unk_172c3e0_arg0* owner = Unk_27fc0a8;
    if (owner->field_15c == 0) {
        return false;
    }
    for (Unk_16580b0_node* node = m_List.m_Root.next; node != &m_List.m_Root; node = node->next) {
        Entry* entry = ToEntry(node);
        if (entry->data.field_10 == peer->field_0) {
            if (owner->field_70 == nullptr) {
                return false;
            }
            s32 state = owner->field_70->field_90;
            if (state < 6 || state > 8) {
                return true;
            }
            return entry->data.field_0 == 2;
        }
    }
    return false;
}

// 0x7101735a20
bool Unk_1734ed0::Unk_1735a20(u64 id, u32* out) const {
    for (Unk_16580b0_node* node = m_List.m_Root.next; node != &m_List.m_Root; node = node->next) {
        Entry* entry = ToEntry(node);
        if (entry->data.field_10 == id) {
            *out = entry->data.field_18;
            return true;
        }
    }
    return false;
}

// 0x7101735a70
void Unk_1734ed0::Unk_1735a70(u64 id, u8 value) {
    for (Unk_16580b0_node* node = m_List.m_Root.next; node != &m_List.m_Root; node = node->next) {
        Entry* entry = ToEntry(node);
        if (entry->data.field_10 == id) {
            entry->data.field_1d = value;
            return;
        }
    }
}

// 0x7101735ab0
bool Unk_1734ed0::Unk_1735ab0(u64 id, u8* out) const {
    for (Unk_16580b0_node* node = m_List.m_Root.next; node != &m_List.m_Root; node = node->next) {
        Entry* entry = ToEntry(node);
        if (entry->data.field_10 == id) {
            *out = entry->data.field_1d;
            return true;
        }
    }
    return false;
}

// 0x7101735b00
void Unk_1734ed0::Unk_1735b00(u64 id, bool value) {
    for (Unk_16580b0_node* node = m_List.m_Root.next; node != &m_List.m_Root; node = node->next) {
        Entry* entry = ToEntry(node);
        if (entry->data.field_10 == id) {
            entry->data.field_1c = value;
            return;
        }
    }
}

// 0x7101735b40
bool Unk_1734ed0::Unk_1735b40(u64 id, bool* out) const {
    for (Unk_16580b0_node* node = m_List.m_Root.next; node != &m_List.m_Root; node = node->next) {
        Entry* entry = ToEntry(node);
        if (entry->data.field_10 == id) {
            *out = entry->data.field_1c;
            return true;
        }
    }
    return false;
}

// 0x7101735b90
s32 Unk_1734ed0::Unk_1735b90(u32 value) const {
    s32 count = 0;
    for (Unk_16580b0_node* node = m_List.m_Root.next; node != &m_List.m_Root; node = node->next) {
        if (ToEntry(node)->data.field_18 == value) {
            count++;
        }
    }
    return count;
}

// 0x7101735bd0
u32 Unk_1734ed0::Unk_1735bd0(u32 value) const {
    u32 values[32];
    u8 count = 0;
    for (Unk_16580b0_node* node = m_List.m_Root.next; node != &m_List.m_Root; node = node->next) {
        u32 entryValue = ToEntry(node)->data.field_18;
        bool found = false;
        for (u8 i = 0; i < count; i++) {
            if (values[i] == entryValue) {
                found = true;
                break;
            }
        }
        if (!found) {
            values[count++] = entryValue;
        }
    }
    u32 rank = 1;
    for (u8 i = 0; i < count; i++) {
        if (values[i] < value) {
            rank++;
        }
    }
    return rank;
}

}  // namespace common
}  // namespace pia
}  // namespace nn
