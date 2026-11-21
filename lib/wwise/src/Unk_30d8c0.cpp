// Scope: common
// A sound engine node class (vtables at 0x710237c860): its destructors, with
// the copies the vtable at 0x18 reaches, its creation and some of its virtual
// functions. Placeholder names.
#include "Unk_237c170.h"
#include "containers.h"

// An item of the node's array: it owns a buffer.
struct Unk_30d8c0_Item {
    ~Unk_30d8c0_Item() {
        if (field_8 != nullptr)
            Unk_3047c0(Unk_237e820, field_8);
    }

    u64 field_0;
    void* field_8;
};

// An array whose items have destructors.
struct Unk_30d8c0_Array {
    Unk_30d8c0_Array() : field_0(nullptr), field_8(0), field_c(0) {}

    void RemoveAll() {
        for (Unk_30d8c0_Item *it = field_0, *end = field_0 + field_8; it != end; ++it)
            it->~Unk_30d8c0_Item();
        field_8 = 0;
    }

    void Term() {
        if (field_0 != nullptr) {
            RemoveAll();
            Unk_3047c0(Unk_237e820, field_0);
            field_0 = nullptr;
            field_c = 0;
        }
    }

    Unk_30d8c0_Item* field_0;
    u32 field_8;
    u32 field_c;
};

// 0x100 bytes.
class Unk_237c860 : public Unk_237c170 {
public:
    explicit Unk_237c860(u32 id) : Unk_237c170(id), field_f8(0) {}

    // The destructors, and their copies for the vtable at 0x18:
    // 0x710030d8c0 (_ZN11Unk_237c860D2Ev)
    // 0x710030da20 (_ZN11Unk_237c860D0Ev)
    // 0x710030d970 (_ZThn24_N11Unk_237c860D1Ev)
    // 0x710030dad0 (_ZThn24_N11Unk_237c860D0Ev)
    ~Unk_237c860() override { field_e8.Term(); }

    u32 vf17() override { return 7; }
    void vf19(Unk_NodeArg19* a1) override;
    void vf20(Unk_NodeArg19* a1) override;
    u32 vf71(Unk_NodeArg71* a1) override;
    Unk_310160_T* vf76(void* a1, void* a2, void* a3, bool a4) override;
    Unk_310160_T* Unk_30e1a0(void* a1, void* a2, void* a3, bool a4);

    // What slots 19 and 20 do with an argument of type 4.
    void Set(Unk_NodeArg19* a1) {
        if (a1->field_3c_0) {
            f32 value = a1->field_38_f;
            if (value >= 0.0f) {
                if (value > 1.0f)
                    value = 1.0f;
            } else {
                value = 0.0f;
            }
            Unk_3067b0(Unk_24bb988, this, a1->field_8, a1->field_10, value, a1->field_3c_1);
        } else {
            Unk_306630(Unk_24bb988, this, a1->field_8, a1->field_10, a1->field_38,
                       a1->field_3c_1);
        }
    }

    Unk_30d8c0_Array field_e8;
    u32 field_f8;
};
PKMN_SIZE_ASSERT(Unk_237c860, 0x100);

struct Unk_3476d0_Obj;

// 0x710030db80
Unk_3476d0_Obj* Unk_30db80(u32 id) {
    Unk_237c860* node = new (Unk_237e820) Unk_237c860(id);
    if (node != nullptr)
        node->Register();
    return reinterpret_cast<Unk_3476d0_Obj*>(node);
}

struct Unk_31bb10;
u32 Unk_31bb10_call(Unk_31bb10* self, u64 a1, u64 a2, bool a3);
void Unk_31b920(Unk_310160_T* self, Unk_237c170* node, void* a2);
void Unk_319d70(Unk_310160_T* self, Unk_237c170* node, void* a2);
u32 Unk_31a080(Unk_310160_T* self, void* a1, void* a2, bool a3);

// 0x710030dfe0
void Unk_237c860::vf19(Unk_NodeArg19* a1) {
    if (a1->field_0 == 4)
        Set(a1);
    else
        Unk_30a0c0(this, a1);
}

// 0x710030e060
void Unk_237c860::vf20(Unk_NodeArg19* a1) {
    if (a1->field_0 == 4)
        Set(a1);
    else
        Unk_30a210(this, a1);
}

// 0x710030e0e0
Unk_310160_T* Unk_237c860::vf76(void* a1, void* a2, void* a3, bool a4) {
    if (field_e8.field_8 == 0)
        return nullptr;
    Unk_310160_T* obj = static_cast<Unk_310160_T*>(Unk_3045e0(Unk_237e820, 0x98));
    if (obj != nullptr) {
        Unk_31b920(obj, this, a1);
        obj->field_48++;
        if (Unk_31bb10_call(reinterpret_cast<Unk_31bb10*>(obj), reinterpret_cast<u64>(a2),
                            reinterpret_cast<u64>(a3), a4) == 1) {
            Unk_308aa0(obj);
        } else {
            Unk_309380_call(reinterpret_cast<Unk_309380*>(obj));
            Unk_308aa0(obj);
            obj = nullptr;
        }
    }
    return obj;
}

// 0x710030e1a0
Unk_310160_T* Unk_237c860::Unk_30e1a0(void* a1, void* a2, void* a3, bool a4) {
    if (field_e8.field_8 == 0)
        return nullptr;
    Unk_310160_T* obj = static_cast<Unk_310160_T*>(Unk_3045e0(Unk_237e820, 0xa0));
    if (obj != nullptr) {
        Unk_319d70(obj, this, a1);
        obj->field_48++;
        if (Unk_31a080(obj, a2, a3, a4) != 1) {
            Unk_309380_call(reinterpret_cast<Unk_309380*>(obj));
            Unk_308aa0(obj);
            obj = nullptr;
        }
    }
    return obj;
}

// 0x710030e380
u32 Unk_237c860::vf71(Unk_NodeArg71* a1) {
    Unk_310160_T* obj =
        Unk_237c860::vf76(nullptr, a1->field_10, a1->field_20, a1->field_188_2);
    if (obj == nullptr)
        return 2;
    Unk_309110_Arg arg;
    arg.field_0 = a1->field_18->field_0;
    arg.field_4 = a1->field_18->field_4;
    arg.field_8 = Unk_30ae10(obj);
    Unk_309110(obj, &arg);
    return 1;
}
