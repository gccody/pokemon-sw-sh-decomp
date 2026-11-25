#pragma once
// The battle logic's view of the battle's main module (vtable 0x71023b9058,
// class Unk_23b9048): most of its slots from 276 on ask the main module it
// holds at +0x58 (src/battle/battle_engine/Unk_7c2d80.cpp), with a default
// for when there's none. src/unsorted/virtual/Unk_8a9080.cpp declares the
// class too; this declaration is the same, with the signatures these
// functions show. Placeholder names: rename once the class is known.
#include <types.h>

#include "gflib3/Unk_239a418.h"

using Unk_7c2d80_Ref = Unk_239a418_Ref<Unk_239a418>;

struct Unk_7c2d80_Main;
struct Unk_7fc430_Party;

// A hashed name (as the main module's clients hold at +0x50): its hash, its
// characters and their count, and the object that keeps them alive. The
// default one is "".
struct Unk_8a9570_Name {
    Unk_8a9570_Name() : field_0(0xcbf29ce484222645), field_8(""), field_10(0) {}  // the hash of ""
    Unk_8a9570_Name(const Unk_8a9570_Name& other)
        : field_0(other.field_0),
          field_8(other.field_8),
          field_10(other.field_10),
          field_18(other.field_18) {}

    // The default name, "" (its guard and storage are weak, so it's an
    // inline function's).
    static const Unk_8a9570_Name& Default() {
        static const Unk_8a9570_Name s_default;
        return s_default;
    }

    u64 field_0;
    const char* field_8;
    u64 field_10;
    Unk_7c2d80_Ref field_18;
};
PKMN_SIZE_ASSERT(Unk_8a9570_Name, 0x20);

// What the main module's setup holds at +0x3a8, per index.
struct Unk_8a9570_Entry {
    u8 _0[0x10];
};

// The main module's setup, as far as these functions read it.
struct Unk_8a9570_Setup {
    u8 _0[0x3a8];
    Unk_8a9570_Entry field_3a8[1];  // indexed by a u8
    u8 _3b8[0xa50 - 0x3b8];
    u8 field_a50;
    u8 _a51[0xa6d - 0xa51];
    u8 field_a6d;
    u8 _a6e[0xa71 - 0xa6e];
    u8 field_a71;
};
PKMN_OFFSET_ASSERT(Unk_8a9570_Setup, field_3a8, 0x3a8);
PKMN_OFFSET_ASSERT(Unk_8a9570_Setup, field_a50, 0xa50);
PKMN_OFFSET_ASSERT(Unk_8a9570_Setup, field_a6d, 0xa6d);
PKMN_OFFSET_ASSERT(Unk_8a9570_Setup, field_a71, 0xa71);

// The main module, as far as these functions read it.
struct Unk_8a9570_Main {
    u8 _0[0x88];
    Unk_8a9570_Setup* field_88;
};
PKMN_OFFSET_ASSERT(Unk_8a9570_Main, field_88, 0x88);

