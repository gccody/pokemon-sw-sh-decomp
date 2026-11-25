// Scope: common
// transport::RttProtocol's members (lib/pia/common/Unk_17484c0.h): its
// vf10, the members that take a station index, RttProtocol::Data's
// serializers and deleting destructor, and the round-trip time entry's
// constructor (lib/pia/common/Unk_1748ae0.h). RttProtocol's vf2 and vf4 and
// Data's vf4 are in lib/nx_middleware/class, 0x7101748960 in
// lib/nx_middleware/leaf/Unk_1721740.cpp.
#include "pia/common/Unk_17484c0.h"

namespace {

// Big-endian writes.
inline void WriteU32(u8* p, u32 value) {
    p[0] = value >> 24;
    p[1] = value >> 16;
    p[2] = value >> 8;
    p[3] = value;
}

inline void WriteU64(u8* p, u64 value) {
    p[0] = value >> 56;
    p[1] = value >> 48;
    p[2] = value >> 40;
    p[3] = value >> 32;
    p[4] = value >> 24;
    p[5] = value >> 16;
    p[6] = value >> 8;
    p[7] = value;
}

}  // namespace

namespace nn {
namespace pia {
namespace transport {

// 0x71017484c0
Unk_165e060 RttProtocol::vf10(const Unk_173d270_arg1* event) {
    Protocol::vf10(event);
    Station* station = Unk_174de50_get(Unk_27fc2d8)->vf11(&event->field_8);
    if (field_38 == 0xfd) {
        return Unk_165e060Value<0>();
    }
    if (vf12() == station->field_40) {
        return Unk_165e060Value<0>();
    }
    switch (event->field_0) {
    case 0:
        Unk_17483b0(station->field_38);
        break;
    case 1:
        if (station->field_38 < field_60) {
            field_58[station->field_38].Unk_1748da0();
        }
        break;
    case 2:
        break;
    default:
        return Unk_165e060Value<0x10c07>();
    }
    return Unk_165e060Value<0>();
}

// 0x71017485f0
Unk_165e060 RttProtocol::Data::vf3(const u8* buffer, u32 bufferSize) {
    if (buffer == nullptr) {
        return Unk_165e060Value<0x10c07>();
    }
    if (bufferSize < 0x10) {
        return Unk_165e060Value<0x10c07>();
    }
    field_8 = __builtin_bswap32(*reinterpret_cast<const u32*>(&buffer[0x0]));
    field_c = __builtin_bswap32(*reinterpret_cast<const u32*>(&buffer[0x4]));
    field_10 = __builtin_bswap64(*reinterpret_cast<const u64*>(&buffer[0x8]));
    return Unk_165e060Value<0>();
}

// 0x7101748690
Unk_165e060 RttProtocol::Unk_1748690(u8 index, const common::ISerializable* data) {
    if (field_38 == index) {
        return Unk_165e060Value<0x10c08>();
    }
    u32 size = 0;
    Unk_165e060 result = data->vf2(field_48, &size, sizeof(field_48));
    if (result.m_Value != 0) {
        return Unk_165e060Value<0x10c08>();
    }
    PacketWriter* writer = field_8;
    Unk_16a9e40_message* packet = writer->vf17(Unk_16a9e40_arg1(vf3()), index, size, false, false, false, true);
    if (packet == nullptr) {
        return Unk_165e060Value<0x2c0a>();
    }
    Unk_173ef10(packet, field_48);
    result = writer->Unk_173caa0();
    if (result.m_Value != 0) {
        return result;
    }
    return Unk_165e060Value<0>();
}

// 0x7101748810
// NON_MATCHING: the original compares a zero-extended copy of the index with
// the count (and w8, w1, #0xff; cmp w8, w9), which a u64 parameter narrowed
// to u8 gives; with the u8 parameter its name has, clang folds the extension
// into the compare (cmp w8, w1, uxtb).
s32 RttProtocol::Unk_1748810(u8 index) {
    if (field_38 == 0xfd || field_38 == index || index >= field_60) {
        return -1;
    }
    return field_58[index].Unk_1748af0();
}

// 0x7101748850
// NON_MATCHING: the original compares a zero-extended copy of the index with
// the count (and w8, w1, #0xff; cmp w8, w9), which a u64 parameter narrowed
// to u8 gives; with the u8 parameter its name has, clang folds the extension
// into the compare (cmp w8, w1, uxtb).
s32 RttProtocol::Unk_1748850(u8 index, u32 count) {
    if (field_38 == 0xfd || field_38 == index || index >= field_60) {
        return -1;
    }
    return field_58[index].Unk_1748c00(count);
}

}  // namespace transport
}  // namespace pia
}  // namespace nn

