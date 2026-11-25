// Scope: common
// pead's synchronisation objects: pead::CriticalSection (RTTI
// N4pead15CriticalSectionE) and pead::Event (RTTI N4pead5EventE), both derived
// from pead::IDisposer (RTTI N4pead9IDisposerE, the base their RTTI names),
// then the allocation of a message queue's buffer (no RTTI: Unk_1721740, after
// its constructor in lib/nx_middleware/leaf/Unk_1721740.cpp). Member names are
// placeholders (lib/pia/README.md).
#include "pia/common/Unk_17214f0.h"

namespace pead {

// 0x71017214f0
CriticalSection::CriticalSection() {
    nn::os::InitializeMutex(&m_mutex, true, 0);
}

// 0x7101721530
CriticalSection::CriticalSection(Heap* heap) : IDisposer(heap, 1) {
    nn::os::InitializeMutex(&m_mutex, true, 0);
}

// 0x7101721570 (and 0x71017215b0, deleting)
CriticalSection::~CriticalSection() {
    nn::os::FinalizeMutex(&m_mutex);
}

// 0x71017215f0
void CriticalSection::Unk_17215f0() {
    nn::os::LockMutex(&m_mutex);
}

// 0x7101721600
void CriticalSection::Unk_1721600() {
    nn::os::UnlockMutex(&m_mutex);
}

// 0x7101721610
Event::Event(bool manualClear) {
    nn::os::InitializeEvent(&m_event, false, static_cast<nn::os::EventClearMode>(!manualClear));
}

// 0x7101721660 (and 0x71017216a0, deleting)
Event::~Event() {
    nn::os::FinalizeEvent(&m_event);
}

// 0x71017216e0
void Event::Unk_17216e0() {
    nn::os::WaitEvent(&m_event);
}

// 0x71017216f0
bool Event::Unk_17216f0(nn::os::Tick timeout) {
    return nn::os::TimedWaitEvent(&m_event, nn::os::ConvertToTimeSpan(timeout));
}

// 0x7101721720
void Event::Unk_1721720() {
    nn::os::SignalEvent(&m_event);
}

// 0x7101721730
void Event::Unk_1721730() {
    nn::os::ClearEvent(&m_event);
}

}  // namespace pead

// 0x7101721760
void Unk_1721740::Unk_1721760(int count, pead::Heap* heap) {
    if (count < 1) {
        return;
    }
    // The count is widened unsigned, as a new[] of it would be once it's
    // known not to be negative.
    uintptr_t* buffer = static_cast<uintptr_t*>(operator new(sizeof(uintptr_t) * static_cast<u32>(count), heap));
    if (buffer != nullptr) {
        for (int i = 0; i < count; i++) {
            buffer[i] = 0;
        }
    }
    m_buffer = buffer;
    nn::os::InitializeMessageQueue(&m_queue, buffer, count);
}