class Unk_23b9048 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual u32 vf5();
    virtual u32 vf6();
    virtual u32 vf7();
    virtual u32 vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
    virtual u32 vf14();
    virtual u32 vf15();
    virtual void vf16();
    virtual u32 vf17();
    virtual u32 vf18();
    virtual u32 vf19();
    virtual void vf20();
    virtual u32 vf21();
    virtual void vf22();
    virtual void vf23();
    virtual u32 vf24();
    virtual void vf25();
    virtual void vf26();
    virtual u32 vf27();
    virtual void vf28();
    virtual void vf29();
    virtual void vf30();
    virtual u32 vf31();
    virtual u32 vf32();
    virtual void vf33();
    virtual void vf34();
    virtual u32 vf35();
    virtual void vf36();
    virtual void vf37();
    virtual void vf38();
    virtual u32 vf39();
    virtual void vf40();
    virtual u32 vf41();
    virtual void vf42();
    virtual void vf43();
    virtual void vf44();
    virtual void vf45();
    virtual void vf46();
    virtual u32 vf47();
    virtual void vf48();
    virtual u32 vf49();
    virtual void vf50();
    virtual u32 vf51();
    virtual void vf52();
    virtual u32 vf53();
    virtual void vf54();
    virtual void vf55();
    virtual void vf56();
    virtual void vf57();
    virtual void vf58();
    virtual void vf59();
    virtual u32 vf60();
    virtual u32 vf61();
    virtual u32 vf62();
    virtual void vf63();
    virtual void vf64();
    virtual u32 vf65();
    virtual void vf66();
    virtual void vf67();
    virtual u32 vf68();
    virtual void vf69();
    virtual u32 vf70();
    virtual void vf71();
    virtual u32 vf72();
    virtual void vf73();
    virtual u32 vf74();
    virtual void vf75();
    virtual u32 vf76();
    virtual void vf77();
    virtual u32 vf78();
    virtual void vf79();
    virtual u32 vf80();
    virtual void vf81();
    virtual void vf82();
    virtual u32 vf83();
    virtual void vf84();
    virtual u32 vf85();
    virtual void vf86();
    virtual u32 vf87();
    virtual void vf88();
    virtual u32 vf89();
    virtual void vf90();
    virtual u32 vf91();
    virtual void vf92();
    virtual u32 vf93();
    virtual void vf94();
    virtual u32 vf95();
    virtual void vf96();
    virtual u32 vf97();
    virtual void vf98();
    virtual u32 vf99();
    virtual void vf100();
    virtual void vf101();
    virtual u32 vf102();
    virtual void vf103();
    virtual u32 vf104();
    virtual void vf105();
    virtual void vf106();
    virtual u32 vf107();
    virtual void vf108();
    virtual u32 vf109();
    virtual void vf110();
    virtual u32 vf111();
    virtual void vf112();
    virtual u32 vf113();
    virtual void vf114();
    virtual u32 vf115();
    virtual void vf116();
    virtual u32 vf117();
    virtual void vf118();
    virtual u32 vf119();
    virtual void vf120();
    virtual u32 vf121();
    virtual u32 vf122();
    virtual u32 vf123();
    virtual u32 vf124();
    virtual u32 vf125();
    virtual void vf126();
    virtual void vf127();
    virtual u32 vf128();
    virtual void vf129();
    virtual void vf130();
    virtual void vf131();
    virtual u32 vf132();
    virtual void vf133();
    virtual u32 vf134();
    virtual void vf135();
    virtual u32 vf136();
    virtual void vf137();
    virtual u32 vf138();
    virtual void vf139();
    virtual u32 vf140();
    virtual void vf141();
    virtual u32 vf142();
    virtual void vf143();
    virtual u32 vf144();
    virtual void vf145();
    virtual u32 vf146();
    virtual void vf147();
    virtual u32 vf148();
    virtual void vf149();
    virtual u32 vf150();
    virtual void vf151();
    virtual u32 vf152();
    virtual void vf153();
    virtual u32 vf154();
    virtual void vf155();
    virtual void vf156();
    virtual void vf157();
    virtual void vf158();
    virtual void vf159();
    virtual void vf160();
    virtual void vf161();
    virtual u32 vf162();
    virtual void vf163();
    virtual u32 vf164();
    virtual void vf165();
    virtual void vf166();
    virtual u32 vf167();
    virtual void vf168();
    virtual void vf169();
    virtual u32 vf170();
    virtual u32 vf171();
    virtual void vf172();
    virtual void vf173();
    virtual void vf174();
    virtual void vf175();
    virtual void vf176();
    virtual u32 vf177();
    virtual void vf178();
    virtual u32 vf179();
    virtual void vf180();
    virtual u32 vf181();
    virtual void vf182();
    virtual u32 vf183();
    virtual void vf184();
    virtual void vf185();
    virtual u32 vf186();
    virtual void vf187();
    virtual void vf188();
    virtual u32 vf189();
    virtual void vf190();
    virtual void vf191();
    virtual void vf192();
    virtual void vf193();
    virtual void vf194();
    virtual u32 vf195();
    virtual u32 vf196();
    virtual void vf197();
    virtual u32 vf198();
    virtual void vf199();
    virtual void vf200();
    virtual u32 vf201();
    virtual void vf202();
    virtual u32 vf203();
    virtual void vf204();
    virtual u32 vf205();
    virtual void vf206();
    virtual void vf207();
    virtual u32 vf208();
    virtual void vf209();
    virtual u32 vf210();
    virtual void vf211();
    virtual void vf212();
    virtual u32 vf213();
    virtual void vf214();
    virtual u32 vf215();
    virtual void vf216();
    virtual u32 vf217();
    virtual void vf218();
    virtual u32 vf219();
    virtual void vf220();
    virtual u32 vf221();
    virtual void vf222();
    virtual void vf223();
    virtual u32 vf224();
    virtual void vf225();
    virtual u32 vf226();
    virtual void vf227();
    virtual u8 vf228(u8 client);
    virtual void vf229();
    virtual void vf230();
    virtual void vf231();
    virtual void vf232();
    virtual void vf233();
    virtual void vf234();
    virtual void vf235();
    virtual void vf236();
    virtual void vf237();
    virtual void vf238();
    virtual void vf239();
    virtual void vf240();
    virtual void vf241();
    virtual void vf242();
    virtual void vf243();
    virtual void vf244();
    virtual void vf245();
    virtual void vf246();
    virtual void vf247();
    virtual void vf248();
    virtual void vf249();
    virtual void vf250();
    virtual u64 vf251();
    virtual void vf252();
    virtual void vf253();
    virtual void vf254();
    virtual void vf255();
    virtual void vf256();
    virtual void vf257();
    virtual void vf258();
    virtual const Unk_7fc430_Party* vf259(u8 client);
    virtual u64 vf260();
    virtual u64 vf261();
    virtual void vf262();
    virtual void vf263();
    virtual void vf264();
    virtual void vf265();
    virtual void vf266();
    virtual void vf267();
    virtual void vf268();
    virtual void vf269();
    virtual void vf270();
    virtual void vf271();
    virtual void vf272();
    virtual void vf273();
    virtual void vf274();
    virtual void vf275();
    virtual u8 vf276();
    virtual u8 vf277();
    virtual void vf278();
    virtual void vf279();
    virtual bool vf280(u8 client);
    virtual u32 vf281(u8 client, u32 index);
    virtual u8 vf282(s32 value);
    virtual u8 vf283(s32 value);
    virtual u8 vf284(s32 value);
    virtual u16 vf285(u8 client);
    virtual void vf286();
    virtual void vf287();
    virtual void vf288();
    virtual Unk_8a9570_Name vf289(u8 client);
    virtual Unk_7c2d80_Ref vf290(u8 client, u16* out);
    virtual void vf291();
    virtual u8 vf292();
    virtual bool vf293(u8 client);
    virtual u32 vf294();
    virtual u32 vf295();
    virtual u8 vf296();
    virtual u8 vf297();
    virtual u8 vf298();
    virtual u8 vf299();
    virtual bool vf300();
    virtual void vf301();
    virtual u32 vf302();
    virtual void vf303();
    virtual bool vf304(u32 value);
    virtual bool vf305();
    virtual bool vf306();
    virtual bool vf307();
    virtual void vf308();
    virtual u32 vf309();
    virtual u32 vf310();
    virtual void vf311();
    virtual const Unk_8a9570_Entry* vf312(u8 index);
    virtual void vf313();
    virtual void vf314();
    virtual void vf315();
    virtual void vf316();
    virtual void vf317();
    virtual void vf318();
    virtual void vf319();
    virtual u32 vf320();
    virtual void vf321();
    virtual u32 vf322();
    virtual void vf323();
    virtual void vf324();
    virtual void vf325();
    u8 _8[0x50];
    Unk_7c2d80_Main* field_58;
};
PKMN_OFFSET_ASSERT(Unk_23b9048, field_58, 0x58);
