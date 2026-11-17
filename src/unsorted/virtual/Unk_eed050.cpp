// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

// Called by forwarders. Placeholders: their real signatures aren't known.
void Unk_eed340(void* self);
void Unk_eee3a0(void* self);
void Unk_eeebe0(void* self);
void Unk_eeee20(void* self);
void Unk_ef0c60(void* self);
void Unk_ef2c60(void* self);
void Unk_ef9a90(void* self);
void Unk_efa5f0(void* self);
void Unk_efb080(void* self);
void Unk_efbfb0(void* self);
void Unk_efe300(void* self);
void Unk_efe900(void* self);
void Unk_eff3f0(void* self);

class Unk_23f87b0 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual u32 vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
};

// 0x7100eed310
void Unk_23f87b0::vf6() {
    Unk_eed340(this);
}

// 0x7100eed050
u32 Unk_23f87b0::vf7() {
    return 1;
}

// 0x7100eed060
void Unk_23f87b0::vf8() {}

// 0x7100eed070
void Unk_23f87b0::vf10() {}

class Unk_23f8818 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x7100eed320
void Unk_23f8818::vf5() {
    Unk_eed340(this);
}

class Unk_23f8858 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x7100eed330
void Unk_23f8858::vf0() {
    Unk_eed340(this);
}

class Unk_23f8880 {
public:
    virtual ~Unk_23f8880();
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
    virtual u32 vf20();
    virtual void vf21();
    virtual void vf22();
    virtual void vf23();
    virtual void vf24();
    virtual u32 vf25();
};

// 0x7100eed8a0
u32 Unk_23f8880::vf20() {
    return 1;
}

// 0x7100eed8b0
void Unk_23f8880::vf21() {}

// 0x7100eed8c0
void Unk_23f8880::vf22() {}

// 0x7100eed9b0
u32 Unk_23f8880::vf25() {
    return 1;
}

class Unk_23f8a08 {
public:
    virtual u32 vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
};

// 0x7100eee180
u32 Unk_23f8a08::vf0() {
    return 1;
}

class Unk_23f8a38 {
public:
    virtual ~Unk_23f8a38();
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

// 0x7100eeeb70
void Unk_23f8a38::vf6() {
    Unk_eeebe0(this);
}

// 0x7100eeeb50
void Unk_23f8a38::vf9() {}

class Unk_23f8aa0 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x7100eeeba0
void Unk_23f8aa0::vf5() {
    Unk_eeebe0(this);
}

class Unk_23f8ae0 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x7100eeebb0
void Unk_23f8ae0::vf0() {
    Unk_eeebe0(this);
}

class Unk_23f8b08 {
public:
    virtual ~Unk_23f8b08();
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
};

// 0x7100eef790
void Unk_23f8b08::vf6() {
    Unk_eeee20(this);
}

// 0x7100eef380
u32 Unk_23f8b08::vf16() {
    return 0;
}

class Unk_23f8ba0 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x7100eef7c0
void Unk_23f8ba0::vf5() {
    Unk_eeee20(this);
}

class Unk_23f8be0 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x7100eef7d0
void Unk_23f8be0::vf0() {
    Unk_eeee20(this);
}

class Unk_23f8c20 {
public:
    virtual ~Unk_23f8c20();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
};

// 0x7100eef890
void Unk_23f8c20::vf6() {
    Unk_eee3a0(this);
}

class Unk_23f8c68 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x7100eef8c0
void Unk_23f8c68::vf5() {
    Unk_eee3a0(this);
}

class Unk_23f8ca8 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x7100eef8d0
void Unk_23f8ca8::vf0() {
    Unk_eee3a0(this);
}

class Unk_23f8d10 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual u32 vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
};

// 0x7100ef0ab0
void Unk_23f8d10::vf6() {
    Unk_ef0c60(this);
}

// 0x7100ef07a0
u32 Unk_23f8d10::vf7() {
    return 1;
}

// 0x7100ef07b0
void Unk_23f8d10::vf8() {}

// 0x7100ef07c0
void Unk_23f8d10::vf10() {}

class Unk_23f8d78 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x7100ef0b80
void Unk_23f8d78::vf5() {
    Unk_ef0c60(this);
}

class Unk_23f8db8 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x7100ef0b90
void Unk_23f8db8::vf0() {
    Unk_ef0c60(this);
}

class Unk_23f8e20 {
public:
    virtual u32 vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
};

