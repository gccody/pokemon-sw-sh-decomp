// Scope: common
// Slots of the battle scene's view system (vtable 0x71023c0970, declared by
// the generator as Unk_23c0960 in src/unsorted/virtual/Unk_9afd60.cpp and
// as battle/battle_scene/Unk_23c4ef0_Owner.h's class): 40-47, 207 and 208.
// Each first records a step number in Unk_27d6bc0, like the generator's
// slots. Free functions over a view of the fields they use, as the class
// is declared elsewhere without them. Placeholder names: rename and move
// once the class is known.
#include <types.h>

#include "unsorted/Unk_98a420.h"

extern u32 Unk_27d6bc0 __attribute__((visibility("hidden")));

// Matched first as tools/leafgen.py's placeholders (src/unsorted/leaf).
struct Unk_95abd0;
struct Unk_763000;
bool Unk_95abd0_check(const Unk_95abd0* self);
u32 Unk_763000_call(const Unk_763000* self);

// The scene's forwarders (src/unsorted/Unk_989900.cpp).
u8 Unk_98a030(Unk_23c4ef0_Scene* scene);
void Unk_989fd0(Unk_23c4ef0_Scene* scene, u64 arg1, u64 arg2, u32 arg3, bool arg4, u64 arg5);

void Unk_8cd080(u64 object, u64 arg1);
void Unk_8ea710(void* self, u32 arg1, void* arg2);
void Unk_9411c0(void* self);
void Unk_95a2a0(void* self, u32 arg1, u32 arg2);

// The view system, as these slots see it.
class Unk_9b34e0_Self {
public:
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
    virtual void vf55();
    virtual void vf56();
    virtual void vf57();
    virtual void vf58();
    virtual void vf59();
    virtual void vf60();
    virtual void vf61();
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
    virtual void vf92();
    virtual void vf93();
    virtual void vf94();
    virtual void vf95();
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
    virtual void vf114();
    virtual void vf115();
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
    virtual void vf180();
    virtual void vf181();
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
    virtual void vf200();
    virtual void vf201();
    virtual void vf202();
    virtual void vf203();
    virtual void vf204();
    virtual void vf205();
    virtual void vf206();
    virtual void vf207();
    virtual void vf208();
    virtual void vf209();
    virtual void vf210();
    virtual void vf211();
    virtual void vf212();
    virtual void vf213();
    virtual void vf214();
    virtual void vf215();
    virtual void vf216();
    virtual void vf217();
    virtual void vf218();
    virtual void vf219();
    virtual void vf220();
    virtual void vf221();
    virtual void vf222();
    virtual void vf223();
    virtual void vf224();
    virtual void vf225();
    virtual void vf226();
    virtual u32 vf227();
    virtual void vf228();
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
    virtual void vf251();
    virtual void vf252();
    virtual void vf253();
    virtual void vf254();
    virtual const Unk_763000* vf255(u32 pos);
    virtual void vf256();
    virtual void vf257();
    virtual void vf258();
    virtual void vf259();
    virtual void vf260();
    virtual void vf261();
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
    virtual void vf276();
    virtual void vf277();
    virtual void vf278();
    virtual void vf279();
    virtual void vf280();
    virtual void vf281();
    virtual void vf282();
    virtual void vf283();
    virtual u8 vf284(u32 pos);

