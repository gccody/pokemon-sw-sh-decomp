// Scope: common
// Messages of kind 0x36 posted to the audio thread: what the message is in
// its second number, an ID in its third. Written from the executable.
// Placeholder names.
#include <types.h>

#include <string.h>

struct Unk_3358b0_T;
// The audio manager, as far as these functions use it: how many messages
// are being written.
struct Unk_3e5940_Manager {
    u8 _0[0x94];
    volatile s32 field_94;
};
extern Unk_3e5940_Manager* Unk_24bbbc0;

// A message of kind 0x36.
struct Unk_3e5940_Message {
    u32 field_0;
    u32 field_4;  // what it is
    u64 field_8;
    u32 field_10;
    u8 field_14[4];
};

u32 Unk_3358a0_get();
u32 Unk_335850_get();
Unk_3e5940_Message* Unk_336100(Unk_3358b0_T* self, u32 kind, u32 size);

// The queue of the manager: read before the size of a message is known
// (the first argument of the call that reserves it).
static inline Unk_3358b0_T* Unk_3e5940_Queue() {
    return reinterpret_cast<Unk_3358b0_T*>(Unk_24bbbc0);
}

static inline void Unk_3e5940_Finish() {
    __sync_fetch_and_sub(&Unk_24bbbc0->field_94, 1);
}

// 0x71003e5940
u32 Unk_3e5940(u64 id) {
    Unk_3e5940_Message* message =
        Unk_336100(Unk_3e5940_Queue(), 0x36, static_cast<u16>(Unk_3358a0_get()) + 0x38);
    message->field_4 = 1;
    message->field_8 = id;
    Unk_3e5940_Finish();
    return 1;
}

// 0x71003e5b00
u32 Unk_3e5b00(u64 id) {
    Unk_3e5940_Message* message = Unk_336100(Unk_3e5940_Queue(), 0x36, static_cast<u16>(Unk_3358a0_get()) + 8);
    message->field_4 = 2;
    message->field_8 = id;
    Unk_3e5940_Finish();
    return 1;
}

// 0x71003e5b70
u32 Unk_3e5b70(u64 id) {
    Unk_3e5940_Message* message = Unk_336100(Unk_3e5940_Queue(), 0x36, static_cast<u16>(Unk_3358a0_get()) + 8);
    message->field_4 = 3;
    message->field_8 = id;
    Unk_3e5940_Finish();
    return 1;
}

// 0x71003e60e0: with `count` items of 16 bytes
u32 Unk_3e60e0(u64 id, u64 items, u32 count) {
    Unk_3e5940_Message* message = Unk_336100(Unk_3e5940_Queue(), 0x36, 
        static_cast<u16>(Unk_3358a0_get()) + static_cast<u16>(Unk_335850_get()) + count * 16 - 16);
    message->field_4 = 6;
    message->field_8 = id;
    message->field_10 = count;
    memcpy(message->field_14, reinterpret_cast<void*>(items), count * 16);
    Unk_3e5940_Finish();
    return 1;
}
