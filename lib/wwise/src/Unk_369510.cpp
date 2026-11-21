// Scope: common
// The destructors of the class with the vtables 0x7102381490 and
// 0x71023815b0 (what a plug-in gets to ask about the sound it is in): the
// complete one and the deleting one, each also as the second base's thunk
// with the destructor inlined. Free functions with placeholder names.
#include "Unk_369950.h"

void operator delete(void* ptr) noexcept;
extern "C" void* memcpy(void* dest, const void* src, size_t size);
extern "C" void* memset(void* dest, int value, size_t size);

extern void* Unk_2381490[];
extern void* Unk_2384248[];
extern void* Unk_2380be8[];

void Unk_362360(Unk_362360_T* self);
void Unk_3d45c0_call(Unk_3d45c0* self, u64 value);
void Unk_36a5e0_set(Unk_36a5e0* self);
void Unk_3cd470(void* self);
// The destructor of the member's base, which sets the vtable 0x7102384190:
// its row has a constructor's name (src/unsorted/ctor).
void Unk_3cd300(void* self) __asm__("_ZN11Unk_2384190C2Ev");

static inline void Unk_369510_Dtor(Unk_369950_T* self) {
    self->vptr = Unk_2381490 + 2;
    self->vptr2 = Unk_2381490 + 0x26;
    Unk_362360(&self->field_68);
    if (self->field_50 != nullptr)
        Unk_3d45c0_call(self->field_50, reinterpret_cast<u64>(self));
    Unk_36a5e0_set(&self->field_20);
    Unk_3cd470(self->field_f0);
    self->field_e0 = Unk_2384248 + 2;
    Unk_3cd300(self->field_f0);
    // The base at 0x68 has its own vtable back, and its destructor calls the
    // sixth virtual function through it.
    Unk_SetVtable(&self->field_68, Unk_2380be8);
    reinterpret_cast<void (*)(Unk_362360_T*)>(Unk_2380be8[7])(&self->field_68);
}

static inline Unk_369950_T* Unk_3695b0_Self(Unk_369950_Base2* base) {
    return reinterpret_cast<Unk_369950_T*>(reinterpret_cast<u8*>(base) - 8);
}

// 0x7100369510
void Unk_369510(Unk_369950_T* self) {
    Unk_369510_Dtor(self);
}

// 0x71003695b0
void Unk_3695b0(Unk_369950_Base2* base) {
    Unk_369510_Dtor(Unk_3695b0_Self(base));
}

// 0x7100369650
void Unk_369650(Unk_369950_T* self) {
    Unk_369510_Dtor(self);
    operator delete(self);
}

// 0x71003696f0
void Unk_3696f0(Unk_369950_Base2* base) {
    Unk_369950_T* self = Unk_3695b0_Self(base);
    Unk_369510_Dtor(self);
    operator delete(self);
}

extern int Unk_2381488;
void* Unk_3046a0(int poolId, size_t size, u32 align);
void Unk_3cd230(void* self);

// What the context is created for (the object its key comes from when it
// has one).
struct Unk_3d45c0 {
    u8 _0[0x70];
    u64 field_70;
    u64 field_78;
    u8 _80[0x10];
    u8 field_90;
};
void Unk_3d4550(Unk_3d45c0* self, Unk_369950_T* context);

// The contexts, by the first one.
struct Unk_3697a0_List {
    u32 field_0;  // how many
    Unk_369950_T* field_8;
};

