// SiOS's synchronisation objects (RTTI names the classes: SiOSCriticalSection
// and SiOSMutex derive from SiOSSyncObject): each wraps an nn::os mutex.
// Placeholder file name (their translation unit's isn't in the executable)
// and placeholder members; the virtual functions are vf<slot>.
#pragma once

#include <nn/os.h>
#include <types.h>

namespace SiSDK3 {

// How many of each there are (placeholder name): 0x7102771490.
struct Unk_2771490_t {
    s32 field_0;  // critical sections
    s32 field_4;  // mutexes
};

class SiOSSyncObject {
public:
    virtual ~SiOSSyncObject() {}
    virtual bool vf2() = 0;   // locks
    virtual bool vf3() = 0;   // unlocks
    virtual bool vf4() = 0;   // tries to lock
    virtual void* vf5() = 0;  // the nn::os object, if it has one for callers
};

class SiOSCriticalSection : public SiOSSyncObject {
public:
    explicit SiOSCriticalSection(u32 value);
    ~SiOSCriticalSection() override;
    bool vf2() override;
    bool vf3() override;
    bool vf4() override;
    void* vf5() override;

    nn::os::MutexType field_8;
    u32 field_28;
    u32 field_2c;
};
PKMN_SIZE_ASSERT(SiOSCriticalSection, 0x30);

class SiOSMutex : public SiOSSyncObject {
public:
    SiOSMutex();
    ~SiOSMutex() override;
    bool vf2() override;
    bool vf3() override;
    bool vf4() override;
    void* vf5() override;

    nn::os::MutexType field_8;
};
PKMN_SIZE_ASSERT(SiOSMutex, 0x28);

}  // namespace SiSDK3

// A lock held for a scope (placeholder name, after its constructor).
struct Unk_596640 {
    Unk_596640(SiSDK3::SiOSSyncObject* object, bool lock);

    SiSDK3::SiOSSyncObject* field_0;
    bool field_8;  // whether it locked the object
};
