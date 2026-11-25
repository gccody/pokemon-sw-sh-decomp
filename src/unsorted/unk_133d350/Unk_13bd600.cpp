// Scope: common
// Script commands (Unk_13bd600.h): the command table, and commands on the field
// objects the manager holds.
#include <types.h>

#include "field/content/Unk_13f1360.h"
#include "unsorted/unk_133d350/Unk_13bd600.h"

// The command table: its first entry is "AddFieldObject"'s.
extern const u8 Unk_2434ce0[] __attribute__((visibility("hidden")));

// 0x71013bd600
const u8* Unk_13bd600_get() {
    return Unk_2434ce0;
}

bool Unk_d1ee90(const s64& id);

// 0x71013bd610
s64 Unk_13bd610_call(Unk_13bd600_Script* self, const Unk_13bd600_Arg* args) {
    s64 id = args[1].i;
    return Unk_d1ee90(id);
}

// The first object with the id that isn't gone.
static Unk_13f1360_Object* FindObject(s64 id) {
    for (Unk_13f1360_Object* object : Unk_27d6158->field_b0) {
        if (object != nullptr && object->field_1a0 == id && !object->vf17())
            return object;
    }
    return nullptr;
}

// NON_MATCHING: the original loads the object's id before testing it for null
// (a ccmp); the natural test branches on null first.
// 0x71013bd690: whether there's an object with the id.
s64 Unk_13bd690_call(Unk_13bd600_Script* self, const Unk_13bd600_Arg* args) {
    s64 id = args[1].i;
    Unk_13f1360_Object* object = FindObject(id);
    if (object == nullptr)
        return 0;
    Unk_239a418_Ref<Unk_13f1360_Object> ref(object);
    return 1;
}

// 0x71013bd780
s64 Unk_13bd780_call(Unk_13bd600_Script* self, const Unk_13bd600_Arg* args) {
    return Unk_13bd600_GetManager()->vf13(true);
}

void Unk_13fa3c0(Unk_13bd600_Owner* self, const u64& hash);

// 0x71013bdbb0
s64 Unk_13bdbb0_call(Unk_13bd600_Script* self, const Unk_13bd600_Arg* args) {
    u64 hash = Unk_13b12d0(reinterpret_cast<Unk_66efd0*>(self), args[1].i);
    Unk_13fa3c0(self->field_84, hash);
    return 1;
}

// 0x71013bdbf0
s64 Unk_13bdbf0_call(Unk_13bd600_Script* self, const Unk_13bd600_Arg* args) {
    return Unk_13bd600_GetManager()->vf10();
}

void Unk_d2aa70(const u64& arg1, const u64& arg2, const u64& arg3, bool arg4);

// 0x71013bdc20
s64 Unk_13bdc20_call(Unk_13bd600_Script* self, const Unk_13bd600_Arg* args) {
    u64 kind = 0x0ac6b1274261ea10;
    u64 hash1 = Unk_13b12d0(reinterpret_cast<Unk_66efd0*>(self), args[1].i);
    u64 hash2 = Unk_13b12d0(reinterpret_cast<Unk_66efd0*>(self), args[2].i);
    Unk_d2aa70(kind, hash1, hash2, args[3].i != 0);
    return hash2;
}
