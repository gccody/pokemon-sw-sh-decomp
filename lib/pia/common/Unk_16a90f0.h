#pragma once
// mesh::MeshPacketReader (vtable 0x710245bb28, RTTI
// N2nn3pia4mesh16MeshPacketReaderE) and mesh::MeshPacketWriter (vtable
// 0x710245bc28, RTTI N2nn3pia4mesh16MeshPacketWriterE), with their bases
// transport::PacketReader (vtable 0x7102460518) and transport::PacketWriter
// (vtable 0x71024606a8), both transport::PacketHandler (vtable 0x7102460618),
// as far as the mesh classes' members use them. src/unsorted/ctor names the
// mesh classes after their vtables (Unk_245bb18, Unk_245bc18). Member names
// are placeholders (lib/pia/README.md): vf<slot> for virtual functions.
#include "pia/common/Unk_1749070.h"

// A received packet's buffer (placeholder, after PacketReader::vf22's
// parameter): the sending station's kind and sequence id, the size of the
// data and the sender's address.
struct Unk_173ad90_arg1 {
    u8 _0[0xd];
    u8 field_d;   // 1: from this station
    u16 field_e;  // sequence id
    u8 _10[0x5e8 - 0x10];
    u32 field_5e8;  // bytes received (0x20 of them a header)
    u8 _5ec[0x628 - 0x5ec];
    nn::pia::Unk_165fb30 field_628;  // the sender
    bool field_650;                  // in use
};
PKMN_OFFSET_ASSERT(Unk_173ad90_arg1, field_d, 0xd);
PKMN_OFFSET_ASSERT(Unk_173ad90_arg1, field_e, 0xe);
PKMN_OFFSET_ASSERT(Unk_173ad90_arg1, field_5e8, 0x5e8);
PKMN_OFFSET_ASSERT(Unk_173ad90_arg1, field_628, 0x628);
PKMN_OFFSET_ASSERT(Unk_173ad90_arg1, field_650, 0x650);
PKMN_SIZE_ASSERT(Unk_173ad90_arg1, 0x658);

// The ring of received buffers PacketReader reads (placeholder, its vf15's
// second parameter): the buffers and their count, and the indices of the
// first and the next free one.
struct Unk_16a9220_arg2 {
    struct Buffers {
        s32 count;
        Unk_173ad90_arg1* entries;
    };

    Buffers* field_0;
    s32 field_8;
    s32 field_c;
};
PKMN_OFFSET_ASSERT(Unk_16a9220_arg2, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_16a9220_arg2, field_c, 0xc);

// A message PacketReader parses out of a buffer (placeholder, after the
// getter of its destination, Unk_173e5e0_get in lib/nx_middleware/leaf):
// its size, flags (bits 0-4 add header fields), its destination (a station
// mask in the low half when bit 0 of field_39 is set) and its source.
struct Unk_173e5e0 {
    u32 field_0;
    u64 field_8;
    u8 _10[0x38 - 0x10];
    u8 field_38;
    u8 field_39;
    u64 field_40;
    u64 field_48;
};
PKMN_OFFSET_ASSERT(Unk_173e5e0, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_173e5e0, field_38, 0x38);
PKMN_OFFSET_ASSERT(Unk_173e5e0, field_39, 0x39);
PKMN_OFFSET_ASSERT(Unk_173e5e0, field_40, 0x40);
PKMN_OFFSET_ASSERT(Unk_173e5e0, field_48, 0x48);

u64 Unk_173e5e0_get(const Unk_173e5e0* self);
void Unk_173e2c0(Unk_173e5e0* self, const Unk_173ad90_arg1* buffer, u32 offset);

