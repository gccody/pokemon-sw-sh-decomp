// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

// Called by forwarders. Placeholders: their real signatures aren't known.
void Unk_1439d80(void* self);
void Unk_143cee0(void* self);
void Unk_143f560(void* self);
void Unk_1440750(void* self);
void Unk_1441d30(void* self);
void Unk_1443030(void* self);
void Unk_1449740(void* self);
void Unk_144aae0(void* self);
void Unk_144c2d0(void* self);
void Unk_144cc50(void* self);
void Unk_144d650(void* self);

class Unk_243b490 {
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

// 0x710143a9d0
void Unk_243b490::vf9() {}

class Unk_243b560 {
public:
    virtual ~Unk_243b560();
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

// 0x710143b560
void Unk_243b560::vf9() {}

class Unk_243b648 {
public:
    virtual ~Unk_243b648();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual u32 vf8();
    virtual void vf9();
    virtual void vf10();
};

// 0x710143b840
u32 Unk_243b648::vf8() {
    return 1;
}

// 0x710143b850
void Unk_243b648::vf9() {}

class Unk_243b800 {
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
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
    virtual void vf14();
    virtual void vf15();
    virtual u32 vf16();
};

// 0x710143cbb0
void Unk_243b800::vf6() {
    Unk_143cee0(this);
}

// 0x710143be10
u32 Unk_243b800::vf7() {
    return 1;
}

// 0x710143c910
u32 Unk_243b800::vf16() {
    return 0;
}

class Unk_243b898 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x710143cd40
void Unk_243b898::vf5() {
    Unk_143cee0(this);
}

class Unk_243b8d8 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x710143cd50
void Unk_243b8d8::vf0() {
    Unk_143cee0(this);
}

class Unk_243b980 {
public:
    virtual ~Unk_243b980();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
};

// 0x710143dc20
void Unk_243b980::vf6() {
    Unk_1439d80(this);
}

class Unk_243b9c8 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x710143dc50
void Unk_243b9c8::vf5() {
    Unk_1439d80(this);
}

class Unk_243ba08 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x710143dc60
void Unk_243ba08::vf0() {
    Unk_1439d80(this);
}

class Unk_243ba30 {
public:
    virtual ~Unk_243ba30();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual u32 vf7();
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

// 0x710143e500
u32 Unk_243ba30::vf7() {
    return 1;
}

class Unk_243bb40 {
public:
    virtual u32 vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
};

// 0x710143eb20
u32 Unk_243bb40::vf0() {
    return 1;
}

class Unk_243bb70 {
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

// 0x710143f530
void Unk_243bb70::vf6() {
    Unk_143f560(this);
}

// 0x710143f120
u32 Unk_243bb70::vf7() {
    return 1;
}

// 0x710143f130
void Unk_243bb70::vf8() {}

// 0x710143f140
void Unk_243bb70::vf10() {}

class Unk_243bbd8 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x710143f540
void Unk_243bbd8::vf5() {
    Unk_143f560(this);
}

class Unk_243bc18 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x710143f550
void Unk_243bc18::vf0() {
    Unk_143f560(this);
}

class Unk_243bcf0 {
public:
    virtual ~Unk_243bcf0();
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
    virtual u32 vf25();
};

// 0x710143fbd0
void Unk_243bcf0::vf21() {}

// 0x710143fbe0
void Unk_243bcf0::vf22() {}

// 0x710143fbf0
u32 Unk_243bcf0::vf25() {
    return 1;
}

class Unk_243bc40 {
public:
    virtual ~Unk_243bc40();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
};

// 0x7101440100
void Unk_243bc40::vf6() {
    Unk_1440750(this);
}

class Unk_243bc88 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x7101440130
void Unk_243bc88::vf5() {
    Unk_1440750(this);
}

class Unk_243bcc8 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x7101440140
void Unk_243bcc8::vf0() {
    Unk_1440750(this);
}

class Unk_243be78 {
public:
    virtual u32 vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
};

// 0x7101440530
u32 Unk_243be78::vf0() {
    return 1;
}

class Unk_243bea8 {
public:
    virtual ~Unk_243bea8();
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

// 0x7101441cc0
void Unk_243bea8::vf6() {
    Unk_1441d30(this);
}

// 0x7101441ca0
void Unk_243bea8::vf9() {}

class Unk_243bf10 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x7101441cf0
void Unk_243bf10::vf5() {
    Unk_1441d30(this);
}

class Unk_243bf50 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x7101441d00
void Unk_243bf50::vf0() {
    Unk_1441d30(this);
}

class Unk_243bf78 {
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
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
    virtual void vf14();
    virtual void vf15();
    virtual void vf16();
};

// 0x7101442e80
void Unk_243bf78::vf6() {
    Unk_1443030(this);
}

// 0x71014420a0
u32 Unk_243bf78::vf7() {
    return 1;
}

class Unk_243c010 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x7101442f50
void Unk_243c010::vf5() {
    Unk_1443030(this);
}

class Unk_243c050 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x7101442f60
void Unk_243c050::vf0() {
    Unk_1443030(this);
}

class Unk_243c120 {
public:
    virtual ~Unk_243c120();
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
};

// 0x71014496d0
void Unk_243c120::vf6() {
    Unk_1449740(this);
}

class Unk_243c1b8 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x7101449700
void Unk_243c1b8::vf5() {
    Unk_1449740(this);
}

class Unk_243c1f8 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x7101449710
void Unk_243c1f8::vf0() {
    Unk_1449740(this);
}

class Unk_243c268 {
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

// 0x710144aab0
void Unk_243c268::vf6() {
    Unk_144aae0(this);
}

// 0x710144a570
u32 Unk_243c268::vf7() {
    return 1;
}

// 0x710144a580
void Unk_243c268::vf8() {}

// 0x710144a590
void Unk_243c268::vf10() {}

class Unk_243c2d0 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x710144aac0
void Unk_243c2d0::vf5() {
    Unk_144aae0(this);
}

class Unk_243c310 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x710144aad0
void Unk_243c310::vf0() {
    Unk_144aae0(this);
}

class Unk_243c378 {
public:
    virtual u32 vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
};

// 0x710144b290
u32 Unk_243c378::vf0() {
    return 1;
}

class Unk_243c458 {
public:
    virtual ~Unk_243c458();
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

// 0x710144b960
u32 Unk_243c458::vf20() {
    return 1;
}

// 0x710144be40
u32 Unk_243c458::vf25() {
    return 1;
}

class Unk_243c3a8 {
public:
    virtual ~Unk_243c3a8();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
};

// 0x710144c260
void Unk_243c3a8::vf6() {
    Unk_144c2d0(this);
}

class Unk_243c3f0 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x710144c290
void Unk_243c3f0::vf5() {
    Unk_144c2d0(this);
}

class Unk_243c430 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x710144c2a0
void Unk_243c430::vf0() {
    Unk_144c2d0(this);
}

class Unk_243c5a0 {
public:
    virtual ~Unk_243c5a0();
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

// 0x710144cbe0
void Unk_243c5a0::vf6() {
    Unk_144cc50(this);
}

// 0x710144cbc0
void Unk_243c5a0::vf9() {}

class Unk_243c608 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x710144cc10
void Unk_243c608::vf5() {
    Unk_144cc50(this);
}

class Unk_243c648 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x710144cc20
void Unk_243c648::vf0() {
    Unk_144cc50(this);
}

class Unk_243c670 {
public:
    virtual ~Unk_243c670();
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

// 0x710144d5e0
void Unk_243c670::vf6() {
    Unk_144d650(this);
}

// 0x710144d5c0
void Unk_243c670::vf9() {}

class Unk_243c6d8 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x710144d610
void Unk_243c6d8::vf5() {
    Unk_144d650(this);
}

class Unk_243c718 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x710144d620
void Unk_243c718::vf0() {
    Unk_144d650(this);
}
