// Scope: common
// A sound engine node class (vtables at 0x710237cbc8, four of them): its
// destructors, with the copies the vtable at 0x18 reaches, and its creation.
// Placeholder names.
#include <nn/os.h>
#include "Unk_237d540.h"
#include "containers.h"

// The base at 0xf8: an interface of one function, with two fields.
struct Unk_237cf38 {
    Unk_237cf38() : field_100(0), field_108(0) {}
    virtual u32 vf83(u64 a1, bool a2) = 0;  // slot 83 of the node's first vtable

    u64 field_100;
    u32 field_108;
};

// The member at 0x110 (a leaf's type, Unk_35b310.cpp).
struct Unk_35b620 {
    u32 field_0;
    u64 field_8;
    u16 field_10;
    u8 field_12;
};
struct Unk_35b640;
void Unk_35b620_set(Unk_35b620* self);
void Unk_35b640_call(const Unk_35b640* self);

struct Unk_30ed50_Member : Unk_35b620 {
    Unk_30ed50_Member() { Unk_35b620_set(this); }
    ~Unk_30ed50_Member() { Unk_35b640_call(reinterpret_cast<const Unk_35b640*>(this)); }
};

// A buffer from the default pool.
struct Unk_30ed50_Buffer {
    Unk_30ed50_Buffer() : field_0(nullptr) {}

    void Term() {
        if (field_0 != nullptr) {
            Unk_3047c0(Unk_237e820, field_0);
            field_0 = nullptr;
        }
    }

    void* field_0;
};

// 0x140 bytes.
class Unk_237cbc8 : public Unk_237d540, public Unk_237cf38 {
public:
    explicit Unk_237cbc8(u32 id) : Unk_237d540(id), field_128(true) {}

    // The destructors, and their copies for the vtable at 0x18:
    // 0x710030ed50 (_ZN11Unk_237cbc8D2Ev)
    // 0x710030ee70 (_ZN11Unk_237cbc8D0Ev)
    // 0x710030ede0 (_ZThn24_N11Unk_237cbc8D1Ev)
    // 0x710030ef00 (_ZThn24_N11Unk_237cbc8D0Ev)
    ~Unk_237cbc8() override {
        field_130.Term();
        field_138.Term();
    }

    void vf19(Unk_NodeArg19* a1) override;
    void vf53(u32 a1, u8 a2) override;
    u32 vf71(Unk_NodeArg71* a1) override;
    u32 p_vf1(Unk_2382098* child) override;  // slot 75, 0x710030f2c0: not written
    Unk_310160_T* vf76(void* a1, void* a2, void* a3, bool a4) override;

    // 0x710030f550 (_ZN11Unk_237cbc84vf83Emb)
    // NON_MATCHING: the compiler folds the thunk's adjustment into the member's offset, the
    // original keeps the adjusted pointer
    // 0x710030f5b0 (_ZThn248_N11Unk_237cbc84vf83Emb)
    u32 vf83(u64 a1, bool a2) override;

    Unk_30ed50_Member field_110;
    bool field_128;
    Unk_30ed50_Buffer field_130;
    Unk_30ed50_Buffer field_138;
};
PKMN_SIZE_ASSERT(Unk_237cbc8, 0x140);
PKMN_OFFSET_ASSERT(Unk_237cbc8, field_110, 0x110);

void Unk_310160(Unk_310160_T* self, Unk_237c170* node, void* a2);
u32 Unk_310340(Unk_310160_T* self, void* a1, void* a2, bool a3);

extern nn::os::MutexType Unk_24bbc90;
struct Unk_3476d0_Obj;

// 0x710030ef90
Unk_3476d0_Obj* Unk_30ef90(u32 id) {
    nn::os::LockMutex(&Unk_24bbc90);
    Unk_237cbc8* node = new (Unk_237e820) Unk_237cbc8(id);
    if (node != nullptr)
        node->Register();
    nn::os::UnlockMutex(&Unk_24bbc90);
    return reinterpret_cast<Unk_3476d0_Obj*>(node);
}

// 0x710030f230
void Unk_237cbc8::vf53(u32 a1, u8 a2) {
    if (a1 == 0x12)
        field_110.field_12 = a2;
    else
        Unk_30a6e0(this);
}

// 0x710030f260
void Unk_237cbc8::vf19(Unk_NodeArg19* a1) {
    if (a1->field_0 == 4) {
        if (a1->field_3c_0)
            Unk_3067b0(Unk_24bb988, this, a1->field_8, a1->field_10, a1->field_38_f,
                       a1->field_3c_1);
        else
            Unk_306630(Unk_24bb988, this, a1->field_8, a1->field_10, a1->field_38,
                       a1->field_3c_1);
    } else {
        Unk_30a0c0(this, a1);
    }
}

// 0x710030f3f0
Unk_310160_T* Unk_237cbc8::vf76(void* a1, void* a2, void* a3, bool a4) {
    Unk_310160_T* obj = static_cast<Unk_310160_T*>(Unk_3045e0(Unk_237e820, 0xc8));
    if (obj != nullptr) {
        Unk_310160(obj, this, a1);
        obj->field_48++;
        if (Unk_310340(obj, a2, a3, a4) == 1) {
            Unk_308aa0(obj);
        } else {
            Unk_309380_call(reinterpret_cast<Unk_309380*>(obj));
            Unk_308aa0(obj);
            obj = nullptr;
        }
    }
    return obj;
}

// 0x710030f4b0
u32 Unk_237cbc8::vf71(Unk_NodeArg71* a1) {
    Unk_310160_T* obj = vf76(nullptr, a1->field_10, a1->field_20, a1->field_188_2);
    if (obj == nullptr)
        return 2;
    obj->vf16();
    Unk_309110_Arg arg;
    arg.field_0 = a1->field_18->field_0;
    arg.field_4 = a1->field_18->field_4;
    arg.field_8 = Unk_30ae10(obj);
    Unk_309110(obj, &arg);
    return 1;
}

u32 Unk_35c1b0(Unk_35b620* self);
u32 Unk_382d00(u32 a0);
u32 Unk_382d80(u32 a0);

u32 Unk_237cbc8::vf83(u64, bool a2) {
    if (field_108 != 0 && field_110.field_0 == 1) {
        u32 result = Unk_35c1b0(&field_110);
        if (result != 0) {
            if (a2)
                return Unk_382d00(result);
            Unk_382d80(result);
        }
    }
    return 1;
}
