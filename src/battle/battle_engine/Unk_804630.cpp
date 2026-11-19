// Scope: common
// Functions that raise battle events (src/battle/battle_engine/Unk_7e8a20.h):
// each pushes a frame of variables, sets them from its arguments, calls the
// event and reads the result back. They're members of what holds the event
// system at +0x10 (0x7100804630 to 0x710080d4b0). Placeholder names: rename
// once the functions are known.
#include "battle/battle_engine/Unk_804630.h"

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
