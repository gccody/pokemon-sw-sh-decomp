// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

#include "gflib3/Unk_239a418.h"

// 0x7100ff5c70
void Unk_ff5c70_update() {}

struct Unk_ff5c80_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_ff5c80_arg1, field_0, 0x0);

struct Unk_ff5c80 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_ff5c80, field_0, 0x0);

// 0x7100ff5c80
void Unk_ff5c80_set(const Unk_ff5c80* self, Unk_ff5c80_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_ff5c90_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_ff5c90_arg1, field_0, 0x0);

struct Unk_ff5c90 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_ff5c90, field_0, 0x0);

// 0x7100ff5c90
void Unk_ff5c90_set(const Unk_ff5c90* self, Unk_ff5c90_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_ff5d20_arg1 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_ff5d20_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_ff5d20_arg1, field_8, 0x8);

struct Unk_ff5d20 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_ff5d20, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_ff5d20, field_8, 0x8);

// 0x7100ff5d20
void Unk_ff5d20_call(const Unk_ff5d20* self, Unk_ff5d20_arg1* value) {
    value->field_0 = self->field_0;
    Unk_239a418* v0 = self->field_8;
    value->field_8 = v0;
    if (v0 != nullptr) {
        static_cast<Unk_239a458*>(v0)->vf4();
    }
}

struct Unk_ff5d50_arg1 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_ff5d50_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_ff5d50_arg1, field_8, 0x8);

struct Unk_ff5d50 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_ff5d50, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_ff5d50, field_8, 0x8);

// 0x7100ff5d50
void Unk_ff5d50_call(const Unk_ff5d50* self, Unk_ff5d50_arg1* value) {
    value->field_0 = self->field_0;
    Unk_239a418* v0 = self->field_8;
    value->field_8 = v0;
    if (v0 != nullptr) {
        static_cast<Unk_239a458*>(v0)->vf4();
    }
}

struct Unk_ff5df0_arg1 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_ff5df0_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_ff5df0_arg1, field_8, 0x8);

struct Unk_ff5df0 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_ff5df0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_ff5df0, field_8, 0x8);

// 0x7100ff5df0
void Unk_ff5df0_call(const Unk_ff5df0* self, Unk_ff5df0_arg1* value) {
    value->field_0 = self->field_0;
    Unk_239a418* v0 = self->field_8;
    value->field_8 = v0;
    if (v0 != nullptr) {
        static_cast<Unk_239a458*>(v0)->vf4();
    }
}

struct Unk_ff5e20_arg1 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_ff5e20_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_ff5e20_arg1, field_8, 0x8);

struct Unk_ff5e20 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_ff5e20, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_ff5e20, field_8, 0x8);

// 0x7100ff5e20
void Unk_ff5e20_call(const Unk_ff5e20* self, Unk_ff5e20_arg1* value) {
    value->field_0 = self->field_0;
    Unk_239a418* v0 = self->field_8;
    value->field_8 = v0;
    if (v0 != nullptr) {
        static_cast<Unk_239a458*>(v0)->vf4();
    }
}

// 0x7100ff5f30
void Unk_ff5f30_update() {}

struct Unk_ff5f40_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_ff5f40_arg1, field_0, 0x0);

struct Unk_ff5f40 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_ff5f40, field_0, 0x0);

// 0x7100ff5f40
void Unk_ff5f40_set(const Unk_ff5f40* self, Unk_ff5f40_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_ff5f50_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_ff5f50_arg1, field_0, 0x0);

struct Unk_ff5f50 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_ff5f50, field_0, 0x0);

// 0x7100ff5f50
void Unk_ff5f50_set(const Unk_ff5f50* self, Unk_ff5f50_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_ff5ff0_arg1 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_ff5ff0_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_ff5ff0_arg1, field_8, 0x8);

struct Unk_ff5ff0 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_ff5ff0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_ff5ff0, field_8, 0x8);

