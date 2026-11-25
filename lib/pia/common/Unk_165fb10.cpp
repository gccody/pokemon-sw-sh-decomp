// Scope: common
// common::StationAddress's members (Unk_165fb30, RTTI
// N2nn3pia6common14StationAddressE; vf5 is in
// lib/nx_middleware/class/nn_pia_common_StationAddress.cpp) and
// common::SocketStreamBase's constructor. Member names are placeholders
// (vf<slot>, lib/pia/README.md).
#include "pia/common/Unk_165fb10.h"

namespace nn {
namespace pia {

// 0x710165fb30
Unk_165fb30::Unk_165fb30() {}

// 0x710165fb50
Unk_165fb30::Unk_165fb30(const Unk_165fb30& other) : field_8(other.field_8) {}

// 0x710165fb70
void Unk_165fb30::Unk_165fb70() {
    field_8.Unk_16538d0();
}

// 0x710165fb80
Unk_165e060 Unk_165fb30::vf2(u8* buffer, u32* size, u32 capacity) {
    if (buffer == nullptr || size == nullptr) {
        return Unk_165e060Value<0x10c07>();
    }
    u32 needed = field_8.Unk_16532e0();
    if (needed > capacity) {
        return Unk_165e060Value<0x10c07>();
    }
    u32 written;
    Unk_165e060 result = field_8.Unk_1653370(buffer, &written, capacity);
    if (result.m_Value != 0) {
        return result;
    }
    *size = needed;
    return Unk_165e060Value<0>();
}

// 0x710165fc70
Unk_165e060 Unk_165fb30::vf3(const u8* buffer, u32 size) {
    if (buffer == nullptr) {
        return Unk_165e060Value<0x10c07>();
    }
    Unk_165e060 result = field_8.Unk_1653520(buffer, size);
    if (result.m_Value != 0) {
        return result;
    }
    return Unk_165e060Value<0>();
}

// 0x710165fd20
u32 Unk_165fb30::vf4() {
    return field_8.Unk_16532e0();
}

// 0x710165fd30
bool Unk_165fb30::Unk_165fd30() const {
    return Unk_1653890(reinterpret_cast<const Unk_1653890_arg0*>(&field_8));
}

// 0x710165fd40
bool Unk_165fb30::Unk_165fd40(const Unk_165fb30& other) const {
    return Unk_1653b50(reinterpret_cast<const Unk_1653890_arg0*>(&field_8),
                       reinterpret_cast<const Unk_1653890_arg0*>(&other.field_8));
}

// 0x710165fd50
Unk_165fb30& Unk_165fb30::operator=(const Unk_165fb30& other) {
    if (this != &other) {
        field_8 = other.field_8;
    }
    return *this;
}

// 0x710165fd90
Unk_165e060 Unk_165fb30::Unk_165fd90(const Unk_1652c70& value) {
    field_8 = value;
    return Unk_165e060Value<0>();
}

// 0x710165fdf0
void Unk_165fb30::Unk_165fdf0(Unk_23a2c98* out) const {
    common::FixedString<48> text;
    field_8.Unk_1652fe0(&text);
    out->Unk_165c560("%s", Unk_165be90_get(reinterpret_cast<const Unk_165be90*>(&text)));
}

// 0x710165feb0 (D2), 0x710165fed0 (D0): ~Unk_165fb30, inline in the header

namespace common {

// 0x710165ff10
SocketStreamBase::SocketStreamBase() : field_8(false), field_10(nullptr) {}

}  // namespace common
}  // namespace pia
}  // namespace nn
