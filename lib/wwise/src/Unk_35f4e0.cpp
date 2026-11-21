// Scope: common
// An indexed object (index 0xa8) with a list of other indexed objects (index
// 0xe0), which a bank gives by their IDs. Placeholder names.
#include "Unk_Indexed.h"

void operator delete(void* ptr) noexcept;

struct Unk_35f9a0_Obj {
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();  // release
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
    virtual void vf16(void* a1, void* a2, void* a3, u32 a4, void* a5, u32 a6, u32 a7);
};

// An item of the list.
struct Unk_35f4e0_Item {
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();  // release

    Unk_Indexed* field_8;
    u32 field_10;
    u32 field_14;
    Unk_35f4e0_Item* field_18;  // next
    u8 _20[0x14];
    u16 field_34;  // kind
};
PKMN_OFFSET_ASSERT(Unk_35f4e0_Item, field_18, 0x18);
PKMN_OFFSET_ASSERT(Unk_35f4e0_Item, field_34, 0x34);

// A list of items by their first one.
struct Unk_35f4e0_List {
    Unk_35f4e0_Item* field_0;

    Unk_35f4e0_Item* First() { return field_0; }
    bool IsEmpty() const { return field_0 == nullptr; }

    void RemoveFirst() {
        if (field_0 != nullptr) {
            if (field_0->field_18 == nullptr)
                field_0 = nullptr;
            else
                field_0 = field_0->field_18;
        }
    }

    void AddItem(Unk_35f4e0_Item* item, Unk_35f4e0_Item* next, Unk_35f4e0_Item* prev) {
        item->field_18 = next;
        if (prev == nullptr)
            field_0 = item;
        else
            prev->field_18 = item;
    }

    void Term() { field_0 = nullptr; }
};

struct Unk_35f4e0_T : Unk_Indexed {
    Unk_35f4e0_List field_18;
    u32 field_20;
};
PKMN_SIZE_ASSERT(Unk_35f4e0_T, 0x28);

extern void* Unk_2380850[];

void Unk_3b6b20(void* self);
Unk_35f9a0_Obj* Unk_33e810(Unk_35f4e0_Item* self);



// 0x710035f5d0
void Unk_35f5d0(Unk_35f4e0_T* self) {
    Unk_IndexedAdd<0xa8>(self);
}

// 0x710035f690
Unk_35f4e0_T* Unk_35f690(u32 id) {
    Unk_35f4e0_T* self = static_cast<Unk_35f4e0_T*>(Unk_3045e0(Unk_237e820, sizeof(Unk_35f4e0_T)));
    if (self != nullptr) {
        Unk_363510(self, id);
        Unk_SetVtable(self, Unk_2380850);
        self->field_18.field_0 = nullptr;
        self->field_20 = 0;
    }
    return self;
}

// 0x710035f870
u32 Unk_35f870(Unk_35f4e0_T* self, u8* data, u32 size) {
    u8 byte = data[4];
    data += 5;
    u32 count = byte & 0x7f;
    while (byte & 0x80) {
        byte = *data++;
        count = (count << 7) | (byte & 0x7f);
    }
    Unk_35f4e0_Item* last = nullptr;
    for (u32 i = 0; i < count; i++) {
        u32 id = *reinterpret_cast<u32*>(data);
        data += 4;
        if (id == 0)
            return 0xe;
        Unk_35f4e0_Item* item =
            reinterpret_cast<Unk_35f4e0_Item*>(Unk_IndexedGetAndAddRef<0xe0>(id));
        if (item == nullptr)
            return 2;
        self->field_18.AddItem(item, nullptr, last);
        last = item;
    }
    return 1;
}

// 0x710035f9a0
u32 Unk_35f9a0(Unk_35f4e0_T* self, void* a1, void* a2, void* a3, void* a4, u32 a5, u32 a6) {
    for (Unk_35f4e0_Item* item = self->field_18.First(); item != nullptr; item = item->field_18) {
        if (item->field_34 == 0x403) {
            Unk_35f9a0_Obj* obj = Unk_33e810(item);
            if (obj != nullptr) {
                obj->vf16(a1, a2, a3, 1, a4, a5, a6);
                obj->vf3();
            }
        }
    }
    return 1;
}
