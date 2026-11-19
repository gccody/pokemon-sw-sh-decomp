// Scope: common
// Small virtual functions of a library class (tools/leafgen.py members): placeholder
// member names vf<slot>, placeholder structs. The class's name is its RTTI's.
#include <types.h>

struct Unk_57ff50 {
    u8 _0[0x10];
    u32 field_10;
};
PKMN_OFFSET_ASSERT(Unk_57ff50, field_10, 0x10);

struct Unk_57f990 {
    u8 _0[0x30];
    u32 field_30;
};
PKMN_OFFSET_ASSERT(Unk_57f990, field_30, 0x30);

struct Unk_57ff60 {
    u8 _0[0x18];
    bool field_18;
};
PKMN_OFFSET_ASSERT(Unk_57ff60, field_18, 0x18);

struct Unk_57ff70 {
    u8 _0[0x18];
    u8 field_18;
};
PKMN_OFFSET_ASSERT(Unk_57ff70, field_18, 0x18);

namespace SiSDK3 {
class SiIOCSVDocument {
public:
    u32 vf4();
    u32 vf9();
    void vf21(bool value);
    u8 vf22();
};
}  // namespace SiSDK3

// 0x710057f990
u32 SiSDK3::SiIOCSVDocument::vf9() {
    const Unk_57f990* self = reinterpret_cast<const Unk_57f990*>(this);
    return self->field_30;
}

// 0x710057ff50
u32 SiSDK3::SiIOCSVDocument::vf4() {
    const Unk_57ff50* self = reinterpret_cast<const Unk_57ff50*>(this);
    return self->field_10;
}

// 0x710057ff60
void SiSDK3::SiIOCSVDocument::vf21(bool value) {
    Unk_57ff60* self = reinterpret_cast<Unk_57ff60*>(this);
    self->field_18 = value;
}

// 0x710057ff70
u8 SiSDK3::SiIOCSVDocument::vf22() {
    const Unk_57ff70* self = reinterpret_cast<const Unk_57ff70*>(this);
    return self->field_18;
}
