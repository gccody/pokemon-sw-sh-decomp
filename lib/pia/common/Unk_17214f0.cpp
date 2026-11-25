// Scope: common
// pead's synchronisation objects: pead::CriticalSection (RTTI
// N4pead15CriticalSectionE) and pead::Event (RTTI N4pead5EventE), both derived
// from pead::IDisposer (RTTI N4pead9IDisposerE, the base their RTTI names),
// then the allocation of a message queue's buffer (no RTTI: Unk_1721740, after
// its constructor in lib/nx_middleware/leaf/Unk_1721740.cpp). Member names are
// placeholders (lib/pia/README.md).
#include "pia/common/Unk_17162d0.h"

#include <nn/os.h>

namespace nn {
namespace os {

// From the imports' mangled names. pead::Event keeps one at 0x20.
struct EventType {
    u8 field_0[0x28];
};
// 0x48 bytes: Unk_1721740 keeps its buffer right after it.
struct MessageQueueType {
    u8 field_0[0x48];
};
void WaitEvent(EventType* event) noexcept;
bool TimedWaitEvent(EventType* event, TimeSpan timeout) noexcept;
void InitializeMessageQueue(MessageQueueType* queue, uintptr_t* buffer, size_t count) noexcept;

}  // namespace os
}  // namespace nn

namespace pead {

// 0x20 bytes: its constructors (0x710171a7f0, 0x710171a850) register it with a
// heap, at 0x8.
class IDisposer {
public:
    IDisposer();
    IDisposer(Heap* heap, int option);
    virtual ~IDisposer();

    Heap* m_heap;
    u8 _10[0x10];
};
PKMN_SIZE_ASSERT(IDisposer, 0x20);

class CriticalSection : public IDisposer {
public:
    CriticalSection();
    explicit CriticalSection(Heap* heap);
    ~CriticalSection() override;

    void Unk_17215f0();
    void Unk_1721600();

    nn::os::MutexType m_mutex;
};
PKMN_OFFSET_ASSERT(CriticalSection, m_mutex, 0x20);
PKMN_SIZE_ASSERT(CriticalSection, 0x40);

class Event : public IDisposer {
public:
    explicit Event(bool manualClear);
    ~Event() override;

    void Unk_17216e0();
    bool Unk_17216f0(nn::os::Tick timeout);
    void Unk_1721720();
    void Unk_1721730();

    nn::os::EventType m_event;
};
PKMN_OFFSET_ASSERT(Event, m_event, 0x20);

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

// 0x50 bytes: an nn::os::MessageQueueType, then its buffer.
class Unk_1721740 {
public:
    void Unk_1721760(int count, pead::Heap* heap);

    nn::os::MessageQueueType m_queue;
    uintptr_t* m_buffer;
};
PKMN_OFFSET_ASSERT(Unk_1721740, m_buffer, 0x48);

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
