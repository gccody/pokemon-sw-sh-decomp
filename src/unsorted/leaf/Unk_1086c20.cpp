// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

#include "gflib3/Unk_239a418.h"

struct Unk_1086c20_arg1 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_1086c20_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_1086c20_arg1, field_8, 0x8);

struct Unk_1086c20 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_1086c20, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_1086c20, field_8, 0x8);

// 0x7101086c20
void Unk_1086c20_set(Unk_1086c20* self, Unk_1086c20_arg1* value) {
    u64 v0 = self->field_0;
    self->field_0 = 0;
    value->field_0 = v0;
    u64 v1 = self->field_8;
    self->field_8 = 0;
    value->field_8 = v1;
}

struct Unk_1086cc0_arg1 {
    Unk_239a418* field_0;
};
PKMN_OFFSET_ASSERT(Unk_1086cc0_arg1, field_0, 0x0);

struct Unk_1086cc0 {
    Unk_239a418* field_0;
};
PKMN_OFFSET_ASSERT(Unk_1086cc0, field_0, 0x0);

// 0x7101086cc0
void Unk_1086cc0_call(const Unk_1086cc0* self, Unk_1086cc0_arg1* value) {
    Unk_239a418* v0 = self->field_0;
    value->field_0 = v0;
    if (v0 != nullptr) {
        static_cast<Unk_239a458*>(v0)->vf4();
    }
}

struct Unk_1086ce0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1086ce0_arg1, field_0, 0x0);

struct Unk_1086ce0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1086ce0, field_0, 0x0);

// 0x7101086ce0
void Unk_1086ce0_set(Unk_1086ce0* self, Unk_1086ce0_arg1* value) {
    u64 v0 = self->field_0;
    self->field_0 = 0;
    value->field_0 = v0;
}

struct Unk_1086d90_arg1 {
    Unk_239a418* field_0;
};
PKMN_OFFSET_ASSERT(Unk_1086d90_arg1, field_0, 0x0);

struct Unk_1086d90 {
    Unk_239a418* field_0;
};
PKMN_OFFSET_ASSERT(Unk_1086d90, field_0, 0x0);

// 0x7101086d90
void Unk_1086d90_call(const Unk_1086d90* self, Unk_1086d90_arg1* value) {
    Unk_239a418* v0 = self->field_0;
    value->field_0 = v0;
    if (v0 != nullptr) {
        static_cast<Unk_239a458*>(v0)->vf4();
    }
}

struct Unk_1086db0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1086db0_arg1, field_0, 0x0);

struct Unk_1086db0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1086db0, field_0, 0x0);

// 0x7101086db0
void Unk_1086db0_set(Unk_1086db0* self, Unk_1086db0_arg1* value) {
    u64 v0 = self->field_0;
    self->field_0 = 0;
    value->field_0 = v0;
}

struct Unk_1088290_arg1 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_1088290_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_1088290_arg1, field_8, 0x8);

struct Unk_1088290 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_1088290, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_1088290, field_8, 0x8);

// 0x7101088290
void Unk_1088290_set(Unk_1088290* self, Unk_1088290_arg1* value) {
    u64 v0 = self->field_0;
    self->field_0 = 0;
    value->field_0 = v0;
    u64 v1 = self->field_8;
    self->field_8 = 0;
    value->field_8 = v1;
}

struct Unk_1088330_arg1 {
    Unk_239a418* field_0;
};
PKMN_OFFSET_ASSERT(Unk_1088330_arg1, field_0, 0x0);

struct Unk_1088330 {
    Unk_239a418* field_0;
};
PKMN_OFFSET_ASSERT(Unk_1088330, field_0, 0x0);

// 0x7101088330
void Unk_1088330_call(const Unk_1088330* self, Unk_1088330_arg1* value) {
    Unk_239a418* v0 = self->field_0;
    value->field_0 = v0;
    if (v0 != nullptr) {
        static_cast<Unk_239a458*>(v0)->vf4();
    }
}

struct Unk_1088350_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1088350_arg1, field_0, 0x0);

struct Unk_1088350 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1088350, field_0, 0x0);

// 0x7101088350
void Unk_1088350_set(Unk_1088350* self, Unk_1088350_arg1* value) {
    u64 v0 = self->field_0;
    self->field_0 = 0;
    value->field_0 = v0;
}

