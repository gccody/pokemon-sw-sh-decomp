// Scope: common
// NEX 4.6.8: the scheduler's worker thread's slot 4, ...
#include "Unk_15d48b0.h"

// 0x71015d0da0
void Unk_15d0da0(void* self, u32 arg1, u32 arg2);

namespace nn {
namespace nex {

// 0x71015d4cf0
void Scheduler::SchedulerWorkerThread::vf4() {
    Unk_15d0da0(m_scheduler, field_14c, field_148);
    m_pacer.vf2();
}

}  // namespace nex
}  // namespace nn
