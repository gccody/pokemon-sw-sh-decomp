// Scope: common
// nn::pia::nex::NatProbeData (RTTI N2nn3pia3nex12NatProbeDataE, derived from
// nn::pia::common::ISerializable) and nn::pia::nex::NatProbeRequest (RTTI
// N2nn3pia3nex15NatProbeRequestE), the setter after them and the TU's static
// array of two addresses. Member names are placeholders (vf<slot>,
// lib/pia/README.md); the members tools/leafgen.py matched are in
// lib/nx_middleware/class/nn_pia_nex_NatProbe*.cpp.
//
// NatProbeData's vtable slot 0 is ISerializable's (empty, inline) D2, the one
// Packet::Header's and LanMessage's vtables share, and its D0 is a bare
// `b operator delete`: the base's destructor is inline.
#include <nn/os.h>

#include "pia/common/Unk_165e060.h"

namespace nn {
namespace pia {

// nn::pia::common::InetAddress (RTTI N2nn3pia6common11InetAddressE; the
// placeholder of lib/pia/common/Unk_1749cd0.h): a 16-byte host and a port.
class Unk_1652c70 {
public:
    Unk_1652c70();
    virtual ~Unk_1652c70();

    u8 field_8[0x10];
    u16 field_18;
};
PKMN_OFFSET_ASSERT(Unk_1652c70, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_1652c70, field_18, 0x18);
PKMN_SIZE_ASSERT(Unk_1652c70, 0x20);

namespace common {

// The base of what Pia writes into a buffer and reads back (RTTI
// N2nn3pia6common13ISerializableE). Slots 2 to 4: write, read, size.
class ISerializable {
public:
    virtual ~ISerializable() {}

    virtual Unk_165e060 vf2(u8* buffer, u32* size, u32 bufferSize) const = 0;
    virtual Unk_165e060 vf3(const u8* buffer, u32 bufferSize) = 0;
    virtual u32 vf4() = 0;
};

}  // namespace common

namespace transport {

// RTTI N2nn3pia9transport15StationLocationE: three InetAddresses (0x8, 0x28,
// 0x48) and the fields after them (lib/pia/common/Unk_1749cd0.h's Unk_1749cf0).
class StationLocation {
public:
    StationLocation();
    StationLocation(const StationLocation& other);
    virtual ~StationLocation();

    u8 _8[0x80 - 0x8];
};
PKMN_SIZE_ASSERT(StationLocation, 0x80);

}  // namespace transport
}  // namespace pia
}  // namespace nn

// StationLocation's third address (0x48, a getter tools/leafgen.py matched),
// and whether an address has a host and a port.
struct Unk_1749e40;
struct Unk_1653890_arg0;
const Unk_1653890_arg0* Unk_1749e40_get(const Unk_1749e40* self);
bool Unk_1653890(const Unk_1653890_arg0* self);

namespace nn {
namespace pia {
namespace nex {

// Big-endian writes.
static inline void WriteU32(u8* p, u32 value) {
    p[0] = value >> 24;
    p[1] = value >> 16;
    p[2] = value >> 8;
    p[3] = value;
}

static inline void WriteU64(u8* p, u64 value) {
    p[0] = value >> 56;
    p[1] = value >> 48;
    p[2] = value >> 40;
    p[3] = value >> 32;
    p[4] = value >> 24;
    p[5] = value >> 16;
    p[6] = value >> 8;
    p[7] = value;
}

// The data of a NAT probe, 0x14 bytes in big-endian order.
class NatProbeData : public common::ISerializable {
public:
    NatProbeData();

    Unk_165e060 vf2(u8* buffer, u32* size, u32 bufferSize) const override;
    Unk_165e060 vf3(const u8* buffer, u32 bufferSize) override;
    u32 vf4() override;  // 0x14

