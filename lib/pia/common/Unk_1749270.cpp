// Scope: common
// transport::Station's members (lib/pia/common/Unk_1749070.h). vf2 is in
// lib/nx_middleware/class/nn_pia_transport_Station.cpp, vf3 (0x7101749810)
// in nn_pia_mesh_MeshStation.cpp, 0x71017493f0's neighbour 0x7101749400 and
// 0x71017497e0 in lib/nx_middleware/leaf/Unk_1721740.cpp.
#include "pia/common/Unk_1749070.h"

void Unk_17490e0_update(u64 self);  // SequenceIdController's, does nothing
nn::pia::Unk_165e060 Unk_1748960_call(u64 value);

namespace nn {
namespace pia {
namespace transport {

// 0x7101749270
Station::Station()
    : field_8(false), field_38(0xfd), field_40(0), field_48(0), field_50(nullptr), field_78(0),
      field_80(0), field_88(0), field_90(false) {}

// 0x71017492d0
Station::~Station() {}

// 0x7101749370
Unk_165e060 Station::Unk_1749370(RttProtocol* rtt) {
    if (rtt == nullptr) {
        return Unk_165e060Value<0x10c07>();
    }
    field_50 = rtt;
    field_8 = false;
    return Unk_165e060Value<0>();
}

// 0x7101749410
bool Station::Unk_1749410(u64 id, u8 index, const Unk_165fb30& address) {
    if (!Unk_165ca20(index)) {
        return false;
    }
    field_8 = true;
    field_58.Unk_1749070();
    Unk_165c600 now = {0};
    Unk_165c600_call(&now);
    field_80 = now.field_0;
    field_88 = now.field_0;
    field_40 = id;
    field_38 = index;
    field_10 = address;
    field_48 = 1;
    field_78 = 0;
    field_90 = false;
    return true;
}

// 0x71017494b0
bool Station::Unk_17494b0(const Unk_165fb30& address) {
    field_8 = true;
    field_58.Unk_1749070();
    Unk_165c600 now = {0};
    Unk_165c600_call(&now);
    field_80 = now.field_0;
    field_88 = now.field_0;
    field_40 = 0;
    field_38 = 0xfd;
    field_10 = address;
    field_48 = 1;
    field_78 = 0;
    field_90 = false;
    return true;
}

// 0x7101749530
bool Station::Unk_1749530() {
    Unk_165fb30 address;
    address.Unk_165fb70();
    return Unk_17494b0(address);
}

// 0x71017495e0
void Station::Unk_17495e0() {
    Unk_165fb30 address;
    address.Unk_165fb70();
    field_8 = false;
    Unk_17490e0_update(reinterpret_cast<u64>(&field_58));
    if (field_50 != nullptr && field_38 != 0xfd) {
        field_50->Unk_1748490(field_38);
    }
    field_40 = 0;
    field_38 = 0xfd;
    field_10 = address;
    field_48 = 0;
    field_78 = 0;
    field_90 = false;
}

// 0x7101749680
Unk_165e060 Station::Unk_1749680() {
    if (field_50 == nullptr || field_38 == 0xfd) {
        return Unk_165e060Value<0x10c08>();
    }
    field_50->Unk_17483b0(field_38);
    return Unk_165e060Value<0>();
}

// 0x7101749700
u32 Station::Unk_1749700() {
    if (field_50 == nullptr || field_38 == 0xfd) {
        return 0xffffffff;
    }
    return field_50->Unk_1748810(field_38);
}

// 0x7101749730
u32 Station::Unk_1749730(u32 value) {
    if (field_50 == nullptr || field_38 == 0xfd) {
        return 0xffffffff;
    }
    return field_50->Unk_1748850(field_38, value);
}

// 0x7101749760
void Station::Unk_1749760() {
    if (field_50 == nullptr || field_38 == 0xfd) {
        return;
    }
    field_50->Unk_17488d0(field_38);
}

// 0x7101749780
u32 Station::Unk_1749780() {
    if (field_50 == nullptr || field_38 == 0xfd) {
        return 0xffffffff;
    }
    return field_50->Unk_1748900(field_38);
}

// 0x71017497b0
u32 Station::Unk_17497b0() {
    if (field_50 == nullptr || field_38 == 0xfd) {
        return 0xffffffff;
    }
    return field_50->Unk_1748930(field_38);
}

}  // namespace transport
}  // namespace pia
}  // namespace nn

// 0x7101749800
nn::pia::Unk_165e060 Unk_1749800(s64 value) {
    return Unk_1748960_call(value);
}