// 0x7100ff5ff0
void Unk_ff5ff0_call(const Unk_ff5ff0* self, Unk_ff5ff0_arg1* value) {
    value->field_0 = self->field_0;
    Unk_239a418* v0 = self->field_8;
    value->field_8 = v0;
    if (v0 != nullptr) {
        static_cast<Unk_239a458*>(v0)->vf4();
    }
}

struct Unk_ff6020_arg1 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_ff6020_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_ff6020_arg1, field_8, 0x8);

struct Unk_ff6020 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_ff6020, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_ff6020, field_8, 0x8);

// 0x7100ff6020
void Unk_ff6020_call(const Unk_ff6020* self, Unk_ff6020_arg1* value) {
    value->field_0 = self->field_0;
    Unk_239a418* v0 = self->field_8;
    value->field_8 = v0;
    if (v0 != nullptr) {
        static_cast<Unk_239a458*>(v0)->vf4();
    }
}

struct Unk_ff60c0_arg1 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_ff60c0_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_ff60c0_arg1, field_8, 0x8);

struct Unk_ff60c0 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_ff60c0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_ff60c0, field_8, 0x8);

// 0x7100ff60c0
void Unk_ff60c0_call(const Unk_ff60c0* self, Unk_ff60c0_arg1* value) {
    value->field_0 = self->field_0;
    Unk_239a418* v0 = self->field_8;
    value->field_8 = v0;
    if (v0 != nullptr) {
        static_cast<Unk_239a458*>(v0)->vf4();
    }
}

struct Unk_ff60f0_arg1 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_ff60f0_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_ff60f0_arg1, field_8, 0x8);

struct Unk_ff60f0 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_ff60f0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_ff60f0, field_8, 0x8);

// 0x7100ff60f0
void Unk_ff60f0_call(const Unk_ff60f0* self, Unk_ff60f0_arg1* value) {
    value->field_0 = self->field_0;
    Unk_239a418* v0 = self->field_8;
    value->field_8 = v0;
    if (v0 != nullptr) {
        static_cast<Unk_239a458*>(v0)->vf4();
    }
}

struct Unk_ff6770_arg1 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_ff6770_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_ff6770_arg1, field_8, 0x8);

struct Unk_ff6770 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_ff6770, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_ff6770, field_8, 0x8);

// 0x7100ff6770
void Unk_ff6770_call(const Unk_ff6770* self, Unk_ff6770_arg1* value) {
    value->field_0 = self->field_0;
    Unk_239a418* v0 = self->field_8;
    value->field_8 = v0;
    if (v0 != nullptr) {
        static_cast<Unk_239a458*>(v0)->vf4();
    }
}

struct Unk_ff67a0_arg1 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_ff67a0_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_ff67a0_arg1, field_8, 0x8);

struct Unk_ff67a0 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_ff67a0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_ff67a0, field_8, 0x8);

// 0x7100ff67a0
void Unk_ff67a0_call(const Unk_ff67a0* self, Unk_ff67a0_arg1* value) {
    value->field_0 = self->field_0;
    Unk_239a418* v0 = self->field_8;
    value->field_8 = v0;
    if (v0 != nullptr) {
        static_cast<Unk_239a458*>(v0)->vf4();
    }
}

struct Unk_ff6850_arg1 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_ff6850_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_ff6850_arg1, field_8, 0x8);

struct Unk_ff6850 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_ff6850, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_ff6850, field_8, 0x8);

// 0x7100ff6850
void Unk_ff6850_call(const Unk_ff6850* self, Unk_ff6850_arg1* value) {
    value->field_0 = self->field_0;
    Unk_239a418* v0 = self->field_8;
    value->field_8 = v0;
    if (v0 != nullptr) {
        static_cast<Unk_239a458*>(v0)->vf4();
    }
}

struct Unk_ff6880_arg1 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_ff6880_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_ff6880_arg1, field_8, 0x8);

struct Unk_ff6880 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_ff6880, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_ff6880, field_8, 0x8);