static inline void Unk_3697a0_Init(Unk_369950_T* self, Unk_3d08c0_Self* a1, Unk_3d45c0* a2, void* a3,
                                   u32 a4, u32 a5) {
    self->field_20.field_0 = 0;
    self->vptr = Unk_2381490 + 2;
    self->vptr2 = Unk_2381490 + 0x26;
    self->field_10[0] = 1.0f;
    self->field_10[1] = 1.0f;
    self->field_10[2] = 1.0f;
    self->field_10[3] = 1.0f;
    self->field_20.field_8 = 0;
    self->field_20.field_10 = 0;
    self->field_20.field_18 = 0;
    self->field_48 = a1;
    self->field_50 = a2;
    self->field_58 = a3;
    self->field_60 = 0;
    Unk_SetVtable(&self->field_68, Unk_2380be8);
    self->field_68.field_8 = nullptr;
    self->field_68.field_10 = nullptr;
    self->field_68.field_18 = 0;
    self->field_68.field_20 = 0;
    self->field_68.field_28 = 0;
    self->field_68.field_30 = 0xff;
    self->field_68.field_38 = 0xff;
    self->field_68.field_40 = 0;
    self->field_68.field_48.field_0 = nullptr;
    self->field_68.field_48.field_8 = 0;
    self->field_68.field_48.field_c = 0;
    self->field_68.field_58 = nullptr;
    self->field_d0 = 0;
    self->field_e0 = Unk_2384248 + 2;
    self->field_e8 = 0;
    Unk_3cd230(self->field_f0);
    self->field_290 = 1.0f;
    self->field_294 = -4096.0f;
    self->field_298 = -4096.0f;
    self->field_29c = 0;
    self->field_2a0 = a4;
    self->field_2a4_0 = a5;
    self->field_2a4_1 = a5;
    self->field_2a4_2 = false;
    self->field_c8 = a2->field_70 != 0 ? a2->field_78 : a1->vf2();
    Unk_3d4550(a2, self);
}

// 0x71003697a0: a new context at the front of the list, null without memory.
// NON_MATCHING: after the member at 0xf0 is constructed, the original loads
// the byte with the three flags and clears them before it stores the two
// pairs of floats (the loaded byte in w9, the constants in x8); here the
// stores come first and the registers are the other way round. The rest
// matches: the stores of the constructor are in the order of the members,
// which is what gives the original's order (runs of zero stores become
// memsets, and a store can't move over a vtable's load from the GOT).
Unk_369950_T* Unk_3697a0(Unk_3697a0_List* list, Unk_3d08c0_Self* a1, Unk_3d45c0* a2, void* a3, u32 a4,
                         u32 a5) {
    Unk_369950_T* self =
        static_cast<Unk_369950_T*>(Unk_3046a0(Unk_2381488, sizeof(Unk_369950_T), 0x10));
    if (self != nullptr) {
        Unk_3697a0_Init(self, a1, a2, a3, a4, a5);
        if (list->field_8 != nullptr) {
            self->field_40 = list->field_8;
            list->field_8 = self;
        } else {
            list->field_8 = self;
            self->field_40 = nullptr;
        }
        list->field_0++;
    }
    return self;
}

// A reference to what the sound's source is asked for, released when it goes.
struct Unk_384340_Ref {
    Unk_360c20_T* field_0;
    u16 field_8;

    Unk_384340_Ref() : field_0(nullptr) {}
    ~Unk_384340_Ref() {
        if (field_0 != nullptr) {
            field_0->vf3();
            field_0 = nullptr;
        }
    }
};

void Unk_384340(u64 source, Unk_384340_Ref* out);

// The object the sound is the second base of (0x18 bytes in).
struct Unk_369b40_First {
    u64 field_0[3];
};
struct Unk_369b40_Whole : Unk_369b40_First, Unk_369950_Sound {};

Unk_360c20_Params* Unk_361400(Unk_362360_T* self, Unk_360c20_T* object, Unk_369950_Sound* sound);

// 0x7100369b40: what the object at 0x68 refers to, set up at the first call.
Unk_360c20_Params* Unk_369b40(Unk_369950_T* self) {
    if (self->field_2a4_2)
        return self->field_68.field_8;
    self->field_2a4_2 = true;
    Unk_384340_Ref object;
    Unk_384340(self->field_48->field_20->field_148, &object);
    if (object.field_0 == nullptr)
        return nullptr;
    Unk_369b40_Whole* whole = static_cast<Unk_369b40_Whole*>(self->field_48->field_20);
    return Unk_361400(&self->field_68, object.field_0, whole);
}

// 0x710036a100: the context's two buffers copied out, or zeros without them.
void Unk_36a100(Unk_369950_T* self, void* out1, void* out2) {
    u32 size = self->field_29c;
    u32 n = self->field_50->field_90;
    u64 buffer = self->field_20.field_0;
    u32 count = ((n + 3) & ~3) * size;
    if (buffer != 0) {
        if (count != 0) {
            memcpy(out1, reinterpret_cast<void*>(self->field_20.field_18), count * sizeof(f32));
            memcpy(out2, reinterpret_cast<void*>(self->field_20.field_10), count * sizeof(f32));
        }
    } else {
        if (count != 0) {
            memset(out1, 0, count * sizeof(f32));
            memset(out2, 0, count * sizeof(f32));
        }
    }
}
