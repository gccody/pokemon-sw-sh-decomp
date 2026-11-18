// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

void Unk_81bc20(void*, u64, u32, u32);

// 0x7100869aa0
void Unk_869aa0_call(void* self, u64 value) {
    Unk_81bc20(self, value, 2, 3);
}

void Unk_86b540(void*, u32, u32);

// 0x710086b440
void Unk_86b440_call(void* self, u32 value) {
    Unk_86b540(self, 1, value);
}

void Unk_86b540(void*, u32, u32);

// 0x710086b6f0
void Unk_86b6f0_call(void* self, u32 value) {
    Unk_86b540(self, 2, value);
}

void Unk_86b540(void*, u32, u32);

// 0x710086b8b0
void Unk_86b8b0_call(void* self, u32 value) {
    Unk_86b540(self, 0, value);
}

void Unk_81b320();

// 0x710086ea90
void Unk_86ea90_call() {
    Unk_81b320();
}

void Unk_81b860();

// 0x710086eb40
void Unk_86eb40_call() {
    Unk_81b860();
}

void Unk_86f720();

// 0x710086f5f0
void Unk_86f5f0_call() {
    Unk_86f720();
}

void Unk_86fe60(void*, u64, u32);

// 0x710086fda0
void Unk_86fda0_call(void* self, u64 value) {
    Unk_86fe60(self, value, 0);
}

void Unk_86fe60(void*, u64, u32);

// 0x710086fdb0
void Unk_86fdb0_call(void* self, u64 value) {
    Unk_86fe60(self, value, 1);
}

void Unk_879590(void*, u64, u32);

// 0x7100879580
void Unk_879580_call(void* self, u64 value) {
    Unk_879590(self, value, 1);
}

void Unk_879590(void*, u64, u32);

// 0x7100879660
void Unk_879660_call(void* self, u64 value) {
    Unk_879590(self, value, 2);
}

void Unk_879590(void*, u64, u32);

// 0x7100879670
void Unk_879670_call(void* self, u64 value) {
    Unk_879590(self, value, 3);
}

void Unk_879590(void*, u64, u32);

// 0x7100879680
void Unk_879680_call(void* self, u64 value) {
    Unk_879590(self, value, 4);
}

void Unk_87a210();

// 0x710087a1b0
void Unk_87a1b0_call() {
    Unk_87a210();
}

void Unk_87a7b0();

// 0x710087a750
void Unk_87a750_call() {
    Unk_87a7b0();
}
