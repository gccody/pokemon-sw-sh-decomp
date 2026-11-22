// Scope: common
// PPFX::IPfxBaseRenderToTexture (RTTI; C:/workspace/YEBIS_draft/src/ppfxRenderToTexture.cpp
// is the __FILE__ of its log lines, which name Initialize and Uninitialize).
// The TU's statics are the ones every src/GPU TU has (Unk_Statics.h), which
// its static initialiser, 0x71004ba330 (_GLOBAL__sub_I_ppfxRenderToTexture.cpp),
// sets up.
#include <yebis/YEBIS_draft/src/GPU/GPUResourceManage.h>
#include <yebis/YEBIS_draft/src/GPU/Unk_Statics.h>
#include <yebis/YEBIS_draft/src/Unk_4b9860.h>

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

// 0x71004b9840 (lib/yebis/leaf): what an interface holds at 0x10
struct Unk_4b9840;
const u8* Unk_4b9840_get(const Unk_4b9840* self);

namespace PPFX {

class IPfxBaseRenderToTexture : public IPfxInterface {
public:
    IPfxBaseRenderToTexture() : field_18(nullptr) {}
    ~IPfxBaseRenderToTexture() override;  // 0x71004b9b60, 0x71004b9cd0
    virtual s32 vf6();           // 0x71004b9d00
    virtual s32 Uninitialize();  // 0x71004ba140

    // 0x71004ba020
    s32 Initialize(void* context, CGPUBaseResourceManage* util);

    // what the interface holds (field_10), and what its context does
    CGPUBaseResourceManage** Unk_Util() {
        return reinterpret_cast<CGPUBaseResourceManage**>(
            const_cast<u8*>(Unk_4b9840_get(reinterpret_cast<const Unk_4b9840*>(this))));
    }

    void* field_18;  // the context
};
PKMN_SIZE_ASSERT(IPfxBaseRenderToTexture, 0x20);

// RTTI: PPFX::IPfxRenderToTexture_Nvn. Its deleting destructor is 0x71004ba2a0.
class IPfxRenderToTexture_Nvn : public IPfxBaseRenderToTexture {
public:
    ~IPfxRenderToTexture_Nvn() override {}
};

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
