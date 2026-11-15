// Scope: common - example of a cross-TU tail call, verified via relocations.
#include "unsorted/Unk_7eef40.h"

// 0x71007cc390 - ignores its first argument and tail-calls the getter.
u16 Unk_7cc390(void* /*unused*/, const Unk_7eef40* obj) {
    return Unk_7eef40_getField70(obj);
}
