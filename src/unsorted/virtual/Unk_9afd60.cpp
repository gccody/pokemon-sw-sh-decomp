// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

// Called by forwarders. Placeholders: their real signatures aren't known.
void Unk_9b0150(void* self);
void Unk_9b0ae0(void* self);

// Tail-called by lifted functions. Placeholders, like the forwarders' callees.
void Unk_98a4b0(u64);
void Unk_98a4e0(u64);
void Unk_98a510(u64);
void Unk_9bbe20(u64);

// Globals other TUs define, named after their addresses.
extern u32 Unk_27d6bc0;

// Lifted through their own placeholder structs (cast_member).
extern u32 Unk_27d6bc0 __attribute__((visibility("hidden")));

extern u32 Unk_27d6bc0 __attribute__((visibility("hidden")));
struct Unk_9b23e0 {
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
};

extern u32 Unk_27d6bc0 __attribute__((visibility("hidden")));

extern u32 Unk_27d6bc0 __attribute__((visibility("hidden")));

struct Unk_98a420;
extern u32 Unk_27d6bc0 __attribute__((visibility("hidden")));
struct Unk_9b3fb0 {
    u8 _0[0x5c8];
    Unk_98a420* field_5c8;
};
PKMN_OFFSET_ASSERT(Unk_9b3fb0, field_5c8, 0x5c8);

void Unk_98a420_call(const Unk_98a420*);

extern u32 Unk_27d6bc0 __attribute__((visibility("hidden")));
struct Unk_9b45d0 {
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
    virtual void vf67(u64, u64, u64);
};

extern u32 Unk_27d6bc0 __attribute__((visibility("hidden")));

extern u32 Unk_27d6bc0 __attribute__((visibility("hidden")));

extern u32 Unk_27d6bc0 __attribute__((visibility("hidden")));
struct Unk_9b6520 {
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
    virtual void vf86(u32, u32);
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
};

extern u32 Unk_27d6bc0 __attribute__((visibility("hidden")));
struct Unk_9b6580 {
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
};

extern u32 Unk_27d6bc0 __attribute__((visibility("hidden")));
struct Unk_9b65b0 {
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
    virtual void vf86(u32, u32);
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
};

extern u32 Unk_27d6bc0 __attribute__((visibility("hidden")));
struct Unk_9b6610 {
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
};

extern u32 Unk_27d6bc0 __attribute__((visibility("hidden")));

extern u32 Unk_27d6bc0 __attribute__((visibility("hidden")));

extern u32 Unk_27d6bc0 __attribute__((visibility("hidden")));

extern u32 Unk_27d6bc0 __attribute__((visibility("hidden")));

extern u32 Unk_27d6bc0 __attribute__((visibility("hidden")));

extern u32 Unk_27d6bc0 __attribute__((visibility("hidden")));

extern u32 Unk_27d6bc0 __attribute__((visibility("hidden")));

extern u32 Unk_27d6bc0 __attribute__((visibility("hidden")));

extern u32 Unk_27d6bc0 __attribute__((visibility("hidden")));

extern u32 Unk_27d6bc0 __attribute__((visibility("hidden")));

extern u32 Unk_27d6bc0 __attribute__((visibility("hidden")));

extern u32 Unk_27d6bc0 __attribute__((visibility("hidden")));
struct Unk_9b8200 {
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
};

extern u32 Unk_27d6bc0 __attribute__((visibility("hidden")));
struct Unk_9b8290 {
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
};

extern u32 Unk_27d6bc0 __attribute__((visibility("hidden")));
struct Unk_9b82c0 {
    u8 _0[0x16f4];
    u32 field_16f4;
};
PKMN_OFFSET_ASSERT(Unk_9b82c0, field_16f4, 0x16f4);

extern u32 Unk_27d6bc0 __attribute__((visibility("hidden")));

class Unk_23c4860 {
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
};

// 0x71009afd60
void Unk_23c4860::vf6() {
    Unk_9b0150(this);
}

class Unk_23c4aa0 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x71009aff50
void Unk_23c4aa0::vf5() {
    Unk_9b0150(this);
}

class Unk_23c4ae0 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x71009aff60
void Unk_23c4ae0::vf0() {
    Unk_9b0150(this);
}

class Unk_23c4b08 {
public:
    virtual ~Unk_23c4b08();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
};

// 0x71009b02f0
void Unk_23c4b08::vf4() {}

