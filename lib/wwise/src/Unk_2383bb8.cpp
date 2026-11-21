// Scope: common
// The class with the vtable 0x7102383bb8: an object kept by ID in the index
// at 0x2d8 of the global object, with 28 bytes of parameters (six of them
// floats set one at a time). Written from the executable. Placeholder names.
#include "Unk_Indexed.h"

// The parameters: 28 bytes.
struct Unk_2383bb8_Params {
    u32 field_0;
    f32 field_4;
    f32 field_8;
    f32 field_c;
    f32 field_10;
    f32 field_14;
    f32 field_18;
};
PKMN_SIZE_ASSERT(Unk_2383bb8_Params, 0x1c);

struct Unk_2383bb8_T : Unk_Indexed {
    Unk_2383bb8_Params field_18;

    void SetParams(Unk_2383bb8_Params params) { field_18 = params; }
    Unk_2383bb8_Params* GetParams() { return &field_18; }
};
PKMN_SIZE_ASSERT(Unk_2383bb8_T, 0x38);

// A lock for a scope.
struct Unk_2383bb8_Lock {
    nn::os::MutexType* field_0;

    explicit Unk_2383bb8_Lock(nn::os::MutexType* mutex) : field_0(mutex) {
        nn::os::LockMutex(field_0);
    }
    ~Unk_2383bb8_Lock() { nn::os::UnlockMutex(field_0); }
};

// The object of an ID with one more reference, or null. (The lock is an
// object: each way out unlocks.)
static inline Unk_2383bb8_T* Unk_2383bb8_GetAndAddRef(u32 id) {
    Unk_Index* index = Unk_GetIndex<0x2d8>();
    Unk_2383bb8_Lock lock(&index->field_0);
    if (index->field_20.Length() != 0) {
        u32 bucket = id % index->field_20.Length();
        for (Unk_Indexed* p = index->field_20.field_0[bucket]; p != nullptr; p = p->field_8) {
            if (p->field_10 == id) {
                p->field_14++;
                return static_cast<Unk_2383bb8_T*>(p);
            }
        }
    }
    return nullptr;
}

extern void* Unk_2383bb8[];
extern nn::os::MutexType Unk_24bbc90;

// 0x71003c1c60: a new one in the index
Unk_2383bb8_T* Unk_3c1c60(u32 id, u32 arg1) {
    Unk_2383bb8_T* self = nullptr;
    if (arg1 == 0) {
        self = static_cast<Unk_2383bb8_T*>(Unk_3045e0(Unk_237e820, sizeof(Unk_2383bb8_T)));
        if (self != nullptr) {
            Unk_363510(self, id);
            Unk_SetVtable(self, Unk_2383bb8);
            self->field_18 = Unk_2383bb8_Params();
            Unk_IndexedAdd<0x2d8>(self);
        }
    }
    return self;
}

// 0x71003c1ef0
void Unk_3c1ef0(Unk_2383bb8_T* self, u32 index, f32 value) {
    switch (index) {
    case 0:
        self->field_18.field_4 = value;
        break;
    case 1:
        self->field_18.field_8 = value;
        break;
    case 2:
        self->field_18.field_c = value;
        break;
    case 3:
        self->field_18.field_10 = value;
        break;
    case 4:
        self->field_18.field_14 = value;
        break;
    case 5:
        self->field_18.field_18 = value;
        break;
    }
}

// 0x71003c1f50: the parameters of an ID: the object is made when the index
// doesn't have it
u32 Unk_3c1f50(u32 id, Unk_2383bb8_Params* params) {
    if (Unk_2383bb8_GetAndAddRef(id) != nullptr)
        return 1;
    Unk_2383bb8_Lock lock(&Unk_24bbc90);
    Unk_2383bb8_T* self = Unk_3c1c60(id, 0);
    if (self != nullptr) {
        self->SetParams(*params);
        return 1;
    }
    return 2;
}

// 0x71003c2040: the parameters of an ID, with a reference to their object
Unk_2383bb8_Params* Unk_3c2040(u32 id) {
    // Through a function: the test of the object is then still a branch when
    // the lookup is inlined, and each of its two ways gets its own unlock.
    Unk_2383bb8_T* self = Unk_2383bb8_GetAndAddRef(id);
    if (self != nullptr)
        return self->GetParams();
    return nullptr;
}

// 0x71003c20e0: the destructor is the base class's
void Unk_3c20e0(Unk_Indexed* self) {
    Unk_IndexedDtor(self);
}

// 0x71003c20f0: and the deleting one
void Unk_3c20f0(Unk_Indexed* self) {
    Unk_IndexedDtor(self);
    operator delete(self);
}
