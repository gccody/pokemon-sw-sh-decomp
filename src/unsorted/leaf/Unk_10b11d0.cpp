// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

#include "gflib3/Unk_239a418.h"

struct Unk_10b11d0 {
    Unk_239a418* field_0;
};
PKMN_OFFSET_ASSERT(Unk_10b11d0, field_0, 0x0);

// 0x71010b11d0
void Unk_10b11d0_call(Unk_10b11d0* self) {
    if (self->field_0 != nullptr) {
        static_cast<Unk_239a458*>(self->field_0)->vf5();
        self->field_0 = nullptr;
    }
}

struct Unk_10b1210_arg1 {
    Unk_239a418* field_0;
};
PKMN_OFFSET_ASSERT(Unk_10b1210_arg1, field_0, 0x0);

struct Unk_10b1210 {
    Unk_239a418* field_0;
};
PKMN_OFFSET_ASSERT(Unk_10b1210, field_0, 0x0);

// 0x71010b1210
void Unk_10b1210_call(const Unk_10b1210* self, Unk_10b1210_arg1* value) {
    Unk_239a418* v0 = self->field_0;
    value->field_0 = v0;
    if (v0 != nullptr) {
        static_cast<Unk_239a458*>(v0)->vf4();
    }
}

struct Unk_10b1230_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_10b1230_arg1, field_0, 0x0);

struct Unk_10b1230 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_10b1230, field_0, 0x0);

// 0x71010b1230
void Unk_10b1230_set(Unk_10b1230* self, Unk_10b1230_arg1* value) {
    u64 v0 = self->field_0;
    self->field_0 = 0;
    value->field_0 = v0;
}

struct Unk_10b49d0 {
    Unk_239a418* field_0;
};
PKMN_OFFSET_ASSERT(Unk_10b49d0, field_0, 0x0);

// 0x71010b49d0
void Unk_10b49d0_call(Unk_10b49d0* self) {
    if (self->field_0 != nullptr) {
        static_cast<Unk_239a458*>(self->field_0)->vf5();
        self->field_0 = nullptr;
    }
}

struct Unk_10b4a10_arg1 {
    Unk_239a418* field_0;
};
PKMN_OFFSET_ASSERT(Unk_10b4a10_arg1, field_0, 0x0);

struct Unk_10b4a10 {
    Unk_239a418* field_0;
};
PKMN_OFFSET_ASSERT(Unk_10b4a10, field_0, 0x0);

// 0x71010b4a10
void Unk_10b4a10_call(const Unk_10b4a10* self, Unk_10b4a10_arg1* value) {
    Unk_239a418* v0 = self->field_0;
    value->field_0 = v0;
    if (v0 != nullptr) {
        static_cast<Unk_239a458*>(v0)->vf4();
    }
}

struct Unk_10b4a30_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_10b4a30_arg1, field_0, 0x0);

struct Unk_10b4a30 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_10b4a30, field_0, 0x0);

// 0x71010b4a30
void Unk_10b4a30_set(Unk_10b4a30* self, Unk_10b4a30_arg1* value) {
    u64 v0 = self->field_0;
    self->field_0 = 0;
    value->field_0 = v0;
}

struct Unk_10b4a50 {
    Unk_239a418* field_0;
};
PKMN_OFFSET_ASSERT(Unk_10b4a50, field_0, 0x0);

// 0x71010b4a50
void Unk_10b4a50_call(Unk_10b4a50* self) {
    if (self->field_0 != nullptr) {
        static_cast<Unk_239a458*>(self->field_0)->vf5();
        self->field_0 = nullptr;
    }
}

struct Unk_10b4a90_arg1 {
    Unk_239a418* field_0;
};
PKMN_OFFSET_ASSERT(Unk_10b4a90_arg1, field_0, 0x0);

struct Unk_10b4a90 {
    Unk_239a418* field_0;
};
PKMN_OFFSET_ASSERT(Unk_10b4a90, field_0, 0x0);

// 0x71010b4a90
void Unk_10b4a90_call(const Unk_10b4a90* self, Unk_10b4a90_arg1* value) {
    Unk_239a418* v0 = self->field_0;
    value->field_0 = v0;
    if (v0 != nullptr) {
        static_cast<Unk_239a458*>(v0)->vf4();
    }
}

struct Unk_10b4ab0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_10b4ab0_arg1, field_0, 0x0);

