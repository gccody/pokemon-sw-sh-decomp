// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

class Unk_23ad038 {
public:
    virtual ~Unk_23ad038();
};

// 0x7100831000, 0x7100831010
Unk_23ad038::~Unk_23ad038() {}
