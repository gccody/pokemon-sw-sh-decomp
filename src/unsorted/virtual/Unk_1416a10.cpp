// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

// Called by forwarders. Placeholders: their real signatures aren't known.
void Unk_1416a80(void* self);
void Unk_1417340(void* self);

class Unk_2438b90 {
public:
    virtual ~Unk_2438b90();
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

// 0x7101416a10
void Unk_2438b90::vf6() {
    Unk_1416a80(this);
}

class Unk_2438bf8 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x7101416a40
void Unk_2438bf8::vf5() {
    Unk_1416a80(this);
}

class Unk_2438c38 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x7101416a50
void Unk_2438c38::vf0() {
    Unk_1416a80(this);
}

class Unk_2438c60 {
public:
    virtual ~Unk_2438c60();
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

// 0x71014172d0
void Unk_2438c60::vf6() {
    Unk_1417340(this);
}

// 0x71014172b0
void Unk_2438c60::vf9() {}

class Unk_2438cc8 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x7101417300
void Unk_2438cc8::vf5() {
    Unk_1417340(this);
}

class Unk_2438d08 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x7101417310
void Unk_2438d08::vf0() {
    Unk_1417340(this);
}
