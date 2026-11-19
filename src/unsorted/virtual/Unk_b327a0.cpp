// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>
#include "gflib3/Unk_239a418.h"
#include "unsorted/Unk_23f5d00.h"

// Called by forwarders. Placeholders: their real signatures aren't known.
void Unk_b32b10(void* self);
void Unk_b426b0(void* self);
void Unk_b46170(void* self);

// Tail-called by lifted functions. Placeholders, like the forwarders' callees.
void Unk_7c2db0(void*, u32);
void Unk_b3b9f0(void*, u32, u64);

// Lifted through their own placeholder structs (cast_member).
struct Unk_b40d50 {
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
    u8 _8[0x118];
    u64 field_120;
    u8 field_128;
};
PKMN_OFFSET_ASSERT(Unk_b40d50, field_120, 0x120);
PKMN_OFFSET_ASSERT(Unk_b40d50, field_128, 0x128);

void Unk_598de0(u64, u64, u64, u8);

struct Unk_b48c00 {
    u8 _0[0x8];
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_b48c00, field_8, 0x8);

class Unk_23cefc0 {
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
    u8 _8[0x84];
    u32 field_8c;
};
PKMN_OFFSET_ASSERT(Unk_23cefc0, field_8c, 0x8c);

// 0x7100b32a60
void Unk_23cefc0::vf6() {
    Unk_b32b10(this);
}

// 0x7100b327a0
void Unk_23cefc0::vf11() {
    field_8c = 4;
}

// 0x7100b32800
void Unk_23cefc0::vf13() {
    field_8c = 5;
}

// 0x7100b32820
void Unk_23cefc0::vf14() {
    field_8c = 5;
}

// 0x7100b32840
void Unk_23cefc0::vf15() {
    field_8c = 5;
}

class Unk_23cf0c0 {
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
    u8 _8[0xc];
    u32 field_14;
};
PKMN_OFFSET_ASSERT(Unk_23cf0c0, field_14, 0x14);

// 0x7100b327b0
void Unk_23cf0c0::vf2() {
    field_14 = 4;
}

// 0x7100b32850
void Unk_23cf0c0::vf3() {
    field_14 = 5;
}

// 0x7100b32810
void Unk_23cf0c0::vf5() {
    field_14 = 5;
}

// 0x7100b32830
void Unk_23cf0c0::vf6() {
    field_14 = 5;
}

class Unk_23cf058 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x7100b32a90
void Unk_23cf058::vf5() {
    Unk_b32b10(this);
}

class Unk_23cf098 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x7100b32aa0
void Unk_23cf098::vf0() {
    Unk_b32b10(this);
}

class Unk_23cda40 {
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
    u8 _8[0x14];
    u8 field_1c;
    u8 _1d[0x3];
    u32 field_20;
    u8 _24[0x1];
    u8 field_25;
    u8 _26[0x1a2];
    u8 field_1c8;
};
PKMN_OFFSET_ASSERT(Unk_23cda40, field_1c, 0x1c);
PKMN_OFFSET_ASSERT(Unk_23cda40, field_20, 0x20);
PKMN_OFFSET_ASSERT(Unk_23cda40, field_25, 0x25);
PKMN_OFFSET_ASSERT(Unk_23cda40, field_1c8, 0x1c8);

// 0x7100b32af0
void Unk_23cda40::vf7() {}

// 0x7100b32b00
void Unk_23cda40::vf8() {}

class Unk_23cf3c0 {
public:
    virtual ~Unk_23cf3c0();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8(u64 value);
    virtual void vf9(u64 value);
    virtual u32 vf10();
    virtual bool vf11();
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
    virtual void vf31(u64 value, u64 arg2);
    virtual void vf32();
    virtual void vf33();
    virtual void vf34();
    virtual u32 vf35();
    virtual void vf36();
    virtual void vf37();
    virtual void vf38();
    virtual void vf39();
    virtual u32 vf40();
    virtual void vf41();
    virtual void vf42();
    virtual u32 vf43();
    virtual void vf44();
    virtual u64 vf45();
    u8 _8[0x8c];
    u32 field_94;
    u8 _98[0xb0];
    u64 field_148;
};
PKMN_OFFSET_ASSERT(Unk_23cf3c0, field_94, 0x94);
PKMN_OFFSET_ASSERT(Unk_23cf3c0, field_148, 0x148);

// 0x7100b42000
void Unk_23cf3c0::vf8(u64 value) {
    Unk_b3b9f0(this, 1, value);
}

// 0x7100b42010
void Unk_23cf3c0::vf9(u64 value) {
    Unk_b3b9f0(this, 0, value);
}

// 0x7100b42020
u32 Unk_23cf3c0::vf10() {
    return (field_94 == 3) | (field_94 == 5);
}

// 0x7100b42040
bool Unk_23cf3c0::vf11() {
    return field_94 == 5;
}

// 0x7100b42050
bool Unk_23cf3c0::vf14() {
    return field_94 == 0;
}

