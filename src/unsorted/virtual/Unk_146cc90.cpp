// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

// Called by forwarders. Placeholders: their real signatures aren't known.
void Unk_146db90(void* self);
void Unk_146e500(void* self);
void Unk_146f510(void* self);
void Unk_1470910(void* self);
void Unk_1472050(void* self);
void Unk_1472660(void* self);

class Unk_243d920 {
public:
    virtual ~Unk_243d920();
};

// 0x710146cc90, 0x710146cf90
Unk_243d920::~Unk_243d920() {}

class Unk_243d958 {
public:
    virtual ~Unk_243d958();
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

// 0x710146db20
void Unk_243d958::vf6() {
    Unk_146db90(this);
}

class Unk_243d9f0 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x710146db50
void Unk_243d9f0::vf5() {
    Unk_146db90(this);
}

class Unk_243da30 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x710146db60
void Unk_243da30::vf0() {
    Unk_146db90(this);
}

class Unk_243da58 {
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

// 0x710146e350
void Unk_243da58::vf6() {
    Unk_146e500(this);
}

// 0x710146e280
void Unk_243da58::vf9() {}

class Unk_243dac0 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x710146e420
void Unk_243dac0::vf5() {
    Unk_146e500(this);
}

class Unk_243db00 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x710146e430
void Unk_243db00::vf0() {
    Unk_146e500(this);
}

class Unk_243db28 {
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

// 0x710146f360
void Unk_243db28::vf6() {
    Unk_146f510(this);
}

// 0x710146f290
void Unk_243db28::vf9() {}

class Unk_243db90 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x710146f430
void Unk_243db90::vf5() {
    Unk_146f510(this);
}

class Unk_243dbd0 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x710146f440
void Unk_243dbd0::vf0() {
    Unk_146f510(this);
}

class Unk_243dc10 {
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

// 0x7101470720
void Unk_243dc10::vf6() {
    Unk_1470910(this);
}

class Unk_243dca8 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x7101470810
void Unk_243dca8::vf5() {
    Unk_1470910(this);
}

class Unk_243dce8 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x7101470820
void Unk_243dce8::vf0() {
    Unk_1470910(this);
}

class Unk_243dd28 {
public:
    virtual ~Unk_243dd28();
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

// 0x7101471fe0
void Unk_243dd28::vf6() {
    Unk_1472050(this);
}

class Unk_243ddc0 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x7101472010
void Unk_243ddc0::vf5() {
    Unk_1472050(this);
}

class Unk_243de00 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x7101472020
void Unk_243de00::vf0() {
    Unk_1472050(this);
}

class Unk_243de40 {
public:
    virtual ~Unk_243de40();
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

// 0x71014725f0
void Unk_243de40::vf6() {
    Unk_1472660(this);
}

class Unk_243dea8 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x7101472620
void Unk_243dea8::vf5() {
    Unk_1472660(this);
}

class Unk_243dee8 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x7101472630
void Unk_243dee8::vf0() {
    Unk_1472660(this);
}
