#pragma once
// The battle logic's view of the battle (vtable 0x71023b9058, class
// Unk_23b9048), as slots 252 to 279 and the function its constructor calls
// show it: a class on gflib3's other reference-counted object (its slots 2 to
// 4 are Unk_239a4c0's), with the battle's main module at +0x58 (null when
// there's none, src/battle/battle_engine/Unk_7c2d80.cpp), two more of its
// modules at +0x60 and +0x68 and an object it owns at +0x78.
// Unk_8a9570.h declares the class too, with the signatures slots 276 to 296
// show; this declaration is the same, with the signatures these functions
// show. Placeholder names: rename once the class is known.
#include <memory>

#include <types.h>

#include "gflib3/Unk_239a4c0.h"
#include "unsorted/Unk_23f4660.h"
#include "unsorted/Unk_2771620.h"

struct Unk_7ecc90_Con;
struct Unk_7ee6b0;
struct Unk_7fc430_Party;

// The object at +0x28 of what the battle owns: its destructor is out of line.
class Unk_7dfde0 {
public:
    ~Unk_7dfde0();  // 0x71007dfde0, not decompiled yet
};

// The object at +0x8 of what the battle owns: destroyed through its vtable.
class Unk_8a82e0_Object {
public:
    virtual ~Unk_8a82e0_Object();
};

// What the battle's object is made from: the allocator and two of the
// battle's modules (+0x58 and +0x68).
struct Unk_8a82e0_Args {
    Unk_239a418_Allocator* field_0;
    void* field_8;
    void* field_10;
};
PKMN_SIZE_ASSERT(Unk_8a82e0_Args, 0x18);

// The object the battle owns at +0x78, 0x48 bytes, freed through its
// allocator.
class Unk_8a82e0 {
public:
    explicit Unk_8a82e0(const Unk_8a82e0_Args& args);  // 0x71008a82e0, not decompiled yet

    void* field_0;
    std::unique_ptr<Unk_8a82e0_Object, Unk_23f4660_Deleter> field_8;
    std::unique_ptr<Unk_7dfde0, Unk_23f4660_Deleter> field_28;
};
PKMN_SIZE_ASSERT(Unk_8a82e0, 0x48);
PKMN_OFFSET_ASSERT(Unk_8a82e0, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_8a82e0, field_28, 0x28);

// The main module's setup, as far as slot 269 reads it.
struct Unk_8a8e30_Setup {
    u8 _0[0xb28];
    u8 field_b28;
};
PKMN_OFFSET_ASSERT(Unk_8a8e30_Setup, field_b28, 0xb28);

// The main module, as far as slot 269 reads it.
struct Unk_8a8e30_Main {
    u8 _0[0x88];
    const Unk_8a8e30_Setup* field_88;
};
PKMN_OFFSET_ASSERT(Unk_8a8e30_Main, field_88, 0x88);

class Unk_23b9048 : public Unk_239a4c0 {
public:
    ~Unk_23b9048() override;
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
    virtual Unk_7ecc90_Con* vf252();
    virtual Unk_7ee6b0* vf253(u8 client);
    virtual bool vf254(Unk_7ee6b0* out, u32 client);
    virtual u64 vf255(u8 client);
    virtual const Unk_7fc430_Party* vf256();
    virtual const Unk_7fc430_Party* vf257();
    virtual const Unk_7fc430_Party* vf258(u32 value);
    virtual const Unk_7fc430_Party* vf259(u8 client);
    virtual u64 vf260();
    virtual u64 vf261();
    virtual void vf262();
    virtual u64 vf263();
    virtual void vf264(u64 value, u64 arg2);
    virtual void vf265(u64 value, u64 arg2);
    virtual u32 vf266();
    virtual u32 vf267();
    virtual u8 vf268();
    virtual bool vf269();
    virtual bool vf270();
    virtual bool vf271();
    virtual bool vf272(s32 value);
    virtual bool vf273();
    virtual bool vf274(u8 client);
    virtual u32 vf275();
    virtual u8 vf276();
    virtual u8 vf277();
    virtual void vf278();
    virtual void vf279(u32 value);
    virtual bool vf280(u8 client);
    virtual u32 vf281(u8 client, u32 index);
    virtual u8 vf282(s32 value);
    virtual u8 vf283(s32 value);
    virtual u8 vf284(s32 value);
    virtual u16 vf285(u8 client);
    virtual void vf286();
    virtual void vf287();
    virtual void vf288();
    virtual void vf289();
    virtual void vf290();
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
    virtual void vf312();
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

    // Makes the object it owns at +0x78 with `allocator`.
    void Unk_8a8f00(Unk_239a418_Allocator* allocator);

    void* field_58;
    void* field_60;
    void* field_68;
    u32 field_70;
    u32 field_74;
    std::unique_ptr<Unk_8a82e0, Unk_23f4660_Deleter> field_78;
};
PKMN_OFFSET_ASSERT(Unk_23b9048, field_58, 0x58);
PKMN_OFFSET_ASSERT(Unk_23b9048, field_70, 0x70);
PKMN_OFFSET_ASSERT(Unk_23b9048, field_78, 0x78);
PKMN_SIZE_ASSERT(Unk_23b9048, 0x98);
