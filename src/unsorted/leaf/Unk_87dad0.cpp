// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

// 0x710087dad0
void Unk_87dad0_update() {}

struct Unk_819640;
void Unk_819640_call(const Unk_819640*, u32, u32);

// 0x710087dae0
void Unk_87dae0_call(const Unk_819640* self) {
    Unk_819640_call(self, 0x51, 1);
}

void Unk_87e280(void*, u32, u32);

// 0x710087dfa0
void Unk_87dfa0_call(void* self) {
    Unk_87e280(self, 0x11, 0x674);
}

void Unk_87e280(void*, u32, u32);

// 0x710087e0f0
void Unk_87e0f0_call(void* self) {
    Unk_87e280(self, 0x10, 0x65c);
}
