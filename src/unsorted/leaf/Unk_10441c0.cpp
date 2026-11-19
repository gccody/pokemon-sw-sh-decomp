// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

#include "gflib3/Unk_239a418.h"

struct Unk_10441c0 {
    u8 _0[0x8];
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_10441c0, field_8, 0x8);

// 0x71010441c0
void Unk_10441c0_call(Unk_10441c0* self) {
    if (self->field_8 != nullptr) {
        static_cast<Unk_239a458*>(self->field_8)->vf5();
        self->field_8 = nullptr;
    }
}

struct Unk_1044200_arg1 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_1044200_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_1044200_arg1, field_8, 0x8);

struct Unk_1044200 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_1044200, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_1044200, field_8, 0x8);

// 0x7101044200
void Unk_1044200_call(const Unk_1044200* self, Unk_1044200_arg1* value) {
    value->field_0 = self->field_0;
    Unk_239a418* v0 = self->field_8;
    value->field_8 = v0;
    if (v0 != nullptr) {
        static_cast<Unk_239a458*>(v0)->vf4();
    }
}

struct Unk_1044230_arg1 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_1044230_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_1044230_arg1, field_8, 0x8);

struct Unk_1044230 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_1044230, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_1044230, field_8, 0x8);

// 0x7101044230
void Unk_1044230_call(const Unk_1044230* self, Unk_1044230_arg1* value) {
    value->field_0 = self->field_0;
    Unk_239a418* v0 = self->field_8;
    value->field_8 = v0;
    if (v0 != nullptr) {
        static_cast<Unk_239a458*>(v0)->vf4();
    }
}

struct Unk_1044bc0 {
    u8 _0[0x8];
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_1044bc0, field_8, 0x8);

// 0x7101044bc0
void Unk_1044bc0_call(Unk_1044bc0* self) {
    if (self->field_8 != nullptr) {
        static_cast<Unk_239a458*>(self->field_8)->vf5();
        self->field_8 = nullptr;
    }
}

struct Unk_1044c00_arg1 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_1044c00_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_1044c00_arg1, field_8, 0x8);

struct Unk_1044c00 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_1044c00, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_1044c00, field_8, 0x8);

// 0x7101044c00
void Unk_1044c00_call(const Unk_1044c00* self, Unk_1044c00_arg1* value) {
    value->field_0 = self->field_0;
    Unk_239a418* v0 = self->field_8;
    value->field_8 = v0;
    if (v0 != nullptr) {
        static_cast<Unk_239a458*>(v0)->vf4();
    }
}

struct Unk_1044c30_arg1 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_1044c30_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_1044c30_arg1, field_8, 0x8);

struct Unk_1044c30 {
    u64 field_0;
    Unk_239a418* field_8;
};
PKMN_OFFSET_ASSERT(Unk_1044c30, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_1044c30, field_8, 0x8);

// 0x7101044c30
void Unk_1044c30_call(const Unk_1044c30* self, Unk_1044c30_arg1* value) {
    value->field_0 = self->field_0;
    Unk_239a418* v0 = self->field_8;
    value->field_8 = v0;
    if (v0 != nullptr) {
        static_cast<Unk_239a458*>(v0)->vf4();
    }
}

struct Unk_1044d60 {
    u8 _0[0x60];
    u32 field_60;
};
PKMN_OFFSET_ASSERT(Unk_1044d60, field_60, 0x60);

// 0x7101044d60
bool Unk_1044d60_check(const Unk_1044d60* self) {
    return self->field_60 == 3;
}

struct Unk_1044d70 {
    u8 _0[0x60];
    u32 field_60;
};
PKMN_OFFSET_ASSERT(Unk_1044d70, field_60, 0x60);

// 0x7101044d70
void Unk_1044d70_set(Unk_1044d70* self) {
    self->field_60 = 4;
}

struct Unk_1044d80 {
    u8 _0[0x60];
    u32 field_60;
};
PKMN_OFFSET_ASSERT(Unk_1044d80, field_60, 0x60);

// 0x7101044d80
bool Unk_1044d80_check(const Unk_1044d80* self) {
    return self->field_60 == 5;
}

struct Unk_1044d90 {
    u8 _0[0x64];
    u32 field_64;
};
PKMN_OFFSET_ASSERT(Unk_1044d90, field_64, 0x64);

// 0x7101044d90
void Unk_1044d90_update(Unk_1044d90* self) {
    if (self->field_64 != 0) {
        return;
    }
    self->field_64 = 1;
}

struct Unk_1044e60 {
    u8 _0[0x64];
    u32 field_64;
};
PKMN_OFFSET_ASSERT(Unk_1044e60, field_64, 0x64);

// 0x7101044e60
bool Unk_1044e60_check(const Unk_1044e60* self) {
    return self->field_64 == 2;
}

struct Unk_10457c0 {
    u8 _0[0x68];
    u32 field_68;
};
PKMN_OFFSET_ASSERT(Unk_10457c0, field_68, 0x68);

// 0x71010457c0
u32 Unk_10457c0_get(const Unk_10457c0* self) {
    return (self->field_68 == 0) | (self->field_68 == 3);
}

struct Unk_10457e0 {
    u8 _0[0x6c];
    u32 field_6c;
};
PKMN_OFFSET_ASSERT(Unk_10457e0, field_6c, 0x6c);

// 0x71010457e0
u32 Unk_10457e0_getField6c(const Unk_10457e0* self) {
    return self->field_6c;
}

struct Unk_10459a0 {
    u8 _0[0x6c];
    u32 field_6c;
    u8 field_70;
};
PKMN_OFFSET_ASSERT(Unk_10459a0, field_6c, 0x6c);
PKMN_OFFSET_ASSERT(Unk_10459a0, field_70, 0x70);

// 0x71010459a0
void Unk_10459a0_update(Unk_10459a0* self) {
    if (self->field_6c != 0) {
        return;
    }
    self->field_70 = 1;
}

struct Unk_10459c0 {
    u8 _0[0x68];
    u32 field_68;
    u32 field_6c;
    u8 field_70;
};
PKMN_OFFSET_ASSERT(Unk_10459c0, field_68, 0x68);
PKMN_OFFSET_ASSERT(Unk_10459c0, field_6c, 0x6c);
PKMN_OFFSET_ASSERT(Unk_10459c0, field_70, 0x70);

// 0x71010459c0
u32 Unk_10459c0_get(Unk_10459c0* self) {
    if (self->field_68 == 6) {
        return 0;
    }
    if (self->field_6c != 0) {
        return 1;
    }
    self->field_68 = 7;
    self->field_70 = 0;
    return 1;
}
