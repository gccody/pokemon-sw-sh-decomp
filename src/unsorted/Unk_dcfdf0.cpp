// Scope: common
// The balloon minigame's parameters (BALLOON_RADIUS, CHECKPOINT_RADIUS, the
// SCORE_* factors, ...): each is read from a data document by name and keeps
// its value when the document doesn't have it. Placeholder names.
#include <types.h>

#include "unsorted/Unk_1106320.h"

// 0x7101106f30 (Shield: 0x7101106f60): the root of a document's data
Unk_1106320_Node Unk_1106f30(const void* data, size_t size);

struct Unk_dcfdf0_Params {
    f32 field_0;
    f32 field_4;
    f32 field_8;
    f32 field_c;
    f32 field_10;
    f32 field_14;
    f32 field_18;
    s32 field_1c;
    s32 field_20;
    s32 field_24;
    s32 field_28;
    s32 field_2c;
    f32 field_30;
    f32 field_34;
    f32 field_38;
    s32 field_3c;
    f32 field_40;
    s32 field_44;
    s32 field_48;
    s32 field_4c;
    s32 field_50;
    s32 field_54;
    s32 field_58;
    s32 field_5c;
    s32 field_60;
    f32 field_64;
    s32 field_68;
    s32 field_6c;
    s32 field_70;
    s32 field_74;
    f32 field_78;
    f32 field_7c;
    f32 field_80;
    f32 field_84;
    s32 field_88;
    f32 field_8c;
    f32 field_90;
    f32 field_94;
    f32 field_98;
    f32 field_9c;
    f32 field_a0;
    f32 field_a4;
    f32 field_a8;
    f32 field_ac;
    f32 field_b0;
};

