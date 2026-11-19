// Scope: common
// Small virtual functions of a library class (tools/leafgen.py members): placeholder
// member names vf<slot>, placeholder structs. The class's name is its RTTI's.
#include <types.h>

struct Unk_5654d0 {
    u8 _0[0x18];
    u32 field_18;
};
PKMN_OFFSET_ASSERT(Unk_5654d0, field_18, 0x18);

struct Unk_564a20 {
    u8 _0[0x20];
    u64 field_20;
};
PKMN_OFFSET_ASSERT(Unk_564a20, field_20, 0x20);

struct Unk_564a30 {
    u8 _0[0x20];
    u64 field_20;
};
PKMN_OFFSET_ASSERT(Unk_564a30, field_20, 0x20);

struct Unk_564a40 {
    u8 _0[0x28];
    u64 field_28;
};
PKMN_OFFSET_ASSERT(Unk_564a40, field_28, 0x28);

struct Unk_564a50 {
    u8 _0[0x64];
    u8 field_64;
};
PKMN_OFFSET_ASSERT(Unk_564a50, field_64, 0x64);

struct Unk_5650c0 {
    u8 _0[0x3fc];
    u32 field_3fc;
};
PKMN_OFFSET_ASSERT(Unk_5650c0, field_3fc, 0x3fc);

struct Unk_5650d0 {
    u8 _0[0x7c];
    u8 field_7c;
};
PKMN_OFFSET_ASSERT(Unk_5650d0, field_7c, 0x7c);

struct Unk_565120 {
    u8 _0[0x440];
    u32 field_440;
};
PKMN_OFFSET_ASSERT(Unk_565120, field_440, 0x440);

struct Unk_5653e0 {
    u8 _0[0x7c];
    u8 field_7c;
};
PKMN_OFFSET_ASSERT(Unk_5653e0, field_7c, 0x7c);

struct Unk_5649e0 {
    u8 _0[0x30];
    u8 field_30;
};
PKMN_OFFSET_ASSERT(Unk_5649e0, field_30, 0x30);

struct Unk_564a00 {
    u8 _0[0x60];
    u32 field_60;
};
PKMN_OFFSET_ASSERT(Unk_564a00, field_60, 0x60);

struct Unk_5649f0 {
    u8 _0[0x28];
    u8 field_28;
};
PKMN_OFFSET_ASSERT(Unk_5649f0, field_28, 0x28);

namespace SiSDK3 {
class SiGfxNXVertexFormat {
public:
    u32 vf4();
    u64 vf5();
    u64 vf6();
    u64 vf7();
    const u8* vf8();
    void vf9();
    void vf11();
    void vf12();
    void vf13();
    void vf14();
    void vf15();
    u32 vf16();
    void vf21();
    u32 vf22();
    const u8* vf23();
    u32 vf25();
    const u8* vf32();
    const u8* vf36();
    u32 vf37();
    const u8* vf3();
};
}  // namespace SiSDK3

// 0x71005649e0
const u8* SiSDK3::SiGfxNXVertexFormat::vf36() {
    const Unk_5649e0* self = reinterpret_cast<const Unk_5649e0*>(this);
    return &self->field_30;
}

// 0x71005649f0
const u8* SiSDK3::SiGfxNXVertexFormat::vf3() {
    const Unk_5649f0* self = reinterpret_cast<const Unk_5649f0*>(this);
    return &self->field_28;
}

// 0x7100564a00
u32 SiSDK3::SiGfxNXVertexFormat::vf37() {
    const Unk_564a00* self = reinterpret_cast<const Unk_564a00*>(this);
    return self->field_60;
}

// 0x7100564a20
u64 SiSDK3::SiGfxNXVertexFormat::vf5() {
    const Unk_564a20* self = reinterpret_cast<const Unk_564a20*>(this);
    return self->field_20;
}

// 0x7100564a30
u64 SiSDK3::SiGfxNXVertexFormat::vf6() {
    const Unk_564a30* self = reinterpret_cast<const Unk_564a30*>(this);
    return self->field_20;
}

// 0x7100564a40
u64 SiSDK3::SiGfxNXVertexFormat::vf7() {
    const Unk_564a40* self = reinterpret_cast<const Unk_564a40*>(this);
    return self->field_28;
}

// 0x7100564a50
const u8* SiSDK3::SiGfxNXVertexFormat::vf8() {
    const Unk_564a50* self = reinterpret_cast<const Unk_564a50*>(this);
    return &self->field_64;
}

// 0x7100564a60
void SiSDK3::SiGfxNXVertexFormat::vf9() {
}

// 0x7100564a80
void SiSDK3::SiGfxNXVertexFormat::vf11() {
}

// 0x7100564a90
void SiSDK3::SiGfxNXVertexFormat::vf12() {
}

// 0x7100564aa0
void SiSDK3::SiGfxNXVertexFormat::vf13() {
}

// 0x7100564ab0
void SiSDK3::SiGfxNXVertexFormat::vf14() {
}

// 0x71005650b0
void SiSDK3::SiGfxNXVertexFormat::vf21() {
}

// 0x71005650c0
u32 SiSDK3::SiGfxNXVertexFormat::vf22() {
    const Unk_5650c0* self = reinterpret_cast<const Unk_5650c0*>(this);
    return self->field_3fc;
}

// 0x71005650d0
const u8* SiSDK3::SiGfxNXVertexFormat::vf23() {
    const Unk_5650d0* self = reinterpret_cast<const Unk_5650d0*>(this);
    return &self->field_7c;
}

// 0x7100565120
u32 SiSDK3::SiGfxNXVertexFormat::vf25() {
    const Unk_565120* self = reinterpret_cast<const Unk_565120*>(this);
    return self->field_440;
}

// 0x71005653e0
const u8* SiSDK3::SiGfxNXVertexFormat::vf32() {
    const Unk_5653e0* self = reinterpret_cast<const Unk_5653e0*>(this);
    return &self->field_7c;
}

// 0x7100565410
void SiSDK3::SiGfxNXVertexFormat::vf15() {
}

// 0x7100565420
u32 SiSDK3::SiGfxNXVertexFormat::vf16() {
    return 0;
}

// 0x71005654d0
u32 SiSDK3::SiGfxNXVertexFormat::vf4() {
    const Unk_5654d0* self = reinterpret_cast<const Unk_5654d0*>(this);
    return self->field_18;
}
