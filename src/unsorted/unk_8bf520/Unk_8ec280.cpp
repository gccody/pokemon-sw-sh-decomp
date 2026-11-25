// Scope: common
// A record holding a counted reference and 0xa8 bytes of data, in the TU of
// 0x71008ec280-0x71008ec490: its setter, which clears it and copies a value
// in, and a getter of 7 bytes of the owner, valid while the second flag is
// set. The referenced object's interface at 0x48 takes and drops a reference
// through its slots 2 and 3. Placeholder types: rename and move once the
// owning classes are known.
#include <types.h>

class Unk_8ec280_Ref {
public:
    virtual void vf00();
    virtual void vf08();
    virtual void vf10();
    virtual void vf18();
};

class Unk_8ec280_ObjBase {
public:
    virtual void vf00();

private:
    u8 _8[0x40];
};

PKMN_SIZE_ASSERT(Unk_8ec280_ObjBase, 0x48);

class Unk_8ec280_Obj : public Unk_8ec280_ObjBase, public Unk_8ec280_Ref {};

struct Unk_8ec280_Ptr {
    Unk_8ec280_Obj* ptr;

    void Reset() {
        Unk_8ec280_Obj* old = ptr;
        ptr = nullptr;
        if (old != nullptr) {
            static_cast<Unk_8ec280_Ref*>(old)->vf18();
        }
    }

    Unk_8ec280_Ptr& operator=(const Unk_8ec280_Ptr& other) {
        Unk_8ec280_Obj* obj = other.ptr;
        if (obj != nullptr) {
            static_cast<Unk_8ec280_Ref*>(obj)->vf10();
        }
        Unk_8ec280_Obj* old = ptr;
        ptr = obj;
        if (old != nullptr) {
            static_cast<Unk_8ec280_Ref*>(old)->vf18();
        }
        return *this;
    }
};
PKMN_SIZE_ASSERT(Unk_8ec280_Ptr, 0x8);

struct Unk_8ec280_Data {
    u8 _0[0xa8];
};
PKMN_SIZE_ASSERT(Unk_8ec280_Data, 0xa8);

struct Unk_8ec280_Value {
    Unk_8ec280_Ptr field_0;
    Unk_8ec280_Data field_8;
};
PKMN_SIZE_ASSERT(Unk_8ec280_Value, 0xb0);

struct Unk_8ec280_Flags {
    bool field_0;
    bool field_1;
};
PKMN_SIZE_ASSERT(Unk_8ec280_Flags, 0x2);

struct Unk_8ec340_10 {
    u8 _0[0x358];
    u8 field_358[7];
};
PKMN_OFFSET_ASSERT(Unk_8ec340_10, field_358, 0x358);

struct Unk_8ec280 {
    u8 _0[0x10];
    Unk_8ec340_10* field_10;
    u8 _18[0x8];
    Unk_8ec280_Value field_20;
    Unk_8ec280_Flags field_d0;
};
PKMN_OFFSET_ASSERT(Unk_8ec280, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_8ec280, field_20, 0x20);
PKMN_OFFSET_ASSERT(Unk_8ec280, field_d0, 0xd0);

// 0x71008ec280
// NON_MATCHING: the clear and the copy share one address of field_20.field_8,
// kept in a callee-saved register; the original addresses the clear from
// `self` (its clear likely starts at a member of the unknown data struct).
void Unk_8ec280_set(Unk_8ec280* self, const Unk_8ec280_Value* value) {
    self->field_20.field_0.Reset();
    self->field_20.field_8 = Unk_8ec280_Data();
    self->field_d0 = Unk_8ec280_Flags();
    self->field_20 = *value;
    self->field_d0.field_0 = true;
}

// 0x71008ec340
bool Unk_8ec340_get(const Unk_8ec280* self, u8* out) {
    if (!self->field_d0.field_1) {
        return false;
    }
    if (out != nullptr) {
        const Unk_8ec340_10* owner = self->field_10;
        for (s32 i = 0; i < 7; i++) {
            out[i] = owner->field_358[i];
        }
    }
    return true;
}
