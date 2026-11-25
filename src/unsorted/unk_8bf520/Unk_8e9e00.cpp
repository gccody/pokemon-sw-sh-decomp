// Scope: common
// The Battle Tower's views (src/unsorted/unk_8bf520/Unk_8e9e00.h): finding
// them, and showing the battle on them.
#include "unsorted/unk_8bf520/Unk_8e9e00.h"

// tools/leafgen.py's placeholders.
void Unk_8faa60(void* view, void* battle, u32 id, void* flags);
void Unk_8fa9a0_call(void* view, void* battle, u32 id, void* flags);
void Unk_905af0(void* view, void* battle, u32 id, void* flags);
void Unk_9059f0_call(void* view, void* battle, u32 id, void* flags);
void Unk_8ef110(void* view, u32 id, u32 value);
void Unk_8ef140(void* view, u32 id, bool value);
bool Unk_eb6530(void* view);

// 0x71008ea080
void Unk_23bd130::vf2() {
    Unk_a7bb80_Views* views = field_8->field_548;
    Unk_23bda50* top = views->Unk_a7bb80<Unk_23bda50>("TopView");
    field_20 = top;
    Unk_23bd220* boss = views->Unk_a7bb80<Unk_23bd220>("BossView");
    field_28 = boss;
    Unk_23be058* time = views->Unk_a7bb80<Unk_23be058>("RemainTimeView");
    field_30 = time;
    Unk_23bd6b8* spectator = views->Unk_a7bb80<Unk_23bd6b8>("SpectatorViewName");
    field_38 = spectator;
    Unk_23bd4b8* bg = views->Unk_a7bb80<Unk_23bd4b8>("CommonBGView");
    field_40 = bg;
}

void Unk_8ea2b0(void* p, u32 id, bool arg2, bool arg3, bool arg4);

// 0x71008ea250
void Unk_8ea250(void* p, u32 id, bool arg2, bool arg3) {
    Unk_23bd130* self = static_cast<Unk_23bd130*>(p);
    Unk_8ea2b0(p, id, arg2, self->field_10->field_370->vf267() == 2, arg3);
}

// 0x71008ea2b0
// NON_MATCHING: only the order of two of the stores differs.
void Unk_8ea2b0(void* p, u32 id, bool arg2, bool arg3, bool arg4) {
    Unk_23bd130* self = static_cast<Unk_23bd130*>(p);
    if (self->field_10->field_370->vf275()) {
        Unk_8faa60_Flags flags;
        flags.field_0 = arg2;
        flags.field_1 = arg3;
        flags.field_2 = arg2;
        Unk_8faa60(self->field_38, self->field_10->field_370, id, &flags);
    } else {
        Unk_905af0_Flags flags = {};
        flags.field_0 = arg2;
        flags.field_1 = arg3;
        flags.field_2 = arg2 && arg4;
        Unk_905af0(self->field_20, self->field_10->field_370, id, &flags);
        if (self->field_10->field_370->vf267() == 2)
            Unk_8ef140(self->field_28, id, arg2);
    }
}

// 0x71008ea3b0
// NON_MATCHING: the constant 1 isn't hoisted above the branch.
void Unk_8ea3b0(u64 p, bool arg1) {
    Unk_23bd130* self = reinterpret_cast<Unk_23bd130*>(p);
    if (self->field_10->field_370->vf275()) {
        Unk_8faa60_Flags flags;
        flags.field_0 = true;
        flags.field_1 = false;
        flags.field_2 = true;
        Unk_8fa9a0_call(self->field_38, self->field_10->field_370, 2, &flags);
    } else {
        Unk_905af0_Flags flags = {};
        flags.field_0 = true;
        flags.field_1 = false;
        flags.field_2 = arg1;
        Unk_9059f0_call(self->field_20, self->field_10->field_370, 2, &flags);
        if (self->field_10->field_370->vf267() == 2)
            Unk_8ef110(self->field_28, 2, 1);
        Unk_e806b0(self->field_30, true, true);
    }
}

// 0x71008ea490
void Unk_8ea490(u64 p) {
    Unk_23bd130* self = reinterpret_cast<Unk_23bd130*>(p);
    if (!self->field_10->field_370->vf275()) {
        Unk_905af0_Flags flags = {};
        Unk_9059f0_call(self->field_20, self->field_10->field_370, 2, &flags);
        if (self->field_10->field_370->vf267() == 2)
            Unk_8ef110(self->field_28, 2, 0);
        Unk_e806b0(self->field_30, false, true);
    } else {
        Unk_8faa60_Flags flags = {false, false, false};
        Unk_8fa9a0_call(self->field_38, self->field_10->field_370, 2, &flags);
    }
}

// 0x71008ea550
bool Unk_23bd130::Unk_8ea550() {
    if (field_10->field_370->vf275())
        return true;
    Unk_23bda50* top = field_20;
    if (Unk_eb6530(top))
        return false;
    return top->field_5d0->field_60 == 0;
}
