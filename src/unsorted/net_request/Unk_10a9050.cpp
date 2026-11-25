// Scope: common
// The object a request step makes and waits on, and the step's vf2 and vf11
// (src/unsorted/net_request/Unk_10a9050.h). Placeholder names: rename once
// the classes are known.
#include "unsorted/net_request/Unk_10a9050.h"

// src/gflib3/Unk_New.h, instantiated in Unk_10a9660.cpp (declared here: its
// inline body would be inlined).
struct Unk_New {
    template <class T, class... Args>
    T* Create(Unk_239a418_Allocator* allocator, Args&&... args);
};

bool Unk_15bbc70_check(const Unk_15bbc70* self, const u32* value);

// The network system (gflib3) and its connection.
struct Unk_6a41e0;
struct Unk_6a9270;

// What the connection is given: a weak reference to what it tells.
struct Unk_6a96f0_Arg {
    Unk_6a96f0_Arg(const Unk_239a418_Ref2<Unk_239a418_Handle>& handle, Unk_24108a8* target)
        : field_0(handle), field_8(target) {}

    Unk_239a418_Ref2<Unk_239a418_Handle> field_0;
    Unk_24108a8* field_8;
};

extern Unk_6a41e0* Unk_2778bf8;

struct Unk_24ba560_Object {
    u8 _0[0xc8];
    Unk_239a418_Allocator* field_c8;
};
PKMN_OFFSET_ASSERT(Unk_24ba560_Object, field_c8, 0xc8);

extern Unk_24ba560_Object* Unk_24ba560;

bool Unk_6a4160(Unk_6a41e0* self);
bool Unk_6a41f0(Unk_6a41e0* self);
Unk_6a9270* Unk_6a41e0_getFieldc8(const Unk_6a41e0* self);
void Unk_6a96f0(Unk_6a9270* self, Unk_6a96f0_Arg arg);
bool Unk_6aa010(Unk_6a9270* self, u32 value);

// 0x71010a9050, its thunk from +0x60 0x71010a9070
void Unk_2411318::vf4(bool ok) {
    field_68 = {1, 1};
    if (!ok)
        SetResult(1);
}

// 0x71010a9090, its thunk from +0x60 0x71010a90e0
void Unk_2411318::vf5(const Unk_15bbc70* result) {
    u32 code = 0x8074000e;
    SetResult(Unk_15bbc70_check(result, &code));
}

// NON_MATCHING: control flow and registers: the original keeps the result in
// a callee-saved register up to one return, a flag for whether the handle is
// held, and duplicates the vf1 call; the logic and the calls are the same.
// 0x71010a9130
bool Unk_2411420::vf2() {
    Unk_10a9050_Callable* target = vf11();
    bool done = false;
    switch (field_14) {
        case 0: {
            Unk_6a41e0* system = Unk_2778bf8;
            field_40 = Unk_6a4160(system);
            if (!field_40) {
                field_14 = 2;
                break;
            }
            u32 value = field_28;
            Unk_6a9270* connection = Unk_6a41e0_getFieldc8(system);
            Unk_2411318* object = Unk_New().Create<Unk_2411318>(Unk_24ba560->field_c8);
            {
                Unk_239a418_Ref<Unk_2411318> ref(object);
                if (field_38.m_ptr != nullptr) {
                    static_cast<Unk_239a458*>(field_38.m_ptr)->vf5();
                    field_38.m_ptr = nullptr;
                }
                field_38.m_ptr = ref.Release();
            }
            if (object == nullptr) {
                field_14 = 2;
                break;
            }
            Unk_24108a8* listener = object;
            Unk_239a418_Ref2<Unk_239a418_Handle> handle(static_cast<Unk_239a418*>(object)->vf2());
            Unk_6a96f0(connection, Unk_6a96f0_Arg(handle, listener));
            field_14 = Unk_6aa010(connection, value) ? 1 : 2;
            break;
        }
        case 1: {
            Unk_2411318_State state = field_38.m_ptr->GetState();
            if (state.field_0) {
                field_41 = state.field_1;
                field_14 = 2;
            }
            break;
        }
        case 2:
            if (field_40)
                Unk_6a41f0(Unk_2778bf8);
            if (field_41) {
                target->vf0();
            } else {
                Unk_10a9050_Error error = {
                    1, field_38.m_ptr != nullptr ? field_38.m_ptr->field_6c : 0};
                target->vf1(error);
            }
            done = true;
            break;
    }
    return done;
}

// 0x71010a93a0
Unk_10a9050_Callable* Unk_2411420::vf11() {
    Unk_10a9050_Callable* target = Unk_2411490::vf11();
    return target != nullptr ? target : &field_30;
}

// 0x71010a9410, its thunks from +0x48 0x71010a9550 (D1) and 0x71010a95a0 (D0)
// and from +0x50 0x71010a9610 (D1) and 0x71010a9660 (D0). Its vf_type's
// thunks are emitted with the vtable: 0x71010a95f0 (+0x48), 0x71010a9600 (+0x50).
Unk_2411318::~Unk_2411318() {}
