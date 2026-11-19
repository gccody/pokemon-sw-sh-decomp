// Scope: common
// rehash and __rehash of unordered_maps keyed by u64 (or u32) on an allocator like
// Unk_2771620_Allocator that passes a fixed alignment (16 or 4) for every block it
// allocates and frees, the node arrays' included: the only difference from
// src/unsorted/Unk_597350.cpp's instances. Placeholder allocator and mapped types
// (named after each map's __rehash): their code doesn't read the mapped type.
#include <types.h>
#include <unordered_map>

#include "unsorted/Unk_2771620.h"

template <class T, size_t A>
class Unk_2771620_AlignedAllocator : public Unk_2771620_Allocator<T> {
public:
    using value_type = T;
    template <class U>
    struct rebind {
        using other = Unk_2771620_AlignedAllocator<U, A>;
    };

    template <class U>
    Unk_2771620_AlignedAllocator(const Unk_2771620_AlignedAllocator<U, A>& other)
        : Unk_2771620_Allocator<T>(other) {}

    T* allocate(size_t n) {
        void* p = this->field_0->vf2(n * sizeof(T), A);
        if (p == nullptr)
            this->field_0->vf23();
        return static_cast<T*>(p);
    }
    void deallocate(T* p, size_t n) {
        this->field_0->vf3(reinterpret_cast<u64>(p), n * sizeof(T), A);
    }
};

template <class T, size_t A, class U, size_t B>
bool operator==(const Unk_2771620_AlignedAllocator<T, A>& a,
                const Unk_2771620_AlignedAllocator<U, B>& b) {
    return a.field_0 == b.field_0;
}

template <class K, class T, size_t A>
using Unk_2771620_AlignedMap =
    std::unordered_map<K,
                       T,
                       std::hash<K>,
                       std::equal_to<K>,
                       Unk_2771620_AlignedAllocator<std::pair<const K, T>, A>>;

// The mapped type of the map whose __rehash is 0x7100678520.
struct Unk_678520 {};  // its layout isn't known (nothing here reads it)

// 0x7100678410
template void Unk_2771620_AlignedMap<u32, Unk_678520, 4>::__table::rehash(size_t);
// 0x7100678520
template void Unk_2771620_AlignedMap<u32, Unk_678520, 4>::__table::__rehash(size_t);

// The mapped type of the map whose __rehash is 0x71009694d0.
struct Unk_9694d0 {};  // its layout isn't known (nothing here reads it)

// 0x71009693c0
template void Unk_2771620_AlignedMap<u32, Unk_9694d0, 4>::__table::rehash(size_t);
// 0x71009694d0
template void Unk_2771620_AlignedMap<u32, Unk_9694d0, 4>::__table::__rehash(size_t);

// The mapped type of the map whose __rehash is 0x7100bc80f0.
struct Unk_bc80f0 {};  // its layout isn't known (nothing here reads it)

// 0x7100bc7fe0
template void Unk_2771620_AlignedMap<u32, Unk_bc80f0, 4>::__table::rehash(size_t);
// 0x7100bc80f0
template void Unk_2771620_AlignedMap<u32, Unk_bc80f0, 4>::__table::__rehash(size_t);

// The mapped type of the map whose __rehash is 0x7100bd59a0.
struct Unk_bd59a0 {};  // its layout isn't known (nothing here reads it)

// 0x7100bd5890
template void Unk_2771620_AlignedMap<u32, Unk_bd59a0, 4>::__table::rehash(size_t);
// 0x7100bd59a0
template void Unk_2771620_AlignedMap<u32, Unk_bd59a0, 4>::__table::__rehash(size_t);

// The mapped type of the map whose __rehash is 0x7100c50eb0.
struct Unk_c50eb0 {};  // its layout isn't known (nothing here reads it)

// 0x7100c50c10
template void Unk_2771620_AlignedMap<u64, Unk_c50eb0, 16>::__table::rehash(size_t);
// 0x7100c50eb0
template void Unk_2771620_AlignedMap<u64, Unk_c50eb0, 16>::__table::__rehash(size_t);

// The mapped type of the map whose __rehash is 0x7100c80a70.
struct Unk_c80a70 {};  // its layout isn't known (nothing here reads it)

// 0x7100c80960
template void Unk_2771620_AlignedMap<u64, Unk_c80a70, 16>::__table::rehash(size_t);
// 0x7100c80a70
template void Unk_2771620_AlignedMap<u64, Unk_c80a70, 16>::__table::__rehash(size_t);

// The mapped type of the map whose __rehash is 0x7100e9bfd0.
struct Unk_e9bfd0 {};  // its layout isn't known (nothing here reads it)

// 0x7100e9bd20
template void Unk_2771620_AlignedMap<u64, Unk_e9bfd0, 16>::__table::rehash(size_t);
// 0x7100e9bfd0
template void Unk_2771620_AlignedMap<u64, Unk_e9bfd0, 16>::__table::__rehash(size_t);

// The mapped type of the map whose __rehash is 0x7100e9c7a0.
struct Unk_e9c7a0 {};  // its layout isn't known (nothing here reads it)

// 0x7100e9c4e0
template void Unk_2771620_AlignedMap<u64, Unk_e9c7a0, 16>::__table::rehash(size_t);
// 0x7100e9c7a0
template void Unk_2771620_AlignedMap<u64, Unk_e9c7a0, 16>::__table::__rehash(size_t);

// The mapped type of the map whose __rehash is 0x7100edff30.
struct Unk_edff30 {};  // its layout isn't known (nothing here reads it)

// 0x7100edfe20
template void Unk_2771620_AlignedMap<u64, Unk_edff30, 16>::__table::rehash(size_t);
// 0x7100edff30
template void Unk_2771620_AlignedMap<u64, Unk_edff30, 16>::__table::__rehash(size_t);

// The mapped type of the map whose __rehash is 0x7100ee0410.
struct Unk_ee0410 {};  // its layout isn't known (nothing here reads it)

// 0x7100ee01f0
template void Unk_2771620_AlignedMap<u64, Unk_ee0410, 16>::__table::rehash(size_t);
// 0x7100ee0410
template void Unk_2771620_AlignedMap<u64, Unk_ee0410, 16>::__table::__rehash(size_t);

// The mapped type of the map whose __rehash is 0x7100ee0ab0.
struct Unk_ee0ab0 {};  // its layout isn't known (nothing here reads it)

// 0x7100ee0890
template void Unk_2771620_AlignedMap<u64, Unk_ee0ab0, 16>::__table::rehash(size_t);
// 0x7100ee0ab0
template void Unk_2771620_AlignedMap<u64, Unk_ee0ab0, 16>::__table::__rehash(size_t);

// The mapped type of the map whose __rehash is 0x7100ee0f90.
struct Unk_ee0f90 {};  // its layout isn't known (nothing here reads it)

// 0x7100ee0d70
template void Unk_2771620_AlignedMap<u64, Unk_ee0f90, 16>::__table::rehash(size_t);
// 0x7100ee0f90
template void Unk_2771620_AlignedMap<u64, Unk_ee0f90, 16>::__table::__rehash(size_t);
