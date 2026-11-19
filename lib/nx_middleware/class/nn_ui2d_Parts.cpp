// Scope: common
// Small virtual functions of a library class (tools/leafgen.py members): placeholder
// member names vf<slot>, placeholder structs. The class's name is its RTTI's.
#include <types.h>

struct Unk_17b0630 {
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
    virtual void vf18();
    virtual void vf19();
    virtual void vf20();
    virtual void vf21();
    virtual void vf22();
    virtual void vf23();
    virtual void vf24(u64);
};

struct Unk_17b06e0 {
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
    virtual void vf18();
    virtual void vf19();
    virtual void vf20();
    virtual void vf21();
    virtual void vf22();
    virtual void vf23();
    virtual void vf24();
    virtual void vf25();
    virtual void vf26(u64);
};

namespace nn {
namespace ui2d {
class Parts {
public:
    void vf25(u64 value);
    void vf27(u64 value);
};
}  // namespace ui2d
}  // namespace nn

// 0x71017b0630
void nn::ui2d::Parts::vf25(u64 value) {
    Unk_17b0630* self = reinterpret_cast<Unk_17b0630*>(this);
    self->vf24(value);
}

// 0x71017b06e0
void nn::ui2d::Parts::vf27(u64 value) {
    Unk_17b06e0* self = reinterpret_cast<Unk_17b06e0*>(this);
    self->vf26(value);
}
