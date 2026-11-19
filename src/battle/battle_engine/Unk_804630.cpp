// Scope: common
// Functions that raise battle events (src/battle/battle_engine/Unk_7e8a20.h):
// each pushes a frame of variables, sets them from its arguments, calls the
// event and reads the result back. They're members of what holds the event
// system at +0x10 (0x7100804630 to 0x710080d4b0). Placeholder names: rename
// once the functions are known.
#include "battle/battle_engine/Unk_804630.h"
#include "unsorted/Unk_7eef40.h"

// 0x7100806d90
void Unk_806d90(Unk_804630_Flow* self, const Unk_7ee6b0* poke) {
    Unk_7e94d0(self->field_10);
    Unk_7e9610(self->field_10, 2, Unk_7ee6b0_getField7d(poke));
    Unk_7e8f60_call(self->field_10, 0xd1);
    Unk_7e9510(self->field_10);
}

// 0x7100806df0
void Unk_806df0(Unk_804630_Flow* self, u8 pokeId) {
    Unk_7e94d0(self->field_10);
    Unk_7e9610(self->field_10, 2, pokeId);
    Unk_7e8f60_call(self->field_10, 0xac);
    Unk_7e9510(self->field_10);
}

// 0x7100806e40
void Unk_806e40(Unk_804630_Flow* self, u8 pokeId, u32 arg2, const Unk_806e40_Arg* arg3, u32 event) {
    Unk_7e94d0(self->field_10);
    Unk_7e9610(self->field_10, 2, pokeId);
    Unk_7e9610(self->field_10, 0x12, arg2);
    Unk_7e9610(self->field_10, 0x6f, (arg3->field_4 >> 1) & 1);
    Unk_7e9610(self->field_10, 0x70, (arg3->field_4 >> 2) & 1);
    Unk_7e9610(self->field_10, 0x71, (arg3->field_4 >> 3) & 1);
    Unk_7e9610(self->field_10, 0x72, arg3->field_4 & 1);
    Unk_7e8f60_call(self->field_10, event);
    Unk_7e9510(self->field_10);
}

// 0x7100806f10
void Unk_806f10(Unk_804630_Flow* self,
                u32 arg1,
                u32 arg2,
                const Unk_7ee6b0* attacker,
                const Unk_7ee6b0* defender,
                u32* outA,
                u32* outB) {
    *outA = Unk_7810b0(arg1, arg2, outB);
    Unk_7e94d0(self->field_10);
    Unk_7e9610(self->field_10, 3, Unk_7ee6b0_getField7d(attacker));
    Unk_7e9610(self->field_10, 4, Unk_7ee6b0_getField7d(defender));
    Unk_7e95a0(self->field_10, 0x22, *outA);
    Unk_7e95a0(self->field_10, 0x23, *outB);
    Unk_7e95a0(self->field_10, 0x38, 1);
    Unk_7e8f60_call(self->field_10, 0x71);
    *outA = Unk_7e9830(self->field_10, 0x22);
    *outB = Unk_7e9830(self->field_10, 0x23);
    u8 mul = Unk_7e9830(self->field_10, 0x38);
    if (mul >= 2)
        *outB *= mul;
    Unk_7e9510(self->field_10);
    if (*outA == 8)
        *outA = 0;
}

// 0x7100807040
void Unk_807040(Unk_804630_Flow* self, const Unk_7ee6b0* poke, u32 arg2, u32 arg3, u32 arg4) {
    Unk_7e94d0(self->field_10);
    Unk_7e9610(self->field_10, 3, Unk_7ee6b0_getField7d(poke));
    Unk_7e9610(self->field_10, 0x12, arg2);
    Unk_7e9610(self->field_10, 0x22, arg3);
    Unk_7e9610(self->field_10, 0x23, arg4);
    Unk_7e8f60_call(self->field_10, 0x78);
    Unk_7e9510(self->field_10);
}

// 0x71008070e0
void Unk_8070e0(Unk_804630_Flow* self, const Unk_7ee6b0* poke, u32 arg2) {
    Unk_7e94d0(self->field_10);
    Unk_7e9610(self->field_10, 2, Unk_7ee6b0_getField7d(poke));
    Unk_7e9610(self->field_10, 0x1a, arg2);
    Unk_7e8f60_call(self->field_10, 0x74);
    Unk_7e9510(self->field_10);
}

// 0x7100807150
bool Unk_807150(Unk_804630_Flow* self,
                const Unk_7ee6b0* poke,
                u32 arg2,
                u8 arg3,
                u32 arg4,
                u8 arg5,
                u32 arg6) {
    Unk_7e94d0(self->field_10);
    Unk_7e9610(self->field_10, 2, Unk_7ee6b0_getField7d(poke));
    Unk_7e9610(self->field_10, 3, arg3);
    Unk_7e9610(self->field_10, 0x22, arg2);
    Unk_7e9610(self->field_10, 0x23, arg4);
    Unk_7e9610(self->field_10, 0x68, arg5);
    Unk_7e9610(self->field_10, 0x1a, arg6);
    Unk_7e9680(self->field_10, 0x48, 0);
    Unk_7e8f60_call(self->field_10, 0x73);
    bool result = Unk_7e9830(self->field_10, 0x48) == 0;
    Unk_7e9510(self->field_10);
    return result;
}

// 0x7100807250
u32 Unk_807250(Unk_804630_Flow* self,
               const Unk_7ee6b0* poke,
               u32 arg2,
               u32 arg3,
               u32 arg4,
               u32 arg5) {
    Unk_7e94d0(self->field_10);
    Unk_7e9610(self->field_10, 2, Unk_7ee6b0_getField7d(poke));
    Unk_7e9610(self->field_10, 0x22, arg2);
    Unk_7e9680(self->field_10, 0x23, arg5);
    Unk_7e8f60_call(self->field_10, 0x72);
    u32 result = Unk_7e9830(self->field_10, 0x23);
    Unk_7e9510(self->field_10);
    return result;
}

// 0x7100807300
void Unk_807300(Unk_804630_Flow* self, u8 pokeId, const Unk_7ee6b0* poke, u32 arg3, u32 arg4) {
    Unk_7e94d0(self->field_10);
    Unk_7e9610(self->field_10, 3, pokeId);
    Unk_7e9610(self->field_10, 2, Unk_7ee6b0_getField7d(poke));
    Unk_7e9610(self->field_10, 0x22, arg3);
    Unk_7e9610(self->field_10, 0x23, arg4);
    Unk_7e8f60_call(self->field_10, 0x75);
    Unk_7e9510(self->field_10);
}

// 0x71008073a0
bool Unk_8073a0(Unk_804630_Flow* self,
                const Unk_7ee6b0* poke,
                u8 pokeId,
                u32 arg3,
                u32 arg4,
                u8 arg5) {
    Unk_7e94d0(self->field_10);
    Unk_7e9610(self->field_10, 4, Unk_7ee6b0_getField7d(poke));
    Unk_7e9610(self->field_10, 3, pokeId);
    Unk_7e9610(self->field_10, 0x22, arg3);
    Unk_7e9610(self->field_10, 0x23, arg4);
    Unk_7e9610(self->field_10, 0x68, arg5);
    Unk_7e9680(self->field_10, 0x74, 0);
    Unk_7e8f60_call(self->field_10, 0x76);
    bool result = Unk_7e9830(self->field_10, 0x74) != 0;
    Unk_7e9510(self->field_10);
    return result;
}

// 0x7100807490
void Unk_807490(Unk_804630_Flow* self, const Unk_7ee6b0* poke, u8 pokeId, u32 arg3, u32 arg4) {
    Unk_7e94d0(self->field_10);
    Unk_7e9610(self->field_10, 4, Unk_7ee6b0_getField7d(poke));
    Unk_7e9610(self->field_10, 3, pokeId);
    Unk_7e9610(self->field_10, 0x22, arg3);
    Unk_7e9610(self->field_10, 0x23, arg4);
    Unk_7e8f60_call(self->field_10, 0x77);
    Unk_7e9510(self->field_10);
}

// 0x7100807530
void Unk_807530(Unk_804630_Flow* self, const u32* arg1, const Unk_7ee6b0* poke) {
    Unk_7e94d0(self->field_10);
    Unk_7e9610(self->field_10, 3, Unk_7ee6b0_getField7d(poke));
    Unk_7e9610(self->field_10, 0x12, *arg1);
    Unk_7e8f60_call(self->field_10, 0xa9);
    Unk_7e9510(self->field_10);
}

// 0x71008075a0
void Unk_8075a0(Unk_804630_Flow* self) {
    Unk_7e94d0(self->field_10);
    Unk_7e8f60_call(self->field_10, 0xdf);
    Unk_7e9510(self->field_10);
}

// 0x71008075e0
u32 Unk_8075e0(Unk_804630_Flow* self, u32 move, const Unk_7ee6b0* poke) {
    u32 value = Unk_780dd0(move) + 7;
    u8 type = Unk_780d40(move);
    Unk_7e94d0(self->field_10);
    Unk_7e9610(self->field_10, 3, Unk_7ee6b0_getField7d(poke));
    Unk_7e9610(self->field_10, 0x12, move);
    Unk_7e9610(self->field_10, 0x16, type);
    Unk_7e95a0(self->field_10, 0x19, value);
    Unk_7e8f60_call(self->field_10, 0x11);
    u32 result = Unk_7e9830(self->field_10, 0x19);
    Unk_7e9510(self->field_10);
    return result;
}

// 0x7100807810
void Unk_807810(Unk_804630_Flow* self, const Unk_82d7e0_Arg* arg) {
    u32 value = Unk_82d7e0(arg);
    Unk_7e94d0(self->field_10);
    Unk_7e9610(self->field_10, 2, Unk_7ee6b0_getField7d(arg->field_0));
    Unk_7e9610(self->field_10, 0xc, arg->field_8);
    Unk_7e9610(self->field_10, 0x12, value);
    Unk_7e8f60_call(self->field_10, 1);
    Unk_7e9510(self->field_10);
}

// 0x71008078a0
void Unk_8078a0(Unk_804630_Flow* self, const Unk_7ee6b0* poke, u32 arg2) {
    Unk_7e94d0(self->field_10);
    Unk_7e9610(self->field_10, 2, Unk_7ee6b0_getField7d(poke));
    Unk_7e9610(self->field_10, 0xc, arg2);
    Unk_7e8f60_call(self->field_10, 2);
    Unk_7e9510(self->field_10);
}

// 0x7100807910
void Unk_807910(Unk_804630_Flow* self, const Unk_82d7e0_Arg* arg) {
    Unk_7e94d0(self->field_10);
    Unk_7e9610(self->field_10, 2, Unk_7ee6b0_getField7d(arg->field_0));
    Unk_7e9610(self->field_10, 0x12, Unk_82d7e0(arg));
    Unk_7e8f60_call(self->field_10, 0xdd);
    Unk_7e9510(self->field_10);
}

// 0x7100807990
bool Unk_807990(Unk_804630_Flow* self, const Unk_7ee6b0* poke) {
    Unk_7e94d0(self->field_10);
    Unk_7e9610(self->field_10, 2, Unk_7ee6b0_getField7d(poke));
    Unk_7e9680(self->field_10, 0x48, 0);
    Unk_7e8f60_call(self->field_10, 0xe);
    bool result = Unk_7e9830(self->field_10, 0x48) != 0;
    Unk_7e9510(self->field_10);
    return result;
}

// 0x7100807a20
void Unk_807a20(Unk_804630_Flow* self, const Unk_7ee6b0* poke) {
    Unk_7e94d0(self->field_10);
    Unk_7e95a0(self->field_10, 2, Unk_7ee6b0_getField7d(poke));
    Unk_7e8f60_call(self->field_10, 0xc8);
    Unk_7e9510(self->field_10);
}

// 0x7100807a80
bool Unk_807a80(Unk_804630_Flow* self, const Unk_7ee6b0* poke) {
    Unk_7e94d0(self->field_10);
    Unk_7e9610(self->field_10, 2, Unk_7ee6b0_getField7d(poke));
    Unk_7e9680(self->field_10, 0x48, 0);
    if (Unk_7ef4c0(poke, 0x16) || Unk_7ef4c0(poke, 8))
        Unk_7e97b0(self->field_10, 0x48, 1);
    Unk_7e8f60_call(self->field_10, 0xc);
    bool result = Unk_7e9830(self->field_10, 0x48) != 0;
    Unk_7e9510(self->field_10);
    return result;
}

// 0x7100807b40
bool Unk_807b40(Unk_804630_Flow* self, const Unk_7ee6b0* poke) {
    Unk_7e94d0(self->field_10);
    Unk_7e95a0(self->field_10, 2, Unk_7ee6b0_getField7d(poke));
    Unk_7e9680(self->field_10, 0x59, 0);
    Unk_7e8f60_call(self->field_10, 0xd);
    bool result = Unk_7e9830(self->field_10, 0x59) != 0;
    Unk_7e9510(self->field_10);
    return result;
}

