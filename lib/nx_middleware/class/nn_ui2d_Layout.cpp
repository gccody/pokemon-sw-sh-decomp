// Scope: common
// Small virtual functions of a library class (tools/leafgen.py members): placeholder
// member names vf<slot>, placeholder structs. The class's name is its RTTI's.
#include <types.h>

struct Unk_179e870_arg1 {
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
    virtual void vf10(u64, u32);
};

struct Unk_179e870 {
    u8 _0[0x18];
    u64 field_18;
};
PKMN_OFFSET_ASSERT(Unk_179e870, field_18, 0x18);

struct Unk_179e8a0_arg1 {
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
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
    virtual void vf14();
    virtual void vf15();
    virtual void vf16();
    virtual void vf17();
};

namespace nn {
namespace ui2d {
class Layout {
public:
    void vf4(Unk_179e870_arg1* value);
    void vf5(Unk_179e8a0_arg1* value);
    void vf20();
};
}  // namespace ui2d
}  // namespace nn

// 0x710179e670
void nn::ui2d::Layout::vf20() {
}

// 0x710179e870
void nn::ui2d::Layout::vf4(Unk_179e870_arg1* value) {
    const Unk_179e870* self = reinterpret_cast<const Unk_179e870*>(this);
    if (self->field_18 != 0) {
        value->vf10(self->field_18, 1);
    }
}

// 0x710179e8a0
void nn::ui2d::Layout::vf5(Unk_179e8a0_arg1* value) {
    value->vf17();
}
