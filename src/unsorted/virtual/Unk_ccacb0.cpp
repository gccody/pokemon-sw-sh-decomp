// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

// Tail-called by lifted functions. Placeholders, like the forwarders' callees.
void Unk_c67a60(u64, void*);
void Unk_ccb590(void*, u64, u64);
void Unk_ccc300(void*, u64, u64);
void Unk_ccca20(void*, u64, u64);
void Unk_ccd140(void*, u64, u64);
void Unk_ccdad0(void*, u64, u64);
void Unk_cce1e0(void*, u64, u64);
void Unk_cce8f0(void*, u64, u64);
void Unk_ccf000(void*, u64, u64);
void Unk_ccf8b0(void*, u64, u64);
void Unk_ccffc0(void*, u64, u64);
void Unk_cd06d0(void*, u64, u64);
void Unk_cd0de0(void*, u64, u64);
void Unk_cd14f0(void*, u64, u64);
void Unk_cd1c10(void*, u64, u64);
void Unk_cd2320(void*, u64, u64);
void Unk_cd2a30(void*, u64, u64);
void Unk_cd3140(void*, u64, u64);
void Unk_cd3850(void*, u64, u64);
void Unk_cd3f60(void*, u64, u64);
void Unk_cd4670(void*, u64, u64);
void Unk_cd4d80(void*, u64, u64);
void Unk_cd54a0(void*, u64, u64);
void Unk_cd5bb0(void*, u64, u64);
void Unk_cd62c0(void*, u64, u64);
void Unk_cd69d0(void*, u64, u64);
void Unk_cd70e0(void*, u64, u64);
void Unk_cd77f0(void*, u64, u64);
void Unk_cd7f00(void*, u64, u64);
void Unk_cd8610(void*, u64, u64);
void Unk_cd8d20(void*, u64, u64);
void Unk_cd9430(void*, u64, u64);
void Unk_cd9b40(void*, u64, u64);
void Unk_cda250(void*, u64, u64);
void Unk_cda970(void*, u64, u64);

class Unk_23e13a8 {
public:
    virtual ~Unk_23e13a8();
    virtual void vf2(u64 value);
    virtual void vf3(u64 value);
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual u64 vf9();
    virtual void vf10();
    virtual u64 vf11();
    virtual void vf12();
    virtual void vf13();
    virtual void vf14();
    virtual u8 vf15();
    virtual void vf16();
    virtual u8 vf17();
    virtual void vf18();
    virtual void vf19(u64 value);
    virtual void vf20();
    virtual void vf21(f32 fvalue);
    virtual void vf22();
    virtual u8 vf23();
    virtual void vf24();
    virtual void vf25();
    virtual u32 vf26();
    virtual void vf27();
    virtual void vf28();
    virtual void vf29();
    u8 _8[0x8];
    u64 field_10;
    u64 field_18;
    f32 field_20;
    u8 field_24;
    u8 field_25;
    u8 _26[0x2];
    u64 field_28;
    u8 _30[0x48];
    u8 field_78;
    u8 _79[0x7];
    u64 field_80;
};
PKMN_OFFSET_ASSERT(Unk_23e13a8, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_23e13a8, field_18, 0x18);
PKMN_OFFSET_ASSERT(Unk_23e13a8, field_20, 0x20);
PKMN_OFFSET_ASSERT(Unk_23e13a8, field_24, 0x24);
PKMN_OFFSET_ASSERT(Unk_23e13a8, field_25, 0x25);
PKMN_OFFSET_ASSERT(Unk_23e13a8, field_28, 0x28);
PKMN_OFFSET_ASSERT(Unk_23e13a8, field_78, 0x78);
PKMN_OFFSET_ASSERT(Unk_23e13a8, field_80, 0x80);

// 0x7100ccacb0
void Unk_23e13a8::vf2(u64 value) {
    Unk_c67a60(value, this);
}

// 0x7100ccacc0
void Unk_23e13a8::vf3(u64 value) {
    Unk_ccb590(this, value, field_80);
}

// 0x7100ccae70
u64 Unk_23e13a8::vf9() {
    return field_10;
}

// 0x7100ccaf00
u64 Unk_23e13a8::vf11() {
    return field_18;
}

