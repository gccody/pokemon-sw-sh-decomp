// Scope: common
// NintendoSDK_gfx 7.3.2 for NVN, used by the SDK's g3d-style resources: the
// vertex and index buffers of a shape's meshes (the index buffers are labelled
// "g3d_index"), a mesh's indexed draw of a range of its submeshes, the casts
// that relocate a binary resource file, and the defaults of three info
// structs. Neither the classes nor their fields are named in the executable:
// placeholders (gfx.h).
#include <types.h>
#include "nx_middleware/gfx/gfx.h"

namespace nn {
namespace util {
// The SDK imports these (include/nn/util.h declares the class's other member).
class RelocationTable {
public:
    // _ZN2nn4util15RelocationTable8RelocateEv
    void Relocate() noexcept;
};

class BinaryFileHeader {
public:
    // _ZNK2nn4util16BinaryFileHeader11IsRelocatedEv
    bool IsRelocated() const noexcept;
    // _ZN2nn4util16BinaryFileHeader18GetRelocationTableEv
    RelocationTable* GetRelocationTable() noexcept;
};
}  // namespace util
}  // namespace nn

// The buffer's defaults (it clears the buffer's 0x48 bytes) and an empty
// function the buffer is passed to after its finalisation, both declared in
// lib/nx_middleware/leaf/Unk_1787320.cpp.
struct Unk_1787a90;
void Unk_1787a90_set(Unk_1787a90* self);
void Unk_1787ab0_update(unsigned long);

// Declared in lib/nx_middleware/gfx/Unk_1787970.cpp, Unk_1791080.cpp and
// Unk_1787d90.cpp.
struct Unk_1787ac0_Info {
    u32 field_0;
    u32 field_4;
};
void Unk_1787ac0(Unk_1787ac0_Buffer* self, Unk_1791080_Device* device, const Unk_1787ac0_Info* info,
                 Unk_1787ac0_Pool* pool, s64 offset);
void Unk_1787bb0(Unk_1787ac0_Buffer* self, Unk_1791080_Device* device);
void Unk_1787c60(void* self, void* address);
void Unk_1791380(const Unk_1787ac0_Buffer* self, const char* label);
void Unk_1788170(Unk_1787d90_CommandBuffer* self, int topology, int indexFormat,
                 const Unk_178d730_Address* indexBuffer, int indexCount, int baseVertex,
                 int instanceCount, int baseInstance);

// A buffer as these resources store it: 0x48 bytes (Unk_1787a90_set).
struct Unk_1786f50_Buffer {
    Unk_1787ac0_Buffer field_0;
    u8 _40[0x8];
};
PKMN_SIZE_ASSERT(Unk_1786f50_Buffer, 0x48);

// The vertex buffers, and the pointers to them.
struct Unk_1786f50_Vertex {
    u8 _0[0x20];
    Unk_1786f50_Buffer* field_20;
    Unk_1787ac0_Buffer** field_28;
    u8 _30[0x1d];
    u8 field_4d;
};
PKMN_OFFSET_ASSERT(Unk_1786f50_Vertex, field_20, 0x20);
PKMN_OFFSET_ASSERT(Unk_1786f50_Vertex, field_28, 0x28);
PKMN_OFFSET_ASSERT(Unk_1786f50_Vertex, field_4d, 0x4d);

// 0x7101786f50
void Unk_1786f50(Unk_1786f50_Vertex* self, Unk_1791080_Device* device) {
    int count = self->field_4d;
    for (int i = 0; i < count; ++i) {
        self->field_28[i] = &self->field_20[i].field_0;
        Unk_1787ac0_Buffer* buffer = self->field_28[i];
        if (buffer->field_0 != 0) {
            Unk_1787bb0(buffer, device);
            Unk_1787ab0_update(reinterpret_cast<unsigned long>(buffer));
        }
    }
}

// A submesh: its first index's offset in the index buffer, and its count.
struct Unk_17d4ec0_SubMesh {
    u32 field_0;
    u32 field_4;
};
PKMN_SIZE_ASSERT(Unk_17d4ec0_SubMesh, 0x8);

