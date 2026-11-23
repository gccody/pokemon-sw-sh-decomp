// Scope: common
// YEBIS's interface functions (C:/workspace/YEBIS_draft/src/ppfx.cpp is the
// __FILE__ of this translation unit's log lines): most of them hand their
// arguments to the one PPFX::CPostEffect there is, without the context they
// are called with. lib/yebis/leaf/Unk_4182e0.cpp has the ones leafgen wrote;
// these are the others of that shape. Placeholder names.
#include <stdarg.h>
#include <stdio.h>

#include <yebis/YEBIS_draft/src/GPU/GPUPostEffect.h>
#include <yebis/YEBIS_draft/src/GPU/Unk_Statics.h>
#include <yebis/YEBIS_draft/src/GPU/Unk_Array.h>
#include <yebis/YEBIS_draft/src/GPU/GPUInterface.h>
#include <yebis/YEBIS_draft/src/Unk_4b9860.h>
#include <yebis/YEBIS_draft/src/GPU/GPUInterfaceDevice.h>
#include <yebis/YEBIS_draft/src/ppfxRenderToTexture.h>

#define PPFX_FILE "C:/workspace/YEBIS_draft/src/ppfx.cpp"
#include <yebis/YEBIS_draft/src/GPU/Unk_Log.h>

// This file's statics, which LLVM merged with the ones of Unk_Statics.h into
// one object (0x71024e0018), sorted by size: the angle, the white points, the
// four pointers below (0x71024e00e0 to 0x71024e00f8), the two colour spaces,
// the reflection handle and the line of the log (0x71024e01b8).

// 0x71024e00e0: the post effect (its name is in the log lines)
static PPFX::CPostEffect* s_pSinglePostEffect;

// 0x71024e00e8, 0x71024e00f0: the context's two render-to-texture interfaces
static PPFX::IPfxBaseRenderToTexture* Unk_24e00e8;
static PPFX::IPfxBaseRenderToTexture* Unk_24e00f0;

// 0x71004b9840, 0x71004b9850 (lib/yebis/leaf): where an interface keeps what
// it holds
struct Unk_4b9840;
const u8* Unk_4b9840_get(const Unk_4b9840* self);
struct Unk_4b9850;
const u8* Unk_4b9850_get(const Unk_4b9850* self);
// 0x7100446df0: a result's name
const char* Unk_446df0(s32 result);

// The post effect's functions these call, under the names and types their
// rows have (leafgen's, where it wrote them).
struct Unk_424490;
struct Unk_423eb0;
struct Unk_427a60;
struct Unk_427a80;
struct Unk_427ab0;
struct Unk_427ac0;
struct Unk_423950;
struct Unk_423950_arg3;
struct Unk_423950_arg4;
struct Unk_423950_arg5;
struct Unk_423da0;
struct Unk_423b90;
struct Unk_423b80;
struct Unk_43b9b0;
struct Unk_43a0e0;
struct Unk_423ed0;
s32 Unk_424670(PPFX::CPostEffect* self, f32 elapsed);  // SetDeltaTime (its log message)
void Unk_424490_update(Unk_424490* self, u32 value);
void Unk_423eb0_update(Unk_423eb0* self, f32 a, f32 b, f32 c);
void Unk_427a60_update(Unk_427a60* self, f32 a, f32 b);
void Unk_427a80_update(Unk_427a80* self, f32 a, f32 b, f32 c, f32 d, f32 e);
void Unk_427ab0_update(Unk_427ab0* self, u32 index, f32 value);
void Unk_427ac0_update(Unk_427ac0* self, f32 a, f32 b);
void Unk_423950_update(Unk_423950* self, u32 arg1, bool arg2, const Unk_423950_arg3* arg3,
                       const Unk_423950_arg4* arg4, const Unk_423950_arg5* arg5, bool arg6);
void Unk_423da0_update(Unk_423da0* self, u32 value);
void Unk_423b90_update(Unk_423b90* self, u32 value);
namespace PPFX {
struct Unk_GlareRect;
}
void Unk_423b80_call(const Unk_423b80* self, const PPFX::Unk_GlareRect* arg, f32 a, f32 b, f32 c, f32 d, f32 e);
void Unk_43b9b0_update(Unk_43b9b0* self, u64 value);
void Unk_43a0e0_update(Unk_43a0e0* self, u64 value);
void Unk_423ed0_update(Unk_423ed0* self, u64 value, u32 arg2);
void Unk_425410(PPFX::CPostEffect* self, u32 arg1, u64 object, u64 arg3, u32 arg4, f32 a, f32 b);
void Unk_423ee0(PPFX::CPostEffect* self, u32 arg1, u64 object);
void Unk_423ff0(PPFX::CPostEffect* self, u32 arg1, u64 object);