// 0x7100ccb020
u8 Unk_23e13a8::vf15() {
    return field_24;
}

// 0x7100ccb040
u8 Unk_23e13a8::vf17() {
    return field_25;
}

// 0x7100ccb060
void Unk_23e13a8::vf19(u64 value) {
    field_28 = value;
}

// 0x7100ccb0b0
void Unk_23e13a8::vf21(f32 fvalue) {
    field_20 = fvalue;
}

// 0x7100ccb310
u8 Unk_23e13a8::vf23() {
    return field_78;
}

// 0x7100ccb3b0
u32 Unk_23e13a8::vf26() {
    return 0;
}

class Unk_23e15c8 {
public:
    virtual ~Unk_23e15c8();
    virtual void vf2(u64 value);
    virtual void vf3(u64 value);
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
    virtual u32 vf26();
    virtual void vf27();
    virtual void vf28();
    virtual void vf29();
    u8 _8[0x78];
    u64 field_80;
};
PKMN_OFFSET_ASSERT(Unk_23e15c8, field_80, 0x80);

// 0x7100ccc200
void Unk_23e15c8::vf2(u64 value) {
    Unk_c67a60(value, this);
}

// 0x7100ccc210
void Unk_23e15c8::vf3(u64 value) {
    Unk_ccc300(this, value, field_80);
}

// 0x7100ccc260
u32 Unk_23e15c8::vf26() {
    return 0;
}

class Unk_23e16c8 {
public:
    virtual ~Unk_23e16c8();
    virtual void vf2(u64 value);
    virtual void vf3(u64 value);
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
    virtual u32 vf26();
    virtual void vf27();
    virtual void vf28();
    virtual void vf29();
    u8 _8[0x78];
    u64 field_80;
};
PKMN_OFFSET_ASSERT(Unk_23e16c8, field_80, 0x80);

// 0x7100ccc920
void Unk_23e16c8::vf2(u64 value) {
    Unk_c67a60(value, this);
}

// 0x7100ccc930
void Unk_23e16c8::vf3(u64 value) {
    Unk_ccca20(this, value, field_80);
}

// 0x7100ccc980
u32 Unk_23e16c8::vf26() {
    return 0;
}

class Unk_23e17c8 {
public:
    virtual ~Unk_23e17c8();
    virtual void vf2(u64 value);
    virtual void vf3(u64 value);
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
    virtual u32 vf26();
    virtual void vf27();
    virtual void vf28();
    virtual void vf29();
    u8 _8[0x78];
    u64 field_80;
};
PKMN_OFFSET_ASSERT(Unk_23e17c8, field_80, 0x80);

// 0x7100ccd040
void Unk_23e17c8::vf2(u64 value) {
    Unk_c67a60(value, this);
}

// 0x7100ccd050
void Unk_23e17c8::vf3(u64 value) {
    Unk_ccd140(this, value, field_80);
}

// 0x7100ccd0a0
u32 Unk_23e17c8::vf26() {
    return 0;
}

class Unk_23e18c8 {
public:
    virtual ~Unk_23e18c8();
    virtual void vf2(u64 value);
    virtual void vf3(u64 value);
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
    virtual u32 vf26();
    virtual void vf27();
    virtual void vf28();
    virtual u32 vf29();
    u8 _8[0x78];
    u64 field_80;
};
PKMN_OFFSET_ASSERT(Unk_23e18c8, field_80, 0x80);

// 0x7100ccd9e0
void Unk_23e18c8::vf2(u64 value) {
    Unk_c67a60(value, this);
}

// 0x7100ccd9f0
void Unk_23e18c8::vf3(u64 value) {
    Unk_ccdad0(this, value, field_80);
}

// 0x7100ccda40
u32 Unk_23e18c8::vf26() {
    return 0;
}

// 0x7100ccda80
u32 Unk_23e18c8::vf29() {
    return 1;
}

class Unk_23e19c8 {
public:
    virtual ~Unk_23e19c8();
    virtual void vf2(u64 value);
    virtual void vf3(u64 value);
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
    virtual u32 vf26();
    virtual void vf27();
    virtual void vf28();
    virtual u32 vf29();
    u8 _8[0x78];
    u64 field_80;
};
PKMN_OFFSET_ASSERT(Unk_23e19c8, field_80, 0x80);

