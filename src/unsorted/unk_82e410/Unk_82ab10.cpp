// Scope: common
// More of Unk_23acc98's helpers (see Handler.h): they pass a Pokemon, or its
// ID, to the battle's modules that the object keeps (field_8.field_0[0], the
// main module, and field_0[1], whose getters give the others). Placeholder
// names: rename once the class is known.
#include <types.h>

#include "unsorted/ctor/Unk_23acc98.h"

struct Unk_7c56e0;
struct Unk_7fe1d0;
struct Unk_7fe250;
struct Unk_7ecc90_Con;
struct Unk_7ee6b0;
struct Unk_7fc430_Party;
bool Unk_7c56e0_check(const Unk_7c56e0* self, u32 value);
Unk_7ecc90_Con* Unk_7fe1d0_getField8(const Unk_7fe1d0* self);
void* Unk_7fe250_getFielda8(const Unk_7fe250* self);
Unk_7ee6b0* Unk_7ecc90(Unk_7ecc90_Con* self, u8 pokeId);
Unk_7fc430_Party* Unk_7ed1a0(Unk_7ecc90_Con* self, u32 client);
const Unk_7ee6b0* Unk_7ed6f0(const Unk_7ecc90_Con* self, u8 client, u8 index);
u8 Unk_7ee6b0_getField7d(const Unk_7ee6b0* self);
u8 Unk_803600(void* self, u8 pokeId);
// Placeholder names whose types came from callers that pass a u32 through.
void Unk_7cc000(void* self, u32 pokeId);
void Unk_7cbf80(void* self, u32 pokeId, u32 otherId);

static inline void* Unk_82ab10_Field0(const Unk_23acc98* self) {
    return reinterpret_cast<void*>(self->field_8.field_0[0]);
}

static inline Unk_7ecc90_Con* Unk_82ab10_Con(const void* self) {
    const Unk_23acc98* object = static_cast<const Unk_23acc98*>(self);
    return Unk_7fe1d0_getField8(reinterpret_cast<const Unk_7fe1d0*>(object->field_8.field_0[1]));
}

static inline void* Unk_82ab10_Fielda8(const void* self) {
    const Unk_23acc98* object = static_cast<const Unk_23acc98*>(self);
    return Unk_7fe250_getFielda8(reinterpret_cast<const Unk_7fe250*>(object->field_8.field_0[1]));
}

// 0x710082ab10
u64 Unk_82ab10(void* self, u8 index) {
    return reinterpret_cast<u64>(Unk_7ecc90(Unk_82ab10_Con(self), index));
}

// 0x710082ab40
const Unk_7ee6b0* Unk_82ab40(const Unk_23acc98* self, u8 client, u8 index) {
    return Unk_7ed6f0(Unk_82ab10_Con(self), client, index);
}

// 0x710082ab70
u8 Unk_82ab70(const Unk_23acc98* self, const Unk_7ee6b0* poke) {
    u8 pokeId = Unk_7ee6b0_getField7d(poke);
    return Unk_803600(Unk_82ab10_Fielda8(self), pokeId);
}

// 0x710082abb0
u8 Unk_82abb0(void* self, u8 index) {
    return Unk_803600(Unk_82ab10_Fielda8(self), index);
}

// NON_MATCHING: Unk_7cc000/Unk_7cbf80 take u8 IDs (they mask them themselves),
// but their placeholder names say u32 (_Z10Unk_7cc000Pvj, _Z10Unk_7cbf80Pvjj), so
// the u8 from Unk_7ee6b0_getField7d is masked here: an extra `and`.
// 0x710082abe0
void Unk_82abe0(const Unk_23acc98* self, const Unk_7ee6b0* poke) {
    u8 pokeId = Unk_7ee6b0_getField7d(poke);
    Unk_7cc000(Unk_82ab10_Field0(self), pokeId);
}

// 0x710082ac20
Unk_7fc430_Party* Unk_82ac20(const Unk_23acc98* self, u8 client) {
    return Unk_7ed1a0(Unk_82ab10_Con(self), client);
}

// 0x710082aca0
bool Unk_82aca0(const Unk_23acc98* self, u32 value) {
    return Unk_7c56e0_check(reinterpret_cast<const Unk_7c56e0*>(Unk_82ab10_Field0(self)), value);
}

// NON_MATCHING: Unk_7cbf80 takes u8 IDs (it masks them itself), but its
// placeholder name says u32 (_Z10Unk_7cbf80Pvjj), so each u8 from Unk_7ee6b0_getField7d is masked
// here: an extra `and`. 0x710082acb0
void Unk_82acb0(const Unk_23acc98* self, const Unk_7ee6b0* poke, const Unk_7ee6b0* other) {
    u8 pokeId = Unk_7ee6b0_getField7d(poke);
    u8 otherId = Unk_7ee6b0_getField7d(other);
    Unk_7cbf80(Unk_82ab10_Field0(self), pokeId, otherId);
}