// 0x7100ff6880
void Unk_ff6880_call(const Unk_ff6880* self, Unk_ff6880_arg1* value) {
    value->field_0 = self->field_0;
    Unk_239a418* v0 = self->field_8;
    value->field_8 = v0;
    if (v0 != nullptr) {
        static_cast<Unk_239a458*>(v0)->vf4();
    }
}

struct Unk_ff6920_arg1 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_ff6920_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_ff6920_arg1, field_8, 0x8);

struct Unk_ff6920 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_ff6920, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_ff6920, field_8, 0x8);

// 0x7100ff6920
void Unk_ff6920_call(const Unk_ff6920* self, Unk_ff6920_arg1* value) {
    value->field_0 = self->field_0;
    Unk_239a418* v0 = self->field_8;
    value->field_8 = v0;
    if (v0 != nullptr) {
        static_cast<Unk_239a458*>(v0)->vf4();
    }
}

struct Unk_ff6950_arg1 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_ff6950_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_ff6950_arg1, field_8, 0x8);

struct Unk_ff6950 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_ff6950, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_ff6950, field_8, 0x8);

// 0x7100ff6950
void Unk_ff6950_call(const Unk_ff6950* self, Unk_ff6950_arg1* value) {
    value->field_0 = self->field_0;
    Unk_239a418* v0 = self->field_8;
    value->field_8 = v0;
    if (v0 != nullptr) {
        static_cast<Unk_239a458*>(v0)->vf4();
    }
}

struct Unk_ff6a00_arg1 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_ff6a00_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_ff6a00_arg1, field_8, 0x8);

struct Unk_ff6a00 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_ff6a00, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_ff6a00, field_8, 0x8);

// 0x7100ff6a00
void Unk_ff6a00_call(const Unk_ff6a00* self, Unk_ff6a00_arg1* value) {
    value->field_0 = self->field_0;
    Unk_239a418* v0 = self->field_8;
    value->field_8 = v0;
    if (v0 != nullptr) {
        static_cast<Unk_239a458*>(v0)->vf4();
    }
}

struct Unk_ff6a30_arg1 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_ff6a30_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_ff6a30_arg1, field_8, 0x8);

struct Unk_ff6a30 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_ff6a30, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_ff6a30, field_8, 0x8);

// 0x7100ff6a30
void Unk_ff6a30_call(const Unk_ff6a30* self, Unk_ff6a30_arg1* value) {
    value->field_0 = self->field_0;
    Unk_239a418* v0 = self->field_8;
    value->field_8 = v0;
    if (v0 != nullptr) {
        static_cast<Unk_239a458*>(v0)->vf4();
    }
}

struct Unk_ff6ae0_arg1 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_ff6ae0_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_ff6ae0_arg1, field_8, 0x8);

struct Unk_ff6ae0 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_ff6ae0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_ff6ae0, field_8, 0x8);

// 0x7100ff6ae0
void Unk_ff6ae0_call(const Unk_ff6ae0* self, Unk_ff6ae0_arg1* value) {
    value->field_0 = self->field_0;
    Unk_239a418* v0 = self->field_8;
    value->field_8 = v0;
    if (v0 != nullptr) {
        static_cast<Unk_239a458*>(v0)->vf4();
    }
}

struct Unk_ff6b10_arg1 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_ff6b10_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_ff6b10_arg1, field_8, 0x8);

struct Unk_ff6b10 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_ff6b10, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_ff6b10, field_8, 0x8);

// 0x7100ff6b10
void Unk_ff6b10_call(const Unk_ff6b10* self, Unk_ff6b10_arg1* value) {
    value->field_0 = self->field_0;
    Unk_239a418* v0 = self->field_8;
    value->field_8 = v0;
    if (v0 != nullptr) {
        static_cast<Unk_239a458*>(v0)->vf4();
    }
}

struct Unk_ff6bc0_arg1 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_ff6bc0_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_ff6bc0_arg1, field_8, 0x8);

struct Unk_ff6bc0 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_ff6bc0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_ff6bc0, field_8, 0x8);

