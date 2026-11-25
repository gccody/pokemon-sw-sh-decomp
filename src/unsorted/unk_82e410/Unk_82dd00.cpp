// Scope: common
// Unk_23ace58's function (the TU of 0x710082dd00-0x710082de40), see Handler.h.
#include "unsorted/unk_82e410/Handler.h"

struct Unk_7fe250;
struct Unk_811d90_Self;
void* Unk_7fe250_getFielda8(const Unk_7fe250* self);
bool Unk_803560(void* self, u8 pokeId);
void Unk_811fe0(const Unk_811d90_Self* self, u8 pokeId, bool flag);
void Unk_80e1f0(void* self, void* object, u16 id);

// What Unk_82dd30 takes.
struct Unk_82dd30_Arg {
    u8 field_0;
};

// 0x710082dd30
void Unk_82dd30(Unk_23ace58* self, Unk_23acc98_Result& /*result*/, const Unk_82dd30_Arg& arg) {
    if (!Unk_803560(
            Unk_7fe250_getFielda8(static_cast<const Unk_7fe250*>(Unk_23acc98_Field10(self))),
            arg.field_0))
        return;
    void* poke = Unk_23acc98_Object(self, arg.field_0);
    Unk_811fe0(static_cast<const Unk_811d90_Self*>(Unk_23acc98_Field20(self)), arg.field_0, false);
    Unk_80e1f0(Unk_23acc98_Field20(self), poke, 0x5f6);
}
