// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>
#include "unsorted/Unk_241b640.h"

class Unk_241d190 : public Unk_241b640 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_241b640::Unk_GetType());
        return &type;
    }

    const Unk_239a418_Type* vf_type() override;
    void vf7() override;
    void vf9() override;
    void vf10() override;
    virtual u32 vf11();
    virtual u32 vf12();
    virtual void vf13();
};

// 0x71011961c0
void Unk_241d190::vf13() {}
