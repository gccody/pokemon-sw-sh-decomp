#pragma once
#include <nn/nex/RootObject.h>
#include <vector>

void* Unk_15b9340(size_t size);
void Unk_15b9390(u64 p);

namespace nn {
namespace nex {

// nn::nex::MemAllocator<T> (RTTI: std::__1::list<nn::nex::URLProbe,
// nn::nex::MemAllocator<nn::nex::URLProbe>>): NEX's allocator for libc++'s
// containers, through 0x71015b9340 and 0x71015b9390.
template <class T>
class MemAllocator {
public:
    typedef T value_type;
    MemAllocator() {}
    template <class U>
    MemAllocator(const MemAllocator<U>&) {}
    T* allocate(size_t n) { return static_cast<T*>(Unk_15b9340(n * sizeof(T))); }
    void deallocate(T* p, size_t) { Unk_15b9390(reinterpret_cast<u64>(p)); }
    template <class U>
    bool operator==(const MemAllocator<U>&) const {
        return true;
    }
    template <class U>
    bool operator!=(const MemAllocator<U>&) const {
        return false;
    }
};

// nn::nex::qVector<T> (RTTI: SharedPtr<qVector<SocketDriver::PollInfo>> ...): a
// std::vector with NEX's allocator.
template <class T>
class qVector : public std::vector<T, MemAllocator<T>> {};

}  // namespace nex
}  // namespace nn

#include <nn/nex/ByteStream.h>

// Writes a container: its u32 count, then each element with `write` (an inline
// helper; the name isn't the executable's).
template <class T, class F>
inline bool WriteContainer(nn::nex::ByteStream* s, const T& v, F write) {
    u32 count = static_cast<u32>(v.size());
    s->Write(count);
    for (const auto& e : v) {
        write(s, e);
    }
    return true;
}

// A container of scalars.
template <class T>
inline bool WriteContainer(nn::nex::ByteStream* s, const T& v) {
    u32 count = static_cast<u32>(v.size());
    s->Write(count);
    for (const auto& e : v) {
        s->Write(e);
    }
    return true;
}
