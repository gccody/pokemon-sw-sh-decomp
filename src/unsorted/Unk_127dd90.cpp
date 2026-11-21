// Scope: common
//
// A TU of game/pokecamp (0x710127dd90 to its static initialiser at
// 0x7101285150): eight classes on Unk_24284d0 (src/unsorted/Unk_24284d0.h)
// with internal linkage, and the functions that make them. The classes are
// named after their vtables.
//
// Each class has a type whose parent is one type of this file (the static at
// 0x71027ee3a0), so there is a class between them and Unk_24284d0; its vf10
// (0x710127e810) is the one seven of them have. None has a member to destroy:
// their D2 is Unk_24284d0's (clang replaces the one by the other), and their
// D0 and the destructor thunks are copies of it.
//
// Their vf7 sets the object's callables up (480 to 840 bytes, with the
// lambdas it stores): not decompiled yet, like the larger vf8s.
#include "unsorted/Unk_24284d0_Make.h"

namespace {

class Unk_127dd90_Base : public Unk_24284d0 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_24284d0::Unk_GetType());
        return &type;
    }
    const Unk_239a418_Type* vf_type() override { return Unk_GetType(); }

    // 0x710127e810
    void vf10() override {
        vf7(Unk_126ac90_getField68(reinterpret_cast<const Unk_126ac90*>(this)));
    }
};

// A class's own type and its getter.
#define UNK_127DD90_TYPE()                                             \
    static const Unk_239a418_Type* Unk_GetType() {                     \
        static Unk_239a418_Type type(Unk_127dd90_Base::Unk_GetType()); \
        return &type;                                                  \
    }                                                                  \
    const Unk_239a418_Type* vf_type() override {                       \
        return Unk_GetType();                                          \
    }

// The vf8 five of them have: field_70, or the object itself.
#define UNK_127DD90_VF8()                          \
    Unk_239a418_Ref<Unk_239a418> vf8() override {  \
        Unk_126b1f0();                             \
        if (field_70.m_ptr)                        \
            return field_70;                       \
        return Unk_239a418_Ref<Unk_239a418>(this); \
    }

// vtable 0x7102429af0: D0 0x710127e1e0, vf_type 0x710127e330, vf8 0x710127e7b0
class Unk_2429af0 : public Unk_127dd90_Base {
public:
    Unk_2429af0() : Unk_127dd90_Base() { field_60 = 1; }

    UNK_127DD90_TYPE()
    void vf7(u64 arg) override;  // 0x710127e490
    UNK_127DD90_VF8()
};

// vtable 0x7102429bc0: D0 0x710127f170, vf_type 0x710127f2c0, vf8 0x710127f5b0
class Unk_2429bc0 : public Unk_127dd90_Base {
public:
    Unk_2429bc0() { field_60 = 7; }

    UNK_127DD90_TYPE()
    void vf7(u64 arg) override;  // 0x710127f420
    UNK_127DD90_VF8()
};

// vtable 0x7102429c90: D0 0x710127fbf0, vf_type 0x710127fd40, vf8 0x71012801f0
class Unk_2429c90 : public Unk_127dd90_Base {
public:
    Unk_2429c90() : Unk_127dd90_Base() { field_60 = 2; }

    UNK_127DD90_TYPE()
    void vf7(u64 arg) override;  // 0x710127fea0
    UNK_127DD90_VF8()
};

// vtable 0x7102429d60: D0 0x71012809b0, vf_type 0x7101280b00, vf8 0x7101280e40
class Unk_2429d60 : public Unk_127dd90_Base {
public:
    Unk_2429d60() : Unk_127dd90_Base() { field_60 = 3; }

    UNK_127DD90_TYPE()
    void vf7(u64 arg) override;  // 0x7101280c60
    UNK_127DD90_VF8()
};

// vtable 0x7102429e30: D0 0x7101281640, vf_type 0x7101281790
class alignas(16) Unk_2429e30 : public Unk_127dd90_Base {
public:
    Unk_2429e30() : Unk_127dd90_Base() { field_60 = 6; }

