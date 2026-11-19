// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

// Called by forwarders. Placeholders: their real signatures aren't known.
void Unk_add5d0(void* self);
void Unk_ae43b0(void* self);
void Unk_15b6e10(void* self);

class Unk_23c98b0 {
public:
    virtual ~Unk_23c98b0();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
};

// 0x7100ad7170, 0x7100ad7080
Unk_23c98b0::~Unk_23c98b0() {}

// 0x7100ad70f0
void Unk_23c98b0::vf4() {}

// 0x7100ad7100
void Unk_23c98b0::vf5() {
    ::operator delete(this);
}

class Unk_23c98f8 : public Unk_23c98b0 {
public:
    void vf4() override;
    void vf2() override;
    void vf3() override;
    void vf5() override;
    void vf6() override;
};

// 0x7100ad71f0
void Unk_23c98f8::vf4() {}

// 0x7100ad7200
void Unk_23c98f8::vf5() {
    ::operator delete(this);
}

class Unk_23c9940 : public Unk_23c98b0 {
public:
    void vf4() override;
    void vf2() override;
    void vf3() override;
    void vf5() override;
    void vf6() override;
};

// 0x7100ad72e0
void Unk_23c9940::vf4() {}

// 0x7100ad72f0
void Unk_23c9940::vf5() {
    ::operator delete(this);
}

struct Unk_23c9ab0_8 {
    u8 _0[0xb40];
    u32 field_b40;
};
PKMN_OFFSET_ASSERT(Unk_23c9ab0_8, field_b40, 0xb40);

class Unk_23c9ab0 {
public:
    virtual ~Unk_23c9ab0();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    Unk_23c9ab0_8* field_8;
};
PKMN_OFFSET_ASSERT(Unk_23c9ab0, field_8, 0x8);

// 0x7100ad9320, 0x7100ad9330
Unk_23c9ab0::~Unk_23c9ab0() {}

// 0x7100ad93a0
void Unk_23c9ab0::vf4() {}

// 0x7100ad93b0
void Unk_23c9ab0::vf5() {
    ::operator delete(this);
}

class Unk_23c9af8 : public Unk_23c98b0 {
public:
    void vf4() override;
    void vf2() override;
    void vf3() override;
    void vf5() override;
    void vf6() override;
};

// 0x7100ad97e0
void Unk_23c9af8::vf4() {}

// 0x7100ad97f0
void Unk_23c9af8::vf5() {
    ::operator delete(this);
}

class Unk_23c9b40 : public Unk_23c98b0 {
public:
    void vf4() override;
    void vf2() override;
    void vf3() override;
    void vf5() override;
    void vf6() override;
};

// 0x7100ad98d0
void Unk_23c9b40::vf4() {}

// 0x7100ad98e0
void Unk_23c9b40::vf5() {
    ::operator delete(this);
}

class Unk_23c9b88 : public Unk_23c98b0 {
public:
    void vf4() override;
    void vf2() override;
    void vf3() override;
    void vf5() override;
    void vf6() override;
};

// 0x7100ad99c0
void Unk_23c9b88::vf4() {}

// 0x7100ad99d0
void Unk_23c9b88::vf5() {
    ::operator delete(this);
}

class Unk_23c9bd0 : public Unk_23c98b0 {
public:
    void vf4() override;
    void vf2() override;
    void vf3() override;
    void vf5() override;
    void vf6() override;
};

// 0x7100ad9ab0
void Unk_23c9bd0::vf4() {}

// 0x7100ad9ac0
void Unk_23c9bd0::vf5() {
    ::operator delete(this);
}

class Unk_23c9c18 : public Unk_23c98b0 {
public:
    void vf4() override;
    void vf2() override;
    void vf3() override;
    void vf5() override;
    void vf6() override;
};

// 0x7100ad9ba0
void Unk_23c9c18::vf4() {}

// 0x7100ad9bb0
void Unk_23c9c18::vf5() {
    ::operator delete(this);
}

class Unk_23ca118 : public Unk_23c98b0 {
public:
    void vf4() override;
    void vf2() override;
    void vf3() override;
    void vf5() override;
    void vf6() override;
};

// 0x7100adcaa0
void Unk_23ca118::vf4() {}

// 0x7100adcab0
void Unk_23ca118::vf5() {
    ::operator delete(this);
}

class Unk_23ca160 : public Unk_23c98b0 {
public:
    void vf4() override;
    void vf2() override;
    void vf3() override;
    void vf5() override;
    void vf6() override;
};

// 0x7100adcb90
void Unk_23ca160::vf4() {}

// 0x7100adcba0
void Unk_23ca160::vf5() {
    ::operator delete(this);
}

struct Unk_23ca1a8_5f0 {
    u8 _0[0x58];
    u8 field_58;
};
PKMN_OFFSET_ASSERT(Unk_23ca1a8_5f0, field_58, 0x58);

class Unk_23ca1a8 {
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
    virtual u32 vf16();
    virtual void vf17();
    u8 _8[0x5e8];
    Unk_23ca1a8_5f0* field_5f0;
};
PKMN_OFFSET_ASSERT(Unk_23ca1a8, field_5f0, 0x5f0);

// 0x7100add3c0
void Unk_23ca1a8::vf6() {
    Unk_add5d0(this);
}

// 0x7100add260
u32 Unk_23ca1a8::vf16() {
    return 0;
}

// 0x7100add3d0
void Unk_23ca1a8::vf17() {
    field_5f0->field_58 = field_5f0->field_58 & 0xfe;
}

class Unk_23ca248 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x7100add4d0
void Unk_23ca248::vf5() {
    Unk_add5d0(this);
}

class Unk_23ca288 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x7100add4e0
void Unk_23ca288::vf0() {
    Unk_add5d0(this);
}

class Unk_23ca420 {
public:
    virtual ~Unk_23ca420();
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
};

// 0x7100ae4150
void Unk_23ca420::vf6() {
    Unk_ae43b0(this);
}

class Unk_23ca4c8 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x7100ae4180
void Unk_23ca4c8::vf5() {
    Unk_ae43b0(this);
}

class Unk_23ca508 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x7100ae4190
void Unk_23ca508::vf0() {
    Unk_ae43b0(this);
}

struct Unk_23ca530_8 {
    u8 _0[0xb44];
    u8 field_b44;
};
PKMN_OFFSET_ASSERT(Unk_23ca530_8, field_b44, 0xb44);

class Unk_23ca530 {
public:
    virtual ~Unk_23ca530();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    Unk_23ca530_8* field_8;
};
PKMN_OFFSET_ASSERT(Unk_23ca530, field_8, 0x8);

// 0x7100ae71b0, 0x7100ae47a0
Unk_23ca530::~Unk_23ca530() {}

// 0x7100ae4810
void Unk_23ca530::vf4() {}

// 0x7100ae4820
void Unk_23ca530::vf5() {
    ::operator delete(this);
}

class Unk_23ca578 : public Unk_23ca530 {
public:
    void vf4() override;
    void vf2() override;
    void vf3() override;
    void vf5() override;
    void vf6() override;
};

// 0x7100ae48e0
void Unk_23ca578::vf4() {}

// 0x7100ae48f0
void Unk_23ca578::vf5() {
    ::operator delete(this);
}

// 0x7100ae4900
void Unk_23ca578::vf6() {
    field_8->field_b44 = 1;
}

class Unk_23ca5c0 : public Unk_23ca530 {
public:
    void vf4() override;
    void vf2() override;
    void vf3() override;
    void vf5() override;
    void vf6() override;
};

// 0x7100ae4980
void Unk_23ca5c0::vf4() {}

// 0x7100ae4990
void Unk_23ca5c0::vf5() {
    ::operator delete(this);
}

// 0x7100ae49a0
void Unk_23ca5c0::vf6() {
    field_8->field_b44 = 1;
}

class Unk_23ca608 : public Unk_23ca530 {
public:
    void vf4() override;
    void vf2() override;
    void vf3() override;
    void vf5() override;
    void vf6() override;
};

