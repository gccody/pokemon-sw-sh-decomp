// Scope: common
// The object of 0x71008a8880's shape that does the work (vtable
// 0x71023b9028, its destructors only): three of the battle's modules, a
// reference to the battle logic's view, a state, a flag that says it's done
// and a message it builds. Its update steps through the states, sending the
// view the messages and waiting on it; the state's reset and the flag's
// getter are in src/unsorted/leaf/Unk_8a8bb0.cpp. Placeholder names: rename
// once the classes are known.
#include "battle/battle_logic/source/netwatch/Unk_8a8880.h"

// A message being built: its id, then up to eight arguments, counted in the
// high nibble of the byte at +3 (Unk_8aabb0 starts one, Unk_8aabe0 adds an
// argument).
struct Unk_8aabb0_Message {
    u16 field_0;
    u8 field_2;
    u8 field_3;
    u32 field_4[8];
};
PKMN_SIZE_ASSERT(Unk_8aabb0_Message, 0x24);
void Unk_8aabb0(void* self, u32 arg1, u32 id);
void Unk_8aabe0(void* self, u32 value);

// The battle logic's view of the battle (vtable 0x71023b9058), declared in
// src/battle/battle_logic/source/netwatch/Unk_8a8e30.h too: its slots up to
// 191, with the signatures the update shows.
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
    virtual void vf55(const Unk_8aabb0_Message* message);
    virtual void vf56();
    virtual void vf57();
    virtual void vf58();
    virtual void vf59();
    virtual u32 vf60();
    virtual bool vf61();
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
    virtual bool vf146();
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
};

// What the update calls: the main module's (0x71007c5700, not decompiled
// yet), the client's message builder (src/unsorted/leaf/Unk_7ce130.cpp), the
// party's and the battle Pokemon's (src/battle/battle_engine).
struct Unk_7d90d0;
struct Unk_7ecc90_Con;
struct Unk_7ee6b0;
struct Unk_7f0b70;
u32 Unk_7c5700(const void* main);
void Unk_7d90d0_call(const Unk_7d90d0* self, void* value, u32 arg2);
Unk_7ee6b0* Unk_7ed5e0(Unk_7ecc90_Con* self, u8 position);
bool Unk_7ef2b0_call(void* self);
bool Unk_7f0b70_check(const Unk_7f0b70* self);
u8 Unk_804810(u32 index);

// What the object is given.
struct Unk_23b9028_Args {
    const void* field_0;
    const Unk_7d90d0* field_8;
    Unk_7ecc90_Con* field_10;
    Unk_8a8880_Ref<Unk_23b9048> field_18;
};
PKMN_SIZE_ASSERT(Unk_23b9028_Args, 0x20);

class Unk_23b9028 {
public:
    Unk_23b9028();
    virtual ~Unk_23b9028();

    void Unk_8a8b40(const Unk_23b9028_Args& args);
    void Unk_8a8bd0();

    const void* field_8;
    const Unk_7d90d0* field_10;
    Unk_7ecc90_Con* field_18;
    Unk_8a8880_Ref<Unk_23b9048> field_20;
    u32 field_28;
    bool field_2c;
    Unk_8aabb0_Message field_30;
};
PKMN_SIZE_ASSERT(Unk_23b9028, 0x58);
PKMN_OFFSET_ASSERT(Unk_23b9028, field_20, 0x20);
PKMN_OFFSET_ASSERT(Unk_23b9028, field_28, 0x28);
PKMN_OFFSET_ASSERT(Unk_23b9028, field_2c, 0x2c);
PKMN_OFFSET_ASSERT(Unk_23b9028, field_30, 0x30);

// 0x71008a8a70
Unk_23b9028::Unk_23b9028()
    : field_8(nullptr),
      field_10(nullptr),
      field_18(nullptr),
      field_28(0),
      field_2c(false),
      field_30() {}

// 0x71008a8aa0
Unk_23b9028::~Unk_23b9028() {}

// 0x71008a8b40
void Unk_23b9028::Unk_8a8b40(const Unk_23b9028_Args& args) {
    field_8 = args.field_0;
    field_10 = args.field_8;
    field_18 = args.field_10;
    field_20 = args.field_18;
}

// 0x71008a8bd0: a Pokemon that can't (none at position 0, or one the two
// checks rule out) skips state 3. The original's state 3 shares its last
// store with that skip.
void Unk_23b9028::Unk_8a8bd0() {
    if (field_2c)
        return;
    switch (field_28) {
        case 0: {
            u32 value = Unk_7c5700(field_8);
            if (value != 0) {
                Unk_7d90d0_call(field_10, &field_30, value);
                field_20->vf55(&field_30);
            }
            field_28 = 1;
        }
        // fallthrough
        case 1:
            if (field_20->vf61())
                field_28 = 6;
            break;
        case 2: {
            field_20->vf191();
            Unk_7ee6b0* poke = Unk_7ed5e0(field_18, 0);
            if (poke == nullptr || Unk_7ef2b0_call(poke) ||
                Unk_7f0b70_check(reinterpret_cast<const Unk_7f0b70*>(poke)))
                goto skip;
            field_20->vf145();
            field_28 = 3;
            break;
        }
        case 3:
            if (!field_20->vf146())
                break;
        skip:
            field_28 = 4;
            break;
        case 4: {
            u8 value = Unk_804810(1);
            Unk_8aabb0(&field_30, 1, 0x3e);
            Unk_8aabe0(&field_30, value);
            field_20->vf55(&field_30);
            field_28 = 5;
        }
        // fallthrough
        case 5:
            if (field_20->vf61())
                field_28 = 6;
            break;
        default:
            field_2c = true;
            break;
    }
}
