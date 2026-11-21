// PPFX::IGPUEffect (RTTI): the effect PPFX's GPU code draws with, a wrapper
// of a PPFX::CTinyEffect. C:/workspace/YEBIS_draft/src/GPU/GPUInterfaceEffect.cpp
// is the __FILE__ of its allocation and log line. SetupGraphicsPipelineState
// is named by its log line; the virtual functions are vf<slot>, as
// lib/yebis/class names the ones it has (their parameter types are kept).
#pragma once

#include <vector>

#include <types.h>
#include <yebis/YEBIS_draft/src/GPU/GPUMemoryAllocator.h>
#include <yebis/YEBIS_draft/src/GPU/TinyEffect/TFXString.h>

namespace PPFX {

class IGPUDevice;

// PPFX::CTinyEffect, as IGPUEffect uses it: counted references and the
// virtual functions IGPUEffect forwards to.
class Unk_TinyEffect {
public:
    // what vf20 and vf21 return: more than two registers hold
    struct Unk_Result {
        u64 field_0[3];
    };

    virtual ~Unk_TinyEffect();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual s32 vf5(const char* name);
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual s32 vf9(u64 a, u64 b, u32 count);
    virtual void vf10();
    virtual void vf11();
    virtual s32 vf12(u64 a, u64 b, u32 count);
    virtual s32 vf13(u64 a, u64 b, u32 count);
    virtual void vf14();
    virtual s32 vf15(u64 a, u64 b, u32 count);
    virtual void vf16();
    virtual void vf17();
    virtual void vf18();
    virtual void vf19();
    virtual Unk_Result vf20(u64 a);
    virtual Unk_Result vf21(u64 a);
    virtual void vf22();
    virtual void vf23();
    virtual s32 vf24(u32 pass);
    virtual s32 vf25();
    virtual s32 vf26(u64 a, void** b, u32* c, u32* d, u32 e, s32 f, bool g);

    // one reference more or less (inline in their callers)
    void Unk_AddRef() { field_8++; }
    void Unk_Release() {
        if (--field_8 == 0)
            Unk_Delete(Unk_238d5f8, this);
    }

    s32 field_8;  // references
    u8 _c[0x2f8 - 0xc];
    std::vector<void*, Unk_StlAllocator<void*>> field_2f8;
};
PKMN_OFFSET_ASSERT(Unk_TinyEffect, field_2f8, 0x2f8);

// PPFX::IGPUResource, IGPUEffect's base (its functions are before this TU's)
class IGPUResource {
public:
    explicit IGPUResource(IGPUDevice* device);  // 0x7100446330
    virtual void vf0();
    virtual void vf1();
    virtual ~IGPUResource();  // 0x7100446440
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual s32 vf7(void* out);

    s32 field_8;
    s32 field_c;  // the kind of resource
    u64 field_10;
    void* field_18;
    u8 _20[0x48 - 0x20];
};
PKMN_SIZE_ASSERT(IGPUResource, 0x48);

class IGPUEffect : public IGPUResource {
public:
    struct Unk_Info {
        u64 field_0;
        u32 field_8;
        s32 field_c;  // the number of the tiny effect's parameters
        u64 field_10;
    };
    // a parameter's record (its string is destroyed with it)
    struct Unk_Param {
        u64 field_0;
        Unk_TFXString field_8;
    };
    typedef std::vector<Unk_Param*, Unk_StlAllocator<Unk_Param*>> Unk_Params;

    explicit IGPUEffect(IGPUDevice* device) : IGPUResource(device) { field_c = 10; }
    ~IGPUEffect() override;      // 0x7100499e00, 0x7100499f00
    s32 vf7(void* out) override;  // 0x710049a5e0
    virtual void vf8(u64 value);
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12(u32 value, u64 arg2);
    virtual u32 vf13();
    virtual void vf14(u64 value);
    virtual void vf15(u64 value);
    virtual s32 vf16(const char* name);  // 0x7100499fc0
    virtual void vf17(u64 value);
    virtual void vf18(u64 value);
    virtual s32 vf19(u64 a, u64 b, u32 count);  // 0x710049a070
    virtual void vf20(u64 value, u64 arg2);
    virtual void vf21(u64 value, u64 arg2);
    virtual s32 vf22(u64 a, u64 b, u32 count);  // 0x710049a0b0
    virtual s32 vf23(u64 a, u64 b, u32 count);  // 0x710049a0f0
    virtual void vf24(u64 value, u64 arg2);
    virtual s32 vf25(u64 a, u64 b, u32 count);  // 0x710049a120
    virtual void vf26(u64 value, u64 arg2);
    virtual void vf27(u64 value);
    virtual void vf28(u64 value);
    virtual void vf29(u64 value);
    virtual void vf30();
    virtual Unk_TinyEffect::Unk_Result vf31(u64 a);  // 0x710049a190
    virtual Unk_TinyEffect::Unk_Result vf32(u64 a);  // 0x710049a1a0
    virtual void vf33(u64 value, u64 arg2);
    virtual void vf34();
    virtual s32 vf35(u32 pass);  // 0x710049a280
    virtual s32 vf36();          // 0x710049a2c0
    virtual s32 vf37();          // 0x710049a1b0
    virtual s32 vf38();          // 0x710049a1c0
    virtual s32 vf39();          // 0x710049a1d0
    virtual s32 vf40();          // 0x710049a1e0
    virtual void vf41(u64, u64, u64, u64, u64, u64, bool);
    // 0x710049a1f0
    virtual s32 vf42(const u8* a, void* b, u32 c, s32 d, u32 index, bool flag);
    virtual void vf43();

    // 0x710049a480
    s32 SetupGraphicsPipelineState();

    // takes the tiny effect (inline in the function that makes the effect)
    void Unk_SetTinyEffect(Unk_TinyEffect* tinyEffect) {
        field_78 = tinyEffect;
        tinyEffect->Unk_AddRef();
        field_48.field_0 = 0;
        field_48.field_8 = 0;
        field_48.field_c = 0;
        field_48.field_10 = 0;
        Unk_DeleteParams();
        field_60.clear();
        field_48.field_c = static_cast<s32>(field_78->field_2f8.size());
    }
    void Unk_DeleteParams() {
        for (s32 i = 0; i < static_cast<s32>(field_60.size()); i++)
            UNK_DELETE(field_60[i]);
    }

    Unk_Info field_48;
    Unk_Params field_60;
    Unk_TinyEffect* field_78;
};
PKMN_SIZE_ASSERT(IGPUEffect, 0x80);

}  // namespace PPFX
