// Scope: common
// A playing context class (vtables at 0x710237c638): some of its virtual
// functions and the thunks its second base at 0x2c0 and its base at 0x18
// reach them through. Placeholder names; the class's small members are
// lib/wwise/class/Unk_237c628.cpp (tools/leafgen.py), named vf<slot>.
//
// The thunks (_ZThn704_..., _ZThn24_...) are clang's, with the function's
// body inlined: so the class here has the original's bases, and vf0, the
// first of its virtual functions defined out of line, makes this TU emit its
// vtable. The members leafgen wrote (vf25, vf29, vf30, vf32) are inline here
// so that their thunks are emitted with them: the strong copies are the
// leafgen ones.
#include <types.h>

// What 0x710038c050 takes (named with these types).
struct Unk_3be850_Ctx;
struct Unk_3bff70_Transition {
    u32 field_0;  // time
    u32 field_4;  // curve
    bool field_8;

    Unk_3bff70_Transition() : field_8(false) {}
};
void Unk_38c050(Unk_3be850_Ctx* ctx, Unk_3bff70_Transition* transition, bool arg2);

// What 0x710038cca0 takes.
struct Unk_38cca0_Arg {
    void* field_0;
    u8 field_8;
};
void Unk_38cca0(Unk_3be850_Ctx* ctx, Unk_38cca0_Arg* arg, f32 value);

void Unk_38c590(void* self, u32 a1, bool a2);  // slot 0 of Unk_2382488
void Unk_38d590(void* self);
bool Unk_31db50(void* self, void* ctx, s32* position, s32* offset);

extern "C" f32 log10f(f32 x);

extern u16 Unk_2382e78;  // the samples of a buffer

// What field_1f8 of a context points at.
struct Unk_2382488_1f8 {
    u8 _0[0xc];
    u16 field_c_0 : 1;
    u16 field_c_1 : 1;
};

// The bases of Unk_2382488 (vtables at 0x7102382498, 25 slots).
struct Unk_2382488_Base0 {
    virtual void vf0(u32 a1, bool a2);
    virtual ~Unk_2382488_Base0();
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
    virtual u32 vf16();
    virtual void vf17();
    virtual void vf18();
    virtual void vf19(u32 a1);
    virtual void vf20();
    virtual void vf21();
    virtual void vf22();
    virtual u32 vf23();
    virtual void vf24();

    u64 field_8;
};

// The base at 0x10 (one slot).
struct Unk_2382488_Base10 {
    virtual void vf5();
};

// The base at 0x18 (14 slots): its slot 10 is the primary vtable's slot 18,
// and a class below overrides its slot 5 in the primary's slot 26.
struct Unk_2382488_Base18 {
    virtual ~Unk_2382488_Base18();
    virtual void b_vf2();
    virtual void b_vf3();
    virtual void b_vf4();
    virtual u64 vf26();
    virtual void b_vf6();
    virtual void b_vf7();
    virtual void b_vf8();
    virtual void b_vf9();
    virtual void vf18();
    virtual void b_vf11();
    virtual void b_vf12();
    virtual void b_vf13();
};

// 0x2c0 bytes.
class Unk_2382488 : public Unk_2382488_Base0, public Unk_2382488_Base10,
                    public Unk_2382488_Base18 {
public:
    u8 _20[0x60];
    f32 field_80;
    f32 field_84;
    f32 field_88;
    u8 _8c[0x78];
    f32 field_104;
    f32 field_108;
    f32 field_10c;
    f32 field_110;
    u8 _114[0x58];
    u16 field_16c;
    u8 _16e[0x8a];
    Unk_2382488_1f8* field_1f8;
    u8 _200[0x14];
    f32 field_214;
    u8 _218[4];
    f32 field_21c;
    u8 _220[0x44];
    s32 field_264;
    u8 _268[3];
    // 40 bits of flags, not aligned.
    struct __attribute__((packed)) {
        u64 field_26b_0 : 21;
        u64 field_26b_21 : 1;
        u64 field_26b_22 : 1;
        u64 field_26b_23 : 1;
        u64 field_26b_24 : 1;
        u64 field_26b_25 : 4;
        u64 field_26b_29 : 1;
        u64 field_26b_30 : 10;
    };
    u8 _270[0x18];
    s32 field_288;
    u8 _28c[0x2c];
    u32 field_2b8;
    u8 _2bc[4];
};
PKMN_OFFSET_ASSERT(Unk_2382488, field_80, 0x80);
PKMN_OFFSET_ASSERT(Unk_2382488, field_104, 0x104);
PKMN_OFFSET_ASSERT(Unk_2382488, field_16c, 0x16c);
PKMN_OFFSET_ASSERT(Unk_2382488, field_1f8, 0x1f8);
PKMN_OFFSET_ASSERT(Unk_2382488, field_214, 0x214);
PKMN_OFFSET_ASSERT(Unk_2382488, field_21c, 0x21c);
PKMN_OFFSET_ASSERT(Unk_2382488, field_264, 0x264);
PKMN_OFFSET_ASSERT(Unk_2382488, field_288, 0x288);
PKMN_OFFSET_ASSERT(Unk_2382488, field_2b8, 0x2b8);
PKMN_SIZE_ASSERT(Unk_2382488, 0x2c0);

