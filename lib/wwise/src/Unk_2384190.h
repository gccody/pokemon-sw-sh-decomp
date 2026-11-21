#pragma once
// The two filters with their memory that the class with the vtable
// 0x7102384248 has at 0x10. Written from the executable. Placeholder names.
#include <types.h>

// A filter: 0xb0 bytes with its memory at the end.
struct Unk_2384190_Filter {
    u8 _0[0xa0];
    void* field_a0;
    u32 field_a8;  // bytes
};
PKMN_SIZE_ASSERT(Unk_2384190_Filter, 0xb0);

struct Unk_2384190_State {
    u8 _0[0xc];
    bool field_c;
    u8 _d[3];
};
PKMN_SIZE_ASSERT(Unk_2384190_State, 0x10);

// The two filters (the function at 0x71003cd300 that the table of functions
// names its constructor is what the destructors below call).
struct Unk_2384190 {
    Unk_2384190();

    u8 _0[0x10];
    Unk_2384190_Filter field_10;
    Unk_2384190_Filter field_c0;
    Unk_2384190_State field_170;
    Unk_2384190_State field_180;
};
PKMN_SIZE_ASSERT(Unk_2384190, 0x190);

// What 0x71003cd530 is given.
struct Unk_3cd530_Arg {
    void* field_0;
};

void Unk_3cd4d0(Unk_2384190* self);
void Unk_3cd530(Unk_2384190* self, Unk_3cd530_Arg* arg);
