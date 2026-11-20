// Scope: common
// What applies the battle server's commands on the client (0x71007cdac0 to
// 0x71007e37b0): one function for each command, which reads the command's
// arguments (words) and calls the matching server command
// (src/battle/battle_engine/Unk_8139c0.cpp) or battle Pokemon member function.
// Placeholder names: rename once the class is known.
#include "battle/battle_engine/Unk_7fc210.h"
#include "battle/battle_engine/Unk_8139c0.h"
#include "gflib3/Unk_239a418.h"

using Unk_7cdac0_Ref = Unk_239a418_Ref<Unk_239a418>;

struct Unk_7c2d80_Main;
struct Unk_7e88f0;

// What the client counts for each Pokemon of its party.
struct Unk_7dcd30_Counts {
    u32 field_0;
    u32 field_4;
    u32 field_8;
    u32 field_c;
    u32 field_10;
    u32 field_14;
    u32 field_18;
};
PKMN_SIZE_ASSERT(Unk_7dcd30_Counts, 0x1c);

// What the client reads its commands from (Unk_813b40 reads the next one).
struct Unk_813b40_Reader;

// What a view's message command fills in.
struct Unk_7dcde0_Data {
    u32 field_0;
    u16 field_4;
    u8 field_6;
};
PKMN_SIZE_ASSERT(Unk_7dcde0_Data, 0x8);

// What a view's command of six values takes.
struct Unk_7ded00_Data {
    u16 field_0;
    u16 field_2;
    u16 field_4;
    u16 field_6;
    u16 field_8;
    u8 field_a;
};
PKMN_SIZE_ASSERT(Unk_7ded00_Data, 0xc);

// What the client's view at +0x358 does: each command starts something
// (an animation, a message) with one function and waits for it with the next.
struct Unk_7cdac0_View {
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
    virtual void vf14();
    virtual void vf15();
    virtual void vf16();
    virtual bool vf17();
    virtual void vf18();
    virtual void vf19();
    virtual void vf20();
    virtual void vf21();
    virtual void vf22();
    virtual void vf23();
    virtual void vf24();
    virtual void vf25();
    virtual void vf26();
    virtual void vf27();
    virtual void vf28();
    virtual void vf29();
    virtual void vf30();
    virtual void vf31();
    virtual void vf32();
    virtual void vf33();
    virtual void vf34();
    virtual void vf35();
    virtual void vf36();
    virtual void vf37();
    virtual void vf38();
    virtual void vf39();
    virtual void vf40();
    virtual void vf41();
    virtual void vf42();
    virtual void vf43();
    virtual void vf44();
    virtual void vf45();
    virtual void vf46();
    virtual void vf47();
    virtual void vf48();
    virtual void vf49();
    virtual void vf50();
    virtual void vf51();
    virtual void vf52();
    virtual void vf53();
    virtual void vf54();
    virtual void vf55();
    virtual void vf56();
    virtual void vf57();
    virtual void vf58(u32 arg1);
    virtual void vf59();
    virtual void vf60();
    virtual bool vf61();
    virtual void vf62();
    virtual void vf63();
    virtual void vf64();
    virtual void vf65();
    virtual void vf66();
    virtual void vf67(u32 arg1, u8 position, u32 arg3);
    virtual bool vf68();
    virtual void vf69();
    virtual void vf70();
    virtual void vf71();
    virtual void vf72();
    virtual void vf73(u8 position, bool arg2);
    virtual bool vf74();
    virtual void vf75();
    virtual void vf76();
    virtual void vf77(u8 position);
    virtual bool vf78();
    virtual void vf79(u8 position, u32 arg2);
    virtual bool vf80();
    virtual void vf81(u8 position, bool arg2);
    virtual void vf82(u8 position);
    virtual bool vf83();
    virtual void vf84();
    virtual void vf85();
    virtual void vf86(u8 position, u32 arg2);
    virtual bool vf87();
    virtual void vf88();
    virtual void vf89();
    virtual void vf90();
    virtual void vf91();
    virtual void vf92();
    virtual void vf93();
    virtual void vf94(u8 position);
    virtual bool vf95(u8 position);
    virtual void vf96();
    virtual void vf97();
    virtual void vf98();
    virtual void vf99();
    virtual void vf100();
    virtual void vf101();
    virtual void vf102();
    virtual void vf103();
    virtual void vf104();
    virtual void vf105();
    virtual void vf106();
    virtual void vf107();
    virtual void vf108();
    virtual void vf109();
    virtual void vf110();
    virtual void vf111();
    virtual void vf112();
    virtual void vf113();
    virtual void vf114(u8 position, u8 other);
    virtual bool vf115();
    virtual void vf116();
    virtual void vf117();
    virtual void vf118();
    virtual void vf119();
    virtual void vf120();
    virtual void vf121();
    virtual void vf122();
    virtual void vf123();
    virtual void vf124();
    virtual void vf125();
    virtual void vf126();
    virtual void vf127();
    virtual void vf128();
    virtual void vf129();
    virtual void vf130();
    virtual void vf131();
    virtual void vf132();
    virtual void vf133();
    virtual void vf134();
    virtual void vf135(Unk_7dcde0_Data* data);
    virtual bool vf136(Unk_7dcde0_Data* data);
    virtual void vf137();
    virtual void vf138();
    virtual void vf139();
    virtual void vf140();
    virtual void vf141();
    virtual bool vf142();
    virtual void vf143();
    virtual void vf144();
    virtual void vf145();
    virtual void vf146();
    virtual void vf147();
    virtual void vf148();
    virtual void vf149();
    virtual bool vf150();
    virtual void vf151();
    virtual void vf152();
    virtual void vf153();
    virtual void vf154();
    virtual void vf155();
    virtual void vf156();
    virtual void vf157();
    virtual void vf158();
    virtual void vf159();
    virtual void vf160();
    virtual void vf161();
    virtual void vf162();
    virtual void vf163();
    virtual void vf164();
    virtual void vf165();
    virtual void vf166();
    virtual void vf167();
    virtual void vf168();
    virtual void vf169();
    virtual void vf170();
    virtual void vf171();
    virtual void vf172();
    virtual void vf173();
    virtual void vf174();
    virtual void vf175();
    virtual void vf176();
    virtual void vf177();
    virtual void vf178();
    virtual void vf179();
    virtual void vf180(u32 arg1);
    virtual bool vf181();
    virtual void vf182();
    virtual void vf183();
    virtual void vf184();
    virtual void vf185();
    virtual void vf186();
    virtual void vf187();
    virtual void vf188();
    virtual void vf189();
    virtual void vf190();
    virtual void vf191();
    virtual void vf192();
    virtual void vf193();
    virtual void vf194();
    virtual void vf195();
    virtual void vf196();
    virtual void vf197();
    virtual void vf198();
    virtual void vf199();
    virtual void vf200(u8 position);
    virtual bool vf201();
    virtual void vf202(u8 position);
    virtual bool vf203();
    virtual void vf204(const Unk_7ded00_Data* data);
    virtual bool vf205();
};

