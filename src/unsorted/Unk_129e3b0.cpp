// Scope: common
// The job table's fields, by job index: Unk_1298270_Jobs's accessors of its
// data document (src/unsorted/Unk_1106320.h).
#include "unsorted/Unk_1298270.h"

#include <stdio.h>

// 0x710129e3b0
s32 Unk_1298270_Jobs::Unk_129e3b0(s32 index) {
    Unk_1106320_Node job = field_120.Unk_1106320(index);
    return job.Unk_11063e0("required_job").Unk_11065b0(0);
}

// 0x710129e420
s32 Unk_1298270_Jobs::Unk_129e420(s32 index) {
    Unk_1106320_Node job = field_120.Unk_1106320(index);
    return job.Unk_11063e0("group_id").Unk_11065b0(0);
}

// 0x710129e610
s32 Unk_1298270_Jobs::Unk_129e610(s32 index) {
    Unk_1106320_Node job = field_120.Unk_1106320(index);
    return job.Unk_11063e0("recruit_count").Unk_11065b0(0);
}

// 0x710129e800
s32 Unk_1298270_Jobs::Unk_129e800(s32 index) {
    Unk_1106320_Node job = field_120.Unk_1106320(index);
    return job.Unk_11063e0("related_job").Unk_11065b0(0);
}

// 0x710129e870
u32 Unk_1298270_Jobs::Unk_129e870(s32 index) {
    Unk_1106320_Node job = field_120.Unk_1106320(index);
    return job.Unk_11063e0("effort_type").Unk_11065b0(0) != 0;
}

// 0x710129e9b0
s32 Unk_1298270_Jobs::Unk_129e9b0(s32 index) {
    Unk_1106320_Node job = field_120.Unk_1106320(index);
    return job.Unk_11063e0("exp_grade").Unk_11065b0(0);
}

// 0x710129ea20
s32 Unk_1298270_Jobs::Unk_129ea20(s32 index) {
    Unk_1106320_Node job = field_120.Unk_1106320(index);
    return job.Unk_11063e0("effort_type").Unk_11065b0(0) - 1;
}

// 0x710129ea90
s32 Unk_1298270_Jobs::Unk_129ea90(s32 index) {
    Unk_1106320_Node job = field_120.Unk_1106320(index);
    return job.Unk_11063e0("effort_value").Unk_11065b0(0);
}

// 0x710129eb00
u32 Unk_1298270_Jobs::Unk_129eb00(s32 index) {
    Unk_1106320_Node job = field_120.Unk_1106320(index);
    return job.Unk_11063e0("effort_up").Unk_11065b0(0) == 1;
}

// 0x710129eb80
f32 Unk_1298270_Jobs::Unk_129eb80(s32 index) {
    Unk_1106320_Node job = field_120.Unk_1106320(index);
    return job.Unk_11063e0("exp_bonus_factor").Unk_11067c0(0.0f);
}

// 0x710129ee70
s32 Unk_1298270_Jobs::Unk_129ee70(s32 index) {
    Unk_1106320_Node job = field_120.Unk_1106320(index);
    return job.Unk_11063e0("reward_rank").Unk_11065b0(0);
}

// 0x710129e490
Unk_11069b0_String Unk_1298270_Jobs::Unk_129e490(s32 index) {
    Unk_1106320_Node job = field_120.Unk_1106320(index);
    return job.Unk_11063e0("description_txt").Unk_11069b0("");
}

// 0x710129e550
Unk_11069b0_String Unk_1298270_Jobs::Unk_129e550(s32 index) {
    Unk_1106320_Node job = field_120.Unk_1106320(index);
    return job.Unk_11063e0("title_txt").Unk_11069b0("");
}

// 0x710129e680
Unk_11069b0_String Unk_1298270_Jobs::Unk_129e680(s32 index) {
    Unk_1106320_Node job = field_120.Unk_1106320(index);
    return job.Unk_11063e0("company_txt").Unk_11069b0("");
}

// 0x710129e740
Unk_11069b0_String Unk_1298270_Jobs::Unk_129e740(s32 index) {
    Unk_1106320_Node job = field_120.Unk_1106320(index);
    return job.Unk_11063e0("company_icon").Unk_11069b0("");
}

// 0x710129ed90
u64 Unk_1298270_Jobs::Unk_129ed90(s32 index) {
    return Unk_129ed90_Flag(index).hash;
}

// 0x710129e8f0
s32 Unk_1298270_Jobs::Unk_129e8f0(s32 index, s32 hours) {
    Unk_1106320_Node job = field_120.Unk_1106320(index);
    char name[10];
    snprintf(name, sizeof(name), "exp_%dh", hours);
    return job.Unk_11063e0(name).Unk_11065b0(0);
}

// 0x710129ecd0
u8 Unk_1298270_Jobs::Unk_129ecd0(s32 index, s32 slot) {
    Unk_1106320_Node job = field_120.Unk_1106320(index);
    char name[10];
    snprintf(name, sizeof(name), "type%d", slot + 1);
    u8 type = job.Unk_11063e0(name).Unk_11065b0(0);
    if (type == 0)
        return 18;
    return type - 1;
}

// 0x710129ebf0
f32 Unk_1298270_Jobs::Unk_129ebf0(s32 index, s32 kind) {
    Unk_1106320_Node job = field_120.Unk_1106320(index);
    switch (kind) {
        case 0:
            return job.Unk_11063e0("exp_bonus_factor_0").Unk_11067c0(0.0f);
        case 1:
            return job.Unk_11063e0("exp_bonus_factor_1").Unk_11067c0(0.0f);
        case 2:
            return job.Unk_11063e0("exp_bonus_factor_2").Unk_11067c0(0.0f);
    }
    return 0.0f;
}

// 0x710129f550
s32 Unk_1298270_Jobs::Unk_129f550() {
    Unk_1106320_Node initial = field_110.Unk_11063e0("initialJob");
    return initial.Unk_11063e0("value").Unk_11065b0(0);
}

// 0x710129f310: the level of `count` successes (the last of the 5 levels
// whose required count it reaches) gives the count of jobs unlocked.
s32 Unk_1298270_Jobs::Unk_129f310(u32 count) {
    Unk_1106320_Node counts = field_110.Unk_11063e0("jobCounts");
    for (s32 i = 0; i < 5; i++) {
        if (counts.Unk_1106320(i).Unk_11063e0("required_success").Unk_11065b0(0) > count) {
            if (i == 0)
                return 0;
            return counts.Unk_1106320(i - 1).Unk_11063e0("unlock_count").Unk_11065b0(0);
        }
    }
    return counts.Unk_1106320(4).Unk_11063e0("unlock_count").Unk_11065b0(0);
}
