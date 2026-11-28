// Scope: common
// A small object of the battle logic (vtable 0x71023b9018, its destructors
// only): three pointers and a reference it's given, a state and a flag that
// says it's done. Its leaf functions (the state's reset, the flag's getter
// and its update, which only finishes) are in src/unsorted/leaf/Unk_8a89b0.cpp.
// Unk_8a8a70.cpp has an object of the same shape that does the work.
// Placeholder names: rename once the classes are known.
#include "battle/battle_logic/source/netwatch/Unk_8a8880.h"

// What the object is given.
struct Unk_23b9008_Args {
    void* field_0;
    void* field_8;
    void* field_10;
    Unk_8a8880_Ref<Unk_239a4c0> field_18;
};
PKMN_SIZE_ASSERT(Unk_23b9008_Args, 0x20);

class Unk_23b9008 {
public:
    Unk_23b9008();
    virtual ~Unk_23b9008();

    void Unk_8a8940(const Unk_23b9008_Args& args);

    void* field_8;
    void* field_10;
    void* field_18;
    Unk_8a8880_Ref<Unk_239a4c0> field_20;
    u32 field_28;
    bool field_2c;
};
PKMN_SIZE_ASSERT(Unk_23b9008, 0x30);
PKMN_OFFSET_ASSERT(Unk_23b9008, field_20, 0x20);
PKMN_OFFSET_ASSERT(Unk_23b9008, field_28, 0x28);
PKMN_OFFSET_ASSERT(Unk_23b9008, field_2c, 0x2c);

// 0x71008a8880
Unk_23b9008::Unk_23b9008()
    : field_8(nullptr), field_10(nullptr), field_18(nullptr), field_28(0), field_2c(false) {}

// 0x71008a88a0
Unk_23b9008::~Unk_23b9008() {}

// 0x71008a8940
void Unk_23b9008::Unk_8a8940(const Unk_23b9008_Args& args) {
    field_8 = args.field_0;
    field_10 = args.field_8;
    field_18 = args.field_10;
    field_20 = args.field_18;
}