// 0x7100807bd0
void Unk_807bd0(Unk_804630_Flow* self, const Unk_7ee6b0* poke, u32 event) {
    Unk_7e94d0(self->field_10);
    Unk_7e9610(self->field_10, 2, Unk_7ee6b0_getField7d(poke));
    Unk_7e8f60_call(self->field_10, event);
    Unk_7e9510(self->field_10);
}

// 0x7100807c30
void Unk_807c30(Unk_804630_Flow* self, const Unk_7ee6b0* poke, u32 event) {
    Unk_7e94d0(self->field_10);
    Unk_7e9610(self->field_10, 2, Unk_7ee6b0_getField7d(poke));
    Unk_7e9050_call(self->field_10, event);
    Unk_7e9510(self->field_10);
}

// 0x7100807c90
void Unk_807c90(Unk_804630_Flow* self) {
    Unk_7e94d0(self->field_10);
    Unk_7e8f60_call(self->field_10, 0x6f);
    Unk_7e9510(self->field_10);
}

// 0x7100807cd0
void Unk_807cd0(Unk_804630_Flow* self) {
    Unk_7e94d0(self->field_10);
    Unk_7e8f60_call(self->field_10, 0x70);
    Unk_7e9510(self->field_10);
}

// 0x7100807d10
void Unk_807d10(Unk_804630_Flow* self, const Unk_7ee6b0* poke) {
    Unk_7e94d0(self->field_10);
    Unk_7e9610(self->field_10, 2, Unk_7ee6b0_getField7d(poke));
    Unk_7e8f60_call(self->field_10, 0x68);
    Unk_7e9510(self->field_10);
}

// 0x7100807d70
void Unk_807d70(Unk_804630_Flow* self, const Unk_7ee6b0* poke, u32 arg2, u32 arg3) {
    Unk_7e94d0(self->field_10);
    Unk_7e9610(self->field_10, 2, Unk_7ee6b0_getField7d(poke));
    Unk_7e9610(self->field_10, 0x14, arg2);
    Unk_7e9610(self->field_10, 0x12, arg3);
    Unk_7e8f60_call(self->field_10, 0xdc);
    Unk_7e9510(self->field_10);
}

// 0x7100807e00
void Unk_807e00(Unk_804630_Flow* self, const Unk_7ee6b0* poke, Unk_807e00_Move* move) {
    Unk_7e94d0(self->field_10);
    Unk_7e9610(self->field_10, 3, Unk_7ee6b0_getField7d(poke));
    Unk_7e9610(self->field_10, 0x12, move->field_0);
    Unk_7e9680(self->field_10, 0x16, move->field_e);
    Unk_7e8f60_call(self->field_10, 0xc6);
    move->field_e = Unk_7e9830(self->field_10, 0x16);
    Unk_7e9510(self->field_10);
}

// 0x7100807ea0
void Unk_807ea0(Unk_804630_Flow* self, const Unk_7ee6b0* poke, const u32* arg2, const u32* arg3) {
    Unk_7e94d0(self->field_10);
    Unk_7e9610(self->field_10, 3, Unk_7ee6b0_getField7d(poke));
    Unk_7e9610(self->field_10, 0x12, *arg3);
    Unk_7e9610(self->field_10, 0x14, *arg2);
    Unk_7e8f60_call(self->field_10, 0x24);
    Unk_7e9510(self->field_10);
}

// 0x7100807f30
void Unk_807f30(Unk_804630_Flow* self,
                const Unk_7ee6b0* poke,
                const Unk_807e00_Move* move,
                u32 event) {
    Unk_7e94d0(self->field_10);
    Unk_7e9610(self->field_10, 3, Unk_7ee6b0_getField7d(poke));
    Unk_7e9610(self->field_10, 0x12, move->field_0);
    Unk_7e9610(self->field_10, 0x16, move->field_e);
    Unk_7e8f60_call(self->field_10, event);
    Unk_7e9510(self->field_10);
}

// 0x7100807fc0
void Unk_807fc0(Unk_804630_Flow* self, const Unk_7ee6b0* poke, u8* arg2, bool* arg3, bool* arg4) {
    Unk_7e94d0(self->field_10);
    Unk_7e9610(self->field_10, 3, Unk_7ee6b0_getField7d(poke));
    Unk_7e9680(self->field_10, 0xd, *arg2);
    Unk_7e9680(self->field_10, 0x59, 0);
    Unk_7e95a0(self->field_10, 0x78, 0);
    Unk_7e8f60_call(self->field_10, 6);
    *arg3 = Unk_7e9830(self->field_10, 0x59) != 0;
    *arg4 = Unk_7e9830(self->field_10, 0x78) != 0;
    *arg2 = Unk_7e9830(self->field_10, 0xd);
    Unk_7e9510(self->field_10);
}

// 0x71008080b0
void Unk_8080b0(Unk_804630_Flow* self, const Unk_7ee6b0* poke) {
    Unk_7e94d0(self->field_10);
    Unk_7e9610(self->field_10, 3, Unk_7ee6b0_getField7d(poke));
    Unk_7e8f60_call(self->field_10, 7);
    Unk_7e9510(self->field_10);
}

// 0x7100808110
void Unk_808110(Unk_804630_Flow* self, const Unk_7ee6b0* poke, u32 arg2) {
    Unk_7e94d0(self->field_10);
    Unk_7e9610(self->field_10, 3, Unk_7ee6b0_getField7d(poke));
    Unk_7e9610(self->field_10, 0x12, arg2);
    Unk_7e8f60_call(self->field_10, 3);
    Unk_7e9510(self->field_10);
}

// 0x7100808180
void Unk_808180(Unk_804630_Flow* self,
                const Unk_7ee6b0* poke,
                u32 arg2,
                bool arg3,
                const Unk_806e40_Arg* arg4) {
    Unk_7e94d0(self->field_10);
    Unk_7e9610(self->field_10, 2, Unk_7ee6b0_getField7d(poke));
    Unk_7e9610(self->field_10, 0x12, arg2);
    Unk_7e9610(self->field_10, 0x59, arg3);
    Unk_7e9610(self->field_10, 0x71, (arg4->field_4 >> 3) & 1);
    Unk_7e8f60_call(self->field_10, 4);
    Unk_7e9510(self->field_10);
}

// 0x7100808230
void Unk_808230(Unk_804630_Flow* self, const Unk_7ee6b0* pokeA, const Unk_7ee6b0* pokeB, u32 arg3) {
    Unk_7e94d0(self->field_10);
    Unk_7e9610(self->field_10, 2, Unk_7ee6b0_getField7d(pokeA));
    Unk_7e9610(self->field_10, 3, Unk_7ee6b0_getField7d(pokeB));
    Unk_7e9610(self->field_10, 0x12, arg3);
    Unk_7e8f60_call(self->field_10, 8);
    Unk_7e9510(self->field_10);
}

// 0x71008082d0
void Unk_8082d0(Unk_804630_Flow* self, const Unk_7ee6b0* pokeA, const Unk_7ee6b0* pokeB, u32 arg3) {
    Unk_7e94d0(self->field_10);
    Unk_7e9610(self->field_10, 2, Unk_7ee6b0_getField7d(pokeA));
    Unk_7e9610(self->field_10, 3, Unk_7ee6b0_getField7d(pokeB));
    Unk_7e9610(self->field_10, 0x12, arg3);
    Unk_7e9680(self->field_10, 0x59, 0);
    Unk_7e8f60_call(self->field_10, 9);
    Unk_7e9510(self->field_10);
}

// 0x7100808380
bool Unk_808380(Unk_804630_Flow* self,
                const Unk_7ee6b0* poke,
                u32 move,
                const Unk_813270* targets,
                u8* outA,
                u8* outB) {
    u32 count = Unk_813270_getField4c(targets);
    Unk_7e94d0(self->field_10);
    Unk_7e9610(self->field_10, 0x12, move);
    Unk_7e9610(self->field_10, 3, Unk_7ee6b0_getField7d(poke));
    Unk_7e9610(self->field_10, 5, count);
    for (u32 i = 0; i < count; i++) {
        const Unk_7ee6b0* target = Unk_813110(targets, i);
        u16 label = 6 + i;
        Unk_7e9610(self->field_10, label, Unk_7ee6b0_getField7d(target));
    }
    Unk_7e9680(self->field_10, 2, 0x1f);
    Unk_7e95a0(self->field_10, 4, 0x1f);
    Unk_7e8f60_call(self->field_10, 0x1c);
    *outA = Unk_7e9830(self->field_10, 2);
    *outB = Unk_7e9830(self->field_10, 4);
    Unk_7e9510(self->field_10);
    return *outA != 0x1f;
}

// 0x71008084c0
bool Unk_8084c0(Unk_804630_Flow* self, const Unk_7ee6b0* poke, const u32* move) {
    Unk_7e94d0(self->field_10);
    Unk_7e95a0(self->field_10, 3, Unk_7ee6b0_getField7d(poke));
    Unk_7e95a0(self->field_10, 0x12, *move);
    Unk_7e9680(self->field_10, 0x59, 0);
    Unk_7e8f60_call(self->field_10, 0x4c);
    bool result = Unk_7e9830(self->field_10, 0x59) != 0;
    Unk_7e9510(self->field_10);
    return result;
}

// 0x7100808560
bool Unk_808560(Unk_804630_Flow* self, const Unk_807e00_Move* move, const Unk_7ee6b0* poke) {
    Unk_7e94d0(self->field_10);
    Unk_7e95a0(self->field_10, 3, Unk_7ee6b0_getField7d(poke));
    Unk_7e95a0(self->field_10, 0x12, move->field_0);
    Unk_7e95a0(self->field_10, 0x16, move->field_e);
    Unk_7e9680(self->field_10, 0x59, 0);
    Unk_7e8f60_call(self->field_10, 0x4d);
    bool result = Unk_7e9830(self->field_10, 0x59) != 0;
    Unk_7e9510(self->field_10);
    return result;
}

// 0x7100808610
void Unk_808610(Unk_804630_Flow* self,
                const u32* move,
                const Unk_7ee6b0* poke,
                const Unk_813270* targets) {
    Unk_7e94d0(self->field_10);
    u8 count = Unk_813270_getField4c(targets);
    Unk_7e9610(self->field_10, 3, Unk_7ee6b0_getField7d(poke));
    Unk_7e9610(self->field_10, 0x12, *move);
    Unk_7e9610(self->field_10, 5, count);
    for (u8 i = 0; i < count; i++) {
        const Unk_7ee6b0* target = Unk_813110(targets, i);
        u16 label = 6 + i;
        Unk_7e9610(self->field_10, label, Unk_7ee6b0_getField7d(target));
    }
    Unk_7e8f60_call(self->field_10, 0x32);
    Unk_7e9510(self->field_10);
}

// 0x71008086f0
void Unk_8086f0(Unk_804630_Flow* self,
                const u32* move,
                const Unk_7ee6b0* poke,
                const Unk_813270* targets) {
    Unk_7e94d0(self->field_10);
    u8 count = Unk_813270_getField4c(targets);
    Unk_7e9610(self->field_10, 3, Unk_7ee6b0_getField7d(poke));
    Unk_7e9610(self->field_10, 0x12, *move);
    Unk_7e9610(self->field_10, 5, count);
    for (u8 i = 0; i < count; i++) {
        const Unk_7ee6b0* target = Unk_813110(targets, i);
        u16 label = 6 + i;
        Unk_7e9610(self->field_10, label, Unk_7ee6b0_getField7d(target));
    }
    Unk_7e8f60_call(self->field_10, 0x34);
    Unk_7e9510(self->field_10);
}

// 0x71008087d0
void Unk_8087d0(Unk_804630_Flow* self,
                const Unk_7ee6b0* attacker,
                const Unk_7ee6b0* defender,
                const Unk_8087d0_Arg* arg3) {
    Unk_7e94d0(self->field_10);
    Unk_7e9610(self->field_10, 3, Unk_7ee6b0_getField7d(attacker));
    Unk_7e9610(self->field_10, 4, Unk_7ee6b0_getField7d(defender));
    Unk_7e9610(self->field_10, 0x12, arg3->field_0);
    Unk_7e9610(self->field_10, 0x63, arg3->field_14);
    Unk_7e8f60_call(self->field_10, 0xc9);
    Unk_7e9510(self->field_10);
}

// 0x7100808df0
bool Unk_808df0(Unk_804630_Flow* self,
                const Unk_7ee6b0* attacker,
                const Unk_7ee6b0* defender,
                u32 move) {
    if (Unk_780e30(move))
        return true;
    Unk_7e94d0(self->field_10);
    Unk_7e9610(self->field_10, 3, Unk_7ee6b0_getField7d(attacker));
    Unk_7e9610(self->field_10, 4, Unk_7ee6b0_getField7d(defender));
    Unk_7e9680(self->field_10, 0x59, 0);
    Unk_7e8f60_call(self->field_10, 0x3e);
    bool result = Unk_7e9830(self->field_10, 0x59) != 0;
    Unk_7e9510(self->field_10);
    return result;
}

