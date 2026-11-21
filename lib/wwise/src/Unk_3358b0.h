#pragma once
// Wwise's audio manager: the queue of messages the game's calls post to the
// audio thread, and the two lists of actions waiting to run. Placeholder
// names.
#include <nn/os.h>
#include "Unk_List2Keep.h"
#include "containers.h"

// The audio thread's object (Unk_334a10.cpp): only its stop flag.
struct Unk_334a10_T {
    volatile bool field_0;

    void Unk_334a30();
    u32 Unk_334ac0();
    void Unk_334b70();
    static void Unk_334a40(void* arg);
};
void Unk_334a10(void* self);

// The messages: a ring buffer written by the game's threads.
struct Unk_3358b0_Queue {
    u8* volatile field_0;  // read position
    u8* volatile field_8;  // write position
    u8* volatile field_10;  // buffer
    u8* volatile field_18;  // and its end
    u32 field_20;  // size

    // 1, or 2 when the buffer couldn't be allocated.
    u32 Init(int pool, u32 size) {
        field_10 = static_cast<u8*>(Unk_3045e0(pool, size));
        field_0 = field_10;
        field_8 = field_10;
        field_18 = field_10 + size;
        field_20 = size;
        return field_10 != nullptr ? 1 : 2;
    }

    void Term(int pool) {
        if (field_10 != nullptr) {
            Unk_3047c0(pool, field_10);
            field_10 = nullptr;
        }
    }
};

// What an action plays (a leaf's type, Unk_341b70.cpp).
struct Unk_341ca0;
u32 Unk_341ca0_get(const Unk_341ca0* self);

struct Unk_3358b0_Params {
    u32 field_0;
    u8 _4[0x44];
};

struct Unk_3358b0_Obj {
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();  // release
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11(Unk_3358b0_Params* params);

    u8 _8[0x2c];
    u16 field_34;  // type
};
PKMN_OFFSET_ASSERT(Unk_3358b0_Obj, field_34, 0x34);

// An action waiting in one of the manager's lists.
struct Unk_3358b0_Action {
    virtual void vf0();
    virtual void vf1();  // destructor

    Unk_3358b0_Obj* field_8;
    u8 _10[0x20];
    u32 field_30;
};
PKMN_OFFSET_ASSERT(Unk_3358b0_Action, field_30, 0x30);

struct Unk_3358b0_Pending {
    u64 field_0;
    Unk_3358b0_Action* field_8;
};

// A handler of the messages of one kind.
struct Unk_3358b0_Handler {
    u32 field_0;
    u8 _4[0xc];
    void (*field_10)(void* data, u32 size);
};
PKMN_SIZE_ASSERT(Unk_3358b0_Handler, 0x18);

struct Unk_3358b0_T {
    Unk_3358b0_Queue field_0;
    Unk_List2Keep<Unk_3358b0_Pending> field_28;
    Unk_List2Keep<Unk_3358b0_Pending> field_50;
    u32 field_78;
    s32 field_7c;
    Unk_334a10_T field_80;
    s64 field_88;  // the tick the manager started at
    volatile u32 field_90;
    volatile s32 field_94;
    u32 field_98;
    Unk_Array<Unk_3358b0_Handler> field_a0;
};
PKMN_OFFSET_ASSERT(Unk_3358b0_T, field_28, 0x28);
PKMN_OFFSET_ASSERT(Unk_3358b0_T, field_50, 0x50);
PKMN_OFFSET_ASSERT(Unk_3358b0_T, field_80, 0x80);
PKMN_OFFSET_ASSERT(Unk_3358b0_T, field_a0, 0xa0);
PKMN_SIZE_ASSERT(Unk_3358b0_T, 0xb0);

// The sound engine's settings.
struct Unk_24bbc30_T {
    u8 _0[0x14];
    u32 field_14;  // size of the message queue
    u8 _18[0x2d];
    bool field_45;
    void (*field_48)(bool a1, void* a2);  // told when the flagged nodes' state changes
    void* field_50;
};
PKMN_OFFSET_ASSERT(Unk_24bbc30_T, field_45, 0x45);
extern Unk_24bbc30_T Unk_24bbc30;

void Unk_3358b0(Unk_3358b0_T* self);
u32 Unk_335940(Unk_3358b0_T* self);
void Unk_335a60(Unk_3358b0_T* self);
void Unk_335c40(Unk_3358b0_T* self);
void Unk_335df0(Unk_3358b0_T* self);
void Unk_335f00(Unk_3358b0_T* self);
u32 Unk_336010(Unk_3358b0_T* self, bool a1);
void Unk_336100(Unk_3358b0_T* self, u32 a1, u32 a2);
struct Unk_336510_T;
void Unk_336510(Unk_336510_T* self);
