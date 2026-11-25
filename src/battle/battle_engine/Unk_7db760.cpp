// Scope: common
// Battle client commands (0x71007db7d0 to 0x71007dbad0): each reads the
// command's arguments and forwards them to a server command. Placeholder
// names: rename once the class is known.
#include "battle/battle_engine/Unk_7dc020.h"

// The server commands (src/battle/battle_engine/Unk_8139c0.cpp and
// Unk_817a50.cpp).
void Unk_816960(const Unk_8139c0_Self* self, u8 pokeId, u32 value);
void Unk_8169a0(const Unk_8139c0_Self* self, u8 pokeId, u32 value);
void Unk_8169e0(const Unk_8139c0_Self* self, u8 pokeId, u32 value);
void Unk_816a20(const Unk_8139c0_Self* self, u8 pokeId, u32 value);
void Unk_816a60(const Unk_8139c0_Self* self, u8 pokeId, u32 value);
void Unk_816b90(const Unk_8139c0_Self* self, u8 pokeId);
void Unk_816e00(const Unk_8139c0_Self* self, u8 pokeId, u16 value);
void Unk_8174b0(const Unk_8139c0_Self* self, u8 pokeId, u16 value);
void Unk_817c80(const Unk_8139c0_Self* self, u16 value);
void Unk_817cb0(const Unk_8139c0_Self* self, u16 value);
void Unk_817ce0(const Unk_8139c0_Self* self, u8 pokeId);
void Unk_817d10(const Unk_8139c0_Self* self, u32 arg1, u32 arg2);
void Unk_817d40(const Unk_8139c0_Self* self, u32 arg1, u32 arg2);

// 0x71007db7d0
bool Unk_7db7d0(Unk_7cdac0_Self* self, u32*, const u32* args) {
    u8 pokeId = args[0];
    u32 value = args[1];
    Unk_8169e0(Unk_7cdac0_Server(self), pokeId, value);
    return true;
}

// 0x71007db810
bool Unk_7db810(Unk_7cdac0_Self* self, u32*, const u32* args) {
    u8 pokeId = args[0];
    u32 value = args[1];
    Unk_816a20(Unk_7cdac0_Server(self), pokeId, value);
    return true;
}

// 0x71007db850
bool Unk_7db850(Unk_7cdac0_Self* self, u32*, const u32* args) {
    u8 pokeId = args[0];
    u32 value = args[1];
    Unk_816960(Unk_7cdac0_Server(self), pokeId, value);
    return true;
}

// 0x71007db890
bool Unk_7db890(Unk_7cdac0_Self* self, u32*, const u32* args) {
    u8 pokeId = args[0];
    u32 value = args[1];
    Unk_8169a0(Unk_7cdac0_Server(self), pokeId, value);
    return true;
}

// 0x71007db8d0
bool Unk_7db8d0(Unk_7cdac0_Self* self, u32*, const u32* args) {
    u8 pokeId = args[0];
    u32 value = args[1];
    Unk_816a60(Unk_7cdac0_Server(self), pokeId, value);
    return true;
}

// 0x71007db910
bool Unk_7db910(Unk_7cdac0_Self* self, u32*, const u32* args) {
    u16 value = args[0];
    Unk_817c80(Unk_7cdac0_Server(self), value);
    return true;
}

// 0x71007db940
bool Unk_7db940(Unk_7cdac0_Self* self, u32*, const u32* args) {
    u16 value = args[0];
    Unk_817cb0(Unk_7cdac0_Server(self), value);
    return true;
}

// 0x71007db970
bool Unk_7db970(Unk_7cdac0_Self* self, u32*, const u32* args) {
    u8 pokeId = args[0];
    Unk_817ce0(Unk_7cdac0_Server(self), pokeId);
    return true;
}

// 0x71007db9a0
bool Unk_7db9a0(Unk_7cdac0_Self* self, u32*, const u32* args) {
    u32 arg1 = args[0];
    u32 arg2 = args[1];
    Unk_817d10(Unk_7cdac0_Server(self), arg1, arg2);
    return true;
}

// 0x71007db9e0
bool Unk_7db9e0(Unk_7cdac0_Self* self, u32*, const u32* args) {
    u32 arg1 = args[0];
    u32 arg2 = args[1];
    Unk_817d40(Unk_7cdac0_Server(self), arg1, arg2);
    return true;
}

// 0x71007dba20
bool Unk_7dba20(Unk_7cdac0_Self* self, u32*, const u32* args) {
    u8 pokeId = args[0];
    Unk_816b90(Unk_7cdac0_Server(self), pokeId);
    return true;
}

// 0x71007dba50
bool Unk_7dba50(Unk_7cdac0_Self* self, u32*, const u32* args) {
    u8 pokeId = args[0];
    u16 value = args[1];
    Unk_8174b0(Unk_7cdac0_Server(self), pokeId, value);
    return true;
}

// 0x71007dba90
bool Unk_7dba90(Unk_7cdac0_Self* self, u32*, const u32* args) {
    u8 pokeId = args[0];
    u16 value = args[1];
    Unk_816e00(Unk_7cdac0_Server(self), pokeId, value);
    return true;
}
