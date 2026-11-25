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
