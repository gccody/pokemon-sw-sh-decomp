#pragma once
// A class of gflib3 on the reference-counted object's shape (vtable group
// 0x7102398ab8), and Unk_2398848 on it (vtable group 0x7102398848).
// Unk_2398ab8 is abstract: its interface at +0x48 (vtable 0x7102398b08, 34
// slots) adds 28 pure virtual functions to Unk_239a458's six, and its D0s
// are traps. Unk_2398848 fills them (its slots 7-34, the +0x48 vtable's
// 6-33 as thunks). Placeholder names: rename once the classes are known.
#include <types.h>

#include "gflib3/Unk_239a418.h"

// A callable, 0x80 bytes: four functions, then the storage (the shape of
// Unk_241c218_Callable, src/contents/pokecamp/source/Unk_1172690.h). Its
// manager (+0x8) disposes of the storage and +0x10 moves it into another
// callable's; a move takes the functions only when there's something to move.
class Unk_2398af8_Callable {
public:
    struct Header {
        u64 field_0;
        void (*field_8)(void* storage);
        void (*field_10)(void* src, void* dst);
        u64 field_18;
    };

    Unk_2398af8_Callable(Unk_2398af8_Callable&& other) : header() { Take(other); }
    ~Unk_2398af8_Callable() { Clear(); }

    Unk_2398af8_Callable& operator=(Unk_2398af8_Callable&& other) {
        Clear();
        Take(other);
        return *this;
    }

    void Clear() {
        if (void (*manager)(void*) = header.field_8) {
            header = {};
            manager(storage);
        }
    }
    void Take(Unk_2398af8_Callable& other) {
        if (other.header.field_10 != nullptr) {
            other.header.field_10(other.storage, storage);
            header = other.header;
        }
    }

    Header header;
    alignas(16) u8 storage[0x60];
};
PKMN_OFFSET_ASSERT(Unk_2398af8_Callable, storage, 0x20);
PKMN_SIZE_ASSERT(Unk_2398af8_Callable, 0x80);

// The type 0x71027715a0, the parent of Unk_2398848's. Its getter is too big
// to be inlined: the interfaces' vf_type tail-call it (0x71005b2f90).
struct Unk_27715a0 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_239a418_GetType());
        return &type;
    }
};

// The interface at +0x48: Unk_239a458's slots, then 28 of its own. The last
// four set the callables Unk_2398848 keeps. Its vf_type is 0x71005b2f10
// (named _ZN11Unk_2398af83vf5Ev by tools/typegen.py, src/unsorted/types/
// Unk_5b2f10.cpp); the interface at +0x50's (0x71005b2f20) returns the same
// type.
class Unk_2398af8 : public Unk_239a458 {
public:
    const Unk_239a418_Type* vf_type() override { return Unk_27715a0::Unk_GetType(); }
    virtual void vf6() = 0;
    virtual void vf7() = 0;
    virtual void vf8() = 0;
    virtual void vf9() = 0;
    virtual void vf10() = 0;
    virtual void vf11() = 0;
    virtual void vf12() = 0;
    virtual void vf13() = 0;
    virtual void vf14() = 0;
    virtual void vf15() = 0;
    virtual void vf16() = 0;
    virtual void vf17() = 0;
    virtual void vf18() = 0;
    virtual void vf19() = 0;
    virtual void vf20() = 0;
    virtual void vf21() = 0;
    virtual void vf22() = 0;
    virtual void vf23() = 0;
    virtual void vf24() = 0;
    virtual void vf25() = 0;
    virtual void vf26() = 0;
    virtual void vf27() = 0;
    virtual void vf28() = 0;
    virtual void vf29() = 0;
    virtual void vf30(Unk_2398af8_Callable callable) = 0;
    virtual void vf31(Unk_2398af8_Callable callable) = 0;
    virtual void vf32(Unk_2398af8_Callable callable) = 0;
    virtual void vf33(Unk_2398af8_Callable callable) = 0;
};

// The interface at +0x50: Unk_239a498's slots. Its vf_type is 0x71005b2f20
// (named _ZN11Unk_2398c183vf0Ev by tools/typegen.py).
class Unk_2398c18 : public Unk_239a498 {
public:
    const Unk_239a418_Type* vf_type() override { return Unk_27715a0::Unk_GetType(); }
};

// The object: Unk_239a418's shape (the handle at +0x58), with Unk_2398af8 as
// its interface at +0x48. Its D2 (0x71005b2e50) is its key function
// (src/gflib3/Unk_5b2d50.cpp), so its vtables and the handle getter's
// thunk come with it. vf3 is 0x71005b27c0 (src/unsorted/virtual/Unk_59e460.cpp).
class Unk_2398ab8 : public Unk_239a418_Base, public Unk_2398af8, public Unk_2398c18 {
public:
    ~Unk_2398ab8() override;
    Unk_239a418_Ref<Unk_239a418_Handle> vf2() override { return m_handle; }
    void vf3() override;
    void vf4() override;
    void vf5() override;

    Unk_239a418_Ref<Unk_239a418_Handle> m_handle;
};
PKMN_SIZE_ASSERT(Unk_2398ab8, 0x60);
PKMN_OFFSET_ASSERT(Unk_2398ab8, m_handle, 0x58);

// Its size isn't known here: only the callables its last four slots set.
class Unk_2398848 : public Unk_2398ab8 {
public:
    ~Unk_2398848() override;
    void vf30(Unk_2398af8_Callable callable) override;
    void vf31(Unk_2398af8_Callable callable) override;
    void vf32(Unk_2398af8_Callable callable) override;
    void vf33(Unk_2398af8_Callable callable) override;

    u8 _60[0xd0];
    Unk_2398af8_Callable field_130;
    Unk_2398af8_Callable field_1b0;
    Unk_2398af8_Callable field_230;
    Unk_2398af8_Callable field_2b0;
};
PKMN_OFFSET_ASSERT(Unk_2398848, field_130, 0x130);
PKMN_OFFSET_ASSERT(Unk_2398848, field_1b0, 0x1b0);
PKMN_OFFSET_ASSERT(Unk_2398848, field_230, 0x230);
PKMN_OFFSET_ASSERT(Unk_2398848, field_2b0, 0x2b0);