// 0x7100ef1410
u32 Unk_23f8e20::vf0() {
    return 1;
}

class Unk_23f8f98 {
public:
    virtual ~Unk_23f8f98();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
};

// 0x7100ef2920
void Unk_23f8f98::vf6() {
    Unk_ef2c60(this);
}

class Unk_23f8fe0 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x7100ef2950
void Unk_23f8fe0::vf5() {
    Unk_ef2c60(this);
}

class Unk_23f9020 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x7100ef2960
void Unk_23f9020::vf0() {
    Unk_ef2c60(this);
}

class Unk_23f9248 {
public:
    virtual ~Unk_23f9248();
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

// 0x7100ef9a20
void Unk_23f9248::vf6() {
    Unk_ef9a90(this);
}

class Unk_23f92b0 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x7100ef9a50
void Unk_23f92b0::vf5() {
    Unk_ef9a90(this);
}

class Unk_23f92f0 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x7100ef9a60
void Unk_23f92f0::vf0() {
    Unk_ef9a90(this);
}

class Unk_23f9330 {
public:
    virtual ~Unk_23f9330();
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

// 0x7100efa580
void Unk_23f9330::vf6() {
    Unk_efa5f0(this);
}

class Unk_23f9398 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x7100efa5b0
void Unk_23f9398::vf5() {
    Unk_efa5f0(this);
}

class Unk_23f93d8 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x7100efa5c0
void Unk_23f93d8::vf0() {
    Unk_efa5f0(this);
}

class Unk_23f9418 {
public:
    virtual ~Unk_23f9418();
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

// 0x7100efb010
void Unk_23f9418::vf6() {
    Unk_efb080(this);
}

class Unk_23f9480 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x7100efb040
void Unk_23f9480::vf5() {
    Unk_efb080(this);
}

class Unk_23f94c0 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x7100efb050
void Unk_23f94c0::vf0() {
    Unk_efb080(this);
}

class Unk_23f9678 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual u32 vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
};

// 0x7100efbf80
void Unk_23f9678::vf6() {
    Unk_efbfb0(this);
}

// 0x7100efba60
u32 Unk_23f9678::vf7() {
    return 1;
}

// 0x7100efba70
void Unk_23f9678::vf8() {}

// 0x7100efba80
void Unk_23f9678::vf10() {}

class Unk_23f96e0 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x7100efbf90
void Unk_23f96e0::vf5() {
    Unk_efbfb0(this);
}

class Unk_23f9720 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x7100efbfa0
void Unk_23f9720::vf0() {
    Unk_efbfb0(this);
}

class Unk_23f9788 {
public:
    virtual u32 vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
};

// 0x7100efc7d0
u32 Unk_23f9788::vf0() {
    return 2;
}

class Unk_23f9868 {
public:
    virtual ~Unk_23f9868();
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
};

// 0x7100efdbf0
void Unk_23f9868::vf22() {}

class Unk_23f97b8 {
public:
    virtual ~Unk_23f97b8();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
};

// 0x7100efdeb0
void Unk_23f97b8::vf6() {
    Unk_efe300(this);
}

class Unk_23f9800 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x7100efdec0
void Unk_23f9800::vf5() {
    Unk_efe300(this);
}

class Unk_23f9840 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x7100efded0
void Unk_23f9840::vf0() {
    Unk_efe300(this);
}

class Unk_23f99b0 {
public:
    virtual ~Unk_23f99b0();
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

// 0x7100efe890
void Unk_23f99b0::vf6() {
    Unk_efe900(this);
}

// 0x7100efe870
void Unk_23f99b0::vf9() {}

class Unk_23f9a18 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x7100efe8c0
void Unk_23f9a18::vf5() {
    Unk_efe900(this);
}

class Unk_23f9a58 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x7100efe8d0
void Unk_23f9a58::vf0() {
    Unk_efe900(this);
}

class Unk_23f9a80 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual u32 vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
};

// 0x7100eff3c0
void Unk_23f9a80::vf6() {
    Unk_eff3f0(this);
}

// 0x7100efeff0
u32 Unk_23f9a80::vf7() {
    return 1;
}

// 0x7100eff0e0
void Unk_23f9a80::vf10() {}

class Unk_23f9ae8 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x7100eff3d0
void Unk_23f9ae8::vf5() {
    Unk_eff3f0(this);
}

class Unk_23f9b28 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x7100eff3e0
void Unk_23f9b28::vf0() {
    Unk_eff3f0(this);
}
