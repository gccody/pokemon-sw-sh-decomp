// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

// Called by forwarders. Placeholders: their real signatures aren't known.
void Unk_14f5220(void* self);
void Unk_14f90c0(void* self);
void Unk_1500210(void* self);

class Unk_2444f50 {
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
    virtual u32 vf22();
    virtual void vf23();
    virtual void vf24();
    virtual void vf25();
    virtual void vf26();
};

// 0x71014eb420
void Unk_2444f50::vf13() {}

// 0x71014eb430
void Unk_2444f50::vf18() {}

// 0x71014eac60
u32 Unk_2444f50::vf22() {
    return 1;
}

class Unk_24450e8 {
public:
    virtual ~Unk_24450e8();
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
    virtual bool vf22();
    virtual void vf23();
    virtual void vf24();
    virtual void vf25();
    virtual void vf26();
    virtual void vf27();
    virtual void vf28();
    virtual void vf29();
    u8 _8[0x79];
    u8 field_81;
};
PKMN_OFFSET_ASSERT(Unk_24450e8, field_81, 0x81);

// 0x71014ec830
bool Unk_24450e8::vf22() {
    return field_81 == 0;
}

class Unk_2445268 {
public:
    virtual ~Unk_2445268();
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
    virtual u32 vf22();
    virtual void vf23();
    virtual void vf24();
    virtual void vf25();
    virtual void vf26();
    virtual void vf27();
    virtual void vf28();
    virtual void vf29();
    virtual void vf30();
    virtual void vf31();
    virtual void vf32();
    virtual void vf33();
    virtual void vf34();
    virtual void vf35();
    virtual void vf36();
};

// 0x71014eec80
void Unk_2445268::vf12() {}

// 0x71014ef1e0
u32 Unk_2445268::vf22() {
    return 1;
}

class Unk_24455a8 {
public:
    virtual ~Unk_24455a8();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual u32 vf5();
    virtual void vf6(u32 value);
    u32 field_8;
};
PKMN_OFFSET_ASSERT(Unk_24455a8, field_8, 0x8);

// 0x71014f4d60
u32 Unk_24455a8::vf5() {
    return field_8;
}

// 0x71014f4d70
void Unk_24455a8::vf6(u32 value) {
    field_8 = value;
}

class Unk_24455f0 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual u32 vf8();
    virtual u32 vf9();
    virtual u32 vf10();
    virtual void vf11();
    virtual bool vf12();
    virtual u32 vf13();
    u8 _8[0x60];
    u32 field_68;
};
PKMN_OFFSET_ASSERT(Unk_24455f0, field_68, 0x68);

// 0x71014f5050
void Unk_24455f0::vf6() {
    Unk_14f5220(this);
}

// 0x71014f5060
u32 Unk_24455f0::vf8() {
    return 0;
}

// 0x71014f5070
u32 Unk_24455f0::vf9() {
    return 0;
}

// 0x71014f5080
u32 Unk_24455f0::vf10() {
    return 0;
}

// 0x71014f5090
bool Unk_24455f0::vf12() {
    return field_68 == 3;
}

// 0x71014f50a0
u32 Unk_24455f0::vf13() {
    return (field_68 == 3) | (field_68 == 0);
}

class Unk_2445670 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x71014f5160
void Unk_2445670::vf5() {
    Unk_14f5220(this);
}

class Unk_24456b0 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x71014f5170
void Unk_24456b0::vf0() {
    Unk_14f5220(this);
}

class Unk_24456d8 {
public:
    virtual ~Unk_24456d8();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual u32 vf5();
    virtual void vf6(u32 value);
    u8 _8[0xc];
    u32 field_14;
};
PKMN_OFFSET_ASSERT(Unk_24456d8, field_14, 0x14);

// 0x71014f63b0, 0x71014f63c0
Unk_24456d8::~Unk_24456d8() {}

// 0x71014f63d0
u32 Unk_24456d8::vf5() {
    return field_14;
}

// 0x71014f63e0
void Unk_24456d8::vf6(u32 value) {
    field_14 = value;
}

class Unk_24458c0 {
public:
    virtual ~Unk_24458c0();
};

// 0x71014f8bc0, 0x71014f8bd0
Unk_24458c0::~Unk_24458c0() {}

class Unk_24458e0 {
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
    virtual bool vf12();
    virtual u32 vf13();
    u8 _8[0x60];
    u32 field_68;
};
PKMN_OFFSET_ASSERT(Unk_24458e0, field_68, 0x68);

