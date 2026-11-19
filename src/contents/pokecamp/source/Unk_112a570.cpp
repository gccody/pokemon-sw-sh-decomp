// Scope: common
// Three tables of Pokemon Camp's sounds (`@Play_Camp_*`, `@Play_UI_Emotional_*`)
// and the voices (`PMxxx_yy`) and motions (`kw*`, `ba*`) that go with them,
// each an unordered_map keyed by the sound's hash. The three functions that fill
// them register a different set each.
#include "contents/pokecamp/source/Unk_112a570.h"

// 0x7101129ca0
void Unk_1129ca0(Unk_112d870* self, const Unk_112d870_Key& key, const Unk_112dd40& voice) {
    self->field_178.emplace(key.hash, voice);
}

// 0x7101129f60
void Unk_1129f60(Unk_112d870* self, const Unk_112d870_Key& key, const Unk_112dd40& voice) {
    self->field_1d0.emplace(key.hash, voice);
}

// 0x710112a220
void Unk_112a220(Unk_112d870* self,
                 const Unk_112d870_Key& key,
                 const Unk_112dd40& voice,
                 std::initializer_list<Unk_112dd40> motions) {
    Unk_112e110 value(voice);
    int i = 0;
    for (const Unk_112dd40& motion : motions)
        value.motions[i++].value = motion.hash;
    self->field_228.emplace(key.hash, value);
}

// 0x710112a570
void Unk_112a570(Unk_112d870* self) {
    Unk_1129f60(self, "@Play_Camp_Eat_start", "PM025_12");
    Unk_1129f60(self, "@Play_Camp_Eat_reaction_01", "PM025_13");
    Unk_1129f60(self, "@Play_Camp_Eat_reaction_02", "PM025_14");
    Unk_1129f60(self, "@Play_Camp_Eat_reaction_03", "PM025_15");
    Unk_1129f60(self, "@Play_Camp_Eat_reaction_04", "PM025_16");
    Unk_1129f60(self, "@Play_Camp_Eat_reaction_05", "PM025_17");
    Unk_1129f60(self, "@Play_Camp_Eat_loop_slow", "PM025_18");
    Unk_1129f60(self, "@Play_Camp_Eat_loop_normal", "PM025_19");
    Unk_1129f60(self, "@Play_Camp_Eat_loop_fast", "PM025_20");
    Unk_1129ca0(self, "kw11_turnA01", "PM025_21");
    Unk_1129ca0(self, "kw11_turnB01", "PM025_22");
    Unk_1129ca0(self, "kw20_drowseA01", "PM025_23");
    Unk_1129ca0(self, "kw20_drowseC01", "PM025_24");
    Unk_1129ca0(self, "kw21_sleepB01", "PM025_26");
    Unk_1129ca0(self, "kw30_hate01", "PM025_27");
    Unk_1129ca0(self, "kw31_question01", "PM025_28");
    Unk_1129ca0(self, "kw32_happyA01", "PM025_29");
    Unk_1129ca0(self, "kw32_happyB01", "PM025_30");
    Unk_1129ca0(self, "kw32_happyC01", "PM025_31");
    Unk_1129ca0(self, "kw33_moveA01", "PM025_32");
    Unk_1129ca0(self, "kw33_moveB01", "PM025_33");
    Unk_1129ca0(self, "kw33_moveC01", "PM025_34");
    Unk_1129ca0(self, "kw34_lonely01", "PM025_35");
    Unk_1129ca0(self, "kw35_playA01", "PM025_36");
    Unk_1129ca0(self, "kw35_playB01", "PM025_37");
    Unk_1129ca0(self, "kw36_mad01", "PM025_38");
    Unk_1129ca0(self, "ba02_roar01", "PM025_39");
    Unk_1129ca0(self, "kw60_touch01", "PM025_44");
    Unk_1129f60(self, "@Play_Camp_Sleep", "PM025_25");
    Unk_1129f60(self, "@Play_Camp_Zoom_Appear", "PM025_40");
    Unk_1129f60(self, "Play_UI_Emotional_Hungry", "PM025_41");
    Unk_1129f60(self, "itching", "PM025_42");
    Unk_1129f60(self, "Play_Camp_PlayingHit", "");
    Unk_1129f60(self, "Play_Camp_Throw_Ball", "");
    Unk_1129f60(self, "@Play_Camp_Battle", "PM025_46");
    Unk_1129f60(self, "@Play_Camp_Race", "PM025_91");
    Unk_1129f60(self, "@Play_Camp_RandomLook", "PM025_48");
    Unk_1129f60(self, "Play_UI_Emotional_Confuse", "PM025_49");
    Unk_1129f60(self, "@Play_Camp_ComeNear01", "PM025_50");
    Unk_1129f60(self, "@Play_Camp_ComeNear02", "PM025_51");
    Unk_1129f60(self, "@Play_Camp_ComeNear03", "PM025_52");
    Unk_1129f60(self, "@Play_Camp_ComeNear04", "PM025_53");
    Unk_1129f60(self, "@Play_Camp_ComeNear05", "PM025_54");
    Unk_1129f60(self, "@Play_Camp_ComeNear06", "PM025_55");
    Unk_112a220(self, "@Play_Camp_PlayingHit", "PM025_43", {"ba20_buturi01", "ba21_tokusyu01"});
    Unk_112a220(self, "@Play_Camp_Throw_Ball", "PM025_45", {"ba20_buturi01", "ba21_tokusyu01"});
    Unk_112a220(self, "@Play_UI_Emotional_Hungry", "PM025_41",
                {"kw32_happyA01", "kw32_happyB01", "kw35_playA01", "kw35_playB01"});
    Unk_112a220(self, "@Play_UI_Emotional_Confuse", "PM025_49", {"kw30_hate01", "kw36_mad01"});
}