// The base at 0x2c0 (vtable at 0x710237c800, 12 slots; constructor
// 0x71003096f0), 0x18 bytes.
struct Unk_237c628_Base2c0 {
    virtual void vf25(u64 a1);
    virtual void vf27();
    virtual void vf28(u32 a1);
    virtual void vf29();
    virtual void vf30();
    virtual void vf31(void* a1, f32 a2);
    virtual void vf32(u32 a1, f32 a2);
    virtual void vf33();
    virtual void vf34();
    virtual void vf35();
    virtual ~Unk_237c628_Base2c0();

    u64 field_8;
    void* field_10;
};
PKMN_SIZE_ASSERT(Unk_237c628_Base2c0, 0x18);

// The nearest of two values to x.
static inline s32 Unk_Round(f32 x) {
    return static_cast<s32>(x + (x > 0.0f ? 0.5f : -0.5f));
}

class Unk_237c628 : public Unk_2382488, public Unk_237c628_Base2c0 {
public:
    void vf0(u32 a1, bool a2) override;
    ~Unk_237c628() override;
    u32 vf16() override;
    void vf18() override;
    u32 vf23() override;

    void vf25(u64 a1) override { vf28(a1); }
    u64 vf26() override;
    void vf27() override;
    void vf28(u32 a1) override;
    void vf29() override { vf19(1); }
    void vf30() override {
        vf20();
        field_21c = 1.0f;
        vf13();
    }
    void vf31(void* a1, f32 a2) override;
    void vf32(u32 a1, f32 a2) override {
        if (a1 == 0x36) {
            field_214 = a2;
            field_16c &= ~0x20;
        }
    }
    void vf33() override;
    void vf34() override;
    void vf35() override;

    void Unk_30d650();

    void Move(s32 delta) {
        field_288 += delta;
        field_264 += delta;
        field_26b_22 = 1;
        field_26b_23 = 0;
        field_26b_24 = 0;
    }

    u8 field_2d8[8];
    u8 field_2e0_0 : 1;
};
PKMN_OFFSET_ASSERT(Unk_237c628, field_2d8, 0x2d8);

// 0x710030d2e0
void Unk_237c628::vf0(u32 a1, bool a2) {
    if (a2 && field_2b8 != 0xffffffff)
        return;
    Unk_38c590(this, a1, false);
}

// 0x710030d370, and its thunk 0x710030d400
void Unk_237c628::vf28(u32 a1) {
    if (a1 != 0xffffffff) {
        u32 value = Unk_Round(a1 / field_214);
        if (field_2b8 > value)
            field_2b8 = value;
    }
    Unk_3bff70_Transition transition;
    transition.field_0 = 0;
    transition.field_4 = 4;
    Unk_38c050(reinterpret_cast<Unk_3be850_Ctx*>(this), &transition,
               field_2b8 == 0xffffffff ? true : field_2e0_0);
}

// 0x710030d5b0, and its thunk 0x710030d5e0
void Unk_237c628::vf31(void* a1, f32 a2) {
    Unk_38cca0_Arg arg;
    arg.field_8 = 2;
    arg.field_0 = a1;
    Unk_38cca0(reinterpret_cast<Unk_3be850_Ctx*>(this), &arg, a2);
}

// 0x710030d740
u32 Unk_237c628::vf16() {
    s32 position;
    s32 offset;
    if (!Unk_31db50(Unk_237c628_Base2c0::field_10, this, &position, &offset))
        return 2;
    field_288 = position;
    field_264 = offset;
    field_26b_22 = 1;
    field_26b_23 = 0;
    field_26b_24 = 0;
    return 1;
}

// 0x710030d7c0, and its thunk 0x710030d800
void Unk_237c628::vf18() {
    Unk_38d590(this);
    field_80 = log10f(field_214) * 3986.3135f;
}

// 0x710030d840
u32 Unk_237c628::vf23() {
    u32 value = field_2b8;
    field_2b8 = 0xffffffff;
    return field_2e0_0 ? 0xffffffff : value;
}

// 0x710030d650: moves the position to a multiple of the buffers' length.
void Unk_237c628::Unk_30d650() {
    if (field_26b_22 || !field_1f8->field_c_1) {
        s32 position = field_288;
        s32 length = Unk_Round(Unk_2382e78 * field_214);
        s32 rest = position % length;
        if (rest > length / 2 || field_264 < rest)
            Move(length - rest);
        else if (rest > 0)
            Move(-rest);
    }
    field_26b_29 = 1;
}
