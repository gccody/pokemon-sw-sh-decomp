// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

#include "gflib3/Unk_239a418.h"

struct Unk_10df990_arg1 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_10df990_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_10df990_arg1, field_8, 0x8);

struct Unk_10df990 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_10df990, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_10df990, field_8, 0x8);

// 0x71010df990
void Unk_10df990_set(Unk_10df990* self, Unk_10df990_arg1* value) {
    u64 v0 = self->field_0;
    self->field_0 = 0;
    value->field_0 = v0;
    u64 v1 = self->field_8;
    self->field_8 = 0;
    value->field_8 = v1;
}

struct Unk_10dfa30_arg1 {
    Unk_239a418* field_0;
};
PKMN_OFFSET_ASSERT(Unk_10dfa30_arg1, field_0, 0x0);

struct Unk_10dfa30 {
    Unk_239a418* field_0;
};
PKMN_OFFSET_ASSERT(Unk_10dfa30, field_0, 0x0);

// 0x71010dfa30
void Unk_10dfa30_call(const Unk_10dfa30* self, Unk_10dfa30_arg1* value) {
    Unk_239a418* v0 = self->field_0;
    value->field_0 = v0;
    if (v0 != nullptr) {
        static_cast<Unk_239a458*>(v0)->vf4();
    }
}

struct Unk_10dfa50_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_10dfa50_arg1, field_0, 0x0);

struct Unk_10dfa50 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_10dfa50, field_0, 0x0);

// 0x71010dfa50
void Unk_10dfa50_set(Unk_10dfa50* self, Unk_10dfa50_arg1* value) {
    u64 v0 = self->field_0;
    self->field_0 = 0;
    value->field_0 = v0;
}

struct Unk_10dfb00_arg1 {
    Unk_239a418* field_0;
};
PKMN_OFFSET_ASSERT(Unk_10dfb00_arg1, field_0, 0x0);

struct Unk_10dfb00 {
    Unk_239a418* field_0;
};
PKMN_OFFSET_ASSERT(Unk_10dfb00, field_0, 0x0);

// 0x71010dfb00
void Unk_10dfb00_call(const Unk_10dfb00* self, Unk_10dfb00_arg1* value) {
    Unk_239a418* v0 = self->field_0;
    value->field_0 = v0;
    if (v0 != nullptr) {
        static_cast<Unk_239a458*>(v0)->vf4();
    }
}

struct Unk_10dfb20_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_10dfb20_arg1, field_0, 0x0);

struct Unk_10dfb20 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_10dfb20, field_0, 0x0);

// 0x71010dfb20
void Unk_10dfb20_set(Unk_10dfb20* self, Unk_10dfb20_arg1* value) {
    u64 v0 = self->field_0;
    self->field_0 = 0;
    value->field_0 = v0;
}

struct Unk_10e0bb0_arg1 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_10e0bb0_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_10e0bb0_arg1, field_8, 0x8);

struct Unk_10e0bb0 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_10e0bb0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_10e0bb0, field_8, 0x8);

// 0x71010e0bb0
void Unk_10e0bb0_set(Unk_10e0bb0* self, Unk_10e0bb0_arg1* value) {
    u64 v0 = self->field_0;
    self->field_0 = 0;
    value->field_0 = v0;
    u64 v1 = self->field_8;
    self->field_8 = 0;
    value->field_8 = v1;
}

struct Unk_10e0c50_arg1 {
    Unk_239a418* field_0;
};
PKMN_OFFSET_ASSERT(Unk_10e0c50_arg1, field_0, 0x0);

struct Unk_10e0c50 {
    Unk_239a418* field_0;
};
PKMN_OFFSET_ASSERT(Unk_10e0c50, field_0, 0x0);

// 0x71010e0c50
void Unk_10e0c50_call(const Unk_10e0c50* self, Unk_10e0c50_arg1* value) {
    Unk_239a418* v0 = self->field_0;
    value->field_0 = v0;
    if (v0 != nullptr) {
        static_cast<Unk_239a458*>(v0)->vf4();
    }
}

struct Unk_10e0c70_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_10e0c70_arg1, field_0, 0x0);

struct Unk_10e0c70 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_10e0c70, field_0, 0x0);

// 0x71010e0c70
void Unk_10e0c70_set(Unk_10e0c70* self, Unk_10e0c70_arg1* value) {
    u64 v0 = self->field_0;
    self->field_0 = 0;
    value->field_0 = v0;
}

struct Unk_10e0d20_arg1 {
    Unk_239a418* field_0;
};
PKMN_OFFSET_ASSERT(Unk_10e0d20_arg1, field_0, 0x0);

struct Unk_10e0d20 {
    Unk_239a418* field_0;
};
PKMN_OFFSET_ASSERT(Unk_10e0d20, field_0, 0x0);

// 0x71010e0d20
void Unk_10e0d20_call(const Unk_10e0d20* self, Unk_10e0d20_arg1* value) {
    Unk_239a418* v0 = self->field_0;
    value->field_0 = v0;
    if (v0 != nullptr) {
        static_cast<Unk_239a458*>(v0)->vf4();
    }
}

struct Unk_10e0d40_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_10e0d40_arg1, field_0, 0x0);

struct Unk_10e0d40 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_10e0d40, field_0, 0x0);

// 0x71010e0d40
void Unk_10e0d40_set(Unk_10e0d40* self, Unk_10e0d40_arg1* value) {
    u64 v0 = self->field_0;
    self->field_0 = 0;
    value->field_0 = v0;
}

struct Unk_10e1870_arg1 {
    Unk_239a418* field_0;
};
PKMN_OFFSET_ASSERT(Unk_10e1870_arg1, field_0, 0x0);

