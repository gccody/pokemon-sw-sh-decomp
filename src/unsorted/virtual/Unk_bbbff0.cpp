// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>
#include "unsorted/Unk_23d4470.h"

#include "unsorted/Unk_23d4470.inl"

// Tail-called by lifted functions. Placeholders, like the forwarders' callees.
void Unk_ba7db0(u64);
void Unk_bc17c0(u64, u64, u64, u32);
void Unk_140b690(u64, void*, u32);
void Unk_140bd70(u64, void*, u32);

class Unk_23d3f58 {
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
    u8 _8[0x190];
    u64 field_198;
};
PKMN_OFFSET_ASSERT(Unk_23d3f58, field_198, 0x198);

// 0x7100bbbff0
void Unk_23d3f58::vf9() {
    Unk_ba7db0(field_198);
}

class Unk_23d4028 {
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
    u8 _8[0x190];
    u64 field_198;
};
PKMN_OFFSET_ASSERT(Unk_23d4028, field_198, 0x198);

// 0x7100bbe9e0
void Unk_23d4028::vf9() {
    Unk_ba7db0(field_198);
}

class Unk_23d4270 {
public:
    virtual ~Unk_23d4270();
    virtual void vf2(u64 value, u64 arg2);
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_23d4270, field_8, 0x8);

// 0x7100bc7670, 0x7100bc7680
Unk_23d4270::~Unk_23d4270() {}

// 0x7100bc7690
void Unk_23d4270::vf2(u64 value, u64 arg2) {
    Unk_bc17c0(field_8, value, arg2, 0);
}

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

class Unk_23d43b0 : public Unk_23d4470 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23d4470::Unk_GetType());
        return &type;
    }

    const Unk_239a418_Type* vf_type() override;
    void vf7(u64, const Unk_23d4470_Desc&) override;
    u32 vf8() override;
};

// 0x7100bc9b80
const Unk_239a418_Type* Unk_23d43b0::vf_type() {
    return Unk_GetType();
}

class Unk_23d4530 : public Unk_23d4470 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23d4470::Unk_GetType());
        return &type;
    }

    const Unk_239a418_Type* vf_type() override;
    void vf7(u64, const Unk_23d4470_Desc&) override;
    u32 vf8() override;
};

// 0x7100bca2a0
const Unk_239a418_Type* Unk_23d4530::vf_type() {
    return Unk_GetType();
}

// 0x7100bca310
void Unk_23d4530::vf7(u64, const Unk_23d4470_Desc&) {}

class Unk_23d45f0 : public Unk_23d4470 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23d4470::Unk_GetType());
        return &type;
    }

    const Unk_239a418_Type* vf_type() override;
    void vf7(u64, const Unk_23d4470_Desc&) override;
    u32 vf8() override;
};

// 0x7100bcabc0
const Unk_239a418_Type* Unk_23d45f0::vf_type() {
    return Unk_GetType();
}

class Unk_23d46b0 : public Unk_23d4470 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23d4470::Unk_GetType());
        return &type;
    }

    const Unk_239a418_Type* vf_type() override;
    void vf7(u64, const Unk_23d4470_Desc&) override;
    u32 vf8() override;
};

// 0x7100bcb410
const Unk_239a418_Type* Unk_23d46b0::vf_type() {
    return Unk_GetType();
}

class Unk_23d4770 : public Unk_23d4470 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23d4470::Unk_GetType());
        return &type;
    }

    const Unk_239a418_Type* vf_type() override;
    void vf7(u64, const Unk_23d4470_Desc&) override;
    u32 vf8() override;
    u8 _348[0x20];
    u64 _368;
    Unk_239a418_Ref<Unk_239a418> field_370;
    u64 _378;
    u64 _380;
    u64 _388;
    u64 _390;
    u64 _398;
    u64 _3a0;
    u64 _3a8;
    Unk_239a418_Ref<Unk_239a418> field_3b0;
};
PKMN_OFFSET_ASSERT(Unk_23d4770, field_370, 0x370);
PKMN_OFFSET_ASSERT(Unk_23d4770, field_3b0, 0x3b0);

// 0x7100bcbd30
const Unk_239a418_Type* Unk_23d4770::vf_type() {
    return Unk_GetType();
}

class Unk_23d4830 : public Unk_23d4470 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23d4470::Unk_GetType());
        return &type;
    }

    const Unk_239a418_Type* vf_type() override;
    void vf7(u64, const Unk_23d4470_Desc&) override;
    u32 vf8() override;
};

// 0x7100bcd290
const Unk_239a418_Type* Unk_23d4830::vf_type() {
    return Unk_GetType();
}

// 0x7100bcd300
void Unk_23d4830::vf7(u64, const Unk_23d4470_Desc&) {}

class Unk_23d48f0 : public Unk_23d4470 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23d4470::Unk_GetType());
        return &type;
    }

    const Unk_239a418_Type* vf_type() override;
    void vf7(u64, const Unk_23d4470_Desc&) override;
    u32 vf8() override;
};

// 0x7100bcd860
const Unk_239a418_Type* Unk_23d48f0::vf_type() {
    return Unk_GetType();
}

