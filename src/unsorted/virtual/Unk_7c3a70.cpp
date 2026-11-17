// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

class Unk_23aa6d0 {
public:
    virtual ~Unk_23aa6d0();
};

// 0x71007c3a70, 0x71007cd950
Unk_23aa6d0::~Unk_23aa6d0() {}
