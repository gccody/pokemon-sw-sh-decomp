// Scope: common
// The node class with children and nothing else (vtables at 0x710237f528, 0xc8
// bytes): its creation, its destructors (the base's, inline) with their copies
// for the vtable at 0x18, and its virtual functions. Placeholder names.
#include "Unk_237c170.h"

class Unk_237f528 : public Unk_237f858 {
public:
    explicit Unk_237f528(u32 id) : Unk_237f858(id) {}

    // The implicit destructors, and their copies for the vtable at 0x18:
    // 0x710034ae50 (_ZN11Unk_237f858D2Ev), the base's
    // 0x710034af30 (_ZN11Unk_237f528D0Ev)
    // 0x710034aec0 (_ZThn24_N11Unk_237f528D1Ev)
    // 0x710034afa0 (_ZThn24_N11Unk_237f528D0Ev)
    // And the base at 0x18's inline slot 7, which this TU has:
    // 0x710034c1f0 (_ZN9Unk_NodeB5b_vf7Ev)

    u32 vf10(Unk_2381d78* child) override;
    u32 vf11(u32 id) override;
    void vf15(u32* max, Unk_NodeEntry15* entries, u32* count, u32 depth) override;
    void vf16(void* a1, void* a2, void* a3, bool a4, void* a5, u32 a6, u32 a7) override;
    u32 vf17() override { return 1; }
    void vf19(Unk_NodeArg19* a1) override;
    void vf20(Unk_NodeArg19* a1) override;  // 0x710034b7c0: Unk_34b7c0 below
    void Vf20(Unk_NodeArg19* a1);
    void vf22(void* a1, void* a2, u32 a3) override;
    void vf23(Unk_NodeArg23* a1) override;
    void vf25(void* a1, bool a2, f32 a3) override;
    void vf26(void* a1, void* a2, f32 a3, bool a4) override;
    void vf27(u32 a1, void* a2, void* a3, f32 a4) override;
    void vf29() override;
    void vf30(void* a1, void* a2, void* a3) override;
    void vf31(u32 a1, u32 a2, void* a3, void* a4) override;
    void vf34(u32 a1) override;
    u32 vf39() override;
    void vf40() override;
    void vf48(bool a1) override;
    bool vf61(u32 a1) override;
    bool vf62(u32 a1) override;

    // What slots 61 and 62 answer for a property: they differ in the answer
    // for the properties this class doesn't know.
    bool HasProperty(u32 a1, bool other) {
        switch (a1) {
        case 39:
        case 40:
        case 41:
        case 42:
        case 47:
        case 48:
        case 49:
        case 50:
        case 51:
        case 52:
        case 53:
        case 54:
            if (field_98_22 || field_98_23 || field_98_24 || field_98_25 || field_98_30 ||
                field_98_31)
                return true;
            return field_78 == nullptr;
        case 38:
        case 55:
        case 56:
            if (field_98_21)
                return true;
            return field_78 == nullptr;
        case 43:
        case 44:
        case 45:
            return field_80 != nullptr;
        default:
            return other;
        }
    }
    void vf73(u32 a1) override;

    // Whether a child takes part in what the node passes on to its children.
    static bool IsActive(Unk_2381d78* child) {
        return child->field_70 != nullptr && child->field_70->field_90 > 0;
    }
    u32 vf75(Unk_2381d78* child) override;
};
PKMN_SIZE_ASSERT(Unk_237f528, 0xc8);

struct Unk_3476d0_Obj;

// 0x710034b010
Unk_3476d0_Obj* Unk_34b010(u32 id) {
    Unk_237f528* node = new (Unk_237e820) Unk_237f528(id);
    if (node != nullptr)
        node->Register();
    return reinterpret_cast<Unk_3476d0_Obj*>(node);
}

// NON_MATCHING: matches when built with clang 5.0.2. LLVM 6's LICM clones the search's item
// address (a GEP that is free in the loop) into the exit block, where the original tests the
// one the loop computed
// 0x710034b0a0
u32 Unk_237f528::vf75(Unk_2381d78* child) {
    if (child->field_78 != nullptr)
        return 0x15;
    if (field_b8.Exists(child->field_10) != nullptr)
        return 5;
    if (field_10 == child->field_10)
        return 0x17;
    return 1;
}

Unk_NodeA** Unk_34c330(Unk_NodeChildren* self, u32 key);
Unk_2381d78* Unk_3351b0(void* self, u32 id, u32 type);
extern void* Unk_24bbbb8;

