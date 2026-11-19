// Scope: common
// Battle sequence functions: what the tables of unsorted/Unk_23c4ef0.h call
// for a command, with the sequence being read (its arguments follow the
// command), the view system and the command (its hash, then its frames).
// They're in the tables' TU, after their constructors (0x71009be950 to
// 0x7100a6c510). Placeholder names: rename once the functions are known.
#include "battle/battle_scene/Unk_23c4ef0_Seq.h"

void Unk_9a7300(void*, u32);
void Unk_9a7680(void*, f32);
bool Unk_7ccca0(u64, u32);
void Unk_97f120(Unk_23c4ef0_Poke*, bool);
void Unk_9805d0(Unk_23c4ef0_Poke*);
void Unk_c444b0(void*, u32, s32);
void Unk_97d960(Unk_23c4ef0_Poke*, f32);
void Unk_97f000(Unk_23c4ef0_Poke*, bool);
void Unk_97f050(Unk_23c4ef0_Poke*, bool, s32, bool);
void Unk_980950(Unk_23c4ef0_Poke*, s32);
u8 Unk_981b70(Unk_23c4ef0_Poke*);
void Unk_988980(Unk_23c4ef0_Poke*, s32);
void Unk_9889a0(Unk_23c4ef0_Poke*, f32, s32);

// A global object.
extern void* Unk_24ba638;

// What Unk_98a880_call takes.
struct Unk_23c4ef0_Arg98a880 {
    s32 field_0;
    u8 field_4;
    u8 field_5;
    u8 field_6;
};

// What Unk_23c4ef0_Owner::vf23 takes first.
struct Unk_23c4ef0_Arg23 {
    void* field_0;
    u32 field_8;
    bool field_c;
    u64 field_10;
    u64 field_18;
    u32 field_20;
};

// 0x7100a40230
void Unk_a40230(void* seq, Unk_23c4ef0_Owner*, const u64*) {
    s32 arg1;
    s32 arg2;
    Unk_23c4ef0_ReadS32(seq, &arg1);
    Unk_23c4ef0_ReadS32(seq, &arg2);
}

// 0x7100a42830
void Unk_a42830(void* seq, Unk_23c4ef0_Owner* owner, const u64*) {
    bool arg;
    Unk_23c4ef0_ReadBool(seq, &arg);
    Unk_9a7300(owner->field_4a8, arg);
}

// 0x7100a42870
void Unk_a42870(void* seq, Unk_23c4ef0_Owner* owner, const u64*) {
    f32 arg;
    Unk_23c4ef0_ReadF32(seq, &arg);
    owner->field_4a8->SetField_a0(arg);
}

// 0x7100a428b0
void Unk_a428b0(void* seq, Unk_23c4ef0_Owner* owner, const u64*) {
    Unk_23c4ef0_Vec arg;
    Unk_23c4ef0_ReadVec(seq, &arg);
    owner->field_4a8->SetField_b0(arg);
}

// 0x7100a428f0
void Unk_a428f0(void* seq, Unk_23c4ef0_Owner* owner, const u64*) {
    f32 arg;
    Unk_23c4ef0_ReadF32(seq, &arg);
    Unk_9a7680(owner->field_4a8, arg);
}

// 0x7100a42930
void Unk_a42930(void* seq, Unk_23c4ef0_Owner* owner, const u64*) {
    bool arg;
    Unk_23c4ef0_ReadBool(seq, &arg);
    owner->field_4a8->SetField_c1(arg);
}

// 0x7100a42b80
void Unk_a42b80(void* seq, Unk_23c4ef0_Owner* owner, const u64*) {
    bool arg;
    Unk_23c4ef0_ReadBool(seq, &arg);
    Unk_9a7300(owner->field_4c8, arg);
}

// 0x7100a42bc0
void Unk_a42bc0(void* seq, Unk_23c4ef0_Owner* owner, const u64*) {
    f32 arg;
    Unk_23c4ef0_ReadF32(seq, &arg);
    owner->field_4c8->SetField_a0(arg);
}

// 0x7100a42c00
void Unk_a42c00(void* seq, Unk_23c4ef0_Owner* owner, const u64*) {
    Unk_23c4ef0_Vec arg;
    Unk_23c4ef0_ReadVec(seq, &arg);
    owner->field_4c8->SetField_b0(arg);
}

// 0x7100a42c40
void Unk_a42c40(void* seq, Unk_23c4ef0_Owner* owner, const u64*) {
    f32 arg;
    Unk_23c4ef0_ReadF32(seq, &arg);
    Unk_9a7680(owner->field_4c8, arg);
}

