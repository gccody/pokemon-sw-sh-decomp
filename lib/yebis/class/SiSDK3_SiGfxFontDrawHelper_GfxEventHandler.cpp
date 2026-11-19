// Scope: common
// Small virtual functions of a library class (tools/leafgen.py members): placeholder
// member names vf<slot>, placeholder structs. The class's name is its RTTI's.
// RTTI: N6SiSDK319SiGfxFontDrawHelper15GfxEventHandlerE
#include <types.h>

struct Unk_545ed0 {
    u8 _0[0x10];
    u32 field_10;
};
PKMN_OFFSET_ASSERT(Unk_545ed0, field_10, 0x10);

namespace SiSDK3 {
namespace SiGfxFontDrawHelper {
class GfxEventHandler {
public:
    u32 vf4();
    void vf5();
    void vf6();
};
}  // namespace SiGfxFontDrawHelper
}  // namespace SiSDK3

// 0x7100543260
void SiSDK3::SiGfxFontDrawHelper::GfxEventHandler::vf5() {
}

// 0x7100543270
void SiSDK3::SiGfxFontDrawHelper::GfxEventHandler::vf6() {
}

// 0x7100545ed0
u32 SiSDK3::SiGfxFontDrawHelper::GfxEventHandler::vf4() {
    const Unk_545ed0* self = reinterpret_cast<const Unk_545ed0*>(this);
    return self->field_10;
}
