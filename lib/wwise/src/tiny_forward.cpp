// Scope: common
// Functions that tail-call one of tiny.cpp's: a TU of their own, so that
// the callee isn't inlined. The smallest Wwise functions: empty functions, deleting destructors of
// abstract classes (a trap), functions that return a constant and functions
// that only tail-call another. Placeholders: most are virtual functions of
// classes not reconstructed yet.
#include <nn/os.h>
#include <types.h>

void Unk_33cfe0(void* a0);
void Unk_33ebe0(void* a0);

// 0x710033cdc0
void Unk_33cdc0(void* a0) {
    Unk_33cfe0(a0);
}

// 0x710033e850
void Unk_33e850(void* a0) {
    Unk_33ebe0(a0);
}

// 0x710033f9e0
void Unk_33f9e0(void* a0) {
    Unk_33cfe0(a0);
}

// 0x710033fbf0
void Unk_33fbf0(void* a0) {
    Unk_33cfe0(a0);
}

// 0x710033fe00
void Unk_33fe00(void* a0) {
    Unk_33cfe0(a0);
}

// 0x71003407d0
void Unk_3407d0(void* a0) {
    Unk_33ebe0(a0);
}

// 0x7100340db0
void Unk_340db0(void* a0) {
    Unk_33cfe0(a0);
}

// 0x7100340f10
void Unk_340f10(void* a0) {
    Unk_33ebe0(a0);
}
