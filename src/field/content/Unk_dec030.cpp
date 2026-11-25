// Scope: common
// HaxeSymbolPokemonObject's spawner functions: whether a position, the Pokemon's own
// or the player's is in one of its spawner's areas, a random position in one, the
// spawner's position and type, and the vanish flag of the gimmick spawner that has
// the Pokemon's id.
#include <arm_neon.h>
#include <stdlib.h>

#include <algorithm>
#include <vector>

#include <types.h>

#include "field/content/HaxeSymbolPokemonObject.h"
#include "field/content/HaxeVector3.h"
#include "field/content/Unk_debce0_Owner.h"
#include "gflib3/Unk_239a418.h"

// 0x71013ed240
template <class T>
bool Unk_61a530(Unk_239a498* object);

// 0x7100c8e1a0: a random position in the area of that index, `margin` in from its edge.
float32x4_t Unk_c8e1a0(const Unk_debce0_Areas& areas, int index, float margin);

// What GetXAreaRandomPos add to the Pokemon's margin, and the least margin they use.
extern const float Unk_1f24eb8;
extern const float Unk_1f24eb4;

// A field object: the manager's list holds them. Placeholder names.
class Unk_dec030_Object : public Unk_239a418 {
public:
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
    virtual void vf14();
    virtual void vf15();
    virtual void vf16();
    virtual bool vf17();  // gone: skipped when looking objects up

    // The object as a T, or null when it isn't one: through its +0x50 interface.
    template <class T>
    T* Unk_Cast() {
        Unk_239a498* object = this;
        const Unk_239a418_Type* type = object->vf_type();
        const Unk_239a418_Type* kind = T::Unk_GetType();
        for (; type != nullptr; type = type->field_0)
            if (type == kind)
                return static_cast<T*>(object);
        return nullptr;
    }
};

struct Unk_dec030_Manager {
    u8 _0[0xb0];
    std::vector<Unk_dec030_Object*> field_b0;
};
static_assert(__builtin_offsetof(Unk_dec030_Manager, field_b0) == 0xb0, "field_b0");

extern Unk_dec030_Manager* Unk_27d6158;

// A position kept as a whole: what the area tests are given is a copy of it, made
// through memory (two 64-bit words), not a vector load.
struct Unk_dec030_Vector {
    float32x4_t field_0;
};
PKMN_SIZE_ASSERT(Unk_dec030_Vector, 0x10);

// The player's object (type 0x71027f0000).
class Unk_23ea168 : public Unk_dec030_Object {
public:
    u8 _60[0xb0 - 0x60];
    Unk_dec030_Vector field_b0;  // the position
};
static_assert(__builtin_offsetof(Unk_23ea168, field_b0) == 0xb0, "field_b0");

// A spawner (vtable 0x71023e7370): the ids of the Pokemon it spawns, a hash each
// (Unk_d07d60_set resets them), at most one.
class Unk_23e7370 : public Unk_dec030_Object {
public:
    // 0x7100cdc200 (out of line: the copy for its static, 0x71027daa08)
    static const Unk_239a418_Type* Unk_GetType();

    // 0x7100d07d90
    void Unk_d07d90(bool flag);
    // 0x7100d07690
    bool Unk_d07690();

    const s64& Unk_Id(int index) const {
        if (index >= 1)
            abort();
        return field_c48[index];
    }

    bool Unk_HasId(s64 id) const {
        for (int i = 0; i < field_c50; i++)
            if (Unk_Id(i) == id)
                return true;
        return false;
    }

    u8 _60[0xc48 - 0x60];
    s64 field_c48[1];
    s32 field_c50;
};
static_assert(__builtin_offsetof(Unk_23e7370, field_c48) == 0xc48, "field_c48");
static_assert(__builtin_offsetof(Unk_23e7370, field_c50) == 0xc50, "field_c50");

// The head of the spawner's areas: its position and type.
struct Unk_dec030_Spawner {
    float32x4_t field_0;
    s32 field_10;
};
static_assert(__builtin_offsetof(Unk_dec030_Spawner, field_10) == 0x10, "field_10");

// What HaxeSymbolPokemonObject::field_0 points to, as these use it (Unk_debce0_Owner.h
// has its parameters): its position, its id, the spawner's areas and its handle on
// the player's object.
struct Unk_dec030_Owner {
    u8 _0[0xb0];
    Unk_dec030_Vector field_b0;
    u8 _c0[0x1a0 - 0xc0];
    s64 field_1a0;
    u8 _1a8[0x994 - 0x1a8];
    float field_994;
    u8 _998[0xa70 - 0x998];
    union {
        Unk_debce0_Areas field_a70;
        Unk_dec030_Spawner field_a70_spawner;
    };
    u8 _b10[0xc10 - 0xb10];
    Unk_239a418_Handle* field_c10;
};
static_assert(__builtin_offsetof(Unk_dec030_Owner, field_b0) == 0xb0, "field_b0");
static_assert(__builtin_offsetof(Unk_dec030_Owner, field_1a0) == 0x1a0, "field_1a0");
static_assert(__builtin_offsetof(Unk_dec030_Owner, field_994) == 0x994, "field_994");
static_assert(__builtin_offsetof(Unk_dec030_Owner, field_a70) == 0xa70, "field_a70");
static_assert(__builtin_offsetof(Unk_dec030_Owner, field_c10) == 0xc10, "field_c10");

