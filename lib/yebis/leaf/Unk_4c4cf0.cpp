// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

// 0x71004c4cf0
void Unk_4c4cf0_update(u64 /*unused*/, u64 /*unused*/, u32 /*unused*/) {
}

// 0x71004c4d00
void Unk_4c4d00_update(u64 /*unused*/, u64 /*unused*/, u32 /*unused*/) {
}

// 0x71004c4d70
void Unk_4c4d70_update(u64 /*unused*/, u64 /*unused*/, u64 /*unused*/) {
}

// 0x71004c4d80
void Unk_4c4d80_update(u64 /*unused*/, u64 /*unused*/, u64 /*unused*/) {
}

void Unk_4c4700(void*, void*);

// 0x71004c5b30
u32 Unk_4c5b30_call(void* self, void* value) {
    Unk_4c4700(self, value);
    return 1;
}

void Unk_4c4700(void*, void*);

// 0x71004c5b50
u32 Unk_4c5b50_call(void* self, void* value) {
    Unk_4c4700(self, value);
    return 1;
}
