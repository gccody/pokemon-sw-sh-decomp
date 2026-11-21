// Scope: common
// SiSDK3::SiCoreCriticalSection (RTTI): an nn::os mutex, counted, and the
// scoped lock on one. The file's name isn't in the executable.
#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/SiCore_CriticalSection.h>

// 0x710276ba10: how many critical sections there are
s32 Unk_276ba10;

namespace SiSDK3 {

// 0x71004c86a0
SiCoreCriticalSection::SiCoreCriticalSection() {
    nn::os::InitializeMutex(&field_8, true, 0);
    Unk_276ba10++;
}

// 0x71004c86e0, 0x71004c8710
SiCoreCriticalSection::~SiCoreCriticalSection() {
    Unk_276ba10--;
    nn::os::FinalizeMutex(&field_8);
}

// 0x71004c8760
bool SiCoreCriticalSection::vf2() {
    nn::os::LockMutex(&field_8);
    return true;
}

// 0x71004c8780
bool SiCoreCriticalSection::vf3() {
    nn::os::UnlockMutex(&field_8);
    return true;
}

// 0x71004c87a0
bool SiCoreCriticalSection::vf4() {
    return nn::os::TryLockMutex(&field_8);
}

}  // namespace SiSDK3

// 0x71004c87b0
Unk_4c87b0::Unk_4c87b0(SiSDK3::ISiCriticalSection* pCriticalSection, bool lock) {
    field_0 = pCriticalSection;
    field_8 = false;
    if (lock) {
        pCriticalSection->vf2();
        field_8 = true;
    }
}
