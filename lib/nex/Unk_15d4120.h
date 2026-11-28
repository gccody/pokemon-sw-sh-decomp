#pragma once
// NEX 4.6.8's thread-safe call policy (RTTI N2nn3nex20ThreadSafeCallPolicyE: a
// recursive lock over a CriticalSection, with its owner's thread ID), as
// lib/nex/Unk_15d4120.cpp and Unk_15d46a0.cpp use it. Its slots without a name
// in the executable are placeholders (vf<slot>).
#include <nn/nex/RootObject.h>
#include <nn/os.h>

namespace nn {
namespace nex {

// N2nn3nex14MutexPrimitiveE (lib/nex/Unk_15b9290.cpp defines it): only what
// this code uses.
class MutexPrimitive {
public:
    virtual ~MutexPrimitive();

    nn::os::MutexType m_mutex;
};
PKMN_SIZE_ASSERT(MutexPrimitive, 0x28);

// N2nn3nex15CriticalSectionE (lib/nex/Unk_15b9290.cpp defines it): slot 2
// enters it, slot 4 leaves it.
class CriticalSection : public RootObject {
public:
    // 0x71015b9300
    ~CriticalSection() override;
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual u32 vf5();
    virtual u32 vf6();

    MutexPrimitive m_mutex;
    // a N2nn3nex11LockCheckerE
    u8 m_checker[0x18];
};
PKMN_OFFSET_ASSERT(CriticalSection, m_mutex, 0x8);
PKMN_SIZE_ASSERT(CriticalSection, 0x48);

// N2nn3nex20ThreadSafeCallPolicyE
class ThreadSafeCallPolicy : public RootObject {
public:
    // 0x71015d4760 (D2), 0x71015d4780 (D0)
    ~ThreadSafeCallPolicy() override;
    // 0x71015d47c0 (lib/nx_middleware/class): m_lockCount
    virtual u32 vf2();
    // 0x71015d41b0: whether the calling thread holds the lock.
    virtual bool vf3();
    // 0x71015d41e0: whether another thread holds it.
    virtual bool vf4();
    // 0x71015d4120: tries to take it.
    virtual bool vf5();
    // 0x71015d4180: releases it.
    virtual void vf6();

    CriticalSection m_cs;
    u32 m_lockCount;
    // the owner's thread ID, -1 when it's free
    u64 m_owner;
};
PKMN_OFFSET_ASSERT(ThreadSafeCallPolicy, m_lockCount, 0x50);
PKMN_OFFSET_ASSERT(ThreadSafeCallPolicy, m_owner, 0x58);
PKMN_SIZE_ASSERT(ThreadSafeCallPolicy, 0x60);

}  // namespace nex
}  // namespace nn