// 0x71014f8f20
void Unk_24458e0::vf6() {
    Unk_14f90c0(this);
}

// 0x71014f8f30
bool Unk_24458e0::vf12() {
    return field_68 == 0xb;
}

// 0x71014f8f40
u32 Unk_24458e0::vf13() {
    return (field_68 == 0xb) | (field_68 == 4);
}

class Unk_2445960 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x71014f9000
void Unk_2445960::vf5() {
    Unk_14f90c0(this);
}

class Unk_24459a0 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x71014f9010
void Unk_24459a0::vf0() {
    Unk_14f90c0(this);
}

class Unk_24459c8 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x71014fb430
void Unk_24459c8::vf1() {}

class Unk_2445a08 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
};

// 0x71014fb440
void Unk_2445a08::vf0() {}

// 0x71014fb450
void Unk_2445a08::vf1() {}

class Unk_2445bb0 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x71014fbc60
void Unk_2445bb0::vf1() {}

class Unk_2445bf0 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
};

// 0x71014fbc70
void Unk_2445bf0::vf0() {}

// 0x71014fbc80
void Unk_2445bf0::vf1() {}

class Unk_2445c20 {
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
    virtual u32 vf22();
    virtual u32 vf23();
    virtual void vf24();
    virtual void vf25();
    virtual void vf26();
    virtual void vf27();
    virtual void vf28();
    virtual void vf29();
    virtual void vf30();
    virtual void vf31();
};

// 0x71014fbfe0
void Unk_2445c20::vf18() {}

// 0x71014fc060
u32 Unk_2445c20::vf22() {
    return 1;
}

// 0x71014fc070
u32 Unk_2445c20::vf23() {
    return 1;
}

// 0x71014fc080
void Unk_2445c20::vf27() {}

// 0x71014fc090
void Unk_2445c20::vf28() {}

class Unk_2445d98 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x71014fcd70
void Unk_2445d98::vf1() {}

class Unk_2445dd8 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
};

// 0x71014fcd80
void Unk_2445dd8::vf0() {}

// 0x71014fcd90
void Unk_2445dd8::vf1() {}

class Unk_2445e08 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x71014fd5b0
void Unk_2445e08::vf1() {}

class Unk_2445e48 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
};

// 0x71014fd5c0
void Unk_2445e48::vf0() {}

// 0x71014fd5d0
void Unk_2445e48::vf1() {}

class Unk_2445e78 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x71014fdd60
void Unk_2445e78::vf1() {}

class Unk_2445eb8 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
};

// 0x71014fdd70
void Unk_2445eb8::vf0() {}

// 0x71014fdd80
void Unk_2445eb8::vf1() {}

class Unk_2445ee8 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x71014fe4f0
void Unk_2445ee8::vf1() {}

class Unk_2445f28 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
};

// 0x71014fe500
void Unk_2445f28::vf0() {}

// 0x71014fe510
void Unk_2445f28::vf1() {}

class Unk_2445f58 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x71014fe890
void Unk_2445f58::vf1() {}

class Unk_2445f98 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
};

// 0x71014fe8a0
void Unk_2445f98::vf0() {}

// 0x71014fe8b0
void Unk_2445f98::vf1() {}

class Unk_2446140 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x71014ff4c0
void Unk_2446140::vf1() {}

class Unk_2446180 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
};

// 0x71014ff4d0
void Unk_2446180::vf0() {}

// 0x71014ff4e0
void Unk_2446180::vf1() {}

class Unk_2446328 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x7101500080
void Unk_2446328::vf1() {}

class Unk_2446368 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
};

// 0x7101500090
void Unk_2446368::vf0() {}

// 0x71015000a0
void Unk_2446368::vf1() {}

class Unk_2446398 {
public:
    virtual ~Unk_2446398();
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
    virtual void vf30();
    virtual void vf31();
};

// 0x7101500200
void Unk_2446398::vf16() {
    Unk_1500210(this);
}

class Unk_24465c0 {
public:
    virtual ~Unk_24465c0();
    virtual void vf2();
};

// 0x7101501c90, 0x7101501ca0
Unk_24465c0::~Unk_24465c0() {}

class Unk_2446678 {
public:
    virtual u32 vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
};

// 0x7101506190
u32 Unk_2446678::vf0() {
    return 4;
}

class Unk_24466a8 {
public:
    virtual ~Unk_24466a8();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
};

// 0x71015064c0
void Unk_24466a8::vf4() {}

class Unk_24466f0 {
public:
    virtual ~Unk_24466f0();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
};

// 0x7101506540
void Unk_24466f0::vf4() {}
