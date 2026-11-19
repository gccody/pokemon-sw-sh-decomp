// Scope: common
// Small virtual functions of a library class (tools/leafgen.py members): placeholder
// member names vf<slot>, placeholder structs. The class's name is its RTTI's.
// RTTI: N2nn4ui2d28TransitionConditionIsDecidedE
#include <types.h>

struct Unk_17a2e30_arg1 {
    u8 _0[0x10];
    u32 field_10;
};
PKMN_OFFSET_ASSERT(Unk_17a2e30_arg1, field_10, 0x10);

namespace nn {
namespace ui2d {
class TransitionConditionIsDecided {
public:
    bool vf2(const Unk_17a2e30_arg1* value);
};
}  // namespace ui2d
}  // namespace nn

// 0x71017a2e30
bool nn::ui2d::TransitionConditionIsDecided::vf2(const Unk_17a2e30_arg1* value) {
    return value->field_10 == 4;
}
