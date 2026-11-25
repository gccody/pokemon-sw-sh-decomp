#pragma once
// local::LocalEjectClientListCheckJob (RTTI N2nn3pia5local28LocalEjectClientListCheckJobE)
// and the job it runs, local::LocalEjectClientBackgroundJob (RTTI
// N2nn3pia5local29LocalEjectClientBackgroundJobE), both derived from
// common::StepSequenceJob (RTTI N2nn3pia6common15StepSequenceJobE). Each is a
// TU of its own in the original: Unk_16998e0.cpp and Unk_1699e40.cpp. Their
// vf5 are in lib/nx_middleware/class/nn_pia_local_LocalEjectClient*Job.cpp.
//
// The steps' names are the strings stored with them ("Class::Function").
// Other names are placeholders (lib/pia/README.md).
#include "pia/common/Unk_165e060.h"

// The 16 bytes of an address and a port (lib/pia/common/Unk_1749cd0.h). Its
// destructor is slot 0 of its vtable (0x7102456bd0), an empty function.
namespace nn {
namespace pia {

class Unk_1652c70 {
public:
    virtual ~Unk_1652c70();

    Unk_1652c70& Unk_1652cf0(const Unk_1652c70& other);

    u8 field_8[0x10];
    u16 field_18;
};
PKMN_OFFSET_ASSERT(Unk_1652c70, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_1652c70, field_18, 0x18);
PKMN_SIZE_ASSERT(Unk_1652c70, 0x20);

// common::StationAddress (its vtable 0x7102457108 holds
// _ZN2nn3pia6common14StationAddress3vf5Ev); it keeps its constructor's
// placeholder name here. Its destructor is inline: callers store the vtable and
// destroy the Unk_1652c70.
class Unk_165fb30 {
public:
    Unk_165fb30();
    Unk_165fb30(const Unk_165fb30& other);
    virtual ~Unk_165fb30() {}

    virtual void vf2();

    Unk_165fb30& operator=(const Unk_165fb30& other);

    Unk_1652c70 field_8;
};
PKMN_OFFSET_ASSERT(Unk_165fb30, field_8, 0x8);
PKMN_SIZE_ASSERT(Unk_165fb30, 0x28);

}  // namespace pia
}  // namespace nn

// What an address is written into for a log (placeholder; Unk_1653bb0_update is
// empty).
struct Unk_1653bb0_arg1 {
    Unk_1653bb0_arg1() {
        field_8 = 0;
        field_0 = 0x10;
        field_4 = 0;
    }

    u32 field_0;
    u32 field_4;
    u32 field_8;
};
void Unk_1653bb0_update(void* self, void* out);
void Unk_1653900(void* self);                     // clears an Unk_1652c70

// What a job reports back to (placeholder type, after its constructor
// 0x7101655080): a state (1 running, 2 done, 3 failed), a result and a
// callback.
struct Unk_1655190;
struct Unk_1655080 {
    void Unk_1655110();                                   // reset
    void Unk_16551b0(nn::pia::Unk_165e060 result);        // state 2, callback
    void Unk_1655220(nn::pia::Unk_165e060 result);        // state 3, callback

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
void Unk_1655170_update(u64 self);              // its destructor (empty)
u32 Unk_1655190_update(Unk_1655190* self);      // state 1

// A list the protocol checks addresses against (placeholder: only its slot 6 is
// called).
class Unk_1699ae0_list {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual bool vf6(const nn::pia::Unk_1652c70* address);
};

// What the jobs are created for (placeholder: the ListCheckJob constructor's
// argument): ejecting a client is its slot 35.
class Unk_16997e0_arg1 {
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
    virtual nn::pia::Unk_165e060 vf35(const nn::pia::Unk_1652c70* address);

    u8 _8[0x308 - 0x8];
    Unk_1699ae0_list* field_308;
};
PKMN_OFFSET_ASSERT(Unk_16997e0_arg1, field_308, 0x308);

namespace nn {
namespace pia {
namespace common {

// A job's base (vtable 0x7102456ef8, constructor 0x7101655760; no RTTI name).
class Unk_1655760 {
public:
    virtual ~Unk_1655760();

