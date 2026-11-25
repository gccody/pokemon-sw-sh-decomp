#pragma once
// A gflnet3 object (vtable 0x71023a3dc8, 0x1a8 bytes) that runs a thread of
// its own (Unk_23a3e08, 0x580 bytes, made in 0x71006c2cf0) and keeps, each
// under a mutex of its own, a 16-bit value, a state (0 to 3), two requests and
// a result and a value its update (0x71006c2bb0) hands to a listener it holds
// weakly. One instance, which the global Unk_27790f0 holds (src/gflib3/
// families/Unk_7c20.cpp destroys it: its vf3 is there). Its functions are in
// Unk_6c2a10.cpp and Unk_6c3260.cpp (two TUs: the update calls 0x71006c3460,
// which it would inline). Placeholder names: rename once the classes are known.
#include <atomic>
#include <new>
#include <utility>

#include <nn/os.h>
#include <types.h>

#include "gflib3/Unk_23994d8.h"
#include "gflib3/Unk_239a418.h"
#include "pia/common/Unk_165e060.h"

// Holds a mutex while it's alive. (include/nn/os.h gives MutexType
// alignment 1: the SDK's is 8, so the members are aligned here.)
class Unk_23a3db8_Lock {
public:
    explicit Unk_23a3db8_Lock(nn::os::Mutex& mutex) : m_mutex(mutex) { m_mutex.Lock(); }
    ~Unk_23a3db8_Lock() { m_mutex.Unlock(); }

private:
    nn::os::Mutex& m_mutex;
};

// A value or none: the flag first, then the value. Its destructor and its
// assignment clear the flag when they drop the value.
template <class T>
class Unk_23a3db8_Optional {
public:
    Unk_23a3db8_Optional() : m_has(false) {}
    Unk_23a3db8_Optional(const Unk_23a3db8_Optional& other) : m_has(false) {
        if (other.m_has)
            Construct(other.m_value);
    }
    ~Unk_23a3db8_Optional() { Reset(); }

    Unk_23a3db8_Optional& operator=(const Unk_23a3db8_Optional& other) {
        if (m_has) {
            if (other.m_has)
                m_value = other.m_value;
            else
                Reset();
        } else if (other.m_has) {
            Construct(other.m_value);
        }
        return *this;
    }

    void Construct(const T& value) {
        ::new (&m_value) T(value);
        m_has = true;
    }

    void Reset() {
        if (m_has) {
            m_value.~T();
            m_has = false;
        }
    }

    explicit operator bool() const { return m_has; }
    const T& operator*() const { return m_value; }

    bool m_has;
    union {
        T m_value;
    };
};

// A request, 8 bytes, set and taken as a whole: whether there is one, and its
// value.
struct Unk_23a3db8_Request {
    bool field_0 = false;
    u32 field_4;
};
PKMN_SIZE_ASSERT(Unk_23a3db8_Request, 0x8);

// Takes another reference's object: the new one is added and stored before the
// old one is dropped.
template <class T>
void Unk_23a3db8_Assign(Unk_239a418_Ref<T>& ref, const Unk_239a418_Ref<T>& other) {
    Unk_239a418_Ref<T> copy(other);
    std::swap(ref.m_ptr, copy.m_ptr);
}

// A weak reference: the handle that keeps the object's count
// (src/gflib3/Unk_239a418.h), then the object.
template <class T>
class Unk_23a3db8_Weak {
public:
    Unk_23a3db8_Weak() : m_ptr(nullptr) {}
    Unk_23a3db8_Weak& operator=(const Unk_23a3db8_Weak& other) {
        Unk_23a3db8_Assign(m_handle, other.m_handle);
        m_ptr = other.m_ptr;
        return *this;
    }
    Unk_23a3db8_Weak& operator=(Unk_23a3db8_Weak&& other) = default;

    // Whether the object still has references.
    bool IsAlive() const { return m_handle.m_ptr != nullptr && m_handle.m_ptr->field_54 != 0; }
    T* Get() const { return IsAlive() ? m_ptr : nullptr; }

