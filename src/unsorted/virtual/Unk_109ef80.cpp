// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

// Called by forwarders. Placeholders: their real signatures aren't known.
void Unk_15b6e10(void* self);

class Unk_2410040 {
public:
    virtual ~Unk_2410040();
    virtual void vf2();
    virtual u32 vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6(u64 value);
    virtual u64 vf7();
    virtual u8 vf8();
    virtual void vf9(u32 value);
    virtual u32 vf10();
    virtual void vf11();
    u64 field_8;
    u8 field_10;
    u8 _11[0x3];
    u32 field_14;
};
PKMN_OFFSET_ASSERT(Unk_2410040, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_2410040, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_2410040, field_14, 0x14);

// 0x710109efa0
u32 Unk_2410040::vf3() {
    return 1;
}

// 0x710109f580
void Unk_2410040::vf5() {
    field_14 = 0;
    field_10 = 1;
}

// 0x710109f590
void Unk_2410040::vf6(u64 value) {
    field_8 = value;
}

// 0x710109f5a0
u64 Unk_2410040::vf7() {
    return field_8;
}

// 0x710109f5b0
u8 Unk_2410040::vf8() {
    return field_10;
}

// 0x710109ef90
void Unk_2410040::vf9(u32 value) {
    field_14 = value;
}

// 0x710109ef80
u32 Unk_2410040::vf10() {
    return field_14;
}

class Unk_24100b0 {
public:
    virtual void vf0();
    virtual void vf1();
};

// 0x710109f5c0
void Unk_24100b0::vf1() {
    Unk_15b6e10(this);
}
