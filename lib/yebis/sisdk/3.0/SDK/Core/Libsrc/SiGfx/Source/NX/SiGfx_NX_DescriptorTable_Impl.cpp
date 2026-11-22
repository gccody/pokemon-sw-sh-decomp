// Scope: common
// SiSDK3::SiGfxNXDescriptorTable: its construction and destruction, its lists
// of resources, and the reference counts its header defines. (Its small
// accessors are lib/yebis/class's.)
#define UNK_SIGFX_NX_DESCRIPTORTABLE_IMPL
#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiGfx/Source/NX/SiGfx_NX_DescriptorTable_Impl.h>

namespace SiSDK3 {

// Releases the four lists' resources (in the release and in slot 8, each of
// which has the four inline: a function of the four would be too large to be
// inlined).
#define UNK_RELEASE_LISTS()                 \
    Unk_ReleaseAll(&field_30.field_8);      \
    Unk_ReleaseAll(&field_88.field_8);      \
    Unk_ReleaseAll(&field_e0.field_8);      \
    Unk_ReleaseAll(&field_138.field_8)

// 0x710054fa00
SiGfxNXDescriptorTable::SiGfxNXDescriptorTable(ISiAllocator* pAllocator, SiGfxNXDevice* pDevice)
    : field_8(pAllocator), field_18(pDevice), field_20(0), field_28(false), field_29(false), field_190(0) {}

// 0x710054fb40 (D2), 0x7100550000 (D0)
SiGfxNXDescriptorTable::~SiGfxNXDescriptorTable() {
    Unk_54fdc0();
}

// 0x710054fdc0
void SiGfxNXDescriptorTable::Unk_54fdc0() {
    UNK_RELEASE_LISTS();
}

// 0x7100550030
bool SiGfxNXDescriptorTable::Unk_550030(u32 kind) {
    field_20 = kind;
    field_30.field_0 = 0;
    field_30.field_8.Unk_SetAllocator(field_8.m_pAllocator);
    field_88.field_0 = 1;
    field_88.field_8.Unk_SetAllocator(field_8.m_pAllocator);
    field_e0.field_0 = 2;
    field_e0.field_8.Unk_SetAllocator(field_8.m_pAllocator);
    field_138.field_0 = 3;
    field_138.field_8.Unk_SetAllocator(field_8.m_pAllocator);
    return true;
}

// 0x7100550240
bool SiGfxNXDescriptorTable::vf8(u32 kind) {
    if (field_29) {
        return false;
    }
    field_24 = kind;
    UNK_RELEASE_LISTS();
    field_29 = true;
    field_28 = false;
    return true;
}

// 0x71005504a0
bool SiGfxNXDescriptorTable::vf9() {
    if (!field_29) {
        return false;
    }
    if (field_18 == nullptr) {
        return false;
    }
    field_28 = true;
    field_29 = false;
    vf30();
    return true;
}

// A list gets count resources, none of them set, in a table of a kind that is
// being changed.
#define UNK_SET_COUNT(Slot, List, Kind)                                 \
    bool SiGfxNXDescriptorTable::Slot(s32 count) {                      \
        if (!field_29) {                                                \
            return false;                                               \
        }                                                               \
        if (field_24 != Kind) {                                         \
            return false;                                               \
        }                                                               \
        if (count >= 1) {                                               \
            List.field_8.Unk_SetCount(count);                           \
            for (s32 i = 0; i < count; i++) {                           \
                List.field_8.m_pData[i] = nullptr;                      \
            }                                                           \
        }                                                               \
        return true;                                                    \
    }

// Sets a list's resource while the table is being changed (the slot that
// does it), and reads one.
#define UNK_SET_AND_GET(SetSlot, Set, GetSlot, List)                                     \
    bool SiGfxNXDescriptorTable::SetSlot(s32 index, ISiGfxResource* resource) {          \
        if (!field_29) {                                                                 \
            return false;                                                                \
        }                                                                                \
        return Set(index, resource);                                                     \
    }                                                                                    \
    ISiGfxResource* SiGfxNXDescriptorTable::GetSlot(s32 index) { return List.field_8.m_pData[index]; }

// 0x7100550510
UNK_SET_COUNT(vf10, field_88, 1)
// 0x7100550660, 0x7100550680
UNK_SET_AND_GET(vf12, vf27, vf13, field_88)
// 0x7100550690
UNK_SET_COUNT(vf14, field_30, 1)
// 0x71005507e0, 0x7100550800
UNK_SET_AND_GET(vf16, vf26, vf17, field_30)
// 0x7100550810
UNK_SET_COUNT(vf18, field_e0, 1)
// 0x7100550960, 0x7100550980
UNK_SET_AND_GET(vf20, vf28, vf21, field_e0)
// 0x7100550990
UNK_SET_COUNT(vf22, field_138, 2)
// 0x7100550ae0, 0x7100550b00
UNK_SET_AND_GET(vf24, vf29, vf25, field_138)
#undef UNK_SET_COUNT
#undef UNK_SET_AND_GET

// A list's resource of an index becomes resource (null: none), if the table
// is of the list's kind and the resource can be used as what the list holds.
// (The kind is read before the index is tested: the original has the two
// tests as one condition, which needs the load ahead of the first.)
#define UNK_SET_RESOURCE(Slot, List, ReadKind, Check, Usable)                    \
    bool SiGfxNXDescriptorTable::Slot(s32 index, ISiGfxResource* resource) {     \
        ReadKind                                                                 \
        if (index >= 0 Check) {                                                  \
            if (static_cast<s32>(List.field_8.m_itemCount) <= index) {           \
                return false;                                                    \
            }                                                                    \
            if (resource == nullptr) {                                           \
                if (List.field_8.m_pData[index] != nullptr) {                    \
                    List.field_8.m_pData[index]->vf3();                          \
                    List.field_8.m_pData[index] = nullptr;                       \
                }                                                                \
                return true;                                                     \
            }                                                                    \
            if (Usable) {                                                        \
                resource->vf2();                                                 \
                if (List.field_8.m_pData[index] != nullptr) {                    \
                    List.field_8.m_pData[index]->vf3();                          \
                }                                                                \
                List.field_8.m_pData[index] = resource;                          \
                vf30();                                                          \
                return true;                                                     \
            }                                                                    \
        }                                                                        \
        return false;                                                            \
    }
#define UNK_READ_KIND u32 kind = field_24;
#define UNK_KIND(Kind) &&kind == Kind
#define UNK_USABLE(Bits) (resource->vf8()->field_8 & Bits) != 0

// 0x7100550b10
UNK_SET_RESOURCE(vf26, field_30, UNK_READ_KIND, UNK_KIND(1), UNK_USABLE(4))
// 0x7100550c20
UNK_SET_RESOURCE(vf27, field_88, UNK_READ_KIND, UNK_KIND(1), UNK_USABLE(8))
// 0x7100550d30
UNK_SET_RESOURCE(vf28, field_e0, , , UNK_USABLE(0x8000))
// 0x7100550e40
UNK_SET_RESOURCE(vf29, field_138, UNK_READ_KIND, UNK_KIND(2), true)
#undef UNK_SET_RESOURCE
#undef UNK_READ_KIND
#undef UNK_KIND
#undef UNK_USABLE

// 0x7100550f20
void SiGfxNXDescriptorTable::vf30() {
    field_190++;
}

}  // namespace SiSDK3