struct Unk_1088400_arg1 {
    Unk_239a418* field_0;
};
PKMN_OFFSET_ASSERT(Unk_1088400_arg1, field_0, 0x0);

struct Unk_1088400 {
    Unk_239a418* field_0;
};
PKMN_OFFSET_ASSERT(Unk_1088400, field_0, 0x0);

// 0x7101088400
void Unk_1088400_call(const Unk_1088400* self, Unk_1088400_arg1* value) {
    Unk_239a418* v0 = self->field_0;
    value->field_0 = v0;
    if (v0 != nullptr) {
        static_cast<Unk_239a458*>(v0)->vf4();
    }
}

struct Unk_1088420_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1088420_arg1, field_0, 0x0);

struct Unk_1088420 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1088420, field_0, 0x0);

// 0x7101088420
void Unk_1088420_set(Unk_1088420* self, Unk_1088420_arg1* value) {
    u64 v0 = self->field_0;
    self->field_0 = 0;
    value->field_0 = v0;
}

struct Unk_108aa10_arg1 {
    Unk_239a418* field_0;
};
PKMN_OFFSET_ASSERT(Unk_108aa10_arg1, field_0, 0x0);

struct Unk_108aa10 {
    Unk_239a418* field_0;
};
PKMN_OFFSET_ASSERT(Unk_108aa10, field_0, 0x0);

// 0x710108aa10
void Unk_108aa10_call(const Unk_108aa10* self, Unk_108aa10_arg1* value) {
    Unk_239a418* v0 = self->field_0;
    value->field_0 = v0;
    if (v0 != nullptr) {
        static_cast<Unk_239a458*>(v0)->vf4();
    }
}

struct Unk_108aa30_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_108aa30_arg1, field_0, 0x0);

struct Unk_108aa30 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_108aa30, field_0, 0x0);

// 0x710108aa30
void Unk_108aa30_set(Unk_108aa30* self, Unk_108aa30_arg1* value) {
    u64 v0 = self->field_0;
    self->field_0 = 0;
    value->field_0 = v0;
}

struct Unk_108aac0_arg1 {
    Unk_239a418* field_0;
};
PKMN_OFFSET_ASSERT(Unk_108aac0_arg1, field_0, 0x0);

struct Unk_108aac0 {
    Unk_239a418* field_0;
};
PKMN_OFFSET_ASSERT(Unk_108aac0, field_0, 0x0);

// 0x710108aac0
void Unk_108aac0_call(const Unk_108aac0* self, Unk_108aac0_arg1* value) {
    Unk_239a418* v0 = self->field_0;
    value->field_0 = v0;
    if (v0 != nullptr) {
        static_cast<Unk_239a458*>(v0)->vf4();
    }
}

struct Unk_108aae0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_108aae0_arg1, field_0, 0x0);

struct Unk_108aae0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_108aae0, field_0, 0x0);

// 0x710108aae0
void Unk_108aae0_set(Unk_108aae0* self, Unk_108aae0_arg1* value) {
    u64 v0 = self->field_0;
    self->field_0 = 0;
    value->field_0 = v0;
}

struct Unk_108ab90_arg1 {
    Unk_239a418* field_0;
};
PKMN_OFFSET_ASSERT(Unk_108ab90_arg1, field_0, 0x0);

struct Unk_108ab90 {
    Unk_239a418* field_0;
};
PKMN_OFFSET_ASSERT(Unk_108ab90, field_0, 0x0);

// 0x710108ab90
void Unk_108ab90_call(const Unk_108ab90* self, Unk_108ab90_arg1* value) {
    Unk_239a418* v0 = self->field_0;
    value->field_0 = v0;
    if (v0 != nullptr) {
        static_cast<Unk_239a458*>(v0)->vf4();
    }
}

struct Unk_108abb0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_108abb0_arg1, field_0, 0x0);

struct Unk_108abb0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_108abb0, field_0, 0x0);

// 0x710108abb0
void Unk_108abb0_set(Unk_108abb0* self, Unk_108abb0_arg1* value) {
    u64 v0 = self->field_0;
    self->field_0 = 0;
    value->field_0 = v0;
}

struct Unk_108cf20_arg1 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_108cf20_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_108cf20_arg1, field_8, 0x8);

struct Unk_108cf20 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_108cf20, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_108cf20, field_8, 0x8);

