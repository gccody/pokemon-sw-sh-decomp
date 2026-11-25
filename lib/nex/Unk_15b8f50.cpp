// Scope: common
// NEX 4.6.8: the system tick, a wrapper of the SDK's (its own TU: the job
// constructors in lib/nex/Unk_1630ba0.cpp call it).
#include <types.h>

#include <nn/os.h>

// 0x71015b8f50
u64 Unk_15b8f50() {
    return nn::os::GetSystemTick().field_0;
}
