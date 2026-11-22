// Scope: common
// PPFX::IGPUTexture (C:/workspace/YEBIS_draft/src/GPU/GPUInterfaceTexture.cpp, the __FILE__ of its log lines).
#include <yebis/YEBIS_draft/src/GPU/Unk_Statics.h>
#include <yebis/YEBIS_draft/src/GPU/GPUInterfaceTexture.h>

// 0x710238c3f9
extern bool Unk_238c3f9;

// 0x7100445370: a texture's surface for a level
PPFX::IGPUSurface* Unk_445370(PPFX::IGPUDevice* device, PPFX::IGPUBaseTexture* texture, u32 level, u32 arg3, u32 usage);

namespace PPFX {

u32 Unk_446a90(u32 size, u32 level);
u32 Unk_446ae0(s32 format);
s32 Unk_43e620(IGPUDevice* self, s32 n);

// 0x71004472c0: what the texture is of goes before its last reference
s32 IGPUBaseTexture::vf1() {
    if (field_8 == 1) {
        vf11();
    }
    return IGPUInterface::vf1();
}

// 0x7100447300
u32 IGPUBaseTexture::vf12() {
    return field_80;
}

// 0x7100447310
void IGPUBaseTexture::vf13() {}

// 0x7100447640
s32 IGPUBaseTexture::vf5(void* a1, bool a2) {
    return IGPUPixelContainer::vf5(a1, a2);
}

// 0x7100447650
s32 IGPUBaseTexture::vf14() {
    field_7c = -1;
    return 0;
}

// 0x7100447660
s32 IGPUBaseTexture::vf15(u32 state) {
    if (state > 15) {
        return -6;
    }
    field_78 = state;
    return 0;
}

// 0x7100447680
u32 IGPUBaseTexture::vf16() {
    return field_78;
}

// 0x7100447690
s32 IGPUBaseTexture::vf17(u32 value) {
    if (value > 3) {
        return -6;
    }
    return vf15((field_78 & ~3u) | value);
}

// 0x71004476c0
u32 IGPUBaseTexture::vf19() {
    return field_78 & 3;
}

// 0x71004476d0
s32 IGPUBaseTexture::vf18(u32 value) {
    if (value > 3) {
        return -6;
    }
    return vf15((field_78 & ~0xcu) | (value << 2));
}

// 0x7100447700
u32 IGPUBaseTexture::vf20() {
    return (field_78 >> 2) & 3;
}

// 0x7100447710: takes a sampler state (-1: the one that is set) as the one
// applied; with check, tells whether it already was (1)
s32 IGPUBaseTexture::vf21(s32 state, bool check) {
    if (state == -1) {
        state = field_78;
    }
    if (static_cast<u32>(state) > 15) {
        return -6;
    }
    if (!Unk_238c3f9) {
        field_78 = state;
        field_7c = -1;
        return 0;
    }
    if (check) {
        s32 applied = field_7c;
        field_78 = state;
        if (state == applied) {
            return 1;
        }
    } else {
        field_78 = state;
    }
    field_7c = state;
    return 0;
}

// 0x7100447970, 0x7100447a10 (deleting): gives back the memory the device
// counts for each level
IGPUTexture::~IGPUTexture() {
    if (field_20) {
        u32 levels = field_80;
        field_20 = false;
        for (u32 i = 0; i < levels; i++) {
            u32 width = Unk_446a90(field_44.field_8, i);
            u32 height = Unk_446a90(field_44.field_c, i);
            Unk_43e620(field_18, Unk_446ae0(field_44.field_0) * width * height);
        }
    }
}

// 0x7100447ac0: makes a surface for each level
s32 IGPUTexture::vf10() {
    u32 levels = vf12();
    if (levels == 0) {
        return -3;
    }
#line 2086
    field_88 = UNK_NEW_ARRAY(IGPUSurface*, levels);
    for (u32 i = 0; i < levels; i++) {
        field_88[i] = Unk_445370(field_18, this, i, 0, field_24);
    }
    return 0;
}

// 0x7100447cf0
s32 IGPUTexture::vf24(u32 level, IGPUPixelContainer::Unk_Desc* pDesc) {
    if (level >= field_80) {
        return -6;
    }
    field_88[level]->vf8(pDesc);
    return 0;
}

// 0x7100447d30
s32 IGPUTexture::vf23(u32 level, IGPUSurface** ppSurface) {
    if (level >= field_80) {
        return -6;
    }
    *ppSurface = field_88[level];
    (*ppSurface)->vf0();
    return 0;
}

// 0x7100448530, 0x71004485d0 (deleting)
IGPUVolumeTexture::~IGPUVolumeTexture() {
    if (field_20) {
        u32 levels = field_80;
        field_20 = false;
        for (u32 i = 0; i < levels; i++) {
            u32 width = Unk_446a90(field_44.field_8, i);
            u32 height = Unk_446a90(field_44.field_c, i);
            Unk_43e620(field_18, Unk_446ae0(field_44.field_0) * width * height);
        }
    }
}

// 0x7100448680
s32 IGPUVolumeTexture::vf10() {
    return -4;
}

// 0x7100448690
s32 IGPUVolumeTexture::vf11() {
    return 0;
}

}  // namespace PPFX

// 0x7100448900: _GLOBAL__sub_I_GPUInterfaceTexture.cpp
