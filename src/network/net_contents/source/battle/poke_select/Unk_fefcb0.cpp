// Scope: common
//
// A class on gflib3's reference-counted object (vtable 0x7102406090), next to
// the battle team selection's channel (Unk_fee160.cpp): it listens to the net
// peers (slot 0 of its primary interface) and puts itself, weakly, on two of
// the net managers' lists (Unk_feffa0, taken off by Unk_ff00f0). The segment
// 0x7100fefcb0-0x7100ff03d0. Placeholder names: rename once the classes are
// known.
#include <types.h>

#include "gflib3/Unk_239a418.h"

// The type 0x71027e2828.
struct Unk_27e2828 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_239a418_GetType());
        return &type;
    }
};

// An interface with one function (vtable 0x71023b8fb8, its slot pure):
// what the peer manager (Unk_24ba170) calls, with what happened and the peer.
class Unk_23b8fb8 {
public:
    virtual void vf0(s32 kind, u64 peer) = 0;
};

// An interface with one function (vtable 0x71023b8fd0, its slot pure): what
// the stack of Unk_24ba598 holds.
class Unk_23b8fd0 {
public:
    virtual void vf4() = 0;
};

// A weak reference: a reference to the object's handle, and the object.
template <class T>
struct Unk_fefcb0_Weak {
    Unk_fefcb0_Weak() : m_ptr(nullptr) {}
    Unk_fefcb0_Weak(const Unk_239a418_Ref<Unk_239a418_Handle>& handle, T* ptr)
        : m_handle(handle), m_ptr(ptr) {}

    Unk_239a418_Ref<Unk_239a418_Handle> m_handle;
    T* m_ptr;
};
static_assert(sizeof(Unk_fefcb0_Weak<Unk_23b8fb8>) == 0x10, "Unk_fefcb0_Weak");

// The managers: the peer manager and the stack.
extern u64 Unk_24ba170;
extern u64 Unk_24ba150;
extern u64 Unk_24ba598;

u8 Unk_6ae9d0(u64 peer);  // the client of a peer
void Unk_104bf60(u64 self);
// Adds a listener to the peer manager's list, and takes one off.
void Unk_6aea40(u64 self, const Unk_fefcb0_Weak<Unk_23b8fb8>& listener);
void Unk_6aeb70(u64 self, const Unk_fefcb0_Weak<Unk_23b8fb8>& listener);
// Pushes onto the stack (8 at most), and pops its top.
void Unk_104dfb0(u64 self, const Unk_fefcb0_Weak<Unk_23b8fd0>& entry);
void Unk_104dfd0(u64 self);

class Unk_2406090 : public Unk_23b8fb8, public Unk_23b8fd0, public Unk_239a418 {
public:
    Unk_2406090();
    void vf0(s32 kind, u64 peer) override;
    const Unk_239a418_Type* vf_type() override { return Unk_27e2828::Unk_GetType(); }
    ~Unk_2406090() override {}
    void vf4() override;

    void Unk_feffa0(bool flag);

    bool field_70;
};
static_assert(sizeof(Unk_2406090) == 0x78, "Unk_2406090");
PKMN_OFFSET_ASSERT(Unk_2406090, field_70, 0x70);

// 0x7100fefcb0
Unk_2406090::Unk_2406090() : field_70(false) {}

// 0x7100ff01c0
void Unk_2406090::vf0(s32 kind, u64 peer) {
    if (kind != 1)
        return;
    if (field_70 && Unk_24ba170 != 0 && Unk_6ae9d0(peer) > 1)
        return;
    if (Unk_24ba150 != 0)
        Unk_104bf60(Unk_24ba150);
}

// 0x7100feffa0
void Unk_2406090::Unk_feffa0(bool flag) {
    field_70 = flag;
    if (u64 stack = Unk_24ba598) {
        Unk_fefcb0_Weak<Unk_23b8fd0> entry(vf2(), this);
        Unk_104dfb0(stack, entry);
    }
    if (u64 peers = Unk_24ba170) {
        Unk_fefcb0_Weak<Unk_23b8fb8> listener(vf2(), this);
        Unk_6aea40(peers, listener);
    }
}

// A weak reference to `object` (none when it's null).
template <class T>
Unk_fefcb0_Weak<T> Unk_fefcb0_WeakOf(Unk_2406090* object) {
    if (object == nullptr)
        return Unk_fefcb0_Weak<T>();
    return Unk_fefcb0_Weak<T>(object->vf2(), object);
}

// 0x7100ff00f0
void Unk_ff00f0(Unk_2406090* object) {
    if (Unk_24ba598 != 0)
        Unk_104dfd0(Unk_24ba598);
    if (u64 peers = Unk_24ba170) {
        Unk_fefcb0_Weak<Unk_23b8fb8> listener = Unk_fefcb0_WeakOf<Unk_23b8fb8>(object);
        Unk_6aeb70(peers, listener);
    }
}

// Emitted with the vtable (its key function is vf0):
// 0x7100fefd20 (D2), 0x7100fefe60 (D0), and the destructor thunks
// 0x7100fefd70/0x7100fefeb0 (+0x10), 0x7100fefdc0/0x7100feff00 (+0x58),
// 0x7100fefe10/0x7100feff50 (+0x60); vf_type 0x7100ff0240 and its thunks
// 0x7100ff0330 (+0x58), 0x7100ff0340 (+0x60).
