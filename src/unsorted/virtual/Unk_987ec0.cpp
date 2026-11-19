// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>
#include "unsorted/Unk_23c44f8.h"
#include "unsorted/Unk_23d4470.h"

// Called by forwarders. Placeholders: their real signatures aren't known.
void Unk_9895d0(void* self);
void Unk_98dd50(void* self);
void Unk_98ed90(void* self);

// Tail-called by lifted functions. Placeholders, like the forwarders' callees.
void Unk_9a76e0(u64);

class Unk_23c2358 {
public:
    virtual ~Unk_23c2358();
};

// 0x7100987ec0, 0x7100987ed0
Unk_23c2358::~Unk_23c2358() {}

class Unk_23c2378 {
public:
    virtual ~Unk_23c2378();
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
    virtual void vf32();
    virtual void vf33();
    virtual void vf34();
    virtual void vf35();
    virtual void vf36();
    virtual void vf37();
    virtual void vf38();
    virtual void vf39();
    virtual void vf40();
    virtual void vf41();
    virtual void vf42();
    virtual void vf43();
    virtual void vf44();
    virtual void vf45();
    virtual void vf46();
    virtual void vf47();
    virtual void vf48();
    virtual void vf49();
    virtual void vf50();
    virtual void vf51();
    virtual void vf52();
    virtual void vf53();
    virtual void vf54();
    virtual void vf55();
    virtual void vf56();
    virtual void vf57();
    virtual void vf58();
    virtual void vf59();
    virtual void vf60();
    virtual void vf61();
    virtual void vf62();
    virtual void vf63();
    virtual void vf64();
    virtual void vf65();
    virtual void vf66();
    virtual void vf67();
    virtual void vf68();
    virtual void vf69();
};

// 0x7100989560
void Unk_23c2378::vf6() {
    Unk_9895d0(this);
}

class Unk_23c25b8 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x7100989590
void Unk_23c25b8::vf5() {
    Unk_9895d0(this);
}

class Unk_23c25f8 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x71009895a0
void Unk_23c25f8::vf0() {
    Unk_9895d0(this);
}

class Unk_23c2640 {
public:
    virtual ~Unk_23c2640();
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
    virtual void vf32();
    virtual void vf33();
    virtual void vf34();
    virtual void vf35();
    virtual void vf36();
    virtual void vf37();
    virtual void vf38();
    virtual void vf39();
    virtual void vf40();
    virtual void vf41();
    virtual void vf42();
    virtual void vf43();
    virtual void vf44();
    virtual void vf45();
    virtual void vf46();
    virtual void vf47();
    virtual void vf48();
    virtual void vf49();
    virtual void vf50();
    virtual void vf51();
    virtual void vf52();
    virtual void vf53();
    virtual void vf54();
    virtual void vf55();
    virtual void vf56();
    virtual void vf57();
    virtual void vf58();
    virtual void vf59();
    virtual void vf60();
    virtual void vf61();
    virtual void vf62();
    virtual void vf63();
    virtual void vf64();
    virtual void vf65();
    virtual u32 vf66();
    virtual u8 vf67();
    virtual void vf68();
    virtual void vf69();
    u8 _8[0x4a8];
    u32 field_4b0;
    u8 field_4b4;
};
PKMN_OFFSET_ASSERT(Unk_23c2640, field_4b0, 0x4b0);
PKMN_OFFSET_ASSERT(Unk_23c2640, field_4b4, 0x4b4);

// 0x710098dc70
void Unk_23c2640::vf6() {
    Unk_98dd50(this);
}

// 0x710098dc80
u32 Unk_23c2640::vf66() {
    return field_4b0;
}

// 0x710098dc90
u8 Unk_23c2640::vf67() {
    return field_4b4;
}

class Unk_23c2880 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x710098dd10
void Unk_23c2880::vf5() {
    Unk_98dd50(this);
}

class Unk_23c28c0 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x710098dd20
void Unk_23c28c0::vf0() {
    Unk_98dd50(this);
}