struct Unk_7cdac0_Self {
    u8 _0[0x58];
    const Unk_7c2d80_Main* field_58;
    u8 _60[0x70 - 0x60];
    const Unk_7fe1d0* field_70;
    u8 _78[0x1f0 - 0x78];
    const Unk_7e88f0* field_1f0;
    u8 _1f8[0x210 - 0x1f8];
    Unk_813b40_Reader* field_210;
    u8 _218[0x2a6 - 0x218];
    u8 field_2a6;
    u8 field_2a7;
    u8 _2a8[0x340 - 0x2a8];
    const Unk_7fc430_Party* field_340;
    u8 _348[0x358 - 0x348];
    Unk_239a418_Ref<Unk_7cdac0_View> field_358;
    Unk_7dcde0_Data field_360;
    Unk_7dcd30_Counts field_368[6];
    u8 _410[0x4c0 - 0x410];
    u32 field_4c0[0x10];
    u8 field_500;
};
PKMN_OFFSET_ASSERT(Unk_7cdac0_Self, field_58, 0x58);
PKMN_OFFSET_ASSERT(Unk_7cdac0_Self, field_70, 0x70);
PKMN_OFFSET_ASSERT(Unk_7cdac0_Self, field_1f0, 0x1f0);
PKMN_OFFSET_ASSERT(Unk_7cdac0_Self, field_2a6, 0x2a6);
PKMN_OFFSET_ASSERT(Unk_7cdac0_Self, field_358, 0x358);
PKMN_OFFSET_ASSERT(Unk_7cdac0_Self, field_368, 0x368);
PKMN_OFFSET_ASSERT(Unk_7cdac0_Self, field_500, 0x500);

