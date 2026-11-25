// Scope: common
// nn::vfx (the SDK's effect library, NintendoSDK_gfx based): the last virtual
// function of nn::vfx::Primitive, the small virtual functions of
// nn::vfx::G3dPrimitive (RTTI names N2nn3vfx9PrimitiveE and
// N2nn3vfx12G3dPrimitiveE are in main), and two functions reading a binary
// resource whose sections are offsets from its header. Neither the members nor
// the structs are named in the executable: placeholders, the virtual ones named
// after their slot (vf<slot>), as in lib/nx_middleware/class/nn_vfx_*.cpp.
#include <types.h>
#include "nx_middleware/gfx/gfx.h"

void Unk_1788170(Unk_1787d90_CommandBuffer* self, int topology, int indexFormat,
                 const Unk_178d730_Address* indexBuffer, int indexCount, int baseVertex,
                 int instanceCount, int baseInstance);
void Unk_1787c60(void* self, void* address);

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
    virtual void vf12(Unk_1787d90_CommandBuffer* commandBuffer, int instanceCount, int baseInstance,
                      int level);
};
}  // namespace vfx
}  // namespace nn

// 0x71017d4d60
void nn::vfx::Primitive::vf12(Unk_1787d90_CommandBuffer* commandBuffer, int instanceCount,
                              int baseInstance, int level) {
    Unk_1788170(commandBuffer, 3, vf9(), vf5(), vf1(), 0, instanceCount, baseInstance);
}

// A mesh: its draw calls take the first submesh and their count.
struct Unk_17d4ec0_Mesh {
    u8 _0[0x34];
    u16 field_34;
    u8 _36[0x2];
};
PKMN_SIZE_ASSERT(Unk_17d4ec0_Mesh, 0x38);

void Unk_17871c0(Unk_17d4ec0_Mesh* self, Unk_1787d90_CommandBuffer* commandBuffer, int first,
                 int count, int instanceCount);
void Unk_1787270(Unk_17d4ec0_Mesh* self, Unk_1787d90_CommandBuffer* commandBuffer, int first,
                 int count, int instanceCount, int baseInstance);

// A shape: its meshes, one per level of detail.
struct Unk_17d4ec0_Shape {
    u8 _0[0x18];
    Unk_17d4ec0_Mesh* field_18;
    u8 _20[0x3b];
    u8 field_5b;

    Unk_17d4ec0_Mesh* GetMesh(int level) {
        int index = level < field_5b ? level : field_5b - 1;
        return &field_18[index];
    }
};
PKMN_OFFSET_ASSERT(Unk_17d4ec0_Shape, field_18, 0x18);
PKMN_OFFSET_ASSERT(Unk_17d4ec0_Shape, field_5b, 0x5b);

struct Unk_17d4df0_Attribute {
    s32 field_0;
    u32 field_4;
    u8 _8[0x8];
};
PKMN_SIZE_ASSERT(Unk_17d4df0_Attribute, 0x10);

struct Unk_17d4df0_18 {
    u8 _0[0x28];
    void** field_28;
    Unk_17d4df0_Attribute* field_30;
    Unk_17d4df0_Attribute* field_38;
    u8 _40[0x10];
    u32 field_50;
};
PKMN_OFFSET_ASSERT(Unk_17d4df0_18, field_28, 0x28);
PKMN_OFFSET_ASSERT(Unk_17d4df0_18, field_30, 0x30);
PKMN_OFFSET_ASSERT(Unk_17d4df0_18, field_38, 0x38);
PKMN_OFFSET_ASSERT(Unk_17d4df0_18, field_50, 0x50);

struct Unk_17d4e00_28 {
    u8 _0[0x2c];
    u32 field_2c;
};
PKMN_OFFSET_ASSERT(Unk_17d4e00_28, field_2c, 0x2c);

namespace nn {
namespace vfx {
class G3dPrimitive {
public:
    virtual u32 vf0();
    virtual u32 vf1();
    virtual s64 vf2(int index);
    virtual u32 vf3(int index);
    virtual void vf4(Unk_178d730_Address* address, int index);
    virtual const u8* vf5();
    virtual u8 vf6();
    virtual u32 vf7(u32 index);
    virtual u32 vf8(u32 index);
    virtual u32 vf9();
    virtual u64 vf10(u32 index);
    virtual void vf11(Unk_1787d90_CommandBuffer* commandBuffer, int instanceCount, int level);
    virtual void vf12(Unk_1787d90_CommandBuffer* commandBuffer, int instanceCount, int baseInstance,
                      int level);

    u8 _8[0x10];
    Unk_17d4df0_18* field_18;
    Unk_17d4ec0_Shape* field_20;
    Unk_17d4e00_28* field_28;
    u8 _30[0x10];
    u32 field_40[5];
    u32 field_54[5];
    u64 field_68[1];
};
PKMN_OFFSET_ASSERT(G3dPrimitive, field_18, 0x18);
PKMN_OFFSET_ASSERT(G3dPrimitive, field_20, 0x20);
PKMN_OFFSET_ASSERT(G3dPrimitive, field_28, 0x28);
PKMN_OFFSET_ASSERT(G3dPrimitive, field_40, 0x40);
PKMN_OFFSET_ASSERT(G3dPrimitive, field_54, 0x54);
PKMN_OFFSET_ASSERT(G3dPrimitive, field_68, 0x68);
}  // namespace vfx
}  // namespace nn