    Unk_239a418_Ref<Unk_239a418_Handle> m_handle;
    T* m_ptr;
};

// What's told the result (slot 0) and the value (slot 1).
class Unk_23a3db8_Listener {
public:
    virtual void vf0(const nn::pia::Unk_165e060& result);
    virtual void vf1(const u32& value);
};

// What the thread is started with (copied into it at +0x300): the first word
// goes to its base's constructor, the thread's name (?) is at +0x8.
struct Unk_23a3db8_Config {
    u64 field_0;
    u64 field_8;
    u64 field_10;
    u64 field_18;
    u64 field_20;
    u64 field_28;
    u64 field_30;
    u64 field_38;
    u64 field_40;
    u64 field_48;
};
PKMN_SIZE_ASSERT(Unk_23a3db8_Config, 0x50);

// What the thread is handed (vtable 0x71023a3d58, 0x180 bytes; slot 2 is in
// src/unsorted/virtual/Unk_6c27d0.cpp): its destructor is inline, and clears
// the value at +0x170.
struct Unk_23a3d58_Value {
    u32 field_0;
    u16 field_4;
};

class Unk_23a3d58 {
public:
    virtual ~Unk_23a3d58() {}
    virtual u8* vf2();
    virtual void vf3();

    u8 field_8[0x168];
    Unk_23a3db8_Optional<Unk_23a3d58_Value> field_170;
};
PKMN_OFFSET_ASSERT(Unk_23a3d58, field_170, 0x170);
PKMN_SIZE_ASSERT(Unk_23a3d58, 0x180);

// Makes what the thread is handed (0x71006c2450). The arguments' types aren't
// known.
Unk_23a3d58 Unk_6c2450(const void* arg1, const void* arg2);

// The thread (vtable 0x71023a3e08), on gflib3's thread class.
class Unk_23a3e08 : public Unk_23994d8 {
public:
    explicit Unk_23a3e08(const Unk_23a3db8_Config& config);

    void Unk_6c3950(const Unk_23a3d58& value);
    void Unk_6c3a00(const Unk_239a418_Ref<Unk_239a418>& ref);
    void Unk_6c3a70(const Unk_239a418_Ref<Unk_239a418>& ref);

    u8 _2e8[0x2fa - 0x2e8];
    std::atomic<bool> field_2fa;  // done
    u8 _2fb[0x580 - 0x2fb];
};
PKMN_OFFSET_ASSERT(Unk_23a3e08, field_2fa, 0x2fa);
PKMN_SIZE_ASSERT(Unk_23a3e08, 0x580);

// gflib3's thread functions: start (the name, the priority and the core) and
// stop.
void Unk_5d0f90(void* thread, const void* name, s32 priority, s32 core);
void Unk_5d0e50(void* thread);

// A reference to the thread: added and dropped through its +0x48 interface
// (Unk_239a4f8::vf3 and vf4).
class Unk_23a3db8_ThreadRef {
public:
    Unk_23a3db8_ThreadRef() : m_ptr(nullptr) {}
    explicit Unk_23a3db8_ThreadRef(Unk_23a3e08* ptr) : m_ptr(ptr) {
        if (m_ptr)
            static_cast<Unk_239a4f8*>(m_ptr)->vf3();
    }
    ~Unk_23a3db8_ThreadRef() {
        if (m_ptr) {
            static_cast<Unk_239a4f8*>(m_ptr)->vf4();
            m_ptr = nullptr;
        }
    }
    Unk_23a3db8_ThreadRef& operator=(Unk_23a3db8_ThreadRef&& other) {
        if (m_ptr) {
            static_cast<Unk_239a4f8*>(m_ptr)->vf4();
            m_ptr = nullptr;
        }
        m_ptr = other.m_ptr;
        other.m_ptr = nullptr;
        return *this;
    }

    Unk_23a3e08* operator->() const { return m_ptr; }
    explicit operator bool() const { return m_ptr != nullptr; }

    Unk_23a3e08* m_ptr;
};

