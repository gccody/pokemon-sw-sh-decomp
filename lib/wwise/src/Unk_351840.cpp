// Scope: common
// The node class with two sets of children (Unk_237ff98.h): its construction
// and destruction, its creation and its virtual functions. With it come the
// functions of its base, Unk_NodeParent<Unk_2382098>. Placeholder names.
#include <math.h>
#include "Unk_237ff98.h"
#include "Unk_NodeParentImpl.h"
#include "Unk_3358b0.h"
#include "bank_read.h"

void Unk_349950();
void Unk_3c58d0(u32 id, u32 arg1, f32 arg2);

// 0x7100351840
Unk_237ff98::Unk_237ff98(u32 id)
    : Unk_NodeActiveParent<Unk_NodeParent<Unk_2382098>>(id), field_b0(nullptr), field_b8(), field_c8(),
      field_d0(-96.3f) {
    field_160 = 0xffffffff;
    field_164_0 = 0;
    field_164_3 = 0;
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
        Unk_35c6b0_get(reinterpret_cast<Unk_35c6b0*>(&(*it).field_8));
    field_100.Term();
    for (auto it = field_128.Begin(); it != field_128.End(); ++it)
        Unk_35c6b0_get(reinterpret_cast<Unk_35c6b0*>(&(*it).field_8));
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
        Unk_351b20_Tell(1.0f);
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
        Unk_3c58d0(field_10, a2, a1);
}