// 0x710108cf20
void Unk_108cf20_set(Unk_108cf20* self, Unk_108cf20_arg1* value) {
    u64 v0 = self->field_0;
    self->field_0 = 0;
    value->field_0 = v0;
    u64 v1 = self->field_8;
    self->field_8 = 0;
    value->field_8 = v1;
}

struct Unk_108cf90_arg1 {
    Unk_239a418* field_0;
};
PKMN_OFFSET_ASSERT(Unk_108cf90_arg1, field_0, 0x0);

struct Unk_108cf90 {
    Unk_239a418* field_0;
};
PKMN_OFFSET_ASSERT(Unk_108cf90, field_0, 0x0);

// 0x710108cf90
void Unk_108cf90_call(const Unk_108cf90* self, Unk_108cf90_arg1* value) {
    Unk_239a418* v0 = self->field_0;
    value->field_0 = v0;
    if (v0 != nullptr) {
        static_cast<Unk_239a458*>(v0)->vf4();
    }
}

struct Unk_108cfb0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_108cfb0_arg1, field_0, 0x0);

struct Unk_108cfb0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_108cfb0, field_0, 0x0);

// 0x710108cfb0
void Unk_108cfb0_set(Unk_108cfb0* self, Unk_108cfb0_arg1* value) {
    u64 v0 = self->field_0;
    self->field_0 = 0;
    value->field_0 = v0;
}

struct Unk_108d060_arg1 {
    Unk_239a418* field_0;
};
PKMN_OFFSET_ASSERT(Unk_108d060_arg1, field_0, 0x0);

struct Unk_108d060 {
    Unk_239a418* field_0;
};
PKMN_OFFSET_ASSERT(Unk_108d060, field_0, 0x0);

// 0x710108d060
void Unk_108d060_call(const Unk_108d060* self, Unk_108d060_arg1* value) {
    Unk_239a418* v0 = self->field_0;
    value->field_0 = v0;
    if (v0 != nullptr) {
        static_cast<Unk_239a458*>(v0)->vf4();
    }
}

struct Unk_108d080_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_108d080_arg1, field_0, 0x0);

struct Unk_108d080 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_108d080, field_0, 0x0);

// 0x710108d080
void Unk_108d080_set(Unk_108d080* self, Unk_108d080_arg1* value) {
    u64 v0 = self->field_0;
    self->field_0 = 0;
    value->field_0 = v0;
}

struct Unk_108e9b0_arg1 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_108e9b0_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_108e9b0_arg1, field_8, 0x8);

struct Unk_108e9b0 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_108e9b0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_108e9b0, field_8, 0x8);

// 0x710108e9b0
void Unk_108e9b0_set(Unk_108e9b0* self, Unk_108e9b0_arg1* value) {
    u64 v0 = self->field_0;
    self->field_0 = 0;
    value->field_0 = v0;
    u64 v1 = self->field_8;
    self->field_8 = 0;
    value->field_8 = v1;
}

struct Unk_108ea20_arg1 {
    Unk_239a418* field_0;
};
PKMN_OFFSET_ASSERT(Unk_108ea20_arg1, field_0, 0x0);

struct Unk_108ea20 {
    Unk_239a418* field_0;
};
PKMN_OFFSET_ASSERT(Unk_108ea20, field_0, 0x0);

// 0x710108ea20
void Unk_108ea20_call(const Unk_108ea20* self, Unk_108ea20_arg1* value) {
    Unk_239a418* v0 = self->field_0;
    value->field_0 = v0;
    if (v0 != nullptr) {
        static_cast<Unk_239a458*>(v0)->vf4();
    }
}

struct Unk_108ea40_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_108ea40_arg1, field_0, 0x0);

struct Unk_108ea40 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_108ea40, field_0, 0x0);

// 0x710108ea40
void Unk_108ea40_set(Unk_108ea40* self, Unk_108ea40_arg1* value) {
    u64 v0 = self->field_0;
    self->field_0 = 0;
    value->field_0 = v0;
}

struct Unk_108eaf0_arg1 {
    Unk_239a418* field_0;
};
PKMN_OFFSET_ASSERT(Unk_108eaf0_arg1, field_0, 0x0);

struct Unk_108eaf0 {
    Unk_239a418* field_0;
};
PKMN_OFFSET_ASSERT(Unk_108eaf0, field_0, 0x0);

