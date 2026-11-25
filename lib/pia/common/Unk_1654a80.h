#pragma once
// Pia's monitoring jobs and the classes around them, as these files use them
// (lib/pia/common/Unk_1654a80.cpp, Unk_1655080.cpp, Unk_1655180.cpp):
//
// - common::MonitoringDataSendJob (RTTI N2nn3pia6common21MonitoringDataSendJobE)
//   and common::MonitoringServerAddressResolveJob
//   (N2nn3pia6common33MonitoringServerAddressResolveJobE), both derived from
//   common::StepSequenceJob;
// - common::FixedString<256> (N2nn3pia6common11FixedStringILj256EEE);
// - the jobs' base, common::Job (N2nn3pia6common3JobE), which keeps the
//   placeholder name Unk_1655760 its members already have;
// - what a job reports back to, Unk_1655080 (no vtable, so no RTTI).
//
// lib/pia/common/Unk_16998e0.h and Unk_165fb10.h declare some of the same
// classes with fewer members, so a file includes one header or the other. The
// steps' names are the strings stored with them ("Class::Function"); other
// names are placeholders (lib/pia/README.md).
#include "pia/common/Unk_165e060.h"

// What a job reports back to (placeholder type, after its constructor): a
// state (1 running, 2 done, 3 failed, 4 cancelled), a result and a callback.
// The functions that release it (0x7101655170, empty) and start it
// (0x7101655190) have free functions' placeholder names.
struct Unk_1655190;
struct Unk_1655080 {
    Unk_1655080();

    void Unk_1655110();                             // reset
    void Unk_16551b0(nn::pia::Unk_165e060 result);  // state 2, callback
    void Unk_1655220(nn::pia::Unk_165e060 result);  // state 3, callback

    // Inline (each takes its result by value, as the copies show).
    void SetResult(nn::pia::Unk_165e060 result) { m_Result = result; }
    void Notify(nn::pia::Unk_165e060 result) {
        if (m_Callback != nullptr) {
            m_Callback(result, m_CallbackArg);
        }
    }

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
void Unk_1655170_update(u64 self);            // its destructor (empty)
u32 Unk_1655190_update(Unk_1655190* self);    // state 1
void Unk_1655290(void* self);                 // state 4 (cancelled), callback

namespace nn {
namespace pia {

// common::InetAddress (lib/pia/common/Unk_165fb10.h has the rest).
class Unk_1652c70 {
public:
    virtual ~Unk_1652c70();

    bool Unk_1652f60() const;  // whether its 16 bytes aren't all zero

    u8 field_8[0x10];
    u16 field_18;
};
PKMN_OFFSET_ASSERT(Unk_1652c70, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_1652c70, field_18, 0x18);
PKMN_SIZE_ASSERT(Unk_1652c70, 0x20);

}  // namespace pia
}  // namespace nn

// What MonitoringDataSendJob sends (placeholder, after the function that takes
// it): its leaf getters have placeholder types of their own.
struct Unk_1654e50_arg1;
struct Unk_1654290;
struct Unk_1654870;
bool Unk_1654860(const Unk_1654e50_arg1* self);                        // still sending
nn::pia::Unk_165e060 Unk_1654720(Unk_1654e50_arg1* self);
const nn::pia::Unk_1652c70* Unk_1654290_get(const Unk_1654290* self);  // the server's address
bool Unk_1654870_get(const Unk_1654870* self);

// A string over a buffer of its own (placeholder name after its vtable,
// 0x71023a2ca8; also in lib/pia/common/Unk_165fb10.h).
class Unk_23a2c98 {
public:
    Unk_23a2c98() : field_18(0) {}
    virtual ~Unk_23a2c98() {}
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual nn::pia::Unk_165e060 vf5(const void* text, u32 length, u32 encoding);

