// Scope: common
// Small virtual functions of a library class (tools/leafgen.py members): placeholder
// member names vf<slot>, placeholder structs. The class's name is its RTTI's.
#include <types.h>

struct Unk_17b5cb0 {
    u8 _0[0x140];
    u64 field_140;
};
PKMN_OFFSET_ASSERT(Unk_17b5cb0, field_140, 0x140);

struct Unk_17b5cc0 {
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    u8 _8[0x138];
    u64 field_140;
};
PKMN_OFFSET_ASSERT(Unk_17b5cc0, field_140, 0x140);

namespace nn {
namespace ui2d {
class TextBox {
public:
    bool vf10();
    u64 vf11(u32 value);
    void vf23();
};
}  // namespace ui2d
}  // namespace nn

// 0x71017b5cb0
bool nn::ui2d::TextBox::vf10() {
    const Unk_17b5cb0* self = reinterpret_cast<const Unk_17b5cb0*>(this);
    return self->field_140 != 0;
}

// 0x71017b5cc0
u64 nn::ui2d::TextBox::vf11(u32 value) {
    Unk_17b5cc0* self = reinterpret_cast<Unk_17b5cc0*>(this);
    self->vf10();
    if (value != 0) {
        return 0;
    }
    return self->field_140;
}

// 0x71017b7780
void nn::ui2d::TextBox::vf23() {
}
