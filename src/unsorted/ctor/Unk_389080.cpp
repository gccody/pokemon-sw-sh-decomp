// Scope: common
// Constructors that call their base's and set the vptr: `Unk_D::Unk_D() {}`.
// Placeholder classes, named after their vtables: only what the constructors
// need (a base constructor to call, and a key function elsewhere, so that the
// vtable is another TU's).
#include <types.h>

class Unk_23836c0 {
public:
    Unk_23836c0();
    virtual ~Unk_23836c0();
};

class Unk_23823e8 : public Unk_23836c0 {
public:
    Unk_23823e8();
    ~Unk_23823e8() override;
    u8 _8[0x8];
    u64 field_10;
};
PKMN_OFFSET_ASSERT(Unk_23823e8, field_10, 0x10);

class Unk_2382a40 {
public:
    Unk_2382a40();
    virtual ~Unk_2382a40();
};

class Unk_2382ac0 {
public:
    Unk_2382ac0();
    virtual ~Unk_2382ac0();
};

// 0x7100389080
Unk_23823e8::Unk_23823e8() : field_10(0) {}

// 0x7100394ee0
Unk_2382a40::Unk_2382a40() {}

// 0x71003953b0
Unk_2382ac0::Unk_2382ac0() {}
