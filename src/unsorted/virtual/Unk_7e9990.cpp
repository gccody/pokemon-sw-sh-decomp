// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

class Unk_23ac748 {
public:
    virtual ~Unk_23ac748();
};

// 0x71007e9990, 0x71007e99a0
Unk_23ac748::~Unk_23ac748() {}

class Unk_23ac768 {
public:
    virtual ~Unk_23ac768();
};

// 0x71007e9d40, 0x71007e9d50
Unk_23ac768::~Unk_23ac768() {}

class Unk_23ac788 {
public:
    virtual ~Unk_23ac788();
};

// 0x71007e9df0, 0x71007e9e00
Unk_23ac788::~Unk_23ac788() {}
