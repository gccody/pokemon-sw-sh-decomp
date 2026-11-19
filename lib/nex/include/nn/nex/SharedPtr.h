#pragma once
#include <atomic>
#include <nn/nex/RootObject.h>

namespace nn {
namespace nex {

// N2nn3nex17SharedCounterBaseE: a SharedPtr's counts and how it disposes of
// the object (slot 2).
class SharedCounterBase : public RootObject {
public:
    virtual ~SharedCounterBase() {}
    virtual void vf2() = 0;

    std::atomic<s32> m_strong;
    std::atomic<s32> m_weak;
};
PKMN_OFFSET_ASSERT(SharedCounterBase, m_weak, 0xc);

// N2nn3nex23SharedPtrDefaultDeleterINS0_6TicketEEE ...: deletes the object.
template <class T>
class SharedPtrDefaultDeleter {
public:
    void operator()(T* p) const { delete p; }
};

// N2nn3nex13SharedCounterINS0_6TicketES2_NS0_23SharedPtrDefaultDeleterIS2_EEEE ...:
// the counts of an object and its deleter.
template <class T, class U, class D>
class SharedCounter : public SharedCounterBase {
public:
    ~SharedCounter() override {}
    void vf2() override { m_deleter(m_ptr); }

    U* m_ptr;
    D m_deleter;
};

// Takes one from a count and returns what is left (an inline helper; the name
// isn't the executable's).
inline s32 Decrement(std::atomic<s32>& count) {
    s32 v = count.load();
    while (!count.compare_exchange_weak(v, v - 1)) {
    }
    return v - 1;
}

// N2nn3nex9SharedPtrINS0_6TicketEEE ...: a shared pointer (polymorphic itself).
template <class T>
class SharedPtr : public RootObject {
public:
    ~SharedPtr() override {
        SharedCounterBase* counter = m_counter;
        if (counter != nullptr) {
            if (Decrement(counter->m_strong) == 0) {
                counter->vf2();
                if (Decrement(counter->m_weak) == 0) {
                    delete counter;
                }
            }
        }
    }

    SharedCounterBase* m_counter;
    T* m_ptr;
};

}  // namespace nex
}  // namespace nn
