// Scope: common
// A class on gflib3's Unk_239fd60 (vtable 0x71023bb170, 0x280 bytes) that
// adds nothing to it: its constructor (0x71008c26c0 makes one with
// Unk_New's steps, written out there), its destructors and thunks, and what
// hands its base's vf7 the data the caller has, with an empty string. Its
// vtables are emitted here, with its base's type getter (whose copy is
// src/unsorted/types/Unk_8c6600.cpp) and its thunks. Placeholder names:
// rename once the classes are known.
#include <types.h>

#include "gflib3/Unk_239a418.h"

// gflib3's class with vtable 0x710239fd70 (its constructor 0x710066afd0, D2
// 0x710066b040, D0 0x710066b2b0 and vf7 to vf9 are gflib3's, not written
// here): what follows its base is opaque here.
class Unk_239fd60 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_239a418_GetType());
        return &type;
    }

    explicit Unk_239fd60(Unk_239a418_Allocator* allocator);
    ~Unk_239fd60() override;
    const Unk_239a418_Type* vf_type() override { return Unk_GetType(); }
    // Its third parameter isn't used.
    virtual void vf7(const void* data, u64 size, const char* name);
    virtual void vf8();
    virtual void vf9();

    u8 _60[0x220];
};
static_assert(sizeof(Unk_239fd60) == 0x280, "Unk_239fd60");

class Unk_23bb160 : public Unk_239fd60 {
public:
    explicit Unk_23bb160(Unk_239a418_Allocator* allocator);
    ~Unk_23bb160() override;

    void Unk_8c65f0(const void* data, u64 size);
};
static_assert(sizeof(Unk_23bb160) == 0x280, "Unk_23bb160");

// 0x71008c6550
Unk_23bb160::Unk_23bb160(Unk_239a418_Allocator* allocator) : Unk_239fd60(allocator) {}

// 0x71008c6590 (D1), 0x71008c65c0 (D0), its thunks for +0x48 (0x71008c65a0
// D1, 0x71008c65d0 D0) and +0x50 (0x71008c65b0 D1, 0x71008c65e0 D0); the type
// getter's thunks 0x71008c66f0 (+0x48) and 0x71008c6700 (+0x50)
Unk_23bb160::~Unk_23bb160() = default;

// 0x71008c65f0
void Unk_23bb160::Unk_8c65f0(const void* data, u64 size) {
    Unk_239fd60::vf7(data, size, "");
}
