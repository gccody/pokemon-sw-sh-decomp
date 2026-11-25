// Scope: common
// NintendoWare ui2d 7.3.2: nn::ui2d::Layout's static allocator functions and
// settings, and its destructors (vtable 0x71024931f0: slot 0 is its runtime
// type getter, the RTTI is N2nn4ui2d6LayoutE). Placeholder names.
#include "nx_middleware/gfx/Unk_179c420.h"
#include "nx_middleware/gfx/Unk_179cc10.h"

void operator delete(void* ptr) noexcept;

// 0x710179cc10
Unk_24931a0* Unk_179cc10(Unk_179cc10_List* list, const char* name) {
    for (Unk_179cc10_ListNode* node = list->begin(); node != list->end(); node = node->next) {
        Unk_24931a0* object = Unk_24931a0::FromLink(node);
        if (Unk_24931a0::EqualsName(object->name, name)) {
            return object;
        }
    }
    return nullptr;
}

// 0x710179ccc0
void Unk_179ccc0(Unk_179cc10_AllocateFunction allocateFunction, Unk_179cc10_FreeFunction freeFunction,
                 void* userData) {
    Unk_27fd788 = allocateFunction;
    Unk_27fd790 = freeFunction;
    Unk_27fd798 = userData;
}

// 0x710179ccf0
void* Unk_179ccf0(size_t size, size_t alignment) {
    return Unk_27fd788(size, alignment, Unk_27fd798);
}

// 0x710179cd10
void* Unk_179cd10(size_t size) {
    return Unk_27fd788(size, 4, Unk_27fd798);
}

// 0x710179cd30
void Unk_179cd30(u64 ptr) {
    Unk_27fd790(reinterpret_cast<void*>(ptr), Unk_27fd798);
}

extern s32 Unk_24931d0;
extern s32 Unk_24931d4;
extern s32 Unk_24931d8;
extern s32 Unk_24931dc;

// 0x710179cd50
void Unk_179cd50(s32 count0, s32 count1, s32 count2, s32 count3) {
    Unk_24931d0 = count0;
    Unk_24931d4 = count1;
    Unk_24931d8 = count2;
    Unk_24931dc = count3;
}

// 0x710179cde0: the deleting destructor (the complete one, 0x710179cdc0, only
// sets the vptr).
void Unk_179cde0(void* self) {
    operator delete(self);
}

// What 0x710179cdf0 destroys. Only the members it touches are known.
struct Unk_179cdf0_Buffer {
    void Finalize() {
        if (field_8 != nullptr) {
            Unk_179cd30(reinterpret_cast<u64>(field_8));
        }
    }

    u64 field_0;
    void* field_8;
};
PKMN_OFFSET_ASSERT(Unk_179cdf0_Buffer, field_8, 0x8);

class Unk_179cdf0_Pane {
public:
    virtual ~Unk_179cdf0_Pane();
    virtual void vf2();
    virtual void vf3(void* device);

    u8 _8[0x58 - 0x8];
    u8 flags;
};
PKMN_OFFSET_ASSERT(Unk_179cdf0_Pane, flags, 0x58);

// An object of the list at 0x8: its node follows the vptr.
class Unk_179cdf0_Linked {
public:
    virtual void vf0();
    virtual ~Unk_179cdf0_Linked();

    static Unk_179cdf0_Linked* FromLink(Unk_179cc10_ListNode* node) {
        return reinterpret_cast<Unk_179cdf0_Linked*>(reinterpret_cast<u8*>(node) - 8);
    }

    Unk_179cc10_ListNode link;
};
PKMN_OFFSET_ASSERT(Unk_179cdf0_Linked, link, 0x8);

void Unk_179cb50(Unk_179cc10_List* list);

struct Unk_179cdf0_Self {
    void* vptr;
    Unk_179cc10_List field_8;
    Unk_179cdf0_Pane* field_18;
    Unk_179cc10_List* field_20;
    u64 field_28;
    u64 field_30;
    u64 field_38;
    u64 field_40;
    Unk_179cc10_List field_48;
    Unk_179cdf0_Buffer* field_58;
};
PKMN_OFFSET_ASSERT(Unk_179cdf0_Self, field_18, 0x18);
PKMN_OFFSET_ASSERT(Unk_179cdf0_Self, field_48, 0x48);
PKMN_OFFSET_ASSERT(Unk_179cdf0_Self, field_58, 0x58);

template <typename T>
static void Unk_179cdf0_Delete(T* object) {
    if (object != nullptr) {
        object->~T();
        Unk_179cd30(reinterpret_cast<u64>(object));
    }
}

