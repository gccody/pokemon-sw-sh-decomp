// Scope: common
// Small virtual functions of a library class (tools/leafgen.py members): placeholder
// member names vf<slot>, placeholder structs. The class's name is its RTTI's.
// RTTI: N6SiSDK335SiReflectionEventHandlerClassMethodINS_22SiGfxShaderGraphObjectEEE
#include <types.h>

struct Unk_4cf860 {
    u8 _0[0x10];
    u32 field_10;
};
PKMN_OFFSET_ASSERT(Unk_4cf860, field_10, 0x10);

struct Unk_4cf870_arg1_8 {
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
    virtual void vf14(void*, u32);
};

struct Unk_4cf870_arg1 {
    u8 _0[0x8];
    Unk_4cf870_arg1_8* field_8;
};
PKMN_OFFSET_ASSERT(Unk_4cf870_arg1, field_8, 0x8);

struct Unk_4cf890_arg1_8 {
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
    virtual void vf14();
    virtual void vf15(void*, u32);
};

struct Unk_4cf890_arg1 {
    u8 _0[0x8];
    Unk_4cf890_arg1_8* field_8;
};
PKMN_OFFSET_ASSERT(Unk_4cf890_arg1, field_8, 0x8);

namespace SiSDK3 { class SiGfxShaderGraphObject; }
namespace SiSDK3 { template <class T0> class SiReflectionEventHandlerClassMethod; }

namespace SiSDK3 {
template <> class SiReflectionEventHandlerClassMethod<SiSDK3::SiGfxShaderGraphObject> {
public:
    u32 vf4();
    void vf5(Unk_4cf870_arg1* value, bool arg2);
    void vf6(Unk_4cf890_arg1* value, bool arg2);
};
}  // namespace SiSDK3

// 0x71004cf860
u32 SiSDK3::SiReflectionEventHandlerClassMethod<SiSDK3::SiGfxShaderGraphObject>::vf4() {
    const Unk_4cf860* self = reinterpret_cast<const Unk_4cf860*>(this);
    return self->field_10;
}

// 0x71004cf870
void SiSDK3::SiReflectionEventHandlerClassMethod<SiSDK3::SiGfxShaderGraphObject>::vf5(Unk_4cf870_arg1* value, bool arg2) {
    value->field_8->vf14(value, arg2);
}

// 0x71004cf890
void SiSDK3::SiReflectionEventHandlerClassMethod<SiSDK3::SiGfxShaderGraphObject>::vf6(Unk_4cf890_arg1* value, bool arg2) {
    value->field_8->vf15(value, arg2);
}
