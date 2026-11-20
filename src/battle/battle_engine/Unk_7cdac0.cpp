// Scope: common
// What applies the battle server's commands on the client (0x71007cdac0 to
// 0x71007e37b0): one function for each command, which reads the command's
// arguments (words) and calls the matching server command
// (src/battle/battle_engine/Unk_8139c0.cpp) or battle Pokemon member function.
// Placeholder names: rename once the class is known.
#include "battle/battle_engine/Unk_8139c0.h"
#include "gflib3/Unk_239a418.h"

using Unk_7cdac0_Ref = Unk_239a418_Ref<Unk_239a418>;

struct Unk_7c2d80_Main;
struct Unk_7e88f0;

struct Unk_7cdac0_Self {
    u8 _0[0x58];
    const Unk_7c2d80_Main* field_58;
    u8 _60[0x70 - 0x60];
    const Unk_7fe1d0* field_70;
    u8 _78[0x1f0 - 0x78];
    const Unk_7e88f0* field_1f0;
};
PKMN_OFFSET_ASSERT(Unk_7cdac0_Self, field_58, 0x58);
PKMN_OFFSET_ASSERT(Unk_7cdac0_Self, field_70, 0x70);
PKMN_OFFSET_ASSERT(Unk_7cdac0_Self, field_1f0, 0x1f0);

// Its server (src/unsorted/leaf/Unk_7e88d0.cpp).
const Unk_8139c0_Self* Unk_7e88f0_getField90(const Unk_7e88f0* self);

static inline const Unk_8139c0_Self* Unk_7cdac0_Server(const Unk_7cdac0_Self* self) {
    return Unk_7e88f0_getField90(self->field_1f0);
}

static inline Unk_7ecc90_Con* Unk_7cdac0_Con(const Unk_7cdac0_Self* self) {
    return Unk_7fe1d0_getField8(self->field_70);
}

static inline Unk_7ee6b0* Unk_7cdac0_Poke(const Unk_7cdac0_Self* self, u8 pokeId) {
    return Unk_7ecc90(Unk_7cdac0_Con(self), pokeId);
}

// The server commands (src/battle/battle_engine/Unk_8139c0.cpp).
void Unk_816aa0(const Unk_8139c0_Self* self, u8 pokeId, u32 index, u8 value);
void Unk_816af0(const Unk_8139c0_Self* self, u8 pokeId, u8 index, u32 value);
void Unk_816b40(const Unk_8139c0_Self* self, u8 pokeId, u8 index, u32 value);
void Unk_816c00(const Unk_8139c0_Self* self, u8 pokeId, u32 arg2, u32 arg3, u8 arg4);
void Unk_816c80(const Unk_8139c0_Self* self, u8 pokeId);
void Unk_816cb0(const Unk_8139c0_Self* self, u8 pokeId, u8 slot, u8 count);
void Unk_816d00(const Unk_8139c0_Self* self, u8 pokeId, u8 slot);
void Unk_816d40(const Unk_8139c0_Self* self, u8 pokeId, u8 slot);
void Unk_816da0(const Unk_8139c0_Self* self, u8 pokeId, u8 slot);
void Unk_816f90(const Unk_8139c0_Self* self,
                u8 pokeId,
                u8 arg2,
                u8 arg3,
                u8 arg4,
                u32 arg5,
                u16 arg6,
                u16 arg7);
void Unk_816ff0(const Unk_8139c0_Self* self, u8 pokeId, u8 index, u8 other, u32 arg4);
void Unk_8170d0(const Unk_8139c0_Self* self, u32 condition, const u64* value);
void Unk_817100(const Unk_8139c0_Self* self, u32 condition, void* value);
void Unk_8172b0(const Unk_8139c0_Self* self,
                u8 pokeId,
                u32 arg2,
                u32 arg3,
                u32 arg4,
                u32 arg5,
                u32 arg6,
                u32 arg7);
void Unk_817410(const Unk_8139c0_Self* self, u8 pokeId, u16 arg2, u32 arg3);
void Unk_817460(const Unk_8139c0_Self* self, u8 pokeId, u8 arg2, u32 arg3);
void Unk_8175a0(const Unk_8139c0_Self* self, u8 pokeId, u32 arg2, u16 arg3);
void Unk_817710(const Unk_8139c0_Self* self, u8 pokeId, u8 arg2, u32 arg3, u8 arg4, u8 arg5);
void Unk_817770(const Unk_8139c0_Self* self, u8 pokeId);
void Unk_8177b0(const Unk_8139c0_Self* self, u8 pokeId);
void Unk_817860(const Unk_8139c0_Self* self, u8 pokeId, u16 arg2);
void Unk_817910(const Unk_8139c0_Self* self,
                u8 pokeId,
                u32 arg2,
                bool* arg3,
                const u64* arg4,
                bool* arg5);