// 0x710108eaf0
void Unk_108eaf0_call(const Unk_108eaf0* self, Unk_108eaf0_arg1* value) {
    Unk_239a418* v0 = self->field_0;
    value->field_0 = v0;
    if (v0 != nullptr) {
        static_cast<Unk_239a458*>(v0)->vf4();
    }
}

struct Unk_108eb10_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_108eb10_arg1, field_0, 0x0);

struct Unk_108eb10 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_108eb10, field_0, 0x0);

// 0x710108eb10
void Unk_108eb10_set(Unk_108eb10* self, Unk_108eb10_arg1* value) {
    u64 v0 = self->field_0;
    self->field_0 = 0;
    value->field_0 = v0;
}

struct Unk_10913c0_arg1 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_10913c0_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_10913c0_arg1, field_8, 0x8);

struct Unk_10913c0 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_10913c0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_10913c0, field_8, 0x8);

// 0x71010913c0
void Unk_10913c0_set(Unk_10913c0* self, Unk_10913c0_arg1* value) {
    u64 v0 = self->field_0;
    self->field_0 = 0;
    value->field_0 = v0;
    u64 v1 = self->field_8;
    self->field_8 = 0;
    value->field_8 = v1;
}

struct Unk_1091460_arg1 {
    Unk_239a418* field_0;
};
PKMN_OFFSET_ASSERT(Unk_1091460_arg1, field_0, 0x0);

struct Unk_1091460 {
    Unk_239a418* field_0;
};
PKMN_OFFSET_ASSERT(Unk_1091460, field_0, 0x0);

// 0x7101091460
void Unk_1091460_call(const Unk_1091460* self, Unk_1091460_arg1* value) {
    Unk_239a418* v0 = self->field_0;
    value->field_0 = v0;
    if (v0 != nullptr) {
        static_cast<Unk_239a458*>(v0)->vf4();
    }
}

struct Unk_1091480_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1091480_arg1, field_0, 0x0);

struct Unk_1091480 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1091480, field_0, 0x0);

// 0x7101091480
void Unk_1091480_set(Unk_1091480* self, Unk_1091480_arg1* value) {
    u64 v0 = self->field_0;
    self->field_0 = 0;
    value->field_0 = v0;
}

struct Unk_1091530_arg1 {
    Unk_239a418* field_0;
};
PKMN_OFFSET_ASSERT(Unk_1091530_arg1, field_0, 0x0);

struct Unk_1091530 {
    Unk_239a418* field_0;
};
PKMN_OFFSET_ASSERT(Unk_1091530, field_0, 0x0);

// 0x7101091530
void Unk_1091530_call(const Unk_1091530* self, Unk_1091530_arg1* value) {
    Unk_239a418* v0 = self->field_0;
    value->field_0 = v0;
    if (v0 != nullptr) {
        static_cast<Unk_239a458*>(v0)->vf4();
    }
}

struct Unk_1091550_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1091550_arg1, field_0, 0x0);

struct Unk_1091550 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1091550, field_0, 0x0);

// 0x7101091550
void Unk_1091550_set(Unk_1091550* self, Unk_1091550_arg1* value) {
    u64 v0 = self->field_0;
    self->field_0 = 0;
    value->field_0 = v0;
}

struct Unk_10942b0_arg1 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_10942b0_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_10942b0_arg1, field_8, 0x8);

struct Unk_10942b0 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_10942b0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_10942b0, field_8, 0x8);

// 0x71010942b0
void Unk_10942b0_set(Unk_10942b0* self, Unk_10942b0_arg1* value) {
    u64 v0 = self->field_0;
    self->field_0 = 0;
    value->field_0 = v0;
    u64 v1 = self->field_8;
    self->field_8 = 0;
    value->field_8 = v1;
}

struct Unk_1094350_arg1 {
    Unk_239a418* field_0;
};
PKMN_OFFSET_ASSERT(Unk_1094350_arg1, field_0, 0x0);

struct Unk_1094350 {
    Unk_239a418* field_0;
};
PKMN_OFFSET_ASSERT(Unk_1094350, field_0, 0x0);

// 0x7101094350
void Unk_1094350_call(const Unk_1094350* self, Unk_1094350_arg1* value) {
    Unk_239a418* v0 = self->field_0;
    value->field_0 = v0;
    if (v0 != nullptr) {
        static_cast<Unk_239a458*>(v0)->vf4();
    }
}

