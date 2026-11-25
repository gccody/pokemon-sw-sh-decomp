// Scope: common
// The battle server's command queue: each command is written as its id and
// its arguments, whose count and format come from a table indexed by the id
// (Unk_8151d0 encodes them). Placeholder names: rename once they're known.
#include <cstdarg>

#include "battle/battle_engine/Unk_8139c0.h"

// A byte buffer with the write position first and a second position after it.
struct Unk_8151d0_Que {
    u32 field_0;
    u32 field_4;
    u8 field_8[1];
};
PKMN_OFFSET_ASSERT(Unk_8151d0_Que, field_4, 0x4);
PKMN_OFFSET_ASSERT(Unk_8151d0_Que, field_8, 0x8);

// The argument format of each command id.
extern const u8 Unk_1f12a80[0xbd] __attribute__((visibility("hidden")));

void Unk_8151d0(Unk_8151d0_Que* que, u16 id, u8 format, const u32* args);

// 0x7100816320
// NON_MATCHING: the name gives a third fixed u32 parameter; the original has
// only two before the variadic ones (it saves x2..x7 into its va_list).
void Unk_816320(u64 que, u32 id, u32 arg, ...) {
    u8 format = Unk_1f12a80[static_cast<u16>(id)];
    va_list list;
    u32 args[16] = {};
    va_start(list, arg);
    u32 count = 0;
    u32 value = arg;
    for (;;) {
        args[count++] = value;
        if (value == 0xffff0000)
            break;
        value = va_arg(list, u32);
    }
    va_end(list);
    Unk_8151d0(reinterpret_cast<Unk_8151d0_Que*>(que), id, format, args);
}

// 0x7100816420
void Unk_816420(Unk_816910_List* self) {
    self->field_8[self->field_0++] = 0;
    self->field_8[self->field_0++] = 0xc0;
    self->field_8[self->field_0++] = 1;
    self->field_8[self->field_0++] = 0;
}

// Reserves room for a command with no arguments, as a 0xbe record, and
// returns where it starts.
static inline u16 Unk_8151d0_Reserve(Unk_8151d0_Que* self, u16 id) {
    if (id < 0xbd) {
        u32 start = self->field_0;
        u8 format = Unk_1f12a80[id];
        u32 args[16] = {};
        Unk_8151d0(self, id, format, args);
        u8 size = self->field_0 - start;
        u16 pos = start;
        self->field_8[pos] = 0;
        self->field_8[pos + 1] = 0xbe;
        self->field_8[pos + 2] = size - 3;
        self->field_0 = pos + size;
        return start;
    }
    return 0xffff;
}

// 0x7100816460
u16 Unk_816460(u64 que, u32 id) {
    return Unk_8151d0_Reserve(reinterpret_cast<Unk_8151d0_Que*>(que), id);
}
// Writes a command at another position of the queue, then goes back.
static inline void Unk_8151d0_WriteAt(Unk_8151d0_Que* self, u16 pos, u16 id, const u32* args) {
    if (pos != 0xffff && id <= 0xbc) {
        u8 format = Unk_1f12a80[id];
        u16 saved = self->field_0;
        u16 second = self->field_4;
        self->field_0 = pos;
        self->field_4 = second;
        Unk_8151d0(self, id, format, args);
        self->field_0 = saved;
    }
}

// 0x7100816500
void Unk_816500(void* que, u32 pos, u16 id, ...) {
    if (id > 0xbc)
        return;
    va_list list;
    u32 args[16] = {};
    u8 format = Unk_1f12a80[id];
    u32 count = (format == 0x20 || format == 0x10) ? 9 : format & 0xf;
    va_start(list, id);
    for (u32 i = 0; i < count; i++)
        args[i] = va_arg(list, u32);
    va_end(list);
    Unk_8151d0_WriteAt(static_cast<Unk_8151d0_Que*>(que), pos, id, args);
}
// 0x7100816680
void Unk_816680(void* que, u32 pos, u16 id, ...) {
    va_list list;
    u32 args[16] = {};
    va_start(list, id);
    u32 count = 0;
    u32 value;
    do {
        value = va_arg(list, u32);
        args[count++] = value;
    } while (value != 0xffff0000);
    va_end(list);
    Unk_8151d0_WriteAt(static_cast<Unk_8151d0_Que*>(que), pos, id, args);
}

