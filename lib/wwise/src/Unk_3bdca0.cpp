// Scope: common
// The manager of the transitions (a value that goes from one level to
// another over a time, and the objects it is given to): two arrays of them.
// Written from the executable. Placeholder names.
#include "containers.h"

// What is given the transition's value.
struct Unk_3bdca0_User {
    virtual void vf0(void* target, f32 value, bool done);
};

// A transition: 0x48 bytes. lib/wwise/leaf has its small functions, with a
// type name each.
struct Unk_3bd6b0 {
    void* field_0;  // what the value is for
    f32 field_8;  // from
    f32 field_c;  // to
    f32 field_10;  // the value now
    f32 field_14;  // and at the end
    u32 field_18;  // when it started
    u32 field_1c;  // how long it takes
    f32 field_20;
    u32 field_24;
    Unk_Array<Unk_3bdca0_User*, Unk_PoolDefault, 4> field_28;
    u32 field_38;  // curve
    u32 field_3c;  // state: 1 and 2 paused, 3 and 4 to resume, 6 to remove
    u8 field_40;
    f32 field_44;
};
PKMN_SIZE_ASSERT(Unk_3bd6b0, 0x48);
PKMN_OFFSET_ASSERT(Unk_3bd6b0, field_28, 0x28);
PKMN_OFFSET_ASSERT(Unk_3bd6b0, field_3c, 0x3c);

struct Unk_3bd6f0;
void Unk_3bd6b0_set(Unk_3bd6b0* self);  // constructs it
void Unk_3bd6e0_update(u64 self);  // its destructor
void Unk_3bd6f0_call(Unk_3bd6f0* self);  // frees its array

// What a transition is started with.
struct Unk_3bdd90_Params {
    Unk_3bdca0_User* field_0;
    void* field_8;
    f32 field_10;
    f32 field_14;  // the level to reach
};

// The engine: the time is at 0x78.
struct Unk_3bdca0_Engine {
    u8 _0[0x78];
    u32 field_78;
};
extern Unk_3bdca0_Engine* Unk_24bbbc0;

typedef Unk_Array<Unk_3bd6b0*, Unk_PoolDefault, 0x80> Unk_3bdca0_List;

struct Unk_3bdca0 {
    Unk_3bdca0_List field_0;
    Unk_3bdca0_List field_10;
};

bool Unk_3bd7c0(Unk_3bd6b0* self, u32 time);  // true when it has ended
u32 Unk_3bd940(Unk_3bd6b0* self, Unk_3bdd90_Params* params, u32 time);
void Unk_3bdcd0(Unk_3bdca0* self, Unk_3bdca0_List* list);
void Unk_3be5a0(Unk_3bdca0* self, u32 time, Unk_3bdca0_List* list);

static inline void Unk_3bdca0_Delete(Unk_3bd6b0* transition) {
    if (transition != nullptr) {
        int pool = Unk_237e820;
        Unk_3bd6e0_update(reinterpret_cast<u64>(transition));
        Unk_3047c0(pool, transition);
    }
}

static inline void Unk_3bdca0_Pause(Unk_3bd6b0* transition) {
    if (transition->field_3c == 1)
        transition->field_3c = 2;
    else if (transition->field_3c == 4)
        transition->field_3c = 3;
}

static inline void Unk_3bdca0_Resume(Unk_3bd6b0* transition) {
    if (transition->field_3c == 3)
        transition->field_3c = 4;
    else if (transition->field_3c == 2)
        transition->field_3c = 1;
}

// 0x71003bdca0
void Unk_3bdca0_Term(Unk_3bdca0* self) {
    Unk_3bdcd0(self, &self->field_0);
    Unk_3bdcd0(self, &self->field_10);
}

// 0x71003bdcd0: ends the transitions of a list and frees it
void Unk_3bdcd0(Unk_3bdca0* /*self*/, Unk_3bdca0_List* list) {
    if (!list->IsEmpty()) {
        for (auto it = list->Begin(); it != list->End(); ++it) {
            Unk_3bd6b0* transition = *it;
            Unk_3bd7c0(transition, transition->field_18 + transition->field_1c);
            Unk_3bd6f0_call(reinterpret_cast<Unk_3bd6f0*>(transition));
            Unk_3bdca0_Delete(transition);
        }
    }
    list->Term();
}

