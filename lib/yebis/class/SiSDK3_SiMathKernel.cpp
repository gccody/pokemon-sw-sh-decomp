// Scope: common
// Small virtual functions of a library class (tools/leafgen.py members): placeholder
// member names vf<slot>, placeholder structs. The class's name is its RTTI's.
#include <types.h>

struct Unk_594ca0 {
    u8 _0[0x10];
    u32 field_10;
};
PKMN_OFFSET_ASSERT(Unk_594ca0, field_10, 0x10);

struct Unk_594be0 {
    u8 _0[0x18];
    u64 field_18;
};
PKMN_OFFSET_ASSERT(Unk_594be0, field_18, 0x18);

struct Unk_594bf0 {
    u8 _0[0x28];
    u64 field_28;
};
PKMN_OFFSET_ASSERT(Unk_594bf0, field_28, 0x28);

namespace SiSDK3 {
class SiMathKernel {
public:
    u32 vf4();
    u64 vf6();
    u64 vf7();
};
}  // namespace SiSDK3

// 0x7100594be0
u64 SiSDK3::SiMathKernel::vf6() {
    const Unk_594be0* self = reinterpret_cast<const Unk_594be0*>(this);
    return self->field_18;
}

// 0x7100594bf0
u64 SiSDK3::SiMathKernel::vf7() {
    const Unk_594bf0* self = reinterpret_cast<const Unk_594bf0*>(this);
    return self->field_28;
}

// 0x7100594ca0
u32 SiSDK3::SiMathKernel::vf4() {
    const Unk_594ca0* self = reinterpret_cast<const Unk_594ca0*>(this);
    return self->field_10;
}
