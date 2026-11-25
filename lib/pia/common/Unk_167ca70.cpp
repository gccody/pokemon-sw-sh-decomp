// Scope: common
// LdnNetworkFactory's overrides that forward to LocalNetworkFactory's
// function in the same vtable slot (Ldn slot N -> Local slot N). Placeholder
// member names vf<slot> (lib/pia/README.md).
// RTTI: N2nn3pia5local17LdnNetworkFactoryE, N2nn3pia5local19LocalNetworkFactoryE
// Then its vf72 and vf73, and the members of
// session::SessionInfoList<local::LdnSessionInfo> (RTTI
// N2nn3pia7session15SessionInfoListINS0_5local14LdnSessionInfoEEE) that vf72
// instantiates. The list's shape is the one of its NexSessionInfoPrivate
// instance (lib/pia/common/Unk_16d7bb0.cpp).
#include "pia/common/Unk_17162d0.h"

struct Unk_168e6c0_arg1;
struct Unk_168e740_arg1;
struct Unk_168e800_arg1;
struct Unk_245a928;
struct Unk_245aa88;
struct Unk_245f6a8;

// What vf73 creates: 0x7220 bytes, built by 0x710167d6d0 from Unk_27fb2a8.
class Unk_167d6d0 {
public:
    explicit Unk_167d6d0(void* arg);

    u8 _0[0x7220];
};

extern void* Unk_27fb2a8;

// 0x71017163e0, called on an array before it's freed (as in
// lib/pia/common/Unk_16d8140.h).
u64 Unk_17163e0(void* memory);

namespace nn {
namespace pia {
namespace local {

// Its constructor is at 0x7101685cb0. (It has a second vptr at 0x10: a
// secondary base this file doesn't need.)
class LdnSessionInfo {
public:
    LdnSessionInfo();
    virtual ~LdnSessionInfo();

    u8 _8[0xbe0 - 0x8];
};
PKMN_SIZE_ASSERT(LdnSessionInfo, 0xbe0);

}  // namespace local

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
    virtual void vf8();  // empties the list
    virtual T* vf9(int index);

    u16 m_Count;
    u16 m_Capacity;
    T** m_Array;
};

// 0x710167cc10
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

// 0x710167cd10 (and 0x710167cdb0, deleting)
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

// The constructor and destructors, emitted with the vtable.
template class SessionInfoList<local::LdnSessionInfo>;

}  // namespace session
}  // namespace pia
}  // namespace nn

namespace nn {
namespace pia {
namespace local {
class LocalNetworkFactory {
public:
    Unk_245a928* vf61();
    void vf69(Unk_168e6c0_arg1* object);
    Unk_245aa88* vf62();
    void vf70(Unk_168e740_arg1* object);
    u64 vf63();
    void vf71();
    Unk_245f6a8* vf74();
    void vf77(Unk_168e800_arg1* object);
};

class LdnNetworkFactory : public LocalNetworkFactory {
public:
    Unk_245a928* vf61();
    void vf69(Unk_168e6c0_arg1* object);
    Unk_245aa88* vf62();
    void vf70(Unk_168e740_arg1* object);
    u64 vf63();
    void vf71();
    session::SessionInfoList<LdnSessionInfo>* vf72(u16 capacity);
    Unk_167d6d0* vf73();
    Unk_245f6a8* vf74();
    void vf77(Unk_168e800_arg1* object);
};
}  // namespace local
}  // namespace pia
}  // namespace nn

// 0x710167ca70
Unk_245a928* nn::pia::local::LdnNetworkFactory::vf61() {
    return LocalNetworkFactory::vf61();
}

// 0x710167ca80
void nn::pia::local::LdnNetworkFactory::vf69(Unk_168e6c0_arg1* object) {
    LocalNetworkFactory::vf69(object);
}

// 0x710167ca90
Unk_245aa88* nn::pia::local::LdnNetworkFactory::vf62() {
    return LocalNetworkFactory::vf62();
}

// 0x710167caa0
void nn::pia::local::LdnNetworkFactory::vf70(Unk_168e740_arg1* object) {
    LocalNetworkFactory::vf70(object);
}

// 0x710167cab0
u64 nn::pia::local::LdnNetworkFactory::vf63() {
    return LocalNetworkFactory::vf63();
}

// 0x710167cac0
void nn::pia::local::LdnNetworkFactory::vf71() {
    LocalNetworkFactory::vf71();
}

// 0x710167cad0
nn::pia::session::SessionInfoList<nn::pia::local::LdnSessionInfo>*
nn::pia::local::LdnNetworkFactory::vf72(u16 capacity) {
    return new (Unk_1652bd0()) session::SessionInfoList<LdnSessionInfo>(capacity);
}

// 0x710167cb60
Unk_167d6d0* nn::pia::local::LdnNetworkFactory::vf73() {
    void* arg = Unk_27fb2a8;
    return new (Unk_1652bd0()) Unk_167d6d0(arg);
}

// 0x710167cbf0
Unk_245f6a8* nn::pia::local::LdnNetworkFactory::vf74() {
    return LocalNetworkFactory::vf74();
}

// 0x710167cc00
void nn::pia::local::LdnNetworkFactory::vf77(Unk_168e800_arg1* object) {
    LocalNetworkFactory::vf77(object);
}
