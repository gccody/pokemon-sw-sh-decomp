// Scope: common
// SiSDK3::SiIOVFSManager.
#define UNK_SIIO_VFSMANAGER_IMPL
#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiIO/Source/SiIO_VFSManager_Impl.h>

#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiIO/Source/SiIO_VFS_Impl.h>

// 0x7100584410 (leafgen's name and type): the archive's initialisation, which
// only succeeds
bool Unk_584410_get(u64 vfs);

namespace SiSDK3 {

// 0x7100583760
SiIOVFSManager::SiIOVFSManager(ISiAllocator* pAllocator) : field_8(pAllocator), field_18(pAllocator) {}

// 0x71005837c0 (D2), 0x7100583890 (D0)
SiIOVFSManager::~SiIOVFSManager() {}

// 0x7100583980
// NON_MATCHING: the same instructions, but two pairs of independent stores are scheduled the other
// way round (the new node's links' zeros before its list and previous node, and `add x8, x19, #0x28`
// before the head's store).
SiIOVFS* SiIOVFSManager::Unk_583980(ISiAllocator* pAllocator) {
#line 56
    SiIOVFS* pVFS = UNK_SI_NEW(pAllocator, 0x10) SiIOVFS(pAllocator);
    if (pVFS == nullptr) {
        return nullptr;
    }
    if (!Unk_584410_get(reinterpret_cast<u64>(pVFS))) {
        pVFS->vf3();
        return nullptr;
    }
    field_18.AddTail(pVFS);
    return pVFS;
}

// 0x7100583a80
void SiIOVFSManager::Unk_583a80(SiIOVFS* pVFS) {
    SiLinkedList<SiIOVFS*>::Node* node = field_18.m_pHead;
    while (node != nullptr) {
        if (node->m_value == pVFS) {
            node = field_18.Remove(node);
        } else {
            node = node->m_pNext;
        }
    }
}

}  // namespace SiSDK3

// 0x7100583b70
SiSDK3::SiIOVFSEntry* Unk_583b70(void* manager, const char* path) {
    SiSDK3::SiIOVFSManager* self = static_cast<SiSDK3::SiIOVFSManager*>(manager);
    for (SiSDK3::SiLinkedList<SiSDK3::SiIOVFS*>::Node* node = self->field_18.m_pHead; node != nullptr; node = node->m_pNext) {
        SiSDK3::SiIOVFS* pVFS = node->m_value;
        if (pVFS != nullptr && pVFS->vf10()) {
            SiSDK3::SiIOVFSEntry* entry = pVFS->vf13(path);
            if (entry != nullptr) {
                return entry;
            }
        }
    }
    return nullptr;
}

// 0x7100583be0
SiSDK3::SiIOVFSEntry* Unk_583be0(void* manager, const char* path) {
    SiSDK3::SiIOVFSManager* self = static_cast<SiSDK3::SiIOVFSManager*>(manager);
    for (SiSDK3::SiLinkedList<SiSDK3::SiIOVFS*>::Node* node = self->field_18.m_pHead; node != nullptr; node = node->m_pNext) {
        SiSDK3::SiIOVFS* pVFS = node->m_value;
        if (pVFS != nullptr && pVFS->vf10()) {
            SiSDK3::SiIOVFSEntry* entry = pVFS->vf14(path);
            if (entry != nullptr) {
                return entry;
            }
        }
    }
    return nullptr;
}