class Unk_23d49b0 : public Unk_23d4470 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23d4470::Unk_GetType());
        return &type;
    }

    const Unk_239a418_Type* vf_type() override;
    void vf7(u64, const Unk_23d4470_Desc&) override;
    u32 vf8() override;
    u8 _348[0x20];
    Unk_239a418_Ref<Unk_239a418> field_368;
};
PKMN_OFFSET_ASSERT(Unk_23d49b0, field_368, 0x368);

// 0x7100bce0a0
const Unk_239a418_Type* Unk_23d49b0::vf_type() {
    return Unk_GetType();
}

class Unk_23d4a70 : public Unk_23d4470 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23d4470::Unk_GetType());
        return &type;
    }

    const Unk_239a418_Type* vf_type() override;
    void vf7(u64, const Unk_23d4470_Desc&) override;
    u32 vf8() override;
    u8 _348[0x20];
    Unk_239a418_Ref<Unk_239a418> field_368;
};
PKMN_OFFSET_ASSERT(Unk_23d4a70, field_368, 0x368);

// 0x7100bcea40
const Unk_239a418_Type* Unk_23d4a70::vf_type() {
    return Unk_GetType();
}

// The type between Unk_23d4470 and Unk_23d4b50 (its class isn't known yet).
struct Unk_27d8c38 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23d4470::Unk_GetType());
        return &type;
    }
};

class Unk_23d4b50 : public Unk_23d4470 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_27d8c38::Unk_GetType());
        return &type;
    }

    const Unk_239a418_Type* vf_type() override;
    void vf7(u64, const Unk_23d4470_Desc&) override;
    u32 vf8() override;
    virtual void vf9();
};

// 0x7100bcfcb0
const Unk_239a418_Type* Unk_23d4b50::vf_type() {
    return Unk_GetType();
}

class Unk_23d4cf8 : public Unk_23d4470 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23d4470::Unk_GetType());
        return &type;
    }

    const Unk_239a418_Type* vf_type() override;
    void vf7(u64, const Unk_23d4470_Desc&) override;
    u32 vf8() override;
};

// 0x7100bd0e60
const Unk_239a418_Type* Unk_23d4cf8::vf_type() {
    return Unk_GetType();
}

class Unk_23d4db8 : public Unk_23d4470 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23d4470::Unk_GetType());
        return &type;
    }

    const Unk_239a418_Type* vf_type() override;
    u32 vf8() override;
};

// 0x7100bd1460
const Unk_239a418_Type* Unk_23d4db8::vf_type() {
    return Unk_GetType();
}

class Unk_23d4e78 : public Unk_23d4470 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23d4470::Unk_GetType());
        return &type;
    }

    const Unk_239a418_Type* vf_type() override;
    void vf7(u64, const Unk_23d4470_Desc&) override;
    u32 vf8() override;
};

// 0x7100bd1870
const Unk_239a418_Type* Unk_23d4e78::vf_type() {
    return Unk_GetType();
}

// 0x7100bd18e0
void Unk_23d4e78::vf7(u64, const Unk_23d4470_Desc&) {}

class Unk_23d4f38 : public Unk_23d4470 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23d4470::Unk_GetType());
        return &type;
    }

    const Unk_239a418_Type* vf_type() override;
    void vf7(u64, const Unk_23d4470_Desc&) override;
    u32 vf8() override;
};

// 0x7100bd1ee0
const Unk_239a418_Type* Unk_23d4f38::vf_type() {
    return Unk_GetType();
}

class Unk_23d4ff8 : public Unk_23d4470 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23d4470::Unk_GetType());
        return &type;
    }

    const Unk_239a418_Type* vf_type() override;
    void vf7(u64, const Unk_23d4470_Desc&) override;
};

// 0x7100bd3400
const Unk_239a418_Type* Unk_23d4ff8::vf_type() {
    return Unk_GetType();
}

class Unk_23d5238 : public Unk_23d4470 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23d4470::Unk_GetType());
        return &type;
    }

    const Unk_239a418_Type* vf_type() override;
    void vf7(u64, const Unk_23d4470_Desc&) override;
    u32 vf8() override;
};

// 0x7100bd6070
const Unk_239a418_Type* Unk_23d5238::vf_type() {
    return Unk_GetType();
}

class Unk_23d52f8 : public Unk_23d4470 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23d4470::Unk_GetType());
        return &type;
    }

    const Unk_239a418_Type* vf_type() override;
    void vf7(u64, const Unk_23d4470_Desc&) override;
    u32 vf8() override;
};

// 0x7100bd7150
const Unk_239a418_Type* Unk_23d52f8::vf_type() {
    return Unk_GetType();
}

class Unk_23d53b8 : public Unk_23d4470 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23d4470::Unk_GetType());
        return &type;
    }

    const Unk_239a418_Type* vf_type() override;
    void vf7(u64, const Unk_23d4470_Desc&) override;
    u32 vf8() override;
};

// 0x7100bd78d0
const Unk_239a418_Type* Unk_23d53b8::vf_type() {
    return Unk_GetType();
}

class Unk_23d5478 : public Unk_23d4470 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23d4470::Unk_GetType());
        return &type;
    }

    const Unk_239a418_Type* vf_type() override;
    void vf7(u64, const Unk_23d4470_Desc&) override;
    u32 vf8() override;
};

// 0x7100bd7df0
const Unk_239a418_Type* Unk_23d5478::vf_type() {
    return Unk_GetType();
}

