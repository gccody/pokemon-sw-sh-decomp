// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

// Called by forwarders. Placeholders: their real signatures aren't known.
void Unk_fc4520(void* self);

class Unk_2402dc8 {
public:
    virtual ~Unk_2402dc8();
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

// 0x7100fb9aa0
u32 Unk_2402dc8::vf7() {
    return 1;
}

class Unk_2402e98 {
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

// 0x7100fc1c40
u32 Unk_2402e98::vf7() {
    return 1;
}

// 0x7100fc1c50
void Unk_2402e98::vf8() {}

// 0x7100fc1d10
void Unk_2402e98::vf10() {}

class Unk_2402f68 {
public:
    virtual ~Unk_2402f68();
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

// 0x7100fc44f0
void Unk_2402f68::vf6() {
    Unk_fc4520(this);
}

// 0x7100fc2d00
u32 Unk_2402f68::vf7() {
    return 1;
}

class Unk_2402fd0 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x7100fc4500
void Unk_2402fd0::vf5() {
    Unk_fc4520(this);
}

class Unk_2403010 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x7100fc4510
void Unk_2403010::vf0() {
    Unk_fc4520(this);
}

class Unk_2403108 {
public:
    virtual ~Unk_2403108();
    virtual void vf2();
    virtual u64 vf3();
    virtual void vf4();
    virtual void vf5();
    u8 _8[0x50];
    u64 field_58;
};
PKMN_OFFSET_ASSERT(Unk_2403108, field_58, 0x58);

// 0x7100fc59d0
u64 Unk_2403108::vf3() {
    return field_58;
}

class Unk_2403148_Obj {
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

struct Unk_2403148_Entry {
    void* field_0;
    Unk_2403148_Obj* field_8;
    u64 field_10;
    u8 _18[0x8];
};
PKMN_SIZE_ASSERT(Unk_2403148_Entry, 0x20);

class Unk_2403148 {
public:
    virtual u32 vf0();
    virtual void* vf1(u64 index);
    virtual void* vf2(u64 index);
    virtual void vf3(u64 index);
    Unk_2403148_Entry m_entries[1];
};
PKMN_OFFSET_ASSERT(Unk_2403148, m_entries, 0x8);

// 0x7100fc5b40
u32 Unk_2403148::vf0() {
    return 1;
}

// 0x7100fc5b50
void* Unk_2403148::vf1(u64 index) {
    return m_entries[index].field_0;
}

// 0x7100fc5b60
void* Unk_2403148::vf2(u64 index) {
    return m_entries[index].field_8;
}

// 0x7100fc5b70
void Unk_2403148::vf3(u64 index) {
    if (Unk_2403148_Obj* obj = m_entries[index].field_8)
        obj->vf16(m_entries[index].field_10);
}