// Members of the mesh classes (placeholders, after the leaf members
// tools/leafgen.py matched: Unk_17399e0_set, Unk_1739a90_set).
struct Unk_17399e0 {
    bool field_0;
};
struct Unk_1739a90 {
    u32 field_0;
    u32 field_4;
};
struct Unk_173eb50 {
    u8 _0[0xbb0];
    u64 field_bb0;
};
PKMN_OFFSET_ASSERT(Unk_173eb50, field_bb0, 0xbb0);

struct Unk_16a9320_arg1;  // what PacketHandler::vf8 and vf9 are given
void Unk_17399f0_update(u64 /*unused*/);
void Unk_1739a00(Unk_17399e0* self, u32 stations, Unk_16a9320_arg1* arg);
u32 Unk_1739b30(Unk_1739a90* self, u32 stations, Unk_16a9320_arg1* arg);
void Unk_173eb50_set(Unk_173eb50* self, u64 value);

// What the mesh writer sends (placeholder): its first word is a header.
struct Unk_16a9e40_arg1 {
    u32 field_0;
    u8 _4[0x10 - 0x4];
};
struct Unk_16a9e40_message;

// The object behind the global Unk_27fb2d8's field_368 (placeholder).
struct Unk_16c0ab0_arg0;

namespace nn {
namespace pia {

namespace mesh {
class MeshPacketWriter;
}  // namespace mesh

namespace transport {

class StationManager {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual Station* vf7(u64 id);
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual Station* vf11(const Unk_165fb30* address);
    virtual void vf12();
    virtual void vf13();
    virtual void vf14();
    virtual Station* vf15(u64 id);

    u32 Unk_174b0f0(bool withOwn);  // the mask of the connected stations

    u8 _8[0x98 - 0x8];
    Station* field_98;  // the host
    u8 field_a0;        // this station's index
};
PKMN_OFFSET_ASSERT(StationManager, field_98, 0x98);
PKMN_OFFSET_ASSERT(StationManager, field_a0, 0xa0);

class StationLocation {
public:
    StationLocation();
    virtual ~StationLocation();

    u8 _8[0x80 - 0x8];
};
PKMN_SIZE_ASSERT(StationLocation, 0x80);

// What Unk_174de60_get gives (placeholder): slot 5 finds a station's location.
class Unk_174de60_object {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual Unk_165e060 vf5(Station* station, StationLocation* location);
};

class PacketHandler {
public:
    virtual ~PacketHandler();
    virtual Unk_165e060 vf2();
    virtual void vf3();
    virtual Unk_165e060 vf4();
    virtual void vf5();
    virtual u64 vf6(const Unk_165fb30* address) = 0;
    virtual u8 vf7(const Unk_165fb30* address) = 0;
    virtual void vf8(Unk_16a9320_arg1* arg) = 0;
    virtual void vf9(Unk_16a9320_arg1* arg) = 0;
    virtual void vf10(u64 value);
    virtual void vf11();
    virtual bool vf12();
    virtual bool vf13();

    u64 field_8;
    u8 _10[0x2c - 0x10];
    bool field_2c;
    bool field_2d;
};
PKMN_OFFSET_ASSERT(PacketHandler, field_8, 0x8);
PKMN_OFFSET_ASSERT(PacketHandler, field_2c, 0x2c);

class PacketReader : public PacketHandler {
public:
    ~PacketReader() override;
    void vf3() override;
    void vf5() override;
    void vf8(Unk_16a9320_arg1* arg) override;
    void vf9(Unk_16a9320_arg1* arg) override;
    virtual Unk_165e060 vf14(bool arg1, bool arg2, u32 arg3);
    virtual Unk_165e060 vf15(void* arg1, Unk_16a9220_arg2* buffers, void* arg3, void* arg4);
    virtual void vf16();
    virtual bool vf17(u64 id) = 0;
    virtual void vf18() = 0;
    virtual void vf19();
    virtual void vf20();
    virtual void vf21();
    virtual u32 vf22(const Unk_173ad90_arg1* buffer);
    virtual bool vf23(const Unk_173e5e0* message);
    virtual bool vf24(const Unk_173e5e0* message);
    virtual bool vf25(const Unk_165fb30* address);

