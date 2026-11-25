// Scope: common
// The mystery gift app's views' common base, Unk_27e15e0, and Unk_23ff3d0
// (src/unsorted/Unk_f67230.h): the base's slots that show the view,
// and Unk_23ff3d0's destructor, layout file and sounds.
#include "unsorted/Unk_f67230.h"

struct Unk_e83430;
u32 Unk_e83430_call(const Unk_e83430* self, void* arg);

// 0x7100f677c0
void Unk_f677c0(Unk_27e15e0* self, u32 state) {
    switch (state) {
        case 0:
            Unk_e806b0(self, true, true);
            break;
        case 1:
            Unk_e806b0(self, true, true);
            break;
        case 2:
            Unk_e806b0(self, true, true);
            break;
        case 3:
            Unk_e806b0(self, true, true);
            break;
    }
}

// 0x7100f677f0
void Unk_f677f0(Unk_27e15e0* self, u32 state) {
    switch (state) {
        case 0:
            Unk_e806b0(self, true, true);
            break;
        case 1:
            Unk_e806b0(self, false, true);
            break;
        case 2:
            Unk_e806b0(self, true, true);
            break;
        case 3:
            Unk_e806b0(self, false, true);
            break;
    }
}

// The object Unk_e7ea90 looks entries up in (what Unk_e7f7e0_get gives), and
// what an entry holds at +0x60.
struct Unk_e7f7e0;
struct Unk_e7ea90_Self;
Unk_e7ea90_Self* Unk_e7f7e0_get(const Unk_e7f7e0* self);

class Unk_e7ea90_Entry : public Unk_239a418 {
public:
    Unk_239a418_Ref<Unk_239a418> field_60;
};
static_assert(__builtin_offsetof(Unk_e7ea90_Entry, field_60) == 0x60, "Unk_e7ea90_Entry::field_60");

Unk_239a418_Ref<Unk_e7ea90_Entry> Unk_e7ea90(Unk_e7ea90_Self* self,
                                             const Unk_5cfaf0_Name& name,
                                             u32 kind);
void Unk_8f19b0(void* self,
                const u64& arg1,
                Unk_239a418_Ref<Unk_239a418> object,
                const u64& arg3,
                u32 kind);

// The object of the entry of kind 10 named `name` (inline: its temporary is
// the function's first stack object).
inline Unk_239a418_Ref<Unk_239a418> Unk_f67840_Find(Unk_23f4660* self,
                                                    const Unk_5cfaf0_Name& name) {
    return Unk_e7ea90(Unk_e7f7e0_get(reinterpret_cast<const Unk_e7f7e0*>(self)), name, 10)
        .m_ptr->field_60;
}

// 0x7100f67840
// NON_MATCHING: register allocation: the original keeps the object's pointer
// and adjusts it to its +0x48 interface twice (for the copy's reference and
// the final release); this adjusts it once and keeps that.
void Unk_f67840(Unk_23f4660* self, u64 arg1, const Unk_5cfaf0_Name& name, u64 arg3) {
    Unk_239a418_Ref<Unk_239a418> object = Unk_f67840_Find(self, name);
    if (object.m_ptr)
        Unk_8f19b0(&self->field_100, arg1, object, arg3, 10);
}

// 0x7100f67aa0 (its D0; its D2 folds into Unk_23ff270's, 0x7100f673c0)
Unk_23ff3d0::~Unk_23ff3d0() {}

// 0x7100f67910
void Unk_f67910(Unk_23ff3d0*, Unk_27e15e0_Layout* layout) {
    Unk_27e15e0_MoveName(layout->field_0,
                         Unk_c46830("bin/appli/mystery/bin/mystery_title_00_lyt.bin"));
    layout->field_60 = false;
}

// 0x7100f67a20
void Unk_23ff3d0::Unk_f67a20() {
    if (field_5e0 != 0) {
        static const u64 hash = 0xda74cfea38becf9f;
        Unk_e83430_call(reinterpret_cast<const Unk_e83430*>(&field_100), const_cast<u64*>(&hash));
        field_5e0 = 0;
    }
}

// 0x7100f67a60
void Unk_23ff3d0::Unk_f67a60() {
    if (field_5e0 != 1) {
        static const u64 hash = 0x5deb53e286553cde;
        Unk_e83430_call(reinterpret_cast<const Unk_e83430*>(&field_100), const_cast<u64*>(&hash));
        field_5e0 = 1;
    }
}
