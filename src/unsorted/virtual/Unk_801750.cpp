// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

class Unk_23ac998 {
public:
    virtual ~Unk_23ac998();
};

// 0x7100801750, 0x7100801760
Unk_23ac998::~Unk_23ac998() {}

class Unk_23ac9d8 {
public:
    virtual ~Unk_23ac9d8();
};

// 0x7100802330, 0x7100802340
Unk_23ac9d8::~Unk_23ac9d8() {}

class Unk_23ac9f8 {
public:
    virtual ~Unk_23ac9f8();
};

// 0x71008025d0, 0x71008025e0
Unk_23ac9f8::~Unk_23ac9f8() {}