// 0x7100a42c80
void Unk_a42c80(void* seq, Unk_23c4ef0_Owner* owner, const u64*) {
    bool arg;
    Unk_23c4ef0_ReadBool(seq, &arg);
    owner->field_4c8->SetField_c1(arg);
}

// 0x7100a52950
void Unk_a52950(void* seq, Unk_23c4ef0_Owner* owner, const u64*) {
    s32 arg;
    Unk_23c4ef0_ReadS32(seq, &arg);
    s32 value = arg;
    owner->vf321(&value);
}

// 0x7100a3d810
void Unk_a3d810(void* seq, Unk_23c4ef0_Owner* owner, const u64* cmd) {
    s32 frames = Unk_23c4ef0_Frames(cmd) / 2;
    s32 id;
    s32 arg;
    Unk_23c4ef0_ReadS32(seq, &id);
    Unk_23c4ef0_ReadS32(seq, &arg);
    s32 n = 1;
    if (id == 1)
        n = owner->Unk_9526f0(true);
    for (s32 i = 0; i < n; i++) {
        u32 pos = owner->Unk_952670(id, i);
        if (pos != 0xff)
            owner->Unk_952940(pos, frames, arg);
    }
}

// 0x7100a41c40
void Unk_a41c40(void* seq, Unk_23c4ef0_Owner* owner, const u64*) {
    s32 id;
    bool arg;
    Unk_23c4ef0_ReadS32(seq, &id);
    Unk_23c4ef0_ReadBool(seq, &arg);
    u32 pos = owner->Unk_952670(id, 0);
    if (pos != 0xff)
        owner->Unk_965220(arg, pos);
}

// 0x7100a42310
void Unk_a42310(void* seq, Unk_23c4ef0_Owner* owner, const u64*) {
    s32 id;
    Unk_23c4ef0_ReadS32(seq, &id);
    s32 n = 1;
    if (id == 1)
        n = owner->Unk_9526f0(true);
    for (s32 i = 0; i < n; i++) {
        u32 pos = owner->Unk_952670(id, i);
        if (pos == 0xff)
            continue;
        Unk_239a418_Ref<Unk_23c4ef0_Poke> poke = owner->field_548[pos];
        if (poke.m_ptr)
            Unk_9805d0(poke.m_ptr);
    }
}

// 0x7100a42690
void Unk_a42690(void* seq, Unk_23c4ef0_Owner* owner, const u64* cmd) {
    s32 frames = Unk_23c4ef0_Frames(cmd) / 2;
    s32 arg;
    Unk_23c4ef0_ReadS32(seq, &arg);
    Unk_23c4ef0_Light* light = owner->field_4a8;
    owner->Unk_9533f0(frames, arg, light);
}

// 0x7100a426f0
void Unk_a426f0(void* seq, Unk_23c4ef0_Owner* owner, const u64* cmd) {
    s32 frames = Unk_23c4ef0_Frames(cmd) / 2;
    s32 arg;
    Unk_23c4ef0_ReadS32(seq, &arg);
    Unk_23c4ef0_Light* light = owner->field_4a8;
    owner->Unk_953170(frames, arg, light);
}

// 0x7100a429e0
void Unk_a429e0(void* seq, Unk_23c4ef0_Owner* owner, const u64* cmd) {
    s32 frames = Unk_23c4ef0_Frames(cmd) / 2;
    s32 arg;
    Unk_23c4ef0_ReadS32(seq, &arg);
    Unk_23c4ef0_Light* light = owner->field_4c8;
    owner->Unk_9533f0(frames, arg, light);
}

// 0x7100a42a40
void Unk_a42a40(void* seq, Unk_23c4ef0_Owner* owner, const u64* cmd) {
    s32 frames = Unk_23c4ef0_Frames(cmd) / 2;
    s32 arg;
    Unk_23c4ef0_ReadS32(seq, &arg);
    Unk_23c4ef0_Light* light = owner->field_4c8;
    owner->Unk_953170(frames, arg, light);
}

// 0x7100a4d780
void Unk_a4d780(void* seq, Unk_23c4ef0_Owner*, const u64*) {
    Unk_23f4660_Name name = {nullptr, 0xcbf29ce484222645, "", 0, nullptr, 0};
    s32 arg2;
    bool arg1;
    Unk_140bd70(reinterpret_cast<u64>(seq), &name, 1);
    Unk_23c4ef0_ReadBool(seq, &arg1);
    Unk_23c4ef0_ReadS32(seq, &arg2);
}