// 0x7100808eb0
void Unk_808eb0(Unk_804630_Flow* self, const Unk_7ee6b0* poke, bool arg2) {
    Unk_7e94d0(self->field_10);
    Unk_7e9610(self->field_10, 2, Unk_7ee6b0_getField7d(poke));
    Unk_7e9610(self->field_10, 0x54, arg2);
    Unk_7e8f60_call(self->field_10, 0x3b);
    Unk_7e9510(self->field_10);
}

// 0x7100808f20
void Unk_808f20(Unk_804630_Flow* self, const Unk_7ee6b0* poke, const Unk_7ee6b0*, const u32* move) {
    Unk_7e94d0(self->field_10);
    Unk_7e9610(self->field_10, 3, Unk_7ee6b0_getField7d(poke));
    Unk_7e9610(self->field_10, 0x12, *move);
    Unk_7e8f60_call(self->field_10, 0xce);
    Unk_7e9510(self->field_10);
}

// 0x7100808f90
bool Unk_808f90(Unk_804630_Flow* self, const Unk_7ee6b0* poke, u32 move, u8 arg3) {
    Unk_7e94d0(self->field_10);
    Unk_7e9610(self->field_10, 2, Unk_7ee6b0_getField7d(poke));
    Unk_7e9610(self->field_10, 0x25, arg3);
    Unk_7e9610(self->field_10, 0x12, move);
    Unk_7e9680(self->field_10, 0x48, 0);
    Unk_7e8f60_call(self->field_10, 0x1f);
    bool result = Unk_7e9830(self->field_10, 0x48) != 0;
    Unk_7e9510(self->field_10);
    return result;
}

// 0x7100809050
u32 Unk_809050(Unk_804630_Flow* self,
               const Unk_7ee6b0* poke,
               u32 move,
               u32 event,
               const Unk_807e00_Move* param,
               const Unk_813270* targets) {
    u32 b = 0;
    u32 a = 0;
    if (param != nullptr) {
        a = param->field_1c;
        b = param->field_10;
    }
    u8 count = targets != nullptr ? Unk_813270_getField4c(targets) : 0;
    Unk_7e94d0(self->field_10);
    Unk_7e9610(self->field_10, 0x12, move);
    Unk_7e9610(self->field_10, 2, Unk_7ee6b0_getField7d(poke));
    Unk_7e9610(self->field_10, 0x19, a);
    Unk_7e9610(self->field_10, 0x1b, b);
    Unk_7e9680(self->field_10, 0x25, 0);
    Unk_7e9610(self->field_10, 5, count);
    for (u8 i = 0; i < count; i++) {
        const Unk_7ee6b0* target = Unk_813110(targets, i);
        u16 label = 6 + i;
        Unk_7e9610(self->field_10, label, Unk_7ee6b0_getField7d(target));
    }
    if (param != nullptr)
        Unk_7e9610(self->field_10, 0x16, param->field_e);
    Unk_7e8f60_call(self->field_10, event);
    u32 result = Unk_7e9830(self->field_10, 0x25);
    Unk_7e9510(self->field_10);
    return result;
}

// 0x71008091d0
bool Unk_8091d0(Unk_804630_Flow* self, const Unk_7ee6b0* poke, u32 move) {
    Unk_7e94d0(self->field_10);
    Unk_7e9610(self->field_10, 3, Unk_7ee6b0_getField7d(poke));
    Unk_7e9610(self->field_10, 0x12, move);
    Unk_7e9680(self->field_10, 0x48, 0);
    Unk_7e8f60_call(self->field_10, 0xda);
    bool result = Unk_7e9830(self->field_10, 0x48) != 0;
    Unk_7e9510(self->field_10);
    return result;
}

// 0x7100809270
u32 Unk_809270(Unk_804630_Flow* self,
               const Unk_7ee6b0* poke,
               u8 arg2,
               u32 move,
               const Unk_813270* targets) {
    Unk_7e94d0(self->field_10);
    Unk_7e9610(self->field_10, 5, Unk_813270_getField4c(targets));
    for (u32 i = 0;; i++) {
        const Unk_7ee6b0* target = Unk_813110(targets, i);
        if (target == nullptr)
            break;
        u16 label = 6 + i;
        Unk_7e9610(self->field_10, label, Unk_7ee6b0_getField7d(target));
    }
    Unk_7e9610(self->field_10, 3, Unk_7ee6b0_getField7d(poke));
    Unk_7e9610(self->field_10, 0x12, move);
    Unk_7e9610(self->field_10, 0x18, arg2);
    Unk_7e95a0(self->field_10, 0x23, 1);
    Unk_7e8f60_call(self->field_10, 0x63);
    u32 result = Unk_7e9830(self->field_10, 0x23);
    Unk_7e9510(self->field_10);
    return result;
}

// 0x71008093a0
bool Unk_8093a0(Unk_804630_Flow* self, const Unk_7ee6b0* poke, const u32* move) {
    Unk_7e94d0(self->field_10);
    Unk_7e9610(self->field_10, 3, Unk_7ee6b0_getField7d(poke));
    Unk_7e9610(self->field_10, 0x12, *move);
    Unk_7e9680(self->field_10, 0x59, 0);
    Unk_7e8f60_call(self->field_10, 0xcc);
    bool result = Unk_7e9830(self->field_10, 0x59) != 0;
    Unk_7e9510(self->field_10);
    return result;
}

// 0x7100809440
void Unk_809440(Unk_804630_Flow* self,
                const Unk_7ee6b0* attacker,
                const Unk_7ee6b0* defender,
                const Unk_807e00_Move* move) {
    Unk_7e94d0(self->field_10);
    Unk_7e9610(self->field_10, 3, Unk_7ee6b0_getField7d(attacker));
    Unk_7e9610(self->field_10, 4, Unk_7ee6b0_getField7d(defender));
    Unk_7e9610(self->field_10, 0x12, move->field_0);
    Unk_7e9610(self->field_10, 0x16, move->field_e);
    Unk_7e8f60_call(self->field_10, 0x57);
    Unk_7e9510(self->field_10);
}

// 0x7100809650
void Unk_809650(Unk_804630_Flow* self, const Unk_7ee6b0* poke) {
    Unk_7e94d0(self->field_10);
    Unk_7e9610(self->field_10, 2, Unk_7ee6b0_getField7d(poke));
    Unk_7e8f60_call(self->field_10, 0x90);
    Unk_7e9510(self->field_10);
}

// 0x71008096b0
void Unk_8096b0(Unk_804630_Flow* self,
                const Unk_7ee6b0* poke,
                const Unk_807e00_Move* move,
                u32 arg3) {
    Unk_7e94d0(self->field_10);
    Unk_7e9610(self->field_10, 3, Unk_7ee6b0_getField7d(poke));
    Unk_7e9610(self->field_10, 0x12, move->field_0);
    Unk_7e9610(self->field_10, 0x16, move->field_e);
    Unk_7e9610(self->field_10, 0x35, arg3);
    Unk_7e8f60_call(self->field_10, 0x62);
    Unk_7e9510(self->field_10);
}

// 0x7100809750
void Unk_809750(Unk_804630_Flow* self, const Unk_7ee6b0* poke, u8 arg2) {
    Unk_7e94d0(self->field_10);
    Unk_7e9610(self->field_10, 2, Unk_7ee6b0_getField7d(poke));
    Unk_7e9610(self->field_10, 0x31, arg2);
    Unk_7e8f60_call(self->field_10, 0xb4);
    Unk_7e9510(self->field_10);
}

// 0x71008097c0
void Unk_8097c0(Unk_804630_Flow* self,
                const Unk_7ee6b0* poke,
                const Unk_807e00_Move* move,
                const Unk_813270* targets) {
    u32 count = Unk_813270_getField4c(targets);
    Unk_7e94d0(self->field_10);
    Unk_7e9610(self->field_10, 3, Unk_7ee6b0_getField7d(poke));
    Unk_7e9610(self->field_10, 0x12, move->field_0);
    Unk_7e9610(self->field_10, 0x16, move->field_e);
    Unk_7e9610(self->field_10, 5, count);
    for (u32 i = 0; i < count; i++) {
        const Unk_7ee6b0* target = Unk_813110(targets, i);
        u16 label = 6 + i;
        Unk_7e9610(self->field_10, label, Unk_7ee6b0_getField7d(target));
    }
    Unk_7e8f60_call(self->field_10, 0xa0);
    Unk_7e9510(self->field_10);
}

// 0x71008098b0
void Unk_8098b0(Unk_804630_Flow* self,
                const Unk_7ee6b0* poke,
                const Unk_813270* targets,
                const Unk_806e40_Arg* arg3,
                const Unk_807e00_Move* move,
                bool arg5,
                bool arg6,
                u32 event) {
    u32 count = Unk_813270_getField4c(targets);
    Unk_7e94d0(self->field_10);
    Unk_7e9610(self->field_10, 3, Unk_7ee6b0_getField7d(poke));
    Unk_7e9610(self->field_10, 0x54, arg5);
    Unk_7e9610(self->field_10, 0x12, move->field_0);
    Unk_7e9610(self->field_10, 0x16, move->field_e);
    Unk_7e9610(self->field_10, 0x1b, move->field_10);
    Unk_7e9610(self->field_10, 0x63, move->field_14);
    Unk_7e9610(self->field_10, 0x6e, arg3->field_4 & 1);
    if (count != 0) {
        u32 total = 0;
        u32 hits = 0;
        for (u32 i = 0; i < count; i++) {
            const Unk_7ee6b0* target = Unk_813110(targets, i);
            u32 value;
            bool hit =
                arg6 ? Unk_8131d0(targets, target, &value) : Unk_813170(targets, target, &value);
            if (hit) {
                u16 label = 6 + hits;
                total += value;
                Unk_7e9610(self->field_10, label, Unk_7ee6b0_getField7d(target));
                hits++;
            }
        }
        if (hits != 0) {
            Unk_7e9610(self->field_10, 5, hits);
            Unk_7e9680(self->field_10, 0x4e, 0);
            Unk_7e9680(self->field_10, 0x4f, 0);
            Unk_7e9610(self->field_10, 0x35, total);
            Unk_7e8f60_call(self->field_10, 0xa1);
            if (Unk_7e9830(self->field_10, 0x4f) == 0)
                Unk_7e8f60_call(self->field_10, event);
        }
    }
    Unk_7e9510(self->field_10);
}

// 0x7100809b00
void Unk_809b00(Unk_804630_Flow* self,
                const Unk_7ee6b0* poke,
                const Unk_7ee6b0*,
                const u32* move,
                bool arg4) {
    Unk_7e94d0(self->field_10);
    Unk_7e9610(self->field_10, 3, Unk_7ee6b0_getField7d(poke));
    Unk_7e9610(self->field_10, 0x54, arg4);
    Unk_7e9610(self->field_10, 0x12, *move);
    Unk_7e8f60_call(self->field_10, 0xa8);
    Unk_7e9510(self->field_10);
}

// 0x7100809b90
void Unk_809b90(Unk_804630_Flow* self, const Unk_7ee6b0* poke, u8 arg2, u8 arg3) {
    Unk_7e94d0(self->field_10);
    Unk_7e9610(self->field_10, 4, Unk_7ee6b0_getField7d(poke));
    Unk_7e9610(self->field_10, 0x69, arg2);
    Unk_7e9610(self->field_10, 0x6a, arg3);
    Unk_7e8f60_call(self->field_10, 0x9f);
    Unk_7e9510(self->field_10);
}

// 0x7100809c20
bool Unk_809c20(Unk_804630_Flow* self, const Unk_7ee6b0* poke, u16 item) {
    Unk_7e94d0(self->field_10);
    Unk_7e9610(self->field_10, 2, Unk_7ee6b0_getField7d(poke));
    Unk_7e9610(self->field_10, 0x30, item);
    Unk_7e9680(self->field_10, 0x48, 0);
    Unk_7e8f60_call(self->field_10, 0xb2);
    bool result = Unk_7e9830(self->field_10, 0x48) != 0;
    Unk_7e9510(self->field_10);
    return result;
}

// 0x7100809cc0
void Unk_809cc0(Unk_804630_Flow* self, const Unk_7ee6b0* poke, u16 item, bool arg3) {
    Unk_7e94d0(self->field_10);
    Unk_7e9610(self->field_10, 2, Unk_7ee6b0_getField7d(poke));
    Unk_7e9610(self->field_10, 0x30, item);
    Unk_7e9610(self->field_10, 0x58, arg3);
    Unk_7e8f60_call(self->field_10, 0xb3);
    Unk_7e9510(self->field_10);
}

// 0x7100809d50
void Unk_809d50(Unk_804630_Flow* self, const Unk_7ee6b0* poke, u8 pokeId) {
    u8 id = Unk_7ee6b0_getField7d(poke);
    Unk_7e94d0(self->field_10);
    Unk_7e9610(self->field_10, 4, id);
    Unk_7e9610(self->field_10, 3, pokeId);
    Unk_7e8f60_call(self->field_10, 0xcf);
    Unk_7e9510(self->field_10);
}