// 0x7100ae4a20
void Unk_23ca608::vf4() {}

// 0x7100ae4a30
void Unk_23ca608::vf5() {
    ::operator delete(this);
}

// 0x7100ae4a40
void Unk_23ca608::vf6() {
    field_8->field_b44 = 1;
}

class Unk_23ca650 : public Unk_23ca530 {
public:
    void vf4() override;
    void vf2() override;
    void vf3() override;
    void vf5() override;
    void vf6() override;
};

// 0x7100ae4ac0
void Unk_23ca650::vf4() {}

// 0x7100ae4ad0
void Unk_23ca650::vf5() {
    ::operator delete(this);
}

// 0x7100ae4ae0
void Unk_23ca650::vf6() {
    field_8->field_b44 = 1;
}

class Unk_23ca698 : public Unk_23c9ab0 {
public:
    void vf4() override;
    void vf2() override;
    void vf3() override;
    void vf5() override;
    void vf6() override;
};

// 0x7100ae4b60
void Unk_23ca698::vf4() {}

// 0x7100ae4b70
void Unk_23ca698::vf5() {
    ::operator delete(this);
}

// 0x7100ae4b80
void Unk_23ca698::vf6() {
    field_8->field_b40 = 0;
}

class Unk_23ca6e0 : public Unk_23c9ab0 {
public:
    void vf4() override;
    void vf2() override;
    void vf3() override;
    void vf5() override;
    void vf6() override;
};

// 0x7100ae4c00
void Unk_23ca6e0::vf4() {}

// 0x7100ae4c10
void Unk_23ca6e0::vf5() {
    ::operator delete(this);
}

// 0x7100ae4c20
void Unk_23ca6e0::vf6() {
    field_8->field_b40 = 1;
}

class Unk_23ca728 : public Unk_23c9ab0 {
public:
    void vf4() override;
    void vf2() override;
    void vf3() override;
    void vf5() override;
    void vf6() override;
};

// 0x7100ae4ca0
void Unk_23ca728::vf4() {}

// 0x7100ae4cb0
void Unk_23ca728::vf5() {
    ::operator delete(this);
}

// 0x7100ae4cc0
void Unk_23ca728::vf6() {
    field_8->field_b40 = 2;
}

class Unk_23ca770 : public Unk_23ca530 {
public:
    void vf4() override;
    void vf2() override;
    void vf3() override;
    void vf5() override;
    void vf6() override;
};

// 0x7100ae4d40
void Unk_23ca770::vf4() {}

// 0x7100ae4d50
void Unk_23ca770::vf5() {
    ::operator delete(this);
}

// 0x7100ae4d60
void Unk_23ca770::vf6() {
    field_8->field_b44 = 1;
}

class Unk_23ca7b8 : public Unk_23ca530 {
public:
    void vf4() override;
    void vf2() override;
    void vf3() override;
    void vf5() override;
    void vf6() override;
};

// 0x7100ae4de0
void Unk_23ca7b8::vf4() {}

// 0x7100ae4df0
void Unk_23ca7b8::vf5() {
    ::operator delete(this);
}

// 0x7100ae4e00
void Unk_23ca7b8::vf6() {
    field_8->field_b44 = 1;
}

class Unk_23ca800 : public Unk_23ca530 {
public:
    void vf4() override;
    void vf2() override;
    void vf3() override;
    void vf5() override;
    void vf6() override;
};

// 0x7100ae4e80
void Unk_23ca800::vf4() {}

// 0x7100ae4e90
void Unk_23ca800::vf5() {
    ::operator delete(this);
}

// 0x7100ae4ea0
void Unk_23ca800::vf6() {
    field_8->field_b44 = 1;
}

class Unk_23ca848 : public Unk_23c9ab0 {
public:
    void vf4() override;
    void vf2() override;
    void vf3() override;
    void vf5() override;
    void vf6() override;
};

// 0x7100ae4f20
void Unk_23ca848::vf4() {}

// 0x7100ae4f30
void Unk_23ca848::vf5() {
    ::operator delete(this);
}

// 0x7100ae4f40
void Unk_23ca848::vf6() {
    field_8->field_b40 = 0;
}

class Unk_23ca890 : public Unk_23c9ab0 {
public:
    void vf4() override;
    void vf2() override;
    void vf3() override;
    void vf5() override;
    void vf6() override;
};

// 0x7100ae4fc0
void Unk_23ca890::vf4() {}

// 0x7100ae4fd0
void Unk_23ca890::vf5() {
    ::operator delete(this);
}

// 0x7100ae4fe0
void Unk_23ca890::vf6() {
    field_8->field_b40 = 1;
}

class Unk_23ca8d8 : public Unk_23c9ab0 {
public:
    void vf4() override;
    void vf2() override;
    void vf3() override;
    void vf5() override;
    void vf6() override;
};

// 0x7100ae5060
void Unk_23ca8d8::vf4() {}

// 0x7100ae5070
void Unk_23ca8d8::vf5() {
    ::operator delete(this);
}

// 0x7100ae5080
void Unk_23ca8d8::vf6() {
    field_8->field_b40 = 2;
}

class Unk_23ca920 : public Unk_23c9ab0 {
public:
    void vf4() override;
    void vf2() override;
    void vf3() override;
    void vf5() override;
    void vf6() override;
};

// 0x7100ae5100
void Unk_23ca920::vf4() {}

// 0x7100ae5110
void Unk_23ca920::vf5() {
    ::operator delete(this);
}

// 0x7100ae5120
void Unk_23ca920::vf6() {
    field_8->field_b40 = 0;
}

class Unk_23ca968 : public Unk_23c9ab0 {
public:
    void vf4() override;
    void vf2() override;
    void vf3() override;
    void vf5() override;
    void vf6() override;
};

// 0x7100ae51a0
void Unk_23ca968::vf4() {}

// 0x7100ae51b0
void Unk_23ca968::vf5() {
    ::operator delete(this);
}

// 0x7100ae51c0
void Unk_23ca968::vf6() {
    field_8->field_b40 = 1;
}

class Unk_23ca9b0 : public Unk_23c9ab0 {
public:
    void vf4() override;
    void vf2() override;
    void vf3() override;
    void vf5() override;
    void vf6() override;
};

// 0x7100ae5240
void Unk_23ca9b0::vf4() {}

// 0x7100ae5250
void Unk_23ca9b0::vf5() {
    ::operator delete(this);
}

// 0x7100ae5260
void Unk_23ca9b0::vf6() {
    field_8->field_b40 = 2;
}

class Unk_23ca9f8 : public Unk_23c9ab0 {
public:
    void vf4() override;
    void vf2() override;
    void vf3() override;
    void vf5() override;
    void vf6() override;
};

// 0x7100ae52e0
void Unk_23ca9f8::vf4() {}

// 0x7100ae52f0
void Unk_23ca9f8::vf5() {
    ::operator delete(this);
}

// 0x7100ae5300
void Unk_23ca9f8::vf6() {
    field_8->field_b40 = 0;
}

class Unk_23caa40 : public Unk_23c9ab0 {
public:
    void vf4() override;
    void vf2() override;
    void vf3() override;
    void vf5() override;
    void vf6() override;
};

// 0x7100ae5380
void Unk_23caa40::vf4() {}

// 0x7100ae5390
void Unk_23caa40::vf5() {
    ::operator delete(this);
}

// 0x7100ae53a0
void Unk_23caa40::vf6() {
    field_8->field_b40 = 1;
}

class Unk_23caa88 : public Unk_23c9ab0 {
public:
    void vf4() override;
    void vf2() override;
    void vf3() override;
    void vf5() override;
    void vf6() override;
};

// 0x7100ae5420
void Unk_23caa88::vf4() {}

// 0x7100ae5430
void Unk_23caa88::vf5() {
    ::operator delete(this);
}

// 0x7100ae5440
void Unk_23caa88::vf6() {
    field_8->field_b40 = 0;
}

class Unk_23caad0 : public Unk_23c9ab0 {
public:
    void vf4() override;
    void vf2() override;
    void vf3() override;
    void vf5() override;
    void vf6() override;
};