// 0x7100b40d50
void Unk_23cf3c0::vf31(u64 value, u64 arg2) {
    Unk_b40d50* self = reinterpret_cast<Unk_b40d50*>(this);
    self->vf32();
    if (self->field_120 != 0) {
        Unk_598de0(self->field_120, value, arg2, 1);
        self->field_128 = 0;
    }
}

// 0x7100b45b20
void Unk_23cf3c0::vf34() {}

// 0x7100b45b30
u32 Unk_23cf3c0::vf35() {
    return 1;
}

// 0x7100b45b40
void Unk_23cf3c0::vf36() {}

// 0x7100b45b50
void Unk_23cf3c0::vf37() {}

// 0x7100b45b60
void Unk_23cf3c0::vf38() {}

// 0x7100b45b70
void Unk_23cf3c0::vf39() {}

// 0x7100b45b80
u32 Unk_23cf3c0::vf40() {
    return 0;
}

// 0x7100b45b90
void Unk_23cf3c0::vf41() {}

// 0x7100b45ba0
void Unk_23cf3c0::vf42() {}

// 0x7100b45bb0
u32 Unk_23cf3c0::vf43() {
    return 1;
}

// 0x7100b40eb0
u64 Unk_23cf3c0::vf45() {
    return field_148;
}

class Unk_23cf5e8 {
public:
    virtual ~Unk_23cf5e8();
};

// 0x7100b42340, 0x7100b42350
Unk_23cf5e8::~Unk_23cf5e8() {}

class Unk_23cf668 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
};

// 0x7100b42b10
void Unk_23cf668::vf6() {
    Unk_b426b0(this);
}

class Unk_23cf6b0 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x7100b42cc0
void Unk_23cf6b0::vf5() {
    Unk_b426b0(this);
}

class Unk_23cf6f0 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x7100b42cd0
void Unk_23cf6f0::vf0() {
    Unk_b426b0(this);
}

class Unk_23cf718 {
public:
    virtual ~Unk_23cf718();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
};

// 0x7100b44420, 0x7100b44360
Unk_23cf718::~Unk_23cf718() {}

// 0x7100b443d0
void Unk_23cf718::vf4() {}

// 0x7100b443e0
void Unk_23cf718::vf5() {
    ::operator delete(this);
}

class Unk_23cf760 {
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
    virtual u32 vf16();
    virtual u32 vf17();
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
    virtual void* vf44();
    virtual void* vf45();
};

// 0x7100b45ec0
void Unk_23cf760::vf6() {
    Unk_b46170(this);
}

// 0x7100b45370
void Unk_23cf760::vf7() {}

// 0x7100b45380
void Unk_23cf760::vf8() {}

// 0x7100b45390
void Unk_23cf760::vf9() {}

// 0x7100b453a0
void Unk_23cf760::vf12() {}

// 0x7100b453b0
void Unk_23cf760::vf13() {}

// 0x7100b453c0
u32 Unk_23cf760::vf16() {
    return 0;
}

// 0x7100b453d0
u32 Unk_23cf760::vf17() {
    return 1;
}

// 0x7100b45af0
void Unk_23cf760::vf31() {}

// 0x7100b45b00
void Unk_23cf760::vf32() {}

// 0x7100b45b10
void Unk_23cf760::vf33() {}

// 0x7100b45bc0
void* Unk_23cf760::vf44() {
    return nullptr;
}

// 0x7100b45bd0
void* Unk_23cf760::vf45() {
    return nullptr;
}

class Unk_23cf8e0 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x7100b46010
void Unk_23cf8e0::vf5() {
    Unk_b46170(this);
}

class Unk_23cf920 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x7100b46020
void Unk_23cf920::vf0() {
    Unk_b46170(this);
}

class Unk_23cf948 : public Unk_23cf718 {
public:
    void vf4() override;
    void vf2() override;
    void vf3() override;
    void vf5() override;
    void vf6() override;
};

// 0x7100b46310
void Unk_23cf948::vf4() {}

// 0x7100b46320
void Unk_23cf948::vf5() {
    ::operator delete(this);
}

class Unk_23cfab0 : public Unk_23cf718 {
public:
    void vf4() override;
    void vf2() override;
    void vf3() override;
    void vf5() override;
    void vf6() override;
};

// 0x7100b488c0
void Unk_23cfab0::vf4() {}

// 0x7100b488d0
void Unk_23cfab0::vf5() {
    ::operator delete(this);
}

class Unk_23cfaf8 {
public:
    virtual ~Unk_23cfaf8();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
};

// 0x7100b489a0
void Unk_23cfaf8::vf4() {}

// 0x7100b489b0
void Unk_23cfaf8::vf5() {
    ::operator delete(this);
}

class Unk_23cfb40 {
public:
    virtual ~Unk_23cfb40();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
};

// 0x7100b48e00, 0x7100b48a10
Unk_23cfb40::~Unk_23cfb40() {}

// 0x7100b48a80
void Unk_23cfb40::vf4() {}

// 0x7100b48a90
void Unk_23cfb40::vf5() {
    ::operator delete(this);
}

class Unk_23cfb88 {
public:
    virtual ~Unk_23cfb88();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
};