// 0x7100ff6bc0
void Unk_ff6bc0_call(const Unk_ff6bc0* self, Unk_ff6bc0_arg1* value) {
    value->field_0 = self->field_0;
    Unk_239a418* v0 = self->field_8;
    value->field_8 = v0;
    if (v0 != nullptr) {
        static_cast<Unk_239a458*>(v0)->vf4();
    }
}

struct Unk_ff6bf0_arg1 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_ff6bf0_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_ff6bf0_arg1, field_8, 0x8);

struct Unk_ff6bf0 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_ff6bf0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_ff6bf0, field_8, 0x8);

// 0x7100ff6bf0
void Unk_ff6bf0_call(const Unk_ff6bf0* self, Unk_ff6bf0_arg1* value) {
    value->field_0 = self->field_0;
    Unk_239a418* v0 = self->field_8;
    value->field_8 = v0;
    if (v0 != nullptr) {
        static_cast<Unk_239a458*>(v0)->vf4();
    }
}

struct Unk_ff6df0_arg1 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_ff6df0_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_ff6df0_arg1, field_8, 0x8);

struct Unk_ff6df0 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_ff6df0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_ff6df0, field_8, 0x8);

// 0x7100ff6df0
void Unk_ff6df0_call(const Unk_ff6df0* self, Unk_ff6df0_arg1* value) {
    value->field_0 = self->field_0;
    Unk_239a418* v0 = self->field_8;
    value->field_8 = v0;
    if (v0 != nullptr) {
        static_cast<Unk_239a458*>(v0)->vf4();
    }
}

struct Unk_ff6e20_arg1 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_ff6e20_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_ff6e20_arg1, field_8, 0x8);

struct Unk_ff6e20 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_ff6e20, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_ff6e20, field_8, 0x8);

// 0x7100ff6e20
void Unk_ff6e20_call(const Unk_ff6e20* self, Unk_ff6e20_arg1* value) {
    value->field_0 = self->field_0;
    Unk_239a418* v0 = self->field_8;
    value->field_8 = v0;
    if (v0 != nullptr) {
        static_cast<Unk_239a458*>(v0)->vf4();
    }
}

struct Unk_ff6ec0_arg1 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_ff6ec0_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_ff6ec0_arg1, field_8, 0x8);

struct Unk_ff6ec0 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_ff6ec0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_ff6ec0, field_8, 0x8);

// 0x7100ff6ec0
void Unk_ff6ec0_call(const Unk_ff6ec0* self, Unk_ff6ec0_arg1* value) {
    value->field_0 = self->field_0;
    Unk_239a418* v0 = self->field_8;
    value->field_8 = v0;
    if (v0 != nullptr) {
        static_cast<Unk_239a458*>(v0)->vf4();
    }
}

struct Unk_ff6ef0_arg1 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_ff6ef0_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_ff6ef0_arg1, field_8, 0x8);

struct Unk_ff6ef0 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_ff6ef0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_ff6ef0, field_8, 0x8);

// 0x7100ff6ef0
void Unk_ff6ef0_call(const Unk_ff6ef0* self, Unk_ff6ef0_arg1* value) {
    value->field_0 = self->field_0;
    Unk_239a418* v0 = self->field_8;
    value->field_8 = v0;
    if (v0 != nullptr) {
        static_cast<Unk_239a458*>(v0)->vf4();
    }
}

struct Unk_ff6fa0_arg1 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_ff6fa0_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_ff6fa0_arg1, field_8, 0x8);

struct Unk_ff6fa0 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_ff6fa0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_ff6fa0, field_8, 0x8);

// 0x7100ff6fa0
void Unk_ff6fa0_call(const Unk_ff6fa0* self, Unk_ff6fa0_arg1* value) {
    value->field_0 = self->field_0;
    Unk_239a418* v0 = self->field_8;
    value->field_8 = v0;
    if (v0 != nullptr) {
        static_cast<Unk_239a458*>(v0)->vf4();
    }
}

struct Unk_ff6fd0_arg1 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_ff6fd0_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_ff6fd0_arg1, field_8, 0x8);

