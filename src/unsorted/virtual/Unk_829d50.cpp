// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

class Unk_23acc18 {
public:
    virtual ~Unk_23acc18();
};

// 0x7100829d50, 0x7100829d60
Unk_23acc18::~Unk_23acc18() {}
