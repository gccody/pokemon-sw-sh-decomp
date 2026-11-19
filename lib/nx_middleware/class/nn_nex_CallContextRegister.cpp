// Scope: common
// Small virtual functions of a library class (tools/leafgen.py members): placeholder
// member names vf<slot>, placeholder structs. The class's name is its RTTI's.
#include <types.h>

struct Unk_15a9140 {
    u8 _0[0x38];
    u32 field_38;
};
PKMN_OFFSET_ASSERT(Unk_15a9140, field_38, 0x38);

namespace nn {
namespace nex {
class CallContextRegister {
public:
    void vf5();
    u32 vf9();
    u32 vf11();
    u32 vf14();
    void vf15();
    const char* vf2();
    void vf4();
};
}  // namespace nex
}  // namespace nn

// 0x71015a90f0
void nn::nex::CallContextRegister::vf5() {
}

// 0x71015a9120
u32 nn::nex::CallContextRegister::vf9() {
    return 1;
}

// 0x71015a9130
u32 nn::nex::CallContextRegister::vf11() {
    return 1;
}

// 0x71015a9140
u32 nn::nex::CallContextRegister::vf14() {
    const Unk_15a9140* self = reinterpret_cast<const Unk_15a9140*>(this);
    return self->field_38;
}

// 0x71015a9150
void nn::nex::CallContextRegister::vf15() {
}

// 0x71015d46c0
const char* nn::nex::CallContextRegister::vf2() {
    return "CallContextRegister";
}

// 0x71015d4730
void nn::nex::CallContextRegister::vf4() {
}
