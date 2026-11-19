// Scope: common
//
// A class on gflib3's reference-counted object (vtable 0x710242ed68): a
// holder (Unk_236d3d8) and a table: buckets freed through an allocator and
// nodes that 0x71012f8b90 frees. Its destructor is its key function: its
// vtable and thunks are emitted here. Placeholder names: rename once the
// classes are known.
#include "unsorted/Unk_236d3d8.h"
#include "unsorted/Unk_2438308.h"

struct Unk_242ed68_Table;

// Frees a table's nodes from `node` on (0x71012f8b90), not decompiled yet.
void Unk_12f8b90(Unk_242ed68_Table* table, void* node);

struct Unk_242ed68_Table {
    ~Unk_242ed68_Table() { Unk_12f8b90(this, field_28); }

    Unk_2438308_Words<u64> field_0;
    u64 field_18;
    u64 field_20;
    void* field_28;
};
static_assert(sizeof(Unk_242ed68_Table) == 0x30, "Unk_242ed68_Table");

class Unk_242ed68 : public Unk_239a418 {
public:
    ~Unk_242ed68() override;
    const Unk_239a418_Type* vf_type() override;

    Unk_236d3d8 field_60;
    Unk_242ed68_Table field_170;
};
static_assert(sizeof(Unk_242ed68) == 0x1a0, "Unk_242ed68");
static_assert(__builtin_offsetof(Unk_242ed68, field_170) == 0x170, "Unk_242ed68::field_170");

// 0x71012f8900, its D0 and thunks for +0x48 and +0x50
Unk_242ed68::~Unk_242ed68() {}
