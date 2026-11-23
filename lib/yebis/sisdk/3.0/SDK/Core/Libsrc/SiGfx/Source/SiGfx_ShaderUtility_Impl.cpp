// Scope: common
// SiSDK3::SiGfxShaderUtility: its constructor and destructors, the lists of
// shader effect packages and binary cache packages. The reference counts are
// its header's.
#define UNK_SIGFX_SHADERUTILITY_IMPL
#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/Unk_StringAssign.h>
#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/Unk_StringCompare.h>
#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/Unk_StringFuncs.h>
#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiGfx/Source/SiGfx_Kernel_Impl.h>
#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiGfx/Source/SiGfx_ShaderUtility_Impl.h>

#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/Unk_Version.h>
#include <yebis/sisdk/3.0/SDK/Core/Include/SiIO/SiIO_Stream.h>
#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiGfx/Source/ShaderEffect/SiGfx_ShaderEffectVariationList_Impl.h>
#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiIO/Source/SiIO_Kernel_Impl.h>

// 0x71004cbec0: the graphics kernel (a function-local static)
void* Unk_4cbec0();
// 0x71004c94c0
void Unk_4c94c0_call(void* self);
// 0x71004ca0b0: replaces one string with another in a string
void Unk_4ca0b0(SiSDK3::SiString<char>* self, const char* from, const char* to, u64, u64, bool);
// 0x71004e4230: a path's directory, 0x71004e4400: its file's name
SiSDK3::SiString<char> Unk_4e4230(SiSDK3::SiString<char>* path);
SiSDK3::SiString<char> Unk_4e4400(SiSDK3::SiString<char>* path, bool);
// 0x71004eddf0: a key in hexadecimal (placeholder name and types)
void Unk_4eddf0(SiSDK3::SiString<char>* dst, const void* key);
// 0x710057d030: SiIO's kernel
u64 Unk_57d030_get();
// 0x71004cbf40 (leafgen's name and type): the graphics kernel
u64 Unk_4cbf40_get();
// 0x7100582d80: whether a file is there
bool Unk_582d80(const char* path, bool searchArchives);
// 0x71004c9b30: a number's name
const char* Unk_4c9b30(u32 value);
// 0x71004c5630: compares two strings (-1, 0 or 1)
s64 Unk_4c5630(const char* a, const char* b, bool caseSensitive);
// 0x7100570cb0: makes a variation list
SiSDK3::SiGfxShaderEffectVariationList* Unk_570cb0(SiSDK3::ISiAllocator* pAllocator);
// 0x7100582e30: makes a directory (and the ones it's in)
bool Unk_582e30(const char* path);
// 0x71004c5520: copies at most count characters of src, terminated, into
// dst's size
void Unk_4c5520(char* dst, size_t size, const char* src, s64 count);
// 0x7100567750: makes a package (it returns SiGfxShaderEffectPackage*)
SiSDK3::ISiGfxShaderEffectPackage* Unk_567750(SiSDK3::ISiAllocator* pAllocator);

