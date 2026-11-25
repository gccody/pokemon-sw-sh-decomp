// Scope: common
//
// The message board views (src/unsorted/unk_14b14a0/Unk_14b6680.h): the rest
// of Unk_27e0b00's shared members, and Unk_2442a00's constructor, destructor
// (its key function: its vtable and thunks are emitted here) and set-up.
#include "unsorted/unk_14b14a0/Unk_14b6680.h"

// The views' layout files (0x71024425c0 and 0x71024425c8, reached through
// the GOT).
extern const char* const Unk_24425c0;
extern const char* const Unk_24425c8;

// 0x71014b6cc0
void Unk_27e0b00::vf20() {
    Unk_14a94a0(this, vf23(2), 0.0f, true, true);
}

// 0x71014b6d00
void Unk_27e0b00::vf21() {
    Unk_14a9520(this, vf23(0));
}

// 0x71014b6d40 (and its thunk 0x71014b6e50)
void Unk_27e0b00::vf25(bool value) {
    if (value == field_390)
        return;
    if (value) {
        field_388->field_58 |= 1;
        Unk_14a94a0(this, vf23(4), 0.0f, true, true);
        Unk_14a94a0(this, vf23(3), 0.0f, true, true);
        Unk_14a9570_call(reinterpret_cast<const Unk_14a9570*>(this), vf23(5));
    } else {
        Unk_14a94a0(this, vf23(5), 0.0f, true, false);
        Unk_14a9570_call(reinterpret_cast<const Unk_14a9570*>(this), vf23(3));
    }
    field_390 = value;
}

// 0x71014b6e80
Unk_2442a00::Unk_2442a00(void* arg) : Unk_27e0b00(arg), field_394(0) {}

// 0x71014b6ee0, its D0 0x71014b6f10 and thunks 0x71014b6ef0, 0x71014b6f20
// (+0x48), 0x71014b6f00, 0x71014b6f30 (+0x50)
Unk_2442a00::~Unk_2442a00() {}

// The animation for a state (0x71014b70f0). Slot 8 tail-calls it with its
// own argument.
void Unk_14b70f0(void* self, u32 state);

// 0x71014b6f40: sets the layout up for its kind, then shows the state.
// NON_MATCHING: the original loads the parent's pointer in each branch; here
// the load is hoisted above the branch (one instruction fewer).
void Unk_2442a00::Unk_14b6f40(u32 state,
                              u32 kind,
                              u64 arg,
                              const Unk_239a418_Ref<Unk_239a418>& parent) {
    field_394 = kind;
    if (kind == 0)
        Unk_14a82b0(this, arg, parent, Unk_c46830(Unk_24425c0), "msg_sys_00.bflyt", true);
    else
        Unk_14a82b0(this, arg, parent, Unk_c46830(Unk_24425c8), "msg_sys_03.bflyt", true);
    Unk_14b70f0(this, state);
}

// 0x71014b70f0
// NON_MATCHING: it takes the state (w1), which its name (_Z11Unk_14b70f0Pv)
// leaves out; as _Z11Unk_14b70f0Pvj it matches.
void Unk_14b70f0(void* self, u32 state) {
    switch (state) {
        case 0:
            Unk_14a94a0(self, 2, 0.0f, false, true);
            break;
        case 1:
            Unk_14a94a0(self, 2, 3.0f, false, true);
            break;
        case 2:
            Unk_14a94a0(self, 2, 4.0f, false, true);
            break;
        case 3:
            Unk_14a94a0(self, 2, 5.0f, false, true);
            break;
        case 4:
            Unk_14a94a0(self, 2, 1.0f, false, true);
            break;
        case 5:
            Unk_14a94a0(self, 2, 2.0f, false, true);
            break;
    }
}
