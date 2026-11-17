// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

class Unk_23bd320 {
public:
    virtual ~Unk_23bd320() {}
    virtual void vf2();
};

class Unk_23bd490 : public Unk_23bd320 {
public:
    void vf2() override;
};

// 0x71008f3740
void Unk_23bd490::vf2() {}
