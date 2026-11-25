// Scope: common
// mesh::MeshPacketWriter's members (lib/pia/common/Unk_16a90f0.h): it knows
// this station's index and bit (0x1038, 0x103c) and sends to one station, to
// every station or to the ones of a mask. vf2, vf4 (lib/pia/gen) and vf11
// (lib/nx_middleware/class) are elsewhere; 0x71016a9920-0x71016a9a20 are
// MeshPacketReader's and PacketHandler's small members and a constructor.
#include "pia/common/Unk_16a90f0.h"

namespace nn {
namespace pia {
namespace mesh {

// 0x71016a9a50 (and 0x71016a9a60, deleting)
MeshPacketWriter::~MeshPacketWriter() {}

// 0x71016a9a90
Unk_165e060 MeshPacketWriter::vf14(bool arg1, bool arg2, u32 arg3, u32 arg4) {
    Unk_165e060 result(0);
    result = PacketWriter::vf14(arg1, arg2, arg3, arg4);
    if (result.m_Value != 0) {
        return result;
    }
    field_1038 = 0xfd;
    field_103c = 0;
    return Unk_165e060Value<0>();
}

// 0x71016a9b80
void MeshPacketWriter::vf3() {
    field_1038 = 0xfd;
    field_103c = 0;
    PacketWriter::vf3();
}

// 0x71016a9ba0
Unk_165e060 MeshPacketWriter::vf15(void* arg1, void* arg2, void* arg3) {
    Unk_165e060 result(0);
    result = PacketWriter::vf15(arg1, arg2, arg3);
    if (result.m_Value != 0) {
        return result;
    }
    if (Unk_27fb2d8 == nullptr) {
        return Unk_165e060Value<0x10c08>();
    }
    field_1048 = Unk_16a8380_get(reinterpret_cast<const Unk_16a8380*>(Unk_27fb2d8));
    if (field_1048 == nullptr) {
        return Unk_165e060Value<0x10c08>();
    }
    result = Unk_16c0ab0(field_1048, this);
    field_1038 = 0xfd;
    field_103c = 0;
    field_1040 = 0;
    Unk_173eb50_set(&field_38, 0);
    return Unk_165e060Value<0>();
}

// 0x71016a9ce0
void MeshPacketWriter::vf5() {
    field_1038 = 0xfd;
    field_103c = 0;
    field_1040 = 0;
    if (field_1048 != nullptr) {
        Unk_16c0b10(field_1048);
    }
    PacketWriter::vf5();
}

// 0x71016a9d20
// NON_MATCHING: PacketWriter::vf8 (0x710173c350) is named without the
// parameter it's given (RENAME in the report).
void MeshPacketWriter::vf8(Unk_16a9320_arg1* arg) {
    vf21(arg);
    PacketWriter::vf8(arg);
}

// 0x71016a9d60
void MeshPacketWriter::vf9(Unk_16a9320_arg1* arg) {
    if (field_1048 != nullptr) {
        Unk_16c0b30(field_1048);
    }
    u32 stations = Unk_1739b30(&field_fec, field_1040, arg);
    field_1040 = 0;
    if (stations != 0) {
        Unk_16a9e40_message* sent;
        {
            Unk_16a9e40_arg1 message;
            message.field_0 = 0x8000000;
            u32 connected = Unk_174de50_get(Unk_27fc2d8)->Unk_174b0f0(false);
            sent = vf24(&message, connected & stations, 0, false, false, false, true);
        }
        if (sent != nullptr) {
            Unk_173caa0();
            if (field_1040 != 0) {
                Unk_1739b30(&field_fec, field_1040, arg);
                field_1040 = 0;
            }
        }
    }
    PacketWriter::vf9(arg);
}

// 0x71016a9e40
Unk_16a9e40_message* MeshPacketWriter::vf17(Unk_16a9e40_arg1* message, u8 station, u32 arg3, bool arg4, bool arg5,
                                            bool arg6, bool arg7) {
    if (station != 0xff) {
        return vf22(message, station, arg3, arg4, arg5, arg6, arg7);
    }
    if (vf12() && vf13()) {
        return vf23(message, arg3, arg4, arg5, arg6, arg7);
    }
    u32 stations = Unk_174de50_get(Unk_27fc2d8)->Unk_174b0f0(false);
    return vf24(message, stations, arg3, arg4, arg5, arg6, arg7);
}

// 0x71016a9f50
Unk_16a9e40_message* MeshPacketWriter::vf18(Unk_16a9e40_arg1* message, u64 id, u32 arg3, bool arg4, bool arg5,
                                            bool arg6, bool arg7) {
    transport::Station* station = Unk_174de50_get(Unk_27fc2d8)->vf15(id);
    if (station == nullptr || station->field_38 == 0xfd) {
        return nullptr;
    }
    return vf17(message, station->field_38, arg3, arg4, arg5, arg6, arg7);
}

}  // namespace mesh
}  // namespace pia
}  // namespace nn
