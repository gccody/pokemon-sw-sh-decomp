// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

// Called by forwarders. Placeholders: their real signatures aren't known.
void Unk_c668b0(void* self);

class Unk_23dc748 {
public:
    virtual ~Unk_23dc748();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
};

// 0x7100c609f0, 0x7100c60270
Unk_23dc748::~Unk_23dc748() {}

// 0x7100c602c0
void Unk_23dc748::vf4() {}

// 0x7100c602d0
void Unk_23dc748::vf5() {
    ::operator delete(this);
}

class Unk_23dc790 : public Unk_23dc748 {
public:
    void vf4() override;
    void vf2() override;
    void vf3() override;
    void vf5() override;
    void vf6() override;
};

// 0x7100c60850
void Unk_23dc790::vf4() {}

// 0x7100c60860
void Unk_23dc790::vf5() {
    ::operator delete(this);
}

class Unk_23dc7d8 : public Unk_23dc748 {
public:
    void vf4() override;
    void vf2() override;
    void vf3() override;
    void vf5() override;
    void vf6() override;
};

// 0x7100c60a50
void Unk_23dc7d8::vf4() {}

// 0x7100c60a60
void Unk_23dc7d8::vf5() {
    ::operator delete(this);
}

class Unk_23dcc30 {
public:
    virtual void vf0();
    virtual void vf1();
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
};

// 0x7100c66560
void Unk_23dcc30::vf6() {
    Unk_c668b0(this);
}

class Unk_23dccb0 {
public:
    virtual void vf0();
    virtual void vf1();
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
};

// 0x7100c666f0
void Unk_23dccb0::vf5() {
    Unk_c668b0(this);
}

class Unk_23dcd20 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x7100c66700
void Unk_23dcd20::vf0() {
    Unk_c668b0(this);
}