// 0x710238c230: what the context's initialisation starts from (negative: it
// fails at once)
extern s32 Unk_238c230 __attribute__((visibility("hidden")));
f32 Unk_429da0(u64 self, s32 view);
f32 Unk_429e80(u64 self, s32 view);
f32 Unk_429ed0(u64 self, s32 view);
f32 Unk_429e60(u64, u32);
struct Unk_43b9c0;
u64 Unk_43b9c0_get(const Unk_43b9c0* self);
void Unk_43b580(u64 self, bool value);

// What an interface holds; a null pointer stays one (inline in the functions
// that take an interface, which read it before they read the post effect).
static inline u64 Unk_Held(const void* object) {
    if (object != nullptr) {
        object = *reinterpret_cast<const void* const*>(Unk_4b9850_get(static_cast<const Unk_4b9850*>(object)));
    }
    return reinterpret_cast<u64>(object);
}

// 0x71024e00f8: what the log hands its lines to (printf without one)
static void (*Unk_24e00f8)(const char* text);
// 0x71024e01b8: the line
static char Unk_24e01b8[0x800];

// 0x71004190d0 (lib/yebis/leaf): whether the post effect is between its
// begin and end
struct Unk_4190d0;
bool Unk_4190d0_check(const Unk_4190d0* self);

namespace PPFX {

// RTTI: PPFX::IPfxBaseContext and PPFX::IPfxContext_Nvn. What a context holds
// (field_10) is a block that starts with a flag and has the post effect's
// device at 0x18.
struct Unk_ContextData {
    bool field_0;
    u8 pad_1[0x17];
    void* field_18;
};

class IPfxBaseContext : public IPfxInterface {
public:
    IPfxBaseContext() {}
    ~IPfxBaseContext() override;  // 0x7100417870, 0x7100417b00
    s32 vf5() override;           // 0x7100418060
    // 0x7100417b30 (its log lines name it)
    s32 Initialize(const Unk_417b30_Desc* desc, u32 arg2, u32 arg3, u32 arg4, void* arg5);