// 0x7100a51ff0
void Unk_a51ff0(void* seq, Unk_23c4ef0_Owner* owner, const u64*) {
    bool arg;
    Unk_23c4ef0_ReadBool(seq, &arg);
    if (arg)
        Unk_8ea3b0(reinterpret_cast<u64>(owner->Unk_95bb50()), 0);
    else
        Unk_8ea490(reinterpret_cast<u64>(owner->Unk_95bb50()));
}

// 0x7100a528a0
void Unk_a528a0(void* seq, Unk_23c4ef0_Owner* owner, const u64*) {
    bool arg1;
    s32 arg2;
    Unk_23c4ef0_ReadBool(seq, &arg1);
    Unk_23c4ef0_ReadS32(seq, &arg2);
    if (!arg1) {
        owner->field_5c8->Unk_98a8b0();
        return;
    }
    Unk_23c4ef0_Arg98a880 value;
    value.field_4 = 5;
    value.field_5 = 5;
    value.field_6 = 5;
    value.field_0 = arg2;
    if (u64 p = Unk_8a9060_getField58(reinterpret_cast<const Unk_8a9060*>(owner))) {
        value.field_4 = 0;
        value.field_5 = 1;
        if (Unk_7ccca0(p, 3))
            value.field_6 = 3;
    }
    Unk_98a880_call(reinterpret_cast<const Unk_98a880*>(owner->field_5c8),
                    reinterpret_cast<const Unk_98a880_arg1*>(&value));
}

// 0x7100a53460
void Unk_a53460(void* seq, Unk_23c4ef0_Owner* owner, const u64*) {
    bool arg1;
    bool arg2;
    Unk_23c4ef0_ReadBool(seq, &arg1);
    Unk_23c4ef0_ReadBool(seq, &arg2);
    owner->Unk_965790(arg1, 2);
}

// 0x7100a53640
void Unk_a53640(void* seq, Unk_23c4ef0_Owner* owner, const u64*) {
    Unk_23c4ef0_Vec arg2;
    bool arg1;
    Unk_23c4ef0_ReadBool(seq, &arg1);
    Unk_23c4ef0_ReadVec(seq, &arg2);
    if (arg1)
        owner->Unk_953970();
    else
        Unk_953950_set(reinterpret_cast<const Unk_953950*>(owner),
                       reinterpret_cast<const Unk_953950_arg1*>(&arg2));
}

// 0x7100a536b0
void Unk_a536b0(void* seq, Unk_23c4ef0_Owner* owner, const u64*) {
    char str[0x40];
    Unk_140bcf0(seq, str, sizeof(str), 1);
    Unk_23c4ef0_Name name(str);
    owner->Unk_9650e0(&name);
}

// 0x7100a53830
void Unk_a53830(void* seq, Unk_23c4ef0_Owner*, const u64* cmd) {
    s32 frames = Unk_23c4ef0_Frames(cmd) / 2;
    s32 arg;
    Unk_23c4ef0_ReadS32(seq, &arg);
    s32 n = frames;
    if (n == 0)
        n = 2;
    Unk_c444b0(Unk_24ba638, 0, n);
}

// 0x7100a56900
void Unk_a56900(void* seq, Unk_23c4ef0_Owner* owner, const u64*) {
    bool arg;
    Unk_23c4ef0_ReadBool(seq, &arg);
    if (owner->vf267() != 2)
        return;
    if (arg)
        owner->field_5c8->Unk_98a1c0();
    else
        owner->field_5c8->Unk_98a230();
}

// 0x7100a56960
void Unk_a56960(void* seq, Unk_23c4ef0_Owner* owner, const u64*) {
    s32 arg;
    Unk_23c4ef0_ReadS32(seq, &arg);
    owner->field_5c8->Unk_98a1e0(owner->vf314(), owner->vf315(), arg);
}

// 0x7100a5bc40
void Unk_a5bc40(void* seq, Unk_23c4ef0_Owner* owner, const u64*) {
    u64 arg;
    Unk_23c4ef0_ReadU64(seq, &arg);
    u64 value = arg;
    owner->Unk_9626a0(&value);
}

// 0x7100a5c5d0
void Unk_a5c5d0(void* seq, Unk_23c4ef0_Owner* owner, const u64*) {
    s32 id;
    bool arg;
    Unk_23c4ef0_ReadS32(seq, &id);
    Unk_23c4ef0_ReadBool(seq, &arg);
    s32 n = 1;
    if (id == 10)
        n = owner->Unk_9526f0(true);
    for (s32 i = 0; i < n; i++) {
        u32 pos = owner->Unk_960620(id, i);
        if (pos != 0xff)
            owner->Unk_952f90(pos, arg);
    }
}

