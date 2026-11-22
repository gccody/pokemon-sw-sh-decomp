// Scope: common
// SiSDK3::SiOSSharedMemory: its construction, destruction and unmapping (the
// small accessors are lib/yebis/class's).
#define UNK_SIOS_SHAREDMEMORY_IMPL
#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiOS/Source/SiOS_SharedMemory_Impl.h>

namespace SiSDK3 {

// 0x71005960d0
SiOSSharedMemory::SiOSSharedMemory(ISiAllocator* pAllocator) : field_8(pAllocator) {
    field_20 = 0;
    field_28 = 0;
    field_18 = 0;
}

// 0x7100596110 (D2), 0x7100596150 (D0)
SiOSSharedMemory::~SiOSSharedMemory() {
    SiOSSharedMemory::vf11();
    field_20 = 0;
    field_28 = 0;
    field_18 = 0;
}

// 0x71005962a0
void SiOSSharedMemory::vf11() {
    if (field_20 > 0) {
        field_20--;
        if (field_20 == 0) {
            field_28 = 0;
        }
    }
}

}  // namespace SiSDK3