// 0x7100cce0f0
void Unk_23e19c8::vf2(u64 value) {
    Unk_c67a60(value, this);
}

// 0x7100cce100
void Unk_23e19c8::vf3(u64 value) {
    Unk_cce1e0(this, value, field_80);
}

// 0x7100cce150
u32 Unk_23e19c8::vf26() {
    return 0;
}

// 0x7100cce190
u32 Unk_23e19c8::vf29() {
    return 1;
}

class Unk_23e1ac8 {
public:
    virtual ~Unk_23e1ac8();
    virtual void vf2(u64 value);
    virtual void vf3(u64 value);
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
    virtual u32 vf26();
    virtual void vf27();
    virtual void vf28();
    virtual u32 vf29();
    u8 _8[0x78];
    u64 field_80;
};
PKMN_OFFSET_ASSERT(Unk_23e1ac8, field_80, 0x80);

// 0x7100cce800
void Unk_23e1ac8::vf2(u64 value) {
    Unk_c67a60(value, this);
}

// 0x7100cce810
void Unk_23e1ac8::vf3(u64 value) {
    Unk_cce8f0(this, value, field_80);
}

// 0x7100cce860
u32 Unk_23e1ac8::vf26() {
    return 0;
}

// 0x7100cce8a0
u32 Unk_23e1ac8::vf29() {
    return 1;
}

class Unk_23e1bc8 {
public:
    virtual ~Unk_23e1bc8();
    virtual void vf2(u64 value);
    virtual void vf3(u64 value);
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
    virtual u32 vf26();
    virtual void vf27();
    virtual void vf28();
    virtual u32 vf29();
    u8 _8[0x78];
    u64 field_80;
};
PKMN_OFFSET_ASSERT(Unk_23e1bc8, field_80, 0x80);

// 0x7100ccef10
void Unk_23e1bc8::vf2(u64 value) {
    Unk_c67a60(value, this);
}

// 0x7100ccef20
void Unk_23e1bc8::vf3(u64 value) {
    Unk_ccf000(this, value, field_80);
}

// 0x7100ccef70
u32 Unk_23e1bc8::vf26() {
    return 0;
}

// 0x7100ccefb0
u32 Unk_23e1bc8::vf29() {
    return 1;
}

class Unk_23e1cc8 {
public:
    virtual ~Unk_23e1cc8();
    virtual void vf2(u64 value);
    virtual void vf3(u64 value);
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
    virtual u32 vf26();
    virtual void vf27();
    virtual void vf28();
    virtual u32 vf29();
    u8 _8[0x78];
    u64 field_80;
};
PKMN_OFFSET_ASSERT(Unk_23e1cc8, field_80, 0x80);

// 0x7100ccf7c0
void Unk_23e1cc8::vf2(u64 value) {
    Unk_c67a60(value, this);
}

// 0x7100ccf7d0
void Unk_23e1cc8::vf3(u64 value) {
    Unk_ccf8b0(this, value, field_80);
}

// 0x7100ccf820
u32 Unk_23e1cc8::vf26() {
    return 0;
}

// 0x7100ccf860
u32 Unk_23e1cc8::vf29() {
    return 1;
}

class Unk_23e1dc8 {
public:
    virtual ~Unk_23e1dc8();
    virtual void vf2(u64 value);
    virtual void vf3(u64 value);
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
    virtual u32 vf26();
    virtual void vf27();
    virtual void vf28();
    virtual u32 vf29();
    u8 _8[0x78];
    u64 field_80;
};
PKMN_OFFSET_ASSERT(Unk_23e1dc8, field_80, 0x80);

// 0x7100ccfed0
void Unk_23e1dc8::vf2(u64 value) {
    Unk_c67a60(value, this);
}

// 0x7100ccfee0
void Unk_23e1dc8::vf3(u64 value) {
    Unk_ccffc0(this, value, field_80);
}

// 0x7100ccff30
u32 Unk_23e1dc8::vf26() {
    return 0;
}

// 0x7100ccff70
u32 Unk_23e1dc8::vf29() {
    return 1;
}

