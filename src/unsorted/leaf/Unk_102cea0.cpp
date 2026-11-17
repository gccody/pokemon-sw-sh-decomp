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