    Unk_ContextData** Unk_Data() {
        return reinterpret_cast<Unk_ContextData**>(
            const_cast<u8*>(Unk_4b9850_get(reinterpret_cast<const Unk_4b9850*>(this))));
    }
};

class IPfxContext_Nvn : public IPfxBaseContext {
public:
    ~IPfxContext_Nvn() override {}  // 0x7100418ae0 (deleting)
};

// 0x7100417870
IPfxBaseContext::~IPfxBaseContext() {
#line 712
    PPFX_LOG("==== IPfxBaseContext::~IPfxBaseContext() ====\n");
    if (s_pSinglePostEffect != nullptr) {
        PPFX_SAFE_RELEASE_INTERFACE(Unk_24e00e8);
        PPFX_SAFE_RELEASE_INTERFACE(Unk_24e00f0);
        s32 result = s_pSinglePostEffect->Uninitialize(nullptr);
        if (result < 0) {
#line 729
            PPFX_ERROR("IPfxBaseContext::~IPfxBaseContext(): s_pSinglePostEffect->Uninitialize() failed (0x%x: %s).\n",
                       result, Unk_446df0(result));
        } else {
#line 734
            PPFX_LOG("IPfxBaseContext::~IPfxBaseContext(): s_pSinglePostEffect->Uninitialize() succeeded.\n");
        }
        UNK_DELETE(s_pSinglePostEffect);
        *const_cast<u64*>(reinterpret_cast<const u64*>(Unk_4b9840_get(reinterpret_cast<const Unk_4b9840*>(this)))) = 0;
        if (result < 0) {
            return;
        }
    }
#line 744
    PPFX_LOG("==== IPfxBaseContext::~IPfxBaseContext() succeeded. ====\n");
}

// a view's auto exposure settings, as Initialize keeps them across the post
// effect's initialisation (placeholder)
struct Unk_417b30_View {
    f32 field_0;
    f32 field_4;
    f32 field_8;
    f32 field_c;
};
PKMN_SIZE_ASSERT(Unk_417b30_View, 0x10);

// 0x7100417b30
s32 IPfxBaseContext::Initialize(const Unk_417b30_Desc* desc, u32 arg2, u32 arg3, u32 arg4, void* arg5) {
    UNK_PPFX_INFO("==== IPfxBaseContext::Initialize() ====\n");
#line 855
    PPFX_LOG("==== IPfxBaseContext::Initialize() ====\n");
    s32 result = Unk_238c230;
    if (result < 0) {
        return result;
    }
    PPFX_SAFE_RELEASE_INTERFACE(Unk_24e00e8);
    PPFX_SAFE_RELEASE_INTERFACE(Unk_24e00f0);
    if (s_pSinglePostEffect == nullptr) {
#line 891
        s_pSinglePostEffect = UNK_NEW(CPostEffect);
        *reinterpret_cast<CPostEffect**>(const_cast<u8*>(Unk_4b9840_get(reinterpret_cast<const Unk_4b9840*>(this)))) =
            s_pSinglePostEffect;
    }
    s32 count = 0;
    Unk_417b30_View* views = nullptr;
    if (vf5() != 0) {
        count = s_pSinglePostEffect->field_400;
#line 915
        views = UNK_NEW_ARRAY(Unk_417b30_View, count);
        for (s32 i = 0; i < count; i++) {
            views[i].field_0 = Unk_429da0(reinterpret_cast<u64>(s_pSinglePostEffect), i);
            views[i].field_4 = Unk_429e80(reinterpret_cast<u64>(s_pSinglePostEffect), i);
            if (views[i].field_4 <= 0.0f || views[i].field_4 > 256.0f || views[i].field_0 <= 0.0f ||
                views[i].field_0 > 65536.0f) {
                views[i].field_0 = 1.0f;
                views[i].field_4 = 0.18f;
            }
            views[i].field_8 = Unk_429e60(reinterpret_cast<u64>(s_pSinglePostEffect), i);
            views[i].field_c = Unk_429ed0(reinterpret_cast<u64>(s_pSinglePostEffect), i);
        }
    }
    u64 saved = Unk_43b9c0_get(reinterpret_cast<const Unk_43b9c0*>(s_pSinglePostEffect));
    bool none = true;
    if (desc->field_70 != 0) {
        Unk_43b9b0_update(reinterpret_cast<Unk_43b9b0*>(s_pSinglePostEffect), desc->field_70);
        none = false;
    }
    Unk_43b580(reinterpret_cast<u64>(s_pSinglePostEffect), none);
    result = s_pSinglePostEffect->Initialize(desc, arg2, arg3, arg4, arg5);
    if (count != 0 && result >= 0) {
        s32 n = std::min(count, s_pSinglePostEffect->field_400);
        for (s32 i = 0; i < n; i++) {
            s_pSinglePostEffect->InitializeAutoExposure(i, views[i].field_4, views[i].field_0);
            s_pSinglePostEffect->Unk_426070(i, views[i].field_8);
        }
    }
    UNK_DELETE_ARRAY(views);
    Unk_43b580(reinterpret_cast<u64>(s_pSinglePostEffect), false);
    Unk_43b9b0_update(reinterpret_cast<Unk_43b9b0*>(s_pSinglePostEffect), saved);
    if (result < 0) {
#line 995
        PPFX_ERROR("IPfxBaseContext::Initialize(): s_pSinglePostEffect->Initialize() failed (0x%x: %s).\n", result,
                   Unk_446df0(result));
        return result;
    }
    if (s_pSinglePostEffect->Unk_41af70()->field_2c >= 0) {
        Unk_24e00e8 = Unk_4ba2d0();
        Unk_24e00e8->Initialize(this, reinterpret_cast<CGPUBaseResourceManage*>(s_pSinglePostEffect->Unk_41af70()));
    }
    Unk_RenderTexture* texture = s_pSinglePostEffect->field_1d8;
    if (texture != nullptr) {
        Unk_24e00f0 = Unk_4ba2d0();
        Unk_24e00f0->Initialize(this, reinterpret_cast<CGPUBaseResourceManage*>(texture));
    }
    {
        s32 used = s_pSinglePostEffect->field_18->field_15000;
        f32 kb = used / 1024.0f;
        f32 mb = kb / 1024.0f;
        UNK_PPFX_INFO("GPU total Resource used: %d bytes (%.2f KB / %.2f MB)\n", used, kb, mb);
    }
#line 1128
    PPFX_LOG("==== IPfxBaseContext::Initialize() succeeded. ====\n");
    UNK_PPFX_INFO("==== IPfxBaseContext::Initialize() succeeded. ====\n");
    return 0;
}

// 0x7100418060
s32 IPfxBaseContext::vf5() {
    Unk_ContextData** data = Unk_Data();
    if (*data == nullptr) {
        return 0;
    }
    if ((*data)->field_18 == nullptr) {
        return 0;
    }
    if (Unk_4190d0_check(reinterpret_cast<const Unk_4190d0*>(*data))) {
        return -2;
    }
    return (*data)->field_0 ? 2 : 1;
}

// 0x7100418b10: "IPfxContext::Instantiate()" is the name its allocation is
// made under.
IPfxContext_Nvn* Unk_418b10() {
#line 771
    return new (Unk_4b99a0(Unk_238d5f8, sizeof(IPfxContext_Nvn), __FILE__, __LINE__,
                           const_cast<char*>("IPfxContext::Instantiate()"))) IPfxContext_Nvn;
}

}  // namespace PPFX

// Not in the executable (nothing calls it, so the linker dropped it): what
// sets Unk_24e00f8. The static is in the merged object between the post
// effect's pointers and the colour spaces, and its test survives in
// Unk_417a30, so something in this file stores it: without a store LLVM
// takes it to be always null.
void Unk_24e00f8_set(void (*callback)(const char* text)) {
    Unk_24e00f8 = callback;
}

