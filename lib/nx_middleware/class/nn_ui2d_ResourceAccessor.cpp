// Scope: common
// Small virtual functions of a library class (tools/leafgen.py members): placeholder
// member names vf<slot>, placeholder structs. The class's name is its RTTI's.
// RTTI: N2nn4ui2d16ResourceAccessorE
#include <types.h>

struct Unk_17b2f60 {
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8(u64, u64, u64);
};

namespace nn {
namespace ui2d {
class ResourceAccessor {
public:
    u64 vf5();
    void vf6();
    void vf7();
    void vf9(u64 value, u64 arg2, u64 arg3);
};
}  // namespace ui2d
}  // namespace nn

// 0x71017b2d00
void nn::ui2d::ResourceAccessor::vf7() {
}

// 0x71017b2f40
u64 nn::ui2d::ResourceAccessor::vf5() {
    return 0;
}

// 0x71017b2f50
void nn::ui2d::ResourceAccessor::vf6() {
}

// 0x71017b2f60
void nn::ui2d::ResourceAccessor::vf9(u64 value, u64 arg2, u64 arg3) {
    Unk_17b2f60* self = reinterpret_cast<Unk_17b2f60*>(this);
    self->vf8(value, arg2, arg3);
}