class Unk_23e1ec8 {
public:
    virtual ~Unk_23e1ec8();
    virtual void vf2(u64 value);
    virtual void vf3(u64 value);
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
    virtual u32 vf26();
    virtual void vf27();
    virtual void vf28();
    virtual u32 vf29();
    u8 _8[0x78];
    u64 field_80;
};
PKMN_OFFSET_ASSERT(Unk_23e1ec8, field_80, 0x80);

// 0x7100cd05e0
void Unk_23e1ec8::vf2(u64 value) {
    Unk_c67a60(value, this);
}

// 0x7100cd05f0
void Unk_23e1ec8::vf3(u64 value) {
    Unk_cd06d0(this, value, field_80);
}

// 0x7100cd0640
u32 Unk_23e1ec8::vf26() {
    return 0;
}

// 0x7100cd0680
u32 Unk_23e1ec8::vf29() {
    return 1;
}

class Unk_23e1fc8 {
public:
    virtual ~Unk_23e1fc8();
    virtual void vf2(u64 value);
    virtual void vf3(u64 value);
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
    virtual u32 vf26();
    virtual void vf27();
    virtual void vf28();
    virtual u32 vf29();
    u8 _8[0x78];
    u64 field_80;
};
PKMN_OFFSET_ASSERT(Unk_23e1fc8, field_80, 0x80);

// 0x7100cd0cf0
void Unk_23e1fc8::vf2(u64 value) {
    Unk_c67a60(value, this);
}

// 0x7100cd0d00
void Unk_23e1fc8::vf3(u64 value) {
    Unk_cd0de0(this, value, field_80);
}

// 0x7100cd0d50
u32 Unk_23e1fc8::vf26() {
    return 0;
}

// 0x7100cd0d90
u32 Unk_23e1fc8::vf29() {
    return 1;
}

class Unk_23e20c8 {
public:
    virtual ~Unk_23e20c8();
    virtual void vf2(u64 value);
    virtual void vf3(u64 value);
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
    virtual u32 vf26();
    virtual void vf27();
    virtual void vf28();
    virtual u32 vf29();
    u8 _8[0x78];
    u64 field_80;
};
PKMN_OFFSET_ASSERT(Unk_23e20c8, field_80, 0x80);

// 0x7100cd1400
void Unk_23e20c8::vf2(u64 value) {
    Unk_c67a60(value, this);
}

// 0x7100cd1410
void Unk_23e20c8::vf3(u64 value) {
    Unk_cd14f0(this, value, field_80);
}

// 0x7100cd1460
u32 Unk_23e20c8::vf26() {
    return 0;
}

// 0x7100cd14a0
u32 Unk_23e20c8::vf29() {
    return 1;
}

class Unk_23e21c8 {
public:
    virtual ~Unk_23e21c8();
    virtual void vf2(u64 value);
    virtual void vf3(u64 value);
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
    virtual u32 vf26();
    virtual void vf27();
    virtual void vf28();
    virtual void vf29();
    u8 _8[0x78];
    u64 field_80;
};
PKMN_OFFSET_ASSERT(Unk_23e21c8, field_80, 0x80);

// 0x7100cd1b10
void Unk_23e21c8::vf2(u64 value) {
    Unk_c67a60(value, this);
}

// 0x7100cd1b20
void Unk_23e21c8::vf3(u64 value) {
    Unk_cd1c10(this, value, field_80);
}

// 0x7100cd1b70
u32 Unk_23e21c8::vf26() {
    return 1;
}

class Unk_23e22c8 {
public:
    virtual ~Unk_23e22c8();
    virtual void vf2(u64 value);
    virtual void vf3(u64 value);
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
    virtual u32 vf26();
    virtual void vf27();
    virtual void vf28();
    virtual u32 vf29();
    u8 _8[0x78];
    u64 field_80;
};
PKMN_OFFSET_ASSERT(Unk_23e22c8, field_80, 0x80);

// 0x7100cd2230
void Unk_23e22c8::vf2(u64 value) {
    Unk_c67a60(value, this);
}

// 0x7100cd2240
void Unk_23e22c8::vf3(u64 value) {
    Unk_cd2320(this, value, field_80);
}

// 0x7100cd2290
u32 Unk_23e22c8::vf26() {
    return 0;
}

