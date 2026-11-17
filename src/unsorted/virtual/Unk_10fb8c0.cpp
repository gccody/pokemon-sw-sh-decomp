// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

// Called by forwarders. Placeholders: their real signatures aren't known.
void Unk_15b6e10(void* self);

class Unk_2417ee0 {
public:
    virtual ~Unk_2417ee0();
    virtual u8* vf2();
    u8 field_8;
};
PKMN_OFFSET_ASSERT(Unk_2417ee0, field_8, 0x8);

// 0x71010fb8c0
u8* Unk_2417ee0::vf2() {
    return &field_8;
}

class Unk_2417dc8 {
public:
    virtual ~Unk_2417dc8();
    virtual void vf2();
    virtual void vf3();
};

// 0x71010fdcd0
void Unk_2417dc8::vf2() {}

class Unk_2417df8 {
public:
    virtual void vf0();
    virtual void vf1();
};

// 0x71010fdd50
void Unk_2417df8::vf0() {}

class Unk_2417eb8 {
public:
    virtual ~Unk_2417eb8();
    virtual u8* vf2();
    u8 field_8;
};
PKMN_OFFSET_ASSERT(Unk_2417eb8, field_8, 0x8);

// 0x71010fe080
u8* Unk_2417eb8::vf2() {
    return &field_8;
}

class Unk_2417f08 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
};

// 0x71010fe0f0
void Unk_2417f08::vf1() {
    Unk_15b6e10(this);
}

class Unk_2417f38 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
};

// 0x71010fe1d0
void Unk_2417f38::vf1() {
    Unk_15b6e10(this);
}

class Unk_2417f68 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
};

// 0x71010fe320
void Unk_2417f68::vf1() {
    Unk_15b6e10(this);
}

class Unk_2417f98 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
};

// 0x71010fe420
void Unk_2417f98::vf1() {
    Unk_15b6e10(this);
}

class Unk_2417fc8 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
};

// 0x71010fe4a0
void Unk_2417fc8::vf1() {
    Unk_15b6e10(this);
}

class Unk_2417ff8 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
};

// 0x71010fe580
void Unk_2417ff8::vf1() {
    Unk_15b6e10(this);
}
