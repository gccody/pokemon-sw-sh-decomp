// Scope: common
// The items' base class (vtable 0x7102383c78). Written from the executable.
// Placeholder names.
#include "Unk_2383cc0.h"

// 0x71003c2900: the constructor
void Unk_3c2900(Unk_2383c58_Item* self, Unk_23837d0_Object* object, Unk_2383c78_Key* key,
                Unk_2383c78_User* user, u32 id) {
    self->next = nullptr;
    self->field_10 = object;
    self->field_18.field_0 = nullptr;
    Unk_2383cc0_SetVptr(self, Unk_2383c78);
    self->field_18.Set(*user);
    self->field_30 = *key;
    self->field_3c = id;
    self->field_40 = nullptr;
    self->field_48 = false;
    self->field_4c = 1;
    self->field_50 = false;
    if (self->field_10 != nullptr)
        self->field_10->field_50++;
}

// 0x71003c2990: the destructor
void Unk_3c2990(Unk_2383c58_Item* self) {
    Unk_2383cc0_SetVptr(self, Unk_2383c78);
    if (self->field_10 != nullptr)
        self->field_10->Release();
    if (self->field_40 != nullptr)
        self->field_40->vf3();
    if (self->field_18.field_0 != nullptr)
        Unk_331150(self->field_18.field_0);
}

// 0x71003c2a50
u32 Unk_3c2a50(Unk_2383c58_Item* self) {
    return self->vf5() ? 1 : 2;
}

// 0x71003c2a80: an event of this item for its owner: into the list, which is
// in the order of `arg3`
// NON_MATCHING: the two masks of the status byte are computed in the other
// order (`and #0x80` first in the original), which swaps two registers.
void Unk_3c2a80(Unk_2383c58_Item* self, Unk_3c2490_Pair* events, Unk_2383ce0_Entry* entry,
                u32 arg3, u32 arg4, bool arg5, bool arg6) {
    u8 status = *reinterpret_cast<u8*>(entry);
    if ((status & 0xf0) == 0xf0 || (status & 0x80) == 0)
        return;
    if (self->field_50)
        return;
    Unk_3c2f40_Event* event =
        static_cast<Unk_3c2f40_Event*>(Unk_3045e0(Unk_237e820, sizeof(Unk_3c2f40_Event)));
    if (event == nullptr)
        return;
    event->field_0 = self;
    event->field_8 = entry->field_0;
    event->field_c = arg3;
    event->field_10_0 = arg4;
    event->field_10_30 = arg5;
    event->field_10_31 = arg6;
    event->next = nullptr;
    self->field_4c++;
    auto it = events->BeginEx();
    while (it != events->End()) {
        Unk_3c2f40_Event* other = *it;
        if (other->field_c > event->field_c)
            break;
        if (other->field_c == event->field_c) {
            if (other->field_10_30 && !event->field_10_30)
                break;
            if (!other->field_10_31 && event->field_10_31)
                break;
        }
        ++it;
    }
    events->AddItem(event, it.item, it.prev);
}

// 0x71003c2bc0
void Unk_3c2bc0(Unk_2383c58_Item* self) {
    void* owner = self->vf6();
    Unk_23837d0_Node* node = self->field_40;
    if (owner != nullptr && node != nullptr)
        Unk_3c3610(owner, self);
}

// 0x71003c2c30 was named with this parameter: one reference less
u32 Unk_3c2c30(void* arg) {
    Unk_2383c58_Item* self = static_cast<Unk_2383c58_Item*>(arg);
    u32 count = --self->field_4c;
    if (count == 0) {
        int pool = Unk_237e820;
        self->~Unk_2383c58_Item();
        Unk_3047c0(pool, self);
    }
    return count;
}
