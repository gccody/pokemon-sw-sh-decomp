// Scope: common
// A class of game/unk_133d350 (vtable 0x7102433350) on Unk_2431de8 whose data
// is two arrays of 10 values, each stored in the block store
// (src/unsorted/families/Unk_13471e0.h) under a key of its own, through the
// store's writes and reads of an array (a header with the element count,
// checked by 0x7101397160 where a block's is by Unk_13471e0). field_60 starts
// as 0..9, field_88 as all 1s. Its destructor is its key function: its
// vtables and thunks are emitted here. Placeholder names: rename once the
// class is known.
#include "battle/battle_engine/Unk_137af00.h"

// The arrays' keys in the store.
extern const u32 Unk_1f34720;
extern const u32 Unk_1f34724;

// 0x7101397160: whether an entry's array header is valid.
bool Unk_1397160(Unk_13471e0_Store* self, const Unk_13471e0_Entry* entry);
// 0x71013972f0: writes over an entry's array.
bool Unk_13972f0(Unk_13471e0_Store* self,
                 Unk_13471e0_Entry* entry,
                 const s32 (&data)[10],
                 const u64& count);
// 0x7101397540: adds an array.
bool Unk_1397540(Unk_13471e0_Store* self, const u32& key, const s32 (&data)[10], const u64& count);
// 0x7101396c50: reads an array.
Unk_1346860_Result Unk_1396c50(Unk_13471e0_Store* self,
                               const u32& key,
                               s32 (&data)[10],
                               const u64& count);

// final: vf7 inlines vf9.
class Unk_2433340 final : public Unk_2431de8 {
public:
    static const int Count = 10;

    Unk_2433340();
    ~Unk_2433340() override;
    void vf7() override;  // reset both arrays and write them
    void vf8() override;  // read both arrays from the store
    void vf9() override;  // write them

    void Unk_13969a0(int index, s32 value);
    s32 Unk_13969b0(int index);
    void Unk_13969c0(int index);
    bool Unk_13969d0(int index);

private:
    void Reset() {
        for (int i = 0; i < Count; i++) {
            field_60[i] = i;
            field_88[i] = 1;
        }
    }

public:
    s32 field_60[Count];
    s32 field_88[Count];
};
PKMN_OFFSET_ASSERT(Unk_2433340, field_60, 0x60);
PKMN_OFFSET_ASSERT(Unk_2433340, field_88, 0x88);
PKMN_SIZE_ASSERT(Unk_2433340, 0xb0);

// 0x7101396860: writes an array, adding it if it's not there.
bool Unk_1396860(Unk_13471e0_Store* self, const u32& key, const s32 (&data)[10], const u64& count) {
    nn::os::LockMutex(&self->field_78);
    bool ok;
    if (self->field_98.load()) {
        if (self->field_58 != nullptr)
            self->field_58->vf12();
        ok = false;
    } else if (Unk_13471e0_Entry* entry = self->Unk_Find(key)) {
        if (!Unk_1397160(self, entry) && self->field_58 != nullptr)
            self->field_58->vf11(&key);
        ok = Unk_13972f0(self, entry, data, count);
    } else {
        ok = Unk_1397540(self, key, data, count);
    }
    nn::os::UnlockMutex(&self->field_78);
    return ok;
}

// 0x7101396620
void Unk_2433340::vf7() {
    Reset();
    vf9();
}

// 0x71013966f0
void Unk_2433340::vf9() {
    {
        Unk_24ba4e0_Type* owner = Unk_24ba4e0;
        int which = 0;
        Unk_13471e0_Store* store = Unk_137e480(owner, which);
        u64 count = Count;
        Unk_1396860(store, Unk_1f34720, field_60, count);
    }
    {
        Unk_24ba4e0_Type* owner = Unk_24ba4e0;
        int which = 0;
        Unk_13471e0_Store* store = Unk_137e480(owner, which);
        u64 count = Count;
        Unk_1396860(store, Unk_1f34724, field_88, count);
    }
}

// 0x7101396780
void Unk_2433340::vf8() {
    {
        Unk_24ba4e0_Type* owner = Unk_24ba4e0;
        int which = 0;
        Unk_13471e0_Store* store = Unk_137e480(owner, which);
        u64 count = Count;
        if (!Unk_1396c50(store, Unk_1f34720, field_60, count).field_0 && store->field_58 != nullptr)
            store->field_58->vf10(&Unk_1f34720);
    }
    {
        Unk_24ba4e0_Type* owner = Unk_24ba4e0;
        int which = 0;
        Unk_13471e0_Store* store = Unk_137e480(owner, which);
        u64 count = Count;
        if (!Unk_1396c50(store, Unk_1f34724, field_88, count).field_0 && store->field_58 != nullptr)
            store->field_58->vf10(&Unk_1f34724);
    }
}

// 0x71013969a0
void Unk_2433340::Unk_13969a0(int index, s32 value) {
    field_60[index] = value;
}

// 0x71013969b0
s32 Unk_2433340::Unk_13969b0(int index) {
    return field_60[index];
}

// 0x71013969c0
void Unk_2433340::Unk_13969c0(int index) {
    field_88[index] = 0;
}

// 0x71013969d0
bool Unk_2433340::Unk_13969d0(int index) {
    return field_88[index] == 1;
}

// 0x71013969f0
Unk_2433340::Unk_2433340() {
    Reset();
}

// 0x7101396a70, 0x7101396b60 (D0), thunks 0x7101396ac0/0x7101396bb0 (+0x48)
// and 0x7101396b10/0x7101396c00 (+0x50)
Unk_2433340::~Unk_2433340() {}
