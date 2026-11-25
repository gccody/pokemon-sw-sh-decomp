// Scope: common
#include "pia/common/Unk_1734ed0.h"

namespace nn {
namespace pia {
namespace common {
struct Unk_1735990_arg0;
}  // namespace common
}  // namespace pia
}  // namespace nn

// What 0x7101735840 looks an id up in: the object behind the global
// Unk_27fc2d8 and a virtual member (slot 7) of what Unk_174de50_get returns.
struct Unk_1735840_found {
    u8 _0[0x48];
    s32 field_48;
};
PKMN_OFFSET_ASSERT(Unk_1735840_found, field_48, 0x48);

class Unk_1735840_lookup {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual Unk_1735840_found* vf7(u64 id);
};

struct Unk_174de50;
struct Unk_16a8390;
struct Unk_16c16d0_arg0;

extern Unk_174de50* Unk_27fc2d8;
extern Unk_16a8390* Unk_27fb2d8;

// Declared in lib/nx_middleware/leaf with the u64 field they return.
Unk_1735840_lookup* Unk_174de50_get(const Unk_174de50* self);
Unk_16c16d0_arg0* Unk_16a8390_get(const Unk_16a8390* self);

nn::pia::common::Unk_1735990_arg0* Unk_16c16d0(Unk_16c16d0_arg0* self, u64 id);

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
// NON_MATCHING: the original keeps the list head it loaded before each inlined flag-setting loop
// (as if the byte stores couldn't change it, which needs -fstrict-aliasing and a bool field_9)
// instead of reloading it; and Unk_1735350, written out here, is inlined from the other file.
void Unk_1734ed0::Unk_1735690() {
    Unk_172c3e0_arg0* owner = Unk_27fc0a8;
    u64 id = owner->field_f0;
    if (!Unk_1735640(id)) {
        Unk_172c3e0(owner, id);
        Unk_172c450(owner, id);
        Unk_1735600(id, true);
    }
    id = owner->field_f8;
    if (!Unk_1735640(id)) {
        // Unk_1735350(id), which is in the other file.
        for (Unk_16580b0_node* node = m_List.m_Root.next; node != &m_List.m_Root;
             node = node->next) {
            Entry* entry = ToEntry(node);
            if (entry->data.field_10 == id) {
                if (entry->data.field_8 != 0) {
                    Unk_172c3e0(owner, id);
                    Unk_172c450(owner, id);
                    Unk_1735600(id, true);
                }
                break;
            }
        }
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

// 0x7101735840
// NON_MATCHING: the original loads field_8 before testing field_48 == 5 and combines the two
// tests with a ccmp; this one branches between them.
void Unk_1734ed0::Unk_1735840() {
    if (m_List.m_Root.next == &m_List.m_Root) {
        return;
    }
    Unk_172c3e0_arg0* owner = Unk_27fc0a8;
    u64 ownId = owner->field_f0;
    u64 ids[32];
    u16 count = 0;
    bool hasOwn = false;
    for (Unk_16580b0_node* node = m_List.m_Root.next; node != &m_List.m_Root; node = node->next) {
        Entry* entry = ToEntry(node);
        Unk_1735840_found* found = Unk_174de50_get(Unk_27fc2d8)->vf7(entry->data.field_10);
        if (found != nullptr && found->field_48 == 5 && entry->data.field_8 != 0) {
            continue;
        }
        if (entry->data.field_10 == ownId) {
            hasOwn = true;
        } else {
            ids[count] = entry->data.field_10;
            count++;
        }
        Unk_1735990_arg0* peer = Unk_16c16d0(Unk_16a8390_get(Unk_27fb2d8), entry->data.field_10);
        if (peer != nullptr && peer->field_8 == 0xfd) {
            peer->field_8 = entry->data.field_1d;
        }
    }
    if (hasOwn) {
        ids[count] = ownId;
        count++;
    }
    for (u16 i = 0; i < count; i++) {
        Unk_172abd0(owner, ids[i], 0xfd, nullptr, false);
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
            if (state >= 6 && state <= 8) {
                return entry->data.field_0 == 2;
            }
            return true;
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
