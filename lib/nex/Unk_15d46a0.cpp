// Scope: common
// NEX 4.6.8: Job's destructor (RTTI N2nn3nex3JobE), the call policies'
// destructors (N2nn3nex22SingleThreadCallPolicyE,
// N2nn3nex20ThreadSafeCallPolicyE), and the slot 3 of SystemComponent
// (N2nn3nex15SystemComponentE) and two of its derived classes
// (N2nn3nex19CallContextRegisterE, N2nn3nex20SystemComponentGroupE): whether
// the object is of the class named, by the names of its class and bases. The
// members without a name in the executable are placeholders.
#include <atomic>
#include <cstring>

#include "Unk_15d4120.h"

namespace nn {
namespace nex {

// N2nn3nex16RefCountedObjectE, with the inline destructor Job's inlines
// (<nn/nex/RefCountedObject.h> declares it out of line; lib/nex/Unk_15c64b0.h
// explains why it doesn't derive from RootObject here). Its operator new and
// delete are RootObject's.
class RefCountedObject {
public:
    static void* operator new(size_t size) noexcept { return Unk_15b6dc0(size); }
    static void operator delete(void* p) { Unk_15b6e10(p); }

    virtual ~RefCountedObject() {}

    // (an anonymous union: the empty destructor still stores the vtable)
    union {
        std::atomic<s32> m_count;
    };
    bool m_deleting;
};
PKMN_SIZE_ASSERT(RefCountedObject, 0x10);

// N2nn3nex3JobE: only its slots (lib/nex/Unk_15d48b0.h has its members).
class Job : public RefCountedObject {
public:
    ~Job() override;
    virtual void vf2();
    virtual void vf3() = 0;
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();

    u8 _10[0x58];
};
PKMN_SIZE_ASSERT(Job, 0x68);

// 0x71015d46a0
Job::~Job() {}

// N2nn3nex22SingleThreadCallPolicyE: the call policy without a lock.
class SingleThreadCallPolicy : public RootObject {
public:
    // 0x71015d4740 (D0; its D2 is a `ret` shared with other classes)
    ~SingleThreadCallPolicy() override;
    // 0x71015d4750 (lib/nx_middleware/class): m_lockCount
    virtual u32 vf2();
    virtual bool vf3();
    virtual bool vf4();
    virtual bool vf5();
    virtual void vf6();

    u32 m_lockCount;
};
PKMN_SIZE_ASSERT(SingleThreadCallPolicy, 0x10);

SingleThreadCallPolicy::~SingleThreadCallPolicy() {}

ThreadSafeCallPolicy::~ThreadSafeCallPolicy() {}

// N2nn3nex15SystemComponentE: only its slots 2 and 3.
class SystemComponent : public RootObject {
public:
    ~SystemComponent() override;
    // 0x71015d47d0 (lib/nx_middleware/class): the class's name
    virtual const char* vf2();
    // 0x71015d47e0: whether the object is of the class `name`
    virtual bool vf3(const char* name);
};

bool SystemComponent::vf3(const char* name) {
    return strcmp("SystemComponent", name) == 0;
}

// N2nn3nex19CallContextRegisterE
class CallContextRegister : public SystemComponent {
public:
    // 0x71015d46d0
    bool vf3(const char* name) override;
};

bool CallContextRegister::vf3(const char* name) {
    if (strcmp("CallContextRegister", name) == 0) {
        return true;
    }
    return SystemComponent::vf3(name);
}

// N2nn3nex20SystemComponentGroupE
class SystemComponentGroup : public SystemComponent {
public:
    // 0x71015d4840
    bool vf3(const char* name) override;
};

bool SystemComponentGroup::vf3(const char* name) {
    if (strcmp("SystemComponentGroup", name) == 0) {
        return true;
    }
    return SystemComponent::vf3(name);
}

}  // namespace nex
}  // namespace nn
