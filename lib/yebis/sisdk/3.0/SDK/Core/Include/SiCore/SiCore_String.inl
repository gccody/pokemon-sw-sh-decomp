// SiSDK3::SiString's implementation (included by SiCore_String.h). The
// original's __LINE__s are kept with #line.

namespace SiSDK3 {

template <class T>
inline void SiString<T>::Unk_Release() {
    if (!(field_28 & 1)) {
        if (m_pBuffer != nullptr) {
            if (m_pAllocator != nullptr) {
#line 225
                SI_FREE(m_pAllocator, m_pBuffer);
            }
            m_pBuffer = nullptr;
        }
        m_pBuffer = nullptr;
    }
}

template <class T>
inline void SiString<T>::Unk_Clear() {
    if (!(field_28 & 1) && m_pBuffer != nullptr) {
        if (m_pAllocator != nullptr) {
#line 344
            SI_FREE(m_pAllocator, m_pBuffer);
        }
        m_pBuffer = nullptr;
    }
    m_pBuffer = nullptr;
    field_10 = 0;
    field_20 = 0;
    field_28 = 0;
}

}  // namespace SiSDK3
