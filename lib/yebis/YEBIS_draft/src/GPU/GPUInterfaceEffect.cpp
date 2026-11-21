// Scope: common
// PPFX::IGPUEffect (lib/yebis/YEBIS_draft/src/GPU/GPUInterfaceEffect.h). Its
// other small virtual functions are in lib/yebis/class. The TU's statics are
// the ones every src/GPU TU has (Unk_Statics.h) and two counters of vf22's,
// which its static initialiser, 0x710049a620, leaves alone.
#include <yebis/YEBIS_draft/src/GPU/GPUInterfaceEffect.h>
#include <yebis/YEBIS_draft/src/GPU/Unk_Statics.h>

// 0x7100417a30: printf to the log
void Unk_417a30(const char* format, ...);
// 0x7100446df0: an error code's name
const char* Unk_446df0(s32 result);
// log switches: all messages, and the errors
extern s32 Unk_238c1e0;
extern s32 Unk_238c1e8;

#define UNK_ERROR(...)                                                                                        \
    do {                                                                                                      \
        if (Unk_238c1e0 != 0 && Unk_238c1e8 != 0) {                                                           \
            Unk_417a30("C:/workspace/YEBIS_draft/src/GPU/GPUInterfaceEffect.cpp(%d) : PPFX ERROR: ", __LINE__); \
            Unk_417a30(__VA_ARGS__);                                                                          \
        }                                                                                                     \
    } while (0)

// The tiny effect's functions (C:/workspace/YEBIS_draft/src/GPU/TinyEffect):
// 0x710044f3a0 makes one from an effect file
void* Unk_44f3a0(const void* data, void* arg1, bool arg2);
s32 Unk_44f450(void* self);
s32 Unk_44e630(void* self);
s32 Unk_44e750(void* self);
s32 Unk_44e870(void* self);
s32 Unk_44e960(void* self);
struct Unk_44fa70;
struct Unk_44fa90;
struct Unk_44fab0;
struct Unk_44fad0;
struct Unk_44fae0;
struct Unk_44faf0;
struct Unk_44fb00;
struct Unk_44fb10;
struct Unk_44fb20;
void* Unk_44fa70_get(const Unk_44fa70* self);
void* Unk_44fa90_get(const Unk_44fa90* self);
void* Unk_44fab0_get(const Unk_44fab0* self);
void* Unk_44fad0_get(const Unk_44fad0* self);
u32 Unk_44fae0_get(const Unk_44fae0* self);
u32 Unk_44faf0_get(const Unk_44faf0* self);
void* Unk_44fb00_get(const Unk_44fb00* self);
void* Unk_44fb10_get(const Unk_44fb10* self);
void* Unk_44fb20_get(const Unk_44fb20* self);
// The pipeline state an effect's resource holds (field_18)
void Unk_43fc00(void* self, u32 pass);
void Unk_43fc30(void* self);
void Unk_43fca0(void* self, void* value);
void Unk_43fcc0(void* self, void* value);
void Unk_43fce0(void* self, void* value);
void Unk_43fd00(void* self, void* value);
void Unk_43fd20(void* self, u32 arg1, u32 arg2, void* arg3, void* arg4, void* arg5);

