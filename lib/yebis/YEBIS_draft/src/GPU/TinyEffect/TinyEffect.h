// PPFX::CTinyEffect and PPFX::CManualProgramParameterTable (RTTI names them;
// C:/workspace/YEBIS_draft/src/GPU/TinyEffect/TinyEffect.cpp is this
// translation unit, 0x710044ab80 to 0x7100450eb0), as far as the functions
// written so far read them. The members are placeholders; the virtual
// functions are vf<slot>, as lib/yebis/class names the ones it has.
#pragma once

#include <vector>

#include <types.h>
#include <yebis/YEBIS_draft/src/GPU/GPUMemoryAllocator.h>
#include <yebis/YEBIS_draft/src/GPU/TinyEffect/TFXString.h>
#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/Unk_Interface.h>

// 0x71024e2730, 0x71024e2734, 0x71024e2738, 0x71024e273c: the sizes of a
// parameter's elements, by kind
extern u32 Unk_24e2730;
extern u32 Unk_24e2734;
extern u32 Unk_24e2738;
extern u32 Unk_24e273c;

namespace PPFX {

class CTinyEffect;

// what vf20 and vf21 return: a pass's three device objects
struct Unk_TinyResult {
    Unk_TinyResult() {}
    Unk_TinyResult(SiSDK3::ISiInterface* a, SiSDK3::ISiInterface* b, SiSDK3::ISiInterface* c)
        : field_0(a), field_8(b), field_10(c) {}
    Unk_TinyResult(const Unk_TinyResult& other)
        : field_0(other.field_0), field_8(other.field_8), field_10(other.field_10) {}
    Unk_TinyResult& operator=(const Unk_TinyResult& other) {
        field_0 = other.field_0;
        field_8 = other.field_8;
        field_10 = other.field_10;
        return *this;
    }

    SiSDK3::ISiInterface* field_0;
    SiSDK3::ISiInterface* field_8;
    SiSDK3::ISiInterface* field_10;
};
PKMN_SIZE_ASSERT(Unk_TinyResult, 0x18);

// a technique (field_2f8's elements)
struct Unk_TinyTechnique {
    CTinyEffect* field_0;
    Unk_TFXString field_8;  // the name
    bool field_18;
    u8 pad_19[0x3];
    s32 field_1c;  // its pass, in field_310
};
PKMN_SIZE_ASSERT(Unk_TinyTechnique, 0x20);

// what a pass keeps in field_70 (placeholder)
struct Unk_TinyPassItem {
    u64 field_0;
    Unk_TFXString field_8;
};

// an entry of field_370 (placeholder): a name and two numbers as text
struct Unk_TinyEntry {
    char field_0[0xe0];   // the name
    char field_e0[0x10];  // an offset in field_378
    char field_f0[0x10];  // a size
};
PKMN_SIZE_ASSERT(Unk_TinyEntry, 0x100);

// a resource of a pass's program, as CreateSiGfxProgramResources reads it
// (placeholder)
struct Unk_TinyBinding {
    u8 pad_0[0x24];
    s32 field_24;
    u8 pad_28[0x4];
    s32 field_2c;
};

// an object passes share, counted (placeholder): their program's resources
struct Unk_TinyShared {
    virtual ~Unk_TinyShared();
    s32 field_8;
    u8 pad_c[0x1c];
    s32 field_28;  // whether it has constants
    s32 field_2c;  // the number of field_40's
    s32 field_30;  // the number of field_140's
    s32 field_34;
    s32 field_38;
    u8 pad_3c[0x4];
    Unk_TinyBinding* field_40[32];
    Unk_TinyBinding* field_140[32];
};
PKMN_OFFSET_ASSERT(Unk_TinyShared, field_140, 0x140);

// what a pass is made from (placeholder): its programs' names and objects,
// the base of a pass (the part CreateProgram fills in)
struct Unk_TinyProgram {
    Unk_TinyProgram(CTinyEffect* effect) : field_0(effect), field_8(""), field_18(false) {
        field_20 = "";
        field_30.field_0 = nullptr;
        field_30.field_8 = nullptr;
        field_30.field_10 = nullptr;
        field_48 = 0;
        field_4c = 0;
        field_50 = 0;
        field_58 = nullptr;
        field_60 = nullptr;
    }

