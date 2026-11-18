#pragma once
// A node of gflib3 on its reference-counted object (vtable 0x7102399590),
// 0x290 bytes: it keeps its parents (+0x60) and children (+0x90), the
// nodes it hangs between, two more lists of nodes, two references, a count
// of its parents that have run, locks and two groups of callables. Its
// destructor unlinks it from its parents and children (its children get
// its parents) before its members go. 8 classes derive from it without a
// destructor of their own (their D2 is this one, their D0s and thunks
// tail-call it: the family's operator delete is empty), 15 more release
// references of their own first. Placeholder names: rename once the classes
// are known.
#include <algorithm>
#include <atomic>
#include <vector>

#include <nn/os.h>

#include "gflib3/Unk_239a418.h"
#include "gflib3/Unk_5cf870.h"

class Unk_2399590;

// What vf7 runs the node with (passed on to its children).
struct Unk_2399590_Arg {
    u8 _0[0x8];
    u32 field_8;
};
PKMN_OFFSET_ASSERT(Unk_2399590_Arg, field_8, 0x8);

// A callable, 0x80 bytes: when it holds one, its manager (+0x8) disposes of
// the storage (+0x20). Clearing it zeroes the four words first. Its storage
// is 16-aligned (a vector of them frees with alignment 0x10).
class Unk_2399590_Callable {
public:
    ~Unk_2399590_Callable() {
        if (void (*manager)(void*) = field_8) {
            field_18 = 0;
            field_10 = 0;
            field_8 = nullptr;
            field_0 = 0;
            manager(field_20);
        }
    }

    u64 field_0;
    void (*field_8)(void*);
    u64 field_10;
    u64 field_18;
    alignas(16) u8 field_20[0x60];
};
static_assert(sizeof(Unk_2399590_Callable) == 0x80, "Unk_2399590_Callable");

// A light event, finalized when it goes.
class Unk_2399590_LightEvent {
public:
    ~Unk_2399590_LightEvent() { Unk_5cf8d0(&field_0); }

    nn::os::LightEventType field_0;
};

// A lock: the thread that holds it (+0x10), taken with a compare-and-swap,
// and a light event to wait on until it's free (signalled when it is).
class Unk_2399590_Lock {
public:
    void Lock() {
        nn::os::ThreadType* self = nn::os::GetCurrentThread();
        nn::os::ThreadType* expected = nullptr;
        while (!field_10.compare_exchange_strong(expected, self, std::memory_order_acquire)) {
            Unk_5cf8f0(&field_4.field_0);
            expected = nullptr;
        }
    }

    void Unlock() {
        field_10.exchange(nullptr, std::memory_order_release);
        Unk_5cf8e0(&field_4.field_0);
    }

    u32 field_0;
    Unk_2399590_LightEvent field_4;
    std::atomic<nn::os::ThreadType*> field_10;
};
static_assert(sizeof(Unk_2399590_Lock) == 0x18, "Unk_2399590_Lock");
PKMN_OFFSET_ASSERT(Unk_2399590_Lock, field_10, 0x10);

// A list of nodes (its constructor takes the allocator from a global).
struct Unk_2399590_Nodes {
    // Takes `node` out of the list, if it's in it.
    void Erase(Unk_2399590* node) {
        auto it = std::find(field_0.begin(), field_0.end(), node);
        if (it != field_0.end())
            field_0.erase(it);
    }

    std::vector<Unk_2399590*, Unk_239a418_StdAllocator<Unk_2399590*>> field_0;
    u64 field_20;
    u32 field_28;
};
static_assert(sizeof(Unk_2399590_Nodes) == 0x30, "Unk_2399590_Nodes");

// A list of callables and whether it holds any to run (+0x30).
struct Unk_2399590_Callables {
    std::vector<Unk_2399590_Callable, Unk_239a418_StdAllocator<Unk_2399590_Callable>> field_0;
    u64 field_20;
    u32 field_28;
    u32 field_2c;
    std::atomic<bool> field_30;
};
static_assert(sizeof(Unk_2399590_Callables) == 0x38, "Unk_2399590_Callables");

// Two lists of callables under a lock, and whether they're running (+0x88).
// Its constructor is 0x71005d14a0.
struct Unk_2399590_Group {
    // Empties the first list, under the lock, if it holds any.
    void Clear() {
        if (field_0.field_30.load(std::memory_order_acquire)) {
            field_70.Lock();
            field_0.field_0.clear();
            field_0.field_30.store(false, std::memory_order_release);
            field_70.Unlock();
        }
    }

    // 0x71005d2a90: runs the first list (under the lock), after moving the
    // second's callables to it.
    void Unk_5d2a90(Unk_2399590_Arg* arg);

    Unk_2399590_Callables field_0;
    Unk_2399590_Callables field_38;
    Unk_2399590_Lock field_70;
    std::atomic<bool> field_88;
};
static_assert(sizeof(Unk_2399590_Group) == 0x90, "Unk_2399590_Group");
PKMN_OFFSET_ASSERT(Unk_2399590_Group, field_70, 0x70);
PKMN_OFFSET_ASSERT(Unk_2399590_Group, field_88, 0x88);

// 0x71005d4c20: takes a node out of what it was registered with (the
// constructor registers it with 0x71005d4d50).
void Unk_5d4c20(void* self, Unk_2399590* node);

class Unk_2399590 : public Unk_239a418 {
public:
    // Its type, whose parent is the object's, inlined into vf_type.
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_239a418_GetType());
        return &type;
    }

    ~Unk_2399590() override;
    void vf3() override;
    // Overrides the interfaces' type getter, so it also gets slot 6 of the
    // primary vtable.
    const Unk_239a418_Type* vf_type() override { return Unk_GetType(); }
    virtual void vf7(Unk_2399590_Arg* arg);

    // 0x71005d1970: adds a parent (if it isn't one yet), and itself to the
    // parent's children (if it isn't one yet).
    void Unk_5d1970(Unk_2399590* parent);

    Unk_2399590_Nodes field_60;  // its parents
    Unk_2399590_Nodes field_90;  // its children
    Unk_2399590_Nodes field_c0;
    Unk_2399590_Nodes field_f0;
    Unk_239a418_Ref<Unk_239a418> field_120;
    Unk_239a418_Ref<Unk_239a418> field_128;
    u64 field_130;
    u64 field_138;
    std::atomic<s32> field_140;  // how many of its parents have run it
    u32 field_144;
    Unk_2399590_Lock field_148;
    void* field_160;  // what it's registered with
    Unk_2399590_Group field_168;
    Unk_2399590_Group field_1f8;
    u32 field_288;
};
static_assert(sizeof(Unk_2399590) == 0x290, "Unk_2399590");
static_assert(__builtin_offsetof(Unk_2399590, field_60) == 0x60, "Unk_2399590::field_60");
static_assert(__builtin_offsetof(Unk_2399590, field_120) == 0x120, "Unk_2399590::field_120");
static_assert(__builtin_offsetof(Unk_2399590, field_148) == 0x148, "Unk_2399590::field_148");
static_assert(__builtin_offsetof(Unk_2399590, field_168) == 0x168, "Unk_2399590::field_168");
static_assert(__builtin_offsetof(Unk_2399590, field_1f8) == 0x1f8, "Unk_2399590::field_1f8");
static_assert(__builtin_offsetof(Unk_2399590, field_288) == 0x288, "Unk_2399590::field_288");
