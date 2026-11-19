// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

// Lifted through their own placeholder structs (cast_member).
struct Unk_7be190_260 {
    u8 field_0;
};
PKMN_OFFSET_ASSERT(Unk_7be190_260, field_0, 0x0);
struct Unk_7be190 {
    u8 _0[0x1ed];
    u8 field_1ed;
    u8 _1ee[0x6a];
    u8 field_258;
    u8 _259[0x7];
    Unk_7be190_260* field_260;
};
PKMN_OFFSET_ASSERT(Unk_7be190, field_1ed, 0x1ed);
PKMN_OFFSET_ASSERT(Unk_7be190, field_258, 0x258);
PKMN_OFFSET_ASSERT(Unk_7be190, field_260, 0x260);

class Unk_23aa0e8 {
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

// 0x71007bc8c0
u32 Unk_23aa0e8::vf7() {
    return 1;
}

class Unk_23aa1b8 {
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
    virtual u32 vf17();
    virtual void vf18();
};

// 0x71007be000
u32 Unk_23aa1b8::vf7() {
    return 1;
}

// 0x71007be190
u32 Unk_23aa1b8::vf11() {
    const Unk_7be190* self = reinterpret_cast<const Unk_7be190*>(this);
    if (self->field_258 != 0) {
        if (self->field_260 != nullptr) {
            self->field_260->field_0 = self->field_1ed;
            return 1;
        }
        return 1;
    }
    return 1;
}

class Unk_23aa2c8 {
public:
    virtual ~Unk_23aa2c8();
    virtual void vf2();
    virtual u64 vf3();
    virtual void vf4();
    virtual void vf5();
    u8 _8[0x50];
    u64 field_58;
};
PKMN_OFFSET_ASSERT(Unk_23aa2c8, field_58, 0x58);

// 0x71007bea60
u64 Unk_23aa2c8::vf3() {
    return field_58;
}

class Unk_23aa308_Obj {
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

struct Unk_23aa308_Entry {
    void* field_0;
    Unk_23aa308_Obj* field_8;
    u64 field_10;
    u8 _18[0x8];
};
PKMN_SIZE_ASSERT(Unk_23aa308_Entry, 0x20);

class Unk_23aa308 {
public:
    virtual u32 vf0();
    virtual void* vf1(u64 index);
    virtual void* vf2(u64 index);
    virtual void vf3(u64 index);
    Unk_23aa308_Entry m_entries[1];
};
PKMN_OFFSET_ASSERT(Unk_23aa308, m_entries, 0x8);

// 0x71007bebd0
u32 Unk_23aa308::vf0() {
    return 1;
}

// 0x71007bebe0
void* Unk_23aa308::vf1(u64 index) {
    return m_entries[index].field_0;
}

// 0x71007bebf0
void* Unk_23aa308::vf2(u64 index) {
    return m_entries[index].field_8;
}

// 0x71007bec00
void Unk_23aa308::vf3(u64 index) {
    if (Unk_23aa308_Obj* obj = m_entries[index].field_8)
        obj->vf16(m_entries[index].field_10);
}

class Unk_23aa338 {
public:
    virtual ~Unk_23aa338();
    virtual void vf2();
    virtual u64 vf3();
    virtual void vf4();
    virtual void vf5();
    u8 _8[0x50];
    u64 field_58;
};
PKMN_OFFSET_ASSERT(Unk_23aa338, field_58, 0x58);

// 0x71007bf2f0
u64 Unk_23aa338::vf3() {
    return field_58;
}

class Unk_23aa378_Obj {
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

struct Unk_23aa378_Entry {
    void* field_0;
    Unk_23aa378_Obj* field_8;
    u64 field_10;
    u8 _18[0x8];
};
PKMN_SIZE_ASSERT(Unk_23aa378_Entry, 0x20);

class Unk_23aa378 {
public:
    virtual u32 vf0();
    virtual void* vf1(u64 index);
    virtual void* vf2(u64 index);
    virtual void vf3(u64 index);
    Unk_23aa378_Entry m_entries[1];
};
PKMN_OFFSET_ASSERT(Unk_23aa378, m_entries, 0x8);

// 0x71007bf460
u32 Unk_23aa378::vf0() {
    return 1;
}

// 0x71007bf470
void* Unk_23aa378::vf1(u64 index) {
    return m_entries[index].field_0;
}

// 0x71007bf480
void* Unk_23aa378::vf2(u64 index) {
    return m_entries[index].field_8;
}

// 0x71007bf490
void Unk_23aa378::vf3(u64 index) {
    if (Unk_23aa378_Obj* obj = m_entries[index].field_8)
        obj->vf16(m_entries[index].field_10);
}
