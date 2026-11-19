// Scope: common
#include "unsorted/registry/Unk_23daca0.h"

// What 0x71024ba560 points to: an object whose +0x48 is the memory resource
// Unk_23daca0 takes when it's given none.
struct Unk_24ba560_Object {
    u8 _0[0x48];
    Unk_239f910_Base* field_48;
};
PKMN_OFFSET_ASSERT(Unk_24ba560_Object, field_48, 0x48);

// 0x71024ba560
extern Unk_24ba560_Object* Unk_24ba560;

// 0x7100e7b5e0 (Shield 0x7100e7b610)
void Unk_23daca0::Unk_e7b5e0(Unk_239f910_Base* resource) {
    field_8 = resource;
    if (!resource)
        field_8 = Unk_24ba560->field_48;
}
