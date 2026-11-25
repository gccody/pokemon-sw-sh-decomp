// Scope: common
//
// The thunks of the type getters of Unk_240c2d8 and Unk_240c3e8
// (Unk_105d610.cpp, Unk_105db10.cpp) in the vtables of their object's two
// interfaces (+0x50, +0x58). The getters are written by tools/typegen.py with
// their slot names (src/unsorted/types/Unk_105ce20.cpp), which the classes'
// full declarations can't have (the object has functions of those names), so
// the thunks are written as functions over the class's `this` in a TU of
// their own, with the classes declared as the generator does.
#include "gflib3/Unk_239a418.h"

struct Unk_240c2d8 {
    const Unk_239a418_Type* vf3();
};

struct Unk_240c3e8 {
    const Unk_239a418_Type* vf2();
};

// 0x710105d8f0
const Unk_239a418_Type* Unk_105d8f0(void* self) {
    return reinterpret_cast<Unk_240c2d8*>(static_cast<u8*>(self) - 0x50)->vf3();
}

// 0x710105d900
const Unk_239a418_Type* Unk_105d900(void* self) {
    return reinterpret_cast<Unk_240c2d8*>(static_cast<u8*>(self) - 0x58)->vf3();
}

// 0x710105dca0
const Unk_239a418_Type* Unk_105dca0(void* self) {
    return reinterpret_cast<Unk_240c3e8*>(static_cast<u8*>(self) - 0x50)->vf2();
}

// 0x710105dcb0
const Unk_239a418_Type* Unk_105dcb0(void* self) {
    return reinterpret_cast<Unk_240c3e8*>(static_cast<u8*>(self) - 0x58)->vf2();
}