    CTinyEffect* field_0;
    Unk_TFXString field_8;  // the name
    bool field_18;
    u8 pad_19[0x7];
    Unk_TFXString field_20;  // the code's name
    Unk_TinyResult field_30;
    u32 field_48;
    u32 field_4c;  // the sizes of the vertex and fragment code
    u32 field_50;
    u8 pad_54[0x4];
    const char* field_58;  // the vertex and fragment code
    const char* field_60;
};
PKMN_SIZE_ASSERT(Unk_TinyProgram, 0x68);

// a pass (field_310's elements)
struct Unk_TinyPass : Unk_TinyProgram {
    Unk_TinyPass(CTinyEffect* effect)
        : Unk_TinyProgram(effect), field_68(false), field_88(nullptr), field_90(nullptr), field_98(nullptr),
          field_c0(false) {}
    // a pass for `program`
    Unk_TinyPass(CTinyEffect* effect, const Unk_TinyProgram& program)
        : Unk_TinyProgram(effect), field_68(false), field_88(nullptr), field_90(nullptr), field_98(nullptr),
          field_c0(false) {
        field_8 = program.field_8.field_8;
        field_20 = program.field_20;
        field_30 = program.field_30;
        field_48 = program.field_48;
    }
    ~Unk_TinyPass() { Unk_44ab80(); }
    s32 Unk_44ab80();  // 0x710044ab80: releases its device objects

    bool field_68;
    u8 pad_69[0x7];
    std::vector<Unk_TinyPassItem*, Unk_StlAllocator<Unk_TinyPassItem*>> field_70;
    Unk_TinyShared* field_88;
    SiSDK3::ISiInterface* field_90;
    SiSDK3::ISiInterface* field_98;
    // the device objects made for it
    SiSDK3::ISiInterface* field_a0;
    SiSDK3::ISiInterface* field_a8;
    SiSDK3::ISiInterface* field_b0;
    SiSDK3::ISiInterface* field_b8;
    bool field_c0;  // they are made
};
PKMN_OFFSET_ASSERT(Unk_TinyPass, field_30, 0x30);
PKMN_OFFSET_ASSERT(Unk_TinyPass, field_70, 0x70);
PKMN_OFFSET_ASSERT(Unk_TinyPass, field_c0, 0xc0);

// a parameter (field_328's elements)
struct Unk_TinyParam {
    Unk_TinyParam(CTinyEffect* effect)
        : field_0(effect), field_8(""), field_18(false), field_40(false), field_41(false), field_48(nullptr) {
        field_1c = 0;
    }

    CTinyEffect* field_0;
    Unk_TFXString field_8;  // the name
    bool field_18;
    u8 pad_19[0x3];
    s32 field_1c;   // the kind: 1 to 3 numbers, 4 an object
    u32 field_20;   // the size in bytes
    u32 field_24;
    u32 field_28;
    u32 field_2c;   // the number of elements
    Unk_TFXString field_30;  // the semantic (the element's name)
    bool field_40;  // field_48 is the parameter's own
    bool field_41;  // an element of an array
    u8 pad_42[0x6];
    void* field_48;  // the value

