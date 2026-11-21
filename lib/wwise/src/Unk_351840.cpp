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
    : Unk_NodeActiveParent<Unk_NodeParent<Unk_2382098>>(id), field_b0(nullptr), field_b8(), field_c8(),
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
            Unk_PropValue16* prop = field_50->field_18.FindProp(0xb);
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
    return sum > field_d0 ? sum : field_d0;
}

// 0x7100352df0
u32 Unk_237ff98::Unk_352df0(Unk_352df0_Out* out, Unk_NodeKey* key) {
    out->field_0 = Unk_353010(*key, &out->field_28);
    out->field_2c = Unk_353330(*key, 0x1a);
    out->field_30 = Unk_353330(*key, 0x19);
    if (field_88 != nullptr) {
        Unk_352bd0(&out->field_34[0], 0x13, key);
        Unk_352bd0(&out->field_34[1], 0x14, key);
        Unk_352bd0(&out->field_34[2], 0x15, key);
        Unk_352bd0(&out->field_34[3], 0x16, key);
        Unk_352bd0(&out->field_34[4], 0x3c, key);
        Unk_352bd0(&out->field_34[5], 0x3d, key);
        Unk_352bd0(&out->field_34[6], 0x3e, key);
        Unk_352bd0(&out->field_34[7], 0x3f, key);
        Unk_352bd0(&out->field_34[8], 0x40, key);
        Unk_352bd0(&out->field_34[9], 0x41, key);
        Unk_352bd0(&out->field_34[10], 0x42, key);
        Unk_352bd0(&out->field_34[11], 0x43, key);
        out->field_64[0] = field_88[0];
        out->field_64[1] = field_88[1];
        out->field_64[2] = field_88[2];
        out->field_64[3] = field_88[3];
    }
    out->field_80 = field_9c_18;
    Unk_352bd0(&out->field_74, 0x17, key);
    Unk_352bd0(&out->field_78, 0x44, key);
    Unk_352bd0(&out->field_7c, 0x45, key);
    return 1;
}

// 0x7100353330
f32 Unk_237ff98::Unk_353330(Unk_NodeKey key, u32 prop) {
    f32 value = 0.0f;
    Unk_352bd0(&value, prop, &key);
    if (field_50 != nullptr) {
        Unk_PropValue16* own = field_50->field_18.FindProp(prop);
        if (own != nullptr)
            value += own->field_0;
    }
    if (field_58 != nullptr) {
        Unk_2382098_58_Item* it = field_58->FindEx(key.field_0);
        if (it != field_58->End()) {
            Unk_PropValue16* other = it->field_8->field_18.FindProp(prop);
            if (other != nullptr)
                value += other->field_0;
        }
    }
    Unk_237ff98* parent = static_cast<Unk_237ff98*>(field_80);
    if (parent != nullptr && !parent->Unk_3536a0())
        value += static_cast<Unk_237ff98*>(field_80)->Unk_353330(key, prop);
    return value;
}

// Whether the node does something to the sound that passes through it: what
// goes up the parents stops at such a node.
// 0x71003536a0
bool Unk_237ff98::Unk_3536a0() {
    if (field_60 != nullptr) {
        for (u32 i = 0; i < 4; i++) {
            if (field_60->field_0[i].field_4 != 0)
                return true;
        }
    }
    if (vf17() == 10)
        return true;
    if (field_c8.field_4)
        return true;
    if (field_9c_19 || field_9c_24)
        return true;
    if (field_80 == nullptr)
        return true;
    if (field_98_17 || field_98_18 || field_98_19)
        return true;
    if (field_b0 != nullptr)
        return true;
    if (field_88 != nullptr)
        return true;
    if (field_9c_18)
        return true;
    if (field_38 == nullptr)
        return false;
    return field_38->Has(5) || field_38->Has(43) || field_38->Has(45) || field_38->Has(44);
}

// Slot 78 and its copy for the vtable at 0x30:
// 0x7100353b30 (_ZN11Unk_237ff985c_vf0EjP11Unk_NodeKeyPvff)
// 0x7100353b70 (_ZThn48_N11Unk_237ff985c_vf0EjP11Unk_NodeKeyPvff)
void Unk_237ff98::c_vf0(u32 a1, Unk_NodeKey* a2, void* a3, f32 a4, f32 a5) {
    switch (a1) {
    case 0x23:
        field_164_4 = 1;
        break;
    case 0x22:
    case 0x24:
        field_164_5 = 1;
        break;
    default:
        Unk_NodeC::c_vf0(a1, a2, a3, a4, a5);
        break;
    }
}

// Slot 79 and its copy for the vtable at 0x30:
// 0x7100353bc0 (_ZN11Unk_237ff985c_vf1Ebj)
// 0x7100353be0 (_ZThn48_N11Unk_237ff985c_vf1Ebj)
void Unk_237ff98::c_vf1(bool a1, u32 a2) {
    field_164_4 = 1;
    field_164_5 = 1;
    Unk_NodeC::c_vf1(a1, a2);
}

// Slot 80 and its copy for the vtable at 0x30:
// 0x7100353c00 (_ZN11Unk_237ff985c_vf2Ebj)
// 0x7100353c20 (_ZThn48_N11Unk_237ff985c_vf2Ebj)
void Unk_237ff98::c_vf2(bool a1, u32 a2) {
    field_164_4 = 1;
    field_164_5 = 1;
    Unk_NodeC::c_vf2(a1, a2);
}
