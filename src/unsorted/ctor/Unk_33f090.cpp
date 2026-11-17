// Scope: common
// Constructors that call their base's and set the vptr: `Unk_D::Unk_D() {}`.
// Placeholder classes, named after their vtables: only what the constructors
// need (a base constructor to call, and a key function elsewhere, so that the
// vtable is another TU's).
#include <types.h>

class Unk_237eb18 {
public:
    Unk_237eb18();
    virtual ~Unk_237eb18();
};

class Unk_237ece0 : public Unk_237eb18 {
public:
    Unk_237ece0();
    ~Unk_237ece0() override;
    u8 _8[0x30];
    u32 field_38;
};
PKMN_OFFSET_ASSERT(Unk_237ece0, field_38, 0x38);

// 0x710033f090
Unk_237ece0::Unk_237ece0() : field_38(0) {}
