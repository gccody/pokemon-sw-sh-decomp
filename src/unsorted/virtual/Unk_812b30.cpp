// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

class Unk_23aca58 {
public:
    virtual ~Unk_23aca58();
};

// 0x7100812b30, 0x7100812b40
Unk_23aca58::~Unk_23aca58() {}
