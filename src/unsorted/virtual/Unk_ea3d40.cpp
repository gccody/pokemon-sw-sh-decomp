// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

// Called by forwarders. Placeholders: their real signatures aren't known.
void Unk_ea3e70(void* self);
void Unk_ea41d0(void* self);
void Unk_ea4450(void* self);

class Unk_23f5720 {
public:
    virtual ~Unk_23f5720();
    virtual void vf2();
    virtual void* vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual u32 vf8();
    virtual void vf9();
    virtual void vf10();
    virtual u32 vf11();
};

// 0x7100ea3de0, 0x7100ea3d30
Unk_23f5720::~Unk_23f5720() {}

// 0x7100ea3d40
void Unk_23f5720::vf2() {}

// 0x7100ea3d50
void* Unk_23f5720::vf3() {
    return nullptr;
}

// 0x7100ea3da0
u32 Unk_23f5720::vf8() {
    return 0;
}

// 0x7100ea3db0
void Unk_23f5720::vf9() {}

// 0x7100ea3dc0
void Unk_23f5720::vf10() {}

// 0x7100ea3dd0
u32 Unk_23f5720::vf11() {
    return 0;
}

class Unk_23f5790 {
public:
    virtual ~Unk_23f5790();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual u32 vf8();
    virtual void vf9();
    virtual void vf10();
    virtual u32 vf11();
};

// 0x7100ea3e60
void Unk_23f5790::vf2() {
    Unk_ea3e70(this);
}

// 0x7100ea3f80
u32 Unk_23f5790::vf8() {
    return 1;
}

// 0x7100ea3f90
void Unk_23f5790::vf9() {}

// 0x7100ea3fb0
u32 Unk_23f5790::vf11() {
    return 1;
}

class Unk_23f5800 {
public:
    virtual ~Unk_23f5800();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual u32 vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();
};

// 0x7100ea41c0
void Unk_23f5800::vf2() {
    Unk_ea41d0(this);
}

// 0x7100ea42e0
u32 Unk_23f5800::vf8() {
    return 3;
}

// 0x7100ea42f0
void Unk_23f5800::vf9() {}

class Unk_23f5870 {
public:
    virtual ~Unk_23f5870();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual u32 vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();
};

// 0x7100ea4410
u32 Unk_23f5870::vf8() {
    return 4;
}

// 0x7100ea4420
void Unk_23f5870::vf9() {}

class Unk_23f58e0 {
public:
    virtual ~Unk_23f58e0();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual u32 vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();
};

// 0x7100ea4440
void Unk_23f58e0::vf2() {
    Unk_ea4450(this);
}

// 0x7100ea4560
u32 Unk_23f58e0::vf8() {
    return 2;
}

// 0x7100ea4570
void Unk_23f58e0::vf9() {}

// 0x7100ea4580
void Unk_23f58e0::vf10() {}

class Unk_23f5950 {
public:
    virtual ~Unk_23f5950();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual u32 vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();
};

// 0x7100ea4690
u32 Unk_23f5950::vf8() {
    return 5;
}

// 0x7100ea46a0
void Unk_23f5950::vf9() {}

class Unk_23f5a80 {
public:
    virtual ~Unk_23f5a80();
};

// 0x7100ea5db0, 0x7100ea5dc0
Unk_23f5a80::~Unk_23f5a80() {}

class Unk_23f5aa0 {
public:
    virtual ~Unk_23f5aa0();
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
};

// 0x7100ea6a40, 0x7100ea6a50
Unk_23f5aa0::~Unk_23f5aa0() {}
