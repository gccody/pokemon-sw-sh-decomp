// Scope: common
// The block store's writes of an array of 10 s32 (src/unsorted/families/
// Unk_13471e0.h), for Unk_2433340 (src/unsorted/Unk_1396620.cpp), in the
// layout its reads take (src/unsorted/Unk_1396c50.cpp): these are the array's
// versions of the store's Unk_1347350 and Unk_13475a0 and of the writer's
// Unk_1347af0 (free functions here: the writer's class is declared in a shared
// header). Then a read of one u8 by key. Placeholder names: rename once the
// classes are known.
#include "battle/battle_engine/Unk_137af00.h"

// The kind of an array's header and the type of an s32.
static const u8 kArray = 5;
static const u8 kS32 = 10;

// The size of an array's element type and elements.
static u64 ElementsSize(u64 count) {
    return count * sizeof(s32) + 1;
}

// Whether there's room for `size` bytes at the writer's position.
static bool CanWrite(Unk_24319f0* self, u64 size) {
    Unk_2431940* stream = self->vf3();
    return stream->vf5()->vf3(size, stream->field_8);
}

// Writes `size` bytes at the writer's position and moves it past them.
static void Write(Unk_24319f0* self, const void* src, u64 size) {
    Unk_2431940* stream = self->vf2();
    if (src != nullptr && stream->vf5()->vf3(size, stream->field_8))
        stream->vf3(src, size, 0);
    self->vf2()->field_8 += size;
}

template <class T>
static void WriteValue(Unk_24319f0* self, T value) {
    Write(self, &value, sizeof(value));
}

// 0x71013978e0: writes the elements of an array.
bool Unk_13978e0(Unk_24319f0* self, const s32* data, u64 count) {
    if (!CanWrite(self, ElementsSize(count)))
        return false;
    WriteValue<u8>(self, kS32);
    Write(self, data, count * sizeof(s32));
    return true;
}

// 0x7101397760: writes an array.
bool Unk_1397760(Unk_24319f0* self, const s32* data, u64 count) {
    if (data == nullptr)
        return false;
    if (!CanWrite(self, ElementsSize(count) + 5))
        return false;
    WriteValue<u8>(self, kArray);
    WriteValue<u32>(self, count);
    return Unk_13978e0(self, data, count);
}

// 0x71013972f0
bool Unk_13972f0(Unk_13471e0_Store* self,
                 Unk_13471e0_Entry* entry,
                 const s32 (&data)[10],
                 const u64& count) {
    nn::os::LockMutex(&self->field_78);
    if (self->field_58 != nullptr)
        self->field_58->vf6(entry);
    bool ok = false;
    if (self->Unk_Resize(entry, ElementsSize(count) + 5)) {
        Unk_24319f0 writer = Unk_13471e0_Store::Unk_Writer(entry);
        ok = Unk_1397760(&writer, data, count);
    }
    nn::os::UnlockMutex(&self->field_78);
    return ok;
}

// 0x7101397540
// NON_MATCHING: as the store's Unk_13475a0 (src/unsorted/families/
// Unk_13471e0.h): the original takes the address of field_78 again for
// Unk_Sort's lock instead of reusing the outer lock's, and keeps the result in
// w20, which lets the failure paths share their `mov w20, wzr`.
bool Unk_1397540(Unk_13471e0_Store* self, const u32& key, const s32 (&data)[10], const u64& count) {
    nn::os::LockMutex(&self->field_78);
    if (self->field_58 != nullptr)
        self->field_58->vf7(&key);
    bool ok = false;
    Unk_1347cd0_Result added = self->Unk_1347cd0(key, ElementsSize(count) + 5);
    if (Unk_13471e0_Entry* entry = added.field_0) {
        Unk_24319f0 writer = Unk_13471e0_Store::Unk_Writer(entry);
        if (Unk_1397760(&writer, data, count)) {
            self->Unk_Sort();
            ok = true;
        } else {
            self->field_38->vf3(added.field_0->field_8, added.field_0->field_10);
            self->field_8.pop_back();
        }
    }
    nn::os::UnlockMutex(&self->field_78);
    return ok;
}

// The key of the u8 Unk_1397a60 reads.
extern const u32 Unk_1f34728 __attribute__((visibility("hidden")));

// 0x7101397a60
u8 Unk_1397a60() {
    Unk_13471e0_Store* store = Unk_137e480(Unk_24ba4e0, 0);
    Unk_2432ba8_Value<u8> value = Unk_134d370(store, Unk_1f34728);
    if (!value.field_0 && store->field_58 != nullptr)
        store->field_58->vf10(&Unk_1f34728);
    return value.field_value;
}
