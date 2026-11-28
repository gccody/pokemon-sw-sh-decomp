// Scope: common
// Two callbacks of a battle net watcher (0x71008a7510, 0x71008a7770): each
// holds the watcher and a weak reference to it (the reference's handle), and
// does nothing once the watcher is gone. Part of the segment
// 0x71008a6010-0x71008a7910. Placeholder names: rename once the classes are
// known.
#include <types.h>

#include "gflib3/Unk_239a418.h"

// What the watcher asks, held weakly: which of the five members a station is
// (5: none), and how many it waits for.
class Unk_8a7510_Target {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual u8 vf6(u64 stationId);
    virtual u8 vf7();
};

// A weak reference: the handle that counts the object's references, and the
// object.
template <class T>
struct Unk_8a7510_Weak {
    T* Get() const {
        if (field_0 != nullptr && field_0->field_54.load() != 0)
            return field_8;
        return nullptr;
    }

    Unk_239a418_Handle* field_0;
    T* field_8;
};

// A station in the list: the previous and next ones, and its id. A list of
// its own, not std::list: libc++'s iterator compares the other way round.
struct Unk_27fc0a8_Node {
    Unk_27fc0a8_Node* field_0;
    Unk_27fc0a8_Node* field_8;
    u64 field_10;
};
PKMN_SIZE_ASSERT(Unk_27fc0a8_Node, 0x18);

// The stations, a list at +0x198 (its head a node, linked both ways) of the
// object Unk_27fc0a8 points to.
struct Unk_27fc0a8_Object {
    u8 _0[0x198];
    Unk_27fc0a8_Node field_198;
};
PKMN_OFFSET_ASSERT(Unk_27fc0a8_Object, field_198, 0x198);

extern Unk_27fc0a8_Object* Unk_27fc0a8;
extern u64 Unk_24ba170;

void Unk_6aedf0(u64 self);

struct Unk_8a7510_Watcher {
    // Stops: tells the target, clears what was gathered.
    void Finish() {
        if (Unk_8a7510_Target* target = field_b0.Get())
            target->vf5();
        field_88 = 0;
        field_90 = 0;
        field_98 = 0;
        Unk_6aedf0(Unk_24ba170);
        field_70 = 8;
    }

    u8 _0[0x70];
    u32 field_70;  // the state (8: finished)
    u8 _74[0x88 - 0x74];
    u64 field_88;
    u64 field_90;
    u64 field_98;
    u8 field_a0[5];  // the members that came
    u8 field_a5[5];  // the members that were there already
    u8 _aa[0xb0 - 0xaa];
    Unk_8a7510_Weak<Unk_8a7510_Target> field_b0;
};
PKMN_OFFSET_ASSERT(Unk_8a7510_Watcher, field_70, 0x70);
PKMN_OFFSET_ASSERT(Unk_8a7510_Watcher, field_88, 0x88);
PKMN_OFFSET_ASSERT(Unk_8a7510_Watcher, field_a0, 0xa0);
PKMN_OFFSET_ASSERT(Unk_8a7510_Watcher, field_b0, 0xb0);

// What a callback holds: the watcher and its handle.
struct Unk_8a7510_Callback {
    // Whether the watcher is still there.
    bool IsAlive() const { return field_8 != nullptr && field_8->field_54.load() != 0; }

    Unk_8a7510_Watcher* field_0;
    Unk_239a418_Handle* field_8;
};
PKMN_SIZE_ASSERT(Unk_8a7510_Callback, 0x10);

// 0x71008a7510
void Unk_8a7510(const Unk_8a7510_Callback* self) {
    // Read first, as a lambda's captured `this` is.
    Unk_8a7510_Watcher* watcher = self->field_0;
    if (!self->IsAlive())
        return;
    for (s32 i = 0; i < 5; i++)
        watcher->field_a0[i] = 0;
    if (Unk_27fc0a8_Object* object = Unk_27fc0a8) {
        Unk_8a7510_Target* target = watcher->field_b0.Get();
        if (target != nullptr && watcher->field_70 != 8) {
            const Unk_27fc0a8_Node* head = &object->field_198;
            for (const Unk_27fc0a8_Node* node = head->field_8; node != head; node = node->field_8) {
                u8 member = target->vf6(node->field_10);
                if (member != 5 && watcher->field_a5[member] == 0)
                    watcher->field_a0[member] = 1;
            }
        }
    }
    // The count is taken between the target's lookup and its test: the
    // original's loads follow that order.
    Unk_8a7510_Target* target = watcher->field_b0.Get();
    const u8* came = watcher->field_a0;
    const u8* there = watcher->field_a5;
    u8 count = came[0] + came[1] + came[2] + came[3] + came[4] + there[0] + there[1] + there[2] +
               there[3] + there[4];
    if (target != nullptr && count >= target->vf7()) {
        watcher->field_70 = 3;
        return;
    }
    watcher->Finish();
}

// 0x71008a7770
void Unk_8a7770(const Unk_8a7510_Callback* self) {
    Unk_8a7510_Watcher* watcher = self->field_0;
    if (self->IsAlive())
        watcher->Finish();
}
