// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

// Called by forwarders. Placeholders: their real signatures aren't known.
void Unk_150d990(void* self);
void Unk_150e690(void* self);
void Unk_150f330(void* self);
void Unk_150fd80(void* self);

class Unk_2446e08 {
public:
    virtual ~Unk_2446e08();
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

// 0x710150d920
void Unk_2446e08::vf6() {
    Unk_150d990(this);
}

// 0x710150d900
void Unk_2446e08::vf9() {}

class Unk_2446e70 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x710150d950
void Unk_2446e70::vf5() {
    Unk_150d990(this);
}

class Unk_2446eb0 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x710150d960
void Unk_2446eb0::vf0() {
    Unk_150d990(this);
}

class Unk_2446ed8 {
public:
    virtual ~Unk_2446ed8();
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

// 0x710150e620
void Unk_2446ed8::vf6() {
    Unk_150e690(this);
}

// 0x710150e600
void Unk_2446ed8::vf9() {}

class Unk_2446f40 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x710150e650
void Unk_2446f40::vf5() {
    Unk_150e690(this);
}

class Unk_2446f80 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x710150e660
void Unk_2446f80::vf0() {
    Unk_150e690(this);
}

class Unk_2446fa8 {
public:
    virtual ~Unk_2446fa8();
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

// 0x710150f2c0
void Unk_2446fa8::vf6() {
    Unk_150f330(this);
}

// 0x710150f2a0
void Unk_2446fa8::vf9() {}

class Unk_2447010 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x710150f2f0
void Unk_2447010::vf5() {
    Unk_150f330(this);
}

class Unk_2447050 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x710150f300
void Unk_2447050::vf0() {
    Unk_150f330(this);
}

class Unk_2447078 {
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
};

// 0x710150fd50
void Unk_2447078::vf6() {
    Unk_150fd80(this);
}

// 0x710150f8f0
u32 Unk_2447078::vf7() {
    return 1;
}

// 0x710150f910
void Unk_2447078::vf10() {}

class Unk_24470e0 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x710150fd60
void Unk_24470e0::vf5() {
    Unk_150fd80(this);
}

class Unk_2447120 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x710150fd70
void Unk_2447120::vf0() {
    Unk_150fd80(this);
}

class Unk_2447188 {
public:
    virtual u32 vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
};

// 0x7101510520
u32 Unk_2447188::vf0() {
    return 1;
}
