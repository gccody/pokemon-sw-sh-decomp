// PPFX::IGPUResource, what the device's surfaces, textures, buffers and
// effects are, and PPFX::IGPUPixelContainer, the surfaces' and textures'
// base (RTTI names the classes; members are placeholders, virtual functions
// are vf<slot>).
#pragma once

#include <vector>

#include <yebis/YEBIS_draft/src/GPU/GPUInterface.h>
#include <yebis/YEBIS_draft/src/GPU/GPUMemoryAllocator.h>

namespace PPFX {

class IGPUDevice;
struct Unk_SiGfxInterface;

class IGPUResource : public IGPUInterface {
public:
    // the device's list of its resources
    typedef std::vector<IGPUResource*, Unk_StlAllocator<IGPUResource*>> Unk_List;

    explicit IGPUResource(IGPUDevice* pDevice);  // 0x7100446330
    ~IGPUResource() override;                    // 0x7100446440, 0x7100446530
    virtual u32 vf4();                           // 0x7100446680: what it is, as flags
    virtual s32 vf5(void* a1, bool a2);          // 0x7100446660
    virtual s32 vf6();                           // 0x7100446670

    u32 field_c;   // the kind: 1 a pixel container, 3 and 4 buffers
    s32 field_10;
    IGPUDevice* field_18;
    bool field_20;
    bool field_21;
    u32 field_24;  // usage flags
    u32 field_28;
    bool* field_30;  // one for each frame slot
    Unk_SiGfxInterface* field_38;
    bool field_40;
};
PKMN_SIZE_ASSERT(IGPUResource, 0x48);
PKMN_OFFSET_ASSERT(IGPUResource, field_c, 0xc);

class IGPUPixelContainer : public IGPUResource {
public:
    // what vf8 gives: the format, the kind (3: one that can't be locked at a
    // level), the size
    struct Unk_Desc {
        s32 field_0;
        s32 field_4;
        u32 field_8;
        u32 field_c;
        u32 field_10;
        u32 field_14;
    };

    explicit IGPUPixelContainer(IGPUDevice* pDevice);  // 0x7100445f10
    ~IGPUPixelContainer() override;                    // 0x7100445f60, 0x7100445f70
    u32 vf4() override { return IGPUResource::vf4(); }  // 0x7100445fc0
    s32 vf5(void* a1, bool a2) override;                // 0x7100446060
    s32 vf6() override;                                 // 0x71004460a0
    virtual s32 vf7(void* a1, u32 a2, u32 a3, bool a4);  // 0x7100445fd0
    virtual s32 vf8(Unk_Desc* pDesc);                    // 0x7100446030
    virtual s32 vf9(void* a1, u32 a2, u32 a3, bool a4) = 0;

    // 0x7100445f80
    void Unk_445f80();

    Unk_Desc field_44;
    u32 field_5c;
    u64 field_60;
    u64 field_68;
};
PKMN_OFFSET_ASSERT(IGPUPixelContainer, field_44, 0x44);
PKMN_OFFSET_ASSERT(IGPUPixelContainer, field_68, 0x68);

}  // namespace PPFX
