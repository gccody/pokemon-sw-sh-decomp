// Scope: common
// Small virtual functions of a library class (tools/leafgen.py members): placeholder
// member names vf<slot>, placeholder structs. The class's name is its RTTI's.
#include <types.h>

extern u32 Unk_1f3d294;

namespace nn {
namespace nex {
class QueuingSocket {
public:
    u32 vf3();
    u32 vf6();
};
}  // namespace nex
}  // namespace nn

// 0x710160f5d0
u32 nn::nex::QueuingSocket::vf6() {
    return 1;
}

// 0x710160f5e0
u32 nn::nex::QueuingSocket::vf3() {
    return Unk_1f3d294;
}
