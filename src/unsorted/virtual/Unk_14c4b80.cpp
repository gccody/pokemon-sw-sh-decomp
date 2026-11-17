// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

// Called by forwarders. Placeholders: their real signatures aren't known.
void Unk_14d39f0(void* self);
void Unk_14d4880(void* self);

class Unk_24432a8 {
public:
    virtual u32 vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
};

// 0x71014c4b80
u32 Unk_24432a8::vf0() {
    return 1;
}

class Unk_2443340 {
public:
    virtual ~Unk_2443340();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
};

// 0x71014c6660
void Unk_2443340::vf4() {}

class Unk_2443388 {
public:
    virtual ~Unk_2443388();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
};

// 0x71014c6970
void Unk_2443388::vf4() {}

class Unk_24433f0 {
public:
    virtual u32 vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
};

// 0x71014c6c60
u32 Unk_24433f0::vf0() {
    return 1;
}

class Unk_2443680 {
public:
    virtual u32 vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
};

// 0x71014caaf0
u32 Unk_2443680::vf0() {
    return 3;
}

class Unk_2443818 {
public:
    virtual ~Unk_2443818();
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

// 0x71014d3980
void Unk_2443818::vf6() {
    Unk_14d39f0(this);
}

class Unk_24438b0 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x71014d39b0
void Unk_24438b0::vf5() {
    Unk_14d39f0(this);
}

class Unk_24438f0 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x71014d39c0
void Unk_24438f0::vf0() {
    Unk_14d39f0(this);
}

class Unk_2443918 {
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
    virtual void vf14();
    virtual void vf15();
    virtual void vf16();
};

// 0x71014d4610
void Unk_2443918::vf6() {
    Unk_14d4880(this);
}

class Unk_24439b0 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x71014d4740
void Unk_24439b0::vf5() {
    Unk_14d4880(this);
}

class Unk_24439f0 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x71014d4750
void Unk_24439f0::vf0() {
    Unk_14d4880(this);
}

class Unk_2443f98 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
};

// 0x71014db760
void Unk_2443f98::vf1() {}

class Unk_2443fd0 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
};

// 0x71014db770
void Unk_2443fd0::vf0() {}

// 0x71014db780
void Unk_2443fd0::vf1() {}

class Unk_2444020 {
public:
    virtual ~Unk_2444020();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
};

// 0x71014dbcc0
void Unk_2444020::vf5() {}

class Unk_24440a0 {
public:
    virtual ~Unk_24440a0();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6() = 0;
    virtual void vf7() = 0;
};

// 0x71014dbdd0
void Unk_24440a0::vf5() {}

class Unk_2444238 {
public:
    virtual ~Unk_2444238();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
};

// 0x71014dd690
void Unk_2444238::vf5() {}

class Unk_24442c0 {
public:
    virtual u32 vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
};

// 0x71014ddfb0
u32 Unk_24442c0::vf0() {
    return 2;
}

class Unk_24442f0 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual u32 vf7();
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

// 0x71014de3f0
u32 Unk_24442f0::vf7() {
    return 1;
}

class Unk_2444440 {
public:
    virtual u32 vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
};

// 0x71014def10
u32 Unk_2444440::vf0() {
    return 1;
}

class Unk_2444470 {
public:
    virtual ~Unk_2444470();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
};

// 0x71014e0aa0
void Unk_2444470::vf5() {}

class Unk_24444f8 {
public:
    virtual u32 vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
};

// 0x71014e1330
u32 Unk_24444f8::vf0() {
    return 1;
}
