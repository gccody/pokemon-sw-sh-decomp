// Scope: common
// Slots 7 and 8 of Unk_2418218 (vtable 0x7102418228, on gflib3's object),
// written as free functions: the class is declared by generators
// (src/unsorted/virtual/Unk_1100500.cpp, src/unsorted/types/Unk_1100570.cpp)
// without its bases. They hand what they're given to the global object
// Unk_24ba5b8 (vtable 0x710240ca38).
// Placeholder types: rename and move once the classes are known.
#include <cstring>

#include <types.h>

class Unk_240ca28;
extern Unk_240ca28* Unk_24ba5b8;
class Unk_2417bd8;
extern Unk_2417bd8* Unk_27e1870;

// src/unsorted/virtual/Unk_10f8e00.cpp's: a string, handed on by pointer.
// Its destructor is inline here: the original's stack copy calls none.
class Unk_2417d10 {
public:
    explicit Unk_2417d10(const char* value) : field_8(value) {}
    virtual ~Unk_2417d10() {}
    virtual u64 vf2();

    const char* field_8;
};
PKMN_OFFSET_ASSERT(Unk_2417d10, field_8, 0x8);

void Unk_1064e60(Unk_240ca28* self, u64 value);
void Unk_1062ad0(Unk_240ca28* self, const Unk_2417d10* value);
s32 Unk_174ff60(u64* length, char* dst, u64 dstSize, const char* src, u64 srcLength, s32 arg);

struct Unk_1100420_Arg {
    u8 _0[0x10];
    u64 field_10;
};
PKMN_OFFSET_ASSERT(Unk_1100420_Arg, field_10, 0x10);

struct Unk_1100440_Arg {
    u8 _0[0x48];
    const char* field_48;
};
PKMN_OFFSET_ASSERT(Unk_1100440_Arg, field_48, 0x48);

// 0x7101100420
void Unk_1100420(void* self, const Unk_1100420_Arg* arg) {
    if (Unk_24ba5b8 != nullptr)
        Unk_1064e60(Unk_24ba5b8, arg->field_10);
}

// NON_MATCHING: the buffer sits at sp+0x1c, the original's at sp+0x18 (8-aligned)
// 0x7101100440
void Unk_1100440(void* self, const Unk_1100440_Arg* arg) {
    if (Unk_27e1870 == nullptr)
        return;
    char buffer[0x201] = {};
    {
        const char* text = arg->field_48;
        u64 length;
        if (Unk_174ff60(&length, buffer, sizeof(buffer), text, strlen(text), 0) != 0 ||
            length < 0x200)
            return;
    }
    Unk_2417d10 value(buffer);
    if (Unk_24ba5b8 != nullptr)
        Unk_1062ad0(Unk_24ba5b8, &value);
}
