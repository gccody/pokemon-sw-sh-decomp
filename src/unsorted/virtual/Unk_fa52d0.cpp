// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

// Called by forwarders. Placeholders: their real signatures aren't known.
void Unk_fa55b0(void* self);
void Unk_fa7a80(void* self);

class Unk_24024e0 {
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

// 0x7100fa53c0
void Unk_24024e0::vf6() {
    Unk_fa55b0(this);
}

// 0x7100fa52d0
void Unk_24024e0::vf9() {}

class Unk_2402548 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x7100fa54b0
void Unk_2402548::vf5() {
    Unk_fa55b0(this);
}

class Unk_2402588 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x7100fa54c0
void Unk_2402588::vf0() {
    Unk_fa55b0(this);
}

class Unk_24025b0 {
public:
    virtual ~Unk_24025b0();
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

// 0x7100fa7a10
void Unk_24025b0::vf6() {
    Unk_fa7a80(this);
}

// 0x7100fa7880
void Unk_24025b0::vf9() {}

class Unk_2402618 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x7100fa7a40
void Unk_2402618::vf5() {
    Unk_fa7a80(this);
}

class Unk_2402658 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x7100fa7a50
void Unk_2402658::vf0() {
    Unk_fa7a80(this);
}
