// Scope: common
// PPFX::CTinyEffect (C:/workspace/YEBIS_draft/src/GPU/TinyEffect/TinyEffect.cpp,
// 0x710044ab80 to 0x7100450eb0): the small virtual functions so far.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <algorithm>

#include <yebis/YEBIS_draft/src/GPU/Unk_Statics.h>
#include <yebis/YEBIS_draft/src/GPU/TinyEffect/TinyEffect.h>
#include <yebis/YEBIS_draft/src/GPU/GPUInterfaceBuffer.h>
#include <yebis/YEBIS_draft/src/GPU/GPUInterfaceTexture.h>
#include <yebis/YEBIS_draft/src/GPU/Unk_Array.h>

#define PPFX_FILE "C:/workspace/YEBIS_draft/src/GPU/TinyEffect/TinyEffect.cpp"
#include <yebis/YEBIS_draft/src/GPU/Unk_Log.h>

namespace PPFX {

// 0x71024e2808 (in the TU's merged statics): the device objects a pass has
// before it has its own (placeholder)
static const Unk_TinyResult Unk_24e2808(reinterpret_cast<SiSDK3::ISiInterface*>(-1),
                                        reinterpret_cast<SiSDK3::ISiInterface*>(-1),
                                        reinterpret_cast<SiSDK3::ISiInterface*>(-1));

}  // namespace PPFX

// how many bytes `count` floats are (inline: placeholder)
static inline u32 Unk_FloatBytes(u32 count) {
    return count * sizeof(f32);
}

// 0x71024e2730, 0x71024e2734, 0x71024e2738, 0x71024e273c
u32 Unk_24e2730 = Unk_FloatBytes(1);
u32 Unk_24e2734 = Unk_FloatBytes(4);
u32 Unk_24e2738 = Unk_FloatBytes(16);
u32 Unk_24e273c = Unk_FloatBytes(2);