class Unk_23d5538 : public Unk_23d4470 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23d4470::Unk_GetType());
        return &type;
    }

    const Unk_239a418_Type* vf_type() override;
    void vf7(u64, const Unk_23d4470_Desc&) override;
    u32 vf8() override;
};

// 0x7100bd8440
const Unk_239a418_Type* Unk_23d5538::vf_type() {
    return Unk_GetType();
}

class Unk_23d55f8 : public Unk_23d4470 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23d4470::Unk_GetType());
        return &type;
    }

    const Unk_239a418_Type* vf_type() override;
    void vf7(u64, const Unk_23d4470_Desc&) override;
    u32 vf8() override;
};

// 0x7100bd8c90
const Unk_239a418_Type* Unk_23d55f8::vf_type() {
    return Unk_GetType();
}

class Unk_23d5778 : public Unk_23d4470 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23d4470::Unk_GetType());
        return &type;
    }

    const Unk_239a418_Type* vf_type() override;
    void vf7(u64, const Unk_23d4470_Desc&) override;
    u32 vf8() override;
    Unk_239a418_Ref<Unk_239a418> field_348;
};
PKMN_OFFSET_ASSERT(Unk_23d5778, field_348, 0x348);

// 0x7100bda130
const Unk_239a418_Type* Unk_23d5778::vf_type() {
    return Unk_GetType();
}

class Unk_23d5838 : public Unk_23d4470 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23d4470::Unk_GetType());
        return &type;
    }

    const Unk_239a418_Type* vf_type() override;
    void vf7(u64, const Unk_23d4470_Desc&) override;
    u32 vf8() override;
    Unk_239a418_Ref<Unk_239a418> field_348;
};
PKMN_OFFSET_ASSERT(Unk_23d5838, field_348, 0x348);

// 0x7100bdaa50
const Unk_239a418_Type* Unk_23d5838::vf_type() {
    return Unk_GetType();
}

class Unk_23d58f8 : public Unk_23d4470 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23d4470::Unk_GetType());
        return &type;
    }

    const Unk_239a418_Type* vf_type() override;
    void vf7(u64, const Unk_23d4470_Desc&) override;
    u32 vf8() override;
    Unk_239a418_Ref<Unk_239a418> field_348;
};
PKMN_OFFSET_ASSERT(Unk_23d58f8, field_348, 0x348);

// 0x7100bdb6d0
const Unk_239a418_Type* Unk_23d58f8::vf_type() {
    return Unk_GetType();
}

class Unk_23d59b8 : public Unk_23d4470 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23d4470::Unk_GetType());
        return &type;
    }

    const Unk_239a418_Type* vf_type() override;
    void vf7(u64, const Unk_23d4470_Desc&) override;
    u32 vf8() override;
    Unk_239a418_Ref<Unk_239a418> field_348;
};
PKMN_OFFSET_ASSERT(Unk_23d59b8, field_348, 0x348);

// 0x7100bdbfe0
const Unk_239a418_Type* Unk_23d59b8::vf_type() {
    return Unk_GetType();
}

class Unk_23d5a78 : public Unk_23d4470 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23d4470::Unk_GetType());
        return &type;
    }

    const Unk_239a418_Type* vf_type() override;
    void vf7(u64, const Unk_23d4470_Desc&) override;
    u32 vf8() override;
    Unk_239a418_Ref<Unk_239a418> field_348;
};
PKMN_OFFSET_ASSERT(Unk_23d5a78, field_348, 0x348);

// 0x7100bdc9a0
const Unk_239a418_Type* Unk_23d5a78::vf_type() {
    return Unk_GetType();
}

class Unk_23d5b38 : public Unk_23d4470 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23d4470::Unk_GetType());
        return &type;
    }

    const Unk_239a418_Type* vf_type() override;
    void vf7(u64, const Unk_23d4470_Desc&) override;
    u32 vf8() override;
};

// 0x7100bdd200
const Unk_239a418_Type* Unk_23d5b38::vf_type() {
    return Unk_GetType();
}

// 0x7100bdd270
void Unk_23d5b38::vf7(u64, const Unk_23d4470_Desc&) {}

class Unk_23d5bf8 : public Unk_23d4470 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23d4470::Unk_GetType());
        return &type;
    }

    const Unk_239a418_Type* vf_type() override;
    void vf7(u64, const Unk_23d4470_Desc&) override;
    u32 vf8() override;
};

// 0x7100bdd770
const Unk_239a418_Type* Unk_23d5bf8::vf_type() {
    return Unk_GetType();
}

class Unk_23d5cb8 : public Unk_23d4470 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23d4470::Unk_GetType());
        return &type;
    }

    const Unk_239a418_Type* vf_type() override;
    void vf7(u64, const Unk_23d4470_Desc&) override;
    u32 vf8() override;
};

// 0x7100bde1b0
const Unk_239a418_Type* Unk_23d5cb8::vf_type() {
    return Unk_GetType();
}

class Unk_23d5d78 : public Unk_23d4470 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23d4470::Unk_GetType());
        return &type;
    }

    const Unk_239a418_Type* vf_type() override;
    void vf7(u64, const Unk_23d4470_Desc&) override;
    u32 vf8() override;
};

// 0x7100bdeed0
const Unk_239a418_Type* Unk_23d5d78::vf_type() {
    return Unk_GetType();
}

