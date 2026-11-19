// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

// Tail-called by lifted functions. Placeholders, like the forwarders' callees.
void Unk_b87470(void*, u32, u64);
void Unk_b93690(void*, u32);
void Unk_b9ac60(void*, u32, u64);
void Unk_b9e7a0(void*, u32);

// Lifted through their own placeholder structs (cast_member).
struct Unk_b8ce60 {
    u8 _0[0x94];
    u32 field_94;
    u8 _98[0x30c];
    u32 field_3a4;
};
PKMN_OFFSET_ASSERT(Unk_b8ce60, field_94, 0x94);
PKMN_OFFSET_ASSERT(Unk_b8ce60, field_3a4, 0x3a4);

class Unk_23d1de8 {
public:
    virtual ~Unk_23d1de8();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8(u64 value);
    virtual void vf9(u64 value);
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
    virtual void vf37();
    virtual void vf38();
    virtual void vf39();
    virtual void vf40();
    virtual void vf41();
    virtual void vf42();
    virtual void vf43();
    virtual void vf44();
    virtual u64 vf45();
    u8 _8[0x138];
    u64 field_140;
};
PKMN_OFFSET_ASSERT(Unk_23d1de8, field_140, 0x140);

// 0x7100b8ac40
void Unk_23d1de8::vf8(u64 value) {
    Unk_b87470(this, 1, value);
}

// 0x7100b8ac50
void Unk_23d1de8::vf9(u64 value) {
    Unk_b87470(this, 0, value);
}

// 0x7100b8a630
u64 Unk_23d1de8::vf45() {
    return field_140;
}

class Unk_23d2138 {
public:
    virtual ~Unk_23d2138();
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
    virtual bool vf14();
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
    virtual void vf37();
    virtual void vf38();
    virtual void vf39();
    virtual void vf40();
    virtual void vf41();
    virtual void vf42();
    virtual void vf43();
    virtual void vf44();
    virtual void vf45();
};

// 0x7100b8ce60
bool Unk_23d2138::vf14() {
    const Unk_b8ce60* self = reinterpret_cast<const Unk_b8ce60*>(this);
    if (self->field_3a4 != 0) {
        return 0;
    }
    return self->field_94 == 0;
}

// 0x7100b94130
void Unk_23d2138::vf32() {
    Unk_b93690(this, 0);
}

class Unk_23d24b0 {
public:
    virtual ~Unk_23d24b0();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
};

// 0x7100b99210
void Unk_23d24b0::vf4() {}

// 0x7100b99220
void Unk_23d24b0::vf5() {
    ::operator delete(this);
}

class Unk_23d24f8 {
public:
    virtual ~Unk_23d24f8();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
};

// 0x7100b995a0
void Unk_23d24f8::vf4() {}

// 0x7100b995b0
void Unk_23d24f8::vf5() {
    ::operator delete(this);
}

class Unk_23d2540 {
public:
    virtual ~Unk_23d2540();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
};

// 0x7100b99930
void Unk_23d2540::vf4() {}

// 0x7100b99940
void Unk_23d2540::vf5() {
    ::operator delete(this);
}

class Unk_23d2588 {
public:
    virtual ~Unk_23d2588();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
};

// 0x7100b99e00
void Unk_23d2588::vf4() {}

// 0x7100b99e10
void Unk_23d2588::vf5() {
    ::operator delete(this);
}

class Unk_23d25d0 {
public:
    virtual ~Unk_23d25d0();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
};

// 0x7100b9a030
void Unk_23d25d0::vf4() {}

// 0x7100b9a040
void Unk_23d25d0::vf5() {
    ::operator delete(this);
}

class Unk_23d2618 {
public:
    virtual ~Unk_23d2618();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
};

// 0x7100b9a260
void Unk_23d2618::vf4() {}

// 0x7100b9a270
void Unk_23d2618::vf5() {
    ::operator delete(this);
}

class Unk_23d2660 {
public:
    virtual ~Unk_23d2660();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
};

// 0x7100b9a340
void Unk_23d2660::vf4() {}

// 0x7100b9a350
void Unk_23d2660::vf5() {
    ::operator delete(this);
}

class Unk_23d2728 {
public:
    virtual ~Unk_23d2728();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8(u64 value);
    virtual void vf9(u64 value);
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
    virtual void vf37();
    virtual void vf38();
    virtual void vf39();
    virtual void vf40();
    virtual void vf41();
    virtual void vf42();
    virtual void vf43();
    virtual void vf44();
    virtual void vf45();
};

// 0x7100b9f130
void Unk_23d2728::vf8(u64 value) {
    Unk_b9ac60(this, 1, value);
}

// 0x7100b9f140
void Unk_23d2728::vf9(u64 value) {
    Unk_b9ac60(this, 0, value);
}

// 0x7100b9f150
void Unk_23d2728::vf32() {
    Unk_b9e7a0(this, 0);
}

class Unk_23d2d88 {
public:
    virtual ~Unk_23d2d88();
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
};

// 0x7100ba3630
void Unk_23d2d88::vf22() {}

class Unk_23d2ee8 {
public:
    virtual ~Unk_23d2ee8();
    virtual void vf2();
    virtual u64 vf3();
    virtual void vf4();
    virtual void vf5();
    u8 _8[0x50];
    u64 field_58;
};
PKMN_OFFSET_ASSERT(Unk_23d2ee8, field_58, 0x58);

// 0x7100ba4030
u64 Unk_23d2ee8::vf3() {
    return field_58;
}

class Unk_23d2f28_Obj {
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

struct Unk_23d2f28_Entry {
    void* field_0;
    Unk_23d2f28_Obj* field_8;
    u64 field_10;
    u8 _18[0x8];
};
PKMN_SIZE_ASSERT(Unk_23d2f28_Entry, 0x20);

class Unk_23d2f28 {
public:
    virtual u32 vf0();
    virtual void* vf1(u64 index);
    virtual void* vf2(u64 index);
    virtual void vf3(u64 index);
    Unk_23d2f28_Entry m_entries[1];
};
PKMN_OFFSET_ASSERT(Unk_23d2f28, m_entries, 0x8);

// 0x7100ba41a0
u32 Unk_23d2f28::vf0() {
    return 1;
}

// 0x7100ba41b0
void* Unk_23d2f28::vf1(u64 index) {
    return m_entries[index].field_0;
}

// 0x7100ba41c0
void* Unk_23d2f28::vf2(u64 index) {
    return m_entries[index].field_8;
}

// 0x7100ba41d0
void Unk_23d2f28::vf3(u64 index) {
    if (Unk_23d2f28_Obj* obj = m_entries[index].field_8)
        obj->vf16(m_entries[index].field_10);
}
