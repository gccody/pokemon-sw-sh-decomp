// Scope: common
// An indexed object (0xf8 bytes, vtables at 0x7102380de8) with children,
// which a bank gives by their IDs, and a list of objects it creates from the
// bank and owns. Placeholder names.
#include "Unk_BankRead.h"
#include "Unk_366110.h"

void operator delete(void* ptr) noexcept;

struct Unk_363570_T;

Unk_366110_T* Unk_366280(u32 id);
void Unk_367630(Unk_366110_T* self, void* owner);
u32 Unk_366d90(Unk_366110_T* self, u8** data, u32* size);

// What the object plays, in a list.
struct Unk_3643f0_Item {
    Unk_3643f0_Item* field_0;  // next
    void* field_8;
    u8 _10[0x3c];
    u32 field_4c;
    u32 field_50;
};
PKMN_OFFSET_ASSERT(Unk_3643f0_Item, field_4c, 0x4c);

// What an action does, and to what.
struct Unk_3643f0_Action {
    u32 field_0;  // 0 and 3 stop, 1 pause, 2 resume
    void* field_8;
    u32 field_10;
    u8 _14[0xc];
    bool field_20;
};

struct Unk_363570_T {
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
    virtual u32 vf10(Unk_366110_Node* child);
    virtual u32 vf11(u32 id);  // add a child
    virtual void vf12();
    virtual void vf13();
    virtual void vf14();
    virtual void vf15();
    virtual void vf16();
    virtual u32 vf17();  // the kind of object

    u64 field_8;
    u32 field_10;  // key
    u32 field_14;
    void** field_18;
    u8 _20[0x10];
    void** field_30;
    u8 _38[0x38];
    Unk_366110_NodeInfo* field_70;
    u8 _78[0x40];
    Unk_GrowArray<Unk_366110_Node*> field_b8;  // children
    u8 _c8[0x10];
    Unk_GrowArray<Unk_366110_T*, Unk_PoolDefault, 4> field_d8;
    Unk_3643f0_Item* field_e8;  // first
    bool field_f0;
};
PKMN_OFFSET_ASSERT(Unk_363570_T, field_b8, 0xb8);
PKMN_OFFSET_ASSERT(Unk_363570_T, field_d8, 0xd8);
PKMN_SIZE_ASSERT(Unk_363570_T, 0xf8);

extern void* Unk_2380de8[];
extern unsigned long Unk_24bbbe0;

// The base class: its constructor, initialisation and destructor.
void Unk_379e60(Unk_363570_T* self, u32 id);
u32 Unk_379f40(Unk_363570_T* self);
void Unk_379fa0_call(struct Unk_379fa0* self);
void Unk_379eb0(Unk_363570_T* self);
u32 Unk_385430(void* self, u8** data, u32* size, bool a3);
void Unk_349be0_update(unsigned long self, u32 id, u32 expected, u32 kind);

static inline void Unk_363570_Dtor(Unk_363570_T* self) {
    Unk_SetVtable(self, Unk_2380de8);
    self->field_18 = Unk_2380de8 + 0x51;
    self->field_30 = Unk_2380de8 + 0x64;
    for (auto it = self->field_d8.Begin(), end = self->field_d8.End(); it != end; ++it) {
        Unk_367630(*it, nullptr);
        (*it)->vf3();
    }
    self->field_d8.Term();
    self->field_e8 = 0;
    Unk_379fa0_call(reinterpret_cast<Unk_379fa0*>(self));
    Unk_379eb0(self);
}

// 0x7100363570
void Unk_363570(Unk_363570_T* self) {
    Unk_363570_Dtor(self);
}

// 0x71003636d0
void Unk_3636d0(void* self) {
    Unk_363570_Dtor(static_cast<Unk_363570_T*>(self));
    operator delete(self);
}

struct Unk_3476d0_Obj;

// 0x7100363980
u32 Unk_363980(Unk_3476d0_Obj* self_, u32* data_, u32 size_) {
    Unk_363570_T* self = reinterpret_cast<Unk_363570_T*>(self_);
    u8* data = reinterpret_cast<u8*>(data_);
    u32 size = size_;
    if (self->vf17() != 5) {
        Unk_349be0_update(Unk_24bbbe0, self->field_10, 5, self->vf17());
        return 0x5a;
    }
    Unk_ReadBank<u32>(data);
    u32 result = Unk_385430(self, &data, &size, false);
    if (result != 1)
        return result;

    u32 count = Unk_ReadBank<u32>(data);
    if (count != 0) {
        result = self->field_b8.Reserve(count);
        if (result != 1)
            return result;
        for (u32 i = 0; i < count; i++) {
            u32 id = Unk_ReadBank<u32>(data);
            result = self->vf11(id);
            if (result != 0xf && result != 1)
                break;
        }
        if (result != 1)
            return result;
    }

    count = Unk_ReadBank<u32>(data);
    for (u32 i = 0; i < count; i++) {
        Unk_366110_T* item = Unk_366280(*reinterpret_cast<u32*>(data));
        if (item == nullptr) {
            result = 2;
            break;
        }
        Unk_367630(item, self);
        result = Unk_366d90(item, &data, &size);
        if (result != 1) {
            item->vf3();
            break;
        }
        if (self->field_d8.AddLast(item) == nullptr) {
            item->vf3();
            result = 2;
            break;
        }
    }
    self->field_f0 = Unk_ReadBank<u8>(data) != 0;
    return result;
}

