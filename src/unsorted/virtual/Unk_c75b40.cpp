// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

class Unk_23dd610 {
public:
    virtual ~Unk_23dd610();
};

// 0x7100c75b40, 0x7100c75b50
Unk_23dd610::~Unk_23dd610() {}
