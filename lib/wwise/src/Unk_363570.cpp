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
    virtual void vf10();
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
    u8 _38[0x80];
    Unk_GrowArray<u64> field_b8;  // children
    u8 _c8[0x10];
    Unk_GrowArray<Unk_366110_T*, Unk_PoolDefault, 4> field_d8;
    u64 field_e8;
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
