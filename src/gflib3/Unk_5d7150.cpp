// Scope: common
//
// A gflib3 event object on its reference-counted object Unk_239a4c0 (vtable
// 0x7102399890), with an interface of its own at +0x58 (vtable
// 0x7102399910) and an nn::os event at +0x60: its constructor initializes
// the event, its destructor finalizes it, and its members wait for, signal
// and clear it through gflib3's event wrappers (src/gflib3/Unk_5cf850.cpp).
// Placeholder names: rename once the class is known.
#include <nn/os.h>

#include "gflib3/Unk_239a4c0.h"
#include "gflib3/Unk_5cf870.h"
#include "unsorted/Unk_2771620.h"

// The interface at +0x58: its type getter (0x71005d7520, a type-getter
// TU's copy), then its destructor.
class Unk_2399900 {
public:
    virtual const Unk_239a418_Type* vf0();
    virtual ~Unk_2399900() {}
};

// The event (the SDK's EventType, 0x28 bytes), finalized when it goes.
struct Unk_2399880_Event {
    ~Unk_2399880_Event() { Unk_5cf880(Get()); }

    nn::os::EventType* Get() { return reinterpret_cast<nn::os::EventType*>(field_0); }

    alignas(8) u8 field_0[0x28];
};

class Unk_2399880 : public Unk_239a4c0, public Unk_2399900 {
public:
    Unk_2399880(nn::os::EventClearMode clearMode, bool signaled);
    ~Unk_2399880() override;
    // 0x71005d7450, its type getter (src/unsorted/types/Unk_5d7450.cpp).
    virtual const Unk_239a418_Type* vf5();
    virtual bool vf6();
    virtual void vf7();

    void Unk_5d73d0();

    nn::os::EventType* Event() { return field_60.Get(); }

    Unk_2399880_Event field_60;
};
static_assert(__builtin_offsetof(Unk_2399880, field_60) == 0x60, "Unk_2399880::field_60");

// 0x71005d7310
Unk_2399880::Unk_2399880(nn::os::EventClearMode clearMode, bool signaled) {
    Unk_5cf870(Event(), clearMode, signaled);
}

// 0x71005d73c0: whether the event is signalled (clearing it if it clears
// itself).
bool Unk_2399880::vf6() {
    return Unk_5cf890(Event());
}

// 0x71005d73d0: signals the event.
void Unk_2399880::Unk_5d73d0() {
    Unk_5cf8a0(Event());
}

// 0x71005d73e0: clears the event.
void Unk_2399880::vf7() {
    Unk_5cf8b0(Event());
}

// 0x71005d73f0, 0x71005d7420 (D0), thunks 0x71005d74c0/0x71005d74f0 (+0x48)
// and 0x71005d7610/0x71005d7640 (+0x58).
Unk_2399880::~Unk_2399880() {}