// 0x7100cd22d0
u32 Unk_23e22c8::vf29() {
    return 1;
}

class Unk_23e23c8 {
public:
    virtual ~Unk_23e23c8();
    virtual void vf2(u64 value);
    virtual void vf3(u64 value);
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
    virtual u32 vf26();
    virtual void vf27();
    virtual void vf28();
    virtual u32 vf29();
    u8 _8[0x78];
    u64 field_80;
};
PKMN_OFFSET_ASSERT(Unk_23e23c8, field_80, 0x80);

// 0x7100cd2940
void Unk_23e23c8::vf2(u64 value) {
    Unk_c67a60(value, this);
}

// 0x7100cd2950
void Unk_23e23c8::vf3(u64 value) {
    Unk_cd2a30(this, value, field_80);
}

// 0x7100cd29a0
u32 Unk_23e23c8::vf26() {
    return 0;
}

// 0x7100cd29e0
u32 Unk_23e23c8::vf29() {
    return 1;
}

class Unk_23e24c8 {
public:
    virtual ~Unk_23e24c8();
    virtual void vf2(u64 value);
    virtual void vf3(u64 value);
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
    virtual u32 vf26();
    virtual void vf27();
    virtual void vf28();
    virtual u32 vf29();
    u8 _8[0x78];
    u64 field_80;
};
PKMN_OFFSET_ASSERT(Unk_23e24c8, field_80, 0x80);

// 0x7100cd3050
void Unk_23e24c8::vf2(u64 value) {
    Unk_c67a60(value, this);
}

// 0x7100cd3060
void Unk_23e24c8::vf3(u64 value) {
    Unk_cd3140(this, value, field_80);
}

// 0x7100cd30b0
u32 Unk_23e24c8::vf26() {
    return 0;
}

// 0x7100cd30f0
u32 Unk_23e24c8::vf29() {
    return 1;
}

class Unk_23e25c8 {
public:
    virtual ~Unk_23e25c8();
    virtual void vf2(u64 value);
    virtual void vf3(u64 value);
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
    virtual u32 vf26();
    virtual void vf27();
    virtual void vf28();
    virtual u32 vf29();
    u8 _8[0x78];
    u64 field_80;
};
PKMN_OFFSET_ASSERT(Unk_23e25c8, field_80, 0x80);

// 0x7100cd3760
void Unk_23e25c8::vf2(u64 value) {
    Unk_c67a60(value, this);
}

// 0x7100cd3770
void Unk_23e25c8::vf3(u64 value) {
    Unk_cd3850(this, value, field_80);
}

// 0x7100cd37c0
u32 Unk_23e25c8::vf26() {
    return 0;
}

// 0x7100cd3800
u32 Unk_23e25c8::vf29() {
    return 1;
}

class Unk_23e26c8 {
public:
    virtual ~Unk_23e26c8();
    virtual void vf2(u64 value);
    virtual void vf3(u64 value);
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
    virtual u32 vf26();
    virtual void vf27();
    virtual void vf28();
    virtual u32 vf29();
    u8 _8[0x78];
    u64 field_80;
};
PKMN_OFFSET_ASSERT(Unk_23e26c8, field_80, 0x80);

// 0x7100cd3e70
void Unk_23e26c8::vf2(u64 value) {
    Unk_c67a60(value, this);
}

// 0x7100cd3e80
void Unk_23e26c8::vf3(u64 value) {
    Unk_cd3f60(this, value, field_80);
}

// 0x7100cd3ed0
u32 Unk_23e26c8::vf26() {
    return 0;
}

// 0x7100cd3f10
u32 Unk_23e26c8::vf29() {
    return 1;
}

class Unk_23e27c8 {
public:
    virtual ~Unk_23e27c8();
    virtual void vf2(u64 value);
    virtual void vf3(u64 value);
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
    virtual u32 vf26();
    virtual void vf27();
    virtual void vf28();
    virtual u32 vf29();
    u8 _8[0x78];
    u64 field_80;
};
PKMN_OFFSET_ASSERT(Unk_23e27c8, field_80, 0x80);

// 0x7100cd4580
void Unk_23e27c8::vf2(u64 value) {
    Unk_c67a60(value, this);
}

