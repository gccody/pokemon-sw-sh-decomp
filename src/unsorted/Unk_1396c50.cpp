// Scope: common
// The block store's reads of an array of 10 s32 (src/unsorted/families/
// Unk_13471e0.h), for Unk_2433340 (src/unsorted/Unk_1396620.cpp): what an
// array's block holds is a header (a kind byte, 5, and the element count as a
// u32), then the element type's byte (10 for an s32) and the elements. These
// are the array's versions of the store's Unk_1346030 and of the reader's
// Unk_1346860 (free functions here: the reader's class is declared in a shared
// header). Placeholder names: rename once the classes are known.
#include "unsorted/families/Unk_13471e0.h"

// What Unk_13477b0 reads of a block's header: its kind, the type of an
// array's elements and its count or size.
struct Unk_13477b0_Header {
    u8 field_0;
    u8 field_1;
    u8 field_2;
    u32 field_4;
};
PKMN_SIZE_ASSERT(Unk_13477b0_Header, 0x8);
PKMN_OFFSET_ASSERT(Unk_13477b0_Header, field_4, 0x4);

// 0x71013477b0: reads a block's header.
Unk_13477b0_Header Unk_13477b0(Unk_2431910* self);

// The kind of an array's header and the type of an s32.
static const u8 kArray = 5;
static const u8 kS32 = 10;

// Whether a type is one of the fixed-size ones (8 to 17).
static bool IsFixedType(u8 type) {
    return type >= 8 && type < 18;
}

// Reads `size` bytes at the reader's position and moves it past them.
static bool Read(Unk_2431910* self, void* dst, u64 size) {
    bool ok = false;
    Unk_2431940* stream = self->vf3();
    if (dst != nullptr && stream->vf5()->vf2(size, stream->field_8))
        ok = stream->vf2(dst, size, 0);
    self->vf2()->field_8 += size;
    return ok;
}

// The same, for the elements of an array.
static bool ReadElements(Unk_2431910* self, s32* data, u64 count) {
    u64 size = count * sizeof(s32);
    Unk_2431940* stream = self->vf3();
    if (data != nullptr && stream->vf5()->vf2(size, stream->field_8)) {
        bool ok = stream->vf2(data, size, 0);
        self->vf2()->field_8 += size;
        return ok;
    }
    self->vf2()->field_8 += size;
    return false;
}

// 0x7101396ff0: reads the elements of an array of `count`, room for `max`.
Unk_1346860_Result Unk_1396ff0(Unk_2431910* self, u32 count, s32* data, u64 max) {
    if (count <= max) {
        u8 type;
        if (Read(self, &type, sizeof(type)) && type == kS32 && ReadElements(self, data, count))
            return {true, count};
    }
    return {false, count};
}

// 0x7101396e70: reads an array, room for `max` elements.
// NON_MATCHING: control flow: the failed read of the count gets its own copy
// of the reader's advance (the original keeps one, then tests the result),
// and the null check of `data` returns before the prologue instead of through
// the shared return.
Unk_1346860_Result Unk_1396e70(Unk_2431910* self, s32* data, u64 max) {
    Unk_1346860_Result result;
    result.field_0 = false;
    if (data == nullptr)
        return result;
    u32 count;
    u8 kind;
    if (!Read(self, &kind, sizeof(kind)) || kind != kArray)
        return result;
    if (!Read(self, &count, sizeof(count)))
        return result;
    result = Unk_1396ff0(self, count, data, max);
    return result;
}

// 0x7101396c50
Unk_1346860_Result Unk_1396c50(Unk_13471e0_Store* self,
                               const u32& key,
                               s32 (&data)[10],
                               const u64& count) {
    nn::os::LockMutex(&self->field_78);
    if (self->field_58 != nullptr)
        self->field_58->vf5(&key);
    Unk_1346860_Result result;
    result.field_0 = false;
    if (Unk_13471e0_Entry* entry = self->Unk_Find(key)) {
        Unk_2431910 reader = Unk_13471e0_Store::Unk_Reader(entry);
        result = Unk_1396e70(&reader, data, count);
    }
    nn::os::UnlockMutex(&self->field_78);
    return result;
}

// 0x7101397160: whether an entry holds an array of s32.
// NON_MATCHING: the kind and element type tests are merged into one test of
// the header's low 16 bits (the original tests the two bytes apart).
bool Unk_1397160(Unk_13471e0_Store* self, const Unk_13471e0_Entry* entry) {
    Unk_2431910 reader = Unk_13471e0_Store::Unk_Reader(entry);
    Unk_13477b0_Header header = Unk_13477b0(&reader);
    return header.field_0 == kArray && header.field_1 == kS32 && IsFixedType(header.field_1) &&
           (header.field_2 == 0 || header.field_4 == 0);
}