class Unk_23c28e8 {
public:
    virtual ~Unk_23c28e8();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
};

// 0x710098def0
void Unk_23c28e8::vf4() {}

// 0x710098df00
void Unk_23c28e8::vf5() {
    ::operator delete(this);
}

class Unk_23c2930 {
public:
    virtual ~Unk_23c2930();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
};

// 0x710098e040
void Unk_23c2930::vf4() {}

// 0x710098e050
void Unk_23c2930::vf5() {
    ::operator delete(this);
}

class Unk_23c2978 {
public:
    virtual ~Unk_23c2978();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
};

// 0x710098e140
void Unk_23c2978::vf4() {}

// 0x710098e150
void Unk_23c2978::vf5() {
    ::operator delete(this);
}

class Unk_23c29c0 {
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
    virtual void vf32();
    virtual void vf33();
    virtual void vf34();
    virtual void vf35();
    virtual void vf36();
    virtual void vf37();
    virtual void vf38();
    virtual void vf39();
    virtual void vf40();
    virtual void vf41();
    virtual void vf42();
    virtual void vf43();
    virtual void vf44();
    virtual void vf45();
    virtual void vf46();
    virtual void vf47();
    virtual void vf48();
    virtual void vf49();
    virtual void vf50();
    virtual void vf51();
    virtual void vf52();
    virtual void vf53();
    virtual void vf54();
    virtual void vf55();
    virtual void vf56();
    virtual void vf57();
    virtual void vf58();
    virtual void vf59();
    virtual void vf60();
    virtual void vf61();
    virtual void vf62();
    virtual void vf63();
    virtual void vf64();
    virtual void vf65();
    virtual void vf66();
    virtual void vf67();
    virtual void vf68();
    virtual void vf69();
};

// 0x710098e9a0
void Unk_23c29c0::vf6() {
    Unk_98ed90(this);
}

// 0x710098e820
void Unk_23c29c0::vf48() {}

class Unk_23c2c00 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x710098eb90
void Unk_23c2c00::vf5() {
    Unk_98ed90(this);
}

class Unk_23c2c40 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x710098eba0
void Unk_23c2c40::vf0() {
    Unk_98ed90(this);
}

class Unk_23c2d20 : public Unk_23c44f8 {
public:
    ~Unk_23c2d20() override;
    void vf7(s32) override;
    Unk_239a418_Ref<Unk_239a418> field_80;
};
PKMN_OFFSET_ASSERT(Unk_23c2d20, field_80, 0x80);

// 0x7100999cd0: its key function
Unk_23c2d20::~Unk_23c2d20() {}

class Unk_23c2dd8 : public Unk_23c44f8 {
public:
    ~Unk_23c2dd8() override;
    void vf7(s32) override;
    Unk_239a418_Ref<Unk_239a418> field_80;
};
PKMN_OFFSET_ASSERT(Unk_23c2dd8, field_80, 0x80);

// 0x710099a270: its key function
Unk_23c2dd8::~Unk_23c2dd8() {}

class Unk_23c2e90 : public Unk_23c44f8 {
public:
    ~Unk_23c2e90() override;
    void vf7(s32) override;
    Unk_23d4470_Callable field_80;
};
PKMN_OFFSET_ASSERT(Unk_23c2e90, field_80, 0x80);

// 0x710099a810: its key function
Unk_23c2e90::~Unk_23c2e90() {}

class Unk_23c2f48 : public Unk_23c44f8 {
public:
    ~Unk_23c2f48() override;
    void vf7(s32) override;
    Unk_23d4470_Callable field_80;
};
PKMN_OFFSET_ASSERT(Unk_23c2f48, field_80, 0x80);

// 0x710099adb0: its key function
Unk_23c2f48::~Unk_23c2f48() {}

class Unk_23c3000 : public Unk_23c44f8 {
public:
    ~Unk_23c3000() override;
    void vf7(s32) override;
    Unk_23d4470_Callable field_80;
};
PKMN_OFFSET_ASSERT(Unk_23c3000, field_80, 0x80);

