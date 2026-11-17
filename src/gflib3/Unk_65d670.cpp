// Scope: common
//
// gflib3's heap globals: the global and debug heaps, the default heap, and a
// heap set for one thread (or for all of them) that takes the default's place
// while it's set. A static nn::os::Mutex guards the per-thread state. The
// heaps are named through a virtual function ("GlobalHeap", "DebugHeap").
//
// Placeholder names: rename once the class and functions are identified. The
// segment (0x710065b490-0x710067a530) also holds gflib3's TLSF pool
// (lib/gflib3/src/mem/internal/tlsf_pool.cpp, mem/tlsf_pool_resource.cpp).
#include <nn/os.h>
#include <types.h>

// A heap: its vtable slot 22 (+0xb0) takes the heap's name.
class Unk_65d680_Heap {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
    virtual void vf14();
    virtual void vf15();
    virtual void vf16();
    virtual void vf17();
    virtual void vf18();
    virtual void vf19();
    virtual void vf20();
    virtual void vf21();
    virtual void vf22(const char* name);
};

// Declared like src/unsorted/virtual/Unk_65dbb0.cpp (tools/vtables.py), the
// TU of its vtable (0x710239f8e8).
class Unk_239f8e8 {
public:
    virtual u32 vf0();
    virtual void vf1();
    virtual void* vf2();
};

u8 Unk_2777f04;                // a bool flag, stored as a byte: loads normalize it
Unk_65d680_Heap* Unk_2777f08;  // set with its name "GlobalHeap"
Unk_65d680_Heap* Unk_2777f10;  // set with its name "DebugHeap"
Unk_65d680_Heap* Unk_2777f18;  // the default heap: the global heap
u64 Unk_2777f20;               // the thread Unk_2777f28 was set on (nn::os::GetThreadId)
Unk_65d680_Heap* Unk_2777f28;  // the heap that takes the default's place
Unk_239f8e8* Unk_2777f30;
bool Unk_239f8d8 = true;
bool Unk_239f8d9 = true;  // Unk_2777f28 is for Unk_2777f20's thread only

static Unk_239f8e8 Unk_239f8e0;  // constant-initialized: in .data, its vptr and nothing else

static nn::os::Mutex& Unk_2777f40() {
    static nn::os::Mutex mutex(false);
    return mutex;
}

// Locks Unk_2777f40() for its scope.
class Unk_2777f40_Lock {
public:
    Unk_2777f40_Lock() : m_mutex(Unk_2777f40()) { m_mutex.Lock(); }
    ~Unk_2777f40_Lock() { m_mutex.Unlock(); }

private:
    nn::os::Mutex& m_mutex;
};

// Whether Unk_2777f28 applies to the calling thread.
static bool Unk_2777f28_applies() {
    if (Unk_239f8d9)
        return Unk_2777f28 != nullptr &&
               Unk_2777f20 == nn::os::GetThreadId(nn::os::GetCurrentThread());
    return Unk_2777f28 != nullptr;
}

// 0x710065d680
void Unk_65d680(Unk_65d680_Heap* heap) {
    Unk_2777f08 = heap;
    heap->vf22("GlobalHeap");
    Unk_2777f18 = heap;
}

// 0x710065d6d0
void Unk_65d6d0(Unk_65d680_Heap* heap) {
    Unk_2777f10 = heap;
    heap->vf22("DebugHeap");
}

// 0x710065d6f0
Unk_65d680_Heap* Unk_65d6f0() {
    return Unk_2777f08;
}

// 0x710065d700
Unk_65d680_Heap* Unk_65d700() {
    Unk_2777f40_Lock lock;
    return Unk_2777f28_applies() ? Unk_2777f28 : Unk_2777f18;
}

// 0x710065d800
Unk_239f8e8* Unk_65d800() {
    if (Unk_2777f30 == nullptr)
        Unk_2777f30 = &Unk_239f8e0;
    return Unk_2777f30;
}

// 0x710065d830
bool Unk_65d830() {
    Unk_2777f40_Lock lock;
    return !Unk_2777f28_applies() && Unk_2777f04 != 0;
}

// 0x710065d940
void Unk_65d940(bool value) {
    Unk_2777f04 = value;
}

// 0x710065d960
bool Unk_65d960() {
    Unk_2777f40_Lock lock;
    return Unk_239f8d8;
}

// 0x710065da00
void Unk_65da00(void* /*unused*/, Unk_65d680_Heap* heap, bool value, bool thisThreadOnly) {
    Unk_2777f40_Lock lock;
    Unk_2777f20 = nn::os::GetThreadId(nn::os::GetCurrentThread());
    Unk_2777f28 = heap;
    Unk_239f8d8 = value;
    Unk_239f8d9 = thisThreadOnly;
}

// 0x710065daf0
void Unk_65daf0() {
    Unk_2777f40_Lock lock;
    Unk_239f8d9 = true;
    Unk_239f8d8 = true;
    Unk_2777f28 = nullptr;
    Unk_2777f20 = 0;
}