// 0x7100417a30: printf to the log
s32 Unk_417a30(const char* format, ...) {
    va_list args;
    va_start(args, format);
    s32 length = vsnprintf(Unk_24e01b8, sizeof(Unk_24e01b8), format, args);
    va_end(args);
    if (Unk_24e00f8 != nullptr) {
        Unk_24e00f8(Unk_24e01b8);
    } else {
        printf(Unk_24e01b8);
    }
    return length;
}

// 0x71004180d0: IPfxBaseContext::Uninitialize (its log lines name it)
s32 Unk_4180d0(u64 self) {
    UNK_PPFX_INFO("==== IPfxBaseContext::Uninitialize() ====\n");
#line 1185
    PPFX_LOG("==== IPfxBaseContext::Uninitialize() ====\n");
    if (s_pSinglePostEffect != nullptr) {
        PPFX_SAFE_RELEASE_INTERFACE(Unk_24e00e8);
        PPFX_SAFE_RELEASE_INTERFACE(Unk_24e00f0);
        s32 result = s_pSinglePostEffect->Uninitialize(nullptr);
        if (result < 0) {
#line 1227
            PPFX_ERROR("IPfxBaseContext::Uninitialize(): s_pSinglePostEffect->Uninitialize() failed (0x%x: %s).\n", result,
                       Unk_446df0(result));
            return result;
        }
#line 1232
        PPFX_LOG("IPfxBaseContext::Uninitialize(): s_pSinglePostEffect->Uninitialize() succeeded.\n");
        UNK_DELETE(s_pSinglePostEffect);
        *reinterpret_cast<void**>(const_cast<u8*>(Unk_4b9840_get(reinterpret_cast<const Unk_4b9840*>(self)))) = nullptr;
    }
#line 1246
    PPFX_LOG("==== IPfxBaseContext::Uninitialize() succeeded. ====\n");
    UNK_PPFX_INFO("==== IPfxBaseContext::Uninitialize() succeeded. ====\n");
    return 0;
}

void Unk_4234f0(u64, u32);
// 0x71004182e0
void Unk_4182e0_call(void* /*unused*/, u32 value) {
    Unk_4234f0(reinterpret_cast<u64>(s_pSinglePostEffect), value);
}

void Unk_4276e0(u64, f32, f32, f32, f32, f32);
// 0x71004182f0
void Unk_4182f0_call(f32 a, f32 b, f32 c, f32 d, f32 e) {
    Unk_4276e0(reinterpret_cast<u64>(s_pSinglePostEffect), a, b, c, d, e);
}

void Unk_427760(u64, f32, f32, f32, f32, f32);
// 0x7100418300
void Unk_418300_call(f32 a, f32 b, f32 c, f32 d, f32 e) {
    Unk_427760(reinterpret_cast<u64>(s_pSinglePostEffect), a, b, c, d, e);
}

// 0x7100418310
s32 Unk_418310(u64, f32 elapsed) {
    return Unk_424670(s_pSinglePostEffect, elapsed);
}

void Unk_4243c0(u64, u32, f32, f32, PPFX::Unk_Float);
// 0x7100418320
void Unk_418320_call(void* /*unused*/, u32 value, f32 a, f32 b, PPFX::Unk_Float c) {
    Unk_4243c0(reinterpret_cast<u64>(s_pSinglePostEffect), value, a, b, c);
}

// 0x7100418330
void Unk_418330(void*, u32 value) {
    Unk_424490_update(reinterpret_cast<Unk_424490*>(s_pSinglePostEffect), value);
}

void Unk_4278c0(u64, void*);
// 0x7100418340
void Unk_418340_call(void* /*unused*/, void* value) {
    Unk_4278c0(reinterpret_cast<u64>(s_pSinglePostEffect), value);
}

// 0x7100427900 (GPUPostEffect.cpp)
PPFX::Unk_4278c0_Data* Unk_427900(u64, void*, u32);
// 0x7100418350
void Unk_418350_call(void* /*unused*/, void* value, u32 arg2) {
    Unk_427900(reinterpret_cast<u64>(s_pSinglePostEffect), value, arg2);
}

void Unk_423990(u64, bool);
// 0x7100418360
void Unk_418360_call(void* /*unused*/, bool value) {
    Unk_423990(reinterpret_cast<u64>(s_pSinglePostEffect), value);
}

void Unk_423a50(u64, const PPFX::Unk_Rect*, u32, f32, f32, f32, f32, f32, f32);
// 0x7100418370
void Unk_418370_call(void* /*unused*/, const PPFX::Unk_Rect* value, u32 arg2, f32 a, f32 b, f32 c, f32 d, f32 e, f32 f) {
    Unk_423a50(reinterpret_cast<u64>(s_pSinglePostEffect), value, arg2, a, b, c, d, e, f);
}