namespace PPFX {

// vf22's counters: how often it was called, and with how many values
static s32 Unk_24e521c;
static s32 Unk_24e5220;

// vf42's first argument
struct Unk_49a1f0_Arg {
    u8 _0[0x38];
    s32 field_38[1];
};

// what the device holds for its tiny effects
struct Unk_49a300_Device {
    u8 _0[0x30];
    void* field_30;
};

// 0x710049a300: "IGPUEffect::CreateEffectFromFile()" in the log. It keeps the
// placeholder name its caller (GPUTextureUtil.cpp) has.
s32 Unk_49a300(void* device, const void* data, s32 size, void* arg3, void* effect, char** errors, s32 arg6);

// 0x7100499e00, 0x7100499f00
IGPUEffect::~IGPUEffect() {
    if (field_78 != nullptr) {
        field_78->Unk_Release();
        field_78 = nullptr;
    }
    Unk_DeleteParams();
}

// 0x7100499fc0: the name with everything after its first character reversed
s32 IGPUEffect::vf16(const char* name) {
    Unk_TFXString reversed(name);
    for (s32 i = 1; i < reversed.field_0; i++)
        reversed.field_8[i] = name[reversed.field_0 - i];
    return field_78->vf5(reversed.field_8);
}

// 0x710049a070
s32 IGPUEffect::vf19(u64 a, u64 b, u32 count) {
    if (count == 0)
        return 0;
    return field_78->vf9(a, b, count);
}

// 0x710049a0b0
s32 IGPUEffect::vf22(u64 a, u64 b, u32 count) {
    if (count == 0)
        return 0;
    Unk_24e521c++;
    Unk_24e5220 += count;
    return field_78->vf12(a, b, count);
}

// 0x710049a0f0
s32 IGPUEffect::vf23(u64 a, u64 b, u32 count) {
    if (count == 0)
        return 0;
    return field_78->vf13(a, b, count);
}

// 0x710049a120
s32 IGPUEffect::vf25(u64 a, u64 b, u32 count) {
    if (count == 0)
        return 0;
    return field_78->vf15(a, b, count);
}

// 0x710049a190
Unk_TinyEffect::Unk_Result IGPUEffect::vf31(u64 a) {
    return field_78->vf20(a);
}

// 0x710049a1a0
Unk_TinyEffect::Unk_Result IGPUEffect::vf32(u64 a) {
    return field_78->vf21(a);
}

// 0x710049a1b0
s32 IGPUEffect::vf37() {
    return Unk_44e630(field_78);
}

// 0x710049a1c0
s32 IGPUEffect::vf38() {
    return Unk_44e750(field_78);
}

// 0x710049a1d0
s32 IGPUEffect::vf39() {
    return Unk_44e870(field_78);
}

// 0x710049a1e0
s32 IGPUEffect::vf40() {
    return Unk_44e960(field_78);
}

// 0x710049a1f0
s32 IGPUEffect::vf42(const u8* a, void* b, u32 c, s32 d, u32 index, bool flag) {
    if (d == 0)
        d = reinterpret_cast<const Unk_49a1f0_Arg*>(a)->field_38[index];
    return field_78->vf26(reinterpret_cast<u64>(a), &b, &c, reinterpret_cast<u32*>(&d), index, 1, flag);
}

// 0x710049a280
s32 IGPUEffect::vf35(u32 pass) {
    if (field_18 != nullptr)
        Unk_43fc00(field_18, pass);
    return field_78->vf24(pass);
}

// 0x710049a2c0
s32 IGPUEffect::vf36() {
    s32 result = field_78->vf25();
    if (field_18 != nullptr)
        Unk_43fc30(field_18);
    return result;
}

// 0x710049a300
s32 Unk_49a300(void* device, const void* data, s32 size, void* arg3, void* effect, char** errors, s32 arg6) {
    IGPUEffect** out = static_cast<IGPUEffect**>(effect);
    if (out == nullptr)
        return -6;
    *out = nullptr;
    Unk_TinyEffect* tinyEffect = static_cast<Unk_TinyEffect*>(Unk_44f3a0(data, static_cast<Unk_49a300_Device*>(device)->field_30, arg6 & 1));
    if (tinyEffect == nullptr)
        return -1;
#line 1398
    *out = UNK_NEW(IGPUEffect)(static_cast<IGPUDevice*>(device));
    (*out)->Unk_SetTinyEffect(tinyEffect);
    tinyEffect->Unk_Release();
    return 0;
}

// 0x710049a480
s32 IGPUEffect::SetupGraphicsPipelineState() {
    if (field_78 == nullptr)
        return -1;
    s32 result = Unk_44f450(field_78);
    if (result < 0) {
#line 2460
        UNK_ERROR("IGPUEffect::SetupGraphicsPipelineState(): pTinyEffect->SetupRenderStateForSiGfx() failed (0x%x: %s).\n", result, Unk_446df0(result));
        return result;
    }
    void* a = Unk_44fa70_get(reinterpret_cast<const Unk_44fa70*>(field_78));
    void* b = Unk_44fa90_get(reinterpret_cast<const Unk_44fa90*>(field_78));
    void* c = Unk_44fab0_get(reinterpret_cast<const Unk_44fab0*>(field_78));
    void* d = Unk_44fad0_get(reinterpret_cast<const Unk_44fad0*>(field_78));
    void* state = field_18;
    Unk_43fca0(state, a);
    Unk_43fcc0(state, b);
    Unk_43fce0(state, c);
    Unk_43fd00(state, d);
    u32 e = Unk_44faf0_get(reinterpret_cast<const Unk_44faf0*>(field_78));
    u32 f = Unk_44fae0_get(reinterpret_cast<const Unk_44fae0*>(field_78));
    void* g = Unk_44fb00_get(reinterpret_cast<const Unk_44fb00*>(field_78));
    void* h = Unk_44fb20_get(reinterpret_cast<const Unk_44fb20*>(field_78));
    void* i = Unk_44fb10_get(reinterpret_cast<const Unk_44fb10*>(field_78));
    Unk_43fd20(state, e, f, g, h, i);
    return 0;
}

// 0x710049a5e0
s32 IGPUEffect::vf7(void* out) {
    *static_cast<Unk_Info*>(out) = field_48;
    return 0;
}

}  // namespace PPFX