    u32 field_8;
    u8 field_c;
    u8 field_d;
    u8 field_e;
    u8 field_f;
    u64 field_10;
    u32 field_18;
};
PKMN_OFFSET_ASSERT(NatProbeData, field_8, 0x8);
PKMN_OFFSET_ASSERT(NatProbeData, field_c, 0xc);
PKMN_OFFSET_ASSERT(NatProbeData, field_10, 0x10);
PKMN_OFFSET_ASSERT(NatProbeData, field_18, 0x18);
PKMN_SIZE_ASSERT(NatProbeData, 0x20);

// 0x71016d26c0
NatProbeData::NatProbeData() : field_8(0), field_c(0), field_10(0), field_18(0) {}

// 0x71016d26f0
Unk_165e060 NatProbeData::vf2(u8* buffer, u32* size, u32 bufferSize) const {
    if (buffer == nullptr || size == nullptr) {
        return Unk_165e060Value<0x10c07>();
    }
    if (bufferSize < 0x14) {
        return Unk_165e060Value<0x10c07>();
    }
    WriteU32(&buffer[0x0], field_8);
    buffer[0x4] = field_c;
    buffer[0x5] = field_d;
    buffer[0x6] = field_e;
    buffer[0x7] = field_f;
    WriteU64(&buffer[0x8], field_10);
    WriteU32(&buffer[0x10], field_18);
    *size = 0x14;
    return Unk_165e060Value<0>();
}

// 0x71016d2810
Unk_165e060 NatProbeData::vf3(const u8* buffer, u32 bufferSize) {
    if (buffer == nullptr) {
        return Unk_165e060Value<0x10c07>();
    }
    if (bufferSize < 0x14) {
        return Unk_165e060Value<0x10c07>();
    }
    field_8 = __builtin_bswap32(*reinterpret_cast<const u32*>(&buffer[0x0]));
    field_c = buffer[0x4];
    field_d = buffer[0x5];
    field_e = buffer[0x6];
    field_f = buffer[0x7];
    field_10 = __builtin_bswap64(*reinterpret_cast<const u64*>(&buffer[0x8]));
    field_18 = __builtin_bswap32(*reinterpret_cast<const u32*>(&buffer[0x10]));
    return Unk_165e060Value<0>();
}

// A request to probe a station's NAT: its location, two flags and two words.
class NatProbeRequest {
public:
    NatProbeRequest();
    explicit NatProbeRequest(const transport::StationLocation& location);
    NatProbeRequest(const transport::StationLocation& location, bool arg2, bool arg3, u64 arg4);
    virtual ~NatProbeRequest();

    virtual void vf2();

    transport::StationLocation field_8;
    bool field_88;
    bool field_89;
    u64 field_90;
    u64 field_98;
};
PKMN_OFFSET_ASSERT(NatProbeRequest, field_8, 0x8);
PKMN_OFFSET_ASSERT(NatProbeRequest, field_88, 0x88);
PKMN_OFFSET_ASSERT(NatProbeRequest, field_89, 0x89);
PKMN_OFFSET_ASSERT(NatProbeRequest, field_90, 0x90);
PKMN_OFFSET_ASSERT(NatProbeRequest, field_98, 0x98);
PKMN_SIZE_ASSERT(NatProbeRequest, 0xa0);

// 0x71016d28f0
NatProbeRequest::NatProbeRequest(const transport::StationLocation& location, bool arg2, bool arg3, u64 arg4)
    : field_8(location), field_88(arg2), field_89(arg3), field_90(0), field_98(arg4) {}

// 0x71016d2940
NatProbeRequest::NatProbeRequest(const transport::StationLocation& location)
    : field_8(location), field_88(false), field_90(0), field_98(0) {
    field_89 = Unk_1653890(Unk_1749e40_get(reinterpret_cast<const Unk_1749e40*>(&location)));
}

// 0x71016d29a0
NatProbeRequest::NatProbeRequest() : field_88(false), field_89(false), field_90(0), field_98(0) {}

// 0x71016d29f0 (and 0x71016d2a10, deleting)
NatProbeRequest::~NatProbeRequest() {}

// What the setter below changes (RTTI N2nn3pia3nex9NexFacadeE).
class NexFacade {
public:
    Unk_165e060 SetRelayServiceEnabled(bool enabled);

    u8 _0[0xb0];
    bool field_b0;  // set: too late to change
    u8 _b1;
    bool field_b2;
};
PKMN_OFFSET_ASSERT(NexFacade, field_b0, 0xb0);
PKMN_OFFSET_ASSERT(NexFacade, field_b2, 0xb2);

// 0x71016d2a50
Unk_165e060 NexFacade::SetRelayServiceEnabled(bool enabled) {
    nn::util::ReferSymbol("SDK Private+Nintendo+nex::NexFacade::SetRelayServiceEnabled");
    if (field_b0) {
        return Unk_165e060Value<0x10c08>();
    }
    field_b2 = enabled;
    return Unk_165e060Value<0>();
}

}  // namespace nex
}  // namespace pia
}  // namespace nn

// Two addresses (placeholder: what they are isn't known). 0x71016d2b10 is the
// TU's static initialiser, 0x71016d2ae0 their array destructor.
nn::pia::Unk_1652c70 Unk_27fb438[2];