// 0x7100809dc0
u32 Unk_809dc0(Unk_804630_Flow* self,
               u32 move,
               const Unk_7ee6b0* attacker,
               const Unk_7ee6b0* defender,
               u64* out) {
    u32 value = Unk_780f80(move);
    u64 kind = Unk_780fe0(move);
    u32 chance = Unk_780fb0(move);
    u64 data;
    Unk_7f7df0(kind, attacker, &data);
    Unk_7e94d0(self->field_10);
    Unk_7e9610(self->field_10, 4, Unk_7ee6b0_getField7d(defender));
    Unk_7e9610(self->field_10, 3, Unk_7ee6b0_getField7d(attacker));
    Unk_7e9610(self->field_10, 0x12, move);
    Unk_7e98a0(self->field_10, 0x1f, &data);
    Unk_7e95a0(self->field_10, 0x1e, value);
    Unk_7e9680(self->field_10, 0x48, 0);
    Unk_7e95a0(self->field_10, 0x29, chance);
    Unk_7e8f60_call(self->field_10, 0x7d);
    u32 result = Unk_7e9830(self->field_10, 0x1e);
    s32 percent = Unk_7e9830(self->field_10, 0x29);
    u8 fail = Unk_7e9830(self->field_10, 0x48);
    if (result == 0xffff)
        result = 0;
    Unk_7e9510(self->field_10);
    if (result == 0)
        return 0;
    if (percent <= 0 || fail)
        return 0;
    if (Unk_7f7690(100) < static_cast<u8>(percent)) {
        *out = data;
        return result;
    }
    return 0;
}

// 0x7100809f70
void Unk_809f70(Unk_804630_Flow* self,
                void* arg1,
                const Unk_7ee6b0* attacker,
                const Unk_7ee6b0* defender,
                u32 move) {
    Unk_7e94d0(self->field_10);
    Unk_7e9610(self->field_10, 3, Unk_7ee6b0_getField7d(attacker));
    Unk_7e9610(self->field_10, 4, Unk_7ee6b0_getField7d(defender));
    Unk_7e9610(self->field_10, 0x12, move);
    Unk_7e98a0(self->field_10, 0x44, arg1);
    Unk_7e8f60_call(self->field_10, 0xe4);
    Unk_7e9510(self->field_10);
}

// 0x710080a020
void Unk_80a020(Unk_804630_Flow* self,
                u32 arg1,
                const Unk_7ee6b0* attacker,
                const Unk_7ee6b0* defender,
                void* arg4) {
    Unk_7e94d0(self->field_10);
    Unk_7e9610(self->field_10, 3, Unk_7ee6b0_getField7d(attacker));
    Unk_7e9610(self->field_10, 4, Unk_7ee6b0_getField7d(defender));
    Unk_7e98a0(self->field_10, 0x44, arg4);
    Unk_7e9610(self->field_10, 0x1e, arg1);
    Unk_7e8f60_call(self->field_10, 0x7a);
    Unk_7e9510(self->field_10);
}

// 0x710080a0d0
void Unk_80a0d0(Unk_804630_Flow* self,
                const Unk_7ee6b0* attacker,
                const Unk_7ee6b0* defender,
                u32 arg3,
                void* arg4) {
    Unk_7e94d0(self->field_10);
    Unk_7e9610(self->field_10, 3, Unk_7ee6b0_getField7d(attacker));
    Unk_7e9610(self->field_10, 4, Unk_7ee6b0_getField7d(defender));
    Unk_7e9610(self->field_10, 0x1e, arg3);
    Unk_7e98a0(self->field_10, 0x1f, arg4);
    Unk_7e8f60_call(self->field_10, 0x7b);
    Unk_7e9510(self->field_10);
}

// 0x710080a180
bool Unk_80a180(Unk_804630_Flow* self,
                const Unk_7ee6b0* defender,
                const Unk_7ee6b0* attacker,
                u32 arg3,
                u8 arg4) {
    if (attacker == nullptr)
        return false;
    Unk_7e94d0(self->field_10);
    Unk_7e9610(self->field_10, 3, Unk_7ee6b0_getField7d(attacker));
    Unk_7e9610(self->field_10, 4, Unk_7ee6b0_getField7d(defender));
    Unk_7e9610(self->field_10, 0x1e, arg3);
    Unk_7e9610(self->field_10, 0x6b, arg4);
    Unk_7e9680(self->field_10, 0x59, 0);
    Unk_7e8f60_call(self->field_10, 0xd9);
    bool result = Unk_7e9830(self->field_10, 0x59) != 0;
    Unk_7e9510(self->field_10);
    return result;
}

// 0x710080a270
bool Unk_80a270(Unk_804630_Flow* self,
                const Unk_7ee6b0* attacker,
                const Unk_7ee6b0* defender,
                u32 arg3,
                u8 arg4,
                bool* out) {
    Unk_7e94d0(self->field_10);
    Unk_7e9610(self->field_10, 3, attacker != nullptr ? Unk_7ee6b0_getField7d(attacker) : 0x1f);
    Unk_7e9610(self->field_10, 4, Unk_7ee6b0_getField7d(defender));
    Unk_7e9610(self->field_10, 0x1e, arg3);
    Unk_7e9610(self->field_10, 0x6b, arg4);
    Unk_7e9680(self->field_10, 0x48, 0);
    Unk_7e9680(self->field_10, 0x4a, 0);
    Unk_7e8f60_call(self->field_10, 0x7e);
    bool result = Unk_7e9830(self->field_10, 0x48) != 0;
    *out = Unk_7e9830(self->field_10, 0x4a) != 0;
    Unk_7e9510(self->field_10);
    return result;
}

// 0x710080a390
void Unk_80a390(Unk_804630_Flow* self,
                const Unk_7ee6b0* defender,
                const Unk_7ee6b0* attacker,
                u32 arg3,
                u8 arg4,
                u32 arg5) {
    Unk_7e94d0(self->field_10);
    Unk_7e9610(self->field_10, 4, Unk_7ee6b0_getField7d(defender));
    Unk_7e9610(self->field_10, 3, attacker != nullptr ? Unk_7ee6b0_getField7d(attacker) : 0x1f);
    Unk_7e9610(self->field_10, 0x1e, arg3);
    Unk_7e9610(self->field_10, 0x6b, arg4);
    Unk_7e9610(self->field_10, 0x1a, arg5);
    Unk_7e8f60_call(self->field_10, 0x80);
    Unk_7e9510(self->field_10);
}

// 0x710080a470
void Unk_80a470(Unk_804630_Flow* self,
                const Unk_7ee6b0* defender,
                const Unk_7ee6b0* attacker,
                u32 arg3,
                u64 arg4) {
    Unk_7e94d0(self->field_10);
    Unk_7e9610(self->field_10, 4, Unk_7ee6b0_getField7d(defender));
    u8 id = attacker != nullptr ? Unk_7ee6b0_getField7d(attacker) : 0x1f;
    Unk_7e9610(self->field_10, 3, id);
    Unk_7e9610(self->field_10, 0x1e, arg3);
    Unk_7e98a0(self->field_10, 0x1f, &arg4);
    Unk_7e8f60_call(self->field_10, 0x81);
    Unk_7e9510(self->field_10);
}

// 0x710080a530
void Unk_80a530(Unk_804630_Flow* self,
                const Unk_7ee6b0* defender,
                const Unk_7ee6b0* attacker,
                u32 arg3) {
    Unk_7e94d0(self->field_10);
    Unk_7e9610(self->field_10, 4, Unk_7ee6b0_getField7d(defender));
    u8 id = attacker != nullptr ? Unk_7ee6b0_getField7d(attacker) : 0x1f;
    Unk_7e9610(self->field_10, 3, id);
    Unk_7e9610(self->field_10, 0x1e, arg3);
    Unk_7e8f60_call(self->field_10, 0x82);
    Unk_7e9510(self->field_10);
}

// 0x710080a5d0
bool Unk_80a5d0(Unk_804630_Flow* self, const Unk_7ee6b0* poke) {
    Unk_7e94d0(self->field_10);
    Unk_7e9610(self->field_10, 2, Unk_7ee6b0_getField7d(poke));
    Unk_7e9680(self->field_10, 0x73, 1);
    Unk_7e8f60_call(self->field_10, 0xde);
    bool result = Unk_7e9830(self->field_10, 0x73) == 0;
    Unk_7e9510(self->field_10);
    return result;
}

// 0x710080a660
void Unk_80a660(Unk_804630_Flow* self, const Unk_7ee6b0* poke) {
    Unk_7e94d0(self->field_10);
    Unk_7e9610(self->field_10, 2, Unk_7ee6b0_getField7d(poke));
    Unk_7e9050_call(self->field_10, 0x83);
    Unk_7e9510(self->field_10);
}

// 0x710080a6c0
bool Unk_80a6c0(Unk_804630_Flow* self,
                const u32* move,
                const Unk_7ee6b0* attacker,
                const Unk_7ee6b0* defender) {
    u8 value = Unk_781130(*move, 0);
    Unk_7e94d0(self->field_10);
    Unk_7e9610(self->field_10, 3, Unk_7ee6b0_getField7d(attacker));
    Unk_7e9610(self->field_10, 4, Unk_7ee6b0_getField7d(defender));
    Unk_7e9610(self->field_10, 0x12, *move);
    Unk_7e9680(self->field_10, 0x48, 0);
    Unk_7e95a0(self->field_10, 0x29, value);
    Unk_7e8f60_call(self->field_10, 0x66);
    u8 fail = Unk_7e9830(self->field_10, 0x48);
    u8 percent = Unk_7e9830(self->field_10, 0x29);
    Unk_7e9510(self->field_10);
    if (!fail && Unk_7f7690(100) < percent)
        return true;
    return false;
}

// 0x710080a7e0
u32 Unk_80a7e0(Unk_804630_Flow* self, const Unk_7ee6b0* poke) {
    Unk_7e94d0(self->field_10);
    Unk_7e9610(self->field_10, 3, Unk_7ee6b0_getField7d(poke));
    Unk_7e9680(self->field_10, 0x5f, 0);
    Unk_7e8f60_call(self->field_10, 0xcb);
    u32 result = Unk_7e9830(self->field_10, 0x5f);
    Unk_7e9510(self->field_10);
    return result;
}

// 0x710080a870
void Unk_80a870(Unk_804630_Flow* self,
                bool* outA,
                bool* outB,
                const Unk_7ee6b0*,
                const Unk_7ee6b0* poke) {
    *outA = false;
    *outB = false;
    Unk_7e94d0(self->field_10);
    Unk_7e9680(self->field_10, 0x48, *outA);
    Unk_7e95a0(self->field_10, 0x75, *outB);
    Unk_7e9610(self->field_10, 4, Unk_7ee6b0_getField7d(poke));
    Unk_7e8f60_call(self->field_10, 0xad);
    *outA = Unk_7e9830(self->field_10, 0x48) != 0;
    *outB = Unk_7e9830(self->field_10, 0x75) != 0;
    Unk_7e9510(self->field_10);
}

// 0x710080a950
u32 Unk_80a950(Unk_804630_Flow* self, u8 arg1, const Unk_7ee6b0* poke) {
    Unk_7e94d0(self->field_10);
    Unk_7e9610(self->field_10, 0x3e, arg1);
    Unk_7e9610(self->field_10, 3, Unk_7ee6b0_getField7d(poke));
    Unk_7e95a0(self->field_10, 0x27, 0);
    Unk_7e8f60_call(self->field_10, 0x98);
    u32 result = Unk_7e9830(self->field_10, 0x27);
    Unk_7e9510(self->field_10);
    return result;
}

// 0x710080a9f0
void Unk_80a9f0(Unk_804630_Flow* self, u8 pokeId, u8 arg2, void* arg3) {
    Unk_7e94d0(self->field_10);
    Unk_7e9610(self->field_10, 2, pokeId);
    Unk_7e9610(self->field_10, 0x66, arg2);
    Unk_7e95a0(self->field_10, 0x27, 0);
    Unk_7e8f60_call(self->field_10, 0xd2);
    s32 value = Unk_7e9830(self->field_10, 0x27);
    if (value > 0) {
        Unk_7f8ab0(arg3, value);
        Unk_7f8990(arg3, value);
    }
    Unk_7e9510(self->field_10);
}

// 0x710080aaa0
void Unk_80aaa0(Unk_804630_Flow* self, u8 pokeId, u8 arg2) {
    Unk_7e94d0(self->field_10);
    Unk_7e9610(self->field_10, 2, pokeId);
    Unk_7e9610(self->field_10, 0x66, arg2);
    Unk_7e8f60_call(self->field_10, 0xd3);
    Unk_7e9510(self->field_10);
}

// 0x710080ab10
bool Unk_80ab10(Unk_804630_Flow* self, const Unk_7ee6b0* poke, u32 move) {
    Unk_7e94d0(self->field_10);
    Unk_7e95a0(self->field_10, 3, Unk_7ee6b0_getField7d(poke));
    Unk_7e95a0(self->field_10, 0x12, move);
    Unk_7e95a0(self->field_10, 0x78, 0);
    Unk_7e8f60_call(self->field_10, 0xc2);
    bool result = Unk_7e9830(self->field_10, 0x78) != 0;
    Unk_7e9510(self->field_10);
    return result;
}

