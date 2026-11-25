// Scope: common
// nn::vfx (the SDK's effect library, NintendoSDK_gfx based): lookups of
// resources by id and by name, and the small virtual functions of
// nn::vfx::Primitive (its RTTI name N2nn3vfx9PrimitiveE is in main). Neither
// the members nor the structs are named in the executable: placeholders, the
// virtual ones named after their slot (vf<slot>), as tools/leafgen.py names
// the class's other members in lib/nx_middleware/class/nn_vfx_Primitive.cpp.
#include <string.h>
#include <types.h>
#include "nx_middleware/gfx/gfx.h"

void Unk_1788170(Unk_1787d90_CommandBuffer* self, int topology, int indexFormat,
                 const Unk_178d730_Address* indexBuffer, int indexCount, int baseVertex,
                 int instanceCount, int baseInstance);

// One entry of a list of resources: its id, the offset of the next entry
// (0 for the last one) and its name.
struct Unk_17d49e0_Entry {
    u64 field_0;
    u32 field_8;
    u8 _c[0x4];
    char field_10[1];

    const Unk_17d49e0_Entry* GetNext() const {
        return field_8 != 0
                   ? reinterpret_cast<const Unk_17d49e0_Entry*>(reinterpret_cast<const u8*>(this) + field_8)
                   : nullptr;
    }
};
PKMN_OFFSET_ASSERT(Unk_17d49e0_Entry, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_17d49e0_Entry, field_10, 0x10);

// A string and its length.
struct Unk_17d49e0_StringView {
    const char* field_0;
    size_t field_8;

    Unk_17d49e0_StringView(const char* data, size_t length) : field_0(data), field_8(length) {}
    explicit Unk_17d49e0_StringView(const char* string) : field_0(string), field_8(strlen(string)) {}

    int Compare(const Unk_17d49e0_StringView& other) const {
        size_t n = other.field_8 < field_8 ? other.field_8 : field_8;
        int result = n != 0 ? memcmp(field_0, other.field_0, n) : 0;
        if (result == 0) {
            result = field_8 > other.field_8 ? 1 : (field_8 < other.field_8 ? -1 : 0);
        }
        return result;
    }
};

// A string of a binary resource: its length, then its characters.
struct Unk_17d49e0_String {
    u16 field_0;
    char field_2[1];

    Unk_17d49e0_StringView Get() const { return Unk_17d49e0_StringView(field_2, field_0); }
};
PKMN_OFFSET_ASSERT(Unk_17d49e0_String, field_2, 0x2);

// A dictionary of a binary resource, a Patricia tree: node 0 is the root, the
// others are the entries, each with the bit it tests, its two children and its
// key.
struct Unk_17d49e0_DicNode {
    s32 field_0;
    u16 field_4[2];
    const Unk_17d49e0_String* field_8;
};
PKMN_SIZE_ASSERT(Unk_17d49e0_DicNode, 0x10);

struct Unk_17d49e0_Dic {
    u32 field_0;
    s32 field_4;
    Unk_17d49e0_DicNode field_8[1];

    static int GetBit(const Unk_17d49e0_StringView& key, int bit) {
        int index = bit >> 3;
        if (static_cast<size_t>(index) < key.field_8) {
            return (key.field_0[key.field_8 - index - 1] >> (bit & 7)) & 1;
        }
        return 0;
    }

    const Unk_17d49e0_DicNode* Find(const Unk_17d49e0_StringView& key) const {
        const Unk_17d49e0_DicNode* parent = &field_8[0];
        const Unk_17d49e0_DicNode* child = &field_8[parent->field_4[0]];
        while (parent->field_0 < child->field_0) {
            parent = child;
            child = &field_8[child->field_4[GetBit(key, child->field_0)]];
        }
        return child;
    }

    int FindIndex(const Unk_17d49e0_StringView& key) const {
        const Unk_17d49e0_DicNode* node = Find(key);
        if (node->field_8->Get().Compare(key) != 0) {
            return -1;
        }
        return static_cast<int>(node - &field_8[1]);
    }
};
PKMN_OFFSET_ASSERT(Unk_17d49e0_Dic, field_8, 0x8);

struct Unk_17d49e0_Res {
    u8 _0[0x28];
    void** field_28;
    u8 _30[0x8];
    const Unk_17d49e0_Dic* field_38;
};
PKMN_OFFSET_ASSERT(Unk_17d49e0_Res, field_28, 0x28);
PKMN_OFFSET_ASSERT(Unk_17d49e0_Res, field_38, 0x38);

struct Unk_17d49e0_Element {
    u8 _0[0x90];
};

