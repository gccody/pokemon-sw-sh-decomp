// Scope: common
//
// gflib3's TLSF pool resource (its asserts name
// lib/gflib3/src/mem/tlsf_pool_resource.cpp): a memory resource with two
// vtables that owns a TLSF pool (mem/internal/tlsf_pool.cpp) and guards it
// with an owner thread and a light event. And a static object of the same
// code, created on first use. Its TU is not the heap globals'
// (src/gflib3/Unk_65d670.cpp): its guard and object (0x7102778768) are far
// from theirs.
#include "gflib3/Unk_65f110.h"

// 0x710065f110
Unk_2778770* Unk_65f110() {
    static Unk_2778770 instance;
    return &instance;
}

// 0x710065f1c0
Unk_239f910::Unk_239f910(void* memory, u64 size, void* arg)
    : Unk_239f9e8(arg),
      m_pool(memory, size),
      field_98(0),
      m_event(nn::os::EventClearMode(1), false),
      m_owner(nullptr) {}

// 0x710065f220, 0x710065f300 (D0), 0x710065f2f0 and 0x710065f330 (their thunks from the secondary
// base)
Unk_239f910::~Unk_239f910() {
    nn::os::ThreadType* self = nn::os::GetCurrentThread();
    nn::os::ThreadType* expected = nullptr;
    while (!m_owner.compare_exchange_strong(expected, self, std::memory_order_acquire)) {
        expected = nullptr;
        m_event.Wait();
    }
    if (!Unk_65f070(&m_pool))
        Unk_65f360(this);
    Unk_65edc0(&m_pool);
    m_owner.exchange(nullptr, std::memory_order_release);
    m_event.Signal();
}
