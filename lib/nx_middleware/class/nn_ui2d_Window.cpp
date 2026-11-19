// Scope: common
// Small virtual functions of a library class (tools/leafgen.py members): placeholder
// member names vf<slot>, placeholder structs. The class's name is its RTTI's.
// RTTI: N2nn4ui2d6WindowE
#include <types.h>

struct Unk_17bbff0 {
    u8 _0[0x109];
    u8 field_109;
};
PKMN_OFFSET_ASSERT(Unk_17bbff0, field_109, 0x109);

struct Unk_17bc180 {
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
    virtual void vf14(u64, u32);
};

namespace nn {
namespace ui2d {
class Window {
public:
    u32 vf10();
    void vf15(u64 value, bool arg2);
};
}  // namespace ui2d
}  // namespace nn

// 0x71017bbff0
u32 nn::ui2d::Window::vf10() {
    const Unk_17bbff0* self = reinterpret_cast<const Unk_17bbff0*>(this);
    return self->field_109 + 1;
}

// 0x71017bc180
void nn::ui2d::Window::vf15(u64 value, bool arg2) {
    Unk_17bc180* self = reinterpret_cast<Unk_17bc180*>(this);
    self->vf14(value, arg2);
}
