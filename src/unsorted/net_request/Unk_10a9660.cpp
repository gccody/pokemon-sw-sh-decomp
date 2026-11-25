// Scope: common
// A request step base and its derived step's destructors, the base's vf4
// and vf11, and the factory of the object the step makes
// (src/unsorted/net_request/Unk_10a9050.h). Placeholder names: rename once
// the classes are known.
#include <new>
#include <utility>

#include "unsorted/Unk_2771620.h"
#include "unsorted/net_request/Unk_10a9050.h"

// src/gflib3/Unk_New.h's maker, with the allocation tested as a T* (as
// src/gflib3/Unk_239a418_Make.h's Unk_Create does): the object's
// constructor isn't inlined, and its call is split in two, one of them with
// a null pointer (LLVM's call site splitting needs the tested value to be the
// call's argument). Unk_New.h's tests a void*, which gives the same code when
// the constructor is inlined; once it tests a T* this copy can go.
struct Unk_New {
    template <class T, class... Args>
    T* Create(Unk_239a418_Allocator* allocator, Args&&... args) {
        Unk_2771620_Scope scope(allocator);
        T* p = static_cast<T*>(allocator->vf2(sizeof(T), alignof(T)));
        if (p == nullptr)
            allocator->vf23();
        T* object = ::new (p) T(std::forward<Args>(args)...);
        object->field_8 = allocator;
        object->field_10 = reinterpret_cast<u64>(object);
        object->field_18 = sizeof(T);
        object->field_20 = alignof(T);
        return object;
    }
};

// 0x71010a96b0 (D2), 0x71010a9720 (D0)
Unk_2411420::~Unk_2411420() = default;

// 0x71010a9790
void Unk_2411490::vf4() {
    if (field_18.m_ptr != nullptr) {
        static_cast<Unk_239a458*>(field_18.m_ptr)->vf5();
        field_18.m_ptr = nullptr;
    }
    field_18.m_ptr = nullptr;
    field_20 = nullptr;
}

// 0x71010a9810 (D2), 0x71010a9860 (D0, a trap: the class is abstract)
Unk_2411490::~Unk_2411490() = default;

// 0x71010a98a0
template Unk_2411318* Unk_New::Create<Unk_2411318>(Unk_239a418_Allocator*);