// 0x71003bdd90: a new transition, or the user is given the level at once
Unk_3bd6b0* Unk_3bdd90(Unk_3bdca0* self, Unk_3bdd90_Params* params, bool paused, u32 kind) {
    Unk_3bdca0_List* list = kind == 1 ? &self->field_10 : &self->field_0;
    Unk_3bd6b0* transition =
        static_cast<Unk_3bd6b0*>(Unk_3045e0(Unk_237e820, sizeof(Unk_3bd6b0)));
    if (transition != nullptr) {
        Unk_3bd6b0_set(transition);
        if (Unk_3bd940(transition, params, Unk_24bbbc0->field_78) != 2) {
            if (list->AddLastGrow(transition) != nullptr) {
                if (paused)
                    transition->field_3c = 1;
                return transition;
            }
        }
        Unk_3bd6f0_call(reinterpret_cast<Unk_3bd6f0*>(transition));
        Unk_3bdca0_Delete(transition);
    }
    params->field_0->vf0(params->field_8, params->field_14, true);
    return nullptr;
}

// 0x71003bdf70
void Unk_3bdf70(Unk_3bdca0* self) {
    for (auto it = self->field_10.Begin(); it != self->field_10.End(); ++it)
        Unk_3bdca0_Pause(*it);
}

// 0x71003bdfc0
void Unk_3bdfc0(Unk_3bdca0* self) {
    for (auto it = self->field_10.Begin(); it != self->field_10.End(); ++it)
        Unk_3bdca0_Resume(*it);
}

// 0x71003be010: one more user for a transition
u32 Unk_3be010(Unk_3bdca0* /*self*/, Unk_3bd6b0* transition, Unk_3bdca0_User* user) {
    if (transition->field_28.Exists(user) == nullptr) {
        if (transition->field_28.AddLastGrow(user) != nullptr)
            return 1;
    }
    return 2;
}

// 0x71003be1a0 has the name of a function with these parameters
// (lib/wwise/leaf's scan): one user less; without users the transition goes.
u32 Unk_3be1a0(u64 /*self*/, void* arg1, void* arg2) {
    Unk_3bd6b0* transition = static_cast<Unk_3bd6b0*>(arg1);
    auto it = transition->field_28.FindEx(static_cast<Unk_3bdca0_User*>(arg2));
    if (it == transition->field_28.End())
        return 0x1d;
    transition->field_28.EraseSwap(it);
    if (transition->field_28.IsEmpty())
        transition->field_3c = 6;
    return 1;
}

// 0x71003be230
void Unk_3be230(Unk_3bdca0* /*self*/, Unk_3bd6b0* transition) {
    Unk_3bdca0_Pause(transition);
}

// 0x71003be260
void Unk_3be260(Unk_3bdca0* /*self*/, Unk_3bd6b0* transition) {
    Unk_3bdca0_Resume(transition);
}

// 0x71003be570: the time goes on for both lists
void Unk_3be570(Unk_3bdca0* self, u32 time) {
    Unk_3be5a0(self, time, &self->field_0);
    Unk_3be5a0(self, time, &self->field_10);
}

// 0x71003be5a0: the time goes on for a list's transitions
void Unk_3be5a0(Unk_3bdca0* /*self*/, u32 time, Unk_3bdca0_List* list) {
    u32 i = 0;
    while (i < list->Length()) {
        Unk_3bd6b0* transition = list->field_0[i];
        if (transition->field_3c == 6) {
            Unk_3bd6f0_call(reinterpret_cast<Unk_3bd6f0*>(transition));
            Unk_3bdca0_Delete(transition);
            list->Erase(i);
        } else {
            switch (transition->field_3c) {
            case 2:
                transition->field_24 = time;
                transition->field_3c = 3;
                break;
            case 4:
                transition->field_18 += time - transition->field_24;
                transition->field_3c = 1;
                break;
            default:
                break;
            }
            if (transition->field_3c == 1 && Unk_3bd7c0(transition, time)) {
                Unk_3bd6f0_call(reinterpret_cast<Unk_3bd6f0*>(transition));
                list->Erase(i);
                Unk_3bdca0_Delete(transition);
            } else {
                ++i;
            }
        }
    }
}
