#pragma once
// transport::RttProtocol (vtable 0x7102460b38, RTTI
// N2nn3pia9transport11RttProtocolE, derived from transport::Protocol, RTTI
// N2nn3pia9transport8ProtocolE, vtable 0x7102460788) and the data it sends,
// RttProtocol::Data (vtable 0x7102460bd8, RTTI
// N2nn3pia9transport11RttProtocol4DataE, derived from common::ISerializable),
// as these members use them. Member names are placeholders
// (lib/pia/README.md). pia/common/Unk_1749070.h declares RttProtocol without
// its base and fields, so a file includes one header or the other; the
// StationManager, Station and PacketWriter here are views of the ones in
// pia/common/Unk_174aea0.h and pia/common/Unk_16a90f0.h.
#include "pia/common/Unk_165fb10.h"
#include "pia/common/Unk_1748ae0.h"

// What the protocols send (an opaque message of
// pia/common/Unk_16a90f0.h's PacketWriter) and the setter of its payload.
struct Unk_16a9e40_arg1 {
    explicit Unk_16a9e40_arg1(u32 protocol) : field_0(protocol) {}

    u32 field_0;  // the protocol
    u8 _4[0x10 - 0x4];
};
PKMN_SIZE_ASSERT(Unk_16a9e40_arg1, 0x10);
struct Unk_16a9e40_message;
void Unk_173ef10(Unk_16a9e40_message* message, const u8* payload);

namespace nn {
namespace pia {

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

class Station {
public:
    virtual ~Station();

    u8 _8[0x38 - 0x8];
    u8 field_38;  // station index
    u64 field_40;  // station id
};
PKMN_OFFSET_ASSERT(Station, field_38, 0x38);
PKMN_OFFSET_ASSERT(Station, field_40, 0x40);

class StationManager {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual Station* vf11(const Unk_165fb30* address);
};

class PacketWriter {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
    virtual void vf14();
    virtual void vf15();
    virtual void vf16();
    virtual Unk_16a9e40_message* vf17(const Unk_16a9e40_arg1& message, u8 station, u32 arg3, bool arg4, bool arg5,
                                      bool arg6, bool arg7);

    Unk_165e060 Unk_173caa0();
};

// What a protocol is told about a station (Protocol::vf10's argument).
struct Unk_173d270_arg1 {
    u32 field_0;          // 0, 1 or 2
    Unk_165fb30 field_8;  // the station's address
    u64 field_30;
};
PKMN_OFFSET_ASSERT(Unk_173d270_arg1, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_173d270_arg1, field_30, 0x30);

class Protocol {
public:
    virtual ~Protocol();
    virtual void vf2();
    virtual u32 vf3();  // field_28
    virtual u32 vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual Unk_165e060 vf10(const Unk_173d270_arg1* event);
    virtual u32 vf11();
    virtual u64 vf12();  // field_30
    virtual void vf13(u64 value);

    PacketWriter* field_8;
    u8 _10[0x28 - 0x10];
    u32 field_28;
    u64 field_30;
    u8 field_38;  // this station's index (0xfd: none)
    u64 field_40;
};
PKMN_OFFSET_ASSERT(Protocol, field_8, 0x8);
PKMN_OFFSET_ASSERT(Protocol, field_28, 0x28);
PKMN_OFFSET_ASSERT(Protocol, field_30, 0x30);
PKMN_OFFSET_ASSERT(Protocol, field_38, 0x38);
PKMN_OFFSET_ASSERT(Protocol, field_40, 0x40);
PKMN_SIZE_ASSERT(Protocol, 0x48);

// Measures the round-trip time to each station: one Unk_1748ab0 per station
// index (field_58, field_60 of them).
class RttProtocol : public Protocol {
public:
    // The 16 bytes it sends, in big-endian order.
    class Data : public common::ISerializable {
    public:
        Unk_165e060 vf2(u8* buffer, u32* size, u32 bufferSize) const override;
        Unk_165e060 vf3(const u8* buffer, u32 bufferSize) override;
        u32 vf4() override;  // 0x10

        u32 field_8;
        u32 field_c;
        u64 field_10;
    };

    ~RttProtocol() override;
    u32 vf4() override;  // 0x58
    Unk_165e060 vf10(const Unk_173d270_arg1* event) override;

    void Unk_17483b0(u8 index);
    Unk_165e060 Unk_1748690(u8 index, const common::ISerializable* data);
    s32 Unk_1748810(u8 index);
    s32 Unk_1748850(u8 index, u32 count);
    void Unk_17488d0(u8 index);
    s32 Unk_1748900(u8 index);
    s32 Unk_1748930(u8 index);

    u8 field_48[0x10];  // a Data, written
    Unk_1748ab0* field_58;
    u8 field_60;
};
PKMN_OFFSET_ASSERT(RttProtocol::Data, field_8, 0x8);
PKMN_OFFSET_ASSERT(RttProtocol::Data, field_c, 0xc);
PKMN_OFFSET_ASSERT(RttProtocol::Data, field_10, 0x10);
PKMN_SIZE_ASSERT(RttProtocol::Data, 0x18);
PKMN_OFFSET_ASSERT(RttProtocol, field_48, 0x48);
PKMN_OFFSET_ASSERT(RttProtocol, field_58, 0x58);
PKMN_OFFSET_ASSERT(RttProtocol, field_60, 0x60);

}  // namespace transport
}  // namespace pia
}  // namespace nn

// The object behind the global Unk_27fc2d8 and the leaf getter
// (lib/nx_middleware/leaf) of its station manager.
struct Unk_174de50;
extern Unk_174de50* Unk_27fc2d8;
nn::pia::transport::StationManager* Unk_174de50_get(const Unk_174de50* self);

// The count of samples of a station's entry (0: no such station).
s32 Unk_17488a0(void* self, u8 index);
