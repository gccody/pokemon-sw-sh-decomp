// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

class Unk_2417d38 {
public:
    virtual ~Unk_2417d38();
    virtual u64 vf2();
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_2417d38, field_8, 0x8);

// 0x71010f8e00, 0x71010f92b0
Unk_2417d38::~Unk_2417d38() {}

// 0x71010f92c0
u64 Unk_2417d38::vf2() {
    return field_8;
}

class Unk_2417d10 {
public:
    virtual ~Unk_2417d10();
    virtual u64 vf2();
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_2417d10, field_8, 0x8);

// 0x71010f9280, 0x71010f9290
Unk_2417d10::~Unk_2417d10() {}

// 0x71010f92a0
u64 Unk_2417d10::vf2() {
    return field_8;
}
