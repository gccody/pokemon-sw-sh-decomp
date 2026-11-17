// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

// Called by forwarders. Placeholders: their real signatures aren't known.
void Unk_fcce00(void* self);
void Unk_fcd090(void* self);

struct Unk_24033d0_5f0 {
    u8 _0[0x58];
    u8 field_58;
};
PKMN_OFFSET_ASSERT(Unk_24033d0_5f0, field_58, 0x58);

class Unk_24033d0 {
public:
    virtual ~Unk_24033d0();
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
    u8 _8[0x5e0];
    u64 field_5e8;
    Unk_24033d0_5f0* field_5f0;
};
PKMN_OFFSET_ASSERT(Unk_24033d0, field_5e8, 0x5e8);
PKMN_OFFSET_ASSERT(Unk_24033d0, field_5f0, 0x5f0);

// 0x7100fcd440
void Unk_24033d0::vf20() {
    field_5e8 = 0;
}

// 0x7100fcccc0
void Unk_24033d0::vf21() {
    field_5f0->field_58 = field_5f0->field_58 & 0xfe;
}

class Unk_24034f8 {
public:
    virtual ~Unk_24034f8();
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
    virtual u32 vf18();
    virtual void vf19();
    virtual void vf20();
    virtual void vf21();
};

// 0x7100fcd600
void Unk_24034f8::vf6() {
    Unk_fcce00(this);
}

// 0x7100fcd610
void Unk_24034f8::vf17() {}

// 0x7100fcd620
u32 Unk_24034f8::vf18() {
    return 1;
}

// 0x7100fcd630
void Unk_24034f8::vf19() {}

class Unk_24035b8 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x7100fcd660
void Unk_24035b8::vf5() {
    Unk_fcce00(this);
}

class Unk_24035f8 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x7100fcd670
void Unk_24035f8::vf0() {
    Unk_fcce00(this);
}

class Unk_2403830 {
public:
    virtual ~Unk_2403830();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
};

// 0x7100fcf8f0
void Unk_2403830::vf4() {}

class Unk_2403878 {
public:
    virtual ~Unk_2403878();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
};

// 0x7100fcf9e0
void Unk_2403878::vf4() {}

class Unk_24038c0 {
public:
    virtual ~Unk_24038c0();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
};

// 0x7100fcfad0
void Unk_24038c0::vf4() {}

class Unk_2403908 {
public:
    virtual ~Unk_2403908();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
};

// 0x7100fcfbc0
void Unk_2403908::vf4() {}

class Unk_2403950 {
public:
    virtual ~Unk_2403950();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
};

// 0x7100fcfcb0
void Unk_2403950::vf4() {}

class Unk_2403998 {
public:
    virtual ~Unk_2403998();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
};

// 0x7100fcfda0
void Unk_2403998::vf4() {}

class Unk_24039e0 {
public:
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
};

// 0x7100fd04c0
void Unk_24039e0::vf19() {
    Unk_fcd090(this);
}

class Unk_2403d88 {
public:
    virtual ~Unk_2403d88();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
};

// 0x7100fd37c0
void Unk_2403d88::vf4() {}

class Unk_2403dd0 {
public:
    virtual ~Unk_2403dd0();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
};

// 0x7100fd38b0
void Unk_2403dd0::vf4() {}

class Unk_2403e18 {
public:
    virtual ~Unk_2403e18();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
};

// 0x7100fd39a0
void Unk_2403e18::vf4() {}

class Unk_2403f88 {
public:
    virtual ~Unk_2403f88();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
};

// 0x7100fd7420, 0x7100fd63b0
Unk_2403f88::~Unk_2403f88() {}

// 0x7100fd6420
void Unk_2403f88::vf4() {}

class Unk_2403fd0 : public Unk_2403f88 {
public:
    void vf4() override;
    void vf2() override;
    void vf3() override;
    void vf5() override;
    void vf6() override;
};

// 0x7100fd64f0
void Unk_2403fd0::vf4() {}

struct Unk_2404018_8 {
    u8 _0[0xb30];
    u32 field_b30;
};
PKMN_OFFSET_ASSERT(Unk_2404018_8, field_b30, 0xb30);

