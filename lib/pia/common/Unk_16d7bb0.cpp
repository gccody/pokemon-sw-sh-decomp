// Scope: common
// The end of NexNetworkFactory's file: its vf82, and the members of
// session::SessionInfoList<nex::NexSessionInfoPrivate> (RTTI
// N2nn3pia7session15SessionInfoListINS0_3nex21NexSessionInfoPrivateEEE) and
// the deleting destructor of nex::NexSessionInfoPrivate (RTTI
// N2nn3pia3nex21NexSessionInfoPrivateE, derived from nex::NexSessionInfo) that
// it instantiates. Member names are placeholders (vf<slot>, lib/pia/README.md).
#include "pia/common/Unk_16d8140.h"


namespace nn {
namespace pia {
namespace nex {

// RTTI N2nn3pia3nex14NexSessionInfoE; its constructor is at 0x7101713980,
// its (empty) destructor at 0x7101713a20. Its virtual functions are in
// lib/nx_middleware/class/nn_pia_nex_NexSessionInfoPrivate.cpp.
class NexSessionInfo {
public:
    NexSessionInfo();
    virtual ~NexSessionInfo();

    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();  // 0x7101713a40: its list's vf8 calls it on every entry
    virtual void vf11();
    virtual void vf12();

    u8 _8[0x270 - 0x8];
};

// Overrides nothing but the destructors: its vtable (and its deleting
// destructor) is emitted where it's constructed.
class NexSessionInfoPrivate : public NexSessionInfo {};
PKMN_SIZE_ASSERT(NexSessionInfoPrivate, 0x270);

class NexNetworkFactory {
public:
    NexCommunityInfoList* vf82(u8 capacity);
};

// 0x71016d7bf0
NexCommunityInfoList* NexNetworkFactory::vf82(u8 capacity) {
    return new (Unk_1652bd0()) NexCommunityInfoList(capacity);
}

}  // namespace nex

namespace session {

// An array of `capacity` T pointers, each T allocated by the constructor.
template <class T>
class SessionInfoList {
public:
    explicit SessionInfoList(u16 capacity);
    virtual ~SessionInfoList();

    virtual u64 vf2();   // m_Array
    virtual u64 vf3();   // m_Array
    virtual T** vf4();   // the end of the m_Count entries
    virtual T** vf5();   // the end of the m_Count entries
    virtual u16 vf6();   // m_Count
    virtual u16 vf7();   // m_Capacity
    virtual void vf8();  // empties the list, calls each entry's vf10
    virtual T* vf9(int index);

    u16 m_Count;
    u16 m_Capacity;
    T** m_Array;
};

// 0x71016d7c80
template <class T>
SessionInfoList<T>::SessionInfoList(u16 capacity) : m_Count(0), m_Capacity(capacity) {
    pead::Heap* heap = Unk_1652bd0();
    T** array = static_cast<T**>(operator new(sizeof(T*) * capacity, heap));
    if (array != nullptr) {
        for (size_t i = 0; i < capacity; i++) {
            array[i] = nullptr;
        }
    }
    m_Array = array;
    for (u32 i = 0; i < m_Capacity; i++) {
        m_Array[i] = new (Unk_1652bd0()) T();
    }
}

// 0x71016d7db0 (and 0x71016d7e50, deleting)
template <class T>
SessionInfoList<T>::~SessionInfoList() {
    for (u32 i = 0; i < m_Capacity; i++) {
        T* info = m_Array[i];
        if (info != nullptr) {
            info->~T();
            Unk_1716390(info);
        }
    }
    T** array = m_Array;
    if (array != nullptr) {
        Unk_17163e0(array);
        Unk_1716390(array);
    }
}

// 0x71016d7f00
template <class T>
T** SessionInfoList<T>::vf4() {
    return m_Array + m_Count;
}

// 0x71016d7f10
template <class T>
T** SessionInfoList<T>::vf5() {
    return m_Array + m_Count;
}

// 0x71016d7f40
template <class T>
void SessionInfoList<T>::vf8() {
    m_Count = 0;
    if (m_Array != nullptr) {
        for (u32 i = 0; i < m_Capacity; i++) {
            m_Array[i]->vf10();
        }
    }
}

// 0x71016d7fc0
template <class T>
T* SessionInfoList<T>::vf9(int index) {
    if (index < 0 || index >= m_Count) {
        return nullptr;
    }
    return m_Array[index];
}

// The members above, and NexSessionInfoPrivate's deleting destructor
// (0x71016d7ff0), emitted with its vtable.
template class SessionInfoList<nex::NexSessionInfoPrivate>;

}  // namespace session
}  // namespace pia
}  // namespace nn
