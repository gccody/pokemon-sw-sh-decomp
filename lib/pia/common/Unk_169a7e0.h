#pragma once
// The local network's jobs after local::LocalResendMessageJob
// (lib/pia/common/Unk_169a7e0.cpp):
//
// - the rest of local::LocalResendMessageJob (RTTI
//   N2nn3pia5local21LocalResendMessageJobE; the rest of it is in
//   lib/pia/common/Unk_169a160.cpp);
// - local::LocalScanNetworkJob (N2nn3pia5local19LocalScanNetworkJobE, vtable
//   0x710245b418; vtables.py names the class Unk_245b408 after it).
//
// Both derive from common::StepSequenceJob. The steps' names are the strings
// stored with them ("Class::Function"), and the GOT slots each step's pointer
// is loaded from hold the functions they name. LocalScanNetworkJob's vf5 is in
// lib/nx_middleware/class/nn_pia_local_LocalScanNetworkJob.cpp. Other names
// are placeholders (lib/pia/README.md).
//
// lib/pia/common/Unk_1697a00.h and Unk_1698930.h declare some of the same
// classes with other members (local::LocalBackgroundProcessJob's slots), so
// this header doesn't include them.
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
// vtable 0x7102459bf0): abstract, slots 6 to 13 are pure. Slot 7 starts a
// network scan.
class LocalBackgroundProcessJob : public common::StepSequenceJob {
public:
    virtual void vf6() = 0;
    virtual Unk_165e060 vf7(Unk_1655080* context) = 0;
};

// local::LocalProtocol (RTTI N2nn3pia5local13LocalProtocolE), as these jobs use
// it.
class LocalProtocol {
public:
    virtual ~LocalProtocol();

    u8 _8[0x400 - 0x8];
    LocalBackgroundProcessJob* field_400;
    u8 _408[0x47d - 0x408];
    u8 field_47d;
};
PKMN_OFFSET_ASSERT(LocalProtocol, field_400, 0x400);
PKMN_OFFSET_ASSERT(LocalProtocol, field_47d, 0x47d);

// Only the members this file has (lib/pia/common/Unk_169a160.cpp declares it
// all).
class LocalResendMessageJob : public common::StepSequenceJob {
public:
    ~LocalResendMessageJob() override;

    void vf5() override;

    void Unk_169a7e0(u32 station);

    u32 m_Id;
    u32 m_Stations;  // a bit per station that hasn't acknowledged it yet
};
PKMN_OFFSET_ASSERT(LocalResendMessageJob, m_Id, 0x58);
PKMN_OFFSET_ASSERT(LocalResendMessageJob, m_Stations, 0x5c);

class LocalScanNetworkJob : public common::StepSequenceJob {
public:
    explicit LocalScanNetworkJob(LocalProtocol* protocol);
    ~LocalScanNetworkJob() override;

    void vf5() override;
    virtual Unk_165e060 vf6(Unk_1655080* context);  // starts it

    common::Unk_165bb20_result WaitScanNetwork();
    void Unk_169aae0();  // cancels it
    common::Unk_165bb20_result WaitForCancel();

    Unk_1655080* m_Context;
    Unk_1655080* m_JobContext;
    LocalProtocol* m_Protocol;
};
PKMN_OFFSET_ASSERT(LocalScanNetworkJob, m_Context, 0x58);
PKMN_OFFSET_ASSERT(LocalScanNetworkJob, m_JobContext, 0x60);
PKMN_OFFSET_ASSERT(LocalScanNetworkJob, m_Protocol, 0x68);
PKMN_SIZE_ASSERT(LocalScanNetworkJob, 0x70);

}  // namespace local
}  // namespace pia
}  // namespace nn