// 0x7100cd4590
void Unk_23e27c8::vf3(u64 value) {
    Unk_cd4670(this, value, field_80);
}

// 0x7100cd45e0
u32 Unk_23e27c8::vf26() {
    return 0;
}

// 0x7100cd4620
u32 Unk_23e27c8::vf29() {
    return 1;
}

class Unk_23e28c8 {
public:
    virtual ~Unk_23e28c8();
    virtual void vf2(u64 value);
    virtual void vf3(u64 value);
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
    virtual u32 vf26();
    virtual void vf27();
    virtual void vf28();
    virtual u32 vf29();
    u8 _8[0x78];
    u64 field_80;
};
PKMN_OFFSET_ASSERT(Unk_23e28c8, field_80, 0x80);

// 0x7100cd4c90
void Unk_23e28c8::vf2(u64 value) {
    Unk_c67a60(value, this);
}

// 0x7100cd4ca0
void Unk_23e28c8::vf3(u64 value) {
    Unk_cd4d80(this, value, field_80);
}

// 0x7100cd4cf0
u32 Unk_23e28c8::vf26() {
    return 0;
}

// 0x7100cd4d30
u32 Unk_23e28c8::vf29() {
    return 1;
}

class Unk_23e29c8 {
public:
    virtual ~Unk_23e29c8();
    virtual void vf2(u64 value);
    virtual void vf3(u64 value);
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
    virtual u32 vf26();
    virtual void vf27();
    virtual void vf28();
    virtual void vf29();
    u8 _8[0x78];
    u64 field_80;
};
PKMN_OFFSET_ASSERT(Unk_23e29c8, field_80, 0x80);

// 0x7100cd53a0
void Unk_23e29c8::vf2(u64 value) {
    Unk_c67a60(value, this);
}

// 0x7100cd53b0
void Unk_23e29c8::vf3(u64 value) {
    Unk_cd54a0(this, value, field_80);
}

// 0x7100cd5400
u32 Unk_23e29c8::vf26() {
    return 1;
}

class Unk_23e2ac8 {
public:
    virtual ~Unk_23e2ac8();
    virtual void vf2(u64 value);
    virtual void vf3(u64 value);
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
    virtual u32 vf26();
    virtual void vf27();
    virtual void vf28();
    virtual u32 vf29();
    u8 _8[0x78];
    u64 field_80;
};
PKMN_OFFSET_ASSERT(Unk_23e2ac8, field_80, 0x80);

// 0x7100cd5ac0
void Unk_23e2ac8::vf2(u64 value) {
    Unk_c67a60(value, this);
}

// 0x7100cd5ad0
void Unk_23e2ac8::vf3(u64 value) {
    Unk_cd5bb0(this, value, field_80);
}

// 0x7100cd5b20
u32 Unk_23e2ac8::vf26() {
    return 0;
}

// 0x7100cd5b60
u32 Unk_23e2ac8::vf29() {
    return 1;
}

class Unk_23e2bc8 {
public:
    virtual ~Unk_23e2bc8();
    virtual void vf2(u64 value);
    virtual void vf3(u64 value);
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
    virtual u32 vf26();
    virtual void vf27();
    virtual void vf28();
    virtual u32 vf29();
    u8 _8[0x78];
    u64 field_80;
};
PKMN_OFFSET_ASSERT(Unk_23e2bc8, field_80, 0x80);

// 0x7100cd61d0
void Unk_23e2bc8::vf2(u64 value) {
    Unk_c67a60(value, this);
}

// 0x7100cd61e0
void Unk_23e2bc8::vf3(u64 value) {
    Unk_cd62c0(this, value, field_80);
}

// 0x7100cd6230
u32 Unk_23e2bc8::vf26() {
    return 0;
}

// 0x7100cd6270
u32 Unk_23e2bc8::vf29() {
    return 1;
}

class Unk_23e2cc8 {
public:
    virtual ~Unk_23e2cc8();
    virtual void vf2(u64 value);
    virtual void vf3(u64 value);
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
    virtual u32 vf26();
    virtual void vf27();
    virtual void vf28();
    virtual u32 vf29();
    u8 _8[0x78];
    u64 field_80;
};
PKMN_OFFSET_ASSERT(Unk_23e2cc8, field_80, 0x80);

