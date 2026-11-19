// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

#include "gflib3/Unk_239a418.h"

struct Unk_10e7aa0_arg1 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_10e7aa0_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_10e7aa0_arg1, field_8, 0x8);

struct Unk_10e7aa0 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_10e7aa0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_10e7aa0, field_8, 0x8);

// 0x71010e7aa0
void Unk_10e7aa0_set(Unk_10e7aa0* self, Unk_10e7aa0_arg1* value) {
    u64 v0 = self->field_0;
    self->field_0 = 0;
    value->field_0 = v0;
    u64 v1 = self->field_8;
    self->field_8 = 0;
    value->field_8 = v1;
}

struct Unk_10e7b00 {
    Unk_239a418* field_0;
};
PKMN_OFFSET_ASSERT(Unk_10e7b00, field_0, 0x0);

// 0x71010e7b00
void Unk_10e7b00_call(Unk_10e7b00* self) {
    if (self->field_0 != nullptr) {
        static_cast<Unk_239a458*>(self->field_0)->vf5();
        self->field_0 = nullptr;
    }
}

struct Unk_10e7b40_arg1 {
    Unk_239a418* field_0;
};
PKMN_OFFSET_ASSERT(Unk_10e7b40_arg1, field_0, 0x0);

struct Unk_10e7b40 {
    Unk_239a418* field_0;
};
PKMN_OFFSET_ASSERT(Unk_10e7b40, field_0, 0x0);

// 0x71010e7b40
void Unk_10e7b40_call(const Unk_10e7b40* self, Unk_10e7b40_arg1* value) {
    Unk_239a418* v0 = self->field_0;
    value->field_0 = v0;
    if (v0 != nullptr) {
        static_cast<Unk_239a458*>(v0)->vf4();
    }
}

struct Unk_10e7b60_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_10e7b60_arg1, field_0, 0x0);

struct Unk_10e7b60 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_10e7b60, field_0, 0x0);

// 0x71010e7b60
void Unk_10e7b60_set(Unk_10e7b60* self, Unk_10e7b60_arg1* value) {
    u64 v0 = self->field_0;
    self->field_0 = 0;
    value->field_0 = v0;
}

struct Unk_10e7bd0 {
    Unk_239a418* field_0;
};
PKMN_OFFSET_ASSERT(Unk_10e7bd0, field_0, 0x0);

// 0x71010e7bd0
void Unk_10e7bd0_call(Unk_10e7bd0* self) {
    if (self->field_0 != nullptr) {
        static_cast<Unk_239a458*>(self->field_0)->vf5();
        self->field_0 = nullptr;
    }
}

struct Unk_10e7c10_arg1 {
    Unk_239a418* field_0;
};
PKMN_OFFSET_ASSERT(Unk_10e7c10_arg1, field_0, 0x0);

struct Unk_10e7c10 {
    Unk_239a418* field_0;
};
PKMN_OFFSET_ASSERT(Unk_10e7c10, field_0, 0x0);

// 0x71010e7c10
void Unk_10e7c10_call(const Unk_10e7c10* self, Unk_10e7c10_arg1* value) {
    Unk_239a418* v0 = self->field_0;
    value->field_0 = v0;
    if (v0 != nullptr) {
        static_cast<Unk_239a458*>(v0)->vf4();
    }
}

struct Unk_10e7c30_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_10e7c30_arg1, field_0, 0x0);

struct Unk_10e7c30 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_10e7c30, field_0, 0x0);

// 0x71010e7c30
void Unk_10e7c30_set(Unk_10e7c30* self, Unk_10e7c30_arg1* value) {
    u64 v0 = self->field_0;
    self->field_0 = 0;
    value->field_0 = v0;
}

struct Unk_10e9200_arg1 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_10e9200_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_10e9200_arg1, field_8, 0x8);

struct Unk_10e9200 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_10e9200, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_10e9200, field_8, 0x8);

