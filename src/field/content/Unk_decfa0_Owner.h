#pragma once
// More of what HaxeSymbolPokemonObject::field_0 points to (Unk_debce0_Owner.h has the
// parameters its getters read): its components at 0x208, the effects at 0x968/0x970,
// the battle and pop types and the script state at 0xb18-0xb24, the ground raycast
// flag at 0xbb9 and the voice player at 0xbc0. Placeholder names until the class is
// known; the functions it calls are free functions on it for the same reason.
#include <arm_neon.h>

#include <vector>

#include <types.h>

#include "gflib3/Unk_239a418.h"

// A component of the Pokemon (an object on gflib3's object).
class Unk_decfa0_Component : public Unk_239a418 {
public:
    // The component as a T, or null when it isn't one: through its +0x50 interface.
    template <class T>
    T* Unk_Cast() {
        Unk_239a498* object = this;
        const Unk_239a418_Type* type = object->vf_type();
        const Unk_239a418_Type* kind = T::Unk_GetType();
        for (; type != nullptr; type = type->field_0)
            if (type == kind)
                return static_cast<T*>(object);
        return nullptr;
    }
};

// The type between Unk_239a418 and Unk_27dbf28 (0x71027effd0).
struct Unk_27effd0 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_239a418_GetType());
        return &type;
    }
};

// The type between Unk_27effd0 and Unk_23e7a38 (0x71027dbf28): its getter is out of
// line, 0x7100ded8b0.
struct Unk_27dbf28 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_27effd0::Unk_GetType());
        return &type;
    }
};

// The motion component (vtable 0x71023e7a38, src/unsorted/virtual/Unk_d0ca80.cpp).
class Unk_23e7a38 : public Unk_decfa0_Component {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_27dbf28::Unk_GetType());
        return &type;
    }

    // 0x7100d0d4b0
    bool Unk_d0d4b0();
    // 0x7100d0d500 (the rotation, in radians, that faces the position)
    float32x4_t Unk_d0d500(const float32x4_t& target);
};

// An object on gflib3's object (its handle getter is slot 2).
struct Unk_decfa0_Owner : Unk_239a418 {
    // 0x7100d0b230
    void Unk_d0b230(float radius);
    // 0x7100d0a900
    bool Unk_d0a900() const;
    // 0x7100d0b1f0
    void Unk_d0b1f0(const float32x4_t& offset);
    // 0x7100d0b200
    float32x4_t Unk_d0b200() const;
    // 0x7100d0acd0
    void Unk_d0acd0(const float32x4_t& offset);
    // 0x7100d0b210
    float32x4_t Unk_d0b210() const;
    // 0x7100d0b580
    float32x4_t Unk_d0b580(const float32x4_t& from, const float32x4_t& to) const;
    // 0x7100d0b710
    void Unk_d0b710();
    // 0x7100d0b850
    void Unk_d0b850(const u64& effect);
    // 0x7100d0bd80
    void Unk_d0bd80(int type);
    // 0x7100d0be30
    void Unk_d0be30(int se);

    void Unk_SetEnableGroundRaycast(bool enable) { field_bb9 = enable; }
    bool Unk_GetEnableGroundRaycast() const { return field_bb9; }

    // The first component that is a T, or null.
    template <class T>
    T* Unk_GetComponent() const {
        for (Unk_decfa0_Component* component : field_208) {
            if (T* found = component->Unk_Cast<T>())
                return found;
        }
        return nullptr;
    }

    u8 _60[0x208 - 0x60];
    std::vector<Unk_decfa0_Component*> field_208;
    u8 _220[0x968 - 0x220];
    u64 field_968;
    u64 field_970;
    u8 _978[0xb18 - 0x978];
    int field_b18;
    int field_b1c;
    u8 _b20[0xb24 - 0xb20];
    int field_b24;
    u8 _b28[0xbb9 - 0xb28];
    bool field_bb9;
    u8 _bba[0xbc0 - 0xbba];
    void* field_bc0;
};
PKMN_OFFSET_ASSERT(Unk_decfa0_Owner, field_208, 0x208);
PKMN_OFFSET_ASSERT(Unk_decfa0_Owner, field_968, 0x968);
PKMN_OFFSET_ASSERT(Unk_decfa0_Owner, field_970, 0x970);
PKMN_OFFSET_ASSERT(Unk_decfa0_Owner, field_b18, 0xb18);
PKMN_OFFSET_ASSERT(Unk_decfa0_Owner, field_b1c, 0xb1c);
PKMN_OFFSET_ASSERT(Unk_decfa0_Owner, field_b24, 0xb24);
PKMN_OFFSET_ASSERT(Unk_decfa0_Owner, field_bb9, 0xbb9);
PKMN_OFFSET_ASSERT(Unk_decfa0_Owner, field_bc0, 0xbc0);
