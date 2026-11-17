// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

// Called by forwarders. Placeholders: their real signatures aren't known.
void Unk_153dd60(void* self);
void Unk_153f430(void* self);
void Unk_1542c50(void* self);
void Unk_1544450(void* self);

class Unk_2449478 {
public:
    virtual ~Unk_2449478();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
};

// 0x710153d940
void Unk_2449478::vf6() {
    Unk_153dd60(this);
}

class Unk_24494c0 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x710153d950
void Unk_24494c0::vf5() {
    Unk_153dd60(this);
}

class Unk_2449500 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x710153d960
void Unk_2449500::vf0() {
    Unk_153dd60(this);
}

class Unk_2449670 {
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

// 0x7101541b10
void Unk_2449670::vf6() {
    Unk_153f430(this);
}

// 0x7101540510
void Unk_2449670::vf10() {}

class Unk_2449708 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x7101541c60
void Unk_2449708::vf5() {
    Unk_153f430(this);
}

class Unk_2449748 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x7101541c70
void Unk_2449748::vf0() {
    Unk_153f430(this);
}

class Unk_2449870 {
public:
    virtual ~Unk_2449870();
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
    virtual u32 vf16();
};

// 0x7101542be0
void Unk_2449870::vf6() {
    Unk_1542c50(this);
}

// 0x7101542a80
void Unk_2449870::vf8() {}

// 0x7101542a90
void Unk_2449870::vf10() {}

// 0x7101542aa0
u32 Unk_2449870::vf16() {
    return 0;
}

class Unk_2449908 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x7101542c10
void Unk_2449908::vf5() {
    Unk_1542c50(this);
}

class Unk_2449948 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x7101542c20
void Unk_2449948::vf0() {
    Unk_1542c50(this);
}

class Unk_2449970 {
public:
    virtual ~Unk_2449970();
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
    virtual u32 vf16();
};

// 0x71015443e0
void Unk_2449970::vf6() {
    Unk_1544450(this);
}

// 0x71015434f0
void Unk_2449970::vf10() {}

// 0x7101543500
u32 Unk_2449970::vf16() {
    return 0;
}

class Unk_2449a08 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x7101544410
void Unk_2449a08::vf5() {
    Unk_1544450(this);
}

class Unk_2449a48 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x7101544420
void Unk_2449a48::vf0() {
    Unk_1544450(this);
}
