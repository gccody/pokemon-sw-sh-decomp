// Scope: common
// The allocator and reference count every SiSDK3 object keeps (Unk_4bf660.h):
// its constructor. The file's name isn't in the executable; the TU's other
// functions are the empty destructor 0x71004bf6a0 (lib/yebis/leaf) and its
// static initialiser 0x71004bf6b0 (lib/yebis/static).
#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/Unk_4bf660.h>

// 0x71004bf660
Unk_4bf660::Unk_4bf660(SiSDK3::ISiAllocator* pAllocator) : m_pAllocator(pAllocator), m_count(1), field_c(0) {
    if (m_pAllocator == nullptr) {
        m_pAllocator = Unk_4bc640();
    }
}
