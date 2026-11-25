// Scope: common
// NEX 4.6.8: the scheduler's worker thread's slot 4, SecurityContext's
// destructors (RTTI N2nn3nex15SecurityContextE), slots of
// MethodCallJob<CallContextRegister, int, PeriodicJob> (RTTI
// N2nn3nex13MethodCallJobINS0_19CallContextRegisterEiNS0_11PeriodicJobEEE,
// declared by lib/nx_middleware/class: written here as free functions over its
// layout), and the destroy function of a tree.
#include <map>

#include <nn/nex/InstanceTable.h>
#include <nn/nex/String.h>
#include <nn/nex/qList.h>
#include <nn/nex/qVector.h>

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

// The node of a std::map-style tree of trivially destroyed values (libc++'s
// __tree_node); the tree isn't known.
struct Unk_15d4d20_Node {
    Unk_15d4d20_Node* m_left;
    Unk_15d4d20_Node* m_right;
};

// 0x71015d4d20: frees a subtree with NEX's allocator.
void Unk_15d4d20(void* tree, Unk_15d4d20_Node* node) {
    if (node != nullptr) {
        Unk_15d4d20(tree, node->m_left);
        Unk_15d4d20(tree, node->m_right);
        Unk_15b9390(reinterpret_cast<u64>(node));
    }
}

namespace nn {
namespace nex {

// N2nn3nex15SecurityContextE
class SecurityContext : public RootObject {
public:
    ~SecurityContext() override;
};

// 0x71015d4d60 (D0; its D2 is a `ret` shared with other classes)
SecurityContext::~SecurityContext() {}

class CallContextRegister;

}  // namespace nex
}  // namespace nn

// MethodCallJob<CallContextRegister, int, PeriodicJob> (named after its
// vtable): a job that calls a member function of an object with an int.
struct Unk_24506a8 {
    u8 _0[0x68];
    void (nn::nex::CallContextRegister::*m_method)(int);
    nn::nex::CallContextRegister* m_object;
    int m_arg;
};
PKMN_OFFSET_ASSERT(Unk_24506a8, m_method, 0x68);
PKMN_OFFSET_ASSERT(Unk_24506a8, m_object, 0x78);
PKMN_OFFSET_ASSERT(Unk_24506a8, m_arg, 0x80);

// 0x71015d4f00: its slot 3, the call.
void Unk_15d4f00(Unk_24506a8* self) {
    (self->m_object->*self->m_method)(self->m_arg);
}

// 0x71015beab0: the calling thread's ID.
u64 Unk_15beab0();

// A critical section, held for the scope.
class Unk_15d5220_Lock {
public:
    explicit Unk_15d5220_Lock(nn::nex::CriticalSection* cs) : m_cs(cs) { m_cs->vf2(); }
    ~Unk_15d5220_Lock() { m_cs->vf4(); }

private:
    nn::nex::CriticalSection* m_cs;
};

namespace nn {
namespace nex {

// N2nn3nex18ThreadVariableRootE (lib/nx_middleware/class declares only its
// slots 2 to 4, empty).
class ThreadVariableRoot : public RootObject {
public:
    // 0x71015be820
    ~ThreadVariableRoot() override;
    virtual void vf2();
    virtual void vf3();
    virtual void vf4(u64 threadId);

    u8 _8[0x10];
};
PKMN_SIZE_ASSERT(ThreadVariableRoot, 0x18);

// N2nn3nex14ThreadVariableINS0_5qListINS0_15SecurityContextEEEEE: a value per
// thread, by thread ID, under a critical section.
template <class T>
class ThreadVariable : public ThreadVariableRoot {
public:
    ~ThreadVariable() override;

    // Forgets every thread's value.
    void vf2() override {
        Unk_15d5220_Lock lock(&m_cs);
        while (m_values.size() != 0) {
            m_values.erase(m_values.begin());
        }
    }

    // Forgets the calling thread's value.
    void vf3() override {
        Unk_15d5220_Lock lock(&m_cs);
        auto it = m_values.find(Unk_15beab0());
        if (it != m_values.end()) {
            m_values.erase(it);
        }
    }

    // Forgets a thread's value.
    void vf4(u64 threadId) override {
        Unk_15d5220_Lock lock(&m_cs);
        auto it = m_values.find(threadId);
        if (it != m_values.end()) {
            m_values.erase(it);
        }
    }

