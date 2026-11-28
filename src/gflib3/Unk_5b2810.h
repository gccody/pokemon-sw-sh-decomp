#pragma once
// A class of gflib3 on the reference-counted object's shape (vtable group
// 0x7102398ab8), and Unk_2398848 on it (vtable group 0x7102398848).
// Unk_2398ab8 is abstract: its interface at +0x48 (vtable 0x7102398b08, 34
// slots) adds 28 pure virtual functions to Unk_239a458's six, and its D0s
// are traps. Unk_2398848 fills them (its slots 7-34, the +0x48 vtable's
// 6-33 as thunks). Placeholder names: rename once the classes are known.
#include <vector>

#include <types.h>

#include "battle/battle_logic/source/netwatch/Unk_8a9570.h"
#include "gflib3/Unk_239a418.h"
#include "unsorted/Unk_2771620.h"

// A callable, 0x80 bytes: four functions, then the storage (the shape of
// Unk_241c218_Callable, src/contents/pokecamp/source/Unk_1172690.h). Its
// manager (+0x8) disposes of the storage and +0x10 moves it into another
// callable's; a move takes the functions only when there's something to move.
// The first calls it, with its storage and the argument (Unk_2398848::vf25).
class Unk_2398af8_Callable {
public:
    struct Header {
        void (*field_0)(void* storage, void* arg);
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
    explicit operator bool() const { return header.field_0 != nullptr; }
    void operator()(void* arg) { header.field_0(storage, arg); }

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

// What names an entry of one of Unk_2398848's vectors: whether it names one,
// and its index (slots 24-28 take it by reference; slot 9, 0x71005b0cc0,
// returns one, found or not).
struct Unk_2398848_Id {
    bool field_0;
    u32 field_4;
};
PKMN_SIZE_ASSERT(Unk_2398848_Id, 0x8);
PKMN_OFFSET_ASSERT(Unk_2398848_Id, field_4, 0x4);

// The interface at +0x48: Unk_239a458's slots, then 28 of its own. The last
// four set the callables Unk_2398848 keeps. Slots 24-29 are the ones on its
// vector at +0xf8 (Unk_2398848_Trigger); the others' signatures aren't
// written yet. Its vf_type is 0x71005b2f10
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
    virtual const Unk_8a9570_Name& vf24(const Unk_2398848_Id& id) = 0;
    virtual void vf25(const Unk_2398848_Id& id, bool value) = 0;
    virtual bool vf26(const Unk_2398848_Id& id) = 0;
    virtual void vf27(const Unk_2398848_Id& id) = 0;
    virtual bool vf28(const Unk_2398848_Id& id) = 0;
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
// its interface at +0x48. Its D2 (0x71005b2e50) is inline: Unk_2398848's
// (0x71005b2530) inlines it. vf4 is declared first, the key function
// (src/gflib3/Unk_5b2810.cpp): the vtables come with it, and with them the D2,
// the D0, their thunks and the handle getter's thunk. vf3 is 0x71005b27c0
// (written as a free function, src/unsorted/virtual/Unk_59e460.cpp).
class Unk_2398ab8 : public Unk_239a418_Base, public Unk_2398af8, public Unk_2398c18 {
public:
    ~Unk_2398ab8() override {}
    Unk_239a418_Ref<Unk_239a418_Handle> vf2() override { return m_handle; }
    void vf4() override;
    void vf5() override;
    void vf3() override;

    Unk_239a418_Ref<Unk_239a418_Handle> m_handle;
};
PKMN_SIZE_ASSERT(Unk_2398ab8, 0x60);
PKMN_OFFSET_ASSERT(Unk_2398ab8, m_handle, 0x58);

// An entry of Unk_2398848's vectors, 0x30 bytes: what it reads first (a
// flatbuffers table, src/gflib3/Unk_5b2d50.cpp), its name, then its value:
// a u32 (+0x68), a float (+0x98) or a bool (+0xc8).
template <class T>
struct Unk_2398848_Entry {
    const void* field_0;
    Unk_8a9570_Name field_8;
    T field_28;
};
PKMN_SIZE_ASSERT(Unk_2398848_Entry<u32>, 0x30);
PKMN_OFFSET_ASSERT(Unk_2398848_Entry<u32>, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_2398848_Entry<u32>, field_28, 0x28);
PKMN_SIZE_ASSERT(Unk_2398848_Entry<f32>, 0x30);
PKMN_SIZE_ASSERT(Unk_2398848_Entry<bool>, 0x30);

// The entries of the vector at +0xf8: a value (slot 25 sets it, telling the
// callable at +0x2b0 when it changes) and a flag (slot 27 sets it; slot 29
// clears each entry's flag, or its value when the flag wasn't set).
struct Unk_2398848_Trigger {
    const void* field_0;
    Unk_8a9570_Name field_8;
    bool field_28;
    bool field_29;
};
PKMN_SIZE_ASSERT(Unk_2398848_Trigger, 0x30);
PKMN_OFFSET_ASSERT(Unk_2398848_Trigger, field_28, 0x28);
PKMN_OFFSET_ASSERT(Unk_2398848_Trigger, field_29, 0x29);

// What slot 25 hands the callable at +0x2b0: the entry's name (its words,
// the reference a Unk_239a418_Ref2: its copy tests the pointer it loaded) and
// id, then its value before and after. The id is taken by value: it's loaded
// before the name is copied.
struct Unk_2398848_Event {
    Unk_2398848_Event(const Unk_8a9570_Name& name, Unk_2398848_Id id, bool before, bool after)
        : field_0(name.field_0),
          field_8(name.field_8),
          field_10(name.field_10),
          field_18(name.field_18),
          field_20(id),
          field_28(before),
          field_29(after) {}