// A mesh: its submeshes, its index buffer (memory pool, buffer, info and
// offset in the pool), the primitive topology, the index format (also the log2
// of an index's size), the base vertex and the submesh count.
struct Unk_17d4ec0_Mesh {
    Unk_17d4ec0_SubMesh* field_0;
    Unk_1787ac0_Pool* field_8;
    Unk_1787ac0_Buffer* field_10;
    Unk_1787ac0_Info* field_18;
    u32 field_20;
    int field_24;
    int field_28;
    u8 _2c[0x4];
    int field_30;
    u16 field_34;
    u8 _36[0x2];
};
PKMN_OFFSET_ASSERT(Unk_17d4ec0_Mesh, field_18, 0x18);
PKMN_OFFSET_ASSERT(Unk_17d4ec0_Mesh, field_20, 0x20);
PKMN_OFFSET_ASSERT(Unk_17d4ec0_Mesh, field_30, 0x30);
PKMN_OFFSET_ASSERT(Unk_17d4ec0_Mesh, field_34, 0x34);
PKMN_SIZE_ASSERT(Unk_17d4ec0_Mesh, 0x38);

// A shape: its meshes, one per level of detail.
struct Unk_17d4ec0_Shape {
    u8 _0[0x18];
    Unk_17d4ec0_Mesh* field_18;
    u8 _20[0x3b];
    u8 field_5b;
};
PKMN_OFFSET_ASSERT(Unk_17d4ec0_Shape, field_18, 0x18);
PKMN_OFFSET_ASSERT(Unk_17d4ec0_Shape, field_5b, 0x5b);

// 0x7101786fd0
// NON_MATCHING: the original passes the info's size as a sixth argument to
// Unk_1787ac0, whose placeholder name has five parameters
void Unk_1786fd0(Unk_17d4ec0_Shape* self, Unk_1791080_Device* device) {
    int count = self->field_5b;
    for (int i = 0; i < count; ++i) {
        Unk_17d4ec0_Mesh* mesh = &self->field_18[i];
        Unk_1787ac0_Pool* pool = mesh->field_8;
        Unk_1787ac0_Buffer* buffer = mesh->field_10;
        Unk_1787ac0_Info* info = mesh->field_18;
        Unk_1787a90_set(reinterpret_cast<Unk_1787a90*>(buffer));
        info->field_4 = 8;
        Unk_1787ac0(buffer, device, info, pool, mesh->field_20);
        Unk_1791380(buffer, "g3d_index");
    }
}

// 0x7101787080
// NON_MATCHING: the original passes the info's size as a sixth argument to
// Unk_1787ac0, whose placeholder name has five parameters
void Unk_1787080(Unk_17d4ec0_Shape* self, Unk_1791080_Device* device, Unk_1787ac0_Pool* pool,
                 s64 offset) {
    int count = self->field_5b;
    for (int i = 0; i < count; ++i) {
        Unk_17d4ec0_Mesh* mesh = &self->field_18[i];
        Unk_1787ac0_Buffer* buffer = mesh->field_10;
        Unk_1787ac0_Info* info = mesh->field_18;
        Unk_1787a90_set(reinterpret_cast<Unk_1787a90*>(buffer));
        info->field_4 = 8;
        Unk_1787ac0(buffer, device, info, pool, mesh->field_20 + offset);
        Unk_1791380(buffer, "g3d_index");
    }
}

// 0x7101787140
void Unk_1787140(Unk_17d4ec0_Shape* self, Unk_1791080_Device* device) {
    int count = self->field_5b;
    for (int i = 0; i < count; ++i) {
        Unk_1787ac0_Buffer* buffer = self->field_18[i].field_10;
        if (buffer->field_0 != 0) {
            Unk_1787bb0(buffer, device);
            Unk_1787ab0_update(reinterpret_cast<unsigned long>(buffer));
        }
    }
}

