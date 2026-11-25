// Scope: common
// Unk_2418100's virtuals (the request step of src/unsorted/net_request/
// Unk_10ff800.cpp holding ids and items): its vf2 is the class's key
// function, so its vtable and destructors (0x7101100240, 0x71011002f0) come
// from this file. The other steps' destructors in this range (0x71010ffde0 to
// 0x71011001a0) are Unk_10ff800.cpp's, where their vtables are.
// Placeholder types: rename and move once the classes are known.
#include <cstddef>
#include <vector>

#include "unsorted/net_request/Unk_10ff440.h"

void* Unk_15b9340(size_t size);
void Unk_15b9390(u64 p);

namespace nn {
namespace nex {

// NEX's allocator and vector, as in Unk_10ff800.cpp.
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

// As in Unk_10ff800.cpp.
class Unk_24181e0_Item {
public:
    virtual ~Unk_24181e0_Item();
    u8 _8[0x58];
};
static_assert(sizeof(Unk_24181e0_Item) == 0x60, "Unk_24181e0_Item");

struct Unk_2418100_Id {
    Unk_2418100_Id(const Unk_2418100_Id& other) : field_0(other.field_0) {}

    u64 field_0;
};
static_assert(sizeof(Unk_2418100_Id) == 0x8, "Unk_2418100_Id");

// The object's slot 13, which Unk_10ff440.h's Unk_2417c28 doesn't declare.
class Unk_2417c28_Slot13 : public Unk_2417c28 {
public:
    virtual void vf13(bool value, const nn::nex::qVector<Unk_2418100_Id>& ids,
                      const nn::nex::qVector<Unk_24181e0_Item>& items);
};

// The manager the steps report to (Unk_10ff800.cpp).
class Unk_2417dc8 {
public:
    void Unk_10fda60();
};
extern Unk_2417dc8* Unk_27e4f70;

struct Unk_10fdac0;
void Unk_10fdac0_call(Unk_10fdac0* self);

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

// 0x71010ffd00
void Unk_2418100::vf2(u64 value, const Unk_239a418_Ref<Unk_239a418>& object) {
    Unk_2418090::vf2(value, object);
    if (Unk_27e4f70 != nullptr)
        Unk_27e4f70->Unk_10fda60();
}

// 0x71010ffd30
void Unk_2418100::vf3() {
    if (Unk_27e4f70 != nullptr)
        Unk_10fdac0_call(reinterpret_cast<Unk_10fdac0*>(Unk_27e4f70));
    Unk_2418090::vf3();
}

// 0x71010ffd70
void Unk_2418100::vf4(bool value) {
    Unk_239a418_Ref<Unk_2417c28> object = Unk_10ff530();
    if (object.m_ptr != nullptr)
        static_cast<Unk_2417c28_Slot13*>(object.m_ptr)->vf13(value, field_18, field_30);
}
