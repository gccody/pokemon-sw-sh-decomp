// Scope: common
// The event system's variables, frames and handler nodes (0x71007e9940 to
// 0x71007e9f60): the event system's TU calls them out of line, so they're
// in TUs of their own. Placeholder names: rename once the functions are known.
#include "battle/battle_engine/Unk_7e89c0.h"

// 0x71007e99b0
void Unk_7e99b0(Unk_7e99b0_Self* self, const Unk_7e99b0_Self* other) {
    self->field_8 = other->field_8;
    self->field_20 = other->field_20;
}

// 0x71007e9b00
void Unk_7e9b00(Unk_7e9b00_Node* self, Unk_7e9b00_Node* next) {
    self->field_18 = next;
    if (next != nullptr)
        next->field_10 = self;
}

// 0x71007e9b10
void Unk_7e9b10(Unk_7e9b00_Node* self) {
    Unk_7e9b00_Node* prev = self->field_10;
    Unk_7e9b00_Node* next = self->field_18;
    if (prev != nullptr)
        prev->field_18 = next;
    if (next != nullptr)
        next->field_10 = prev;
    self->field_10 = nullptr;
    self->field_18 = nullptr;
}

// 0x71007e9c80
void Unk_7e9c80(Unk_7e9b00_Node* self, bool value) {
    self->field_3c_29 = value;
}

// 0x71007e9ca0
void Unk_7e9ca0(Unk_7e9b00_Node* self, bool value) {
    self->field_3c_26 = value;
}

// 0x71007e9cc0
void Unk_7e9cc0(Unk_7e9b00_Node* self, bool value) {
    self->field_3c_24 = value;
}

// 0x71007e9d60
Unk_7e9dc0_Var* Unk_7e9d60(Unk_7e9d60_Frame* self, u16 label) {
    if (label <= 0x7a)
        return self->field_8[label];
    return nullptr;
}

// 0x71007e9d80
void Unk_7e9d80(Unk_7e9d60_Frame* self, Unk_7e9dc0_Var* var) {
    u16 label = Unk_7e9f40_getField8(reinterpret_cast<const Unk_7e9f40*>(var));
    if (label <= 0x7a)
        self->field_8[label] = var;
}

// 0x71007e9ed0
void Unk_7e9ed0(Unk_7e9dc0_Var* self, s32 ratio) {
    if (self->field_a == 3) {
        s32 value = static_cast<u64>(static_cast<s64>(self->field_c) * ratio + 0x800) >> 12;
        if (self->field_10 != 0 || self->field_14 != 0) {
            if (value < self->field_10)
                value = self->field_10;
            if (self->field_14 < value)
                value = self->field_14;
        }
        self->field_c = value;
    }
}

// 0x71007e9f20
void Unk_7e9f20(Unk_7e9dc0_Var* self, void* value) {
    self->field_c = 0;
    self->field_10 = 0;
    self->field_14 = 0;
    self->field_18 = value;
    self->field_a = 0;
}

// 0x71007e9d20
void Unk_7e9d20(Unk_7e9d60_Frame* self) {
    for (s32 i = 0; i < 0x7b; i++)
        self->field_8[i] = nullptr;
}