    char* field_8;
    u32 field_10;
    u32 field_14;
    u32 field_18;
};
PKMN_OFFSET_ASSERT(Unk_23a2c98, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_23a2c98, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_23a2c98, field_18, 0x18);

u32 Unk_165c200(const char* text, u32 length);  // counts UTF-8 characters

namespace nn {
namespace pia {
namespace common {

// A string of up to N characters of up to 4 bytes each, in the object.
// field_14 is its length in bytes and field_18 its encoding (1 UTF-8,
// 2 UTF-16).
template <u32 N>
class FixedString : public Unk_23a2c98 {
public:
    FixedString() {
        field_8 = m_Buffer;
        field_10 = N * 4;
        field_14 = 0;
        for (u32 i = 0; i < sizeof(m_Buffer); ++i) {
            m_Buffer[i] = '\0';
        }
        field_14 = 0;
        field_18 = 0;
    }
    virtual ~FixedString() {}
    virtual void vf3();
    virtual Unk_165e060 vf5(const void* text, u32 length, u32 encoding);

    char m_Buffer[N * 4 + 1];
};

// A job's base (common::Job, RTTI N2nn3pia6common3JobE; vtable 0x7102456ef8).
// It's abstract: its slot 3 is pure, so its deleting destructor is a trap.
class Unk_1655760 {
public:
    Unk_1655760();
    virtual ~Unk_1655760();

    virtual void vf2(bool arg);
    virtual void vf3() = 0;

    void Unk_1655850(bool arg);  // starts it
    bool Unk_1655a80();          // whether it's running

    u32 field_8;
    u32 field_c;
    void* field_10;
    void* field_18;
    void* field_20;
};
PKMN_OFFSET_ASSERT(Unk_1655760, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_1655760, field_c, 0xc);
PKMN_OFFSET_ASSERT(Unk_1655760, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_1655760, field_18, 0x18);
PKMN_OFFSET_ASSERT(Unk_1655760, field_20, 0x20);
PKMN_SIZE_ASSERT(Unk_1655760, 0x28);

// What runs the jobs in the background (placeholder: the global behind the
// GOT slot the job's destructor reads, Unk_27fa890, and the member it calls).
class Unk_1657ba0_type {
public:
    void Unk_1657ba0(Unk_1655760* job);  // forgets a job
};

// What a step returns (placeholder: StepSequenceJob's vf3, 0x710165bb20, takes
// it apart): 0 runs the next step at once, 1 ends the job, 5 waits.
struct Unk_165bb20_result {
    u8 m_Kind;
    u8 field_1;
    u16 field_2;
};
PKMN_SIZE_ASSERT(Unk_165bb20_result, 0x4);

// A job that runs one step at a time: the member function in m_Step, with its
// name (as lib/pia/common/Unk_16998e0.h declares it).
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

class MonitoringDataSendJob : public StepSequenceJob {
public:
    MonitoringDataSendJob();
    ~MonitoringDataSendJob() override;

    Unk_165e060 Unk_1654e50(Unk_1654e50_arg1* data);  // starts sending
    Unk_165bb20_result StepSendReport();
    void Unk_1655030();  // cancels and resets

    Unk_1655080 m_Context;
    Unk_1654e50_arg1* m_Data;
};
PKMN_OFFSET_ASSERT(MonitoringDataSendJob, m_Context, 0x58);
PKMN_OFFSET_ASSERT(MonitoringDataSendJob, m_Data, 0x88);
PKMN_SIZE_ASSERT(MonitoringDataSendJob, 0x90);

class MonitoringServerAddressResolveJob : public StepSequenceJob {
public:
    MonitoringServerAddressResolveJob();
    ~MonitoringServerAddressResolveJob() override;

    void Unk_16554d0();  // cancels and resets

    Unk_1655080 m_Context;
    void* field_88;
    FixedString<256> m_Name;
    void* field_4b0;
};
PKMN_OFFSET_ASSERT(MonitoringServerAddressResolveJob, m_Context, 0x58);
PKMN_OFFSET_ASSERT(MonitoringServerAddressResolveJob, field_88, 0x88);
PKMN_OFFSET_ASSERT(MonitoringServerAddressResolveJob, m_Name, 0x90);
PKMN_OFFSET_ASSERT(MonitoringServerAddressResolveJob, field_4b0, 0x4b0);
PKMN_SIZE_ASSERT(MonitoringServerAddressResolveJob, 0x4b8);

}  // namespace common
}  // namespace pia
}  // namespace nn

extern nn::pia::common::Unk_1657ba0_type* Unk_27fa890;
