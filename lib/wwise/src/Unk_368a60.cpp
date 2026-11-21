// Scope: common
// In a file of its own: the list's teardown (Unk_367ed0.cpp) calls it, and
// would inline it.
#include "Unk_368a60.h"

// 0x7100368a60
void Unk_368a60(Unk_368a60_T* object, u32 a1) {
    object->vf17(a1);
    if (object != nullptr) {
        int pool = Unk_2381488;
        object->~Unk_368a60_T();
        Unk_3047c0(pool, object);
    }
}