void Unk_423ae0(u64, const PPFX::Unk_Rect*, f32, f32, f32, f32);
// 0x7100418380
void Unk_418380_call(void* /*unused*/, const PPFX::Unk_Rect* value, f32 a, f32 b, f32 c, f32 d) {
    Unk_423ae0(reinterpret_cast<u64>(s_pSinglePostEffect), value, a, b, c, d);
}

void Unk_423b50(u64, f32, f32);
// 0x7100418390
void Unk_418390_call(f32 a, f32 b) {
    Unk_423b50(reinterpret_cast<u64>(s_pSinglePostEffect), a, b);
}

// 0x71004183a0
void Unk_4183a0(void*, bool enable) {
    s_pSinglePostEffect->Unk_423630(enable);
}

void Unk_428ec0(u64, f32, f32, f32);
// 0x71004183b0
void Unk_4183b0_call(f32 a, f32 b, f32 c) {
    Unk_428ec0(reinterpret_cast<u64>(s_pSinglePostEffect), a, b, c);
}

void Unk_424740(u64, s32, bool);
// 0x71004183c0
void Unk_4183c0_call(void* /*unused*/, s32 value, bool arg2) {
    Unk_424740(reinterpret_cast<u64>(s_pSinglePostEffect), value, arg2);
}

void Unk_429dc0(u64, u32);
// 0x71004183d0
void Unk_4183d0_call(void* /*unused*/, u32 value) {
    Unk_429dc0(reinterpret_cast<u64>(s_pSinglePostEffect), value);
}

void Unk_424b20(u64, s32, f32, f32);
// 0x71004183e0
void Unk_4183e0_call(void* /*unused*/, s32 value, f32 a, f32 b) {
    Unk_424b20(reinterpret_cast<u64>(s_pSinglePostEffect), value, a, b);
}

void Unk_424c90(u64, s32, f32, f32);
// 0x71004183f0
void Unk_4183f0_call(void* /*unused*/, s32 value, f32 a, f32 b) {
    Unk_424c90(reinterpret_cast<u64>(s_pSinglePostEffect), value, a, b);
}

s32 Unk_424f40(f32, f32, f32, f32, u64, s32);
// 0x7100418400
s32 Unk_418400_call(void* /*unused*/, s32 view, f32 width, f32 height, f32 x, f32 y) {
    return Unk_424f40(width, height, x, y, reinterpret_cast<u64>(s_pSinglePostEffect), view);
}

void Unk_424de0(u64, s32, u32, f32);
// 0x7100418410
void Unk_418410_call(void* /*unused*/, s32 value, u32 arg2, f32 a) {
    Unk_424de0(reinterpret_cast<u64>(s_pSinglePostEffect), value, arg2, a);
}

s32 Unk_4248b0(f32, PPFX::Unk_Float, PPFX::Unk_Float, f32, f32, f32, f32, u64, s32);
// 0x7100418420
s32 Unk_418420_call(void* /*unused*/, s32 view, f32 a, f32 b, f32 c, f32 d, f32 e, f32 f, f32 g) {
    return Unk_4248b0(a, b, c, d, e, f, g, reinterpret_cast<u64>(s_pSinglePostEffect), view);
}

void Unk_425170(u64, s32, bool);
// 0x7100418430
void Unk_418430_call(void* /*unused*/, u64 value, bool arg2) {
    Unk_425170(reinterpret_cast<u64>(s_pSinglePostEffect), value, arg2);
}

// 0x7100418440
void Unk_418440_call(void* /*unused*/, u32 value) {
    Unk_429e60(reinterpret_cast<u64>(s_pSinglePostEffect), value);
}

void Unk_423e20(u64, u32);
// 0x7100418450
void Unk_418450_call(void* /*unused*/, bool value) {
    Unk_423e20(reinterpret_cast<u64>(s_pSinglePostEffect), value);
}

// 0x7100418460
void Unk_418460(void*, f32 a, f32 b, f32 c) {
    Unk_423eb0_update(reinterpret_cast<Unk_423eb0*>(s_pSinglePostEffect), a, b, c);
}

s32 Unk_4244a0(u64, u32 tonemap, f32 exposure, f32 gamma, f32 factor, f32 dither);
// 0x7100418470 (the post effect's tone map, whose four floats it passes on)
void Unk_418470_call(void* /*unused*/, u32 value, f32 exposure, f32 gamma, f32 factor, f32 dither) {
    Unk_4244a0(reinterpret_cast<u64>(s_pSinglePostEffect), value, exposure, gamma, factor, dither);
}

void Unk_4246f0(u64, const PPFX::Unk_Rect*, f32, f32, f32);
// 0x7100418480
void Unk_418480_call(void* /*unused*/, const PPFX::Unk_Rect* value, f32 a, f32 b, f32 c) {
    Unk_4246f0(reinterpret_cast<u64>(s_pSinglePostEffect), value, a, b, c);
}

