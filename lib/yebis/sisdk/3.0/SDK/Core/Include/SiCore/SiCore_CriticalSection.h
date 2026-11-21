// SiSDK3::SiCoreCriticalSection (RTTI) and the scoped lock SiSDK3's classes
// take on one (placeholder name, after its constructor, 0x71004c87b0).
#pragma once

#include <nn/os.h>
#include <types.h>

namespace SiSDK3 {

class ISiCriticalSection {
public:
    virtual ~ISiCriticalSection() {}
    virtual bool vf2() = 0;  // locks
    virtual bool vf3() = 0;  // unlocks
    virtual bool vf4() = 0;  // tries to lock
    virtual void* vf5() = 0;
};

class SiCoreCriticalSection : public ISiCriticalSection {
public:
    SiCoreCriticalSection();            // 0x71004c86a0
    ~SiCoreCriticalSection() override;  // 0x71004c86e0, 0x71004c8710
    bool vf2() override;                // 0x71004c8760
    bool vf3() override;                // 0x71004c8780
    bool vf4() override;                // 0x71004c87a0
    void* vf5() override;               // 0x71004c8830

    nn::os::MutexType field_8;
};

}  // namespace SiSDK3

// 0x71004c87f0 (lib/yebis/leaf): the scoped lock's destructor, under the name
// leafgen gave it
struct Unk_4c87f0;
void Unk_4c87f0_call(Unk_4c87f0* self);

// locks a critical section for a scope
class Unk_4c87b0 {
public:
    Unk_4c87b0(SiSDK3::ISiCriticalSection* pCriticalSection, bool lock);  // 0x71004c87b0
    ~Unk_4c87b0() { Unk_4c87f0_call(reinterpret_cast<Unk_4c87f0*>(this)); }

    SiSDK3::ISiCriticalSection* field_0;
    bool field_8;  // locked
};
