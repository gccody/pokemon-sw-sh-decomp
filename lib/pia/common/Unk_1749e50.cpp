// Scope: common
#include "pia/common/Unk_1749cd0.h"

// lib/nx_middleware/leaf/Unk_1721740.cpp: memcmp of the 16 bytes at 0x8.
struct Unk_1653860;
struct Unk_1653860_arg1;
bool Unk_1653860_call(const Unk_1653860* self, const Unk_1653860_arg1* value);

namespace nn {
namespace pia {

static bool Unk_1652c70_Equals(const Unk_1652c70& a, const Unk_1652c70& b) {
    return Unk_1653860_call(reinterpret_cast<const Unk_1653860*>(&a),
                            reinterpret_cast<const Unk_1653860_arg1*>(&b));
}

// 0x7101749e60
bool Unk_1749cf0::Unk_1749e60(const Unk_1749cf0& other) const {
    return Unk_1652c70_Equals(field_8, other.field_8);
}

// 0x7101749e70
bool Unk_1749cf0::Unk_1749e70(const Unk_1749cf0& other) const {
    return Unk_1652c70_Equals(field_28, other.field_28);
}

// 0x7101749f00
void Unk_1749cf0::Unk_1749f00(const Unk_1652c70& value) {
    field_8.Unk_1652cf0(value);
}

// 0x7101749f10
void Unk_1749cf0::Unk_1749f10(const Unk_1652c70& value) {
    field_28.Unk_1652cf0(value);
}

// 0x7101749f20
void Unk_1749cf0::Unk_1749f20(const Unk_1652c70& value) {
    field_48.Unk_1652cf0(value);
}

// 0x7101749f60
void Unk_1749cf0::Unk_1749f60(u32 value) {
    field_78 = (field_78 & ~0xc) | ((value & 3) << 2);
}

}  // namespace pia
}  // namespace nn