class Unk_2404018 {
public:
    virtual ~Unk_2404018();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    Unk_2404018_8* field_8;
};
PKMN_OFFSET_ASSERT(Unk_2404018, field_8, 0x8);

// 0x7100fd6590
void Unk_2404018::vf4() {}

// 0x7100fd65b0
void Unk_2404018::vf6() {
    field_8->field_b30 = 0;
}

struct Unk_2404060_8 {
    u8 _0[0xb30];
    u32 field_b30;
};
PKMN_OFFSET_ASSERT(Unk_2404060_8, field_b30, 0xb30);

class Unk_2404060 {
public:
    virtual ~Unk_2404060();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    Unk_2404060_8* field_8;
};
PKMN_OFFSET_ASSERT(Unk_2404060, field_8, 0x8);

// 0x7100fd6630
void Unk_2404060::vf4() {}

// 0x7100fd6650
void Unk_2404060::vf6() {
    field_8->field_b30 = 1;
}

class Unk_24040a8 : public Unk_2403f88 {
public:
    void vf4() override;
    void vf2() override;
    void vf3() override;
    void vf5() override;
    void vf6() override;
};

// 0x7100fd66d0
void Unk_24040a8::vf4() {}

class Unk_24040f0 : public Unk_2403f88 {
public:
    void vf4() override;
    void vf2() override;
    void vf3() override;
    void vf5() override;
    void vf6() override;
};

// 0x7100fd6770
void Unk_24040f0::vf4() {}

class Unk_2404138 : public Unk_2403f88 {
public:
    void vf4() override;
    void vf2() override;
    void vf3() override;
    void vf5() override;
    void vf6() override;
};

// 0x7100fd6810
void Unk_2404138::vf4() {}

struct Unk_2404180_8 {
    u8 _0[0xb30];
    u32 field_b30;
};
PKMN_OFFSET_ASSERT(Unk_2404180_8, field_b30, 0xb30);

class Unk_2404180 {
public:
    virtual ~Unk_2404180();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    Unk_2404180_8* field_8;
};
PKMN_OFFSET_ASSERT(Unk_2404180, field_8, 0x8);

// 0x7100fd68b0
void Unk_2404180::vf4() {}

// 0x7100fd68d0
void Unk_2404180::vf6() {
    field_8->field_b30 = 0;
}

struct Unk_24041c8_8 {
    u8 _0[0xb30];
    u32 field_b30;
};
PKMN_OFFSET_ASSERT(Unk_24041c8_8, field_b30, 0xb30);

class Unk_24041c8 {
public:
    virtual ~Unk_24041c8();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    Unk_24041c8_8* field_8;
};
PKMN_OFFSET_ASSERT(Unk_24041c8, field_8, 0x8);

// 0x7100fd6950
void Unk_24041c8::vf4() {}

// 0x7100fd6970
void Unk_24041c8::vf6() {
    field_8->field_b30 = 1;
}

struct Unk_2404210_8 {
    u8 _0[0xb30];
    u32 field_b30;
};
PKMN_OFFSET_ASSERT(Unk_2404210_8, field_b30, 0xb30);

class Unk_2404210 {
public:
    virtual ~Unk_2404210();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    Unk_2404210_8* field_8;
};
PKMN_OFFSET_ASSERT(Unk_2404210, field_8, 0x8);

// 0x7100fd69f0
void Unk_2404210::vf4() {}

// 0x7100fd6a10
void Unk_2404210::vf6() {
    field_8->field_b30 = 2;
}

class Unk_2404258 : public Unk_2403f88 {
public:
    void vf4() override;
    void vf2() override;
    void vf3() override;
    void vf5() override;
    void vf6() override;
};

// 0x7100fd6a90
void Unk_2404258::vf4() {}

class Unk_24042a0 : public Unk_2403f88 {
public:
    void vf4() override;
    void vf2() override;
    void vf3() override;
    void vf5() override;
    void vf6() override;
};

// 0x7100fd6b30
void Unk_24042a0::vf4() {}

class Unk_24042e8 : public Unk_2403f88 {
public:
    void vf4() override;
    void vf2() override;
    void vf3() override;
    void vf5() override;
    void vf6() override;
};

