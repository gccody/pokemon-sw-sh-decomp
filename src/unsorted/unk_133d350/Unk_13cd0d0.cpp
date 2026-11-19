// Scope: common
//
// A class on Unk_2434918 (vtable 0x71024356d0): a reference and a word of its
// own, after its base's fields (in their tail padding). Placeholder names:
// rename once the class is known.
#include "unsorted/unk_133d350/Unk_2434918.h"

class Unk_24356d0 : public Unk_2434918 {
public:
    ~Unk_24356d0() override;
    const Unk_239a418_Type* vf_type() override;
    bool vf7(bool value) override;

    Unk_239a418_Ref<Unk_239a418> field_128;
    u64 field_130;
};
static_assert(sizeof(Unk_24356d0) == 0x140, "Unk_24356d0");
static_assert(__builtin_offsetof(Unk_24356d0, field_128) == 0x128, "Unk_24356d0::field_128");

// 0x71013cdb50, 0x71013cdc50 (D0), thunks 0x71013cddc0/0x71013cdec0 (+0x48)
// and 0x71013ce0a0/0x71013ce1a0 (+0x50)
Unk_24356d0::~Unk_24356d0() {}
