// Scope: common
//
// The destructor and virtual functions of Unk_2399590
// (src/gflib3/Unk_2399590.h). Its destructor is its key function: its
// vtable, its inline vf_type and their thunks are emitted here.
#include "gflib3/Unk_2399590.h"

// 0x71005d1550, 0x71005d1b20 (D0), thunks 0x71005d1b00/0x71005d1b30 (+0x48)
// and 0x71005d1b10/0x71005d1b40 (+0x50). vf_type is 0x71005d2980, its
// thunks 0x71005d2a70 (+0x48) and 0x71005d2a80 (+0x50).
Unk_2399590::~Unk_2399590() {
    for (Unk_2399590* parent : field_60.field_0) {
        parent->field_90.Erase(this);
        for (Unk_2399590* child : field_90.field_0)
            child->Unk_5d1970(parent);
    }
    for (Unk_2399590* child : field_90.field_0)
        child->field_60.Erase(this);
}

// 0x71005d1b60
void Unk_2399590::vf3() {
    field_168.Clear();
    field_1f8.Clear();
    field_130 &= ~0x41ull;
    field_120.Reset();
    field_128.Reset();
    field_8->vf17();
    Unk_5d4c20(field_160, this);
}

// 0x71005d2800: runs once all of its parents have run it, then its
// children.
void Unk_2399590::vf7(Unk_2399590_Arg* arg) {
    if (!field_60.field_0.empty()) {
        s32 count = field_140.load(std::memory_order_relaxed);
        while (!field_140.compare_exchange_weak(count, count + 1, std::memory_order_relaxed)) {
        }
        if (field_60.field_0.size() != static_cast<size_t>(count + 1))
            return;
    }
    field_168.Unk_5d2a90(arg);
    for (Unk_2399590* child : field_90.field_0)
        child->vf7(arg);
    field_140.store(0, std::memory_order_release);
    field_288 = arg->field_8;
    field_1f8.Unk_5d2a90(arg);
}