// 0x71009b0300
void Unk_23c4b08::vf5() {
    ::operator delete(this);
}

class Unk_23c4b50 {
public:
    virtual ~Unk_23c4b50();
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
};

// 0x71009b0ab0
void Unk_23c4b50::vf6() {
    Unk_9b0ae0(this);
}

class Unk_23c4d90 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x71009b0ac0
void Unk_23c4d90::vf5() {
    Unk_9b0ae0(this);
}

class Unk_23c4dd0 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x71009b0ad0
void Unk_23c4dd0::vf0() {
    Unk_9b0ae0(this);
}

class Unk_23c0960 {
public:
    virtual ~Unk_23c0960();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual u32 vf7();
    virtual u32 vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
    virtual void vf14();
    virtual u32 vf15();
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
    virtual u32 vf27();
    virtual void vf28();
    virtual void vf29();
    virtual void vf30();
    virtual void vf31();
    virtual u32 vf32();
    virtual void vf33();
    virtual void vf34();
    virtual void vf35();
    virtual void vf36();
    virtual void vf37();
    virtual void vf38();
    virtual u32 vf39();
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
    virtual void vf71(u64 value, u64 arg2, u64 arg3);
    virtual void vf72();
    virtual void vf73();
    virtual void vf74();
    virtual void vf75();
    virtual u32 vf76();
    virtual void vf77();
    virtual u32 vf78();
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
    virtual u32 vf122();
    virtual void vf123();
    virtual void vf124();
    virtual void vf125();
    virtual void vf126();
    virtual void vf127();
    virtual void vf128();
    virtual void vf129();
    virtual void vf130();
    virtual void vf131();
    virtual u32 vf132();
    virtual void vf133();
    virtual u32 vf134();
    virtual void vf135();
    virtual void vf136();
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
    virtual void vf148();
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
    virtual void vf162();
    virtual void vf163();
    virtual u32 vf164();
    virtual void vf165();
    virtual void vf166();
    virtual u32 vf167();
    virtual void vf168();
    virtual void vf169();
    virtual void vf170();
    virtual void vf171();
    virtual void vf172();
    virtual void vf173();
    virtual void vf174();
    virtual void vf175();
    virtual void vf176();
    virtual u32 vf177();
    virtual void vf178();
    virtual void vf179();
    virtual void vf180();
    virtual void vf181();
    virtual void vf182();
    virtual void vf183();
    virtual void vf184();
    virtual void vf185();
    virtual u32 vf186();
    virtual void vf187();
    virtual void vf188();
    virtual void vf189();
    virtual void vf190();
    virtual void vf191();
    virtual void vf192();
    virtual void vf193();
    virtual void vf194();
    virtual u32 vf195();
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
    virtual void vf227();
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
    virtual void vf255();
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
    virtual void vf284();
    virtual void vf285();
    virtual void vf286();
    virtual void vf287();
    virtual void vf288();
    virtual void vf289();
    virtual void vf290();
    virtual void vf291();
    virtual void vf292();
    virtual void vf293();
    virtual void vf294();
    virtual void vf295();
    virtual void vf296();
    virtual void vf297();
    virtual void vf298();
    virtual void vf299();
    virtual void vf300();
    virtual void vf301();
    virtual void vf302();
    virtual void vf303();
    virtual void vf304();
    virtual void vf305();
    virtual void vf306();
    virtual void vf307();
    virtual void vf308();
    virtual void vf309();
    virtual void vf310();
    virtual void vf311();
    virtual void vf312();
    virtual void vf313();
    virtual void vf314();
    virtual void vf315();
    virtual void vf316();
    virtual void vf317();
    virtual void vf318();
    virtual void vf319();
    virtual void vf320();
    virtual void vf321();
    virtual void vf322();
    virtual void vf323();
    virtual void vf324();
    virtual void vf325();
    virtual void vf326();
    virtual void vf327();
    virtual void vf328();
    virtual void vf329();
    virtual void vf330();
    virtual u32 vf331();
    virtual void vf332();
    virtual void vf333();
    virtual u32 vf334();
    virtual void vf335();
    virtual void vf336();
    virtual void vf337();
    virtual void vf338();
    virtual void vf339();
    u8 _8[0x5c0];
    u64 field_5c8;
    u8 _5d0[0x38];
    u64 field_608;
};
PKMN_OFFSET_ASSERT(Unk_23c0960, field_5c8, 0x5c8);
PKMN_OFFSET_ASSERT(Unk_23c0960, field_608, 0x608);

