// Scope: common
// Script commands (Unk_13f1360.h): the store flag of an object's entry, and the
// state, counts and names of the objects 0x71013f6c00 finds.
#include <types.h>

#include "field/content/Unk_13f1360.h"
#include "gflib3/Unk_239a418.h"
#include "unsorted/Unk_136c4d0.h"

// The objects 0x71013a67a0 finds: field_56c is the index of their entry in the
// store's table, -1 for none.
class Unk_13a67a0_Object : public Unk_13f1360_Object {
public:
    u8 _1a8[0x56c - 0x1a8];
    s32 field_56c;
};
static_assert(__builtin_offsetof(Unk_13a67a0_Object, field_56c) == 0x56c, "field_56c");

// 0x71013a67a0: as 0x71013f6c00, for Unk_13a67a0_Object.
Unk_13a67a0_Object* Unk_13a67a0(Unk_13f1360_Manager* manager, const Unk_13f1360_Find& find);

// The owner of the block stores (as src/unsorted/Unk_1298270.h).
struct Unk_24ba4e0_Type {
    u8 _0[0x248];
    Unk_239a418_Ref<Unk_2432608> field_248;
};
PKMN_OFFSET_ASSERT(Unk_24ba4e0_Type, field_248, 0x248);

extern Unk_24ba4e0_Type* Unk_24ba4e0;

bool Unk_e59180_call(void* self);

// What 0x71007c19a0 looks a name's hash up in.
struct Unk_7c19a0_Table;
extern Unk_7c19a0_Table* Unk_24ba5e8;

// 0x71007c19a0: the value of a name's hash (0x11 when it has none).
u16 Unk_7c19a0(Unk_7c19a0_Table* self, u64 hash);

// The hash of "", a name that isn't set.
static constexpr u64 kNoName = 0xcbf29ce484222645;

static Unk_13a67a0_Object* FindEntryObject(const s64& id) {
    return Unk_13a67a0(Unk_27d6158, Unk_13f1360_Find{&id});
}

// 0x71013f1360
s64 Unk_13f1360_call(Unk_66efd0* self, const Unk_13f1360_Args* args) {
    s64 id = args->field_8;
    Unk_13a67a0_Object* object = FindEntryObject(id);
    if (object == nullptr)
        return 0;
    Unk_239a418_Ref<Unk_13a67a0_Object> ref(object);
    int index = object->field_56c;
    if (index != -1) {
        Unk_239a418_Ref2<Unk_2432608> store = Unk_24ba4e0->field_248;
        store.m_ptr->Unk_136c830(index, true);
    }
    return 1;
}

// 0x71013f1450
s64 Unk_13f1450_call(Unk_66efd0* self, const Unk_13f1360_Args* args) {
    s64 id = args->field_8;
    Unk_13a67a0_Object* object = FindEntryObject(id);
    if (object == nullptr)
        return 0;
    Unk_239a418_Ref<Unk_13a67a0_Object> ref(object);
    int index = object->field_56c;
    if (index == -1)
        return false;
    Unk_239a418_Ref2<Unk_2432608> store = Unk_24ba4e0->field_248;
    return store.m_ptr->Unk_136c860(index);
}

// 0x71013f1550
s64 Unk_13f1550_call(Unk_66efd0* self, const Unk_13f1360_Args* args) {
    Unk_239a418_Ref2<Unk_2432608> store = Unk_24ba4e0->field_248;
    u16 value = store.m_ptr->field_60.field_a60;
    return Unk_e59180_call(&value);
}

// 0x71013f15e0
s64 Unk_13f15e0_call(Unk_66efd0* self, const Unk_13f1360_Args* args) {
    s64 id = args->field_8;
    s32 value = args->field_10;
    Unk_13f6c00_Object* object = Unk_13f1360_FindObject(id);
    if (object == nullptr)
        return 0;
    Unk_239a418_Ref<Unk_13f6c00_Object> ref(object);
    Unk_d00dd0_arg1 arg1 = {static_cast<u32>(value)};
    Unk_d00dd0_set(reinterpret_cast<Unk_d00dd0*>(object), &arg1);
    return 1;
}