namespace SiSDK3 {

class SiGfxNXDevice;

// SiGfxShaderEffectPackage as this file calls it (its header defines
// ISiGfxShaderEffectPackage otherwise than this one: not included). The
// packages of field_68 are its objects (RTTI), at offset 0.
class SiGfxShaderEffectPackage {
public:
    void Unk_56d100(SiGfxNXDevice* pDevice);  // 0x710056d100
};

// 0x71004e3650
SiGfxShaderUtility::SiGfxShaderUtility(ISiAllocator* pAllocator)
    : field_8(pAllocator), field_18(pAllocator), field_68(pAllocator), field_b8(nullptr), field_c0(pAllocator),
      field_110(pAllocator), field_140(pAllocator), field_170(pAllocator), field_1a0(false), field_1a1(false) {}

// 0x71004e37d0 (D2), 0x71004e3c00 (D0)
SiGfxShaderUtility::~SiGfxShaderUtility() {
    Unk_ReleaseAll(&field_c0);
    vf7();
    if (field_b8 != nullptr) {
        field_b8->vf3();
        field_b8 = nullptr;
    }
}

// 0x71004e3c40
bool SiGfxShaderUtility::vf5(const char* name, const char* path) {
    if (name == nullptr || *name == 0) {
        return false;
    }
    if (vf8(name) != nullptr) {
        return false;
    }
    ISiGfxShaderEffectPackage* pPackage = Unk_567750(field_8.m_pAllocator);
    if (pPackage == nullptr) {
        return false;
    }
    pPackage->vf5(name);
    if (path != nullptr && *path != 0 && !pPackage->vf8(path)) {
        pPackage->vf3();
        return false;
    }
    field_68.Unk_Add(pPackage);
    return true;
}

// 0x71004e3dc0
void SiGfxShaderUtility::vf6(const char* name) {
    ISiGfxShaderEffectPackage* pPackage = vf8(name);
    if (pPackage == nullptr) {
        return;
    }
    field_68.Unk_RemoveValue(pPackage);
    pPackage->vf9();
    pPackage->vf3();
}

// 0x71004e3ed0
void SiGfxShaderUtility::vf7() {
    Unk_ReleaseAll(&field_68);
}

// 0x71004e3f80
ISiGfxShaderEffectPackage* SiGfxShaderUtility::vf8(const char* name) {
    for (s64 i = 0; i < static_cast<s32>(field_68.m_itemCount); i++) {
        ISiGfxShaderEffectPackage* pPackage = field_68.m_pData[i];
        if (pPackage != nullptr && Unk_Compare(pPackage->vf6(), name) == 0) {
            return pPackage;
        }
    }
    return nullptr;
}

// 0x71004e40b0
void SiGfxShaderUtility::vf11() {
    for (s64 i = 0; i < static_cast<s32>(field_68.m_itemCount); i++) {
        ISiGfxShaderEffectPackage* pPackage = field_68.m_pData[i];
        if (pPackage != nullptr) {
            Unk_4e40b0_Object* pObject = pPackage->vf23();
            if (pObject != nullptr) {
                pObject->vf19();
            }
        }
    }
}

// 0x71004e4120: the path of the shaders, its directory and its file's name
void SiGfxShaderUtility::vf12(const char* path, bool flag) {
    field_1a1 = flag;
    Unk_StringAssign(&field_110, path);
    Unk_4c94c0_call(&field_110);
    Unk_4ca0b0(&field_110, "\\", "/", 0, 0, true);
    field_140 = Unk_4e4230(&field_110);
    field_170 = Unk_4e4400(&field_110, true);
}

// The last index of the first character of c in a string (-1: none; also
// for an empty c). Placeholder name.
static inline s64 Unk_FindLast(const SiString<char>* self, const char* c) {
    if (self->field_10 == 0) {
        return -1;
    }
    size_t count = Unk_StringLength(c);
    s64 i = static_cast<s64>(self->field_10) - 1;
    if (i >= 0 && count != 0) {
        const char* buffer = self->m_pBuffer;
        do {
            if (buffer[i] == *c) {
                return i;
            }
        } while (i-- > 0);
    }
    return -1;
}

// The last index of any of chars in a string (-1: none). Placeholder name.
static inline s64 Unk_FindLastOf(const SiString<char>* self, const char* chars) {
    if (self->field_10 == 0) {
        return -1;
    }
    s64 count = Unk_StringLength(chars);
    s64 i = static_cast<s64>(self->field_10) - 1;
    if (i >= 0 && count != 0) {
        const char* buffer = self->m_pBuffer;
        do {
            char c = buffer[i];
            for (s64 j = 0; j < count; j++) {
                if (c == chars[j]) {
                    return i;
                }
            }
        } while (i-- > 0);
    }
    return -1;
}

// count characters of another string from pos on (0: all of them), read
// after the string has room for them (inline: placeholder name)
static inline void Unk_StringAssignPart(SiString<char>* self, const SiString<char>* other, size_t pos, size_t count) {
    if (count == 0) {
        count = other->field_10 - pos;
    }
    if (self->field_20 <= count) {
        size_t step = self->field_18;
        size_t length = count + 1;
        size_t capacity;
        if (step != 0) {
            capacity = step + length;
        } else {
            capacity = length > self->field_20 * 2 ? length : self->field_20 * 2;
        }
        Unk_StringSetCapacity(self, capacity, false);
    }
    Unk_StringCopyN(self->m_pBuffer, other->m_pBuffer + pos, count);
    self->field_10 = count;
}

// Another string's characters, read after the string has room for them
// (inline: placeholder name)
static inline void Unk_StringAssignAll(SiString<char>* self, const SiString<char>* other) {
    size_t count = other->field_10;
    if (count == 0) {
        Unk_StringSetEmpty(self);
        return;
    }
    if (self->field_20 <= count) {
        size_t step = self->field_18;
        size_t length = count + 1;
        size_t capacity;
        if (step != 0) {
            capacity = step + length;
        } else {
            capacity = length > self->field_20 * 2 ? length : self->field_20 * 2;
        }
        Unk_StringSetCapacity(self, capacity, false);
    }
    Unk_StringCopyN(self->m_pBuffer, other->m_pBuffer, count);
    self->field_10 = count;
}

// The same, nothing for a negative count or a position past the end (inline:
// placeholder name)
static inline void Unk_StringAssignSub(SiString<char>* self, const SiString<char>* other, size_t pos, s64 count) {
    if (count < 0) {
        return;
    }
    if (pos >= other->field_10) {
        return;
    }
    Unk_StringAssignPart(self, other, pos, count);
}

}  // namespace SiSDK3

