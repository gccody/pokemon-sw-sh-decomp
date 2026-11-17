// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

// Called by forwarders. Placeholders: their real signatures aren't known.
void Unk_bc7540(void* self);
void Unk_bc8a00(void* self);
void Unk_c1cdd0(void* self);
void Unk_c22600(void* self);

class Unk_23d4270 {
public:
    virtual ~Unk_23d4270();
    virtual void vf2();
};

// 0x7100bc7670, 0x7100bc7680
Unk_23d4270::~Unk_23d4270() {}

class Unk_23d4298 {
public:
    virtual ~Unk_23d4298();
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
};

// 0x7100bc7a80
void Unk_23d4298::vf12() {}

// 0x7100bc7a90
void Unk_23d4298::vf13() {}

class Unk_23d4318 {
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
};

// 0x7100bc7b30
void Unk_23d4318::vf10() {}

// 0x7100bc7b40
void Unk_23d4318::vf11() {}

class Unk_23d4470 {
public:
    virtual ~Unk_23d4470();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual u32 vf8();
};

// 0x7100bc9dd0
void Unk_23d4470::vf6() {
    Unk_bc8a00(this);
}

// 0x7100bc9de0
void Unk_23d4470::vf7() {}

// 0x7100bc9df0
u32 Unk_23d4470::vf8() {
    return 1;
}

class Unk_23d44c8 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x7100bc9e20
void Unk_23d44c8::vf5() {
    Unk_bc8a00(this);
}

class Unk_23d4508 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x7100bc9e30
void Unk_23d4508::vf0() {
    Unk_bc8a00(this);
}

class Unk_23d4530 {
public:
    virtual ~Unk_23d4530();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
};

// 0x7100bca310
void Unk_23d4530::vf7() {}

class Unk_23d4830 {
public:
    virtual ~Unk_23d4830();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
};

// 0x7100bcd300
void Unk_23d4830::vf7() {}

class Unk_23d4e78 {
public:
    virtual ~Unk_23d4e78();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
};

// 0x7100bd18e0
void Unk_23d4e78::vf7() {}

class Unk_23d5b38 {
public:
    virtual ~Unk_23d5b38();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
};

// 0x7100bdd270
void Unk_23d5b38::vf7() {}

class Unk_23d5ef8 {
public:
    virtual ~Unk_23d5ef8();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
};

// 0x7100bdf9c0
void Unk_23d5ef8::vf7() {}

class Unk_23d5fb8 {
public:
    virtual ~Unk_23d5fb8();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
};

// 0x7100bdff90
void Unk_23d5fb8::vf7() {}

class Unk_23d6078 {
public:
    virtual ~Unk_23d6078();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
};

// 0x7100be0560
void Unk_23d6078::vf7() {}

class Unk_23d6138 {
public:
    virtual ~Unk_23d6138();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual u32 vf8();
};

// 0x7100be0b60
void Unk_23d6138::vf7() {}

// 0x7100be0b70
u32 Unk_23d6138::vf8() {
    return 1;
}

class Unk_23d62b8 {
public:
    virtual ~Unk_23d62b8();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual u32 vf8();
};

// 0x7100be1370
u32 Unk_23d62b8::vf8() {
    return 1;
}

class Unk_23d65b8 {
public:
    virtual ~Unk_23d65b8();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual u32 vf8();
};

// 0x7100be4f70
void Unk_23d65b8::vf7() {}

// 0x7100be4f80
u32 Unk_23d65b8::vf8() {
    return 1;
}

class Unk_23d6728 {
public:
    virtual ~Unk_23d6728();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
};

// 0x7100be87c0
void Unk_23d6728::vf9() {}

class Unk_23d7420 {
public:
    virtual ~Unk_23d7420();
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
};

// 0x7100bf7340
void Unk_23d7420::vf13() {}

class Unk_23d74a0 {
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
};

// 0x7100bf7450
void Unk_23d74a0::vf11() {}

class Unk_23d7838 {
public:
    virtual ~Unk_23d7838();
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
};

// 0x7100bfd6d0
void Unk_23d7838::vf13() {}

class Unk_23d78b8 {
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
};

// 0x7100bfd7e0
void Unk_23d78b8::vf11() {}

class Unk_23d7ad8 {
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
};

// 0x7100bff6e0
void Unk_23d7ad8::vf10() {}

class Unk_23d7bc0 {
public:
    virtual ~Unk_23d7bc0();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
};

// 0x7100c008f0
void Unk_23d7bc0::vf4() {}

class Unk_23d7c08 {
public:
    virtual ~Unk_23d7c08();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
};

// 0x7100c00cc0
void Unk_23d7c08::vf4() {}

class Unk_23d7c50 {
public:
    virtual ~Unk_23d7c50();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
};

// 0x7100c00d60
void Unk_23d7c50::vf4() {}

class Unk_23d7c98 {
public:
    virtual ~Unk_23d7c98();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
};