// 0x7100ae54c0
void Unk_23caad0::vf4() {}

// 0x7100ae54d0
void Unk_23caad0::vf5() {
    ::operator delete(this);
}

// 0x7100ae54e0
void Unk_23caad0::vf6() {
    field_8->field_b40 = 1;
}

class Unk_23cab18 : public Unk_23ca530 {
public:
    void vf4() override;
    void vf2() override;
    void vf3() override;
    void vf5() override;
    void vf6() override;
};

// 0x7100ae5560
void Unk_23cab18::vf4() {}

// 0x7100ae5570
void Unk_23cab18::vf5() {
    ::operator delete(this);
}

// 0x7100ae5580
void Unk_23cab18::vf6() {
    field_8->field_b44 = 1;
}

class Unk_23cab60 : public Unk_23ca530 {
public:
    void vf4() override;
    void vf2() override;
    void vf3() override;
    void vf5() override;
    void vf6() override;
};

// 0x7100ae5600
void Unk_23cab60::vf4() {}

// 0x7100ae5610
void Unk_23cab60::vf5() {
    ::operator delete(this);
}

// 0x7100ae5620
void Unk_23cab60::vf6() {
    field_8->field_b44 = 1;
}

class Unk_23caba8 : public Unk_23ca530 {
public:
    void vf4() override;
    void vf2() override;
    void vf3() override;
    void vf5() override;
    void vf6() override;
};

// 0x7100ae56a0
void Unk_23caba8::vf4() {}

// 0x7100ae56b0
void Unk_23caba8::vf5() {
    ::operator delete(this);
}

// 0x7100ae56c0
void Unk_23caba8::vf6() {
    field_8->field_b44 = 1;
}

class Unk_23cabf0 : public Unk_23ca530 {
public:
    void vf4() override;
    void vf2() override;
    void vf3() override;
    void vf5() override;
    void vf6() override;
};

// 0x7100ae5740
void Unk_23cabf0::vf4() {}

// 0x7100ae5750
void Unk_23cabf0::vf5() {
    ::operator delete(this);
}

// 0x7100ae5760
void Unk_23cabf0::vf6() {
    field_8->field_b44 = 1;
}

class Unk_23cac38 : public Unk_23ca530 {
public:
    void vf4() override;
    void vf2() override;
    void vf3() override;
    void vf5() override;
    void vf6() override;
};

// 0x7100ae57e0
void Unk_23cac38::vf4() {}

// 0x7100ae57f0
void Unk_23cac38::vf5() {
    ::operator delete(this);
}

// 0x7100ae5800
void Unk_23cac38::vf6() {
    field_8->field_b44 = 1;
}

class Unk_23cac80 : public Unk_23ca530 {
public:
    void vf4() override;
    void vf2() override;
    void vf3() override;
    void vf5() override;
    void vf6() override;
};

// 0x7100ae5880
void Unk_23cac80::vf4() {}

// 0x7100ae5890
void Unk_23cac80::vf5() {
    ::operator delete(this);
}

// 0x7100ae58a0
void Unk_23cac80::vf6() {
    field_8->field_b44 = 1;
}

class Unk_23cacc8 : public Unk_23ca530 {
public:
    void vf4() override;
    void vf2() override;
    void vf3() override;
    void vf5() override;
    void vf6() override;
};

// 0x7100ae5920
void Unk_23cacc8::vf4() {}

// 0x7100ae5930
void Unk_23cacc8::vf5() {
    ::operator delete(this);
}

// 0x7100ae5940
void Unk_23cacc8::vf6() {
    field_8->field_b44 = 1;
}

class Unk_23cad10 : public Unk_23ca530 {
public:
    void vf4() override;
    void vf2() override;
    void vf3() override;
    void vf5() override;
    void vf6() override;
};

// 0x7100ae59c0
void Unk_23cad10::vf4() {}

// 0x7100ae59d0
void Unk_23cad10::vf5() {
    ::operator delete(this);
}

// 0x7100ae59e0
void Unk_23cad10::vf6() {
    field_8->field_b44 = 1;
}

class Unk_23cad58 : public Unk_23ca530 {
public:
    void vf4() override;
    void vf2() override;
    void vf3() override;
    void vf5() override;
    void vf6() override;
};

// 0x7100ae5a60
void Unk_23cad58::vf4() {}

// 0x7100ae5a70
void Unk_23cad58::vf5() {
    ::operator delete(this);
}

// 0x7100ae5a80
void Unk_23cad58::vf6() {
    field_8->field_b44 = 1;
}

class Unk_23cada0 : public Unk_23ca530 {
public:
    void vf4() override;
    void vf2() override;
    void vf3() override;
    void vf5() override;
    void vf6() override;
};

// 0x7100ae5b00
void Unk_23cada0::vf4() {}

// 0x7100ae5b10
void Unk_23cada0::vf5() {
    ::operator delete(this);
}

// 0x7100ae5b20
void Unk_23cada0::vf6() {
    field_8->field_b44 = 1;
}

class Unk_23cade8 : public Unk_23ca530 {
public:
    void vf4() override;
    void vf2() override;
    void vf3() override;
    void vf5() override;
    void vf6() override;
};

// 0x7100ae5ba0
void Unk_23cade8::vf4() {}

// 0x7100ae5bb0
void Unk_23cade8::vf5() {
    ::operator delete(this);
}

// 0x7100ae5bc0
void Unk_23cade8::vf6() {
    field_8->field_b44 = 1;
}

class Unk_23cae30 : public Unk_23ca530 {
public:
    void vf4() override;
    void vf2() override;
    void vf3() override;
    void vf5() override;
    void vf6() override;
};

// 0x7100ae5c40
void Unk_23cae30::vf4() {}

// 0x7100ae5c50
void Unk_23cae30::vf5() {
    ::operator delete(this);
}

// 0x7100ae5c60
void Unk_23cae30::vf6() {
    field_8->field_b44 = 1;
}

class Unk_23cae78 : public Unk_23ca530 {
public:
    void vf4() override;
    void vf2() override;
    void vf3() override;
    void vf5() override;
    void vf6() override;
};

// 0x7100ae5ce0
void Unk_23cae78::vf4() {}

// 0x7100ae5cf0
void Unk_23cae78::vf5() {
    ::operator delete(this);
}

// 0x7100ae5d00
void Unk_23cae78::vf6() {
    field_8->field_b44 = 1;
}

class Unk_23caec0 : public Unk_23ca530 {
public:
    void vf4() override;
    void vf2() override;
    void vf3() override;
    void vf5() override;
    void vf6() override;
};

// 0x7100ae5d80
void Unk_23caec0::vf4() {}

// 0x7100ae5d90
void Unk_23caec0::vf5() {
    ::operator delete(this);
}

// 0x7100ae5da0
void Unk_23caec0::vf6() {
    field_8->field_b44 = 1;
}

class Unk_23caf08 : public Unk_23ca530 {
public:
    void vf4() override;
    void vf2() override;
    void vf3() override;
    void vf5() override;
    void vf6() override;
};

// 0x7100ae5e20
void Unk_23caf08::vf4() {}

// 0x7100ae5e30
void Unk_23caf08::vf5() {
    ::operator delete(this);
}

// 0x7100ae5e40
void Unk_23caf08::vf6() {
    field_8->field_b44 = 1;
}

class Unk_23caf50 : public Unk_23ca530 {
public:
    void vf4() override;
    void vf2() override;
    void vf3() override;
    void vf5() override;
    void vf6() override;
};

// 0x7100ae5ec0
void Unk_23caf50::vf4() {}

// 0x7100ae5ed0
void Unk_23caf50::vf5() {
    ::operator delete(this);
}

// 0x7100ae5ee0
void Unk_23caf50::vf6() {
    field_8->field_b44 = 1;
}

class Unk_23caf98 : public Unk_23ca530 {
public:
    void vf4() override;
    void vf2() override;
    void vf3() override;
    void vf5() override;
    void vf6() override;
};