// Its server (src/unsorted/leaf/Unk_7e88d0.cpp).
const Unk_8139c0_Self* Unk_7e88f0_getField90(const Unk_7e88f0* self);

static inline Unk_7cdac0_View* Unk_7cdac0_GetView(const Unk_7cdac0_Self* self) {
    return self->field_358.m_ptr;
}

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
u8 Unk_7cb420(const Unk_7c2d80_Main* self, Unk_7ecc90_Con* con, u8 pokeId);
u8 Unk_7cb4b0(const Unk_7c2d80_Main* self, Unk_7ecc90_Con* con, u8 pokeId);
u8 Unk_7cb540(const Unk_7c2d80_Main* self, u8 position);
void Unk_7dfb80(Unk_7cdac0_Self* self, const Unk_7dcde0_Data* data);
// Declared as src/unsorted/leaf/Unk_7ce130.cpp declares them (the step as an integer).
bool Unk_7d8d00(void* self, u64 seq, u32 arg2);
bool Unk_7d8960(void* self, u64 seq, u32 arg2);
Unk_7cdac0_Ref Unk_7cd0c0(const Unk_7c2d80_Main* self, u8 client);
void Unk_8ac140(Unk_239a418* self, u8 pokeId, u8 arg2);
void Unk_8ac060(Unk_239a418* self, u8 pokeId);
void Unk_8ac0d0(Unk_239a418* self, u8 pokeId, bool arg2);
s32 Unk_7fc4e0(const Unk_7fc430_Party* self, u8 pokeId);
u16 Unk_813b40(Unk_813b40_Reader* self, void* out, u32 size, void* arg3);
void Unk_8171f0(const Unk_8139c0_Self* self, u32 arg1, u32 arg2, u32 arg3);
void Unk_8174f0(const Unk_8139c0_Self* self, u8 pokeId, u32 arg2, bool arg3);
void Unk_817630(const Unk_8139c0_Self* self, u8 client, u8 pokeId, u8 other);
void Unk_818340(const Unk_8139c0_Self* self, u8 pokeId, u32 arg2, u32 arg3);

// Declared as src/unsorted/leaf names them.
struct Unk_7cd240;
void Unk_7cd240_call(Unk_7cd240* self, u64 value, u64 arg2);
struct Unk_817c60;
void Unk_817c60_call(const Unk_817c60* self);

// 0x71007daf90
bool Unk_7daf90(Unk_7cdac0_Self* self, u32*, const u32* args) {
    u8 pokeId = args[0];
    u8 arg2 = args[1];
    u16 arg1 = args[2];
    Unk_816c00(Unk_7cdac0_Server(self), pokeId, arg1, arg1, arg2);
    return true;
}

// 0x71007dafe0
bool Unk_7dafe0(Unk_7cdac0_Self* self, u32*, const u32* args) {
    u8 pokeId = args[0];
    u16 arg2 = args[1];
    Unk_817860(Unk_7cdac0_Server(self), pokeId, arg2);
    return true;
}

// 0x71007db020
bool Unk_7db020(Unk_7cdac0_Self* self, u32*, const u32* args) {
    u8 pokeId = args[0];
    Unk_816c80(Unk_7cdac0_Server(self), pokeId);
    return true;
}

// 0x71007db050
bool Unk_7db050(Unk_7cdac0_Self* self, u32*, const u32* args) {
    u8 pokeId = args[0];
    u8 slot = args[1];
    u8 count = args[2];
    Unk_816cb0(Unk_7cdac0_Server(self), pokeId, slot, count);
    return true;
}

// 0x71007db0a0
bool Unk_7db0a0(Unk_7cdac0_Self* self, u32*, const u32* args) {
    u8 pokeId = args[0];
    u8 arg1 = args[1];
    u8 arg2 = args[2];
    Unk_7f0290(Unk_7cdac0_Poke(self, pokeId), arg1, arg2);
    return true;
}

// 0x71007db0f0
bool Unk_7db0f0(Unk_7cdac0_Self* self, u32*, const u32* args) {
    u8 pokeId = args[0];
    u8 slot = args[1];
    Unk_816d00(Unk_7cdac0_Server(self), pokeId, slot);
    return true;
}

// 0x71007db130
bool Unk_7db130(Unk_7cdac0_Self* self, u32*, const u32* args) {
    u8 pokeId = args[0];
    u8 slot = args[1];
    Unk_816d40(Unk_7cdac0_Server(self), pokeId, slot);
    return true;
}

