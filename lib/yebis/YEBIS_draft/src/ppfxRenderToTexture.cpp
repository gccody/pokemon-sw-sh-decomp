// Scope: common
// PPFX::IPfxBaseRenderToTexture (RTTI; C:/workspace/YEBIS_draft/src/ppfxRenderToTexture.cpp
// is the __FILE__ of its log lines, which name Initialize and Uninitialize).
// The TU's statics are the ones every src/GPU TU has (Unk_Statics.h), which
// its static initialiser, 0x71004ba330 (_GLOBAL__sub_I_ppfxRenderToTexture.cpp),
// sets up.
#include <yebis/YEBIS_draft/src/GPU/GPURenderTexture.h>
#include <yebis/YEBIS_draft/src/GPU/GPUResourceManage.h>
#include <yebis/YEBIS_draft/src/GPU/Unk_Statics.h>
#include <yebis/YEBIS_draft/src/Unk_4b9860.h>
#include <yebis/YEBIS_draft/src/ppfxRenderToTexture.h>

// log switches: PPFX_LOG's and PPFX_ERROR's
extern s32 Unk_24e0008;
extern s32 Unk_238c1e8;

#define UNK_LOG(...)                                                                             \
    do {                                                                                         \
        if (Unk_238c1e0 != 0 && Unk_24e0008 != 0) {                                              \
            Unk_417a30("C:/workspace/YEBIS_draft/src/ppfxRenderToTexture.cpp(%d) : PPFX: ", __LINE__); \
            Unk_417a30(__VA_ARGS__);                                                             \
        }                                                                                        \
    } while (0)
#define UNK_ERROR(...)                                                                                 \
    do {                                                                                               \
        if (Unk_238c1e0 != 0 && Unk_238c1e8 != 0) {                                                    \
            Unk_417a30("C:/workspace/YEBIS_draft/src/ppfxRenderToTexture.cpp(%d) : PPFX ERROR: ", __LINE__); \
            Unk_417a30(__VA_ARGS__);                                                                   \
        }                                                                                              \
    } while (0)
#define UNK_RELEASE_COUNTED(object)  \
    do {                             \
        if ((object) != nullptr) {   \
            (object)->Unk_Release(); \
            (object) = nullptr;      \
        }                            \
    } while (0)

namespace PPFX {

// 0x71004b9b60
IPfxBaseRenderToTexture::~IPfxBaseRenderToTexture() {
#line 58
    UNK_LOG("==== IPfxBaseRenderToTexture::~IPfxBaseRenderToTexture() ====\n");
    const u8* state = nullptr;
    if (field_18 != nullptr)
        state = *reinterpret_cast<const u8* const*>(Unk_4b9840_get(static_cast<const Unk_4b9840*>(field_18)));
    CGPUBaseResourceManage*& slot = *Unk_Util();
    if (slot != nullptr) {
        if (*state) {
#line 69
            UNK_ERROR("IPfxBaseRenderToTexture::~IPfxBaseRenderToTexture(): IPfxBaseRenderToTexture::Uninitialize() implicitly called while BeginPostEffectScene() and EndPostEffectScene().\n");
        }
        UNK_RELEASE_COUNTED(slot);
    }
#line 105
    UNK_LOG("==== IPfxBaseRenderToTexture::~IPfxBaseRenderToTexture() succeeded. ====\n");
}

// what a context holds (placeholder)
struct Unk_ContextState {
    u8 field_0;  // whether a scene is begun
    u8 _1[0x18 - 0x1];
    IGPUDevice* field_18;
};

}  // namespace PPFX

// 0x710238d258 (placeholder)
extern u8 Unk_238d258;
// 0x710049c8d0 (lib/yebis/leaf)
s32 Unk_49c8d0_call(void* self, void* value);
// 0x7100446df0: a result's name (Unk_447050.cpp)
const char* Unk_446df0(s32 result);