// 0x7100ae5f60
void Unk_23caf98::vf4() {}

// 0x7100ae5f70
void Unk_23caf98::vf5() {
    ::operator delete(this);
}

// 0x7100ae5f80
void Unk_23caf98::vf6() {
    field_8->field_b44 = 1;
}

class Unk_23cafe0 : public Unk_23ca530 {
public:
    void vf4() override;
    void vf2() override;
    void vf3() override;
    void vf5() override;
    void vf6() override;
};

// 0x7100ae6000
void Unk_23cafe0::vf4() {}

// 0x7100ae6010
void Unk_23cafe0::vf5() {
    ::operator delete(this);
}

// 0x7100ae6020
void Unk_23cafe0::vf6() {
    field_8->field_b44 = 1;
}

class Unk_23cb028 : public Unk_23ca530 {
public:
    void vf4() override;
    void vf2() override;
    void vf3() override;
    void vf5() override;
    void vf6() override;
};

// 0x7100ae60a0
void Unk_23cb028::vf4() {}

// 0x7100ae60b0
void Unk_23cb028::vf5() {
    ::operator delete(this);
}

// 0x7100ae60c0
void Unk_23cb028::vf6() {
    field_8->field_b44 = 1;
}

class Unk_23cb070 : public Unk_23ca530 {
public:
    void vf4() override;
    void vf2() override;
    void vf3() override;
    void vf5() override;
    void vf6() override;
};

// 0x7100ae6140
void Unk_23cb070::vf4() {}

// 0x7100ae6150
void Unk_23cb070::vf5() {
    ::operator delete(this);
}

// 0x7100ae6160
void Unk_23cb070::vf6() {
    field_8->field_b44 = 1;
}

class Unk_23cb0b8 : public Unk_23c9ab0 {
public:
    void vf4() override;
    void vf2() override;
    void vf3() override;
    void vf5() override;
    void vf6() override;
};

// 0x7100ae61e0
void Unk_23cb0b8::vf4() {}

// 0x7100ae61f0
void Unk_23cb0b8::vf5() {
    ::operator delete(this);
}

// 0x7100ae6200
void Unk_23cb0b8::vf6() {
    field_8->field_b40 = 0;
}

class Unk_23cb100 : public Unk_23c9ab0 {
public:
    void vf4() override;
    void vf2() override;
    void vf3() override;
    void vf5() override;
    void vf6() override;
};

// 0x7100ae6280
void Unk_23cb100::vf4() {}

// 0x7100ae6290
void Unk_23cb100::vf5() {
    ::operator delete(this);
}

// 0x7100ae62a0
void Unk_23cb100::vf6() {
    field_8->field_b40 = 1;
}

class Unk_23cb148 : public Unk_23c9ab0 {
public:
    void vf4() override;
    void vf2() override;
    void vf3() override;
    void vf5() override;
    void vf6() override;
};

// 0x7100ae6320
void Unk_23cb148::vf4() {}

// 0x7100ae6330
void Unk_23cb148::vf5() {
    ::operator delete(this);
}

// 0x7100ae6340
void Unk_23cb148::vf6() {
    field_8->field_b40 = 0;
}

class Unk_23cb190 : public Unk_23c9ab0 {
public:
    void vf4() override;
    void vf2() override;
    void vf3() override;
    void vf5() override;
    void vf6() override;
};

// 0x7100ae63c0
void Unk_23cb190::vf4() {}

// 0x7100ae63d0
void Unk_23cb190::vf5() {
    ::operator delete(this);
}

// 0x7100ae63e0
void Unk_23cb190::vf6() {
    field_8->field_b40 = 1;
}

class Unk_23cb1d8 : public Unk_23ca530 {
public:
    void vf4() override;
    void vf2() override;
    void vf3() override;
    void vf5() override;
    void vf6() override;
};

// 0x7100ae6460
void Unk_23cb1d8::vf4() {}

// 0x7100ae6470
void Unk_23cb1d8::vf5() {
    ::operator delete(this);
}

// 0x7100ae6480
void Unk_23cb1d8::vf6() {
    field_8->field_b44 = 1;
}

class Unk_23cb220 : public Unk_23ca530 {
public:
    void vf4() override;
    void vf2() override;
    void vf3() override;
    void vf5() override;
    void vf6() override;
};

// 0x7100ae6500
void Unk_23cb220::vf4() {}

// 0x7100ae6510
void Unk_23cb220::vf5() {
    ::operator delete(this);
}

// 0x7100ae6520
void Unk_23cb220::vf6() {
    field_8->field_b44 = 1;
}

class Unk_23cb268 : public Unk_23ca530 {
public:
    void vf4() override;
    void vf2() override;
    void vf3() override;
    void vf5() override;
    void vf6() override;
};

// 0x7100ae65a0
void Unk_23cb268::vf4() {}

// 0x7100ae65b0
void Unk_23cb268::vf5() {
    ::operator delete(this);
}

// 0x7100ae65c0
void Unk_23cb268::vf6() {
    field_8->field_b44 = 1;
}

class Unk_23cb2b0 : public Unk_23ca530 {
public:
    void vf4() override;
    void vf2() override;
    void vf3() override;
    void vf5() override;
    void vf6() override;
};

// 0x7100ae6640
void Unk_23cb2b0::vf4() {}

// 0x7100ae6650
void Unk_23cb2b0::vf5() {
    ::operator delete(this);
}

// 0x7100ae6660
void Unk_23cb2b0::vf6() {
    field_8->field_b44 = 1;
}

class Unk_23cb2f8 : public Unk_23ca530 {
public:
    void vf4() override;
    void vf2() override;
    void vf3() override;
    void vf5() override;
    void vf6() override;
};

// 0x7100ae66e0
void Unk_23cb2f8::vf4() {}

// 0x7100ae66f0
void Unk_23cb2f8::vf5() {
    ::operator delete(this);
}

// 0x7100ae6700
void Unk_23cb2f8::vf6() {
    field_8->field_b44 = 1;
}

class Unk_23cb340 : public Unk_23ca530 {
public:
    void vf4() override;
    void vf2() override;
    void vf3() override;
    void vf5() override;
    void vf6() override;
};

// 0x7100ae6780
void Unk_23cb340::vf4() {}

// 0x7100ae6790
void Unk_23cb340::vf5() {
    ::operator delete(this);
}

// 0x7100ae67a0
void Unk_23cb340::vf6() {
    field_8->field_b44 = 1;
}

class Unk_23cb388 : public Unk_23ca530 {
public:
    void vf4() override;
    void vf2() override;
    void vf3() override;
    void vf5() override;
    void vf6() override;
};

// 0x7100ae6820
void Unk_23cb388::vf4() {}

// 0x7100ae6830
void Unk_23cb388::vf5() {
    ::operator delete(this);
}

// 0x7100ae6840
void Unk_23cb388::vf6() {
    field_8->field_b44 = 1;
}

class Unk_23cb3d0 : public Unk_23ca530 {
public:
    void vf4() override;
    void vf2() override;
    void vf3() override;
    void vf5() override;
    void vf6() override;
};

// 0x7100ae68c0
void Unk_23cb3d0::vf4() {}

// 0x7100ae68d0
void Unk_23cb3d0::vf5() {
    ::operator delete(this);
}

// 0x7100ae68e0
void Unk_23cb3d0::vf6() {
    field_8->field_b44 = 1;
}

class Unk_23cb418 : public Unk_23ca530 {
public:
    void vf4() override;
    void vf2() override;
    void vf3() override;
    void vf5() override;
    void vf6() override;
};

// 0x7100ae6960
void Unk_23cb418::vf4() {}

// 0x7100ae6970
void Unk_23cb418::vf5() {
    ::operator delete(this);
}

// 0x7100ae6980
void Unk_23cb418::vf6() {
    field_8->field_b44 = 1;
}

class Unk_23cb460 : public Unk_23ca530 {
public:
    void vf4() override;
    void vf2() override;
    void vf3() override;
    void vf5() override;
    void vf6() override;
};