void Unk_817980(const Unk_8139c0_Self* self,
                u8 pokeId,
                u8 arg2,
                u8 arg3,
                bool arg4,
                u32 arg5,
                u32 arg6);
void Unk_817a80(const Unk_8139c0_Self* self,
                u8 pokeId,
                u8 arg2,
                u8 arg3,
                u8 arg4,
                u8 arg5,
                u8 arg6,
                u8 arg7,
                u8 arg8,
                u8 arg9);

// The battle Pokemon's member functions (src/battle/battle_engine/Unk_7ee6b0.cpp).
void Unk_7f0290(Unk_7ee6b0* self, u8 arg1, u8 arg2);
void Unk_7f02d0(Unk_7ee6b0* self, u8 arg1, u8 arg2);
void Unk_7f0320(Unk_7ee6b0* self, u8 arg1, u8 arg2);
u8 Unk_7f0e50(Unk_7ee6b0* self, u32 stat, u8 count);
u8 Unk_7f0f30(Unk_7ee6b0* self, u32 stat, u8 count);
bool Unk_7f10b0(Unk_7ee6b0* self);
void Unk_7f1490(Unk_7ee6b0* self, u32 condition, const u64* value);
u8 Unk_7ee6b0_getField7d(const Unk_7ee6b0* self);

// A condition's value (src/battle/battle_engine/Unk_7f8780.cpp would hold it).
void Unk_7f8bc0(u64* self, u32 arg1, u32 arg2);

u8 Unk_7cb490(u8 pokeId);
Unk_7cdac0_Ref Unk_7cd0c0(const Unk_7c2d80_Main* self, u8 client);
void Unk_8ac140(Unk_239a418* self, u8 pokeId, u8 arg2);

// 0x71007daf90
bool Unk_7daf90(const Unk_7cdac0_Self* self, u32, const u32* args) {
    u8 pokeId = args[0];
    u8 arg2 = args[1];
    u16 arg1 = args[2];
    Unk_816c00(Unk_7cdac0_Server(self), pokeId, arg1, arg1, arg2);
    return true;
}

// 0x71007dafe0
bool Unk_7dafe0(const Unk_7cdac0_Self* self, u32, const u32* args) {
    u8 pokeId = args[0];
    u16 arg2 = args[1];
    Unk_817860(Unk_7cdac0_Server(self), pokeId, arg2);
    return true;
}

// 0x71007db020
bool Unk_7db020(const Unk_7cdac0_Self* self, u32, const u32* args) {
    u8 pokeId = args[0];
    Unk_816c80(Unk_7cdac0_Server(self), pokeId);
    return true;
}

// 0x71007db050
bool Unk_7db050(const Unk_7cdac0_Self* self, u32, const u32* args) {
    u8 pokeId = args[0];
    u8 slot = args[1];
    u8 count = args[2];
    Unk_816cb0(Unk_7cdac0_Server(self), pokeId, slot, count);
    return true;
}

// 0x71007db0a0
bool Unk_7db0a0(const Unk_7cdac0_Self* self, u32, const u32* args) {
    u8 pokeId = args[0];
    u8 arg1 = args[1];
    u8 arg2 = args[2];
    Unk_7f0290(Unk_7cdac0_Poke(self, pokeId), arg1, arg2);
    return true;
}

// 0x71007db0f0
bool Unk_7db0f0(const Unk_7cdac0_Self* self, u32, const u32* args) {
    u8 pokeId = args[0];
    u8 slot = args[1];
    Unk_816d00(Unk_7cdac0_Server(self), pokeId, slot);
    return true;
}

// 0x71007db130
bool Unk_7db130(const Unk_7cdac0_Self* self, u32, const u32* args) {
    u8 pokeId = args[0];
    u8 slot = args[1];
    Unk_816d40(Unk_7cdac0_Server(self), pokeId, slot);
    return true;
}

// 0x71007db170
bool Unk_7db170(const Unk_7cdac0_Self* self, u32, const u32* args) {
    u8 pokeId = args[0];
    u8 slot = args[1];
    Unk_816da0(Unk_7cdac0_Server(self), pokeId, slot);
    return true;
}

// 0x71007db1b0
bool Unk_7db1b0(const Unk_7cdac0_Self* self, u32, const u32* args) {
    Unk_7f02d0(Unk_7ecc90(Unk_7cdac0_Con(self), args[0]), args[1], args[2]);
    return true;
}

