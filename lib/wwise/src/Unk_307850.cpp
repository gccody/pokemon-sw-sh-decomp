// Scope: common
// A sound engine node class (vtables at 0x710237bca0): its destructors, with
// the copies the secondary base's vtable reaches, and its creation.
// Placeholder names.
#include "Unk_237d540.h"
#include "containers.h"

// What the node's list owns.
struct Unk_307850_Obj {
    virtual ~Unk_307850_Obj();
};

struct Unk_307850_Obj2 {
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

struct Unk_3162b0;
void Unk_3162b0_call(Unk_3162b0* self);

// The node's list of objects, 0x40 bytes.
class Unk_237d8a8 {
public:
    Unk_237d8a8()
        : field_8(0), field_10(0), field_14(1), field_18(0), field_1c(50000), field_20(),
          field_30(0), field_38(nullptr) {}
    virtual ~Unk_237d8a8();  // 0x71003161e0
    virtual u32 vf2();

    void RemoveAll() {
        for (Unk_307850_Obj** it = field_20.field_0; it != field_20.field_0 + field_20.field_8;
             ++it) {
            Unk_307850_Obj* p = *it;
            if (p != nullptr) {
                int pool = Unk_237e820;
                p->~Unk_307850_Obj();
                Unk_3047c0(pool, p);
            }
        }
        field_20.field_8 = 0;
    }

    u64 field_8;
    u32 field_10;
    u32 field_14;
    u16 field_18;
    u32 field_1c;
    Unk_Array<Unk_307850_Obj*> field_20;
    u32 field_30;
    Unk_307850_Obj2* field_38;
};
PKMN_SIZE_ASSERT(Unk_237d8a8, 0x40);

void Unk_3820f0(void* self);

// 0x140 bytes.
class Unk_237bca0 : public Unk_237d540 {
public:
    explicit Unk_237bca0(u32 id) : Unk_237d540(id), field_138(false), field_139(1), field_13a(0) {
        field_9c &= ~0x20000;
        field_13c = 0;
    }

    // The destructors, and their copies for the vtable at 0x18:
    // 0x7100307850 (_ZN11Unk_237bca0D2Ev)
    // 0x71003079d0 (_ZN11Unk_237bca0D0Ev)
    // 0x7100307910 (_ZThn24_N11Unk_237bca0D1Ev)
    // 0x7100307aa0 (_ZThn24_N11Unk_237bca0D0Ev)
    ~Unk_237bca0() override {
        field_f8.RemoveAll();
        Unk_3162b0_call(reinterpret_cast<Unk_3162b0*>(&field_f8));
    }

    Unk_237d8a8 field_f8;
    bool field_138;
    u16 field_139 : 8;
    u16 field_13a : 8;
    u16 field_13c;
};
PKMN_SIZE_ASSERT(Unk_237bca0, 0x140);
PKMN_OFFSET_ASSERT(Unk_237bca0, field_f8, 0xf8);

struct Unk_3476d0_Obj;

// NON_MATCHING: two of the constructor's stores (0x128 and 0x138) come out in the other order
// 0x7100307b70
Unk_3476d0_Obj* Unk_307b70(u32 id) {
    Unk_237bca0* node = new (Unk_237e820) Unk_237bca0(id);
    if (node != nullptr)
        Unk_3820f0(node);
    return reinterpret_cast<Unk_3476d0_Obj*>(node);
}