// 0x71007db170
bool Unk_7db170(Unk_7cdac0_Self* self, u32*, const u32* args) {
    u8 pokeId = args[0];
    u8 slot = args[1];
    Unk_816da0(Unk_7cdac0_Server(self), pokeId, slot);
    return true;
}

// 0x71007db1b0
bool Unk_7db1b0(Unk_7cdac0_Self* self, u32*, const u32* args) {
    Unk_7f02d0(Unk_7ecc90(Unk_7cdac0_Con(self), args[0]), args[1], args[2]);
    return true;
}

// 0x71007db1f0
bool Unk_7db1f0(Unk_7cdac0_Self* self, u32*, const u32* args) {
    Unk_7f0320(Unk_7ecc90(Unk_7cdac0_Con(self), args[0]), args[1], args[2]);
    return true;
}

// 0x71007db230
bool Unk_7db230(Unk_7cdac0_Self* self, u32*, const u32* args) {
    Unk_7f0e50(Unk_7ecc90(Unk_7cdac0_Con(self), args[0]), args[1], args[2]);
    return true;
}

// 0x71007db270
bool Unk_7db270(Unk_7cdac0_Self* self, u32*, const u32* args) {
    Unk_7f0f30(Unk_7ecc90(Unk_7cdac0_Con(self), args[0]), args[1], args[2]);
    return true;
}

