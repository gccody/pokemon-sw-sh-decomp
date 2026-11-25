#pragma once
// A request step base (vtable 0x7102411490), the step derived from it
// (vtable 0x7102411420), and the object the step makes and waits on (vtable
// 0x7102411318, on gflib3's reference-counted object): the step makes it,
// hands a weak reference to its +0x60 interface on, and reads the result the
// interface was given (done, ok, a code). The object's functions and the
// step's vf2/vf11 are in Unk_10a9050.cpp, the base's functions, the step's
// destructor and the object's factory in Unk_10a9660.cpp; their simple
// getters are in src/unsorted/virtual/Unk_10a93e0.cpp (as Unk_2411420's) and
// its type getter in src/unsorted/types/Unk_10a9460.cpp. Placeholder types:
// rename and move once the classes are known.
#include <types.h>

#include "gflib3/Unk_239a418.h"

struct Unk_15bbc70;

// The interface at +0x60 of the object: what it is told when the work is
// done (slots 4 and 5).
class Unk_24108a8 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4(bool ok);
    virtual void vf5(const Unk_15bbc70* result);
    virtual void vf6();
};

// Whether the work is done, and whether it went well.
struct Unk_2411318_State {
    u8 field_0 = 0;
    u8 field_1;
};

class Unk_2411318 : public Unk_239a418, public Unk_24108a8 {
public:
    Unk_2411318() {}
    // 0x71010a9410 (D0); its D1 is the object's D2
    ~Unk_2411318() override;
    // Its type, whose parent is the object's.
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_239a418_GetType());
        return &type;
    }

    // Inline: its thunks are emitted with the vtable, and call its copy
    // (0x71010a9460, src/unsorted/types/Unk_10a9460.cpp).
    const Unk_239a418_Type* vf_type() override { return Unk_GetType(); }
    // The interface's slots 4 and 5 (the object's own vf4/vf5 stay visible).
    using Unk_239a418::vf4;
    using Unk_239a418::vf5;
    void vf4(bool ok) override;
    void vf5(const Unk_15bbc70* result) override;

    void SetResult(u32 result) {
        field_6c = result;
        field_68 = {1, 0};
    }

    Unk_2411318_State GetState() const { return field_68; }

    // Read and written whole: the step loads both flags at once.
    Unk_2411318_State field_68;
    u32 field_6c = 0;
};
static_assert(sizeof(Unk_2411318) == 0x70, "Unk_2411318");
static_assert(__builtin_offsetof(Unk_2411318, field_68) == 0x68, "Unk_2411318::field_68");
static_assert(__builtin_offsetof(Unk_2411318, field_6c) == 0x6c, "Unk_2411318::field_6c");

// What the step's target is told when it fails: a kind and a code.
struct Unk_10a9050_Error {
    u32 field_0;
    u32 field_4;
};

// What the steps call: slot 0 when it's done, slot 1 when it failed.
class Unk_10a9050_Callable {
public:
    virtual void vf0();
    virtual void vf1(Unk_10a9050_Error error);
};

class Unk_2411490 {
public:
    virtual ~Unk_2411490();
    virtual bool vf2() = 0;
    virtual u32 vf3() = 0;
    virtual void vf4();
    virtual void vf5();
    virtual void vf6(u64 value);
    virtual u64 vf7();
    virtual u8 vf8();
    virtual void vf9(u32 value);
    virtual u32 vf10();
    // 0x71010a9870: the target, while its handle still has references.
    virtual Unk_10a9050_Callable* vf11() {
        Unk_239a418_Handle* handle = field_18.m_ptr;
        if (handle != nullptr && handle->field_54.load() != 0)
            return field_20;
        return nullptr;
    }

    u64 field_8;
    u8 field_10;
    u8 _11[0x3];
    u32 field_14;
    // A weak reference: the handle and its object.
    Unk_239a418_Ref<Unk_239a418_Handle> field_18;
    Unk_10a9050_Callable* field_20;
};
PKMN_OFFSET_ASSERT(Unk_2411490, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_2411490, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_2411490, field_14, 0x14);
PKMN_OFFSET_ASSERT(Unk_2411490, field_18, 0x18);
PKMN_OFFSET_ASSERT(Unk_2411490, field_20, 0x20);
static_assert(sizeof(Unk_2411490) == 0x28, "Unk_2411490");

class Unk_2411420 final : public Unk_2411490 {
public:
    ~Unk_2411420() override;
    bool vf2() override;
    u32 vf3() override;
    Unk_10a9050_Callable* vf11() override;

    u32 field_28;
    Unk_10a9050_Callable field_30;
    Unk_239a418_Ref<Unk_2411318> field_38;
    bool field_40;
    u8 field_41;
};
PKMN_OFFSET_ASSERT(Unk_2411420, field_28, 0x28);
PKMN_OFFSET_ASSERT(Unk_2411420, field_30, 0x30);
PKMN_OFFSET_ASSERT(Unk_2411420, field_38, 0x38);
PKMN_OFFSET_ASSERT(Unk_2411420, field_40, 0x40);
PKMN_OFFSET_ASSERT(Unk_2411420, field_41, 0x41);