struct Unk_10b4ab0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_10b4ab0, field_0, 0x0);

// 0x71010b4ab0
void Unk_10b4ab0_set(Unk_10b4ab0* self, Unk_10b4ab0_arg1* value) {
    u64 v0 = self->field_0;
    self->field_0 = 0;
    value->field_0 = v0;
}

struct Unk_10b4b20 {
    Unk_239a418* field_0;
};
PKMN_OFFSET_ASSERT(Unk_10b4b20, field_0, 0x0);

// 0x71010b4b20
void Unk_10b4b20_call(Unk_10b4b20* self) {
    if (self->field_0 != nullptr) {
        static_cast<Unk_239a458*>(self->field_0)->vf5();
        self->field_0 = nullptr;
    }
}

struct Unk_10b4b60_arg1 {
    Unk_239a418* field_0;
};
PKMN_OFFSET_ASSERT(Unk_10b4b60_arg1, field_0, 0x0);

struct Unk_10b4b60 {
    Unk_239a418* field_0;
};
PKMN_OFFSET_ASSERT(Unk_10b4b60, field_0, 0x0);

// 0x71010b4b60
void Unk_10b4b60_call(const Unk_10b4b60* self, Unk_10b4b60_arg1* value) {
    Unk_239a418* v0 = self->field_0;
    value->field_0 = v0;
    if (v0 != nullptr) {
        static_cast<Unk_239a458*>(v0)->vf4();
    }
}

struct Unk_10b4b80_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_10b4b80_arg1, field_0, 0x0);

struct Unk_10b4b80 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_10b4b80, field_0, 0x0);

// 0x71010b4b80
void Unk_10b4b80_set(Unk_10b4b80* self, Unk_10b4b80_arg1* value) {
    u64 v0 = self->field_0;
    self->field_0 = 0;
    value->field_0 = v0;
}

struct Unk_10b57e0_arg1 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_10b57e0_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_10b57e0_arg1, field_8, 0x8);

struct Unk_10b57e0 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_10b57e0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_10b57e0, field_8, 0x8);

// 0x71010b57e0
void Unk_10b57e0_set(Unk_10b57e0* self, Unk_10b57e0_arg1* value) {
    u64 v0 = self->field_0;
    self->field_0 = 0;
    value->field_0 = v0;
    u64 v1 = self->field_8;
    self->field_8 = 0;
    value->field_8 = v1;
}

struct Unk_10b83f0 {
    Unk_239a418* field_0;
};
PKMN_OFFSET_ASSERT(Unk_10b83f0, field_0, 0x0);

// 0x71010b83f0
void Unk_10b83f0_call(Unk_10b83f0* self) {
    if (self->field_0 != nullptr) {
        static_cast<Unk_239a458*>(self->field_0)->vf5();
        self->field_0 = nullptr;
    }
}

struct Unk_10b8430_arg1 {
    Unk_239a418* field_0;
};
PKMN_OFFSET_ASSERT(Unk_10b8430_arg1, field_0, 0x0);

struct Unk_10b8430 {
    Unk_239a418* field_0;
};
PKMN_OFFSET_ASSERT(Unk_10b8430, field_0, 0x0);

// 0x71010b8430
void Unk_10b8430_call(const Unk_10b8430* self, Unk_10b8430_arg1* value) {
    Unk_239a418* v0 = self->field_0;
    value->field_0 = v0;
    if (v0 != nullptr) {
        static_cast<Unk_239a458*>(v0)->vf4();
    }
}

struct Unk_10b8450_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_10b8450_arg1, field_0, 0x0);

struct Unk_10b8450 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_10b8450, field_0, 0x0);

// 0x71010b8450
void Unk_10b8450_set(Unk_10b8450* self, Unk_10b8450_arg1* value) {
    u64 v0 = self->field_0;
    self->field_0 = 0;
    value->field_0 = v0;
}

struct Unk_10b8470 {
    Unk_239a418* field_0;
};
PKMN_OFFSET_ASSERT(Unk_10b8470, field_0, 0x0);

// 0x71010b8470
void Unk_10b8470_call(Unk_10b8470* self) {
    if (self->field_0 != nullptr) {
        static_cast<Unk_239a458*>(self->field_0)->vf5();
        self->field_0 = nullptr;
    }
}