// 0x7100b48c00
void Unk_23cfb88::vf4() {
    Unk_b48c00* self = reinterpret_cast<Unk_b48c00*>(this);
    if (self->field_8 != nullptr) {
        static_cast<Unk_239a458*>(self->field_8)->vf5();
        self->field_8 = nullptr;
    }
}

class Unk_23cfbd0 : public Unk_23cfb40 {
public:
    void vf4() override;
    void vf2() override;
    void vf3() override;
    void vf5() override;
    void vf6() override;
};

// 0x7100b48dd0
void Unk_23cfbd0::vf4() {}

// 0x7100b48de0
void Unk_23cfbd0::vf5() {
    ::operator delete(this);
}

class Unk_23cfc18 : public Unk_23cfb40 {
public:
    void vf4() override;
    void vf2() override;
    void vf3() override;
    void vf5() override;
    void vf6() override;
};

// 0x7100b48e80
void Unk_23cfc18::vf4() {}

// 0x7100b48e90
void Unk_23cfc18::vf5() {
    ::operator delete(this);
}

class Unk_23cfc60 : public Unk_23cfb40 {
public:
    void vf4() override;
    void vf2() override;
    void vf3() override;
    void vf5() override;
    void vf6() override;
};

// 0x7100b48f20
void Unk_23cfc60::vf4() {}

// 0x7100b48f30
void Unk_23cfc60::vf5() {
    ::operator delete(this);
}

class Unk_23cfca8 : public Unk_23cfb40 {
public:
    void vf4() override;
    void vf2() override;
    void vf3() override;
    void vf5() override;
    void vf6() override;
};

// 0x7100b48fd0
void Unk_23cfca8::vf4() {}

// 0x7100b48fe0
void Unk_23cfca8::vf5() {
    ::operator delete(this);
}

class Unk_23cfcf0 : public Unk_23cfb40 {
public:
    void vf4() override;
    void vf2() override;
    void vf3() override;
    void vf5() override;
    void vf6() override;
};

// 0x7100b49070
void Unk_23cfcf0::vf4() {}

// 0x7100b49080
void Unk_23cfcf0::vf5() {
    ::operator delete(this);
}

class Unk_23cfd68 {
public:
    virtual ~Unk_23cfd68();
    virtual void vf2();
    virtual void vf3(u64 value);
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_23cfd68, field_8, 0x8);

// 0x7100b498c0, 0x7100b498d0
Unk_23cfd68::~Unk_23cfd68() {}

// 0x7100b498a0
void Unk_23cfd68::vf2() {}

// 0x7100b498b0
void Unk_23cfd68::vf3(u64 value) {
    field_8 = value;
}

class Unk_23cfdb8 {
public:
    virtual ~Unk_23cfdb8();
};

// 0x7100b4a780, 0x7100b4a790
Unk_23cfdb8::~Unk_23cfdb8() {}

class Unk_23cfe60 {
public:
    virtual ~Unk_23cfe60();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    u8 _8[0x30];
    u8 field_38;
};
PKMN_OFFSET_ASSERT(Unk_23cfe60, field_38, 0x38);

// 0x7100b4ce00
void Unk_23cfe60::vf4() {
    Unk_7c2db0(&field_38, 0);
}