struct Unk_1094370_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1094370_arg1, field_0, 0x0);

struct Unk_1094370 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1094370, field_0, 0x0);

// 0x7101094370
void Unk_1094370_set(Unk_1094370* self, Unk_1094370_arg1* value) {
    u64 v0 = self->field_0;
    self->field_0 = 0;
    value->field_0 = v0;
}

struct Unk_1094420_arg1 {
    Unk_239a418* field_0;
};
PKMN_OFFSET_ASSERT(Unk_1094420_arg1, field_0, 0x0);

struct Unk_1094420 {
    Unk_239a418* field_0;
};
PKMN_OFFSET_ASSERT(Unk_1094420, field_0, 0x0);

// 0x7101094420
void Unk_1094420_call(const Unk_1094420* self, Unk_1094420_arg1* value) {
    Unk_239a418* v0 = self->field_0;
    value->field_0 = v0;
    if (v0 != nullptr) {
        static_cast<Unk_239a458*>(v0)->vf4();
    }
}

struct Unk_1094440_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1094440_arg1, field_0, 0x0);

struct Unk_1094440 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1094440, field_0, 0x0);

// 0x7101094440
void Unk_1094440_set(Unk_1094440* self, Unk_1094440_arg1* value) {
    u64 v0 = self->field_0;
    self->field_0 = 0;
    value->field_0 = v0;
}

struct Unk_1095af0_arg1 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_1095af0_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_1095af0_arg1, field_8, 0x8);

struct Unk_1095af0 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_1095af0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_1095af0, field_8, 0x8);

// 0x7101095af0
void Unk_1095af0_set(Unk_1095af0* self, Unk_1095af0_arg1* value) {
    u64 v0 = self->field_0;
    self->field_0 = 0;
    value->field_0 = v0;
    u64 v1 = self->field_8;
    self->field_8 = 0;
    value->field_8 = v1;
}

struct Unk_1095b60_arg1 {
    Unk_239a418* field_0;
};
PKMN_OFFSET_ASSERT(Unk_1095b60_arg1, field_0, 0x0);

struct Unk_1095b60 {
    Unk_239a418* field_0;
};
PKMN_OFFSET_ASSERT(Unk_1095b60, field_0, 0x0);

// 0x7101095b60
void Unk_1095b60_call(const Unk_1095b60* self, Unk_1095b60_arg1* value) {
    Unk_239a418* v0 = self->field_0;
    value->field_0 = v0;
    if (v0 != nullptr) {
        static_cast<Unk_239a458*>(v0)->vf4();
    }
}

struct Unk_1095b80_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1095b80_arg1, field_0, 0x0);

struct Unk_1095b80 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1095b80, field_0, 0x0);

// 0x7101095b80
void Unk_1095b80_set(Unk_1095b80* self, Unk_1095b80_arg1* value) {
    u64 v0 = self->field_0;
    self->field_0 = 0;
    value->field_0 = v0;
}

struct Unk_1095c30_arg1 {
    Unk_239a418* field_0;
};
PKMN_OFFSET_ASSERT(Unk_1095c30_arg1, field_0, 0x0);

struct Unk_1095c30 {
    Unk_239a418* field_0;
};
PKMN_OFFSET_ASSERT(Unk_1095c30, field_0, 0x0);

// 0x7101095c30
void Unk_1095c30_call(const Unk_1095c30* self, Unk_1095c30_arg1* value) {
    Unk_239a418* v0 = self->field_0;
    value->field_0 = v0;
    if (v0 != nullptr) {
        static_cast<Unk_239a458*>(v0)->vf4();
    }
}

struct Unk_1095c50_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1095c50_arg1, field_0, 0x0);

struct Unk_1095c50 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1095c50, field_0, 0x0);

// 0x7101095c50
void Unk_1095c50_set(Unk_1095c50* self, Unk_1095c50_arg1* value) {
    u64 v0 = self->field_0;
    self->field_0 = 0;
    value->field_0 = v0;
}

struct Unk_10976a0_arg1 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_10976a0_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_10976a0_arg1, field_8, 0x8);

struct Unk_10976a0 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_10976a0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_10976a0, field_8, 0x8);

// 0x71010976a0
void Unk_10976a0_set(Unk_10976a0* self, Unk_10976a0_arg1* value) {
    u64 v0 = self->field_0;
    self->field_0 = 0;
    value->field_0 = v0;
    u64 v1 = self->field_8;
    self->field_8 = 0;
    value->field_8 = v1;
}

