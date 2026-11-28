// Scope: common
// Unk_2460ce8 (vtable 0x7102460ce8): two transport::StationLocations, a
// common::StationAddress and a count of at most 32, with a mutex. Its slot 3
// is transport::StationLocationTable's (RTTI
// N2nn3pia9transport20StationLocationTableE,
// lib/nx_middleware/class/nn_pia_transport_StationLocationTable.cpp); the
// constructor keeps the placeholder name its callers use. Slots 4-13 are pure
// virtual. Member names are placeholders (lib/pia/README.md).
#include "pia/common/Unk_174aea0.h"

namespace nn {
namespace pia {
namespace transport {

// As lib/pia/common/Unk_1749700.cpp declares it.
class StationLocation {
public:
    StationLocation();
    virtual ~StationLocation();

    StationLocation& operator=(const StationLocation& other);

    u8 _8[0x80 - 0x8];
};
PKMN_SIZE_ASSERT(StationLocation, 0x80);

}  // namespace transport
}  // namespace pia
}  // namespace nn

// The leaf getter (lib/nx_middleware/leaf) of a StationLocation's field_70.
struct Unk_1749d90;
u32 Unk_1749d90_get(const Unk_1749d90* self);

// The global the station's location writes a value of into (placeholder).
struct Unk_27fa8b8_type {
    u8 _0[0xd4];
    u32 field_d4;
};
PKMN_OFFSET_ASSERT(Unk_27fa8b8_type, field_d4, 0xd4);
extern Unk_27fa8b8_type Unk_27fa8b8;

class Unk_2460ce8 {
public:
    Unk_2460ce8();
    virtual ~Unk_2460ce8();
    virtual nn::pia::Unk_165e060 vf2(u32 count);
    virtual void vf3();
    virtual void vf4() = 0;
    virtual void vf5() = 0;
    virtual void vf6() = 0;
    virtual void vf7() = 0;
    virtual void vf8() = 0;
    virtual void vf9() = 0;
    virtual void vf10() = 0;
    virtual void vf11() = 0;
    virtual void vf12() = 0;
    virtual void vf13() = 0;

    void Unk_174a5a0(const nn::pia::transport::StationLocation& location);
    void Unk_174a5e0(const nn::pia::transport::StationLocation& location);

    nn::pia::transport::StationLocation field_8;
    nn::pia::transport::StationLocation field_88;
    nn::pia::Unk_165fb30 field_108;
    u32 field_130;  // at most 32
    // A mutex: pia/common/Unk_174aea0.h declares it as bytes, without its alignment.
    alignas(8) nn::pia::Unk_1655c60 field_138;
};
PKMN_OFFSET_ASSERT(Unk_2460ce8, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_2460ce8, field_88, 0x88);
PKMN_OFFSET_ASSERT(Unk_2460ce8, field_108, 0x108);
PKMN_OFFSET_ASSERT(Unk_2460ce8, field_130, 0x130);
PKMN_OFFSET_ASSERT(Unk_2460ce8, field_138, 0x138);
PKMN_SIZE_ASSERT(Unk_2460ce8, 0x158);

// 0x710174a460
Unk_2460ce8::Unk_2460ce8() : field_130(0), field_138(-1) {}

// 0x710174a4b0 (and 0x710174a510, deleting)
Unk_2460ce8::~Unk_2460ce8() {}

// 0x710174a520
nn::pia::Unk_165e060 Unk_2460ce8::vf2(u32 count) {
    if (count > 32) {
        return nn::pia::Unk_165e060Value<0x10c07>();
    }
    field_130 = count;
    return nn::pia::Unk_165e060Value<0>();
}

// 0x710174a5a0
void Unk_2460ce8::Unk_174a5a0(const nn::pia::transport::StationLocation& location) {
    field_8 = location;
    Unk_27fa8b8.field_d4 = Unk_1749d90_get(reinterpret_cast<const Unk_1749d90*>(&location));
}

// 0x710174a5e0
void Unk_2460ce8::Unk_174a5e0(const nn::pia::transport::StationLocation& location) {
    field_88 = location;
}
