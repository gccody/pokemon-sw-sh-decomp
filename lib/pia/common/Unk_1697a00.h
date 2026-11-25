#pragma once
// The local network's jobs around local::LocalProtocol
// (lib/pia/common/Unk_1697a00.cpp and Unk_16981b0.cpp):
//
// - local::LocalEventJob's steps (RTTI N2nn3pia5local13LocalEventJobE; its
//   constructor and destructors are in lib/pia/common/Unk_1697700.cpp);
// - local::LocalConnectNetworkJob (N2nn3pia5local22LocalConnectNetworkJobE,
//   vtable 0x710245b0b8);
// - local::LocalDestroyNetworkJob (N2nn3pia5local22LocalDestroyNetworkJobE,
//   vtable 0x710245b118).
//
// All three derive from common::StepSequenceJob. The steps' names are the
// strings stored with them ("Class::Function"), and the GOT slots each step's
// pointer is loaded from hold the functions they name. Other names are
// placeholders (lib/pia/README.md).
//
// lib/pia/common/Unk_1654a80.h and Unk_16998e0.h declare some of the same
// classes; this header declares the members these files call as well (the
// job's Unk_16559c0), so it doesn't include them.
#include "pia/common/Unk_165e060.h"

// What a job reports back to (placeholder type, after its constructor
// 0x7101655080): a state (1 running, 2 done, 3 failed, 4 cancelled), a result
// and a callback. Its destructor (0x7101655170, empty), start (0x7101655190)
// and cancel request (0x7101655330, setting field_28) have free functions'
// placeholder names.
struct Unk_1655190;
struct Unk_1655330;
struct Unk_1655080 {
    Unk_1655080();

    void Unk_1655110();                             // reset
    void Unk_16551b0(nn::pia::Unk_165e060 result);  // state 2, callback
    void Unk_1655220(nn::pia::Unk_165e060 result);  // state 3, callback

    u32 m_State;
    nn::pia::Unk_165e060 m_Result;
    void (*m_Callback)(nn::pia::Unk_165e060 result, void* arg);
    void* m_CallbackArg;
    u8 field_28;
};
PKMN_OFFSET_ASSERT(Unk_1655080, m_Result, 0x4);
PKMN_OFFSET_ASSERT(Unk_1655080, m_Callback, 0x18);
PKMN_OFFSET_ASSERT(Unk_1655080, m_CallbackArg, 0x20);
PKMN_OFFSET_ASSERT(Unk_1655080, field_28, 0x28);
PKMN_SIZE_ASSERT(Unk_1655080, 0x30);
void Unk_1655170_update(u64 self);          // its destructor (empty)
u32 Unk_1655190_update(Unk_1655190* self);  // state 1
void Unk_1655330_set(Unk_1655330* self);    // asks it to cancel (field_28)
void Unk_1655290(void* self);               // state 4 (cancelled), callback

// The system tick (lib/nx_middleware/leaf/Unk_16598a0.cpp) and the ticks in a
// millisecond (as lib/pia/common/Unk_1730630.h declares them).
struct Unk_165c600 {
    u64 field_0;
};
PKMN_SIZE_ASSERT(Unk_165c600, 0x8);
void Unk_165c600_call(Unk_165c600* self);  // reads the tick
const s64* Unk_165c6b0();

// What LocalProtocol's Unk_1695d90_check reads (a leaf, lib/nx_middleware/leaf).
struct Unk_1695d90;
bool Unk_1695d90_check(const Unk_1695d90* self);

// Free functions' placeholder names for two LocalProtocol members
// (lib/nx_middleware/leaf/Unk_1687070.cpp calls them so).
bool Unk_1693c90(void* self);
void Unk_1693c80(void* self, u32 value);

namespace nn {
namespace pia {
namespace common {

// A job's base (common::Job, RTTI N2nn3pia6common3JobE; vtable 0x7102456ef8).
class Unk_1655760 {
public:
    Unk_1655760();
    virtual ~Unk_1655760();

    virtual void vf2(bool arg);
    virtual void vf3() = 0;

    void Unk_1655850(bool arg);  // starts it
    bool Unk_1655a80();          // whether it's running
    bool Unk_16559c0();

    u32 field_8;
    u32 field_c;
    void* field_10;
    void* field_18;
    void* field_20;
};
PKMN_SIZE_ASSERT(Unk_1655760, 0x28);

// What a step returns (placeholder: StepSequenceJob's vf3, 0x710165bb20, takes
// it apart): 0 runs the next step at once, 1 ends the job, 5 waits.
struct Unk_165bb20_result {
    u8 m_Kind;
    u8 field_1;
    u16 field_2;
};
PKMN_SIZE_ASSERT(Unk_165bb20_result, 0x4);

// A job that runs one step at a time: the member function in m_Step, with its
// name.
class StepSequenceJob : public Unk_1655760 {
public:
    typedef Unk_165bb20_result (StepSequenceJob::*StepFunc)();

