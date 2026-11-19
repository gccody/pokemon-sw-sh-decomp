#pragma once
#include <nn/nex/RootObject.h>

namespace nn {
namespace nex {

// N2nn3nex6StringE: a string with a 16-byte inline buffer. Its vtable (and
// its inline destructors) are the copies of gflnet3, which comes first in
// link order (no RTTI there).
class String : public RootObject {
public:
    String() : m_ptr(m_buf), m_capacity(sizeof(m_buf)) { m_buf[0] = '\0'; }
    virtual ~String() { Unk_15bc310(); }

    // 0x71015bc310: frees a heap buffer (one that isn't m_buf).
    void Unk_15bc310();

    char m_buf[16];
    char* m_ptr;
    size_t m_capacity;
};
PKMN_SIZE_ASSERT(String, 0x28);
PKMN_OFFSET_ASSERT(String, m_ptr, 0x18);

}  // namespace nex
}  // namespace nn
