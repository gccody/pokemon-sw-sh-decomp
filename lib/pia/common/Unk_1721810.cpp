// Scope: common
// The message queue holder's other members (Unk_1721740,
// lib/pia/common/Unk_17214f0.h), pead::Mutex (RTTI N4pead5MutexE, derived from
// pead::IDisposer) and two thread helpers.
// Member names are placeholders (lib/pia/README.md).
#include "pia/common/Unk_17214f0.h"

u64 Unk_17163e0(void* memory);

// 0x7101721810
void Unk_1721740::Unk_1721810() {
    nn::os::FinalizeMessageQueue(&m_queue);
    uintptr_t* buffer = m_buffer;
    if (buffer != nullptr) {
        Unk_17163e0(buffer);
        Unk_1716390(buffer);
        m_buffer = nullptr;
    }
}

// 0x7101721850
bool Unk_1721740::Unk_1721850(uintptr_t message, int type) {
    if (type != 0) {
        return nn::os::TrySendMessageQueue(&m_queue, message);
    }
    nn::os::SendMessageQueue(&m_queue, message);
    return true;
}

// 0x7101721870
uintptr_t Unk_1721740::Unk_1721870(int type) {
    uintptr_t message;
    if (type != 0) {
        if (!nn::os::TryReceiveMessageQueue(&message, &m_queue)) {
            return 0;
        }
        return message;
    }
    nn::os::ReceiveMessageQueue(&message, &m_queue);
    return message;
}

// 0x71017218c0
bool Unk_1721740::Unk_17218c0(uintptr_t message, int type) {
    if (type != 0) {
        return nn::os::TryJamMessageQueue(&m_queue, message);
    }
    nn::os::JamMessageQueue(&m_queue, message);
    return true;
}

namespace pead {

class Mutex : public IDisposer {
public:
    Mutex();
    ~Mutex() override;

    void Unk_17219a0();
    void Unk_17219b0();

    nn::os::MutexType m_mutex;
};
PKMN_OFFSET_ASSERT(Mutex, m_mutex, 0x20);
PKMN_SIZE_ASSERT(Mutex, 0x40);

// 0x71017218e0
Mutex::Mutex() {
    nn::os::InitializeMutex(&m_mutex, true, 0);
}

// 0x7101721920 (and 0x7101721960, deleting)
Mutex::~Mutex() {
    nn::os::FinalizeMutex(&m_mutex);
}

// 0x71017219a0
void Mutex::Unk_17219a0() {
    nn::os::LockMutex(&m_mutex);
}

// 0x71017219b0
void Mutex::Unk_17219b0() {
    nn::os::UnlockMutex(&m_mutex);
}

}  // namespace pead

// 0x7101721d90
void Unk_1721d90(nn::os::Tick time) {
    nn::os::SleepThread(nn::os::ConvertToTimeSpan(time));
}

// 0x7101721db0
void Unk_1721db0() {
    nn::os::YieldThread();
}
