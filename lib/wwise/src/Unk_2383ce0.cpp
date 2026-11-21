// Scope: common
// The items of the owner at 0x71024df140 (vtable 0x7102383ce0). Written from
// the executable. Placeholder names.
#include "Unk_2383cc0.h"

extern void* Unk_24bbbb8;
Unk_23837d0_Node* Unk_3351b0(void* self, u32 id, u32 type);

// 0x71003c4070: the constructor
void Unk_3c4070(Unk_2383c58_Item* self, Unk_2383cc0* owner, Unk_23837d0_Object* object,
                Unk_2383c78_Key* key, Unk_2383c78_User* user, u32 id) {
    Unk_3c2900(self, object, key, user, id);
    self->field_58 = owner;
    self->field_60.last = nullptr;
    self->field_60.first = nullptr;
    Unk_2383cc0_SetVptr(self, Unk_2383ce0);
    self->field_70_0 = 0;
}

static inline void Unk_2383ce0_Dtor(Unk_2383c58_Item* self) {
    Unk_2383cc0_SetVptr(self, Unk_2383ce0);
    while (!self->field_60.IsEmpty()) {
        Unk_2383ce0_Entry* entry = self->field_60.First();
        self->field_60.RemoveFirst();
        Unk_3047c0(Unk_237e820, entry);
    }
    if (self->field_58 != nullptr)
        Unk_3c2ee0(self->field_58, self);
    Unk_3c2990(self);
}

// 0x71003c40d0: the destructor
void Unk_3c40d0(Unk_2383c58_Item* self) {
    Unk_2383ce0_Dtor(self);
}

// 0x71003c4160: the deleting destructor
void Unk_3c4160(Unk_2383c58_Item* self) {
    Unk_2383ce0_Dtor(self);
    operator delete(self);
}

// 0x71003c4200
u32 Unk_3c4200(Unk_2383c58_Item* self) {
    u32 result = Unk_3c2a50(self);
    if (result == 1)
        Unk_3c2ec0(self->field_58, self);
    return result;
}

// 0x71003c4250: finds its node
bool Unk_3c4250(Unk_2383c58_Item* self) {
    self->field_48 = false;
    self->field_40 = Unk_3351b0(Unk_24bbbb8, self->field_3c, 0);
    return self->field_40 != nullptr;
}

// 0x71003c42a0: one more entry, kept in the order of `key`
void Unk_3c42a0(Unk_2383c58_Item* self, u32* value, u32 key) {
    if (self->field_70_0)
        return;
    Unk_2383ce0_Entry* entry =
        static_cast<Unk_2383ce0_Entry*>(Unk_3045e0(Unk_237e820, sizeof(Unk_2383ce0_Entry)));
    if (entry == nullptr)
        return;
    u32 first = *value;
    entry->next = nullptr;
    entry->field_0 = first;
    entry->field_4 = key;
    auto it = self->field_60.BeginEx();
    while (it != self->field_60.End()) {
        if ((*it)->field_4 > key)
            break;
        ++it;
    }
    self->field_60.AddItem(entry, it.item, it.prev);
}

// 0x71003c4480: ends it
void Unk_3c4480(Unk_2383c58_Item* self) {
    if (!self->field_70_0) {
        self->field_70_0 = 1;
        if (self->field_58 != nullptr) {
            Unk_3c3610(self->field_58, self);
            Unk_3c2ee0(self->field_58, self);
            self->field_58 = nullptr;
        }
        Unk_3c2c30(self);
    }
}

struct Unk_3c2c10;
void Unk_3c2c10_update(Unk_3c2c10* self);  // one reference more (lib/wwise/leaf)
void Unk_3c2a80(Unk_2383c58_Item* self, Unk_3c2490_Pair* events, Unk_2383ce0_Entry* entry,
                u32 arg3, u32 arg4, bool arg5, bool arg6);

// 0x71003c4370: `count` less to wait for every entry; the ones that are due
// are passed on
void Unk_3c4370(Unk_2383c58_Item* self, Unk_3c2490_Pair* events, u32 count) {
    if (self->field_70_0)
        return;
    Unk_3c2c10_update(reinterpret_cast<Unk_3c2c10*>(self));
    if (count != 0) {
        auto it = self->field_60.BeginEx();
        while (it != self->field_60.End()) {
            Unk_2383ce0_Entry* entry = *it;
            if (entry->field_4 < count) {
                it = self->field_60.Erase(it);
                Unk_3c2a80(self, events, entry, entry->field_4, 0, false, false);
                Unk_3047c0(Unk_237e820, entry);
            } else {
                entry->field_4 -= count;
                ++it;
            }
        }
    }
    Unk_3c2c30(self);
}
