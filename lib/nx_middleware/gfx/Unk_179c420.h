#pragma once

// NintendoWare ui2d 7.3.2: a named object that lists other objects (vtable
// 0x71024931b0, its destructors only; no RTTI) and the lists of them.
// Placeholder names.
#include <types.h>
#include "nx_middleware/gfx/Unk_179cc10.h"

// What 0x710179c940 reads its name and its elements' names from.
struct Unk_179c940_Res {
    u8 _0[0x8];
    char name[0x22];
    u16 count;
    char elementNames[1][0x18];
};
PKMN_OFFSET_ASSERT(Unk_179c940_Res, name, 0x8);
PKMN_OFFSET_ASSERT(Unk_179c940_Res, count, 0x2a);
PKMN_OFFSET_ASSERT(Unk_179c940_Res, elementNames, 0x2c);

// What 0x710179c940 looks its elements up in, by name.
class Unk_179c940_Finder {
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
    virtual void* vf12(const char* name, bool recursive);
};

class Unk_24931a0 {
public:
    // An element: a list node that points at it.
    struct Element {
        Unk_179cc10_ListNode link;
        void* target;
    };

    Unk_24931a0();
    Unk_24931a0(const Unk_179c940_Res* res, Unk_179c940_Finder* finder);
    virtual ~Unk_24931a0();

    void Unk_179ca10(void* target);

    static Unk_24931a0* FromLink(Unk_179cc10_ListNode* node) {
        return reinterpret_cast<Unk_24931a0*>(reinterpret_cast<u8*>(node) - 8);
    }

    // Names are compared up to 32 characters.
    static bool EqualsName(const char* a, const char* b) {
        for (int i = 0; i < 32; i++) {
            if (a[i] != b[i]) {
                return false;
            }
            if (a[i] == '\0') {
                return true;
            }
        }
        return true;
    }

    Unk_179cc10_ListNode link;
    Unk_179cc10_List elements;
    const char* name;
    // Set: a list that holds it doesn't destroy it (0x710179cb50).
    bool field_30;
};
PKMN_OFFSET_ASSERT(Unk_24931a0, link, 0x8);
PKMN_OFFSET_ASSERT(Unk_24931a0, elements, 0x18);
PKMN_OFFSET_ASSERT(Unk_24931a0, name, 0x28);
PKMN_OFFSET_ASSERT(Unk_24931a0, field_30, 0x30);
PKMN_SIZE_ASSERT(Unk_24931a0, 0x38);
PKMN_SIZE_ASSERT(Unk_24931a0::Element, 0x18);
