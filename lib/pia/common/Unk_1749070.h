#pragma once
// transport::SequenceIdController (vtable 0x7102460c38, RTTI
// N2nn3pia9transport20SequenceIdControllerE) and transport::Station (vtable
// 0x7102460c70, RTTI N2nn3pia9transport7StationE), as their members use them.
// Member names are placeholders (lib/pia/README.md). Their small members are
// in lib/nx_middleware/leaf/Unk_1721740.cpp and lib/nx_middleware/class.
#include "pia/common/Unk_165fb10.h"

// The system tick (lib/nx_middleware/leaf/Unk_16598a0.cpp).
struct Unk_165c600 {
    u64 field_0;
};
PKMN_SIZE_ASSERT(Unk_165c600, 0x8);
void Unk_165c600_call(Unk_165c600* self);  // reads the tick

bool Unk_165ca20(u8 value);  // a valid station index (< 0x20, or 0xfd)

namespace nn {
namespace pia {
namespace transport {

// RTTI N2nn3pia9transport11RttProtocolE (vtable 0x7102460b38): its members
// take a station index into the 0x58-byte entries at 0x58 (count at 0x60).
class RttProtocol {
public:
    void Unk_17483b0(u8 index);
    void Unk_1748490(u8 index);
    u32 Unk_1748810(u8 index);
    u32 Unk_1748850(u8 index, u32 value);
    void Unk_17488d0(u8 index);
    u32 Unk_1748900(u8 index);
    u32 Unk_1748930(u8 index);
};

// Counts received sequence ids (0 is never used) and the ones skipped.
class SequenceIdController {
public:
    SequenceIdController();
    virtual ~SequenceIdController();
    virtual void vf2();

    Unk_165e060 Unk_1749070();     // resets the counts
    u16 Unk_17490f0();             // the next id
    bool Unk_1749110(u16 id);      // counts a received id

    u16 field_8;
    u16 field_a;   // the last id received
    u16 field_c;   // ids received (saturates at 0xffff)
    u16 field_e;   // ids skipped
    u16 field_10;  // id-0 packets received (saturates at 0xffff)
    bool field_12; // field_c/field_10 still counting
    u32 field_14;  // ids received (saturates at 0xffffffff)
    u32 field_18;  // ids skipped
};
PKMN_OFFSET_ASSERT(SequenceIdController, field_8, 0x8);
PKMN_OFFSET_ASSERT(SequenceIdController, field_e, 0xe);
PKMN_OFFSET_ASSERT(SequenceIdController, field_12, 0x12);
PKMN_OFFSET_ASSERT(SequenceIdController, field_14, 0x14);
PKMN_OFFSET_ASSERT(SequenceIdController, field_18, 0x18);
PKMN_SIZE_ASSERT(SequenceIdController, 0x20);

class Station {
public:
    Station();
    virtual ~Station();
    virtual void vf2();
    virtual void vf3();

    Unk_165e060 Unk_1749370(RttProtocol* rtt);
    bool Unk_1749410(u64 id, u8 index, const Unk_165fb30& address);
    bool Unk_17494b0(const Unk_165fb30& address);
    bool Unk_1749530();
    void Unk_17495e0();
    Unk_165e060 Unk_1749680();
    u32 Unk_1749700();
    u32 Unk_1749730(u32 value);
    void Unk_1749760();
    u32 Unk_1749780();
    u32 Unk_17497b0();

    bool field_8;
    Unk_165fb30 field_10;  // common::StationAddress
    u8 field_38;           // station index (0xfd: none)
    u64 field_40;
    u32 field_48;
    RttProtocol* field_50;
    SequenceIdController field_58;
    u16 field_78;
    u64 field_80;  // ticks
    u64 field_88;
    bool field_90;
};
PKMN_OFFSET_ASSERT(Station, field_8, 0x8);
PKMN_OFFSET_ASSERT(Station, field_10, 0x10);
PKMN_OFFSET_ASSERT(Station, field_38, 0x38);
PKMN_OFFSET_ASSERT(Station, field_40, 0x40);
PKMN_OFFSET_ASSERT(Station, field_48, 0x48);
PKMN_OFFSET_ASSERT(Station, field_50, 0x50);
PKMN_OFFSET_ASSERT(Station, field_58, 0x58);
PKMN_OFFSET_ASSERT(Station, field_78, 0x78);
PKMN_OFFSET_ASSERT(Station, field_80, 0x80);
PKMN_OFFSET_ASSERT(Station, field_88, 0x88);
PKMN_OFFSET_ASSERT(Station, field_90, 0x90);
PKMN_SIZE_ASSERT(Station, 0x98);

}  // namespace transport
}  // namespace pia
}  // namespace nn
