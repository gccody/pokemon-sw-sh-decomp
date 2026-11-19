// Scope: common
// Small virtual functions of a library class (tools/leafgen.py members): placeholder
// member names vf<slot>, placeholder structs. The class's name is its RTTI's.
// RTTI: N2nn4ui2d7PictureE
#include <types.h>

struct Unk_17b0e00 {
    u8 _0[0xd8];
    u64 field_d8;
};
PKMN_OFFSET_ASSERT(Unk_17b0e00, field_d8, 0xd8);

struct Unk_17b0e10 {
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
    u8 _8[0xd0];
    u64 field_d8;
};
PKMN_OFFSET_ASSERT(Unk_17b0e10, field_d8, 0xd8);

namespace nn {
namespace ui2d {
class Picture {
public:
    bool vf10();
    u64 vf11(u32 value);
};
}  // namespace ui2d
}  // namespace nn

// 0x71017b0e00
bool nn::ui2d::Picture::vf10() {
    const Unk_17b0e00* self = reinterpret_cast<const Unk_17b0e00*>(this);
    return self->field_d8 != 0;
}

// 0x71017b0e10
u64 nn::ui2d::Picture::vf11(u32 value) {
    Unk_17b0e10* self = reinterpret_cast<Unk_17b0e10*>(this);
    self->vf10();
    if (value != 0) {
        return 0;
    }
    return self->field_d8;
}