    StepSequenceJob();
    ~StepSequenceJob() override;

    void vf2(bool arg) override;
    void vf3() override;
    virtual void vf4();
    virtual void vf5();

    void Unk_165bba0(u32 timeout);

    // Inline: asks the running step to stop, then waits for it.
    void Cancel(u32 timeout) {
        field_48 = true;
        Unk_165bba0(timeout);
    }

    // RTTI N2nn3pia6common15StepSequenceJob4StepE.
    class Step {
    public:
        virtual ~Step();
        virtual void vf2();

        StepFunc m_Func;
        const char* m_Name;
    };

    template <typename T>
    void SetStep(Unk_165bb20_result (T::*step)(), const char* name) {
        m_Step.m_Func = static_cast<StepFunc>(step);
        m_Step.m_Name = name;
    }

    Step m_Step;
    u8 field_48;
    u8 _49[0x58 - 0x49];
};
PKMN_OFFSET_ASSERT(StepSequenceJob, m_Step, 0x28);
PKMN_OFFSET_ASSERT(StepSequenceJob, field_48, 0x48);
PKMN_SIZE_ASSERT(StepSequenceJob, 0x58);

}  // namespace common

namespace local {

// local::LocalBackgroundProcessJob (RTTI N2nn3pia5local25LocalBackgroundProcessJobE,
// vtable 0x7102459bf0): abstract, slots 6 to 13 are pure. Its Unk_1687580 and
// Unk_1687630 sit between its destructor and its vf5.
class LocalBackgroundProcessJob : public common::StepSequenceJob {
public:
    virtual void vf6() = 0;
    virtual void vf7() = 0;
    virtual Unk_165e060 vf8(Unk_1655080* context, const void* arg) = 0;
    virtual void vf9() = 0;
    virtual void vf10() = 0;
    virtual void vf11() = 0;
    virtual void vf12() = 0;
    virtual void vf13() = 0;

    Unk_165e060 Unk_1687580();
    Unk_165e060 Unk_1687630(Unk_1655080* context);
};

// local::LocalEventCheckBackgroundJob: the job a LocalEventJob runs (its
// Unk_1688b10 stores the step "LocalEventCheckBackgroundJob::UpdateConnectionStatus").
class LocalEventCheckBackgroundJob : public common::StepSequenceJob {
public:
    Unk_165e060 Unk_1688b10(Unk_1655080* context);  // starts it
    void Unk_1688c40();                             // ends it
};

// What LocalProtocol's Unk_1695fb0 finds (placeholder).
struct Unk_1695fb0_result {
    u8 _0[0x4];
    u32 field_4;
    u8 field_8;
};
PKMN_OFFSET_ASSERT(Unk_1695fb0_result, field_4, 0x4);
PKMN_OFFSET_ASSERT(Unk_1695fb0_result, field_8, 0x8);

// local::LocalProtocol (RTTI N2nn3pia5local13LocalProtocolE), as these jobs use
// it; lib/pia/common/Unk_1697210.cpp has another of its members.
class LocalProtocol {
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
    virtual void vf47();
    virtual void vf48();
    virtual void vf49();
    virtual void vf50();
    virtual void vf51();
    virtual bool vf52();
    virtual LocalEventCheckBackgroundJob* vf53();
    virtual void vf54(LocalEventCheckBackgroundJob* job);
    virtual bool vf55();

    bool Unk_1692ea0();
    void Unk_1692fb0();
    void Unk_16935a0();
    void Unk_16945d0();
    void Unk_1694650();
    bool Unk_1694a60();
    u8 Unk_16955c0();
    const Unk_1695fb0_result* Unk_1695fb0(const void* arg);

    u8 _8[0x400 - 0x8];
    LocalBackgroundProcessJob* field_400;
    u8 _408[0x418 - 0x408];
    u32 field_418;
    u8 _41c[0x468 - 0x41c];
    u8 field_468;
    u8 _469[0x474 - 0x469];
    u32 field_474;
    u8 _478[0x47d - 0x478];
    u8 field_47d;
    u8 _47e[0x569 - 0x47e];
    u8 field_569;
};
PKMN_OFFSET_ASSERT(LocalProtocol, field_400, 0x400);
PKMN_OFFSET_ASSERT(LocalProtocol, field_418, 0x418);
PKMN_OFFSET_ASSERT(LocalProtocol, field_468, 0x468);
PKMN_OFFSET_ASSERT(LocalProtocol, field_474, 0x474);
PKMN_OFFSET_ASSERT(LocalProtocol, field_47d, 0x47d);
PKMN_OFFSET_ASSERT(LocalProtocol, field_569, 0x569);

class LocalEventJob : public common::StepSequenceJob {
public:
    ~LocalEventJob() override;