void Unk_4277e0(u64, u32, u32, f32, f32, f32, f32, f32);
// 0x7100418490
void Unk_418490_call(void* /*unused*/, bool value, bool arg2, f32 a, f32 b, f32 c, f32 d, f32 e) {
    Unk_4277e0(reinterpret_cast<u64>(s_pSinglePostEffect), value, arg2, a, b, c, d, e);
}

void Unk_423660(u64, u32);
// 0x71004184b0
void Unk_4184b0_call(void* /*unused*/, bool value) {
    Unk_423660(reinterpret_cast<u64>(s_pSinglePostEffect), value);
}

// 0x71004184c0
void Unk_4184c0(void*, f32 a, f32 b) {
    Unk_427a60_update(reinterpret_cast<Unk_427a60*>(s_pSinglePostEffect), a, b);
}

// 0x71004184d0
void Unk_4184d0(void*, f32 a, f32 b, f32 c, f32 d, f32 e) {
    Unk_427a80_update(reinterpret_cast<Unk_427a80*>(s_pSinglePostEffect), a, b, c, d, e);
}

// 0x71004184e0
void Unk_4184e0(void*, u32 index, f32 value) {
    Unk_427ab0_update(reinterpret_cast<Unk_427ab0*>(s_pSinglePostEffect), index, value);
}

// 0x71004184f0
void Unk_4184f0(void*, f32 a, f32 b) {
    Unk_427ac0_update(reinterpret_cast<Unk_427ac0*>(s_pSinglePostEffect), a, b);
}

// 0x7100418500
void Unk_418500(void*, u32 arg1, const Unk_423950_arg3* arg2, const Unk_423950_arg4* arg3,
                const Unk_423950_arg5* arg4, bool arg5) {
    Unk_423950_update(reinterpret_cast<Unk_423950*>(s_pSinglePostEffect), arg1, false, arg2, arg3, arg4, arg5);
}

void Unk_4237b0(u64, u32, u32);
// 0x7100418530
void Unk_418530_call(void* /*unused*/, bool value) {
    Unk_4237b0(reinterpret_cast<u64>(s_pSinglePostEffect), value, 0);
}

void Unk_4236f0(u64, u32);
// 0x7100418550
void Unk_418550_call(void* /*unused*/, bool value) {
    Unk_4236f0(reinterpret_cast<u64>(s_pSinglePostEffect), value);
}

void Unk_423780(u64, const PPFX::Unk_Rect*, bool, bool, f32);
// 0x7100418560
void Unk_418560_call(void* /*unused*/, const PPFX::Unk_Rect* value, bool arg2, bool arg3, f32 arg4) {
    Unk_423780(reinterpret_cast<u64>(s_pSinglePostEffect), value, arg2, arg3, arg4);
}

void Unk_423d00(u64, u32);
// 0x7100418580
void Unk_418580_call(void* /*unused*/, bool value) {
    Unk_423d00(reinterpret_cast<u64>(s_pSinglePostEffect), value);
}

// 0x7100418590
void Unk_418590(void*, u32 value) {
    Unk_423da0_update(reinterpret_cast<Unk_423da0*>(s_pSinglePostEffect), value);
}

void Unk_423db0(u64, s32, u32, PPFX::Unk_Float, PPFX::Unk_Float, PPFX::Unk_Float);
// 0x71004185a0
void Unk_4185a0_call(void* /*unused*/, s32 value, u32 arg2, f32 a, f32 b, f32 c) {
    Unk_423db0(reinterpret_cast<u64>(s_pSinglePostEffect), value, arg2, a, b, c);
}

void Unk_439630(u64, u32);
// 0x71004185b0
void Unk_4185b0_call(void* /*unused*/, u32 value) {
    Unk_439630(reinterpret_cast<u64>(s_pSinglePostEffect), value);
}

void Unk_424240(u64, u32, f32, f32, f32, f32);
// 0x71004185c0
void Unk_4185c0_call(f32 a, f32 b, f32 c, f32 d) {
    Unk_424240(reinterpret_cast<u64>(s_pSinglePostEffect), 0, a, b, c, d);
}

void Unk_4253e0(u64, f32, f32, f32, f32);
// 0x71004185d0
void Unk_4185d0_call(f32 a, f32 b, f32 c, f32 d) {
    Unk_4253e0(reinterpret_cast<u64>(s_pSinglePostEffect), a, b, c, d);
}

// 0x71004185e0
void Unk_4185e0(void*, const void* object) {
    u64 held = Unk_Held(object);
    Unk_43a0e0_update(reinterpret_cast<Unk_43a0e0*>(s_pSinglePostEffect), held);
}

// 0x7100418610
void Unk_418610(void*, const void* object) {
    u64 held = Unk_Held(object);
    Unk_423ed0_update(reinterpret_cast<Unk_423ed0*>(s_pSinglePostEffect), held, 0);
}

// 0x7100418640
void Unk_418640(void*, u32 arg1, const void* object, u32 arg3, f32 a, f32 b) {
    u64 held = Unk_Held(object);
    Unk_425410(s_pSinglePostEffect, arg1, held, 0, arg3, a, b);
}