class Unk_23d5e38 : public Unk_23d4470 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23d4470::Unk_GetType());
        return &type;
    }

    const Unk_239a418_Type* vf_type() override;
    void vf7(u64, const Unk_23d4470_Desc&) override;
    u32 vf8() override;
};

// 0x7100bdf540
const Unk_239a418_Type* Unk_23d5e38::vf_type() {
    return Unk_GetType();
}

class Unk_23d5ef8 : public Unk_23d4470 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23d4470::Unk_GetType());
        return &type;
    }

    const Unk_239a418_Type* vf_type() override;
    void vf7(u64, const Unk_23d4470_Desc&) override;
    u32 vf8() override;
};

// 0x7100bdf950
const Unk_239a418_Type* Unk_23d5ef8::vf_type() {
    return Unk_GetType();
}

// 0x7100bdf9c0
void Unk_23d5ef8::vf7(u64, const Unk_23d4470_Desc&) {}

class Unk_23d5fb8 : public Unk_23d4470 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23d4470::Unk_GetType());
        return &type;
    }

    const Unk_239a418_Type* vf_type() override;
    void vf7(u64, const Unk_23d4470_Desc&) override;
    u32 vf8() override;
};

// 0x7100bdff20
const Unk_239a418_Type* Unk_23d5fb8::vf_type() {
    return Unk_GetType();
}

// 0x7100bdff90
void Unk_23d5fb8::vf7(u64, const Unk_23d4470_Desc&) {}

class Unk_23d6078 : public Unk_23d4470 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23d4470::Unk_GetType());
        return &type;
    }

    const Unk_239a418_Type* vf_type() override;
    void vf7(u64, const Unk_23d4470_Desc&) override;
    u32 vf8() override;
};

// 0x7100be04f0
const Unk_239a418_Type* Unk_23d6078::vf_type() {
    return Unk_GetType();
}

// 0x7100be0560
void Unk_23d6078::vf7(u64, const Unk_23d4470_Desc&) {}

class Unk_23d6138 : public Unk_23d4470 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23d4470::Unk_GetType());
        return &type;
    }

    const Unk_239a418_Type* vf_type() override;
    void vf7(u64, const Unk_23d4470_Desc&) override;
    u32 vf8() override;
};

// 0x7100be0af0
const Unk_239a418_Type* Unk_23d6138::vf_type() {
    return Unk_GetType();
}

// 0x7100be0b60
void Unk_23d6138::vf7(u64, const Unk_23d4470_Desc&) {}

// 0x7100be0b70
u32 Unk_23d6138::vf8() {
    return 1;
}

class Unk_23d61f8 : public Unk_23d4470 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23d4470::Unk_GetType());
        return &type;
    }

    const Unk_239a418_Type* vf_type() override;
    void vf7(u64, const Unk_23d4470_Desc&) override;
    u32 vf8() override;
};

// 0x7100be0dc0
const Unk_239a418_Type* Unk_23d61f8::vf_type() {
    return Unk_GetType();
}

class Unk_23d62b8 : public Unk_23d4470 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23d4470::Unk_GetType());
        return &type;
    }

    const Unk_239a418_Type* vf_type() override;
    void vf7(u64, const Unk_23d4470_Desc&) override;
    u32 vf8() override;
};

// 0x7100be12d0
const Unk_239a418_Type* Unk_23d62b8::vf_type() {
    return Unk_GetType();
}

// 0x7100be1370
u32 Unk_23d62b8::vf8() {
    return 1;
}

class Unk_23d6378 : public Unk_23d4470 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23d4470::Unk_GetType());
        return &type;
    }

    const Unk_239a418_Type* vf_type() override;
    void vf7(u64, const Unk_23d4470_Desc&) override;
    u32 vf8() override;
};

// 0x7100be15c0
const Unk_239a418_Type* Unk_23d6378::vf_type() {
    return Unk_GetType();
}

class Unk_23d6438 : public Unk_23d4470 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23d4470::Unk_GetType());
        return &type;
    }

    const Unk_239a418_Type* vf_type() override;
    void vf7(u64, const Unk_23d4470_Desc&) override;
    u32 vf8() override;
};

// 0x7100be2760
const Unk_239a418_Type* Unk_23d6438::vf_type() {
    return Unk_GetType();
}

class Unk_23d64f8 : public Unk_23d4470 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23d4470::Unk_GetType());
        return &type;
    }

    const Unk_239a418_Type* vf_type() override;
    void vf7(u64, const Unk_23d4470_Desc&) override;
    u32 vf8() override;
};

// 0x7100be3c30
const Unk_239a418_Type* Unk_23d64f8::vf_type() {
    return Unk_GetType();
}

class Unk_23d65b8 : public Unk_23d4470 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23d4470::Unk_GetType());
        return &type;
    }

    const Unk_239a418_Type* vf_type() override;
    void vf7(u64, const Unk_23d4470_Desc&) override;
    u32 vf8() override;
};

// 0x7100be4f00
const Unk_239a418_Type* Unk_23d65b8::vf_type() {
    return Unk_GetType();
}

// 0x7100be4f70
void Unk_23d65b8::vf7(u64, const Unk_23d4470_Desc&) {}

// 0x7100be4f80
u32 Unk_23d65b8::vf8() {
    return 1;
}

