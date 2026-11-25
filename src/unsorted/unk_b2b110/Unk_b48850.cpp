// Scope: common
// Calls of two std::function callables (libc++'s __func, vtables
// 0x71023cfac0 and 0x71023cfb08): lambdas that hold a std::function's address
// and call it with their argument, then return 0 (written as that lambda,
// called: with the call spelled out the argument is loaded first); and the
// second one's deleting destructor. Their other slots are in
// src/unsorted/clone and src/unsorted/virtual. Placeholder classes named
// after their vtables, as tools/vtables.py names them.
#include <functional>

#include <types.h>

class __attribute__((visibility("hidden"))) Unk_23cfab0 {
public:
    virtual ~Unk_23cfab0();
    virtual Unk_23cfab0* vf2();
    virtual void vf3(Unk_23cfab0* p);
    virtual void vf4();
    virtual void vf5();
    virtual u32 vf6(u64* value);

    std::function<void(u64)>* field_8;
};
static_assert(sizeof(Unk_23cfab0) == 0x10, "Unk_23cfab0");

// 0x7100b488e0
u32 Unk_23cfab0::vf6(u64* value) {
    std::function<void(u64)>& callback = *field_8;
    auto call = [&callback](u64 v) {
        callback(v);
        return 0u;
    };
    return call(*value);
}

// Its D2 is the shared empty one (0x71009868b0): its destructor is emitted
// here for its D0.
class __attribute__((visibility("hidden"))) Unk_23cfaf8 {
public:
    virtual ~Unk_23cfaf8();
    virtual Unk_23cfaf8* vf2();
    virtual void vf3(Unk_23cfaf8* p);
    virtual void vf4();
    virtual void vf5();
    virtual u32 vf6(u64* value);

    std::function<void(u64)>* field_8;
};
static_assert(sizeof(Unk_23cfaf8) == 0x10, "Unk_23cfaf8");

// 0x7100b48930 (D0)
Unk_23cfaf8::~Unk_23cfaf8() {}

// 0x7100b489c0
u32 Unk_23cfaf8::vf6(u64* value) {
    std::function<void(u64)>& callback = *field_8;
    auto call = [&callback](u64 v) {
        callback(v);
        return 0u;
    };
    return call(*value);
}
