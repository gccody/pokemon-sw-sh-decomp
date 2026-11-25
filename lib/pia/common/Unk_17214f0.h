#pragma once
// pead's synchronisation objects and the message queue holder
// (lib/pia/common/Unk_17214f0.cpp, lib/pia/common/Unk_1721810.cpp).
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
void FinalizeMessageQueue(MessageQueueType* queue) noexcept;
void SendMessageQueue(MessageQueueType* queue, uintptr_t message) noexcept;
bool TrySendMessageQueue(MessageQueueType* queue, uintptr_t message) noexcept;
void JamMessageQueue(MessageQueueType* queue, uintptr_t message) noexcept;
bool TryJamMessageQueue(MessageQueueType* queue, uintptr_t message) noexcept;
void ReceiveMessageQueue(uintptr_t* message, MessageQueueType* queue) noexcept;
bool TryReceiveMessageQueue(uintptr_t* message, MessageQueueType* queue) noexcept;

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

}  // namespace pead

class Unk_1721740;
// Its constructor and destructor, out of line (lib/nx_middleware/leaf/Unk_1721740.cpp,
// written before the class was known: the destructor's parameter is its `this`).
void Unk_1721740_set(Unk_1721740* self);
void Unk_1721750_update(u64 self);

// 0x50 bytes: an nn::os::MessageQueueType, then its buffer.
class Unk_1721740 {
public:
    Unk_1721740() { Unk_1721740_set(this); }
    ~Unk_1721740() { Unk_1721750_update(reinterpret_cast<u64>(this)); }

    void Unk_1721760(int count, pead::Heap* heap);
    void Unk_1721810();
    bool Unk_1721850(uintptr_t message, int type);
    uintptr_t Unk_1721870(int type);
    bool Unk_17218c0(uintptr_t message, int type);

    nn::os::MessageQueueType m_queue;
    uintptr_t* m_buffer;
};
PKMN_OFFSET_ASSERT(Unk_1721740, m_buffer, 0x48);
