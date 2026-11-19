// Scope: common
// Small virtual functions of a library class (tools/leafgen.py members): placeholder
// member names vf<slot>, placeholder structs. The class's name is its RTTI's.
#include <types.h>

struct Unk_17a3150_arg1 {
    u8 _0[0x10];
    u32 field_10;
};
PKMN_OFFSET_ASSERT(Unk_17a3150_arg1, field_10, 0x10);

namespace nn {
namespace ui2d {
class TransitionConditionIsButtonDecided {
public:
    bool vf2(const Unk_17a3150_arg1* value);
};
}  // namespace ui2d
}  // namespace nn

// 0x71017a3150
bool nn::ui2d::TransitionConditionIsButtonDecided::vf2(const Unk_17a3150_arg1* value) {
    return value->field_10 == 0xb;
}
