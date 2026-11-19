// Scope: common
//
// The Pokedex's "bunpu_out" state (vtable 0x7102448ae8): its type and
// thunks are tools/vtables.py's.
#include "contents/pokedex/Unk_dex.h"

// The Pokedex's habitat view (vtable 0x7102448660: "ViewBunpu").
class Unk_2448660 : public Unk_23f4660 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23f4660::Unk_GetType());
        return &type;
    }
};

// The town map (vtable 0x710243c120: "TownmapView").
class Unk_243c120 : public Unk_23f4660 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23f4660::Unk_GetType());
        return &type;
    }

    void Unk_1449290(bool value);
};

void Unk_15318d0_call(void* self);
void Unk_eb6230(void* view, u32 arg);

class Unk_2448ae8 : public Unk_23f43c8 {
public:
    const Unk_239a418_Type* vf_type() override;
    void vf7() override;
    u32 vf8() override;
    void vf9() override;

    Unk_2448660* field_78;
    Unk_243c120* field_80;
};

// 0x71015340f0
void Unk_2448ae8::vf7() {
    field_70 = Unk_d0c0_String("bunpu_out");
    field_78 = Unk_StateView<Unk_2448660>(this, "ViewBunpu");
    UNK_CHECK(field_78 != nullptr);
    Unk_15318d0_call(field_78);
    field_80 = Unk_StateView<Unk_243c120>(this, "TownmapView");
    UNK_CHECK(field_80 != nullptr);
    field_80->Unk_1449290(true);
    Unk_eb6230(field_80, 3);
}