// 0x710034b270
u32 Unk_237f528::vf10(Unk_2381d78* child) {
    u32 result = vf75(child);
    if (result == 1) {
        Unk_NodeA** slot = Unk_34c330(&field_b8, child->field_10);
        if (slot != nullptr) {
            *slot = child;
            child->vf7(this);
            vf2();
        } else {
            result = 2;
        }
    }
    child->vf3();
    return result;
}

// 0x710034b310
u32 Unk_237f528::vf11(u32 id) {
    if (id == 0)
        return 0xe;
    Unk_2381d78* child = Unk_3351b0(Unk_24bbbb8, id, 0);
    if (child == nullptr)
        return 0xf;
    return vf10(child);
}

// 0x710034bc50
void Unk_237f528::vf29() {
    if (field_70 == nullptr)
        return;
    for (Unk_NodeA** it = field_b8.field_0; it != field_b8.field_0 + field_b8.field_8; ++it) {
        Unk_2381d78* child = static_cast<Unk_2381d78*>(*it);
        if (child->field_70 != nullptr && child->field_70->field_90 > 0)
            child->vf29();
    }
}

// 0x710034bf40
void Unk_237f528::vf40() {
    for (Unk_NodeA** it = field_b8.field_0; it != field_b8.field_0 + field_b8.field_8; ++it)
        (*it)->vf40();
}

// 0x710034b560
void Unk_237f528::vf15(u32* max, Unk_NodeEntry15* entries, u32* count, u32 depth) {
    for (Unk_NodeA** it = field_b8.field_0; it != field_b8.field_0 + field_b8.field_8; ++it) {
        if (*count < *max) {
            entries[*count].field_0 = (*it)->field_10;
            entries[*count].field_4 = static_cast<Unk_2381d78*>(*it)->field_78->field_10;
            entries[*count].field_8 = depth;
        }
        (*count)++;
        if (*count == *max)
            return;
        (*it)->vf15(max, entries, count, depth + 1);
        if (*count == *max)
            return;
    }
}

// 0x710034b660
void Unk_237f528::vf16(void* a1, void* a2, void* a3, bool a4, void* a5, u32 a6, u32 a7) {
    for (Unk_NodeA** it = field_b8.field_0; it != field_b8.field_0 + field_b8.field_8; ++it)
        (*it)->vf16(a1, a2, a3, a4, a5, a6, a7);
}

// 0x710034b720
void Unk_237f528::vf19(Unk_NodeArg19* a1) {
    if (field_70 == nullptr)
        return;
    if (field_70->field_90 > 0 || field_70->field_94 > 0) {
        for (u32 i = field_b8.field_8; i != 0; i--) {
            Unk_2381d78* child = static_cast<Unk_2381d78*>(field_b8.field_0[i - 1]);
            if (a1->field_20 && child->field_80 != nullptr)
                continue;
            child->vf19(a1);
        }
    }
}

void Unk_3b3a10(Unk_NodeB* self, bool a1);
bool Unk_382c40(Unk_2381d78* self, void* a1);

// Slot 20, under the name another file calls it by.
struct Unk_363570_T;
struct Unk_3643f0_Action;

inline void Unk_237f528::Vf20(Unk_NodeArg19* a1) {
    if (a1->field_23 && a1->field_21) {
        Unk_NodeB* base = this;
        if (a1->field_0 == 1)
            Unk_3b3a10(base, true);
        else if (a1->field_0 == 0 || a1->field_0 == 2)
            Unk_3b3a10(base, false);
    }
    for (u32 i = field_b8.field_8; i != 0; i--) {
        Unk_2381d78* child = static_cast<Unk_2381d78*>(field_b8.field_0[i - 1]);
        if (a1->field_20 && child->field_80 != nullptr)
            continue;
        if (Unk_382c40(child, a1->field_30))
            continue;
        child->vf20(a1);
    }
}

// 0x710034b7c0
void Unk_34b7c0(Unk_363570_T* self, Unk_3643f0_Action* action) {
    reinterpret_cast<Unk_237f528*>(self)->Vf20(reinterpret_cast<Unk_NodeArg19*>(action));
}

// 0x710034b890
void Unk_237f528::vf22(void* a1, void* a2, u32 a3) {
    for (Unk_NodeA** it = field_b8.field_0; it != field_b8.field_0 + field_b8.field_8; ++it)
        (*it)->vf22(a1, a2, a3);
}

