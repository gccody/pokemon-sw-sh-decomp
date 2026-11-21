// Scope: common
// The node class with two sets of children (Unk_237ff98.h): its construction
// and destruction, its creation and its virtual functions. With it come the
// functions of its base, Unk_NodeParent<Unk_2382098>. Placeholder names.
#include <math.h>
#include "Unk_237ff98.h"
#include "Unk_NodeParentImpl.h"

void Unk_349950();
void Unk_3c58d0(u32 id);

// 0x7100351840
Unk_237ff98::Unk_237ff98(u32 id)
    : Unk_NodeActiveParent<Unk_NodeParent<Unk_2382098>>(id), field_b0(nullptr), field_b8(), field_c8(0),
      field_d0(-96.3f) {
    field_160 = 0xffffffff;
    field_164_0 = 0;
    field_164_4 = 1;
    field_164_5 = 1;
    field_164_6 = 0;
}

// The functions of the base's base (the children) that are in its vtables:
// 0x71003576d0 (_ZN14Unk_NodeParentI11Unk_2382098E4vf10EPS0_)
// The base's functions that this class has (the others it overrides):
// 0x710034d870 (_ZN14Unk_NodeParentI11Unk_2382098E4vf15EPjP15Unk_NodeEntry15S2_j)
// 0x710034d970 (_ZN14Unk_NodeParentI11Unk_2382098E4vf16EPvS2_S2_bS2_jj)
// 0x710034da30 (_ZN20Unk_NodeActiveParentI14Unk_NodeParentI11Unk_2382098EE4vf26EfPvS4_b)
// 0x710034dae0 (_ZN20Unk_NodeActiveParentI14Unk_NodeParentI11Unk_2382098EE4vf39Ev)
// 0x710034db80 (_ZN20Unk_NodeActiveParentI14Unk_NodeParentI11Unk_2382098EE4vf40Ev)
// Its destructor, with a trap for the deleting one (the class is abstract),
// and their copies for the vtable at 0x18:
// 0x7100357960 (_ZN14Unk_NodeParentI11Unk_2382098ED2Ev)
// 0x71003579d0 (_ZN14Unk_NodeParentI11Unk_2382098ED0Ev)
// 0x71003579e0 (_ZThn24_N14Unk_NodeParentI11Unk_2382098ED1Ev)
// 0x7100357a50 (_ZThn24_N14Unk_NodeParentI11Unk_2382098ED0Ev)
// This class's inline virtual functions:
// 0x710034dc10 (_ZN11Unk_237ff985p_vf0Ev)
// The ends of its lists:
// 0x7100351c80 (_ZN9Unk_List2I18Unk_237ff98_Item28E4TermEv)
// 0x7100351d90 (_ZN9Unk_List2I18Unk_237ff98_Item18E4TermEv)

// The destructor, its copies for the vtable at 0x18, and the deleting one:
// 0x71003518d0 (_ZN11Unk_237ff98D2Ev)
// 0x7100351ea0 (_ZThn24_N11Unk_237ff98D1Ev)
// 0x7100351eb0 (_ZN11Unk_237ff98D0Ev)
// 0x7100351ee0 (_ZThn24_N11Unk_237ff98D0Ev)
Unk_237ff98::~Unk_237ff98() {
    Unk_351b20();
    for (auto it = field_100.Begin(); it != field_100.End(); ++it)
        Unk_35c6b0_get(reinterpret_cast<Unk_35c6b0*>((*it).field_8));
    field_100.Term();
    for (auto it = field_128.Begin(); it != field_128.End(); ++it)
        Unk_35c6b0_get(reinterpret_cast<Unk_35c6b0*>((*it).field_8));
    field_128.Term();
    field_d8.Term();

    nn::os::LockMutex(&Unk_24bbc90);
    for (auto it = Unk_24bcaa8.Begin(); it != Unk_24bcaa8.End(); ++it) {
        if (*it == this) {
            Unk_24bcaa8.Erase(it);
            if (Unk_24bcaa8.Length() == 0) {
                Unk_24bcaa8.Term();
                Unk_24bcab9 = false;
                Unk_349950();
            }
            break;
        }
    }
    nn::os::UnlockMutex(&Unk_24bbc90);

    field_b8.Term();
    if (field_b0 != nullptr)
        Unk_3047c0(Unk_237e820, field_b0);
}

