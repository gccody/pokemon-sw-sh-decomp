// Scope: common
// Small virtual functions of a library class (tools/leafgen.py members): placeholder
// member names vf<slot>, placeholder structs. The class's name is its RTTI's.
#include <types.h>

struct Unk_15d3560 {
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
    u8 _8[0x30];
    u32 field_38;
};
PKMN_OFFSET_ASSERT(Unk_15d3560, field_38, 0x38);

namespace nn {
namespace nex {
class SystemComponentGroup {
public:
    const char* vf2();
    void vf4();
    void vf6();
    void vf7();
    u32 vf14();
};
}  // namespace nex
}  // namespace nn

// 0x71015d3560
u32 nn::nex::SystemComponentGroup::vf14() {
    Unk_15d3560* self = reinterpret_cast<Unk_15d3560*>(this);
    self->vf15();
    return self->field_38;
}

// 0x71015d4830
const char* nn::nex::SystemComponentGroup::vf2() {
    return "SystemComponentGroup";
}

// 0x71015d48a0
void nn::nex::SystemComponentGroup::vf4() {
}

// 0x71015d48b0
void nn::nex::SystemComponentGroup::vf6() {
}

// 0x71015d48c0
void nn::nex::SystemComponentGroup::vf7() {
}
