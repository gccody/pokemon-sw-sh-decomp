// Scope: common
// What a SiGfx GPU resource whose deletion is deferred keeps
// (SiCore/Unk_538d70.h): its constructor. The file's name isn't in the
// executable; the TU's other functions are the empty destructor 0x7100538dc0
// (lib/yebis/leaf) and its static initialiser 0x7100538dd0 (lib/yebis/static).
#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/Unk_538d70.h>

// 0x7100538d70
Unk_538d70::Unk_538d70(SiSDK3::ISiAllocator* pAllocator)
    : m_pAllocator(pAllocator), m_count(1), field_c(0), field_d(), field_f(0) {
    if (m_pAllocator == nullptr) {
        m_pAllocator = Unk_4bc640();
    }
}
