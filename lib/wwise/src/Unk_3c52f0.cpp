// Scope: common
// What starts and stops the lower engine (globals at 0x71024df148-0x71024df180:
// two arrays and a list). Written from the executable. Placeholder names.
#include "Unk_24df148.h"
#include "block_pool.h"

// An item of the list at 0x71024df158: its next one is at 0x68.
struct Unk_3c54c0_T {
    u8 _0[0x68];
    Unk_3c54c0_T* next;
};

struct Unk_24bbc30_T {
    u8 _0[0x58];
    void* field_58;
};

struct Unk_24df328_T;

extern Unk_Array<Unk_24df148_Bus*, Unk_Pool2381488> Unk_24df148;
extern Unk_ListPolicy<Unk_3c54c0_T, Unk_ListCount, Unk_ListLast> Unk_24df158;
extern Unk_Array<void*, Unk_Pool2381488> Unk_24df170;
extern Unk_24df328_T* Unk_24df328;
extern Unk_24bbc30_T Unk_24bbc30;

bool Unk_3044e0(void* arg);
u32 Unk_35e990(void* arg);
void Unk_35ef60();
u32 Unk_367e30();
void Unk_367eb0();
void Unk_368870();
u32 Unk_368900();
void Unk_368990();
void Unk_368a60(Unk_3c54c0_T* item, u32 arg1);
void Unk_368ff0();
u32 Unk_37bef0();
void Unk_37c450();
void Unk_3a8030_update();
void Unk_3c5550();
void Unk_34f7b0(Unk_24df148_Mix* self, u32 arg1, f32 arg2);
struct Unk_37af50;
void Unk_37af50_set(Unk_37af50* self);
bool Unk_3c59d0(Unk_24df148_Bus* bus, void* arg1);

// 0x71003c52f0
u32 Unk_3c52f0(void* arg) {
    bool ok = Unk_3044e0(arg);
    if (Unk_24df328 == nullptr || !ok)
        return 2;
    u32 result = Unk_368900();
    if (result != 1)
        return result;
    result = Unk_35e990(Unk_24bbc30.field_58);
    if (result != 1)
        return result;
    result = Unk_367e30();
    if (result != 1)
        return result;
    Unk_3a8030_update();
    return Unk_37bef0();
}

// 0x71003c5360
void Unk_3c5360() {
    Unk_37c450();
    Unk_24df170.Term();
    Unk_367eb0();
    Unk_24df148.Term();
    Unk_24df158.RemoveAll();
    Unk_35ef60();
    Unk_368ff0();
    Unk_368990();
}

// 0x71003c54c0
void Unk_3c54c0() {
    auto it = Unk_24df158.BeginEx();
    while (it != Unk_24df158.End()) {
        Unk_3c54c0_T* item = *it;
        it = Unk_24df158.Erase(it);
        Unk_368a60(item, 0);
    }
    Unk_3c5550();
    Unk_368870();
}

static inline bool Unk_24df148_HasParent(Unk_24df148_Ctx ctx) {
    return ctx.field_0 != nullptr && ctx.field_0->field_80 != nullptr;
}

// 0x71003c5550: destroys the buses, the last one first
void Unk_3c5550() {
    for (s32 i = Unk_24df148.Length() - 1; i >= 0; --i) {
        Unk_24df148_Bus* bus = Unk_24df148.field_0[static_cast<u32>(i)];
        if (bus != nullptr) {
            int pool = Unk_2381488;
            if (bus->field_48 == nullptr &&
                !Unk_24df148_HasParent(bus->field_70)) {
                Unk_37d6b0_T* found = Unk_37d6b0(&bus->field_70);
                if (found != nullptr && (found->field_118 == bus || found->field_118 == nullptr))
                    Unk_37af50_set(reinterpret_cast<Unk_37af50*>(found));
            }
            Unk_3d4310(bus);
            Unk_3047c0(pool, bus);
        }
    }
    Unk_24df148.field_8 = 0;
}

// What the next functions are given.
struct Unk_3c5610_Params {
    u32 field_0;
    u8 _4[0x44];
    f32 field_48;
};