// 0x71004186a0
void Unk_4186a0(void*, u32 arg1, const void* object) {
    u64 held = Unk_Held(object);
    Unk_423ee0(s_pSinglePostEffect, arg1, held);
}

void Unk_423ba0(u64, bool);
// 0x71004186e0
void Unk_4186e0_call(void* /*unused*/, bool value) {
    Unk_423ba0(reinterpret_cast<u64>(s_pSinglePostEffect), value);
}

// 0x71004186f0
void Unk_4186f0(void*, u32 value) {
    Unk_423b90_update(reinterpret_cast<Unk_423b90*>(s_pSinglePostEffect), value);
}

// 0x7100418700
void Unk_418700(void*, const PPFX::Unk_GlareRect* arg, f32 a, f32 b, f32 c, f32 d, f32 e) {
    Unk_423b80_call(reinterpret_cast<const Unk_423b80*>(s_pSinglePostEffect), arg, a, b, c, d, e);
}

void Unk_423c60(u64, const PPFX::Unk_Rect*, u32, u32, f32, f32);
// 0x7100418710
void Unk_418710_call(void* /*unused*/, const PPFX::Unk_Rect* value, u32 arg2, u32 arg3, f32 a, f32 b) {
    Unk_423c60(reinterpret_cast<u64>(s_pSinglePostEffect), value, arg2, arg3, a, b);
}

void Unk_423cd0(u64, f32, f32);
// 0x7100418720
void Unk_418720_call(f32 a, f32 b) {
    Unk_423cd0(reinterpret_cast<u64>(s_pSinglePostEffect), a, b);
}

// 0x7100418730
void Unk_418730(void*, u32 arg1, const void* object) {
    u64 held = Unk_Held(object);
    Unk_423ff0(s_pSinglePostEffect, arg1, held);
}

void Unk_43a400(u64);
// 0x7100418770
void Unk_418770_call() {
    Unk_43a400(reinterpret_cast<u64>(s_pSinglePostEffect));
}

void Unk_4255b0(u64, u32);
// 0x7100418780
void Unk_418780_call(void* /*unused*/, u32 value) {
    Unk_4255b0(reinterpret_cast<u64>(s_pSinglePostEffect), value);
}

void Unk_43a5b0(u64, u32, bool, f32);
// 0x7100418790
void Unk_418790_call(void* /*unused*/, u32 value, bool arg2, f32 a) {
    Unk_43a5b0(reinterpret_cast<u64>(s_pSinglePostEffect), value, arg2, a);
}

void Unk_43a670(u64, u32, f32);
// 0x71004187a0
void Unk_4187a0_call(void* /*unused*/, u32 value, f32 a) {
    Unk_43a670(reinterpret_cast<u64>(s_pSinglePostEffect), value, a);
}

void Unk_43a760(u64, u32, f32);
// 0x71004187b0
void Unk_4187b0_call(void* /*unused*/, u32 value, f32 a) {
    Unk_43a760(reinterpret_cast<u64>(s_pSinglePostEffect), value, a);
}

void Unk_43a6e0(u64, u32, f32, f32, f32);
// 0x71004187c0
void Unk_4187c0_call(void* /*unused*/, u32 value, f32 a, f32 b, f32 c) {
    Unk_43a6e0(reinterpret_cast<u64>(s_pSinglePostEffect), value, a, b, c);
}

void Unk_43a610(u64, u32, f32);
// 0x71004187d0
void Unk_4187d0_call(void* /*unused*/, u32 value, f32 a) {
    Unk_43a610(reinterpret_cast<u64>(s_pSinglePostEffect), value, a);
}

void Unk_43a7e0(u64, u32, f32, f32, f32, f32);
// 0x71004187e0
void Unk_4187e0_call(void* /*unused*/, u32 value, f32 a, f32 b, f32 c, f32 d) {
    Unk_43a7e0(reinterpret_cast<u64>(s_pSinglePostEffect), value, a, b, c, d);
}

void Unk_43a840(u64, u32, f32);
// 0x71004187f0
void Unk_4187f0_call(void* /*unused*/, u32 value, f32 a) {
    Unk_43a840(reinterpret_cast<u64>(s_pSinglePostEffect), value, a);
}

s32 Unk_43ad10(u64, s32, bool, const Unk_410f90*, f32, f32);
// 0x7100418800: a colour matrix times a white balance (GPUPostEffect.cpp)
void Unk_418800_call(void* /*unused*/, s32 index, bool planck, const Unk_410f90* space, f32 temperature,
                     f32 luminance) {
    Unk_43ad10(reinterpret_cast<u64>(s_pSinglePostEffect), index, planck, space, temperature, luminance);
}