struct Unk_10b84b0_arg1 {
    Unk_239a418* field_0;
};
PKMN_OFFSET_ASSERT(Unk_10b84b0_arg1, field_0, 0x0);

struct Unk_10b84b0 {
    Unk_239a418* field_0;
};
PKMN_OFFSET_ASSERT(Unk_10b84b0, field_0, 0x0);

// 0x71010b84b0
void Unk_10b84b0_call(const Unk_10b84b0* self, Unk_10b84b0_arg1* value) {
    Unk_239a418* v0 = self->field_0;
    value->field_0 = v0;
    if (v0 != nullptr) {
        static_cast<Unk_239a458*>(v0)->vf4();
    }
}

struct Unk_10b84d0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_10b84d0_arg1, field_0, 0x0);

struct Unk_10b84d0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_10b84d0, field_0, 0x0);

// 0x71010b84d0
void Unk_10b84d0_set(Unk_10b84d0* self, Unk_10b84d0_arg1* value) {
    u64 v0 = self->field_0;
    self->field_0 = 0;
    value->field_0 = v0;
}

struct Unk_10b8540 {
    Unk_239a418* field_0;
};
PKMN_OFFSET_ASSERT(Unk_10b8540, field_0, 0x0);

// 0x71010b8540
void Unk_10b8540_call(Unk_10b8540* self) {
    if (self->field_0 != nullptr) {
        static_cast<Unk_239a458*>(self->field_0)->vf5();
        self->field_0 = nullptr;
    }
}

struct Unk_10b8580_arg1 {
    Unk_239a418* field_0;
};
PKMN_OFFSET_ASSERT(Unk_10b8580_arg1, field_0, 0x0);

struct Unk_10b8580 {
    Unk_239a418* field_0;
};
PKMN_OFFSET_ASSERT(Unk_10b8580, field_0, 0x0);

// 0x71010b8580
void Unk_10b8580_call(const Unk_10b8580* self, Unk_10b8580_arg1* value) {
    Unk_239a418* v0 = self->field_0;
    value->field_0 = v0;
    if (v0 != nullptr) {
        static_cast<Unk_239a458*>(v0)->vf4();
    }
}

struct Unk_10b85a0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_10b85a0_arg1, field_0, 0x0);

struct Unk_10b85a0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_10b85a0, field_0, 0x0);

// 0x71010b85a0
void Unk_10b85a0_set(Unk_10b85a0* self, Unk_10b85a0_arg1* value) {
    u64 v0 = self->field_0;
    self->field_0 = 0;
    value->field_0 = v0;
}

struct Unk_10b85c0 {
    Unk_239a418* field_0;
};
PKMN_OFFSET_ASSERT(Unk_10b85c0, field_0, 0x0);

// 0x71010b85c0
void Unk_10b85c0_call(Unk_10b85c0* self) {
    if (self->field_0 != nullptr) {
        static_cast<Unk_239a458*>(self->field_0)->vf5();
        self->field_0 = nullptr;
    }
}

struct Unk_10b8600_arg1 {
    Unk_239a418* field_0;
};
PKMN_OFFSET_ASSERT(Unk_10b8600_arg1, field_0, 0x0);

struct Unk_10b8600 {
    Unk_239a418* field_0;
};
PKMN_OFFSET_ASSERT(Unk_10b8600, field_0, 0x0);

// 0x71010b8600
void Unk_10b8600_call(const Unk_10b8600* self, Unk_10b8600_arg1* value) {
    Unk_239a418* v0 = self->field_0;
    value->field_0 = v0;
    if (v0 != nullptr) {
        static_cast<Unk_239a458*>(v0)->vf4();
    }
}

struct Unk_10b8620_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_10b8620_arg1, field_0, 0x0);

struct Unk_10b8620 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_10b8620, field_0, 0x0);

// 0x71010b8620
void Unk_10b8620_set(Unk_10b8620* self, Unk_10b8620_arg1* value) {
    u64 v0 = self->field_0;
    self->field_0 = 0;
    value->field_0 = v0;
}

struct Unk_10b8640 {
    Unk_239a418* field_0;
};
PKMN_OFFSET_ASSERT(Unk_10b8640, field_0, 0x0);

// 0x71010b8640
void Unk_10b8640_call(Unk_10b8640* self) {
    if (self->field_0 != nullptr) {
        static_cast<Unk_239a458*>(self->field_0)->vf5();
        self->field_0 = nullptr;
    }
}

