// Scope: common
// Small virtual functions of a library class (tools/leafgen.py members): placeholder
// member names vf<slot>, placeholder structs. The class's name is its RTTI's.
#include <types.h>

struct Unk_4f10c0 {
    u8 _0[0x10];
    u32 field_10;
};
PKMN_OFFSET_ASSERT(Unk_4f10c0, field_10, 0x10);

namespace SiSDK3 {
class SiGfxTextureChunkHandler {
public:
    u32 vf4();
    u32 vf9();
};
}  // namespace SiSDK3

// 0x71004f10c0
u32 SiSDK3::SiGfxTextureChunkHandler::vf4() {
    const Unk_4f10c0* self = reinterpret_cast<const Unk_4f10c0*>(this);
    return self->field_10;
}

// 0x710057a640
u32 SiSDK3::SiGfxTextureChunkHandler::vf9() {
    return 1;
}