// 0x7100fd6bd0
void Unk_24042e8::vf4() {}

class Unk_2404330 : public Unk_2403f88 {
public:
    void vf4() override;
    void vf2() override;
    void vf3() override;
    void vf5() override;
    void vf6() override;
};

// 0x7100fd6c70
void Unk_2404330::vf4() {}

struct Unk_2404378_8 {
    u8 _0[0xb30];
    u32 field_b30;
};
PKMN_OFFSET_ASSERT(Unk_2404378_8, field_b30, 0xb30);

class Unk_2404378 {
public:
    virtual ~Unk_2404378();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    Unk_2404378_8* field_8;
};
PKMN_OFFSET_ASSERT(Unk_2404378, field_8, 0x8);

// 0x7100fd6d10
void Unk_2404378::vf4() {}

// 0x7100fd6d30
void Unk_2404378::vf6() {
    field_8->field_b30 = 0;
}

struct Unk_24043c0_8 {
    u8 _0[0xb30];
    u32 field_b30;
};
PKMN_OFFSET_ASSERT(Unk_24043c0_8, field_b30, 0xb30);

class Unk_24043c0 {
public:
    virtual ~Unk_24043c0();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    Unk_24043c0_8* field_8;
};
PKMN_OFFSET_ASSERT(Unk_24043c0, field_8, 0x8);

// 0x7100fd6db0
void Unk_24043c0::vf4() {}

// 0x7100fd6dd0
void Unk_24043c0::vf6() {
    field_8->field_b30 = 1;
}

class Unk_2404408 : public Unk_2403f88 {
public:
    void vf4() override;
    void vf2() override;
    void vf3() override;
    void vf5() override;
    void vf6() override;
};

// 0x7100fd6e50
void Unk_2404408::vf4() {}

class Unk_2404450 : public Unk_2403f88 {
public:
    void vf4() override;
    void vf2() override;
    void vf3() override;
    void vf5() override;
    void vf6() override;
};

// 0x7100fd6ef0
void Unk_2404450::vf4() {}

struct Unk_2404498_8 {
    u8 _0[0xb30];
    u32 field_b30;
};
PKMN_OFFSET_ASSERT(Unk_2404498_8, field_b30, 0xb30);

class Unk_2404498 {
public:
    virtual ~Unk_2404498();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    Unk_2404498_8* field_8;
};
PKMN_OFFSET_ASSERT(Unk_2404498, field_8, 0x8);

// 0x7100fd6f90
void Unk_2404498::vf4() {}

// 0x7100fd6fb0
void Unk_2404498::vf6() {
    field_8->field_b30 = 0;
}

struct Unk_24044e0_8 {
    u8 _0[0xb30];
    u32 field_b30;
};
PKMN_OFFSET_ASSERT(Unk_24044e0_8, field_b30, 0xb30);

class Unk_24044e0 {
public:
    virtual ~Unk_24044e0();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    Unk_24044e0_8* field_8;
};
PKMN_OFFSET_ASSERT(Unk_24044e0, field_8, 0x8);

// 0x7100fd7030
void Unk_24044e0::vf4() {}

// 0x7100fd7050
void Unk_24044e0::vf6() {
    field_8->field_b30 = 1;
}

class Unk_2404528 : public Unk_2403f88 {
public:
    void vf4() override;
    void vf2() override;
    void vf3() override;
    void vf5() override;
    void vf6() override;
};

// 0x7100fd70d0
void Unk_2404528::vf4() {}

class Unk_2404570 : public Unk_2403f88 {
public:
    void vf4() override;
    void vf2() override;
    void vf3() override;
    void vf5() override;
    void vf6() override;
};

// 0x7100fd7170
void Unk_2404570::vf4() {}

class Unk_24045b8 : public Unk_2403f88 {
public:
    void vf4() override;
    void vf2() override;
    void vf3() override;
    void vf5() override;
    void vf6() override;
};

// 0x7100fd7210
void Unk_24045b8::vf4() {}

class Unk_2404600 : public Unk_2403f88 {
public:
    void vf4() override;
    void vf2() override;
    void vf3() override;
    void vf5() override;
    void vf6() override;
};