// 0x71007db1f0
bool Unk_7db1f0(const Unk_7cdac0_Self* self, u32, const u32* args) {
    Unk_7f0320(Unk_7ecc90(Unk_7cdac0_Con(self), args[0]), args[1], args[2]);
    return true;
}

// 0x71007db230
bool Unk_7db230(const Unk_7cdac0_Self* self, u32, const u32* args) {
    Unk_7f0e50(Unk_7ecc90(Unk_7cdac0_Con(self), args[0]), args[1], args[2]);
    return true;
}

// 0x71007db270
bool Unk_7db270(const Unk_7cdac0_Self* self, u32, const u32* args) {
    Unk_7f0f30(Unk_7ecc90(Unk_7cdac0_Con(self), args[0]), args[1], args[2]);
    return true;
}

// 0x71007db2b0
bool Unk_7db2b0(const Unk_7cdac0_Self* self, u32, const u32* args) {
    u8 pokeId = args[0];
    u8 arg2 = args[1];
    u8 arg3 = args[2];
    u8 arg4 = args[3];
    u8 arg5 = args[4];
    u8 arg6 = args[5];
    u8 arg7 = args[6];
    u8 arg8 = args[7];
    u8 arg9 = args[8];
    Unk_817a80(Unk_7cdac0_Server(self), pokeId, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9);
    return true;
}

// 0x71007db340
bool Unk_7db340(const Unk_7cdac0_Self* self, u32, const u32* args) {
    Unk_7f10b0(Unk_7ecc90(Unk_7cdac0_Con(self), args[0]));
    return true;
}

// 0x71007db420
bool Unk_7db420(const Unk_7cdac0_Self* self, u32, const u32* args) {
    Unk_7ee6b0* poke = Unk_7ecc90(Unk_7cdac0_Con(self), args[0]);
    u64 value;
    Unk_7f8bc0(&value, args[2], args[3]);
    Unk_7f1490(poke, args[1], &value);
    return true;
}

// 0x71007db4f0
bool Unk_7db4f0(const Unk_7cdac0_Self* self, u32, const u32* args) {
    u8 pokeId = args[0];
    u8 index = args[1];
    u8 other = args[2];
    u32 arg4 = args[3];
    Unk_816ff0(Unk_7cdac0_Server(self), pokeId, index, other, arg4);
    const Unk_7ee6b0* poke =
        Unk_7fc430(Unk_7ed1a0(Unk_7fe1d0_getField8(self->field_70), pokeId), index);
    u8 id = Unk_7ee6b0_getField7d(poke);
    u8 value = poke->field_33d;
    u8 clientId = Unk_7cb490(id);
    Unk_7cdac0_Ref client = Unk_7cd0c0(self->field_58, clientId);
    Unk_8ac140(client.m_ptr, id, value);
    return true;
}

// 0x71007db5b0
bool Unk_7db5b0(const Unk_7cdac0_Self* self, u32, const u32* args) {
    u8 pokeId = args[0];
    u32 arg2 = args[1];
    u16 arg3 = args[2];
    Unk_8175a0(Unk_7cdac0_Server(self), pokeId, arg2, arg3);
    return true;
}

// 0x71007db640
bool Unk_7db640(const Unk_7cdac0_Self* self, u32, const u32* args) {
    u16 arg2 = args[2];
    u8 pokeId = args[0];
    u32 arg3 = args[1];
    Unk_817410(Unk_7cdac0_Server(self), pokeId, arg2, arg3);
    return true;
}

// 0x71007db690
bool Unk_7db690(const Unk_7cdac0_Self* self, u32, const u32* args) {
    u8 pokeId = args[0];
    u8 arg2 = args[1];
    u32 arg3 = args[2];
    Unk_817460(Unk_7cdac0_Server(self), pokeId, arg2, arg3);
    return true;
}

// 0x71007db6e0
bool Unk_7db6e0(const Unk_7cdac0_Self* self, u32, const u32* args) {
    u8 pokeId = args[0];
    u32 arg2 = args[1];
    Unk_817910(Unk_7cdac0_Server(self), pokeId, arg2, nullptr, nullptr, nullptr);
    return true;
}

// 0x71007db760
bool Unk_7db760(const Unk_7cdac0_Self* self, u32, const u32* args) {
    u8 pokeId = args[0];
    u8 arg2 = args[1];
    u8 arg3 = args[2];
    bool arg4 = args[3] != 0;
    u32 arg5 = args[5];
    u32 arg6 = args[6];
    Unk_817980(Unk_7cdac0_Server(self), pokeId, arg2, arg3, arg4, arg5, arg6);
    return true;
}

