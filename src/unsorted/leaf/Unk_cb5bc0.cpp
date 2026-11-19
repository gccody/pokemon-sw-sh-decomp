// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

// 0x7100cb5bc0
void Unk_cb5bc0() {}

// 0x7100cb5bd0
void Unk_cb5bd0() {}

void Unk_cb6430(void*, void*, u64, u64, u32);

// 0x7100cb6420
void Unk_cb6420_call(void* self, void* value, u64 arg2, u64 arg3) {
    Unk_cb6430(self, value, arg2, arg3, 0);
}

void Unk_cb6430(void*, void*, u64, u64, u32);

// 0x7100cb6610
void Unk_cb6610_call(void* self, void* value, u64 arg2, u64 arg3) {
    Unk_cb6430(self, value, arg2, arg3, 1);
}

void Unk_cb6c70(void*, void*, u64, u64, u32);

// 0x7100cb6c60
void Unk_cb6c60_call(void* self, void* value, u64 arg2, u64 arg3) {
    Unk_cb6c70(self, value, arg2, arg3, 0);
}

void Unk_cb6c70(void*, void*, u64, u64, u32);

// 0x7100cb6e50
void Unk_cb6e50_call(void* self, void* value, u64 arg2, u64 arg3) {
    Unk_cb6c70(self, value, arg2, arg3, 1);
}
