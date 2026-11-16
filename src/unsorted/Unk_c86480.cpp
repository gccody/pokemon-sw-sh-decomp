// Scope: common
#include <types.h>

// Placeholder delegate: a call target at +0x0 that receives the storage at
// +0x20 and a pointer to each argument (the arguments are forwarded by
// reference, so they're spilled to the stack).
template <class... Args>
struct Unk_c864a0_Delegate {
    void (*invoke)(void* storage, Args&&... args);
    u8 _8[0x18];
    u8 storage[0x20];

    explicit operator bool() const { return invoke != nullptr; }
    void operator()(Args... args) { invoke(storage, static_cast<Args&&>(args)...); }
};

struct Unk_c86480_Flags {
    u8 _0[0x140];
    bool field_140;
};
PKMN_OFFSET_ASSERT(Unk_c86480_Flags, field_140, 0x140);

// 0x7100c86480
bool Unk_c86480_getField140(const Unk_c86480_Flags* self) {
    return self->field_140;
}

// 0x7100c86490
void Unk_c86490_setField140(Unk_c86480_Flags* self) {
    self->field_140 = true;
}

struct Unk_c864a0 {
    u8 _0[0x28];
    u64 field_28;
    u8 field_30[0x148 - 0x30];
    u64 field_148;
    u8 _150[0x1d0 - 0x150];
    Unk_c864a0_Delegate<void*, u64, u64, u64> field_1d0;
};
PKMN_OFFSET_ASSERT(Unk_c864a0, field_28, 0x28);
PKMN_OFFSET_ASSERT(Unk_c864a0, field_30, 0x30);
PKMN_OFFSET_ASSERT(Unk_c864a0, field_148, 0x148);
PKMN_OFFSET_ASSERT(Unk_c864a0, field_1d0, 0x1d0);

// 0x7100c864a0
void Unk_c864a0_notify(Unk_c864a0* self, u64 arg) {
    if (self->field_1d0)
        self->field_1d0(self->field_30, self->field_148, self->field_28, arg);
}

struct Unk_c865d0_Owner {
    u8 _0[0x28];
    u64 field_28;
    u8 field_30[0x148 - 0x30];
    u64 field_148;
    Unk_c864a0_Delegate<void*, u64, u64> field_150;
};
PKMN_OFFSET_ASSERT(Unk_c865d0_Owner, field_148, 0x148);
PKMN_OFFSET_ASSERT(Unk_c865d0_Owner, field_150, 0x150);

struct Unk_c865d0 {
    Unk_c865d0_Owner* field_0;
};

// 0x7100c865d0
void Unk_c865d0_notify(Unk_c865d0* self) {
    Unk_c865d0_Owner* owner = self->field_0;
    owner->field_150(owner->field_30, owner->field_148, owner->field_28);
}

// 0x7100c86630
void Unk_c86630_copy(const u64* self, u64* out) {
    *out = *self;
}

struct Unk_c869a0 {
    u64 field_0;
    u64 field_8;
    u64 field_10;
    u64 field_18;
};
PKMN_SIZE_ASSERT(Unk_c869a0, 0x20);

// 0x7100c869a0
void Unk_c869a0_copy(const Unk_c869a0* self, Unk_c869a0* out) {
    *out = *self;
}

struct Unk_c869e0 {
    u64 field_0;
    u64 field_8;
};
PKMN_SIZE_ASSERT(Unk_c869e0, 0x10);

// 0x7100c869e0
void Unk_c869e0_copy(const Unk_c869e0* self, Unk_c869e0* out) {
    *out = *self;
}

struct Unk_c6d720 {
    void Unk_c6d720_call(u64 a, u64 b);
    void Unk_c6d790_call(u64 a, u64 b);
    void Unk_c6d910_call(void* a, u64 b, u64 c);
};

struct Unk_c86950_Iface {
    virtual void vf_00();
    virtual void vf_08();
    virtual void vf_10();
    virtual void vf_18();
    virtual void vf_20();
    virtual void vf_28();
};

// The functions at 0x7100c86a00, 0x7100c86950 and 0x7100c87610 have the shape of delegate
// invoke functions (see Unk_c864a0_Delegate): `storage` holds a function
// object, and the arguments arrive by reference. The function object's fields
// are loaded after the arguments, as in an inlined call operator.
struct Unk_c86a00_Fn {
    Unk_c6d720* field_0;

    void operator()(void* a, u64 b, u64 /*unused*/, u64 c) const {
        field_0->Unk_c6d910_call(a, b, c);
    }
};
PKMN_SIZE_ASSERT(Unk_c86a00_Fn, 0x8);

// 0x7100c86a00
void Unk_c86a00_invoke(void* storage, void*&& a, u64&& b, u64&& c, u64&& d) {
    (*static_cast<Unk_c86a00_Fn*>(storage))(a, b, c, d);
}

struct Unk_c86950_Fn {
    Unk_c6d720* field_0;
    Unk_c86950_Iface* field_8;
    u64 field_10;
    u64 field_18;

    bool operator()() const {
        field_0->Unk_c6d720_call(field_10, field_18);
        field_8->vf_28();
        return true;
    }
};
PKMN_SIZE_ASSERT(Unk_c86950_Fn, 0x20);

// 0x7100c86950
bool Unk_c86950_invoke(void* storage) {
    return (*static_cast<Unk_c86950_Fn*>(storage))();
}

struct Unk_c87610_Fn {
    Unk_c6d720* field_0;
    Unk_c86950_Iface* field_8;

    void operator()(u64 a, u64 b) const {
        field_0->Unk_c6d790_call(a, b);
        field_8->vf_28();
    }
};
PKMN_SIZE_ASSERT(Unk_c87610_Fn, 0x10);

// 0x7100c87610
void Unk_c87610_invoke(void* storage, u64&& a, u64&& b) {
    (*static_cast<Unk_c87610_Fn*>(storage))(a, b);
}