    u64 field_0;
    const char* field_8;
    u64 field_10;
    Unk_239a418_Ref2<Unk_239a418> field_18;
    Unk_2398848_Id field_20;
    bool field_28;
    bool field_29;
};
PKMN_SIZE_ASSERT(Unk_2398848_Event, 0x30);
PKMN_OFFSET_ASSERT(Unk_2398848_Event, field_18, 0x18);
PKMN_OFFSET_ASSERT(Unk_2398848_Event, field_20, 0x20);
PKMN_OFFSET_ASSERT(Unk_2398848_Event, field_28, 0x28);

template <class T>
using Unk_2398848_Vector = std::vector<T, Unk_2771620_Allocator<T>>;

// 0x338 bytes or more: its D2 (0x71005b2530) is its key function
// (src/gflib3/Unk_5b1fd0.cpp). vf_type is 0x71005b2890
// (src/unsorted/types/Unk_59b7e0.cpp).
class Unk_2398848 : public Unk_2398ab8 {
public:
    ~Unk_2398848() override;
    const Unk_239a418_Type* vf_type() override;
    void vf6() override;
    void vf7() override;
    void vf8() override;
    void vf9() override;
    void vf10() override;
    void vf11() override;
    void vf12() override;
    void vf13() override;
    void vf14() override;
    void vf15() override;
    void vf16() override;
    void vf17() override;
    void vf18() override;
    void vf19() override;
    void vf20() override;
    void vf21() override;
    void vf22() override;
    void vf23() override;
    const Unk_8a9570_Name& vf24(const Unk_2398848_Id& id) override;
    void vf25(const Unk_2398848_Id& id, bool value) override;
    bool vf26(const Unk_2398848_Id& id) override;
    void vf27(const Unk_2398848_Id& id) override;
    bool vf28(const Unk_2398848_Id& id) override;
    void vf29() override;
    void vf30(Unk_2398af8_Callable callable) override;
    void vf31(Unk_2398af8_Callable callable) override;
    void vf32(Unk_2398af8_Callable callable) override;
    void vf33(Unk_2398af8_Callable callable) override;

    u8 _60[0x8];
    Unk_2398848_Vector<Unk_2398848_Entry<u32>> field_68;
    Unk_2398848_Vector<Unk_2398848_Entry<f32>> field_98;
    Unk_2398848_Vector<Unk_2398848_Entry<bool>> field_c8;
    Unk_2398848_Vector<Unk_2398848_Trigger> field_f8;
    u8 _128[0x8];
    Unk_2398af8_Callable field_130;
    Unk_2398af8_Callable field_1b0;
    Unk_2398af8_Callable field_230;
    Unk_2398af8_Callable field_2b0;
};
PKMN_OFFSET_ASSERT(Unk_2398848, field_68, 0x68);
PKMN_OFFSET_ASSERT(Unk_2398848, field_98, 0x98);
PKMN_OFFSET_ASSERT(Unk_2398848, field_c8, 0xc8);
PKMN_OFFSET_ASSERT(Unk_2398848, field_f8, 0xf8);
PKMN_OFFSET_ASSERT(Unk_2398848, field_130, 0x130);
PKMN_OFFSET_ASSERT(Unk_2398848, field_1b0, 0x1b0);
PKMN_OFFSET_ASSERT(Unk_2398848, field_230, 0x230);
PKMN_OFFSET_ASSERT(Unk_2398848, field_2b0, 0x2b0);
