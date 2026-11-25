// Scope: common
// NEX 4.6.8: Operation (RTTI N2nn3nex9OperationE, the base of
// CallProtocolMethodOperation and the RendezVous login and logout operations),
// the job that signals a call context (N2nn3nex20JobSignalCallContextE), and
// the scheduler's worker thread (N2nn3nex9Scheduler21SchedulerWorkerThreadE).
// The members without a name in the executable are placeholders.
#include <map>

#include <nn/nex/Call.h>
#include <nn/nex/RefCountedObject.h>
#include <nn/nex/qVector.h>

namespace nn {
namespace nex {

class CallContext;

// N2nn3nex9OperationE: its slots 3 to 5 are pure (the type, its name, ...).
class Operation : public RootObject {
public:
    ~Operation() override;
    // 0x71015d4910: vf3's value, narrowed (the call isn't a tail call: the
    // return types differ).
    virtual u32 vf2() { return static_cast<u32>(vf3()); }
    virtual u64 vf3() = 0;
    virtual const char* vf4() = 0;
    virtual void vf5() = 0;

    u8 _8[0x18];
};
PKMN_SIZE_ASSERT(Operation, 0x20);

// 0x71015d48f0 (D2), 0x71015d4900 (D0: a trap, the class is abstract)
Operation::~Operation() {}

// N2nn3nex3JobE (as lib/nex/Unk_1630ba0.cpp declares it). Its members end at
// 0x62: a derived class's begin in its tail padding.
class Job : public RefCountedObject {
public:
    ~Job() override;
    virtual void vf2();
    virtual void vf3() = 0;
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();

    u64 field_10;
    u64 field_18;
    u8 field_20;
    // called when the job is done (state 5), with the job and m_callbackData
    void (*m_callback)(Job* job, void* data);
    u32 m_callbackData;
    u32 field_34;
    u32 m_type;
    u32 field_3c;
    u32 m_state;
    u32 field_44;
    u32 field_48;
    u64 field_50;
    u64 field_58;
    u8 field_60;
    u8 field_61;
};
PKMN_OFFSET_ASSERT(Job, m_callback, 0x28);
PKMN_OFFSET_ASSERT(Job, m_state, 0x40);
PKMN_OFFSET_ASSERT(Job, field_61, 0x61);
PKMN_SIZE_ASSERT(Job, 0x68);

// N2nn3nex20JobSignalCallContextE: gives the call context with the ID
// m_contextId its result.
class JobSignalCallContext : public Job {
public:
    ~JobSignalCallContext() override;
    void vf3() override;

    u32 m_contextId;
    Unk_15bbc10 m_result;
};
PKMN_OFFSET_ASSERT(JobSignalCallContext, m_contextId, 0x64);
PKMN_OFFSET_ASSERT(JobSignalCallContext, m_result, 0x68);
PKMN_SIZE_ASSERT(JobSignalCallContext, 0x80);

}  // namespace nex
}  // namespace nn

// 0x71015c95d0: sets a call context's state (2: success, 3: failure) and result.
void Unk_15c95d0(nn::nex::CallContext* ctx, u32 state, Unk_15bbc10 result, bool arg3);

// 0x71015bbc90 (lib/nx_middleware/leaf): whether a result's success is `value`.
struct Unk_15bbc90;
struct Unk_15bbc90_arg1;
bool Unk_15bbc90_check(const Unk_15bbc90* self, const Unk_15bbc90_arg1* value);

// The call contexts by ID, in the core's holder.
struct Unk_15d49d0_Register {
    u8 _0[0x48];
    std::map<u32, nn::nex::CallContext*, std::less<u32>,
             nn::nex::MemAllocator<std::pair<const u32, nn::nex::CallContext*>>>
        m_contexts;
};
PKMN_OFFSET_ASSERT(Unk_15d49d0_Register, m_contexts, 0x48);

struct Unk_15d49d0_Holder : Unk_CoreHolder {
    Unk_15d49d0_Register* m_register;
};
PKMN_OFFSET_ASSERT(Unk_15d49d0_Holder, m_register, 0x18);

namespace nn {
namespace nex {

// 0x71015d4990 (D2), 0x71015d49b0 (D0)
// NON_MATCHING: the original inlines Job's and RefCountedObject's destructors
// (a store of RefCountedObject's vtable); RefCountedObject's is out of line in
// RefCountedObject.h, Job's in another unit.
JobSignalCallContext::~JobSignalCallContext() {}

// A call context's new state and result.
static void SetContextState(CallContext* ctx, u32 state, Unk_15bbc10 result) {
    Unk_15c95d0(ctx, state, result, true);
}

// The context's success (2) or failure (3), with the result.
static void SignalSuccess(CallContext* ctx, const Unk_15bbc10& result) {
    SetContextState(ctx, 2, result);
}
static void SignalFailure(CallContext* ctx, const Unk_15bbc10& result) {
    SetContextState(ctx, 3, result);
}

// 0x71015d49d0
// NON_MATCHING: the original makes the first copy of the result in each branch;
// here it's hoisted above the branch (the same stack slots, the same copies).
void JobSignalCallContext::vf3() {
    Unk_15d49d0_Holder* holder = static_cast<Unk_15d49d0_Holder*>(GetInstance()->m_holder);
    auto& contexts = holder->m_register->m_contexts;
    auto it = contexts.find(m_contextId);
    if (it != contexts.end()) {
        CallContext* ctx = it->second;
        if (ctx != nullptr) {
            Unk_15bbc10 result = m_result;
            bool success = true;
            if (Unk_15bbc90_check(reinterpret_cast<const Unk_15bbc90*>(&result),
                                  reinterpret_cast<const Unk_15bbc90_arg1*>(&success))) {
                SignalSuccess(ctx, result);
            } else {
                SignalFailure(ctx, result);
            }
        }
    }
    m_state = 5;
    if (m_callback != nullptr) {
        m_callback(this, &m_callbackData);
    }
}

}  // namespace nex
}  // namespace nn
