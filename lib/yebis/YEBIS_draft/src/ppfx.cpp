// Scope: common
// YEBIS's interface functions (C:/workspace/YEBIS_draft/src/ppfx.cpp is the
// __FILE__ of this translation unit's log lines): most of them hand their
// arguments to the one PPFX::CPostEffect there is, without the context they
// are called with. lib/yebis/leaf/Unk_4182e0.cpp has the ones leafgen wrote;
// these are the others of that shape. Placeholder names.
#include <stdarg.h>
#include <stdio.h>

#include <yebis/YEBIS_draft/src/GPU/GPUPostEffect.h>
#include <yebis/YEBIS_draft/src/GPU/Unk_Array.h>
#include <yebis/YEBIS_draft/src/GPU/GPUInterface.h>
#include <yebis/YEBIS_draft/src/Unk_4b9860.h>

#define PPFX_FILE "C:/workspace/YEBIS_draft/src/ppfx.cpp"
#include <yebis/YEBIS_draft/src/GPU/Unk_Log.h>

// 0x71024e00e0: the post effect ("s_pSinglePostEffect" in the log lines)
extern PPFX::CPostEffect* Unk_24e00e0 __attribute__((visibility("hidden")));

// 0x71024e00e8, 0x71024e00f0: two objects the context releases with it
extern PPFX::IGPUInterface* Unk_24e00e8 __attribute__((visibility("hidden")));
extern PPFX::IGPUInterface* Unk_24e00f0 __attribute__((visibility("hidden")));

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

// What an interface holds; a null pointer stays one (inline in the functions
// that take an interface, which read it before they read the post effect).
static inline u64 Unk_Held(const void* object) {
    if (object != nullptr) {
        object = *reinterpret_cast<const void* const*>(Unk_4b9850_get(static_cast<const Unk_4b9850*>(object)));
    }
    return reinterpret_cast<u64>(object);
}

// 0x71024e00f8: what the log hands its lines to (printf without one), and
// 0x71024e01b8 the line: two statics of this file, merged into one object
struct Unk_24e00f8_Statics {
    void (*field_0)(const char* text);
    u8 pad_8[0xb8];
    char field_c0[0x800];
};
extern Unk_24e00f8_Statics Unk_24e00f8 __attribute__((visibility("hidden")));

// 0x7100417a30: printf to the log
s32 Unk_417a30(const char* format, ...) {
    va_list args;
    va_start(args, format);
    s32 length = vsnprintf(Unk_24e00f8.field_c0, sizeof(Unk_24e00f8.field_c0), format, args);
    va_end(args);
    if (Unk_24e00f8.field_0 != nullptr) {
        Unk_24e00f8.field_0(Unk_24e00f8.field_c0);
    } else {
        printf(Unk_24e00f8.field_c0);
    }
    return length;
}

// 0x71004180d0: IPfxBaseContext::Uninitialize (its log lines name it)
s32 Unk_4180d0(u64 self) {
    UNK_PPFX_INFO("==== IPfxBaseContext::Uninitialize() ====\n");
#line 1185
    PPFX_LOG("==== IPfxBaseContext::Uninitialize() ====\n");
    if (Unk_24e00e0 != nullptr) {
        PPFX_SAFE_RELEASE_INTERFACE(Unk_24e00e8);
        PPFX_SAFE_RELEASE_INTERFACE(Unk_24e00f0);
        s32 result = Unk_24e00e0->Unk_419690(nullptr);
        if (result < 0) {
#line 1227
            PPFX_ERROR("IPfxBaseContext::Uninitialize(): s_pSinglePostEffect->Uninitialize() failed (0x%x: %s).\n", result,
                       Unk_446df0(result));
            return result;
        }
#line 1232
        PPFX_LOG("IPfxBaseContext::Uninitialize(): s_pSinglePostEffect->Uninitialize() succeeded.\n");
        UNK_DELETE(Unk_24e00e0);
        *reinterpret_cast<void**>(const_cast<u8*>(Unk_4b9840_get(reinterpret_cast<const Unk_4b9840*>(self)))) = nullptr;
    }
#line 1246
    PPFX_LOG("==== IPfxBaseContext::Uninitialize() succeeded. ====\n");
    UNK_PPFX_INFO("==== IPfxBaseContext::Uninitialize() succeeded. ====\n");
    return 0;
}

// 0x7100418310
s32 Unk_418310(u64, f32 elapsed) {
    return Unk_424670(Unk_24e00e0, elapsed);
}

// 0x7100418330
void Unk_418330(void*, u32 value) {
    Unk_424490_update(reinterpret_cast<Unk_424490*>(Unk_24e00e0), value);
}

// 0x71004183a0
void Unk_4183a0(void*, bool enable) {
    Unk_24e00e0->Unk_423630(enable);
}

// 0x7100418460
void Unk_418460(void*, f32 a, f32 b, f32 c) {
    Unk_423eb0_update(reinterpret_cast<Unk_423eb0*>(Unk_24e00e0), a, b, c);
}

// 0x71004184c0
void Unk_4184c0(void*, f32 a, f32 b) {
    Unk_427a60_update(reinterpret_cast<Unk_427a60*>(Unk_24e00e0), a, b);
}

// 0x71004184d0
void Unk_4184d0(void*, f32 a, f32 b, f32 c, f32 d, f32 e) {
    Unk_427a80_update(reinterpret_cast<Unk_427a80*>(Unk_24e00e0), a, b, c, d, e);
}