// 0x71007db2b0
bool Unk_7db2b0(Unk_7cdac0_Self* self, u32*, const u32* args) {
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
bool Unk_7db340(Unk_7cdac0_Self* self, u32*, const u32* args) {
    Unk_7f10b0(Unk_7ecc90(Unk_7cdac0_Con(self), args[0]));
    return true;
}

// 0x71007db420
bool Unk_7db420(Unk_7cdac0_Self* self, u32*, const u32* args) {
    Unk_7ee6b0* poke = Unk_7ecc90(Unk_7cdac0_Con(self), args[0]);
    u64 value;
    Unk_7f8bc0(&value, args[2], args[3]);
    Unk_7f1490(poke, args[1], &value);
    return true;
}

// 0x71007db4f0
bool Unk_7db4f0(Unk_7cdac0_Self* self, u32*, const u32* args) {
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
bool Unk_7db5b0(Unk_7cdac0_Self* self, u32*, const u32* args) {
    u8 pokeId = args[0];
    u32 arg2 = args[1];
    u16 arg3 = args[2];
    Unk_8175a0(Unk_7cdac0_Server(self), pokeId, arg2, arg3);
    return true;
}

// 0x71007db640
bool Unk_7db640(Unk_7cdac0_Self* self, u32*, const u32* args) {
    u16 arg2 = args[2];
    u8 pokeId = args[0];
    u32 arg3 = args[1];
    Unk_817410(Unk_7cdac0_Server(self), pokeId, arg2, arg3);
    return true;
}

// 0x71007db690
bool Unk_7db690(Unk_7cdac0_Self* self, u32*, const u32* args) {
    u8 pokeId = args[0];
    u8 arg2 = args[1];
    u32 arg3 = args[2];
    Unk_817460(Unk_7cdac0_Server(self), pokeId, arg2, arg3);
    return true;
}

// 0x71007db6e0
bool Unk_7db6e0(Unk_7cdac0_Self* self, u32*, const u32* args) {
    u8 pokeId = args[0];
    u32 arg2 = args[1];
    Unk_817910(Unk_7cdac0_Server(self), pokeId, arg2, nullptr, nullptr, nullptr);
    return true;
}

// 0x71007db760
bool Unk_7db760(Unk_7cdac0_Self* self, u32*, const u32* args) {
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
bool Unk_7dbad0(Unk_7cdac0_Self* self, u32*, const u32* args) {
    u8 pokeId = args[0];
    u8 arg2 = args[1];
    u8 arg4 = args[2];
    u8 arg5 = args[3] != 0;
    u32 arg3 = args[4];
    Unk_817710(Unk_7cdac0_Server(self), pokeId, arg2, arg3, arg4, arg5);
    return true;
}

// 0x71007dbb30
bool Unk_7dbb30(Unk_7cdac0_Self* self, u32*, const u32* args) {
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
bool Unk_7dbbd0(Unk_7cdac0_Self* self, u32*, const u32* args) {
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
bool Unk_7dbc70(Unk_7cdac0_Self* self, u32*, const u32* args) {
    u32 condition = args[0];
    u64 value;
    Unk_7f8bc0(&value, args[1], args[2]);
    Unk_817100(Unk_7cdac0_Server(self), condition, &value);
    return true;
}

// 0x71007dbd00
bool Unk_7dbd00(Unk_7cdac0_Self* self, u32*, const u32* args) {
    u32 condition = args[0];
    u64 value;
    Unk_7f8bc0(&value, args[1], args[2]);
    Unk_8170d0(Unk_7cdac0_Server(self), condition, &value);
    return true;
}

// 0x71007dbdc0
bool Unk_7dbdc0(Unk_7cdac0_Self* self, u32*, const u32* args) {
    u8 pokeId = args[0];
    u32 index = args[1];
    u8 value = args[2];
    Unk_816aa0(Unk_7cdac0_Server(self), pokeId, index, value);
    return true;
}

// 0x71007dbe10
bool Unk_7dbe10(Unk_7cdac0_Self* self, u32*, const u32* args) {
    u8 pokeId = args[0];
    u8 index = args[1];
    u32 value = args[2];
    Unk_816af0(Unk_7cdac0_Server(self), pokeId, index, value);
    return true;
}

// 0x71007dbe60
bool Unk_7dbe60(Unk_7cdac0_Self* self, u32*, const u32* args) {
    u8 pokeId = args[0];
    u8 index = args[1];
    u32 value = args[2];
    Unk_816b40(Unk_7cdac0_Server(self), pokeId, index, value);
    return true;
}

// 0x71007dc060
bool Unk_7dc060(Unk_7cdac0_Self* self, u32*, const u32* args) {
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
bool Unk_7dc130(Unk_7cdac0_Self* self, u32*, const u32* args) {
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

// 0x71007dc290
bool Unk_7dc290(Unk_7cdac0_Self* self, u32*, const u32* args) {
    Unk_7ee6b0* poke = Unk_7ecc90(Unk_7cdac0_Con(self), args[0]);
    if (args[1] != 0x1f && args[2] != 0) {
        struct {
            Unk_7ee6b0* field_0;
            u32 field_8;
        } other;
        Unk_7ee6b0* target = Unk_7ecc90(Unk_7cdac0_Con(self), args[1]);
        u32 value = args[2];
        other.field_0 = target;
        other.field_8 = value;
        Unk_7cd240_call(reinterpret_cast<Unk_7cd240*>(const_cast<Unk_7c2d80_Main*>(self->field_58)),
                        reinterpret_cast<u64>(poke), reinterpret_cast<u64>(&other));
    } else {
        Unk_7cd240_call(reinterpret_cast<Unk_7cd240*>(const_cast<Unk_7c2d80_Main*>(self->field_58)),
                        reinterpret_cast<u64>(poke), 0);
    }
    return true;
}

// 0x71007dc3e0
bool Unk_7dc3e0(Unk_7cdac0_Self* self, u32*, const u32* args) {
    u32 arg1 = args[0];
    u32 arg2 = args[1];
    u32 arg3 = args[2];
    Unk_8171f0(Unk_7cdac0_Server(self), arg1, arg2, arg3);
    return true;
}

// 0x71007dc430
bool Unk_7dc430(Unk_7cdac0_Self* self, u32*, const u32* args) {
    u32 pokeId = args[0];
    u8 clientId = Unk_7cb490(pokeId);
    Unk_7cdac0_Ref client = Unk_7cd0c0(self->field_58, clientId);
    if (client.m_ptr != nullptr)
        Unk_8ac060(client.m_ptr, pokeId);
    return true;
}

// 0x71007dc4a0
bool Unk_7dc4a0(Unk_7cdac0_Self* self, u32*, const u32* args) {
    u32 pokeId = args[0];
    u32 value = args[1];
    u8 clientId = Unk_7cb490(pokeId);
    Unk_7cdac0_Ref client = Unk_7cd0c0(self->field_58, clientId);
    if (client.m_ptr != nullptr)
        Unk_8ac0d0(client.m_ptr, pokeId, value != 0);
    return true;
}

// 0x71007dc520
bool Unk_7dc520(Unk_7cdac0_Self* self, u32*, const u32*) {
    Unk_817c60_call(reinterpret_cast<const Unk_817c60*>(Unk_7cdac0_Server(self)));
    return true;
}

// 0x71007dcb20
bool Unk_7dcb20(Unk_7cdac0_Self* self, u32*, const u32* args) {
    u8 client = args[0];
    u8 pokeId = args[1];
    u8 other = args[2];
    Unk_817630(Unk_7cdac0_Server(self), client, pokeId, other);
    return true;
}

// 0x71007dcd30
bool Unk_7dcd30(Unk_7cdac0_Self* self, u32*, const u32* args) {
    u8 pokeId = args[0];
    u32 value0 = args[1];
    u32 value1 = args[2];
    u32 value2 = args[3];
    u32 value3 = args[4];
    u32 value4 = args[5];
    u32 value5 = args[6];
    u32 value6 = args[7];
    s32 index = Unk_7fc4e0(self->field_340, pokeId);
    if (index >= 0) {
        Unk_7dcd30_Counts* counts = &self->field_368[index];
        counts->field_0 += value0;
        counts->field_4 += value1;
        counts->field_8 += value2;
        counts->field_c += value3;
        counts->field_10 += value4;
        counts->field_14 += value5;
        counts->field_18 += value6;
    }
    return true;
}

// 0x71007dde00
bool Unk_7dde00(Unk_7cdac0_Self* self, u32*, const u32* args) {
    u8 pokeId = args[0];
    u32 arg2 = args[1];
    bool arg3 = args[2] != 0;
    Unk_8174f0(Unk_7cdac0_Server(self), pokeId, arg2, arg3);
    return true;
}

// 0x71007dedc0
bool Unk_7dedc0(Unk_7cdac0_Self* self, u32*, const u32* args) {
    u8 count = args[0];
    self->field_500 = count;
    if (count < 0x10) {
        for (s32 i = 0; i < self->field_500; i++)
            self->field_4c0[i] = args[i + 1];
    }
    return true;
}

// 0x71007dee10
bool Unk_7dee10(Unk_7cdac0_Self* self, u32*, const u32* args) {
    if (args[0] != self->field_2a6) {
        u8 command[0x40];
        u16 id;
        do {
            id = Unk_813b40(self->field_210, command, 0x10, nullptr);
        } while (id != 0xc3 && id != 0xbd);
    }
    return true;
}

// 0x71007dee70
bool Unk_7dee70(Unk_7cdac0_Self* self, u32*, const u32* args) {
    u8 pokeId = args[0];
    u32 arg2 = args[1];
    u32 arg3 = args[2];
    Unk_818340(Unk_7cdac0_Server(self), pokeId, arg2, arg3);
    return true;
}

// 0x71007d29a0
bool Unk_7d29a0(Unk_7cdac0_Self* self, u32* seq, const u32*) {
    if (Unk_7cdac0_GetView(self) != nullptr)
        return Unk_7d8d00(self, reinterpret_cast<u64>(seq), 1);
    return true;
}

// 0x71007d2d40
bool Unk_7d2d40(Unk_7cdac0_Self* self, u32* seq, const u32*) {
    if (Unk_7cdac0_GetView(self) != nullptr)
        return Unk_7d8960(self, reinterpret_cast<u64>(seq), 1);
    return true;
}

// 0x71007d9bf0
bool Unk_7d9bf0(Unk_7cdac0_Self* self, u32* seq, const u32* args) {
    switch (*seq) {
        case 0: {
            u8 position = Unk_7cb420(self->field_58, Unk_7cdac0_Con(self), args[0]);
            Unk_7cdac0_GetView(self)->vf67(args[2], position, args[1]);
            (*seq)++;
            break;
        }
        case 1:
            if (Unk_7cdac0_GetView(self)->vf68())
                return true;
            break;
    }
    return false;
}

// 0x71007d9e10
bool Unk_7d9e10(Unk_7cdac0_Self* self, u32* seq, const u32*) {
    switch (*seq) {
        case 0:
            Unk_7cdac0_GetView(self)->vf58(0x6f);
            (*seq)++;
            break;
        case 1:
            if (Unk_7cdac0_GetView(self)->vf61())
                return true;
            break;
    }
    return false;
}

// 0x71007da020
bool Unk_7da020(Unk_7cdac0_Self* self, u32* seq, const u32* args) {
    switch (*seq) {
        case 0: {
            u8 pokeId = args[0];
            bool value = args[1] != 0;
            u8 position = Unk_7cb420(self->field_58, Unk_7cdac0_Con(self), pokeId);
            Unk_7cdac0_GetView(self)->vf73(position, value);
            (*seq)++;
            break;
        }
        case 1:
            if (Unk_7cdac0_GetView(self)->vf74())
                return true;
            break;
    }
    return false;
}

// 0x71007da0d0
bool Unk_7da0d0(Unk_7cdac0_Self* self, u32* seq, const u32* args) {
    switch (*seq) {
        case 0: {
            u8 position = Unk_7cb420(self->field_58, Unk_7cdac0_Con(self), args[0]);
            Unk_7cdac0_GetView(self)->vf77(position);
            (*seq)++;
            break;
        }
        case 1:
            if (Unk_7cdac0_GetView(self)->vf78())
                return true;
            break;
    }
    return false;
}

// 0x71007daa80
bool Unk_7daa80(Unk_7cdac0_Self* self, u32* seq, const u32* args) {
    switch (*seq) {
        case 0: {
            u8 position = Unk_7cb420(self->field_58, Unk_7cdac0_Con(self), args[0]);
            Unk_7cdac0_GetView(self)->vf82(position);
            (*seq)++;
            break;
        }
        case 1:
            if (Unk_7cdac0_GetView(self)->vf83())
                return true;
            break;
    }
    return false;
}

// 0x71007dca70
bool Unk_7dca70(Unk_7cdac0_Self* self, u32* seq, const u32* args) {
    switch (*seq) {
        case 0: {
            u8 pokeId = args[0];
            u8 position = Unk_7cb420(self->field_58, Unk_7cdac0_Con(self), pokeId);
            Unk_7cdac0_GetView(self)->vf82(position);
            (*seq)++;
            break;
        }
        case 1:
            if (Unk_7cdac0_GetView(self)->vf83())
                return true;
            break;
    }
    return false;
}

// 0x71007dcde0
bool Unk_7dcde0(Unk_7cdac0_Self* self, u32* seq, const u32*) {
    switch (*seq) {
        case 0:
            Unk_7cdac0_GetView(self)->vf135(&self->field_360);
            (*seq)++;
            return false;
        case 1: {
            Unk_7dcde0_Data data;
            data.field_6 = 0;
            data.field_4 = 0;
            data.field_0 = 0;
            if (Unk_7cdac0_GetView(self)->vf136(&data)) {
                Unk_7dfb80(self, &data);
                (*seq)++;
            }
            return false;
        }
    }
    return true;
}

// 0x71007dd000
bool Unk_7dd000(Unk_7cdac0_Self* self, u32* seq, const u32*) {
    switch (*seq) {
        case 0:
            *seq = 2;
            break;
        case 1:
            if (Unk_7cdac0_GetView(self)->vf61())
                *seq = 2;
            break;
        default:
            return true;
    }
    return false;
}

// 0x71007ddc70
bool Unk_7ddc70(Unk_7cdac0_Self* self, u32* seq, const u32* args) {
    if (*seq == 0) {
        Unk_7cdac0_GetView(self)->vf180(args[0]);
        (*seq)++;
    } else if (Unk_7cdac0_GetView(self)->vf181()) {
        return true;
    }
    return false;
}

// 0x71007dde50
bool Unk_7dde50(Unk_7cdac0_Self* self, u32* seq, const u32* args) {
    switch (*seq) {
        case 0: {
            u8 position = Unk_7cb540(self->field_58, args[0]);
            Unk_7cdac0_GetView(self)->vf86(position, 0x3e);
            (*seq)++;
            break;
        }
        case 1:
            if (Unk_7cdac0_GetView(self)->vf87())
                return true;
            break;
    }
    return false;
}

// 0x71007ddee0
bool Unk_7ddee0(Unk_7cdac0_Self* self, u32* seq, const u32* args) {
    switch (*seq) {
        case 0: {
            u8 position = Unk_7cb540(self->field_58, args[0]);
            Unk_7cdac0_GetView(self)->vf86(position, 0x3f);
            (*seq)++;
            return false;
        }
        case 1:
            return Unk_7cdac0_GetView(self)->vf87();
    }
    return false;
}

// 0x71007ddf60
bool Unk_7ddf60(Unk_7cdac0_Self* self, u32* seq, const u32* args) {
    switch (*seq) {
        case 0: {
            u8 position = Unk_7cb4b0(self->field_58, Unk_7cdac0_Con(self), args[0]);
            u8 other = Unk_7cb4b0(self->field_58, Unk_7cdac0_Con(self), args[1]);
            Unk_7cdac0_GetView(self)->vf114(position, other);
            (*seq)++;
            break;
        }
        case 1:
            if (Unk_7cdac0_GetView(self)->vf115())
                return true;
            break;
    }
    return false;
}

// 0x71007de1a0
bool Unk_7de1a0(Unk_7cdac0_Self* self, u32* seq, const u32*) {
    switch (*seq) {
        case 0:
            Unk_7cdac0_GetView(self)->vf149();
            (*seq)++;
            break;
        case 1:
            if (Unk_7cdac0_GetView(self)->vf150())
                return true;
            break;
    }
    return false;
}

// 0x71007de540
bool Unk_7de540(Unk_7cdac0_Self* self, u32* seq, const u32*) {
    switch (*seq) {
        case 0:
            if (self->field_2a7 != 2)
                return true;
            Unk_7cdac0_GetView(self)->vf141();
            (*seq)++;
            return false;
        case 1:
            return Unk_7cdac0_GetView(self)->vf142();
    }
    return true;
}

// 0x71007de5c0
bool Unk_7de5c0(Unk_7cdac0_Self* self, u32* seq, const u32* args) {
    switch (*seq) {
        case 0: {
            u8 pokeId = args[0];
            u8 position = Unk_7cb420(self->field_58, Unk_7cdac0_Con(self), pokeId);
            Unk_7cdac0_GetView(self)->vf200(position);
            (*seq)++;
            return false;
        }
        case 1:
            return Unk_7cdac0_GetView(self)->vf201();
    }
    return true;
}

// 0x71007de670
bool Unk_7de670(Unk_7cdac0_Self* self, u32* seq, const u32* args) {
    switch (*seq) {
        case 0: {
            u8 pokeId = args[0];
            u8 position = Unk_7cb420(self->field_58, Unk_7cdac0_Con(self), pokeId);
            Unk_7cdac0_GetView(self)->vf202(position);
            (*seq)++;
            return false;
        }
        case 1:
            return Unk_7cdac0_GetView(self)->vf203();
    }
    return true;
}

// 0x71007d9b50
bool Unk_7d9b50(Unk_7cdac0_Self* self, u32* seq, const u32* args) {
    switch (*seq) {
        case 0: {
            u8 pokeId = args[0];
            u8 position = Unk_7cb4b0(self->field_58, Unk_7cdac0_Con(self), pokeId);
            bool value = args[1] == 0;
            Unk_7cdac0_GetView(self)->vf81(position, value);
            (*seq)++;
            break;
        }
        case 1:
            return true;
    }
    return false;
}

// 0x71007da250
bool Unk_7da250(Unk_7cdac0_Self* self, u32* seq, const u32* args) {
    switch (*seq) {
        case 0: {
            u8 position = Unk_7cb540(self->field_58, args[0]);
            Unk_7cdac0_GetView(self)->vf79(position, args[1]);
            (*seq)++;
            break;
        }
        case 1:
            if (Unk_7cdac0_GetView(self)->vf80())
                return true;
            break;
    }
    return false;
}

// 0x71007daed0
bool Unk_7daed0(Unk_7cdac0_Self* self, u32* seq, const u32* args) {
    u8 pokeId = args[0];
    u8 position = Unk_7cb420(self->field_58, Unk_7cdac0_Con(self), pokeId);
    switch (*seq) {
        case 0:
            if (pokeId == 0x1f)
                return true;
            Unk_7cdac0_GetView(self)->vf94(position);
            (*seq)++;
            break;
        case 1:
            if (Unk_7cdac0_GetView(self)->vf95(position))
                return true;
            break;
    }
    return false;
}

// 0x71007ded00
bool Unk_7ded00(Unk_7cdac0_Self* self, u32* seq, const u32* args) {
    switch (*seq) {
        case 0: {
            u8 value5 = args[5];
            u16 value4 = args[4];
            u16 value3 = args[3];
            u16 value2 = args[2];
            u16 value1 = args[1];
            u16 value0 = args[0];
            Unk_7ded00_Data data = {value0, value1, value2, value3, value4, value5};
            Unk_7cdac0_GetView(self)->vf204(&data);
            break;
        }
        case 1:
            if (!Unk_7cdac0_GetView(self)->vf205())
                return false;
            break;
        default:
            return true;
    }
    (*seq)++;
    return false;
}
