// Scope: common
// More instances of Unk_3476d0.cpp's function template: other ways to create
// and initialise the object (a policy class each), and an index that is a
// member of a global object. Placeholder names.
#include <nn/os.h>
#include "containers.h"

struct Unk_347550_Obj {
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();  // release
    virtual u32 vf4(u32* source, u32 id);
    virtual u32 vf5(u32* source, u32 id);

    Unk_347550_Obj* field_8;  // next in the hash chain
    u32 field_10;  // key
    u32 field_14;  // reference count
};
PKMN_OFFSET_ASSERT(Unk_347550_Obj, field_10, 0x10);

struct Unk_347550_Index {
    nn::os::MutexType field_0;
    Unk_Array<Unk_347550_Obj*> field_20;  // buckets

    Unk_347550_Obj* GetAndAddRef(u32 key) {
        nn::os::LockMutex(&field_0);
        Unk_347550_Obj* p = nullptr;
        if (field_20.Length() != 0) {
            u32 bucket = key % field_20.Length();
            for (p = field_20.field_0[bucket]; p != nullptr; p = p->field_8) {
                if (p->field_10 == key)
                    break;
            }
            if (p != nullptr)
                p->field_14++;
        }
        nn::os::UnlockMutex(&field_0);
        return p;
    }
};
PKMN_OFFSET_ASSERT(Unk_347550_Index, field_20, 0x20);

struct Unk_347550_Data {
    u8 field_0;
    u32 field_1;
} __attribute__((packed));

struct Unk_347550_Out {
    u8 _0[0x60];
    Unk_Array<Unk_347550_Obj*> field_60;
};
PKMN_OFFSET_ASSERT(Unk_347550_Out, field_60, 0x60);

struct Unk_34e550;
struct Unk_347550_Self {
    u8 _0[8];
    u8 field_8;  // start of a member (Unk_34e250, Unk_34e550_call)
};

u32* Unk_34e250(void* self, u32 id);
void Unk_34e550_call(Unk_34e550* self);
extern nn::os::MutexType Unk_24bbc90;

template <class P>
static inline u32 Unk_347550_Read(Unk_347550_Self* self, const Unk_347550_Data* data,
                                  Unk_347550_Out* out, Unk_347550_Index* index) {
    u32* source = Unk_34e250(&self->field_8, data->field_1);
    if (source == nullptr)
        return 2;
    u32 id = *source;
    u32 result = 1;
    Unk_347550_Obj* obj = P::Index(index)->GetAndAddRef(id);
    if (obj == nullptr) {
        nn::os::LockMutex(&Unk_24bbc90);
        obj = P::Create(id);
        if (obj == nullptr) {
            result = 2;
        } else {
            result = P::Init(obj, source, data);
            if (result != 1)
                obj->vf3();
        }
        nn::os::UnlockMutex(&Unk_24bbc90);
    }
    if (result == 1) {
        Unk_347550_Obj** slot = out->field_60.AddLast();
        if (slot != nullptr)
            *slot = obj;
    }
    Unk_34e550_call(reinterpret_cast<Unk_34e550*>(&self->field_8));
    if (P::kPartial && result == 0x5a)
        result = 1;
    return result;
}

#define UNK_347550_READ(addr)                                                                     \
    u32 Unk_##addr(Unk_347550_Self* self, const Unk_347550_Data* data, Unk_347550_Out* out,       \
                   Unk_347550_Index* index) {                                                     \
        return Unk_347550_Read<Unk_##addr##_Policy>(self, data, out, index);                      \
    }

Unk_347550_Obj* Unk_391800(u32 id, bool a1);
u32 Unk_391040(Unk_347550_Obj* self, u32* source, u32 id);
Unk_347550_Obj* Unk_34d7e0(u32 id);
Unk_347550_Obj* Unk_36a820(u32 id, bool a1);

