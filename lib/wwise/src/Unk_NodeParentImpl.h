#pragma once
// The member functions of Unk_NodeParent<T> and Unk_NodeActiveParent<P>, and
// the inline virtual functions
// of the node classes below it (Unk_237c170.h). The executable has one copy of
// each, with the first class of an instantiation: a file includes this when
// it is that class's. Placeholder names.
#include "Unk_237c170.h"

Unk_NodeA** Unk_34c330(Unk_NodeChildren* self, u32 key);
Unk_2382098* Unk_3351b0(void* self, u32 id, u32 type);
void Unk_3b3a10(Unk_NodeB* self, bool a1);
bool Unk_382c40(Unk_2382098* self, void* a1);
extern u8* Unk_24bbbb8;

// Slot 11: adds the child with this ID.
inline u32 Unk_2382098::vf11(u32 id) {
    if (id == 0)
        return 0xe;
    Unk_2382098* child = Unk_3351b0(Unk_24bbbb8, id, 0);
    if (child == nullptr)
        return 0xf;
    return vf10(child);
}

inline bool Unk_2381d78::vf61(u32 a1) {
    return HasProperty(a1, false);
}

inline bool Unk_2381d78::vf62(u32 a1) {
    return HasProperty(a1, true);
}

inline void Unk_2381d78::vf73(u32 a1) {
    field_b1_0 = a1;
    if (field_b1_0 == 3)
        field_b0_3 = 1;
    else
        field_b0_3 = field_b0_0;
}

// Slot 10: adds a child.
template <class T>
u32 Unk_NodeParent<T>::vf10(Unk_2382098* child) {
    u32 result = p_vf1(child);
    if (result == 1) {
        Unk_NodeA** slot = Unk_34c330(&children, child->field_10);
        if (slot != nullptr) {
            *slot = child;
            child->vf7(this);
            this->vf2();
        } else {
            result = 2;
        }
    }
    child->vf3();
    return result;
}