// 0x71004184e0
void Unk_4184e0(void*, u32 index, f32 value) {
    Unk_427ab0_update(reinterpret_cast<Unk_427ab0*>(Unk_24e00e0), index, value);
}

// 0x71004184f0
void Unk_4184f0(void*, f32 a, f32 b) {
    Unk_427ac0_update(reinterpret_cast<Unk_427ac0*>(Unk_24e00e0), a, b);
}

// 0x7100418500
void Unk_418500(void*, u32 arg1, const Unk_423950_arg3* arg2, const Unk_423950_arg4* arg3,
                const Unk_423950_arg5* arg4, bool arg5) {
    Unk_423950_update(reinterpret_cast<Unk_423950*>(Unk_24e00e0), arg1, false, arg2, arg3, arg4, arg5);
}

// 0x7100418590
void Unk_418590(void*, u32 value) {
    Unk_423da0_update(reinterpret_cast<Unk_423da0*>(Unk_24e00e0), value);
}

// 0x71004185e0
void Unk_4185e0(void*, const void* object) {
    u64 held = Unk_Held(object);
    Unk_43a0e0_update(reinterpret_cast<Unk_43a0e0*>(Unk_24e00e0), held);
}

// 0x7100418610
void Unk_418610(void*, const void* object) {
    u64 held = Unk_Held(object);
    Unk_423ed0_update(reinterpret_cast<Unk_423ed0*>(Unk_24e00e0), held, 0);
}

// 0x7100418640
void Unk_418640(void*, u32 arg1, const void* object, u32 arg3, f32 a, f32 b) {
    u64 held = Unk_Held(object);
    Unk_425410(Unk_24e00e0, arg1, held, 0, arg3, a, b);
}

// 0x71004186a0
void Unk_4186a0(void*, u32 arg1, const void* object) {
    u64 held = Unk_Held(object);
    Unk_423ee0(Unk_24e00e0, arg1, held);
}

// 0x71004186f0
void Unk_4186f0(void*, u32 value) {
    Unk_423b90_update(reinterpret_cast<Unk_423b90*>(Unk_24e00e0), value);
}

// 0x7100418700
void Unk_418700(void*, const PPFX::Unk_GlareRect* arg, f32 a, f32 b, f32 c, f32 d, f32 e) {
    Unk_423b80_call(reinterpret_cast<const Unk_423b80*>(Unk_24e00e0), arg, a, b, c, d, e);
}

// 0x7100418730
void Unk_418730(void*, u32 arg1, const void* object) {
    u64 held = Unk_Held(object);
    Unk_423ff0(Unk_24e00e0, arg1, held);
}

// 0x7100418b80
void Unk_418b80(void*, u64 value) {
    Unk_43b9b0_update(reinterpret_cast<Unk_43b9b0*>(Unk_24e00e0), value);
}

// 0x7100418e30, 0x7100418e40, 0x7100418e50: three of the post effect's parts
void* Unk_418e30() {
    return Unk_24e00e0->field_190;
}

void* Unk_418e40() {
    return Unk_24e00e0->field_198;
}

void* Unk_418e50() {
    return Unk_24e00e0->field_1a0;
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
    return Unk_43bde0(Unk_24e00e0, arg1, arg2, arg3, arg4, Unk_562f10(format), arg6, arg7);
}

// 0x7100418c50
s32 Unk_418c50(void*, u64 arg1, u64 arg2, u32 arg3, u32 arg4, u32 format) {
    return Unk_43bec0(Unk_24e00e0, arg1, arg2, arg3, arg4, Unk_562f10(format));
}

// 0x7100418cb0
s32 Unk_418cb0(void*, u32 arg1, u64 arg2, u64 arg3, u32 arg4, u32 arg5, u32 format, u32 arg7, f32 a, f32 b) {
    return Unk_43bf90(Unk_24e00e0, arg1, arg2, arg3, arg4, arg5, Unk_562f10(format), arg7, a, b);
}

// 0x7100418d40
s32 Unk_418d40(void*, u32 arg1, u64 arg2, u64 arg3, u32 arg4, u32 arg5, u32 format) {
    return Unk_43c020(Unk_24e00e0, arg1, arg2, arg3, arg4, arg5, Unk_562f10(format));
}

// 0x7100418db0
s32 Unk_418db0(void*, u32 arg1, u64 arg2, u64 arg3, u32 arg4, u32 arg5, u32 format) {
    return Unk_43c090(Unk_24e00e0, arg1, arg2, arg3, arg4, arg5, Unk_562f10(format));
}

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
    if (Unk_24e00e0 != nullptr) {
        PPFX_SAFE_RELEASE_INTERFACE(Unk_24e00e8);
        PPFX_SAFE_RELEASE_INTERFACE(Unk_24e00f0);
        s32 result = Unk_24e00e0->Unk_419690(nullptr);
        if (result < 0) {
#line 729
            PPFX_ERROR("IPfxBaseContext::~IPfxBaseContext(): s_pSinglePostEffect->Uninitialize() failed (0x%x: %s).\n",
                       result, Unk_446df0(result));
        } else {
#line 734
            PPFX_LOG("IPfxBaseContext::~IPfxBaseContext(): s_pSinglePostEffect->Uninitialize() succeeded.\n");
        }
        UNK_DELETE(Unk_24e00e0);
        *const_cast<u64*>(reinterpret_cast<const u64*>(Unk_4b9840_get(reinterpret_cast<const Unk_4b9840*>(this)))) = 0;
        if (result < 0) {
            return;
        }
    }
#line 744
    PPFX_LOG("==== IPfxBaseContext::~IPfxBaseContext() succeeded. ====\n");
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
