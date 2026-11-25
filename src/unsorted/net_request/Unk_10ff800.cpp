// Scope: common
// The request steps derived from Unk_2418090 (Unk_10ff440.h), one per vtable
// from 0x71024180d8 to 0x71024181f0: each one's vf4 hands the object its
// weak reference locks a flag (and what the step holds), and some of them
// tell the manager (the global Unk_27e4f70) when they start and stop. Their
// simple getters are in src/unsorted/leaf/Unk_10ff940.cpp.
// Placeholder types: rename and move once the classes are known.
#include <cstddef>
#include <vector>

#include "unsorted/net_request/Unk_10ff440.h"

void* Unk_15b9340(size_t size);
void Unk_15b9390(u64 p);

namespace nn {
namespace nex {

// NEX's allocator and vector, as lib/nex/include/nn/nex/qVector.h declares
// them (src/ doesn't have NEX's include path): the steps' vectors allocate
// through 0x71015b9340 and free through 0x71015b9390.
template <class T>
class MemAllocator {
public:
    typedef T value_type;
    MemAllocator() {}
    template <class U>
    MemAllocator(const MemAllocator<U>&) {}
    T* allocate(size_t n) { return static_cast<T*>(Unk_15b9340(n * sizeof(T))); }
    void deallocate(T* p, size_t) { Unk_15b9390(reinterpret_cast<u64>(p)); }
    template <class U>
    bool operator==(const MemAllocator<U>&) const {
        return true;
    }
    template <class U>
    bool operator!=(const MemAllocator<U>&) const {
        return false;
    }
};

template <class T>
class qVector : public std::vector<T, MemAllocator<T>> {};

}  // namespace nex
}  // namespace nn

// The steps' elements: destroyed through their vtables' slot 0.
class Unk_2418138_Item {
public:
    virtual ~Unk_2418138_Item();
    u8 _8[0x48];
};
static_assert(sizeof(Unk_2418138_Item) == 0x50, "Unk_2418138_Item");

class Unk_2418170_Item {
public:
    virtual ~Unk_2418170_Item();
    u8 _8[0x50];
};
static_assert(sizeof(Unk_2418170_Item) == 0x58, "Unk_2418170_Item");

class Unk_24181e0_Item {
public:
    virtual ~Unk_24181e0_Item();
    u8 _8[0x58];
};
static_assert(sizeof(Unk_24181e0_Item) == 0x60, "Unk_24181e0_Item");

// What Unk_2418100 is made with: 8 bytes, copied one by one (a copy
// constructor of its own: libc++ would copy trivial ones with memcpy).
struct Unk_2418100_Id {
    Unk_2418100_Id(const Unk_2418100_Id& other) : field_0(other.field_0) {}

    u64 field_0;
};
static_assert(sizeof(Unk_2418100_Id) == 0x8, "Unk_2418100_Id");

// The manager the steps report to (gflib3's object, with a lock at +0x320),
// and what they call on it. Its own functions are placeholders; the leaf ones
// (src/unsorted/leaf/Unk_10faa50.cpp) take a struct of their own.
class Unk_2417dc8 {
public:
    void Unk_10fd870();
    void Unk_10fd940();
    void Unk_10fd9d0();
};
extern Unk_2417dc8* Unk_27e4f70;

struct Unk_10fd8d0;
struct Unk_10fd900;
struct Unk_10fd9a0;
struct Unk_10fda30;
void Unk_10fd8d0_call(Unk_10fd8d0* self);
void Unk_10fd900_call(Unk_10fd900* self);
void Unk_10fd9a0_call(Unk_10fd9a0* self);
void Unk_10fda30_call(Unk_10fda30* self);

class Unk_24180c8 : public Unk_2418090 {
public:
    Unk_24180c8(bool arg1, bool arg2);
    void vf2(u64 value, const Unk_239a418_Ref<Unk_239a418>& object) override;
    void vf3() override;
    void vf4(bool value) override;

    bool field_18;
    bool field_19;
};
PKMN_OFFSET_ASSERT(Unk_24180c8, field_18, 0x18);
PKMN_OFFSET_ASSERT(Unk_24180c8, field_19, 0x19);

class Unk_2418100 : public Unk_2418090 {
public:
    explicit Unk_2418100(const nn::nex::qVector<Unk_2418100_Id>& ids);
    void vf2(u64 value, const Unk_239a418_Ref<Unk_239a418>& object) override;
    void vf3() override;
    void vf4(bool value) override;

    nn::nex::qVector<Unk_2418100_Id> field_18;
    nn::nex::qVector<Unk_24181e0_Item> field_30;
};
PKMN_OFFSET_ASSERT(Unk_2418100, field_18, 0x18);
PKMN_OFFSET_ASSERT(Unk_2418100, field_30, 0x30);
static_assert(sizeof(Unk_2418100) == 0x48, "Unk_2418100");

