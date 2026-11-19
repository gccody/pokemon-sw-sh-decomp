#pragma once
#include <nn/nex/RootObject.h>

namespace nn {
namespace nex {

// N2nn3nex16RefCountedObjectE: the base of NEX's reference-counted objects.
// Its destructor's body is empty but still stores the class's vtable, which an
// empty body only does when a member isn't trivially destroyed in clang's
// sense: the anonymous union models that (the members aren't known).
class RefCountedObject : public RootObject {
public:
    virtual ~RefCountedObject();

    union {
        u8 _8[0x8];
    };
};
PKMN_SIZE_ASSERT(RefCountedObject, 0x10);

// N2nn3nex7qBufferE: a byte buffer, freed with NEX's allocator.
class qBuffer : public RefCountedObject {
public:
    virtual ~qBuffer();

    u8* m_data;
    u8 _18[0x20];
};
PKMN_SIZE_ASSERT(qBuffer, 0x38);

}  // namespace nex
}  // namespace nn