// 0x71009b23c0
u32 Unk_23c0960::vf15() {
    if (Unk_27d6bc0 != 0x279) {
        Unk_27d6bc0 = 0x279;
    }
    return 1;
}

// 0x71009b23e0
void Unk_23c0960::vf16() {
    Unk_9b23e0* self = reinterpret_cast<Unk_9b23e0*>(this);
    if (Unk_27d6bc0 != 0x27e) {
        Unk_27d6bc0 = 0x27e;
    }
    self->vf20();
}

// 0x71009b31b0
void Unk_23c0960::vf22() {
    Unk_9bbe20(field_608);
}

// 0x71009b32b0
u32 Unk_23c0960::vf27() {
    return 1;
}

// 0x71009b3330
void Unk_23c0960::vf29() {
    if (Unk_27d6bc0 != 0x367) {
        Unk_27d6bc0 = 0x367;
    }
}

// 0x71009b33e0
u32 Unk_23c0960::vf32() {
    if (Unk_27d6bc0 != 0x384) {
        Unk_27d6bc0 = 0x384;
    }
    return 1;
}

// 0x71009b34e0
void Unk_23c0960::vf37() {
    if (Unk_27d6bc0 != 0x3a3) {
        Unk_27d6bc0 = 0x3a3;
    }
}

// 0x71009b3500
void Unk_23c0960::vf38() {
    if (Unk_27d6bc0 != 0x3a4) {
        Unk_27d6bc0 = 0x3a4;
    }
}

// 0x71009b3520
u32 Unk_23c0960::vf39() {
    if (Unk_27d6bc0 != 0x3a6) {
        Unk_27d6bc0 = 0x3a6;
    }
    return 1;
}

// 0x71009b3a50
void Unk_23c0960::vf43() {
    if (Unk_27d6bc0 != 0x42e) {
        Unk_27d6bc0 = 0x42e;
    }
}

// 0x71009b3ca0
void Unk_23c0960::vf54() {
    if (Unk_27d6bc0 != 0x4e9) {
        Unk_27d6bc0 = 0x4e9;
    }
}

// 0x71009b3fb0
void Unk_23c0960::vf63() {
    const Unk_9b3fb0* self = reinterpret_cast<const Unk_9b3fb0*>(this);
    if (Unk_27d6bc0 != 0x592) {
        Unk_27d6bc0 = 0x592;
    }
    Unk_98a420_call(self->field_5c8);
}

// 0x71009b45d0
void Unk_23c0960::vf71(u64 value, u64 arg2, u64 arg3) {
    Unk_9b45d0* self = reinterpret_cast<Unk_9b45d0*>(this);
    if (Unk_27d6bc0 != 0x623) {
        Unk_27d6bc0 = 0x623;
    }
    self->vf67(value, arg2, arg3);
}

// 0x71009b4bf0
void Unk_23c0960::vf75() {
    if (Unk_27d6bc0 != 0x6c7) {
        Unk_27d6bc0 = 0x6c7;
    }
}

// 0x71009b4c10
u32 Unk_23c0960::vf76() {
    if (Unk_27d6bc0 != 0x6cc) {
        Unk_27d6bc0 = 0x6cc;
    }
    return 1;
}

// 0x71009b4c30
void Unk_23c0960::vf77() {
    if (Unk_27d6bc0 != 0x6d3) {
        Unk_27d6bc0 = 0x6d3;
    }
}

// 0x71009b4c50
u32 Unk_23c0960::vf78() {
    if (Unk_27d6bc0 != 0x6d9) {
        Unk_27d6bc0 = 0x6d9;
    }
    return 1;
}

// 0x71009b6520
void Unk_23c0960::vf106() {
    Unk_9b6520* self = reinterpret_cast<Unk_9b6520*>(this);
    if (Unk_27d6bc0 != 0x961) {
        Unk_27d6bc0 = 0x961;
    }
    u32 r0 = self->vf227();
    self->vf86(r0, 4);
}

// 0x71009b6580
void Unk_23c0960::vf107() {
    Unk_9b6580* self = reinterpret_cast<Unk_9b6580*>(this);
    if (Unk_27d6bc0 != 0x965) {
        Unk_27d6bc0 = 0x965;
    }
    self->vf87();
}

// 0x71009b65b0
void Unk_23c0960::vf108() {
    Unk_9b65b0* self = reinterpret_cast<Unk_9b65b0*>(this);
    if (Unk_27d6bc0 != 0x969) {
        Unk_27d6bc0 = 0x969;
    }
    u32 r0 = self->vf227();
    self->vf86(r0, 5);
}

