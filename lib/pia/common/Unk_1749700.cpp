// Scope: common
// transport::StationLocation (vtable 0x7102460cb0, RTTI
// N2nn3pia9transport15StationLocationE): three addresses and the values
// after them. pia/common/Unk_1749cd0.h declares the same object as
// Unk_1749cf0 for its getters (0x7101749cd0 on); vf4 is in
// lib/nx_middleware/class/nn_pia_transport_StationLocation.cpp. Member names
// are placeholders (lib/pia/README.md).
#include "pia/common/Unk_165fb10.h"

namespace nn {
namespace pia {
namespace transport {

class StationLocation {
public:
    StationLocation();
    StationLocation(const StationLocation& other);
    virtual ~StationLocation();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();

    StationLocation& operator=(const StationLocation& other);
    void Unk_1749960(const StationLocation& other);  // copies every field
    bool Unk_1749b10(const StationLocation& other) const;  // equal
    bool Unk_1749bf0(const StationLocation& other) const;  // not equal

    Unk_1652c70 field_8;
    Unk_1652c70 field_28;
    Unk_1652c70 field_48;
    u64 field_68;
    u32 field_70;
    u32 field_74;
    u8 field_78;  // bits 0-1, 2-3 and 4-7: three values
    u8 field_79;  // bit 7 isn't compared
    u8 field_7a;
    u8 field_7b;
};
PKMN_OFFSET_ASSERT(StationLocation, field_8, 0x8);
PKMN_OFFSET_ASSERT(StationLocation, field_28, 0x28);
PKMN_OFFSET_ASSERT(StationLocation, field_48, 0x48);
PKMN_OFFSET_ASSERT(StationLocation, field_68, 0x68);
PKMN_OFFSET_ASSERT(StationLocation, field_70, 0x70);
PKMN_OFFSET_ASSERT(StationLocation, field_74, 0x74);
PKMN_OFFSET_ASSERT(StationLocation, field_78, 0x78);
PKMN_OFFSET_ASSERT(StationLocation, field_79, 0x79);
PKMN_OFFSET_ASSERT(StationLocation, field_7a, 0x7a);
PKMN_OFFSET_ASSERT(StationLocation, field_7b, 0x7b);
PKMN_SIZE_ASSERT(StationLocation, 0x80);

static bool Equals(const Unk_1652c70& a, const Unk_1652c70& b) {
    return Unk_1653b50(reinterpret_cast<const Unk_1653890_arg0*>(&a),
                       reinterpret_cast<const Unk_1653890_arg0*>(&b));
}

// 0x7101749820
StationLocation::StationLocation()
    : field_68(0), field_70(0), field_74(0), field_78(0), field_79(0), field_7a(0), field_7b(0) {
    field_8.Unk_16538d0();
    field_28.Unk_16538d0();
    field_48.Unk_16538d0();
}

// 0x71017498a0
StationLocation::StationLocation(const StationLocation& other) {
    Unk_1749960(other);
}

// 0x7101749960
void StationLocation::Unk_1749960(const StationLocation& other) {
    field_8 = other.field_8;
    field_28 = other.field_28;
    field_48 = other.field_48;
    field_68 = other.field_68;
    field_70 = other.field_70;
    field_74 = other.field_74;
    field_78 = other.field_78;
    field_79 = other.field_79;
    field_7a = other.field_7a;
    field_7b = other.field_7b;
}

// 0x71017499e0
StationLocation::~StationLocation() {}

// 0x7101749a80
StationLocation& StationLocation::operator=(const StationLocation& other) {
    if (this != &other) {
        Unk_1749960(other);
    }
    return *this;
}

// 0x7101749b10
bool StationLocation::Unk_1749b10(const StationLocation& other) const {
    if (Equals(field_8, other.field_8) && Equals(field_28, other.field_28) &&
        Equals(field_48, other.field_48) && field_68 == other.field_68 &&
        field_70 == other.field_70 && field_74 == other.field_74 && field_78 == other.field_78 &&
        (field_79 & 0x7f) == (other.field_79 & 0x7f) && field_7a == other.field_7a &&
        field_7b == other.field_7b) {
        return true;
    }
    return false;
}

// 0x7101749bf0
bool StationLocation::Unk_1749bf0(const StationLocation& other) const {
    return !Unk_1749b10(other);
}

}  // namespace transport
}  // namespace pia
}  // namespace nn