class Unk_2418138 : public Unk_2418090 {
public:
    void vf4(bool value) override;

    nn::nex::qVector<Unk_2418138_Item> field_18;
};
PKMN_OFFSET_ASSERT(Unk_2418138, field_18, 0x18);

class Unk_2418170 : public Unk_2418090 {
public:
    void vf4(bool value) override;

    nn::nex::qVector<Unk_2418170_Item> field_18;
};
PKMN_OFFSET_ASSERT(Unk_2418170, field_18, 0x18);

class Unk_24181a8 : public Unk_2418090 {
public:
    void vf2(u64 value, const Unk_239a418_Ref<Unk_239a418>& object) override;
    void vf3() override;
    void vf4(bool value) override;
};

class Unk_24181e0 : public Unk_2418090 {
public:
    void vf2(u64 value, const Unk_239a418_Ref<Unk_239a418>& object) override;
    void vf3() override;
    void vf4(bool value) override;

    nn::nex::qVector<Unk_24181e0_Item> field_18;
};
PKMN_OFFSET_ASSERT(Unk_24181e0, field_18, 0x18);

// 0x71010ff800
Unk_24180c8::Unk_24180c8(bool arg1, bool arg2) : field_18(arg1), field_19(arg2) {}

// 0x71010ff830
void Unk_24180c8::vf2(u64 value, const Unk_239a418_Ref<Unk_239a418>& object) {
    Unk_2418090::vf2(value, object);
    if (Unk_27e4f70 != nullptr)
        Unk_27e4f70->Unk_10fd870();
}

// 0x71010ff860
void Unk_24180c8::vf3() {
    if (Unk_27e4f70 != nullptr)
        Unk_10fd8d0_call(reinterpret_cast<Unk_10fd8d0*>(Unk_27e4f70));
    Unk_2418090::vf3();
}

// 0x71010ff8a0
void Unk_24180c8::vf4(bool value) {
    if (value && !field_19 && field_18 && Unk_27e4f70 != nullptr)
        Unk_10fd900_call(reinterpret_cast<Unk_10fd900*>(Unk_27e4f70));
    Unk_239a418_Ref<Unk_2417c28> object = Unk_10ff530();
    if (object.m_ptr != nullptr)
        object.m_ptr->vf7(value, field_18, field_19);
}

// 0x71010ff950
void Unk_2418138::vf4(bool value) {
    Unk_239a418_Ref<Unk_2417c28> object = Unk_10ff530();
    if (object.m_ptr != nullptr)
        object.m_ptr->vf9(value, field_18);
}

// 0x71010ff9d0
void Unk_2418170::vf4(bool value) {
    Unk_239a418_Ref<Unk_2417c28> object = Unk_10ff530();
    if (object.m_ptr != nullptr)
        object.m_ptr->vf10(value, field_18);
}

// 0x71010ffa40
void Unk_24181a8::vf2(u64 value, const Unk_239a418_Ref<Unk_239a418>& object) {
    Unk_2418090::vf2(value, object);
    if (Unk_27e4f70 != nullptr)
        Unk_27e4f70->Unk_10fd940();
}

// 0x71010ffa70
void Unk_24181a8::vf3() {
    if (Unk_27e4f70 != nullptr)
        Unk_10fd9a0_call(reinterpret_cast<Unk_10fd9a0*>(Unk_27e4f70));
    Unk_2418090::vf3();
}

// 0x71010ffab0
void Unk_24181a8::vf4(bool value) {
    Unk_239a418_Ref<Unk_2417c28> object = Unk_10ff530();
    if (object.m_ptr != nullptr)
        object.m_ptr->vf11(value);
}

// 0x71010ffb20
void Unk_24181e0::vf2(u64 value, const Unk_239a418_Ref<Unk_239a418>& object) {
    Unk_2418090::vf2(value, object);
    if (Unk_27e4f70 != nullptr)
        Unk_27e4f70->Unk_10fd9d0();
}

// 0x71010ffb50
void Unk_24181e0::vf3() {
    if (Unk_27e4f70 != nullptr)
        Unk_10fda30_call(reinterpret_cast<Unk_10fda30*>(Unk_27e4f70));
    Unk_2418090::vf3();
}

// 0x71010ffb90
void Unk_24181e0::vf4(bool value) {
    Unk_239a418_Ref<Unk_2417c28> object = Unk_10ff530();
    if (object.m_ptr != nullptr)
        object.m_ptr->vf12(value, field_18);
}

// 0x71010ffc00
Unk_2418100::Unk_2418100(const nn::nex::qVector<Unk_2418100_Id>& ids) : field_18(ids) {}