// 0x7100352da0
f32 Unk_237ff98::Unk_352da0(u32 a1) {
    Unk_237ff98_List* list;
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
        sum += (*it).field_8.field_18;
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
        Unk_2382098_50** found = field_58->Exists(key.field_0);
        if (found != nullptr) {
            Unk_PropValue16* other = (*found)->field_18.FindProp(prop);
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
    if (field_c8.field_4.field_0_0 != 0)
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

// NON_MATCHING: after the first of two property lookups this keeps the pointer to the values
// for the second (GVN's scalar PRE through the PHI of the count); the original computes it again
// 0x7100353010
f32 Unk_237ff98::Unk_353010(Unk_NodeKey key, f32* out) {
    f32 value = 0.0f;
    Unk_352bd0(&value, 5, &key);
    *out = 0.0f;
    Unk_352bd0(out, 0x18, &key);
    if (field_50 != nullptr) {
        Unk_PropValue16* own = field_50->field_18.FindProp(5);
        if (own != nullptr)
            value += own->field_0;
        own = field_50->field_18.FindProp(0x18);
        if (own != nullptr)
            *out += own->field_0;
    }
    if (field_58 != nullptr) {
        Unk_2382098_50** found = field_58->Exists(key.field_0);
        if (found != nullptr) {
            Unk_PropValue16* other = (*found)->field_18.FindProp(5);
            if (other != nullptr)
                value += other->field_0;
            other = (*found)->field_18.FindProp(0x18);
            if (other != nullptr)
                *out += other->field_0;
        }
    }
    value += Unk_352da0(5);
    Unk_237ff98* parent = static_cast<Unk_237ff98*>(field_80);
    if (parent != nullptr && !parent->Unk_3536a0()) {
        f32 above;
        f32 result = static_cast<Unk_237ff98*>(field_80)->Unk_353010(key, &above);
        *out += result + above;
    }
    return value;
}

void Unk_377930(void* self, Unk_NodeTarget* target, void* a2, void* a3);
extern void* Unk_24bbc18;

// 0x7100353560
void Unk_237ff98::vf41(void* a1, void* a2, bool a3) {
    if (field_38 != nullptr && field_38->field_20) {
        Unk_NodeTarget target;
        target.field_0 = this;
        target.field_8 = this;
        target.field_10 = 2;
        target.field_14 = 2;
        Unk_377930(Unk_24bbc18, &target, a1, a2);
    }
    Unk_237ff98* parent = static_cast<Unk_237ff98*>(field_80);
    if (parent != nullptr) {
        if (a3 && parent->Unk_3536a0())
            return;
        static_cast<Unk_237ff98*>(field_80)->vf41(a1, a2, true);
    }
}

Unk_2382098* Unk_3352a0(void* self, Unk_NodeId* id);
struct Unk_3c57e0_Arg;
void Unk_3c57e0(u32 id, u32 arg1, u32 arg2, Unk_3c57e0_Arg* arg3);

// 0x7100354bd0
void Unk_237ff98::vf31(u32 a1, u32 a2, void* a3, void* a4) {
    Unk_3c57e0(field_10, a1, a2, static_cast<Unk_3c57e0_Arg*>(a3));
}

// 0x7100354cf0
u32 Unk_237ff98::vf10(Unk_2382098* child) {
    Unk_2382098* old = static_cast<Unk_2382098*>(child->field_80);
    if (old != nullptr) {
        if (old == this) {
            child->vf3();
            return 1;
        }
        old->vf12(child);
    }
    u32 result = p_vf1(child);
    if (result == 1) {
        Unk_NodeA** slot =
            Unk_34c330(!child->field_9c_17 ? &children : &field_b8, child->field_10);
        if (slot != nullptr) {
            *slot = child;
            child->vf8(this);
            vf2();
        } else {
            result = 2;
        }
    }
    child->vf3();
    return result;
}

// 0x7100354de0
u32 Unk_237ff98::vf11(Unk_NodeId id) {
    if (id.field_0 == 0)
        return 0xe;
    Unk_2382098* child = Unk_3352a0(Unk_24bbbb8, &id);
    if (child == nullptr)
        return 0xf;
    return vf10(child);
}

void Unk_3c5b10(u32 a1);

// Slots 73 to 76, with their copies for the vtable at 0x18: the base's
// function, and a notification when it changed whether the node mixes.
// 0x7100354430 (_ZN11Unk_237ff985b_vf6EjPvb)
// 0x7100354610 (_ZThn24_N11Unk_237ff985b_vf6EjPvb)
void Unk_237ff98::b_vf6(u32 a1, void* a2, bool a3) {
    bool before = Unk_3536a0();
    Unk_NodeB::b_vf6(a1, a2, a3);
    if (before != Unk_3536a0() && field_70 != nullptr)
        Unk_3c5b10(1);
}

// 0x7100354620 (_ZN11Unk_237ff986b_vf12Ejb)
// 0x71003547f0 (_ZThn24_N11Unk_237ff986b_vf12Ejb)
void* Unk_237ff98::b_vf12(u32 a1, bool a2) {
    bool before = Unk_3536a0();
    void* result = Unk_NodeB::b_vf12(a1, a2);
    if (before != Unk_3536a0() && field_70 != nullptr)
        Unk_3c5b10(1);
    return result;
}

// 0x7100354800 (_ZN11Unk_237ff986b_vf11Ejb)
// 0x71003549d0 (_ZThn24_N11Unk_237ff986b_vf11Ejb)
void Unk_237ff98::b_vf11(u32 a1, bool a2) {
    bool before = Unk_3536a0();
    Unk_NodeB::b_vf11(a1, a2);
    if (before != Unk_3536a0() && field_70 != nullptr)
        Unk_3c5b10(1);
}

// 0x71003549e0 (_ZN11Unk_237ff986b_vf13EjPvS0_)
// 0x7100354bc0 (_ZThn24_N11Unk_237ff986b_vf13EjPvS0_)
u32 Unk_237ff98::b_vf13(u32 a1, void* a2, void* a3) {
    bool before = Unk_3536a0();
    u32 result = Unk_NodeB::b_vf13(a1, a2, a3);
    if (before != Unk_3536a0() && field_70 != nullptr)
        Unk_3c5b10(1);
    return result;
}

struct Unk_387770;
void Unk_388010(Unk_2382098* self, bool a1);
void Unk_387770_update(Unk_387770* self);
bool Unk_387370(Unk_2382098* self, bool a1);
void Unk_3874a0(Unk_2382098* self, bool a1);
void Unk_3557c0(void* self);
void Unk_3c5a70(u32 id, u32 bit);
void Unk_3c5b00_call(u32 id);

// 0x7100355640
void Unk_237ff98::Unk_355640() {
    for (auto it = field_100.Begin(); it != field_100.End(); ++it) {
        if ((*it).field_8.field_18 < -0.01f)
            return;
    }
    for (auto it = field_128.Begin(); it != field_128.End(); ++it) {
        if ((*it).field_8.field_18 < -0.01f)
            return;
    }
}

// 0x7100355a80
void Unk_237ff98::vf36(void* a1) {
    Unk_388010(this, true);
    Unk_387770_update(reinterpret_cast<Unk_387770*>(this));
    if (field_80 != nullptr)
        static_cast<Unk_2382098*>(field_80)->vf36(a1);
    if (field_70 == nullptr || field_70->field_90 == 0) {
        if (field_c8.field_0 != 0 && field_d8.field_24 != 0) {
            u32 result = Unk_355880();
            field_164_0 = 0;
            if (result == 1)
                field_164_0 = 2;
        } else {
            field_164_0 = 0;
        }
        Unk_3557c0(this);
    }
}

// 0x7100355b30
bool Unk_237ff98::vf37(bool a1) {
    bool result = Unk_387370(this, true);
    if (field_80 != nullptr)
        result &= static_cast<Unk_2382098*>(field_80)->vf37(true);
    return result;
}

// 0x7100355b80
void Unk_237ff98::vf38(bool a1) {
    Unk_3874a0(this, true);
    if (field_80 != nullptr)
        static_cast<Unk_2382098*>(field_80)->vf38(true);
}

// Whether `node` is `other` or below it.
// 0x7100355bd0
bool Unk_355bd0(Unk_237ff98* node, Unk_237ff98* other) {
    for (; node != nullptr; node = static_cast<Unk_237ff98*>(node->field_80)) {
        if (node == other)
            return true;
    }
    return false;
}

// 0x7100355c10
void Unk_237ff98::Unk_355c10(Unk_237ff98_Config config) {
    u32 old = *reinterpret_cast<u32*>(&field_c8.field_4);
    if (config.field_0_8 == 1) {
        u32 mask = config.field_0_12 & 0x3ff3f;
        config.field_0_0 = __builtin_popcount(mask);
        config.field_0_8 = 1;
        config.field_0_12 = mask;
    }
    field_c8.field_4 = config;
    if (old != *reinterpret_cast<u32*>(&config))
        Unk_3c5b00_call(field_10);
}

// 0x7100355c80
Unk_2382098* Unk_237ff98::vf33() {
    if (Unk_3536a0())
        return this;
    return Unk_2382098::vf33();
}

// 0x7100355d50
void Unk_237ff98::vf34(u32 a1) {
    Unk_3c5a70(field_10, a1);
}

// NON_MATCHING: register allocation (the list item is in x0 here, x8 in the original, which
// then needs one more instruction for each virtual call)
// 0x7100355690
void Unk_237ff98::Unk_355690(u32 id) {
    for (auto it = field_100.Begin(); it != field_100.End(); ++it) {
        if ((*it).field_0 == id) {
            Unk_355690_End(*it, 0);
            break;
        }
    }
    for (auto it = field_128.Begin(); it != field_128.End(); ++it) {
        if ((*it).field_0 == id) {
            Unk_355690_End(*it, 5);
            break;
        }
    }
}

// 0x71003557c0
void Unk_3557c0(void* self_) {
    Unk_237ff98* self = static_cast<Unk_237ff98*>(self_);
    for (auto it = self->field_d8.Begin(); it != self->field_d8.End(); ++it) {
        Unk_237ff98_Item18& item = *it;
        Unk_237ff98* target = static_cast<Unk_237ff98*>(Unk_3351b0(Unk_24bbbb8, item.field_0, 1));
        if (target != nullptr) {
            switch (self->field_164_0) {
            case 0:
                target->Unk_355510(self->field_10, item.field_c, item.field_10, item.field_14);
                break;
            case 1:
                target->Unk_3552e0(self->field_10, item.field_4, item.field_8, item.field_10,
                                   item.field_14);
                break;
            case 2:
                target->Unk_355690(self->field_10);
                break;
            }
            target->vf3();
        }
    }
}

void Unk_3831c0(Unk_2382098* self, void* a1, u32 a2, u32 a3, f32 a4, u32 a5, u32 a6);
void Unk_383410(Unk_2382098* self, void* a1, u32 a2, u32 a3, f32 a4);

// NON_MATCHING: the copies of the float argument and of a4 are in the other order (the float's
// place in the signature isn't found: last of the first three it gives two registers swapped)
// 0x7100356e60
void Unk_237ff98::vf43(f32 a1, u32 a2, void* a3, u32 a4, u32 a5, u32 a6) {
    void* target = vf68(a2 == 5 ? a3 : nullptr);
    if (target != nullptr)
        Unk_3831c0(this, target, a2, a4, a1, a5, a6);
}

// 0x7100356f00
void Unk_237ff98::vf45(void* a1, u32 a2, u32 a3) {
    if (a1 != nullptr)
        return;
    void* target = vf68(a1);
    if (target != nullptr)
        Unk_383410(this, target, a2, a3, 0.0f);
}

// 0x7100356f80
void Unk_237ff98::vf47(u32 a1, u32 a2) {
    vf46(nullptr, a1, a2);
}

// 0x7100357250
void Unk_237ff98::vf29() {
    if (field_70 == nullptr)
        return;
    for (Iterator it = Begin(); !IsEnd(it); Next(it)) {
        Unk_2382098* child = *it;
        if (child->field_70 != nullptr &&
            (child->field_70->field_90 > 0 || child->field_70->field_94 > 0))
            child->vf29();
    }
}

// 0x7100357310
u32 Unk_237ff98::Unk_357310() {
    Unk_PropValue def;
    def.i = 0;
    return field_90.GetProp(0x1e, def).i;
}

// 0x7100357370
void Unk_237ff98::Unk_357370(f32* value) {
    f32 min = GetProp(0x1f).f;
    f32 max = GetProp(0x20).f;
    f32 v = *value;
    *value = v < min ? min : (v < max ? v : max);
}

// 0x7100357650
void Unk_237ff98::Unk_357650(u32 a1) {
    if (field_160 != a1) {
        field_160 = a1;
        for (u32 i = 0; i < field_b8.field_8; i++)
            static_cast<Unk_237ff98*>(field_b8.field_0[i])->Unk_357650(a1);
        if (field_80 == nullptr)
            Unk_3c5b10(1);
    }
}

bool Unk_3b36d0(Unk_NodeB* self, u32 a1, void* a2);

// 0x7100356720
bool Unk_237ff98::Unk_356720(u32 a1, void* a2) {
    Unk_237ff98* node = this;
    do {
        if (Unk_3b36d0(node->AsNodeB(), a1, a2))
            return true;
        node = static_cast<Unk_237ff98*>(node->field_80);
    } while (node != nullptr);
    return false;
}

// The nodes with field_164_6 set are told 0 when the flag at 0x71024bcab8
// goes up, and their own value when it goes down.
// 0x7100357450
void Unk_357450() {
    if (!Unk_24bcab8) {
        Unk_24bcab8 = true;
        nn::os::LockMutex(&Unk_24bcac0);
        for (u32 i = 0; i < Unk_24bca98.Length(); i++) {
            Unk_237ff98* node = Unk_24bca98.field_0[i];
            Unk_237ff98_Arg25 arg;
            arg.field_8 = true;
            arg.field_0 = node;
            node->vf25(&arg, true, 0.0f);
        }
        if (Unk_24bbc30.field_48 != nullptr)
            Unk_24bbc30.field_48(Unk_24bcab8, Unk_24bbc30.field_50);
        nn::os::UnlockMutex(&Unk_24bcac0);
    }
}

// 0x7100357520
void Unk_357520() {
    if (Unk_24bcab8) {
        Unk_24bcab8 = false;
        nn::os::LockMutex(&Unk_24bcac0);
        for (u32 i = 0; i < Unk_24bca98.Length(); i++)
            Unk_24bca98.field_0[i]->Unk_351b20_Tell(1.0f);
        if (Unk_24bbc30.field_48 != nullptr)
            Unk_24bbc30.field_48(Unk_24bcab8, Unk_24bbc30.field_50);
        nn::os::UnlockMutex(&Unk_24bcac0);
    }
}

void Unk_3c56b0(u32 id);
void Unk_399350(void* self, Unk_2382098* node);
u16 Unk_385e80(Unk_2382098* self, u32 a1, void* a2);
extern void* Unk_24bbbd8;

// NON_MATCHING: the four flags are computed in the other order, and stored before the vtable
// pointer and the owner in the original
// 0x7100356fa0
void* Unk_237ff98::vf68(void* a1) {
    if (a1 != nullptr)
        return Unk_2382098::vf68(a1);
    Unk_399350(Unk_24bbbd8, this);
    if (field_50 == nullptr) {
        u16 a = Unk_385e80(this, 0, nullptr);
        u16 b = Unk_385e80(this, 1, nullptr);
        u16 c = Unk_385e80(this, 2, nullptr);
        u16 d = Unk_385e80(this, 3, nullptr);
        field_50 = new (Unk_237e820) Unk_2382098_50(this, a != 0, b != 0, c != 0, d != 0);
    }
    return field_50;
}

// NON_MATCHING: register allocation (`this` and the pointer to the children swapped)
// 0x71003570c0
void Unk_237ff98::vf48(bool a1) {
    if (Unk_3536a0()) {
        field_164_4 = 1;
        Unk_3c56b0(field_10);
    }
    if (field_70 == nullptr)
        return;
    for (Iterator it = Begin(); !IsEnd(it); Next(it)) {
        Unk_2382098* child = *it;
        if (child->field_70 != nullptr &&
            (child->field_70->field_90 > 0 || child->field_70->field_94 > 0))
            child->vf48(a1);
    }
}

void Unk_382ac0(Unk_2382098* self, void* a1, u32 a2, u32 a3, u32 a4);

// NON_MATCHING: 12 bytes short. The original keeps the new object's pointer in x8 and sets the
// result before the last test; the structure of the returns isn't found
// 0x7100356d50
u32 Unk_237ff98::vf55(u32 a1, bool a2, s32 a3) {
    if (a1 != 0 && field_b0 == nullptr) {
        field_b0 = static_cast<Unk_237ff98_b0*>(Unk_3045e0(Unk_237e820, sizeof(Unk_237ff98_b0)));
        if (field_b0 != nullptr)
            new (field_b0, Unk_Placement()) Unk_237ff98_b0;
        if (field_b0 == nullptr)
            return 2;
    }
    if (field_b0 != nullptr) {
        if (field_b0->field_0 > a3)
            return 1;
        field_b0->field_0 = a3;
        if (field_b0 == nullptr)
            return 1;
        if (field_b0->field_9 != a2 || field_b0->field_4 != a1) {
            field_b0->field_9 = a2;
            field_b0->field_4 = a1;
            Unk_382ac0(this, nullptr, 0, 0, 4);
        }
    }
    if (a1 == 0 && field_b0 != nullptr) {
        Unk_3047c0(Unk_237e820, field_b0);
        field_b0 = nullptr;
    }
    return 1;
}

// 0x7100353f30
void Unk_237ff98::vf25(void* a1, bool a2, f32 a3) {
    if (field_70 == nullptr)
        return;
    for (Iterator it = Begin(); !IsEnd(it); Next(it)) {
        Unk_2382098* child = *it;
        if (IsActive(child)) {
            if (Unk_24bcab8 && field_164_6 && static_cast<Unk_237ff98_Arg25*>(a1)->field_0 == this)
                a3 = 0.0f;
            child->vf25(a1, true, a3);
        }
    }
}

u32 Unk_387fb0(Unk_2382098* self, bool a1);
void Unk_387510(Unk_2382098* self, Unk_NodeArg35* a1, bool a2);

// 0x7100355970
u32 Unk_237ff98::vf35(Unk_NodeArg35* a1, bool a2, bool a3) {
    u32 result = 1;
    if (a2)
        result = Unk_387fb0(this, true);
    if (!a3 && !a1->field_1c) {
        Unk_387510(this, a1, a2);
        a1->field_1c = field_9c_30;
    }
    if (field_80 != nullptr) {
        u32 above = static_cast<Unk_2382098*>(field_80)->vf35(a1, a2, a3);
        if (above != 1) {
            if (above == 0x50) {
                if (result == 1)
                    result = 0x50;
            } else {
                result = above;
            }
        }
    }
    if (field_70 != nullptr && field_70->field_90 == 1) {
        field_164_0 = 1;
        Unk_3557c0(this);
    }
    return result;
}

u32 Unk_383520(Unk_2382098* self, u32 index, u32 id, bool a3, u32 a4);
void Unk_383740(Unk_2382098* self, u32 a1, u32 a2);

// Slot 65: reads the node's effects from a sound bank's data.
// 0x71003565e0
u32 Unk_237ff98::vf65(u8*& data) {
    u32 result = 1;
    u32 count = Unk_ReadBank<u8>(data);
    if (count != 0) {
        u32 bypass = Unk_ReadBank<u8>(data);
        for (u32 i = 0; i < count; i++) {
            u32 index = Unk_ReadBank<u8>(data);
            u32 id = Unk_ReadBank<u32>(data);
            bool shared = Unk_ReadBank<u8>(data) != 0;
            Unk_ReadBank<u8>(data);
            if (id != 0)
                result = Unk_383520(this, index, id, shared, 0);
            if (result != 1)
                break;
        }
        Unk_383740(this, bypass, 0xffffffff);
    }
    if (result == 1) {
        u32 id = Unk_ReadBank<u32>(data);
        u8 flag = Unk_ReadBank<u8>(data);
        result = vf55(id, flag != 0, 0);
    }
    field_98_12 = 0x1f;
    return result;
}

// What starts a change of a value over time.
struct Unk_3bdd90_Params {
    Unk_237ff98_Item28_8* field_0;  // who is told the value
    u64 field_8;
    f32 field_10;  // from
    f32 field_14;  // to
    u32 field_18;
    u32 field_1c;
    bool field_20;
    bool field_21;
    bool field_22;
};
void* Unk_3bdd90(void* self, Unk_3bdd90_Params* params, bool a2, bool a3);

// Starts taking the item's value back to 0: over a2 (with what changes it,
// or a new change), or at once.
// 0x7100355510
void Unk_237ff98::Unk_355510(u32 id, u32 a2, u32 a3, u32 prop) {
    Unk_237ff98_List* list;
    switch (prop) {
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
    for (auto it = list->Begin(); it != list->End(); ++it) {
        if ((*it).field_0 == id) {
            Unk_237ff98_Item28& item = *it;
            void* change = item.field_8.field_10;
            item.field_8.field_1c = true;
            if (change != nullptr) {
                Unk_3be290(Unk_24bbbe8, change, prop, a2, a3, 0, 0.0f);
            } else {
                Unk_237ff98_Item28_8* user = item.User();
                if (a2 != 0 && item.field_8.field_18 != 0.0f) {
                    Unk_3bdd90_Params params;
                    params.field_0 = user;
                    params.field_8 = prop;
                    params.field_10 = item.field_8.field_18;
                    params.field_14 = 0.0f;
                    params.field_18 = a2;
                    params.field_1c = a3;
                    params.field_20 = true;
                    params.field_21 = true;
                    params.field_22 = false;
                    item.field_8.field_10 = Unk_3bdd90(Unk_24bbbe8, &params, true, false);
                } else {
                    user->vf0(prop, 0.0f, true);
                }
            }
            return;
        }
    }
}

struct Unk_35c6f0;
void Unk_35c6f0_update(Unk_35c6f0* self, unsigned long a1);
u32 Unk_3a48c0(Unk_2382e40* self, u32 param);

// Starts taking the value another node asks for towards `target`: over a3
// (with what already changes it, or a new change), or at once.
// NON_MATCHING: 20 bytes short. The original keeps a pointer to the list's free items across the new item's
// allocation; the rest has the same shape
// 0x71003552e0
void Unk_237ff98::Unk_3552e0(u32 id, f32 target, u32 a3, u32 a4, u32 prop) {
    Unk_237ff98_List* list;
    switch (prop) {
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
    Unk_237ff98_Item28_8* item = list->Exists(id);
    if (item == nullptr) {
        item = list->Set(id);
        if (item == nullptr)
            return;
        Unk_35c6f0_update(reinterpret_cast<Unk_35c6f0*>(item), reinterpret_cast<unsigned long>(this));
    }
    if (Unk_3a48c0(&field_150, Unk_1b1d654[prop]) != 1)
        return;
    void* change = item->field_10;
    item->field_1c = false;
    if (change != nullptr) {
        Unk_3be290(Unk_24bbbe8, change, prop, a3, a4, 2, target);
    } else if (a3 != 0 && item->field_18 != target) {
        Unk_3bdd90_Params params;
        params.field_0 = item;
        params.field_8 = prop;
        params.field_10 = item->field_18;
        params.field_14 = target;
        params.field_18 = a3;
        params.field_1c = a4;
        params.field_20 = true;
        params.field_21 = true;
        params.field_22 = false;
        item->field_10 = Unk_3bdd90(Unk_24bbbe8, &params, true, false);
    } else {
        item->vf0(prop, target, true);
    }
}

// NON_MATCHING: register allocation only (the ID and the index's object in each other's
// register)
// 0x7100356a90
void Unk_237ff98::Unk_356a90(Unk_237ff98_Ref* out) {
    out->Set(nullptr);
    out->field_8 = 0;
    if (field_b0 != nullptr && field_b0->field_4 != 0) {
        u32 id = field_b0->field_4;
        out->Set(field_b0->field_9 ? Unk_237ff98_Find<0x230>(id) : Unk_237ff98_Find<0x268>(id));
    }
}