// 0x710112b6e0
void Unk_112b6e0(Unk_112d870* self) {
    Unk_1129f60(self, "@Play_Camp_Eat_start", "PM025_56");
    Unk_1129f60(self, "@Play_Camp_Eat_reaction_01", "PM025_57");
    Unk_1129f60(self, "@Play_Camp_Eat_reaction_02", "PM025_58");
    Unk_1129f60(self, "@Play_Camp_Eat_reaction_03", "PM025_59");
    Unk_1129f60(self, "@Play_Camp_Eat_reaction_04", "PM025_60");
    Unk_1129f60(self, "@Play_Camp_Eat_reaction_05", "PM025_61");
    Unk_1129f60(self, "@Play_Camp_Eat_loop_slow", "PM025_62");
    Unk_1129f60(self, "@Play_Camp_Eat_loop_normal", "PM025_63");
    Unk_1129f60(self, "@Play_Camp_Eat_loop_fast", "PM025_64");
    Unk_1129ca0(self, "kw11_turnA01", "PM025_65");
    Unk_1129ca0(self, "kw11_turnB01", "PM025_66");
    Unk_1129ca0(self, "kw20_drowseA01", "PM025_67");
    Unk_1129ca0(self, "kw20_drowseC01", "PM025_68");
    Unk_1129ca0(self, "kw21_sleepB01", "PM025_70");
    Unk_1129ca0(self, "kw30_hate01", "PM025_71");
    Unk_1129ca0(self, "kw31_question01", "PM025_72");
    Unk_1129ca0(self, "kw32_happyA01", "PM025_73");
    Unk_1129ca0(self, "kw32_happyB01", "PM025_74");
    Unk_1129ca0(self, "kw32_happyC01", "PM025_75");
    Unk_1129ca0(self, "kw33_moveA01", "PM025_76");
    Unk_1129ca0(self, "kw33_moveB01", "PM025_77");
    Unk_1129ca0(self, "kw33_moveC01", "PM025_78");
    Unk_1129ca0(self, "kw34_lonely01", "PM025_79");
    Unk_1129ca0(self, "kw35_playA01", "PM025_80");
    Unk_1129ca0(self, "kw35_playB01", "PM025_81");
    Unk_1129ca0(self, "kw36_mad01", "PM025_82");
    Unk_1129ca0(self, "ba02_roar01", "PM025_83");
    Unk_1129ca0(self, "kw60_touch01", "PM025_88");
    Unk_1129f60(self, "@Play_Camp_Sleep", "PM025_69");
    Unk_1129f60(self, "@Play_Camp_Zoom_Appear", "PM025_84");
    Unk_1129f60(self, "Play_UI_Emotional_Hungry", "PM025_85");
    Unk_1129f60(self, "itching", "PM025_86");
    Unk_1129f60(self, "Play_Camp_PlayingHit", "");
    Unk_1129f60(self, "Play_Camp_Throw_Ball", "");
    Unk_1129f60(self, "@Play_Camp_Battle", "PM025_90");
    Unk_1129f60(self, "@Play_Camp_Race", "PM025_91");
    Unk_1129f60(self, "@Play_Camp_RandomLook", "PM025_92");
    Unk_1129f60(self, "Play_UI_Emotional_Confuse", "PM025_93");
    Unk_1129f60(self, "@Play_Camp_ComeNear01", "PM025_94");
    Unk_1129f60(self, "@Play_Camp_ComeNear02", "PM025_95");
    Unk_1129f60(self, "@Play_Camp_ComeNear03", "PM025_96");
    Unk_1129f60(self, "@Play_Camp_ComeNear04", "PM025_97");
    Unk_1129f60(self, "@Play_Camp_ComeNear05", "PM025_98");
    Unk_1129f60(self, "@Play_Camp_ComeNear06", "PM025_99");
    Unk_112a220(self, "@Play_Camp_PlayingHit", "PM025_87", {"ba20_buturi01", "ba21_tokusyu01"});
    Unk_112a220(self, "@Play_Camp_Throw_Ball", "PM025_89", {"ba20_buturi01", "ba21_tokusyu01"});
    Unk_112a220(self, "@Play_UI_Emotional_Hungry", "PM025_85",
                {"kw32_happyA01", "kw32_happyB01", "kw35_playA01", "kw35_playB01"});
    Unk_112a220(self, "@Play_UI_Emotional_Confuse", "PM025_93", {"kw30_hate01", "kw36_mad01"});
}