    UNK_127DD90_TYPE()
    // 0x71012818f0
    void vf7(u64 arg) override {
        Unk_24284d0::vf7(arg);
        Unk_126aca0()->field_70 = 7;
    }
    Unk_239a418_Ref<Unk_239a418> vf8() override;  // 0x7101281920
    // 0x7101281b20
    void vf9() override {
        Unk_24284d0::vf9();
        Unk_126b5b0().m_ptr->Unk_126d2f0();
    }

    u16 field_3c0 = 1;
};
static_assert(sizeof(Unk_2429e30) == 0x3d0, "Unk_2429e30");

// vtable 0x7102429f00: D0 0x7101282620, vf_type 0x7101282770, vf8 0x7101282ab0
class Unk_2429f00 : public Unk_127dd90_Base {
public:
    Unk_2429f00() : Unk_127dd90_Base() { field_60 = 4; }

    UNK_127DD90_TYPE()
    void vf7(u64 arg) override;  // 0x71012828d0
    UNK_127DD90_VF8()
};

// vtable 0x7102429fd0: D0 0x71012832b0, vf_type 0x7101283400
class Unk_2429fd0 : public Unk_127dd90_Base {
public:
    Unk_2429fd0() : Unk_127dd90_Base() { field_60 = 5; }

    UNK_127DD90_TYPE()
    // 0x7101283560
    void vf7(u64 arg) override {
        Unk_24284d0::vf7(arg);
        Unk_126aca0()->field_70 = 2;
    }
    // 0x7101283590
    Unk_239a418_Ref<Unk_239a418> vf8() override { return Unk_239a418_Ref<Unk_239a418>(nullptr); }
    // 0x71012835a0
    void vf9() override {
        Unk_24284d0::vf9();
        Unk_126b5b0().m_ptr->Unk_126d2f0();
    }
};

// vtable 0x710242a0a0: D0 0x7101283ed0, vf_type 0x7101284020
class Unk_242a0a0 : public Unk_127dd90_Base {
public:
    Unk_242a0a0() : Unk_127dd90_Base() { field_60 = 0; }

    UNK_127DD90_TYPE()
    void vf7(u64 arg) override;                   // 0x7101284180
    Unk_239a418_Ref<Unk_239a418> vf8() override;  // 0x71012844a0
    void vf10() override;                         // 0x71012846c0
};

}  // namespace

// The functions that make the classes, in the classes' order rather than
// their own: a class's vtable, its functions and its type's statics are
// emitted where it's first used, and the eight types' statics are laid out
// in the classes' order (clang merges them into one object, and the getters
// address them from the first). In the original that order comes from the
// vf7s and the callables that aren't written yet (one makes the next).

// 0x710127de10
void Unk_127de10(Unk_239a418_Ref<Unk_24284d0>* out, Unk_239a418_Allocator* allocator) {
    Unk_Make<Unk_2429af0>(out, allocator);
}

// 0x710127f080
void Unk_127f080(Unk_239a418_Ref<Unk_24284d0>* out, Unk_239a418_Allocator* allocator) {
    Unk_Make<Unk_2429bc0>(out, allocator);
}

// 0x710127ef60
void Unk_127ef60(Unk_239a418_Ref<Unk_24284d0>* out, Unk_239a418_Allocator* allocator) {
    Unk_Make<Unk_2429c90>(out, allocator);
}

// 0x7101280790
void Unk_1280790(Unk_24284d0** captured) {
    Unk_Next<Unk_2429d60>(*captured, 0x1f2bffc3f5599b31);
}

// 0x7101281520
void Unk_1281520(Unk_239a418_Ref<Unk_24284d0>* out, Unk_239a418_Allocator* allocator) {
    Unk_Make<Unk_2429e30>(out, allocator);
}

// 0x7101282400
void Unk_1282400(Unk_24284d0** captured) {
    Unk_Next<Unk_2429f00>(*captured, 0xcf2e38d49d8fd87e);
}

// 0x7101283190
void Unk_1283190(Unk_239a418_Ref<Unk_24284d0>* out, Unk_239a418_Allocator* allocator) {
    Unk_Make<Unk_2429fd0>(out, allocator);
}

// 0x710127df30
void Unk_127df30(Unk_239a418_Ref<Unk_24284d0>* out, Unk_239a418_Allocator* allocator) {
    Unk_Make<Unk_242a0a0>(out, allocator);
}