// 0x7100cd68e0
void Unk_23e2cc8::vf2(u64 value) {
    Unk_c67a60(value, this);
}

// 0x7100cd68f0
void Unk_23e2cc8::vf3(u64 value) {
    Unk_cd69d0(this, value, field_80);
}

// 0x7100cd6940
u32 Unk_23e2cc8::vf26() {
    return 0;
}

// 0x7100cd6980
u32 Unk_23e2cc8::vf29() {
    return 1;
}

class Unk_23e2dc8 {
public:
    virtual ~Unk_23e2dc8();
    virtual void vf2(u64 value);
    virtual void vf3(u64 value);
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
    virtual u32 vf26();
    virtual void vf27();
    virtual void vf28();
    virtual u32 vf29();
    u8 _8[0x78];
    u64 field_80;
};
PKMN_OFFSET_ASSERT(Unk_23e2dc8, field_80, 0x80);

// 0x7100cd6ff0
void Unk_23e2dc8::vf2(u64 value) {
    Unk_c67a60(value, this);
}

// 0x7100cd7000
void Unk_23e2dc8::vf3(u64 value) {
    Unk_cd70e0(this, value, field_80);
}

// 0x7100cd7050
u32 Unk_23e2dc8::vf26() {
    return 0;
}

// 0x7100cd7090
u32 Unk_23e2dc8::vf29() {
    return 1;
}

class Unk_23e2ec8 {
public:
    virtual ~Unk_23e2ec8();
    virtual void vf2(u64 value);
    virtual void vf3(u64 value);
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
    virtual u32 vf26();
    virtual void vf27();
    virtual void vf28();
    virtual u32 vf29();
    u8 _8[0x78];
    u64 field_80;
};
PKMN_OFFSET_ASSERT(Unk_23e2ec8, field_80, 0x80);

// 0x7100cd7700
void Unk_23e2ec8::vf2(u64 value) {
    Unk_c67a60(value, this);
}

// 0x7100cd7710
void Unk_23e2ec8::vf3(u64 value) {
    Unk_cd77f0(this, value, field_80);
}

// 0x7100cd7760
u32 Unk_23e2ec8::vf26() {
    return 0;
}

// 0x7100cd77a0
u32 Unk_23e2ec8::vf29() {
    return 1;
}

class Unk_23e2fc8 {
public:
    virtual ~Unk_23e2fc8();
    virtual void vf2(u64 value);
    virtual void vf3(u64 value);
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
    virtual u32 vf26();
    virtual void vf27();
    virtual void vf28();
    virtual u32 vf29();
    u8 _8[0x78];
    u64 field_80;
};
PKMN_OFFSET_ASSERT(Unk_23e2fc8, field_80, 0x80);

// 0x7100cd7e10
void Unk_23e2fc8::vf2(u64 value) {
    Unk_c67a60(value, this);
}

// 0x7100cd7e20
void Unk_23e2fc8::vf3(u64 value) {
    Unk_cd7f00(this, value, field_80);
}

// 0x7100cd7e70
u32 Unk_23e2fc8::vf26() {
    return 0;
}

// 0x7100cd7eb0
u32 Unk_23e2fc8::vf29() {
    return 1;
}

class Unk_23e30c8 {
public:
    virtual ~Unk_23e30c8();
    virtual void vf2(u64 value);
    virtual void vf3(u64 value);
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
    virtual u32 vf26();
    virtual void vf27();
    virtual void vf28();
    virtual u32 vf29();
    u8 _8[0x78];
    u64 field_80;
};
PKMN_OFFSET_ASSERT(Unk_23e30c8, field_80, 0x80);

// 0x7100cd8520
void Unk_23e30c8::vf2(u64 value) {
    Unk_c67a60(value, this);
}

// 0x7100cd8530
void Unk_23e30c8::vf3(u64 value) {
    Unk_cd8610(this, value, field_80);
}

// 0x7100cd8580
u32 Unk_23e30c8::vf26() {
    return 0;
}

// 0x7100cd85c0
u32 Unk_23e30c8::vf29() {
    return 1;
}

