// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

// Called by forwarders. Placeholders: their real signatures aren't known.
void Unk_11e6110(void* self);

class Unk_2421b90 {
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

// 0x71011e5d60
void Unk_2421b90::vf6() {
    Unk_11e6110(this);
}

class Unk_2421c10 {
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

// 0x71011e5f30
void Unk_2421c10::vf5() {
    Unk_11e6110(this);
}

class Unk_2421c80 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x71011e5f40
void Unk_2421c80::vf0() {
    Unk_11e6110(this);
}

class Unk_2421ca8 {
public:
    virtual ~Unk_2421ca8();
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

// 0x71011e64c0
void Unk_2421ca8::vf11() {}

class Unk_2421de8 {
public:
    virtual ~Unk_2421de8();
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

// 0x71011e7db0
void Unk_2421de8::vf11() {}

class Unk_24222e8 {
public:
    virtual ~Unk_24222e8();
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

// 0x71011eebf0
void Unk_24222e8::vf11() {}

class Unk_2422428 {
public:
    virtual ~Unk_2422428();
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
    virtual void vf19();
    virtual void vf20();
    virtual void vf21();
    virtual void vf22();
    virtual void vf23();
    virtual void vf24();
    virtual void vf25();
    virtual void vf26();
    virtual void vf27();
    virtual void vf28();
    virtual void vf29();
    virtual void vf30();
    virtual void vf31();
    virtual void vf32();
    virtual void vf33();
    virtual void vf34();
    virtual void vf35();
    virtual void vf36();
    virtual u32 vf37();
    virtual void vf38();
    virtual void vf39();
    virtual void vf40();
    virtual void vf41();
    virtual void vf42();
    virtual void vf43();
    virtual void vf44();
};

// 0x71011f4900
u32 Unk_2422428::vf37() {
    return 0x50;
}

// 0x71011f4670
void Unk_2422428::vf44() {}

class Unk_2422710 {
public:
    virtual void vf0();
};

// 0x71011f4680
void Unk_2422710::vf0() {}

class Unk_2422638 {
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
    virtual u32 vf14();
};

// 0x71011f4a70
void Unk_2422638::vf1() {}

// 0x71011f4a80
void Unk_2422638::vf3() {}

// 0x71011f4a90
void Unk_2422638::vf4() {}

// 0x71011f4aa0
void Unk_2422638::vf5() {}

// 0x71011f4ab0
void Unk_2422638::vf6() {}

// 0x71011f4ac0
void Unk_2422638::vf7() {}

// 0x71011f4e30
u32 Unk_2422638::vf14() {
    return 0x50;
}

class Unk_24226c0 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
};

// 0x71011f4e40
void Unk_24226c0::vf4() {}

class Unk_2422728 {
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
    virtual void vf13() = 0;
    virtual void vf14() = 0;
};

// 0x71011f4e50
void Unk_2422728::vf0() {}

// 0x71011f4e60
void Unk_2422728::vf2() {}