// 0x710034b910
void Unk_237f528::vf23(Unk_NodeArg23* a1) {
    if (field_70 == nullptr)
        return;
    for (Unk_NodeA** it = field_b8.field_0; it != field_b8.field_0 + field_b8.field_8; ++it) {
        bool flag = a1->field_38;
        Unk_2381d78* child = static_cast<Unk_2381d78*>(*it);
        if (flag && child->field_80 != nullptr)
            continue;
        if (child->field_70 != nullptr && child->field_70->field_90 > 0) {
            if (!child->vf61(a1->field_0))
                (*it)->vf23(a1);
        }
    }
}

// 0x710034b9c0
void Unk_237f528::vf25(void* a1, bool a2, f32 a3) {
    if (field_70 == nullptr)
        return;
    for (Unk_NodeA** it = field_b8.field_0; it != field_b8.field_0 + field_b8.field_8; ++it) {
        Unk_2381d78* child = static_cast<Unk_2381d78*>(*it);
        if (a2 && child->field_80 != nullptr)
            continue;
        if (child->field_70 != nullptr && child->field_70->field_90 > 0)
            child->vf25(a1, a2, a3);
    }
}

// NON_MATCHING: register allocation only (`this` and the first argument swapped)
// 0x710034bac0
void Unk_237f528::vf26(void* a1, void* a2, f32 a3, bool a4) {
    if (field_70 == nullptr)
        return;
    for (Unk_NodeA** it = field_b8.field_0; it != field_b8.field_0 + field_b8.field_8; ++it) {
        Unk_2381d78* child = static_cast<Unk_2381d78*>(*it);
        if (IsActive(child))
            child->vf26(a1, a2, a3, a4);
    }
}

// 0x710034bcc0
void Unk_237f528::vf30(void* a1, void* a2, void* a3) {
    if (field_70 == nullptr)
        return;
    for (Unk_NodeA** it = field_b8.field_0; it != field_b8.field_0 + field_b8.field_8; ++it) {
        Unk_2381d78* child = static_cast<Unk_2381d78*>(*it);
        if (IsActive(child))
            child->vf30(a1, a2, a3);
    }
}

// 0x710034bd60
void Unk_237f528::vf31(u32 a1, u32 a2, void* a3, void* a4) {
    if (field_70 == nullptr)
        return;
    for (Unk_NodeA** it = field_b8.field_0; it != field_b8.field_0 + field_b8.field_8; ++it) {
        Unk_2381d78* child = static_cast<Unk_2381d78*>(*it);
        if (IsActive(child) && child->field_98_12 == 0)
            child->vf31(a1, a2, a3, a4);
    }
}

// 0x710034be20
void Unk_237f528::vf34(u32 a1) {
    if (field_70 == nullptr)
        return;
    for (Unk_NodeA** it = field_b8.field_0; it != field_b8.field_0 + field_b8.field_8; ++it) {
        Unk_2381d78* child = static_cast<Unk_2381d78*>(*it);
        if (IsActive(child))
            child->vf34(a1);
    }
}

// 0x710034bea0
u32 Unk_237f528::vf39() {
    for (Unk_NodeA** it = field_b8.field_0; it != field_b8.field_0 + field_b8.field_8; ++it) {
        u32 result = (*it)->vf39();
        if (result != 1) {
            for (Unk_NodeA** undo = field_b8.field_0; undo != it; ++undo)
                (*undo)->vf40();
            return result;
        }
    }
    return 1;
}

// NON_MATCHING: register allocation only (`this` and the first argument swapped)
// 0x710034bb70
void Unk_237f528::vf27(u32 a1, void* a2, void* a3, f32 a4) {
    if (field_70 == nullptr)
        return;
    for (Unk_NodeA** it = field_b8.field_0; it != field_b8.field_0 + field_b8.field_8; ++it) {
        Unk_2381d78* child = static_cast<Unk_2381d78*>(*it);
        if (child->field_98_1 == 0 && IsActive(child))
            child->vf27(a1, a2, a3, a4);
    }
}

// 0x710034bf90
void Unk_237f528::vf48(bool a1) {
    if (field_70 == nullptr)
        return;
    for (Unk_NodeA** it = field_b8.field_0; it != field_b8.field_0 + field_b8.field_8; ++it) {
        Unk_2381d78* child = static_cast<Unk_2381d78*>(*it);
        if (IsActive(child))
            child->vf48(a1);
    }
}

// 0x710034c1a0
void Unk_237f528::vf73(u32 a1) {
    field_b1_0 = a1;
    if (field_b1_0 == 3)
        field_b0_3 = 1;
    else
        field_b0_3 = field_b0_0;
}

// 0x710034c040
bool Unk_237f528::vf61(u32 a1) {
    return HasProperty(a1, false);
}

// 0x710034c0e0
bool Unk_237f528::vf62(u32 a1) {
    return HasProperty(a1, true);
}
