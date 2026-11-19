// Scope: common
// Small virtual functions of a library class (tools/leafgen.py members): placeholder
// member names vf<slot>, placeholder structs. The class's name is its RTTI's.
// RTTI: N2nn4ui2d28DummyRenderTargetTextureInfoE
#include <types.h>

struct Unk_17b8c50 {
    u8 _0[0x10];
    u64 field_10;
};
PKMN_OFFSET_ASSERT(Unk_17b8c50, field_10, 0x10);

void Unk_179cd30(u64);

namespace nn {
namespace ui2d {
class DummyRenderTargetTextureInfo {
public:
    void vf3();
    u32 vf6();
    u64 vf7();
    u64 vf8();
};
}  // namespace ui2d
}  // namespace nn

// 0x71017b8c50
void nn::ui2d::DummyRenderTargetTextureInfo::vf3() {
    Unk_17b8c50* self = reinterpret_cast<Unk_17b8c50*>(this);
    if (self->field_10 != 0) {
        Unk_179cd30(self->field_10);
        self->field_10 = 0;
    }
}

// 0x71017b8f40
u32 nn::ui2d::DummyRenderTargetTextureInfo::vf6() {
    return 1;
}

// 0x71017b8f50
u64 nn::ui2d::DummyRenderTargetTextureInfo::vf7() {
    return 0;
}

// 0x71017b8f60
u64 nn::ui2d::DummyRenderTargetTextureInfo::vf8() {
    return 0;
}
