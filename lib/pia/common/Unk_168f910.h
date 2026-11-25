#pragma once
// The local network's session jobs (lib/pia/common/Unk_168f910.cpp,
// Unk_1690160.cpp and Unk_1690630.cpp), each derived from one of the session or
// mesh jobs:
//
// - local::LocalMatchDestroySessionJob (RTTI
//   N2nn3pia5local27LocalMatchDestroySessionJobE), from session::DestroySessionJob;
// - local::LocalMatchBrowseMatchmakeJob (N2nn3pia5local28LocalMatchBrowseMatchmakeJobE),
//   from session::BrowseMatchmakeJob;
// - local::LocalLeaveWithHostMigrationJobNew
//   (N2nn3pia5local33LocalLeaveWithHostMigrationJobNewE), from
//   mesh::LeaveWithHostMigrationJob;
// - local::LocalMatchUpdateSessionSettingJob
//   (N2nn3pia5local33LocalMatchUpdateSessionSettingJobE), from
//   session::UpdateSessionSettingJob.
//
// The base classes keep the placeholder names their constructors have (after
// their vtables, Unk_<vtable start>). The steps' names are the strings stored
// with them ("Class::Function"); other names are placeholders
// (lib/pia/README.md).
#include "pia/common/Unk_165e060.h"

// What a job reports back to (placeholder type, after its constructor; also
// in lib/pia/common/Unk_16998e0.h): a state (1 running, 2 done, 3 failed,
// 4 cancelled), a result and a callback.
struct Unk_1655080 {
    Unk_1655080();

    void Unk_1655110();                             // reset
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
void Unk_1655170_update(u64 self);  // its destructor (empty)

// One of the networks the object behind Unk_27fc0a8 runs (placeholder).
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
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
    virtual nn::pia::Unk_165e060 vf14(Unk_1655080* context, u32 arg);
    virtual bool vf15();
};

// The object behind the global Unk_27fc0a8 (pia/common/Unk_1734ed0.h has the
// fields other members use): its networks, the current one's index and a value
// per network.
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

u32 Unk_172be20(const Unk_27fc0a8_type* self);   // its state (0, or 3 to 8)
void Unk_172e100(Unk_27fc0a8_type* self, u32 value);  // sets the current network's value

// What a LocalMatchBrowseMatchmakeJob is created with (placeholder): leaf
// functions with types of their own take it.
struct Unk_168a390;
struct Unk_168a380;
struct Unk_16898a0;
void Unk_168a390_call(const Unk_168a390* self, bool value);
bool Unk_168a380_call(const Unk_168a380* self);
bool Unk_16898a0_check(const Unk_16898a0* self);

// What a LocalMatchBrowseMatchmakeJob browses through (placeholder).
class Unk_168fbe0_arg1 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual nn::pia::Unk_165e060 vf5(Unk_1655080* context);
    virtual bool vf6();
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
    virtual void vf45(void* arg);
    virtual void vf46();
};

namespace nn {
namespace pia {
namespace common {

// What a step returns (lib/pia/common/Unk_16998e0.h): 0 runs the next step at
// once, 1 ends the job, 5 waits.
struct Unk_165bb20_result {
    u8 m_Kind;
    u8 field_1;
    u16 field_2;
};
PKMN_SIZE_ASSERT(Unk_165bb20_result, 0x4);

// A job that runs one step at a time: the member function in m_Step, with its
// name (as lib/pia/common/Unk_16998e0.h declares it).
class StepSequenceJob {
public:
    typedef Unk_165bb20_result (StepSequenceJob::*StepFunc)();

    StepSequenceJob();
    virtual ~StepSequenceJob();

    virtual void vf2(bool arg);
    virtual void vf3();
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

    u8 _8[0x28 - 0x8];
    Step m_Step;
    u8 field_48;
    u8 _49[0x58 - 0x49];
};
PKMN_OFFSET_ASSERT(StepSequenceJob, m_Step, 0x28);
PKMN_OFFSET_ASSERT(StepSequenceJob, field_48, 0x48);
PKMN_SIZE_ASSERT(StepSequenceJob, 0x58);

}  // namespace common
}  // namespace pia
}  // namespace nn

// session::DestroySessionJob (RTTI N2nn3pia7session17DestroySessionJobE).
class Unk_245f368 : public nn::pia::common::StepSequenceJob {
public:
    Unk_245f368();
    ~Unk_245f368() override;