struct Unk_10e1870 {
    Unk_239a418* field_0;
};
PKMN_OFFSET_ASSERT(Unk_10e1870, field_0, 0x0);

// 0x71010e1870
void Unk_10e1870_call(const Unk_10e1870* self, Unk_10e1870_arg1* value) {
    Unk_239a418* v0 = self->field_0;
    value->field_0 = v0;
    if (v0 != nullptr) {
        static_cast<Unk_239a458*>(v0)->vf4();
    }
}

struct Unk_10e1890_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_10e1890_arg1, field_0, 0x0);

struct Unk_10e1890 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_10e1890, field_0, 0x0);

// 0x71010e1890
void Unk_10e1890_set(Unk_10e1890* self, Unk_10e1890_arg1* value) {
    u64 v0 = self->field_0;
    self->field_0 = 0;
    value->field_0 = v0;
}

struct Unk_10e1920_arg1 {
    Unk_239a418* field_0;
};
PKMN_OFFSET_ASSERT(Unk_10e1920_arg1, field_0, 0x0);

struct Unk_10e1920 {
    Unk_239a418* field_0;
};
PKMN_OFFSET_ASSERT(Unk_10e1920, field_0, 0x0);

// 0x71010e1920
void Unk_10e1920_call(const Unk_10e1920* self, Unk_10e1920_arg1* value) {
    Unk_239a418* v0 = self->field_0;
    value->field_0 = v0;
    if (v0 != nullptr) {
        static_cast<Unk_239a458*>(v0)->vf4();
    }
}

struct Unk_10e1940_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_10e1940_arg1, field_0, 0x0);

struct Unk_10e1940 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_10e1940, field_0, 0x0);

// 0x71010e1940
void Unk_10e1940_set(Unk_10e1940* self, Unk_10e1940_arg1* value) {
    u64 v0 = self->field_0;
    self->field_0 = 0;
    value->field_0 = v0;
}

struct Unk_10e19f0_arg1 {
    Unk_239a418* field_0;
};
PKMN_OFFSET_ASSERT(Unk_10e19f0_arg1, field_0, 0x0);

struct Unk_10e19f0 {
    Unk_239a418* field_0;
};
PKMN_OFFSET_ASSERT(Unk_10e19f0, field_0, 0x0);

// 0x71010e19f0
void Unk_10e19f0_call(const Unk_10e19f0* self, Unk_10e19f0_arg1* value) {
    Unk_239a418* v0 = self->field_0;
    value->field_0 = v0;
    if (v0 != nullptr) {
        static_cast<Unk_239a458*>(v0)->vf4();
    }
}

struct Unk_10e1a10_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_10e1a10_arg1, field_0, 0x0);

struct Unk_10e1a10 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_10e1a10, field_0, 0x0);

// 0x71010e1a10
void Unk_10e1a10_set(Unk_10e1a10* self, Unk_10e1a10_arg1* value) {
    u64 v0 = self->field_0;
    self->field_0 = 0;
    value->field_0 = v0;
}

struct Unk_10e2f70_arg1 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_10e2f70_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_10e2f70_arg1, field_8, 0x8);

struct Unk_10e2f70 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_10e2f70, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_10e2f70, field_8, 0x8);

// 0x71010e2f70
void Unk_10e2f70_set(Unk_10e2f70* self, Unk_10e2f70_arg1* value) {
    u64 v0 = self->field_0;
    self->field_0 = 0;
    value->field_0 = v0;
    u64 v1 = self->field_8;
    self->field_8 = 0;
    value->field_8 = v1;
}

struct Unk_10e3010_arg1 {
    Unk_239a418* field_0;
};
PKMN_OFFSET_ASSERT(Unk_10e3010_arg1, field_0, 0x0);

struct Unk_10e3010 {
    Unk_239a418* field_0;
};
PKMN_OFFSET_ASSERT(Unk_10e3010, field_0, 0x0);

// 0x71010e3010
void Unk_10e3010_call(const Unk_10e3010* self, Unk_10e3010_arg1* value) {
    Unk_239a418* v0 = self->field_0;
    value->field_0 = v0;
    if (v0 != nullptr) {
        static_cast<Unk_239a458*>(v0)->vf4();
    }
}

struct Unk_10e3030_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_10e3030_arg1, field_0, 0x0);

struct Unk_10e3030 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_10e3030, field_0, 0x0);

// 0x71010e3030
void Unk_10e3030_set(Unk_10e3030* self, Unk_10e3030_arg1* value) {
    u64 v0 = self->field_0;
    self->field_0 = 0;
    value->field_0 = v0;
}

struct Unk_10e30e0_arg1 {
    Unk_239a418* field_0;
};
PKMN_OFFSET_ASSERT(Unk_10e30e0_arg1, field_0, 0x0);

struct Unk_10e30e0 {
    Unk_239a418* field_0;
};
PKMN_OFFSET_ASSERT(Unk_10e30e0, field_0, 0x0);

// 0x71010e30e0
void Unk_10e30e0_call(const Unk_10e30e0* self, Unk_10e30e0_arg1* value) {
    Unk_239a418* v0 = self->field_0;
    value->field_0 = v0;
    if (v0 != nullptr) {
        static_cast<Unk_239a458*>(v0)->vf4();
    }
}

struct Unk_10e3100_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_10e3100_arg1, field_0, 0x0);

struct Unk_10e3100 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_10e3100, field_0, 0x0);

// 0x71010e3100
void Unk_10e3100_set(Unk_10e3100* self, Unk_10e3100_arg1* value) {
    u64 v0 = self->field_0;
    self->field_0 = 0;
    value->field_0 = v0;
}
