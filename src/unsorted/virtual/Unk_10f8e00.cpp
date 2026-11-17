// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

class Unk_2417d38 {
public:
    virtual ~Unk_2417d38();
    virtual void vf2();
};

// 0x71010f8e00, 0x71010f92b0
Unk_2417d38::~Unk_2417d38() {}

class Unk_2417d10 {
public:
    virtual ~Unk_2417d10();
    virtual void vf2();
};

// 0x71010f9280, 0x71010f9290
Unk_2417d10::~Unk_2417d10() {}
