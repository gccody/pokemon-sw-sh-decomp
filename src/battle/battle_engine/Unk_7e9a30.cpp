// Scope: common
// The event system's variables as its callers see them (Unk_7e8a20.h), looked
// up in the current frame by label, and a handler node's flags. They call the
// frame's lookup (Unk_7e99b0.cpp) out of line, so they're in another TU.
// Placeholder names: rename once the classes are known.
#include "battle/battle_engine/Unk_7e89c0.h"

// Declared here as they are (leafgen's src/unsorted/leaf/Unk_7e89c0.cpp
// returns u32 from Unk_7e9e70_update, which sets a variable and says whether it
// did).
struct Unk_7e9e70;
bool Unk_7e9e70_update(Unk_7e9e70* self, u32 value);
struct Unk_7e9f50;
u32 Unk_7e9f50_getFieldc(const Unk_7e9f50* self);
struct Unk_7e9f60;
u64 Unk_7e9f60_getField18(const Unk_7e9f60* self);
void Unk_7e9ed0(Unk_7e9dc0_Var* self, s32 ratio);

// 0x71007e97b0
bool Unk_7e97b0(void* self, u32 label, u32 value) {
    Unk_7e9dc0_Var* var = Unk_7e9d60(static_cast<Unk_7e8a20*>(self)->field_70, label);
    if (var != nullptr)
        return Unk_7e9e70_update(reinterpret_cast<Unk_7e9e70*>(var), value);
    return false;
}

// 0x71007e97f0
void Unk_7e97f0(void* self, u32 label, u32 ratio) {
    Unk_7e9dc0_Var* var = Unk_7e9d60(static_cast<Unk_7e8a20*>(self)->field_70, label);
    if (var != nullptr)
        Unk_7e9ed0(var, ratio);
}

// 0x71007e9830
u32 Unk_7e9830(void* self, u32 label) {
    Unk_7e9dc0_Var* var = Unk_7e9d60(static_cast<Unk_7e8a20*>(self)->field_70, label);
    if (var != nullptr)
        return Unk_7e9f50_getFieldc(reinterpret_cast<const Unk_7e9f50*>(var));
    return 0;
}

// 0x71007e9860
bool Unk_7e9860(void* self, u32 label, void* out) {
    Unk_7e9dc0_Var* var = Unk_7e9d60(static_cast<Unk_7e8a20*>(self)->field_70, label);
    if (var == nullptr)
        return false;
    *static_cast<u32*>(out) = Unk_7e9f50_getFieldc(reinterpret_cast<const Unk_7e9f50*>(var));
    return true;
}

// 0x71007e9910
u64 Unk_7e9910(void* self, u32 label) {
    Unk_7e9dc0_Var* var = Unk_7e9d60(static_cast<Unk_7e8a20*>(self)->field_70, label);
    if (var != nullptr)
        return Unk_7e9f60_getField18(reinterpret_cast<const Unk_7e9f60*>(var));
    return 0;
}

// 0x71007e9a00 - a table of 32-bit values at +0x40, indexed by a byte.
// NON_MATCHING: the original adds the index with `uxtb` (a u8 parameter);
// with the u32 its callers' declaration gives (src/unsorted/leaf/Unk_819600.cpp)
// the byte is masked first. One instruction more.
u32 Unk_7e9a00(u64 self, u32 index) {
    u8 i = index;
    return *reinterpret_cast<const u32*>(self + i * 4 + 0x40);
}

// 0x71007e9a10
// NON_MATCHING: as Unk_7e9a00, the u8 index is masked instead of extended.
void Unk_7e9a10(u64 self, u32 index, u32 value) {
    u8 i = index;
    *reinterpret_cast<u32*>(self + i * 4 + 0x40) = value;
}

// 0x71007e9a30
void Unk_7e9a30(void* self) {
    Unk_7e9b00_Node* node = static_cast<Unk_7e9b00_Node*>(self);
    if (node->field_3c_24)
        node->field_3c_25 = true;
}
