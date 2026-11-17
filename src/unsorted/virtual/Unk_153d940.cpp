// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

// Called by forwarders. Placeholders: their real signatures aren't known.
void Unk_153dd60(void* self);
void Unk_153f430(void* self);
void Unk_15425a0(void* self);
void Unk_1542c50(void* self);
void Unk_1544450(void* self);
void Unk_1545350(void* self);
void Unk_1545da0(void* self);
void Unk_1546e70(void* self);
void Unk_15472f0(void* self);
void Unk_15476c0(void* self);
void Unk_1547cd0(void* self);
void Unk_15482e0(void* self);

class Unk_2449478 {
public:
    virtual ~Unk_2449478();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
};

// 0x710153d940
void Unk_2449478::vf6() {
    Unk_153dd60(this);
}

class Unk_24494c0 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x710153d950
void Unk_24494c0::vf5() {
    Unk_153dd60(this);
}

class Unk_2449500 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x710153d960
void Unk_2449500::vf0() {
    Unk_153dd60(this);
}

class Unk_2449670 {
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
};

// 0x7101541b10
void Unk_2449670::vf6() {
    Unk_153f430(this);
}

// 0x7101540510
void Unk_2449670::vf10() {}

class Unk_2449708 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x7101541c60
void Unk_2449708::vf5() {
    Unk_153f430(this);
}

class Unk_2449748 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x7101541c70
void Unk_2449748::vf0() {
    Unk_153f430(this);
}

class Unk_2449788 {
public:
    virtual ~Unk_2449788();
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

// 0x7101542530
void Unk_2449788::vf6() {
    Unk_15425a0(this);
}

// 0x7101542510
void Unk_2449788::vf9() {}

class Unk_24497f0 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x7101542560
void Unk_24497f0::vf5() {
    Unk_15425a0(this);
}

class Unk_2449830 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x7101542570
void Unk_2449830::vf0() {
    Unk_15425a0(this);
}

class Unk_2449870 {
public:
    virtual ~Unk_2449870();
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

// 0x7101542be0
void Unk_2449870::vf6() {
    Unk_1542c50(this);
}

// 0x7101542a80
void Unk_2449870::vf8() {}

// 0x7101542a90
void Unk_2449870::vf10() {}

// 0x7101542aa0
u32 Unk_2449870::vf16() {
    return 0;
}

class Unk_2449908 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x7101542c10
void Unk_2449908::vf5() {
    Unk_1542c50(this);
}

class Unk_2449948 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x7101542c20
void Unk_2449948::vf0() {
    Unk_1542c50(this);
}

class Unk_2449970 {
public:
    virtual ~Unk_2449970();
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

// 0x71015443e0
void Unk_2449970::vf6() {
    Unk_1544450(this);
}

// 0x71015434f0
void Unk_2449970::vf10() {}

// 0x7101543500
u32 Unk_2449970::vf16() {
    return 0;
}

class Unk_2449a08 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x7101544410
void Unk_2449a08::vf5() {
    Unk_1544450(this);
}

class Unk_2449a48 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x7101544420
void Unk_2449a48::vf0() {
    Unk_1544450(this);
}

class Unk_2449a70 {
public:
    virtual ~Unk_2449a70();
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

// 0x71015452e0
void Unk_2449a70::vf6() {
    Unk_1545350(this);
}

// 0x71015452c0
void Unk_2449a70::vf9() {}

class Unk_2449ad8 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x7101545310
void Unk_2449ad8::vf5() {
    Unk_1545350(this);
}

class Unk_2449b18 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x7101545320
void Unk_2449b18::vf0() {
    Unk_1545350(this);
}

class Unk_2449b70 {
public:
    virtual ~Unk_2449b70();
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

// 0x7101545d30
void Unk_2449b70::vf6() {
    Unk_1545da0(this);
}

// 0x7101545d10
void Unk_2449b70::vf9() {}

class Unk_2449bd8 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x7101545d60
void Unk_2449bd8::vf5() {
    Unk_1545da0(this);
}

class Unk_2449c18 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x7101545d70
void Unk_2449c18::vf0() {
    Unk_1545da0(this);
}

class Unk_2449c40 {
public:
    virtual ~Unk_2449c40();
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

// 0x7101546e00
void Unk_2449c40::vf6() {
    Unk_1546e70(this);
}

// 0x7101546de0
void Unk_2449c40::vf9() {}

class Unk_2449ca8 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x7101546e30
void Unk_2449ca8::vf5() {
    Unk_1546e70(this);
}

class Unk_2449ce8 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x7101546e40
void Unk_2449ce8::vf0() {
    Unk_1546e70(this);
}

class Unk_2449d10 {
public:
    virtual ~Unk_2449d10();
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

// 0x7101547280
void Unk_2449d10::vf6() {
    Unk_15472f0(this);
}

// 0x7101547260
void Unk_2449d10::vf9() {}

class Unk_2449d78 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x71015472b0
void Unk_2449d78::vf5() {
    Unk_15472f0(this);
}

class Unk_2449db8 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x71015472c0
void Unk_2449db8::vf0() {
    Unk_15472f0(this);
}

class Unk_2449de0 {
public:
    virtual ~Unk_2449de0();
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

// 0x7101547650
void Unk_2449de0::vf6() {
    Unk_15476c0(this);
}

// 0x7101547630
void Unk_2449de0::vf9() {}

class Unk_2449e48 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x7101547680
void Unk_2449e48::vf5() {
    Unk_15476c0(this);
}

class Unk_2449e88 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x7101547690
void Unk_2449e88::vf0() {
    Unk_15476c0(this);
}

class Unk_2449eb0 {
public:
    virtual ~Unk_2449eb0();
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

// 0x7101547c60
void Unk_2449eb0::vf6() {
    Unk_1547cd0(this);
}

// 0x7101547c40
void Unk_2449eb0::vf9() {}

class Unk_2449f18 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x7101547c90
void Unk_2449f18::vf5() {
    Unk_1547cd0(this);
}

class Unk_2449f58 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x7101547ca0
void Unk_2449f58::vf0() {
    Unk_1547cd0(this);
}

class Unk_2449f80 {
public:
    virtual ~Unk_2449f80();
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

// 0x7101548270
void Unk_2449f80::vf6() {
    Unk_15482e0(this);
}

class Unk_2449fe8 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x71015482a0
void Unk_2449fe8::vf5() {
    Unk_15482e0(this);
}

class Unk_244a028 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x71015482b0
void Unk_244a028::vf0() {
    Unk_15482e0(this);
}
