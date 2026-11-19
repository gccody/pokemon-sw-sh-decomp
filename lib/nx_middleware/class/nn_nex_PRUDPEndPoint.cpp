// Scope: common
// Small virtual functions of a library class (tools/leafgen.py members): placeholder
// member names vf<slot>, placeholder structs. The class's name is its RTTI's.
#include <types.h>

struct Unk_160fed0 {
    u8 _0[0x180];
    u8 field_180;
};
PKMN_OFFSET_ASSERT(Unk_160fed0, field_180, 0x180);

struct Unk_160ff30 {
    u8 _0[0x118];
    u8 field_118;
};
PKMN_OFFSET_ASSERT(Unk_160ff30, field_118, 0x118);

struct Unk_160ff50 {
    u8 _0[0x10c];
    u32 field_10c;
};
PKMN_OFFSET_ASSERT(Unk_160ff50, field_10c, 0x10c);

struct Unk_160ff60 {
    u8 _0[0x110];
    u32 field_110;
};
PKMN_OFFSET_ASSERT(Unk_160ff60, field_110, 0x110);

struct Unk_160ff70 {
    u8 _0[0x10c];
    u32 field_10c;
};
PKMN_OFFSET_ASSERT(Unk_160ff70, field_10c, 0x10c);

struct Unk_160ff80 {
    u8 _0[0x118];
    u8 field_118;
};
PKMN_OFFSET_ASSERT(Unk_160ff80, field_118, 0x118);

struct Unk_160ff90 {
    u8 _0[0x118];
    u8 field_118;
};
PKMN_OFFSET_ASSERT(Unk_160ff90, field_118, 0x118);

struct Unk_160ffa0 {
    u8 _0[0x114];
    u32 field_114;
};
PKMN_OFFSET_ASSERT(Unk_160ffa0, field_114, 0x114);

struct Unk_160ffb0 {
    u8 _0[0x11c];
    u32 field_11c;
};
PKMN_OFFSET_ASSERT(Unk_160ffb0, field_11c, 0x11c);

struct Unk_160ffc0 {
    u8 _0[0x130];
    u32 field_130;
};
PKMN_OFFSET_ASSERT(Unk_160ffc0, field_130, 0x130);

struct Unk_160ffd0 {
    u8 _0[0x128];
    u32 field_128;
};
PKMN_OFFSET_ASSERT(Unk_160ffd0, field_128, 0x128);

struct Unk_160ffe0 {
    u8 _0[0x1f0];
    u64 field_1f0;
};
PKMN_OFFSET_ASSERT(Unk_160ffe0, field_1f0, 0x1f0);

namespace nn {
namespace nex {
class PRUDPEndPoint {
public:
    u8 vf6();
    u8 vf12();
    void vf16(u32 value);
    u32 vf17();
    u32 vf18();
    void vf19();
    void vf20();
    u32 vf21();
    u32 vf25();
    u32 vf26();
    u32 vf27();
    u64 vf31();
};
}  // namespace nex
}  // namespace nn

// 0x710160fed0
u8 nn::nex::PRUDPEndPoint::vf6() {
    const Unk_160fed0* self = reinterpret_cast<const Unk_160fed0*>(this);
    return self->field_180;
}

// 0x710160ff30
u8 nn::nex::PRUDPEndPoint::vf12() {
    const Unk_160ff30* self = reinterpret_cast<const Unk_160ff30*>(this);
    return self->field_118;
}

// 0x710160ff50
void nn::nex::PRUDPEndPoint::vf16(u32 value) {
    Unk_160ff50* self = reinterpret_cast<Unk_160ff50*>(this);
    self->field_10c = value;
}

// 0x710160ff60
u32 nn::nex::PRUDPEndPoint::vf17() {
    const Unk_160ff60* self = reinterpret_cast<const Unk_160ff60*>(this);
    return self->field_110;
}

// 0x710160ff70
u32 nn::nex::PRUDPEndPoint::vf18() {
    const Unk_160ff70* self = reinterpret_cast<const Unk_160ff70*>(this);
    return self->field_10c;
}

// 0x710160ff80
void nn::nex::PRUDPEndPoint::vf19() {
    Unk_160ff80* self = reinterpret_cast<Unk_160ff80*>(this);
    self->field_118 = 1;
}

// 0x710160ff90
void nn::nex::PRUDPEndPoint::vf20() {
    Unk_160ff90* self = reinterpret_cast<Unk_160ff90*>(this);
    self->field_118 = 0;
}

// 0x710160ffa0
u32 nn::nex::PRUDPEndPoint::vf21() {
    const Unk_160ffa0* self = reinterpret_cast<const Unk_160ffa0*>(this);
    return self->field_114;
}

// 0x710160ffb0
u32 nn::nex::PRUDPEndPoint::vf25() {
    const Unk_160ffb0* self = reinterpret_cast<const Unk_160ffb0*>(this);
    return self->field_11c;
}

// 0x710160ffc0
u32 nn::nex::PRUDPEndPoint::vf26() {
    const Unk_160ffc0* self = reinterpret_cast<const Unk_160ffc0*>(this);
    return self->field_130;
}

// 0x710160ffd0
u32 nn::nex::PRUDPEndPoint::vf27() {
    const Unk_160ffd0* self = reinterpret_cast<const Unk_160ffd0*>(this);
    return self->field_128 >> 3;
}

// 0x710160ffe0
u64 nn::nex::PRUDPEndPoint::vf31() {
    const Unk_160ffe0* self = reinterpret_cast<const Unk_160ffe0*>(this);
    return self->field_1f0;
}