    u8 _8[0x5c8 - 0x8];
    Unk_23c4ef0_Scene* field_5c8;
    u8 _5d0[0x628 - 0x5d0];
    u64 field_628;
    u8 _630[0x16f4 - 0x630];
    u32 field_16f4;
    u8 _16f8[0x16fc - 0x16f8];
    u32 field_16fc;
    u8 _1700[0x1704 - 0x1700];
    u32 field_1704;
    u8 _1708[0x1720 - 0x1708];
    u32 field_1720;
    u8 _1724[0x1740 - 0x1724];
    u32 field_1740;
    u8 _1744[0x1f78 - 0x1744];
    u32 field_1f78;
};
PKMN_OFFSET_ASSERT(Unk_9b34e0_Self, field_5c8, 0x5c8);
PKMN_OFFSET_ASSERT(Unk_9b34e0_Self, field_628, 0x628);
PKMN_OFFSET_ASSERT(Unk_9b34e0_Self, field_16f4, 0x16f4);
PKMN_OFFSET_ASSERT(Unk_9b34e0_Self, field_16fc, 0x16fc);
PKMN_OFFSET_ASSERT(Unk_9b34e0_Self, field_1704, 0x1704);
PKMN_OFFSET_ASSERT(Unk_9b34e0_Self, field_1720, 0x1720);
PKMN_OFFSET_ASSERT(Unk_9b34e0_Self, field_1740, 0x1740);
PKMN_OFFSET_ASSERT(Unk_9b34e0_Self, field_1f78, 0x1f78);

// 0x71009b3540
void Unk_9b3540(Unk_9b34e0_Self* self, u64 arg1, u32 arg2) {
    if (Unk_27d6bc0 != 0x3ae) {
        Unk_27d6bc0 = 0x3ae;
    }
    u32 pos = self->vf227();
    Unk_9411c0(self);
    self->field_16fc = pos;
    self->field_1704 = pos;
    Unk_95a2a0(self, arg2, 0);
}

// 0x71009b35b0
bool Unk_9b35b0(Unk_9b34e0_Self* self) {
    if (Unk_27d6bc0 != 0x3b9) {
        Unk_27d6bc0 = 0x3b9;
    }
    return Unk_95abd0_check(reinterpret_cast<const Unk_95abd0*>(self));
}

// 0x71009b3600
void Unk_9b3600(Unk_9b34e0_Self* self) {
    if (Unk_27d6bc0 != 0x3d0) {
        Unk_27d6bc0 = 0x3d0;
    }
    u32 pos = self->vf227();
    Unk_9411c0(self);
    self->field_16fc = pos;
    self->field_1704 = pos;
    self->field_1720 = self->vf284(pos);
    self->field_1740 = Unk_763000_call(self->vf255(pos));
    self->field_1f78 = pos;
    Unk_8ea710(Unk_98ab90(reinterpret_cast<u64>(self->field_5c8->field_38)) + 0x2f8, 0xc, self);
    self->field_16f4 = 0;
}

// 0x71009b3a20
void Unk_9b3a20(Unk_9b34e0_Self* self, const u64* arg1) {
    if (Unk_27d6bc0 != 0x42a) {
        Unk_27d6bc0 = 0x42a;
    }
    Unk_8cd080(self->field_628, *arg1);
}

// 0x71009b3a70
void Unk_9b3a70(Unk_9b34e0_Self* self, bool arg1) {
    if (Unk_27d6bc0 != 0x431) {
        Unk_27d6bc0 = 0x431;
    }
    self->field_16f4 = 0;
    self->field_5c8->Unk_98a570(self->field_628, arg1);
}

// 0x71009b3ab0
void Unk_9b3ab0(Unk_9b34e0_Self* self, u64 arg1, u64 arg2) {
    if (Unk_27d6bc0 != 0x448) {
        Unk_27d6bc0 = 0x448;
    }
    self->field_5c8->Unk_98a530(arg1, false);
    self->field_5c8->Unk_98a6c0(arg2);
}

// 0x71009b3b00
void Unk_9b3b00(Unk_9b34e0_Self* self, u64 arg1, u64 arg2, u32 arg3, bool arg4, u64 arg5) {
    if (Unk_27d6bc0 != 0x464) {
        Unk_27d6bc0 = 0x464;
    }
    Unk_989fd0(self->field_5c8, arg1, arg2, arg3, arg4, arg5);
}

// 0x71009b3b30
u8 Unk_9b3b30(Unk_9b34e0_Self* self) {
    if (Unk_27d6bc0 != 0x478) {
        Unk_27d6bc0 = 0x478;
    }
    return Unk_98a030(self->field_5c8);
}
