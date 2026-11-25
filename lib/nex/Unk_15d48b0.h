#pragma once
// NEX 4.6.8's scheduler's worker thread (RTTI
// N2nn3nex9Scheduler21SchedulerWorkerThreadE, derived from
// N2nn3nex13WorkerThreadsE) and its Pacer (N2nn3nex5PacerE), as
// lib/nex/Unk_15d48b0.cpp and Unk_15d4cf0.cpp use them.
#include <nn/nex/RootObject.h>

// What the scheduler's worker thread runs for (its +0x1b0: the instance index
// the thread takes).
struct Unk_15d4ca0_Scheduler {
    u8 _0[0x1b0];
    u32 m_instanceIndex;
};
PKMN_OFFSET_ASSERT(Unk_15d4ca0_Scheduler, m_instanceIndex, 0x1b0);

namespace nn {
namespace nex {

// N2nn3nex13WorkerThreadsE (its slot 4 is pure).
class WorkerThreads : public RootObject {
public:
    ~WorkerThreads() override;
    virtual void vf2();
    virtual void vf3();
    virtual void vf4() = 0;

    u8 _8[0x68];
};
PKMN_SIZE_ASSERT(WorkerThreads, 0x70);

// N2nn3nex5PacerE
class Pacer : public RootObject {
public:
    ~Pacer() override;
    // 0x71015cea50
    virtual void vf2();

    u8 _8[0xc8];
};
PKMN_SIZE_ASSERT(Pacer, 0xd0);

// N2nn3nex9Scheduler21SchedulerWorkerThreadE
class Scheduler {
public:
    class SchedulerWorkerThread : public WorkerThreads {
    public:
        ~SchedulerWorkerThread() override;
        void vf2() override;
        void vf4() override;

        Unk_15d4ca0_Scheduler* m_scheduler;
        Pacer m_pacer;
        u32 field_148;
        u32 field_14c;
    };
};
PKMN_OFFSET_ASSERT(Scheduler::SchedulerWorkerThread, m_scheduler, 0x70);
PKMN_OFFSET_ASSERT(Scheduler::SchedulerWorkerThread, m_pacer, 0x78);
PKMN_OFFSET_ASSERT(Scheduler::SchedulerWorkerThread, field_148, 0x148);

}  // namespace nex
}  // namespace nn
