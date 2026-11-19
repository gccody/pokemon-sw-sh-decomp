// Scope: common
// Small functions of the bank manager's TU. Placeholder names.
#include <string.h>
#include "Unk_3476d0.h"

// 0x7100347060
void Unk_347060(Unk_3476d0_Self*, Unk_3476d0_Out* out, Unk_3476d0_Obj* obj) {
    Unk_3476d0_Obj** slot = out->field_60.AddLast();
    if (slot != nullptr)
        *slot = obj;
}

struct Unk_347090 {
    u8 _0[0xc];
    u32 field_c;
};
PKMN_OFFSET_ASSERT(Unk_347090, field_c, 0xc);

// 0x7100347090
u32 Unk_347090(const Unk_347090* self, u32 size) {
    if (size >= 0x1c)
        return self->field_c;
    return 0;
}

struct Unk_34e550;
void Unk_34e550_call(Unk_34e550* self);
u32 Unk_332a80(const char* name);

// 0x7100346320
u32 Unk_346320(Unk_3476d0_Self* self, u32 size) {
    if (size == 0)
        return 1;
    u32* data = Unk_34e250(&self->field_8, size);
    u32 length = data[0];
    const char* str = reinterpret_cast<const char*>(data + 1);
    u32 result;
    if (length == 0) {
        result = 1;
    } else {
        char* name = static_cast<char*>(__builtin_alloca(length + 1));
        strncpy(name, str, length);
        name[length] = '\0';
        result = Unk_332a80(name);
    }
    Unk_34e550_call(reinterpret_cast<Unk_34e550*>(&self->field_8));
    return result;
}

// Objects of the index at 0xa8 of the global object 0x71024bbb8.
struct Unk_346460_Obj {
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();  // release

    Unk_346460_Obj* field_8;  // next in the hash chain
    u32 field_10;  // key
    u32 field_14;  // reference count
    u8 _18[8];
    u32 field_20;  // load count
};
PKMN_OFFSET_ASSERT(Unk_346460_Obj, field_20, 0x20);

struct Unk_346460_Index {
    nn::os::MutexType field_0;
    Unk_Array<Unk_346460_Obj*> field_20;  // buckets

    Unk_346460_Obj* GetAndAddRef(u32 key) {
        nn::os::LockMutex(&field_0);
        Unk_346460_Obj* p = nullptr;
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

struct Unk_346460_Global {
    u8 _0[0xa8];
    Unk_346460_Index field_a8;
};
PKMN_OFFSET_ASSERT(Unk_346460_Global, field_a8, 0xa8);
extern Unk_346460_Global* Unk_24bbbb8;

u32 Unk_346650(void* self, void* a1, Unk_346460_Obj* obj);
void Unk_346b00(void* self, Unk_346460_Obj* obj);

// 0x7100346460
u32 Unk_346460(void* self, void* a1, u32 id) {
    Unk_346460_Obj* obj = Unk_24bbbb8->field_a8.GetAndAddRef(id);
    if (obj == nullptr)
        return 0xf;
    u32 result = 1;
    if (obj->field_20 == 0) {
        result = Unk_346650(self, a1, obj);
        if (result == 1)
            obj->vf2();
    }
    if (result == 1)
        obj->field_20++;
    obj->vf3();
    return result;
}

// 0x7100346560
u32 Unk_346560(void* self, u32 id) {
    Unk_346460_Obj* obj = Unk_24bbbb8->field_a8.GetAndAddRef(id);
    if (obj == nullptr)
        return 0xf;
    if (obj->field_20 != 0 && --obj->field_20 == 0) {
        Unk_346b00(self, obj);
        obj->vf3();
    }
    obj->vf3();
    return 1;
}
