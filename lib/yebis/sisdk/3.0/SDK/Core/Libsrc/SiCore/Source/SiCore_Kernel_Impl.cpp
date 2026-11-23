// Scope: common
// SiSDK3::SiKernel: the string tables, report handlers and indexed allocators
// it keeps. Its small accessors are lib/yebis/class's.
#define UNK_SIKERNEL_DEFINE
#define UNK_SIMAP_MEMBERS_DEFINE
#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiCore/Source/SiCore_Kernel_Impl.h>

#include <stdlib.h>
#include <time.h>

#include <nn/os.h>

#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/Unk_4be540_arg1.h>
#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/Unk_StringFuncs.h>

namespace nn {
namespace time {
Result Initialize() noexcept;
Result Finalize() noexcept;
}  // namespace time
}  // namespace nn

namespace SiSDK3 {
class SiHeapAllocator;
}

// 0x71024e8f38: the static allocator (Unk_4c2cd0.cpp)
extern SiSDK3::SiHeapAllocator Unk_24e8f38;

// 0x71004c3360: the CRC table
void Unk_4c3360();
// 0x71004c5930: a number's digits, in groups of three
bool Unk_4c5930(char* dst, size_t size, u64 value);
// 0x71004c9300, 0x71004ca6a0: set up the tick's period and the noise tables
void Unk_4c9300();
void Unk_4ca6a0();
// 0x71004ca820: what a language's name is looked up by
const SiSDK3::ISiStringTable::Unk_Item* Unk_4ca820(const Unk_4ca820_arg0& language);

// 0x7101eea8cc: the id of the kernel's own string table
extern const SiSDK3::SI_GUID Unk_1eea8cc __attribute__((visibility("hidden")));

// 0x71024e8f28: the kernel there is (lib/yebis/leaf's Unk_4bf7b0_get, this
// TU's, returns it)
SiSDK3::SiKernel* Unk_24e8f28 __attribute__((visibility("hidden")));

// 0x71004bf730: the kernel, constructed where it is first asked for
SiSDK3::SiKernel* Unk_4bf730() {
    static SiSDK3::SiKernel kernel;
    return &kernel;
}