struct Unk_347f00_Obj {
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
    virtual void vf14();
    virtual void vf15();
    virtual void vf16();
    virtual void vf17();
    virtual void vf18();
    virtual void vf19();
    virtual void vf20();
    virtual void vf21();
    virtual void vf22();
    virtual void vf23();
    virtual void vf24();
    virtual void vf25();
    virtual void vf26();
    virtual void vf27();
    virtual void vf28();
    virtual void vf29();
    virtual void vf30();
    virtual void vf31();
    virtual void vf32();
    virtual void vf33();
    virtual void vf34();
    virtual void vf35();
    virtual void vf36();
    virtual void vf37();
    virtual void vf38();
    virtual void vf39();
    virtual void vf40();
    virtual void vf41();
    virtual void vf42();
    virtual void vf43();
    virtual void vf44();
    virtual void vf45();
    virtual void vf46();
    virtual void vf47();
    virtual void vf48();
    virtual void vf49();
    virtual void vf50();
    virtual void vf51();
    virtual void vf52();
    virtual void vf53();
    virtual void vf54();
    virtual void vf55();
    virtual void vf56();
    virtual void vf57();
    virtual void vf58();
    virtual void vf59();
    virtual void vf60();
    virtual void vf61();
    virtual void vf62();
    virtual void vf63();
    virtual void vf64();
    virtual void vf65();
    virtual void vf66();
    virtual void vf67();
    virtual void vf68();
    virtual void vf69();
    virtual void vf70();
    virtual void vf71();
    virtual void vf72();
    virtual void vf73();
    virtual void vf74();
    virtual void vf75();
    virtual void vf76();
    virtual u32 vf77(u32* source, u32 id);
};

struct Unk_347550_Policy {
    static Unk_347550_Index* Index(Unk_347550_Index* index) { return index; }
    static Unk_347550_Obj* Create(u32 id) { return Unk_391800(id, true); }
    static u32 Init(Unk_347550_Obj* obj, u32* source, const Unk_347550_Data* data) { return Unk_391040(obj, source, data->field_1); }
    static const bool kPartial = true;
};

struct Unk_347f00_Policy {
    static Unk_347550_Index* Index(Unk_347550_Index* index) { return index; }
    static Unk_347550_Obj* Create(u32 id) { return Unk_34d7e0(id); }
    static u32 Init(Unk_347550_Obj* obj, u32* source, const Unk_347550_Data* data) {
        return reinterpret_cast<Unk_347f00_Obj*>(obj)->vf77(source, data->field_1);
    }
    static const bool kPartial = true;
};

struct Unk_3481f0_Policy {
    static Unk_347550_Index* Index(Unk_347550_Index* index) { return index; }
    static Unk_347550_Obj* Create(u32 id) { return Unk_36a820(id, false); }
    static u32 Init(Unk_347550_Obj* obj, u32* source, const Unk_347550_Data* data) { return obj->vf5(source, data->field_1); }
    static const bool kPartial = true;
};

struct Unk_348370_Policy {
    static Unk_347550_Index* Index(Unk_347550_Index* index) { return index; }
    static Unk_347550_Obj* Create(u32 id) { return Unk_36a820(id, true); }
    static u32 Init(Unk_347550_Obj* obj, u32* source, const Unk_347550_Data* data) { return obj->vf5(source, data->field_1); }
    static const bool kPartial = true;
};

// 0x7100347550
UNK_347550_READ(347550)
// 0x7100347f00
UNK_347550_READ(347f00)
// 0x71003481f0
UNK_347550_READ(3481f0)
// 0x7100348370
UNK_347550_READ(348370)

// The indexes of a global object (0x71024bbbb8).
struct Unk_24bbbb8_T {
    u8 _0[0x70];
    Unk_347550_Index field_70;
};
PKMN_OFFSET_ASSERT(Unk_24bbbb8_T, field_70, 0x70);
extern Unk_24bbbb8_T* Unk_24bbbb8;

Unk_347550_Obj* Unk_3b1950(u32 id);
u32 Unk_3b1a50(Unk_347550_Obj* self, u32* source, u32 id);

struct Unk_347b20_Policy {
    static Unk_347550_Index* Index(Unk_347550_Index*) { return &Unk_24bbbb8->field_70; }
    static Unk_347550_Obj* Create(u32 id) { return Unk_3b1950(id); }
    static u32 Init(Unk_347550_Obj* obj, u32* source, const Unk_347550_Data* data) { return Unk_3b1a50(obj, source, data->field_1); }
    static const bool kPartial = false;
};

// 0x7100347b20
u32 Unk_347b20(Unk_347550_Self* self, const Unk_347550_Data* data, Unk_347550_Out* out) {
    return Unk_347550_Read<Unk_347b20_Policy>(self, data, out, nullptr);
}

