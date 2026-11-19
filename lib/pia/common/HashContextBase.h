#pragma once
// RTTI: N2nn3pia6common15HashContextBaseE (the base of Md5Context and
// ShaBlock512BitContext). Abstract: it has no vtable of its own in main.
#include <types.h>

namespace nn {
namespace pia {
namespace common {

class HashContextBase {
public:
    virtual void vf0() = 0;                          // initialises the state
    virtual void vf1(const void* data, u32 size) = 0;  // hashes data
    virtual u32 vf2() = 0;                           // the digest's size
    virtual u32 vf3() = 0;                           // the block's size
    virtual void vf4(void* digest) = 0;              // pads and writes the digest
    virtual void vf5() = 0;                          // hashes the buffered block
};

}  // namespace common
}  // namespace pia
}  // namespace nn
