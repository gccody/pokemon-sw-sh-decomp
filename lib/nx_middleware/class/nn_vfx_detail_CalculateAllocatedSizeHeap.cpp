// Scope: common
// Small virtual functions of a library class (tools/leafgen.py members): placeholder
// member names vf<slot>, placeholder structs. The class's name is its RTTI's.
#include <types.h>

struct Unk_17d4140_8 {
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3(u64);
};

struct Unk_17d4140 {
    u8 _0[0x8];
    Unk_17d4140_8* field_8;
    u8 _10[0x8];
    u32 field_18;
};
PKMN_OFFSET_ASSERT(Unk_17d4140, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_17d4140, field_18, 0x18);

namespace nn {
namespace vfx {
namespace detail {
class CalculateAllocatedSizeHeap {
public:
    void vf3(u64 value);
};
}  // namespace detail
}  // namespace vfx
}  // namespace nn

// 0x71017d4140
void nn::vfx::detail::CalculateAllocatedSizeHeap::vf3(u64 value) {
    Unk_17d4140* self = reinterpret_cast<Unk_17d4140*>(this);
    self->field_18 = self->field_18 - 1;
    self->field_8->vf3(value);
}