    void vf5() override;
    virtual void vf6();
    virtual nn::pia::Unk_165e060 vf7() = 0;
    virtual void vf8() = 0;
    virtual void vf9() = 0;

    nn::pia::common::Unk_165bb20_result SendMonitoringData();
    nn::pia::common::Unk_165bb20_result MeshCleanup();

    Unk_1655080* m_Context;
    Unk_1655080 field_60;
    void* field_90;
};
PKMN_OFFSET_ASSERT(Unk_245f368, m_Context, 0x58);
PKMN_OFFSET_ASSERT(Unk_245f368, field_60, 0x60);
PKMN_OFFSET_ASSERT(Unk_245f368, field_90, 0x90);
PKMN_SIZE_ASSERT(Unk_245f368, 0x98);

// session::BrowseMatchmakeJob (RTTI N2nn3pia7session18BrowseMatchmakeJobE).
class Unk_245f0a8 : public nn::pia::common::StepSequenceJob {
public:
    Unk_245f0a8();
    ~Unk_245f0a8() override;

    void vf5() override;
    virtual void vf6();
    virtual nn::pia::Unk_165e060 vf7(Unk_168fbe0_arg1* matchmake, void* arg) = 0;
    virtual nn::pia::Unk_165e060 vf8(Unk_168fbe0_arg1* matchmake) = 0;

    nn::pia::common::Unk_165bb20_result CompleteProcess();

    Unk_1655080* m_Context;
};
PKMN_OFFSET_ASSERT(Unk_245f0a8, m_Context, 0x58);
PKMN_SIZE_ASSERT(Unk_245f0a8, 0x60);

// What LocalLeaveWithHostMigrationJobNew is created with (placeholder): the
// object at its field_18 has an address at 0x2a0.
struct Unk_16953a0_arg0;
struct Unk_16903c0_arg1 {
    u8 _0[0x18];
    Unk_16953a0_arg0* field_18;
};
PKMN_OFFSET_ASSERT(Unk_16903c0_arg1, field_18, 0x18);

// mesh::LeaveWithHostMigrationJob (RTTI N2nn3pia4mesh25LeaveWithHostMigrationJobE).
class Unk_245b868 : public nn::pia::common::StepSequenceJob {
public:
    Unk_245b868();
    ~Unk_245b868() override;

    virtual u8 vf6();
    virtual void vf7();

    u8 _58[0x90 - 0x58];
};
PKMN_SIZE_ASSERT(Unk_245b868, 0x90);

// What a LocalMatchUpdateSessionSettingJob updates (placeholder).
class Unk_16906c0_arg2 {
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
    virtual nn::pia::Unk_165e060 vf16(Unk_1655080* context, u32 id);
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
    virtual bool vf39(u32 id);

    nn::pia::Unk_165e060 Unk_168dec0(void* data, u32 size);
};

// The setting a LocalMatchUpdateSessionSettingJob applies (placeholder).
class Unk_16906c0_arg3 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual u32 vf4();
    virtual void vf5();
    virtual void vf6();
    virtual bool vf7(bool arg);
    virtual void vf8();
    virtual void vf9();
    virtual void* vf10();
};

// session::UpdateSessionSettingJob (RTTI N2nn3pia7session23UpdateSessionSettingJobE).
class Unk_2460028 : public nn::pia::common::StepSequenceJob {
public:
    Unk_2460028();
    ~Unk_2460028() override;

    virtual void vf6();
    virtual nn::pia::Unk_165e060 vf7(u32 id, Unk_16906c0_arg2* session, Unk_16906c0_arg3* setting,
                                     bool arg) = 0;

    Unk_1655080* m_Context;
    Unk_1655080 field_60;
    u8 _90[0x98 - 0x90];
    Unk_16906c0_arg2* field_98;
    u32 field_a0;
};
PKMN_OFFSET_ASSERT(Unk_2460028, m_Context, 0x58);
PKMN_OFFSET_ASSERT(Unk_2460028, field_60, 0x60);
PKMN_OFFSET_ASSERT(Unk_2460028, field_98, 0x98);
PKMN_OFFSET_ASSERT(Unk_2460028, field_a0, 0xa0);

