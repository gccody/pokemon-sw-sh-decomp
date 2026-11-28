#pragma once
// The fields of the battle client (src/battle/battle_engine/Unk_7cdac0.cpp
// defines it in full) that its commands from 0x71007dc850 to 0x71007dd348
// use: each reads the command's arguments (words) and calls a server command
// (src/battle/battle_engine/Unk_8139c0.cpp), or starts something on the
// client's view at +0x358 and waits for it. Placeholder names: rename once
// the classes are known.
#include <types.h>

#include "battle/battle_engine/Unk_7fc210.h"
#include "battle/battle_engine/Unk_8139c0.h"
#include "gflib3/Unk_239a418.h"

struct Unk_7e88f0;

// What the battle's setup holds (src/battle/battle_engine/Unk_7c2d80.cpp).
struct Unk_7c2d80_Setup {
    u8 _0[0xa6d];
    u8 field_a6d;
};
PKMN_OFFSET_ASSERT(Unk_7c2d80_Setup, field_a6d, 0xa6d);

// The battle's main module (src/battle/battle_engine/Unk_7c2d80.cpp).
struct Unk_7c2d80_Main {
    u8 _0[0x88];
    const Unk_7c2d80_Setup* field_88;
};
PKMN_OFFSET_ASSERT(Unk_7c2d80_Main, field_88, 0x88);

// A message being built: its id, then its arguments (Unk_8aabb0, Unk_8aabe0).
struct Unk_7dc850_Message {
    u8 _0[0x10];
};

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
    virtual void vf17();
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
    virtual void vf55(Unk_7dc850_Message* message);
    virtual void vf56();
    virtual void vf57();
    virtual void vf58();
    virtual void vf59();
    virtual void vf60();
    virtual bool vf61();
    virtual void vf62();
    virtual void vf63();
    virtual void vf64();
    virtual void vf65();
    virtual void vf66();
    virtual void vf67();
    virtual void vf68();
    virtual void vf69();
    virtual void vf70();
    virtual void vf71();
    virtual void vf72();
    virtual void vf73();
    virtual void vf74();
    virtual void vf75();
    virtual void vf76();
    virtual void vf77();
    virtual void vf78();
    virtual void vf79();
    virtual void vf80();
    virtual void vf81();
    virtual void vf82();
    virtual void vf83();
    virtual void vf84();
    virtual void vf85();
    virtual void vf86();
    virtual void vf87();
    virtual void vf88();
    virtual void vf89();
    virtual void vf90();
    virtual void vf91();
    virtual void vf92(u8 position, bool arg2);
    virtual bool vf93(u8 position);
    virtual void vf94();
    virtual void vf95();
    virtual void vf96(u8 position);
    virtual bool vf97(u8 position);
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
    virtual void vf114();
    virtual void vf115();
    virtual void vf116(u8 arg1, u8 position1, u8 position2, u8 count1, u8 count2);
    virtual bool vf117();
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
    virtual void vf135();
    virtual void vf136();
    virtual void vf137();
    virtual void vf138();
    virtual void vf139();
    virtual void vf140();
    virtual void vf141();
    virtual void vf142();
    virtual void vf143();
    virtual void vf144();
    virtual void vf145();
    virtual void vf146();
    virtual void vf147();
    virtual void vf148();
    virtual void vf149();
    virtual void vf150();
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
    virtual void vf168(u32 position1, u32 position2, u32 arg3, u32 arg4, bool arg5, bool arg6);
    virtual void vf169(u32 position, u32 arg2);
    virtual bool vf170();
    virtual bool vf171();
};

// What the client's +0x360 holds: the Pokemon its view shows.
struct Unk_7dc850_List {
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5(u64 value);
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
    virtual void vf14();
};

// What the client counts for each Pokemon of its party.
struct Unk_7dc850_Counts {
    u32 field_0;
    u32 field_4;
    u32 field_8;
    u32 field_c;
    u32 field_10;
    u32 field_14;
    u32 field_18;
};
PKMN_SIZE_ASSERT(Unk_7dc850_Counts, 0x1c);

struct Unk_7cdac0_Self {
    // Its state while it waits for the server (0x71007d0160, not decompiled yet).
    bool Unk_7d0160();

    u8 _0[0x58];
    const Unk_7c2d80_Main* field_58;
    u8 _60[0x70 - 0x60];
    const Unk_7fe1d0* field_70;
    u8 _78[0xd0 - 0x78];
    bool (Unk_7cdac0_Self::*field_d0)();
    u8 _e0[0x1f0 - 0xe0];
    const Unk_7e88f0* field_1f0;
    u8 _1f8[0x340 - 0x1f8];
    Unk_7fc430_Party* field_340;
    u8 _348[0x358 - 0x348];
    Unk_239a418_Ref<Unk_7cdac0_View> field_358;
    Unk_7dc850_List* field_360;
    Unk_7dc850_Counts field_368[6];
    u8 _410[0x574 - 0x410];
    Unk_7dc850_Message field_574;
};
PKMN_OFFSET_ASSERT(Unk_7cdac0_Self, field_58, 0x58);
PKMN_OFFSET_ASSERT(Unk_7cdac0_Self, field_70, 0x70);
PKMN_OFFSET_ASSERT(Unk_7cdac0_Self, field_d0, 0xd0);
PKMN_OFFSET_ASSERT(Unk_7cdac0_Self, field_1f0, 0x1f0);
PKMN_OFFSET_ASSERT(Unk_7cdac0_Self, field_340, 0x340);
PKMN_OFFSET_ASSERT(Unk_7cdac0_Self, field_358, 0x358);
PKMN_OFFSET_ASSERT(Unk_7cdac0_Self, field_360, 0x360);
PKMN_OFFSET_ASSERT(Unk_7cdac0_Self, field_368, 0x368);
PKMN_OFFSET_ASSERT(Unk_7cdac0_Self, field_574, 0x574);

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

// Declared as src/battle/battle_engine/Unk_7cdac0.cpp declares it (not decompiled yet).
u8 Unk_7cb540(const Unk_7c2d80_Main* self, u8 position);
