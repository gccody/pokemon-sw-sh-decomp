// Scope: common
// pead::Thread (RTTI N4pead6ThreadE, derived from pead::IDisposer and
// pead::INamable): its
// constructor, destructor, entry function and vf6. A TU of its own: it calls
// the message queue holder's members (lib/pia/common/Unk_1721810.cpp). Member
// names are placeholders (lib/pia/README.md).
#include "pia/common/Unk_17214f0.h"

u64 Unk_17163e0(void* memory);

namespace nn {
namespace os {

// From the imports' mangled names.
void SetThreadName(ThreadType* thread, const char* name) noexcept;
int GetCurrentCoreNumber() noexcept;

}  // namespace os
}  // namespace nn

void* operator new(size_t size, pead::Heap* heap, int alignment) noexcept;

// pead's intrusive list links (no RTTI): 0x71017166a0 unlinks a node,
// 0x7101716680 links one in after a list's head.
struct Unk_17166a0_arg0 {
    Unk_17166a0_arg0() : field_0(nullptr), field_8(nullptr) {}

    Unk_17166a0_arg0* field_0;
    Unk_17166a0_arg0* field_8;
};
PKMN_SIZE_ASSERT(Unk_17166a0_arg0, 0x10);

void Unk_17166a0(Unk_17166a0_arg0* node);
void Unk_1716680(Unk_17166a0_arg0* head, Unk_17166a0_arg0* node);

struct Unk_171aea0;
// Its constructor, out of line (lib/nx_middleware/leaf/Unk_1716870.cpp).
void Unk_171aea0_set(Unk_171aea0* self);

struct Unk_171aea0 {
    Unk_171aea0() { Unk_171aea0_set(this); }

    u64 field_0;
};

// The nn::os::ThreadType a pead::Thread allocates and zero-fills: 0x1c0
// bytes, more than include/nn/os.h's 0x1a8.
struct Unk_17219c0_thread {
    u8 field_0[0x1c0];
};

namespace pead {

template <class T>
class SafeStringBase;

// RTTI N4pead14SafeStringBaseIcEE (lib/nx_middleware/class/pead_SafeStringBase_char.cpp).
template <>
class SafeStringBase<char> {
public:
    virtual ~SafeStringBase() {}
    virtual void vf2(const SafeStringBase& other);
    virtual void vf3() const;

    const char* Unk_cstr() const {
        vf3();
        return m_string;
    }

    const char* m_string;
};
PKMN_SIZE_ASSERT(SafeStringBase<char>, 0x10);

// RTTI N4pead8INamableE: Thread's second base, at 0x20 (no vtable of its own).
class INamable {
public:
    explicit INamable(const SafeStringBase<char>& name) : m_name(name) {}

    SafeStringBase<char> m_name;
};
PKMN_SIZE_ASSERT(INamable, 0x10);

class Thread;
struct Unk_1721c60_list;

struct Unk_1721c60_node : Unk_17166a0_arg0 {
    Unk_1721c60_node() : m_thread(nullptr), m_list(nullptr) {}

    inline void Unk_erase();

    Thread* m_thread;
    Unk_1721c60_list* m_list;
};
PKMN_SIZE_ASSERT(Unk_1721c60_node, 0x20);

struct Unk_1721c60_list {
    void Unk_pushBack(Unk_1721c60_node* node) {
        node->Unk_erase();
        node->m_list = this;
        Unk_1716680(&m_head, node);
        m_count++;
    }
    void Unk_erase(Unk_1721c60_node* node) {
        if (node->m_list != nullptr) {
            node->m_list = nullptr;
            Unk_17166a0(node);
            m_count--;
        }
    }

    Unk_17166a0_arg0 m_head;
    int m_count;
};
PKMN_SIZE_ASSERT(Unk_1721c60_list, 0x18);

inline void Unk_1721c60_node::Unk_erase() {
    Unk_1721c60_list* list = m_list;
    if (list != nullptr) {
        m_list = nullptr;
        Unk_17166a0(this);
        list->m_count--;
    }
}

class Thread : public IDisposer, public INamable {
public:
    Thread(const SafeStringBase<char>& name, Heap* heap, int priority, int blockType,
           uintptr_t quitMessage, int stackSize, int queueSize);
    ~Thread() override;
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual bool vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9(bool);
    virtual void vf10(bool);
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
    virtual void vf14();
    virtual void vf15();
    virtual void vf16(uintptr_t message) = 0;
    virtual void vf17();

    static void Unk_1721bf0(void* arg);
    void Unk_17211a0();

