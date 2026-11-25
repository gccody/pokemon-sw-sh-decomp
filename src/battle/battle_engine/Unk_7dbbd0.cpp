// Scope: common
// Battle client commands (0x71007dbcc0 to 0x71007dc020): each reads the
// command's arguments and forwards them to a server command. Placeholder
// names: rename once the class is known.
#include "battle/battle_engine/Unk_7dc020.h"

// The server commands (src/battle/battle_engine/Unk_8139c0.cpp and
// Unk_817a50.cpp).
void Unk_816bc0(const Unk_8139c0_Self* self, u8 pokeId);
void Unk_816e80(const Unk_8139c0_Self* self, u8 pokeId);
void Unk_817130(const Unk_8139c0_Self* self, u32 value);
void Unk_817190(const Unk_8139c0_Self* self, u32 arg1, u32 arg2);
void Unk_8171c0(const Unk_8139c0_Self* self, u8 arg1, u32 arg2);
void Unk_8173b0(const Unk_8139c0_Self* self, u8 pokeId, u8 otherId);
void Unk_8177f0(const Unk_8139c0_Self* self, u8 pokeId, u16 value);
void Unk_817830(const Unk_8139c0_Self* self, u8 pokeId);
void Unk_817d70(const Unk_8139c0_Self* self, u32 value);
void Unk_817db0(const Unk_8139c0_Self* self, u8 pokeId);

// 0x71007dbcc0
bool Unk_7dbcc0(Unk_7cdac0_Self* self, u32*, const u32* args) {
    u32 arg1 = args[0];
    u32 arg2 = args[1];
    Unk_817190(Unk_7cdac0_Server(self), arg1, arg2);
    return true;
}

// 0x71007dbd50
bool Unk_7dbd50(Unk_7cdac0_Self* self, u32*, const u32* args) {
    u32 arg1 = args[0];
    u32 arg2 = args[1];
    Unk_8171c0(Unk_7cdac0_Server(self), arg1, arg2);
    return true;
}

// 0x71007dbd90
bool Unk_7dbd90(Unk_7cdac0_Self* self, u32*, const u32* args) {
    u32 value = args[0];
    Unk_817130(Unk_7cdac0_Server(self), value);
    return true;
}

// 0x71007dbeb0
bool Unk_7dbeb0(Unk_7cdac0_Self* self, u32*, const u32* args) {
    u8 pokeId = args[0];
    Unk_816bc0(Unk_7cdac0_Server(self), pokeId);
    return true;
}

// 0x71007dbee0
bool Unk_7dbee0(Unk_7cdac0_Self* self, u32*, const u32* args) {
    u8 pokeId = args[0];
    u8 otherId = args[1];
    Unk_8173b0(Unk_7cdac0_Server(self), pokeId, otherId);
    return true;
}

// 0x71007dbf20
bool Unk_7dbf20(Unk_7cdac0_Self* self, u32*, const u32* args) {
    u8 pokeId = args[0];
    u16 value = args[1];
    Unk_8177f0(Unk_7cdac0_Server(self), pokeId, value);
    return true;
}

// 0x71007dbf60
bool Unk_7dbf60(Unk_7cdac0_Self* self, u32*, const u32* args) {
    u8 pokeId = args[0];
    Unk_817830(Unk_7cdac0_Server(self), pokeId);
    return true;
}

// 0x71007dbf90
bool Unk_7dbf90(Unk_7cdac0_Self* self, u32*, const u32* args) {
    u32 value = args[0];
    Unk_817d70(Unk_7cdac0_Server(self), value);
    return true;
}

// 0x71007dbfc0
bool Unk_7dbfc0(Unk_7cdac0_Self* self, u32*, const u32* args) {
    u8 pokeId = args[0];
    Unk_817db0(Unk_7cdac0_Server(self), pokeId);
    return true;
}

// 0x71007dbff0
bool Unk_7dbff0(Unk_7cdac0_Self* self, u32*, const u32* args) {
    u8 pokeId = args[0];
    Unk_816e80(Unk_7cdac0_Server(self), pokeId);
    return true;
}