// 0x7100ae6a00
void Unk_23cb460::vf4() {}

// 0x7100ae6a10
void Unk_23cb460::vf5() {
    ::operator delete(this);
}

// 0x7100ae6a20
void Unk_23cb460::vf6() {
    field_8->field_b44 = 1;
}

class Unk_23cb4a8 : public Unk_23ca530 {
public:
    void vf4() override;
    void vf2() override;
    void vf3() override;
    void vf5() override;
    void vf6() override;
};

// 0x7100ae6aa0
void Unk_23cb4a8::vf4() {}

// 0x7100ae6ab0
void Unk_23cb4a8::vf5() {
    ::operator delete(this);
}

// 0x7100ae6ac0
void Unk_23cb4a8::vf6() {
    field_8->field_b44 = 1;
}

class Unk_23cb4f0 : public Unk_23c9ab0 {
public:
    void vf4() override;
    void vf2() override;
    void vf3() override;
    void vf5() override;
    void vf6() override;
};

// 0x7100ae6b40
void Unk_23cb4f0::vf4() {}

// 0x7100ae6b50
void Unk_23cb4f0::vf5() {
    ::operator delete(this);
}

// 0x7100ae6b60
void Unk_23cb4f0::vf6() {
    field_8->field_b40 = 0;
}

class Unk_23cb538 : public Unk_23c9ab0 {
public:
    void vf4() override;
    void vf2() override;
    void vf3() override;
    void vf5() override;
    void vf6() override;
};

// 0x7100ae6be0
void Unk_23cb538::vf4() {}

// 0x7100ae6bf0
void Unk_23cb538::vf5() {
    ::operator delete(this);
}

// 0x7100ae6c00
void Unk_23cb538::vf6() {
    field_8->field_b40 = 1;
}

class Unk_23cb580 : public Unk_23c9ab0 {
public:
    void vf4() override;
    void vf2() override;
    void vf3() override;
    void vf5() override;
    void vf6() override;
};

// 0x7100ae6c80
void Unk_23cb580::vf4() {}

// 0x7100ae6c90
void Unk_23cb580::vf5() {
    ::operator delete(this);
}

// 0x7100ae6ca0
void Unk_23cb580::vf6() {
    field_8->field_b40 = 0;
}

class Unk_23cb5c8 : public Unk_23c9ab0 {
public:
    void vf4() override;
    void vf2() override;
    void vf3() override;
    void vf5() override;
    void vf6() override;
};

// 0x7100ae6d20
void Unk_23cb5c8::vf4() {}

// 0x7100ae6d30
void Unk_23cb5c8::vf5() {
    ::operator delete(this);
}

// 0x7100ae6d40
void Unk_23cb5c8::vf6() {
    field_8->field_b40 = 1;
}

class Unk_23cb610 : public Unk_23c9ab0 {
public:
    void vf4() override;
    void vf2() override;
    void vf3() override;
    void vf5() override;
    void vf6() override;
};

// 0x7100ae6dc0
void Unk_23cb610::vf4() {}

// 0x7100ae6dd0
void Unk_23cb610::vf5() {
    ::operator delete(this);
}

// 0x7100ae6de0
void Unk_23cb610::vf6() {
    field_8->field_b40 = 2;
}

class Unk_23cb658 : public Unk_23ca530 {
public:
    void vf4() override;
    void vf2() override;
    void vf3() override;
    void vf5() override;
    void vf6() override;
};

// 0x7100ae6e60
void Unk_23cb658::vf4() {}

// 0x7100ae6e70
void Unk_23cb658::vf5() {
    ::operator delete(this);
}

// 0x7100ae6e80
void Unk_23cb658::vf6() {
    field_8->field_b44 = 1;
}

class Unk_23cb6a0 : public Unk_23ca530 {
public:
    void vf4() override;
    void vf2() override;
    void vf3() override;
    void vf5() override;
    void vf6() override;
};

// 0x7100ae6f00
void Unk_23cb6a0::vf4() {}

// 0x7100ae6f10
void Unk_23cb6a0::vf5() {
    ::operator delete(this);
}

// 0x7100ae6f20
void Unk_23cb6a0::vf6() {
    field_8->field_b44 = 1;
}

class Unk_23cb6e8 : public Unk_23c9ab0 {
public:
    void vf4() override;
    void vf2() override;
    void vf3() override;
    void vf5() override;
    void vf6() override;
};

// 0x7100ae6fa0
void Unk_23cb6e8::vf4() {}

// 0x7100ae6fb0
void Unk_23cb6e8::vf5() {
    ::operator delete(this);
}

// 0x7100ae6fc0
void Unk_23cb6e8::vf6() {
    field_8->field_b40 = 0;
}

class Unk_23cb730 : public Unk_23c9ab0 {
public:
    void vf4() override;
    void vf2() override;
    void vf3() override;
    void vf5() override;
    void vf6() override;
};

// 0x7100ae7040
void Unk_23cb730::vf4() {}

// 0x7100ae7050
void Unk_23cb730::vf5() {
    ::operator delete(this);
}

// 0x7100ae7060
void Unk_23cb730::vf6() {
    field_8->field_b40 = 1;
}

class Unk_23cb778 : public Unk_23ca530 {
public:
    void vf4() override;
    void vf2() override;
    void vf3() override;
    void vf5() override;
    void vf6() override;
};

// 0x7100ae70e0
void Unk_23cb778::vf4() {}

// 0x7100ae70f0
void Unk_23cb778::vf5() {
    ::operator delete(this);
}

// 0x7100ae7100
void Unk_23cb778::vf6() {
    field_8->field_b44 = 1;
}

class Unk_23cb7c0 : public Unk_23ca530 {
public:
    void vf4() override;
    void vf2() override;
    void vf3() override;
    void vf5() override;
    void vf6() override;
};

// 0x7100ae7180
void Unk_23cb7c0::vf4() {}

// 0x7100ae7190
void Unk_23cb7c0::vf5() {
    ::operator delete(this);
}

// 0x7100ae71a0
void Unk_23cb7c0::vf6() {
    field_8->field_b44 = 1;
}

class Unk_23cb808 : public Unk_23ca530 {
public:
    void vf4() override;
    void vf2() override;
    void vf3() override;
    void vf5() override;
    void vf6() override;
};

// 0x7100ae7230
void Unk_23cb808::vf4() {}

// 0x7100ae7240
void Unk_23cb808::vf5() {
    ::operator delete(this);
}

// 0x7100ae7250
void Unk_23cb808::vf6() {
    field_8->field_b44 = 1;
}

class Unk_23cb850 : public Unk_23ca530 {
public:
    void vf4() override;
    void vf2() override;
    void vf3() override;
    void vf5() override;
    void vf6() override;
};

// 0x7100ae72d0
void Unk_23cb850::vf4() {}

// 0x7100ae72e0
void Unk_23cb850::vf5() {
    ::operator delete(this);
}

// 0x7100ae72f0
void Unk_23cb850::vf6() {
    field_8->field_b44 = 1;
}

class Unk_23cb898 : public Unk_23ca530 {
public:
    void vf4() override;
    void vf2() override;
    void vf3() override;
    void vf5() override;
    void vf6() override;
};

// 0x7100ae7370
void Unk_23cb898::vf4() {}

// 0x7100ae7380
void Unk_23cb898::vf5() {
    ::operator delete(this);
}

// 0x7100ae7390
void Unk_23cb898::vf6() {
    field_8->field_b44 = 1;
}

class Unk_23cb8e0 : public Unk_23ca530 {
public:
    void vf4() override;
    void vf2() override;
    void vf3() override;
    void vf5() override;
    void vf6() override;
};

// 0x7100ae7410
void Unk_23cb8e0::vf4() {}

// 0x7100ae7420
void Unk_23cb8e0::vf5() {
    ::operator delete(this);
}

// 0x7100ae7430
void Unk_23cb8e0::vf6() {
    field_8->field_b44 = 1;
}

