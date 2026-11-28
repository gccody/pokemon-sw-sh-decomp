// Scope: common
// Hands a weak handle's object, locked as Unk_23cf990, a callback that
// calls Unk_619060 on what it's given with `false` and a mask of 0x10 (in
// state 3) or 0. The callbacks are captureless lambdas in libc++
// std::functions (vtables 0x71023d8be0 and 0x71023d8c28: no target slots
// without RTTI). Placeholder names: rename once the classes are known.
#include <functional>

#include <types.h>

#include "gflib3/Unk_Lock.h"

// Its getter is out of line.
class Unk_23cf990 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType();
};

struct Unk_619060_0;

void Unk_619060(Unk_619060_0* target, bool enable, const u64& mask);
void Unk_b46790(Unk_23cf990* object, const std::function<void(Unk_619060_0*)>& callback);

class Unk_c0bb20_0 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual Unk_239a418_Ref<Unk_239a418_Handle> vf9();

    u8 _8[0x7c - 0x8];
    u32 field_7c;
};
PKMN_OFFSET_ASSERT(Unk_c0bb20_0, field_7c, 0x7c);

struct Unk_c0bb20_arg0 {
    Unk_c0bb20_0* field_0;
};

// 0x7100c0bb20
void Unk_c0bb20(const Unk_c0bb20_arg0* self) {
    Unk_c0bb20_0* obj = self->field_0;
    if (obj->field_7c == 3) {
        Unk_239a418_Ref<Unk_239a418_Handle> handle = obj->vf9();
        Unk_239a418_Ref<Unk_23cf990> object = handle.m_ptr != nullptr
                                                  ? Unk_Lock<Unk_23cf990>(handle.m_ptr)
                                                  : Unk_239a418_Ref<Unk_23cf990>();
        std::function<void(Unk_619060_0*)> callback = [](Unk_619060_0* target) {
            Unk_619060(target, false, 0x10);
        };
        Unk_b46790(object.m_ptr, callback);
    } else {
        Unk_239a418_Ref<Unk_239a418_Handle> handle = obj->vf9();
        Unk_239a418_Ref<Unk_23cf990> object = handle.m_ptr != nullptr
                                                  ? Unk_Lock<Unk_23cf990>(handle.m_ptr)
                                                  : Unk_239a418_Ref<Unk_23cf990>();
        std::function<void(Unk_619060_0*)> callback = [](Unk_619060_0* target) {
            Unk_619060(target, false, 0);
        };
        Unk_b46790(object.m_ptr, callback);
    }
}
