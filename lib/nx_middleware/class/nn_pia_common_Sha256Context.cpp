// Scope: common
// Small virtual functions of a library class (tools/leafgen.py members): placeholder
// member names vf<slot>, placeholder structs. The class's name is its RTTI's.
#include <types.h>

namespace nn {
namespace pia {
namespace common {
class Sha256Context {
public:
    u32 vf2();
    u32 vf3();
};
}  // namespace common
}  // namespace pia
}  // namespace nn

// 0x7101661340
u32 nn::pia::common::Sha256Context::vf2() {
    return 0x20;
}

// 0x7101661350
u32 nn::pia::common::Sha256Context::vf3() {
    return 0x40;
}