struct Unk_10b8680_arg1 {
    Unk_239a418* field_0;
};
PKMN_OFFSET_ASSERT(Unk_10b8680_arg1, field_0, 0x0);

struct Unk_10b8680 {
    Unk_239a418* field_0;
};
PKMN_OFFSET_ASSERT(Unk_10b8680, field_0, 0x0);

// 0x71010b8680
void Unk_10b8680_call(const Unk_10b8680* self, Unk_10b8680_arg1* value) {
    Unk_239a418* v0 = self->field_0;
    value->field_0 = v0;
    if (v0 != nullptr) {
        static_cast<Unk_239a458*>(v0)->vf4();
    }
}

struct Unk_10b86a0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_10b86a0_arg1, field_0, 0x0);

struct Unk_10b86a0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_10b86a0, field_0, 0x0);

// 0x71010b86a0
void Unk_10b86a0_set(Unk_10b86a0* self, Unk_10b86a0_arg1* value) {
    u64 v0 = self->field_0;
    self->field_0 = 0;
    value->field_0 = v0;
}

struct Unk_10b8710 {
    Unk_239a418* field_0;
};
PKMN_OFFSET_ASSERT(Unk_10b8710, field_0, 0x0);

// 0x71010b8710
void Unk_10b8710_call(Unk_10b8710* self) {
    if (self->field_0 != nullptr) {
        static_cast<Unk_239a458*>(self->field_0)->vf5();
        self->field_0 = nullptr;
    }
}

struct Unk_10b8750_arg1 {
    Unk_239a418* field_0;
};
PKMN_OFFSET_ASSERT(Unk_10b8750_arg1, field_0, 0x0);

struct Unk_10b8750 {
    Unk_239a418* field_0;
};
PKMN_OFFSET_ASSERT(Unk_10b8750, field_0, 0x0);

// 0x71010b8750
void Unk_10b8750_call(const Unk_10b8750* self, Unk_10b8750_arg1* value) {
    Unk_239a418* v0 = self->field_0;
    value->field_0 = v0;
    if (v0 != nullptr) {
        static_cast<Unk_239a458*>(v0)->vf4();
    }
}

struct Unk_10b8770_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_10b8770_arg1, field_0, 0x0);

struct Unk_10b8770 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_10b8770, field_0, 0x0);

// 0x71010b8770
void Unk_10b8770_set(Unk_10b8770* self, Unk_10b8770_arg1* value) {
    u64 v0 = self->field_0;
    self->field_0 = 0;
    value->field_0 = v0;
}

struct Unk_10b8790 {
    Unk_239a418* field_0;
};
PKMN_OFFSET_ASSERT(Unk_10b8790, field_0, 0x0);

// 0x71010b8790
void Unk_10b8790_call(Unk_10b8790* self) {
    if (self->field_0 != nullptr) {
        static_cast<Unk_239a458*>(self->field_0)->vf5();
        self->field_0 = nullptr;
    }
}

struct Unk_10b87d0_arg1 {
    Unk_239a418* field_0;
};
PKMN_OFFSET_ASSERT(Unk_10b87d0_arg1, field_0, 0x0);

struct Unk_10b87d0 {
    Unk_239a418* field_0;
};
PKMN_OFFSET_ASSERT(Unk_10b87d0, field_0, 0x0);

// 0x71010b87d0
void Unk_10b87d0_call(const Unk_10b87d0* self, Unk_10b87d0_arg1* value) {
    Unk_239a418* v0 = self->field_0;
    value->field_0 = v0;
    if (v0 != nullptr) {
        static_cast<Unk_239a458*>(v0)->vf4();
    }
}

struct Unk_10b87f0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_10b87f0_arg1, field_0, 0x0);

struct Unk_10b87f0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_10b87f0, field_0, 0x0);

// 0x71010b87f0
void Unk_10b87f0_set(Unk_10b87f0* self, Unk_10b87f0_arg1* value) {
    u64 v0 = self->field_0;
    self->field_0 = 0;
    value->field_0 = v0;
}

struct Unk_10b8810 {
    Unk_239a418* field_0;
};
PKMN_OFFSET_ASSERT(Unk_10b8810, field_0, 0x0);