// Ends the job with the error of the session's state, if it has one: each of
// LocalMatchBrowseMatchmakeJob's steps that waits checks it first (the same
// code in each, so a macro).
#define LOCAL_MATCH_FAIL_ON_SESSION_STATE()                                  \
    if (Unk_27fc0a8 != nullptr) {                                            \
        switch (Unk_172be20(Unk_27fc0a8)) {                                  \
        case 5:                                                              \
            m_Context->Unk_1655220(Unk_165e060Value<0xc406>());              \
            m_Context = nullptr;                                             \
            return {1};                                                      \
        case 4:                                                              \
            m_Context->Unk_1655220(Unk_165e060Value<0x8c56>());              \
            m_Context = nullptr;                                             \
            return {1};                                                      \
        case 7:                                                              \
            m_Context->Unk_1655220(Unk_165e060Value<0xc420>());              \
            m_Context = nullptr;                                             \
            return {1};                                                      \
        case 8:                                                              \
            m_Context->Unk_1655220(Unk_165e060Value<0xc421>());              \
            m_Context = nullptr;                                             \
            return {1};                                                      \
        }                                                                    \
    }

namespace nn {
namespace pia {
namespace local {

class LocalMatchDestroySessionJob : public Unk_245f368 {
public:
    void vf5() override;
    void vf6() override;
    Unk_165e060 vf7() override;
    void vf8() override;
    void vf9() override;

    common::Unk_165bb20_result DestroyLocalNetwork();
    common::Unk_165bb20_result WaitDestroyLocalNetwork();

    u8 _98[0xa0 - 0x98];
};
PKMN_SIZE_ASSERT(LocalMatchDestroySessionJob, 0xa0);

class LocalMatchBrowseMatchmakeJob : public Unk_245f0a8 {
public:
    explicit LocalMatchBrowseMatchmakeJob(void* owner);
    ~LocalMatchBrowseMatchmakeJob() override;

    void vf5() override;
    void vf6() override;
    Unk_165e060 vf7(Unk_168fbe0_arg1* matchmake, void* arg) override;
    Unk_165e060 vf8(Unk_168fbe0_arg1* matchmake) override;

    common::Unk_165bb20_result BrowseMatchmake();
    common::Unk_165bb20_result WaitBrowseMatchmake();
    common::Unk_165bb20_result WaitHostMigration();
    common::Unk_165bb20_result UpdateCurrentConnectionStatus();
    common::Unk_165bb20_result WaitUpdateCurrentConnectionStatus();
    common::Unk_165bb20_result UpdateSessionInfo();

    void* m_Owner;
    Unk_1655080 m_BrowseContext;
    Unk_168fbe0_arg1* m_Matchmake;
};
PKMN_OFFSET_ASSERT(LocalMatchBrowseMatchmakeJob, m_Owner, 0x60);
PKMN_OFFSET_ASSERT(LocalMatchBrowseMatchmakeJob, m_BrowseContext, 0x68);
PKMN_OFFSET_ASSERT(LocalMatchBrowseMatchmakeJob, m_Matchmake, 0x98);
PKMN_SIZE_ASSERT(LocalMatchBrowseMatchmakeJob, 0xa0);

class LocalLeaveWithHostMigrationJobNew : public Unk_245b868 {
public:
    explicit LocalLeaveWithHostMigrationJobNew(Unk_16903c0_arg1* owner);
    ~LocalLeaveWithHostMigrationJobNew() override;

    void vf5() override;
    u8 vf6() override;

    Unk_16903c0_arg1* m_Owner;
};
PKMN_OFFSET_ASSERT(LocalLeaveWithHostMigrationJobNew, m_Owner, 0x90);
PKMN_SIZE_ASSERT(LocalLeaveWithHostMigrationJobNew, 0x98);

// Its constructor (0x7101690630) has the placeholder name Unk_245aa88 (after
// the vtable), as lib/pia/gen/nn_pia_local_LocalNetworkFactory.cpp calls it:
// it's in lib/pia/common/Unk_1690630.cpp.
class LocalMatchUpdateSessionSettingJob : public Unk_2460028 {
public:
    ~LocalMatchUpdateSessionSettingJob() override;

    void vf5() override;
    void vf6() override;
    Unk_165e060 vf7(u32 id, Unk_16906c0_arg2* session, Unk_16906c0_arg3* setting, bool arg) override;

    common::Unk_165bb20_result SignalProcess();
    common::Unk_165bb20_result CompleteFailure();

    Unk_165e060 m_Result;
};
PKMN_OFFSET_ASSERT(LocalMatchUpdateSessionSettingJob, m_Result, 0xa4);
PKMN_SIZE_ASSERT(LocalMatchUpdateSessionSettingJob, 0xb8);

}  // namespace local
}  // namespace pia
}  // namespace nn
