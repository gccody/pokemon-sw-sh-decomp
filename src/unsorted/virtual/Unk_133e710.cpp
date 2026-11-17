// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

// Called by forwarders. Placeholders: their real signatures aren't known.
void Unk_133ecb0(void* self);
void Unk_133f290(void* self);
void Unk_133fe90(void* self);
void Unk_1340910(void* self);
void Unk_13447b0(void* self);

class Unk_24311b8 {
public:
    virtual u32 vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
};

// 0x710133e710
u32 Unk_24311b8::vf0() {
    return 1;
}

class Unk_24311e8 {
public:
    virtual ~Unk_24311e8();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
};

// 0x710133ec40
void Unk_24311e8::vf6() {
    Unk_133ecb0(this);
}

class Unk_2431230 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x710133ec70
void Unk_2431230::vf5() {
    Unk_133ecb0(this);
}

class Unk_2431270 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x710133ec80
void Unk_2431270::vf0() {
    Unk_133ecb0(this);
}

class Unk_2431298 {
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
};

// 0x710133fce0
void Unk_2431298::vf6() {
    Unk_133fe90(this);
}

// 0x710133fc10
void Unk_2431298::vf9() {}

class Unk_2431300 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x710133fdb0
void Unk_2431300::vf5() {
    Unk_133fe90(this);
}

class Unk_2431340 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x710133fdc0
void Unk_2431340::vf0() {
    Unk_133fe90(this);
}

class Unk_2431368 {
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
};

// 0x7101340760
void Unk_2431368::vf6() {
    Unk_1340910(this);
}

// 0x7101340690
void Unk_2431368::vf9() {}

class Unk_24313d0 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x7101340830
void Unk_24313d0::vf5() {
    Unk_1340910(this);
}

class Unk_2431410 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x7101340840
void Unk_2431410::vf0() {
    Unk_1340910(this);
}

class Unk_2431618 {
public:
    virtual ~Unk_2431618();
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

// 0x7101344040
void Unk_2431618::vf6() {
    Unk_133f290(this);
}

class Unk_24316b0 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x7101344070
void Unk_24316b0::vf5() {
    Unk_133f290(this);
}

class Unk_24316f0 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x7101344080
void Unk_24316f0::vf0() {
    Unk_133f290(this);
}

class Unk_2431778 {
public:
    virtual ~Unk_2431778();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual u32 vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
};

// 0x7101344780
void Unk_2431778::vf6() {
    Unk_13447b0(this);
}

// 0x7101344540
u32 Unk_2431778::vf7() {
    return 1;
}

// 0x71013445d0
void Unk_2431778::vf10() {}

class Unk_24317e0 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x7101344790
void Unk_24317e0::vf5() {
    Unk_13447b0(this);
}

class Unk_2431820 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x71013447a0
void Unk_2431820::vf0() {
    Unk_13447b0(this);
}

class Unk_2431910 {
public:
    virtual ~Unk_2431910();
    virtual void vf2();
    virtual void vf3();
};

// 0x7101346250, 0x7101346260
Unk_2431910::~Unk_2431910() {}

class Unk_2431940 {
public:
    virtual ~Unk_2431940();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x7101346290, 0x71013462a0
Unk_2431940::~Unk_2431940() {}

class Unk_24319a8 {
public:
    virtual ~Unk_24319a8();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
};

// 0x7101346750, 0x7101346760
Unk_24319a8::~Unk_24319a8() {}

class Unk_24319f0 {
public:
    virtual ~Unk_24319f0();
    virtual void vf2();
    virtual void vf3();
};

// 0x7101347ab0, 0x7101347ac0
Unk_24319f0::~Unk_24319f0() {}