struct Unk_1097710_arg1 {
    Unk_239a418* field_0;
};
PKMN_OFFSET_ASSERT(Unk_1097710_arg1, field_0, 0x0);

struct Unk_1097710 {
    Unk_239a418* field_0;
};
PKMN_OFFSET_ASSERT(Unk_1097710, field_0, 0x0);

// 0x7101097710
void Unk_1097710_call(const Unk_1097710* self, Unk_1097710_arg1* value) {
    Unk_239a418* v0 = self->field_0;
    value->field_0 = v0;
    if (v0 != nullptr) {
        static_cast<Unk_239a458*>(v0)->vf4();
    }
}

struct Unk_1097730_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1097730_arg1, field_0, 0x0);

struct Unk_1097730 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1097730, field_0, 0x0);

// 0x7101097730
void Unk_1097730_set(Unk_1097730* self, Unk_1097730_arg1* value) {
    u64 v0 = self->field_0;
    self->field_0 = 0;
    value->field_0 = v0;
}

struct Unk_10977e0_arg1 {
    Unk_239a418* field_0;
};
PKMN_OFFSET_ASSERT(Unk_10977e0_arg1, field_0, 0x0);

struct Unk_10977e0 {
    Unk_239a418* field_0;
};
PKMN_OFFSET_ASSERT(Unk_10977e0, field_0, 0x0);

// 0x71010977e0
void Unk_10977e0_call(const Unk_10977e0* self, Unk_10977e0_arg1* value) {
    Unk_239a418* v0 = self->field_0;
    value->field_0 = v0;
    if (v0 != nullptr) {
        static_cast<Unk_239a458*>(v0)->vf4();
    }
}

struct Unk_1097800_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1097800_arg1, field_0, 0x0);

struct Unk_1097800 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1097800, field_0, 0x0);

// 0x7101097800
void Unk_1097800_set(Unk_1097800* self, Unk_1097800_arg1* value) {
    u64 v0 = self->field_0;
    self->field_0 = 0;
    value->field_0 = v0;
}

struct Unk_1098980_arg1 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_1098980_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_1098980_arg1, field_8, 0x8);

struct Unk_1098980 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_1098980, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_1098980, field_8, 0x8);

// 0x7101098980
void Unk_1098980_set(Unk_1098980* self, Unk_1098980_arg1* value) {
    u64 v0 = self->field_0;
    self->field_0 = 0;
    value->field_0 = v0;
    u64 v1 = self->field_8;
    self->field_8 = 0;
    value->field_8 = v1;
}

struct Unk_10989f0_arg1 {
    Unk_239a418* field_0;
};
PKMN_OFFSET_ASSERT(Unk_10989f0_arg1, field_0, 0x0);

struct Unk_10989f0 {
    Unk_239a418* field_0;
};
PKMN_OFFSET_ASSERT(Unk_10989f0, field_0, 0x0);

// 0x71010989f0
void Unk_10989f0_call(const Unk_10989f0* self, Unk_10989f0_arg1* value) {
    Unk_239a418* v0 = self->field_0;
    value->field_0 = v0;
    if (v0 != nullptr) {
        static_cast<Unk_239a458*>(v0)->vf4();
    }
}

struct Unk_1098a10_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1098a10_arg1, field_0, 0x0);

struct Unk_1098a10 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1098a10, field_0, 0x0);

// 0x7101098a10
void Unk_1098a10_set(Unk_1098a10* self, Unk_1098a10_arg1* value) {
    u64 v0 = self->field_0;
    self->field_0 = 0;
    value->field_0 = v0;
}

struct Unk_1098ac0_arg1 {
    Unk_239a418* field_0;
};
PKMN_OFFSET_ASSERT(Unk_1098ac0_arg1, field_0, 0x0);

struct Unk_1098ac0 {
    Unk_239a418* field_0;
};
PKMN_OFFSET_ASSERT(Unk_1098ac0, field_0, 0x0);

// 0x7101098ac0
void Unk_1098ac0_call(const Unk_1098ac0* self, Unk_1098ac0_arg1* value) {
    Unk_239a418* v0 = self->field_0;
    value->field_0 = v0;
    if (v0 != nullptr) {
        static_cast<Unk_239a458*>(v0)->vf4();
    }
}