// 0x7100dcfdf0
void Unk_dcfdf0(Unk_dcfdf0_Params* self, const void* data, u32 size) {
    Unk_1106320_Node root = Unk_1106f30(data, size);
    self->field_0 = root.Unk_11063e0("BALLOON_RADIUS").Unk_11067c0(self->field_0);
    self->field_4 = root.Unk_11063e0("CHECKPOINT_RADIUS").Unk_11067c0(self->field_4);
    self->field_8 = root.Unk_11063e0("TIME_BONUS").Unk_11067c0(self->field_8);
    self->field_c = root.Unk_11063e0("BALLOON_EFFECT_SCALE").Unk_11067c0(self->field_c);
    self->field_10 = root.Unk_11063e0("BALLOON_MODEL_SCALE").Unk_11067c0(self->field_10);
    self->field_14 = root.Unk_11063e0("CHECKPOINT_EFFECT_SCALE").Unk_11067c0(self->field_14);
    self->field_18 = root.Unk_11063e0("CHECKPOINT_MODEL_SCALE").Unk_11067c0(self->field_18);
    self->field_1c = root.Unk_11063e0("BALLOON_CLOSE_FRAMES").Unk_11065b0(self->field_1c);
    self->field_20 = root.Unk_11063e0("DASH_FRAMES").Unk_11065b0(self->field_20);
    self->field_40 = root.Unk_11063e0("DASH_ACC").Unk_11067c0(self->field_40);
    self->field_24 = root.Unk_11063e0("SPIN_RECOVERY_FRAMES").Unk_11065b0(self->field_24);
    self->field_28 = root.Unk_11063e0("SPIN_FRAMES").Unk_11065b0(self->field_28);
    self->field_2c = root.Unk_11063e0("SPIN_COUNT").Unk_11065b0(self->field_2c);
    self->field_30 = root.Unk_11063e0("SPIN_TURN_STEP").Unk_11067c0(self->field_30);
    self->field_34 = root.Unk_11063e0("SPIN_REVERT_MOVE_STEP").Unk_11067c0(self->field_34);
    self->field_38 = root.Unk_11063e0("SPIN_REVERT_TURN_STEP").Unk_11067c0(self->field_38);
    self->field_3c = root.Unk_11063e0("SPIN_TO_FREEMOVE_FRAMES").Unk_11065b0(self->field_3c);
    self->field_44 = root.Unk_11063e0("BLACK_WAIT_FRAMES").Unk_11065b0(self->field_44);
    self->field_48 = root.Unk_11063e0("GOAL_WAIT_FRAMES").Unk_11065b0(self->field_48);
    self->field_58 = root.Unk_11063e0("GOAL_FADE_FRAMES").Unk_11065b0(self->field_58);
    self->field_4c = root.Unk_11063e0("START_FADE_FRAMES").Unk_11065b0(self->field_4c);
    self->field_50 = root.Unk_11063e0("RETIRE_FADE_FRAMES").Unk_11065b0(self->field_50);
    self->field_54 = root.Unk_11063e0("REVERT_FADE_FRAMES").Unk_11065b0(self->field_54);
    self->field_5c = root.Unk_11063e0("BALLOON_OPENING_INTERVAL").Unk_11065b0(self->field_5c);
    self->field_60 = root.Unk_11063e0("INVINSIBLE_FRAMES").Unk_11065b0(self->field_60);
    self->field_64 = root.Unk_11063e0("INVINSIBLE_SPEED_THRESHOLD").Unk_11067c0(self->field_64);
    self->field_68 = root.Unk_11063e0("START_DASH_ACCEPT_FRAMES").Unk_11065b0(self->field_68);
    self->field_6c = root.Unk_11063e0("START_DASH_FRAMES").Unk_11065b0(self->field_6c);
    self->field_70 = root.Unk_11063e0("REVERSAL_DASH_ACCEPT_FRAMES").Unk_11065b0(self->field_70);
    self->field_74 = root.Unk_11063e0("REVERSAL_DASH_FRAMES").Unk_11065b0(self->field_74);
    self->field_78 = root.Unk_11063e0("DEFAULT_CHARGE_DELTA").Unk_11067c0(self->field_78);
    self->field_7c = root.Unk_11063e0("AGAKI_CHARGE_FACTOR").Unk_11067c0(self->field_7c);
    self->field_80 = root.Unk_11063e0("CHARGE_INC").Unk_11067c0(self->field_80);
    self->field_84 = root.Unk_11063e0("SELFSPIN_DELTA_DEGREE").Unk_11067c0(self->field_84);
    self->field_88 = root.Unk_11063e0("SELFSPIN_ACCEPT_FRAMES").Unk_11065b0(self->field_88);
    self->field_88 = root.Unk_11063e0("SELFSPIN_ACCEPT_FRAMES").Unk_11065b0(self->field_88);
    self->field_8c = root.Unk_11063e0("ALERT_TIME").Unk_11067c0(self->field_8c);
    self->field_90 = root.Unk_11063e0("RANK_TH_EASY").Unk_11067c0(self->field_90);
    self->field_94 = root.Unk_11063e0("RANK_TH_NORMAL").Unk_11067c0(self->field_94);
    self->field_98 = root.Unk_11063e0("RANK_TH_HARD").Unk_11067c0(self->field_98);
    self->field_9c = root.Unk_11063e0("WATT_SCORE_FACT").Unk_11067c0(self->field_9c);
    self->field_a0 = root.Unk_11063e0("WATT_BALLOON_FACT").Unk_11067c0(self->field_a0);
    self->field_a4 = root.Unk_11063e0("WATT_CHECKPOINT_FACT").Unk_11067c0(self->field_a4);
    self->field_a8 = root.Unk_11063e0("SCORE_WEIGHT_FACT").Unk_11067c0(self->field_a8);
    self->field_ac = root.Unk_11063e0("SCORE_WRIGHT_ADD").Unk_11067c0(self->field_ac);
    self->field_b0 = root.Unk_11063e0("SCORE_TIME_FACT").Unk_11067c0(self->field_b0);
}