// 0x7100a5c680
void Unk_a5c680(void* seq, Unk_23c4ef0_Owner* owner, const u64*) {
    bool arg;
    Unk_23c4ef0_ReadBool(seq, &arg);
    for (u32 pos = 0; pos < 7; pos++)
        owner->Unk_952f90(pos, arg);
}

// 0x7100a5cfe0
void Unk_a5cfe0(void* seq, Unk_23c4ef0_Owner* owner, const u64*) {
    s32 id;
    bool arg;
    Unk_23c4ef0_ReadS32(seq, &id);
    Unk_23c4ef0_ReadBool(seq, &arg);
    s32 n = 1;
    if (id == 10)
        n = owner->Unk_9526f0(true);
    for (s32 i = 0; i < n; i++) {
        Unk_239a418_Ref<Unk_23c4ef0_Poke> poke = owner->Unk_961f10(id, i);
        if (poke.m_ptr)
            Unk_97f120(poke.m_ptr, arg);
    }
}

// 0x7100a5d6b0
void Unk_a5d6b0(void* seq, Unk_23c4ef0_Owner* owner, const u64*) {
    s32 id;
    Unk_23c4ef0_ReadS32(seq, &id);
    Unk_239a418_Ref<Unk_23c4ef0_Poke> poke = owner->Unk_961f10(id, 0);
    if (poke.m_ptr)
        Unk_9805d0(poke.m_ptr);
}

// 0x7100a5edd0
void Unk_a5edd0(void*, Unk_23c4ef0_Owner* owner, const u64*) {
    u32 pos = owner->Unk_952670(0, 0);
    owner->field_5c8->Unk_98a290(
        Unk_7ee6b0_getField7d(static_cast<const Unk_7ee6b0*>(owner->vf253(pos))), owner->field_1754,
        1);
}

// 0x7100a600b0
void Unk_a600b0(void* seq, Unk_23c4ef0_Owner* owner, const u64*) {
    s32 arg;
    Unk_23c4ef0_ReadS32(seq, &arg);
    u64 flags;
    switch (arg) {
        case 0:
            flags = 1ul << 28;
            break;
        case 1:
            flags = 1ul << 29;
            break;
        case 2:
            flags = 1ul << 30;
            break;
        case 3:
            flags = 1ul << 31;
            break;
        case 4:
            flags = 1ul << 32;
            break;
        case 5:
            flags = 1ul << 33;
            break;
        case 6:
            flags = 1ul << 34;
            break;
        case 7:
            flags = 1ul << 35;
            break;
        case 8:
            flags = 1ul << 48;
            break;
        case 9:
            flags = 1ul << 49;
            break;
        default:
            flags = 0;
            break;
    }
    owner->field_5c8->Unk_98aa50(flags);
}

// 0x7100a60100
void Unk_a60100(void* seq, Unk_23c4ef0_Owner* owner, const u64*) {
    bool arg;
    Unk_23c4ef0_ReadBool(seq, &arg);
    u32 pos = owner->Unk_952670(0, 0);
    if (!arg) {
        owner->vf25();
        return;
    }
    Unk_23c4ef0_Arg23 arg1;
    arg1.field_0 = owner->vf253(pos);
    arg1.field_c = false;
    arg1.field_8 = 0;
    arg1.field_10 = 0;
    arg1.field_18 = 0;
    arg1.field_20 = 2;
    u64 arg2 = 0;
    owner->vf23(&arg1, &arg2);
}

// 0x7100a601b0
void Unk_a601b0(void* seq, Unk_23c4ef0_Owner* owner, const u64*) {
    bool arg;
    Unk_23c4ef0_ReadBool(seq, &arg);
    if (arg) {
        Unk_98aac0_set(reinterpret_cast<Unk_98aac0*>(owner->field_5c8), 0);
        owner->vf118(2, 0, 0, 1, 0, 1);
    } else {
        owner->vf120();
    }
}

// 0x7100a3d8e0
void Unk_a3d8e0(void* seq, Unk_23c4ef0_Owner* owner, const u64* cmd) {
    s32 frames = Unk_23c4ef0_Frames(cmd) / 2;
    s32 arg;
    Unk_23c4ef0_ReadS32(seq, &arg);
    for (u32 pos = 0; pos < 7; pos++)
        owner->Unk_952940(pos, frames, arg);
}