// 0x7100363ef0
Unk_363570_T* Unk_363ef0(u32 id) {
    Unk_363570_T* self = static_cast<Unk_363570_T*>(Unk_3045e0(Unk_237e820, sizeof(Unk_363570_T)));
    if (self != nullptr) {
        Unk_379e60(self, id);
        Unk_SetVtable(self, Unk_2380de8);
        self->field_18 = Unk_2380de8 + 0x51;
        self->field_30 = Unk_2380de8 + 0x64;
        self->field_d8.field_0 = nullptr;
        self->field_d8.field_8 = 0;
        self->field_d8.field_c = 0;
        self->field_e8 = 0;
        self->field_f0 = false;
        if (Unk_379f40(self) != 1) {
            self->vf3();
            self = nullptr;
        }
    }
    return self;
}

void Unk_367750(Unk_366110_T* self, u32 id);

// An ID and whether it is the one of a bus.
struct Unk_363cb0_Id {
    u32 field_0;
    bool field_4;
};

// 0x7100363cb0
u32 Unk_363cb0(Unk_363570_T* self, Unk_363cb0_Id id_) {
    u32 id = id_.field_0;
    if (id == 0)
        return 0xe;
    Unk_366110_Node* child = Unk_3351b0(Unk_24bbbb8, id, 0);
    if (child == nullptr)
        return 0xf;
    u32 result = self->vf10(child);
    if (result != 1)
        return result;
    for (auto it = self->field_d8.Begin(), end = self->field_d8.End(); it != end; ++it)
        Unk_367750(*it, id);
    return 1;
}

void Unk_3641b0(Unk_363570_T* self, void* object, u32 id);
void Unk_34b7c0(Unk_363570_T* self, Unk_3643f0_Action* action);

static inline bool Unk_3643f0_Matches(Unk_3643f0_Item* item, void* object, u32 id) {
    return (object == nullptr || item->field_8 == object) && (id == 0 || item->field_4c == id);
}

static inline void Unk_3643f0_Pause(Unk_363570_T* self, void* object, u32 id) {
    for (Unk_3643f0_Item* item = self->field_e8; item != nullptr; item = item->field_0) {
        if (Unk_3643f0_Matches(item, object, id))
            item->field_50 = 1;
    }
}

static inline void Unk_3643f0_Resume(Unk_363570_T* self, void* object, u32 id) {
    for (Unk_3643f0_Item* item = self->field_e8; item != nullptr; item = item->field_0) {
        if (Unk_3643f0_Matches(item, object, id))
            item->field_50 = 0;
    }
}

// 0x71003643f0
void Unk_3643f0(Unk_363570_T* self, Unk_3643f0_Action* action) {
    switch (action->field_0) {
    case 0:
        Unk_3641b0(self, action->field_8, action->field_10);
        break;
    case 1:
        Unk_3643f0_Pause(self, action->field_8, action->field_10);
        break;
    case 2:
        Unk_3643f0_Resume(self, action->field_8, action->field_10);
        break;
    }
    Unk_34b7c0(self, action);
}

// 0x7100363fa0
void Unk_363fa0(Unk_363570_T* self, Unk_3643f0_Action* action) {
    switch (action->field_0) {
    case 0:
    case 3:
        Unk_3641b0(self, action->field_8, action->field_10);
        break;
    case 1:
        Unk_3643f0_Pause(self, action->field_8, action->field_10);
        break;
    case 2:
        Unk_3643f0_Resume(self, action->field_8, action->field_10);
        break;
    }
    if (self->field_70 != nullptr && (self->field_70->field_90 > 0 || self->field_70->field_94 > 0)) {
        for (u32 i = self->field_b8.Length(); i > 0; i--) {
            Unk_366110_Node* child = self->field_b8.field_0[i - 1];
            if (!action->field_20 || child->field_80 == nullptr)
                child->vf19(action);
        }
    }
}