class Unk_23cb928 : public Unk_23ca530 {
public:
    void vf4() override;
    void vf2() override;
    void vf3() override;
    void vf5() override;
    void vf6() override;
};

// 0x7100ae74b0
void Unk_23cb928::vf4() {}

// 0x7100ae74c0
void Unk_23cb928::vf5() {
    ::operator delete(this);
}

// 0x7100ae74d0
void Unk_23cb928::vf6() {
    field_8->field_b44 = 1;
}

class Unk_23cb970 : public Unk_23ca530 {
public:
    void vf4() override;
    void vf2() override;
    void vf3() override;
    void vf5() override;
    void vf6() override;
};

// 0x7100ae7550
void Unk_23cb970::vf4() {}

// 0x7100ae7560
void Unk_23cb970::vf5() {
    ::operator delete(this);
}

// 0x7100ae7570
void Unk_23cb970::vf6() {
    field_8->field_b44 = 1;
}

class Unk_23cb9b8 : public Unk_23ca530 {
public:
    void vf4() override;
    void vf2() override;
    void vf3() override;
    void vf5() override;
    void vf6() override;
};

// 0x7100ae75f0
void Unk_23cb9b8::vf4() {}

// 0x7100ae7600
void Unk_23cb9b8::vf5() {
    ::operator delete(this);
}

// 0x7100ae7610
void Unk_23cb9b8::vf6() {
    field_8->field_b44 = 1;
}

class Unk_23cba00 : public Unk_23ca530 {
public:
    void vf4() override;
    void vf2() override;
    void vf3() override;
    void vf5() override;
    void vf6() override;
};

// 0x7100ae7690
void Unk_23cba00::vf4() {}

// 0x7100ae76a0
void Unk_23cba00::vf5() {
    ::operator delete(this);
}

// 0x7100ae76b0
void Unk_23cba00::vf6() {
    field_8->field_b44 = 1;
}

class Unk_23cba48 : public Unk_23ca530 {
public:
    void vf4() override;
    void vf2() override;
    void vf3() override;
    void vf5() override;
    void vf6() override;
};

// 0x7100ae7730
void Unk_23cba48::vf4() {}

// 0x7100ae7740
void Unk_23cba48::vf5() {
    ::operator delete(this);
}

// 0x7100ae7750
void Unk_23cba48::vf6() {
    field_8->field_b44 = 1;
}

class Unk_23cba90 : public Unk_23ca530 {
public:
    void vf4() override;
    void vf2() override;
    void vf3() override;
    void vf5() override;
    void vf6() override;
};

// 0x7100ae77d0
void Unk_23cba90::vf4() {}

// 0x7100ae77e0
void Unk_23cba90::vf5() {
    ::operator delete(this);
}

// 0x7100ae77f0
void Unk_23cba90::vf6() {
    field_8->field_b44 = 1;
}

class Unk_23cbcf0 : public Unk_23c98b0 {
public:
    void vf4() override;
    void vf2() override;
    void vf3() override;
    void vf5() override;
    void vf6() override;
};

// 0x7100ae8e80
void Unk_23cbcf0::vf4() {}

// 0x7100ae8e90
void Unk_23cbcf0::vf5() {
    ::operator delete(this);
}

class Unk_23cbd38 : public Unk_23c98b0 {
public:
    void vf4() override;
    void vf2() override;
    void vf3() override;
    void vf5() override;
    void vf6() override;
};

// 0x7100ae8f70
void Unk_23cbd38::vf4() {}

// 0x7100ae8f80
void Unk_23cbd38::vf5() {
    ::operator delete(this);
}

class Unk_23cbd80 : public Unk_23c98b0 {
public:
    void vf4() override;
    void vf2() override;
    void vf3() override;
    void vf5() override;
    void vf6() override;
};

// 0x7100ae9060
void Unk_23cbd80::vf4() {}

// 0x7100ae9070
void Unk_23cbd80::vf5() {
    ::operator delete(this);
}

class Unk_23cbf50 : public Unk_23c98b0 {
public:
    void vf4() override;
    void vf2() override;
    void vf3() override;
    void vf5() override;
    void vf6() override;
};

// 0x7100aeb150
void Unk_23cbf50::vf4() {}

// 0x7100aeb160
void Unk_23cbf50::vf5() {
    ::operator delete(this);
}

class Unk_23cbf98 : public Unk_23c98b0 {
public:
    void vf4() override;
    void vf2() override;
    void vf3() override;
    void vf5() override;
    void vf6() override;
};

// 0x7100aeb240
void Unk_23cbf98::vf4() {}

// 0x7100aeb250
void Unk_23cbf98::vf5() {
    ::operator delete(this);
}

class Unk_23cbfe0 : public Unk_23c98b0 {
public:
    void vf4() override;
    void vf2() override;
    void vf3() override;
    void vf5() override;
    void vf6() override;
};

// 0x7100aeb330
void Unk_23cbfe0::vf4() {}

// 0x7100aeb340
void Unk_23cbfe0::vf5() {
    ::operator delete(this);
}

class Unk_23cc028 : public Unk_23c98b0 {
public:
    void vf4() override;
    void vf2() override;
    void vf3() override;
    void vf5() override;
    void vf6() override;
};

// 0x7100aeb420
void Unk_23cc028::vf4() {}

// 0x7100aeb430
void Unk_23cc028::vf5() {
    ::operator delete(this);
}

class Unk_23cc070 : public Unk_23c98b0 {
public:
    void vf4() override;
    void vf2() override;
    void vf3() override;
    void vf5() override;
    void vf6() override;
};

// 0x7100aeb510
void Unk_23cc070::vf4() {}

// 0x7100aeb520
void Unk_23cc070::vf5() {
    ::operator delete(this);
}

class Unk_23cc0b8 : public Unk_23c98b0 {
public:
    void vf4() override;
    void vf2() override;
    void vf3() override;
    void vf5() override;
    void vf6() override;
};

// 0x7100aeb600
void Unk_23cc0b8::vf4() {}

// 0x7100aeb610
void Unk_23cc0b8::vf5() {
    ::operator delete(this);
}

class Unk_23cc100 : public Unk_23c98b0 {
public:
    void vf4() override;
    void vf2() override;
    void vf3() override;
    void vf5() override;
    void vf6() override;
};

// 0x7100aeb6f0
void Unk_23cc100::vf4() {}

// 0x7100aeb700
void Unk_23cc100::vf5() {
    ::operator delete(this);
}

class Unk_23cc288 : public Unk_23c98b0 {
public:
    void vf4() override;
    void vf2() override;
    void vf3() override;
    void vf5() override;
    void vf6() override;
};

// 0x7100aed340
void Unk_23cc288::vf4() {}

// 0x7100aed350
void Unk_23cc288::vf5() {
    ::operator delete(this);
}

class Unk_23cc2d0 : public Unk_23c98b0 {
public:
    void vf4() override;
    void vf2() override;
    void vf3() override;
    void vf5() override;
    void vf6() override;
};

// 0x7100aed430
void Unk_23cc2d0::vf4() {}

// 0x7100aed440
void Unk_23cc2d0::vf5() {
    ::operator delete(this);
}

class Unk_23cc318 : public Unk_23c98b0 {
public:
    void vf4() override;
    void vf2() override;
    void vf3() override;
    void vf5() override;
    void vf6() override;
};

// 0x7100aed760
void Unk_23cc318::vf4() {}

// 0x7100aed770
void Unk_23cc318::vf5() {
    ::operator delete(this);
}

class Unk_23cc360 : public Unk_23c98b0 {
public:
    void vf4() override;
    void vf2() override;
    void vf3() override;
    void vf5() override;
    void vf6() override;
};

// 0x7100aed850
void Unk_23cc360::vf4() {}

// 0x7100aed860
void Unk_23cc360::vf5() {
    ::operator delete(this);
}

class Unk_23cc3a8 : public Unk_23c98b0 {
public:
    void vf4() override;
    void vf2() override;
    void vf3() override;
    void vf5() override;
    void vf6() override;
};

// 0x7100aed940
void Unk_23cc3a8::vf4() {}