// Encodes a command with no arguments at the write position and returns its
// size.
static inline u8 Unk_8151d0_Encode(Unk_8151d0_Que* self, u16 id, u32 start) {
    u32 args[16] = {};
    Unk_8151d0(self, id, Unk_1f12a80[id], args);
    return self->field_0 - start;
}

// 0x71008167c0
void Unk_8167c0(Unk_8151d0_Que* self, u32 pos) {
    u32 end = self->field_0;
    u32 read = self->field_4;
    self->field_4 = pos;
    u32 start;
    u32 id;
    for (;;) {
        start = self->field_4;
        id = self->field_8[start] << 8 | self->field_8[start + 1];
        self->field_4 = start + 2;
        if (id != 0xc1 && id != 0xbe)
            break;
        self->field_4 += self->field_8[self->field_4] + 1;
        if (self->field_4 >= end) {
            start = pos;
            id = 0xbd;
            break;
        }
    }
    u8 size;
    u8 len = 0;
    if (id == 0xbf || id == 0xc0) {
        len = self->field_8[self->field_4++];
        self->field_0 = start;
    } else {
        self->field_0 = start;
    }
    if (len != 0)
        size = len + 3;
    else
        size = Unk_8151d0_Encode(self, id, start);
    u16 at = start;
    self->field_8[at] = 0;
    self->field_8[at + 1] = 0xc1;
    self->field_8[at + 2] = size - 3;
    self->field_0 = end;
    self->field_4 = read;
}

// 0x71008168e0
void Unk_8168e0(Unk_816910_List* self, u8 value) {
    self->field_8[self->field_0++] = 0;
    self->field_8[self->field_0++] = 0xbf;
    self->field_8[self->field_0++] = value;
}

// The battle Pokemon's member functions (src/battle/battle_engine/Unk_7ee6b0.cpp)
// and two it calls with the types their other callers gave them.
void Unk_7f1400(u64 self, u32 flag);
void Unk_7f1a20(u64 self, u32 flag);
void Unk_7f1430(Unk_7ee6b0* self, u32 flag);
void Unk_7f1460(Unk_7ee6b0* self, u32 flag);
void Unk_7f0b00(Unk_7ee6b0* self, u32 flag);

// 0x7100816960
void Unk_816960(const Unk_8139c0_Self* self, u8 pokeId, u32 flag) {
    Unk_7ee6b0* poke = Unk_8139c0_Poke(self, pokeId);
    Unk_7f1400(reinterpret_cast<u64>(poke), flag);
}

// 0x71008169a0
void Unk_8169a0(const Unk_8139c0_Self* self, u8 pokeId, u32 flag) {
    Unk_7ee6b0* poke = Unk_8139c0_Poke(self, pokeId);
    Unk_7f1a20(reinterpret_cast<u64>(poke), flag);
}

// 0x71008169e0
void Unk_8169e0(const Unk_8139c0_Self* self, u8 pokeId, u32 flag) {
    Unk_7ee6b0* poke = Unk_8139c0_Poke(self, pokeId);
    Unk_7f1430(poke, flag);
}

// 0x7100816a20
void Unk_816a20(const Unk_8139c0_Self* self, u8 pokeId, u32 flag) {
    Unk_7ee6b0* poke = Unk_8139c0_Poke(self, pokeId);
    Unk_7f1460(poke, flag);
}

// 0x7100816a60
void Unk_816a60(const Unk_8139c0_Self* self, u8 pokeId, u32 flag) {
    Unk_7ee6b0* poke = Unk_8139c0_Poke(self, pokeId);
    Unk_7f0b00(poke, flag);
}
