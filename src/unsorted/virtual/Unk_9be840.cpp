// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

class Unk_23c4e70 {
public:
    virtual ~Unk_23c4e70();
};

// 0x71009be840, 0x71009be850
Unk_23c4e70::~Unk_23c4e70() {}
