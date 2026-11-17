// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

class Unk_2405578 {
public:
    virtual ~Unk_2405578();
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
};

// 0x7100fe7600
void Unk_2405578::vf7() {}

class Unk_2405658 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
};

// 0x7100fe7610
void Unk_2405658::vf0() {}

// 0x7100fe7bc0
void Unk_2405658::vf2() {}

// 0x7100fe7bd0
void Unk_2405658::vf3() {}

// 0x7100fe7be0
void Unk_2405658::vf4() {}

// 0x7100fe7bf0
void Unk_2405658::vf5() {}

// 0x7100fe7c00
void Unk_2405658::vf6() {}

// 0x7100fe7c10
void Unk_2405658::vf7() {}
