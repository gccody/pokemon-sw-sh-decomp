#pragma once
// RTTI: N2nn3pia6common13Sha256ContextE
#include "pia/common/ShaBlock512BitContext.h"

namespace nn {
namespace pia {
namespace common {

class Sha256Context : public ShaBlock512BitContext {
public:
    void vf0() override;
    void vf1(const void* data, u32 size) override;
    u32 vf2() override;
    u32 vf3() override;
    void vf4(void* digest) override;
    void vf5() override;

    u32 m_State[8];
};
PKMN_OFFSET_ASSERT(Sha256Context, m_State, 0x54);
PKMN_SIZE_ASSERT(Sha256Context, 0x78);

}  // namespace common
}  // namespace pia
}  // namespace nn