// 0x7100351b20
void Unk_237ff98::Unk_351b20() {
    nn::os::LockMutex(&Unk_24bcac0);
    if (field_164_6) {
        Unk_24bca98.RemoveSwap(this);
        field_164_6 = 0;
        Unk_237ff98_Arg25 arg;
        arg.field_8 = true;
        arg.field_0 = this;
        f32 value = 1.0f;
        if (field_50 != nullptr) {
            Unk_2382098_50_Value* prop = field_50->field_18.FindProp(0xb);
            if (prop != nullptr)
                value = prop->field_0;
        }
        vf25(&arg, true, value);
        if (Unk_24bca98.Length() == 0)
            Unk_24bca98.Term();
    }
    nn::os::UnlockMutex(&Unk_24bcac0);
}

struct Unk_3476d0_Obj;

// 0x7100351f10
Unk_3476d0_Obj* Unk_351f10(u32 id) {
    Unk_237ff98* node = new (Unk_237e820) Unk_237ff98(id);
    if (node != nullptr)
        node->Register();
    return reinterpret_cast<Unk_3476d0_Obj*>(node);
}

// 0x7100352010
void Unk_237ff98::vf19(Unk_NodeArg19* a1) {
    if (field_70 == nullptr)
        return;
    if (field_70->field_90 > 0 || field_70->field_94 > 0) {
        a1->field_20 = true;
        for (u32 i = children.field_8; i > 0;) {
            --i;
            static_cast<Unk_2382098*>(children.field_0[i])->vf19(a1);
            if (i > children.field_8)
                i = children.field_8;
        }
        for (u32 i = field_b8.field_8; i > 0;) {
            --i;
            static_cast<Unk_2382098*>(field_b8.field_0[i])->vf19(a1);
            if (i > field_b8.field_8)
                i = field_b8.field_8;
        }
    }
}

// 0x71003520d0
void Unk_237ff98::vf20(Unk_NodeArg19* a1) {
    if (a1->field_23 && a1->field_21) {
        Unk_NodeB* base = this;
        if (a1->field_0 == 1)
            Unk_3b3a10(base, true);
        else if (a1->field_0 == 0 || a1->field_0 == 2)
            Unk_3b3a10(base, false);
    }
    a1->field_20 = true;
    for (u32 i = children.field_8; i > 0;) {
        --i;
        Unk_2382098* child = static_cast<Unk_2382098*>(children.field_0[i]);
        if (!Unk_382c40(child, a1->field_30))
            child->vf21(a1);
        if (i > children.field_8)
            i = children.field_8;
    }
    for (u32 i = field_b8.field_8; i > 0;) {
        --i;
        Unk_2382098* child = static_cast<Unk_2382098*>(field_b8.field_0[i]);
        if (!Unk_382c40(child, a1->field_30))
            child->vf21(a1);
        if (i > field_b8.field_8)
            i = field_b8.field_8;
    }
}

// NON_MATCHING: the original loads the current array's length through the array pointer each
// time (as slot 30 does); this keeps a second pointer to it across the loop
// 0x7100352670
void Unk_237ff98::vf22(void* a1, void* a2, u32 a3) {
    for (Iterator it = Begin(); !IsEnd(it); Next(it))
        (*it)->vf22(a1, a2, a3);
}

// 0x7100352720
void Unk_237ff98::vf30(void* a1, void* a2, void* a3) {
    if (field_70 == nullptr)
        return;
    for (Iterator it = Begin(); !IsEnd(it); Next(it)) {
        Unk_2382098* child = *it;
        if (IsActive(child))
            child->vf30(a1, a2, a3);
    }
}

// 0x7100352800
void Unk_237ff98::vf27(f32 a1, u32 a2, void* a3, void* a4) {
    if (field_80 != nullptr)
        Unk_3c58d0(field_10);
}

// NON_MATCHING: the operands of the sum's fadd are the other way round (the item's value first)
// 0x7100352da0
f32 Unk_237ff98::Unk_352da0(u32 a1) {
    Unk_List2<Unk_237ff98_Item28>* list;
    switch (a1) {
    case 0:
        list = &field_100;
        break;
    case 5:
        list = &field_128;
        break;
    default:
        list = nullptr;
        break;
    }
    f32 sum = 0.0f;
    for (auto it = list->Begin(); it != list->End(); ++it)
        sum += (*it).field_20;
    return fmaxf(sum, field_d0);
}