// NON_MATCHING: the original keeps the erase's end() check before each unlink; clang folds it here, as the loop condition implies it (the loop over field_8)
// 0x710179cdf0
void Unk_179cdf0(Unk_179cdf0_Self* self, void* device) {
    if (self->field_58 != nullptr) {
        self->field_58->Finalize();
        Unk_179cdf0_Delete(self->field_58);
        self->field_58 = nullptr;
    }
    while (!self->field_48.empty()) {
        self->field_48.erase(self->field_48.begin());
    }
    Unk_179cc10_List* list = self->field_20;
    if (list != nullptr) {
        Unk_179cb50(list);
        Unk_179cd30(reinterpret_cast<u64>(list));
    }
    self->field_20 = nullptr;
    if (self->field_18 != nullptr && (self->field_18->flags & 8) == 0) {
        self->field_18->vf3(device);
        Unk_179cdf0_Delete(self->field_18);
        self->field_18 = nullptr;
    }
    for (Unk_179cc10_ListNode* node = self->field_8.begin(); self->field_8.end() != node;) {
        Unk_179cc10_ListNode* current = node;
        node = self->field_8.erase(current);
        Unk_179cdf0_Linked* object = Unk_179cdf0_Linked::FromLink(current);
        object->~Unk_179cdf0_Linked();
        Unk_179cd30(reinterpret_cast<u64>(object));
    }
    self->field_28 = 0;
    self->field_30 = 0;
    self->field_38 = 0;
    self->field_40 = 0;
}

void Unk_17a38b0(void* self, void* arg, void* owner, void* res, void* target);
void Unk_17a3ad0(void* self, void* arg, void* owner, void* res, void* target);

// An element of Unk_179d130_Outer's list: its node follows four pointers.
struct Unk_179d130_Element {
    struct Target {
        u8 _0[0x30];
        void* field_30;
    };

    Target* field_0;
    void* field_8;
    void* field_10;
    const char* field_18;
    Unk_179cc10_ListNode link;
};
PKMN_OFFSET_ASSERT(Unk_179d130_Element::Target, field_30, 0x30);
PKMN_OFFSET_ASSERT(Unk_179d130_Element, link, 0x20);

struct Unk_179d130_Owner {
    u8 _0[0x18];
    Unk_179c940_Finder* field_18;
};
PKMN_OFFSET_ASSERT(Unk_179d130_Owner, field_18, 0x18);

// An element of Unk_179d130_Self's list: its node comes first.
struct Unk_179d130_Outer {
    Unk_179d130_Element* GetElement(int index) {
        int i = 0;
        for (Unk_179cc10_ListNode* node = elements.begin(); node != elements.end(); node = node->next) {
            if (index == i) {
                return reinterpret_cast<Unk_179d130_Element*>(reinterpret_cast<u8*>(node) - 0x20);
            }
            i++;
        }
        return nullptr;
    }

    Unk_179cc10_ListNode link;
    Unk_179d130_Owner* field_10;
    u8 _18[0x38 - 0x18];
    Unk_179cc10_List elements;
    s32 count;
};
PKMN_OFFSET_ASSERT(Unk_179d130_Outer, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_179d130_Outer, elements, 0x38);
PKMN_OFFSET_ASSERT(Unk_179d130_Outer, count, 0x48);

struct Unk_179d130_Self {
    struct Field20 {
        void Clear() {
            field_0 = 0;
            field_10 = 0;
            field_20 = 0;
        }

        u64 field_0;
        u64 field_8;
        u64 field_10;
        u64 field_18;
        u64 field_20;
    };

    u64 field_0;
    u64 field_8;
    Unk_179cc10_List* field_10;
    u32 field_18;
    Field20* field_20;
    void* field_28;
};
PKMN_OFFSET_ASSERT(Unk_179d130_Self, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_179d130_Self, field_20, 0x20);
PKMN_SIZE_ASSERT(Unk_179d130_Self, 0x30);

// NON_MATCHING: register allocation: the original keeps the outer list's node in another register (one more mov)
// 0x710179d130
void Unk_179d130(Unk_179d130_Self* self, void* arg) {
    for (Unk_179cc10_ListNode* node = self->field_10->begin(); self->field_10->end() != node;) {
        Unk_179d130_Outer* outer = reinterpret_cast<Unk_179d130_Outer*>(node);
        int count = outer->count;
        node = node->next;
        Unk_179d130_Owner* owner = outer->field_10;
        for (int i = 0; i < count; i++) {
            Unk_179d130_Element* element = outer->GetElement(i);
            if (element->field_0->field_30 != nullptr) {
                continue;
            }
            void* target = owner->field_18->vf12(element->field_18, true);
            if (element->field_8 != nullptr) {
                Unk_17a38b0(element->field_0, arg, owner, element->field_8, target);
            } else if (element->field_10 != nullptr) {
                Unk_17a3ad0(element->field_0, arg, owner, element->field_10, target);
            }
        }
    }
}