// 0x71017488a0
// NON_MATCHING: the original compares a zero-extended copy of the index with
// the count (and w8, w1, #0xff; cmp w8, w9), which a u64 parameter narrowed
// to u8 gives; with the u8 parameter its name has, clang folds the extension
// into the compare (cmp w8, w1, uxtb).
s32 Unk_17488a0(void* self, u8 index) {
    nn::pia::transport::RttProtocol* rtt = static_cast<nn::pia::transport::RttProtocol*>(self);
    if (index >= rtt->field_60) {
        return 0;
    }
    return rtt->field_58[index].field_1c.count;
}

namespace nn {
namespace pia {
namespace transport {

// 0x71017488d0
// NON_MATCHING: the original compares a zero-extended copy of the index with
// the count (and w8, w1, #0xff; cmp w8, w9), which a u64 parameter narrowed
// to u8 gives; with the u8 parameter its name has, clang folds the extension
// into the compare (cmp w8, w1, uxtb).
void RttProtocol::Unk_17488d0(u8 index) {
    if (index < field_60) {
        Unk_1748d10_set(reinterpret_cast<Unk_1748d10*>(&field_58[index]));
    }
}

// 0x7101748900
// NON_MATCHING: the original compares a zero-extended copy of the index with
// the count (and w8, w1, #0xff; cmp w8, w9), which a u64 parameter narrowed
// to u8 gives; with the u8 parameter its name has, clang folds the extension
// into the compare (cmp w8, w1, uxtb).
s32 RttProtocol::Unk_1748900(u8 index) {
    if (index >= field_60) {
        return -1;
    }
    return Unk_1748d20_get(reinterpret_cast<const Unk_1748d20*>(&field_58[index]));
}

// 0x7101748930
// NON_MATCHING: the original compares a zero-extended copy of the index with
// the count (and w8, w1, #0xff; cmp w8, w9), which a u64 parameter narrowed
// to u8 gives; with the u8 parameter its name has, clang folds the extension
// into the compare (cmp w8, w1, uxtb).
s32 RttProtocol::Unk_1748930(u8 index) {
    if (index >= field_60) {
        return -1;
    }
    return Unk_1748d40_get(reinterpret_cast<const Unk_1748d40*>(&field_58[index]));
}

// 0x7101748990: Data's deleting destructor (its D2 is ISerializable's).

// 0x71017489a0
Unk_165e060 RttProtocol::Data::vf2(u8* buffer, u32* size, u32 bufferSize) const {
    if (buffer == nullptr || size == nullptr) {
        return Unk_165e060Value<0x10c07>();
    }
    if (bufferSize < 0x10) {
        return Unk_165e060Value<0x10c07>();
    }
    WriteU32(&buffer[0x0], field_8);
    WriteU32(&buffer[0x4], field_c);
    WriteU64(&buffer[0x8], field_10);
    *size = 0x10;
    return Unk_165e060Value<0>();
}

}  // namespace transport
}  // namespace pia
}  // namespace nn

// 0x7101748ab0
Unk_1748ab0::Unk_1748ab0() {
    field_0 = false;
    Reset();
}