    Unk_1721740 m_queue;
    int m_stackSize;
    Unk_1721c60_node m_node;
    u64 field_a8;
    Unk_171aea0 field_b0;
    int m_blockType;
    uintptr_t m_quitMessage;
    u32 field_c8;
    u32 m_state;
    nn::os::ThreadType* m_thread;
    u8* m_stack;
    u64 field_e0;
    int m_priority;
};
PKMN_OFFSET_ASSERT(Thread, m_queue, 0x30);
PKMN_OFFSET_ASSERT(Thread, m_stackSize, 0x80);
PKMN_OFFSET_ASSERT(Thread, m_node, 0x88);
PKMN_OFFSET_ASSERT(Thread, field_b0, 0xb0);
PKMN_OFFSET_ASSERT(Thread, m_blockType, 0xb8);
PKMN_OFFSET_ASSERT(Thread, m_quitMessage, 0xc0);
PKMN_OFFSET_ASSERT(Thread, field_c8, 0xc8);
PKMN_OFFSET_ASSERT(Thread, m_state, 0xcc);
PKMN_OFFSET_ASSERT(Thread, m_thread, 0xd0);
PKMN_OFFSET_ASSERT(Thread, m_stack, 0xd8);
PKMN_OFFSET_ASSERT(Thread, field_e0, 0xe0);
PKMN_OFFSET_ASSERT(Thread, m_priority, 0xe8);

}  // namespace pead

// What Unk_27fc098 points to: the threads' list, its lock, the main thread
// and the TLS slot that holds each thread's pead::Thread.
struct Unk_27fc098_obj {
    u8 _0[0x28];
    pead::Unk_1721c60_list m_threads;
    pead::CriticalSection m_lock;
    pead::Thread* m_mainThread;
    nn::os::TlsSlot m_tlsSlot;
};
PKMN_OFFSET_ASSERT(Unk_27fc098_obj, m_threads, 0x28);
PKMN_OFFSET_ASSERT(Unk_27fc098_obj, m_lock, 0x40);
PKMN_OFFSET_ASSERT(Unk_27fc098_obj, m_mainThread, 0x80);
PKMN_OFFSET_ASSERT(Unk_27fc098_obj, m_tlsSlot, 0x88);

extern Unk_27fc098_obj* Unk_27fc098;
// A TLS slot that holds each thread's core number plus one.
extern nn::os::TlsSlot Unk_27fbb6c;

namespace pead {

// 0x71017219c0
Thread::Thread(const SafeStringBase<char>& name, Heap* heap, int priority, int blockType,
               uintptr_t quitMessage, int stackSize, int queueSize)
    : INamable(name), m_stackSize(stackSize), field_a8(0), m_blockType(blockType),
      m_quitMessage(quitMessage), field_c8(0), m_state(0), m_thread(nullptr), m_stack(nullptr),
      field_e0(0), m_priority(priority) {
    m_node.m_thread = this;
    m_queue.Unk_1721760(queueSize, heap);
    u32 size = stackSize;
    u8* stack = static_cast<u8*>(operator new(size, heap, 0x1000));
    if (size != 0 && stack != nullptr) {
        for (u32 i = 0; i < size; i++) {
            stack[i] = 0;
        }
    }
    m_stack = stack;
    m_thread = reinterpret_cast<nn::os::ThreadType*>(new (heap) Unk_17219c0_thread());
    nn::os::CreateThread(m_thread, Unk_1721bf0, this, m_stack, stackSize, m_priority);
    nn::os::SetThreadName(m_thread, name.Unk_cstr());
    Unk_27fc098_obj* threads = Unk_27fc098;
    if (threads != nullptr) {
        threads->m_lock.Unk_17215f0();
        threads->m_threads.Unk_pushBack(&m_node);
        threads->m_lock.Unk_1721600();
    }
}

// 0x7101721c60 (and 0x7101721d80, deleting: a trap, the class is abstract)
Thread::~Thread() {
    Unk_27fc098_obj* threads = Unk_27fc098;
    if (threads == nullptr) {
        return;
    }
    if (threads->m_mainThread != this) {
        threads->m_lock.Unk_17215f0();
        threads->m_threads.Unk_erase(&m_node);
        threads->m_lock.Unk_1721600();
        if (m_state == 2 || m_state == 3) {
            vf8();
        } else if (m_state == 1) {
            vf10(false);
        }
        nn::os::DestroyThread(m_thread);
        if (m_thread != nullptr) {
            Unk_1716390(m_thread);
        }
        u8* stack = m_stack;
        if (stack != nullptr) {
            Unk_17163e0(stack);
            Unk_1716390(stack);
        }
    }
    m_queue.Unk_1721810();
}

// 0x7101721bf0
void Thread::Unk_1721bf0(void* arg) {
    Thread* thread = static_cast<Thread*>(arg);
    nn::os::SetTlsValue(Unk_27fc098->m_tlsSlot, reinterpret_cast<uintptr_t>(thread));
    nn::os::SetTlsValue(Unk_27fbb6c, nn::os::GetCurrentCoreNumber() + 1);
    thread->field_c8 = reinterpret_cast<uintptr_t>(thread->m_thread);
    thread->m_state = 1;
    thread->Unk_17211a0();
    thread->m_state = 3;
}

// 0x7101721dc0
bool Thread::vf6() {
    if (m_state != 0) {
        return false;
    }
    nn::os::StartThread(m_thread);
    field_c8 = reinterpret_cast<uintptr_t>(m_thread);
    if (m_state == 0) {
        m_state = 1;
    }
    return true;
}

}  // namespace pead