// 0x71004e4230: a path's directory (without its last separator)
SiSDK3::SiString<char> Unk_4e4230(SiSDK3::SiString<char>* path) {
    char separators[] = "/:\\";
    SiSDK3::SiString<char> result(path->m_pAllocator);
    s64 index = SiSDK3::Unk_FindLastOf(path, separators);
    if (index > 0) {
        SiSDK3::Unk_StringAssignSub(&result, path, 0, index);
    }
    return result;
}

// 0x71004e4400: a path's file's name, with its extension or without
// NON_MATCHING: 2452 bytes for 2076. The separator search and the first
// branches are the original's; after them the original searches for the
// period with a pointer stepping down from the end (here an index), keeps
// "no period" and "period at 0" apart (a csel of the count where this jumps
// into the whole copy) and uses one stack slot for the two periods.
SiSDK3::SiString<char> Unk_4e4400(SiSDK3::SiString<char>* path, bool withExtension) {
    SiSDK3::SiString<char> result(path->m_pAllocator);
    size_t length = path->field_10;
    s64 separator = -1;
    if (static_cast<s64>(length) >= 1) {
        const char* buffer = path->m_pBuffer;
        s64 i = length;
        do {
            char c = buffer[i - 1];
            if (c == '/' || c == '\\' || c == ':' || c == '|') {
                separator = i - 1;
                break;
            }
        } while (--i > 0);
    }
    if (separator != -1) {
        if (withExtension) {
            SiSDK3::Unk_StringAssignSub(&result, path, separator + 1, 0);
        } else {
            s64 dot;
            {
                char period[] = ".";
                dot = SiSDK3::Unk_FindLast(path, period);
            }
            if (dot >= separator && dot != -1) {
                SiSDK3::Unk_StringAssignSub(&result, path, separator + 1, dot - (separator + 1));
            } else {
                SiSDK3::Unk_StringAssignSub(&result, path, separator + 1, 0);
            }
        }
    } else if (withExtension) {
        SiSDK3::Unk_StringAssignAll(&result, path);
    } else {
        s64 dot;
        {
            char period[] = ".";
            dot = SiSDK3::Unk_FindLast(path, period);
        }
        if (dot != -1) {
            SiSDK3::Unk_StringAssignPart(&result, path, 0, dot);
        } else {
            SiSDK3::Unk_StringAssignAll(&result, path);
        }
    }
    return result;
}

