// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

class Unk_23aca78 {
public:
    virtual ~Unk_23aca78();
};

// 0x7100812ca0, 0x7100812cb0
Unk_23aca78::~Unk_23aca78() {}
