// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_10307f0;
struct Unk_102cea0 {
    u8 _0[0x120];
    Unk_10307f0* field_120;
};
PKMN_OFFSET_ASSERT(Unk_102cea0, field_120, 0x120);

void Unk_10307f0_call(const Unk_10307f0*);

// 0x710102cea0
void Unk_102cea0_call(const Unk_102cea0* self) {
    if (self->field_120 != nullptr) {
        Unk_10307f0_call(self->field_120);
    }
}

struct Unk_102d9a0 {
    u8 _0[0x120];
    void* field_120;
};
PKMN_OFFSET_ASSERT(Unk_102d9a0, field_120, 0x120);

void Unk_10314c0_call(void*);

// 0x710102d9a0
void Unk_102d9a0_call(const Unk_102d9a0* self) {
    Unk_10314c0_call(self->field_120);
}

struct Unk_102daa0 {
    u8 _0[0x120];
    void* field_120;
};
PKMN_OFFSET_ASSERT(Unk_102daa0, field_120, 0x120);

void Unk_10314a0_call(void*);

// 0x710102daa0
void Unk_102daa0_call(const Unk_102daa0* self) {
    Unk_10314a0_call(self->field_120);
}

struct Unk_102dab0 {
    u8 _0[0x120];
    void* field_120;
};
PKMN_OFFSET_ASSERT(Unk_102dab0, field_120, 0x120);

void Unk_10314b0_call(void*);

// 0x710102dab0
void Unk_102dab0_call(const Unk_102dab0* self) {
    Unk_10314b0_call(self->field_120);
}

struct Unk_102dac0 {
    u8 _0[0x120];
    void* field_120;
};
PKMN_OFFSET_ASSERT(Unk_102dac0, field_120, 0x120);

void Unk_10314d0_call(void*);

// 0x710102dac0
void Unk_102dac0_call(const Unk_102dac0* self) {
    Unk_10314d0_call(self->field_120);
}

struct Unk_102dad0 {
    u8 _0[0x120];
    void* field_120;
};
PKMN_OFFSET_ASSERT(Unk_102dad0, field_120, 0x120);

void Unk_10314e0_call(void*);

// 0x710102dad0
void Unk_102dad0_call(const Unk_102dad0* self) {
    Unk_10314e0_call(self->field_120);
}

// 0x710102f870
void Unk_102f870_update() {}

struct Unk_102f880_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_102f880_arg1, field_0, 0x0);

struct Unk_102f880 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_102f880, field_0, 0x0);

// 0x710102f880
void Unk_102f880_set(const Unk_102f880* self, Unk_102f880_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_102f890_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_102f890_arg1, field_0, 0x0);

struct Unk_102f890 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_102f890, field_0, 0x0);

// 0x710102f890
void Unk_102f890_set(const Unk_102f890* self, Unk_102f890_arg1* value) {
    value->field_0 = self->field_0;
}

// 0x710102fac0
void Unk_102fac0_update() {}

struct Unk_102fad0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_102fad0_arg1, field_0, 0x0);

struct Unk_102fad0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_102fad0, field_0, 0x0);

// 0x710102fad0
void Unk_102fad0_set(const Unk_102fad0* self, Unk_102fad0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_102fae0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_102fae0_arg1, field_0, 0x0);

struct Unk_102fae0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_102fae0, field_0, 0x0);

// 0x710102fae0
void Unk_102fae0_set(const Unk_102fae0* self, Unk_102fae0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_102faf0_0 {
    u8 _0[0x140];
    u64 field_140;
};
PKMN_OFFSET_ASSERT(Unk_102faf0_0, field_140, 0x140);

struct Unk_102faf0 {
    Unk_102faf0_0* field_0;
};
PKMN_OFFSET_ASSERT(Unk_102faf0, field_0, 0x0);

// 0x710102faf0
void Unk_102faf0_set(const Unk_102faf0* self) {
    self->field_0->field_140 = 0x100000003;
}

// 0x710102fb10
void Unk_102fb10_update() {}

struct Unk_102fb20_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_102fb20_arg1, field_0, 0x0);

struct Unk_102fb20 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_102fb20, field_0, 0x0);

// 0x710102fb20
void Unk_102fb20_set(const Unk_102fb20* self, Unk_102fb20_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_102fb30_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_102fb30_arg1, field_0, 0x0);

struct Unk_102fb30 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_102fb30, field_0, 0x0);

// 0x710102fb30
void Unk_102fb30_set(const Unk_102fb30* self, Unk_102fb30_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_102fd10_0 {
    u8 _0[0x140];
    u32 field_140;
};
PKMN_OFFSET_ASSERT(Unk_102fd10_0, field_140, 0x140);

struct Unk_102fd10 {
    Unk_102fd10_0* field_0;
};
PKMN_OFFSET_ASSERT(Unk_102fd10, field_0, 0x0);

// 0x710102fd10
void Unk_102fd10_set(const Unk_102fd10* self) {
    self->field_0->field_140 = 8;
}

// 0x710102fd20
void Unk_102fd20_update() {}

struct Unk_102fd30_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_102fd30_arg1, field_0, 0x0);

struct Unk_102fd30 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_102fd30, field_0, 0x0);

// 0x710102fd30
void Unk_102fd30_set(const Unk_102fd30* self, Unk_102fd30_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_102fd40_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_102fd40_arg1, field_0, 0x0);

struct Unk_102fd40 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_102fd40, field_0, 0x0);

// 0x710102fd40
void Unk_102fd40_set(const Unk_102fd40* self, Unk_102fd40_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_102fd50_0 {
    u8 _0[0x140];
    u64 field_140;
};
PKMN_OFFSET_ASSERT(Unk_102fd50_0, field_140, 0x140);

struct Unk_102fd50 {
    Unk_102fd50_0* field_0;
};
PKMN_OFFSET_ASSERT(Unk_102fd50, field_0, 0x0);

// 0x710102fd50
void Unk_102fd50_set(const Unk_102fd50* self) {
    self->field_0->field_140 = 0x200000008;
}

// 0x710102fd70
void Unk_102fd70_update() {}

struct Unk_102fd80_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_102fd80_arg1, field_0, 0x0);

struct Unk_102fd80 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_102fd80, field_0, 0x0);

// 0x710102fd80
void Unk_102fd80_set(const Unk_102fd80* self, Unk_102fd80_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_102fd90_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_102fd90_arg1, field_0, 0x0);

struct Unk_102fd90 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_102fd90, field_0, 0x0);

// 0x710102fd90
void Unk_102fd90_set(const Unk_102fd90* self, Unk_102fd90_arg1* value) {
    value->field_0 = self->field_0;
}
