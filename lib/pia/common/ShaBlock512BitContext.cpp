// Scope: common
#include "pia/common/ShaBlock512BitContext.h"

#include <string.h>

namespace nn {
namespace pia {
namespace common {

namespace {
const u8 s_Padding[64] = {0x80};
}

// 0x7101661360
void ShaBlock512BitContext::Unk_1661360() {
    u32 length[2];
    length[1] = __builtin_bswap32((m_BlockCountLow << 9) + (m_BufferUsed << 3));
    length[0] = __builtin_bswap32((m_BlockCountHigh << 9) | (m_BlockCountLow >> 23));
    u32 padding = (m_BufferUsed < 56 ? 56 : 120) - m_BufferUsed;
    vf1(s_Padding, padding);
    vf1(length, sizeof(length));
}

// 0x71016613e0
void ShaBlock512BitContext::Unk_16613e0(const void* data, u32 size) {
    const u8* p = static_cast<const u8*>(data);
    while (size > 0) {
        u32 n = 64 - m_BufferUsed;
        if (n > size) {
            n = size;
        }
        memcpy(&m_Buffer[m_BufferUsed], p, n);
        m_BufferUsed += n;
        p += n;
        size -= n;
        if (m_BufferUsed >= 64) {
            vf5();
            m_BufferUsed = 0;
            if (++m_BlockCountLow == 0) {
                m_BlockCountHigh++;
            }
        }
    }
}

}  // namespace common
}  // namespace pia
}  // namespace nn
