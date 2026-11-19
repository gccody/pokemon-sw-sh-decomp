// Scope: common
// The bank reader: data from a bank in memory, or read from a file into a
// buffer. Placeholder names.
#include "containers.h"

void* Unk_3046a0(int poolId, size_t size, u32 align);
u32 Unk_304740(int poolId, void* ptr);

struct Unk_34e250_Reader {
    u8 _0[8];
    u8* field_8;  // read position in the file buffer
    u32 field_10;  // bytes left
    u8 _14[0xc];
    void* field_20;  // buffer allocated for a read
    u8* field_28;  // read position in memory
    void* field_30;  // the file, null for a bank in memory
};
PKMN_OFFSET_ASSERT(Unk_34e250_Reader, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_34e250_Reader, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_34e250_Reader, field_20, 0x20);
PKMN_OFFSET_ASSERT(Unk_34e250_Reader, field_30, 0x30);

u32 Unk_34e350(Unk_34e250_Reader* self, void* buffer, u32 size, u32* read);

// 0x710034e250
void* Unk_34e250(void* self_, u32 size) {
    Unk_34e250_Reader* self = static_cast<Unk_34e250_Reader*>(self_);
    if (self->field_30 == nullptr) {
        u32 left = self->field_10;
        u32 n = left > size ? size : left;
        self->field_10 = left - n;
        u8* p = self->field_28;
        self->field_28 = p + n;
        return p;
    }
    u32 left = self->field_10;
    if (left >= size) {
        u8* p = self->field_8;
        self->field_8 = p + size;
        self->field_10 = left - size;
        return p;
    }
    self->field_20 = Unk_3046a0(Unk_237e820, (left & 0x1f) == 0 ? size : size + 0x1f, 0x20);
    if (self->field_20 == nullptr)
        return nullptr;
    u32 misalign = left & 0x1f;
    u8* buffer = static_cast<u8*>(self->field_20) + (misalign != 0 ? 0x20 - misalign : 0);
    u32 read;
    if (Unk_34e350(self, buffer, size, &read) == 1 && read == size)
        return buffer;
    Unk_304740(Unk_237e820, self->field_20);
    self->field_20 = nullptr;
    return nullptr;
}

// 0x710034e590
u32 Unk_34e590(Unk_34e250_Reader* self, void* buffer, u32 size) {
    u32 read = 0;
    u32 result = Unk_34e350(self, buffer, size, &read);
    if (result == 1 && read != size)
        return 0x38;
    return result;
}
