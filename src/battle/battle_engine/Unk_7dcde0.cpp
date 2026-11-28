// Scope: common
// Battle client commands (0x71007dcea0 to 0x71007dd348): each reads the
// command's arguments and calls the matching server command
// (src/battle/battle_engine/Unk_8139c0.cpp), or starts something on the view
// and waits for it. Placeholder names: rename once the class is known.
#include "battle/battle_engine/Unk_7dc850.h"

#include "unsorted/Unk_7eef40.h"

// The server command (src/battle/battle_engine/Unk_816f90.cpp).
void Unk_817270(const Unk_8139c0_Self* self, u8 pokeId, u32 value);

// Declared as src/battle/battle_engine/Unk_7cdac0.cpp declares them.
u8 Unk_7cb420(const Unk_7c2d80_Main* self, Unk_7ecc90_Con* con, u8 pokeId);
Unk_7ee6b0* Unk_7ed5e0(Unk_7ecc90_Con* self, u8 position);
u16 Unk_7cc390(void* self, const Unk_7eef40* obj);
void Unk_8a8260(u8 index);
// Declared as src/unsorted/leaf names them.
void Unk_8aabb0(void* self, u32 arg1, u32 id);
void Unk_8aabe0(void* self, u32 value);
u8 Unk_7ee6b0_getField7d(const Unk_7ee6b0* self);
struct Unk_7f2370;
void Unk_7f2370_setField338(Unk_7f2370* self, u16 value);

// 0x71007dcea0
bool Unk_7dcea0(Unk_7cdac0_Self* self, u32*, const u32* args) {
    u8 pokeId = args[0];
    u32 value = args[1];
    Unk_817270(Unk_7cdac0_Server(self), pokeId, value);
    return true;
}

// 0x71007dcee0
bool Unk_7dcee0(Unk_7cdac0_Self* self, u32* seq, const u32* args) {
    u8 pokeId1 = args[0];
    u8 pokeId2 = args[1];
    u32 arg2 = args[2];
    bool flag3 = args[3] != 0;
    bool flag5 = args[5] != 0;
    u32 arg6 = args[6];
    switch (*seq) {
        case 0: {
            u8 position1 = Unk_7cb540(self->field_58, pokeId1);
            u8 position2 = Unk_7cb540(self->field_58, pokeId2);
            Unk_7cdac0_GetView(self)->vf168(position1, position2, arg6, arg2, flag3, flag5);
            *seq = 1;
            return false;
        }
        case 1:
            if (Unk_7cdac0_GetView(self)->vf170())
                *seq = 2;
            return false;
        case 2:
            if (flag3) {
                Unk_7ee6b0* poke = Unk_7ed5e0(Unk_7cdac0_Con(self), pokeId2);
                Unk_7cc390(self->field_58, reinterpret_cast<const Unk_7eef40*>(poke));
            }
            break;
    }
    return true;
}

// 0x71007dd070
bool Unk_7dd070(Unk_7cdac0_Self* self, u32* seq, const u32* args) {
    u8 pokeId = args[0];
    switch (*seq) {
        case 0:
            *seq = self->field_58->field_88->field_a6d != 0 ? 3 : 1;
            break;
        case 1: {
            u32 value = args[2];
            u8 position = Unk_7cb540(self->field_58, pokeId);
            Unk_7cdac0_GetView(self)->vf169(position, value);
            (*seq)++;
            break;
        }
        case 2:
            if (Unk_7cdac0_GetView(self)->vf171())
                (*seq)++;
            break;
        case 3: {
            u8 kind = args[1];
            if (kind == 0) {
                Unk_8aabb0(&self->field_574, 1, 0x4c);
                Unk_7cdac0_GetView(self)->vf55(&self->field_574);
                (*seq)++;
            } else if (kind == 1) {
                Unk_7ee6b0* poke = Unk_7ed5e0(Unk_7cdac0_Con(self), pokeId);
                Unk_8aabb0(&self->field_574, 1, 0x1d7);
                Unk_8aabe0(&self->field_574, Unk_7ee6b0_getField7d(poke));
                Unk_7cdac0_GetView(self)->vf55(&self->field_574);
                (*seq)++;
            } else {
                *seq = 5;
            }
            break;
        }
        case 4:
            if (Unk_7cdac0_GetView(self)->vf61())
                (*seq)++;
            break;
        case 5:
            return true;
    }
    return false;
}

// 0x71007dd1e0
bool Unk_7dd1e0(Unk_7cdac0_Self* self, u32* seq, const u32* args) {
    u8 pokeId = args[0];
    u8 position = Unk_7cb420(self->field_58, Unk_7cdac0_Con(self), pokeId);
    switch (*seq) {
        case 0:
            if (self->field_d0 == &Unk_7cdac0_Self::Unk_7d0160) {
                Unk_7ee6b0* poke = Unk_7ecc90(Unk_7cdac0_Con(self), pokeId);
                Unk_7f2370_setField338(reinterpret_cast<Unk_7f2370*>(poke), args[1]);
                return true;
            }
            Unk_7cdac0_GetView(self)->vf92(position, false);
            break;
        case 1: {
            if (!Unk_7cdac0_GetView(self)->vf93(position))
                return false;
            Unk_7ee6b0* poke = Unk_7ecc90(Unk_7cdac0_Con(self), pokeId);
            Unk_7f2370_setField338(reinterpret_cast<Unk_7f2370*>(poke), args[1]);
            Unk_7cdac0_GetView(self)->vf96(position);
            break;
        }
        case 2:
            if (!Unk_7cdac0_GetView(self)->vf97(position))
                return false;
            Unk_8a8260(pokeId);
            break;
        default:
            return true;
    }
    (*seq)++;
    return false;
}