// 0x71013f1670
s64 Unk_13f1670_call(Unk_66efd0* self, const Unk_13f1360_Args* args) {
    s64 id = args->field_8;
    Unk_13f6c00_Object* object = Unk_13f1360_FindObject(id);
    if (object == nullptr)
        return 0;
    Unk_239a418_Ref<Unk_13f6c00_Object> ref(object);
    return object->field_6a8;
}

// NON_MATCHING: the second argument's slot is at sp+0x8, the original's at
// sp+0xc (the stack layout only).
// 0x71013f16f0
s64 Unk_13f16f0_call(Unk_66efd0* self, const Unk_13f1360_Args* args) {
    s64 id = args->field_8;
    s32 value = args->field_10;
    s32 value2 = args->field_18;
    Unk_13f6c00_Object* object = Unk_13f1360_FindObject(id);
    if (object == nullptr)
        return 0;
    Unk_239a418_Ref<Unk_13f6c00_Object> ref(object);
    Unk_d00de0_arg1 arg1 = {static_cast<u32>(value)};
    Unk_d00de0_arg2 arg2 = {static_cast<u32>(value2)};
    Unk_d00de0_set(reinterpret_cast<Unk_d00de0*>(object), &arg1, &arg2);
    return 1;
}

// 0x71013f1790
s64 Unk_13f1790_call(Unk_66efd0* self, const Unk_13f1360_Args* args) {
    s64 id = args->field_8;
    s32 value = args->field_10;
    Unk_13f6c00_Object* object = Unk_13f1360_FindObject(id);
    if (object == nullptr)
        return 0;
    Unk_239a418_Ref<Unk_13f6c00_Object> ref(object);
    return object->Unk_d00e00(value);
}

// 0x71013f1830
s64 Unk_13f1830_call(Unk_66efd0* self, const Unk_13f1360_Args* args) {
    s64 id = args->field_8;
    s32 value = args->field_10;
    Unk_13f6c00_Object* object = Unk_13f1360_FindObject(id);
    if (object == nullptr)
        return 0;
    Unk_239a418_Ref<Unk_13f6c00_Object> ref(object);
    object->field_6bc = value;
    return 1;
}

// 0x71013f18b0
s64 Unk_13f18b0_call(Unk_66efd0* self, const Unk_13f1360_Args* args) {
    s64 id = args->field_8;
    s32 value = args->field_10;
    Unk_13f6c00_Object* object = Unk_13f1360_FindObject(id);
    if (object == nullptr)
        return 0;
    Unk_239a418_Ref<Unk_13f6c00_Object> ref(object);
    u64 hash = object->Unk_d01750(value);
    if (hash == kNoName)
        return 0;
    return Unk_7c19a0(Unk_24ba5e8, hash);
}

// 0x71013f1980
s64 Unk_13f1980_call(Unk_66efd0* self, const Unk_13f1360_Args* args) {
    s64 id = args->field_8;
    Unk_13f6c00_Object* object = Unk_13f1360_FindObject(id);
    if (object == nullptr)
        return 0;
    Unk_239a418_Ref<Unk_13f6c00_Object> ref(object);
    object->Unk_d011d0();
    return 1;
}

// 0x71013f1a00
s64 Unk_13f1a00_call(Unk_66efd0* self, const Unk_13f1360_Args* args) {
    s64 id = args->field_8;
    s32 value = args->field_10;
    Unk_13f6c00_Object* object = Unk_13f1360_FindObject(id);
    if (object == nullptr)
        return 0;
    Unk_239a418_Ref<Unk_13f6c00_Object> ref(object);
    u64 hash = object->Unk_d01720(value).field_0;
    if (hash == kNoName)
        return 0;
    return Unk_7c19a0(Unk_24ba5e8, hash);
}

// 0x71013f1ad0
s64 Unk_13f1ad0_call(Unk_66efd0* self, const Unk_13f1360_Args* args) {
    s64 id = args->field_8;
    s32 value = args->field_10;
    Unk_13f6c00_Object* object = Unk_13f1360_FindObject(id);
    if (object == nullptr)
        return 0;
    Unk_239a418_Ref<Unk_13f6c00_Object> ref(object);
    return object->Unk_d01720(value).field_8;
}