// 0x71003c5610
void Unk_3c5610(u32 id, Unk_3c5610_Params* params) {
    for (auto it = Unk_24df148.Begin(); it != Unk_24df148.End(); ++it) {
        Unk_24df148_Bus* bus = *it;
        if (bus->Id() == id && bus->field_20 != nullptr)
            bus->field_20->vf2(params->field_0, 0, params->field_48);
    }
}

// 0x71003c56b0
void Unk_3c56b0(u32 id) {
    for (auto it = Unk_24df148.Begin(); it != Unk_24df148.End(); ++it) {
        Unk_24df148_Bus* bus = *it;
        if (bus->Id() == id && bus->field_20 != nullptr)
            bus->field_20->vf3(0, 5);
    }
}

// 0x71003c58d0
void Unk_3c58d0(u32 id, u32 arg1, f32 arg2) {
    for (auto it = Unk_24df148.Begin(); it != Unk_24df148.End(); ++it) {
        Unk_24df148_Bus* bus = *it;
        if (bus->Id() == id && bus->field_20 != nullptr)
            Unk_34f7b0(bus->field_20, arg1, arg2);
    }
}

// 0x71003c5960
void Unk_3c5960(void* arg0) {
    for (auto it = Unk_24df148.Begin(); it != Unk_24df148.End(); ++it) {
        Unk_24df148_Bus* bus = *it;
        if (Unk_3c59d0(bus, arg0))
            Unk_3d1930(bus);
    }
}

// 0x71003c5740
void Unk_3c5740(u32 id, bool arg1, u32 arg2) {
    for (auto it = Unk_24df148.Begin(); it != Unk_24df148.End(); ++it) {
        Unk_24df148_Bus* bus = *it;
        if (bus->Id() == id && bus->field_20 != nullptr)
            bus->field_20->vf3(arg1, arg2);
    }
}

struct Unk_3c57e0_Arg {
    u8 _0[0x48];
    void* field_48;
};

// 0x71003c57e0
void Unk_3c57e0(u32 id, u32 arg1, u32 arg2, Unk_3c57e0_Arg* arg3) {
    for (auto it = Unk_24df148.Begin(); it != Unk_24df148.End(); ++it) {
        Unk_24df148_Bus* bus = *it;
        if (bus->Id() == id && (arg3 == nullptr || reinterpret_cast<void*>(bus->field_78) == arg3->field_48))
            Unk_3d2290(bus, arg1, arg2);
    }
}

bool Unk_3c9ae0(void* self, void* arg1, void* arg2);
bool Unk_3c8da0(Unk_24df148_Bus* bus, void* arg1);

// 0x71003c59d0
bool Unk_3c59d0(Unk_24df148_Bus* bus, void* arg1) {
    for (u32 i = 0; i < 4; i++) {
        if (bus->field_c8[i].field_70 != nullptr &&
            Unk_3c9ae0(bus->field_c8[i].field_70, arg1, bus->field_c8[i].field_68))
            return true;
    }
    return Unk_3c8da0(bus, arg1);
}


// 0x71003c5a70
void Unk_3c5a70(u32 id, u32 bit) {
    for (auto it = Unk_24df148.Begin(); it != Unk_24df148.End(); ++it) {
        Unk_24df148_Bus* bus = *it;
        if (bus->Id() == id && bus->field_348 != 2)
            Unk_3d45f0(bus, 1 << bit);
    }
}

// What 0x71003c5f60 finds a bus by.
struct Unk_3c5f60_Key {
    void* field_0;
    u64 field_8;
};
struct Unk_3c5f10_Arg {
    u64 field_0;
    u64 field_8;
    u32 field_10;
};
Unk_24df148_Bus* Unk_3c5f60(Unk_3c5f60_Key* key, void* arg1, u32 arg2);

// 0x71003c5f10
void Unk_3c5f10(void* arg0, Unk_3c5f10_Arg* arg1, void* arg2) {
    Unk_3c5f60_Key key;
    key.field_0 = arg0;
    key.field_8 = arg1->field_0;
    Unk_24df148_Bus* bus = Unk_3c5f60(&key, arg2, arg1->field_10);
    if (bus != nullptr)
        bus->field_354_0 = 1;
}
