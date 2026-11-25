// Scope: common
// Unk_23bb2a0's steps (src/unsorted/unk_8bf520/Unk_8c6550.h), a state machine
// on +0xd0, which its vf5 runs until its vf6 says it's done: for each set bit
// of its mask (Unk_23bb228's walk, in another TU), for each of its battler's
// moves, it asks the conditions' context about one target and keeps a score
// per target and move (+0xd4, +0x124). Placeholder names: rename once the
// classes are known.
#include <types.h>

#include "unsorted/unk_8bf520/Unk_8c6550.h"

// The leaf placeholders declared below are tools/leafgen.py's, each taking its
// own placeholder type; their return types aren't part of their symbols, so
// they're declared with the types the code here shows.
struct Unk_7cb3b0;
struct Unk_7cb3d0;
struct Unk_7caa70;
struct Unk_7ca1c0;
struct Unk_7ee6c0;
struct Unk_7ee800;
struct Unk_7efe00;
struct Unk_8c1d30;
struct Unk_8c6810;
struct Unk_8c6820;
u8 Unk_7cb3b0_call(const Unk_7cb3b0* self, u32 value, u32 arg2);
u8 Unk_7cb3d0_call(const Unk_7cb3d0* self, u32 value, u32 arg2);
bool Unk_7caa70_check(const Unk_7caa70* self);
u32 Unk_7ca1c0_getField150(const Unk_7ca1c0* self);
bool Unk_7ee6c0_getField298(const Unk_7ee6c0* self);
bool Unk_7ee800_getField273(const Unk_7ee800* self);
u8 Unk_7efe00_getField33c(const Unk_7efe00* self);
bool Unk_7ef2b0_call(void* self);
u32* Unk_8c1d30_getFieldacPtr(Unk_8c1d30* self);
u8 Unk_8c6810_getField64(const Unk_8c6810* self);
u32 Unk_8c6820_getField5c(const Unk_8c6820* self);

void* Unk_7fe1d0_getField8(const Unk_7fe1d0* self);
Unk_7ee6b0* Unk_7ed5e0(Unk_7ecc90_Con* self, u8 position);
u32 Unk_7efef0(void* object, u32 index);
u32 Unk_7cac40(const Unk_7c2d80_Main* self, u8 position);
u32 Unk_7cacb0(const Unk_7c2d80_Main* self, u8 position);
bool Unk_780ec0(u32 move);
u32 Unk_82d9a0(u32 move);

// What Unk_8c1b50 is handed: the references, the battlers, the move.
struct Unk_8c1b50_Args {
    Unk_8c6550_Ref<Unk_239a4c0> field_0;
    u32 field_8;
    Unk_8c6550_Ref<Unk_23bac00> field_10;
    u8 field_18 = 5;
    Unk_7ee6b0* field_20 = nullptr;
    Unk_7ee6b0* field_28 = nullptr;
    u8 field_30 = 0;
    u32 field_34 = 0;
    u16 field_38 = 0;
    u64 field_40 = 0;
    bool field_48 = false;
};
static_assert(sizeof(Unk_8c1b50_Args) == 0x50, "Unk_8c1b50_Args");
PKMN_OFFSET_ASSERT(Unk_8c1b50_Args, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_8c1b50_Args, field_20, 0x20);
PKMN_OFFSET_ASSERT(Unk_8c1b50_Args, field_34, 0x34);
PKMN_OFFSET_ASSERT(Unk_8c1b50_Args, field_40, 0x40);
PKMN_OFFSET_ASSERT(Unk_8c1b50_Args, field_48, 0x48);

// Unk_23bab98's (in the TU of 0x71008c18d0-0x71008c26c0)
void Unk_8c1b50(Unk_23bab98* self, const Unk_8c1b50_Args* args);
bool Unk_8c1c10(Unk_23bab98* self);

// The conditions' context's (src/unsorted/unk_8bf520/Unk_8c18d0.cpp: it's
// Unk_23bac00)
struct Unk_8c18d0_Context;
void Unk_8c24e0(Unk_8c18d0_Context* self, Unk_7ee6b0* battler);

// The battler's move, as the target sees it.
static u32 Unk_8c6ef0_Move(Unk_23bb2a0* self) {
    u32 move = Unk_7efef0(self->field_78, self->field_c4);
    if (Unk_7ee6c0_getField298(reinterpret_cast<const Unk_7ee6c0*>(self->field_78)) ||
        self->field_ce)
        move = Unk_82d9a0(move);
    return move;
}

