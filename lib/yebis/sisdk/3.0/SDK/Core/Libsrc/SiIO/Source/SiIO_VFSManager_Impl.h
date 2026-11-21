// SiSDK3::SiIOVFSManager (RTTI names the class): the list of the mounted
// archives. Placeholder members. The reference counts are defined in this
// header (their __FILE__), at the original's lines, for the class's own
// translation unit (UNK_SIIO_VFSMANAGER_IMPL).
#pragma once

#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/SiCore_LinkedList.h>
#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/Unk_4bf660.h>
#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/Unk_RefCount.h>

namespace SiSDK3 {

class SiIOVFS;
class SiIOVFSEntry;

class SiIOVFSManager {
public:
    explicit SiIOVFSManager(ISiAllocator* pAllocator);
    virtual ~SiIOVFSManager();
    UNK_REFCOUNT_DECLARE;
    virtual u32 vf4();

    // 0x7100583980: mounts an archive
    SiIOVFS* Unk_583980(ISiAllocator* pAllocator);
    // 0x7100583a80: takes an archive off the list
    void Unk_583a80(SiIOVFS* pVFS);

    Unk_4bf660 field_8;
    SiLinkedList<SiIOVFS*> field_18;
};
PKMN_SIZE_ASSERT(SiIOVFSManager, 0x38);

}  // namespace SiSDK3

// 0x7100583b70, 0x7100583be0: the first mounted archive's file or directory
// of a path, or null (free functions here: the streams call them through
// the manager SiIO's kernel returns as a number)
SiSDK3::SiIOVFSEntry* Unk_583b70(void* manager, const char* path);
SiSDK3::SiIOVFSEntry* Unk_583be0(void* manager, const char* path);

#ifdef UNK_SIIO_VFSMANAGER_IMPL
// 0x7100583c50 (vf2), 0x7100583c70 (vf3)
#line 33
UNK_REFCOUNT_DEFINE(SiSDK3::SiIOVFSManager, field_8.m_pAllocator, field_8.m_count)
#endif