namespace field {
namespace content {

static const Unk_dec030_Owner* Owner(const HaxeSymbolPokemonObject* object) {
    return static_cast<const Unk_dec030_Owner*>(object->field_0);
}

// The area tests copy the areas first and pass the copy on (Unk_c8dd50 takes it by
// value under its current name; by reference, see IsContainsAreaPlayer).

// Whether the Pokemon is in the area of that index.
static bool IsContainsAreaSelf(const Unk_dec030_Owner* owner, int index) {
    Unk_debce0_Areas areas = owner->field_a70;
    return Unk_c8dd50(areas, Unk_dec030_Vector(owner->field_b0).field_0, index, 0.0f);
}

// The handle's object as the player's, or null when it isn't one.
static Unk_23ea168* Player(Unk_239a498* object) {
    if (object == nullptr)
        return nullptr;
    return Unk_61a530<Unk_23ea168>(object) ? static_cast<Unk_23ea168*>(object) : nullptr;
}

// Whether the player is in the area of that index.
static bool IsContainsAreaPlayer(const Unk_dec030_Owner* owner, int index) {
    Unk_debce0_Areas areas = owner->field_a70;
    Unk_239a418_Ref<Unk_239a418_Handle> handle(owner->field_c10);
    if (handle.m_ptr == nullptr || handle.m_ptr->field_54.load() == 0)
        return false;
    Unk_23ea168* player = Player(reinterpret_cast<Unk_239a498*>(handle.m_ptr->field_60));
    return Unk_c8dd50(areas, Unk_dec030_Vector(player->field_b0).field_0, index, 0.0f);
}

// A random position in the area of that index.
static HaxeVector3 GetAreaRandomPos(const Unk_dec030_Owner* owner, int index) {
    Unk_debce0_Areas areas = owner->field_a70;
    float32x4_t pos =
        Unk_c8e1a0(areas, index, std::max(owner->field_994 + Unk_1f24eb8, Unk_1f24eb4));
    return HaxeVector3(vgetq_lane_f32(pos, 0), vgetq_lane_f32(pos, 1), vgetq_lane_f32(pos, 2));
}

// 0x7100dec030
bool HaxeSymbolPokemonObject::IsContainsMovementArea(HaxeVector3 pos) const {
    Unk_debce0_Areas areas = Owner(this)->field_a70;
    return Unk_c8dd50(areas, float32x4_t{pos.X, pos.Y, pos.Z, 0.0f}, 2, 0.0f);
}

// 0x7100dec0a0
bool HaxeSymbolPokemonObject::IsContainsCreateAreaSelf() const {
    return IsContainsAreaSelf(Owner(this), 0);
}

// 0x7100dec100
bool HaxeSymbolPokemonObject::IsContainsVanishAreaSelf() const {
    return IsContainsAreaSelf(Owner(this), 1);
}

// 0x7100dec160
bool HaxeSymbolPokemonObject::IsContainsMovementAreaSelf() const {
    return IsContainsAreaSelf(Owner(this), 2);
}

// 0x7100dec1c0
bool HaxeSymbolPokemonObject::IsContainsCreateAreaPlayer() const {
    return IsContainsAreaPlayer(Owner(this), 0);
}

// 0x7100dec280
bool HaxeSymbolPokemonObject::IsContainsVanishAreaPlayer() const {
    return IsContainsAreaPlayer(Owner(this), 1);
}

// 0x7100dec340
bool HaxeSymbolPokemonObject::IsContainsMovementAreaPlayer() const {
    return IsContainsAreaPlayer(Owner(this), 2);
}

// 0x7100dec400
HaxeVector3 HaxeSymbolPokemonObject::GetSpawnerPos() const {
    float32x4_t pos = Owner(this)->field_a70_spawner.field_0;
    return HaxeVector3(vgetq_lane_f32(pos, 0), vgetq_lane_f32(pos, 1), vgetq_lane_f32(pos, 2));
}

// 0x7100dec440
HaxeVector3 HaxeSymbolPokemonObject::GetCreateAreaRandomPos() const {
    return GetAreaRandomPos(Owner(this), 0);
}

// 0x7100dec4c0
HaxeVector3 HaxeSymbolPokemonObject::GetVanishAreaRandomPos() const {
    return GetAreaRandomPos(Owner(this), 1);
}

// 0x7100dec540
HaxeVector3 HaxeSymbolPokemonObject::GetMovementAreaRandomPos() const {
    return GetAreaRandomPos(Owner(this), 2);
}

// 0x7100dec5c0
int HaxeSymbolPokemonObject::GetSpawnerType() const {
    return Owner(this)->field_a70_spawner.field_10;
}

// The gimmick spawner that has the id and is still in play, or null.
static Unk_23e7370* FindGimmickSpawner(s64 id) {
    for (Unk_dec030_Object*& object : Unk_27d6158->field_b0) {
        Unk_23e7370* spawner = object->Unk_Cast<Unk_23e7370>();
        if (spawner == nullptr)
            continue;
        for (int i = 0; i < spawner->field_c50; i++) {
            if (spawner->Unk_Id(i) == id) {
                if (!object->vf17())
                    return spawner;
                break;
            }
        }
    }
    return nullptr;
}

// 0x7100dec5d0
void HaxeSymbolPokemonObject::SetGimmickSpawnerVanishFlag(bool flag) {
    if (Unk_23e7370* spawner = FindGimmickSpawner(Owner(this)->field_1a0))
        spawner->Unk_d07d90(flag);
}

// 0x7100dec6c0
bool HaxeSymbolPokemonObject::GetGimmickSpawnerVanishFlag() const {
    if (Unk_23e7370* spawner = FindGimmickSpawner(Owner(this)->field_1a0))
        return spawner->Unk_d07690();
    return false;
}

}  // namespace content
}  // namespace field