namespace PPFX {

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
        CManualProgramParameterTable* shared = field_88;
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

// 0x710044ad90: field_140 is cleared up to its numbers by the difference of
// their addresses (the address of field_1a4 is computed before the memset
// and kept across it; with offsetof it is computed after)
CTinyEffect::CTinyEffect()
    : field_78(nullptr), field_80(0), field_130(nullptr), field_138(0), field_13c(0), field_2f0(false), field_2f1(false), field_340(false),
      field_348(nullptr), field_3c0(0), field_3c8(nullptr) {
    memset(&field_88, 0, sizeof(field_88));
    memset(&field_140, 0, reinterpret_cast<u8*>(&field_140.field_1a4) - reinterpret_cast<u8*>(&field_140));
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

// whether a pass's device objects are made (and not the stand-in ones)
static inline bool Unk_IsMade(const Unk_TinyResult& objects) {
    return objects.field_0 != nullptr && objects.field_8 != nullptr && objects.field_10 != nullptr &&
           !(objects.field_0 == Unk_24e2808.field_0 && objects.field_8 == Unk_24e2808.field_8 &&
             objects.field_10 == Unk_24e2808.field_10);
}

typedef CManualProgramParameterTable::Unk_Item Unk_TableItem;

// the table's item at `index` (null if there is none)
static inline Unk_TableItem* Unk_GetItem(const CManualProgramParameterTable* table, s32 index) {
    return index < 0 ? nullptr : table->field_10[index];
}

// whether `item` is one of the table's
static inline bool Unk_IsItem(const CManualProgramParameterTable* table, const Unk_TableItem* item) {
    if (item->field_1c >= static_cast<s32>(table->field_10.size())) {
        return false;
    }
    return Unk_GetItem(table, item->field_1c) == item;
}

// whether `item` is one of the table's parameters of the effect's kinds
static inline bool Unk_IsParameter(const CManualProgramParameterTable* table, const Unk_TableItem* item) {
    return Unk_IsItem(table, item) && item->field_20 >= 1 && item->field_20 <= 4 && item->field_24 >= 0;
}

// whether the program uses it
static inline bool Unk_IsReferenced(const CManualProgramParameterTable* table, const Unk_TableItem* item) {
    return Unk_IsParameter(table, item) && item->field_18;
}

// the `element`th element of `item` (itself; null past its end)
static inline Unk_TableItem* Unk_GetElement(const CManualProgramParameterTable* table, Unk_TableItem* item,
                                            s32 element) {
    if (!Unk_IsParameter(table, item)) {
        return nullptr;
    }
    if (item->field_24 < 1 || item->field_24 <= element) {
        return nullptr;
    }
    return item;
}

// the table's item named `name` (null if there is none)
static inline Unk_TableItem* Unk_FindItem(const CManualProgramParameterTable* table, const char* name) {
    s32 index = -1;
    for (u32 i = 0; i < table->field_10.size(); i++) {
        if (table->field_10[i]->field_8 == name) {
            index = i;
            break;
        }
    }
    if (index < 0 || index >= static_cast<s32>(table->field_10.size())) {
        return nullptr;
    }
    return table->field_10[index];
}

// 0x710044b4d0 (its log lines name it)
// NON_MATCHING: a first version (the table's constructor matches): the
// original doesn't fold the first test of the loop (`item != nullptr`) and
// keeps the name search's index check and the array's element loop in other
// shapes; the loop over the parameters is probably the inlined iteration
// functions of a Cg-like interface (the log lines' "cgParameter"), not this
// one loop.
s32 CTinyEffect::CreateParameter(Unk_TinyPass* pass, s32 programIndex) {
    if (pass->field_68) {
        return 0;
    }
    Unk_TinyResult objects = pass->field_30;
#line 2567
    PPFX_FX("CTinyEffect::CreateParameter(): \n%d: %s\n", programIndex, pass->field_8.field_8);
#line 2567
    PPFX_FX("CTinyEffect::CreateParameter(programIndex: %d, pProgram->m_strName: \"%s\"):\n", programIndex,
            pass->field_8.field_8);
    if (!Unk_IsMade(objects)) {
        return 0;
    }
    if (Unk_IsMade(pass->field_30) && pass->field_88 == nullptr) {
#line 13731
        CManualProgramParameterTable* table = UNK_NEW(CManualProgramParameterTable)();
        table->Unk_44fca0(pass);
        pass->field_88 = table;
    }
    s32 index = -1;
    Unk_TableItem* item = nullptr;
    while (item != nullptr || field_70) {
        bool grouped = field_70;
        Unk_TinyParam* param = nullptr;
        if (index >= 0 && grouped) {
            index += field_328[index]->field_2c;
            if (index >= static_cast<s32>(field_328.size())) {
                break;
            }
            param = field_328[index];
        } else {
            index++;
            if (grouped) {
                param = field_328[index];
            }
        }
        Unk_TFXString name(param != nullptr ? param->field_8 : Unk_TFXString(""));
        if (param != nullptr) {
            item = Unk_FindItem(pass->field_88, name.field_8);
            if (item == nullptr || !Unk_IsParameter(pass->field_88, item)) {
                continue;
            }
        }
        Unk_TFXString parameterName(name);
        if (param == nullptr || param->field_1c == 0) {
            continue;
        }
        Unk_TinyParam* first = field_328[index];
        s32 referenced = 0;
        if (param->field_41) {
            for (s32 element = 0; element < first->field_2c; element++) {
                Unk_TableItem* elementItem = Unk_GetElement(pass->field_88, item, element);
                if (elementItem == nullptr) {
                    break;
                }
                if (Unk_IsReferenced(pass->field_88, elementItem)) {
                    referenced = element + 1;
                }
            }
        } else {
            referenced = Unk_IsReferenced(pass->field_88, item);
        }
        if (referenced != 0) {
            bool array = param->field_41;
            // compared, the result unused
            bool matrix = parameterName == "m44_ColorTransformMatrix" || parameterName == "am44_TransformMatrix";
            (void)matrix;
#line 3802
            Unk_TinyPassItem* passItem = UNK_NEW(Unk_TinyPassItem)(this);
            pass->field_70.push_back(passItem);
            passItem->field_20 = item;
            passItem->field_8 = first->field_8;
            passItem->field_3c = array;
            passItem->field_28 = index;
            passItem->field_30 = first;
            passItem->field_40 = 0;
            passItem->field_38 = referenced;
            passItem->field_44 = passItem->field_20->field_2c;
            passItem->field_48 = passItem->field_20->field_30;
        }
        if (param->field_41) {
            s32 elements = param->field_2c;
            Unk_TFXString text = Unk_TFXString(" ") + Unk_4525a0(referenced) + " elements referenced";
#line 4010
            PPFX_FX("cgParameter name: %s[%d]%s.\n", parameterName.field_8, elements,
                    referenced != 0 ? text.field_8 : "");
        } else {
#line 4016
            PPFX_FX("cgParameter name: %s%s.\n", parameterName.field_8, referenced != 0 ? " referenced" : "");
        }
    }
    pass->field_68 = true;
    CreateSiGfxProgramResources(pass);
    return 0;
}

// 0x710044bbd0
// NON_MATCHING: register allocation in the loop: the original keeps
// `elements` on the stack and a down-counter of `count` in x19, the
// first parameter in x28, and ends the loop on `i - count != 0`; the
// instructions are otherwise the same.
s32 CTinyEffect::CreateGlobalParameter(const Unk_TFXString& name, s32 type, s32 elements, bool find) {
#line 6579
    PPFX_FX("CTinyEffect::CreateGlobalParameter():\nstrName: %s\neType: %d\nnElements: %d\n", name.field_8, type,
            elements);
    s32 index = -1;
    if (find) {
        index = Unk_44b1d0(name.field_8, false);
        if (index >= 0) {
            return index;
        }
    }
    s32 count = elements > 0 ? elements : (elements == 0 ? 1 : elements);
    field_328.reserve(field_328.size() + count);
    Unk_TinyParam* first = nullptr;
    for (s32 i = 0; i < count; i++) {
#line 6631
        Unk_TinyParam* param = UNK_NEW(Unk_TinyParam)(this);
        field_328.push_back(param);
        if (i == 0) {
            param->field_2c = count;
            index = field_328.size() - 1;
            first = param;
        } else {
            param->field_2c = elements - i;
        }
        param->field_1c = type;
        u32 size;
        u32 rows;
        switch (type) {
        case 1:
            size = 4;
            rows = 1;
            break;
        case 2:
            size = 16;
            rows = 1;
            break;
        case 3:
            size = 64;
            rows = 4;
            break;
        case 4:
            size = 8;
            rows = 1;
            break;
        default:
            size = 0;
            rows = 0;
            break;
        }
        param->field_20 = size;
        param->field_24 = size;
        param->field_28 = rows;
        param->field_8 = name;
        param->field_30 = name;
        param->field_41 = elements > 0;
        if (elements > 0) {
            char text[16];
            sprintf(text, "[%d]", i);
            param->field_30 += text;
        }
#line 6672
        PPFX_FX("\nm_strName       : %s\nm_strElementName: %s\n", param->field_8.field_8, param->field_30.field_8);
        if (i == 0) {
            param->field_40 = true;
            s32 bytes = static_cast<s32>(param->field_20) * count;
#line 6686
            param->field_48 = UNK_NEW_ARRAY(char, bytes);
            memset(param->field_48, 0, bytes);
        } else {
            param->field_40 = false;
            param->field_48 = static_cast<char*>(first->field_48) + static_cast<s32>(param->field_20) * i;
        }
    }
    return index;
}

// the index of the entry named `name` (a number is the index itself). `c`
// is declared outside the loop: inside it, the gotos leave its scope through
// a cleanup, and jump threading of the cleanup's switch puts the search's
// block after the loop's latch (`cmp #0x3a ; b.lo` instead of the original's
// `cmp #0x39 ; b.ls`).
static inline s32 Unk_FindEntry(const CTinyEffect* effect, const Unk_TFXString& name) {
    s32 i = 0;
    char c;
    while (i < name.field_0) {
        c = name.field_8[i];
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

// a SiGfx shader as CreateProgram uses it (placeholder)
struct Unk_TinyShader : SiSDK3::ISiInterface {
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
    virtual bool vf18(u32 size, const char* code, s32 arg3);  // pSiGfxShader->Create()
};

// a SiGfx shader program as CreateProgram uses it (placeholder)
struct Unk_TinyShaderProgram : SiSDK3::ISiInterface {
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
    // pSiGfxShaderProgram->Create()
    virtual bool vf18(Unk_TinyShader* vertex, Unk_TinyShader* fragment, void* arg3, void* arg4, void* arg5);
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
    virtual struct Unk_TinyTable* vf27(s32 arg0, s32 arg1, void* arg2);  // a table of textures
    virtual SiSDK3::ISiInterface* vf28(s32 arg0, s32 arg1, void* arg2);  // CreateDescriptorSet
    virtual void vf29();
    virtual void vf30();
    virtual void vf31();
    virtual void vf32();
    virtual void vf33();
    virtual void vf34();
    virtual void vf35();
    virtual void vf36();
    virtual void vf37();
    virtual void vf38();
    virtual void vf39();
    virtual void vf40();
    virtual void vf41();
    virtual Unk_TinyShader* vf42(s32 stage, void* arg1, s32 arg2, void* arg3);  // CreateShader
    virtual void vf43();
    virtual void vf44();
    virtual Unk_TinyShaderProgram* vf45(void* arg0, s32 arg1, void* arg2);  // a shader program
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
    CManualProgramParameterTable* program = pass->field_88;
    Unk_TinyGfxDevice* device = reinterpret_cast<Unk_TinyGfxDevice*>(field_80);
    s32 constants = program->field_28;
    Unk_TinyRootSignature* signature = device->vf26(1, 0, nullptr);
    if (signature == nullptr) {
#line 6362
        PPFX_ERROR("CTinyEffect::CreateSiGfxProgramResources(): pSiGfxDevice->CreateRootSignature() failed.\n");
        return -1;
    }
    s32 textures = program->field_2c[0];
    s32 samplers = program->field_2c[1];
    s32 count3 = program->field_34[0];
    s32 count4 = program->field_34[1];
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
            CManualProgramParameterTable::Unk_Item* item = program->field_40[0][static_cast<s32>(i)];
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
            CManualProgramParameterTable::Unk_Item* item = program->field_40[1][static_cast<s32>(i)];
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

// 0x710044c370 (its log lines name it)
// NON_MATCHING: the order of the zeros of the path without an effect file
// (the original: vertexSize, shaderProgram, fragment, vertex, fragmentSize,
// fragmentCode, vertexCode) and of the shaders' Create() arguments (the
// original copies the size first); the locals' declaration order decides
// both, and none of the 270 orders tried gives the original's.
s32 CTinyEffect::CreateProgram(Unk_TinyProgram* program) {
    Unk_TinyGfxDevice* device = reinterpret_cast<Unk_TinyGfxDevice*>(field_80);
    const Unk_TFXString& programNames = program->field_8;
    const Unk_TFXString& codeNames = program->field_20;
    Unk_TFXString vertexName;
    Unk_TFXString fragmentName;
    Unk_TFXString vertexCodeName;
    Unk_TFXString fragmentCodeName;
    {
        Unk_TFXString names(programNames);
        vertexName = Token(&names, " \t\n\r", "//", "\"'", -1, -1, -1);
        fragmentName = Token(&names, " \t\n\r", "//", "\"'", -1, -1, -1);
        Unk_TFXString codes(codeNames);
        vertexCodeName = Token(&codes, " \t\n\r", "//", "\"'", -1, -1, -1);
        fragmentCodeName = Token(&codes, " \t\n\r", "//", "\"'", -1, -1, -1);
    }
    const char* fragmentCode = nullptr;
    Unk_TinyShader* vertex = nullptr;
    Unk_TinyShader* fragment = nullptr;
    Unk_TinyShaderProgram* shaderProgram = nullptr;
    const char* vertexCode = nullptr;
    u32 vertexSize = 0;
    u32 fragmentSize = 0;
    if (field_348 != nullptr) {
        if (field_368 != 6) {
            s32 index = Unk_FindEntry(this, vertexCodeName);
            if (index >= 0) {
                Unk_TinyEntry* entry = &field_370[index];
                u32 offset = atoi(entry->field_e0);
                vertexCode = field_378 + offset;
                vertexSize = atoi(entry->field_f0);
            }
            index = Unk_FindEntry(this, fragmentCodeName);
            if (index >= 0) {
                Unk_TinyEntry* entry = &field_370[index];
                u32 offset = atoi(entry->field_e0);
                fragmentCode = field_378 + offset;
                fragmentSize = atoi(entry->field_f0);
            }
        }
        vertex = device->vf42(1, nullptr, 0, nullptr);
        bool vertexCreated = vertex != nullptr ? vertex->vf18(vertexSize, vertexCode, 1) : false;
        fragment = device->vf42(2, nullptr, 0, nullptr);
        bool fragmentCreated = fragment != nullptr ? fragment->vf18(fragmentSize, fragmentCode, 1) : false;
        if (!(vertexCreated & fragmentCreated)) {
            if (vertex != nullptr) {
                vertex->vf3();
            }
            if (fragment != nullptr) {
                fragment->vf3();
            }
            if (!vertexCreated) {
#line 5097
                PPFX_ERROR("CTinyEffect::CreateProgram(): pSiGfxDevice->CreateShader() failed: \"%s\".\n",
                           vertexName.field_8);
            }
            if (!fragmentCreated) {
#line 5102
                PPFX_ERROR("CTinyEffect::CreateProgram(): pSiGfxDevice->CreateShader() failed: \"%s\".\n",
                           fragmentName.field_8);
            }
            return -1;
        }
        shaderProgram = device->vf45(nullptr, 0, nullptr);
        if (shaderProgram == nullptr || !shaderProgram->vf18(vertex, fragment, nullptr, nullptr, nullptr)) {
            if (shaderProgram != nullptr) {
                shaderProgram->vf3();
            }
            if (vertex != nullptr) {
                vertex->vf3();
            }
            fragment->vf3();
#line 5128
            PPFX_ERROR("CTinyEffect::CreateProgram(): pSiGfxShaderProgram->Create() failed.\n");
            return -1;
        }
    }
    program->field_30.field_0 = vertex;
    program->field_30.field_8 = fragment;
    program->field_30.field_10 = shaderProgram;
    program->field_58 = vertexCode;
    program->field_60 = fragmentCode;
    program->field_4c = vertexSize;
    program->field_50 = fragmentSize;
    if (vertex == nullptr || fragment == nullptr || shaderProgram == nullptr) {
        return -4;
    }
    return 0;
}

// 0x710044c920
// NON_MATCHING: the order of the local program's zero stores (the original
// stores field_58/field_60 second, here last); the rest is the same.
// Every order of the constructor's body gives this one (MemCpyOpt makes it
// two memsets).
s32 CTinyEffect::Unk_44c920(const Unk_TFXString& name, const Unk_TFXString& code, u32 arg,
                            Unk_TinyResult objects) {
    if (!(objects.field_0 != nullptr && objects.field_8 != nullptr && objects.field_10 != nullptr &&
          !(objects.field_0 == Unk_24e2808.field_0 && objects.field_8 == Unk_24e2808.field_8 &&
            objects.field_10 == Unk_24e2808.field_10))) {
        s32 index = Unk_FindPass(code.field_8);
        if (index >= 0) {
            return index;
        }
    }
    Unk_TinyProgram program(nullptr);
    program.field_48 = arg;
    program.field_8 = name;
    program.field_20 = code;
    program.field_30 = objects;
    if (objects.field_0 == nullptr || objects.field_8 == nullptr || objects.field_10 == nullptr) {
        s32 result = CreateProgram(&program);
        if (result < 0 && result != -4) {
            return -1;
        }
    }
#line 5586
    Unk_TinyPass* pass = UNK_NEW(Unk_TinyPass)(this, program);
    field_310.push_back(pass);
    return field_310.size() - 1;
}

// the size of a parameter's element, by its kind
static inline u32 Unk_ElementSize(s32 type) {
    switch (type) {
    case 1:
        return 4;
    case 2:
        return 16;
    case 3:
        return 64;
    case 4:
        return 8;
    default:
        return 0;
    }
}

// 0x710238cf40: the kinds' names (the log's)
static const char* const Unk_238cf40[] = {"ETFXPT_FLOAT", "ETFXPT_FLOAT", "ETFXPT_FLOAT4", "ETFXPT_FLOAT4x4",
                                          "ETFXPT_SAMPLER"};

// 0x710044cbd0 (its log line names it)
// NON_MATCHING: two scheduling nits, the instructions are the same: the
// original computes the code's offset before the address of the text
// (`add w9` before `add x1` at +0x144), and the last two terms of the
// passes' sharing condition after the shared objects' loads. The condition
// is the bitwise one the original evaluates (every term, no branches); the
// objects are passed by value (the copy is made just before the call).
s32 CTinyEffect::BuildEffect() {
#line 6847
    PPFX_FX("CTinyEffect::BuildEffect(): \n\n%s\n\n", field_30.field_8);
    field_2f0 = true;
    field_368 = 0;
    if (field_348 != nullptr) {
        const char* header = static_cast<const char*>(field_348);
        s32 size = atoi(header + 0x20);
        field_350 = atoi(header + 0x30);
        field_358 = Unk_TFXString(header + 0x38, 8, 8);
        field_358.Unk_452b30();
        if (field_358 == "glsl") {
            field_368 = 1;
        } else if (field_358 == "glsl_bin") {
            field_368 = 2;
        } else if (field_358 == "glsl_mrg" || field_358 == "glsl_kgr") {
            field_368 = 3;
        } else if (field_358 == "cgsrc") {
            field_368 = 4;
        } else if (field_358 == "cgnv1") {
            field_368 = 5;
        } else if (field_358 == "cgnv2") {
            field_368 = 6;
        } else if (field_358 == "cgstrip") {
            field_368 = 7;
        }
        s32 entries = size + 0x40;
        s32 code = entries + field_350 * static_cast<s32>(sizeof(Unk_TinyEntry));
        if (field_368 == 5 || field_368 == 6) {
            code = (code + 15) & ~15;
        }
        field_30 = Unk_TFXString(static_cast<const char*>(field_348) + 0x40);
        Unk_TFXString globalTag("GlobalParameter:\n");
        s32 global = field_30.Unk_4520d0(globalTag.field_8, 0, globalTag.field_0);
        Unk_TFXString effectTag("Effect:\n");
        s32 effect = field_30.Unk_4520d0(effectTag.field_8, global, effectTag.field_0);
        if (global != 0) {
            global = field_30.Unk_4520d0("\n", global, -1);
            field_50 = field_30.Unk_452340(global, effect - 1);
            field_70 = true;
        }
        if (effect != 0) {
            effect = field_30.Unk_4520d0("\n", field_30.Unk_4520d0("\n", effect, -1) + 1, -1);
            field_60 = field_30.Unk_4522d0(effect, field_30.field_0);
        }
        if (global != 0 || effect != 0) {
            s32 effectEnd = effect != 0 ? effect - 1 : field_30.field_0;
            s32 globalEnd = global != 0 ? global - 1 : field_30.field_0;
            field_30.Unk_451530(effectEnd < globalEnd ? effectEnd : globalEnd);
        }
        field_370 = reinterpret_cast<Unk_TinyEntry*>(static_cast<char*>(field_348) + entries);
        field_378 = static_cast<char*>(field_348) + code;
    }
    field_3c0 = 0;
    field_2f1 = false;
    if (field_70) {
        Unk_TFXString text(field_50);
        Unk_TFXString countText = Token(&text, " \t\n\r", "//", "\"'", -1, -1, -1);
        s32 count = atoi(countText.field_8);
        u32 maxSize = 0;
        for (s32 i = 0; i < count; i++) {
            Unk_TFXString name = Token(&text, ", \t\n\r", "//", "\"'", -1, -1, -1);
            Unk_TFXString typeText = Token(&text, ", \t\n\r", "//", "\"'", -1, -1, -1);
            Unk_TFXString elementsText = Token(&text, ", \t\n\r", "//", "\"'", -1, -1, -1);
            s32 type = atoi(typeText.field_8);
            s32 elements = atoi(elementsText.field_8);
            CreateGlobalParameter(name, type, elements, false);
            s32 n = elements > 1 ? elements : 1;
            u32 bytes = Unk_ElementSize(type) * n;
            maxSize = static_cast<s32>(maxSize) > static_cast<s32>(bytes) ? maxSize : bytes;
        }
        field_3c0 = maxSize;
#line 7076
        field_3c8 = UNK_NEW_ARRAY(char, maxSize);
    }
    Unk_TFXString text(field_30);
    field_40 = Token(&text, " \t\n\r", "//", "\"'", -1, -1, -1);
    Unk_TFXString countText = Token(&text, " \t\n\r", "//", "\"'", -1, -1, -1);
    s32 count = atoi(countText.field_8);
    field_2f8.reserve(field_2f8.size() + count);
    for (s32 i = 0; i < count; i++) {
#line 7173
        Unk_TinyTechnique* technique = UNK_NEW(Unk_TinyTechnique)(this);
        field_2f8.push_back(technique);
    }
    text.CutLeft(" \t\n", -1);
    Unk_TFXString comma(",");
    Unk_TFXString spaces(" \t\n");
    s32 pos = 1;
    for (s32 i = 0; i < count; i++) {
        Unk_TinyTechnique* technique = field_2f8[i];
        s32 end = text.Unk_451dc0('\n', pos);
        if (end == 0) {
            end = text.field_0;
        }
        Unk_TFXString line = text.Unk_452340(pos, end - 1);
        line.CutLeft(" \t\n", -1);
        technique->field_8 = Token(&line, ",", nullptr, "\"'", -1, -1, -1);
        Unk_TFXString strLinkedProgramName;
        Unk_TFXString strLinkedProgramFile;
        Unk_TFXString strVertexProgramName = Token(&line, comma.field_8, "//", "\"'", -1, -1, -1);
        Unk_TFXString strVertexProgramFile = Token(&line, comma.field_8, "//", "\"'", -1, -1, -1);
        Unk_TFXString strFragmentProgramName = Token(&line, comma.field_8, "//", "\"'", -1, -1, -1);
        Unk_TFXString strFragmentProgramFile = Token(&line, comma.field_8, "//", "\"'", -1, -1, -1);
        strLinkedProgramName.Unk_452c00(spaces);
        strLinkedProgramName.Unk_452b30();
        strLinkedProgramFile.Unk_452c00(spaces);
        strLinkedProgramFile.Unk_452b30();
        strVertexProgramName.Unk_452c00(spaces);
        strVertexProgramName.Unk_452b30();
        strVertexProgramFile.Unk_452c00(spaces);
        strVertexProgramFile.Unk_452b30();
        strFragmentProgramName.Unk_452c00(spaces);
        strFragmentProgramName.Unk_452b30();
        strFragmentProgramFile.Unk_452c00(spaces);
        strFragmentProgramFile.Unk_452b30();
#line 7290
        PPFX_FX("pTechnique->m_strName: %s\n", technique->field_8.field_8);
        pos = end + 1;
        if (field_368 == 3) {
#line 7293
            PPFX_FX("strLinkedProgramName: %s\n", strLinkedProgramName.field_8);
            PPFX_FX("strLinkedProgramFile: %s\n", strLinkedProgramFile.field_8);
            PPFX_FX("strVertexProgramName: %s\n", strVertexProgramName.field_8);
            PPFX_FX("strFragmentProgramName: %s\n", strFragmentProgramName.field_8);
        } else {
#line 7300
            PPFX_FX("strVertexProgramName: %s\n", strVertexProgramName.field_8);
            PPFX_FX("strVertexProgramFile: %s\n", strVertexProgramFile.field_8);
            PPFX_FX("strFragmentProgramName: %s\n", strFragmentProgramName.field_8);
            PPFX_FX("strFragmentProgramFile: %s\n", strFragmentProgramFile.field_8);
        }
        Unk_TinyResult objects = Unk_24e2808;
        if (!(i != 0 & i != count - 1 & i != count / 2 | field_70 != 0)) {
            objects = Unk_TinyResult(nullptr, nullptr, nullptr);
        }
        Unk_TFXString programName = strVertexProgramName + " " + strFragmentProgramName;
        Unk_TFXString programFile = strVertexProgramFile + " " + strFragmentProgramFile;
        technique->field_1c = Unk_44c920(programName, programFile, 3, objects);
    }
    s32 passes = field_310.size();
    for (s32 i = 0; i < passes; i++) {
        CreateParameter(field_310[i], i);
    }
#line 7425
    PPFX_FX("\nm_apGlobalParameter.size(): %d\n", field_328.size());
    PPFX_FX("\n");
    u32 params = field_328.size();
    for (u32 i = 0; i < params; i++) {
#line 7430
        PPFX_FX("\n");
        Unk_TinyParam* param = field_328[i];
#line 7431
        PPFX_FX("m_apGlobalParameter[%d]->m_eType: %d: %s\n", i, param->field_1c,
                static_cast<u32>(param->field_1c) <= 4 ? Unk_238cf40[param->field_1c] : "invalid ETFXPARAMETERTYPE");
        PPFX_FX("m_apGlobalParameter[%d]->m_sizeOfElement: %d\n", i, param->field_20);
        PPFX_FX("m_apGlobalParameter[%d]->m_nElements: %d\n", i, param->field_2c);
        PPFX_FX("m_apGlobalParameter[%d]->m_sizeOfElement: %d\n", i, param->field_20);
        PPFX_FX("m_apGlobalParameter[%d]->m_strName: %s\n", i, param->field_8.field_8);
        PPFX_FX("m_apGlobalParameter[%d]->m_strElementName: %s\n", i, param->field_30.field_8);
        PPFX_FX("m_apGlobalParameter[%d]->m_pData: 0x%0x\n", i, param->field_48);
    }
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
    BuildEffect();
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

// a 4x4 matrix's numbers, copied as they are (placeholder)
struct Unk_TinyMatrix {
    u32 field_0[16];
};

// the matrix with its rows and columns swapped, into `out`
static inline void Unk_TransposeTo(u32* out, const Unk_TinyMatrix& matrix) {
    for (s32 row = 0; row < 4; row++) {
        for (s32 column = 0; column < 4; column++) {
            out[row * 4 + column] = matrix.field_0[column * 4 + row];
        }
    }
}

// 0x710044eac0
// NON_MATCHING: only the matrices' loop: loop strength reduction biases the
// source pointer by 0x20 here (`mov w9, #0x20`, loads at -0x20..0x18); the
// original counts the byte offset from 0. Tried: the matrix as one or two
// dimensional arrays, read through a pointer, memcpy, a reference, the
// transposed copy into a local first.
// The check of the kinds is a value tested for being negative (the original
// keeps `select(bad, sext(bad), result)`, csetm + csel), and the constants'
// size goes to the device as the fourth argument (it is in w4 on both
// paths).
s32 CTinyEffect::Unk_44eac0() {
    Unk_TinyTechnique* technique = field_2f8[field_380 - 1];
    Unk_TinyPass* pass = technique->field_0->field_310[technique->field_1c];
    if (field_3d0) {
        Unk_417a30("\n");
        Unk_417a30("technique name: %s\n", technique->field_8.field_8);
        Unk_417a30("  vertexprogram name:   %s\n", pass->field_8.field_8);
        Unk_417a30("  fragmentprogram name: %s\n", pass->field_8.field_8);
    }
    pass->field_18 = true;
    if (pass->field_30.field_0 == Unk_24e2808.field_0 && pass->field_30.field_8 == Unk_24e2808.field_8 &&
        pass->field_30.field_10 == Unk_24e2808.field_10) {
        s32 index = technique->field_1c;
        CreateProgram(pass);
        CreateParameter(pass, index);
    }
    s32 result = 0;
    s32 items = pass->field_70.size();
    for (s32 i = 0; i < items; i++) {
        s32 check;
        switch (pass->field_70[i]->field_30->field_1c) {
        case 1:
        case 2:
        case 3:
        case 4:
            check = 0;
            break;
        default:
            check = -1;
            break;
        }
        if (check < 0) {
            result = check;
        }
    }
    s32 constants = pass->field_88->field_28;
    char* buffer = nullptr;
    if (constants != 0) {
        buffer = field_78->vf72(1, 3, 0, constants);
    }
    Unk_SiGfxInterface* vertexSamplers[4] = {};
    Unk_SiGfxInterface* fragmentSamplers[16] = {};
    field_88.field_0 = pass;
    s32 count = pass->field_70.size();
    if (field_3d0) {
        Unk_417a30("\n");
        Unk_417a30("program: %s has %d parameters.\n", pass->field_8.field_8, count);
    }
    for (s32 i = 0; i < count; i++) {
        Unk_TinyPassItem* item = pass->field_70[i];
        if (item->field_38 < 1) {
            continue;
        }
        Unk_TinyParam* param = item->field_30;
        if (field_3d0) {
            Unk_417a30("\n");
            Unk_417a30("parameter %d/%d: %s.\n", i, count, item->field_8.field_8);
            switch (param->field_1c) {
            case 1:
                if (item->field_3c) {
                    Unk_417a30("float[%d]\n", item->field_38);
                } else {
                    Unk_417a30("float\n");
                }
                break;
            case 2:
                if (item->field_3c) {
                    Unk_417a30("float4[%d]\n", item->field_38);
                } else {
                    Unk_417a30("float4\n");
                }
                break;
            case 3:
                if (item->field_3c) {
                    Unk_417a30("float4x4[%d]\n", item->field_38);
                } else {
                    Unk_417a30("float4x4\n");
                }
                break;
            case 4:
                Unk_417a30("sampler\n");
                if (*static_cast<IGPUBaseTexture**>(param->field_48) == nullptr) {
                    Unk_417a30("  NULL texture.\n");
                } else {
                    Unk_417a30("pProgramParameter->m_iResourceIndex: %d\n", item->field_44);
                }
                break;
            default:
#line 9523
                PPFX_ERROR("Invalid pGlobalParameter->m_eType: %d: %s.\n", param->field_1c,
                           static_cast<u32>(param->field_1c) <= 4 ? Unk_238cf40[param->field_1c]
                                                                  : "invalid ETFXPARAMETERTYPE");
                break;
            }
        }
        switch (param->field_1c) {
        case 1: {
            char* data = buffer + item->field_48;
            if (!item->field_3c) {
                *reinterpret_cast<u32*>(data) = *static_cast<u32*>(param->field_48);
            } else {
                for (s32 j = 0; j < item->field_38; j++) {
                    u32* out = reinterpret_cast<u32*>(data + static_cast<s32>(param->field_24) * j);
                    *out = static_cast<u32*>(param->field_48)[j];
                }
            }
            break;
        }
        case 2:
            memcpy(buffer + item->field_48, param->field_48, item->field_38 * static_cast<s32>(param->field_24));
            break;
        case 3:
            for (s32 j = 0; j < item->field_38; j++) {
                u32* out = reinterpret_cast<u32*>(buffer + item->field_48 + static_cast<s32>(param->field_24) * j);
                Unk_TinyMatrix matrix = static_cast<Unk_TinyMatrix*>(param->field_48)[j];
                Unk_TransposeTo(out, matrix);
            }
            break;
        case 4: {
            Unk_SiGfxInterface* textures[16] = {};
            bool any = false;
            CManualProgramParameterTable::Unk_Item* binding = item->field_20;
            for (s32 j = 0; j < item->field_38; j++) {
                IGPUBaseTexture* texture = static_cast<IGPUBaseTexture**>(param->field_48)[j];
                if (texture != nullptr) {
                    textures[j] = *texture->field_70;
                    u32 resource = item->field_44;
                    if (binding->field_44 & 1) {
                        vertexSamplers[resource + j] = texture->Unk_447790();
                    }
                    if (binding->field_44 & 2) {
                        fragmentSamplers[resource + j] = texture->Unk_447790();
                    }
                    any = true;
                }
            }
            if (any) {
                if (binding->field_44 & 1) {
                    memcpy(&field_88.field_8[item->field_48], textures, item->field_38 * sizeof(Unk_SiGfxInterface*));
                }
                if (binding->field_44 & 2) {
                    memcpy(&field_88.field_28[item->field_48], textures, item->field_38 * sizeof(Unk_SiGfxInterface*));
                }
            }
            break;
        }
        default:
#line 10620
            PPFX_ERROR("Invalid pGlobalParameter->m_eType: %d: %s.\n", param->field_1c,
                       static_cast<u32>(param->field_1c) <= 4 ? Unk_238cf40[param->field_1c]
                                                              : "invalid ETFXPARAMETERTYPE");
            result = -1;
            break;
        }
    }
    for (s32 i = 0; i < 4; i++) {
        field_140.field_100[i] = vertexSamplers[i];
    }
    for (s32 i = 0; i < 16; i++) {
        field_140.field_120[i] = fragmentSamplers[i];
    }
    if (constants != 0) {
        field_78->vf73();
    }
    return result < 0 ? result : 0;
}

// 0x710044f250
// NON_MATCHING: the end of the first loop is `start + count` in the original
// (`add w8, w5, w6`) and `count + start` here, whichever way it is written.
// Copies of the two (`u32 first = start; u32 number = count;` after the
// defaults, used only by this loop) give the original, a difference of debug
// values alone.
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

// a texture as Unk_44f450 uses it (placeholder): slot 32 takes its sampler
struct Unk_TinyTexture : Unk_SiGfxInterface {
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
    virtual void vf26();
    virtual void vf27();
    virtual void vf28();
    virtual void vf29();
    virtual void vf30();
    virtual void vf31();
    virtual void vf32(Unk_SiGfxInterface* sampler);
};

// a pass's table of textures (or samplers), field_a0 and field_a8
// (placeholder): what the device's slot 27 makes
struct Unk_TinyTable : SiSDK3::ISiInterface {
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8(s32 arg1, s32 arg2);  // begins
    virtual void vf9();                   // ends
    virtual void vf10(s32 size);
    virtual void vf11();
    virtual void vf12(s32 index, Unk_SiGfxInterface* texture);  // sets one
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
    virtual void vf26();
    virtual void vf27(s32 index, Unk_SiGfxInterface* texture);  // and changes one
};

// a pass's descriptor set, field_98 (placeholder)
struct Unk_TinySet : SiSDK3::ISiInterface {
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8(SiSDK3::ISiInterface* signature);  // begins
    virtual void vf9(s32 count);
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13(s32 index, s32 range, SiSDK3::ISiInterface* table);
    virtual void vf14();
    virtual void vf15();
    virtual void vf16();  // ends
};

}  // namespace PPFX

// 0x710044f450: sets the applied pass's textures and samplers (the tables of
// them are made the first time)
// NON_MATCHING: a first version, the same calls and loops (1576 bytes against
// 1560): the original keeps the effect in x23 and the device only in x0
// (spilled), and unswitches the texture loops on `made` after computing the
// arrays' addresses once; the slot/range bookkeeping of the descriptor set
// is laid out differently. The texture and sampler numbers carried from one
// item to the next are uninitialised in the original too (registers that
// hold other values).
s32 Unk_44f450(void* self) {
    using namespace PPFX;
    CTinyEffect* effect = static_cast<CTinyEffect*>(self);
    Unk_TinyDevice* context = effect->field_78;
    Unk_TinyGfxDevice* device = reinterpret_cast<Unk_TinyGfxDevice*>(effect->field_80);
    if (context == nullptr || device == nullptr) {
        return -1;
    }
    Unk_TinyPass* pass = effect->field_88.field_0;
    CManualProgramParameterTable* program = pass->field_88;
    bool made = pass->field_c0;
    s32 vertexTextures = program->field_2c[0];
    s32 fragmentTextures = program->field_2c[1];
    s32 vertexSamplers = program->field_34[0];
    s32 fragmentSamplers = program->field_34[1];
    if (vertexTextures != 0 && vertexSamplers != 0) {
        Unk_TinyTable* table;
        if (made) {
            table = static_cast<Unk_TinyTable*>(pass->field_a0);
        } else {
            table = device->vf27(1, 0, nullptr);
            table->vf8(1, 0);
            s32 size = 0;
            s32 binding;
            s32 elements;
            for (u32 i = 0; i < static_cast<u32>(vertexTextures); i++) {
                CManualProgramParameterTable::Unk_Item* item = program->field_40[0][static_cast<s32>(i)];
                if (item != nullptr) {
                    binding = item->field_2c;
                    elements = item->field_24;
                }
                s32 end = binding + elements;
                size = size > end ? size : end;
            }
            table->vf10(size);
        }
        s32 first;
        s32 samplerFirst;
        s32 count;
        for (u32 i = 0; i < static_cast<u32>(vertexTextures); i++) {
            CManualProgramParameterTable::Unk_Item* item = program->field_40[0][static_cast<s32>(i)];
            if (item != nullptr) {
                first = item->field_2c;
            }
            CManualProgramParameterTable::Unk_Item* sampler = program->field_240[0][static_cast<s32>(i)];
            if (sampler != nullptr) {
                samplerFirst = sampler->field_2c;
                count = sampler->field_24;
            }
            for (s32 k = 0; k < count; k++) {
                static_cast<Unk_TinyTexture*>(effect->field_88.field_8[first + k])
                    ->vf32(effect->field_140.field_100[samplerFirst + k]);
                context->vf30(effect->field_88.field_8[first + k], 0x10, 0x100);
                if (made) {
                    table->vf27(first + k, effect->field_88.field_8[first + k]);
                } else {
                    table->vf12(first + k, effect->field_88.field_8[first + k]);
                }
            }
        }
        if (!made) {
            table->vf9();
            pass->field_a0 = table;
        }
        context->vf95(1, 0x10, 4, &effect->field_140.field_1a0);
    }
    if (fragmentTextures != 0 && fragmentSamplers != 0) {
        Unk_TinyTable* table;
        if (made) {
            table = static_cast<Unk_TinyTable*>(pass->field_a8);
        } else {
            table = device->vf27(1, 0, nullptr);
            table->vf8(1, 0);
            s32 size = 0;
            s32 binding;
            s32 elements;
            for (u32 i = 0; i < static_cast<u32>(fragmentTextures); i++) {
                CManualProgramParameterTable::Unk_Item* item = program->field_40[1][static_cast<s32>(i)];
                if (item != nullptr) {
                    binding = item->field_2c;
                    elements = item->field_24;
                }
                s32 end = binding + elements;
                size = size > end ? size : end;
            }
            table->vf10(size);
        }
        s32 first;
        s32 samplerFirst;
        s32 count;
        for (u32 i = 0; i < static_cast<u32>(fragmentTextures); i++) {
            CManualProgramParameterTable::Unk_Item* item = program->field_40[1][static_cast<s32>(i)];
            if (item != nullptr) {
                first = item->field_2c;
            }
            CManualProgramParameterTable::Unk_Item* sampler = program->field_240[1][static_cast<s32>(i)];
            if (sampler != nullptr) {
                samplerFirst = sampler->field_2c;
                count = sampler->field_24;
            }
            for (s32 k = 0; k < count; k++) {
                if (effect->field_88.field_28[first + k] != nullptr) {
                    static_cast<Unk_TinyTexture*>(effect->field_88.field_28[first + k])
                        ->vf32(effect->field_140.field_120[samplerFirst + k]);
                    context->vf30(effect->field_88.field_28[first + k], 0x10, 0x200);
                }
                if (made) {
                    table->vf27(first + k, effect->field_88.field_28[first + k]);
                } else {
                    table->vf12(first + k, effect->field_88.field_28[first + k]);
                }
            }
        }
        if (!made) {
            table->vf9();
            pass->field_a8 = table;
        }
    }
    Unk_TinySet* set = static_cast<Unk_TinySet*>(pass->field_98);
    s32 constants = pass->field_88->field_28;
    s32 index = constants != 0 ? 1 : 0;
    s32 range = index;
    if (!made) {
        set->vf8(pass->field_90);
        set->vf9(index + vertexTextures + fragmentTextures);
    }
    if (vertexTextures != 0) {
        SiSDK3::ISiInterface** tables = &pass->field_a0;
        for (u32 k = 0; k < static_cast<u32>(vertexTextures); k++) {
            set->vf13(index + k, range, tables[k]);
        }
        index += vertexTextures;
        range++;
    }
    if (fragmentTextures != 0) {
        SiSDK3::ISiInterface** tables = &pass->field_a8;
        for (u32 k = 0; k < static_cast<u32>(fragmentTextures); k++) {
            set->vf13(index + k, range, tables[k]);
        }
    }
    if (!made) {
        set->vf16();
    }
    pass->field_c0 = true;
    return 0;
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

// the kind of a uniform's type (1 to 3 numbers, 4 a texture, 10 an image;
// inline)
static inline s32 Unk_UniformKind(u32 type) {
    switch (type) {
    case 36: case 40:
        return 1;
    case 37: case 38: case 39: case 41: case 42: case 43:
        return 2;
    case 48: case 49: case 50: case 51: case 52: case 53: case 54: case 55: case 56:
        return 3;
    case 66: case 67: case 68: case 69: case 70: case 71: case 72: case 73: case 74: case 75: case 76: case 77: case 78: case 80: case 81: case 82: case 83: case 84: case 85: case 86: case 87: case 88: case 89: case 91: case 92: case 93: case 94: case 95: case 96: case 97: case 98: case 101: case 135: case 136: case 137: case 138:
        return 4;
    case 79: case 90: case 100: case 102: case 103: case 104: case 105: case 106: case 107: case 108: case 109: case 110: case 111: case 112: case 113: case 114: case 115: case 116: case 117: case 118: case 119: case 120: case 121: case 122: case 123: case 124: case 125: case 126: case 127: case 128: case 129: case 130: case 131: case 132: case 133: case 134:
        return 10;
    default:
        return 0;
    }
}

// the stages' bits and indices (placeholders)
static const u32 Unk_1aa18e0[2] = {1, 2};
static const s32 Unk_1aa1928[2] = {0, 1};

// 0x710044fca0: the uniforms of the pass's two programs: one item each (a
// texture's with its sampler, kind 10, after it), the stages that use them,
// and the textures' and samplers' tables
// NON_MATCHING: the original adds the stage's offset to `pass` in the loop
// (here `pass + 0x58` is computed once and spilled), keeps the texture's
// binding on the stack and `this + stage * 0x100` in x27 (the other way round
// here), and rereads the item count for the inner loop of the samplers' search;
// the rest differs by registers.
s32 CManualProgramParameterTable::Unk_44fca0(Unk_TinyPass* pass) {
    s32 index = 0;
    field_10.clear();
    s32 samplers[2] = {};
    s32 textures[2] = {};
    for (s32 stage = 0; stage < 2; stage++) {
        const Unk_ReflProgram* program = reinterpret_cast<const Unk_ReflProgram*>((&pass->field_58)[stage]);
        for (u32 i = 0; i < program->field_4c; i++) {
            const Unk_ReflTable* table = &program->field_90[i];
            if (table->field_8 != 3) {
                continue;
            }
            const u8* data = reinterpret_cast<const u8*>(program) + table->field_4;
            const char* strings = reinterpret_cast<const char*>(data + table->field_68);
            const Unk_ReflUniform* uniforms = reinterpret_cast<const Unk_ReflUniform*>(data + table->field_38);
            const Unk_ReflBlock* blocks = reinterpret_cast<const Unk_ReflBlock*>(data + table->field_30);
            for (u32 j = 0; j < table->field_2c; j++) {
                u32 size = blocks[j].field_2c;
                if (field_28 == 0) {
                    field_28 = blocks[j].field_28;
                }
                if (stage == 0) {
                    field_10.reserve(size);
                }
            }
            for (u32 j = 0; j < table->field_34; j++) {
                const Unk_ReflUniform* uniform = &uniforms[j];
                const char* name = strings + uniform->field_0;
                const char* member = strchr(name, '.');
                char buffer[0x100];
                memset(buffer, 0, sizeof(buffer));
                memcpy(buffer, name, uniform->field_4);
                if (member != nullptr) {
                    memset(buffer, 0, sizeof(buffer));
                    strcpy(buffer, member + 1);
                }
                const char* bracket = strchr(buffer, '[');
                if (bracket != nullptr) {
                    size_t length = strlen(bracket);
                    size_t count = strlen(buffer) - length;
                    char base[0x100];
                    memset(base, 0, sizeof(base));
                    strncpy(base, buffer, count);
                    memset(buffer, 0, sizeof(buffer));
                    strcpy(buffer, base);
                }
                u32 used = uniform->field_44;
                u32 type = uniform->field_28;
                s32 a = uniform->field_2c;
                s32 b = uniform->field_30;
                s32 count = uniform->field_34;
                Unk_Item* item = nullptr;
                if (stage != 0) {
                    s32 found = -1;
                    for (u32 k = 0; k < field_10.size(); k++) {
                        if (field_10[k]->field_8 == buffer) {
                            found = k;
                            break;
                        }
                    }
                    if (found >= 0) {
                        item = field_10[found];
                    }
                }
                if (item != nullptr) {
                    if (!item->field_18) {
                        item->field_18 = used != 0;
                    }
                    item->field_44 = Unk_1aa18e0[stage];
                    continue;
                }
#line 13439
                item = UNK_NEW(Unk_Item)(pass->field_0);
                field_10.push_back(item);
                item->field_1c = index;
                s32 next = index + 1;
                item->field_40 = 1;
                item->field_8 = buffer;
                item->field_24 = count;
                item->field_28 = -1;
                item->field_20 = Unk_UniformKind(type);
                item->field_2c = a;
                item->field_30 = b;
                item->field_18 = used != 0;
                item->field_44 = Unk_1aa18e0[stage];
                switch (item->field_20 & 0xf) {
                case 1:
                case 2:
                case 3:
                    item->field_40 = 1;
                    index = next;
                    break;
                case 4: {
                    s32 binding = uniform->field_48[Unk_1aa1928[stage]];
                    item->field_40 = 2;
                    item->field_2c = binding;
                    item->field_30 = -1;
                    field_240[stage][textures[stage]++] = item;
#line 13501
                    Unk_Item* sampler = UNK_NEW(Unk_Item)(pass->field_0);
                    sampler->field_1c = next;
                    index += 2;
                    field_10.push_back(sampler);
                    sampler->field_20 = 10;
                    sampler->field_24 = count;
                    sampler->field_28 = -1;
                    sampler->field_2c = binding;
                    sampler->field_30 = -1;
                    sampler->field_40 = 2;
                    sampler->field_44 = Unk_1aa18e0[stage];
                    sampler->field_18 = used != 0;
                    field_40[stage][samplers[stage]++] = sampler;
                    break;
                }
                default:
                    index = next;
                    break;
                }
            }
        }
    }
    s32 texture = 0;
    for (u32 i = 0; i < static_cast<u32>(field_10.size()); i++) {
        Unk_Item* item = field_10[i];
        if (item->field_20 != 4) {
            continue;
        }
        s32 sampler = 0;
        for (u32 j = 0; j < static_cast<u32>(field_10.size()); j++) {
            if (field_10[j]->field_20 == 10) {
                if (texture == sampler) {
                    item->field_30 = field_10[j]->field_2c;
                    break;
                }
                sampler++;
            }
        }
        texture++;
    }
    memcpy(field_2c, samplers, sizeof(field_2c));
    memcpy(field_34, textures, sizeof(field_34));
    return 0;
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
