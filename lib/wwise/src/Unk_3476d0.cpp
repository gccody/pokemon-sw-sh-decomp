// Scope: common
// Eight instances of one function template: take an object of some type from
// its index (Unk_3476d0_Index), or create and initialise it when the index
// doesn't have it, and append it to an array. Each instance has its own
// create and initialise functions. Placeholder names.
#include "Unk_3476d0.h"


void Unk_34e550_call(Unk_34e550* self);
extern nn::os::MutexType Unk_24bbc90;

template <Unk_3476d0_Obj* (*Create)(u32), u32 (*Init)(Unk_3476d0_Obj*, u32*, u32)>
static inline u32 Unk_3476d0_Read(Unk_3476d0_Self* self, const Unk_3476d0_Data* data,
                                  Unk_3476d0_Out* out, Unk_3476d0_Index* index) {
    u32* source = Unk_34e250(&self->field_8, data->field_1);
    if (source == nullptr)
        return 2;
    u32 id = *source;
    u32 result = 1;
    Unk_3476d0_Obj* obj = index->GetAndAddRef(id);
    if (obj == nullptr) {
        nn::os::LockMutex(&Unk_24bbc90);
        obj = Create(id);
        if (obj == nullptr) {
            result = 2;
        } else {
            result = Init(obj, source, data->field_1);
            if (result != 1)
                obj->vf3();
        }
        nn::os::UnlockMutex(&Unk_24bbc90);
    }
    if (result == 1) {
        Unk_3476d0_Obj** slot = out->field_60.AddLast();
        if (slot != nullptr)
            *slot = obj;
    }
    Unk_34e550_call(reinterpret_cast<Unk_34e550*>(&self->field_8));
    if (result == 0x5a)
        result = 1;
    return result;
}

#define UNK_3476D0_READ(addr, create, init)                                                      \
    Unk_3476d0_Obj* Unk_##create(u32 id);                                                         \
    u32 Unk_##init(Unk_3476d0_Obj* self, u32* source, u32 id);                                    \
    u32 Unk_##addr(Unk_3476d0_Self* self, const Unk_3476d0_Data* data, Unk_3476d0_Out* out,       \
                   Unk_3476d0_Index* index) {                                                     \
        return Unk_3476d0_Read<Unk_##create, Unk_##init>(self, data, out, index);                 \
    }

// 0x71003476d0
UNK_3476D0_READ(3476d0, 3b89e0, 3b7ed0)
// 0x7100347840
UNK_3476D0_READ(347840, 363ef0, 363980)
// 0x71003479b0
UNK_3476D0_READ(3479b0, 34b010, 34b140)
// 0x7100348080
UNK_3476D0_READ(348080, 34c610, 34c780)
// 0x71003484f0
UNK_3476D0_READ(3484f0, 35c210, 35c490)
// 0x7100348660
UNK_3476D0_READ(348660, 360c20, 35ff30)
// 0x71003487d0
UNK_3476D0_READ(3487d0, 360ec0, 35ff30)
// 0x7100348940
UNK_3476D0_READ(348940, 361160, 35ff30)

// The same, but the object goes to Unk_347060 instead of an array.
void Unk_347060(Unk_3476d0_Self* self, Unk_3476d0_Out* out, Unk_3476d0_Obj* obj);

template <Unk_3476d0_Obj* (*Create)(u32), u32 (*Init)(Unk_3476d0_Obj*, u32*, u32)>
static inline u32 Unk_307430_Read(Unk_3476d0_Self* self, const Unk_3476d0_Data* data,
                                  Unk_3476d0_Out* out, Unk_3476d0_Index* index) {
    u32* source = Unk_34e250(&self->field_8, data->field_1);
    if (source == nullptr)
        return 2;
    u32 id = *source;
    u32 result = 1;
    Unk_3476d0_Obj* obj = index->GetAndAddRef(id);
    if (obj == nullptr) {
        nn::os::LockMutex(&Unk_24bbc90);
        obj = Create(id);
        if (obj == nullptr) {
            result = 2;
        } else {
            result = Init(obj, source, data->field_1);
            if (result != 1)
                obj->vf3();
        }
        nn::os::UnlockMutex(&Unk_24bbc90);
    }
    if (result == 1)
        Unk_347060(self, out, obj);
    Unk_34e550_call(reinterpret_cast<Unk_34e550*>(&self->field_8));
    if (result == 0x5a)
        result = 1;
    return result;
}

#define UNK_307430_READ(addr, create, init)                                                      \
    Unk_3476d0_Obj* Unk_##create(u32 id);                                                         \
    u32 Unk_##init(Unk_3476d0_Obj* self, u32* source, u32 id);                                    \
    u32 Unk_##addr(Unk_3476d0_Self* self, const Unk_3476d0_Data* data, Unk_3476d0_Out* out,       \
                   Unk_3476d0_Index* index) {                                                     \
        return Unk_307430_Read<Unk_##create, Unk_##init>(self, data, out, index);                 \
    }

// 0x7100307430
UNK_307430_READ(307430, 30db80, 30dc10)
// 0x7100307580
UNK_307430_READ(307580, 30ef90, 30f070)
// 0x71003076d0
UNK_307430_READ(3076d0, 307b70, 307c30)
