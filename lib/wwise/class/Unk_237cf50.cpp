// Scope: common
// Small virtual functions of a library class (tools/leafgen.py members): placeholder
// member names vf<slot>, placeholder structs. The class's name is its RTTI's.
#include <types.h>

struct Unk_319d60 {
    u8 _0[0x78];
    u64 field_78;
};
PKMN_OFFSET_ASSERT(Unk_319d60, field_78, 0x78);

class Unk_237cf50 {
public:
    u64 vf22();
    void vf25();
    u32 vf29();
    u32 vf30();
    void vf31();
    u64 vf32();
    u32 vf33();
    void vf34();
    void vf35();
};

// 0x710030fe50
u64 Unk_237cf50::vf22() {
    return 0;
}

// 0x7100313010
u32 Unk_237cf50::vf29() {
    return 1;
}

// 0x7100313020
u32 Unk_237cf50::vf33() {
    return 0;
}

// 0x7100313030
void Unk_237cf50::vf34() {
}

// 0x7100313040
void Unk_237cf50::vf35() {
}

// 0x7100319910
void Unk_237cf50::vf25() {
}

// 0x7100319920
u32 Unk_237cf50::vf30() {
    return 0;
}

// 0x7100319930
void Unk_237cf50::vf31() {
}

// 0x7100319d60
u64 Unk_237cf50::vf32() {
    const Unk_319d60* self = reinterpret_cast<const Unk_319d60*>(this);
    return self->field_78;
}
