// Scope: common
#include "pia/common/Unk_1749cd0.h"

namespace nn {
namespace pia {

// 0x7101749cf0
Unk_165fb30 Unk_1749cf0::Unk_1749cf0_get() const {
    Unk_165fb30 result;
    if (field_7b == 1) {
        result.Unk_165fd90(field_28);
    } else {
        result.Unk_165fd90(field_8);
    }
    return result;
}

}  // namespace pia
}  // namespace nn
