// PPFX::CDepthOfField (RTTI; C:/workspace/YEBIS_draft/src/GPU/GPUDepthOfField.cpp
// is the __FILE__ of its allocations): the depth of field's levels and their
// render textures. Placeholder members, as far as the functions written so
// far read them.
#pragma once

#include <yebis/YEBIS_draft/src/GPU/GPURenderTexturePool.h>

namespace PPFX {

// 0x71004385e0 (GPUPostEffect.cpp's TU; placeholder signature, from its callers).
// It is an `inline` function there (a linkonce copy: its callers in that TU
// reload members after the call, no attributes are inferred for it); the
// TUs that only call it see this plain declaration. Moving its definition
// and its format helpers into a shared header would make the declarations
// agree.
bool Unk_4385e0(s32 format);

class IGPUBuffer;
class IGPUTexture;

struct Unk_462090_Params;

class CDepthOfField : public CGPUResourceManage {
public:
    // a level's render textures (0x108 bytes)
    struct Unk_Level {
        void Unk_4a7050();  // 0x71004a7050: the blur size of its kind
        s32 Unk_4a71c0(u32 flags, bool arg2, s32 arg3);  // 0x71004a71c0: resets it

        u32 field_0;  // the width
        u32 field_4;  // the height
        u32 field_8;
        u32 field_c;
        s32 field_10;  // its kind
        s32 field_14;
        s32 field_18;
        s32 field_1c;
        f32 field_20;
        f32 field_24;
        u32 field_28;
        f32 field_2c;
        f32 field_30;
        u8 _34[0x38 - 0x34];
        CRenderTexture* field_38;
        bool field_40;  // field_38 isn't the pool's
        u8 _41[0x48 - 0x41];
        CRenderTexture* field_48[3];
        s32 field_60;
        u8 _64[0x68 - 0x64];
        CRenderTexture** field_68;  // four textures
        s32 field_70;
        u8 _74[0x78 - 0x74];
        CRenderTexture** field_78;
        CRenderTexture* field_80;
        CRenderTexture* field_88;
        CRenderTexture* field_90;
        CRenderTexture* field_98;
        CRenderTexture* field_a0;
        CRenderTexture* field_a8;
        CRenderTexture* field_b0;
        CRenderTexture* field_b8;
        f32 field_c0;  // the depth's scale and bias, near side
        f32 field_c4;
        f32 field_c8;  // far side
        f32 field_cc;
        f32 field_d0;
        f32 field_d4;
        f32 field_d8;
        f32 field_dc;
        u8 _e0[0xe8 - 0xe0];
        Unk_Float2 field_e8;
        f32 field_f0;
        f32 field_f4;
        u8 _f8[0x108 - 0xf8];
    };

    // the description (Initialize copies it to field_2c and field_c0)
    struct Unk_Desc {
        Unk_Desc() {
            for (s32 i = 0; i < 14; i++) {
                field_20[i] = -1;
            }
            Unk_Reset();
        }
        // the defaults (inline in the constructor and Unk_4a7760), all but
        // field_20
        void Unk_Reset() {
            field_0[0] = 0;
            field_0[1] = 0;
            field_0[2] = 0;
            field_0[3] = 0;
            field_10 = 0;
            field_14 = 0;
            field_18 = 0;
            field_1c = -1;
            field_58 = -1;
            field_5c = 160;
            field_60 = 0.125f;
            field_64 = false;
            field_65 = false;
            field_68 = 2;
            field_6c = false;
            field_6d = false;
            field_70 = 2;
            field_74 = 0.0f;
            field_78 = 0.0f;
            field_7c = 0.75f;
            field_80 = 0.75f;
            field_84 = true;
            field_88 = 0.0f;
            field_8c = 1.0f;
            field_90 = 1.0f;
        }

        s32 field_0[4];
        s32 field_10;  // the number of levels
        s32 field_14;  // the format
        s32 field_18;
        s32 field_1c;
        s32 field_20[14];
        s32 field_58;
        s32 field_5c;
        f32 field_60;
        bool field_64;
        bool field_65;
        s32 field_68;
        bool field_6c;
        bool field_6d;
        s32 field_70;
        f32 field_74;  // the taps' aspect ratio
        f32 field_78;
        f32 field_7c;
        f32 field_80;
        bool field_84;
        f32 field_88;
        f32 field_8c;
        f32 field_90;
    };

