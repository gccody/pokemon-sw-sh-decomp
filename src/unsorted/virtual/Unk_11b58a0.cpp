// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>
#include "unsorted/Unk_241b640.h"

class Unk_241f3f0 {
public:
    virtual ~Unk_241f3f0();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
    virtual void vf14();
    virtual void vf15();
    virtual void vf16();
    virtual void vf17();
    virtual void vf18();
};

// 0x71011b58a0
void Unk_241f3f0::vf11() {}

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

class Unk_241f530 : public Unk_241d190 {
public:
    u32 vf11() override;
    void vf7() override;
    void vf9() override;
    void vf10() override;
    u32 vf12() override;
    void vf13() override;
};

// 0x71011b7a80
u32 Unk_241f530::vf11() {
    return 0;
}

// 0x71011b7a90
u32 Unk_241f530::vf12() {
    return 0;
}