class Unk_23cfe98_Obj {
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

struct Unk_23cfe98_Entry {
    void* field_0;
    Unk_23cfe98_Obj* field_8;
    u64 field_10;
    u8 _18[0x8];
};
PKMN_SIZE_ASSERT(Unk_23cfe98_Entry, 0x20);

class Unk_23cfe98 {
public:
    virtual u32 vf0();
    virtual void* vf1(u64 index);
    virtual void* vf2(u64 index);
    virtual void vf3(u64 index);
    Unk_23cfe98_Entry m_entries[1];
};
PKMN_OFFSET_ASSERT(Unk_23cfe98, m_entries, 0x8);

// 0x7100b4ce10
u32 Unk_23cfe98::vf0() {
    return 1;
}

// 0x7100b4ce20
void* Unk_23cfe98::vf1(u64 index) {
    return m_entries[index].field_0;
}

// 0x7100b4ce30
void* Unk_23cfe98::vf2(u64 index) {
    return m_entries[index].field_8;
}

// 0x7100b4ce40
void Unk_23cfe98::vf3(u64 index) {
    if (Unk_23cfe98_Obj* obj = m_entries[index].field_8)
        obj->vf16(m_entries[index].field_10);
}

class Unk_23cff00_Obj {
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

struct Unk_23cff00_Entry {
    void* field_0;
    Unk_23cff00_Obj* field_8;
    u64 field_10;
    u8 _18[0x8];
};
PKMN_SIZE_ASSERT(Unk_23cff00_Entry, 0x20);

class Unk_23cff00 {
public:
    virtual u32 vf0();
    virtual void* vf1(u64 index);
    virtual void* vf2(u64 index);
    virtual void vf3(u64 index);
    Unk_23cff00_Entry m_entries[9];
};
PKMN_OFFSET_ASSERT(Unk_23cff00, m_entries, 0x8);

// 0x7100b4d2e0
u32 Unk_23cff00::vf0() {
    return 9;
}

// 0x7100b4d2f0
void* Unk_23cff00::vf1(u64 index) {
    return m_entries[index].field_0;
}

// 0x7100b4d300
void* Unk_23cff00::vf2(u64 index) {
    return m_entries[index].field_8;
}

// 0x7100b4d310
void Unk_23cff00::vf3(u64 index) {
    if (Unk_23cff00_Obj* obj = m_entries[index].field_8)
        obj->vf16(m_entries[index].field_10);
}

class Unk_23cff68_Obj {
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

struct Unk_23cff68_Entry {
    void* field_0;
    Unk_23cff68_Obj* field_8;
    u64 field_10;
    u8 _18[0x8];
};
PKMN_SIZE_ASSERT(Unk_23cff68_Entry, 0x20);

class Unk_23cff68 {
public:
    virtual u32 vf0();
    virtual void* vf1(u64 index);
    virtual void* vf2(u64 index);
    virtual void vf3(u64 index);
    Unk_23cff68_Entry m_entries[28];
};
PKMN_OFFSET_ASSERT(Unk_23cff68, m_entries, 0x8);

// 0x7100b4dbe0
u32 Unk_23cff68::vf0() {
    return 0x1c;
}

// 0x7100b4dbf0
void* Unk_23cff68::vf1(u64 index) {
    return m_entries[index].field_0;
}

// 0x7100b4dc00
void* Unk_23cff68::vf2(u64 index) {
    return m_entries[index].field_8;
}

// 0x7100b4dc10
void Unk_23cff68::vf3(u64 index) {
    if (Unk_23cff68_Obj* obj = m_entries[index].field_8)
        obj->vf16(m_entries[index].field_10);
}

class Unk_23cffd0_Obj {
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

struct Unk_23cffd0_Entry {
    void* field_0;
    Unk_23cffd0_Obj* field_8;
    u64 field_10;
    u8 _18[0x8];
};
PKMN_SIZE_ASSERT(Unk_23cffd0_Entry, 0x20);

class Unk_23cffd0 {
public:
    virtual u32 vf0();
    virtual void* vf1(u64 index);
    virtual void* vf2(u64 index);
    virtual void vf3(u64 index);
    Unk_23cffd0_Entry m_entries[28];
};
PKMN_OFFSET_ASSERT(Unk_23cffd0, m_entries, 0x8);

// 0x7100b4e290
u32 Unk_23cffd0::vf0() {
    return 0x1c;
}

// 0x7100b4e2a0
void* Unk_23cffd0::vf1(u64 index) {
    return m_entries[index].field_0;
}

// 0x7100b4e2b0
void* Unk_23cffd0::vf2(u64 index) {
    return m_entries[index].field_8;
}

// 0x7100b4e2c0
void Unk_23cffd0::vf3(u64 index) {
    if (Unk_23cffd0_Obj* obj = m_entries[index].field_8)
        obj->vf16(m_entries[index].field_10);
}

class Unk_23d0038_Obj {
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

struct Unk_23d0038_Entry {
    void* field_0;
    Unk_23d0038_Obj* field_8;
    u64 field_10;
    u8 _18[0x8];
};
PKMN_SIZE_ASSERT(Unk_23d0038_Entry, 0x20);

class Unk_23d0038 {
public:
    virtual u32 vf0();
    virtual void* vf1(u64 index);
    virtual void* vf2(u64 index);
    virtual void vf3(u64 index);
    Unk_23d0038_Entry m_entries[8];
};
PKMN_OFFSET_ASSERT(Unk_23d0038, m_entries, 0x8);

// 0x7100b4e700
u32 Unk_23d0038::vf0() {
    return 8;
}

// 0x7100b4e710
void* Unk_23d0038::vf1(u64 index) {
    return m_entries[index].field_0;
}

// 0x7100b4e720
void* Unk_23d0038::vf2(u64 index) {
    return m_entries[index].field_8;
}

// 0x7100b4e730
void Unk_23d0038::vf3(u64 index) {
    if (Unk_23d0038_Obj* obj = m_entries[index].field_8)
        obj->vf16(m_entries[index].field_10);
}

class Unk_23d00a0_Obj {
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

struct Unk_23d00a0_Entry {
    void* field_0;
    Unk_23d00a0_Obj* field_8;
    u64 field_10;
    u8 _18[0x8];
};
PKMN_SIZE_ASSERT(Unk_23d00a0_Entry, 0x20);

class Unk_23d00a0 {
public:
    virtual u32 vf0();
    virtual void* vf1(u64 index);
    virtual void* vf2(u64 index);
    virtual void vf3(u64 index);
    Unk_23d00a0_Entry m_entries[8];
};
PKMN_OFFSET_ASSERT(Unk_23d00a0, m_entries, 0x8);

// 0x7100b4ed80
u32 Unk_23d00a0::vf0() {
    return 8;
}

// 0x7100b4ed90
void* Unk_23d00a0::vf1(u64 index) {
    return m_entries[index].field_0;
}

// 0x7100b4eda0
void* Unk_23d00a0::vf2(u64 index) {
    return m_entries[index].field_8;
}

// 0x7100b4edb0
void Unk_23d00a0::vf3(u64 index) {
    if (Unk_23d00a0_Obj* obj = m_entries[index].field_8)
        obj->vf16(m_entries[index].field_10);
}

class Unk_23d0108_Obj {
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

struct Unk_23d0108_Entry {
    void* field_0;
    Unk_23d0108_Obj* field_8;
    u64 field_10;
    u8 _18[0x8];
};
PKMN_SIZE_ASSERT(Unk_23d0108_Entry, 0x20);

class Unk_23d0108 {
public:
    virtual u32 vf0();
    virtual void* vf1(u64 index);
    virtual void* vf2(u64 index);
    virtual void vf3(u64 index);
    Unk_23d0108_Entry m_entries[28];
};
PKMN_OFFSET_ASSERT(Unk_23d0108, m_entries, 0x8);

// 0x7100b4f640
u32 Unk_23d0108::vf0() {
    return 0x1c;
}

// 0x7100b4f650
void* Unk_23d0108::vf1(u64 index) {
    return m_entries[index].field_0;
}

// 0x7100b4f660
void* Unk_23d0108::vf2(u64 index) {
    return m_entries[index].field_8;
}

// 0x7100b4f670
void Unk_23d0108::vf3(u64 index) {
    if (Unk_23d0108_Obj* obj = m_entries[index].field_8)
        obj->vf16(m_entries[index].field_10);
}

class Unk_23d0170_Obj {
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

struct Unk_23d0170_Entry {
    void* field_0;
    Unk_23d0170_Obj* field_8;
    u64 field_10;
    u8 _18[0x8];
};
PKMN_SIZE_ASSERT(Unk_23d0170_Entry, 0x20);

class Unk_23d0170 {
public:
    virtual u32 vf0();
    virtual void* vf1(u64 index);
    virtual void* vf2(u64 index);
    virtual void vf3(u64 index);
    Unk_23d0170_Entry m_entries[28];
};
PKMN_OFFSET_ASSERT(Unk_23d0170, m_entries, 0x8);

// 0x7100b4fcf0
u32 Unk_23d0170::vf0() {
    return 0x1c;
}

// 0x7100b4fd00
void* Unk_23d0170::vf1(u64 index) {
    return m_entries[index].field_0;
}

// 0x7100b4fd10
void* Unk_23d0170::vf2(u64 index) {
    return m_entries[index].field_8;
}

// 0x7100b4fd20
void Unk_23d0170::vf3(u64 index) {
    if (Unk_23d0170_Obj* obj = m_entries[index].field_8)
        obj->vf16(m_entries[index].field_10);
}

class Unk_23d01d8_Obj {
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

struct Unk_23d01d8_Entry {
    void* field_0;
    Unk_23d01d8_Obj* field_8;
    u64 field_10;
    u8 _18[0x8];
};
PKMN_SIZE_ASSERT(Unk_23d01d8_Entry, 0x20);

class Unk_23d01d8 {
public:
    virtual u32 vf0();
    virtual void* vf1(u64 index);
    virtual void* vf2(u64 index);
    virtual void vf3(u64 index);
    Unk_23d01d8_Entry m_entries[7];
};
PKMN_OFFSET_ASSERT(Unk_23d01d8, m_entries, 0x8);

// 0x7100b50110
u32 Unk_23d01d8::vf0() {
    return 7;
}

// 0x7100b50120
void* Unk_23d01d8::vf1(u64 index) {
    return m_entries[index].field_0;
}

// 0x7100b50130
void* Unk_23d01d8::vf2(u64 index) {
    return m_entries[index].field_8;
}

// 0x7100b50140
void Unk_23d01d8::vf3(u64 index) {
    if (Unk_23d01d8_Obj* obj = m_entries[index].field_8)
        obj->vf16(m_entries[index].field_10);
}

class Unk_23d0240_Obj {
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

struct Unk_23d0240_Entry {
    void* field_0;
    Unk_23d0240_Obj* field_8;
    u64 field_10;
    u8 _18[0x8];
};
PKMN_SIZE_ASSERT(Unk_23d0240_Entry, 0x20);

class Unk_23d0240 {
public:
    virtual u32 vf0();
    virtual void* vf1(u64 index);
    virtual void* vf2(u64 index);
    virtual void vf3(u64 index);
    Unk_23d0240_Entry m_entries[7];
};
PKMN_OFFSET_ASSERT(Unk_23d0240, m_entries, 0x8);

// 0x7100b50710
u32 Unk_23d0240::vf0() {
    return 7;
}

// 0x7100b50720
void* Unk_23d0240::vf1(u64 index) {
    return m_entries[index].field_0;
}

// 0x7100b50730
void* Unk_23d0240::vf2(u64 index) {
    return m_entries[index].field_8;
}

// 0x7100b50740
void Unk_23d0240::vf3(u64 index) {
    if (Unk_23d0240_Obj* obj = m_entries[index].field_8)
        obj->vf16(m_entries[index].field_10);
}

class Unk_23d02a8_Obj {
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

struct Unk_23d02a8_Entry {
    void* field_0;
    Unk_23d02a8_Obj* field_8;
    u64 field_10;
    u8 _18[0x8];
};
PKMN_SIZE_ASSERT(Unk_23d02a8_Entry, 0x20);

class Unk_23d02a8 {
public:
    virtual u32 vf0();
    virtual void* vf1(u64 index);
    virtual void* vf2(u64 index);
    virtual void vf3(u64 index);
    Unk_23d02a8_Entry m_entries[7];
};
PKMN_OFFSET_ASSERT(Unk_23d02a8, m_entries, 0x8);

// 0x7100b50d10
u32 Unk_23d02a8::vf0() {
    return 7;
}

// 0x7100b50d20
void* Unk_23d02a8::vf1(u64 index) {
    return m_entries[index].field_0;
}

// 0x7100b50d30
void* Unk_23d02a8::vf2(u64 index) {
    return m_entries[index].field_8;
}

// 0x7100b50d40
void Unk_23d02a8::vf3(u64 index) {
    if (Unk_23d02a8_Obj* obj = m_entries[index].field_8)
        obj->vf16(m_entries[index].field_10);
}

class Unk_23d0310_Obj {
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

struct Unk_23d0310_Entry {
    void* field_0;
    Unk_23d0310_Obj* field_8;
    u64 field_10;
    u8 _18[0x8];
};
PKMN_SIZE_ASSERT(Unk_23d0310_Entry, 0x20);

class Unk_23d0310 {
public:
    virtual u32 vf0();
    virtual void* vf1(u64 index);
    virtual void* vf2(u64 index);
    virtual void vf3(u64 index);
    Unk_23d0310_Entry m_entries[4];
};
PKMN_OFFSET_ASSERT(Unk_23d0310, m_entries, 0x8);

// 0x7100b513d0
u32 Unk_23d0310::vf0() {
    return 4;
}

// 0x7100b513e0
void* Unk_23d0310::vf1(u64 index) {
    return m_entries[index].field_0;
}

// 0x7100b513f0
void* Unk_23d0310::vf2(u64 index) {
    return m_entries[index].field_8;
}

// 0x7100b51400
void Unk_23d0310::vf3(u64 index) {
    if (Unk_23d0310_Obj* obj = m_entries[index].field_8)
        obj->vf16(m_entries[index].field_10);
}

class Unk_23d0378_Obj {
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

struct Unk_23d0378_Entry {
    void* field_0;
    Unk_23d0378_Obj* field_8;
    u64 field_10;
    u8 _18[0x8];
};
PKMN_SIZE_ASSERT(Unk_23d0378_Entry, 0x20);

class Unk_23d0378 {
public:
    virtual u32 vf0();
    virtual void* vf1(u64 index);
    virtual void* vf2(u64 index);
    virtual void vf3(u64 index);
    Unk_23d0378_Entry m_entries[4];
};
PKMN_OFFSET_ASSERT(Unk_23d0378, m_entries, 0x8);

// 0x7100b518b0
u32 Unk_23d0378::vf0() {
    return 4;
}

// 0x7100b518c0
void* Unk_23d0378::vf1(u64 index) {
    return m_entries[index].field_0;
}

// 0x7100b518d0
void* Unk_23d0378::vf2(u64 index) {
    return m_entries[index].field_8;
}

// 0x7100b518e0
void Unk_23d0378::vf3(u64 index) {
    if (Unk_23d0378_Obj* obj = m_entries[index].field_8)
        obj->vf16(m_entries[index].field_10);
}

class Unk_23d03e0_Obj {
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

struct Unk_23d03e0_Entry {
    void* field_0;
    Unk_23d03e0_Obj* field_8;
    u64 field_10;
    u8 _18[0x8];
};
PKMN_SIZE_ASSERT(Unk_23d03e0_Entry, 0x20);

class Unk_23d03e0 {
public:
    virtual u32 vf0();
    virtual void* vf1(u64 index);
    virtual void* vf2(u64 index);
    virtual void vf3(u64 index);
    Unk_23d03e0_Entry m_entries[3];
};
PKMN_OFFSET_ASSERT(Unk_23d03e0, m_entries, 0x8);

// 0x7100b51d00
u32 Unk_23d03e0::vf0() {
    return 3;
}

// 0x7100b51d10
void* Unk_23d03e0::vf1(u64 index) {
    return m_entries[index].field_0;
}

// 0x7100b51d20
void* Unk_23d03e0::vf2(u64 index) {
    return m_entries[index].field_8;
}

// 0x7100b51d30
void Unk_23d03e0::vf3(u64 index) {
    if (Unk_23d03e0_Obj* obj = m_entries[index].field_8)
        obj->vf16(m_entries[index].field_10);
}

class Unk_23d0448_Obj {
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

struct Unk_23d0448_Entry {
    void* field_0;
    Unk_23d0448_Obj* field_8;
    u64 field_10;
    u8 _18[0x8];
};
PKMN_SIZE_ASSERT(Unk_23d0448_Entry, 0x20);

class Unk_23d0448 {
public:
    virtual u32 vf0();
    virtual void* vf1(u64 index);
    virtual void* vf2(u64 index);
    virtual void vf3(u64 index);
    Unk_23d0448_Entry m_entries[3];
};
PKMN_OFFSET_ASSERT(Unk_23d0448, m_entries, 0x8);

// 0x7100b52150
u32 Unk_23d0448::vf0() {
    return 3;
}

// 0x7100b52160
void* Unk_23d0448::vf1(u64 index) {
    return m_entries[index].field_0;
}

// 0x7100b52170
void* Unk_23d0448::vf2(u64 index) {
    return m_entries[index].field_8;
}

// 0x7100b52180
void Unk_23d0448::vf3(u64 index) {
    if (Unk_23d0448_Obj* obj = m_entries[index].field_8)
        obj->vf16(m_entries[index].field_10);
}

class Unk_23d04b0_Obj {
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

struct Unk_23d04b0_Entry {
    void* field_0;
    Unk_23d04b0_Obj* field_8;
    u64 field_10;
    u8 _18[0x8];
};
PKMN_SIZE_ASSERT(Unk_23d04b0_Entry, 0x20);

class Unk_23d04b0 {
public:
    virtual u32 vf0();
    virtual void* vf1(u64 index);
    virtual void* vf2(u64 index);
    virtual void vf3(u64 index);
    Unk_23d04b0_Entry m_entries[20];
};
PKMN_OFFSET_ASSERT(Unk_23d04b0, m_entries, 0x8);

// 0x7100b526b0
u32 Unk_23d04b0::vf0() {
    return 0x14;
}

// 0x7100b526c0
void* Unk_23d04b0::vf1(u64 index) {
    return m_entries[index].field_0;
}

// 0x7100b526d0
void* Unk_23d04b0::vf2(u64 index) {
    return m_entries[index].field_8;
}

// 0x7100b526e0
void Unk_23d04b0::vf3(u64 index) {
    if (Unk_23d04b0_Obj* obj = m_entries[index].field_8)
        obj->vf16(m_entries[index].field_10);
}

class Unk_23d0518_Obj {
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

struct Unk_23d0518_Entry {
    void* field_0;
    Unk_23d0518_Obj* field_8;
    u64 field_10;
    u8 _18[0x8];
};
PKMN_SIZE_ASSERT(Unk_23d0518_Entry, 0x20);

class Unk_23d0518 {
public:
    virtual u32 vf0();
    virtual void* vf1(u64 index);
    virtual void* vf2(u64 index);
    virtual void vf3(u64 index);
    Unk_23d0518_Entry m_entries[20];
};
PKMN_OFFSET_ASSERT(Unk_23d0518, m_entries, 0x8);

// 0x7100b530e0
u32 Unk_23d0518::vf0() {
    return 0x14;
}

// 0x7100b530f0
void* Unk_23d0518::vf1(u64 index) {
    return m_entries[index].field_0;
}

// 0x7100b53100
void* Unk_23d0518::vf2(u64 index) {
    return m_entries[index].field_8;
}

// 0x7100b53110
void Unk_23d0518::vf3(u64 index) {
    if (Unk_23d0518_Obj* obj = m_entries[index].field_8)
        obj->vf16(m_entries[index].field_10);
}

class Unk_23d0580_Obj {
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

struct Unk_23d0580_Entry {
    void* field_0;
    Unk_23d0580_Obj* field_8;
    u64 field_10;
    u8 _18[0x8];
};
PKMN_SIZE_ASSERT(Unk_23d0580_Entry, 0x20);

class Unk_23d0580 {
public:
    virtual u32 vf0();
    virtual void* vf1(u64 index);
    virtual void* vf2(u64 index);
    virtual void vf3(u64 index);
    Unk_23d0580_Entry m_entries[16];
};
PKMN_OFFSET_ASSERT(Unk_23d0580, m_entries, 0x8);

// 0x7100b53ad0
u32 Unk_23d0580::vf0() {
    return 0x10;
}

// 0x7100b53ae0
void* Unk_23d0580::vf1(u64 index) {
    return m_entries[index].field_0;
}

// 0x7100b53af0
void* Unk_23d0580::vf2(u64 index) {
    return m_entries[index].field_8;
}

// 0x7100b53b00
void Unk_23d0580::vf3(u64 index) {
    if (Unk_23d0580_Obj* obj = m_entries[index].field_8)
        obj->vf16(m_entries[index].field_10);
}

class Unk_23d05e8_Obj {
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

struct Unk_23d05e8_Entry {
    void* field_0;
    Unk_23d05e8_Obj* field_8;
    u64 field_10;
    u8 _18[0x8];
};
PKMN_SIZE_ASSERT(Unk_23d05e8_Entry, 0x20);

class Unk_23d05e8 {
public:
    virtual u32 vf0();
    virtual void* vf1(u64 index);
    virtual void* vf2(u64 index);
    virtual void vf3(u64 index);
    Unk_23d05e8_Entry m_entries[20];
};
PKMN_OFFSET_ASSERT(Unk_23d05e8, m_entries, 0x8);

// 0x7100b54420
u32 Unk_23d05e8::vf0() {
    return 0x14;
}

// 0x7100b54430
void* Unk_23d05e8::vf1(u64 index) {
    return m_entries[index].field_0;
}

// 0x7100b54440
void* Unk_23d05e8::vf2(u64 index) {
    return m_entries[index].field_8;
}

// 0x7100b54450
void Unk_23d05e8::vf3(u64 index) {
    if (Unk_23d05e8_Obj* obj = m_entries[index].field_8)
        obj->vf16(m_entries[index].field_10);
}

class Unk_23d0650_Obj {
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

struct Unk_23d0650_Entry {
    void* field_0;
    Unk_23d0650_Obj* field_8;
    u64 field_10;
    u8 _18[0x8];
};
PKMN_SIZE_ASSERT(Unk_23d0650_Entry, 0x20);

class Unk_23d0650 {
public:
    virtual u32 vf0();
    virtual void* vf1(u64 index);
    virtual void* vf2(u64 index);
    virtual void vf3(u64 index);
    Unk_23d0650_Entry m_entries[20];
};
PKMN_OFFSET_ASSERT(Unk_23d0650, m_entries, 0x8);

// 0x7100b54e50
u32 Unk_23d0650::vf0() {
    return 0x14;
}

// 0x7100b54e60
void* Unk_23d0650::vf1(u64 index) {
    return m_entries[index].field_0;
}

// 0x7100b54e70
void* Unk_23d0650::vf2(u64 index) {
    return m_entries[index].field_8;
}

// 0x7100b54e80
void Unk_23d0650::vf3(u64 index) {
    if (Unk_23d0650_Obj* obj = m_entries[index].field_8)
        obj->vf16(m_entries[index].field_10);
}

class Unk_23d06b8_Obj {
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

struct Unk_23d06b8_Entry {
    void* field_0;
    Unk_23d06b8_Obj* field_8;
    u64 field_10;
    u8 _18[0x8];
};
PKMN_SIZE_ASSERT(Unk_23d06b8_Entry, 0x20);

class Unk_23d06b8 {
public:
    virtual u32 vf0();
    virtual void* vf1(u64 index);
    virtual void* vf2(u64 index);
    virtual void vf3(u64 index);
    Unk_23d06b8_Entry m_entries[16];
};
PKMN_OFFSET_ASSERT(Unk_23d06b8, m_entries, 0x8);

// 0x7100b55840
u32 Unk_23d06b8::vf0() {
    return 0x10;
}

// 0x7100b55850
void* Unk_23d06b8::vf1(u64 index) {
    return m_entries[index].field_0;
}

// 0x7100b55860
void* Unk_23d06b8::vf2(u64 index) {
    return m_entries[index].field_8;
}

// 0x7100b55870
void Unk_23d06b8::vf3(u64 index) {
    if (Unk_23d06b8_Obj* obj = m_entries[index].field_8)
        obj->vf16(m_entries[index].field_10);
}

class Unk_23d06e8 {
public:
    virtual ~Unk_23d06e8();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    u8 _8[0x30];
    u8 field_38;
};
PKMN_OFFSET_ASSERT(Unk_23d06e8, field_38, 0x38);

// 0x7100b55fa0
void Unk_23d06e8::vf4() {
    Unk_7c2db0(&field_38, 0);
}

class Unk_23d0720_Obj {
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

struct Unk_23d0720_Entry {
    void* field_0;
    Unk_23d0720_Obj* field_8;
    u64 field_10;
    u8 _18[0x8];
};
PKMN_SIZE_ASSERT(Unk_23d0720_Entry, 0x20);

class Unk_23d0720 {
public:
    virtual u32 vf0();
    virtual void* vf1(u64 index);
    virtual void* vf2(u64 index);
    virtual void vf3(u64 index);
    Unk_23d0720_Entry m_entries[1];
};
PKMN_OFFSET_ASSERT(Unk_23d0720, m_entries, 0x8);

// 0x7100b55fb0
u32 Unk_23d0720::vf0() {
    return 1;
}

// 0x7100b55fc0
void* Unk_23d0720::vf1(u64 index) {
    return m_entries[index].field_0;
}

// 0x7100b55fd0
void* Unk_23d0720::vf2(u64 index) {
    return m_entries[index].field_8;
}

// 0x7100b55fe0
void Unk_23d0720::vf3(u64 index) {
    if (Unk_23d0720_Obj* obj = m_entries[index].field_8)
        obj->vf16(m_entries[index].field_10);
}

class Unk_23d0770 : public Unk_23f5d00 {
public:
    u8* vf5() override;
    u8 field_180;
    u8 _181[0x17];
    Unk_239a418_Ref<Unk_239a418> field_198;
};
PKMN_OFFSET_ASSERT(Unk_23d0770, field_180, 0x180);
PKMN_OFFSET_ASSERT(Unk_23d0770, field_198, 0x198);

// 0x7100b57af0
u8* Unk_23d0770::vf5() {
    return &field_180;
}

class Unk_23d07e0 : public Unk_23f5d00 {
public:
    ~Unk_23d07e0() override;
    u8* vf5() override;
};

// 0x7100b58130: its key function
Unk_23d07e0::~Unk_23d07e0() {}