    void Unk_1655850(bool arg);  // starts it
    bool Unk_1655a80();          // whether it's running

    u8 _8[0x28 - 0x8];
};

// What a step returns (placeholder: StepSequenceJob's vf3, 0x710165bb20, takes
// it apart): 0 runs the next step at once, 1 ends the job, 5 waits; field_2 is
// a wait (in a step that waits for one).
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

    virtual void vf2(bool arg);
    virtual void vf3();
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

class LocalEjectClientBackgroundJob : public common::StepSequenceJob {
public:
    explicit LocalEjectClientBackgroundJob(Unk_16997e0_arg1* owner);
    ~LocalEjectClientBackgroundJob() override;

    void vf5() override;

    Unk_165e060 Unk_1699f40(Unk_1655080* context, const Unk_165fb30& target);
    common::Unk_165bb20_result EjectClient();
    void Unk_169a0d0();

    Unk_1655080* m_Context;
    Unk_165fb30 m_Target;
    Unk_16997e0_arg1* m_Owner;
};
PKMN_OFFSET_ASSERT(LocalEjectClientBackgroundJob, m_Context, 0x58);
PKMN_OFFSET_ASSERT(LocalEjectClientBackgroundJob, m_Target, 0x60);
PKMN_OFFSET_ASSERT(LocalEjectClientBackgroundJob, m_Owner, 0x88);
PKMN_SIZE_ASSERT(LocalEjectClientBackgroundJob, 0x90);

// A queue of addresses in a ring buffer (placeholder: inline in the job).
template <typename T>
class Unk_1699ae0_queue {
public:
    s32 Index(s32 i) const {
        s32 index = m_Head + i;
        return index < m_Capacity ? index : index - m_Capacity;
    }
    T& Front() {
        if (m_Count > 0) {
            return m_Data[Index(0)];
        }
        return m_Data[0];
    }
    void PopFront() {
        if (m_Count > 0) {
            m_Head = m_Head + 1 < m_Capacity ? m_Head + 1 : 0;
            m_Count--;
        }
    }
    bool PushBack(const T& value) {
        if (m_Count >= m_Capacity) {
            return false;
        }
        m_Count++;
        m_Data[Index(m_Count - 1)] = value;
        return true;
    }
    void Clear() {
        m_Head = 0;
        m_Count = 0;
    }

    T* m_Data;
    s32 m_Capacity;
    s32 m_Head;
    s32 m_Count;
};

class LocalEjectClientListCheckJob : public common::StepSequenceJob {
public:
    explicit LocalEjectClientListCheckJob(Unk_16997e0_arg1* owner);
    ~LocalEjectClientListCheckJob() override;

    void vf5() override;

    Unk_165e060 Unk_16999d0();
    common::Unk_165bb20_result CheckTargetList();
    void Unk_1699a90();
    bool Unk_1699ae0(const Unk_165fb30& address);
    common::Unk_165bb20_result EjectTargetClient();
    common::Unk_165bb20_result WaitEjectTargetClient();
    common::Unk_165bb20_result WaitBackgroundJobEnd();

    LocalEjectClientBackgroundJob* m_BackgroundJob;
    Unk_165fb30 m_Addresses[7];
    Unk_1699ae0_queue<Unk_165fb30> m_Queue;
    Unk_1655080 m_Context;
    Unk_16997e0_arg1* m_Owner;
};
PKMN_OFFSET_ASSERT(LocalEjectClientListCheckJob, m_BackgroundJob, 0x58);
PKMN_OFFSET_ASSERT(LocalEjectClientListCheckJob, m_Addresses, 0x60);
PKMN_OFFSET_ASSERT(LocalEjectClientListCheckJob, m_Queue, 0x178);
PKMN_OFFSET_ASSERT(LocalEjectClientListCheckJob, m_Context, 0x190);
PKMN_OFFSET_ASSERT(LocalEjectClientListCheckJob, m_Owner, 0x1c0);
PKMN_SIZE_ASSERT(LocalEjectClientListCheckJob, 0x1c8);

}  // namespace local
}  // namespace pia
}  // namespace nn
