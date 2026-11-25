// Scope: common
// The Poke Job app's save data (src/unsorted/Unk_1373180.h): writing its
// blocks to the store, and the accessors of its jobs and lists.
#include "unsorted/Unk_1373180.h"

#include <cstring>

#include "gflib3/Unk_New.h"

// The owner of the block stores (src/unsorted/Unk_1298270.h).
struct Unk_24ba4e0_Type;
extern Unk_24ba4e0_Type* Unk_24ba4e0;

// 0x710137e480: one of its two stores.
Unk_13471e0_Store* Unk_137e480(Unk_24ba4e0_Type* self, const int& which);

// 0x7101357700, 0x7101375830, 0x7101375d90: write a u32, u64 and u8 block,
// adding it if it's not there (as Unk_13471e0_Store::Unk_13456e0, sized by
// the value).
bool Unk_1357700(Unk_13471e0_Store* self, const u32& key, const u32& value);
bool Unk_1375830(Unk_13471e0_Store* self, const u32& key, const u64& value);
bool Unk_1375d90(Unk_13471e0_Store* self, const u32& key, const u8& value);

// The keys of the three blocks.
extern const u32 Unk_1f34180;
extern const u32 Unk_1f34184;
extern const u32 Unk_1f34188;

// A counter's store and key.
struct Unk_24329f0_Key {
    int field_0;
    u32 field_4;
};
PKMN_SIZE_ASSERT(Unk_24329f0_Key, 0x8);

// The counters' stores and keys.
extern const Unk_24329f0_Key Unk_24329f0[5] __attribute__((visibility("hidden")));

// 0x710076f7d0, 0x710076f7e0 (game/unk_761f70): hand an entry to `self`.
void Unk_76f7d0(void* self, void* entry);
void Unk_76f7e0(void* self, void* entry);

// The job table's owner as src/unsorted/Unk_1298270.h declares it: this
// class.
class Unk_13736e0_Owner : public Unk_239a418 {};

// 0x7101373180
void Unk_2432938::vf9() {
    {
        Unk_24ba4e0_Type* owner = Unk_24ba4e0;
        int which = 0;
        Unk_13471e0_Store* store = Unk_137e480(owner, which);
        store->Unk_13456e0(Unk_1f34180, field_60, sizeof(field_60));
    }
    {
        Unk_24ba4e0_Type* owner = Unk_24ba4e0;
        int which = 0;
        Unk_13471e0_Store* store = Unk_137e480(owner, which);
        store->Unk_13456e0(Unk_1f34184, field_1fb0, sizeof(field_1fb0));
    }
    {
        Unk_24ba4e0_Type* owner = Unk_24ba4e0;
        int which = 0;
        Unk_13471e0_Store* store = Unk_137e480(owner, which);
        store->Unk_13456e0(Unk_1f34188, field_52be8, sizeof(field_52be8));
    }
    {
        u32 value = field_52bd8;
        const Unk_24329f0_Key& key = Unk_24329f0[0];
        Unk_1357700(Unk_137e480(Unk_24ba4e0, key.field_0), key.field_4, value);
    }
    {
        u32 value = field_52bd0;
        const Unk_24329f0_Key& key = Unk_24329f0[1];
        Unk_1357700(Unk_137e480(Unk_24ba4e0, key.field_0), key.field_4, value);
    }
    {
        u32 value = field_52bd4;
        const Unk_24329f0_Key& key = Unk_24329f0[2];
        Unk_1357700(Unk_137e480(Unk_24ba4e0, key.field_0), key.field_4, value);
    }
    {
        u64 value = field_52be0;
        const Unk_24329f0_Key& key = Unk_24329f0[3];
        Unk_1375830(Unk_137e480(Unk_24ba4e0, key.field_0), key.field_4, value);
    }
    {
        u8 value = field_53120;
        const Unk_24329f0_Key& key = Unk_24329f0[4];
        Unk_1375d90(Unk_137e480(Unk_24ba4e0, key.field_0), key.field_4, value);
    }
}

// 0x71013736e0
Unk_2432938_Job* Unk_13736e0(Unk_13736e0_Owner* self, s32 id) {
    Unk_239a418* object = self;
    return &static_cast<Unk_2432938*>(object)->field_60.field_0[id];
}

// 0x71013736f0
Unk_2432938_List* Unk_2432938::Unk_13736f0(s32 list) {
    return &field_1fb0.field_0[list];
}

// 0x7101373710
void Unk_2432938::Unk_1373710(s32 job, u8 value) {
    field_60.field_0[job].field_0 = value;
}

// 0x7101373720
void Unk_2432938::Unk_1373720(s32 job, u64 time) {
    field_60.field_0[job].field_8 = time;
}

// 0x7101373730
void Unk_2432938::Unk_1373730(s32 job, u64 time) {
    field_60.field_0[job].field_10 = time;
}

// 0x7101373740
void Unk_2432938::Unk_1373740(s32 job, u8 value) {
    field_60.field_0[job].field_18 = value;
}

// 0x7101373750
void Unk_2432938::Unk_1373750(s32 job, u8 value) {
    field_60.field_0[job].field_2 = value;
}

// 0x7101373760
void Unk_2432938::Unk_1373760(s32 job, u8 value) {
    field_60.field_0[job].field_1 = value;
}

// 0x7101373770
void Unk_2432938::Unk_1373770(s32 list, void* const& object) {
    Unk_2432938_List* entries = &field_1fb0.field_0[list];
    Unk_1393080_Entry* entry = &entries->field_1[entries->field_0];
    Unk_76f7d0(object, entry);
    entries->field_0++;
}

// 0x71013737c0
// NON_MATCHING: register allocation: the object's pointer is loaded into x8
// and copied to x0 (the original loads it into x0), which shifts the count
// and addresses up a register. The ways of writing the entry's address and
// the test tried here all give the same IR.
bool Unk_2432938::Unk_13737c0(s32 list, void* const& object) {
    Unk_2432938_List* entries = &field_1fb0.field_0[list];
    if (entries->field_0 == 0)
        return false;
    Unk_1393080_Entry* entry = &entries->field_1[entries->field_0 - 1];
    void* target = object;
    Unk_76f7e0(target, entry);
    std::memset(entry, 0, sizeof(*entry));
    entries->field_0--;
    return true;
}

// 0x7101373860
Unk_239a418_Ref<Unk_76f440> Unk_2432938::Unk_1373860(s32 list,
                                                     s32 index,
                                                     Unk_239a418_Allocator* allocator) {
    Unk_2432938_List* entries = &field_1fb0.field_0[list];
    Unk_239a418_Ref<Unk_76f440> object(Unk_New().Create<Unk_76f440>(allocator, allocator));
    Unk_76f7e0(object.m_ptr, &entries->field_1[index]);
    return object;
}