class Unk_23d6728 : public Unk_23d4470 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23d4470::Unk_GetType());
        return &type;
    }

    const Unk_239a418_Type* vf_type() override;
    void vf7(u64, const Unk_23d4470_Desc&) override;
    u32 vf8() override;
    virtual void vf9();
};

// 0x7100be8750
const Unk_239a418_Type* Unk_23d6728::vf_type() {
    return Unk_GetType();
}

// 0x7100be87c0
void Unk_23d6728::vf9() {}

class Unk_23d68b0 : public Unk_23d4470 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23d4470::Unk_GetType());
        return &type;
    }

    const Unk_239a418_Type* vf_type() override;
    void vf7(u64, const Unk_23d4470_Desc&) override;
    u32 vf8() override;
};

// 0x7100bea690
const Unk_239a418_Type* Unk_23d68b0::vf_type() {
    return Unk_GetType();
}

class Unk_23d6970 : public Unk_23d4470 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23d4470::Unk_GetType());
        return &type;
    }

    const Unk_239a418_Type* vf_type() override;
    void vf7(u64, const Unk_23d4470_Desc&) override;
    u32 vf8() override;
};

// 0x7100beab40
const Unk_239a418_Type* Unk_23d6970::vf_type() {
    return Unk_GetType();
}

class Unk_23d6af0 : public Unk_23d4470 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23d4470::Unk_GetType());
        return &type;
    }

    const Unk_239a418_Type* vf_type() override;
    void vf7(u64, const Unk_23d4470_Desc&) override;
    u32 vf8() override;
};

// 0x7100becb90
const Unk_239a418_Type* Unk_23d6af0::vf_type() {
    return Unk_GetType();
}

class Unk_23d6d30 : public Unk_23d4470 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23d4470::Unk_GetType());
        return &type;
    }

    const Unk_239a418_Type* vf_type() override;
    void vf7(u64, const Unk_23d4470_Desc&) override;
    u32 vf8() override;
};

// 0x7100bef000
const Unk_239a418_Type* Unk_23d6d30::vf_type() {
    return Unk_GetType();
}

class Unk_23d6f70 : public Unk_23d4470 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23d4470::Unk_GetType());
        return &type;
    }

    const Unk_239a418_Type* vf_type() override;
    void vf7(u64, const Unk_23d4470_Desc&) override;
    u32 vf8() override;
};

// 0x7100bf1c60
const Unk_239a418_Type* Unk_23d6f70::vf_type() {
    return Unk_GetType();
}

class Unk_23d7030 : public Unk_23d4470 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23d4470::Unk_GetType());
        return &type;
    }

    const Unk_239a418_Type* vf_type() override;
    void vf7(u64, const Unk_23d4470_Desc&) override;
    u32 vf8() override;
};

// 0x7100bf24b0
const Unk_239a418_Type* Unk_23d7030::vf_type() {
    return Unk_GetType();
}

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

class Unk_23d7538 {
public:
    virtual ~Unk_23d7538();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7(u64 value);
    virtual void vf8();
    u8 _8[0x340];
    u8 field_348;
};
PKMN_OFFSET_ASSERT(Unk_23d7538, field_348, 0x348);

// 0x7100bf7cc0
void Unk_23d7538::vf7(u64 value) {
    Unk_140b690(value, &field_348, 1);
}

class Unk_23d75f8 : public Unk_23d4470 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23d4470::Unk_GetType());
        return &type;
    }

    const Unk_239a418_Type* vf_type() override;
    void vf7(u64, const Unk_23d4470_Desc&) override;
    u32 vf8() override;
};

// 0x7100bfae20
const Unk_239a418_Type* Unk_23d75f8::vf_type() {
    return Unk_GetType();
}

class Unk_23d76b8 : public Unk_23d4470 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23d4470::Unk_GetType());
        return &type;
    }

    const Unk_239a418_Type* vf_type() override;
    void vf7(u64, const Unk_23d4470_Desc&) override;
    u32 vf8() override;
};

// 0x7100bfb720
const Unk_239a418_Type* Unk_23d76b8::vf_type() {
    return Unk_GetType();
}

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

class Unk_23d7950 : public Unk_23d4470 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23d4470::Unk_GetType());
        return &type;
    }

    const Unk_239a418_Type* vf_type() override;
    void vf7(u64, const Unk_23d4470_Desc&) override;
    u32 vf8() override;
    u8 _348[0x98];
    Unk_239a418_Ref<Unk_239a418> field_3e0;
};
PKMN_OFFSET_ASSERT(Unk_23d7950, field_3e0, 0x3e0);

// 0x7100bfe3c0
const Unk_239a418_Type* Unk_23d7950::vf_type() {
    return Unk_GetType();
}

class Unk_23d7a10 : public Unk_23d4470 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23d4470::Unk_GetType());
        return &type;
    }

    const Unk_239a418_Type* vf_type() override;
    void vf7(u64, const Unk_23d4470_Desc&) override;
    u32 vf8() override;
    virtual void vf9();
};

// 0x7100bfebb0
const Unk_239a418_Type* Unk_23d7a10::vf_type() {
    return Unk_GetType();
}

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
    virtual u8 vf12();
    virtual u8 vf13();
    u8 _8[0x370];
    u8 field_378;
    u8 field_379;
};
PKMN_OFFSET_ASSERT(Unk_23d7ad8, field_378, 0x378);
PKMN_OFFSET_ASSERT(Unk_23d7ad8, field_379, 0x379);