// The interface at +0x48: the same two functions as the primary vtable's.
class Unk_23a3db8_Interface {
public:
    virtual void vf2();
    virtual void vf3();
};

// Set when the object is made.
extern bool Unk_277911e;

// The primary base, on the root: its constructor sets the flag (the store
// comes before the object's vptrs).
class Unk_23a3db8_Base : public Unk_236d378 {
public:
    Unk_23a3db8_Base() { Unk_277911e = true; }
};

class Unk_23a3db8 : public Unk_23a3db8_Base, public Unk_23a3db8_Interface {
public:
    Unk_23a3db8(const u16& id, const Unk_23a3db8_Config& config);
    ~Unk_23a3db8() override;
    void vf2() override;  // stops the thread, lets go of the listener
    void vf3() override;  // destroys the instance

    const u16& Unk_6c2b60();
    void Unk_6c2cf0();
    u32 Unk_6c3070();
    void Unk_6c30b0(const u32& state);
    void Unk_6c3180(const void* arg1, const void* arg2);
    void Unk_6c31e0(const Unk_239a418_Ref<Unk_239a418>& ref);
    void Unk_6c3260(const Unk_239a418_Ref<Unk_239a418>& ref);
    void Unk_6c32e0(const Unk_23a3db8_Weak<Unk_23a3db8_Listener>& listener);
    Unk_23a3db8_Request Unk_6c33e0();
    Unk_23a3db8_Request Unk_6c3420();
    void Unk_6c3460(const Unk_23a3db8_Optional<nn::pia::Unk_165e060>& result);
    void Unk_6c3550(const Unk_23a3db8_Optional<u32>& value);

    Unk_23a3db8_ThreadRef field_50;
    u16 field_58;
    alignas(8) nn::os::Mutex field_60{true};
    u32 field_80 = 3;  // the state
    alignas(8) nn::os::Mutex field_88{true};
    Unk_23a3db8_Request field_a8;
    alignas(8) nn::os::Mutex field_b0{true};
    Unk_23a3db8_Request field_d0;
    alignas(8) nn::os::Mutex field_d8{true};
    Unk_23a3db8_Config field_f8;
    Unk_239a418_Ref<Unk_239a418> field_148;
    Unk_239a418_Ref<Unk_239a418> field_150;
    Unk_23a3db8_Weak<Unk_23a3db8_Listener> field_158;
    Unk_23a3db8_Optional<nn::pia::Unk_165e060> field_168;
    Unk_23a3db8_Optional<u32> field_17c;
    alignas(8) nn::os::Mutex field_188{false};
};
PKMN_OFFSET_ASSERT(Unk_23a3db8, field_50, 0x50);
PKMN_OFFSET_ASSERT(Unk_23a3db8, field_58, 0x58);
PKMN_OFFSET_ASSERT(Unk_23a3db8, field_60, 0x60);
PKMN_OFFSET_ASSERT(Unk_23a3db8, field_80, 0x80);
PKMN_OFFSET_ASSERT(Unk_23a3db8, field_88, 0x88);
PKMN_OFFSET_ASSERT(Unk_23a3db8, field_a8, 0xa8);
PKMN_OFFSET_ASSERT(Unk_23a3db8, field_b0, 0xb0);
PKMN_OFFSET_ASSERT(Unk_23a3db8, field_d0, 0xd0);
PKMN_OFFSET_ASSERT(Unk_23a3db8, field_d8, 0xd8);
PKMN_OFFSET_ASSERT(Unk_23a3db8, field_f8, 0xf8);
PKMN_OFFSET_ASSERT(Unk_23a3db8, field_148, 0x148);
PKMN_OFFSET_ASSERT(Unk_23a3db8, field_158, 0x158);
PKMN_OFFSET_ASSERT(Unk_23a3db8, field_168, 0x168);
PKMN_OFFSET_ASSERT(Unk_23a3db8, field_17c, 0x17c);
PKMN_OFFSET_ASSERT(Unk_23a3db8, field_188, 0x188);
PKMN_SIZE_ASSERT(Unk_23a3db8, 0x1a8);