    T m_default;
    CriticalSection m_cs;
    u8 _38[0x40];
    std::map<u64, T, std::less<u64>, MemAllocator<std::pair<const u64, T>>> m_values;
};
PKMN_OFFSET_ASSERT(ThreadVariable<qList<SecurityContext>>, m_default, 0x18);
PKMN_OFFSET_ASSERT(ThreadVariable<qList<SecurityContext>>, m_cs, 0x30);
PKMN_OFFSET_ASSERT(ThreadVariable<qList<SecurityContext>>, m_values, 0x78);

// 0x71015d2210 (D2, another unit's), 0x71015d51f0 (D0)
// NON_MATCHING (D2 only): the original destroys the CriticalSection with its
// out-of-line destructor (0x71015b9300), which InstanceTable.h doesn't declare.
template <class T>
ThreadVariable<T>::~ThreadVariable() {
    Unk_15d5220_Lock lock(&m_cs);
    while (m_values.size() != 0) {
        m_values.erase(m_values.begin());
    }
}

// 0x71015d5220 (slot 2), 0x71015d5290 (slot 3), 0x71015d5320 (slot 4)
template class ThreadVariable<qList<SecurityContext>>;

}  // namespace nex
}  // namespace nn

namespace nn {
namespace nex {

// N2nn3nex18DefaultChainPolicyIPNS0_3JobEEE (a template argument of qChain's
// RTTI): an element's links.
template <class T>
class DefaultChainPolicy {
public:
    static T& Next(T element) { return element->m_chainNext; }
    static T& Prev(T element) { return element->m_chainPrev; }
};

// N2nn3nex6qChainIPNS0_3JobENS0_18DefaultChainPolicyIS3_EEEE: an intrusive
// list, linked through its elements.
template <class T, class Policy>
class qChain : public RootObject {
public:
    // 0x71015d0280 (D2, another unit's), 0x71015d5010 (D0)
    ~qChain() override {
        for (T element = m_first, end = m_end; end != element;) {
            T next = Policy::Next(element);
            Remove(element);
            element = next;
        }
    }

    void Remove(T element) {
        T next = Policy::Next(element);
        T prev = Policy::Prev(element);
        if (prev != nullptr) {
            Policy::Next(prev) = next;
        }
        Policy::Prev(element) = nullptr;
        if (next != nullptr) {
            Policy::Prev(next) = prev;
        }
        Policy::Next(element) = nullptr;
        if (m_first == element) {
            m_first = next;
        }
        if (m_last == element) {
            m_last = prev;
        }
        m_count--;
    }

    T m_first;
    T m_last;
    T m_end;
    size_t m_count;
};
using Unk_JobChain = qChain<Job*, DefaultChainPolicy<Job*>>;
PKMN_SIZE_ASSERT(Unk_JobChain, 0x28);

template class qChain<Job*, DefaultChainPolicy<Job*>>;

}  // namespace nex
}  // namespace nn

// What 0x71015cd070 keeps pointers to.
struct Unk_15d50b0;

// 0x71015d50b0: libc++'s slow path of push_back (a reallocation).
template void std::vector<Unk_15d50b0*, nn::nex::MemAllocator<Unk_15d50b0*>>::__push_back_slow_path<
    Unk_15d50b0* const&>(Unk_15d50b0* const& value);

namespace nn {
namespace nex {

// N2nn3nex12StringStreamE: a string being written, in a 0x100-byte buffer that
// grows on the heap.
class StringStream : public RootObject {
public:
    // 0x71015bd810
    StringStream();
    // 0x71015bd850
    ~StringStream() override;

    // 0x71015bd4f0: appends a String.
    StringStream& Unk_15bd4f0(const String& str);
    // 0x71015bdc00: appends a number.
    StringStream& Unk_15bdc00(int value);

    char* m_ptr;
    u8 _10[0x118];
};
PKMN_SIZE_ASSERT(StringStream, 0x128);

}  // namespace nex
}  // namespace nn

// 0x71015b82d0: appends a C string to a StringStream (the name's parameter is
// an integer: the string's address).
nn::nex::StringStream& Unk_15b82d0(void* self, u64 str);
// 0x71015bc1e0: assigns `length` characters of `str` (all of it for -1).
void Unk_15bc1e0(nn::nex::String* self, const char* str, size_t length);

// A String with a copy of `str` (NEX's String(const char*), inline).
static nn::nex::String Unk_MakeString(const char* str) {
    nn::nex::String result;
    Unk_15bc1e0(&result, str, static_cast<size_t>(-1));
    return result;
}

// 0x71015d4f30: the job's slot 6, its description: Job's (an empty string),
// then the argument.
nn::nex::String Unk_15d4f30(const Unk_24506a8* self) {
    nn::nex::StringStream stream;
    stream.Unk_15bd4f0(Unk_MakeString(""));
    Unk_15b82d0(&stream, reinterpret_cast<u64>("\tArgument: ")).Unk_15bdc00(self->m_arg);
    return Unk_MakeString(stream.m_ptr);
}
