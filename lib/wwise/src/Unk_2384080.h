#pragma once
// The source that reads its samples from a stream (vtable 0x7102384080, on
// the class of 0x7102383f80). Written from the executable. Placeholder
// names.
#include "Unk_2383f80.h"

// What 0x71003ccb10 asks the stream and tells it back.
struct Unk_2384080_Info {
    u64 field_0;
    u32 field_8;
    u8 _c[4];
};

// The stream.
struct Unk_2384080_Stream {
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5(Unk_2384080_Info* info);
    virtual void vf6(Unk_2384080_Info* info);
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();
    virtual u32 vf12();
    virtual void vf13();
    virtual void vf14();
    virtual void vf15();
    virtual void vf16();
    virtual void vf17();
};

// What 0x71003cc420 is given.
struct Unk_3cc420_Arg {
    u32 field_0;
    u32 field_4;
    u32 field_8;
};

// What 0x71003cd170 is given: bytes.
struct Unk_3cd170_Data {
    u32 field_0;
    void* field_8;
};

class Unk_2384080 : public Unk_2383f80 {
public:
    Unk_2384080();

    Unk_2384080_Stream* field_58;
    u8* field_60;  // where it is in what the stream gave
    u32 field_68;
    u32 field_6c;
    u32 field_70;
    u32 field_74;
    u32 field_78;
    u32 field_7c;
    u16 field_80;
    u8 field_82_0 : 1;
    u8 field_82_1 : 1;
    u8 field_82_2 : 1;
    u8 field_82_3 : 1;
    u8 field_82_4 : 1;
};
PKMN_OFFSET_ASSERT(Unk_2384080, field_60, 0x60);
PKMN_OFFSET_ASSERT(Unk_2384080, field_80, 0x80);

u32 Unk_3cc420(Unk_2384080* self, Unk_3cc420_Arg* arg);
