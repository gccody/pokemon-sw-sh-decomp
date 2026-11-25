#pragma once
// transport::StationManager (vtable 0x7102460d88, RTTI
// N2nn3pia9transport14StationManagerE), transport::ThreadStreamManager
// (0x7102460e50, N2nn3pia9transport19ThreadStreamManagerE) and the thread
// streams it owns: transport::TransportThreadStream (0x7102461070,
// N2nn3pia9transport21TransportThreadStreamE) and its two derived classes,
// SendThreadStream (0x7102460e88) and ReceiveThreadStream (0x7102460ee8), as
// these members use them. Member names are placeholders (lib/pia/README.md).
// pia/common/Unk_16a90f0.h declares StationManager with fewer members, so a
// file includes one header or the other.
#include "pia/common/Unk_1749070.h"

// The object behind the global Unk_27fc2d8 (no RTTI here) and the leaf getter
// (lib/nx_middleware/leaf) of what it holds: the factory of the streams'
// buffers (placeholder).
struct Unk_174de50;
struct Unk_174e330;
extern Unk_174de50* Unk_27fc2d8;

namespace nn {
namespace pia {
namespace transport {

class Unk_174e330_object {
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
    virtual void vf17();
    virtual void vf18();
    virtual void* vf19();  // the receive side's buffer
    virtual void* vf20();  // the send side's buffer
    virtual void vf21(void* buffer);  // frees vf19's
    virtual void vf22(void* buffer);  // frees vf20's
};

}  // namespace transport
}  // namespace pia
}  // namespace nn

nn::pia::transport::Unk_174e330_object* Unk_174e330_get(const Unk_174e330* self);

namespace nn {
namespace pia {
namespace transport {

// A node of StationManager's list of stations.
struct StationManagerLink {
    StationManagerLink* prev;
    StationManagerLink* next;
};
struct StationManagerNode : StationManagerLink {
    Station* station;
};
PKMN_OFFSET_ASSERT(StationManagerNode, station, 0x10);

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
    virtual Station* vf10(u8 index);
    virtual void vf11();
    virtual void vf12();
    virtual Station* vf13(const Unk_1652c70* address);
    virtual Station* vf14(const Unk_1652c70* address);
    virtual Station* vf15(u64 id);
    virtual Station* vf16(u64 id);
    virtual void vf17();
    virtual void vf18();
    virtual void vf19();
    virtual bool vf20(u8 index);  // a valid station index

    Unk_165e060 Unk_174b020(Unk_165fb30* address, u8 index);  // the address of a station
    u32 Unk_174b0f0(bool withOwn);  // the mask of the connected stations

    u8 _8[0x18 - 0x8];
    StationManagerLink field_18;  // the stations
    u8 _28[0x98 - 0x28];
    Station* field_98;  // this station
};
PKMN_OFFSET_ASSERT(StationManager, field_18, 0x18);
PKMN_OFFSET_ASSERT(StationManager, field_98, 0x98);

class TransportThreadStream {
public:
    TransportThreadStream();
    virtual void vf0() {}
    virtual Unk_165e060 vf1(void* packet) = 0;
    virtual ~TransportThreadStream();

    Unk_165e060 Unk_174f430(const char* name, u32 arg2, u32 arg3, u32 arg4, bool arg5, u32 arg6);
    Unk_165e060 Unk_174f810();
    void Unk_174f970();

    u8 _8[0xc4 - 0x8];
    u32 field_c4;
    u8 _c8[0xd8 - 0xc8];
    void* field_d8;
    u8 _e0[0x4f0 - 0xe0];
};
PKMN_OFFSET_ASSERT(TransportThreadStream, field_c4, 0xc4);
PKMN_OFFSET_ASSERT(TransportThreadStream, field_d8, 0xd8);
PKMN_SIZE_ASSERT(TransportThreadStream, 0x4f0);

class SendThreadStream : public TransportThreadStream {
public:
    SendThreadStream();
    virtual Unk_165e060 vf1(void* packet);
    virtual ~SendThreadStream() {}

    Unk_165e060 Unk_174b620(void* buffer, u32 arg2, u32 arg3, u32 arg4, bool arg5);
    void Unk_174b970();

    void* field_4f0;
    u32 field_4f8;   // packets sent
    u64 field_500;   // bytes sent
};
PKMN_OFFSET_ASSERT(SendThreadStream, field_4f0, 0x4f0);
PKMN_OFFSET_ASSERT(SendThreadStream, field_4f8, 0x4f8);
PKMN_OFFSET_ASSERT(SendThreadStream, field_500, 0x500);
PKMN_SIZE_ASSERT(SendThreadStream, 0x508);

class ReceiveThreadStream : public TransportThreadStream {
public:
    ReceiveThreadStream();
    virtual Unk_165e060 vf1(void* packet);
    virtual ~ReceiveThreadStream();

    Unk_165e060 Unk_174c650(void* buffer, u32 arg2, u32 arg3, u32 arg4, bool arg5);
    void Unk_174c9c0();

    void* field_4f0;
    u32 field_4f8;
    u64 field_500;
};
PKMN_SIZE_ASSERT(ReceiveThreadStream, 0x508);

class ThreadStreamManager {
public:
    ThreadStreamManager(Unk_174e330_object* factory, u32 sendArg2, u32 receiveArg2, u32 sendArg4,
                        u32 receiveArg4, bool arg5);
    virtual ~ThreadStreamManager();
    virtual void vf2();

    Unk_165e060 Unk_174b410();
    void Unk_174b510();
    void Unk_174b550();

    void* field_8;   // the receive stream's buffer
    void* field_10;  // the send stream's buffer
    ReceiveThreadStream* field_18;
    SendThreadStream* field_20;
};
PKMN_SIZE_ASSERT(ThreadStreamManager, 0x28);

}  // namespace transport
}  // namespace pia
}  // namespace nn