    // what field_420 and field_428 hold (0x80 bytes)
    struct Unk_Pass {
        // a viewport of its texture (0x18 bytes)
        struct Unk_Viewport {
            u32 field_0;  // x, y, width, height
            u32 field_4;
            u32 field_8;
            u32 field_c;
            Unk_Float2 field_10;  // the depth range
        };

        u32 field_0;  // the size
        u32 field_4;
        Unk_Float2 field_8;   // the first viewport's scale and offset
        Unk_Float2 field_10;
        Unk_Float2 field_18;  // the second's
        Unk_Float2 field_20;
        Unk_Viewport field_28[2];
        Unk_Float2 field_58;  // the viewports' size and position in fractions of the size
        Unk_Float2 field_60;
        Unk_Float2 field_68;
        Unk_Float2 field_70;
        Unk_Float field_78;
        Unk_Float field_7c;
    };

    explicit CDepthOfField(const char* name);  // 0x71004a7630
    s32 Unk_4a7760(const char* name);          // 0x71004a7760: names it and resets the members
    // the members as the constructor leaves them (inline in Unk_4a7760 and vf3)
    inline void Unk_ResetMembers();

    s32 vf0(IGPUDevice* device) override;  // 0x71004aa810
    s32 vf1() override;                    // 0x71004ac220
    s32 vf2() override;                    // 0x71004ac3a0
    s32 vf3() override;                    // 0x71004ac430
    ~CDepthOfField() override;             // 0x71004aa790, 0x71004aa7d0

    // 0x71004a7390: whether a description fits the source (named by
    // Initialize's log line "ValidateInitParam() failed")
    static s32 ValidateInitParam(CRenderTexture* source, const Unk_Desc* desc);
    // 0x71004aa0d0 (its log line names it)
    s32 Initialize(CRenderTexture* source, const Unk_Desc* desc);
    s32 Unk_4a7f60();  // 0x71004a7f60: the description's defaults, the passes, the levels and their textures
    s32 Unk_4a79e0();  // 0x71004a79e0: makes the levels
    s32 CreateDeviceResources();  // 0x71004aa860 (its log lines name it): the device objects
    // 0x71004ad3d0 (its log lines name it): a scatter bokeh texture and its
    // minimum texture from an image (placeholder parameter names)
    s32 CreateScatterBokehOpticsTexture(u32 width, u32 height, const void* image, IGPUTexture** outTexture,
                                        IGPUTexture** outMinTexture, Unk_Float4* outColor, Unk_Float* outRed,
                                        f32* outPosition, f32 gamma, f32 hue, f32 saturation, f32 exponent);
    s32 Unk_4aa290(void* arg);  // 0x71004aa290: the last result of 0x710049c8d0
    // 0x71004b6fc0 (its log lines name it)
    s32 ApplyDepthOfField(CRenderTexture* source, void* arg2, CRenderTexture* target, bool arg4);
    s32 Unk_4a7dc0();                        // 0x71004a7dc0: the levels' depth ranges
    // 0x71004b4ff0: the numbers of levels with a near and a far blur, and the
    // levels' and passes' sources scaled down from `source`
    s32 Unk_4b4ff0(CRenderTexture* source);
    // 0x71004b6530: ApplyDepthOfField_Composite, the log line
    // of its caller says
    s32 Unk_4b6530(CRenderTexture* source, void* arg2, CRenderTexture* target);