// 0x710099b350: its key function
Unk_23c3000::~Unk_23c3000() {}

class Unk_23c30b8 : public Unk_23c44f8 {
public:
    ~Unk_23c30b8() override;
    void vf7(s32) override;
    Unk_23d4470_Callable field_80;
};
PKMN_OFFSET_ASSERT(Unk_23c30b8, field_80, 0x80);

// 0x710099b8f0: its key function
Unk_23c30b8::~Unk_23c30b8() {}

class Unk_23c3228 : public Unk_23c44f8 {
public:
    ~Unk_23c3228() override;
    void vf7(s32) override;
    u8 _80[0x10];
    Unk_23d4470_Callable field_90;
    Unk_23d4470_Callable field_110;
};
PKMN_OFFSET_ASSERT(Unk_23c3228, field_90, 0x90);
PKMN_OFFSET_ASSERT(Unk_23c3228, field_110, 0x110);

// 0x710099c550: its key function
Unk_23c3228::~Unk_23c3228() {}

class Unk_23c3508 : public Unk_23c44f8 {
public:
    ~Unk_23c3508() override;
    void vf7(s32) override;
    Unk_239a418_Ref<Unk_239a418> field_80;
};
PKMN_OFFSET_ASSERT(Unk_23c3508, field_80, 0x80);

// 0x710099d750: its key function
Unk_23c3508::~Unk_23c3508() {}

class Unk_23c35c0 : public Unk_23c44f8 {
public:
    ~Unk_23c35c0() override;
    void vf7(s32) override;
    Unk_239a418_Ref<Unk_239a418> field_80;
};
PKMN_OFFSET_ASSERT(Unk_23c35c0, field_80, 0x80);

// 0x710099dcf0: its key function
Unk_23c35c0::~Unk_23c35c0() {}

class Unk_23c3678 : public Unk_23c44f8 {
public:
    ~Unk_23c3678() override;
    void vf7(s32) override;
    Unk_239a418_Ref<Unk_239a418> field_80;
};
PKMN_OFFSET_ASSERT(Unk_23c3678, field_80, 0x80);

// 0x710099e290: its key function
Unk_23c3678::~Unk_23c3678() {}

class Unk_23c3730 : public Unk_23c44f8 {
public:
    ~Unk_23c3730() override;
    void vf7(s32) override;
    Unk_239a418_Ref<Unk_239a418> field_80;
};
PKMN_OFFSET_ASSERT(Unk_23c3730, field_80, 0x80);

// 0x710099e830: its key function
Unk_23c3730::~Unk_23c3730() {}

class Unk_23c37e8 : public Unk_23c44f8 {
public:
    ~Unk_23c37e8() override;
    void vf7(s32) override;
    Unk_239a418_Ref<Unk_239a418> field_80;
};
PKMN_OFFSET_ASSERT(Unk_23c37e8, field_80, 0x80);

// 0x710099edd0: its key function
Unk_23c37e8::~Unk_23c37e8() {}

class Unk_23c38a0 : public Unk_23c44f8 {
public:
    ~Unk_23c38a0() override;
    void vf7(s32) override;
    Unk_239a418_Ref<Unk_239a418> field_80;
};
PKMN_OFFSET_ASSERT(Unk_23c38a0, field_80, 0x80);

// 0x710099f370: its key function
Unk_23c38a0::~Unk_23c38a0() {}

class Unk_23c3958 : public Unk_23c44f8 {
public:
    ~Unk_23c3958() override;
    void vf7(s32) override;
    Unk_239a418_Ref<Unk_239a418> field_80;
};
PKMN_OFFSET_ASSERT(Unk_23c3958, field_80, 0x80);

// 0x710099f910: its key function
Unk_23c3958::~Unk_23c3958() {}

class Unk_23c3a10 : public Unk_23c44f8 {
public:
    ~Unk_23c3a10() override;
    void vf7(s32) override;
    Unk_239a418_Ref<Unk_239a418> field_80;
};
PKMN_OFFSET_ASSERT(Unk_23c3a10, field_80, 0x80);

