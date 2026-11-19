// Scope: common
// Small virtual functions of a library class (tools/leafgen.py members): placeholder
// member names vf<slot>, placeholder structs. The class's name is its RTTI's.
#include <types.h>

struct Unk_58bdc0 {
    u8 _0[0x10];
    u32 field_10;
};
PKMN_OFFSET_ASSERT(Unk_58bdc0, field_10, 0x10);

struct Unk_58bcd0 {
    u8 _0[0x20];
    u64 field_20;
};
PKMN_OFFSET_ASSERT(Unk_58bcd0, field_20, 0x20);

struct Unk_58bce0 {
    u8 _0[0x28];
    u8 field_28;
};
PKMN_OFFSET_ASSERT(Unk_58bce0, field_28, 0x28);

struct Unk_58bcf0 {
    u8 _0[0x58];
    u8 field_58;
};
PKMN_OFFSET_ASSERT(Unk_58bcf0, field_58, 0x58);

struct Unk_58bd00 {
    u8 _0[0x88];
    u64 field_88;
};
PKMN_OFFSET_ASSERT(Unk_58bd00, field_88, 0x88);

struct Unk_58bd10 {
    u8 _0[0x88];
    u64 field_88;
};
PKMN_OFFSET_ASSERT(Unk_58bd10, field_88, 0x88);

namespace SiSDK3 {
class SiIONXMemoryMappedFile {
public:
    u32 vf4();
    u64 vf7();
    const u8* vf8();
    const u8* vf9();
    u64 vf10();
    u64 vf11();
};
}  // namespace SiSDK3

// 0x710058bcd0
u64 SiSDK3::SiIONXMemoryMappedFile::vf7() {
    const Unk_58bcd0* self = reinterpret_cast<const Unk_58bcd0*>(this);
    return self->field_20;
}

// 0x710058bce0
const u8* SiSDK3::SiIONXMemoryMappedFile::vf8() {
    const Unk_58bce0* self = reinterpret_cast<const Unk_58bce0*>(this);
    return &self->field_28;
}

// 0x710058bcf0
const u8* SiSDK3::SiIONXMemoryMappedFile::vf9() {
    const Unk_58bcf0* self = reinterpret_cast<const Unk_58bcf0*>(this);
    return &self->field_58;
}

// 0x710058bd00
u64 SiSDK3::SiIONXMemoryMappedFile::vf10() {
    const Unk_58bd00* self = reinterpret_cast<const Unk_58bd00*>(this);
    return self->field_88;
}

// 0x710058bd10
u64 SiSDK3::SiIONXMemoryMappedFile::vf11() {
    const Unk_58bd10* self = reinterpret_cast<const Unk_58bd10*>(this);
    return self->field_88;
}

// 0x710058bdc0
u32 SiSDK3::SiIONXMemoryMappedFile::vf4() {
    const Unk_58bdc0* self = reinterpret_cast<const Unk_58bdc0*>(this);
    return self->field_10;
}