// 0x7100aed950
void Unk_23cc3a8::vf5() {
    ::operator delete(this);
}

class Unk_23cc3f0 : public Unk_23c98b0 {
public:
    void vf4() override;
    void vf2() override;
    void vf3() override;
    void vf5() override;
    void vf6() override;
};

// 0x7100aeda30
void Unk_23cc3f0::vf4() {}

// 0x7100aeda40
void Unk_23cc3f0::vf5() {
    ::operator delete(this);
}

class Unk_23cc438 : public Unk_23c98b0 {
public:
    void vf4() override;
    void vf2() override;
    void vf3() override;
    void vf5() override;
    void vf6() override;
};

// 0x7100aedb20
void Unk_23cc438::vf4() {}

// 0x7100aedb30
void Unk_23cc438::vf5() {
    ::operator delete(this);
}

class Unk_23cc480 : public Unk_23c98b0 {
public:
    void vf4() override;
    void vf2() override;
    void vf3() override;
    void vf5() override;
    void vf6() override;
};

// 0x7100aedc10
void Unk_23cc480::vf4() {}

// 0x7100aedc20
void Unk_23cc480::vf5() {
    ::operator delete(this);
}

class Unk_23cc4c8 : public Unk_23c98b0 {
public:
    void vf4() override;
    void vf2() override;
    void vf3() override;
    void vf5() override;
    void vf6() override;
};

// 0x7100aedd00
void Unk_23cc4c8::vf4() {}

// 0x7100aedd10
void Unk_23cc4c8::vf5() {
    ::operator delete(this);
}

class Unk_23cc510 : public Unk_23c98b0 {
public:
    void vf4() override;
    void vf2() override;
    void vf3() override;
    void vf5() override;
    void vf6() override;
};

// 0x7100aedec0
void Unk_23cc510::vf4() {}

// 0x7100aeded0
void Unk_23cc510::vf5() {
    ::operator delete(this);
}

class Unk_23cc558 : public Unk_23c98b0 {
public:
    void vf4() override;
    void vf2() override;
    void vf3() override;
    void vf5() override;
    void vf6() override;
};

// 0x7100aedfb0
void Unk_23cc558::vf4() {}

// 0x7100aedfc0
void Unk_23cc558::vf5() {
    ::operator delete(this);
}

class Unk_23cc6c8 : public Unk_23c98b0 {
public:
    void vf4() override;
    void vf2() override;
    void vf3() override;
    void vf5() override;
    void vf6() override;
};

// 0x7100aefe90
void Unk_23cc6c8::vf4() {}

// 0x7100aefea0
void Unk_23cc6c8::vf5() {
    ::operator delete(this);
}

class Unk_23cc710 : public Unk_23c98b0 {
public:
    void vf4() override;
    void vf2() override;
    void vf3() override;
    void vf5() override;
    void vf6() override;
};

// 0x7100aeff80
void Unk_23cc710::vf4() {}

// 0x7100aeff90
void Unk_23cc710::vf5() {
    ::operator delete(this);
}

class Unk_23cc758 : public Unk_23c98b0 {
public:
    void vf4() override;
    void vf2() override;
    void vf3() override;
    void vf5() override;
    void vf6() override;
};

// 0x7100af0070
void Unk_23cc758::vf4() {}

// 0x7100af0080
void Unk_23cc758::vf5() {
    ::operator delete(this);
}

class Unk_23cc8e0 : public Unk_23c98b0 {
public:
    void vf4() override;
    void vf2() override;
    void vf3() override;
    void vf5() override;
    void vf6() override;
};

// 0x7100af1ea0
void Unk_23cc8e0::vf4() {}

// 0x7100af1eb0
void Unk_23cc8e0::vf5() {
    ::operator delete(this);
}

class Unk_23cc928 : public Unk_23c98b0 {
public:
    void vf4() override;
    void vf2() override;
    void vf3() override;
    void vf5() override;
    void vf6() override;
};

// 0x7100af1f90
void Unk_23cc928::vf4() {}

// 0x7100af1fa0
void Unk_23cc928::vf5() {
    ::operator delete(this);
}

class Unk_23cc970 : public Unk_23c98b0 {
public:
    void vf4() override;
    void vf2() override;
    void vf3() override;
    void vf5() override;
    void vf6() override;
};

// 0x7100af2080
void Unk_23cc970::vf4() {}

// 0x7100af2090
void Unk_23cc970::vf5() {
    ::operator delete(this);
}

class Unk_23cc9b8 : public Unk_23c98b0 {
public:
    void vf4() override;
    void vf2() override;
    void vf3() override;
    void vf5() override;
    void vf6() override;
};

// 0x7100af2170
void Unk_23cc9b8::vf4() {}

// 0x7100af2180
void Unk_23cc9b8::vf5() {
    ::operator delete(this);
}

class Unk_23cca00 : public Unk_23c98b0 {
public:
    void vf4() override;
    void vf2() override;
    void vf3() override;
    void vf5() override;
    void vf6() override;
};

// 0x7100af2260
void Unk_23cca00::vf4() {}

// 0x7100af2270
void Unk_23cca00::vf5() {
    ::operator delete(this);
}

class Unk_23cca48 : public Unk_23c98b0 {
public:
    void vf4() override;
    void vf2() override;
    void vf3() override;
    void vf5() override;
    void vf6() override;
};

// 0x7100af2350
void Unk_23cca48::vf4() {}

// 0x7100af2360
void Unk_23cca48::vf5() {
    ::operator delete(this);
}

class Unk_23cca90 : public Unk_23c98b0 {
public:
    void vf4() override;
    void vf2() override;
    void vf3() override;
    void vf5() override;
    void vf6() override;
};

// 0x7100af2440
void Unk_23cca90::vf4() {}

// 0x7100af2450
void Unk_23cca90::vf5() {
    ::operator delete(this);
}

class Unk_23ccad8 : public Unk_23c98b0 {
public:
    void vf4() override;
    void vf2() override;
    void vf3() override;
    void vf5() override;
    void vf6() override;
};

// 0x7100af2530
void Unk_23ccad8::vf4() {}

// 0x7100af2540
void Unk_23ccad8::vf5() {
    ::operator delete(this);
}

class Unk_23ccb20 : public Unk_23c98b0 {
public:
    void vf4() override;
    void vf2() override;
    void vf3() override;
    void vf5() override;
    void vf6() override;
};

// 0x7100af2620
void Unk_23ccb20::vf4() {}

// 0x7100af2630
void Unk_23ccb20::vf5() {
    ::operator delete(this);
}

class Unk_23ccb68 : public Unk_23c98b0 {
public:
    void vf4() override;
    void vf2() override;
    void vf3() override;
    void vf5() override;
    void vf6() override;
};

// 0x7100af2710
void Unk_23ccb68::vf4() {}

// 0x7100af2720
void Unk_23ccb68::vf5() {
    ::operator delete(this);
}

class Unk_23ccbb0 : public Unk_23c98b0 {
public:
    void vf4() override;
    void vf2() override;
    void vf3() override;
    void vf5() override;
    void vf6() override;
};

// 0x7100af2800
void Unk_23ccbb0::vf4() {}

// 0x7100af2810
void Unk_23ccbb0::vf5() {
    ::operator delete(this);
}

class Unk_23ccbf8 : public Unk_23c98b0 {
public:
    void vf4() override;
    void vf2() override;
    void vf3() override;
    void vf5() override;
    void vf6() override;
};

// 0x7100af28f0
void Unk_23ccbf8::vf4() {}

// 0x7100af2900
void Unk_23ccbf8::vf5() {
    ::operator delete(this);
}

class Unk_23ccc40 : public Unk_23c98b0 {
public:
    void vf4() override;
    void vf2() override;
    void vf3() override;
    void vf5() override;
    void vf6() override;
};

// 0x7100af29e0
void Unk_23ccc40::vf4() {}

// 0x7100af29f0
void Unk_23ccc40::vf5() {
    ::operator delete(this);
}

