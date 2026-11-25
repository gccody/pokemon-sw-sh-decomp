// Scope: common
//
// The message board views (src/unsorted/unk_14b14a0/Unk_14b6680.h):
// Unk_24428a8's members, and the shared ones of Unk_27e0b00 that its
// derived classes' vtables reach.
#include "unsorted/unk_14b14a0/Unk_14b6680.h"

// The board's layout file (0x71024425d8, reached through the GOT).
extern const char* const Unk_24425d8;

// 0x71014b6680: sets the layout up, then shows the state.
void Unk_24428a8::Unk_14b6680(u32 state, u64 arg, const Unk_239a418_Ref<Unk_239a418>& parent) {
    Unk_14a82b0(this, arg, parent, Unk_c46830(Unk_24425d8), "msg_kanban_00.bflyt", true);
    vf8(state);
}

// 0x71014b67c0
void Unk_24428a8::vf17() {
    Unk_685250_call(static_cast<const Unk_685250*>(field_c0), reinterpret_cast<u64>("all"))
        ->field_58 &= ~1;
    Unk_6855a0(field_c0, 0, "msg_kanban_00_in.bflan", false);
    Unk_6855a0(field_c0, 1, "msg_kanban_00_out.bflan", false);
    Unk_6855a0(field_c0, 2, "msg_kanban_00_switch.bflan", false);
    void* cursor = Unk_685360(field_c0, "L_cursor_00");
    Unk_6856d0(field_c0, cursor, 3, "message_cursor_00_keep.bflan", false);
}

// 0x71014b6870
void Unk_24428a8::vf18() {
    Unk_685250_call(static_cast<const Unk_685250*>(field_c0), reinterpret_cast<u64>("all"))
        ->field_58 |= 1;
    Unk_14a94a0(this, 0, 0.0f, true, true);
}

// 0x71014b68c0
void Unk_24428a8::vf19() {
    Unk_14a94a0(this, 1, 0.0f, true, true);
}

// 0x71014b68e0
void Unk_24428a8::vf20() {
    Unk_14a94a0(this, 3, 0.0f, true, true);
}

// 0x71014b6980
void Unk_24428a8::vf8(u32 state) {
    switch (state) {
        case 0:
            Unk_14a94a0(this, 2, 0.0f, false, true);
            break;
        case 1:
            Unk_14a94a0(this, 2, 1.0f, false, true);
            break;
    }
}

// 0x71014b6aa0
void Unk_27e0b00::vf18() {
    Unk_685250_call(static_cast<const Unk_685250*>(field_c0), reinterpret_cast<u64>("all"))
        ->field_58 |= 1;
    Unk_14a94a0(this, vf23(0), 0.0f, true, true);
    field_384 = false;
}

// 0x71014b6b10
void Unk_27e0b00::vf19() {
    if (vf26()) {
        vf25(false);
        field_384 = true;
    } else {
        Unk_14a94a0(this, vf23(1), 0.0f, true, true);
    }
}

// 0x71014b6b90
bool Unk_27e0b00::vf13() {
    if (vf26())
        return false;
    return Unk_685c60(reinterpret_cast<u64>(field_c0), vf23(1));
}

// 0x71014b6bf0
void Unk_27e0b00::vf16() {
    Unk_2441f08::vf16();
    u32 index = vf23(5);
    if (Unk_685a50(field_c0, index) && Unk_685c60(reinterpret_cast<u64>(field_c0), index)) {
        Unk_6859b0(field_c0, index);
        field_388->field_58 &= ~1;
    }
    if (field_384 && !vf26()) {
        field_384 = false;
        Unk_14a94a0(this, vf23(1), 0.0f, true, true);
    }
}