    // 0x71004aee10: the last texture of the chain that is at least `width` wide
    CRenderTexture* Unk_4aee10(u32 width);
    s32 Unk_4aeed0(s32 arg0, s32 arg1, s32 arg2);  // 0x71004aeed0
    void Unk_4aef30();                             // 0x71004aef30
    f32 Unk_4afaa0(f32 arg0, f32 arg1);            // 0x71004afaa0
    // 0x71004af690: field_3bc scaled for a view (from field_3c0's and the
    // pairs' sizes)
    f32 Unk_4af690(f32 angle, f32 distance, f32 width);
    // the size of an angle at a distance (inline)
    f32 Unk_ViewSize(const f32& angle, f32 distance, f32 width) {
        if (distance > 0.0f)
            return distance * width * 0.5f / (tanf(angle * 0.5f) * distance + width * 0.5f);
        return width / (2.0f * tanf(angle * 0.5f));
    }
    // an angle's size, or the angle itself when field_3c4 says they are sizes (inline)
    f32 Unk_PairSize(const f32& angle, f32 distance, f32 width) {
        return field_3c4 ? angle : Unk_ViewSize(angle, distance, width);
    }
    // 0x71004af020: the lens's numbers from the camera's (placeholder parameter
    // names)
    s32 Unk_4af020(s32 mode, f32 fov, f32 distance, f32 width, f32 value, f32 exponent, f32 angle, f32 focus,
                   f32 a7, f32* outSize, Unk_Float* outFNumber, Unk_Float* outValue, f32* outCoc, f32* outRatio, Unk_Float4* outClip,
                   f32 limit);
    // field_3b0's rounding of a value (inline)
    f32 Unk_Quantize(f32 x) {
        f32 step = field_3b0;
        if (step <= 0.0f)
            return x;
        return exp2f(floorf(2.0f * (logf(x) / 0.6931472f) / step + 0.49999f) * step * 0.5f);
    }
    // 0x71004afc40: the camera (placeholder parameter names)
    // (the mode's position among the floats decides the order of the entry's copies)
    s32 Unk_4afc40(f32 width, f32 height, f32 tanHalfFov, f32 a3, f32 a4, f32 a5, f32 a6, f32 a7, s32 mode, f32 b0,
                   f32 b1, f32 b2, f32 b3, f32 b4, f32 width2, f32 height2);
    // 0x71004afae0: the near and far blur sizes (1 when there is no blur)
    s32 Unk_4afae0(f32* nearSize, f32* farSize);
    // 0x71004b35a0: a level's texture of one of two sets
    CRenderTexture* Unk_4b35a0(bool second, s32 index);
    bool Unk_4b5ae0();  // 0x71004b5ae0: whether there is anything to blur
    s32 Unk_4b5b40();   // 0x71004b5b40: the second kind's blurs brought back to their levels
    s32 Unk_4aa030(s32 value);  // 0x71004aa030: field_170 (negative: from the format)
    s32 Unk_4b4e10();           // 0x71004b4e10: field_238 drawn with 0x710048b1e0
    void Unk_4b0db0(bool near, bool far);  // 0x71004b0db0: the composite's constants
    // 0x71004b0650: a blur of `source` into `target` with the technique for
    // `count` taps (one less when there is none; placeholder parameter names)
    // (arg9 and arg10 are passed on to an inline that ignores them)
    s32 Unk_4b0650(s32 count, s32 mode, CRenderTexture* source, CRenderTexture* target, CRenderTexture* second,
                   const Unk_Float4* color, bool flag, bool arg9, s32 arg10, f32 a, f32 b);
    // 0x71004b19a0: a level's blur by its kind (`list`: its temporary
    // textures; placeholder parameter names)
    s32 Unk_4b19a0(s32 level, bool first, CRenderTexture* source, CRenderTexture* target, CRenderTexture** list,
                   CRenderTexture* extra, s32 mode);
    // 0x71004b1100: the taps' offsets
    s32 Unk_4b1100(bool near, bool far, s32 count, f32 angle);
    // 0x71004b35f0, 0x71004b48d0, 0x71004b4540: the passes of
    // the second kind; 0x71004b29b0, 0x71004b3280: a level's, by its kind
    s32 Unk_4b35f0(f32 scale, CRenderTexture* source, CRenderTexture* target, void* arg3, void* arg4, s32 arg5,
                   s32 arg6, void* arg7, void* arg8, Unk_Pass* arg9, Unk_Pass* arg10, bool first, bool last);
    s32 Unk_4b48d0(s32 index);
    s32 Unk_4b4540(s32 index);
    s32 Unk_4b29b0(s32 level);
    s32 Unk_4b3280(s32 level);
    s32 Unk_4b4c40();  // 0x71004b4c40: all of them
    f32 Unk_4b4ab0(bool near);  // 0x71004b4ab0: a blur scale from the tables of field_358
    // the near blur's position in field_398's table, 0 to 1 (inline in
    // 0x71004b4ab0 and 0x71004b1100)
    f32 Unk_NearPosition(bool far);
    // 0x71004afd80: mode 0's two values from a blur size, a distance and an angle
    s32 Unk_4afd80(f32 size, f32 distance, f32 angle);
    // 0x71004aff50: an RGBA8 image's columns weighted and normalised (placeholder
    // parameter names)
    s32 Unk_4aff50(u8* data, u32 width, u32 height, const f32* scale, bool merge);