namespace SiSDK3 {

// 0x71004bf7c0
SiKernel::SiKernel()
    : field_8(nullptr), field_18(0), field_48(nullptr), field_480(0), field_484(true), field_488(nullptr),
      field_490(nullptr), field_668(0), field_670(0), field_ec8(0) {
    field_487 = false;
    field_486 = false;
    field_485 = false;
    memset(field_50, 0, sizeof(field_50));
    memset(field_6c8, 0, sizeof(field_6c8));
    field_1048 = nullptr;
    field_1050 = nullptr;
    field_678.Unk_SetBuffer(field_6c8, 0x100);
    Unk_24e8f28 = this;
}

// 0x71004bfa80, 0x71004bff90
SiKernel::~SiKernel() {
    Unk_24e8f28 = nullptr;
}

// 0x71004bffc0
bool SiKernel::Unk_4bffc0(ISiAllocator* pAllocator) {
    field_18++;
    if (field_18 != 1) {
        return true;
    }
    Unk_4c3360();
    if (pAllocator != nullptr) {
        vf11(pAllocator);
    } else {
        vf11(reinterpret_cast<ISiAllocator*>(&Unk_24e8f38));
    }
    Unk_4c0390(vf12());

    ISiAllocator* pMapAllocator = vf12();
    if (pMapAllocator != nullptr) {
        Unk_SetMapAllocator(pMapAllocator);
    } else {
        Unk_SetMapAllocator(reinterpret_cast<ISiAllocator*>(&Unk_24e8f38));
    }

    field_490.Unk_4c8b50(vf12());
    Unk_SetTablesAllocator(vf12());

    field_ec8 = vf23(nullptr);
    field_ec8->vf8();
    field_ec8->vf11(Unk_4ca820_arg0(), Unk_4ca820(Unk_4ca820_arg0()));
    field_ec8->vf11(*vf24(), Unk_4ca820(*vf24()));
    field_ec8->vf9();
    vf26(&Unk_1eea8cc, field_ec8);
    {
        Unk_4c87b0 lock(&field_20, true);
        field_ed0.Unk_SetAllocator(vf12());
    }
    nn::time::Initialize();
    field_490.vf7();
    Unk_4c9300();
    field_490.vf6();

    Unk_4be540_arg1 info;
    field_488->vf11(&info);
    char used[0x80];
    Unk_4c5930(used, sizeof(used), info.field_8);
    char total[0x80];
    Unk_4c5930(total, sizeof(total), info.field_28);

    srand(time(nullptr));
    Unk_4ca6a0();
    return true;
}

// 0x71004c0390
bool SiKernel::Unk_4c0390(ISiAllocator* pAllocator) {
    field_fe8.Unk_SetAllocator(pAllocator);
    field_1018.Unk_SetAllocator(pAllocator);
    return true;
}

// 0x71004c04e0
void SiKernel::Unk_4c04e0() {
    if (field_18 == 0) {
        return;
    }
    field_18--;
    if (field_18 != 0) {
        return;
    }
    field_450.Unk_EmptyAll();
    for (size_t i = 0; i < field_f20.m_itemCount; i++) {
        ISiAllocator* pAllocator = field_f20.m_pData[i];
        if (pAllocator != nullptr) {
            field_f20.m_pData[i] = nullptr;
            pAllocator->vf3();
        }
    }
    field_f20.Unk_FreeAll();
    vf35();
    field_ed0.Unk_FreeAll();
    vf27(field_ec8);
    if (field_ec8 != nullptr) {
        field_ec8->vf3();
        field_ec8 = nullptr;
    }
    vf28();
    field_678.Unk_FreeAll();
    nn::time::Finalize();
    Unk_4c06f0();
    if (field_488 != nullptr) {
        field_488->vf3();
        field_488 = nullptr;
    }
}

// 0x71004c06f0
void SiKernel::Unk_4c06f0() {
    if (field_1048 != nullptr) {
        fclose(field_1048);
        field_1048 = nullptr;
    }
    if (field_1050 != nullptr) {
        fclose(field_1050);
        field_1050 = nullptr;
    }
    field_fe8.Unk_EmptyAll();
    field_1018.Unk_EmptyAll();
}

// 0x71004c0910
void SiKernel::Unk_4c0910(SiReflectionObject* object) {
    field_f70.Unk_4c09a0(object->Unk_GetName(), object);
    field_f98.Unk_FreeAll();
}

// 0x71004c0d60
void SiKernel::Unk_4c0d60(SiReflectionObject* object) {
    SiMap<const char*, SiReflectionObject*, ReflectionCompare, 16>::Unk_Iterator position =
        field_f70.Unk_Find(object->Unk_GetName());
    if (position.m_pNode != nullptr) {
        field_f70.Unk_4c0e60(position);
    }
    field_f98.Unk_FreeAll();
}

// 0x71004c14f0
SiReflectionObject* SiKernel::vf19(const char* name) {
    SiMap<const char*, SiReflectionObject*, ReflectionCompare, 16>::Unk_Iterator position = field_f70.Unk_Find(name);
    if (position.m_pNode == nullptr) {
        return nullptr;
    }
    return position.m_pNode->m_value;
}

// 0x71004c1590 (the walk advances its node by reference: Unk_AdvanceNode)
int SiKernel::vf20() {
    typedef SiMap<const char*, SiReflectionObject*, ReflectionCompare, 16> Unk_Map;
    if (field_f98.m_itemCount != field_f70.m_count) {
        field_f98.Unk_FreeAll();
        field_f98.Unk_ReserveAtLeast(field_f70.m_count);
        for (Unk_Map::Unk_Node* pNode = field_f70.m_pRoot; pNode != nullptr; Unk_Map::Unk_AdvanceNode(pNode)) {
            field_f98.Unk_Add(pNode->m_value);
        }
    }
    return static_cast<int>(field_f98.m_itemCount);
}

// 0x71004c0820
void SiKernel::vf11(ISiAllocator* pAllocator) {
    if (pAllocator != nullptr) {
        pAllocator->vf2();
    }
    if (field_488 != nullptr) {
        field_488->vf3();
    }
    field_488 = pAllocator;
    if (pAllocator == nullptr) {
        field_488 = reinterpret_cast<ISiAllocator*>(&Unk_24e8f38);
        field_488->vf2();
    }
    field_f20.Unk_SetAllocator(field_488);
}

// 0x71004c17a0
SiString<char> SiKernel::vf13() {
    return SiString<char>();
}

// 0x71004c1890
SI_GUID SiKernel::vf14() {
    SI_GUID id = {};
    return id;
}

// 0x71004c1760
SiReflectionObject* SiKernel::vf21(int index) {
    return field_f98.m_pData[index];
}

// 0x71004c1800
SiStringTable* SiKernel::vf23(ISiAllocator* pAllocator) {
    if (pAllocator == nullptr) {
        pAllocator = vf12();
    }
#line 1092
    return UNK_SI_NEW(pAllocator, 0x10) SiStringTable(pAllocator);
}

// 0x71004c18a0
bool SiKernel::vf26(const SI_GUID* id, SiStringTable* table) {
    Unk_4c87b0 lock(&field_20, true);
    if (vf29(id) != nullptr) {
        return false;
    }
    table->Unk_4c70f0(id);
    field_678.Unk_Add(table);
    table->vf2();
    return true;
}

// 0x71004c19b0
bool SiKernel::vf27(SiStringTable* table) {
    Unk_4c87b0 lock(&field_20, true);
    field_678.Unk_RemoveValue(table);
    if (table != nullptr) {
        table->vf3();
    }
    return true;
}

// 0x71004c1ac0
void SiKernel::vf28() {
    Unk_4c87b0 lock(&field_20, true);
    for (size_t i = 0; i < field_678.m_itemCount; i++) {
        SiStringTable* table = field_678.m_pData[i];
        if (table != nullptr) {
            field_678.m_pData[i] = nullptr;
            table->vf3();
        }
    }
    field_678.Unk_FreeAll();
}

// 0x71004c1b90
SiStringTable* SiKernel::vf29(const SI_GUID* id) {
    for (s64 i = 0; i < static_cast<int>(field_678.m_itemCount); i++) {
        SiStringTable* table = field_678.m_pData[i];
        if (Unk_4c8f80(table->vf5(), id)) {
            return table;
        }
    }
    return nullptr;
}

// 0x71004c1c10
SiStringTable* SiKernel::vf30(const SI_GUID* id) {
    for (s64 i = 0; i < static_cast<int>(field_678.m_itemCount); i++) {
        SiStringTable* table = field_678.m_pData[i];
        if (Unk_4c8f80(table->vf5(), id)) {
            return table;
        }
    }
    return nullptr;
}

// 0x71004c1c90
const char* SiKernel::vf31(const SI_GUID* id, int string) {
    SiStringTable* table = vf30(id);
    if (table == nullptr) {
        return nullptr;
    }
    return Unk_StringCStr(&table->vf14(string));
}

// 0x71004c1ce0
void SiKernel::vf32(int level, const char* text) {
    Unk_4c87b0 lock(&field_20, true);
    char buffer[0x400 + 4];  // (0x404 bytes on the stack, 0x400 of them for the text)
    if (field_1050 != nullptr) {
        Unk_4c51e0(text, buffer, 0x400);
        fputs(buffer, field_1050);
    }
    for (s64 i = 0; i < static_cast<int>(field_ed0.m_itemCount); i++) {
        field_ed0.m_pData[i]->vf5(level, text);
    }
}

// 0x71004c1da0
bool SiKernel::vf33(ISiKernel::IReportUserHandler* handler) {
    Unk_4c87b0 lock(&field_20, true);
    field_ed0.Unk_Add(handler);
    handler->vf2();
    return true;
}

// 0x71004c1e70
void SiKernel::vf34(ISiKernel::IReportUserHandler* handler) {
    Unk_4c87b0 lock(&field_20, true);
    field_ed0.Unk_RemoveValue(handler);
    if (handler != nullptr) {
        handler->vf3();
    }
}

// 0x71004c1f80
void SiKernel::vf35() {
    Unk_4c87b0 lock(&field_20, true);
    for (size_t i = 0; i < field_ed0.m_itemCount; i++) {
        ISiKernel::IReportUserHandler* handler = field_ed0.m_pData[i];
        if (handler != nullptr) {
            field_ed0.m_pData[i] = nullptr;
            handler->vf3();
        }
    }
    field_ed0.Unk_FreeAll();
}

// 0x71004c2050
int SiKernel::vf36() {
    if (field_1048 != nullptr) {
        fclose(field_1048);
        field_1048 = nullptr;
    }
    return 0;
}

// 0x71004c2090
int SiKernel::vf38() {
    if (field_1050 != nullptr) {
        fclose(field_1050);
        field_1050 = nullptr;
    }
    return 0;
}

// 0x71004c20d0
bool SiKernel::vf40(int count) {
    int oldCount = static_cast<int>(field_f20.m_itemCount);
    if (!field_f20.Unk_SetCount(count)) {
        return false;
    }
    for (int i = oldCount; i < count; i++) {
        field_f20.m_pData[i] = nullptr;
    }
    return true;
}

// 0x71004c2210
bool SiKernel::vf42(int index, ISiAllocator* pAllocator) {
    if (index < 0) {
        return false;
    }
    if (static_cast<int>(field_f20.m_itemCount) <= index) {
        return false;
    }
    if (pAllocator != nullptr) {
        pAllocator->vf2();
    }
    if (field_f20.m_pData[index] != nullptr) {
        field_f20.m_pData[index]->vf3();
    }
    field_f20.m_pData[index] = pAllocator;
    return true;
}

// 0x71004c22c0
ISiAllocator* SiKernel::vf43(int index) {
    if (index < 0) {
        return nullptr;
    }
    if (static_cast<int>(field_f20.m_itemCount) <= index) {
        return nullptr;
    }
    return field_f20.m_pData[index];
}

// 0x71004c22f0
ISiAllocator* SiKernel::vf44(int index) {
    if (index < 0) {
        return nullptr;
    }
    if (static_cast<int>(field_f20.m_itemCount) <= index) {
        return nullptr;
    }
    return field_f20.m_pData[index];
}

}  // namespace SiSDK3