// 0x710080abb0
void Unk_80abb0(Unk_804630_Flow* self, u8 pokeId, u32 arg2) {
    Unk_7e94d0(self->field_10);
    Unk_7e9610(self->field_10, 2, pokeId);
    Unk_7e9610(self->field_10, 0x67, arg2);
    Unk_7e8f60_call(self->field_10, 0xd4);
    Unk_7e9510(self->field_10);
}

// 0x710080ac20
void Unk_80ac20(Unk_804630_Flow* self,
                const Unk_7ee6b0* attacker,
                const Unk_7ee6b0* defender,
                const Unk_807e00_Move* move,
                u32 arg4,
                u32 arg5,
                bool arg6,
                bool arg7) {
    u8 defenderId = Unk_7ee6b0_getField7d(defender);
    Unk_7e94d0(self->field_10);
    Unk_7e9610(self->field_10, 3, Unk_7ee6b0_getField7d(attacker));
    Unk_7e9610(self->field_10, 4, defenderId);
    Unk_7e9610(self->field_10, 0x14, move->field_4);
    Unk_7e9610(self->field_10, 0x12, move->field_0);
    Unk_7e9610(self->field_10, 0x3d, arg4);
    Unk_7e9610(self->field_10, 0x16, move->field_e);
    Unk_7e9610(self->field_10, 0x1b, move->field_10);
    Unk_7e9610(self->field_10, 0x35, arg5);
    Unk_7e9610(self->field_10, 0x4c, arg6);
    Unk_7e9610(self->field_10, 0x4d, arg7);
    Unk_7e9610(self->field_10, 0x63, move->field_14);
    Unk_7e9680(self->field_10, 0x4e, 0);
    Unk_7e8f60_call(self->field_10, 0x5e);
    Unk_7e8f60_call(self->field_10, 0x5f);
    Unk_7e8f60_call(self->field_10, 0x60);
    Unk_7e8f60_call(self->field_10, 0x61);
    Unk_7e9510(self->field_10);
}

// 0x710080ad90
bool Unk_80ad90(Unk_804630_Flow* self,
                const u32* move,
                const Unk_7ee6b0* poke,
                const Unk_813270* targets,
                bool* out) {
    Unk_7e94d0(self->field_10);
    Unk_7e9610(self->field_10, 3, Unk_7ee6b0_getField7d(poke));
    bool flag = Unk_813280_getField4d(reinterpret_cast<const Unk_813280*>(targets));
    u8 count = Unk_813270_getField4c(targets);
    Unk_7e9610(self->field_10, 5, count);
    Unk_7e9680(self->field_10, 0x59, 1);
    Unk_7e9680(self->field_10, 0x47, 1);
    Unk_7e95a0(self->field_10, 0x78, 0);
    for (u8 i = 0; i < count; i++) {
        const Unk_7ee6b0* target = Unk_813110(targets, i);
        u16 label = 6 + i;
        Unk_7e9610(self->field_10, label, Unk_7ee6b0_getField7d(target));
    }
    Unk_7e9610(self->field_10, 0x12, *move);
    if (flag)
        Unk_7e8f60_call(self->field_10, 0xc4);
    else
        Unk_7e8f60_call(self->field_10, 0xc5);
    *out = Unk_7e9830(self->field_10, 0x59) != 0;
    bool result = Unk_7e9830(self->field_10, 0x78) != 0;
    Unk_7e9510(self->field_10);
    return result;
}

// 0x710080af10
void Unk_80af10(Unk_804630_Flow* self, u8 pokeId, u32 event) {
    Unk_7e94d0(self->field_10);
    Unk_7e9610(self->field_10, 2, pokeId);
    Unk_7e8f60_call(self->field_10, event);
    Unk_7e9510(self->field_10);
}

// 0x710080af70
u32 Unk_80af70(Unk_804630_Flow* self, const Unk_7ee6b0* poke, u32 arg2, u32 arg3) {
    Unk_7e94d0(self->field_10);
    Unk_7e9610(self->field_10, 2, Unk_7ee6b0_getField7d(poke));
    Unk_7e9610(self->field_10, 0x1e, arg2);
    Unk_7e95a0(self->field_10, 0x35, arg3);
    Unk_7e8f60_call(self->field_10, 0x84);
    u32 result = Unk_7e9830(self->field_10, 0x35);
    Unk_7e9510(self->field_10);
    return result;
}

// 0x710080b020
u32 Unk_80b020(Unk_804630_Flow* self, const Unk_7ee6b0* poke, u8 arg2, u32 arg3) {
    Unk_7e94d0(self->field_10);
    Unk_7e9610(self->field_10, 2, Unk_7ee6b0_getField7d(poke));
    Unk_7e9610(self->field_10, 0x3e, arg2);
    Unk_7e9680(self->field_10, 0x48, 0);
    Unk_7e95a0(self->field_10, 0x35, arg3);
    Unk_7e8f60_call(self->field_10, 0x9b);
    u32 result = Unk_7e9830(self->field_10, 0x35);
    u8 fail = Unk_7e9830(self->field_10, 0x48);
    Unk_7e9510(self->field_10);
    return fail ? 0 : result;
}

// 0x710080b0f0
void Unk_80b0f0(Unk_804630_Flow* self, u8 pokeId) {
    Unk_7e94d0(self->field_10);
    Unk_7e95a0(self->field_10, 2, pokeId);
    Unk_7e8f60_call(self->field_10, 0xd5);
    Unk_7e9510(self->field_10);
}

// 0x710080b140
void Unk_80b140(Unk_804630_Flow* self, u8 pokeId) {
    Unk_7e94d0(self->field_10);
    Unk_7e95a0(self->field_10, 2, pokeId);
    Unk_7e8f60_call(self->field_10, 0xd6);
    Unk_7e9510(self->field_10);
}

// 0x710080b190
void Unk_80b190(Unk_804630_Flow* self, const Unk_7ee6b0* poke) {
    Unk_7e94d0(self->field_10);
    Unk_7e95a0(self->field_10, 2, Unk_7ee6b0_getField7d(poke));
    Unk_7e8f60_call(self->field_10, 0xc7);
    Unk_7e9510(self->field_10);
}

// 0x710080b1f0
void Unk_80b1f0(Unk_804630_Flow* self,
                const Unk_807e00_Move* move,
                const Unk_7ee6b0* attacker,
                const Unk_7ee6b0* defender) {
    Unk_7e94d0(self->field_10);
    Unk_7e9610(self->field_10, 3, Unk_7ee6b0_getField7d(attacker));
    Unk_7e9610(self->field_10, 4, Unk_7ee6b0_getField7d(defender));
    Unk_7e9610(self->field_10, 0x63, move->field_14);
    Unk_7e8f60_call(self->field_10, 0x44);
    Unk_7e9510(self->field_10);
}

// 0x710080b290
bool Unk_80b290(Unk_804630_Flow* self,
                const Unk_7ee6b0* poke,
                const Unk_7ee6b0*,
                u8 arg3,
                Unk_80b290_Out* out) {
    Unk_7e94d0(self->field_10);
    Unk_7e9610(self->field_10, 2, Unk_7ee6b0_getField7d(poke));
    Unk_7e9610(self->field_10, 0xe, arg3);
    Unk_7e95a0(self->field_10, 0x12, 0);
    Unk_7e95a0(self->field_10, 0xd, 5);
    Unk_7e9680(self->field_10, 0x48, 0);
    Unk_7e8f60_call(self->field_10, 0x1a);
    out->field_0 = Unk_7e9830(self->field_10, 0x12);
    out->field_4 = Unk_7e9830(self->field_10, 0xd);
    bool result = Unk_7e9830(self->field_10, 0x48) == 0;
    Unk_7e9510(self->field_10);
    return result;
}

// 0x710080b390
u32 Unk_80b390(Unk_804630_Flow* self, const Unk_7ee6b0* poke) {
    u8 value = Unk_7ef300_getField342(reinterpret_cast<const Unk_7ef300*>(poke));
    Unk_7e94d0(self->field_10);
    Unk_7e9610(self->field_10, 2, Unk_7ee6b0_getField7d(poke));
    Unk_7e9680(self->field_10, 0x11, value);
    Unk_7e8f60_call(self->field_10, 0xf);
    u32 result = Unk_7e9830(self->field_10, 0x11);
    Unk_7e9510(self->field_10);
    return result;
}

// 0x710080b430
void Unk_80b430(Unk_804630_Flow* self, const Unk_7ee6b0* poke, u32 move) {
    Unk_7e94d0(self->field_10);
    Unk_7e95a0(self->field_10, 2, Unk_7ee6b0_getField7d(poke));
    Unk_7e95a0(self->field_10, 0x12, move);
    Unk_7e8f60_call(self->field_10, 0x17);
    Unk_7e9510(self->field_10);
}

// 0x710080b4a0
void Unk_80b4a0(Unk_804630_Flow* self, const Unk_7ee6b0* poke, u16* item) {
    u16 value = *item;
    Unk_7e94d0(self->field_10);
    Unk_7e9610(self->field_10, 2, Unk_7ee6b0_getField7d(poke));
    Unk_7e95a0(self->field_10, 0x3a, value);
    Unk_7e95a0(self->field_10, 0x3b, 0);
    Unk_7e95a0(self->field_10, 0x3c, 0);
    Unk_7e8f60_call(self->field_10, 0x15);
    u32 result = Unk_7e9830(self->field_10, 0x3a);
    u32 changed = Unk_7e9830(self->field_10, 0x3b);
    u32 removed = Unk_7e9830(self->field_10, 0x3c);
    changed = removed | changed;
    Unk_7e9510(self->field_10);
    if (changed)
        *item = removed == 0 ? result : 0;
}

// 0x710080b590
void Unk_80b590(Unk_804630_Flow* self, const Unk_7ee6b0* attacker, const Unk_7ee6b0* defender) {
    Unk_7e94d0(self->field_10);
    Unk_7e9610(self->field_10, 3, Unk_7ee6b0_getField7d(attacker));
    Unk_7e9610(self->field_10, 4, Unk_7ee6b0_getField7d(defender));
    Unk_7e8f60_call(self->field_10, 0x16);
    Unk_7e9510(self->field_10);
}

// 0x710080b610
bool Unk_80b610(Unk_804630_Flow* self,
                const Unk_7ee6b0* poke,
                const Unk_7ee6b0*,
                u32 move,
                Unk_803c70* out) {
    Unk_803c70_set(out);
    Unk_7e94d0(self->field_10);
    Unk_7e9610(self->field_10, 2, Unk_7ee6b0_getField7d(poke));
    Unk_7e9610(self->field_10, 0x12, move);
    Unk_7e98a0(self->field_10, 0x44, out);
    Unk_7e9680(self->field_10, 0x59, 0);
    Unk_7e8f60_call(self->field_10, 0x1b);
    bool result = Unk_7e9830(self->field_10, 0x59) != 0;
    Unk_7e9510(self->field_10);
    return result;
}

// 0x710080b6e0
void Unk_80b6e0(Unk_804630_Flow* self, const Unk_7ee6b0* poke, u32 move, u8 arg3) {
    Unk_7e94d0(self->field_10);
    Unk_7e9610(self->field_10, 2, Unk_7ee6b0_getField7d(poke));
    Unk_7e9610(self->field_10, 0x12, move);
    Unk_7e9610(self->field_10, 0x25, arg3);
    Unk_7e8f60_call(self->field_10, 0x23);
    Unk_7e9510(self->field_10);
}

// 0x710080b770
u32 Unk_80b770(Unk_804630_Flow* self,
               const Unk_806e40_Arg* arg1,
               const Unk_7ee6b0* poke,
               const Unk_807e00_Move* move,
               const Unk_813270* targets,
               Unk_812dc0* out) {
    u32 count = Unk_813270_getField4c(targets);
    Unk_7e94d0(self->field_10);
    Unk_7e9610(self->field_10, 3, Unk_7ee6b0_getField7d(poke));
    Unk_7e9610(self->field_10, 2, Unk_7ee6b0_getField7d(poke));
    Unk_7e9610(self->field_10, 0x12, move->field_0);
    Unk_7e9610(self->field_10, 0x16, move->field_e);
    Unk_7e9610(self->field_10, 0x6f, (arg1->field_4 >> 1) & 1);
    Unk_7e9610(self->field_10, 0x71, (arg1->field_4 >> 3) & 1);
    Unk_7e9610(self->field_10, 5, count);
    for (u32 i = 0; i < count; i++) {
        const Unk_7ee6b0* target = Unk_813110(targets, i);
        u16 label = 6 + i;
        Unk_7e9610(self->field_10, label, Unk_7ee6b0_getField7d(target));
    }
    Unk_7e9680(self->field_10, 0x43, 0);
    Unk_7e9680(self->field_10, 0x13, 0);
    Unk_7e8f60_call(self->field_10, 0x26);
    u32 result = Unk_7e9830(self->field_10, 0x43);
    u32 value = Unk_7e9830(self->field_10, 0x13);
    Unk_7e9510(self->field_10);
    if (value != 0)
        Unk_812dc0_setField0(out, value);
    return result;
}