// 0x71009b6610
void Unk_23c0960::vf109() {
    Unk_9b6610* self = reinterpret_cast<Unk_9b6610*>(this);
    if (Unk_27d6bc0 != 0x96d) {
        Unk_27d6bc0 = 0x96d;
    }
    self->vf87();
}

// 0x71009b7560
u32 Unk_23c0960::vf122() {
    if (Unk_27d6bc0 != 0xac9) {
        Unk_27d6bc0 = 0xac9;
    }
    return 0;
}

// 0x71009b76c0
void Unk_23c0960::vf130() {
    if (Unk_27d6bc0 != 0xb03) {
        Unk_27d6bc0 = 0xb03;
    }
}

// 0x71009b76e0
void Unk_23c0960::vf131() {
    if (Unk_27d6bc0 != 0xb0b) {
        Unk_27d6bc0 = 0xb0b;
    }
}

// 0x71009b7700
u32 Unk_23c0960::vf132() {
    return 1;
}

// 0x71009b7710
void Unk_23c0960::vf133() {
    if (Unk_27d6bc0 != 0xb16) {
        Unk_27d6bc0 = 0xb16;
    }
}

// 0x71009b7730
u32 Unk_23c0960::vf134() {
    return 1;
}

// 0x71009b7740
void Unk_23c0960::vf137() {
    if (Unk_27d6bc0 != 0xb1d) {
        Unk_27d6bc0 = 0xb1d;
    }
}

// 0x71009b7760
u32 Unk_23c0960::vf138() {
    if (Unk_27d6bc0 != 0xb21) {
        Unk_27d6bc0 = 0xb21;
    }
    return 1;
}

// 0x71009b7780
void Unk_23c0960::vf139() {
    if (Unk_27d6bc0 != 0xb26) {
        Unk_27d6bc0 = 0xb26;
    }
}

// 0x71009b77a0
u32 Unk_23c0960::vf140() {
    if (Unk_27d6bc0 != 0xb2a) {
        Unk_27d6bc0 = 0xb2a;
    }
    return 1;
}

// 0x71009b77c0
void Unk_23c0960::vf141() {
    if (Unk_27d6bc0 != 0xb31) {
        Unk_27d6bc0 = 0xb31;
    }
}

// 0x71009b77e0
u32 Unk_23c0960::vf142() {
    if (Unk_27d6bc0 != 0xb35) {
        Unk_27d6bc0 = 0xb35;
    }
    return 1;
}

// 0x71009b7800
void Unk_23c0960::vf143() {
    if (Unk_27d6bc0 != 0xb3c) {
        Unk_27d6bc0 = 0xb3c;
    }
}

// 0x71009b7820
u32 Unk_23c0960::vf144() {
    if (Unk_27d6bc0 != 0xb41) {
        Unk_27d6bc0 = 0xb41;
    }
    return 1;
}

// 0x71009b7840
void Unk_23c0960::vf145() {
    if (Unk_27d6bc0 != 0xb4a) {
        Unk_27d6bc0 = 0xb4a;
    }
}

// 0x71009b7860
u32 Unk_23c0960::vf146() {
    if (Unk_27d6bc0 != 0xb4f) {
        Unk_27d6bc0 = 0xb4f;
    }
    return 1;
}

// 0x71009b7910
void Unk_23c0960::vf149() {
    if (Unk_27d6bc0 != 0xb64) {
        Unk_27d6bc0 = 0xb64;
    }
}

// 0x71009b7930
u32 Unk_23c0960::vf150() {
    if (Unk_27d6bc0 != 0xb69) {
        Unk_27d6bc0 = 0xb69;
    }
    return 1;
}

// 0x71009b7950
void Unk_23c0960::vf151() {
    if (Unk_27d6bc0 != 0xb73) {
        Unk_27d6bc0 = 0xb73;
    }
}

// 0x71009b7970
u32 Unk_23c0960::vf152() {
    if (Unk_27d6bc0 != 0xb78) {
        Unk_27d6bc0 = 0xb78;
    }
    return 1;
}

// 0x71009b7990
void Unk_23c0960::vf153() {
    if (Unk_27d6bc0 != 0xb82) {
        Unk_27d6bc0 = 0xb82;
    }
}

// 0x71009b79b0
u32 Unk_23c0960::vf154() {
    return 0;
}

