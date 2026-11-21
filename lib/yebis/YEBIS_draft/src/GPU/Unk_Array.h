// YEBIS's allocation macros, as PPFX's code inlines them (placeholder names:
// nothing in the executable names them). Everything goes through the
// allocator in Unk_238d5f8 with the caller's __FILE__ and __LINE__.
//
// An array keeps its element count in the eight bytes before the first
// element, whatever the element type (chars too). Its delete runs the
// destructors from the last element down, with a pointer loop the compiler
// can't remove even when the destructor is empty. The allocator is read
// before the destructors run, and by the array new only after the count is
// known.
#pragma once

#include <new>

#include <miniz/miniz_yebis.h>
#include <types.h>

namespace PPFX {

template <class T>
inline T* Unk_NewArray(s64 count, const char* file, int line) {
    u64* block = static_cast<u64*>(Unk_4b99a0(Unk_238d5f8, count * sizeof(T) + sizeof(u64), file, line, nullptr));
    if (block == nullptr)
        return nullptr;
    *block++ = count;
    T* items = reinterpret_cast<T*>(block);
    for (s64 i = 0; i < count; i++)
        new (&items[i]) T;
    return items;
}

template <class T>
inline void Unk_DeleteArray(Unk_4b99a0_arg0* allocator, T* items) {
    u64* block = reinterpret_cast<u64*>(items) - 1;
    T* item = items + *block;
    while (--item >= items)
        item->~T();
    Unk_4b9a60(allocator, block);
}

// A single object: no count, and no null check before the constructor.
template <class T>
inline void Unk_Delete(Unk_4b99a0_arg0* allocator, T* object) {
    object->~T();
    Unk_4b9a60(allocator, object);
}

}  // namespace PPFX

#define UNK_NEW(T) new (Unk_4b99a0(Unk_238d5f8, sizeof(T), __FILE__, __LINE__, nullptr)) T
#define UNK_DELETE(object)                         \
    do {                                           \
        if ((object) != nullptr) {                 \
            PPFX::Unk_Delete(Unk_238d5f8, object); \
            (object) = nullptr;                    \
        }                                          \
    } while (0)
#define UNK_NEW_ARRAY(T, count) PPFX::Unk_NewArray<T>(count, __FILE__, __LINE__)
#define UNK_DELETE_ARRAY(items)                        \
    do {                                               \
        if ((items) != nullptr) {                      \
            PPFX::Unk_DeleteArray(Unk_238d5f8, items); \
            (items) = nullptr;                         \
        }                                              \
    } while (0)
