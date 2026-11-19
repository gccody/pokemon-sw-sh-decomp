#pragma once
// gflib3's strings and hashed names. A string (Unk_d0c0_String, 0x8 bytes) is
// a reference to a string object (Unk_2399470): its constructor
// (0x710000d0c0) makes one from a C string, or refers to a static empty one.
// A name (Unk_5cfaf0_Name, 0x20 bytes) is a string's hash, characters and
// count, and the string object that keeps them alive; a name in static data
// (Unk_5cfad0_Literal) has no string object. The battle scene's sequence
// functions (src/battle/battle_scene) and the contents' apps (src/contents)
// both use them. Placeholder names: rename once the classes are known.
//
// The string object is on gflib3's other reference-counted base,
// Unk_239a4c0: the constructor's static empty object has its count at +0x50
// and the empty string's hash (Game Freak's FNV-1a basis) at +0x58, and
// references are added and dropped through slots 2 and 3 of its +0x48
// interface (Unk_239a4f8::vf3 and vf4).
#include <cstddef>

#include <types.h>

#include "gflib3/Unk_239a4c0.h"

// The string object (vtable 0x7102399470): the characters' hash (as
// Unk_5cfaf0_Name's), the characters and their count.
class Unk_2399470 : public Unk_239a4c0 {
public:
    void vf2() override;

    u64 field_58;
    const char* field_60;
    u64 field_68;
};
static_assert(sizeof(Unk_2399470) == 0x70, "Unk_2399470");

// A hashed name, 0x20 bytes: its 64-bit FNV-1a hash (from 0xcbf29ce484222645,
// Game Freak's basis), its characters and their count, and the string object
// that keeps them alive (null for a literal). constexpr: one made from a
// literal has its hash folded, one made from a character array (the battle
// sequence's) hashes it inline. Names compare by their hashes.
class Unk_5cfaf0_Name {
public:
    static constexpr u64 Hash(const char* str) {
        u64 hash = 0xcbf29ce484222645;
        for (; *str != '\0'; ++str)
            hash = (hash ^ static_cast<u8>(*str)) * 0x100000001b3;
        return hash;
    }

    template <size_t N>
    constexpr Unk_5cfaf0_Name(const char (&str)[N])
        : field_0(Hash(str)), field_8(str), field_10(N - 1), field_18(nullptr) {}
    Unk_5cfaf0_Name(const Unk_5cfaf0_Name& other)
        : field_0(other.field_0),
          field_8(other.field_8),
          field_10(other.field_10),
          field_18(other.field_18) {
        if (field_18)
            static_cast<Unk_239a4f8*>(field_18)->vf3();
    }
    ~Unk_5cfaf0_Name() {
        if (field_18) {
            static_cast<Unk_239a4f8*>(field_18)->vf4();
            field_18 = nullptr;
        }
    }

    bool operator==(const Unk_5cfaf0_Name& other) const { return field_0 == other.field_0; }

    u64 field_0;
    const char* field_8;
    u64 field_10;
    Unk_2399470* field_18;
};
static_assert(sizeof(Unk_5cfaf0_Name) == 0x20, "Unk_5cfaf0_Name");

// A name in static data, 0x18 bytes: a literal's hash, characters and count.
// constexpr: one made from a literal is a constant.
struct Unk_5cfad0_Literal {
    template <size_t N>
    constexpr Unk_5cfad0_Literal(const char (&str)[N])
        : field_0(Unk_5cfaf0_Name::Hash(str)), field_8(str), field_10(N - 1) {}

    // As a name (0x71005cfad0), without a string object.
    Unk_5cfaf0_Name Unk_5cfad0() const;

    u64 field_0;
    const char* field_8;
    u64 field_10;
};
static_assert(sizeof(Unk_5cfad0_Literal) == 0x18, "Unk_5cfad0_Literal");

class Unk_d0c0_String {
public:
    explicit Unk_d0c0_String(const char* str);  // 0x710000d0c0
    ~Unk_d0c0_String() { Release(); }

    Unk_d0c0_String& operator=(Unk_d0c0_String&& other) {
        Release();
        m_ptr = other.m_ptr;
        other.m_ptr = nullptr;
        return *this;
    }

    // Drops the reference: released first, then cleared.
    void Release() {
        if (m_ptr) {
            static_cast<Unk_239a4f8*>(m_ptr)->vf4();
            m_ptr = nullptr;
        }
    }

    // Its name (0x71005cfaf0): it keeps the string object.
    Unk_5cfaf0_Name Unk_5cfaf0() const;

    Unk_2399470* m_ptr;
};
static_assert(sizeof(Unk_d0c0_String) == 0x8, "Unk_d0c0_String");