    u8 _29[0x2c - 0x29];  // from the end of the base's members
    Unk_Desc field_2c;  // the description Initialize was given
    Unk_Desc field_c0;  // and the one in use
    u32 field_154;  // flags
    u32 field_158;  // the source's width
    u32 field_15c;  // and height
    s32 field_160;  // the source's format
    s32 field_164;  // and the description's
    f32 field_168;  // the source's width over the description's
    s32 field_16c;
    s32 field_170;
    bool field_174;  // the levels are drawn in their colours
    u8 _175[0x178 - 0x175];
    f32 field_178;
    s32 field_17c;
    s32 field_180;  // the number of a level's field_48
    bool field_184;  // whether the camera is usable
    f32 field_188;
    f32 field_18c;
    f32 field_190;
    f32 field_194;
    f32 field_198;  // the field of view
    f32 field_19c;  // the tangent of its half
    f32 field_1a0;
    f32 field_1a4;
    f32 field_1a8;
    Unk_Float field_1ac;
    f32 field_1b0;
    Unk_Float field_1b4;
    f32 field_1b8;
    f32 field_1bc;  // the taps' rotation
    f32 field_1c0;
    f32 field_1c4;
    s32 field_1c8;  // the mode
    Unk_Float field_1cc;
    f32 field_1d0;
    f32 field_1d4;
    f32 field_1d8;
    f32 field_1dc;
    bool field_1e0;
    u8 _1e1[0x1e4 - 0x1e1];
    f32 field_1e4;
    Unk_Float4 field_1e8;  // the depth's scale and bias, and their inverse
    s32 field_1f8[4];
    s32 field_208;  // the number of levels drawn
    s32 field_20c;  // of them, with a near blur
    s32 field_210;  // and with a far blur
    s32 field_214;  // field_20c and field_210 as the flags and limits leave them
    s32 field_218;
    s32 field_21c;
    s32 field_220;
    s32 field_224;
    CRenderTexture* field_228;  // the source
    bool field_230;
    u8 _231[0x238 - 0x231];
    Unk_GPUTexture* field_238;
    bool field_240;
    u8 _241[0x248 - 0x241];
    CRenderTexture* field_248;
    bool field_250;
    bool field_251;
    u8 _252[0x258 - 0x252];
    u64 field_258;
    Unk_GPUTexture* field_260;
    u64 field_268;
    u64 field_270;
    f32 field_278;
    f32 field_27c;
    IGPUInterface* field_280[5];
    s32 field_2a8;
    s32 field_2ac;
    f32 field_2b0;
    f32 field_2b4;
    f32 field_2b8;
    f32 field_2bc;
    s32 field_2c0;
    // field_2c0 interfaces and textures, then tables (by field_2ac)
    IGPUInterface** field_2c8;
    Unk_GPUTexture** field_2d0;
    Unk_Float4* field_2d8;
    f32* field_2e0;
    f32* field_2e8;
    s32 field_2f0;
    // four sets of tables (by field_2a8): interfaces (field_2f0 of each),
    // floats, the blur scales, the apertures' blades
    IGPUInterface** field_2f8[4];
    IGPUInterface** field_318[4];
    f32* field_338[4];
    f32* field_358[4];
    Unk_462090_Params* field_378[4];
    f32* field_398;
    IGPUInterface* field_3a0;  // the eclipse texture
    bool field_3a8;
    u8 _3a9[0x3ac - 0x3a9];
    f32 field_3ac;
    f32 field_3b0;
    bool field_3b4;
    u8 _3b5[0x3b8 - 0x3b5];
    f32 field_3b8;
    f32 field_3bc;
    f32 field_3c0;
    bool field_3c4;
    u8 _3c5[0x3c8 - 0x3c5];
    f32 field_3c8;  // two more (value, angle) pairs
    f32 field_3cc;
    f32 field_3d0;
    f32 field_3d4;
    f32 field_3d8;
    f32 field_3dc;
    f32 field_3e0;
    f32 field_3e4;
    s32 field_3e8;
    f32 field_3ec;
    bool field_3f0;
    u8 _3f1[0x3f4 - 0x3f1];
    f32 field_3f4;
    s32 field_3f8;  // the number of passes of the second kind
    s32* field_400;
    s32* field_408;
    IGPUBuffer** field_410;  // the passes' vertex buffers
    IGPUBuffer** field_418;  // and index buffers
    Unk_Pass* field_420;
    Unk_Pass* field_428;
    CRenderTexture** field_430;
    CRenderTexture** field_438;
    CRenderTexture** field_440;
    CRenderTexture** field_448;
    CRenderTexture** field_450;
    CRenderTexture** field_458;
    CRenderTexture** field_460;
    CRenderTexture** field_468;
    CRenderTexture** field_470;
    CRenderTexture** field_478;
    CRenderTexture** field_480;
    CRenderTexture** field_488;
    CRenderTexture** field_490;
    s32 field_498;
    CRenderTexturePool* field_4a0;
    Unk_Level* field_4a8;
};
PKMN_SIZE_ASSERT(CDepthOfField::Unk_Level, 0x108);
PKMN_SIZE_ASSERT(CDepthOfField::Unk_Desc, 0x94);
PKMN_SIZE_ASSERT(CDepthOfField::Unk_Pass, 0x80);
PKMN_SIZE_ASSERT(CDepthOfField::Unk_Pass::Unk_Viewport, 0x18);
PKMN_OFFSET_ASSERT(CDepthOfField::Unk_Pass, field_58, 0x58);
PKMN_OFFSET_ASSERT(CDepthOfField, field_2c, 0x2c);
PKMN_OFFSET_ASSERT(CDepthOfField, field_c0, 0xc0);
PKMN_OFFSET_ASSERT(CDepthOfField, field_16c, 0x16c);
PKMN_OFFSET_ASSERT(CDepthOfField, field_180, 0x180);
PKMN_OFFSET_ASSERT(CDepthOfField, field_1e0, 0x1e0);
PKMN_OFFSET_ASSERT(CDepthOfField, field_154, 0x154);
PKMN_OFFSET_ASSERT(CDepthOfField, field_1a8, 0x1a8);
PKMN_OFFSET_ASSERT(CDepthOfField, field_1c8, 0x1c8);
PKMN_OFFSET_ASSERT(CDepthOfField, field_1e8, 0x1e8);
PKMN_OFFSET_ASSERT(CDepthOfField, field_20c, 0x20c);
PKMN_OFFSET_ASSERT(CDepthOfField, field_21c, 0x21c);
PKMN_OFFSET_ASSERT(CDepthOfField, field_190, 0x190);
PKMN_OFFSET_ASSERT(CDepthOfField, field_228, 0x228);
PKMN_OFFSET_ASSERT(CDepthOfField, field_240, 0x240);
PKMN_OFFSET_ASSERT(CDepthOfField, field_3f8, 0x3f8);
PKMN_OFFSET_ASSERT(CDepthOfField, field_3a8, 0x3a8);
PKMN_OFFSET_ASSERT(CDepthOfField, field_448, 0x448);
PKMN_OFFSET_ASSERT(CDepthOfField, field_488, 0x488);
PKMN_OFFSET_ASSERT(CDepthOfField, field_468, 0x468);
PKMN_OFFSET_ASSERT(CDepthOfField, field_490, 0x490);
PKMN_OFFSET_ASSERT(CDepthOfField, field_4a0, 0x4a0);
PKMN_OFFSET_ASSERT(CDepthOfField, field_4a8, 0x4a8);
PKMN_OFFSET_ASSERT(CDepthOfField, field_158, 0x158);
PKMN_OFFSET_ASSERT(CDepthOfField, field_248, 0x248);
PKMN_OFFSET_ASSERT(CDepthOfField, field_280, 0x280);
PKMN_OFFSET_ASSERT(CDepthOfField, field_2a8, 0x2a8);
PKMN_OFFSET_ASSERT(CDepthOfField, field_2c8, 0x2c8);
PKMN_OFFSET_ASSERT(CDepthOfField, field_358, 0x358);
PKMN_OFFSET_ASSERT(CDepthOfField, field_2d0, 0x2d0);
PKMN_OFFSET_ASSERT(CDepthOfField, field_2e8, 0x2e8);
PKMN_OFFSET_ASSERT(CDepthOfField, field_318, 0x318);
PKMN_OFFSET_ASSERT(CDepthOfField, field_378, 0x378);
PKMN_OFFSET_ASSERT(CDepthOfField, field_398, 0x398);
PKMN_OFFSET_ASSERT(CDepthOfField, field_3a0, 0x3a0);
PKMN_OFFSET_ASSERT(CDepthOfField, field_440, 0x440);
PKMN_OFFSET_ASSERT(CDepthOfField, field_478, 0x478);

}  // namespace PPFX