// 0x71010e9200
void Unk_10e9200_set(Unk_10e9200* self, Unk_10e9200_arg1* value) {
    u64 v0 = self->field_0;
    self->field_0 = 0;
    value->field_0 = v0;
    u64 v1 = self->field_8;
    self->field_8 = 0;
    value->field_8 = v1;
}

struct Unk_10e9260 {
    Unk_239a418* field_0;
};
PKMN_OFFSET_ASSERT(Unk_10e9260, field_0, 0x0);

// 0x71010e9260
void Unk_10e9260_call(Unk_10e9260* self) {
    if (self->field_0 != nullptr) {
        static_cast<Unk_239a458*>(self->field_0)->vf5();
        self->field_0 = nullptr;
    }
}

struct Unk_10e92a0_arg1 {
    Unk_239a418* field_0;
};
PKMN_OFFSET_ASSERT(Unk_10e92a0_arg1, field_0, 0x0);

struct Unk_10e92a0 {
    Unk_239a418* field_0;
};
PKMN_OFFSET_ASSERT(Unk_10e92a0, field_0, 0x0);

// 0x71010e92a0
void Unk_10e92a0_call(const Unk_10e92a0* self, Unk_10e92a0_arg1* value) {
    Unk_239a418* v0 = self->field_0;
    value->field_0 = v0;
    if (v0 != nullptr) {
        static_cast<Unk_239a458*>(v0)->vf4();
    }
}

struct Unk_10e92c0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_10e92c0_arg1, field_0, 0x0);

struct Unk_10e92c0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_10e92c0, field_0, 0x0);

// 0x71010e92c0
void Unk_10e92c0_set(Unk_10e92c0* self, Unk_10e92c0_arg1* value) {
    u64 v0 = self->field_0;
    self->field_0 = 0;
    value->field_0 = v0;
}

struct Unk_10e9330 {
    Unk_239a418* field_0;
};
PKMN_OFFSET_ASSERT(Unk_10e9330, field_0, 0x0);

// 0x71010e9330
void Unk_10e9330_call(Unk_10e9330* self) {
    if (self->field_0 != nullptr) {
        static_cast<Unk_239a458*>(self->field_0)->vf5();
        self->field_0 = nullptr;
    }
}

struct Unk_10e9370_arg1 {
    Unk_239a418* field_0;
};
PKMN_OFFSET_ASSERT(Unk_10e9370_arg1, field_0, 0x0);

struct Unk_10e9370 {
    Unk_239a418* field_0;
};
PKMN_OFFSET_ASSERT(Unk_10e9370, field_0, 0x0);

// 0x71010e9370
void Unk_10e9370_call(const Unk_10e9370* self, Unk_10e9370_arg1* value) {
    Unk_239a418* v0 = self->field_0;
    value->field_0 = v0;
    if (v0 != nullptr) {
        static_cast<Unk_239a458*>(v0)->vf4();
    }
}

struct Unk_10e9390_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_10e9390_arg1, field_0, 0x0);

struct Unk_10e9390 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_10e9390, field_0, 0x0);

// 0x71010e9390
void Unk_10e9390_set(Unk_10e9390* self, Unk_10e9390_arg1* value) {
    u64 v0 = self->field_0;
    self->field_0 = 0;
    value->field_0 = v0;
}

struct Unk_10e9e50 {
    Unk_239a418* field_0;
};
PKMN_OFFSET_ASSERT(Unk_10e9e50, field_0, 0x0);

// 0x71010e9e50
void Unk_10e9e50_call(Unk_10e9e50* self) {
    if (self->field_0 != nullptr) {
        static_cast<Unk_239a458*>(self->field_0)->vf5();
        self->field_0 = nullptr;
    }
}

struct Unk_10e9e90_arg1 {
    Unk_239a418* field_0;
};
PKMN_OFFSET_ASSERT(Unk_10e9e90_arg1, field_0, 0x0);

