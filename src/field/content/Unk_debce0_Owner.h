#pragma once
// What HaxeSymbolPokemonObject::field_0 points to: the symbol-encounter Pokemon the
// script object wraps. Its parameters are read at 0x930-0xa34, two offsets kept in
// NEON registers at 0xa40/0xa50 and the spawner's areas at 0xa70. Only the members the
// getters at 0x7100debce0-0x7100dec030 read; placeholder names until the class is known.
#include <arm_neon.h>

#include <types.h>

// The spawner's areas, copied by value into Unk_c8dd50: a 0x20-byte header, then four
// 0x20-byte areas Unk_c8dd50 picks by index (create, vanish, ...), aborting past 4.
struct Unk_debce0_Areas {
    u8 _0[0xa0];
};
PKMN_SIZE_ASSERT(Unk_debce0_Areas, 0xa0);

// 0x7100c8dd50
bool Unk_c8dd50(Unk_debce0_Areas areas, const float32x4_t& pos, int index, float margin);

struct Unk_debce0_Owner {
    // 0x7100d0b900
    bool Unk_d0b900() const;

    u8 _0[0x930];
    int field_930;
    u8 field_934;
    u8 field_935;
    u8 _936[0x948 - 0x936];
    float field_948;
    float field_94c;
    float field_950;
    float field_954;
    float field_958;
    float field_95c;
    int field_960;
    int field_964;
    u8 _968[0x978 - 0x968];
    float field_978;
    float field_97c;
    float field_980;
    u8 field_984;
    u8 _985[0x994 - 0x985];
    float field_994;
    float field_998;
    float field_99c;
    float field_9a0;
    float field_9a4;
    float field_9a8;
    float field_9ac;
    u8 _9b0[0xa30 - 0x9b0];
    float field_a30;
    float field_a34;
    u8 _a38[0xa40 - 0xa38];
    float32x4_t field_a40;
    float32x4_t field_a50;
    u8 _a60[0xa70 - 0xa60];
    Unk_debce0_Areas field_a70;
};
PKMN_OFFSET_ASSERT(Unk_debce0_Owner, field_930, 0x930);
PKMN_OFFSET_ASSERT(Unk_debce0_Owner, field_934, 0x934);
PKMN_OFFSET_ASSERT(Unk_debce0_Owner, field_935, 0x935);
PKMN_OFFSET_ASSERT(Unk_debce0_Owner, field_948, 0x948);
PKMN_OFFSET_ASSERT(Unk_debce0_Owner, field_95c, 0x95c);
PKMN_OFFSET_ASSERT(Unk_debce0_Owner, field_960, 0x960);
PKMN_OFFSET_ASSERT(Unk_debce0_Owner, field_964, 0x964);
PKMN_OFFSET_ASSERT(Unk_debce0_Owner, field_978, 0x978);
PKMN_OFFSET_ASSERT(Unk_debce0_Owner, field_984, 0x984);
PKMN_OFFSET_ASSERT(Unk_debce0_Owner, field_994, 0x994);
PKMN_OFFSET_ASSERT(Unk_debce0_Owner, field_9ac, 0x9ac);
PKMN_OFFSET_ASSERT(Unk_debce0_Owner, field_a30, 0xa30);
PKMN_OFFSET_ASSERT(Unk_debce0_Owner, field_a34, 0xa34);
PKMN_OFFSET_ASSERT(Unk_debce0_Owner, field_a40, 0xa40);
PKMN_OFFSET_ASSERT(Unk_debce0_Owner, field_a50, 0xa50);
PKMN_OFFSET_ASSERT(Unk_debce0_Owner, field_a70, 0xa70);