// 0x7100fd72b0
void Unk_2404600::vf4() {}

class Unk_2404648 : public Unk_2403f88 {
public:
    void vf4() override;
    void vf2() override;
    void vf3() override;
    void vf5() override;
    void vf6() override;
};

// 0x7100fd7350
void Unk_2404648::vf4() {}

class Unk_2404690 : public Unk_2403f88 {
public:
    void vf4() override;
    void vf2() override;
    void vf3() override;
    void vf5() override;
    void vf6() override;
};

// 0x7100fd73f0
void Unk_2404690::vf4() {}

class Unk_24046d8 : public Unk_2403f88 {
public:
    void vf4() override;
    void vf2() override;
    void vf3() override;
    void vf5() override;
    void vf6() override;
};

// 0x7100fd74a0
void Unk_24046d8::vf4() {}

struct Unk_2404720_8 {
    u8 _0[0xb30];
    u32 field_b30;
};
PKMN_OFFSET_ASSERT(Unk_2404720_8, field_b30, 0xb30);

class Unk_2404720 {
public:
    virtual ~Unk_2404720();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    Unk_2404720_8* field_8;
};
PKMN_OFFSET_ASSERT(Unk_2404720, field_8, 0x8);

// 0x7100fd7540
void Unk_2404720::vf4() {}

// 0x7100fd7560
void Unk_2404720::vf6() {
    field_8->field_b30 = 0;
}

struct Unk_2404768_8 {
    u8 _0[0xb30];
    u32 field_b30;
};
PKMN_OFFSET_ASSERT(Unk_2404768_8, field_b30, 0xb30);

class Unk_2404768 {
public:
    virtual ~Unk_2404768();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    Unk_2404768_8* field_8;
};
PKMN_OFFSET_ASSERT(Unk_2404768, field_8, 0x8);

// 0x7100fd75e0
void Unk_2404768::vf4() {}

// 0x7100fd7600
void Unk_2404768::vf6() {
    field_8->field_b30 = 1;
}

struct Unk_24047b0_8 {
    u8 _0[0xb30];
    u32 field_b30;
};
PKMN_OFFSET_ASSERT(Unk_24047b0_8, field_b30, 0xb30);

class Unk_24047b0 {
public:
    virtual ~Unk_24047b0();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    Unk_24047b0_8* field_8;
};
PKMN_OFFSET_ASSERT(Unk_24047b0, field_8, 0x8);

// 0x7100fd7680
void Unk_24047b0::vf4() {}

// 0x7100fd76a0
void Unk_24047b0::vf6() {
    field_8->field_b30 = 2;
}

struct Unk_24047f8_8 {
    u8 _0[0xb30];
    u32 field_b30;
};
PKMN_OFFSET_ASSERT(Unk_24047f8_8, field_b30, 0xb30);

class Unk_24047f8 {
public:
    virtual ~Unk_24047f8();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    Unk_24047f8_8* field_8;
};
PKMN_OFFSET_ASSERT(Unk_24047f8, field_8, 0x8);

// 0x7100fd7720
void Unk_24047f8::vf4() {}

// 0x7100fd7740
void Unk_24047f8::vf6() {
    field_8->field_b30 = 3;
}

struct Unk_2404840_8 {
    u8 _0[0xb30];
    u32 field_b30;
};
PKMN_OFFSET_ASSERT(Unk_2404840_8, field_b30, 0xb30);

class Unk_2404840 {
public:
    virtual ~Unk_2404840();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    Unk_2404840_8* field_8;
};
PKMN_OFFSET_ASSERT(Unk_2404840, field_8, 0x8);

// 0x7100fd77c0
void Unk_2404840::vf4() {}

// 0x7100fd77e0
void Unk_2404840::vf6() {
    field_8->field_b30 = 4;
}

struct Unk_2404888_8 {
    u8 _0[0xb30];
    u32 field_b30;
};
PKMN_OFFSET_ASSERT(Unk_2404888_8, field_b30, 0xb30);

class Unk_2404888 {
public:
    virtual ~Unk_2404888();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    Unk_2404888_8* field_8;
};
PKMN_OFFSET_ASSERT(Unk_2404888, field_8, 0x8);