// NON_MATCHING: the original runs state 1 into state 3 with the zeros it
// stored known (its own call with 0, tail-merged with state 3's); this
// reloads them and shares state 3's code. The rest matches but for registers
// and the order of a few loads and stores
// 0x71008c6ef0
void Unk_23bb2a0::Unk_8c6ef0() {
    switch (field_d0) {
        case 0:
            for (u32 i = 0; i < 5; i++) {
                for (u32 j = 0; j < 4; j++) {
                    field_d4[i][j] = 100;
                    field_124[i][j] = 1;
                }
            }
            Unk_8c6830();
            field_d0 = 1;
            break;
        case 2:
            Unk_8c6870();
            field_d0 = 1;
            // fallthrough
        case 1:
            if (Unk_8c68b0()) {
                field_d0 = 9;
                break;
            }
            field_19e = 0;
            field_19f = 0;
            field_c4 = 0;
            field_d0 = 3;
            // fallthrough
        case 3: {
            if (field_19f)
                field_c3 = Unk_7cb3d0_call(reinterpret_cast<const Unk_7cb3d0*>(field_68), field_c2,
                                           field_19e);
            else
                field_c3 = Unk_7cb3b0_call(reinterpret_cast<const Unk_7cb3b0*>(field_68), field_c2,
                                           field_19e);
            field_c8 = Unk_8c6ef0_Move(this);
            if (!field_174[field_c4]) {
                field_d0 = 7;
                break;
            }
            u8 target = field_c3;
            u8 move = field_c4;
            bool valid = target < 5 && move < 4;
            if (valid && field_124[target][move] == 2 && field_d4[target][move] == 0) {
                field_d0 = 8;
                break;
            }
            if (field_c2 == target) {
                if (valid) {
                    field_124[target][move] = 2;
                    field_d4[target][move] = 0;
                }
                field_d0 = 8;
                break;
            }
            field_80 =
                Unk_7ed5e0(static_cast<Unk_7ecc90_Con*>(Unk_7fe1d0_getField8(field_70)), target);
            if (!Unk_7ef2b0_call(field_80) &&
                !(Unk_7caa70_check(reinterpret_cast<const Unk_7caa70*>(field_68)) &&
                  (Unk_7ee6c0_getField298(reinterpret_cast<const Unk_7ee6c0*>(field_78)) ||
                   field_ce) &&
                  !Unk_7ee800_getField273(reinterpret_cast<const Unk_7ee800*>(field_78)) &&
                  !Unk_780ec0(field_c8))) {
                field_d0 = 4;
                goto step4;
            }
            if (field_c4 < 4 && field_c3 < 5) {
                field_124[field_c3][field_c4] = 2;
                field_d4[field_c3][field_c4] = 0;
            }
            field_d0 = 8;
            break;
        }
        case 4:
        step4: {
            field_c8 = Unk_8c6ef0_Move(this);
            Unk_8c24e0(reinterpret_cast<Unk_8c18d0_Context*>(field_b8.m_ptr), field_80);
            Unk_8c1b50_Args args;
            args.field_0 = field_a8;
            args.field_8 = Unk_8c6820_getField5c(reinterpret_cast<const Unk_8c6820*>(this));
            args.field_10 = field_b8;
            args.field_20 = field_78;
            args.field_28 = field_80;
            args.field_30 = field_c4;
            args.field_34 = field_c8;
            args.field_38 = field_cc;
            args.field_18 = Unk_8c6810_getField64(reinterpret_cast<const Unk_8c6810*>(this));
            args.field_48 =
                Unk_7ee6c0_getField298(reinterpret_cast<const Unk_7ee6c0*>(field_78)) || field_ce;
            Unk_8c1b50(field_b0.m_ptr, &args);
        }
            field_d0 = 6;
            // fallthrough
        case 6:
            if (Unk_8c1c10(field_b0.m_ptr)) {
                u32* score =
                    Unk_8c1d30_getFieldacPtr(reinterpret_cast<Unk_8c1d30*>(field_b0.m_ptr));
                if (field_c4 < 4 && field_c3 < 5) {
                    field_124[field_c3][field_c4] = 0;
                    field_d4[field_c3][field_c4] += *score;
                }
                field_d0 = 8;
            }
            break;
        case 8: {
            u32 count = field_19f ? Unk_7cac40(field_68, field_c1) : Unk_7cacb0(field_68, field_c1);
            field_19e++;
            if (field_19e < count) {
                field_d0 = 3;
                break;
            }
            if (!field_19f &&
                Unk_7ca1c0_getField150(reinterpret_cast<const Unk_7ca1c0*>(field_68))) {
                field_19e = 0;
                field_19f = 1;
                field_d0 = 3;
                break;
            }
            field_d0 = 7;
        }
            // fallthrough
        case 7:
            field_c4++;
            field_19e = 0;
            field_19f = 0;
            if (field_c4 < Unk_7efe00_getField33c(reinterpret_cast<const Unk_7efe00*>(field_78)))
                field_d0 = 3;
            else
                field_d0 = 2;
            break;
        case 9:
            if (Unk_7ee800_getField273(reinterpret_cast<const Unk_7ee800*>(field_78)))
                Unk_8c7400();
            else
                Unk_8c78b0();
            field_1a2 = 1;
            break;
    }
}