struct Unk_1098ae0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1098ae0_arg1, field_0, 0x0);

struct Unk_1098ae0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1098ae0, field_0, 0x0);

// 0x7101098ae0
void Unk_1098ae0_set(Unk_1098ae0* self, Unk_1098ae0_arg1* value) {
    u64 v0 = self->field_0;
    self->field_0 = 0;
    value->field_0 = v0;
}

struct Unk_10996c0_arg1 {
    Unk_239a418* field_0;
};
PKMN_OFFSET_ASSERT(Unk_10996c0_arg1, field_0, 0x0);

struct Unk_10996c0 {
    Unk_239a418* field_0;
};
PKMN_OFFSET_ASSERT(Unk_10996c0, field_0, 0x0);

// 0x71010996c0
void Unk_10996c0_call(const Unk_10996c0* self, Unk_10996c0_arg1* value) {
    Unk_239a418* v0 = self->field_0;
    value->field_0 = v0;
    if (v0 != nullptr) {
        static_cast<Unk_239a458*>(v0)->vf4();
    }
}

struct Unk_10996e0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_10996e0_arg1, field_0, 0x0);

struct Unk_10996e0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_10996e0, field_0, 0x0);

// 0x71010996e0
void Unk_10996e0_set(Unk_10996e0* self, Unk_10996e0_arg1* value) {
    u64 v0 = self->field_0;
    self->field_0 = 0;
    value->field_0 = v0;
}

struct Unk_1099740_arg1 {
    Unk_239a418* field_0;
};
PKMN_OFFSET_ASSERT(Unk_1099740_arg1, field_0, 0x0);

struct Unk_1099740 {
    Unk_239a418* field_0;
};
PKMN_OFFSET_ASSERT(Unk_1099740, field_0, 0x0);

// 0x7101099740
void Unk_1099740_call(const Unk_1099740* self, Unk_1099740_arg1* value) {
    Unk_239a418* v0 = self->field_0;
    value->field_0 = v0;
    if (v0 != nullptr) {
        static_cast<Unk_239a458*>(v0)->vf4();
    }
}

struct Unk_1099760_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1099760_arg1, field_0, 0x0);

struct Unk_1099760 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1099760, field_0, 0x0);

// 0x7101099760
void Unk_1099760_set(Unk_1099760* self, Unk_1099760_arg1* value) {
    u64 v0 = self->field_0;
    self->field_0 = 0;
    value->field_0 = v0;
}

struct Unk_1099810_arg1 {
    Unk_239a418* field_0;
};
PKMN_OFFSET_ASSERT(Unk_1099810_arg1, field_0, 0x0);

struct Unk_1099810 {
    Unk_239a418* field_0;
};
PKMN_OFFSET_ASSERT(Unk_1099810, field_0, 0x0);

// 0x7101099810
void Unk_1099810_call(const Unk_1099810* self, Unk_1099810_arg1* value) {
    Unk_239a418* v0 = self->field_0;
    value->field_0 = v0;
    if (v0 != nullptr) {
        static_cast<Unk_239a458*>(v0)->vf4();
    }
}

struct Unk_1099830_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1099830_arg1, field_0, 0x0);

struct Unk_1099830 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1099830, field_0, 0x0);

// 0x7101099830
void Unk_1099830_set(Unk_1099830* self, Unk_1099830_arg1* value) {
    u64 v0 = self->field_0;
    self->field_0 = 0;
    value->field_0 = v0;
}

struct Unk_109c010_arg1 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_109c010_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_109c010_arg1, field_8, 0x8);

struct Unk_109c010 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_109c010, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_109c010, field_8, 0x8);

// 0x710109c010
void Unk_109c010_set(Unk_109c010* self, Unk_109c010_arg1* value) {
    u64 v0 = self->field_0;
    self->field_0 = 0;
    value->field_0 = v0;
    u64 v1 = self->field_8;
    self->field_8 = 0;
    value->field_8 = v1;
}

struct Unk_109c0b0_arg1 {
    Unk_239a418* field_0;
};
PKMN_OFFSET_ASSERT(Unk_109c0b0_arg1, field_0, 0x0);

struct Unk_109c0b0 {
    Unk_239a418* field_0;
};
PKMN_OFFSET_ASSERT(Unk_109c0b0, field_0, 0x0);

