// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>
#include "unsorted/Unk_23f43c8.h"

// Tail-called by lifted functions. Placeholders, like the forwarders' callees.
void Unk_1432860(u64, u32);

// The type of Unk_243ac98: other classes' getters call its getter.
struct Unk_27f0968 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23f43c8::Unk_GetType());
        return &type;
    }
};

class Unk_243ac98 : public Unk_23f43c8 {
public:
    const Unk_239a418_Type* vf_type() override;
    void vf7() override;
};

// 0x7101435ee0; its type 0x7101430b90
const Unk_239a418_Type* Unk_243ac98::vf_type() {
    return Unk_27f0968::Unk_GetType();
}

class Unk_243ad68 : public Unk_23f43c8 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_27f0968::Unk_GetType());
        return &type;
    }

    const Unk_239a418_Type* vf_type() override;
    void vf7() override;
    u32 vf8() override;
    void vf9() override;
    u64 _78;
    u64 _80;
    u64 _88;
    u64 _90;
    Unk_239a418_Ref<Unk_239a418> field_98;
    Unk_239a418_Ref<Unk_239a418> field_a0;
    Unk_239a418_Ref<Unk_239a418> field_a8;
};
PKMN_OFFSET_ASSERT(Unk_243ad68, field_98, 0x98);
PKMN_OFFSET_ASSERT(Unk_243ad68, field_a0, 0xa0);
PKMN_OFFSET_ASSERT(Unk_243ad68, field_a8, 0xa8);

// 0x71014363b0
void Unk_243ad68::vf9() {}

// 0x71014364e0
const Unk_239a418_Type* Unk_243ad68::vf_type() {
    return Unk_GetType();
}

class Unk_243ae38 : public Unk_23f43c8 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_27f0968::Unk_GetType());
        return &type;
    }

    const Unk_239a418_Type* vf_type() override;
    void vf7() override;
    u32 vf8() override;
    void vf9() override;
    u64 field_78;
};
PKMN_OFFSET_ASSERT(Unk_243ae38, field_78, 0x78);

// 0x7101436db0
void Unk_243ae38::vf9() {
    Unk_1432860(field_78, 0);
}

// 0x7101436dd0
const Unk_239a418_Type* Unk_243ae38::vf_type() {
    return Unk_GetType();
}

class Unk_243af38 : public Unk_23f43c8 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_27f0968::Unk_GetType());
        return &type;
    }

    const Unk_239a418_Type* vf_type() override;
    void vf7() override;
    u32 vf8() override;
    void vf9() override;
    u64 _78;
    u64 _80;
    u64 _88;
    u64 _90;
    Unk_239a418_Ref<Unk_239a418> field_98;
};
PKMN_OFFSET_ASSERT(Unk_243af38, field_98, 0x98);

// 0x7101437270
const Unk_239a418_Type* Unk_243af38::vf_type() {
    return Unk_GetType();
}

class Unk_243b008 : public Unk_23f43c8 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_27f0968::Unk_GetType());
        return &type;
    }

    const Unk_239a418_Type* vf_type() override;
    void vf7() override;
    u32 vf8() override;
    void vf9() override;
    u64 _78;
    u64 _80;
    u64 _88;
    u64 _90;
    u64 _98;
    Unk_239a418_Ref<Unk_239a418> field_a0;
    Unk_239a418_Ref<Unk_239a418> field_a8;
    Unk_239a418_Ref<Unk_239a418> field_b0;
};
PKMN_OFFSET_ASSERT(Unk_243b008, field_a0, 0xa0);
PKMN_OFFSET_ASSERT(Unk_243b008, field_a8, 0xa8);
PKMN_OFFSET_ASSERT(Unk_243b008, field_b0, 0xb0);

// 0x7101437ad0
void Unk_243b008::vf9() {}

// 0x7101437c00
const Unk_239a418_Type* Unk_243b008::vf_type() {
    return Unk_GetType();
}

class Unk_243b1a8 : public Unk_23f43c8 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_27f0968::Unk_GetType());
        return &type;
    }

    const Unk_239a418_Type* vf_type() override;
    void vf7() override;
    u32 vf8() override;
    void vf9() override;
};

// 0x71014387f0
void Unk_243b1a8::vf9() {}

// 0x7101438810
const Unk_239a418_Type* Unk_243b1a8::vf_type() {
    return Unk_GetType();
}

class Unk_243b278 : public Unk_23f43c8 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_27f0968::Unk_GetType());
        return &type;
    }

    const Unk_239a418_Type* vf_type() override;
    void vf7() override;
    u32 vf8() override;
    void vf9() override;
};

// 0x7101438a50
void Unk_243b278::vf9() {}

// 0x7101438a70
const Unk_239a418_Type* Unk_243b278::vf_type() {
    return Unk_GetType();
}
