// Scope: common
// Small virtual functions of a library class (tools/leafgen.py members): placeholder
// member names vf<slot>, placeholder structs. The class's name is its RTTI's.
#include <types.h>

struct Unk_349eb0 {
    u8 _0[0xd4];
    u32 field_d4;
};
PKMN_OFFSET_ASSERT(Unk_349eb0, field_d4, 0xd4);

class Unk_237f4c8 {
public:
    u32 vf5();
    u32 vf6(u32 /*unused*/, u32 arg2);
    void vf7();
    void vf8();
};

// 0x7100349ea0
u32 Unk_237f4c8::vf5() {
    return 1;
}

// 0x7100349eb0
u32 Unk_237f4c8::vf6(u32 /*unused*/, u32 arg2) {
    const Unk_349eb0* self = reinterpret_cast<const Unk_349eb0*>(this);
    if (arg2 == 1) {
        return self->field_d4;
    }
    return arg2;
}

// 0x7100349ed0
void Unk_237f4c8::vf7() {
}

// 0x7100349ee0
void Unk_237f4c8::vf8() {
}