// 0x710109c0b0
void Unk_109c0b0_call(const Unk_109c0b0* self, Unk_109c0b0_arg1* value) {
    Unk_239a418* v0 = self->field_0;
    value->field_0 = v0;
    if (v0 != nullptr) {
        static_cast<Unk_239a458*>(v0)->vf4();
    }
}

struct Unk_109c0d0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_109c0d0_arg1, field_0, 0x0);

struct Unk_109c0d0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_109c0d0, field_0, 0x0);

// 0x710109c0d0
void Unk_109c0d0_set(Unk_109c0d0* self, Unk_109c0d0_arg1* value) {
    u64 v0 = self->field_0;
    self->field_0 = 0;
    value->field_0 = v0;
}

struct Unk_109c180_arg1 {
    Unk_239a418* field_0;
};
PKMN_OFFSET_ASSERT(Unk_109c180_arg1, field_0, 0x0);

struct Unk_109c180 {
    Unk_239a418* field_0;
};
PKMN_OFFSET_ASSERT(Unk_109c180, field_0, 0x0);

// 0x710109c180
void Unk_109c180_call(const Unk_109c180* self, Unk_109c180_arg1* value) {
    Unk_239a418* v0 = self->field_0;
    value->field_0 = v0;
    if (v0 != nullptr) {
        static_cast<Unk_239a458*>(v0)->vf4();
    }
}

struct Unk_109c1a0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_109c1a0_arg1, field_0, 0x0);

struct Unk_109c1a0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_109c1a0, field_0, 0x0);

// 0x710109c1a0
void Unk_109c1a0_set(Unk_109c1a0* self, Unk_109c1a0_arg1* value) {
    u64 v0 = self->field_0;
    self->field_0 = 0;
    value->field_0 = v0;
}

struct Unk_109d770_arg1 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_109d770_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_109d770_arg1, field_8, 0x8);

struct Unk_109d770 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_109d770, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_109d770, field_8, 0x8);

// 0x710109d770
void Unk_109d770_set(Unk_109d770* self, Unk_109d770_arg1* value) {
    u64 v0 = self->field_0;
    self->field_0 = 0;
    value->field_0 = v0;
    u64 v1 = self->field_8;
    self->field_8 = 0;
    value->field_8 = v1;
}

struct Unk_109d7e0_arg1 {
    Unk_239a418* field_0;
};
PKMN_OFFSET_ASSERT(Unk_109d7e0_arg1, field_0, 0x0);

struct Unk_109d7e0 {
    Unk_239a418* field_0;
};
PKMN_OFFSET_ASSERT(Unk_109d7e0, field_0, 0x0);

// 0x710109d7e0
void Unk_109d7e0_call(const Unk_109d7e0* self, Unk_109d7e0_arg1* value) {
    Unk_239a418* v0 = self->field_0;
    value->field_0 = v0;
    if (v0 != nullptr) {
        static_cast<Unk_239a458*>(v0)->vf4();
    }
}

struct Unk_109d800_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_109d800_arg1, field_0, 0x0);

struct Unk_109d800 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_109d800, field_0, 0x0);

// 0x710109d800
void Unk_109d800_set(Unk_109d800* self, Unk_109d800_arg1* value) {
    u64 v0 = self->field_0;
    self->field_0 = 0;
    value->field_0 = v0;
}

struct Unk_109d8b0_arg1 {
    Unk_239a418* field_0;
};
PKMN_OFFSET_ASSERT(Unk_109d8b0_arg1, field_0, 0x0);

struct Unk_109d8b0 {
    Unk_239a418* field_0;
};
PKMN_OFFSET_ASSERT(Unk_109d8b0, field_0, 0x0);

// 0x710109d8b0
void Unk_109d8b0_call(const Unk_109d8b0* self, Unk_109d8b0_arg1* value) {
    Unk_239a418* v0 = self->field_0;
    value->field_0 = v0;
    if (v0 != nullptr) {
        static_cast<Unk_239a458*>(v0)->vf4();
    }
}

struct Unk_109d8d0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_109d8d0_arg1, field_0, 0x0);

struct Unk_109d8d0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_109d8d0, field_0, 0x0);

// 0x710109d8d0
void Unk_109d8d0_set(Unk_109d8d0* self, Unk_109d8d0_arg1* value) {
    u64 v0 = self->field_0;
    self->field_0 = 0;
    value->field_0 = v0;
}