struct Unk_179cfc0_Arg6 {
    u64 field_0;
    u32 field_8;
};
PKMN_OFFSET_ASSERT(Unk_179cfc0_Arg6, field_8, 0x8);

struct Unk_179cfc0_Arg7 {
    u8 field_0;
    u64 field_8;
    u64 field_10;
    u8 field_18;
    u8 field_19;
};
PKMN_OFFSET_ASSERT(Unk_179cfc0_Arg7, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_179cfc0_Arg7, field_18, 0x18);
PKMN_OFFSET_ASSERT(Unk_179cfc0_Arg7, field_19, 0x19);

class Unk_179cfc0_Self;

// The arguments 0x710179cfc0 passes to its object's virtual function.
struct Unk_179cfc0_Args {
    f32 field_0;
    f32 field_4;
    u64 field_8;
    u64 field_10;
    u64 field_18;
    u64 field_20;
    Unk_179cfc0_Self* field_28;
    u8 _30[0x20];
    u64 field_50;
    u64 field_58;
    u64 field_60;
    u64 field_68;
    u64 field_70;
    u64 field_78;
    u64 field_80;
    u64 field_88;
    u32 field_90;
    s32 field_94;
    u8 _98[0x8];
    Unk_179d130_Self* field_a0;
    u8 field_a8;
    u64 field_b0;
    u64 field_b8;
    u8 _c0[0x8];
    u8 field_c8;
    bool field_c9;
    u8 field_ca;
    u32 field_cc;
};
PKMN_OFFSET_ASSERT(Unk_179cfc0_Args, field_28, 0x28);
PKMN_OFFSET_ASSERT(Unk_179cfc0_Args, field_50, 0x50);
PKMN_OFFSET_ASSERT(Unk_179cfc0_Args, field_90, 0x90);
PKMN_OFFSET_ASSERT(Unk_179cfc0_Args, field_a0, 0xa0);
PKMN_OFFSET_ASSERT(Unk_179cfc0_Args, field_b0, 0xb0);
PKMN_OFFSET_ASSERT(Unk_179cfc0_Args, field_c8, 0xc8);
PKMN_OFFSET_ASSERT(Unk_179cfc0_Args, field_cc, 0xcc);
PKMN_SIZE_ASSERT(Unk_179cfc0_Args, 0xd0);

class Unk_179cfc0_Self {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
    virtual bool vf14(void* arg1, void* arg2, const Unk_179cfc0_Arg6* arg6, void* arg3, Unk_179cfc0_Args* args,
                      void* parent);
};

// NON_MATCHING: instruction scheduling of the alloca size computation and the stores around it
// 0x710179cfc0
bool Unk_179cfc0(Unk_179cfc0_Self* self, void* arg1, void* arg2, void* arg3, u64 arg4, u64 arg5,
                 const Unk_179cfc0_Arg6* arg6, const Unk_179cfc0_Arg7* arg7, bool arg8) {
    Unk_179cfc0_Args args;
    args.field_0 = 1.0f;
    args.field_4 = 1.0f;
    args.field_8 = 0;
    args.field_10 = arg4;
    args.field_18 = arg5;
    args.field_20 = 0;
    args.field_28 = self;
    args.field_50 = 0;
    args.field_58 = 0;
    args.field_60 = 0;
    args.field_68 = 0;
    args.field_70 = 0;
    args.field_78 = 0;
    args.field_80 = 0;
    args.field_88 = 0;

    Unk_179d130_Self state;
    size_t size = 8 * static_cast<size_t>(Unk_24931dc) + 0x30 * static_cast<size_t>(Unk_24931d0) +
                  0x18 * static_cast<size_t>(Unk_24931d4) + 0x68 * static_cast<size_t>(Unk_24931d8) + 0x40;
    args.field_90 = 0;
    args.field_94 = -1;
    state.field_28 = __builtin_alloca(size);
    state.field_20 = nullptr;
    state.field_18 = 0;
    state.field_0 = 0;
    state.field_8 = 0;
    state.field_10 = nullptr;

    args.field_a0 = &state;
    args.field_a8 = arg7->field_19;
    args.field_c8 = arg7->field_0;
    args.field_c9 = arg8;
    args.field_ca = arg7->field_18;
    args.field_b0 = arg7->field_8;
    args.field_b8 = arg7->field_10;
    args.field_cc = arg6->field_8;

    bool result = self->vf14(arg1, arg2, arg6, arg3, &args, nullptr);
    if (state.field_20 != nullptr) {
        Unk_179d130(&state, arg2);
        if (state.field_20 != nullptr) {
            state.field_20->Clear();
            state.field_20 = nullptr;
        }
        state.field_10 = nullptr;
        state.field_0 = 0;
        state.field_28 = nullptr;
    }
    return result;
}
