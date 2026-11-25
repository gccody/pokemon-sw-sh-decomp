// Scope: common
// HaxeSymbolPokemonObject's motion-state, move and motion functions: they pass the
// script's calls on to the Pokemon's motion component.
#include <arm_neon.h>

#include <types.h>

#include "field/content/HaxeSymbolPokemonObject.h"
#include "field/content/HaxeVector3.h"
#include "field/content/Unk_decfa0_Owner.h"

// The motion component's functions these call (its class is declared in
// Unk_decfa0_Owner.h, so they're free functions on it until it's known).
// 0x7100d0caa0
void Unk_d0caa0(Unk_23e7a38* self, int state);
// 0x7100d0ccd0
int Unk_d0ccd0(Unk_23e7a38* self);
// 0x7100d0ccf0
void Unk_d0ccf0(Unk_23e7a38* self, const float32x4_t& target, float speed);
// 0x7100d0cbd0
void Unk_d0cbd0(Unk_23e7a38* self);
// 0x7100d0cdd0
bool Unk_d0cdd0(Unk_23e7a38* self);
// 0x7100d0d350
void Unk_d0d350(Unk_23e7a38* self, int frame);
// 0x7100d0d360
void Unk_d0d360(Unk_23e7a38* self, float turnY);
// 0x7100d0d380
void Unk_d0d380(Unk_23e7a38* self, int motion);
// 0x7100d0cc50
void Unk_d0cc50(Unk_23e7a38* self);

// The move speeds MoveStart picks from by its type (1, or anything else).
extern const float Unk_1f24f24;
extern const float Unk_1f24f20;

namespace field {
namespace content {

static Unk_23e7a38* Motion(const HaxeSymbolPokemonObject* object) {
    return static_cast<Unk_decfa0_Owner*>(object->field_0)->Unk_GetComponent<Unk_23e7a38>();
}

// 0x7100dec7a0
void HaxeSymbolPokemonObject::SetMotionState(int state) {
    Unk_d0caa0(Motion(this), state);
}

// 0x7100dec880
int HaxeSymbolPokemonObject::GetMotionState() const {
    return Unk_d0ccd0(Motion(this));
}

// 0x7100dec950
void HaxeSymbolPokemonObject::MoveStart(HaxeVector3 target, int type) {
    Unk_23e7a38* motion = Motion(this);
    float speed = type == 1 ? Unk_1f24f24 : Unk_1f24f20;
    Unk_d0ccf0(motion, float32x4_t{target.X, target.Y, target.Z, 0.0f}, speed);
}

// 0x7100deca80
void HaxeSymbolPokemonObject::MoveStop() {
    Unk_d0cbd0(Motion(this));
}

// 0x7100decb50
bool HaxeSymbolPokemonObject::IsMoveEnd() const {
    return Unk_d0cdd0(Motion(this));
}

// 0x7100decc20
void HaxeSymbolPokemonObject::SetMoveLimitFrame(int frame) {
    Unk_d0d350(Motion(this), frame);
}

// 0x7100decd00
void HaxeSymbolPokemonObject::SetMoveLimitTurnY(float turnY) {
    Unk_d0d360(Motion(this), turnY);
}

// 0x7100decdf0
void HaxeSymbolPokemonObject::MotionStart(int motion) {
    Unk_d0d380(Motion(this), motion);
}

// 0x7100deced0
void HaxeSymbolPokemonObject::MotionEnd() {
    Unk_d0cc50(Motion(this));
}

}  // namespace content
}  // namespace field
