// Scope: common
// Type getters of classes on gflib3's object (tools/typegen.py, generated: rewrite,
// don't edit). Placeholder classes, named after their vtables, and types, named
// after their type objects where no class is known: rename them once they are.
#include <types.h>

#include "gflib3/Unk_239a418.h"

// The type 0x71027d6220: its getter is out of line.
struct Unk_23ddd68 {
    static const Unk_239a418_Type* Unk_GetType();
};

// The type 0x71027dcc30: its getter is out of line.
struct Unk_23dffd8 {
    static const Unk_239a418_Type* Unk_GetType();
};

// The type 0x71027dcbe0: its getter is out of line.
struct Unk_23eaf68 {
    static const Unk_239a418_Type* Unk_GetType();
};

// Unk_23dcdd0 (unsorted/Unk_23dcdd0.h), as far as this file needs it: its destructor is out of
// line (its D2, which the D0s and thunks of the classes on it tail-call).
class Unk_23dcdd0 : public Unk_239a418 {
public:
    ~Unk_23dcdd0() override;
    const Unk_239a418_Type* vf_type() override;
    virtual void vf7();
    virtual void vf8();
    virtual u32 vf9();
    virtual u32 vf10();
    virtual u8 vf11();
    virtual u32 vf12();
    virtual void vf13();
    virtual u8 vf14();
    virtual u8 vf15();
    virtual void vf16();
    virtual bool vf17();
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
    virtual u32 vf33();
    virtual void vf34();
    virtual void vf35();
    virtual u32 vf36();
    virtual void vf37();
    virtual f32 vf38();
    virtual void vf39();
    virtual void vf40();
    virtual void vf41();
    virtual void vf42();
    virtual u32 vf43();
    virtual void vf44();
    virtual void vf45();
    virtual u32 vf46();
    virtual void vf47();
    virtual void vf48();
    virtual void vf49();
    virtual void vf50();
    virtual void vf51();
    virtual void vf52();
    virtual void vf53();
    virtual void vf54();
    virtual void vf55();
    virtual void vf56();
    virtual void vf57();
    virtual void vf58();
    virtual void vf59();
    virtual void vf60();
    virtual void vf61();
    virtual void vf62();
    virtual void vf63();
    virtual void vf64();
    virtual void vf65();
    virtual void vf66();
    virtual void vf67();
    virtual u32 vf68();
};

// The type 0x71027efd50.
struct Unk_23e3950 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23ddd68::Unk_GetType());
        return &type;
    }
};

// vtable 0x71023ead88: vf_type and its thunks 0x7100d50ff0 (+0x48), 0x7100d51060 (+0x50).
// Its base and its other functions aren't written here.
class Unk_23ead78 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23eaf68::Unk_GetType());
        return &type;
    }

    ~Unk_23ead78() override;
    const Unk_239a418_Type* vf_type() override;
};

// vtable 0x71023eb360: vf_type and its thunks 0x7100d51ce0 (+0x48), 0x7100d51d50 (+0x50).
// vf_type is its key function, so its vtable is emitted here, with the D0 and the
// destructor thunks below: its destructor is implicit, and they tail-call its
// base's D2 (out of line).
// 0x7100d51c40
// 0x7100d51cc0
// 0x7100d51cd0
// 0x7100d51dc0
// 0x7100d51dd0
class Unk_23eb350 : public Unk_23dcdd0 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23dffd8::Unk_GetType());
        return &type;
    }

    const Unk_239a418_Type* vf_type() override;
};

// vtable 0x71023eb600: vf_type and its thunks 0x7100d52160 (+0x48), 0x7100d52210 (+0x50).
// Its base and its other functions aren't written here.
class Unk_23eb5f0 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23e3950::Unk_GetType());
        return &type;
    }

    ~Unk_23eb5f0() override;
    const Unk_239a418_Type* vf_type() override;
};

// 0x7100d50ea0
// 0x7100d50ff0
// 0x7100d51060
const Unk_239a418_Type* Unk_23ead78::vf_type() {
    return Unk_GetType();
}

// 0x7100d51c50
// 0x7100d51ce0
// 0x7100d51d50
const Unk_239a418_Type* Unk_23eb350::vf_type() {
    return Unk_GetType();
}

// 0x7100d52010
// 0x7100d52160
// 0x7100d52210
const Unk_239a418_Type* Unk_23eb5f0::vf_type() {
    return Unk_GetType();
}
