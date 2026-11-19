// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

class Unk_243d920 {
public:
    virtual ~Unk_243d920();
};

// 0x710146cc90, 0x710146cf90
Unk_243d920::~Unk_243d920() {}
