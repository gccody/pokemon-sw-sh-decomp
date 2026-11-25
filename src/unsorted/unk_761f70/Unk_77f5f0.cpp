// Scope: common
// A Pokémon's encrypted data: accessors that decrypt it (and flag a checksum
// mismatch), read or write a field of one of its four shuffled 0x50-byte
// blocks (or of a stand-in block once the data is flagged) and encrypt it
// again; the reset of the stand-in blocks; the level reached with an amount
// of experience; and the first stat and HP formulas. Placeholder names:
// rename once the owning classes are known.
#include "unsorted/unk_761f70/Unk_77fe40.h"

// Decrypts, encrypts and checksums data with a key.
void Unk_770b80(void* data, u32 size, u32 key);
u16 Unk_770a50(const void* data, u32 size);
void Unk_770af0(void* data, u32 size, u32 key);

// Selects the growth rate of a species' form, then reads the experience a
// level needs (src/battle/battle_engine/Unk_7ee6b0.h).
void Unk_76bd60(u16 species, u8 form);
u32 Unk_76bdf0(u32 level);

struct Unk_77f5f0_Global {
    u8 _0[0x278];
    u8 field_278;
};

Unk_77f5f0_Global* Unk_76a5c0_get();

// Block positions, by the key's shuffle value (bits 13-17).
extern const u8 Unk_1f0c2e0[32][4] __attribute__((visibility("hidden")));

struct Unk_77f5f0_Header {
    u16 field_0;
    u16 field_2;
    u8 _4[0xc];
};
static_assert(sizeof(Unk_77f5f0_Header) == 0x10, "Unk_77f5f0_Header");

struct Unk_77f5f0_Block {
    u16 field_0;
    u8 _2[0x2c];
    u8 field_2e;
    u8 _2f[0xb];
    u8 field_3a;
    u8 _3b;
    u32 field_3c;
    u8 field_40;
    u8 _41[0xf];
};
static_assert(sizeof(Unk_77f5f0_Block) == 0x50, "Unk_77f5f0_Block");
PKMN_OFFSET_ASSERT(Unk_77f5f0_Block, field_2e, 0x2e);
PKMN_OFFSET_ASSERT(Unk_77f5f0_Block, field_3a, 0x3a);
PKMN_OFFSET_ASSERT(Unk_77f5f0_Block, field_3c, 0x3c);
PKMN_OFFSET_ASSERT(Unk_77f5f0_Block, field_40, 0x40);

// The encrypted data.
struct Unk_77f5f0_Data {
    u32 key;
    u16 flags;  // bit 2: the checksum didn't match
    u16 checksum;
    Unk_77f5f0_Block blocks[4];
};
static_assert(sizeof(Unk_77f5f0_Data) == 0x148, "Unk_77f5f0_Data");

struct Unk_77f5f0_Self {
    u8 _0[8];
    void* field_8;  // 0x10 more bytes encrypted with the same key
    Unk_77f5f0_Data* field_10;
    bool field_18;  // encrypted
    bool field_19;  // keep decrypted
};
PKMN_OFFSET_ASSERT(Unk_77f5f0_Self, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_77f5f0_Self, field_18, 0x18);
PKMN_OFFSET_ASSERT(Unk_77f5f0_Self, field_19, 0x19);

// The stand-in blocks: read once the data is flagged.
extern Unk_77f5f0_Header Unk_2779ed8;
extern Unk_77f5f0_Block Unk_2779ee8;
extern Unk_77f5f0_Block Unk_2779f38;
extern Unk_77f5f0_Block Unk_2779f88;
extern Unk_77f5f0_Block Unk_2779fd8;
// The blocks written once the data is flagged.
extern Unk_77f5f0_Block Unk_277a0d8;
extern Unk_77f5f0_Block Unk_277a128;

