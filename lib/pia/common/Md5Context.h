#pragma once
// RTTI: N2nn3pia6common10Md5ContextE
#include "pia/common/HashContextBase.h"

namespace nn {
namespace pia {
namespace common {

class Md5Context : public HashContextBase {
public:
    void vf0() override;
    void vf1(const void* data, u32 size) override;
    u32 vf2() override;
    u32 vf3() override;
    void vf4(void* digest) override;
    void vf5() override;

    u32 m_State[4];
    u32 m_Count;  // bytes hashed
    u8 m_Buffer[64];
};
PKMN_OFFSET_ASSERT(Md5Context, m_State, 0x8);
PKMN_OFFSET_ASSERT(Md5Context, m_Count, 0x18);
PKMN_OFFSET_ASSERT(Md5Context, m_Buffer, 0x1c);
PKMN_SIZE_ASSERT(Md5Context, 0x60);

}  // namespace common
}  // namespace pia
}  // namespace nn