// 0x71007dbad0
bool Unk_7dbad0(const Unk_7cdac0_Self* self, u32, const u32* args) {
    u8 pokeId = args[0];
    u8 arg2 = args[1];
    u8 arg4 = args[2];
    u8 arg5 = args[3] != 0;
    u32 arg3 = args[4];
    Unk_817710(Unk_7cdac0_Server(self), pokeId, arg2, arg3, arg4, arg5);
    return true;
}

// 0x71007dbb30
bool Unk_7dbb30(const Unk_7cdac0_Self* self, u32, const u32* args) {
    u8 pokeId = args[0];
    Unk_817770(Unk_7cdac0_Server(self), pokeId);
    Unk_7ee6b0* poke = Unk_7cdac0_Poke(self, pokeId);
    u8 id = Unk_7ee6b0_getField7d(poke);
    u8 value = poke->field_33d;
    u8 clientId = Unk_7cb490(id);
    Unk_7cdac0_Ref client = Unk_7cd0c0(self->field_58, clientId);
    Unk_8ac140(client.m_ptr, id, value);
    return true;
}

// 0x71007dbbd0
bool Unk_7dbbd0(const Unk_7cdac0_Self* self, u32, const u32* args) {
    u8 pokeId = args[0];
    Unk_8177b0(Unk_7cdac0_Server(self), pokeId);
    Unk_7ee6b0* poke = Unk_7cdac0_Poke(self, pokeId);
    u8 id = Unk_7ee6b0_getField7d(poke);
    u8 value = poke->field_33d;
    u8 clientId = Unk_7cb490(id);
    Unk_7cdac0_Ref client = Unk_7cd0c0(self->field_58, clientId);
    Unk_8ac140(client.m_ptr, id, value);
    return true;
}

// 0x71007dbc70
bool Unk_7dbc70(const Unk_7cdac0_Self* self, u32, const u32* args) {
    u32 condition = args[0];
    u64 value;
    Unk_7f8bc0(&value, args[1], args[2]);
    Unk_817100(Unk_7cdac0_Server(self), condition, &value);
    return true;
}

// 0x71007dbd00
bool Unk_7dbd00(const Unk_7cdac0_Self* self, u32, const u32* args) {
    u32 condition = args[0];
    u64 value;
    Unk_7f8bc0(&value, args[1], args[2]);
    Unk_8170d0(Unk_7cdac0_Server(self), condition, &value);
    return true;
}

// 0x71007dbdc0
bool Unk_7dbdc0(const Unk_7cdac0_Self* self, u32, const u32* args) {
    u8 pokeId = args[0];
    u32 index = args[1];
    u8 value = args[2];
    Unk_816aa0(Unk_7cdac0_Server(self), pokeId, index, value);
    return true;
}

// 0x71007dbe10
bool Unk_7dbe10(const Unk_7cdac0_Self* self, u32, const u32* args) {
    u8 pokeId = args[0];
    u8 index = args[1];
    u32 value = args[2];
    Unk_816af0(Unk_7cdac0_Server(self), pokeId, index, value);
    return true;
}

// 0x71007dbe60
bool Unk_7dbe60(const Unk_7cdac0_Self* self, u32, const u32* args) {
    u8 pokeId = args[0];
    u8 index = args[1];
    u32 value = args[2];
    Unk_816b40(Unk_7cdac0_Server(self), pokeId, index, value);
    return true;
}

// 0x71007dc060
bool Unk_7dc060(const Unk_7cdac0_Self* self, u32, const u32* args) {
    u8 pokeId = args[0];
    u8 arg2 = args[1];
    u8 arg3 = args[2];
    u8 arg4 = args[3];
    u32 arg5 = args[4];
    u16 arg6 = args[5];
    u16 arg7 = args[6];
    Unk_816f90(Unk_7cdac0_Server(self), pokeId, arg2, arg3, arg4, arg5, arg6, arg7);
    return true;
}

// 0x71007dc130
bool Unk_7dc130(const Unk_7cdac0_Self* self, u32, const u32* args) {
    u8 pokeId = args[0];
    u32 arg2 = args[1];
    u32 arg3 = args[2];
    u32 arg4 = args[3];
    u32 arg5 = args[4];
    u32 arg6 = args[5];
    u32 arg7 = args[6];
    Unk_8172b0(Unk_7cdac0_Server(self), pokeId, arg2, arg3, arg4, arg5, arg6, arg7);
    return true;
}