    void* field_30;
    Unk_16a9220_arg2* field_38;
    Unk_173e5e0 field_40;
    u8 _90[0x108 - 0x90];
};
PKMN_OFFSET_ASSERT(PacketReader, field_30, 0x30);
PKMN_OFFSET_ASSERT(PacketReader, field_38, 0x38);
PKMN_OFFSET_ASSERT(PacketReader, field_40, 0x40);
PKMN_SIZE_ASSERT(PacketReader, 0x108);

class PacketWriter : public PacketHandler {
public:
    ~PacketWriter() override;
    void vf3() override;
    void vf5() override;
    void vf8(Unk_16a9320_arg1* arg) override;
    void vf9(Unk_16a9320_arg1* arg) override;
    virtual Unk_165e060 vf14(bool arg1, bool arg2, u32 arg3, u32 arg4);
    virtual Unk_165e060 vf15(void* arg1, void* arg2, void* arg3);
    virtual void vf16();
    virtual Unk_16a9e40_message* vf17(Unk_16a9e40_arg1* message, u8 station, u32 arg3, bool arg4, bool arg5,
                                      bool arg6, bool arg7);
    virtual Unk_16a9e40_message* vf18(Unk_16a9e40_arg1* message, u64 id, u32 arg3, bool arg4, bool arg5, bool arg6,
                                      bool arg7);
    virtual void vf19();
    virtual void vf20();
    virtual void vf21(Unk_16a9320_arg1* arg) = 0;
    virtual Unk_16a9e40_message* vf22(Unk_16a9e40_arg1* message, u8 station, u32 arg3, bool arg4, bool arg5,
                                      bool arg6, bool arg7) = 0;
    virtual Unk_16a9e40_message* vf23(Unk_16a9e40_arg1* message, u32 arg3, bool arg4, bool arg5, bool arg6,
                                      bool arg7) = 0;
    virtual Unk_16a9e40_message* vf24(Unk_16a9e40_arg1* message, u32 stations, u32 arg3, bool arg4, bool arg5,
                                      bool arg6, bool arg7) = 0;

    Unk_165e060 Unk_173caa0();

    void* field_30;
    Unk_173eb50 field_38;
    u8 _bf0[0xfec - 0xbf0];
    Unk_1739a90 field_fec;
    u8 _ff4[0x1038 - 0xff4];
};
PKMN_OFFSET_ASSERT(PacketWriter, field_38, 0x38);
PKMN_OFFSET_ASSERT(PacketWriter, field_fec, 0xfec);
PKMN_SIZE_ASSERT(PacketWriter, 0x1038);

}  // namespace transport

namespace mesh {

class MeshPacketReader : public transport::PacketReader {
public:
    ~MeshPacketReader() override;
    Unk_165e060 vf2() override;
    void vf3() override;
    Unk_165e060 vf4() override;
    void vf5() override;
    u64 vf6(const Unk_165fb30* address) override;
    u8 vf7(const Unk_165fb30* address) override;
    void vf8(Unk_16a9320_arg1* arg) override;
    void vf9(Unk_16a9320_arg1* arg) override;
    void vf11() override;
    Unk_165e060 vf14(bool arg1, bool arg2, u32 arg3) override;
    Unk_165e060 vf15(void* arg1, Unk_16a9220_arg2* buffers, void* arg3, void* arg4) override;
    void vf16() override;
    bool vf17(u64 id) override;
    void vf18() override;
    u32 vf22(const Unk_173ad90_arg1* buffer) override;
    bool vf23(const Unk_173e5e0* message) override;
    bool vf24(const Unk_173e5e0* message) override;
    bool vf25(const Unk_165fb30* address) override;