struct Unk_17d49e0_Owner {
    u8 _0[0x90];
    Unk_17d49e0_Element* field_90;
    u8 _98[0x10];
    Unk_17d49e0_Res* field_a8;
    const Unk_17d49e0_Entry* field_b0;
    const Unk_17d49e0_Entry* field_b8;
    u8 _c0[0x3e8];
    Unk_17d49e0_Owner* field_4a8;
};
PKMN_OFFSET_ASSERT(Unk_17d49e0_Owner, field_90, 0x90);
PKMN_OFFSET_ASSERT(Unk_17d49e0_Owner, field_a8, 0xa8);
PKMN_OFFSET_ASSERT(Unk_17d49e0_Owner, field_b0, 0xb0);
PKMN_OFFSET_ASSERT(Unk_17d49e0_Owner, field_b8, 0xb8);
PKMN_OFFSET_ASSERT(Unk_17d49e0_Owner, field_4a8, 0x4a8);

struct Unk_17d4b90_Item {
    u8 _0[0x10];
    const Unk_17d49e0_Entry* field_10;
    u8 _18[0x20];
};
PKMN_SIZE_ASSERT(Unk_17d4b90_Item, 0x38);

struct Unk_17d4b90_List {
    u8 _0[0x4c];
    s32 field_4c;
    u8 _50[0x8];
    Unk_17d4b90_Item* field_58;
};
PKMN_OFFSET_ASSERT(Unk_17d4b90_List, field_4c, 0x4c);
PKMN_OFFSET_ASSERT(Unk_17d4b90_List, field_58, 0x58);

// 0x71017d49e0
void* Unk_17d49e0(Unk_17d49e0_Owner* self, u64 id) {
    if (id == static_cast<u64>(-1)) {
        return nullptr;
    }
    Unk_17d49e0_Res* res = self->field_a8;
    if (res == nullptr) {
        return nullptr;
    }
    for (const Unk_17d49e0_Entry* entry = self->field_b0; entry != nullptr; entry = entry->GetNext()) {
        if (entry->field_0 == id) {
            int index = res->field_38->FindIndex(Unk_17d49e0_StringView(entry->field_10));
            if (index != -1) {
                return res->field_28[index];
            }
            return nullptr;
        }
    }
    return nullptr;
}

// 0x71017d4b40
Unk_17d49e0_Element* Unk_17d4b40(Unk_17d49e0_Owner* self, u64 id) {
    do {
        Unk_17d49e0_Element* elements = self->field_90;
        if (elements != nullptr) {
            int index = 0;
            for (const Unk_17d49e0_Entry* entry = self->field_b8; entry != nullptr; entry = entry->GetNext()) {
                if (entry->field_0 == id) {
                    return &elements[index];
                }
                index++;
            }
        }
        self = self->field_4a8;
    } while (self != nullptr);
    return nullptr;
}

// 0x71017d4b90
int Unk_17d4b90(const Unk_17d4b90_List* self, const char* name) {
    for (int i = 0; i < self->field_4c; i++) {
        if (strcmp(name, self->field_58[i].field_10->field_10) == 0) {
            return i;
        }
    }
    return -1;
}

namespace nn {
namespace vfx {
class Primitive {
public:
    virtual u32 vf0();
    virtual u32 vf1();
    virtual u64 vf2();
    virtual u64 vf3();
    virtual void vf4(Unk_178d730_Address* address, int index);
    virtual const Unk_178d730_Address* vf5();
    virtual u32 vf6();
    virtual u32 vf7();
    virtual u32 vf8();
    virtual u32 vf9();
    virtual u64 vf10(u32 index);
    virtual void vf11(Unk_1787d90_CommandBuffer* commandBuffer, int instanceCount, int level);

    u8 _8[0x8];
    u32 field_10;
    u32 field_14;
    u8 _18[0x20];
    Unk_178d730_Address field_38;
    Unk_178d730_Address field_48;
    u8 _58[0x18];
    u64 field_70[1];
};
PKMN_OFFSET_ASSERT(Primitive, field_10, 0x10);
PKMN_OFFSET_ASSERT(Primitive, field_14, 0x14);
PKMN_OFFSET_ASSERT(Primitive, field_38, 0x38);
PKMN_OFFSET_ASSERT(Primitive, field_48, 0x48);
PKMN_OFFSET_ASSERT(Primitive, field_70, 0x70);
}  // namespace vfx
}  // namespace nn

// 0x71017d4c20
u32 nn::vfx::Primitive::vf0() {
    return field_10;
}

// 0x71017d4c30
u32 nn::vfx::Primitive::vf1() {
    return field_14;
}

// 0x71017d4c60
void nn::vfx::Primitive::vf4(Unk_178d730_Address* address, int index) {
    *address = field_38;
}

// 0x71017d4cc0
u64 nn::vfx::Primitive::vf10(u32 index) {
    return field_70[index];
}

// 0x71017d4cd0
void nn::vfx::Primitive::vf11(Unk_1787d90_CommandBuffer* commandBuffer, int instanceCount, int level) {
    Unk_1788170(commandBuffer, 3, vf9(), vf5(), vf1(), 0, instanceCount, 0);
}