// 0x7100bff6e0
void Unk_23d7ad8::vf10() {}

// 0x7100c02330
u8 Unk_23d7ad8::vf12() {
    return field_378;
}

// 0x7100c02340
u8 Unk_23d7ad8::vf13() {
    return field_379;
}

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

// 0x7100c00900
void Unk_23d7bc0::vf5() {
    ::operator delete(this);
}

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

// 0x7100c00cd0
void Unk_23d7c08::vf5() {
    ::operator delete(this);
}

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

// 0x7100c00d70
void Unk_23d7c50::vf5() {
    ::operator delete(this);
}

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

// 0x7100c01120
void Unk_23d7c98::vf5() {
    ::operator delete(this);
}

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

// 0x7100c011c0
void Unk_23d7ce0::vf5() {
    ::operator delete(this);
}

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

// 0x7100c01450
void Unk_23d7d28::vf5() {
    ::operator delete(this);
}

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

// 0x7100c01510
void Unk_23d7d70::vf5() {
    ::operator delete(this);
}

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

// 0x7100c015c0
void Unk_23d7db8::vf5() {
    ::operator delete(this);
}

class Unk_23d7e00 : public Unk_23d4470 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23d4470::Unk_GetType());
        return &type;
    }

    const Unk_239a418_Type* vf_type() override;
    void vf7(u64, const Unk_23d4470_Desc&) override;
    u32 vf8() override;
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
    u8 _348[0x28];
    Unk_239a418_Ref<Unk_239a418> field_370;
};
PKMN_OFFSET_ASSERT(Unk_23d7e00, field_370, 0x370);

// 0x7100c02bf0
const Unk_239a418_Type* Unk_23d7e00::vf_type() {
    return Unk_GetType();
}

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

// 0x7100c03610
void Unk_23d7ee8::vf5() {
    ::operator delete(this);
}

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

// 0x7100c042a0
void Unk_23d7f30::vf5() {
    ::operator delete(this);
}

class Unk_23d7f78 : public Unk_23d4470 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23d4470::Unk_GetType());
        return &type;
    }

    const Unk_239a418_Type* vf_type() override;
    void vf7(u64, const Unk_23d4470_Desc&) override;
    u32 vf8() override;
    u8 _348[0x98];
    Unk_239a418_Ref<Unk_239a418> field_3e0;
    u8 _3e8[0x98];
    Unk_239a418_Ref<Unk_239a418> field_480;
};
PKMN_OFFSET_ASSERT(Unk_23d7f78, field_3e0, 0x3e0);
PKMN_OFFSET_ASSERT(Unk_23d7f78, field_480, 0x480);

// 0x7100c04710
const Unk_239a418_Type* Unk_23d7f78::vf_type() {
    return Unk_GetType();
}

class Unk_23d8038 {
public:
    virtual ~Unk_23d8038();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7(u64 value);
    virtual void vf8();
    u8 _8[0x340];
    u8 field_348;
};
PKMN_OFFSET_ASSERT(Unk_23d8038, field_348, 0x348);

// 0x7100c04a70
void Unk_23d8038::vf7(u64 value) {
    Unk_140bd70(value, &field_348, 1);
}

class Unk_23d80f8 : public Unk_23d4470 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23d4470::Unk_GetType());
        return &type;
    }

    const Unk_239a418_Type* vf_type() override;
    void vf7(u64, const Unk_23d4470_Desc&) override;
    u32 vf8() override;
};

// 0x7100c058a0
const Unk_239a418_Type* Unk_23d80f8::vf_type() {
    return Unk_GetType();
}

class Unk_23d81b8 : public Unk_23d4470 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23d4470::Unk_GetType());
        return &type;
    }

    const Unk_239a418_Type* vf_type() override;
    void vf7(u64, const Unk_23d4470_Desc&) override;
    u32 vf8() override;
};

// 0x7100c061b0
const Unk_239a418_Type* Unk_23d81b8::vf_type() {
    return Unk_GetType();
}

class Unk_23d8278 : public Unk_23d4470 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23d4470::Unk_GetType());
        return &type;
    }

    const Unk_239a418_Type* vf_type() override;
    void vf7(u64, const Unk_23d4470_Desc&) override;
    u32 vf8() override;
};

// 0x7100c06670
const Unk_239a418_Type* Unk_23d8278::vf_type() {
    return Unk_GetType();
}

class Unk_23d8338 : public Unk_23d4470 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23d4470::Unk_GetType());
        return &type;
    }

    const Unk_239a418_Type* vf_type() override;
    void vf7(u64, const Unk_23d4470_Desc&) override;
    u32 vf8() override;
};

// 0x7100c06b10
const Unk_239a418_Type* Unk_23d8338::vf_type() {
    return Unk_GetType();
}

class Unk_23d83f8 : public Unk_23d4470 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23d4470::Unk_GetType());
        return &type;
    }

    const Unk_239a418_Type* vf_type() override;
    void vf7(u64, const Unk_23d4470_Desc&) override;
    u32 vf8() override;
};

// 0x7100c070a0
const Unk_239a418_Type* Unk_23d83f8::vf_type() {
    return Unk_GetType();
}

