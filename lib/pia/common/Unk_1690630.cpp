// Scope: common
// local::LocalMatchUpdateSessionSettingJob's constructor (RTTI
// N2nn3pia5local33LocalMatchUpdateSessionSettingJobE). It keeps the
// placeholder name it already has, Unk_245aa88 (after the vtable), which
// lib/pia/gen/nn_pia_local_LocalNetworkFactory.cpp calls it by, so the class
// is declared here under that name (the members are in Unk_1690160.cpp, as
// lib/pia/common/Unk_168f910.h declares the class).
#include "pia/common/Unk_168f910.h"

class Unk_245aa88 : public Unk_2460028 {
public:
    Unk_245aa88();
    ~Unk_245aa88() override;

    nn::pia::Unk_165e060 m_Result;
};
PKMN_OFFSET_ASSERT(Unk_245aa88, m_Result, 0xa4);
PKMN_SIZE_ASSERT(Unk_245aa88, 0xb8);

// 0x7101690630
Unk_245aa88::Unk_245aa88() : m_Result(0) {}