struct Unk_ff6fd0 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_ff6fd0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_ff6fd0, field_8, 0x8);

// 0x7100ff6fd0
void Unk_ff6fd0_call(const Unk_ff6fd0* self, Unk_ff6fd0_arg1* value) {
    value->field_0 = self->field_0;
    Unk_239a418* v0 = self->field_8;
    value->field_8 = v0;
    if (v0 != nullptr) {
        static_cast<Unk_239a458*>(v0)->vf4();
    }
}

struct Unk_ff7070_arg1 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_ff7070_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_ff7070_arg1, field_8, 0x8);

struct Unk_ff7070 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_ff7070, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_ff7070, field_8, 0x8);

// 0x7100ff7070
void Unk_ff7070_call(const Unk_ff7070* self, Unk_ff7070_arg1* value) {
    value->field_0 = self->field_0;
    Unk_239a418* v0 = self->field_8;
    value->field_8 = v0;
    if (v0 != nullptr) {
        static_cast<Unk_239a458*>(v0)->vf4();
    }
}

struct Unk_ff70a0_arg1 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_ff70a0_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_ff70a0_arg1, field_8, 0x8);

struct Unk_ff70a0 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_ff70a0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_ff70a0, field_8, 0x8);

// 0x7100ff70a0
void Unk_ff70a0_call(const Unk_ff70a0* self, Unk_ff70a0_arg1* value) {
    value->field_0 = self->field_0;
    Unk_239a418* v0 = self->field_8;
    value->field_8 = v0;
    if (v0 != nullptr) {
        static_cast<Unk_239a458*>(v0)->vf4();
    }
}

struct Unk_ff7140_arg1 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_ff7140_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_ff7140_arg1, field_8, 0x8);

struct Unk_ff7140 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_ff7140, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_ff7140, field_8, 0x8);

// 0x7100ff7140
void Unk_ff7140_call(const Unk_ff7140* self, Unk_ff7140_arg1* value) {
    value->field_0 = self->field_0;
    Unk_239a418* v0 = self->field_8;
    value->field_8 = v0;
    if (v0 != nullptr) {
        static_cast<Unk_239a458*>(v0)->vf4();
    }
}

struct Unk_ff7170_arg1 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_ff7170_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_ff7170_arg1, field_8, 0x8);

struct Unk_ff7170 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_ff7170, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_ff7170, field_8, 0x8);

// 0x7100ff7170
void Unk_ff7170_call(const Unk_ff7170* self, Unk_ff7170_arg1* value) {
    value->field_0 = self->field_0;
    Unk_239a418* v0 = self->field_8;
    value->field_8 = v0;
    if (v0 != nullptr) {
        static_cast<Unk_239a458*>(v0)->vf4();
    }
}

struct Unk_ff7210_arg1 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_ff7210_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_ff7210_arg1, field_8, 0x8);

struct Unk_ff7210 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_ff7210, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_ff7210, field_8, 0x8);

// 0x7100ff7210
void Unk_ff7210_call(const Unk_ff7210* self, Unk_ff7210_arg1* value) {
    value->field_0 = self->field_0;
    Unk_239a418* v0 = self->field_8;
    value->field_8 = v0;
    if (v0 != nullptr) {
        static_cast<Unk_239a458*>(v0)->vf4();
    }
}

struct Unk_ff7240_arg1 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_ff7240_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_ff7240_arg1, field_8, 0x8);

struct Unk_ff7240 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_ff7240, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_ff7240, field_8, 0x8);

// 0x7100ff7240
void Unk_ff7240_call(const Unk_ff7240* self, Unk_ff7240_arg1* value) {
    value->field_0 = self->field_0;
    Unk_239a418* v0 = self->field_8;
    value->field_8 = v0;
    if (v0 != nullptr) {
        static_cast<Unk_239a458*>(v0)->vf4();
    }
}

