#pragma once
// The local network's session jobs (lib/pia/common/Unk_168ef00.cpp), each
// derived from one of the session jobs:
//
// - local::LocalMatchJoinSessionJob (RTTI N2nn3pia5local24LocalMatchJoinSessionJobE,
//   vtable 0x710245a748), from session::JoinSessionJob;
// - local::LocalMatchLeaveSessionJob (N2nn3pia5local25LocalMatchLeaveSessionJobE,
//   vtable 0x710245a808), from session::LeaveSessionJob;
// - local::LocalMatchCreateSessionJob (N2nn3pia5local26LocalMatchCreateSessionJobE,
//   vtable 0x710245a8b8), from session::CreateSessionJob.
//
// The base classes keep the placeholder names their constructors have (after
// their vtables, Unk_<vtable start>), as in lib/pia/common/Unk_168f910.h. The
// steps' names are the strings stored with them ("Class::Function"); other
// names are placeholders (lib/pia/README.md).
#include "pia/common/Unk_16998e0.h"

// One of the networks the object behind Unk_27fc0a8 runs (placeholder; the
// slots lib/pia/common/Unk_168f910.h declares, and the ones these jobs call).
class Unk_27fc0a8_network {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual nn::pia::Unk_165e060 vf8(Unk_1655080* context);  // creates it
    virtual bool vf9(u32* value);                            // whether it's created
    virtual void vf10();
    virtual void vf11();
    virtual nn::pia::Unk_165e060 vf12(Unk_1655080* context, u32 value);
    virtual bool vf13();
    virtual nn::pia::Unk_165e060 vf14(Unk_1655080* context, u32 value);  // destroys it
    virtual bool vf15();                                                  // whether it's destroyed
    virtual void vf16();
    virtual void vf17();
    virtual void vf18();
    virtual void vf19();
    virtual void vf20();
    virtual void vf21();
    virtual void vf22();
    virtual void vf23();
    virtual void vf24();
    virtual void vf25();
    virtual void vf26();
    virtual void vf27();
    virtual void vf28();
    virtual void vf29();
    virtual void vf30();
    virtual void vf31();
    virtual void vf32();
    virtual void vf33();
    virtual void vf34();
    virtual void vf35();
    virtual void vf36();
    virtual void vf37();
    virtual void vf38();
    virtual void vf39();
    virtual void vf40();
    virtual void vf41();
    virtual void vf42();
    virtual void vf43();
    virtual void vf44();
    virtual void vf45();
    virtual void vf46();
};

// The object behind the global Unk_27fc0a8 (as lib/pia/common/Unk_168f910.h
// declares it): its networks, the current one's index and values per network.
struct Unk_27fc0a8_type {
    u8 _0[0x162];
    u8 field_162;
    Unk_27fc0a8_network* field_168[3];
    u32 field_180[3];
};
PKMN_OFFSET_ASSERT(Unk_27fc0a8_type, field_162, 0x162);
PKMN_OFFSET_ASSERT(Unk_27fc0a8_type, field_168, 0x168);
PKMN_OFFSET_ASSERT(Unk_27fc0a8_type, field_180, 0x180);

extern Unk_27fc0a8_type* Unk_27fc0a8;

void Unk_172e100(Unk_27fc0a8_type* self, u32 value);  // sets the current network's value
void Unk_172e0d0(Unk_27fc0a8_type* self, u32 value);  // sets another value of the current network
void Unk_172e150(Unk_27fc0a8_type* self, u16 value);  // sets a 16-bit value of the current network

// What a LocalMatchCreateSessionJob is created with (placeholder).
class Unk_168f1e0_arg1 {
public:
    bool Unk_1689af0();
    bool Unk_1689b10();
    nn::pia::Unk_165e060 Unk_168a020();
    void Unk_168a370();
};

// The setting a LocalMatchCreateSessionJob creates the session with
// (lib/nx_middleware/leaf/Unk_1721740.cpp).
struct Unk_1723380;
u16 Unk_1723380_get(const Unk_1723380* self);

// session::JoinSessionJob (RTTI N2nn3pia7session14JoinSessionJobE, vtable 0x710245f3f8).
class Unk_245f3e8 : public nn::pia::common::StepSequenceJob {
public:
    Unk_245f3e8();
    ~Unk_245f3e8() override;

    void vf5() override;
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12() = 0;
    virtual void vf13();
    virtual void vf14();
    virtual nn::pia::common::Unk_165bb20_result vf15(const nn::pia::Unk_165e060& result) = 0;
    virtual nn::pia::common::Unk_165bb20_result vf16() = 0;
    virtual nn::pia::common::Unk_165bb20_result vf17() = 0;

    nn::pia::common::Unk_165bb20_result CompleteFailure();
    nn::pia::common::Unk_165bb20_result CompleteProcess();
    nn::pia::common::Unk_165bb20_result MeshCleanup();

