// Scope: common
// The Poke Job app's save data (src/unsorted/Unk_1373180.h): more accessors of
// its lists, jobs and counters.
#include "unsorted/Unk_1373180.h"

#include <algorithm>
#include <cstdio>
#include <cstring>

// 0x710076f7d0 (game/unk_761f70): hands an entry to `self`.
void Unk_76f7d0(void* self, void* entry);

// 0x71012a3c50: the current time.
u64 Unk_12a3c50();

// A xoroshiro128+ generator, as a URNG for libc++'s distributions.
class Unk_ead0f0_Random {
public:
    using result_type = u64;
    static constexpr u64 min() { return 0; }
    static constexpr u64 max() { return ~0ull; }

    Unk_ead0f0_Random() : field_0(0x0f4b17a579f18960), field_8(0x82a2b175229d6a5b), field_10(0) {}

    // 0x7100ead0f0
    void Unk_ead0f0(u64 seed);

    u64 operator()() {
        u64 s0 = field_0;
        u64 s1 = field_8;
        u64 result = s0 + s1;
        s1 ^= s0;
        field_0 = ((s0 << 24) | (s0 >> 40)) ^ s1 ^ (s1 << 16);
        field_8 = (s1 << 37) | (s1 >> 27);
        return result;
    }

    u64 field_0;
    u64 field_8;
    u64 field_10;  // the seed
};
PKMN_SIZE_ASSERT(Unk_ead0f0_Random, 0x18);

// The seed after `seed`: the first draw of a generator seeded with the FNV-1a
// hash of its decimal digits.
static inline u64 Unk_NextSeed(u64 seed) {
    Unk_ead0f0_Random random;
    char digits[0x20] = {};
    std::snprintf(digits, sizeof(digits), "%lu", seed);
    u64 hash = 0xcbf29ce484222645;
    for (const char* p = digits; *p != '\0'; p++)
        hash = (hash ^ static_cast<u8>(*p)) * 0x100000001b3;
    random.Unk_ead0f0(hash);
    return random();
}

// 0x7101373970
void Unk_2432938::Unk_1373970(s32 list, s32 index, void* const& object) {
    Unk_1393080_Entry* entry = &field_1fb0.field_0[list].field_1[index];
    std::memset(entry, 0, sizeof(*entry));
    Unk_76f7d0(object, entry);
}

// 0x71013739c0
s32 Unk_2432938::Unk_13739c0() {
    for (s32 i = 0; i < 32; i++) {
        if (field_1fb0.field_0[i].field_0 == 0)
            return i;
    }
    return 0;
}

// 0x7101373cb0
bool Unk_2432938::Unk_1373cb0() {
    for (s32 i = 0; i < 32; i++) {
        if (field_1fb0.field_0[i].field_0 == 0)
            return true;
    }
    return false;
}

// 0x7101373eb0
// NON_MATCHING: the copy of the 4/5 case's address goes on its own block
// (`mov x8, x21; b`) where the original puts it before the branch, which
// also swaps w8 and w9. The switch and the other if orders give the same or
// pick the other address as the induction pointer.
void Unk_2432938::Unk_1373eb0() {
    for (s32 i = 0; i < 167; i++) {
        u64 now = Unk_12a3c50();
        Unk_2432938_Job& job = field_60.field_0[i];
        if (job.field_0 == 2)
            job.field_8 = now;
        else if (job.field_0 == 4 || job.field_0 == 5)
            job.field_10 = now;
    }
}

// 0x7101373f30
void Unk_2432938::Unk_1373f30(s32 count) {
    field_52bd8 += count;
}

// 0x7101373f50
void Unk_2432938::Unk_1373f50() {
    field_52bd8 = 0;
}

// 0x7101373f60
u32 Unk_2432938::Unk_1373f60() {
    return field_52bd8;
}

// 0x7101373f70
void Unk_2432938::Unk_1373f70(s32 count) {
    field_52bd0 += count;
}

// 0x7101373f90
void Unk_2432938::Unk_1373f90(s32 count) {
    field_52bd4 += count;
}

// 0x7101373fb0
u32 Unk_2432938::Unk_1373fb0() {
    return field_52bd4;
}

// 0x7101373fc0
void Unk_2432938::Unk_1373fc0(s32 job, bool value) {
    field_60.field_0[job].field_19 = value;
}

// 0x7101373fe0
u32 Unk_2432938::Unk_1373fe0(u32 max) {
    field_52be0 = Unk_NextSeed(field_52be0);
    Unk_ead0f0_Random random;
    random.Unk_ead0f0(field_52be0);
    return std::uniform_int_distribution<u32>(0, max)(random);
}