// 0x710080b910
bool Unk_80b910(Unk_804630_Flow* self, const Unk_7ee6b0* poke, const Unk_813270* targets) {
    const Unk_7ee6b0* target = Unk_813110(targets, 0);
    Unk_7e94d0(self->field_10);
    Unk_7e9610(self->field_10, 3, Unk_7ee6b0_getField7d(poke));
    Unk_7e9610(self->field_10, 4, target != nullptr ? Unk_7ee6b0_getField7d(target) : 0x1f);
    Unk_7e9680(self->field_10, 0x48, 0);
    Unk_7e8f60_call(self->field_10, 0xb6);
    bool result = Unk_7e9830(self->field_10, 0x48) != 0;
    Unk_7e9510(self->field_10);
    return result;
}

// 0x710080b9e0
bool Unk_80b9e0(Unk_804630_Flow* self, const Unk_7ee6b0* poke, u32 move) {
    Unk_7e94d0(self->field_10);
    Unk_7e9610(self->field_10, 3, Unk_7ee6b0_getField7d(poke));
    Unk_7e9610(self->field_10, 0x12, move);
    Unk_7e9680(self->field_10, 0x59, 0);
    Unk_7e8f60_call(self->field_10, 0xb7);
    bool result = Unk_7e9830(self->field_10, 0x59) != 0;
    Unk_7e9510(self->field_10);
    return result;
}

// 0x710080ba80
bool Unk_80ba80(Unk_804630_Flow* self,
                const Unk_7ee6b0* poke,
                const Unk_813270* targets,
                void* arg3,
                u8* outTarget,
                bool* outB) {
    u32 count = Unk_813270_getField4c(targets);
    Unk_7e94d0(self->field_10);
    Unk_7e9610(self->field_10, 3, Unk_7ee6b0_getField7d(poke));
    Unk_7e9610(self->field_10, 5, count);
    if (count != 0) {
        for (u32 i = 0; i < count; i++) {
            const Unk_7ee6b0* target = Unk_813110(targets, i);
            u16 label = 6 + i;
            Unk_7e9610(self->field_10, label, Unk_7ee6b0_getField7d(target));
        }
    } else {
        Unk_7e9610(self->field_10, 6, 0x1f);
    }
    Unk_7e9680(self->field_10, 0x48, 0);
    Unk_7e9680(self->field_10, 0x59, 0);
    Unk_7e9680(self->field_10, 0x56, 0);
    Unk_7e98a0(self->field_10, 0x44, arg3);
    Unk_7e8f60_call(self->field_10, 0xb8);
    *outTarget = Unk_7e9830(self->field_10, 0x59) != 0 ? Unk_7e9830(self->field_10, 6) : 0x1f;
    *outB = Unk_7e9830(self->field_10, 0x56) != 0;
    bool result = Unk_7e9830(self->field_10, 0x48) == 0;
    Unk_7e9510(self->field_10);
    return result;
}

// 0x710080bc10
void Unk_80bc10(Unk_804630_Flow* self, const Unk_7ee6b0* poke) {
    Unk_7e94d0(self->field_10);
    Unk_7e9610(self->field_10, 3, Unk_7ee6b0_getField7d(poke));
    Unk_7e8f60_call(self->field_10, 0xb9);
    Unk_7e9510(self->field_10);
}

// 0x710080bc70
void Unk_80bc70(Unk_804630_Flow* self, const Unk_7ee6b0* poke) {
    Unk_7e94d0(self->field_10);
    Unk_7e9610(self->field_10, 3, Unk_7ee6b0_getField7d(poke));
    Unk_7e8f60_call(self->field_10, 0xba);
    Unk_7e9510(self->field_10);
}

// 0x710080bcd0
bool Unk_80bcd0(Unk_804630_Flow* self, const Unk_7ee6b0* poke, const Unk_813270* targets) {
    u32 count = Unk_813270_getField4c(targets);
    Unk_7e94d0(self->field_10);
    Unk_7e9610(self->field_10, 3, Unk_7ee6b0_getField7d(poke));
    Unk_7e9680(self->field_10, 0x48, 0);
    Unk_7e9610(self->field_10, 5, count);
    for (u32 i = 0; i < count; i++) {
        const Unk_7ee6b0* target = Unk_813110(targets, i);
        u16 label = 6 + i;
        Unk_7e9610(self->field_10, label, Unk_7ee6b0_getField7d(target));
    }
    Unk_7e8f60_call(self->field_10, 0xbb);
    u8 fail = Unk_7e9830(self->field_10, 0x48);
    if (!fail)
        Unk_7e8f60_call(self->field_10, 0xbc);
    bool result = !fail;
    Unk_7e9510(self->field_10);
    return result;
}

// 0x710080bf00
bool Unk_80bf00(Unk_804630_Flow* self,
                const Unk_7ee6b0* attacker,
                const Unk_7ee6b0* defender,
                const Unk_807e00_Move* move) {
    Unk_7e94d0(self->field_10);
    Unk_7e9610(self->field_10, 3, Unk_7ee6b0_getField7d(attacker));
    Unk_7e9610(self->field_10, 4, Unk_7ee6b0_getField7d(defender));
    Unk_7e9610(self->field_10, 0x16, move->field_e);
    Unk_7e9680(self->field_10, 0x59, 0);
    Unk_7e8f60_call(self->field_10, 0x3c);
    bool result = Unk_7e9830(self->field_10, 0x59) != 0;
    Unk_7e9510(self->field_10);
    return result;
}

// 0x7100805540
bool Unk_805540(Unk_804630_Flow* self, const Unk_7ee6b0* poke, bool* out) {
    Unk_7e94d0(self->field_10);
    Unk_7e9610(self->field_10, 2, Unk_7ee6b0_getField7d(poke));
    Unk_7e9680(self->field_10, 0x60, 0);
    Unk_7e9680(self->field_10, 0x76, 0);
    Unk_7e8f60_call(self->field_10, 0x8c);
    bool result = Unk_7e9830(self->field_10, 0x60) != 0;
    if (out != nullptr)
        *out = Unk_7e9830(self->field_10, 0x76) != 0;
    Unk_7e9510(self->field_10);
    return result;
}

// 0x710080bfd0
void Unk_80bfd0(Unk_804630_Flow* self, const Unk_7ee6b0* attacker, const Unk_7ee6b0* defender) {
    Unk_7e94d0(self->field_10);
    Unk_7e9610(self->field_10, 3, Unk_7ee6b0_getField7d(attacker));
    Unk_7e9610(self->field_10, 4, Unk_7ee6b0_getField7d(defender));
    Unk_7e8f60_call(self->field_10, 0x3d);
    Unk_7e9510(self->field_10);
}

// 0x710080c050
bool Unk_80c050(Unk_804630_Flow* self, const Unk_7ee6b0* poke, bool* out) {
    bool flag = Unk_805540(self, poke, out);
    Unk_7e94d0(self->field_10);
    Unk_7e9610(self->field_10, 2, Unk_7ee6b0_getField7d(poke));
    Unk_7e9610(self->field_10, 0x60, flag);
    Unk_7e9680(self->field_10, 0x50, 0);
    Unk_7e8f60_call(self->field_10, 0x8d);
    bool result = Unk_7e9830(self->field_10, 0x50) != 0;
    Unk_7e9510(self->field_10);
    return result;
}

// 0x710080c100
bool Unk_80c100(Unk_804630_Flow* self, const Unk_7ee6b0* poke, u8 pokeId, bool* out) {
    bool flag = Unk_805540(self, poke, out);
    Unk_7e94d0(self->field_10);
    Unk_7e95a0(self->field_10, 2, Unk_7ee6b0_getField7d(poke));
    Unk_7e95a0(self->field_10, 3, pokeId);
    Unk_7e95a0(self->field_10, 0x60, flag);
    Unk_7e9680(self->field_10, 0x50, 0);
    Unk_7e9050_call(self->field_10, 0x8e);
    bool result = Unk_7e9830(self->field_10, 0x50) != 0;
    Unk_7e9510(self->field_10);
    return result;
}

// 0x710080c1d0
bool Unk_80c1d0(Unk_804630_Flow* self, const Unk_7ee6b0* poke) {
    Unk_7e94d0(self->field_10);
    Unk_7e9610(self->field_10, 2, Unk_7ee6b0_getField7d(poke));
    Unk_7e9680(self->field_10, 0x75, 0);
    Unk_7e8f60_call(self->field_10, 0x1d);
    bool result = Unk_7e9830(self->field_10, 0x75) != 0;
    Unk_7e9510(self->field_10);
    return result;
}

// 0x710080c260
bool Unk_80c260(Unk_804630_Flow* self, const Unk_7ee6b0* poke, u8 arg2) {
    Unk_7e94d0(self->field_10);
    Unk_7e9610(self->field_10, 2, Unk_7ee6b0_getField7d(poke));
    Unk_7e9610(self->field_10, 0x18, arg2);
    Unk_7e9680(self->field_10, 0x59, 0);
    Unk_7e8f60_call(self->field_10, 0x64);
    bool result = Unk_7e9830(self->field_10, 0x59) != 0;
    Unk_7e9510(self->field_10);
    return result;
}

// 0x710080c4c0
u32 Unk_80c4c0(Unk_804630_Flow* self, u32 move, const Unk_7ee6b0* poke) {
    u32 fixed = Unk_780e90(move);
    Unk_7e94d0(self->field_10);
    Unk_7e9610(self->field_10, 3, Unk_7ee6b0_getField7d(poke));
    Unk_7e9610(self->field_10, 0x28, fixed);
    Unk_7e9680(self->field_10, 0x4c, 0);
    Unk_7e9680(self->field_10, 0x48, 0);
    Unk_7e95a0(self->field_10, 0x29, 0);
    Unk_7e8f60_call(self->field_10, 0x85);
    u32 fail = Unk_7e9830(self->field_10, 0x48);
    u32 twice = Unk_7e9830(self->field_10, 0x4c);
    u32 value = Unk_7e9830(self->field_10, 0x29);
    Unk_7e9510(self->field_10);
    if (fixed != 0 && fail != 0)
        return 0;
    u32 shift = twice != 0 ? 1 : 0;
    u32 result = fixed;
    if (fixed == 0)
        result += value;
    return result << shift;
}

// 0x710080c5e0
bool Unk_80c5e0(Unk_804630_Flow* self, const Unk_7ee6b0* poke, u32 percent) {
    Unk_7e94d0(self->field_10);
    Unk_7e9610(self->field_10, 4, Unk_7ee6b0_getField7d(poke));
    Unk_7e95a0(self->field_10, 0x29, percent);
    Unk_7e9680(self->field_10, 0x48, 0);
    Unk_7e8f60_call(self->field_10, 0x86);
    u32 chance = Unk_7e9830(self->field_10, 0x29);
    u32 fail = Unk_7e9830(self->field_10, 0x48);
    Unk_7e9510(self->field_10);
    if (chance == 0 || fail != 0)
        return false;
    return Unk_7f7690(100) < static_cast<u8>(chance);
}

// 0x710080c6b0
void Unk_80c6b0(Unk_804630_Flow* self, const Unk_7ee6b0* poke) {
    Unk_7e94d0(self->field_10);
    Unk_7e95a0(self->field_10, 2, Unk_7ee6b0_getField7d(poke));
    Unk_7e8f60_call(self->field_10, 0x87);
    Unk_7e9510(self->field_10);
}

// 0x710080c710
u32 Unk_80c710(Unk_804630_Flow* self,
               const Unk_7ee6b0* attacker,
               const Unk_7ee6b0* defender,
               u16 power) {
    u8 defenderId = defender != nullptr ? Unk_7ee6b0_getField7d(defender) : 0x1f;
    Unk_7e94d0(self->field_10);
    Unk_7e9610(self->field_10, 3, Unk_7ee6b0_getField7d(attacker));
    Unk_7e9610(self->field_10, 4, defenderId);
    Unk_7e9720(self->field_10, 0x38, 0x1000, 0x19a, 0x20000);
    Unk_7e95a0(self->field_10, 0x23, power);
    Unk_7e8f60_call(self->field_10, 0xae);
    u16 value = Unk_7e9830(self->field_10, 0x23);
    u32 ratio = Unk_7e9830(self->field_10, 0x38);
    u32 result = value != 0 ? Unk_7f7720(value, ratio) : 0;
    Unk_7e97b0(self->field_10, 0x23, result);
    Unk_7e8f60_call(self->field_10, 0xaf);
    u32 final = Unk_7e9830(self->field_10, 0x23);
    Unk_7e9510(self->field_10);
    return final;
}

