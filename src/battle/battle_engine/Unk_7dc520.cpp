// Scope: common
// Battle client commands (0x71007dc540 to 0x71007dc850): each reads the
// command's arguments and calls the matching server command
// (src/battle/battle_engine/Unk_8139c0.cpp). Placeholder names: rename once
// the class is known.
#include "battle/battle_engine/Unk_7dc020.h"

// The server commands (src/battle/battle_engine/Unk_8139c0.cpp).
void Unk_816f60(const Unk_8139c0_Self* self, u32 arg1, u32 arg2);
void Unk_817bb0(const Unk_8139c0_Self* self, u8 pokeId, u8 value);
void Unk_817e60(const Unk_8139c0_Self* self, u8 pokeId);
void Unk_817fa0(const Unk_8139c0_Self* self, u8 pokeId);
void Unk_818000(const Unk_8139c0_Self* self, u8 pokeId, u32 value);
void Unk_818040(const Unk_8139c0_Self* self, u8 pokeId, u8 value);
void Unk_818080(const Unk_8139c0_Self* self, u8 pokeId);
void Unk_8180c0(const Unk_8139c0_Self* self, u8 pokeId);
void Unk_818100(const Unk_8139c0_Self* self, u8 pokeId);
void Unk_818140(const Unk_8139c0_Self* self, u8 pokeId);
void Unk_818170(const Unk_8139c0_Self* self, u8 pokeId);
void Unk_8181a0(const Unk_8139c0_Self* self, u8 pokeId);
void Unk_818310(const Unk_8139c0_Self* self, u8 pokeId);
// These two take an id they don't use, so their placeholder names (made from
// their own code) leave it out: declared here with it, as the callers pass it.
struct Unk_8181d0;
void Unk_8181d0_call(const Unk_8181d0* self, u8 pokeId);
void Unk_8181f0(const Unk_8139c0_Self* self, u8 pokeId);

// 0x71007dc540
bool Unk_7dc540(Unk_7cdac0_Self* self, u32*, const u32* args) {
    u8 pokeId = args[0];
    u8 value = args[1];
    Unk_817bb0(Unk_7cdac0_Server(self), pokeId, value);
    return true;
}

// 0x71007dc580
bool Unk_7dc580(Unk_7cdac0_Self* self, u32*, const u32* args) {
    u32 arg1 = args[0];
    u32 arg2 = args[1];
    Unk_816f60(Unk_7cdac0_Server(self), arg1, arg2);
    return true;
}

// 0x71007dc5c0
bool Unk_7dc5c0(Unk_7cdac0_Self* self, u32*, const u32* args) {
    u8 pokeId = args[0];
    Unk_818310(Unk_7cdac0_Server(self), pokeId);
    return true;
}

// 0x71007dc5f0
bool Unk_7dc5f0(Unk_7cdac0_Self* self, u32*, const u32* args) {
    u8 pokeId = args[0];
    Unk_817fa0(Unk_7cdac0_Server(self), pokeId);
    return true;
}

// 0x71007dc620
bool Unk_7dc620(Unk_7cdac0_Self* self, u32*, const u32* args) {
    u8 pokeId = args[0];
    u32 value = args[1];
    Unk_818000(Unk_7cdac0_Server(self), pokeId, value);
    return true;
}

// 0x71007dc660
bool Unk_7dc660(Unk_7cdac0_Self* self, u32*, const u32* args) {
    u8 pokeId = args[0];
    u8 value = args[1];
    Unk_818040(Unk_7cdac0_Server(self), pokeId, value);
    return true;
}

// 0x71007dc6a0
bool Unk_7dc6a0(Unk_7cdac0_Self* self, u32*, const u32* args) {
    u8 pokeId = args[0];
    Unk_818080(Unk_7cdac0_Server(self), pokeId);
    return true;
}

// 0x71007dc6d0
bool Unk_7dc6d0(Unk_7cdac0_Self* self, u32*, const u32* args) {
    u8 pokeId = args[0];
    Unk_8180c0(Unk_7cdac0_Server(self), pokeId);
    return true;
}

// 0x71007dc700
bool Unk_7dc700(Unk_7cdac0_Self* self, u32*, const u32* args) {
    u8 pokeId = args[0];
    Unk_818100(Unk_7cdac0_Server(self), pokeId);
    return true;
}

// 0x71007dc730
bool Unk_7dc730(Unk_7cdac0_Self* self, u32*, const u32* args) {
    u8 pokeId = args[0];
    Unk_818140(Unk_7cdac0_Server(self), pokeId);
    return true;
}

// 0x71007dc760
bool Unk_7dc760(Unk_7cdac0_Self* self, u32*, const u32* args) {
    u8 pokeId = args[0];
    Unk_818170(Unk_7cdac0_Server(self), pokeId);
    return true;
}

// 0x71007dc790
bool Unk_7dc790(Unk_7cdac0_Self* self, u32*, const u32* args) {
    u8 pokeId = args[0];
    Unk_8181a0(Unk_7cdac0_Server(self), pokeId);
    return true;
}

// 0x71007dc7c0
// NON_MATCHING: Unk_8181d0_call's name has no id parameter; the original passes args[0].
bool Unk_7dc7c0(Unk_7cdac0_Self* self, u32*, const u32* args) {
    u8 pokeId = args[0];
    Unk_8181d0_call(reinterpret_cast<const Unk_8181d0*>(Unk_7cdac0_Server(self)), pokeId);
    return true;
}

// 0x71007dc7f0
// NON_MATCHING: Unk_8181f0's name has no id parameter; the original passes args[0].
bool Unk_7dc7f0(Unk_7cdac0_Self* self, u32*, const u32* args) {
    u8 pokeId = args[0];
    Unk_8181f0(Unk_7cdac0_Server(self), pokeId);
    return true;
}

// 0x71007dc820
bool Unk_7dc820(Unk_7cdac0_Self* self, u32*, const u32* args) {
    u8 pokeId = args[0];
    Unk_817e60(Unk_7cdac0_Server(self), pokeId);
    return true;
}
