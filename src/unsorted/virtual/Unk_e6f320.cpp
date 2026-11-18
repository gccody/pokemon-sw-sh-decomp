// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

class Unk_23f3670 {
public:
    virtual ~Unk_23f3670();
};

// 0x7100e6f320, 0x7100e6f330
Unk_23f3670::~Unk_23f3670() {}
