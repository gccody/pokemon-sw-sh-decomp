// Scope: common
// Small virtual functions of a library class (tools/leafgen.py members): placeholder
// member names vf<slot>, placeholder structs. The class's name is its RTTI's.
#include <types.h>

struct Unk_3dc850_70 {
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
    virtual void vf14();
    virtual void vf15();
    virtual void vf16();
    virtual void vf17();
    virtual void vf18();
    virtual void vf19();
    virtual void vf20();
    virtual void vf21();
    virtual void vf22();
    virtual void vf23();
    virtual void vf24();
    virtual void vf25();
    virtual void vf26(u16);
};

struct Unk_3dc850 {
    u8 _0[0x70];
    Unk_3dc850_70* field_70;
    u8 _78[0xaa];
    u16 field_122;
};
PKMN_OFFSET_ASSERT(Unk_3dc850, field_70, 0x70);
PKMN_OFFSET_ASSERT(Unk_3dc850, field_122, 0x122);

struct Unk_3dbf10 {
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
    virtual void vf14();
    virtual void vf15();
    virtual void vf16();
    virtual void vf17();
    virtual void vf18();
    virtual void vf19();
    virtual void vf20();
    virtual void vf21();
    virtual void vf22();
    virtual void vf23();
    virtual void vf24();
    virtual void vf25();
    virtual void vf26();
    virtual void vf27();
    virtual void vf28();
    virtual void vf29();
    virtual void vf30(u32);
};

struct Unk_3dc870 {
    u8 _0[0x94];
    u32 field_94;
};
PKMN_OFFSET_ASSERT(Unk_3dc870, field_94, 0x94);

class Unk_2384a98 {
public:
    void vf15();
    void vf29();
    u32 vf31();
};

// 0x71003dbf10
void Unk_2384a98::vf29() {
    Unk_3dbf10* self = reinterpret_cast<Unk_3dbf10*>(this);
    self->vf30(0);
    self->vf30(1);
    self->vf30(2);
    self->vf30(3);
}

// 0x71003dc850
void Unk_2384a98::vf15() {
    const Unk_3dc850* self = reinterpret_cast<const Unk_3dc850*>(this);
    self->field_70->vf26(self->field_122);
}

// 0x71003dc870
u32 Unk_2384a98::vf31() {
    const Unk_3dc870* self = reinterpret_cast<const Unk_3dc870*>(this);
    return self->field_94;
}
