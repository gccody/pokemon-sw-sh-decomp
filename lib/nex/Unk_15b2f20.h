#pragma once
// The structure of NEX's "Gathering" data classes and the self structures of
// two of its derived classes (lib/nex/Unk_15b2f20.cpp).
#include "ddl/Streams.h"

// The structure 0x71015b2f20 reads: 0x71015b2dc0 writes the same fields.
struct Unk_15b2f20 : Unk_15b2dc0 {};
PKMN_SIZE_ASSERT(Unk_15b2f20, 0x60);

// The objects of vtable 0x710244e5a8: the structure, a byte cleared before
// the buffer is read and a Buffer.
struct Unk_244e598 : Unk_15b2f20 {
    u8 field_60;
    nn::nex::Buffer field_68;
};
PKMN_OFFSET_ASSERT(Unk_244e598, field_60, 0x60);
PKMN_OFFSET_ASSERT(Unk_244e598, field_68, 0x68);

// The objects of vtable 0x710244e768: the structure, then the version of a
// structure without fields.
struct Unk_244e758 : Unk_15b2f20 {
    u8 field_60;
};
PKMN_OFFSET_ASSERT(Unk_244e758, field_60, 0x60);

void Unk_15b2f20_read(nn::nex::ByteStream* s, Unk_15b2f20& v);