// 0x7100c01110
void Unk_23d7c98::vf4() {}

class Unk_23d7ce0 {
public:
    virtual ~Unk_23d7ce0();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
};

// 0x7100c011b0
void Unk_23d7ce0::vf4() {}

class Unk_23d7d28 {
public:
    virtual ~Unk_23d7d28();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
};

// 0x7100c01440
void Unk_23d7d28::vf4() {}

class Unk_23d7d70 {
public:
    virtual ~Unk_23d7d70();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
};

// 0x7100c01500
void Unk_23d7d70::vf4() {}

class Unk_23d7db8 {
public:
    virtual ~Unk_23d7db8();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
};

// 0x7100c015b0
void Unk_23d7db8::vf4() {}

class Unk_23d7ee8 {
public:
    virtual ~Unk_23d7ee8();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
};

// 0x7100c03600
void Unk_23d7ee8::vf4() {}

class Unk_23d7f30 {
public:
    virtual ~Unk_23d7f30();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
};

// 0x7100c04290
void Unk_23d7f30::vf4() {}

class Unk_23d8878 {
public:
    virtual ~Unk_23d8878();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
};

// 0x7100c09850
void Unk_23d8878::vf4() {}

class Unk_23d88c0 {
public:
    virtual ~Unk_23d88c0();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
};

// 0x7100c09ad0
void Unk_23d88c0::vf4() {}

class Unk_23d8908 {
public:
    virtual ~Unk_23d8908();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
};

// 0x7100c09ef0
void Unk_23d8908::vf4() {}

class Unk_23d8a10 {
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
};

// 0x7100c0aac0
void Unk_23d8a10::vf10() {}

class Unk_23d8af8 {
public:
    virtual ~Unk_23d8af8();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
};

// 0x7100c0b730
void Unk_23d8af8::vf4() {}

class Unk_23d8b40 {
public:
    virtual ~Unk_23d8b40();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
};

// 0x7100c0ba10
void Unk_23d8b40::vf4() {}

class Unk_23d8b88 {
public:
    virtual ~Unk_23d8b88();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
};

// 0x7100c0bab0
void Unk_23d8b88::vf4() {}

class Unk_23d8bd0 {
public:
    virtual ~Unk_23d8bd0();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
};

// 0x7100c0bd70
void Unk_23d8bd0::vf4() {}

class Unk_23d8c18 {
public:
    virtual ~Unk_23d8c18();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
};

// 0x7100c0be10
void Unk_23d8c18::vf4() {}

class Unk_23d8c60 {
public:
    virtual ~Unk_23d8c60();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
};

// 0x7100c0c020
void Unk_23d8c60::vf4() {}

class Unk_23d8ca8 {
public:
    virtual ~Unk_23d8ca8();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
};

// 0x7100c0c0c0
void Unk_23d8ca8::vf4() {}

class Unk_23d9740 {
public:
    virtual u32 vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
};

// 0x7100c18a10
u32 Unk_23d9740::vf0() {
    return 2;
}

class Unk_23d9770 {
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
};

// 0x7100c18cf0
void Unk_23d9770::vf7() {}

// 0x7100c18d00
void Unk_23d9770::vf8() {}

class Unk_23d9830 {
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
};

// 0x7100c1ac70
void Unk_23d9830::vf6() {
    Unk_bc7540(this);
}

// 0x7100c1ac80
void Unk_23d9830::vf8() {}

class Unk_23d98a8 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x7100c1ae50
void Unk_23d98a8::vf5() {
    Unk_bc7540(this);
}

class Unk_23d98e8 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x7100c1ae60
void Unk_23d98e8::vf0() {
    Unk_bc7540(this);
}

class Unk_23d9978 {
public:
    virtual u32 vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
};

// 0x7100c1c170
u32 Unk_23d9978::vf0() {
    return 1;
}

class Unk_23d9ab8 {
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
};

// 0x7100c1ca60
void Unk_23d9ab8::vf6() {
    Unk_c1cdd0(this);
}

class Unk_23d9b38 {
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
};

// 0x7100c1cc10
void Unk_23d9b38::vf5() {
    Unk_c1cdd0(this);
}

class Unk_23d9ba8 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x7100c1cc20
void Unk_23d9ba8::vf0() {
    Unk_c1cdd0(this);
}

class Unk_23d9d00 {
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

// 0x7100c22450
void Unk_23d9d00::vf6() {
    Unk_c22600(this);
}

// 0x7100c22020
u32 Unk_23d9d00::vf7() {
    return 1;
}

class Unk_23d9d68 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x7100c22520
void Unk_23d9d68::vf5() {
    Unk_c22600(this);
}

class Unk_23d9da8 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x7100c22530
void Unk_23d9da8::vf0() {
    Unk_c22600(this);
}

class Unk_23d9e10 {
public:
    virtual u32 vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
};

// 0x7100c22db0
u32 Unk_23d9e10::vf0() {
    return 1;
}