    ~Unk_TinyParam() {
        if (field_40 && field_48 != nullptr) {
            Unk_4b9a60(Unk_238d5f8, static_cast<u64*>(field_48) - 1);
        }
        field_40 = false;
        field_48 = nullptr;
        field_1c = 0;
    }
};
PKMN_OFFSET_ASSERT(Unk_TinyParam, field_48, 0x48);

class IGPUBuffer;

// the vertex inputs' layout as ApplyVertexInputs reads it (placeholder)
struct Unk_TinyLayout {
    u8 pad_0[0x78];
    void* field_78;  // its SiGfx object
};

// the vertex buffers ApplyVertexInputs sets, their offsets and strides, and
// what follows them
struct Unk_TinyInputs {
    void* field_0[16];
    u32 field_80[16];
    u32 field_c0[16];
    u8 field_100[0xa4];
    u32 field_1a4;
    u32 field_1a8;
    u32 field_1ac;
};
PKMN_SIZE_ASSERT(Unk_TinyInputs, 0x1b0);

// the device an effect is made for, as it uses it (placeholder)
struct Unk_TinyDevice {
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual u64 vf5();
};

// The bases RTTI names (__CTinyEffect, CInheritanceTypedReferenceManager<
// __CTinyEffect>): the interface, and the count of references, which the
// manager's constructor sets before CTinyEffect's vtable is stored. Their
// vtables aren't in the executable; the virtual functions are CTinyEffect's.
class __CTinyEffect {
public:
    virtual ~__CTinyEffect() {}
};

template <class T>
class CInheritanceTypedReferenceManager : public T {
public:
    CInheritanceTypedReferenceManager() : field_8(1) {}

    s32 field_8;  // references
};

class CTinyEffect : public CInheritanceTypedReferenceManager<__CTinyEffect> {
public:
    typedef std::vector<Unk_TinyTechnique*, Unk_StlAllocator<Unk_TinyTechnique*>> Unk_Techniques;
    typedef std::vector<Unk_TinyPass*, Unk_StlAllocator<Unk_TinyPass*>> Unk_Passes;
    typedef std::vector<Unk_TinyParam*, Unk_StlAllocator<Unk_TinyParam*>> Unk_Params;

    CTinyEffect();           // 0x710044ad90
    ~CTinyEffect() override;  // 0x710044aed0, 0x710044b1a0
    virtual u32 vf2();
    virtual s32 vf3();
    virtual s32 vf4(const char* name);                       // a parameter's handle
    virtual s32 vf5(const char* name);                       // a technique's handle
    virtual u32 vf6(u32 value);
    virtual const char* vf7(s32 technique);                  // its name
    virtual s32 vf8(s32 handle, f32 value);
    virtual s32 vf9(s32 handle, const void* values, u32 count);
    virtual s32 vf10(s32 handle, const void* value);
    virtual s32 vf11(s32 handle, void* value);
    virtual s32 vf12(s32 handle, const void* values, u32 count);
    virtual s32 vf13(s32 handle, void* values, u32 count);
    virtual s32 vf14(s32 handle, const void* value);
    virtual s32 vf15(s32 handle, const void* values, u32 count);
    virtual s32 vf16(s32 handle, void* object);
    virtual s32 vf17(s32 technique);  // whether it has a pass
    virtual s32 vf18(s32 technique);  // makes it the current one
    virtual u32 vf19();
    virtual Unk_TinyResult vf20(s32 technique);
    virtual Unk_TinyResult vf21(s32 technique);
    virtual s32 vf22(u32* passes, u32 flags);
    virtual u32 vf23();
    virtual s32 vf24(u32 pass);
    virtual u32 vf25();
    // 0x710044f250 (its log line names it)
    virtual s32 ApplyVertexInputs(Unk_TinyLayout* layout, IGPUBuffer** buffers, const u32* offsets,
                                  const u32* strides, u32 start, u32 count);