// 0x7100fd7860
void Unk_2404888::vf4() {}

// 0x7100fd7880
void Unk_2404888::vf6() {
    field_8->field_b30 = 5;
}

class Unk_24048d0 : public Unk_2403f88 {
public:
    void vf4() override;
    void vf2() override;
    void vf3() override;
    void vf5() override;
    void vf6() override;
};

// 0x7100fd7900
void Unk_24048d0::vf4() {}

struct Unk_2404918_8 {
    u8 _0[0xb30];
    u32 field_b30;
};
PKMN_OFFSET_ASSERT(Unk_2404918_8, field_b30, 0xb30);

class Unk_2404918 {
public:
    virtual ~Unk_2404918();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    Unk_2404918_8* field_8;
};
PKMN_OFFSET_ASSERT(Unk_2404918, field_8, 0x8);

// 0x7100fd79a0
void Unk_2404918::vf4() {}

// 0x7100fd79c0
void Unk_2404918::vf6() {
    field_8->field_b30 = 0;
}

struct Unk_2404960_8 {
    u8 _0[0xb30];
    u32 field_b30;
};
PKMN_OFFSET_ASSERT(Unk_2404960_8, field_b30, 0xb30);

class Unk_2404960 {
public:
    virtual ~Unk_2404960();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    Unk_2404960_8* field_8;
};
PKMN_OFFSET_ASSERT(Unk_2404960, field_8, 0x8);

// 0x7100fd7a40
void Unk_2404960::vf4() {}

// 0x7100fd7a60
void Unk_2404960::vf6() {
    field_8->field_b30 = 1;
}

struct Unk_24049a8_8 {
    u8 _0[0xb30];
    u32 field_b30;
};
PKMN_OFFSET_ASSERT(Unk_24049a8_8, field_b30, 0xb30);

class Unk_24049a8 {
public:
    virtual ~Unk_24049a8();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    Unk_24049a8_8* field_8;
};
PKMN_OFFSET_ASSERT(Unk_24049a8, field_8, 0x8);

// 0x7100fd7ae0
void Unk_24049a8::vf4() {}

// 0x7100fd7b00
void Unk_24049a8::vf6() {
    field_8->field_b30 = 2;
}

class Unk_24049f0 : public Unk_2403f88 {
public:
    void vf4() override;
    void vf2() override;
    void vf3() override;
    void vf5() override;
    void vf6() override;
};

// 0x7100fd7b80
void Unk_24049f0::vf4() {}

class Unk_2404a38 : public Unk_2403f88 {
public:
    void vf4() override;
    void vf2() override;
    void vf3() override;
    void vf5() override;
    void vf6() override;
};

// 0x7100fd7c20
void Unk_2404a38::vf4() {}

struct Unk_2404a80_8 {
    u8 _0[0xb30];
    u32 field_b30;
};
PKMN_OFFSET_ASSERT(Unk_2404a80_8, field_b30, 0xb30);

class Unk_2404a80 {
public:
    virtual ~Unk_2404a80();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    Unk_2404a80_8* field_8;
};
PKMN_OFFSET_ASSERT(Unk_2404a80, field_8, 0x8);

// 0x7100fd7cc0
void Unk_2404a80::vf4() {}

// 0x7100fd7ce0
void Unk_2404a80::vf6() {
    field_8->field_b30 = 0;
}

struct Unk_2404ac8_8 {
    u8 _0[0xb30];
    u32 field_b30;
};
PKMN_OFFSET_ASSERT(Unk_2404ac8_8, field_b30, 0xb30);

class Unk_2404ac8 {
public:
    virtual ~Unk_2404ac8();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    Unk_2404ac8_8* field_8;
};
PKMN_OFFSET_ASSERT(Unk_2404ac8, field_8, 0x8);

// 0x7100fd7d60
void Unk_2404ac8::vf4() {}

// 0x7100fd7d80
void Unk_2404ac8::vf6() {
    field_8->field_b30 = 1;
}

class Unk_2404b10 : public Unk_2403f88 {
public:
    void vf4() override;
    void vf2() override;
    void vf3() override;
    void vf5() override;
    void vf6() override;
};

// 0x7100fd7e00
void Unk_2404b10::vf4() {}