// 0x71017871c0
void Unk_17871c0(Unk_17d4ec0_Mesh* self, Unk_1787d90_CommandBuffer* commandBuffer, int first,
                 int count, int instanceCount) {
    const Unk_17d4ec0_SubMesh* firstSubMesh = &self->field_0[first];
    const Unk_17d4ec0_SubMesh* lastSubMesh = &self->field_0[first + count - 1];
    s64 offset = firstSubMesh->field_0;
    int indexCount = lastSubMesh->field_4 + ((lastSubMesh->field_0 - offset) >> self->field_28);
    Unk_178d730_Address address = {};
    Unk_1787c60(self->field_10, &address);
    address.field_0 += offset;
    Unk_1788170(commandBuffer, self->field_24, self->field_28, &address, indexCount,
                self->field_30, instanceCount, 0);
}

// 0x7101787270
void Unk_1787270(Unk_17d4ec0_Mesh* self, Unk_1787d90_CommandBuffer* commandBuffer, int first,
                 int count, int instanceCount, int baseInstance) {
    const Unk_17d4ec0_SubMesh* firstSubMesh = &self->field_0[first];
    const Unk_17d4ec0_SubMesh* lastSubMesh = &self->field_0[first + count - 1];
    s64 offset = firstSubMesh->field_0;
    int indexCount = lastSubMesh->field_4 + ((lastSubMesh->field_0 - offset) >> self->field_28);
    Unk_178d730_Address address = {};
    Unk_1787c60(self->field_10, &address);
    address.field_0 += offset;
    Unk_1788170(commandBuffer, self->field_24, self->field_28, &address, indexCount,
                self->field_30, instanceCount, baseInstance);
}

// 0x7101787370
void* Unk_1787370(void* data) {
    nn::util::BinaryFileHeader* header = static_cast<nn::util::BinaryFileHeader*>(data);
    if (!header->IsRelocated()) {
        header->GetRelocationTable()->Relocate();
    }
    return data;
}

// 0x71017873b0
void* Unk_17873b0(void* data) {
    nn::util::BinaryFileHeader* header = static_cast<nn::util::BinaryFileHeader*>(data);
    if (!header->IsRelocated()) {
        header->GetRelocationTable()->Relocate();
    }
    return data;
}

struct Unk_17873f0_Info {
    u8 field_0;
    u8 field_1;
    u8 field_2;
    u8 field_3;
    u8 field_4;
    u8 field_5;
    u16 field_6;
    f32 field_8;
    f32 field_c;
    u32 field_10;
};
PKMN_OFFSET_ASSERT(Unk_17873f0_Info, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_17873f0_Info, field_10, 0x10);

// 0x71017873f0
void Unk_17873f0(Unk_17873f0_Info* self) {
    self->field_0 = 2;
    self->field_1 = 2;
    self->field_2 = 2;
    self->field_6 = 0x2a;
    self->field_4 = 0;
    self->field_3 = 0;
    self->field_5 = 1;
    self->field_8 = -1000.0f;
    self->field_c = 1000.0f;
    self->field_10 = 0;
}

// A state, flags (bit 0 is cleared) and a mask (all bits set).
struct Unk_1787420_Info {
    u8 field_0;
    u8 _1[0x1];
    u16 field_2;
    u32 field_4;
};
PKMN_SIZE_ASSERT(Unk_1787420_Info, 0x8);

// 0x7101787420
void Unk_1787420(Unk_1787420_Info* self) {
    self->field_2 &= ~1;
    self->field_0 = 1;
    self->field_4 = 0xffffffff;
}

struct Unk_1787440_Info {
    u8 field_0;
    u8 field_1;
    u8 field_2;
    u8 field_3;
    u16 field_4;
    u8 field_6;
    u8 _7[0x1];
    u64 field_8;
    u32 field_10;
    u8 _14[0x4];
    Unk_1787420_Info field_18;
};
PKMN_OFFSET_ASSERT(Unk_1787440_Info, field_4, 0x4);
PKMN_OFFSET_ASSERT(Unk_1787440_Info, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_1787440_Info, field_18, 0x18);
PKMN_SIZE_ASSERT(Unk_1787440_Info, 0x20);

// 0x7101787440
void Unk_1787440(Unk_1787440_Info* self) {
    self->field_0 = 2;
    self->field_1 = 0;
    self->field_2 = 2;
    self->field_3 = 3;
    self->field_4 &= ~0xf;
    self->field_10 = 0;
    self->field_8 = 0;
    self->field_6 = 0;
    Unk_1787420(&self->field_18);
}