class Unk_23e31c8 {
public:
    virtual ~Unk_23e31c8();
    virtual void vf2(u64 value);
    virtual void vf3(u64 value);
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
    virtual u32 vf26();
    virtual void vf27();
    virtual void vf28();
    virtual u32 vf29();
    u8 _8[0x78];
    u64 field_80;
};
PKMN_OFFSET_ASSERT(Unk_23e31c8, field_80, 0x80);

// 0x7100cd8c30
void Unk_23e31c8::vf2(u64 value) {
    Unk_c67a60(value, this);
}

// 0x7100cd8c40
void Unk_23e31c8::vf3(u64 value) {
    Unk_cd8d20(this, value, field_80);
}

// 0x7100cd8c90
u32 Unk_23e31c8::vf26() {
    return 0;
}

// 0x7100cd8cd0
u32 Unk_23e31c8::vf29() {
    return 1;
}

class Unk_23e32c8 {
public:
    virtual ~Unk_23e32c8();
    virtual void vf2(u64 value);
    virtual void vf3(u64 value);
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
    virtual u32 vf26();
    virtual void vf27();
    virtual void vf28();
    virtual u32 vf29();
    u8 _8[0x78];
    u64 field_80;
};
PKMN_OFFSET_ASSERT(Unk_23e32c8, field_80, 0x80);

// 0x7100cd9340
void Unk_23e32c8::vf2(u64 value) {
    Unk_c67a60(value, this);
}

// 0x7100cd9350
void Unk_23e32c8::vf3(u64 value) {
    Unk_cd9430(this, value, field_80);
}

// 0x7100cd93a0
u32 Unk_23e32c8::vf26() {
    return 0;
}

// 0x7100cd93e0
u32 Unk_23e32c8::vf29() {
    return 1;
}

class Unk_23e33c8 {
public:
    virtual ~Unk_23e33c8();
    virtual void vf2(u64 value);
    virtual void vf3(u64 value);
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
    virtual u32 vf26();
    virtual void vf27();
    virtual void vf28();
    virtual u32 vf29();
    u8 _8[0x78];
    u64 field_80;
};
PKMN_OFFSET_ASSERT(Unk_23e33c8, field_80, 0x80);

// 0x7100cd9a50
void Unk_23e33c8::vf2(u64 value) {
    Unk_c67a60(value, this);
}

// 0x7100cd9a60
void Unk_23e33c8::vf3(u64 value) {
    Unk_cd9b40(this, value, field_80);
}

// 0x7100cd9ab0
u32 Unk_23e33c8::vf26() {
    return 0;
}

// 0x7100cd9af0
u32 Unk_23e33c8::vf29() {
    return 1;
}

class Unk_23e34c8 {
public:
    virtual ~Unk_23e34c8();
    virtual void vf2(u64 value);
    virtual void vf3(u64 value);
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
    virtual u32 vf26();
    virtual void vf27();
    virtual void vf28();
    virtual u32 vf29();
    u8 _8[0x78];
    u64 field_80;
};
PKMN_OFFSET_ASSERT(Unk_23e34c8, field_80, 0x80);

// 0x7100cda160
void Unk_23e34c8::vf2(u64 value) {
    Unk_c67a60(value, this);
}

// 0x7100cda170
void Unk_23e34c8::vf3(u64 value) {
    Unk_cda250(this, value, field_80);
}

// 0x7100cda1c0
u32 Unk_23e34c8::vf26() {
    return 0;
}

// 0x7100cda200
u32 Unk_23e34c8::vf29() {
    return 1;
}

class Unk_23e35c8 {
public:
    virtual ~Unk_23e35c8();
    virtual void vf2(u64 value);
    virtual void vf3(u64 value);
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
    virtual u32 vf26();
    virtual void vf27();
    virtual void vf28();
    virtual void vf29();
    u8 _8[0x78];
    u64 field_80;
};
PKMN_OFFSET_ASSERT(Unk_23e35c8, field_80, 0x80);

// 0x7100cda870
void Unk_23e35c8::vf2(u64 value) {
    Unk_c67a60(value, this);
}

// 0x7100cda880
void Unk_23e35c8::vf3(u64 value) {
    Unk_cda970(this, value, field_80);
}

// 0x7100cda8d0
u32 Unk_23e35c8::vf26() {
    return 1;
}
