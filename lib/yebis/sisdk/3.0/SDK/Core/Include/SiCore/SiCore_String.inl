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

template <class T>
inline void SiString<T>::Unk_FreeBuffer() {
    if (!(field_28 & 1) && m_pBuffer != nullptr) {
        if (m_pAllocator != nullptr) {
#line 344
            SI_FREE(m_pAllocator, m_pBuffer);
        }
        m_pBuffer = nullptr;
    }
}

template <class T>
inline void SiString<T>::Unk_Empty() {
    Unk_FreeBuffer();
    m_pBuffer = nullptr;
    field_10 = 0;
}

template <class T>
inline void SiString<T>::Unk_EmptyAll() {
    Unk_Empty();
    field_20 = 0;
    field_28 = 0;
}

// Sets the capacity, keeping the contents if keep: 0x71004c5d50 (char) and
// 0x71004c5eb0 (wchar_t), free functions under the names Unk_StringFuncs.h
// declares. This is the body they share, a function of each file that uses it.
template <class T>
static bool Unk_StringSetCapacityImpl(SiString<T>* self, size_t capacity, bool keep) {
    if (capacity == 0) {
        self->Unk_EmptyAll();
        return true;
    }
    T* pBuffer = nullptr;
    if (self->m_pAllocator != nullptr) {
#line 301
        pBuffer = static_cast<T*>(self->m_pAllocator->vf8(sizeof(T), capacity, 0xffffffff, __FILE__, __LINE__));
    }
    if (pBuffer == nullptr) {
        self->Unk_EmptyAll();
        return false;
    }
    if (keep) {
        size_t length = self->field_10 < capacity - 1 ? self->field_10 : capacity - 1;
        if (length != 0) {
            memcpy(pBuffer, self->m_pBuffer, length * sizeof(T));
        }
        pBuffer[length] = 0;
    }
    if (!(self->field_28 & 1) && self->m_pBuffer != nullptr) {
        if (self->m_pAllocator != nullptr) {
#line 319
            SI_FREE(self->m_pAllocator, self->m_pBuffer);
        }
        self->m_pBuffer = nullptr;
    }
    self->m_pBuffer = pBuffer;
    self->field_20 = capacity;
    self->field_28 = 0;
    return true;
}

}  // namespace SiSDK3