struct Unk_ff7270_0 {
    u8 _0[0x248];
    u8 field_248;
    u8 _249[0x3];
    u32 field_24c;
};
PKMN_OFFSET_ASSERT(Unk_ff7270_0, field_248, 0x248);
PKMN_OFFSET_ASSERT(Unk_ff7270_0, field_24c, 0x24c);

struct Unk_ff7270 {
    Unk_ff7270_0* field_0;
};
PKMN_OFFSET_ASSERT(Unk_ff7270, field_0, 0x0);

// 0x7100ff7270
void Unk_ff7270_set(const Unk_ff7270* self) {
    Unk_ff7270_0* p0 = self->field_0;
    p0->field_24c = 0xe;
    p0->field_248 = 1;
}

// 0x7100ff7290
void Unk_ff7290_update() {}

struct Unk_ff72a0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_ff72a0_arg1, field_0, 0x0);

struct Unk_ff72a0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_ff72a0, field_0, 0x0);

// 0x7100ff72a0
void Unk_ff72a0_set(const Unk_ff72a0* self, Unk_ff72a0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_ff72b0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_ff72b0_arg1, field_0, 0x0);

struct Unk_ff72b0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_ff72b0, field_0, 0x0);

// 0x7100ff72b0
void Unk_ff72b0_set(const Unk_ff72b0* self, Unk_ff72b0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_ff72c0_0 {
    u8 _0[0x248];
    u8 field_248;
    u8 _249[0x3];
    u32 field_24c;
};
PKMN_OFFSET_ASSERT(Unk_ff72c0_0, field_248, 0x248);
PKMN_OFFSET_ASSERT(Unk_ff72c0_0, field_24c, 0x24c);

struct Unk_ff72c0 {
    Unk_ff72c0_0* field_0;
};
PKMN_OFFSET_ASSERT(Unk_ff72c0, field_0, 0x0);

// 0x7100ff72c0
void Unk_ff72c0_set(const Unk_ff72c0* self) {
    Unk_ff72c0_0* p0 = self->field_0;
    p0->field_24c = 0x10;
    p0->field_248 = 1;
}

// 0x7100ff72e0
void Unk_ff72e0_update() {}

struct Unk_ff72f0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_ff72f0_arg1, field_0, 0x0);

struct Unk_ff72f0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_ff72f0, field_0, 0x0);

// 0x7100ff72f0
void Unk_ff72f0_set(const Unk_ff72f0* self, Unk_ff72f0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_ff7300_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_ff7300_arg1, field_0, 0x0);

struct Unk_ff7300 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_ff7300, field_0, 0x0);

// 0x7100ff7300
void Unk_ff7300_set(const Unk_ff7300* self, Unk_ff7300_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_ff7310_0 {
    u8 _0[0x248];
    u8 field_248;
    u8 _249[0x3];
    u32 field_24c;
};
PKMN_OFFSET_ASSERT(Unk_ff7310_0, field_248, 0x248);
PKMN_OFFSET_ASSERT(Unk_ff7310_0, field_24c, 0x24c);

struct Unk_ff7310 {
    Unk_ff7310_0* field_0;
};
PKMN_OFFSET_ASSERT(Unk_ff7310, field_0, 0x0);

// 0x7100ff7310
void Unk_ff7310_set(const Unk_ff7310* self) {
    Unk_ff7310_0* p0 = self->field_0;
    p0->field_24c = 0x11;
    p0->field_248 = 1;
}

// 0x7100ff7330
void Unk_ff7330_update() {}

struct Unk_ff7340_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_ff7340_arg1, field_0, 0x0);

struct Unk_ff7340 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_ff7340, field_0, 0x0);

// 0x7100ff7340
void Unk_ff7340_set(const Unk_ff7340* self, Unk_ff7340_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_ff7350_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_ff7350_arg1, field_0, 0x0);

struct Unk_ff7350 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_ff7350, field_0, 0x0);

// 0x7100ff7350
void Unk_ff7350_set(const Unk_ff7350* self, Unk_ff7350_arg1* value) {
    value->field_0 = self->field_0;
}