// 0x71017d4df0
u32 nn::vfx::G3dPrimitive::vf0() {
    return field_18->field_50;
}

// 0x71017d4e00
u32 nn::vfx::G3dPrimitive::vf1() {
    return field_28->field_2c;
}

// 0x71017d4e10
s64 nn::vfx::G3dPrimitive::vf2(int index) {
    return field_18->field_38[index].field_0;
}

// 0x71017d4e30
u32 nn::vfx::G3dPrimitive::vf3(int index) {
    return field_18->field_30[index].field_0;
}

// 0x71017d4e50
void nn::vfx::G3dPrimitive::vf4(Unk_178d730_Address* address, int index) {
    Unk_1787c60(field_18->field_28[index], address);
}

// 0x71017d4e80
u32 nn::vfx::G3dPrimitive::vf7(u32 index) {
    return field_54[index];
}

// 0x71017d4e90
u32 nn::vfx::G3dPrimitive::vf8(u32 index) {
    return field_40[index];
}

// 0x71017d4eb0
u64 nn::vfx::G3dPrimitive::vf10(u32 index) {
    return field_68[index];
}

// 0x71017d4ec0
void nn::vfx::G3dPrimitive::vf11(Unk_1787d90_CommandBuffer* commandBuffer, int instanceCount, int level) {
    Unk_17d4ec0_Mesh* mesh = field_20->GetMesh(level);
    if (mesh != nullptr) {
        Unk_17871c0(mesh, commandBuffer, 0, mesh->field_34, instanceCount);
    }
}

// 0x71017d4f10
void nn::vfx::G3dPrimitive::vf12(Unk_1787d90_CommandBuffer* commandBuffer, int instanceCount,
                                 int baseInstance, int level) {
    Unk_17d4ec0_Mesh* mesh = field_20->GetMesh(level);
    if (mesh != nullptr) {
        Unk_1787270(mesh, commandBuffer, 0, mesh->field_34, instanceCount, baseInstance);
    }
}

// A binary resource's header: the offset of its data.
struct Unk_17d4f60_Header {
    u8 _0[0x14];
    u32 field_14;
};
PKMN_OFFSET_ASSERT(Unk_17d4f60_Header, field_14, 0x14);

// Its data: a count, and offsets from the data's start to its arrays (0: none).
struct Unk_17d4f60_Data {
    u64 field_0;
    s32 field_8;
    u8 _c[0x2c];
    s32 field_38;
    u32 field_3c;
    u32 field_40;
    u32 field_44;
    u32 field_48;
    u32 field_4c;
    u32 field_50;

    const void* Get(u32 offset) const {
        return offset != 0 ? reinterpret_cast<const u8*>(this) + offset : nullptr;
    }
};
PKMN_OFFSET_ASSERT(Unk_17d4f60_Data, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_17d4f60_Data, field_38, 0x38);
PKMN_OFFSET_ASSERT(Unk_17d4f60_Data, field_50, 0x50);

static const Unk_17d4f60_Data* Unk_17d4f60_GetData(const Unk_17d4f60_Header* header) {
    return reinterpret_cast<const Unk_17d4f60_Data*>(reinterpret_cast<const u8*>(header) + header->field_14);
}

bool Unk_17d50a0(void* self, void* arg, u64 value, int count, int vertexCount, const void* array0,
                 const void* array1, const void* array2, const void* array3, const void* array4,
                 const void* array5);

// 0x71017d4f60
size_t Unk_17d4f60(const Unk_17d4f60_Header* header) {
    const Unk_17d4f60_Data* data = Unk_17d4f60_GetData(header);
    size_t arrays = 0;
    if (data->Get(data->field_3c) != nullptr) {
        arrays++;
    }
    if (data->Get(data->field_40) != nullptr) {
        arrays++;
    }
    if (data->Get(data->field_44) != nullptr) {
        arrays++;
    }
    if (data->Get(data->field_48) != nullptr) {
        arrays++;
    }
    if (data->Get(data->field_4c) != nullptr) {
        arrays++;
    }
    return data->field_8 * arrays * 0x10 + data->field_38 * 4;
}

// 0x71017d5010
bool Unk_17d5010(void* self, void* arg, const Unk_17d4f60_Header* header) {
    const Unk_17d4f60_Data* data = Unk_17d4f60_GetData(header);
    return Unk_17d50a0(self, arg, data->field_0, data->field_38, data->field_8, data->Get(data->field_3c),
                       data->Get(data->field_40), data->Get(data->field_44), data->Get(data->field_48),
                       data->Get(data->field_4c), data->Get(data->field_50));
}