struct Unk_10e9e90 {
    Unk_239a418* field_0;
};
PKMN_OFFSET_ASSERT(Unk_10e9e90, field_0, 0x0);

// 0x71010e9e90
void Unk_10e9e90_call(const Unk_10e9e90* self, Unk_10e9e90_arg1* value) {
    Unk_239a418* v0 = self->field_0;
    value->field_0 = v0;
    if (v0 != nullptr) {
        static_cast<Unk_239a458*>(v0)->vf4();
    }
}

struct Unk_10e9eb0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_10e9eb0_arg1, field_0, 0x0);

struct Unk_10e9eb0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_10e9eb0, field_0, 0x0);

// 0x71010e9eb0
void Unk_10e9eb0_set(Unk_10e9eb0* self, Unk_10e9eb0_arg1* value) {
    u64 v0 = self->field_0;
    self->field_0 = 0;
    value->field_0 = v0;
}

struct Unk_10e9f00 {
    Unk_239a418* field_0;
};
PKMN_OFFSET_ASSERT(Unk_10e9f00, field_0, 0x0);

// 0x71010e9f00
void Unk_10e9f00_call(Unk_10e9f00* self) {
    if (self->field_0 != nullptr) {
        static_cast<Unk_239a458*>(self->field_0)->vf5();
        self->field_0 = nullptr;
    }
}

struct Unk_10e9f40_arg1 {
    Unk_239a418* field_0;
};
PKMN_OFFSET_ASSERT(Unk_10e9f40_arg1, field_0, 0x0);

struct Unk_10e9f40 {
    Unk_239a418* field_0;
};
PKMN_OFFSET_ASSERT(Unk_10e9f40, field_0, 0x0);

// 0x71010e9f40
void Unk_10e9f40_call(const Unk_10e9f40* self, Unk_10e9f40_arg1* value) {
    Unk_239a418* v0 = self->field_0;
    value->field_0 = v0;
    if (v0 != nullptr) {
        static_cast<Unk_239a458*>(v0)->vf4();
    }
}

struct Unk_10e9f60_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_10e9f60_arg1, field_0, 0x0);

struct Unk_10e9f60 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_10e9f60, field_0, 0x0);

// 0x71010e9f60
void Unk_10e9f60_set(Unk_10e9f60* self, Unk_10e9f60_arg1* value) {
    u64 v0 = self->field_0;
    self->field_0 = 0;
    value->field_0 = v0;
}

struct Unk_10e9fd0 {
    Unk_239a418* field_0;
};
PKMN_OFFSET_ASSERT(Unk_10e9fd0, field_0, 0x0);

// 0x71010e9fd0
void Unk_10e9fd0_call(Unk_10e9fd0* self) {
    if (self->field_0 != nullptr) {
        static_cast<Unk_239a458*>(self->field_0)->vf5();
        self->field_0 = nullptr;
    }
}

struct Unk_10ea010_arg1 {
    Unk_239a418* field_0;
};
PKMN_OFFSET_ASSERT(Unk_10ea010_arg1, field_0, 0x0);

struct Unk_10ea010 {
    Unk_239a418* field_0;
};
PKMN_OFFSET_ASSERT(Unk_10ea010, field_0, 0x0);

// 0x71010ea010
void Unk_10ea010_call(const Unk_10ea010* self, Unk_10ea010_arg1* value) {
    Unk_239a418* v0 = self->field_0;
    value->field_0 = v0;
    if (v0 != nullptr) {
        static_cast<Unk_239a458*>(v0)->vf4();
    }
}

struct Unk_10ea030_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_10ea030_arg1, field_0, 0x0);

struct Unk_10ea030 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_10ea030, field_0, 0x0);

// 0x71010ea030
void Unk_10ea030_set(Unk_10ea030* self, Unk_10ea030_arg1* value) {
    u64 v0 = self->field_0;
    self->field_0 = 0;
    value->field_0 = v0;
}
