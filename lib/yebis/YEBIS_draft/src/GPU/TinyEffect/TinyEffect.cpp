// Scope: common
// PPFX::CTinyEffect (C:/workspace/YEBIS_draft/src/GPU/TinyEffect/TinyEffect.cpp,
// 0x710044ab80 to 0x7100450eb0): the small virtual functions so far.
#include <stdlib.h>
#include <string.h>

#include <algorithm>

#include <yebis/YEBIS_draft/src/GPU/Unk_Statics.h>
#include <yebis/YEBIS_draft/src/GPU/TinyEffect/TinyEffect.h>
#include <yebis/YEBIS_draft/src/GPU/GPUInterfaceBuffer.h>

#define PPFX_FILE "C:/workspace/YEBIS_draft/src/GPU/TinyEffect/TinyEffect.cpp"
#include <yebis/YEBIS_draft/src/GPU/Unk_Log.h>

namespace PPFX {

// 0x71024e2808: the device objects a pass has before it has its own
// (placeholder)
extern Unk_TinyResult Unk_24e2808 __attribute__((visibility("hidden")));

// releases a device object
static inline void Unk_Release(SiSDK3::ISiInterface*& object) {
    if (object != nullptr) {
        object->vf3();
        object = nullptr;
    }
}

// 0x710044aed0, 0x710044b1a0 (deleting)
CTinyEffect::~CTinyEffect() {
    Unk_44afa0();
}

// 0x710044ab80
s32 Unk_TinyPass::Unk_44ab80() {
    for (auto it = field_70.begin(); it != field_70.end(); ++it) {
        if (*it != nullptr) {
            Unk_Delete(Unk_238d5f8, *it);
        }
    }
    field_70.clear();
    field_68 = false;
    if (field_30.field_0 != nullptr && field_30.field_8 != nullptr && field_30.field_10 != nullptr &&
        !(field_30.field_0 == Unk_24e2808.field_0 && field_30.field_8 == Unk_24e2808.field_8 &&
          field_30.field_10 == Unk_24e2808.field_10)) {
        field_4c = 0;
        field_50 = 0;
        Unk_TinyShared* shared = field_88;
        if (shared != nullptr) {
            if (--shared->field_8 == 0) {
                Unk_Delete(Unk_238d5f8, shared);
            }
            field_88 = nullptr;
        }
        Unk_Release(field_30.field_10);
        Unk_Release(field_30.field_8);
        Unk_Release(field_30.field_0);
        if (field_c0) {
            Unk_Release(field_a0);
            Unk_Release(field_a8);
            Unk_Release(field_b0);
            Unk_Release(field_b8);
        }
        Unk_Release(field_98);
        Unk_Release(field_90);
    }
    field_20 = "";
    field_30.field_0 = nullptr;
    field_30.field_8 = nullptr;
    field_30.field_10 = nullptr;
    return 0;
}

// 0x710044ad90
// NON_MATCHING: the original computes the address of field_140.field_1a4
// (0x2e4) before the memsets and keeps it in x20 across the call (with a
// pointer to it taken before the second memset it matches); here it is
// computed after the call. A loop of the three numbers, std::fill and one
// array for field_140 and the numbers were tried.
CTinyEffect::CTinyEffect()
    : field_78(nullptr), field_80(0), field_130(nullptr), field_138(0), field_13c(0), field_2f0(false), field_2f1(false), field_340(false),
      field_348(nullptr), field_3c0(0), field_3c8(nullptr) {
    memset(field_88, 0, sizeof(field_88));
    memset(&field_140, 0, __builtin_offsetof(Unk_TinyInputs, field_1a4));
    field_140.field_1a4 = 1;
    field_140.field_1a8 = 2;
    field_140.field_1ac = 3;
}

// 0x710044afa0: releases everything
s32 CTinyEffect::Unk_44afa0() {
    field_30 = "";
    field_40 = "";
    field_2f0 = false;
    field_2f1 = false;
    for (auto it = field_2f8.begin(); it != field_2f8.end(); ++it) {
        if (*it != nullptr) {
            Unk_Delete(Unk_238d5f8, *it);
        }
    }
    field_2f8.clear();
    for (auto it = field_310.begin(); it != field_310.end(); ++it) {
        if (*it != nullptr) {
            Unk_Delete(Unk_238d5f8, *it);
        }
    }
    field_310.clear();
    for (auto it = field_328.begin(); it != field_328.end(); ++it) {
        if (*it != nullptr) {
            Unk_Delete(Unk_238d5f8, *it);
        }
    }
    field_328.clear();
    if (field_3c8 != nullptr) {
        Unk_4b9a60(Unk_238d5f8, reinterpret_cast<u64*>(field_3c8) - 1);
        field_3c8 = nullptr;
    }
    field_3c0 = 0;
    field_78 = nullptr;
    field_80 = 0;
    if (field_340) {
        if (field_348 != nullptr) {
            Unk_4b9a60(Unk_238d5f8, static_cast<u64*>(field_348) - 1);
            field_348 = nullptr;
        }
    } else {
        field_348 = nullptr;
    }
    field_350 = 0;
    field_378 = 0;
    field_370 = nullptr;
    return 0;
}

// 0x710044b1d0
// NON_MATCHING: in the search by semantic (the loop LLVM unswitches) the
// original keeps the next index in the result's register and -1 in another;
// here -1 is the result's register and the indices move into it.
s32 CTinyEffect::Unk_44b1d0(const char* name, bool semantic) {
    if (field_2f1) {
        if (field_328.empty()) {
            return -1;
        }
        s32 high = static_cast<s32>(field_328.size()) - 1;
        s32 low = 0;
        s32 middle = high / 2;
        s32 order = field_328[middle]->field_8.Unk_452790(name, -1);
        while (order != 0) {
            if (low >= high) {
                return -1;
            }
            if (order > 0) {
                high = middle - 1;
            } else {
                low = middle + 1;
            }
            middle = (high + low) / 2;
            order = field_328[middle]->field_8.Unk_452790(name, -1);
        }
        return middle;
    }
    u32 count = field_328.size();
    for (u32 i = 0; i < count; i++) {
        if (field_328[i]->field_8 == name) {
            return i;
        }
        if (semantic && field_328[i]->field_30 == name) {
            return i;
        }
    }
    return -1;
}

// 0x710044b380
s32 CTinyEffect::Unk_44b380(const char* name) {
    if (field_2f0) {
        if (field_2f8.empty()) {
            return -1;
        }
        s32 high = static_cast<s32>(field_2f8.size()) - 1;
        s32 low = 0;
        s32 middle = high / 2;
        s32 order = field_2f8[middle]->field_8.Unk_452790(name, -1);
        while (order != 0) {
            if (low >= high) {
                return -1;
            }
            if (order > 0) {
                high = middle - 1;
            } else {
                low = middle + 1;
            }
            middle = (high + low) / 2;
            order = field_2f8[middle]->field_8.Unk_452790(name, -1);
        }
        return middle;
    }
    {
        Unk_TFXString text(name);
        for (u32 i = 0; i < field_2f8.size(); i++) {
            if (field_2f8[i]->field_8 == name) {
                return i;
            }
        }
    }
    return -1;
}

// the SiGfx root signature CreateSiGfxProgramResources fills in (placeholder)
struct Unk_TinyRootSignature {
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();  // release
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();  // begins
    virtual void vf9();  // ends
    virtual void vf10(s32 count);
    virtual void vf11();
    virtual void vf12(s32 index, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
    virtual void vf13();
    virtual void vf14(s32 index, s32 kind, s32 count);
    virtual void vf15(s32 index, s32 item, s32 arg2, s32 binding, s32 arg4, s32 size, s32 arg6);
};

// the SiGfx device as CreateSiGfxProgramResources uses it (placeholder)
struct Unk_TinyGfxDevice {
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
    virtual void vf14();
    virtual void vf15();
    virtual void vf16();
    virtual void vf17();
    virtual void vf18();
    virtual void vf19();
    virtual void vf20();
    virtual void vf21();
    virtual void vf22();
    virtual void vf23();
    virtual void vf24();
    virtual void vf25();
    virtual Unk_TinyRootSignature* vf26(s32 arg0, s32 arg1, void* arg2);  // CreateRootSignature
    virtual void vf27();
    virtual SiSDK3::ISiInterface* vf28(s32 arg0, s32 arg1, void* arg2);  // CreateDescriptorSet
};

// 0x710044c060 (its log lines name it)
// NON_MATCHING: the same instructions up to the layout and registers: the
// original places the path without constants after the first error block, so
// that it falls into the textures' loop, and with that the loop counter, the
// binding and the size get other registers and field_34 and field_38 each
// other's spill slots. The count's form (the sum of three conditionals) and
// the unsigned loop counter (a 32-bit index with `sxtw`) decided the rest.
// Tried: the if/else for the constants both ways, the reads in every order,
// the final test's operands in other orders.
s32 CTinyEffect::CreateSiGfxProgramResources(Unk_TinyPass* pass) {
    if (pass == nullptr || pass->field_88 == nullptr) {
        return -1;
    }
    Unk_TinyShared* program = pass->field_88;
    Unk_TinyGfxDevice* device = reinterpret_cast<Unk_TinyGfxDevice*>(field_80);
    s32 constants = program->field_28;
    Unk_TinyRootSignature* signature = device->vf26(1, 0, nullptr);
    if (signature == nullptr) {
#line 6362
        PPFX_ERROR("CTinyEffect::CreateSiGfxProgramResources(): pSiGfxDevice->CreateRootSignature() failed.\n");
        return -1;
    }
    s32 textures = program->field_2c;
    s32 samplers = program->field_30;
    s32 count3 = program->field_34;
    s32 count4 = program->field_38;
    s32 count = (constants != 0 ? 1 : 0) + (textures != 0 ? 1 : 0) + (samplers != 0 ? 1 : 0);
    signature->vf8();
    signature->vf10(count);
    s32 index = 0;
    if (constants != 0) {
        signature->vf12(0, 2, 3, 0, 0);
        index = 1;
    }
    s32 binding;
    s32 size;
    if (textures != 0) {
        signature->vf14(index, 1, textures);
        for (u32 i = 0; i < static_cast<u32>(textures); i++) {
            Unk_TinyBinding* item = program->field_40[static_cast<s32>(i)];
            if (item != nullptr) {
                binding = item->field_2c;
                size = item->field_24;
            }
            binding += 16;
            signature->vf15(index, i, 1, binding, 0, size, -1);
        }
        index++;
    }
    if (samplers != 0) {
        signature->vf14(index, 2, samplers);
        for (u32 i = 0; i < static_cast<u32>(samplers); i++) {
            Unk_TinyBinding* item = program->field_140[static_cast<s32>(i)];
            if (item != nullptr) {
                binding = item->field_2c;
                size = item->field_24;
            }
            signature->vf15(index, i, 1, binding, 0, size, -1);
        }
    }
    signature->vf9();
    SiSDK3::ISiInterface* set = nullptr;
    if (constants != 0 || textures != 0 || samplers != 0 || count3 != 0 || count4 != 0) {
        set = device->vf28(1, 0, nullptr);
        if (set == nullptr) {
            signature->vf3();
#line 6545
            PPFX_ERROR("CTinyEffect::CreateSiGfxProgramResources(): pSiGfxDevice->CreateDescriptorSet() failed.\n");
            return -1;
        }
    }
    pass->field_c0 = false;
    pass->field_90 = reinterpret_cast<SiSDK3::ISiInterface*>(signature);
    pass->field_98 = set;
    pass->field_a0 = nullptr;
    pass->field_a8 = nullptr;
    pass->field_b0 = nullptr;
    pass->field_b8 = nullptr;
    return 0;
}

// 0x710044dbc0
s32 CTinyEffect::CreateFromMemory(const void* data, Unk_TinyDevice* device, bool share) {
    Unk_44afa0();
    if (device != nullptr) {
        field_78 = device;
        field_80 = device->vf5();
        field_10 = "";
        field_20 = "";
        field_380 = 1;
        field_3d0 = false;
    }
    if (data == nullptr) {
        return -6;
    }
#line 7463
    PPFX_LOG("CTinyEffect::CreateFromMemory(): Create effect from Memory\n");
    const char* text = static_cast<const char*>(data);
    if (Unk_TFXString(text) == ".tfxo file") {
        if (share) {
            field_340 = false;
            field_348 = const_cast<void*>(data);
        } else {
            s32 size = atoi(text + 0x10) + 0x40;
            field_340 = true;
#line 7485
            field_348 = UNK_NEW_ARRAY(char, size);
            memcpy(field_348, data, size);
        }
    } else {
        field_30 = text;
    }
    Unk_44cbd0();
    return 0;
}

// 0x710044dd40
s32 CTinyEffect::vf4(const char* name) {
    return Unk_44b1d0(name, true) + 1;
}

// 0x710044dd60
s32 CTinyEffect::vf5(const char* name) {
    return Unk_44b380(name) + 1;
}

// 0x710044dda0: clears the parameters' objects and releases the passes'
s32 CTinyEffect::vf3() {
    u32 count = field_328.size();
    for (u32 i = 0; i < count; i++) {
        Unk_TinyParam* param = field_328[i];
        if (param->field_40 && param->field_1c == 4) {
            memset(param->field_48, 0, static_cast<s32>(param->field_20) * static_cast<s32>(param->field_2c));
        }
    }
    Unk_44def0();
    return 0;
}

// 0x710044def0
void CTinyEffect::Unk_44def0() {
    s32 count = static_cast<s32>(field_310.size());
    for (s32 i = 0; i < count; i++) {
        Unk_TinyPass* pass = field_310[i];
        if (pass->field_c0) {
            if (pass->field_a0 != nullptr) {
                pass->field_a0->vf3();
                pass->field_a0 = nullptr;
            }
            if (pass->field_a8 != nullptr) {
                pass->field_a8->vf3();
                pass->field_a8 = nullptr;
            }
            if (pass->field_b0 != nullptr) {
                pass->field_b0->vf3();
                pass->field_b0 = nullptr;
            }
            if (pass->field_b8 != nullptr) {
                pass->field_b8->vf3();
                pass->field_b8 = nullptr;
            }
        }
        pass->field_c0 = false;
    }
}

// 0x710044dfd0
const char* CTinyEffect::vf7(s32 technique) {
    if (technique < 1 || technique > static_cast<s32>(field_2f8.size())) {
        return nullptr;
    }
    return field_2f8[technique - 1]->field_8.field_8;
}

// 0x710044e010
s32 CTinyEffect::vf8(s32 handle, f32 value) {
    if (!Unk_IsParam(handle)) {
        return -6;
    }
    Unk_TinyParam* param = field_328[handle - 1];
    if (param->field_1c >= 1 && param->field_1c <= 3) {
        *static_cast<f32*>(param->field_48) = value;
        return 0;
    }
    return -6;
}

// 0x710044e070
s32 CTinyEffect::vf9(s32 handle, const void* values, u32 count) {
    if (!Unk_IsParam(handle)) {
        return -6;
    }
    Unk_TinyParam* param = field_328[handle - 1];
    if (param->field_1c == 1) {
        u32 n = std::min(param->field_2c, count);
        memcpy(param->field_48, values, Unk_24e2730 * n);
        return 0;
    }
    return -6;
}

// 0x710044e100
s32 CTinyEffect::vf10(s32 handle, const void* value) {
    if (!Unk_IsParam(handle)) {
        return -6;
    }
    Unk_TinyParam* param = field_328[handle - 1];
    if (param->field_1c >= 1 && param->field_1c <= 3) {
        u32 size = std::min(Unk_24e2734, param->field_20);
        memcpy(param->field_48, value, size);
        return 0;
    }
    return -6;
}

// 0x710044e190
s32 CTinyEffect::vf11(s32 handle, void* value) {
    if (!Unk_IsParam(handle)) {
        return -6;
    }
    Unk_TinyParam* param = field_328[handle - 1];
    if (param->field_1c >= 1 && param->field_1c <= 3) {
        u32 size = std::min(Unk_24e2734, param->field_20);
        memcpy(value, param->field_48, size);
        return 0;
    }
    return -6;
}

// 0x710044e220
s32 CTinyEffect::vf12(s32 handle, const void* values, u32 count) {
    if (!Unk_IsParam(handle)) {
        return -6;
    }
    Unk_TinyParam* param = field_328[handle - 1];
    if (param->field_1c == 2) {
        u32 n = std::min(param->field_2c, count);
        memcpy(param->field_48, values, Unk_24e2734 * n);
        return 0;
    }
    return -6;
}

// 0x710044e2b0
s32 CTinyEffect::vf13(s32 handle, void* values, u32 count) {
    if (!Unk_IsParam(handle)) {
        return -6;
    }
    Unk_TinyParam* param = field_328[handle - 1];
    if (param->field_1c == 2) {
        u32 n = std::min(param->field_2c, count);
        memcpy(values, param->field_48, Unk_24e2734 * n);
        return 0;
    }
    return -6;
}

// 0x710044e340
s32 CTinyEffect::vf14(s32 handle, const void* value) {
    if (!Unk_IsParam(handle)) {
        return -6;
    }
    Unk_TinyParam* param = field_328[handle - 1];
    if (param->field_1c == 3) {
        u32 size = std::min(Unk_24e2738, param->field_20);
        memcpy(param->field_48, value, size);
        return 0;
    }
    return -6;
}

// 0x710044e3d0
s32 CTinyEffect::vf15(s32 handle, const void* values, u32 count) {
    if (!Unk_IsParam(handle)) {
        return -6;
    }
    Unk_TinyParam* param = field_328[handle - 1];
    if (param->field_1c == 3) {
        u32 n = std::min(param->field_2c, count);
        memcpy(param->field_48, values, Unk_24e2738 * n);
        return 0;
    }
    return -6;
}

// 0x710044e460
s32 CTinyEffect::vf16(s32 handle, void* object) {
    if (!Unk_IsParam(handle)) {
        return -6;
    }
    Unk_TinyParam* param = field_328[handle - 1];
    if (param->field_1c == 4) {
        memcpy(param->field_48, &object, Unk_24e273c);
        return 0;
    }
    return -6;
}

// 0x710044e500
s32 CTinyEffect::vf17(s32 technique) {
    s32 result = -6;
    if (technique >= 1 && technique <= static_cast<s32>(field_2f8.size())) {
        s32 pass = field_2f8[technique - 1]->field_1c;
        if (pass >= 0 && pass < static_cast<s32>(field_310.size())) {
            result = 0;
        }
    }
    return result;
}

// 0x710044e560
s32 CTinyEffect::vf18(s32 technique) {
    if (technique < 1 || technique > static_cast<s32>(field_2f8.size())) {
        return -6;
    }
    field_380 = technique;
    return 0;
}

// 0x710044e5b0
Unk_TinyResult CTinyEffect::vf20(s32 technique) {
    if (technique == 0) {
        technique = field_380;
    }
    Unk_TinyTechnique* item = field_2f8[technique - 1];
    return item->field_0->field_310[item->field_1c]->field_30;
}

// 0x710044e5f0
Unk_TinyResult CTinyEffect::vf21(s32 technique) {
    if (technique == 0) {
        technique = field_380;
    }
    Unk_TinyTechnique* item = field_2f8[technique - 1];
    return item->field_0->field_310[item->field_1c]->field_30;
}

// the index of the entry named `name` (a number is the index itself)
// NON_MATCHING (its four callers): the test that ends the digits' loop is
// `cmp w10, #0x3a ; b.lo` here, `cmp w10, #0x39 ; b.ls` in the original: the
// same IR (`icmp ugt 57`), but here the search's block follows the loop's
// latch when instructions are selected, so the branch is inverted there
// (and the DAG makes `ule 57` `ult 58`); the original inverts it only in
// block placement. Seven loop shapes and helpers were tried.
static inline s32 Unk_FindEntry(const CTinyEffect* effect, const Unk_TFXString& name) {
    const char* p = name.field_8;
    s32 i = 0;
    while (i < name.field_0) {
        char c = p[i];
        if (c < '0') goto search;
        i++;
        if (c > '9') goto search;
    }
    return atoi(name.field_8);
search:
    for (s32 j = 0; j < effect->field_350; j++) {
        if (name == effect->field_370[j].field_0) {
            return j;
        }
    }
    return -1;
}

}  // namespace PPFX

// 0x710044e630, 0x710044e750: the code of the technique's pass (0: the current
// technique's)
void* Unk_44e630(void* self, s32 technique) {
    PPFX::CTinyEffect* effect = static_cast<PPFX::CTinyEffect*>(self);
    if (technique == 0) {
        technique = effect->field_380;
    }
    PPFX::Unk_TinyTechnique* item = effect->field_2f8[technique - 1];
    PPFX::Unk_TinyPass* pass = item->field_0->field_310[item->field_1c];
    s32 index = PPFX::Unk_FindEntry(effect, pass->field_20);
    if (index < 0) {
        return nullptr;
    }
    u32 offset = atoi(effect->field_370[index].field_e0);
    return effect->field_378 + offset;
}

void* Unk_44e750(void* self, s32 technique) {
    PPFX::CTinyEffect* effect = static_cast<PPFX::CTinyEffect*>(self);
    if (technique == 0) {
        technique = effect->field_380;
    }
    PPFX::Unk_TinyTechnique* item = effect->field_2f8[technique - 1];
    PPFX::Unk_TinyPass* pass = item->field_0->field_310[item->field_1c];
    s32 index = PPFX::Unk_FindEntry(effect, pass->field_20);
    if (index < 0) {
        return nullptr;
    }
    u32 offset = atoi(effect->field_370[index].field_e0);
    return effect->field_378 + offset;
}

// 0x710044e870, 0x710044e960: the size of that code
s32 Unk_44e870(void* self, s32 technique) {
    PPFX::CTinyEffect* effect = static_cast<PPFX::CTinyEffect*>(self);
    if (technique == 0) {
        technique = effect->field_380;
    }
    PPFX::Unk_TinyTechnique* item = effect->field_2f8[technique - 1];
    PPFX::Unk_TinyPass* pass = item->field_0->field_310[item->field_1c];
    s32 index = PPFX::Unk_FindEntry(effect, pass->field_20);
    if (index < 0) {
        return 0;
    }
    return atoi(effect->field_370[index].field_f0);
}

s32 Unk_44e960(void* self, s32 technique) {
    PPFX::CTinyEffect* effect = static_cast<PPFX::CTinyEffect*>(self);
    if (technique == 0) {
        technique = effect->field_380;
    }
    PPFX::Unk_TinyTechnique* item = effect->field_2f8[technique - 1];
    PPFX::Unk_TinyPass* pass = item->field_0->field_310[item->field_1c];
    s32 index = PPFX::Unk_FindEntry(effect, pass->field_20);
    if (index < 0) {
        return 0;
    }
    return atoi(effect->field_370[index].field_f0);
}

namespace PPFX {

// 0x710044ea50
s32 CTinyEffect::vf22(u32* passes, u32 flags) {
    field_388 = flags;
    field_384 = 1;
    if (passes != nullptr) {
        *passes = 1;
    }
    field_2f8[field_380 - 1]->field_18 = true;
    return 0;
}

// 0x710044ea90
s32 CTinyEffect::vf24(u32 pass) {
    if (pass >= field_384) {
        return -6;
    }
    field_38c = pass;
    s32 result = Unk_44eac0();
    return result < 0 ? result : 0;
}

// 0x710044f250
// NON_MATCHING: the end of the first loop is `start + count` in the original
// (`add w8, w5, w6`) and `count + start` here, whichever way it is written.
s32 CTinyEffect::ApplyVertexInputs(Unk_TinyLayout* layout, IGPUBuffer** buffers, const u32* offsets,
                                   const u32* strides, u32 start, u32 count) {
    if (layout == nullptr || buffers == nullptr) {
        if (layout != nullptr || buffers != nullptr) {
            return -6;
        }
        start = 0;
        count = 16;
    }
    if (buffers != nullptr) {
        for (u32 i = start; i < start + count; i++) {
            if (buffers[i]->field_5c) {
#line 11243
                PPFX_ERROR("CTinyEffect::ApplyVertexInputs(): apGPUVertexBuffers[%d] is currently mapped. Call Unmap() first.",
                           i);
                return -1;
            }
        }
    }
    field_130 = layout->field_78;
    field_138 = count;
    field_13c = start;
    for (u32 i = 0; i < count; i++) {
        if (buffers[i] != nullptr) {
            field_140.field_0[i] = buffers[i]->field_50[buffers[i]->field_58];
        } else {
            field_140.field_0[i] = nullptr;
        }
    }
    memcpy(field_140.field_80, offsets, count * sizeof(u32));
    memcpy(field_140.field_c0, strides, count * sizeof(u32));
    return 0;
}

}  // namespace PPFX

// 0x710044f3a0: a new effect from an effect file (null if it can't be read)
void* Unk_44f3a0(const void* data, void* arg1, bool arg2) {
#line 12101
    PPFX::CTinyEffect* effect = UNK_NEW(PPFX::CTinyEffect)();
    if (effect->CreateFromMemory(data, static_cast<PPFX::Unk_TinyDevice*>(arg1), arg2) < 0) {
        UNK_DELETE(effect);
        return nullptr;
    }
    return effect;
}

namespace PPFX {

// 0x710044fb30, 0x710044fbf0 (deleting)
CManualProgramParameterTable::~CManualProgramParameterTable() {
    for (Unk_Items::iterator it = field_10.begin(); it != field_10.end(); ++it) {
        if (*it != nullptr) {
            Unk_Delete(Unk_238d5f8, *it);
        }
    }
    field_10.clear();
}

}  // namespace PPFX

// 0x7100450510, 0x7100450670, 0x71004507d0, 0x7100450930, 0x7100450a90: the
// growth of the vectors' push_back (instantiated by the functions that
// aren't written yet; the vector each one grows is the caller's member at
// that offset: a pass's field_70, the effect's field_310, field_328 and
// field_2f8, and CManualProgramParameterTable's field_10)
template void std::vector<PPFX::Unk_TinyPassItem*, PPFX::Unk_StlAllocator<PPFX::Unk_TinyPassItem*>>::
    __push_back_slow_path<PPFX::Unk_TinyPassItem* const&>(PPFX::Unk_TinyPassItem* const&);
template void std::vector<PPFX::Unk_TinyPass*, PPFX::Unk_StlAllocator<PPFX::Unk_TinyPass*>>::
    __push_back_slow_path<PPFX::Unk_TinyPass* const&>(PPFX::Unk_TinyPass* const&);
template void std::vector<PPFX::Unk_TinyParam*, PPFX::Unk_StlAllocator<PPFX::Unk_TinyParam*>>::
    __push_back_slow_path<PPFX::Unk_TinyParam* const&>(PPFX::Unk_TinyParam* const&);
template void std::vector<PPFX::Unk_TinyTechnique*, PPFX::Unk_StlAllocator<PPFX::Unk_TinyTechnique*>>::
    __push_back_slow_path<PPFX::Unk_TinyTechnique* const&>(PPFX::Unk_TinyTechnique* const&);
template void std::vector<PPFX::CManualProgramParameterTable::Unk_Item*,
                          PPFX::Unk_StlAllocator<PPFX::CManualProgramParameterTable::Unk_Item*>>::
    __push_back_slow_path<PPFX::CManualProgramParameterTable::Unk_Item* const&>(
        PPFX::CManualProgramParameterTable::Unk_Item* const&);
