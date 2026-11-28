// Scope: common
//
// A gflib3 node that runs a callable (Unk_2399928, vtable 0x7102399938), on
// the abstract node Unk_2399708 (vtable 0x7102399718), and two functions
// over an object with five lists of listeners, which the second runs for the
// applet's notification messages. Placeholder names: rename once the classes
// are known.
#include <vector>

#include <nn/os.h>

#include "gflib3/Unk_2399590.h"
#include "unsorted/Unk_2771620.h"

// The abstract node on Unk_2399590 that 74 functions store the vtable of:
// a reference (+0x290), a count (+0x298, 1 to start with) and a flag its
// constructor takes. Its destructor is inline (its out-of-line copy is
// 0x71005ec610), its slot 8 pure.
// What Unk_2399708's constructor takes its reference from (its slot 4).
class Unk_2399708_Arg;

class Unk_2399708 : public Unk_2399590 {
public:
    // 0x71005d54c0 (not decompiled yet).
    Unk_2399708(Unk_2399708_Arg* arg, bool flag);

    // 0x71005d5870 (a type-getter TU's copy).
    const Unk_239a418_Type* vf_type() override;
    // 0x71005d57d0 (not decompiled yet).
    void vf7(Unk_2399590_Arg* arg) override;
    virtual void vf8(Unk_2399590_Arg* arg) = 0;

    Unk_239a418_Ref<Unk_239a418> field_290;
    u32 field_298 = 1;
    bool field_29c;
};
static_assert(sizeof(Unk_2399708) == 0x2a0, "Unk_2399708");
static_assert(__builtin_offsetof(Unk_2399708, field_290) == 0x290, "Unk_2399708::field_290");
static_assert(__builtin_offsetof(Unk_2399708, field_298) == 0x298, "Unk_2399708::field_298");
static_assert(__builtin_offsetof(Unk_2399708, field_29c) == 0x29c, "Unk_2399708::field_29c");

// A callable, the shape of Unk_2399590_Callable: what calls it (+0x0) and
// its manager (+0x8), which disposes of the storage (+0x20). It starts
// empty; going, it zeroes the four words first.
class Unk_2399928_Callable {
public:
    Unk_2399928_Callable() : field_0(nullptr), field_8(nullptr), field_10(0), field_18(0) {}
    ~Unk_2399928_Callable() {
        if (void (*manager)(void*) = field_8) {
            field_18 = 0;
            field_10 = 0;
            field_8 = nullptr;
            field_0 = nullptr;
            manager(field_20);
        }
    }

    void (*field_0)(void*, Unk_2399590_Arg*);
    void (*field_8)(void*);
    u64 field_10;
    u64 field_18;
    alignas(16) u8 field_20[0x60];
};
static_assert(sizeof(Unk_2399928_Callable) == 0x80, "Unk_2399928_Callable");

class Unk_2399928 : public Unk_2399708 {
public:
    Unk_2399928(Unk_2399708_Arg* arg, bool flag);
    ~Unk_2399928() override;

    // 0x71005d7870 (a type-getter TU's copy).
    const Unk_239a418_Type* vf_type() override;
    void vf8(Unk_2399590_Arg* arg) override;

    Unk_2399928_Callable field_2a0;
};
static_assert(sizeof(Unk_2399928) == 0x320, "Unk_2399928");
static_assert(__builtin_offsetof(Unk_2399928, field_2a0) == 0x2a0, "Unk_2399928::field_2a0");

// 0x71005d7670
Unk_2399928::Unk_2399928(Unk_2399708_Arg* arg, bool flag) : Unk_2399708(arg, flag) {}

// 0x71005d7730: runs the callable, if it holds one.
void Unk_2399928::vf8(Unk_2399590_Arg* arg) {
    if (field_2a0.field_0)
        field_2a0.field_0(field_2a0.field_20, arg);
}

// 0x71005d7750, 0x71005d77e0 (D0), thunks 0x71005d78e0/0x71005d7980 (+0x48)
// and 0x71005d7b00/0x71005d7ba0 (+0x50).
Unk_2399928::~Unk_2399928() {}

// A listener: run through its slot 1.
class Unk_5d7c40_Listener {
public:
    virtual void vf0();
    virtual void vf1();
};

// A list of listeners, added to under a lock (+0x90) by 0x71005ed5e0.
struct Unk_5d7c40_List {
    // Runs its listeners.
    void Run() {
        for (Unk_5d7c40_Listener* listener : field_60)
            listener->vf1();
    }

    u8 _0[0x60];
    std::vector<Unk_5d7c40_Listener*, Unk_2771620_Allocator<Unk_5d7c40_Listener*>> field_60;
};
PKMN_OFFSET_ASSERT(Unk_5d7c40_List, field_60, 0x60);

// 0x71005ed5e0 (not decompiled yet): adds a listener to the list.
void Unk_5ed5e0(Unk_5d7c40_List* list, Unk_5d7c40_Listener* listener);

// What holds five lists of listeners, for five of the applet's notification
// messages.
struct Unk_5d7c40_Self {
    u8 _0[0x50];
    Unk_5d7c40_List* field_50[5];
};
PKMN_OFFSET_ASSERT(Unk_5d7c40_Self, field_50, 0x50);

namespace nn {
namespace oe {
bool TryPopNotificationMessage(u32* message);
}  // namespace oe
}  // namespace nn

// 0x71005d7c40: adds a listener to one of the lists.
void Unk_5d7c40(Unk_5d7c40_Self* self, s32 index, Unk_5d7c40_Listener* listener) {
    Unk_5ed5e0(self->field_50[index], listener);
}

// 0x71005d7c50: takes the applet's next notification message, if there is
// one, and runs the listeners of its list (messages 15, 16, 30, 31 and 4, in
// that order in the object).
void Unk_5d7c50(Unk_5d7c40_Self* self) {
    u32 message;
    if (!nn::oe::TryPopNotificationMessage(&message))
        return;
    switch (message) {
        case 4:
            self->field_50[4]->Run();
            break;
        case 15:
            self->field_50[0]->Run();
            break;
        case 16:
            self->field_50[1]->Run();
            break;
        case 30:
            self->field_50[2]->Run();
            break;
        case 31:
            self->field_50[3]->Run();
            break;
    }
}