// 0x710080c840
void Unk_80c840(Unk_804630_Flow* self, u8 arg1) {
    Unk_7e94d0(self->field_10);
    Unk_7e9610(self->field_10, 0x3e, arg1);
    Unk_7e9680(self->field_10, 0x48, 0);
    Unk_7e8f60_call(self->field_10, 0x99);
    if (Unk_7e9830(self->field_10, 0x48) == 0)
        Unk_7e8f60_call(self->field_10, 0x9a);
    Unk_7e9510(self->field_10);
}

// 0x710080c8d0
u32 Unk_80c8d0(Unk_804630_Flow* self,
               const Unk_7ee6b0* attacker,
               const Unk_7ee6b0* defender,
               u32 move) {
    u32 base = Unk_7811b0(move);
    Unk_7e94d0(self->field_10);
    Unk_7e9610(self->field_10, 3, Unk_7ee6b0_getField7d(attacker));
    Unk_7e9610(self->field_10, 4, Unk_7ee6b0_getField7d(defender));
    Unk_7e9610(self->field_10, 0x12, move);
    Unk_7e95a0(self->field_10, 0x38, 0);
    Unk_7e8f60_call(self->field_10, 0xb1);
    u32 ratio = Unk_7e9830(self->field_10, 0x38);
    Unk_7e9510(self->field_10);
    u32 hp = Unk_7eef50(const_cast<Unk_7ee6b0*>(defender), 0x10);
    u32 result;
    if (ratio != 0)
        result = Unk_7f7700(hp, ratio);
    else
        result = Unk_7f7740(hp, base);
    if (result == 0)
        result = 1;
    else if (result > hp)
        result = hp;
    return result;
}

// 0x710080c9e0
bool Unk_80c9e0(Unk_804630_Flow* self, const Unk_7ee6b0* poke, u16 item) {
    Unk_7e94d0(self->field_10);
    Unk_7e9610(self->field_10, 2, Unk_7ee6b0_getField7d(poke));
    Unk_7e9610(self->field_10, 0x30, item);
    Unk_7e9680(self->field_10, 0x48, 0);
    Unk_7e8f60_call(self->field_10, 0xbe);
    bool result = Unk_7e9830(self->field_10, 0x48) != 0;
    Unk_7e9510(self->field_10);
    return result;
}

// 0x710080ca80
void Unk_80ca80(Unk_804630_Flow* self, const Unk_7ee6b0* poke) {
    Unk_7e94d0(self->field_10);
    Unk_7e9610(self->field_10, 2, Unk_7ee6b0_getField7d(poke));
    Unk_7e8f60_call(self->field_10, 0xbf);
    Unk_7e9510(self->field_10);
}

// 0x710080cae0
void Unk_80cae0(Unk_804630_Flow* self, const Unk_7ee6b0* poke, u16 item) {
    Unk_7e94d0(self->field_10);
    Unk_7e9610(self->field_10, 2, Unk_7ee6b0_getField7d(poke));
    Unk_7e9610(self->field_10, 0x30, item);
    Unk_7e8f60_call(self->field_10, 0xc0);
    Unk_7e9510(self->field_10);
}

// 0x710080cb50
void Unk_80cb50(Unk_804630_Flow* self, const Unk_7ee6b0* poke) {
    Unk_7e94d0(self->field_10);
    Unk_7e9610(self->field_10, 2, Unk_7ee6b0_getField7d(poke));
    Unk_7e8f60_call(self->field_10, 0xc1);
    Unk_7e9510(self->field_10);
}

// 0x710080cbb0
void Unk_80cbb0(Unk_804630_Flow* self, u8 pokeId, u32 arg2, u16 arg3) {
    Unk_7e94d0(self->field_10);
    Unk_7e9610(self->field_10, 2, pokeId);
    Unk_7e9610(self->field_10, 0xf, arg2);
    Unk_7e9610(self->field_10, 0x10, arg3);
    Unk_7e9050_call(self->field_10, 0xab);
    Unk_7e9510(self->field_10);
    Unk_7e94d0(self->field_10);
    Unk_7e9610(self->field_10, 2, pokeId);
    Unk_7e9610(self->field_10, 0xf, arg2);
    Unk_7e9610(self->field_10, 0x10, arg3);
    Unk_7e8f60_call(self->field_10, 0xaa);
    Unk_7e9510(self->field_10);
}

// 0x710080cc80
void Unk_80cc80(Unk_804630_Flow* self, u8 pokeId, u32 arg2, u8 arg3, void* arg4) {
    Unk_7e94d0(self->field_10);
    Unk_7e9610(self->field_10, 2, pokeId);
    Unk_7e9610(self->field_10, 0x5b, arg3);
    Unk_7e9610(self->field_10, 0x5c, arg2);
    Unk_7e98a0(self->field_10, 0x1f, arg4);
    Unk_7e8f60_call(self->field_10, 0xc3);
    Unk_7e9510(self->field_10);
}

// 0x710080cd20
void Unk_80cd20(Unk_804630_Flow* self) {
    Unk_7e94d0(self->field_10);
    Unk_7e8f60_call(self->field_10, 0x94);
    Unk_7e9510(self->field_10);
}

// 0x710080cd60
bool Unk_80cd60(Unk_804630_Flow* self, u8 pokeId, u32 arg2, u8 arg3) {
    Unk_7e94d0(self->field_10);
    Unk_7e9610(self->field_10, 2, pokeId);
    Unk_7e9610(self->field_10, 0x10, arg2);
    Unk_7e9610(self->field_10, 0x6c, arg3);
    Unk_7e9680(self->field_10, 0x48, 0);
    Unk_7e8f60_call(self->field_10, 0xd7);
    bool result = Unk_7e9830(self->field_10, 0x48) == 0;
    Unk_7e9510(self->field_10);
    return result;
}

// 0x710080ce10
void Unk_80ce10(Unk_804630_Flow* self, u8 pokeId, u32 arg2, u8 arg3) {
    Unk_7e94d0(self->field_10);
    Unk_7e9610(self->field_10, 2, pokeId);
    Unk_7e9610(self->field_10, 0x10, arg2);
    Unk_7e9610(self->field_10, 0x6c, arg3);
    Unk_7e8f60_call(self->field_10, 0xd8);
    Unk_7e9510(self->field_10);
}

// 0x710080ce90
u32 Unk_80ce90(Unk_804630_Flow* self, const Unk_7ee6b0* poke, const Unk_807e00_Move* move) {
    Unk_7e94d0(self->field_10);
    Unk_7e9610(self->field_10, 3, Unk_7ee6b0_getField7d(poke));
    Unk_7e9610(self->field_10, 0x16, move->field_e);
    Unk_7e9610(self->field_10, 0x12, move->field_0);
    Unk_7e9680(self->field_10, 4, 0x1f);
    Unk_7e9680(self->field_10, 0x57, 0);
    Unk_7e8f60_call(self->field_10, 0x2d);
    u32 result = Unk_7e9830(self->field_10, 4);
    Unk_7e9510(self->field_10);
    return result;
}

// 0x710080cf50
bool Unk_80cf50(Unk_804630_Flow* self, const Unk_7ee6b0* poke, bool arg2) {
    Unk_7e94d0(self->field_10);
    Unk_7e9610(self->field_10, 2, Unk_7ee6b0_getField7d(poke));
    Unk_7e9680(self->field_10, 0x73, arg2);
    Unk_7e8f60_call(self->field_10, 0x2e);
    bool result = Unk_7e9830(self->field_10, 0x73) != 0;
    Unk_7e9510(self->field_10);
    return result;
}

// 0x710080cfe0
u8 Unk_80cfe0(Unk_804630_Flow* self,
              const Unk_7ee6b0* poke,
              const Unk_807e00_Move* move,
              u8 target,
              u8* out) {
    Unk_7e94d0(self->field_10);
    Unk_7e9610(self->field_10, 3, Unk_7ee6b0_getField7d(poke));
    Unk_7e9610(self->field_10, 0x16, move->field_e);
    Unk_7e9610(self->field_10, 0x12, move->field_0);
    Unk_7e95a0(self->field_10, 0x62, 0);
    Unk_7e95a0(self->field_10, 0x61, 0);
    Unk_7e95a0(self->field_10, 4, target);
    Unk_7e8f60_call(self->field_10, 0x2f);
    u8 result = Unk_7e9830(self->field_10, 4);
    *out = Unk_7e9830(self->field_10, 0x62);
    Unk_7e9510(self->field_10);
    return result == target ? 0x1f : result;
}

// 0x710080d0e0
void Unk_80d0e0(Unk_804630_Flow* self,
                const Unk_7ee6b0* poke,
                u16 target,
                const Unk_807e00_Move* move,
                u8 arg4) {
    Unk_7e94d0(self->field_10);
    Unk_7e9610(self->field_10, 3, Unk_7ee6b0_getField7d(poke));
    Unk_7e9610(self->field_10, 4, target);
    Unk_7e9610(self->field_10, 0x16, move->field_e);
    Unk_7e9610(self->field_10, 0x12, move->field_0);
    Unk_7e9610(self->field_10, 0x62, arg4);
    Unk_7e8f60_call(self->field_10, 0x30);
    Unk_7e9510(self->field_10);
}

// 0x710080d190
u32 Unk_80d190(Unk_804630_Flow* self, const Unk_7ee6b0* poke) {
    Unk_7e94d0(self->field_10);
    Unk_7e9610(self->field_10, 2, Unk_7ee6b0_getField7d(poke));
    Unk_7e9720(self->field_10, 0x38, 0x1000, 0x19a, 0x20000);
    Unk_7e8f60_call(self->field_10, 0x97);
    u32 result = Unk_7e9830(self->field_10, 0x38);
    Unk_7e9510(self->field_10);
    return result;
}

// 0x710080d220
bool Unk_80d220(Unk_804630_Flow* self, const Unk_7ee6b0* poke, const u32* move) {
    Unk_7e94d0(self->field_10);
    Unk_7e9610(self->field_10, 2, Unk_7ee6b0_getField7d(poke));
    Unk_7e9610(self->field_10, 0x12, *move);
    Unk_7e9680(self->field_10, 0x77, 0);
    Unk_7e8f60_call(self->field_10, 0xe1);
    bool result = Unk_7e9830(self->field_10, 0x77) != 0;
    Unk_7e9510(self->field_10);
    return result;
}

// 0x710080d2c0
bool Unk_80d2c0(Unk_804630_Flow* self,
                const Unk_7ee6b0* attacker,
                const Unk_7ee6b0* defender,
                const Unk_7ee6b0* poke) {
    Unk_7e94d0(self->field_10);
    Unk_7e9610(self->field_10, 3, Unk_7ee6b0_getField7d(attacker));
    Unk_7e9610(self->field_10, 4, Unk_7ee6b0_getField7d(defender));
    Unk_7e9610(self->field_10, 2, Unk_7ee6b0_getField7d(poke));
    Unk_7e9680(self->field_10, 0x73, 0);
    Unk_7e8f60_call(self->field_10, 0xe2);
    bool result = Unk_7e9830(self->field_10, 0x73) != 0;
    Unk_7e9510(self->field_10);
    return result;
}

// 0x710080d3a0
bool Unk_80d3a0(Unk_804630_Flow* self, const Unk_7ee6b0* poke) {
    Unk_7e94d0(self->field_10);
    Unk_7e9610(self->field_10, 2, Unk_7ee6b0_getField7d(poke));
    Unk_7e9680(self->field_10, 0x56, 1);
    Unk_7e8f60_call(self->field_10, 0xe3);
    bool result = Unk_7e9830(self->field_10, 0x56) != 0;
    Unk_7e9510(self->field_10);
    return result;
}

// 0x7100805ce0
u32 Unk_805ce0(Unk_804630_Flow* self, const Unk_7ee6b0* poke, u32 arg2) {
    bool flag = Unk_7f0670(poke, arg2);
    Unk_7e94d0(self->field_10);
    Unk_7e9610(self->field_10, 2, Unk_7ee6b0_getField7d(poke));
    Unk_7e9680(self->field_10, 0x59, flag);
    Unk_7e8f60_call(self->field_10, 0x53);
    bool boost = Unk_7e9830(self->field_10, 0x59) != 0;
    Unk_7e9610(self->field_10, 0x4b, boost);
    Unk_7e95a0(self->field_10, 0x38, boost ? 0x1800 : 0x1000);
    Unk_7e8f60_call(self->field_10, 0x54);
    u32 result = Unk_7e9830(self->field_10, 0x38);
    Unk_7e9510(self->field_10);
    return result;
}

// 0x7100805dc0
u8 Unk_805dc0(Unk_804630_Flow* self) {
    Unk_7e94d0(self->field_10);
    Unk_7e9680(self->field_10, 0x48, 0);
    Unk_7e8f60_call(self->field_10, 0x95);
    u32 fail = Unk_7e9830(self->field_10, 0x48);
    Unk_7e9510(self->field_10);
    if (fail != 0)
        return 0;
    return Unk_7ffaa0_getField0(Unk_7fe1e0_getField28(self->field_18));
}