namespace SiSDK3 {

// The header of a file of variation lists (placeholder name)
struct Unk_4e5f50_Header {
    char field_0[0x20];  // "SSKK.ShaderVariationList"
    u8 field_20;         // 1 in what vf14 writes
    u8 field_21[7];
    Unk_567750_Version field_28;
    s32 field_38;  // how many lists
    s32 field_3c;  // what they are aligned to
};
PKMN_SIZE_ASSERT(Unk_4e5f50_Header, 0x40);

// 0x71004e57e0
void SiGfxShaderUtility::Unk_4e57e0(SiArray<ISiGfxShaderEffectVariationList*>* lists,
                                    SiArray<ISiGfxShaderEffectVariationList*>* others) {
    for (s64 i = 0; i < static_cast<s32>(others->m_itemCount); i++) {
        ISiGfxShaderEffectVariationList* other = others->m_pData[i];
        s64 j = 0;
        bool merged = false;
        for (; j < static_cast<s32>(lists->m_itemCount); j++) {
            ISiGfxShaderEffectVariationList* list = lists->m_pData[j];
            const SiString<char>* name =
                reinterpret_cast<const SiString<char>*>(static_cast<SiGfxShaderEffectVariationList*>(list)->vf20());
            const SiString<char>* otherName =
                reinterpret_cast<const SiString<char>*>(static_cast<SiGfxShaderEffectVariationList*>(other)->vf20());
            if (Unk_CompareNoCase(name, otherName) == 0) {
                Unk_4e5d80(list, other);
                merged = true;
            }
        }
        if (!merged) {
            lists->Unk_Add(other);
        }
    }
}

// 0x71004e5d80
void SiGfxShaderUtility::Unk_4e5d80(ISiGfxShaderEffectVariationList* list, ISiGfxShaderEffectVariationList* other) {
    typedef ISiGfxShaderEffectVariationList::ShaderVariationItem Item;
    typedef ISiGfxShaderEffectVariationList::ShaderEffectData Data;
    SiGfxShaderEffectVariationList* self = static_cast<SiGfxShaderEffectVariationList*>(list);
    SiGfxShaderEffectVariationList* from = static_cast<SiGfxShaderEffectVariationList*>(other);
    ISiGfxShaderEffectPackage* package = reinterpret_cast<ISiGfxShaderEffectPackage*>(self->vf21());
    if (package == nullptr) {
        return;
    }
    for (Item* item = reinterpret_cast<Item*>(from->vf9()); item != nullptr; item = item->m_pNext) {
        Data* data = reinterpret_cast<Data*>(from->vf15(item->field_44));
        ISiGfxShaderEffectPackage::ShaderEffectData* effect = package->vf21(Unk_StringCStr(&data->field_0));
        if (effect == nullptr) {
            continue;
        }
        s32 program = effect->field_3c;
        if (program < 0 || data->field_40 != effect->field_48 || data->field_44 != effect->field_50) {
            continue;
        }
        Item* variation = reinterpret_cast<Item*>(self->vf9());
        for (; variation != nullptr; variation = variation->m_pNext) {
            if (variation->field_44 == program && variation->field_10.Unk_Compare(item->field_10) == 0 &&
                variation->field_28.Unk_Compare(item->field_28) == 0) {
                break;
            }
        }
        if (variation == nullptr) {
            self->vf6(program, nullptr, item->field_10, item->field_28, nullptr);
        }
    }
}

// 0x71004e5a60: sets a path's extension (replacing the one its file has). The
// period's buffer is out of scope before the replacement, which is a tail
// call then.
void Unk_4e5a60(SiString<char>* path, const char* extension) {
    s32 index;
    {
        char period[] = ".";
        index = Unk_FindLast(path, period);
    }
    size_t length = path->field_10;
    s32 separator = -1;
    if (static_cast<s64>(length) >= 1) {
        const char* buffer = path->m_pBuffer;
        s64 i = length;
        do {
            char c = buffer[i - 1];
            if (c == '\\' || c == '/') {
                separator = i - 1;
                break;
            }
        } while (--i > 0);
    }
    if (index >= 0 && separator <= index) {
        Unk_4ca0b0(path, path->m_pBuffer + (index + 1), extension, index + 1, 0, true);
        return;
    }
    if (extension != nullptr) {
        Unk_StringAppend(path, '.');
        Unk_StringAppendGrow(path, extension);
    }
}

// 0x71004e5f50
// The header's tests are three ifs (read, signature, version), each closing
// the stream: branch folding merges their blocks only after register
// allocation, so the stream's longer live range gets its register before
// `this`.
bool SiGfxShaderUtility::vf15(const char* path, SiArray<ISiGfxShaderEffectVariationList*>* lists) {
    ISiIOStream* stream = reinterpret_cast<SiIOKernel*>(Unk_57d030_get())->vf9(path, 9, nullptr);
    if (stream == nullptr) {
        return false;
    }
    Unk_4e5f50_Header header;
    if (!stream->vf21(&header, sizeof(header), true)) {
        stream->vf3();
        return false;
    }
    if (Unk_4c5630(header.field_0, "SSKK.ShaderVariationList", true) != 0) {
        stream->vf3();
        return false;
    }
    if (header.field_28.field_0 != 3 || header.field_28.field_4 != 0 || header.field_28.field_8 != 0 ||
        header.field_28.field_c != 1) {
        stream->vf3();
        return false;
    }
    lists->Unk_ReserveAtLeast(header.field_38);
    for (s32 i = 0; i < header.field_38; i++) {
        SiGfxShaderEffectVariationList* list = Unk_570cb0(field_8.m_pAllocator);
        if (list->vf18(stream, header.field_3c)) {
            lists->Unk_Add(list);
        } else if (list != nullptr) {
            list->vf3();
        }
    }
    stream->vf3();
    return true;
}

// 0x71004e6190
bool SiGfxShaderUtility::vf16(ISiGfxShaderBinaryCachePackage* pPackage) {
    if (pPackage != nullptr) {
        pPackage->vf2();
    }
    if (field_b8 != nullptr) {
        field_b8->vf3();
    }
    field_b8 = pPackage;
    return true;
}

// 0x71004e61f0
SiGfxShaderBinaryCachePackage* SiGfxShaderUtility::vf18() {
    SiGfxShaderBinaryCachePackage* pPackage =
#line 635
        UNK_SI_NEW(field_8.m_pAllocator, 0x10) SiGfxShaderBinaryCachePackage(field_8.m_pAllocator);
    if (pPackage != nullptr && !pPackage->Unk_4e8b20()) {
        pPackage->vf3();
        pPackage = nullptr;
    }
    return pPackage;
}

// 0x71004e6270
bool SiGfxShaderUtility::vf19(ISiGfxShaderBinaryCachePackage* pPackage) {
    if (pPackage == nullptr) {
        return false;
    }
    field_c0.Unk_Add(pPackage);
    pPackage->vf2();
    return true;
}

// 0x71004e6320
void SiGfxShaderUtility::vf20(ISiGfxShaderBinaryCachePackage* pPackage) {
    if (pPackage == nullptr) {
        return;
    }
    field_c0.Unk_RemoveValue(pPackage);
    pPackage->vf3();
}

// 0x71004e64a0: the first package that has it, the last one added first
void* SiGfxShaderUtility::vf21(const void* a1, void* a2) {
    for (s32 i = static_cast<s32>(field_c0.m_itemCount) - 1; i >= 0; i--) {
        void* result = field_c0.m_pData[i]->vf10(a1, a2);
        if (result != nullptr) {
            return result;
        }
    }
    return nullptr;
}

// 0x71004e63f0
void SiGfxShaderUtility::vf22() {
    Unk_ReleaseAll(&field_c0);
}

// 0x71004e6520
void SiGfxShaderUtility::vf23() {
    for (s64 i = 0; i < static_cast<s32>(field_68.m_itemCount); i++) {
        field_68.m_pData[i]->vf11();
    }
    static_cast<SiGfxKernel*>(Unk_4cbec0())->Unk_4ce8b0();
}

// 0x71004e6580
void SiGfxShaderUtility::vf24() {
    for (s64 i = 0; i < static_cast<s32>(field_68.m_itemCount); i++) {
        field_68.m_pData[i]->vf28();
    }
    static_cast<SiGfxKernel*>(Unk_4cbec0())->Unk_4ce940();
}

// 0x71004e65e0
bool SiGfxShaderUtility::Unk_4e65e0(u32 kind) {
    const Unk_4ecbc0* settings =
        reinterpret_cast<const Unk_4ecbc0*>(reinterpret_cast<SiGfxKernel*>(Unk_4cbf40_get())->vf27());
    if (!settings->field_60) {
        return true;
    }
    SiString<char> name(field_8.m_pAllocator);
    switch (kind) {
    case 2:
        Unk_StringAssign(&name, "SiGfx_OGL_Common.mi_shader_pkg");
        break;
    case 3:
        Unk_StringAssign(&name, "SiGfx_OGLES3_Common.mi_shader_pkg");
        break;
    case 4:
        Unk_StringAssign(&name, "SiGfx_D3D11_Common.mi_shader_pkg");
        break;
    case 5:
        Unk_StringAssign(&name, "SiGfx_D3D12_Common.mi_shader_pkg");
        break;
    case 6:
        Unk_StringAssign(&name, "SiGfx_PS4_Common.mi_shader_pkg");
        break;
    case 7:
        Unk_StringAssign(&name, "SiGfx_Vulkan_Common.mi_shader_pkg");
        break;
    case 8:
        Unk_StringAssign(&name, "SiGfx_NX_Common.mi_shader_pkg");
        break;
    }
    if (name.field_10 == 0) {
        return false;
    }
    SiString<char> path(field_8.m_pAllocator);
    path = reinterpret_cast<const Unk_4ecbc0*>(reinterpret_cast<SiGfxKernel*>(Unk_4cbf40_get())->vf27())->field_0;
    Unk_StringAppend(&path, '/');
    Unk_StringAppendString(&path, &name);
    if (!Unk_582d80(Unk_StringCStr(&path), true)) {
        const char* platform = Unk_4c9b30(7);
        if (platform == nullptr) {
            return false;
        }
        SiString<char> other(field_8.m_pAllocator);
        Unk_StringAssign(&other, "%SISDK_V3%/SDK/Core/Shader/Bin");
        Unk_StringAppend(&other, '/');
        Unk_StringAppendGrow(&other, platform);
        Unk_StringAppend(&other, '/');
        Unk_StringAppendString(&other, &name);
        Unk_4c94c0_call(&other);
        Unk_4ca0b0(&other, "\\", "/", 0, 0, true);
        if (!Unk_582d80(Unk_StringCStr(&other), true)) {
            return false;
        }
        path = other;
    }
    SiString<char> fileName = Unk_4e4400(&path, false);
    if (vf8(Unk_StringCStr(&fileName)) == nullptr) {
        if (!vf5(Unk_StringCStr(&fileName), Unk_StringCStr(&path))) {
            return false;
        }
        vf8(Unk_StringCStr(&fileName));
        Unk_4e6c80(kind);
    }
    return true;
}

// 0x71004e6c80
bool SiGfxShaderUtility::Unk_4e6c80(u32 kind) {
    SiArray<SiString<char>> names(field_8.m_pAllocator);
    switch (kind) {
    case 4: {
        SiString<char> name(nullptr, "SiGfx_D3D11_Common_Subdiv.mi_shader_pkg");
        names.Unk_Add(name);
        break;
    }
    case 5: {
        SiString<char> name(nullptr, "SiGfx_D3D12_Common_Subdiv.mi_shader_pkg");
        names.Unk_Add(name);
        break;
    }
    case 6: {
        {
            SiString<char> name(nullptr, "SiGfx_PS4_Common_Subdiv.mi_shader_pkg");
            names.Unk_Add(name);
        }
        SiString<char> name(nullptr, "SiGfx_PS4_Special.mi_shader_pkg");
        names.Unk_Add(name);
        break;
    }
    case 8: {
        SiString<char> name(nullptr, "SiGfx_NX_Special.mi_shader_pkg");
        names.Unk_Add(name);
        break;
    }
    }
    if (names.m_itemCount == 0) {
        return true;
    }
    for (s64 i = 0; i < static_cast<s32>(names.m_itemCount); i++) {
        SiString<char> name(field_8.m_pAllocator);
        name = names.m_pData[i];
        SiString<char> path(field_8.m_pAllocator);
        path = reinterpret_cast<const Unk_4ecbc0*>(reinterpret_cast<SiGfxKernel*>(Unk_4cbf40_get())->vf27())->field_0;
        Unk_StringAppend(&path, '/');
        Unk_StringAppendString(&path, &name);
        if (!Unk_582d80(Unk_StringCStr(&path), true)) {
            const char* platform = Unk_4c9b30(7);
            if (platform == nullptr) {
                return false;
            }
            SiString<char> other(field_8.m_pAllocator);
            Unk_StringAssign(&other, "%SISDK_V3%/SDK/Core/Shader/Bin");
            Unk_StringAppend(&other, '/');
            Unk_StringAppendGrow(&other, platform);
            Unk_StringAppend(&other, '/');
            Unk_StringAppendString(&other, &name);
            Unk_4c94c0_call(&other);
            Unk_4ca0b0(&other, "\\", "/", 0, 0, true);
            if (!Unk_582d80(Unk_StringCStr(&other), true)) {
                continue;
            }
            path = other;
        }
        SiString<char> fileName = Unk_4e4400(&path, false);
        if (vf8(Unk_StringCStr(&fileName)) != nullptr) {
            continue;
        }
        if (!vf5(Unk_StringCStr(&fileName), Unk_StringCStr(&path))) {
            continue;
        }
        vf8(Unk_StringCStr(&fileName));
    }
    return true;
}

// 0x71004e7710: fills in a request
bool SiGfxShaderUtility::vf25(Unk_4e7710_Request* request, s32 a2, s32 a3, const u64* a4, s32 a5, s32 a6,
                              const u64* a7, s32 a8, s32 a9, s32 a10, const char* s1, const char* s2,
                              const void* key1, const char* s3, const void* key2, const char* s4,
                              const SiArray<SiString<char>>* names) {
    request->field_38 = a2;
    request->field_3c = a3;
    request->field_40 = *a4;
    request->field_48 = a5;
    request->field_4c = a6;
    request->field_50 = *a7;
    request->field_58 = a8;
    request->field_5c = a9;
    request->field_60 = a10;
    Unk_StringAssign(&request->field_68, s1);
    Unk_StringAssign(&request->field_98, s2);
    if (names != nullptr) {
        request->field_188.Unk_SetCount(names->m_itemCount);
        for (s64 i = 0; i < static_cast<s32>(names->m_itemCount); i++) {
            request->field_188.m_pData[i] = names->m_pData[i];
        }
    }
    Unk_4eddf0(&request->field_c8, key1);
    Unk_4eddf0(&request->field_f8, key2);
    Unk_StringAssign(&request->field_128, s3);
    Unk_StringAssign(&request->field_158, s4);
    request->field_228 = 0;
    return true;
}

// 0x71004e7680: tells the packages that a device goes away
void Unk_4e7680(void* self, SiGfxNXDevice* pDevice) {
    SiGfxShaderUtility* utility = static_cast<SiGfxShaderUtility*>(self);
    for (s64 i = 0; i < static_cast<s32>(utility->field_c0.m_itemCount); i++) {
        static_cast<SiGfxShaderBinaryCachePackage*>(utility->field_c0.m_pData[i])->Unk_4ea060(pDevice);
    }
    for (s64 i = 0; i < static_cast<s32>(utility->field_68.m_itemCount); i++) {
        reinterpret_cast<SiGfxShaderEffectPackage*>(utility->field_68.m_pData[i])->Unk_56d100(pDevice);
    }
}

// A sort of elements by their names (a string at 0x10), without case: vf14's
// sort of the names its variation lists didn't find (placeholder names). The
// partition is out of line and the sort passes it `this`, which it doesn't
// use: they can be replaced at link time (inline, or a template's instance).
template <class T>
struct Unk_NameSorter {
    // (64-bit: the comparison's int result widened keeps each end's result a
    // value the partition tests once)
    static s64 Unk_Compare(T* a, T* b) { return Unk_CompareNoCase(&a->field_10, &b->field_10); }
    s64 Unk_4e7e40(s64 count, T** items);   // 0x71004e7e40
    bool Unk_4e59e0(s64 count, T** items);  // 0x71004e59e0
};

// 0x71004e7e40: the partition around the middle element; the index it ends at
template <class T>
s64 Unk_NameSorter<T>::Unk_4e7e40(s64 count, T** items) {
    s64 pivot = count < 2 ? 1 : count / 2;
    if (pivot >= count) {
        return 0;
    }
    if (pivot != 0) {
        T* t = items[0];
        items[0] = items[pivot];
        items[pivot] = t;
    }
    T* first = items[0];
    s64 i = 1;
    s64 j = count - 1;
    while (i <= j) {
        if (Unk_Compare(first, items[i]) > 0) {
            do {
                if (++i >= j) {
                    break;
                }
            } while (Unk_Compare(first, items[i]) > 0);
        }
        if (Unk_Compare(first, items[j]) <= 0) {
            do {
                if (--j <= i) {
                    break;
                }
            } while (Unk_Compare(first, items[j]) <= 0);
        }
        if (i < j) {
            T* t = items[i];
            items[i] = items[j];
            items[j] = t;
        }
    }
    s64 middle = i - 1;
    T* t = items[0];
    items[0] = items[middle];
    items[middle] = t;
    return middle;
}

template <class T>
bool Unk_NameSorter<T>::Unk_4e59e0(s64 count, T** items) {
    if (count < 2) {
        return true;
    }
    s64 middle = Unk_4e7e40(count, items);
    Unk_4e59e0(middle, items);
    Unk_4e59e0(count - middle - 1, &items[middle + 1]);
    return true;
}


// Unk_ReleaseAll for the variation lists (their reference counts are
// SiGfxShaderEffectVariationList's)
static inline void Unk_ReleaseLists(SiArray<ISiGfxShaderEffectVariationList*>* array) {
    for (size_t i = 0; i < array->m_itemCount; i++) {
        ISiGfxShaderEffectVariationList* item = array->m_pData[i];
        if (item != nullptr) {
            array->m_pData[i] = nullptr;
            static_cast<SiGfxShaderEffectVariationList*>(item)->vf3();
        }
    }
    array->Unk_4e3050();
}

// 0x71004e4c30 (here because it sorts with Unk_NameSorter)
bool SiGfxShaderUtility::vf14() {
    if (field_110.field_10 == 0) {
        return false;
    }
    if (field_140.field_10 != 0 && !Unk_582e30(Unk_StringCStr(&field_140))) {
        return false;
    }
    SiArray<ISiGfxShaderEffectVariationList*> loaded(field_8.m_pAllocator);
    if (field_1a1 && Unk_582d80(Unk_StringCStr(&field_110), true)) {
        vf15(Unk_StringCStr(&field_110), &loaded);
    }
    SiArray<ISiGfxShaderEffectVariationList*> lists(field_8.m_pAllocator);
    for (s64 i = 0; i < static_cast<s32>(field_68.m_itemCount); i++) {
        SiGfxShaderEffectVariationList* list =
            reinterpret_cast<SiGfxShaderEffectVariationList*>(field_68.m_pData[i]->vf23());
        if (list == nullptr || list->vf9() == 0) {
            continue;
        }
        lists.Unk_Add(list);
    }
    Unk_4e57e0(&lists, &loaded);
    ISiIOStream* stream = reinterpret_cast<SiIOKernel*>(Unk_57d030_get())->vf9(Unk_StringCStr(&field_110), 0x15, nullptr);
    if (stream == nullptr) {
        Unk_ReleaseLists(&loaded);
        return false;
    }
    Unk_4e5f50_Header header = {};
    Unk_4c5520(header.field_0, sizeof(header.field_0), "SSKK.ShaderVariationList", -1);
    header.field_20 = 1;
    header.field_3c = 0x10;
    header.field_28 = Unk_567750_Version(3, 0, 0, 1);
    header.field_38 = lists.m_itemCount;
    stream->vf44(&header, sizeof(header), true);
    for (s64 i = 0; i < static_cast<s32>(lists.m_itemCount); i++) {
        static_cast<SiGfxShaderEffectVariationList*>(lists.m_pData[i])->vf17(stream, header.field_3c);
    }
    stream->vf3();
    typedef ISiGfxShaderEffectVariationList::RequestNotFoundEntry Entry;
    SiArray<Entry*> notFound(field_8.m_pAllocator);
    for (s64 i = 0; i < static_cast<s32>(lists.m_itemCount); i++) {
        static_cast<SiGfxShaderEffectVariationList*>(lists.m_pData[i])->vf22(&notFound);
    }
    if (notFound.m_itemCount != 0) {
        Unk_NameSorter<Entry> sorter;
        sorter.Unk_4e59e0(static_cast<s32>(notFound.m_itemCount), notFound.m_pData);
    }
    {
        SiString<char> directory = Unk_4e4230(&field_110);
        SiString<char> name = Unk_4e4400(&field_110, false);
        Unk_StringAppendGrow(&name, "_NotFoundList");
        Unk_4e5a60(&name, "txt");
        SiString<char> path(field_8.m_pAllocator);
        if (directory.field_10 != 0) {
            path = directory;
            Unk_StringAppend(&path, '/');
        }
        Unk_StringAppendString(&path, &name);
        ISiIOStream* text = reinterpret_cast<SiIOKernel*>(Unk_57d030_get())->vf9(Unk_StringCStr(&path), 0x16, nullptr);
        if (text == nullptr) {
            Unk_ReleaseLists(&loaded);
            return false;
        }
        for (s64 i = 0; i < static_cast<s32>(notFound.m_itemCount); i++) {
            Entry* entry = notFound.m_pData[i];
            for (s64 j = 0; j < static_cast<s32>(entry->field_10.field_10); j++) {
                text->vf46(entry->field_10.m_pBuffer[j], true);
            }
            text->vf46('\r', true);
            text->vf46('\n', true);
        }
        text->vf3();
    }
    Unk_ReleaseLists(&loaded);
    return true;
}

// vf14 is its only user.
template s64 Unk_NameSorter<ISiGfxShaderEffectVariationList::RequestNotFoundEntry>::Unk_4e7e40(
    s64 count, ISiGfxShaderEffectVariationList::RequestNotFoundEntry** items);
template bool Unk_NameSorter<ISiGfxShaderEffectVariationList::RequestNotFoundEntry>::Unk_4e59e0(
    s64 count, ISiGfxShaderEffectVariationList::RequestNotFoundEntry** items);

}  // namespace SiSDK3
