#pragma once
// The local network's jobs after local::LocalDestroyNetworkJob
// (lib/pia/common/Unk_1698930.cpp and Unk_1699080.cpp):
//
// - local::LocalDestroyNetworkJob's last step (RTTI
//   N2nn3pia5local22LocalDestroyNetworkJobE, vtable 0x710245b118; the rest of
//   it is with local::LocalConnectNetworkJob's files);
// - local::LocalDisconnectNetworkJob (N2nn3pia5local25LocalDisconnectNetworkJobE,
//   vtable 0x710245b178);
// - local::LocalAllowParticipatingJob (N2nn3pia5local26LocalAllowParticipatingJobE,
//   vtable 0x710245b1d8) and the job it runs,
//   local::LocalAllowParticipatingBackgroundJob
//   (N2nn3pia5local36LocalAllowParticipatingBackgroundJobE, vtable 0x710245b238).
//
// All of them derive from common::StepSequenceJob. The steps' names are the
// strings stored with them ("Class::Function"), and the GOT slots each step's
// pointer is loaded from hold the functions they name. Their vf5 are in
// lib/nx_middleware/class/nn_pia_local_Local*Job.cpp, and the WaitForCancel
// steps (0x7101698540, 0x7101698dc0) in lib/nx_middleware/leaf/Unk_168ab60.cpp,
// under leaves' placeholder names. Other names are placeholders
// (lib/pia/README.md).
//
// lib/pia/common/Unk_1654a80.h, Unk_168f910.h and Unk_16998e0.h declare some
// of the same classes without the members these files call (the context's
// constructor, the job's Unk_16559c0), so this header doesn't include them.
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

// What LocalProtocol's Unk_16928a0_set takes (a leaf, lib/nx_middleware/leaf).
struct Unk_16928a0;
void Unk_16928a0_set(Unk_16928a0* self, u32 value);

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
// vtable 0x7102459bf0), as these jobs use it: its Unk_16877d0 and Unk_1687880
// sit between its destructor and its vf5.
class LocalBackgroundProcessJob : public common::StepSequenceJob {
public:
    Unk_165e060 Unk_16877d0();
    Unk_165e060 Unk_1687880(Unk_1655080* context);
};

// local::LocalProtocol (RTTI N2nn3pia5local13LocalProtocolE), as these jobs use
// it.
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
    virtual Unk_165e060 vf33(bool arg);
    virtual Unk_165e060 vf34();

    void Unk_1692780();
    void Unk_16935a0();
    bool Unk_1694a60();

    u8 _8[0x400 - 0x8];
    LocalBackgroundProcessJob* field_400;
    u8 _408[0x418 - 0x408];
    u32 field_418;
    u8 _41c[0x474 - 0x41c];
    u32 field_474;
};
PKMN_OFFSET_ASSERT(LocalProtocol, field_400, 0x400);
PKMN_OFFSET_ASSERT(LocalProtocol, field_418, 0x418);
PKMN_OFFSET_ASSERT(LocalProtocol, field_474, 0x474);

// The system tick (as lib/pia/common/Unk_1730630.h declares it).
struct Unk_165c600 {
    u64 field_0;
};
PKMN_SIZE_ASSERT(Unk_165c600, 0x8);

class LocalDestroyNetworkJob : public common::StepSequenceJob {
public:
    explicit LocalDestroyNetworkJob(LocalProtocol* protocol);
    ~LocalDestroyNetworkJob() override;

    void vf5() override;

    common::Unk_165bb20_result WaitForCancel();
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
PKMN_OFFSET_ASSERT(LocalDestroyNetworkJob, field_80, 0x80);
PKMN_OFFSET_ASSERT(LocalDestroyNetworkJob, m_Protocol, 0x88);
PKMN_SIZE_ASSERT(LocalDestroyNetworkJob, 0x90);

class LocalDisconnectNetworkJob : public common::StepSequenceJob {
public:
    explicit LocalDisconnectNetworkJob(LocalProtocol* protocol);
    ~LocalDisconnectNetworkJob() override;

    void vf5() override;

    Unk_165e060 Unk_1698b70(Unk_1655080* context);  // starts it
    common::Unk_165bb20_result TryPrepareDisconnectNetwork();
    void Unk_1698d30();  // cancels it
    common::Unk_165bb20_result WaitForCancel();
    common::Unk_165bb20_result WaitDisconnectNetwork();

    Unk_1655080* m_Context;
    Unk_1655080* m_JobContext;
    LocalProtocol* m_Protocol;
};
PKMN_OFFSET_ASSERT(LocalDisconnectNetworkJob, m_Context, 0x58);
PKMN_OFFSET_ASSERT(LocalDisconnectNetworkJob, m_JobContext, 0x60);
PKMN_OFFSET_ASSERT(LocalDisconnectNetworkJob, m_Protocol, 0x68);
PKMN_SIZE_ASSERT(LocalDisconnectNetworkJob, 0x70);

class LocalAllowParticipatingBackgroundJob : public common::StepSequenceJob {
public:
    explicit LocalAllowParticipatingBackgroundJob(LocalProtocol* protocol);
    ~LocalAllowParticipatingBackgroundJob() override;

    void vf5() override;

    Unk_165e060 Unk_1699510(Unk_1655080* context, u32 value);  // starts it
    common::Unk_165bb20_result AllowParticipating();
    void Unk_1699740();  // cancels it

    Unk_1655080* m_Context;
    u32 field_60;
    LocalProtocol* m_Protocol;
};
PKMN_OFFSET_ASSERT(LocalAllowParticipatingBackgroundJob, m_Context, 0x58);
PKMN_OFFSET_ASSERT(LocalAllowParticipatingBackgroundJob, field_60, 0x60);
PKMN_OFFSET_ASSERT(LocalAllowParticipatingBackgroundJob, m_Protocol, 0x68);
PKMN_SIZE_ASSERT(LocalAllowParticipatingBackgroundJob, 0x70);

class LocalAllowParticipatingJob : public common::StepSequenceJob {
public:
    explicit LocalAllowParticipatingJob(LocalProtocol* protocol);
    ~LocalAllowParticipatingJob() override;

    void vf5() override;

    Unk_165e060 Unk_1699080(Unk_1655080* context, u32 value);  // starts it
    common::Unk_165bb20_result WaitAllowParticipating();
    void Unk_16992b0();  // cancels it
    common::Unk_165bb20_result WaitBackgroundJobEnd();
    common::Unk_165bb20_result CompleteProcess();

    LocalAllowParticipatingBackgroundJob* m_Job;
    Unk_1655080* m_Context;
    Unk_1655080 m_JobContext;
    u32 field_98;
    Unk_165e060 m_Result;
    LocalProtocol* m_Protocol;
};
PKMN_OFFSET_ASSERT(LocalAllowParticipatingJob, m_Job, 0x58);
PKMN_OFFSET_ASSERT(LocalAllowParticipatingJob, m_Context, 0x60);
PKMN_OFFSET_ASSERT(LocalAllowParticipatingJob, m_JobContext, 0x68);
PKMN_OFFSET_ASSERT(LocalAllowParticipatingJob, field_98, 0x98);
PKMN_OFFSET_ASSERT(LocalAllowParticipatingJob, m_Result, 0x9c);
PKMN_OFFSET_ASSERT(LocalAllowParticipatingJob, m_Protocol, 0xb0);
PKMN_SIZE_ASSERT(LocalAllowParticipatingJob, 0xb8);

}  // namespace local
}  // namespace pia
}  // namespace nn
