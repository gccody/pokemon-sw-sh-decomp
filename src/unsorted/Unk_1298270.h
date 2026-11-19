#pragma once
// The Poke Job app's list of jobs (game/pw): the job table (a data document)
// and a sorted list of up to 167 job ids. Placeholder names: rename once the
// classes are known.
#include <types.h>

#include "gflib3/Unk_239a418.h"
#include "unsorted/Unk_1106320.h"

// An entry of the table: its state and a flag.
struct Unk_13736e0_Entry {
    u8 field_0;
    u8 _1[0x18];
    bool field_19;
    u8 _1a[0x16];
};
PKMN_OFFSET_ASSERT(Unk_13736e0_Entry, field_19, 0x19);
PKMN_SIZE_ASSERT(Unk_13736e0_Entry, 0x30);

// The table's owner (its entries start at +0x60).
class Unk_13736e0_Owner : public Unk_239a418 {};

// 0x71013736e0: the entry of an id.
const Unk_13736e0_Entry* Unk_13736e0(Unk_13736e0_Owner* self, s32 id);

struct Unk_24ba4e0_Type {
    u8 _0[0x268];
    Unk_239a418_Ref<Unk_13736e0_Owner> field_268;
};
PKMN_OFFSET_ASSERT(Unk_24ba4e0_Type, field_268, 0x268);

extern Unk_24ba4e0_Type* Unk_24ba4e0;

class Unk_1298270_Jobs {
public:
    // 0x7101298270
    void Unk_1298270(bool sort);

    // The job table's fields, by index (src/unsorted/Unk_129e3b0.cpp).
    s32 Unk_129e3b0(s32 index);                 // required_job
    s32 Unk_129e420(s32 index);                 // group_id
    s32 Unk_129e610(s32 index);                 // recruit_count
    s32 Unk_129e800(s32 index);                 // related_job
    u32 Unk_129e870(s32 index);                 // effort_type
    s32 Unk_129e9b0(s32 index);                 // exp_grade
    s32 Unk_129ea20(s32 index);                 // effort_type
    s32 Unk_129ea90(s32 index);                 // effort_value
    u32 Unk_129eb00(s32 index);                 // effort_up
    f32 Unk_129eb80(s32 index);                 // exp_bonus_factor
    s32 Unk_129ee70(s32 index);                 // reward_rank
    Unk_11069b0_String Unk_129e490(s32 index);  // description_txt
    Unk_11069b0_String Unk_129e550(s32 index);  // title_txt
    Unk_11069b0_String Unk_129e680(s32 index);  // company_txt
    Unk_11069b0_String Unk_129e740(s32 index);  // company_icon
    u64 Unk_129ed90(s32 index);                 // unlock_flag's hash
    s32 Unk_129e8f0(s32 index, s32 hours);      // exp_%dh
    u8 Unk_129ecd0(s32 index, s32 slot);        // type%d, from 1
    f32 Unk_129ebf0(s32 index, s32 kind);       // exp_bonus_factor_0..2
    s32 Unk_129f550();                          // initialJob's value
    s32 Unk_129f310(u32 count);                 // jobCounts
    Unk_11069b0_String Unk_129ed90_Flag(s32 index) {
        Unk_1106320_Node job = field_120.Unk_1106320(index);
        return job.Unk_11063e0("unlock_flag").Unk_11069b0("");
    }

    // The order of the list: higher priorities first, ids of the same
    // priority in increasing order.
    u32 Priority(s32 id) {
        Unk_239a418_Ref<Unk_13736e0_Owner> owner = Unk_24ba4e0->field_268;
        const Unk_13736e0_Entry* entry = Unk_13736e0(owner.m_ptr, id);
        u32 priority;
        if (Unk_129e870(id)) {
            if (entry->field_0 == 3)
                priority = entry->field_19 ? 8 : 10;
            else if (entry->field_0 == 1)
                priority = entry->field_19 ? 6 : 2;
            else
                priority = entry->field_19 ? 4 : 0;
        } else {
            if (entry->field_0 == 3)
                priority = entry->field_19 ? 9 : 11;
            else if (entry->field_0 == 1)
                priority = entry->field_19 ? 7 : 3;
            else
                priority = entry->field_19 ? 5 : 1;
        }
        return priority;
    }

    u8 _0[0x110];
    Unk_1106320_Node field_110;
    Unk_1106320_Node field_120;  // the job table
    u8 _130[0x10];
    s32 field_140[167];
    s32 field_3dc;
};
PKMN_OFFSET_ASSERT(Unk_1298270_Jobs, field_110, 0x110);
PKMN_OFFSET_ASSERT(Unk_1298270_Jobs, field_120, 0x120);
PKMN_OFFSET_ASSERT(Unk_1298270_Jobs, field_140, 0x140);
PKMN_OFFSET_ASSERT(Unk_1298270_Jobs, field_3dc, 0x3dc);