// 0x710099feb0: its key function
Unk_23c3a10::~Unk_23c3a10() {}

class Unk_23c3b80 : public Unk_23c44f8 {
public:
    ~Unk_23c3b80() override;
    void vf7(s32) override;
    Unk_239a418_Ref<Unk_239a418> field_80;
};
PKMN_OFFSET_ASSERT(Unk_23c3b80, field_80, 0x80);

// 0x71009a0810: its key function
Unk_23c3b80::~Unk_23c3b80() {}

class Unk_23c3c38 : public Unk_23c44f8 {
public:
    ~Unk_23c3c38() override;
    void vf7(s32) override;
    Unk_239a418_Ref<Unk_239a418> field_80;
};
PKMN_OFFSET_ASSERT(Unk_23c3c38, field_80, 0x80);

// 0x71009a0db0: its key function
Unk_23c3c38::~Unk_23c3c38() {}

class Unk_23c3cf0 : public Unk_23c44f8 {
public:
    ~Unk_23c3cf0() override;
    void vf7(s32) override;
    Unk_239a418_Ref<Unk_239a418> field_80;
};
PKMN_OFFSET_ASSERT(Unk_23c3cf0, field_80, 0x80);

// 0x71009a1350: its key function
Unk_23c3cf0::~Unk_23c3cf0() {}

class Unk_23c3da8 : public Unk_23c44f8 {
public:
    ~Unk_23c3da8() override;
    void vf7(s32) override;
    Unk_23d4470_Callable field_80;
};
PKMN_OFFSET_ASSERT(Unk_23c3da8, field_80, 0x80);

// 0x71009a18f0: its key function
Unk_23c3da8::~Unk_23c3da8() {}

class Unk_23c3e60 : public Unk_23c44f8 {
public:
    ~Unk_23c3e60() override;
    void vf7(s32) override;
    Unk_23d4470_Callable field_80;
};
PKMN_OFFSET_ASSERT(Unk_23c3e60, field_80, 0x80);

// 0x71009a1e90: its key function
Unk_23c3e60::~Unk_23c3e60() {}

class Unk_23c3f18 : public Unk_23c44f8 {
public:
    ~Unk_23c3f18() override;
    void vf7(s32) override;
    Unk_239a418_Ref<Unk_239a418> field_80;
};
PKMN_OFFSET_ASSERT(Unk_23c3f18, field_80, 0x80);

// 0x71009a2430: its key function
Unk_23c3f18::~Unk_23c3f18() {}

class Unk_23c3fd0 : public Unk_23c44f8 {
public:
    ~Unk_23c3fd0() override;
    void vf7(s32) override;
    u8 _80[0x8];
    Unk_239a418_Ref<Unk_239a418> field_88;
};
PKMN_OFFSET_ASSERT(Unk_23c3fd0, field_88, 0x88);

// 0x71009a29d0: its key function
Unk_23c3fd0::~Unk_23c3fd0() {}

class Unk_23c45d0 {
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
    u8 _8[0x70];
    u64 field_78;
};
PKMN_OFFSET_ASSERT(Unk_23c45d0, field_78, 0x78);

// 0x71009ac5e0
void Unk_23c45d0::vf12() {}

// 0x71009ac600
void Unk_23c45d0::vf13() {
    Unk_9a76e0(field_78);
}

class Unk_23c4650 {
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
    u8 _8[0x28];
    u64 field_30;
};
PKMN_OFFSET_ASSERT(Unk_23c4650, field_30, 0x30);

// 0x71009ac5f0
void Unk_23c4650::vf10() {}

// 0x71009ac610
void Unk_23c4650::vf11() {
    Unk_9a76e0(field_30);
}

class Unk_23c4728 {
public:
    virtual ~Unk_23c4728();
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

// 0x71009acf50
void Unk_23c4728::vf13() {}

class Unk_23c47a8 {
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

// 0x71009ad060
void Unk_23c47a8::vf11() {}