    u8 _108[0x10c - 0x108];
    u8 field_10c;   // this station's index (0xfd: not known yet)
    u32 field_110;  // its bit
    Unk_17399e0 field_114;
};
PKMN_OFFSET_ASSERT(MeshPacketReader, field_10c, 0x10c);
PKMN_OFFSET_ASSERT(MeshPacketReader, field_110, 0x110);
PKMN_OFFSET_ASSERT(MeshPacketReader, field_114, 0x114);

class MeshPacketWriter : public transport::PacketWriter {
public:
    ~MeshPacketWriter() override;
    Unk_165e060 vf2() override;
    void vf3() override;
    Unk_165e060 vf4() override;
    void vf5() override;
    u64 vf6(const Unk_165fb30* address) override;
    u8 vf7(const Unk_165fb30* address) override;
    void vf8(Unk_16a9320_arg1* arg) override;
    void vf9(Unk_16a9320_arg1* arg) override;
    void vf11() override;
    Unk_165e060 vf14(bool arg1, bool arg2, u32 arg3, u32 arg4) override;
    Unk_165e060 vf15(void* arg1, void* arg2, void* arg3) override;
    Unk_16a9e40_message* vf17(Unk_16a9e40_arg1* message, u8 station, u32 arg3, bool arg4, bool arg5, bool arg6,
                              bool arg7) override;
    Unk_16a9e40_message* vf18(Unk_16a9e40_arg1* message, u64 id, u32 arg3, bool arg4, bool arg5, bool arg6,
                              bool arg7) override;
    void vf21(Unk_16a9320_arg1* arg) override;
    Unk_16a9e40_message* vf22(Unk_16a9e40_arg1* message, u8 station, u32 arg3, bool arg4, bool arg5, bool arg6,
                              bool arg7) override;
    Unk_16a9e40_message* vf23(Unk_16a9e40_arg1* message, u32 arg3, bool arg4, bool arg5, bool arg6,
                              bool arg7) override;
    Unk_16a9e40_message* vf24(Unk_16a9e40_arg1* message, u32 stations, u32 arg3, bool arg4, bool arg5, bool arg6,
                              bool arg7) override;

    u8 field_1038;   // this station's index (0xfd: not known yet)
    u32 field_103c;  // its bit
    u32 field_1040;  // stations waiting for an acknowledgement
    Unk_16c0ab0_arg0* field_1048;
};
PKMN_OFFSET_ASSERT(MeshPacketWriter, field_1038, 0x1038);
PKMN_OFFSET_ASSERT(MeshPacketWriter, field_103c, 0x103c);
PKMN_OFFSET_ASSERT(MeshPacketWriter, field_1040, 0x1040);
PKMN_OFFSET_ASSERT(MeshPacketWriter, field_1048, 0x1048);

}  // namespace mesh
}  // namespace pia
}  // namespace nn

// The globals behind Pia's transport and mesh objects, and the leaf getters
// (lib/nx_middleware/leaf) of what they hold.
struct Unk_174de50;
struct Unk_174de60;
struct Unk_16a8380;
struct Unk_16a8390;
struct Unk_16c16d0_arg0;
extern Unk_174de50* Unk_27fc2d8;
extern Unk_16a8390* Unk_27fb2d8;
nn::pia::transport::StationManager* Unk_174de50_get(const Unk_174de50* self);
nn::pia::transport::Unk_174de60_object* Unk_174de60_get(const Unk_174de60* self);
Unk_16c0ab0_arg0* Unk_16a8380_get(const Unk_16a8380* self);
Unk_16c16d0_arg0* Unk_16a8390_get(const Unk_16a8390* self);

nn::pia::Unk_165e060 Unk_16c0ab0(Unk_16c0ab0_arg0* self, nn::pia::mesh::MeshPacketWriter* writer);
void Unk_16c0b10(Unk_16c0ab0_arg0* self);
nn::pia::Unk_165e060 Unk_16c0b30(Unk_16c0ab0_arg0* self);