class Unk_23ccc88 : public Unk_23c98b0 {
public:
    void vf4() override;
    void vf2() override;
    void vf3() override;
    void vf5() override;
    void vf6() override;
};

// 0x7100af2ad0
void Unk_23ccc88::vf4() {}

// 0x7100af2ae0
void Unk_23ccc88::vf5() {
    ::operator delete(this);
}

class Unk_23cccd0 : public Unk_23c98b0 {
public:
    void vf4() override;
    void vf2() override;
    void vf3() override;
    void vf5() override;
    void vf6() override;
};

// 0x7100af2bc0
void Unk_23cccd0::vf4() {}

// 0x7100af2bd0
void Unk_23cccd0::vf5() {
    ::operator delete(this);
}

class Unk_23ccd18 : public Unk_23c98b0 {
public:
    void vf4() override;
    void vf2() override;
    void vf3() override;
    void vf5() override;
    void vf6() override;
};

// 0x7100af2cb0
void Unk_23ccd18::vf4() {}

// 0x7100af2cc0
void Unk_23ccd18::vf5() {
    ::operator delete(this);
}

class Unk_23cce88 : public Unk_23c98b0 {
public:
    void vf4() override;
    void vf2() override;
    void vf3() override;
    void vf5() override;
    void vf6() override;
};

// 0x7100af5a30
void Unk_23cce88::vf4() {}

// 0x7100af5a40
void Unk_23cce88::vf5() {
    ::operator delete(this);
}

class Unk_23cced0 : public Unk_23c98b0 {
public:
    void vf4() override;
    void vf2() override;
    void vf3() override;
    void vf5() override;
    void vf6() override;
};

// 0x7100af5b20
void Unk_23cced0::vf4() {}

// 0x7100af5b30
void Unk_23cced0::vf5() {
    ::operator delete(this);
}

class Unk_23ccf18 : public Unk_23c98b0 {
public:
    void vf4() override;
    void vf2() override;
    void vf3() override;
    void vf5() override;
    void vf6() override;
};

// 0x7100af6190
void Unk_23ccf18::vf4() {}

// 0x7100af61a0
void Unk_23ccf18::vf5() {
    ::operator delete(this);
}

class Unk_23ccf60 : public Unk_23c98b0 {
public:
    void vf4() override;
    void vf2() override;
    void vf3() override;
    void vf5() override;
    void vf6() override;
};

// 0x7100af6280
void Unk_23ccf60::vf4() {}

// 0x7100af6290
void Unk_23ccf60::vf5() {
    ::operator delete(this);
}

class Unk_23ccfa8 : public Unk_23c98b0 {
public:
    void vf4() override;
    void vf2() override;
    void vf3() override;
    void vf5() override;
    void vf6() override;
};

// 0x7100af6370
void Unk_23ccfa8::vf4() {}

// 0x7100af6380
void Unk_23ccfa8::vf5() {
    ::operator delete(this);
}

class Unk_23ccff0 : public Unk_23c98b0 {
public:
    void vf4() override;
    void vf2() override;
    void vf3() override;
    void vf5() override;
    void vf6() override;
};

// 0x7100af6460
void Unk_23ccff0::vf4() {}

// 0x7100af6470
void Unk_23ccff0::vf5() {
    ::operator delete(this);
}

class Unk_23cd038 : public Unk_23c98b0 {
public:
    void vf4() override;
    void vf2() override;
    void vf3() override;
    void vf5() override;
    void vf6() override;
};

// 0x7100af6550
void Unk_23cd038::vf4() {}

// 0x7100af6560
void Unk_23cd038::vf5() {
    ::operator delete(this);
}

class Unk_23cd080 : public Unk_23c98b0 {
public:
    void vf4() override;
    void vf2() override;
    void vf3() override;
    void vf5() override;
    void vf6() override;
};

// 0x7100af6640
void Unk_23cd080::vf4() {}

// 0x7100af6650
void Unk_23cd080::vf5() {
    ::operator delete(this);
}

class Unk_23cd0c8 : public Unk_23c98b0 {
public:
    void vf4() override;
    void vf2() override;
    void vf3() override;
    void vf5() override;
    void vf6() override;
};

// 0x7100af6730
void Unk_23cd0c8::vf4() {}

// 0x7100af6740
void Unk_23cd0c8::vf5() {
    ::operator delete(this);
}

class Unk_23cd110 : public Unk_23c98b0 {
public:
    void vf4() override;
    void vf2() override;
    void vf3() override;
    void vf5() override;
    void vf6() override;
};

// 0x7100af6820
void Unk_23cd110::vf4() {}

// 0x7100af6830
void Unk_23cd110::vf5() {
    ::operator delete(this);
}

class Unk_23cd158 : public Unk_23c98b0 {
public:
    void vf4() override;
    void vf2() override;
    void vf3() override;
    void vf5() override;
    void vf6() override;
};

// 0x7100af6910
void Unk_23cd158::vf4() {}

// 0x7100af6920
void Unk_23cd158::vf5() {
    ::operator delete(this);
}

class Unk_23cd1a0 : public Unk_23c98b0 {
public:
    void vf4() override;
    void vf2() override;
    void vf3() override;
    void vf5() override;
    void vf6() override;
};

// 0x7100af6a00
void Unk_23cd1a0::vf4() {}

// 0x7100af6a10
void Unk_23cd1a0::vf5() {
    ::operator delete(this);
}

class Unk_23cd1e8 : public Unk_23c98b0 {
public:
    void vf4() override;
    void vf2() override;
    void vf3() override;
    void vf5() override;
    void vf6() override;
};

// 0x7100af6af0
void Unk_23cd1e8::vf4() {}

// 0x7100af6b00
void Unk_23cd1e8::vf5() {
    ::operator delete(this);
}

class Unk_23cd230 : public Unk_23c98b0 {
public:
    void vf4() override;
    void vf2() override;
    void vf3() override;
    void vf5() override;
    void vf6() override;
};

// 0x7100af6be0
void Unk_23cd230::vf4() {}

// 0x7100af6bf0
void Unk_23cd230::vf5() {
    ::operator delete(this);
}

class Unk_23cd278 : public Unk_23c98b0 {
public:
    void vf4() override;
    void vf2() override;
    void vf3() override;
    void vf5() override;
    void vf6() override;
};

// 0x7100af6cd0
void Unk_23cd278::vf4() {}

// 0x7100af6ce0
void Unk_23cd278::vf5() {
    ::operator delete(this);
}

class Unk_23cd2c0 : public Unk_23c98b0 {
public:
    void vf4() override;
    void vf2() override;
    void vf3() override;
    void vf5() override;
    void vf6() override;
};

// 0x7100af6dc0
void Unk_23cd2c0::vf4() {}

// 0x7100af6dd0
void Unk_23cd2c0::vf5() {
    ::operator delete(this);
}

class Unk_23cd308 : public Unk_23c98b0 {
public:
    void vf4() override;
    void vf2() override;
    void vf3() override;
    void vf5() override;
    void vf6() override;
};

// 0x7100af6eb0
void Unk_23cd308::vf4() {}

// 0x7100af6ec0
void Unk_23cd308::vf5() {
    ::operator delete(this);
}

class Unk_23cd350 : public Unk_23c98b0 {
public:
    void vf4() override;
    void vf2() override;
    void vf3() override;
    void vf5() override;
    void vf6() override;
};

// 0x7100af6fa0
void Unk_23cd350::vf4() {}

// 0x7100af6fb0
void Unk_23cd350::vf5() {
    ::operator delete(this);
}

class Unk_23cd398 {
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
};

// 0x7100af7450
void Unk_23cd398::vf9() {}

class Unk_23cd468 {
public:
    virtual void vf0();
    virtual void vf1();
};

// 0x7100afa580
void Unk_23cd468::vf1() {
    Unk_15b6e10(this);
}

class Unk_23cd488 {
public:
    virtual void vf0();
    virtual void vf1();
};

// 0x7100afa590
void Unk_23cd488::vf1() {
    Unk_15b6e10(this);
}
