// Scope: common
// Unk_23acc98, the base of the objects Unk_7e0080 holds
// (src/unsorted/unk_82e410/Handler.h): its constructor, which keeps the
// battle's modules it is given (field_8.field_0[0..11]), and its helpers that
// ask the main module (field_0[1]) for a Pokemon. Placeholder names: rename
// once the class is known.
#include <types.h>

#include "unsorted/ctor/Unk_23acc98.h"

struct Unk_7fe1d0;
struct Unk_7ecc90_Con;
struct Unk_7ee6b0;
Unk_7ecc90_Con* Unk_7fe1d0_getField8(const Unk_7fe1d0* self);
Unk_7ee6b0* Unk_7ed560(Unk_7ecc90_Con* self, u8 position);
u8 Unk_7ee6b0_getField7d(const Unk_7ee6b0* self);

// 0x710082a930
Unk_23acc98::Unk_23acc98(const Unk_23acc98_Arg& arg) {
    for (int i = 0; i < 12; i++)
        field_8.field_0[i] = arg.field_0[i];
}

// 0x710082aae0: the Pokemon at a position
Unk_7ee6b0* Unk_82aae0(const Unk_23acc98* self, u8 position) {
    const Unk_7fe1d0* main = reinterpret_cast<const Unk_7fe1d0*>(self->field_8.field_0[1]);
    return Unk_7ed560(Unk_7fe1d0_getField8(main), position);
}

// 0x710082aa90: its ID (0x1f for position 5)
u8 Unk_82aa90(const Unk_23acc98* self, u8 position) {
    if (position == 5)
        return 0x1f;
    return Unk_7ee6b0_getField7d(Unk_82aae0(self, position));
}
