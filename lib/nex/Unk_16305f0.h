#pragma once
// What lib/nex/Unk_16305f0.cpp needs of NEX's protocol call context (RTTI:
// N2nn3nex19ProtocolCallContextE): the members its functions read, at the
// offsets the code uses.
#include <nn/nex/Call.h>
#include <nn/nex/qVector.h>

namespace nn {
namespace nex {

// N2nn3nex19ProtocolCallContextE
class ProtocolCallContext {
public:
    u8 _0[0x18];
    u32 m_callId;  // what the call's message carries (0x7101630a20)
    u8 _1c[0x74];
    qVector<void*> m_results;  // where the response's results are copied
};
PKMN_OFFSET_ASSERT(ProtocolCallContext, m_callId, 0x18);
PKMN_OFFSET_ASSERT(ProtocolCallContext, m_results, 0x90);

}  // namespace nex
}  // namespace nn