// 0x7100a40270
void Unk_a40270(void* seq, Unk_23c4ef0_Owner* owner, const u64*) {
    bool arg1;
    s32 id;
    f32 arg2;
    Unk_23c4ef0_ReadBool(seq, &arg1);
    Unk_23c4ef0_ReadS32(seq, &id);
    Unk_23c4ef0_ReadF32(seq, &arg2);
    s32 n = 1;
    if (id == 1)
        n = owner->Unk_9526f0(true);
    for (s32 i = 0; i < n; i++) {
        u32 pos = owner->Unk_952670(id, i);
        if (pos == 0xff)
            continue;
        Unk_239a418_Ref<Unk_23c4ef0_Poke> poke = owner->field_548[pos];
        if (arg1)
            Unk_97d960(poke.m_ptr, Unk_981b70(poke.m_ptr) == 1 ? 0.5f : 1.0f);
        else
            Unk_97d960(poke.m_ptr, arg2);
    }
}

// 0x7100a41370
void Unk_a41370(void* seq, Unk_23c4ef0_Owner* owner, const u64*) {
    s32 id;
    Unk_23c4ef0_ReadS32(seq, &id);
    s32 n = 1;
    if (id == 1)
        n = owner->Unk_9526f0(true);
    for (s32 i = 0; i < n; i++) {
        u32 pos = owner->Unk_952670(id, i);
        if (pos == 0xff)
            continue;
        Unk_239a418_Ref<Unk_23c4ef0_Poke> poke = owner->field_548[pos];
        float32x4_t scale = poke.m_ptr->field_400;
        poke.m_ptr->field_3f0 =
            Unk_23c4ef0_MakeVec(1.0f / vgetq_lane_f32(scale, 0), 1.0f / vgetq_lane_f32(scale, 1),
                                1.0f / vgetq_lane_f32(scale, 2));
    }
}

// 0x7100a41890
void Unk_a41890(void* seq, Unk_23c4ef0_Owner* owner, const u64*) {
    s32 id;
    s32 arg1;
    bool arg2;
    bool arg3;
    Unk_23c4ef0_ReadS32(seq, &id);
    Unk_23c4ef0_ReadS32(seq, &arg1);
    Unk_23c4ef0_ReadBool(seq, &arg2);
    Unk_23c4ef0_ReadBool(seq, &arg3);
    s32 n = 1;
    if (id == 1)
        n = owner->Unk_9526f0(true);
    for (s32 i = 0; i < n; i++) {
        u32 pos = owner->Unk_952670(id, i);
        if (pos == 0xff)
            continue;
        Unk_239a418_Ref<Unk_23c4ef0_Poke> poke = owner->field_548[pos];
        if (!poke.m_ptr)
            continue;
        if (poke.m_ptr->vf50() && Unk_981b70(poke.m_ptr) == 1)
            Unk_97f050(poke.m_ptr, arg2, arg1, arg3);
    }
}

// 0x7100a4ba40
void Unk_a4ba40(void* seq, Unk_23c4ef0_Owner* owner, const u64* cmd) {
    bool arg;
    Unk_23c4ef0_ReadBool(seq, &arg);
    Unk_239a418_Ref<Unk_23c4ef0_Group> group =
        owner->field_640->field_8.find(Unk_23c4ef0_GetCmd(cmd)->field_10)->second;
    for (Unk_23c4ef0_Poke* poke : group.m_ptr->field_a0)
        poke->vf51(arg);
}

// 0x7100a4d9e0
void Unk_a4d9e0(void* seq, Unk_23c4ef0_Owner* owner, const u64* cmd) {
    s32 arg;
    Unk_23c4ef0_ReadS32(seq, &arg);
    Unk_239a418_Ref<Unk_23c4ef0_Group> group =
        owner->field_640->field_8.find(Unk_23c4ef0_GetCmd(cmd)->field_10)->second;
    for (Unk_23c4ef0_Poke* poke : group.m_ptr->field_a0)
        Unk_988980(poke, arg);
}

// 0x7100a4dae0
void Unk_a4dae0(void* seq, Unk_23c4ef0_Owner* owner, const u64* cmd) {
    s32 arg2;
    f32 arg1;
    Unk_23c4ef0_ReadF32(seq, &arg1);
    Unk_23c4ef0_ReadS32(seq, &arg2);
    Unk_239a418_Ref<Unk_23c4ef0_Group> group =
        owner->field_640->field_8.find(Unk_23c4ef0_GetCmd(cmd)->field_10)->second;
    for (Unk_23c4ef0_Poke* poke : group.m_ptr->field_a0)
        Unk_9889a0(poke, arg1, arg2);
}
