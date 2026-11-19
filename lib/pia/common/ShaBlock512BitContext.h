#pragma once
// RTTI: N2nn3pia6common21ShaBlock512BitContextE: the buffering and padding of
// the SHA family with 64-byte blocks (Sha256Context's base). Abstract.
#include "pia/common/HashContextBase.h"

namespace nn {
namespace pia {
namespace common {

class ShaBlock512BitContext : public HashContextBase {
public:
    void Unk_1661360();                           // pads the message: 0x80, zeros, the bit length
    void Unk_16613e0(const void* data, u32 size);  // buffers data, hashing each full block

    u8 m_Buffer[64];
    u32 m_BufferUsed;
    u32 m_BlockCountLow;
    u32 m_BlockCountHigh;
};
PKMN_OFFSET_ASSERT(ShaBlock512BitContext, m_Buffer, 0x8);
PKMN_OFFSET_ASSERT(ShaBlock512BitContext, m_BufferUsed, 0x48);
PKMN_OFFSET_ASSERT(ShaBlock512BitContext, m_BlockCountHigh, 0x50);

}  // namespace common
}  // namespace pia
}  // namespace nn
