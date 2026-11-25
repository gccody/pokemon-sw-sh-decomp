#pragma once
// NEX 4.6.8's base classes, reconstructed from the executable: the names are
// the classes' RTTI names (N2nn3nex10RootObjectE ...), the layouts come from
// the code. Functions without evidence for a name keep their placeholders.
#include <types.h>

// The NEX allocator: a 16-byte header before each block holds the function
// that frees it (MemoryManager-style: a custom allocator or malloc/free).
void* Unk_15b6dc0(size_t size);
void Unk_15b6e10(void* p);

namespace nn {
namespace nex {

// N2nn3nex10RootObjectE: the base of NEX's objects. Its D0s free through
// 0x71015b6e10, and `new` of a NEX class allocates through 0x71015b6dc0,
// which doesn't throw: the code checks what it returns for null.
class RootObject {
public:
    static void* operator new(size_t size) noexcept { return Unk_15b6dc0(size); }
    static void operator delete(void* p) { Unk_15b6e10(p); }
    virtual ~RootObject() {}
};
PKMN_SIZE_ASSERT(RootObject, 0x8);

}  // namespace nex
}  // namespace nn