// 0x71009b79c0
void Unk_23c0960::vf155() {
    if (Unk_27d6bc0 != 0xb8b) {
        Unk_27d6bc0 = 0xb8b;
    }
}

// 0x71009b79e0
void Unk_23c0960::vf156() {
    if (Unk_27d6bc0 != 0xb8f) {
        Unk_27d6bc0 = 0xb8f;
    }
}

// 0x71009b7a00
void Unk_23c0960::vf157() {
    if (Unk_27d6bc0 != 0xb93) {
        Unk_27d6bc0 = 0xb93;
    }
}

// 0x71009b7a20
void Unk_23c0960::vf158() {
    if (Unk_27d6bc0 != 0xb98) {
        Unk_27d6bc0 = 0xb98;
    }
}

// 0x71009b7a40
void Unk_23c0960::vf159() {
    if (Unk_27d6bc0 != 0xb9f) {
        Unk_27d6bc0 = 0xb9f;
    }
}

// 0x71009b7bb0
void Unk_23c0960::vf161() {
    if (Unk_27d6bc0 != 0xbb1) {
        Unk_27d6bc0 = 0xbb1;
    }
}

// 0x71009b7c40
u32 Unk_23c0960::vf164() {
    if (Unk_27d6bc0 != 0xbc8) {
        Unk_27d6bc0 = 0xbc8;
    }
    return 0;
}

// 0x71009b7c60
void Unk_23c0960::vf165() {
    if (Unk_27d6bc0 != 0xbcd) {
        Unk_27d6bc0 = 0xbcd;
    }
}

// 0x71009b7c80
void Unk_23c0960::vf166() {
    if (Unk_27d6bc0 != 0xbd1) {
        Unk_27d6bc0 = 0xbd1;
    }
}

// 0x71009b7ca0
u32 Unk_23c0960::vf167() {
    if (Unk_27d6bc0 != 0xbd4) {
        Unk_27d6bc0 = 0xbd4;
    }
    return 1;
}

// 0x71009b8180
void Unk_23c0960::vf176() {
    if (Unk_27d6bc0 != 0xc96) {
        Unk_27d6bc0 = 0xc96;
    }
}

// 0x71009b81a0
u32 Unk_23c0960::vf177() {
    if (Unk_27d6bc0 != 0xc9b) {
        Unk_27d6bc0 = 0xc9b;
    }
    return 1;
}

// 0x71009b8200
void Unk_23c0960::vf179() {
    Unk_9b8200* self = reinterpret_cast<Unk_9b8200*>(this);
    if (Unk_27d6bc0 != 0xcb4) {
        Unk_27d6bc0 = 0xcb4;
    }
    self->vf85();
}

// 0x71009b8290
void Unk_23c0960::vf181() {
    Unk_9b8290* self = reinterpret_cast<Unk_9b8290*>(this);
    if (Unk_27d6bc0 != 0xcc8) {
        Unk_27d6bc0 = 0xcc8;
    }
    self->vf85();
}

// 0x71009b82c0
void Unk_23c0960::vf182() {
    Unk_9b82c0* self = reinterpret_cast<Unk_9b82c0*>(this);
    if (Unk_27d6bc0 != 0xcd0) {
        Unk_27d6bc0 = 0xcd0;
    }
    self->field_16f4 = 0;
}

// 0x71009b8400
void Unk_23c0960::vf184() {
    if (Unk_27d6bc0 != 0xced) {
        Unk_27d6bc0 = 0xced;
    }
}

// 0x71009b8420
void Unk_23c0960::vf185() {
    if (Unk_27d6bc0 != 0xcf1) {
        Unk_27d6bc0 = 0xcf1;
    }
}

// 0x71009b8440
u32 Unk_23c0960::vf186() {
    if (Unk_27d6bc0 != 0xcf5) {
        Unk_27d6bc0 = 0xcf5;
    }
    return 1;
}

// 0x71009b84c0
void Unk_23c0960::vf194() {}

// 0x71009b84d0
u32 Unk_23c0960::vf195() {
    return 1;
}

// 0x71009b35d0
void Unk_23c0960::vf209() {
    Unk_98a4b0(field_5c8);
}

// 0x71009b35e0
void Unk_23c0960::vf210() {
    Unk_98a4e0(field_5c8);
}

// 0x71009b35f0
void Unk_23c0960::vf211() {
    Unk_98a510(field_5c8);
}