class Unk_23d84b8 : public Unk_23d4470 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23d4470::Unk_GetType());
        return &type;
    }

    const Unk_239a418_Type* vf_type() override;
    void vf7(u64, const Unk_23d4470_Desc&) override;
    u32 vf8() override;
};

// 0x7100c07440
const Unk_239a418_Type* Unk_23d84b8::vf_type() {
    return Unk_GetType();
}

class Unk_23d8578 : public Unk_23d4470 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23d4470::Unk_GetType());
        return &type;
    }

    const Unk_239a418_Type* vf_type() override;
    void vf7(u64, const Unk_23d4470_Desc&) override;
    u32 vf8() override;
};

// 0x7100c07910
const Unk_239a418_Type* Unk_23d8578::vf_type() {
    return Unk_GetType();
}

class Unk_23d8638 : public Unk_23d4470 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23d4470::Unk_GetType());
        return &type;
    }

    const Unk_239a418_Type* vf_type() override;
    void vf7(u64, const Unk_23d4470_Desc&) override;
    u32 vf8() override;
};

// 0x7100c07da0
const Unk_239a418_Type* Unk_23d8638::vf_type() {
    return Unk_GetType();
}

class Unk_23d86f8 : public Unk_23d4470 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23d4470::Unk_GetType());
        return &type;
    }

    const Unk_239a418_Type* vf_type() override;
    void vf7(u64, const Unk_23d4470_Desc&) override;
    u32 vf8() override;
};

// 0x7100c083a0
const Unk_239a418_Type* Unk_23d86f8::vf_type() {
    return Unk_GetType();
}

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

// 0x7100c09860
void Unk_23d8878::vf5() {
    ::operator delete(this);
}

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

// 0x7100c09ae0
void Unk_23d88c0::vf5() {
    ::operator delete(this);
}

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

// 0x7100c09f00
void Unk_23d8908::vf5() {
    ::operator delete(this);
}

class Unk_23d8950 : public Unk_23d4470 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23d4470::Unk_GetType());
        return &type;
    }

    const Unk_239a418_Type* vf_type() override;
    void vf7(u64, const Unk_23d4470_Desc&) override;
    u32 vf8() override;
};

// 0x7100c0a1f0
const Unk_239a418_Type* Unk_23d8950::vf_type() {
    return Unk_GetType();
}

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

// 0x7100c0b740
void Unk_23d8af8::vf5() {
    ::operator delete(this);
}

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

// 0x7100c0ba20
void Unk_23d8b40::vf5() {
    ::operator delete(this);
}

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

// 0x7100c0bac0
void Unk_23d8b88::vf5() {
    ::operator delete(this);
}

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

// 0x7100c0bd80
void Unk_23d8bd0::vf5() {
    ::operator delete(this);
}

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

// 0x7100c0be20
void Unk_23d8c18::vf5() {
    ::operator delete(this);
}

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

// 0x7100c0c030
void Unk_23d8c60::vf5() {
    ::operator delete(this);
}

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

// 0x7100c0c0d0
void Unk_23d8ca8::vf5() {
    ::operator delete(this);
}

class Unk_23d8cf0 : public Unk_23d4470 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23d4470::Unk_GetType());
        return &type;
    }

    const Unk_239a418_Type* vf_type() override;
    void vf7(u64, const Unk_23d4470_Desc&) override;
    u32 vf8() override;
};

// 0x7100c0c670
const Unk_239a418_Type* Unk_23d8cf0::vf_type() {
    return Unk_GetType();
}

// The type between Unk_23d4470 and Unk_23d8f80 (its class isn't known yet).
struct Unk_27d9058 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23d4470::Unk_GetType());
        return &type;
    }
};

class Unk_23d8f80 : public Unk_23d4470 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_27d9058::Unk_GetType());
        return &type;
    }

    const Unk_239a418_Type* vf_type() override;
    void vf7(u64, const Unk_23d4470_Desc&) override;
    u32 vf8() override;
    virtual void vf9();
};

// 0x7100c0f5c0
const Unk_239a418_Type* Unk_23d8f80::vf_type() {
    return Unk_GetType();
}

class Unk_23d9130 : public Unk_23d4470 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23d4470::Unk_GetType());
        return &type;
    }

    const Unk_239a418_Type* vf_type() override;
    void vf7(u64, const Unk_23d4470_Desc&) override;
    u32 vf8() override;
};

// 0x7100c11620
const Unk_239a418_Type* Unk_23d9130::vf_type() {
    return Unk_GetType();
}

class Unk_23d91f0 : public Unk_23d4470 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23d4470::Unk_GetType());
        return &type;
    }

    const Unk_239a418_Type* vf_type() override;
    void vf7(u64, const Unk_23d4470_Desc&) override;
    u32 vf8() override;
};

// 0x7100c11bd0
const Unk_239a418_Type* Unk_23d91f0::vf_type() {
    return Unk_GetType();
}

class Unk_23d92b0 : public Unk_23d4470 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23d4470::Unk_GetType());
        return &type;
    }

    const Unk_239a418_Type* vf_type() override;
    void vf7(u64, const Unk_23d4470_Desc&) override;
    u32 vf8() override;
};

// 0x7100c12120
const Unk_239a418_Type* Unk_23d92b0::vf_type() {
    return Unk_GetType();
}