// 0x7100805e40
u8 Unk_805e40(Unk_804630_Flow* self, u8 pokeId, u8 arg2) {
    Unk_7e94d0(self->field_10);
    Unk_7e95a0(self->field_10, 2, pokeId);
    Unk_7e95a0(self->field_10, 0x3e, arg2);
    Unk_7e9680(self->field_10, 0x48, 0);
    Unk_7e8f60_call(self->field_10, 0x96);
    u32 fail = Unk_7e9830(self->field_10, 0x48);
    Unk_7e9510(self->field_10);
    return fail == 0 ? arg2 : 0;
}

// 0x71008062b0
u32 Unk_8062b0(Unk_804630_Flow* self,
               const Unk_7ee6b0* attacker,
               const Unk_7ee6b0* defender,
               u8 type,
               u32 value) {
    Unk_7e94d0(self->field_10);
    Unk_7e9610(self->field_10, 3, Unk_7ee6b0_getField7d(attacker));
    Unk_7e9610(self->field_10, 4, Unk_7ee6b0_getField7d(defender));
    Unk_7e9610(self->field_10, 0x16, type);
    Unk_7e9680(self->field_10, 0x3d, value);
    Unk_7e8f60_call(self->field_10, 0x50);
    u32 result = Unk_7e9830(self->field_10, 0x3d);
    Unk_7e9510(self->field_10);
    return result;
}

// 0x7100806380
bool Unk_806380(Unk_804630_Flow* self, const Unk_7ee6b0* poke, bool check) {
    bool flag = check ? Unk_7f0670(poke, 2) : false;
    Unk_7e94d0(self->field_10);
    Unk_7e9610(self->field_10, 2, Unk_7ee6b0_getField7d(poke));
    Unk_7e9680(self->field_10, 0x59, flag);
    Unk_7e9680(self->field_10, 0x48, 0);
    Unk_7e8f60_call(self->field_10, 0x12);
    if (Unk_7ef4c0(poke, 0x15))
        Unk_7e97b0(self->field_10, 0x48, 1);
    if (Unk_7ef4c0(poke, 0x20))
        Unk_7e97b0(self->field_10, 0x48, 1);
    if (Unk_7ef4c0(poke, 0x21) || Unk_7ef4c0(poke, 0x1f))
        Unk_7e97b0(self->field_10, 0x59, 1);
    u32 value = Unk_7e9830(self->field_10, 0x59);
    bool ok = Unk_7e9830(self->field_10, 0x48) == 0;
    Unk_7e9510(self->field_10);
    return value != 0 && ok;
}

// 0x71008064e0
bool Unk_8064e0(Unk_804630_Flow* self, const Unk_7ee6b0* attacker, const Unk_7ee6b0* defender) {
    Unk_7e94d0(self->field_10);
    Unk_7e9610(self->field_10, 3, Unk_7ee6b0_getField7d(attacker));
    Unk_7e9610(self->field_10, 4, Unk_7ee6b0_getField7d(defender));
    Unk_7e9680(self->field_10, 0x48, 0);
    Unk_7e8f60_call(self->field_10, 0x51);
    bool result = Unk_7e9830(self->field_10, 0x48) != 0;
    Unk_7e9510(self->field_10);
    return result;
}

// 0x7100806770
bool Unk_806770(Unk_804630_Flow* self, const Unk_7ee6b0* poke, const Unk_7ee6b0*, u8 arg3) {
    Unk_7e94d0(self->field_10);
    Unk_7e9610(self->field_10, 4, Unk_7ee6b0_getField7d(poke));
    Unk_7e9610(self->field_10, 0x69, arg3);
    Unk_7e9680(self->field_10, 0x59, 1);
    Unk_7e8f60_call(self->field_10, 0x9c);
    bool result = Unk_7e9830(self->field_10, 0x59) != 0;
    Unk_7e9510(self->field_10);
    return result;
}

// 0x7100806810
void Unk_806810(Unk_804630_Flow* self, const Unk_7ee6b0* poke, u32 arg2) {
    Unk_7e94d0(self->field_10);
    Unk_7e9610(self->field_10, 2, Unk_7ee6b0_getField7d(poke));
    Unk_7e9610(self->field_10, 0x35, arg2);
    Unk_7e8f60_call(self->field_10, 0x9d);
    Unk_7e9510(self->field_10);
}

// 0x7100806880
void Unk_806880(Unk_804630_Flow* self, const Unk_7ee6b0* poke, u32 arg2) {
    Unk_7e94d0(self->field_10);
    Unk_7e9610(self->field_10, 2, Unk_7ee6b0_getField7d(poke));
    Unk_7e9610(self->field_10, 0x35, arg2);
    Unk_7e8f60_call(self->field_10, 0x9e);
    Unk_7e9510(self->field_10);
}

// 0x7100806a80
u32 Unk_806a80(Unk_804630_Flow* self,
               u32 event,
               const Unk_7ee6b0* attacker,
               const Unk_7ee6b0* defender,
               const Unk_807e00_Move* move) {
    u32 power = Unk_780e00(move->field_0);
    Unk_7e94d0(self->field_10);
    Unk_7e9610(self->field_10, 3, Unk_7ee6b0_getField7d(attacker));
    Unk_7e9610(self->field_10, 4, Unk_7ee6b0_getField7d(defender));
    Unk_7e9610(self->field_10, 0x12, move->field_0);
    Unk_7e9610(self->field_10, 0x1b, move->field_10);
    Unk_7e9680(self->field_10, 0x2e, power);
    Unk_7e9720(self->field_10, 0x38, 0x1000, 0x19a, 0x20000);
    Unk_7e8f60_call(self->field_10, event);
    u32 value = Unk_7e9830(self->field_10, 0x2e);
    u32 ratio = Unk_7e9830(self->field_10, 0x38);
    Unk_7e9510(self->field_10);
    return Unk_7f7700(value, ratio);
}

// 0x71008068f0
bool Unk_8068f0(Unk_804630_Flow* self,
                bool* out,
                const Unk_7ee6b0* attacker,
                const Unk_7ee6b0* defender,
                const Unk_807e00_Move* move) {
    *out = false;
    u8 attackerLevel = Unk_7eef50(const_cast<Unk_7ee6b0*>(attacker), 0x11);
    u8 defenderLevel = Unk_7eef50(const_cast<Unk_7ee6b0*>(defender), 0x11);
    if (attackerLevel < defenderLevel)
        return false;
    Unk_7e94d0(self->field_10);
    Unk_7e9610(self->field_10, 3, Unk_7ee6b0_getField7d(attacker));
    Unk_7e9610(self->field_10, 4, Unk_7ee6b0_getField7d(defender));
    Unk_7e9680(self->field_10, 0x48, 0);
    Unk_7e95a0(self->field_10, 0x75, 0);
    Unk_7e8f60_call(self->field_10, 0x89);
    u32 fail = Unk_7e9830(self->field_10, 0x48);
    *out = Unk_7e9830(self->field_10, 0x75) != 0;
    Unk_7e9510(self->field_10);
    if (fail != 0)
        return false;
    if (Unk_80d9c0(reinterpret_cast<u64>(self->field_8), reinterpret_cast<u64>(attacker),
                   reinterpret_cast<u64>(defender),
                   Unk_7fe250_getFielda8(reinterpret_cast<const Unk_7fe250*>(self->field_18))))
        return true;
    u32 bonus = Unk_806a80(self, 0x41, attacker, defender, move);
    u8 chance = attackerLevel - defenderLevel + bonus;
    return Unk_7f7690(100) < chance;
}

// 0x7100806ba0
bool Unk_806ba0(Unk_804630_Flow* self,
                const Unk_7ee6b0* attacker,
                const Unk_7ee6b0* defender,
                const Unk_807e00_Move* move) {
    Unk_7e94d0(self->field_10);
    Unk_7e9610(self->field_10, 3, Unk_7ee6b0_getField7d(attacker));
    Unk_7e9610(self->field_10, 4, Unk_7ee6b0_getField7d(defender));
    Unk_7e9610(self->field_10, 0x1b, move->field_10);
    Unk_7e95a0(self->field_10, 0x59, 0);
    Unk_7e8f60_call(self->field_10, 0x8a);
    bool result = Unk_7e9830(self->field_10, 0x59) != 0;
    Unk_7e9510(self->field_10);
    return result;
}

// 0x7100806c70
void Unk_806c70(Unk_804630_Flow* self, const Unk_7ee6b0* attacker, const Unk_7ee6b0* defender) {
    Unk_7e94d0(self->field_10);
    Unk_7e9610(self->field_10, 3, Unk_7ee6b0_getField7d(attacker));
    Unk_7e9680(self->field_10, 4, Unk_7ee6b0_getField7d(defender));
    Unk_7e8f60_call(self->field_10, 0xdb);
    Unk_7e9510(self->field_10);
}

// 0x7100805600
u16 Unk_805600(Unk_804630_Flow* self,
               const Unk_7ee6b0* attacker,
               const Unk_7ee6b0* defender,
               const Unk_807e00_Move* move) {
    u16 power = move->field_20;
    Unk_7e94d0(self->field_10);
    Unk_7e9610(self->field_10, 3, Unk_7ee6b0_getField7d(attacker));
    Unk_7e9610(self->field_10, 4, Unk_7ee6b0_getField7d(defender));
    Unk_7e9610(self->field_10, 0x12, move->field_0);
    Unk_7e9610(self->field_10, 0x16, move->field_e);
    Unk_7e9610(self->field_10, 0x1b, move->field_10);
    Unk_7e9610(self->field_10, 0x63, move->field_14);
    Unk_7e9680(self->field_10, 0x5d, 0);
    Unk_7e9680(self->field_10, 0x5e, 0);
    Unk_7e9680(self->field_10, 0x33, power);
    Unk_7e8f60_call(self->field_10, 0x45);
    Unk_7e9720(self->field_10, 0x34, 0x1000, 0x29, 0x200000);
    Unk_7e8f60_call(self->field_10, 0x46);
    u16 value = Unk_7e9830(self->field_10, 0x33);
    u32 ratio = Unk_7e9830(self->field_10, 0x34);
    Unk_7e9510(self->field_10);
    return Unk_7f7700(value, ratio);
}

// 0x7100804630
u8 Unk_804630(const Unk_804630_Poke* poke, u32 move) {
    if (Unk_7f3350(poke)) {
        for (u64 i = 0; i < 0x23; i++) {
            const Unk_1f12228_Entry* entry = &Unk_1f12228[i];
            if (entry->field_0 ==
                    Unk_7eef40_getField70(reinterpret_cast<const Unk_7eef40*>(poke)) &&
                entry->field_4 == poke->field_33d && entry->field_6 == Unk_780d40(move))
                return entry->field_7;
        }
    }
    s32 index;
    switch (move) {
        case 0x2f5:
            index = 1;
            break;
        case 0x2f6:
            index = 11;
            break;
        case 0x2f7:
            index = 3;
            break;
        case 0x2f8:
            index = 0;
            break;
        case 0x2f9:
            index = 6;
            break;
        case 0x2fa:
            index = 13;
            break;
        case 0x2fb:
            index = 5;
            break;
        case 0x2fc:
            index = 7;
            break;
        case 0x2fd:
            index = 2;
            break;
        case 0x2fe:
            index = 9;
            break;
        case 0x2ff:
            index = 17;
            break;
        case 0x300:
            index = 14;
            break;
        case 0x301:
            index = 10;
            break;
        case 0x302:
            index = 12;
            break;
        case 0x303:
            index = 8;
            break;
        case 0x304:
            index = 15;
            break;
        case 0x305:
            index = 4;
            break;
        case 0x306:
            index = 16;
            break;
        default:
            return 0;
    }
    return Unk_1f123cc[index].field_4;
}

// 0x7100804700
s32 Unk_804700(u32 arg0, u16 arg1, bool arg2, bool arg3, u32 move) {
    if (arg2 && arg3 && Unk_780ec0(move)) {
        for (u64 i = 0; i < 0x23; i++) {
            const Unk_1f12228_Entry* entry = &Unk_1f12228[i];
            if (entry->field_0 == arg0 && entry->field_4 == arg1 &&
                entry->field_6 == Unk_780d40(move))
                return entry->field_8;
        }
    }
    return -1;
}

// 0x7100804810
u8 Unk_804810(u32 index) {
    return Unk_1f124f0[index];
}

// 0x7100804820
u8 Unk_804820(u32 index, u8 offset) {
    return Unk_1f124f0[index] + (offset > 5 ? 0 : offset);
}

// 0x71008048c0
u8 Unk_8048c0(u8 value) {
    if (value < 6)
        return 0;
    if (value <= 0xb)
        return 2;
    if (value < 0x12)
        return 1;
    if (value < 0x18)
        return 3;
    if (value <= 0x1d)
        return 4;
    return 0;
}

// 0x7100804840
u8 Unk_804840(u8 value) {
    u8 base = Unk_1f124f0[Unk_8048c0(value)];
    if (value < base)
        return 0;
    return value < base + 6 ? value - base : 0;
}

// 0x7100804920
u8 Unk_804920(u8 value) {
    u32 offset = value - Unk_1f124f0[Unk_8048c0(value)];
    return offset < 6 ? offset : 0;
}