    Unk_1655080* m_Context;
    Unk_1655080 field_60;
    u8 _90[0x114 - 0x90];
    u32 field_114;
    u8 _118[0x120 - 0x118];
    nn::pia::Unk_165e060 field_120;
    u8 _130[0x138 - 0x130];
};
PKMN_OFFSET_ASSERT(Unk_245f3e8, m_Context, 0x58);
PKMN_OFFSET_ASSERT(Unk_245f3e8, field_60, 0x60);
PKMN_OFFSET_ASSERT(Unk_245f3e8, field_114, 0x114);
PKMN_OFFSET_ASSERT(Unk_245f3e8, field_120, 0x120);
PKMN_SIZE_ASSERT(Unk_245f3e8, 0x138);

// session::LeaveSessionJob (RTTI N2nn3pia7session15LeaveSessionJobE, vtable 0x710245f608).
class Unk_245f5f8 : public nn::pia::common::StepSequenceJob {
public:
    Unk_245f5f8();
    ~Unk_245f5f8() override;

    u8 _58[0xa8 - 0x58];
};
PKMN_SIZE_ASSERT(Unk_245f5f8, 0xa8);

// session::CreateSessionJob (RTTI N2nn3pia7session16CreateSessionJobE, vtable 0x710245f288).
class Unk_245f278 : public nn::pia::common::StepSequenceJob {
public:
    Unk_245f278();
    ~Unk_245f278() override;

    void vf5() override;
    virtual void vf6();
    virtual nn::pia::Unk_165e060 vf7(const Unk_1723380* setting) = 0;
    virtual void vf8() = 0;
    virtual nn::pia::common::Unk_165bb20_result vf9(const nn::pia::Unk_165e060& result) = 0;

    nn::pia::common::Unk_165bb20_result MeshStartup();
    nn::pia::common::Unk_165bb20_result CompleteProcess();
    void Unk_17231d0(u32 value);

    Unk_1655080* m_Context;
    Unk_1655080 field_60;
    nn::pia::Unk_165e060 field_90;
};
PKMN_OFFSET_ASSERT(Unk_245f278, m_Context, 0x58);
PKMN_OFFSET_ASSERT(Unk_245f278, field_60, 0x60);
PKMN_OFFSET_ASSERT(Unk_245f278, field_90, 0x90);
PKMN_SIZE_ASSERT(Unk_245f278, 0xa0);

namespace nn {
namespace pia {
namespace local {

class LocalMatchJoinSessionJob : public Unk_245f3e8 {
public:
    void vf14() override;
    common::Unk_165bb20_result vf15(const Unk_165e060& result) override;
    common::Unk_165bb20_result vf16() override;
    common::Unk_165bb20_result vf17() override;

    common::Unk_165bb20_result LeaveMatchmakeSession();
    common::Unk_165bb20_result WaitLeaveMatchmake();

    Unk_27fc0a8_network* m_Network;
    void* m_Owner;
};
PKMN_OFFSET_ASSERT(LocalMatchJoinSessionJob, m_Network, 0x138);
PKMN_OFFSET_ASSERT(LocalMatchJoinSessionJob, m_Owner, 0x140);
PKMN_SIZE_ASSERT(LocalMatchJoinSessionJob, 0x148);

class LocalMatchLeaveSessionJob : public Unk_245f5f8 {
public:
    explicit LocalMatchLeaveSessionJob(void* owner);
    ~LocalMatchLeaveSessionJob() override;

    void* m_Owner;
};
PKMN_OFFSET_ASSERT(LocalMatchLeaveSessionJob, m_Owner, 0xa8);
PKMN_SIZE_ASSERT(LocalMatchLeaveSessionJob, 0xb0);

class LocalMatchCreateSessionJob : public Unk_245f278 {
public:
    explicit LocalMatchCreateSessionJob(Unk_168f1e0_arg1* owner);
    ~LocalMatchCreateSessionJob() override;

    void vf6() override;
    Unk_165e060 vf7(const Unk_1723380* setting) override;
    void vf8() override;
    common::Unk_165bb20_result vf9(const Unk_165e060& result) override;

    common::Unk_165bb20_result CreateLocalNetwork();
    common::Unk_165bb20_result WaitCreateLocalNetwork();
    common::Unk_165bb20_result StartLocalSession();
    common::Unk_165bb20_result StopLocalSession();
    common::Unk_165bb20_result DestroyLocalNetwork();
    common::Unk_165bb20_result WaitDestroyLocalNetwork();
    common::Unk_165bb20_result CompleteFailure();

    Unk_27fc0a8_network* m_Network;
    Unk_168f1e0_arg1* m_Owner;
    Unk_165e060 m_Result;
};
PKMN_OFFSET_ASSERT(LocalMatchCreateSessionJob, m_Network, 0xa0);
PKMN_OFFSET_ASSERT(LocalMatchCreateSessionJob, m_Owner, 0xa8);
PKMN_OFFSET_ASSERT(LocalMatchCreateSessionJob, m_Result, 0xb0);
PKMN_SIZE_ASSERT(LocalMatchCreateSessionJob, 0xc0);

}  // namespace local
}  // namespace pia
}  // namespace nn