    void vf5() override;

    Unk_165e060 Unk_1697a00();  // starts it
    common::Unk_165bb20_result WatchUpdateEvent();
    void Unk_1697b10();  // cancels it
    common::Unk_165bb20_result WaitConnectionStatusUpdated();
    common::Unk_165bb20_result ProcessUpdateEvent();
    common::Unk_165bb20_result WaitBackgroundJobEnd();

    Unk_1655080 m_Context;
    LocalEventCheckBackgroundJob* m_Job;
    LocalProtocol* m_Protocol;
};
PKMN_OFFSET_ASSERT(LocalEventJob, m_Context, 0x58);
PKMN_OFFSET_ASSERT(LocalEventJob, m_Job, 0x88);
PKMN_OFFSET_ASSERT(LocalEventJob, m_Protocol, 0x90);
PKMN_SIZE_ASSERT(LocalEventJob, 0x98);

// What LocalConnectNetworkJob connects to (placeholder: its Unk_1697da0's
// argument, handed on to the background job).
struct Unk_1697da0_arg2 {
    const void* field_0;
    u32 field_8;
};
PKMN_OFFSET_ASSERT(Unk_1697da0_arg2, field_8, 0x8);

class LocalConnectNetworkJob : public common::StepSequenceJob {
public:
    explicit LocalConnectNetworkJob(LocalProtocol* protocol);
    ~LocalConnectNetworkJob() override;

    void vf5() override;

    Unk_165e060 Unk_1697da0(Unk_1655080* context, const Unk_1697da0_arg2* arg);  // starts it
    common::Unk_165bb20_result WaitConnectNetwork();
    void Unk_1698010();  // cancels it
    common::Unk_165bb20_result WaitForCancel();
    common::Unk_165bb20_result ProcessSucceeded();

    Unk_1655080* m_Context;
    Unk_1655080* m_JobContext;
    LocalProtocol* m_Protocol;
};
PKMN_OFFSET_ASSERT(LocalConnectNetworkJob, m_Context, 0x58);
PKMN_OFFSET_ASSERT(LocalConnectNetworkJob, m_JobContext, 0x60);
PKMN_OFFSET_ASSERT(LocalConnectNetworkJob, m_Protocol, 0x68);
PKMN_SIZE_ASSERT(LocalConnectNetworkJob, 0x70);

class LocalDestroyNetworkJob : public common::StepSequenceJob {
public:
    explicit LocalDestroyNetworkJob(LocalProtocol* protocol);
    ~LocalDestroyNetworkJob() override;

    void vf5() override;

    Unk_165e060 Unk_16982d0(Unk_1655080* context, bool arg);  // starts it
    common::Unk_165bb20_result TryPrepareDestroyNetwork();
    void Unk_1698490();  // cancels it
    common::Unk_165bb20_result WaitForCancel();
    common::Unk_165bb20_result WaitUntilAllClientsReceiveUpdateSessionMessage();
    common::Unk_165bb20_result SendDestroyNetworkMessage();
    common::Unk_165bb20_result StartDestroyNetwork();
    common::Unk_165bb20_result WaitUntilAllClientsDisconnection();
    common::Unk_165bb20_result WaitDestroyNetwork();

    Unk_1655080* m_Context;
    Unk_1655080* m_JobContext;
    Unk_165c600 field_68;
    Unk_165c600 field_70;
    Unk_165c600 field_78;
    u8 field_80;
    LocalProtocol* m_Protocol;
};
PKMN_OFFSET_ASSERT(LocalDestroyNetworkJob, m_Context, 0x58);
PKMN_OFFSET_ASSERT(LocalDestroyNetworkJob, m_JobContext, 0x60);
PKMN_OFFSET_ASSERT(LocalDestroyNetworkJob, field_68, 0x68);
PKMN_OFFSET_ASSERT(LocalDestroyNetworkJob, field_70, 0x70);
PKMN_OFFSET_ASSERT(LocalDestroyNetworkJob, field_78, 0x78);
PKMN_OFFSET_ASSERT(LocalDestroyNetworkJob, field_80, 0x80);
PKMN_OFFSET_ASSERT(LocalDestroyNetworkJob, m_Protocol, 0x88);
PKMN_SIZE_ASSERT(LocalDestroyNetworkJob, 0x90);

}  // namespace local
}  // namespace pia
}  // namespace nn
