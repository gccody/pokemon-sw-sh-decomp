// Scope: common
// SiOS's synchronisation objects: SiSDK3::SiOSCriticalSection, SiOSMutex and
// the scope's lock.
#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiOS/Source/Unk_596410.h>

#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/SiCore_Memory.h>

#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/SiCore_Reflection.h>

// 0x7102771418
static SiSDK3::SiReflectionPropertyHandle Unk_2771418;

// 0x7102771490: the counts, in an object the TU's static initialiser
// (0x71005966e0, _GLOBAL__sub_I_Unk_596410.cpp) clears
SiSDK3::Unk_2771490_t Unk_2771490;

namespace SiSDK3 {

// 0x7100596410
SiOSCriticalSection::SiOSCriticalSection(u32 value) : field_28(value), field_2c(0) {
    nn::os::InitializeMutex(&field_8, true, 0);
    Unk_2771490.field_0++;
}

// 0x7100596460 (D2), 0x7100596490 (D0)
SiOSCriticalSection::~SiOSCriticalSection() {
    Unk_2771490.field_0--;
    nn::os::FinalizeMutex(&field_8);
}

// 0x71005964e0
bool SiOSCriticalSection::vf2() {
    nn::os::LockMutex(&field_8);
    return true;
}

// 0x7100596500
bool SiOSCriticalSection::vf3() {
    nn::os::UnlockMutex(&field_8);
    return true;
}

// 0x7100596520
bool SiOSCriticalSection::vf4() {
    return nn::os::TryLockMutex(&field_8);
}

// 0x7100596530
SiOSMutex::SiOSMutex() {
    nn::os::InitializeMutex(&field_8, true, 0);
    Unk_2771490.field_4++;
}

// 0x7100596570 (D2), 0x71005965a0 (D0)
SiOSMutex::~SiOSMutex() {
    Unk_2771490.field_4--;
    nn::os::FinalizeMutex(&field_8);
}

// 0x71005965f0
bool SiOSMutex::vf2() {
    nn::os::LockMutex(&field_8);
    return true;
}

// 0x7100596610
bool SiOSMutex::vf3() {
    nn::os::UnlockMutex(&field_8);
    return true;
}

// 0x7100596630
bool SiOSMutex::vf4() {
    return nn::os::TryLockMutex(&field_8);
}

}  // namespace SiSDK3

// 0x7100596640
Unk_596640::Unk_596640(SiSDK3::SiOSSyncObject* object, bool lock) : field_0(object), field_8(false) {
    if (lock) {
        object->vf2();
        field_8 = true;
    }
}

// 0x7100596760
void Unk_596760() {
    nn::os::YieldThread();
}