// 0x710112c850
void Unk_112c850(Unk_112d870* self) {
    Unk_1129f60(self, "@Play_Camp_Eat_start", "PM133_08");
    Unk_1129f60(self, "@Play_Camp_Eat_reaction_01", "PM133_09");
    Unk_1129f60(self, "@Play_Camp_Eat_reaction_02", "PM133_10");
    Unk_1129f60(self, "@Play_Camp_Eat_reaction_03", "PM133_11");
    Unk_1129f60(self, "@Play_Camp_Eat_reaction_04", "PM133_12");
    Unk_1129f60(self, "@Play_Camp_Eat_reaction_05", "PM133_13");
    Unk_1129f60(self, "@Play_Camp_Eat_loop_slow", "PM133_14");
    Unk_1129f60(self, "@Play_Camp_Eat_loop_normal", "PM133_15");
    Unk_1129f60(self, "@Play_Camp_Eat_loop_fast", "PM133_16");
    Unk_1129ca0(self, "kw20_drowseA01", "PM133_17");
    Unk_1129ca0(self, "kw20_drowseC01", "PM133_18");
    Unk_1129ca0(self, "kw21_sleepB01", "PM133_20");
    Unk_1129ca0(self, "kw30_hate01", "PM133_21");
    Unk_1129ca0(self, "kw31_question01", "PM133_22");
    Unk_1129ca0(self, "kw32_happyA01", "PM133_23");
    Unk_1129ca0(self, "kw32_happyB01", "PM133_24");
    Unk_1129ca0(self, "kw32_happyC01", "PM133_25");
    Unk_1129ca0(self, "kw33_moveA01", "PM133_26");
    Unk_1129ca0(self, "kw33_moveC01", "PM133_27");
    Unk_1129ca0(self, "kw34_lonely01", "PM133_28");
    Unk_1129ca0(self, "kw35_playA01", "PM133_29");
    Unk_1129ca0(self, "kw36_mad01", "PM133_30");
    Unk_1129ca0(self, "ba02_roar01", "PM133_31");
    Unk_1129ca0(self, "kw60_touch01", "PM133_36");
    Unk_1129f60(self, "@Play_Camp_Sleep", "PM133_19");
    Unk_1129f60(self, "@Play_Camp_Zoom_Appear", "PM133_32");
    Unk_1129f60(self, "Play_UI_Emotional_Hungry", "PM133_33");
    Unk_1129f60(self, "itching", "PM133_34");
    Unk_1129f60(self, "Play_Camp_PlayingHit", "");
    Unk_1129f60(self, "Play_Camp_Throw_Ball", "");
    Unk_1129f60(self, "@Play_Camp_Battle", "PM025_38");
    Unk_1129f60(self, "@Play_Camp_Race", "PM133_39");
    Unk_1129f60(self, "@Play_Camp_RandomLook", "PM133_40");
    Unk_1129f60(self, "Play_UI_Emotional_Confuse", "PM133_41");
    Unk_1129f60(self, "@Play_Camp_ComeNear01", "PM133_42");
    Unk_1129f60(self, "@Play_Camp_ComeNear02", "PM133_43");
    Unk_1129f60(self, "@Play_Camp_ComeNear03", "PM133_44");
    Unk_1129f60(self, "@Play_Camp_ComeNear04", "PM133_45");
    Unk_1129f60(self, "@Play_Camp_ComeNear05", "PM133_46");
    Unk_1129f60(self, "@Play_Camp_ComeNear06", "PM133_47");
    Unk_112a220(self, "@Play_Camp_PlayingHit", "PM133_35", {"ba20_buturi01", "ba21_tokusyu01"});
    Unk_112a220(self, "@Play_Camp_Throw_Ball", "PM133_37", {"ba20_buturi01", "ba21_tokusyu01"});
    Unk_112a220(self, "@Play_UI_Emotional_Hungry", "PM025_33",
                {"kw32_happyA01", "kw32_happyB01", "kw35_playA01", "kw35_playB01"});
    Unk_112a220(self, "@Play_UI_Emotional_Confuse", "PM025_41", {"kw30_hate01", "kw36_mad01"});
}
