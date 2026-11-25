// Scope: common
//
// Part of game/unk_1290e40's first TU (0x7101290e40 to 0x71012938b0): the
// functions of Unk_242b0f0 and Unk_242b1c0 (src/unsorted/Unk_12927e0.h) that
// aren't the compiler's. Neither class is made in this file (Unk_242b0f0 by
// 0x7101292440, Unk_242b1c0 by Unk_242ae80's vf8 in
// src/unsorted/Unk_1290e40.cpp), and clang emits a class with internal
// linkage only where it's made: these are the bodies for the file that makes
// it.
#include "unsorted/Unk_12927e0.h"

// The functions of the callables Unk_242b1c0's vf7 stores, local to the TU in
// the original (their addresses are taken with adrp+add): the generated
// leaves of src/unsorted/leaf, and the calls (0x7101292ea0 in
// src/unsorted/Unk_1292e30.cpp; 0x7101293610 and 0x7101293780 not decompiled
// yet).
#define UNK_HIDDEN __attribute__((visibility("hidden")))
void Unk_1292ea0(Unk_24284d0** captured) UNK_HIDDEN;
void Unk_12930c0_update() UNK_HIDDEN;
struct Unk_12935f0;
struct Unk_12935f0_arg1;
void Unk_12935f0_set(const Unk_12935f0* self, Unk_12935f0_arg1* value) UNK_HIDDEN;
struct Unk_1293600;
struct Unk_1293600_arg1;
void Unk_1293600_set(const Unk_1293600* self, Unk_1293600_arg1* value) UNK_HIDDEN;
void Unk_1293610(Unk_24284d0** captured) UNK_HIDDEN;
void Unk_1293750_update() UNK_HIDDEN;
struct Unk_1293760;
struct Unk_1293760_arg1;
void Unk_1293760_set(const Unk_1293760* self, Unk_1293760_arg1* value) UNK_HIDDEN;
struct Unk_1293770;
struct Unk_1293770_arg1;
void Unk_1293770_set(const Unk_1293770* self, Unk_1293770_arg1* value) UNK_HIDDEN;
void Unk_1293780(Unk_24284d0** captured, u64* arg) UNK_HIDDEN;
void Unk_12937b0_update() UNK_HIDDEN;
struct Unk_12937c0;
struct Unk_12937c0_arg1;
void Unk_12937c0_set(const Unk_12937c0* self, Unk_12937c0_arg1* value) UNK_HIDDEN;
struct Unk_12937d0;
struct Unk_12937d0_arg1;
void Unk_12937d0_set(const Unk_12937d0* self, Unk_12937d0_arg1* value) UNK_HIDDEN;
#undef UNK_HIDDEN

// 0x7101292bb0
void Unk_242b1c0::vf7(u64 arg) {
    Unk_24284d0::vf7(arg);
    Unk_126adb0_Arg desc;
    desc.field_0.field_0 = 0x5ea3c9811d533751;
    Unk_SetCallable(desc.field_0.field_20.field_0, this, &Unk_1292ea0, &Unk_12930c0_update,
                    &Unk_12935f0_set, &Unk_1293600_set);
    desc.field_0.field_8 = 0x5ea746811d56418f;
    Unk_SetCallable(desc.field_0.field_20.field_80, this, &Unk_1293610, &Unk_1293750_update,
                    &Unk_1293760_set, &Unk_1293770_set);
    desc.field_2a0 = 0xb0b80d6562080758;
    Unk_SetCallable(desc.field_2b0, this, &Unk_1293780, &Unk_12937b0_update, &Unk_12937c0_set,
                    &Unk_12937d0_set);
    Unk_126adb0(this, desc);
}
