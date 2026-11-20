// Scope: common
// The battle engine's event system (0x71007e89c0 to 0x71007ed7b0): its frames
// of variables and its handler list. Placeholder names: rename once the
// functions are known.
#include "battle/battle_engine/Unk_7e89c0.h"

static inline Unk_7e9b00_Node* Unk_7e8a20_FirstHandler(const Unk_7e8a20* self) {
    return Unk_7eaf40_getField1588(Unk_7fe240_getField88(self->field_8));
}

static inline Unk_7e9b00_Node* Unk_7e8a20_Next(const Unk_7e9b00_Node* node) {
    return Unk_7e9b30_getField18(reinterpret_cast<const Unk_7e9b30*>(node));
}

// 0x71007e8c70
void Unk_7e8c70(Unk_7e8a20* self,
                u32 arg1,
                u32 arg2,
                u32 arg3,
                u32 arg4,
                u32 arg5,
                void* arg6,
                u32 arg7) {
    Unk_7eadb0(const_cast<Unk_7eaf40*>(Unk_7fe240_getField88(self->field_8)), arg1, arg2, arg3,
               arg4, arg5, arg6, arg7, self->field_78);
}

// 0x71007e8d70
void Unk_7e8d70(Unk_7e8a20* self) {
    Unk_7e9b00_Node* node = Unk_7e8a20_FirstHandler(self);
    while (node != nullptr) {
        Unk_7e9b00_Node* current = node;
        node = Unk_7e8a20_Next(current);
        if (Unk_7e9b70_getField30(reinterpret_cast<const Unk_7e9b70*>(current)) == 8 &&
            Unk_7e9bb0_get(reinterpret_cast<const Unk_7e9bb0*>(current))) {
            if (Unk_7e9bd0_get(reinterpret_cast<const Unk_7e9bd0*>(current)))
                Unk_7e9ca0(current, true);
            else
                Unk_7eaee0(const_cast<Unk_7eaf40*>(Unk_7fe240_getField88(self->field_8)), current);
        }
    }
}

// 0x71007e8e10
void Unk_7e8e10(Unk_7e8a20* self, u16 kind, u8 pokeId) {
    for (Unk_7e9b00_Node* node = Unk_7e8a20_FirstHandler(self); node != nullptr;
         node = Unk_7e8a20_Next(node)) {
        if (Unk_7e9a60_getField3b(reinterpret_cast<const Unk_7e9a60*>(node)) == kind &&
            Unk_7e9b70_getField30(reinterpret_cast<const Unk_7e9b70*>(node)) == pokeId)
            Unk_7e9ac0_update(reinterpret_cast<Unk_7e9ac0*>(node));
    }
}

// 0x71007e8e90
void Unk_7e8e90(Unk_7e8a20* self, u16 kind, u8 pokeId) {
    for (Unk_7e9b00_Node* node = Unk_7e8a20_FirstHandler(self); node != nullptr;
         node = Unk_7e8a20_Next(node)) {
        if (Unk_7e9a60_getField3b(reinterpret_cast<const Unk_7e9a60*>(node)) == kind &&
            Unk_7e9b70_getField30(reinterpret_cast<const Unk_7e9b70*>(node)) == pokeId)
            Unk_7e9ae0_update(reinterpret_cast<Unk_7e9ae0*>(node));
    }
}

// 0x71007e8f10
void Unk_7e8f10(Unk_7e8a20* self) {
    for (Unk_7e9b00_Node* node = Unk_7e8a20_FirstHandler(self); node != nullptr;
         node = Unk_7e8a20_Next(node))
        Unk_7e9ae0_update(reinterpret_cast<Unk_7e9ae0*>(node));
}

// 0x71007e94d0
void Unk_7e94d0(Unk_7e8a20* self) {
    Unk_7ea270(self->field_30);
    Unk_7ea810_set(reinterpret_cast<Unk_7ea810*>(self->field_50));
    self->field_70 = Unk_7ea800(self->field_50);
}

// 0x71007e9510
void Unk_7e9510(Unk_7e8a20* self) {
    Unk_7ea830(self->field_50);
    self->field_70 = Unk_7ea800(self->field_50);
    Unk_7ea2f0(self->field_30);
}

// 0x71007e9550
void Unk_7e9550(Unk_7e8a20* self) {
    if (!Unk_7ea260_check(reinterpret_cast<const Unk_7ea260*>(self->field_30))) {
        Unk_7ea110(self->field_30);
        Unk_7ea5d0(self->field_50);
        self->field_70 = Unk_7ea800(self->field_50);
    }
}

// 0x71007e95a0
void Unk_7e95a0(Unk_7e8a20* self, u16 label, u32 value) {
    Unk_7e9dc0_Var* var = Unk_7ea3b0(self->field_30, label);
    if (var != nullptr) {
        Unk_7e9e10_setField8(reinterpret_cast<Unk_7e9e10*>(var), label);
        Unk_7e9e20_set(reinterpret_cast<Unk_7e9e20*>(var), value);
        Unk_7e9d80(self->field_70, var);
    }
}

// 0x71007e9610
void Unk_7e9610(Unk_7e8a20* self, u16 label, u32 value) {
    Unk_7e9dc0_Var* var = Unk_7ea3b0(self->field_30, label);
    if (var != nullptr) {
        Unk_7e9e10_setField8(reinterpret_cast<Unk_7e9e10*>(var), label);
        Unk_7e9e30_set(reinterpret_cast<Unk_7e9e30*>(var), value);
        Unk_7e9d80(self->field_70, var);
    }
}

// 0x71007e9680
void Unk_7e9680(Unk_7e8a20* self, u16 label, u32 value) {
    Unk_7e9dc0_Var* var = Unk_7ea3b0(self->field_30, label);
    if (var != nullptr) {
        Unk_7e9e10_setField8(reinterpret_cast<Unk_7e9e10*>(var), label);
        Unk_7e9e50_set(reinterpret_cast<Unk_7e9e50*>(var), value);
        Unk_7e9d80(self->field_70, var);
    }
}

// 0x71007e96f0
void Unk_7e96f0(Unk_7e8a20* self, u16 label) {
    Unk_7e9dc0_Var* var = Unk_7e9d60(self->field_70, label);
    if (var != nullptr)
        Unk_7e9ea0_set(reinterpret_cast<Unk_7e9ea0*>(var));
}

// 0x71007e9720
void Unk_7e9720(Unk_7e8a20* self, u16 label, u32 value, u32 min, u32 max) {
    Unk_7e9dc0_Var* var = Unk_7ea3b0(self->field_30, label);
    if (var != nullptr) {
        Unk_7e9e10_setField8(reinterpret_cast<Unk_7e9e10*>(var), label);
        Unk_7e9eb0_set(reinterpret_cast<Unk_7e9eb0*>(var), value, min, max);
        Unk_7e9d80(self->field_70, var);
    }
}

// 0x71007e98a0
void Unk_7e98a0(Unk_7e8a20* self, u16 label, void* value) {
    Unk_7e9dc0_Var* var = Unk_7ea3b0(self->field_30, label);
    if (var != nullptr) {
        Unk_7e9e10_setField8(reinterpret_cast<Unk_7e9e10*>(var), label);
        Unk_7e9f20(var, value);
        Unk_7e9d80(self->field_70, var);
    }
}