template <class T>
void Unk_NodeParent<T>::vf15(u32* max, Unk_NodeEntry15* entries, u32* count, u32 depth) {
    for (Unk_NodeA** it = children.field_0; it != children.field_0 + children.field_8; ++it) {
        if (*count < *max) {
            entries[*count].field_0 = (*it)->field_10;
            entries[*count].field_4 = static_cast<Unk_2382098*>(*it)->field_78->field_10;
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

template <class T>
void Unk_NodeParent<T>::vf16(void* a1, void* a2, void* a3, bool a4, void* a5, u32 a6, u32 a7) {
    for (Unk_NodeA** it = children.field_0; it != children.field_0 + children.field_8; ++it)
        (*it)->vf16(a1, a2, a3, a4, a5, a6, a7);
}

template <class P>
void Unk_NodeActiveParent<P>::vf19(Unk_NodeArg19* a1) {
    if (this->field_70 == nullptr)
        return;
    if (this->field_70->field_90 > 0 || this->field_70->field_94 > 0) {
        for (u32 i = this->children.field_8; i != 0; i--) {
            Unk_2382098* child = static_cast<Unk_2382098*>(this->children.field_0[i - 1]);
            if (a1->field_20 && child->field_80 != nullptr)
                continue;
            child->vf19(a1);
        }
    }
}

template <class P>
inline void Unk_NodeActiveParent<P>::Vf20(Unk_NodeArg19* a1) {
    if (a1->field_23 && a1->field_21) {
        Unk_NodeB* base = this;
        if (a1->field_0 == 1)
            Unk_3b3a10(base, true);
        else if (a1->field_0 == 0 || a1->field_0 == 2)
            Unk_3b3a10(base, false);
    }
    for (u32 i = this->children.field_8; i != 0; i--) {
        Unk_2382098* child = static_cast<Unk_2382098*>(this->children.field_0[i - 1]);
        if (a1->field_20 && child->field_80 != nullptr)
            continue;
        if (Unk_382c40(child, a1->field_30))
            continue;
        child->vf20(a1);
    }
}

template <class P>
void Unk_NodeActiveParent<P>::vf22(void* a1, void* a2, u32 a3) {
    for (Unk_NodeA** it = this->children.field_0; it != this->children.field_0 + this->children.field_8; ++it)
        (*it)->vf22(a1, a2, a3);
}

template <class P>
void Unk_NodeActiveParent<P>::vf23(Unk_NodeArg23* a1) {
    if (this->field_70 == nullptr)
        return;
    for (Unk_NodeA** it = this->children.field_0; it != this->children.field_0 + this->children.field_8; ++it) {
        bool flag = a1->field_38;
        Unk_2382098* child = static_cast<Unk_2382098*>(*it);
        if (flag && child->field_80 != nullptr)
            continue;
        if (child->field_70 != nullptr && child->field_70->field_90 > 0) {
            if (!child->vf61(a1->field_0))
                (*it)->vf23(a1);
        }
    }
}

template <class P>
void Unk_NodeActiveParent<P>::vf25(void* a1, bool a2, f32 a3) {
    if (this->field_70 == nullptr)
        return;
    for (Unk_NodeA** it = this->children.field_0; it != this->children.field_0 + this->children.field_8; ++it) {
        Unk_2382098* child = static_cast<Unk_2382098*>(*it);
        if (a2 && child->field_80 != nullptr)
            continue;
        if (child->field_70 != nullptr && child->field_70->field_90 > 0)
            child->vf25(a1, a2, a3);
    }
}

template <class P>
void Unk_NodeActiveParent<P>::vf26(f32 a1, void* a2, void* a3, bool a4) {
    if (this->field_70 == nullptr)
        return;
    for (Unk_NodeA** it = this->children.field_0; it != this->children.field_0 + this->children.field_8; ++it) {
        Unk_2382098* child = static_cast<Unk_2382098*>(*it);
        if (Unk_2382098::IsActive(child))
            child->vf26(a1, a2, a3, a4);
    }
}

template <class P>
void Unk_NodeActiveParent<P>::vf27(f32 a1, u32 a2, void* a3, void* a4) {
    if (this->field_70 == nullptr)
        return;
    for (Unk_NodeA** it = this->children.field_0; it != this->children.field_0 + this->children.field_8; ++it) {
        Unk_2382098* child = static_cast<Unk_2382098*>(*it);
        if (child->field_98_1 == 0 && Unk_2382098::IsActive(child))
            child->vf27(a1, a2, a3, a4);
    }
}

template <class P>
void Unk_NodeActiveParent<P>::vf29() {
    if (this->field_70 == nullptr)
        return;
    for (Unk_NodeA** it = this->children.field_0; it != this->children.field_0 + this->children.field_8; ++it) {
        Unk_2382098* child = static_cast<Unk_2382098*>(*it);
        if (child->field_70 != nullptr && child->field_70->field_90 > 0)
            child->vf29();
    }
}

template <class P>
void Unk_NodeActiveParent<P>::vf30(void* a1, void* a2, void* a3) {
    if (this->field_70 == nullptr)
        return;
    for (Unk_NodeA** it = this->children.field_0; it != this->children.field_0 + this->children.field_8; ++it) {
        Unk_2382098* child = static_cast<Unk_2382098*>(*it);
        if (Unk_2382098::IsActive(child))
            child->vf30(a1, a2, a3);
    }
}

template <class P>
void Unk_NodeActiveParent<P>::vf31(u32 a1, u32 a2, void* a3, void* a4) {
    if (this->field_70 == nullptr)
        return;
    for (Unk_NodeA** it = this->children.field_0; it != this->children.field_0 + this->children.field_8; ++it) {
        Unk_2382098* child = static_cast<Unk_2382098*>(*it);
        if (Unk_2382098::IsActive(child) && child->field_98_12 == 0)
            child->vf31(a1, a2, a3, a4);
    }
}

template <class P>
void Unk_NodeActiveParent<P>::vf34(u32 a1) {
    if (this->field_70 == nullptr)
        return;
    for (Unk_NodeA** it = this->children.field_0; it != this->children.field_0 + this->children.field_8; ++it) {
        Unk_2382098* child = static_cast<Unk_2382098*>(*it);
        if (Unk_2382098::IsActive(child))
            child->vf34(a1);
    }
}

template <class P>
u32 Unk_NodeActiveParent<P>::vf39() {
    for (Unk_NodeA** it = this->children.field_0; it != this->children.field_0 + this->children.field_8; ++it) {
        u32 result = (*it)->vf39();
        if (result != 1) {
            for (Unk_NodeA** undo = this->children.field_0; undo != it; ++undo)
                (*undo)->vf40();
            return result;
        }
    }
    return 1;
}

template <class P>
void Unk_NodeActiveParent<P>::vf40() {
    for (Unk_NodeA** it = this->children.field_0; it != this->children.field_0 + this->children.field_8; ++it)
        (*it)->vf40();
}

template <class P>
void Unk_NodeActiveParent<P>::vf48(bool a1) {
    if (this->field_70 == nullptr)
        return;
    for (Unk_NodeA** it = this->children.field_0; it != this->children.field_0 + this->children.field_8; ++it) {
        Unk_2382098* child = static_cast<Unk_2382098*>(*it);
        if (Unk_2382098::IsActive(child))
            child->vf48(a1);
    }
}
