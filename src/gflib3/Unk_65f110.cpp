// Scope: common
//
// gflib3's TLSF pool resource (its asserts name
// lib/gflib3/src/mem/tlsf_pool_resource.cpp): a memory resource with two
// vtables that owns a TLSF pool (mem/internal/tlsf_pool.cpp) and guards it
// with an owner thread and a light event. And a static object of the same
// code, created on first use. Its TU is not the heap globals'
// (src/gflib3/Unk_65d670.cpp): its guard and object (0x7102778768) are far
// from theirs.
#include <atomic>

#include "gflib3/Unk_5cf870.h"

// A static object (0x7102778770) that Unk_65f110 returns, created on first use.
class Unk_2778770 {
public:
    Unk_2778770() {
        Unk_5cf8c0(&field_4, nn::os::EventClearMode(1), false);
        field_10 = nullptr;
    }
    ~Unk_2778770() { Unk_5cf8d0(&field_4); }

    u32 field_0;
    nn::os::LightEventType field_4;
    void* field_10;
};
PKMN_OFFSET_ASSERT(Unk_2778770, field_4, 0x4);
PKMN_OFFSET_ASSERT(Unk_2778770, field_10, 0x10);

// 0x710065f110
Unk_2778770* Unk_65f110() {
    static Unk_2778770 instance;
    return &instance;
}

class Unk_239f910;
class Unk_239f910_Pool;

// Out of this TU: the pool's constructor and destructor (or the functions
// they call), its emptiness check and reset, and the leak dump.
void Unk_65ed00(Unk_239f910_Pool* pool, void* memory, u64 size);
void Unk_65eda0(Unk_239f910_Pool* pool);
bool Unk_65f070(const Unk_239f910_Pool* pool);
void Unk_65edc0(Unk_239f910_Pool* pool);
void Unk_65f360(Unk_239f910* resource);

// The TLSF pool (0x70 bytes): its constructor takes the memory it manages.
class Unk_239f910_Pool {
public:
    Unk_239f910_Pool(void* memory, u64 size) { Unk_65ed00(this, memory, size); }
    ~Unk_239f910_Pool() { Unk_65eda0(this); }

    u8 _0[0x70];
};
PKMN_SIZE_ASSERT(Unk_239f910_Pool, 0x70);

// A light event that lives as long as its owner.
class Unk_239f910_Event {
public:
    Unk_239f910_Event(nn::os::EventClearMode clearMode, bool signaled) {
        Unk_5cf8c0(&m_event, clearMode, signaled);
    }
    ~Unk_239f910_Event() { Unk_5cf8d0(&m_event); }

    void Wait() { Unk_5cf8f0(&m_event); }
    void Signal() { Unk_5cf8e0(&m_event); }

private:
    nn::os::LightEventType m_event;
};

// The primary base: 25 vtable slots (0x710239f920), 2 of them the destructor.
class Unk_239f910_Base {
public:
    virtual ~Unk_239f910_Base() {}
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
    virtual void vf22();
    virtual void vf23();
    virtual void vf24();
};

// The secondary base, at +0x8 (0x710239f9f8): a function, then the
// destructor. Its fields are initialized before the derived class's vptrs.
class Unk_239f9e8 {
public:
    explicit Unk_239f9e8(void* arg) : field_8(0), field_10(false), field_18(arg) {}
    virtual void vf0();
    virtual ~Unk_239f9e8() {}

    u64 field_8;
    bool field_10;
    void* field_18;
};
PKMN_OFFSET_ASSERT(Unk_239f9e8, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_239f9e8, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_239f9e8, field_18, 0x18);
PKMN_SIZE_ASSERT(Unk_239f9e8, 0x20);

class Unk_239f910 : public Unk_239f910_Base, public Unk_239f9e8 {
public:
    Unk_239f910(void* memory, u64 size, void* arg);
    ~Unk_239f910() override;

    Unk_239f910_Pool m_pool;
    u64 field_98;
    u32 field_a0;
    Unk_239f910_Event m_event;
    std::atomic<nn::os::ThreadType*> m_owner;
};
PKMN_OFFSET_ASSERT(Unk_239f910, m_pool, 0x28);
PKMN_OFFSET_ASSERT(Unk_239f910, field_98, 0x98);
PKMN_OFFSET_ASSERT(Unk_239f910, m_event, 0xa4);
PKMN_OFFSET_ASSERT(Unk_239f910, m_owner, 0xb0);
PKMN_SIZE_ASSERT(Unk_239f910, 0xb8);

// 0x710065f1c0
Unk_239f910::Unk_239f910(void* memory, u64 size, void* arg)
    : Unk_239f9e8(arg),
      m_pool(memory, size),
      field_98(0),
      m_event(nn::os::EventClearMode(1), false),
      m_owner(nullptr) {}

// 0x710065f220, 0x710065f300 (D0), 0x710065f2f0 and 0x710065f330 (their thunks from the secondary
// base)
Unk_239f910::~Unk_239f910() {
    nn::os::ThreadType* self = nn::os::GetCurrentThread();
    nn::os::ThreadType* expected = nullptr;
    while (!m_owner.compare_exchange_strong(expected, self, std::memory_order_acquire)) {
        expected = nullptr;
        m_event.Wait();
    }
    if (!Unk_65f070(&m_pool))
        Unk_65f360(this);
    Unk_65edc0(&m_pool);
    m_owner.exchange(nullptr, std::memory_order_release);
    m_event.Signal();
}