namespace {

void Decrypt(Unk_77f5f0_Self* self) {
    if (!self->field_18) {
        return;
    }
    Unk_770b80(self->field_10->blocks, sizeof(self->field_10->blocks), self->field_10->key);
    if (self->field_8 != nullptr) {
        Unk_770b80(self->field_8, 0x10, self->field_10->key);
    }
    self->field_18 = false;
    if (self->field_10->checksum !=
        Unk_770a50(self->field_10->blocks, sizeof(self->field_10->blocks))) {
        self->field_10->flags |= 4;
    }
}

void Encrypt(Unk_77f5f0_Self* self) {
    if (self->field_18 || self->field_19) {
        return;
    }
    if (self->field_10 != nullptr) {
        self->field_10->checksum =
            Unk_770a50(self->field_10->blocks, sizeof(self->field_10->blocks));
        Unk_770af0(self->field_10->blocks, sizeof(self->field_10->blocks), self->field_10->key);
    }
    if (self->field_8 != nullptr && self->field_10 != nullptr) {
        Unk_770af0(self->field_8, 0x10, self->field_10->key);
    }
    self->field_18 = true;
}

// A block of the data, or the stand-in once the data is flagged.
Unk_77f5f0_Block* GetBlock(Unk_77f5f0_Data* data, u32 index, Unk_77f5f0_Block* standIn) {
    if (data->flags & 4) {
        return standIn;
    }
    return &data->blocks[Unk_1f0c2e0[(data->key >> 13) & 0x1f][index]];
}

}  // namespace

// 0x710077f5f0
void Unk_77f5f0(void* p, u32 value) {
    auto* self = static_cast<Unk_77f5f0_Self*>(p);
    Decrypt(self);
    GetBlock(self->field_10, 2, &Unk_277a0d8)->field_40 = value;
    Encrypt(self);
}

// 0x710077f740
void Unk_77f740(Unk_77f5f0_Self* self, u32 value) {
    Decrypt(self);
    GetBlock(self->field_10, 2, &Unk_277a0d8)->field_3c = value;
    Encrypt(self);
}

// 0x710077f890
u32 Unk_77f890(Unk_77f5f0_Self* self) {
    Decrypt(self);
    u32 value = GetBlock(self->field_10, 2, &Unk_2779f88)->field_3c;
    Encrypt(self);
    return value;
}

// 0x710077f9d0
void Unk_77f9d0(Unk_77f5f0_Self* self, u8 value) {
    Decrypt(self);
    GetBlock(self->field_10, 3, &Unk_277a128)->field_2e = value;
    Encrypt(self);
}

// 0x710077fb20
u8 Unk_77fb20(Unk_77f5f0_Self* self) {
    Decrypt(self);
    u8 value = GetBlock(self->field_10, 3, &Unk_2779fd8)->field_2e;
    Encrypt(self);
    return value;
}

// 0x710077fc60
void Unk_77fc60() {
    Unk_2779ed8 = {};
    Unk_2779ee8 = {};
    Unk_2779f38 = {};
    Unk_2779f88 = {};
    Unk_2779fd8 = {};
    Unk_2779ed8.field_2 = 1;
    Unk_2779ee8.field_0 = 0x37b;
    Unk_2779f88.field_3a = Unk_76a5c0_get()->field_278;
}

// 0x710077fd10
// NON_MATCHING: functions.csv names the callee _Z10Unk_76bdf0j, but it takes a
// u8 (the original keeps the counter 8-bit and passes it unextended): rename
// it _Z10Unk_76bdf0h.
u8 Unk_77fd10(u16 species, u8 form, u32 exp) {
    Unk_76bd60(species, form);
    u8 level;
    for (level = 1; level <= 100; level++) {
        if (Unk_76bdf0(level) > exp) {
            break;
        }
    }
    return level < 2 ? 1 : level - 1;
}

// 0x710077fd70
u16 Unk_77fd70(u32 species, u8 level, u16 base, u16 iv, u16 ev) {
    if (species == Unk_77fe40_SPECIES_SHEDINJA) {
        return 1;
    }
    return (base * 2 + iv + ev / 4) * level / 100 + level + 10;
}

// 0x710077fdc0
u16 Unk_77fdc0(u8 level, u16 base, u16 iv, u16 ev, u32 nature) {
    return Unk_77fe40_ApplyNature(Unk_77fe40_CalcStat(level, base, iv, ev), nature, 0);
}
