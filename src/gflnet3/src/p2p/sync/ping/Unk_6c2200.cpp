// Scope: common
//
// What gflnet3's sync ping thread is handed (Unk_6c2200.h): its two
// implementations and the functions that compare them. Part of the segment
// 0x71006c1c70-0x71006c2920. Placeholder names: rename once the classes are
// known.
#include "gflnet3/src/p2p/sync/ping/Unk_6c2200.h"

#include <cstring>

// 0x71006c2200
Unk_6c2200_Header Unk_6c2200(const Unk_23a3d58_Base& data) {
    const Unk_6c2200_Header* p = reinterpret_cast<const Unk_6c2200_Header*>(data.vf2());
    if (p == nullptr)
        return {};
    Unk_6c2200_Header header;
    header.field_0 = p->field_0;
    header.field_2 = p->field_2;
    header.field_4 = p->field_4;
    return header;
}

// 0x71006c2250
bool Unk_6c2250(const Unk_23a3d58_Base& a, const Unk_23a3d58_Base& b) {
    return std::memcmp(a.vf2(), b.vf2(), sizeof(Unk_23a3d58::field_8)) == 0 && a.vf3() == b.vf3();
}

// 0x71006c2350
bool Unk_6c2350(const Unk_23a3d58_Base& a, const Unk_23a3d58_Base& b) {
    return !Unk_6c2250(a, b);
}

// 0x71006c2700
Unk_23a3d58::Unk_23a3d58(const Unk_23a3d58_Base& other) {
    std::memcpy(field_8, other.vf2(), sizeof(field_8));
    field_170 = other.vf3();
}

// 0x71006c26e0 (and the deleting one, 0x71006c2870)
Unk_23a3d58::~Unk_23a3d58() {}

// 0x71006c27d0 is in src/unsorted/virtual/Unk_6c27d0.cpp.

// 0x71006c27e0
Unk_23a3d58_OptionalValue Unk_23a3d58::vf3() const {
    return field_170;
}

// 0x71006c2810
Unk_23a3d88::Unk_23a3d88(const u8* data, const Unk_23a3d58_OptionalValue& value)
    : field_8(data), field_10(value) {}

// 0x71006c2850
Unk_23a3d58_OptionalValue Unk_23a3d88::vf3() const {
    return field_10;
}

// 0x71006c2890 (and the deleting one, 0x71006c28b0)
Unk_23a3d88::~Unk_23a3d88() {}
