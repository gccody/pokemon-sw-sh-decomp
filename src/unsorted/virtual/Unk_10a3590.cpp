// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>
#include "gflib3/Unk_239a418.h"

class Unk_24108a8 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
};

class Unk_24107e8 : public Unk_239a418, public Unk_24108a8 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_239a418_GetType());
        return &type;
    }

    ~Unk_24107e8() override;
    const Unk_239a418_Type* vf_type() override { return Unk_GetType(); }
    virtual void vf7();
    virtual void vf8();
    u8 _68[0x8];
    Unk_239a418_Ref<Unk_239a418> field_70;
};
PKMN_OFFSET_ASSERT(Unk_24107e8, field_70, 0x70);

// 0x71010a3590: its key function
Unk_24107e8::~Unk_24107e8() {}
