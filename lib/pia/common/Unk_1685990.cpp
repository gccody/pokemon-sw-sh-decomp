// Scope: common
// local::LdnConnectionStatus's getters of the network's channel and link level,
// and LocalConnectionStatus's of its result (lib/pia/common/Unk_1685600.h).
#include "pia/common/Unk_1685600.h"

namespace nn {
namespace pia {
namespace local {

// 0x7101685990
s32 LdnConnectionStatus::vf12() {
    return field_40.field_4a;
}

// 0x71016859a0
s32 LdnConnectionStatus::vf13() {
    return field_40.field_48;
}

// 0x71016859e0
Unk_165e060 LocalConnectionStatus::vf21() {
    return field_30;
}

}  // namespace local
}  // namespace pia
}  // namespace nn