    s32 Unk_44afa0();                                  // 0x710044afa0: releases everything
    s32 Unk_44b1d0(const char* name, bool semantic);  // 0x710044b1d0: a parameter's index
    s32 Unk_44b380(const char* name);                  // 0x710044b380: a technique's index
    s32 Unk_44eac0();                                  // 0x710044eac0: applies the pass
    void Unk_44def0();                                 // 0x710044def0: releases the passes' objects
    // 0x710044dbc0 (its log line names it); `share`: field_348 is `data` itself
    s32 CreateFromMemory(const void* data, Unk_TinyDevice* device, bool share);
    s32 Unk_44cbd0();  // 0x710044cbd0: reads the effect
    // 0x710044c060 (its log lines name it)
    s32 CreateSiGfxProgramResources(Unk_TinyPass* pass);
    // 0x710044bbd0 (its log line names it): `elements` parameters (one if
    // 0) named `name`, or the one that has the name if `find`
    s32 CreateGlobalParameter(const Unk_TFXString& name, s32 type, s32 elements, bool find);
    // 0x710044c370 (its log lines name it): makes the program's objects
    s32 CreateProgram(Unk_TinyProgram* program);
    // 0x710044c920: the pass that runs `code` (a new one unless `objects` are
    // already made), its index
    s32 Unk_44c920(const Unk_TFXString& name, const Unk_TFXString& code, u32 arg, const Unk_TinyResult* objects);
    // the pass that runs `code` (-1 if none)
    s32 Unk_FindPass(const char* code) const {
        s32 index = -1;
        for (u32 i = 0; i < field_310.size(); i++) {
            if (field_310[i]->field_20 == code) {
                index = i;
                break;
            }
        }
        return index;
    }

    // a parameter by its handle (counted from 1)
    bool Unk_IsParam(s32 handle) const { return handle >= 1 && handle <= static_cast<s32>(field_328.size()); }

    u8 pad_c[0x4];
    Unk_TFXString field_10;
    Unk_TFXString field_20;
    Unk_TFXString field_30;
    Unk_TFXString field_40;
    Unk_TFXString field_50;
    Unk_TFXString field_60;
    u8 pad_70[0x8];
    Unk_TinyDevice* field_78;
    u64 field_80;
    u64 field_88[0x15];
    void* field_130;  // the vertex inputs' layout (its SiGfx object)
    u32 field_138;    // the number of vertex buffers
    u32 field_13c;    // the first one
    Unk_TinyInputs field_140;
    bool field_2f0;
    bool field_2f1;  // field_328 is sorted by name
    u8 pad_2f2[0x6];
    Unk_Techniques field_2f8;
    Unk_Passes field_310;
    Unk_Params field_328;
    bool field_340;  // field_348 is the effect's own
    u8 pad_341[0x7];
    void* field_348;
    s32 field_350;  // the number of field_370's entries
    u8 pad_354[0x4];
    Unk_TFXString field_358;
    u8 pad_368[0x8];
    Unk_TinyEntry* field_370;
    char* field_378;
    s32 field_380;  // the current technique
    u32 field_384;  // the number of passes
    u32 field_388;
    u32 field_38c;  // the current pass
    Unk_TFXString field_390;
    Unk_TFXString field_3a0;
    Unk_TFXString field_3b0;
    u32 field_3c0;
    u8 pad_3c4[0x4];
    char* field_3c8;
    bool field_3d0;
    u8 pad_3d1[0x7];
};
PKMN_SIZE_ASSERT(CTinyEffect, 0x3d8);
PKMN_OFFSET_ASSERT(CTinyEffect, field_2f8, 0x2f8);
PKMN_OFFSET_ASSERT(CTinyEffect, field_328, 0x328);
PKMN_OFFSET_ASSERT(CTinyEffect, field_380, 0x380);
PKMN_OFFSET_ASSERT(CTinyEffect, field_3b0, 0x3b0);

class CManualProgramParameterTable {
public:
    struct Unk_Item {
        u64 field_0;
        Unk_TFXString field_8;
    };
    typedef std::vector<Unk_Item*, Unk_StlAllocator<Unk_Item*>> Unk_Items;

    virtual ~CManualProgramParameterTable();  // 0x710044fb30, 0x710044fbf0

    u64 field_8;
    Unk_Items field_10;
};
PKMN_OFFSET_ASSERT(CManualProgramParameterTable, field_10, 0x10);

}  // namespace PPFX