namespace PPFX {

// 0x7100446eb0 (Unk_447050.cpp)
s32 Unk_446eb0(s32 count, s32 quality, u32* outType, s32* outQuality);

// a render texture made from all of a description's numbers (inline: its
// description sits above the caller's locals)
static inline s32 Unk_CreateTexture(CRenderTexture* texture, s32 width, s32 height, s32 arg3, s32 format, u32 type,
                                    s32 quality, s32 arg7) {
    Unk_49ab20_Desc desc(0, width, height, format);
    desc.field_10 = arg3;
    desc.field_14 = type;
    desc.field_18 = quality;
    desc.field_1c = arg7;
    return texture->Unk_49ab20(&desc);
}

// 0x71004b9d00
s32 IPfxBaseRenderToTexture::Initialize(void* context, s32 width, s32 height, s32 arg3, s32 format, s32 samples,
                                        s32 quality, s32 arg7) {
#line 135
    UNK_LOG("==== IPfxBaseRenderToTexture::Initialize() ====\n");
    if (context == nullptr)
        return -6;
    CGPUBaseResourceManage*& slot = *Unk_Util();
    if (slot != nullptr) {
        const Unk_ContextState* state =
            *reinterpret_cast<const Unk_ContextState* const*>(Unk_4b9840_get(static_cast<const Unk_4b9840*>(context)));
        if (state->field_0) {
#line 159
            UNK_ERROR("IPfxBaseRenderToTexture::Initialize(): IPfxBaseRenderToTexture::Uninitialize() implicitly called while BeginPostEffectScene() and EndPostEffectScene().\n");
        }
        UNK_RELEASE_COUNTED(slot);
    }
#line 170
    CRenderTexture* texture = UNK_NEW(CRenderTexture)("IPfxBaseRenderToTexture");
    slot = texture;
    field_18 = context;
    IGPUDevice* device =
        (*reinterpret_cast<const Unk_ContextState* const*>(Unk_4b9840_get(static_cast<const Unk_4b9840*>(context))))
            ->field_18;
    if (device == nullptr)
        return -6;
    u32 type;
    s32 typeQuality;
    Unk_446eb0(samples, quality, &type, &typeQuality);
    s32 result = Unk_CreateTexture(static_cast<CRenderTexture*>(slot), width, height, arg3, format, type, typeQuality,
                                   arg7);
    if (result < 0) {
#line 209
        UNK_ERROR("IPfxBaseRenderToTexture::Initialize(): pRenderTexture->Initialize() failed (0x%x: %s).\n", result,
                  Unk_446df0(result));
        return result;
    }
    Unk_238d258 = 0;
    result = slot->vf0(device);
    if (result < 0) {
#line 222
        UNK_ERROR("IPfxBaseRenderToTexture::Initialize(): pRenderTexture->InitializeDevice() failed (0x%x: %s).\n",
                  result, Unk_446df0(result));
        Uninitialize();
        return result;
    }
    Unk_49c8d0_call(slot, nullptr);
#line 242
    UNK_LOG("==== IPfxBaseRenderToTexture::Initialize() succeeded. ====\n");
    return 0;
}

// 0x71004ba020
s32 IPfxBaseRenderToTexture::Initialize(void* context, CGPUBaseResourceManage* util) {
#line 251
    UNK_LOG("==== IPfxBaseRenderToTexture::Initialize() ====\n");
    if (context == nullptr)
        return -6;
    CGPUBaseResourceManage*& slot = *Unk_Util();
    UNK_RELEASE_COUNTED(slot);
    field_18 = context;
    slot = util;
    util->field_8++;
#line 269
    UNK_LOG("==== IPfxBaseRenderToTexture::Initialize() succeeded. ====\n");
    return 0;
}

// 0x71004ba140
s32 IPfxBaseRenderToTexture::Uninitialize() {
#line 276
    UNK_LOG("==== IPfxBaseRenderToTexture::Uninitialize() ====\n");
    const u8* state = nullptr;
    if (field_18 != nullptr)
        state = *reinterpret_cast<const u8* const*>(Unk_4b9840_get(static_cast<const Unk_4b9840*>(field_18)));
    CGPUBaseResourceManage*& slot = *Unk_Util();
    if (slot != nullptr) {
        if (*state) {
#line 292
            UNK_ERROR("IPfxBaseRenderToTexture::Uninitialize(): Called while BeginPostEffectScene() and EndPostEffectScene().\n");
        }
        UNK_RELEASE_COUNTED(slot);
    }
#line 347
    UNK_LOG("==== IPfxBaseRenderToTexture::Uninitialize() succeeded. ====\n");
    return 0;
}

// 0x71004ba2d0: "IPfxRenderToTexture::Instantiate()" is the name its
// allocation is made under.
IPfxRenderToTexture_Nvn* Unk_4ba2d0() {
#line 114
    return new (Unk_4b99a0(Unk_238d5f8, sizeof(IPfxRenderToTexture_Nvn), __FILE__, __LINE__,
                           const_cast<char*>("IPfxRenderToTexture::Instantiate()"))) IPfxRenderToTexture_Nvn;
}

}  // namespace PPFX
