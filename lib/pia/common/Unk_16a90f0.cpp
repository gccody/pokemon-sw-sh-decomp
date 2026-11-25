// Scope: common
// mesh::MeshPacketReader's members (lib/pia/common/Unk_16a90f0.h): it knows
// this station's index and bit (0x10c, 0x110), and keeps only the messages
// sent to them. vf2, vf4 (lib/pia/gen), vf11 and vf16 (lib/nx_middleware/class)
// are elsewhere.
#include "pia/common/Unk_16a90f0.h"
#include "pia/common/Unk_16c1200.h"

namespace nn {
namespace pia {
namespace mesh {

// 0x71016a90b0 (and 0x71016a90f0, deleting)
MeshPacketReader::~MeshPacketReader() {
    Unk_17399f0_update(reinterpret_cast<u64>(&field_114));
}

// 0x71016a9130
Unk_165e060 MeshPacketReader::vf14(bool arg1, bool arg2, u32 arg3) {
    Unk_165e060 result(0);
    result = PacketReader::vf14(arg1, arg2, arg3);
    if (result.m_Value != 0) {
        return result;
    }
    field_10c = 0xfd;
    field_110 = 0;
    return Unk_165e060Value<0>();
}

// 0x71016a9210
void MeshPacketReader::vf3() {
    field_10c = 0xfd;
    field_110 = 0;
    PacketReader::vf3();
}

// 0x71016a9220
Unk_165e060 MeshPacketReader::vf15(void* arg1, Unk_16a9220_arg2* buffers, void* arg3, void* arg4) {
    Unk_165e060 result(0);
    result = PacketReader::vf15(arg1, buffers, arg3, arg4);
    if (result.m_Value != 0) {
        return result;
    }
    field_10c = 0xfd;
    field_110 = 0;
    return Unk_165e060Value<0>();
}

// 0x71016a9310
void MeshPacketReader::vf5() {
    field_10c = 0xfd;
    field_110 = 0;
    PacketReader::vf5();
}

// 0x71016a9320
// NON_MATCHING: the ring's first and next free index load as one ldp, where
// the original has two ldr (its loop wasn't rotated, and the guard was
// duplicated into the entry later); everything after is one instruction off.
void MeshPacketReader::vf8(Unk_16a9320_arg1* arg) {
    vf18();
    PacketReader::vf8(arg);
    u32 stations = 0;
    Unk_16a9220_arg2* buffers = field_38;
    for (s32 i = buffers->field_8; i != buffers->field_c;
         i = i + 1 >= buffers->field_0->count ? 0 : i + 1) {
        Unk_173ad90_arg1* buffer = &buffers->field_0->entries[i];
        if (!buffer->field_650) {
            continue;
        }
        if (buffer->field_d != 1) {
            transport::Station* station = Unk_174de50_get(Unk_27fc2d8)->vf11(&buffer->field_628);
            if (station != nullptr && station->field_38 < 32) {
                stations |= 1 << station->field_38;
            }
        }
        if (buffer->field_5e8 == 0x20) {
            continue;
        }
        u32 offset = 0;
        do {
            Unk_173e2c0(&field_40, buffer, offset);
            if (field_40.field_8 == 0) {
                break;
            }
            if (u64 source = field_40.field_48) {
                transport::Station* station = Unk_174de50_get(Unk_27fc2d8)->vf7(source);
                if (station != nullptr) {
                    stations |= 1 << station->field_38;
                }
            }
            u8 flags = field_40.field_38;
            u32 header = 1;
            if (flags & 1) {
                header += 1;
            }
            if (flags & 2) {
                header += 2;
            }
            if (flags & 4) {
                header += 4;
            }
            if (flags & 8) {
                header += 8;
            }
            if (flags & 0x10) {
                header += 8;
            }
            offset += (field_40.field_0 + header + 3) & ~3;
        } while (offset < buffer->field_5e8 - 0x20);
    }
    Unk_1739a00(&field_114, stations, arg);
}

// 0x71016a9510
void MeshPacketReader::vf9(Unk_16a9320_arg1* arg) {
    PacketReader::vf9(arg);
}

// 0x71016a9520
u64 MeshPacketReader::vf6(const Unk_165fb30* address) {
    transport::Station* station = Unk_174de50_get(Unk_27fc2d8)->vf11(address);
    if (station == nullptr) {
        return 0;
    }
    return station->field_40;
}

// 0x71016a9570
u8 MeshPacketReader::vf7(const Unk_165fb30* address) {
    transport::Station* station = Unk_174de50_get(Unk_27fc2d8)->vf11(address);
    if (station == nullptr) {
        return 0xfd;
    }
    return station->field_38;
}

// 0x71016a95d0
bool MeshPacketReader::vf17(u64 id) {
    return Unk_16a8390_get(Unk_27fb2d8)->Unk_16c1790(id);
}

// 0x71016a9600
u32 MeshPacketReader::vf22(const Unk_173ad90_arg1* buffer) {
    transport::Station* station = Unk_174de50_get(Unk_27fc2d8)->vf11(&buffer->field_628);
    if (station != nullptr) {
        u8 kind = buffer->field_d;
        // Station's 0x79 is a byte of its own (the kind), which
        // lib/pia/common/Unk_1749070.h declares as half of field_78.
        u8 stationKind = reinterpret_cast<const u8*>(&station->field_78)[1];
        if (kind >= 2 && stationKind != 0 && kind != stationKind) {
            return 0;
        }
        if (field_10c < 32 && !station->field_58.Unk_1749110(buffer->field_e)) {
            return 0;
        }
        if (field_10c != Unk_174de50_get(Unk_27fc2d8)->field_a0 && station->field_48 == 5 &&
            station->field_38 == 0xfd) {
            return 0;
        }
    }
    return buffer->field_5e8;
}

// 0x71016a96d0
bool MeshPacketReader::vf23(const Unk_173e5e0* message) {
    if (vf24(message)) {
        return true;
    }
    if ((message->field_39 & 3) != 1) {
        return false;
    }
    if (Unk_173e5e0_get(message) >> 32 != 0) {
        return false;
    }
    return field_110 == 0;
}

// 0x71016a9760
bool MeshPacketReader::vf24(const Unk_173e5e0* message) {
    u8 flags = message->field_39;
    if (flags & 2) {
        return false;
    }
    u64 destination = Unk_173e5e0_get(message);
    if (!(flags & 1)) {
        return destination == field_8;
    }
    if (destination >> 32 != 0) {
        return false;
    }
    u32 stations = Unk_173e5e0_get(message);
    if (stations == 0) {
        return true;
    }
    return (field_110 & stations) != 0;
}

// 0x71016a9820
bool MeshPacketReader::vf25(const Unk_165fb30* address) {
    transport::Station* station = Unk_174de50_get(Unk_27fc2d8)->vf11(address);
    if (station == nullptr) {
        return false;
    }
    transport::StationLocation location;
    Unk_165e060 result =
        Unk_174de60_get(reinterpret_cast<const Unk_174de60*>(Unk_27fc2d8))->vf5(station, &location);
    return result.m_Value == 0;
}

// 0x71016a98b0
void MeshPacketReader::vf18() {
    if (field_10c < 32) {
        return;
    }
    transport::Station* host = Unk_174de50_get(Unk_27fc2d8)->field_98;
    if (host == nullptr) {
        return;
    }
    u8 index = host->field_38;
    field_10c = index;
    if (index >= 32) {
        return;
    }
    field_8 = host->field_40;
    field_110 = 1 << index;
}

}  // namespace mesh
}  // namespace pia
}  // namespace nn