// 0x71010b8810
void Unk_10b8810_call(Unk_10b8810* self) {
    if (self->field_0 != nullptr) {
        static_cast<Unk_239a458*>(self->field_0)->vf5();
        self->field_0 = nullptr;
    }
}

struct Unk_10b8850_arg1 {
    Unk_239a418* field_0;
};
PKMN_OFFSET_ASSERT(Unk_10b8850_arg1, field_0, 0x0);

struct Unk_10b8850 {
    Unk_239a418* field_0;
};
PKMN_OFFSET_ASSERT(Unk_10b8850, field_0, 0x0);

// 0x71010b8850
void Unk_10b8850_call(const Unk_10b8850* self, Unk_10b8850_arg1* value) {
    Unk_239a418* v0 = self->field_0;
    value->field_0 = v0;
    if (v0 != nullptr) {
        static_cast<Unk_239a458*>(v0)->vf4();
    }
}

struct Unk_10b8870_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_10b8870_arg1, field_0, 0x0);

struct Unk_10b8870 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_10b8870, field_0, 0x0);

// 0x71010b8870
void Unk_10b8870_set(Unk_10b8870* self, Unk_10b8870_arg1* value) {
    u64 v0 = self->field_0;
    self->field_0 = 0;
    value->field_0 = v0;
}

struct Unk_10b88e0 {
    Unk_239a418* field_0;
};
PKMN_OFFSET_ASSERT(Unk_10b88e0, field_0, 0x0);

// 0x71010b88e0
void Unk_10b88e0_call(Unk_10b88e0* self) {
    if (self->field_0 != nullptr) {
        static_cast<Unk_239a458*>(self->field_0)->vf5();
        self->field_0 = nullptr;
    }
}

struct Unk_10b8920_arg1 {
    Unk_239a418* field_0;
};
PKMN_OFFSET_ASSERT(Unk_10b8920_arg1, field_0, 0x0);

struct Unk_10b8920 {
    Unk_239a418* field_0;
};
PKMN_OFFSET_ASSERT(Unk_10b8920, field_0, 0x0);

// 0x71010b8920
void Unk_10b8920_call(const Unk_10b8920* self, Unk_10b8920_arg1* value) {
    Unk_239a418* v0 = self->field_0;
    value->field_0 = v0;
    if (v0 != nullptr) {
        static_cast<Unk_239a458*>(v0)->vf4();
    }
}

struct Unk_10b8940_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_10b8940_arg1, field_0, 0x0);

struct Unk_10b8940 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_10b8940, field_0, 0x0);

// 0x71010b8940
void Unk_10b8940_set(Unk_10b8940* self, Unk_10b8940_arg1* value) {
    u64 v0 = self->field_0;
    self->field_0 = 0;
    value->field_0 = v0;
}

struct Unk_27e4594_Data {
    u32 field_0;
    u32 field_4;
    u32 field_8;
    u32 field_c;
    u16 field_10;
    u8 _12[0x2];
    u32 field_14;
    u16 field_18;
};
PKMN_OFFSET_ASSERT(Unk_27e4594_Data, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_27e4594_Data, field_4, 0x4);
PKMN_OFFSET_ASSERT(Unk_27e4594_Data, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_27e4594_Data, field_c, 0xc);
PKMN_OFFSET_ASSERT(Unk_27e4594_Data, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_27e4594_Data, field_14, 0x14);
PKMN_OFFSET_ASSERT(Unk_27e4594_Data, field_18, 0x18);

extern Unk_27e4594_Data Unk_27e4594 __attribute__((visibility("hidden")));
namespace nn {
namespace ldn {
u64 MakeIpv4Address(u8, u8, u8, u8);
}
}  // namespace nn

// 0x71010b8950
void Unk_10b8950_call() {
    u32 r0 = nn::ldn::MakeIpv4Address(0x7f, 0, 0, 1);
    Unk_27e4594.field_0 = r0;
    u32 r1 = nn::ldn::MakeIpv4Address(0xff, 0xff, 0xff, 0xff);
    Unk_27e4594.field_4 = r1;
    u32 r2 = nn::ldn::MakeIpv4Address(0, 0, 0, 0);
    Unk_27e4594.field_10 = 0xffff;
    Unk_27e4594.field_8 = r2;
    Unk_27e4594.field_c = 0xffffffff;
    Unk_27e4594.field_18 = 0;
    Unk_27e4594.field_14 = 0;
}