s32 Unk_43af30(u64, s32, bool, const Unk_410f90*, f32, f32);
// 0x7100418810: the same inverted
void Unk_418810_call(void* /*unused*/, s32 index, bool planck, const Unk_410f90* space, f32 temperature,
                     f32 luminance) {
    Unk_43af30(reinterpret_cast<u64>(s_pSinglePostEffect), index, planck, space, temperature, luminance);
}

void Unk_43a460(u64, u32, f32);
// 0x7100418820
void Unk_418820_call(void* /*unused*/, u32 value, f32 a) {
    Unk_43a460(reinterpret_cast<u64>(s_pSinglePostEffect), value, a);
}

void Unk_43a530(u64, u32, f32);
// 0x7100418830
void Unk_418830_call(void* /*unused*/, u32 value, f32 a) {
    Unk_43a530(reinterpret_cast<u64>(s_pSinglePostEffect), value, a);
}

void Unk_43b920(u64, u32);
// 0x7100418b70
void Unk_418b70_call(u64 self, u32 value) {
    Unk_43b920(self, value);
}

// 0x7100418b80
void Unk_418b80(void*, u64 value) {
    Unk_43b9b0_update(reinterpret_cast<Unk_43b9b0*>(s_pSinglePostEffect), value);
}

void Unk_43b9d0(u64, u64, u64, u64, u64);
// 0x7100418b90
void Unk_418b90_call(void* /*unused*/, u64 value, u64 arg2) {
    Unk_43b9d0(reinterpret_cast<u64>(s_pSinglePostEffect), value, arg2, 0, 0);
}

void Unk_43bb50(u64, u64, u64, u64, u64);
// 0x7100418bb0
void Unk_418bb0_call(void* /*unused*/, u64 value, u64 arg2) {
    Unk_43bb50(reinterpret_cast<u64>(s_pSinglePostEffect), value, arg2, 0, 0);
}

// 0x7100418e20
u64 Unk_418e20_get() {
    return reinterpret_cast<u64>(s_pSinglePostEffect);
}

// 0x7100418e30, 0x7100418e40, 0x7100418e50: three of the post effect's parts
void* Unk_418e30() {
    return s_pSinglePostEffect->field_190;
}

void* Unk_418e40() {
    return s_pSinglePostEffect->field_198;
}

void* Unk_418e50() {
    return s_pSinglePostEffect->field_1a0;
}

// 0x7100562f10: a texture format as SiGfx numbers it
u32 Unk_562f10(u32 format);
// The post effect's functions the next five call, with the format converted.
s32 Unk_43bde0(PPFX::CPostEffect* self, u64 arg1, u64 arg2, u32 arg3, u32 arg4, u32 format, u32 arg6, u32 arg7);
s32 Unk_43bec0(PPFX::CPostEffect* self, u64 arg1, u64 arg2, u32 arg3, u32 arg4, u32 format);
s32 Unk_43bf90(PPFX::CPostEffect* self, u32 arg1, u64 arg2, u64 arg3, u32 arg4, u32 arg5, u32 format, u32 arg7, f32 a,
               f32 b);
s32 Unk_43c020(PPFX::CPostEffect* self, u32 arg1, u64 arg2, u64 arg3, u32 arg4, u32 arg5, u32 format);
s32 Unk_43c090(PPFX::CPostEffect* self, u32 arg1, u64 arg2, u64 arg3, u32 arg4, u32 arg5, u32 format);

// 0x7100418bd0
s32 Unk_418bd0(void*, u64 arg1, u64 arg2, u32 arg3, u32 arg4, u32 format, u32 arg6, u32 arg7) {
    return Unk_43bde0(s_pSinglePostEffect, arg1, arg2, arg3, arg4, Unk_562f10(format), arg6, arg7);
}

// 0x7100418c50
s32 Unk_418c50(void*, u64 arg1, u64 arg2, u32 arg3, u32 arg4, u32 format) {
    return Unk_43bec0(s_pSinglePostEffect, arg1, arg2, arg3, arg4, Unk_562f10(format));
}

// 0x7100418cb0
s32 Unk_418cb0(void*, u32 arg1, u64 arg2, u64 arg3, u32 arg4, u32 arg5, u32 format, u32 arg7, f32 a, f32 b) {
    return Unk_43bf90(s_pSinglePostEffect, arg1, arg2, arg3, arg4, arg5, Unk_562f10(format), arg7, a, b);
}

// 0x7100418d40
s32 Unk_418d40(void*, u32 arg1, u64 arg2, u64 arg3, u32 arg4, u32 arg5, u32 format) {
    return Unk_43c020(s_pSinglePostEffect, arg1, arg2, arg3, arg4, arg5, Unk_562f10(format));
}

// 0x7100418db0
s32 Unk_418db0(void*, u32 arg1, u64 arg2, u64 arg3, u32 arg4, u32 arg5, u32 format) {
    return Unk_43c090(s_pSinglePostEffect, arg1, arg2, arg3, arg4, arg5, Unk_562f10(format));
}
