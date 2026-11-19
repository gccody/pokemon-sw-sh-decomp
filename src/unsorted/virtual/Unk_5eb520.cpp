// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

// Called by forwarders. Placeholders: their real signatures aren't known.
void Unk_5eb880(void* self);

// Tail-called by lifted functions. Placeholders, like the forwarders' callees.
void Unk_5f5570(void*);
void Unk_5f5660(void*);
void Unk_5f5770(void*);
void Unk_5f5780(void*);

// Lifted through their own placeholder structs (cast_member).
struct Unk_5ed4a0_8 {
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3(u64, u64, u64);
};

struct Unk_5ed4a0 {
    virtual void vf0();
    Unk_5ed4a0_8* field_8;
    u64 field_10;
    u64 field_18;
    u64 field_20;
};
PKMN_OFFSET_ASSERT(Unk_5ed4a0, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_5ed4a0, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_5ed4a0, field_18, 0x18);
PKMN_OFFSET_ASSERT(Unk_5ed4a0, field_20, 0x20);

class Unk_239a840_Obj {
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
    virtual void vf16(u64 value);
};

struct Unk_239a840_Entry {
    void* field_0;
    Unk_239a840_Obj* field_8;
    u64 field_10;
    u8 _18[0x8];
};
PKMN_SIZE_ASSERT(Unk_239a840_Entry, 0x20);

class Unk_239a840 {
public:
    virtual u32 vf0();
    virtual void* vf1(u64 index);
    virtual void* vf2(u64 index);
    virtual void vf3(u64 index);
    Unk_239a840_Entry m_entries[2];
};
PKMN_OFFSET_ASSERT(Unk_239a840, m_entries, 0x8);

// 0x71005eb520
u32 Unk_239a840::vf0() {
    return 2;
}

// 0x71005eb530
void* Unk_239a840::vf1(u64 index) {
    return m_entries[index].field_0;
}

// 0x71005eb540
void* Unk_239a840::vf2(u64 index) {
    return m_entries[index].field_8;
}

// 0x71005eb550
void Unk_239a840::vf3(u64 index) {
    if (Unk_239a840_Obj* obj = m_entries[index].field_8)
        obj->vf16(m_entries[index].field_10);
}

class Unk_239a870 {
public:
    virtual u32 vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x71005eb690
u32 Unk_239a870::vf0() {
    return 2;
}

class Unk_239a8c0 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
};

// 0x71005ec250
void Unk_239a8c0::vf2() {}

class Unk_239a8f0 {
public:
    virtual void vf0();
    virtual void vf1();
};

// 0x71005ec2d0
void Unk_239a8f0::vf0() {}

class Unk_239aa40 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x71005ece00
void Unk_239aa40::vf5() {}

class Unk_239ab90 {
public:
    virtual ~Unk_239ab90();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x71005ed4a0
void Unk_239ab90::vf3() {
    Unk_5ed4a0* self = reinterpret_cast<Unk_5ed4a0*>(this);
    Unk_5ed4a0_8* v0 = self->field_8;
    u64 v1 = self->field_10;
    u64 v2 = self->field_18;
    u64 v3 = self->field_20;
    self->vf0();
    v0->vf3(v1, v2, v3);
}

class Unk_239abd0 {
public:
    virtual ~Unk_239abd0();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6() = 0;
    virtual void vf7() = 0;
    virtual void vf8() = 0;
};

// 0x71005ede40
void Unk_239abd0::vf5() {
    Unk_5eb880(this);
}

class Unk_239ac28 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x71005ede50
void Unk_239ac28::vf0() {
    Unk_5eb880(this);
}

class Unk_239ac50 {
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
    virtual u8* vf12();
    virtual void vf13();
    u8 _8[0x60];
    u8 field_68;
    u8 _69[0xff];
    u8 field_168;
};
PKMN_OFFSET_ASSERT(Unk_239ac50, field_68, 0x68);
PKMN_OFFSET_ASSERT(Unk_239ac50, field_168, 0x168);

// 0x71005ee470
void Unk_239ac50::vf7() {
    Unk_5f5570(&field_68);
}

// 0x71005ee480
void Unk_239ac50::vf8() {
    Unk_5f5660(&field_68);
}

// 0x71005ee4a0
void Unk_239ac50::vf10() {
    Unk_5f5770(&field_68);
}

// 0x71005ee4b0
void Unk_239ac50::vf11() {
    Unk_5f5780(&field_68);
}

// 0x71005ee4c0
u8* Unk_239ac50::vf12() {
    return &field_168;
}
