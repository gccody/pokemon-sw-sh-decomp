// Scope: common
// What the audio thread does with the messages of kind 0x36: the manager at
// 0x71024df1b0 (its mutex at 0xb8, what it manages at 0x18, a changed flag
// at 0xd8, the game object that listens at 0xf0). Written from the
// executable. Placeholder names.
#include <types.h>

#include <nn/os.h>

struct Unk_3e4760_Inner;

struct Unk_3e4760_Manager {
    u8 _0[0x18];
    u8 field_18[0xa0];  // what it manages
    nn::os::MutexType field_b8;
    bool field_d8;  // something changed
    u8 _d9[0x17];
    u64 field_f0;  // the game object that listens
    bool field_f8;
};
PKMN_OFFSET_ASSERT(Unk_3e4760_Manager, field_b8, 0xb8);
PKMN_OFFSET_ASSERT(Unk_3e4760_Manager, field_d8, 0xd8);
PKMN_OFFSET_ASSERT(Unk_3e4760_Manager, field_f0, 0xf0);

extern Unk_3e4760_Manager* Unk_24df1b0;
extern void* Unk_24bbbd8;
extern int Unk_237e820;
extern int Unk_2385820;

// A game object, as far as it is used here: counted.
struct Unk_3e4760_Object {
    virtual void vf0();  // the destructor

    u8 _8[0x30];
    u8* field_38;
    u32 field_40;
    u8 _44[0xc];
    u32 field_50;  // references

    void Release() {
        if (--field_50 == 0) {
            int pool = Unk_237e820;
            vf0();
            Unk_3047c0_(pool, this);
        }
    }
    static u32 Unk_3047c0_(int poolId, void* ptr);
};

struct Unk_Indexed;
u32 Unk_3047c0(int poolId, void* ptr);
void Unk_362cc0(Unk_Indexed** arg);
Unk_3e4760_Object* Unk_397bc0(void* self, u64 id);
void Unk_3e59b0(Unk_3e4760_Object* object);
void* Unk_3eb700(void* self, void* arg);
void Unk_3ec6d0(void* self, u64 id);
void Unk_3ed2b0(void* self, u64 id, void* arg);
void* Unk_3edcf0(void* self, u64 id);
void Unk_3edd30(void* self, u64 id);
void Unk_3eddd0(void* self, u64 id);

inline u32 Unk_3e4760_Object::Unk_3047c0_(int poolId, void* ptr) {
    return Unk_3047c0(poolId, ptr);
}

// What the messages have after their header.
struct Unk_3e4760_Id {
    u64 field_0;
};
struct Unk_3e4fd0_Arg {
    u64 field_0;
    u32 field_8;
};
struct Unk_3e5460_Arg {
    u64 field_0;
    u8 field_8[0x38];
    void* field_40;  // a name
    bool field_48;  // that is the message's own
};

// 0x71003e4760: the game object that listens
void Unk_3e4760(Unk_3e4760_Id* arg) {
    Unk_3e4760_Object* object = Unk_397bc0(Unk_24bbbd8, arg->field_0);
    if (object != nullptr) {
        Unk_3e59b0(object);
        object->Release();
    }
    Unk_24df1b0->field_f0 = arg->field_0;
    Unk_24df1b0->field_f8 = false;
    Unk_24df1b0->field_d8 = true;
}

// 0x71003e4800: it listens no more
void Unk_3e4800(Unk_3e4760_Id* arg) {
    Unk_3e4760_Object* object = Unk_397bc0(Unk_24bbbd8, arg->field_0);
    if (object != nullptr) {
        if (object->field_40 > 6) {
            Unk_Indexed** item = reinterpret_cast<Unk_Indexed**>(object->field_38 + 0x30);
            if (*item != nullptr)
                Unk_362cc0(item);
        }
        object->Release();
    }
    if (Unk_24df1b0->field_f0 == arg->field_0) {
        Unk_24df1b0->field_f0 = 0xffffffffffffffff;
        Unk_24df1b0->field_f8 = false;
        Unk_24df1b0->field_d8 = true;
    }
}

// 0x71003e4fd0
void Unk_3e4fd0(Unk_3e4fd0_Arg* arg) {
    nn::os::LockMutex(&Unk_24df1b0->field_b8);
    void* found = Unk_3edcf0(Unk_24df1b0->field_18, arg->field_0);
    if (found != nullptr)
        *reinterpret_cast<u32*>(static_cast<u8*>(found) + 0x8c) = arg->field_8;
    Unk_24df1b0->field_d8 = true;
    nn::os::UnlockMutex(&Unk_24df1b0->field_b8);
}

// 0x71003e5030
void Unk_3e5030(void* arg) {
    nn::os::LockMutex(&Unk_24df1b0->field_b8);
    Unk_3eb700(Unk_24df1b0->field_18, arg);
    Unk_24df1b0->field_d8 = true;
    nn::os::UnlockMutex(&Unk_24df1b0->field_b8);
}

// 0x71003e5110
void Unk_3e5110(Unk_3e4760_Id* arg) {
    u64 id = arg->field_0;
    nn::os::LockMutex(&Unk_24df1b0->field_b8);
    Unk_3ec6d0(Unk_24df1b0->field_18, id);
    Unk_24df1b0->field_d8 = true;
    nn::os::UnlockMutex(&Unk_24df1b0->field_b8);
}

// 0x71003e5320
void Unk_3e5320(Unk_3e4760_Id* arg) {
    u64 id = arg->field_0;
    nn::os::LockMutex(&Unk_24df1b0->field_b8);
    Unk_3eddd0(Unk_24df1b0->field_18, id);
    Unk_24df1b0->field_d8 = true;
    nn::os::UnlockMutex(&Unk_24df1b0->field_b8);
}

// 0x71003e5460
void Unk_3e5460(Unk_3e5460_Arg* arg) {
    nn::os::LockMutex(&Unk_24df1b0->field_b8);
    Unk_3ed2b0(Unk_24df1b0->field_18, arg->field_0, arg->field_8);
    Unk_24df1b0->field_d8 = true;
    nn::os::UnlockMutex(&Unk_24df1b0->field_b8);
    if (arg->field_40 != nullptr && arg->field_48) {
        Unk_3047c0(Unk_2385820, arg->field_40);
        arg->field_48 = false;
    }
    arg->field_40 = nullptr;
}

// 0x71003e5530
void Unk_3e5530(Unk_3e4760_Id* arg) {
    u64 id = arg->field_0;
    nn::os::LockMutex(&Unk_24df1b0->field_b8);
    Unk_3edd30(Unk_24df1b0->field_18, id);
    Unk_24df1b0->field_d8 = true;
    nn::os::UnlockMutex(&Unk_24df1b0->field_b8);
}
