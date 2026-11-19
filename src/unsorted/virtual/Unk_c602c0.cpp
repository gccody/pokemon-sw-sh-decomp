// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

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
