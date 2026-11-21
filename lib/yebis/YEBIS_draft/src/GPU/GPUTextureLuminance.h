// PPFX::CTextureLuminance and PPFX::CTextureLuminanceManage (RTTI;
// C:/workspace/YEBIS_draft/src/GPU/GPUTextureLuminance.cpp is the __FILE__ of
// their allocations): the scene's luminance, measured through a chain of
// render textures, and its history of 17 frames. Placeholder members.
#pragma once

#include <yebis/YEBIS_draft/src/GPU/GPURenderTexture.h>

namespace PPFX {

class CTextureLuminance : public CGPUResourceManage {
public:
    explicit CTextureLuminance(const char* name) : CGPUResourceManage(nullptr) { Unk_4b75a0(name); }
    s32 vf0(IGPUDevice* device) override;  // 0x71004b7a30
    s32 vf1() override;                    // 0x71004b7ac0
    s32 vf2() override;                    // 0x71004b7b60
    s32 vf3() override;                    // 0x71004b7b90
    ~CTextureLuminance() override;         // 0x71004b79b0, 0x71004b79f0

    s32 Unk_4b75a0(const char* name);  // 0x71004b75a0
    // 0x71004b7670
    s32 Unk_4b7670(CRenderTexture* target, s32 format, s32 arg2);
    // 0x71004b8240
    s32 Unk_4b8240(CGPUBaseResourceManage* target, bool flag);
    // (re)creates it for a target (inline in the manager)
    s32 Unk_Create(CRenderTexture* target, s32 count, s32 format) {
        IGPUDevice* device = field_20;
        Unk_49ec80();
        field_38 = count;
        s32 result = Unk_4b7670(target, format, 0);
        if (result < 0)
            return result;
        return Unk_49ec30(device);
    }

    // what the name setter and vf3 leave (inline)
    void Unk_Reset() {
        field_88 = 0;
        field_60 = 0;
        field_94 = 0;
        field_30 = nullptr;
        field_38 = 0;
        field_3c = 0;
        field_74 = 0.0f;
        field_78 = nullptr;
        field_80 = 0;
        field_98 = 2;
        field_9c = 0;
        field_50 = nullptr;
        field_58 = nullptr;
        field_40 = nullptr;
        field_48 = nullptr;
    }

    u32 _2c;
    CRenderTexture* field_30;
    s32 field_38;
    s32 field_3c;  // how many of the four objects it uses
    Unk_49b230_Object* field_40;
    Unk_49b230_Object* field_48;
    Unk_49b230_Object* field_50;
    Unk_49b230_Object* field_58;
    s32 field_60;
    u8 _64[0x10];
    f32 field_74;
    CRenderTexture** field_78;  // textures of the pool
    s32 field_80;
    u64 field_88;
    u32 _90;
    s32 field_94;
    s32 field_98;
    s32 field_9c;
};
PKMN_OFFSET_ASSERT(CTextureLuminance, field_30, 0x30);
PKMN_OFFSET_ASSERT(CTextureLuminance, field_78, 0x78);
PKMN_SIZE_ASSERT(CTextureLuminance, 0xa0);

class CTextureLuminanceManage : public CGPUResourceManage {
public:
    // 0x10 bytes, aligned to 4: what it is made from
    struct Unk_Desc {
        s32 field_0;
        s32 field_4;
        s32 field_8;
        s32 field_c;
    };
    // a frame's 16 bytes
    struct Unk_Value {
        Unk_Value() {}
        Unk_Value(f32 x, f32 y, f32 z, f32 w) {
            field_0[0] = x;
            field_0[1] = y;
            field_0[2] = z;
            field_0[3] = w;
        }

        f32 field_0[4];
    };

    explicit CTextureLuminanceManage(const char* name);  // 0x71004b86d0
    s32 vf0(IGPUDevice* device) override;                // 0x71004b92a0
    s32 vf1() override;                                  // 0x71004b9380
    s32 vf2() override;                                  // 0x71004b93c0
    s32 vf3() override;                                  // 0x71004b9410
    ~CTextureLuminanceManage() override;                 // 0x71004b9220, 0x71004b9260

    s32 Unk_4b8710(const char* name);    // 0x71004b8710
    s32 Unk_4b87d0(const Unk_Desc* desc);  // 0x71004b87d0: (re)creates it
    s32 Unk_4b8830();                    // 0x71004b8830
    s32 Unk_4b89b0();                    // 0x71004b89b0
    // 0x71004b8a40
    s32 Unk_4b8a40(bool flag, f32 a, f32 b, f32 c, f32 d);
    // 0x71004b9140: every frame of the history gets the same values
    s32 Unk_4b9140(const Unk_Value* value, bool flag, f32 a, f32 b, f32 c, f32 d, f32 e);

    // every frame of the history gets these values (inline, by value: vf0's are constants)
    void Unk_Reset(Unk_Value value, f32 a, f32 b, f32 c, f32 d, f32 e) {
        f32 ratio = a;
        if (field_2c.field_0 != 1)
            ratio = a / b;
        field_5c = ratio;
        field_60 = a;
        field_64 = value;
        for (s32 i = 0; i < 17; i++) {
            field_74[i] = 1;
            field_20c[i] = ratio;
            field_1c8[i] = a;
            field_b8[i] = value;
            field_3a4[i] = ratio;
            field_360[i] = a;
            field_250[i] = value;
            field_3e8[i] = b;
            field_42c[i] = c;
            field_470[i] = d;
            field_4b4[i] = e;
        }
    }

    Unk_Desc field_2c;
    CTextureLuminance* field_40;
    CRenderTexture* field_48;
    s32 field_50;  // the frame's number
    bool field_54;
    s32 field_58;
    f32 field_5c;
    f32 field_60;
    Unk_Value field_64;
    s32 field_74[17];
    Unk_Value field_b8[17];
    f32 field_1c8[17];
    f32 field_20c[17];
    Unk_Value field_250[17];
    f32 field_360[17];
    f32 field_3a4[17];
    f32 field_3e8[17];
    f32 field_42c[17];
    f32 field_470[17];
    f32 field_4b4[17];
    s32 field_4f8;
    f32 field_4fc;
    s32 field_500;
};
PKMN_OFFSET_ASSERT(CTextureLuminanceManage, field_40, 0x40);
PKMN_OFFSET_ASSERT(CTextureLuminanceManage, field_74, 0x74);
PKMN_OFFSET_ASSERT(CTextureLuminanceManage, field_250, 0x250);
PKMN_OFFSET_ASSERT(CTextureLuminanceManage, field_4f8, 0x4f8);

}  // namespace PPFX
