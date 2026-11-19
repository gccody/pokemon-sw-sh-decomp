// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>
#include "gflib3/Unk_239a4c0.h"
#include "unsorted/Unk_23c44f8.h"

// Lifted through their own placeholder structs (cast_member).
struct Unk_14de620_260 {
    u8 field_0;
};
PKMN_OFFSET_ASSERT(Unk_14de620_260, field_0, 0x0);
struct Unk_14de620 {
    u8 _0[0x1ed];
    u8 field_1ed;
    u8 _1ee[0x6a];
    u8 field_258;
    u8 _259[0x7];
    Unk_14de620_260* field_260;
};
PKMN_OFFSET_ASSERT(Unk_14de620, field_1ed, 0x1ed);
PKMN_OFFSET_ASSERT(Unk_14de620, field_258, 0x258);
PKMN_OFFSET_ASSERT(Unk_14de620, field_260, 0x260);

class Unk_24432a8_Obj {
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

struct Unk_24432a8_Entry {
    void* field_0;
    Unk_24432a8_Obj* field_8;
    u64 field_10;
    u8 _18[0x8];
};
PKMN_SIZE_ASSERT(Unk_24432a8_Entry, 0x20);

class Unk_24432a8 {
public:
    virtual u32 vf0();
    virtual void* vf1(u64 index);
    virtual void* vf2(u64 index);
    virtual void vf3(u64 index);
    Unk_24432a8_Entry m_entries[1];
};
PKMN_OFFSET_ASSERT(Unk_24432a8, m_entries, 0x8);

// 0x71014c4b80
u32 Unk_24432a8::vf0() {
    return 1;
}

// 0x71014c4b90
void* Unk_24432a8::vf1(u64 index) {
    return m_entries[index].field_0;
}

// 0x71014c4ba0
void* Unk_24432a8::vf2(u64 index) {
    return m_entries[index].field_8;
}

// 0x71014c4bb0
void Unk_24432a8::vf3(u64 index) {
    if (Unk_24432a8_Obj* obj = m_entries[index].field_8)
        obj->vf16(m_entries[index].field_10);
}

class Unk_2443340 {
public:
    virtual ~Unk_2443340();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
};

// 0x71014c6660
void Unk_2443340::vf4() {}

// 0x71014c6670
void Unk_2443340::vf5() {
    ::operator delete(this);
}

class Unk_2443388 {
public:
    virtual ~Unk_2443388();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
};

// 0x71014c6970
void Unk_2443388::vf4() {}

// 0x71014c6980
void Unk_2443388::vf5() {
    ::operator delete(this);
}

class Unk_24433f0_Obj {
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

struct Unk_24433f0_Entry {
    void* field_0;
    Unk_24433f0_Obj* field_8;
    u64 field_10;
    u8 _18[0x8];
};
PKMN_SIZE_ASSERT(Unk_24433f0_Entry, 0x20);

class Unk_24433f0 {
public:
    virtual u32 vf0();
    virtual void* vf1(u64 index);
    virtual void* vf2(u64 index);
    virtual void vf3(u64 index);
    Unk_24433f0_Entry m_entries[1];
};
PKMN_OFFSET_ASSERT(Unk_24433f0, m_entries, 0x8);

// 0x71014c6c60
u32 Unk_24433f0::vf0() {
    return 1;
}

// 0x71014c6c70
void* Unk_24433f0::vf1(u64 index) {
    return m_entries[index].field_0;
}

// 0x71014c6c80
void* Unk_24433f0::vf2(u64 index) {
    return m_entries[index].field_8;
}

// 0x71014c6c90
void Unk_24433f0::vf3(u64 index) {
    if (Unk_24433f0_Obj* obj = m_entries[index].field_8)
        obj->vf16(m_entries[index].field_10);
}

class Unk_2443680_Obj {
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

struct Unk_2443680_Entry {
    void* field_0;
    Unk_2443680_Obj* field_8;
    u64 field_10;
    u8 _18[0x8];
};
PKMN_SIZE_ASSERT(Unk_2443680_Entry, 0x20);

class Unk_2443680 {
public:
    virtual u32 vf0();
    virtual void* vf1(u64 index);
    virtual void* vf2(u64 index);
    virtual void vf3(u64 index);
    Unk_2443680_Entry m_entries[3];
};
PKMN_OFFSET_ASSERT(Unk_2443680, m_entries, 0x8);

// 0x71014caaf0
u32 Unk_2443680::vf0() {
    return 3;
}

// 0x71014cab00
void* Unk_2443680::vf1(u64 index) {
    return m_entries[index].field_0;
}

// 0x71014cab10
void* Unk_2443680::vf2(u64 index) {
    return m_entries[index].field_8;
}

// 0x71014cab20
void Unk_2443680::vf3(u64 index) {
    if (Unk_2443680_Obj* obj = m_entries[index].field_8)
        obj->vf16(m_entries[index].field_10);
}

class Unk_2443d60 : public Unk_239a4c0 {
public:
    ~Unk_2443d60() override;
    virtual void vf5();
    virtual void vf6();
    u8 _54[0x4];
    Unk_239a418_Ref<Unk_239a418> field_58;
};
PKMN_OFFSET_ASSERT(Unk_2443d60, field_58, 0x58);

// 0x71014d6ca0: its key function
Unk_2443d60::~Unk_2443d60() {}

class Unk_2443ca8 : public Unk_23c44f8 {
public:
    ~Unk_2443ca8() override;
    void vf7(s32) override;
    Unk_239a418_Ref<Unk_239a418> field_80;
};
PKMN_OFFSET_ASSERT(Unk_2443ca8, field_80, 0x80);

// 0x71014d6de0: its key function
Unk_2443ca8::~Unk_2443ca8() {}

class Unk_2443e50 : public Unk_239a4c0 {
public:
    ~Unk_2443e50() override;
    u8 _54[0x54];
    Unk_239a418_Ref<Unk_239a418> field_a8;
    Unk_239a418_Ref<Unk_239a418> field_b0;
    u8 _b8[0x90];
    u64 _148;
    u64 _150;
    u64 _158;
    u64 _160;
    u64 _168;
    u64 _170;
    u64 _178;
    Unk_239a418_Ref<Unk_239a418> field_180;
    Unk_239a418_Ref<Unk_239a418> field_188;
    Unk_239a418_Ref<Unk_239a418> field_190;
};
PKMN_OFFSET_ASSERT(Unk_2443e50, field_a8, 0xa8);
PKMN_OFFSET_ASSERT(Unk_2443e50, field_b0, 0xb0);
PKMN_OFFSET_ASSERT(Unk_2443e50, field_180, 0x180);
PKMN_OFFSET_ASSERT(Unk_2443e50, field_188, 0x188);
PKMN_OFFSET_ASSERT(Unk_2443e50, field_190, 0x190);

// 0x71014d9ff0: its key function
Unk_2443e50::~Unk_2443e50() {}

class Unk_2443f98 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
};

// 0x71014db760
void Unk_2443f98::vf1() {}

class Unk_2443fd0 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
};

// 0x71014db770
void Unk_2443fd0::vf0() {}

// 0x71014db780
void Unk_2443fd0::vf1() {}

class Unk_2444020 {
public:
    virtual ~Unk_2444020();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual u64 vf6();
    virtual void vf7();
    u8 _8[0x1b0];
    u64 field_1b8;
};
PKMN_OFFSET_ASSERT(Unk_2444020, field_1b8, 0x1b8);

// 0x71014dbcc0
void Unk_2444020::vf5() {}

// 0x71014dbb60
u64 Unk_2444020::vf6() {
    return field_1b8;
}

class Unk_24440a0 {
public:
    virtual ~Unk_24440a0();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6() = 0;
    virtual void vf7() = 0;
};

// 0x71014dbdd0
void Unk_24440a0::vf5() {}

class Unk_2444238 {
public:
    virtual ~Unk_2444238();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
};

// 0x71014dd690
void Unk_2444238::vf5() {}

class Unk_2444280 {
public:
    virtual ~Unk_2444280();
    virtual void vf2();
    virtual u64 vf3();
    virtual void vf4();
    virtual void vf5();
    u8 _8[0x70];
    u64 field_78;
};
PKMN_OFFSET_ASSERT(Unk_2444280, field_78, 0x78);

// 0x71014dde20
u64 Unk_2444280::vf3() {
    return field_78;
}

class Unk_24442c0_Obj {
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

struct Unk_24442c0_Entry {
    void* field_0;
    Unk_24442c0_Obj* field_8;
    u64 field_10;
    u8 _18[0x8];
};
PKMN_SIZE_ASSERT(Unk_24442c0_Entry, 0x20);

class Unk_24442c0 {
public:
    virtual u32 vf0();
    virtual void* vf1(u64 index);
    virtual void* vf2(u64 index);
    virtual void vf3(u64 index);
    Unk_24442c0_Entry m_entries[2];
};
PKMN_OFFSET_ASSERT(Unk_24442c0, m_entries, 0x8);

// 0x71014ddfb0
u32 Unk_24442c0::vf0() {
    return 2;
}

// 0x71014ddfc0
void* Unk_24442c0::vf1(u64 index) {
    return m_entries[index].field_0;
}

// 0x71014ddfd0
void* Unk_24442c0::vf2(u64 index) {
    return m_entries[index].field_8;
}

// 0x71014ddfe0
void Unk_24442c0::vf3(u64 index) {
    if (Unk_24442c0_Obj* obj = m_entries[index].field_8)
        obj->vf16(m_entries[index].field_10);
}

class Unk_24442f0 {
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
    virtual u32 vf11();
    virtual void vf12();
    virtual void vf13();
    virtual void vf14();
    virtual void vf15();
    virtual void vf16();
    virtual void vf17();
    virtual void vf18();
};

// 0x71014de3f0
u32 Unk_24442f0::vf7() {
    return 1;
}

// 0x71014de620
u32 Unk_24442f0::vf11() {
    const Unk_14de620* self = reinterpret_cast<const Unk_14de620*>(this);
    if (self->field_258 != 0) {
        if (self->field_260 != nullptr) {
            self->field_260->field_0 = self->field_1ed;
            return 1;
        }
        return 1;
    }
    return 1;
}

class Unk_2444400 {
public:
    virtual ~Unk_2444400();
    virtual void vf2();
    virtual u64 vf3();
    virtual void vf4();
    virtual void vf5();
    u8 _8[0x50];
    u64 field_58;
};
PKMN_OFFSET_ASSERT(Unk_2444400, field_58, 0x58);

// 0x71014deda0
u64 Unk_2444400::vf3() {
    return field_58;
}

class Unk_2444440_Obj {
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

struct Unk_2444440_Entry {
    void* field_0;
    Unk_2444440_Obj* field_8;
    u64 field_10;
    u8 _18[0x8];
};
PKMN_SIZE_ASSERT(Unk_2444440_Entry, 0x20);

class Unk_2444440 {
public:
    virtual u32 vf0();
    virtual void* vf1(u64 index);
    virtual void* vf2(u64 index);
    virtual void vf3(u64 index);
    Unk_2444440_Entry m_entries[1];
};
PKMN_OFFSET_ASSERT(Unk_2444440, m_entries, 0x8);

// 0x71014def10
u32 Unk_2444440::vf0() {
    return 1;
}

// 0x71014def20
void* Unk_2444440::vf1(u64 index) {
    return m_entries[index].field_0;
}

// 0x71014def30
void* Unk_2444440::vf2(u64 index) {
    return m_entries[index].field_8;
}

// 0x71014def40
void Unk_2444440::vf3(u64 index) {
    if (Unk_2444440_Obj* obj = m_entries[index].field_8)
        obj->vf16(m_entries[index].field_10);
}

class Unk_2444470 {
public:
    virtual ~Unk_2444470();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
};

// 0x71014e0aa0
void Unk_2444470::vf5() {}

class Unk_24444b8 {
public:
    virtual ~Unk_24444b8();
    virtual void vf2();
    virtual u64 vf3();
    virtual void vf4();
    virtual void vf5();
    u8 _8[0x50];
    u64 field_58;
};
PKMN_OFFSET_ASSERT(Unk_24444b8, field_58, 0x58);

// 0x71014e11c0
u64 Unk_24444b8::vf3() {
    return field_58;
}

class Unk_24444f8_Obj {
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

struct Unk_24444f8_Entry {
    void* field_0;
    Unk_24444f8_Obj* field_8;
    u64 field_10;
    u8 _18[0x8];
};
PKMN_SIZE_ASSERT(Unk_24444f8_Entry, 0x20);

class Unk_24444f8 {
public:
    virtual u32 vf0();
    virtual void* vf1(u64 index);
    virtual void* vf2(u64 index);
    virtual void vf3(u64 index);
    Unk_24444f8_Entry m_entries[1];
};
PKMN_OFFSET_ASSERT(Unk_24444f8, m_entries, 0x8);

// 0x71014e1330
u32 Unk_24444f8::vf0() {
    return 1;
}

// 0x71014e1340
void* Unk_24444f8::vf1(u64 index) {
    return m_entries[index].field_0;
}

// 0x71014e1350
void* Unk_24444f8::vf2(u64 index) {
    return m_entries[index].field_8;
}

// 0x71014e1360
void Unk_24444f8::vf3(u64 index) {
    if (Unk_24444f8_Obj* obj = m_entries[index].field_8)
        obj->vf16(m_entries[index].field_10);
}