class Unk_23d9370 : public Unk_23d4470 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23d4470::Unk_GetType());
        return &type;
    }

    const Unk_239a418_Type* vf_type() override;
    u32 vf8() override;
};

// 0x7100c128e0
const Unk_239a418_Type* Unk_23d9370::vf_type() {
    return Unk_GetType();
}

class Unk_23d9430 : public Unk_23d4470 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23d4470::Unk_GetType());
        return &type;
    }

    const Unk_239a418_Type* vf_type() override;
    void vf7(u64, const Unk_23d4470_Desc&) override;
    u32 vf8() override;
};

// 0x7100c12bf0
const Unk_239a418_Type* Unk_23d9430::vf_type() {
    return Unk_GetType();
}

class Unk_23d95d0 : public Unk_23d4470 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23d4470::Unk_GetType());
        return &type;
    }

    const Unk_239a418_Type* vf_type() override;
    void vf7(u64, const Unk_23d4470_Desc&) override;
    u32 vf8() override;
};

// 0x7100c14d60
const Unk_239a418_Type* Unk_23d95d0::vf_type() {
    return Unk_GetType();
}

class Unk_23d9740_Obj {
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
    virtual void vf16(u64 value);
};

struct Unk_23d9740_Entry {
    void* field_0;
    Unk_23d9740_Obj* field_8;
    u64 field_10;
    u8 _18[0x8];
};
PKMN_SIZE_ASSERT(Unk_23d9740_Entry, 0x20);

class Unk_23d9740 {
public:
    virtual u32 vf0();
    virtual void* vf1(u64 index);
    virtual void* vf2(u64 index);
    virtual void vf3(u64 index);
    Unk_23d9740_Entry m_entries[2];
};
PKMN_OFFSET_ASSERT(Unk_23d9740, m_entries, 0x8);

// 0x7100c18a10
u32 Unk_23d9740::vf0() {
    return 2;
}

// 0x7100c18a20
void* Unk_23d9740::vf1(u64 index) {
    return m_entries[index].field_0;
}

// 0x7100c18a30
void* Unk_23d9740::vf2(u64 index) {
    return m_entries[index].field_8;
}

// 0x7100c18a40
void Unk_23d9740::vf3(u64 index) {
    if (Unk_23d9740_Obj* obj = m_entries[index].field_8)
        obj->vf16(m_entries[index].field_10);
}

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

// 0x7100c1ac80
void Unk_23d9830::vf8() {}

class Unk_23d9978_Obj {
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
    virtual void vf16(u64 value);
};

struct Unk_23d9978_Entry {
    void* field_0;
    Unk_23d9978_Obj* field_8;
    u64 field_10;
    u8 _18[0x8];
};
PKMN_SIZE_ASSERT(Unk_23d9978_Entry, 0x20);

class Unk_23d9978 {
public:
    virtual u32 vf0();
    virtual void* vf1(u64 index);
    virtual void* vf2(u64 index);
    virtual void vf3(u64 index);
    Unk_23d9978_Entry m_entries[1];
};
PKMN_OFFSET_ASSERT(Unk_23d9978, m_entries, 0x8);

// 0x7100c1c170
u32 Unk_23d9978::vf0() {
    return 1;
}

// 0x7100c1c180
void* Unk_23d9978::vf1(u64 index) {
    return m_entries[index].field_0;
}

// 0x7100c1c190
void* Unk_23d9978::vf2(u64 index) {
    return m_entries[index].field_8;
}

// 0x7100c1c1a0
void Unk_23d9978::vf3(u64 index) {
    if (Unk_23d9978_Obj* obj = m_entries[index].field_8)
        obj->vf16(m_entries[index].field_10);
}

class Unk_23d9dd0 {
public:
    virtual ~Unk_23d9dd0();
    virtual void vf2();
    virtual u64 vf3();
    virtual void vf4();
    virtual void vf5();
    u8 _8[0x50];
    u64 field_58;
};
PKMN_OFFSET_ASSERT(Unk_23d9dd0, field_58, 0x58);

// 0x7100c22c40
u64 Unk_23d9dd0::vf3() {
    return field_58;
}

class Unk_23d9e10_Obj {
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
    virtual void vf16(u64 value);
};

struct Unk_23d9e10_Entry {
    void* field_0;
    Unk_23d9e10_Obj* field_8;
    u64 field_10;
    u8 _18[0x8];
};
PKMN_SIZE_ASSERT(Unk_23d9e10_Entry, 0x20);

class Unk_23d9e10 {
public:
    virtual u32 vf0();
    virtual void* vf1(u64 index);
    virtual void* vf2(u64 index);
    virtual void vf3(u64 index);
    Unk_23d9e10_Entry m_entries[1];
};
PKMN_OFFSET_ASSERT(Unk_23d9e10, m_entries, 0x8);

// 0x7100c22db0
u32 Unk_23d9e10::vf0() {
    return 1;
}

// 0x7100c22dc0
void* Unk_23d9e10::vf1(u64 index) {
    return m_entries[index].field_0;
}

// 0x7100c22dd0
void* Unk_23d9e10::vf2(u64 index) {
    return m_entries[index].field_8;
}

// 0x7100c22de0
void Unk_23d9e10::vf3(u64 index) {
    if (Unk_23d9e10_Obj* obj = m_entries[index].field_8)
        obj->vf16(m_entries[index].field_10);
}
