// Scope: common
// transport::SequenceIdController's members (lib/pia/common/Unk_1749070.h).
// Its constructor, destructors and vf2 (0x7101749030-0x7101749060,
// 0x7101749260) belong to this TU too; 0x71017490e0 is Unk_17490e0_update.
#include "pia/common/Unk_1749070.h"

namespace nn {
namespace pia {
namespace transport {

// 0x7101749070
Unk_165e060 SequenceIdController::Unk_1749070() {
    field_8 = 0;
    field_a = 0;
    field_c = 0;
    field_e = 0;
    field_10 = 0;
    field_12 = false;
    field_14 = 0;
    field_18 = 0;
    return Unk_165e060Value<0>();
}

// 0x71017490f0
u16 SequenceIdController::Unk_17490f0() {
    ++field_8;
    if (field_8 == 0) {
        ++field_8;
    }
    return field_8;
}

// 0x7101749110
bool SequenceIdController::Unk_1749110(u16 id) {
    if (id == 0) {
        if (field_12) {
            if (field_10 == 0xffff) {
                field_10 = 0xffff;
                field_12 = false;
            } else {
                ++field_10;
            }
        }
        return true;
    }
    s16 step = id - field_a;
    if (step <= 0) {
        return false;
    }
    // Id 0 is skipped when the ids wrap.
    if (field_a != 0 && static_cast<u16>(-field_a) < step) {
        --step;
    }
    if (field_12) {
        u32 count = field_c + step;
        if (count <= 0xffff) {
            field_c = count;
            field_e += step - 1;
        } else {
            field_e += 0xffff - field_c;
            field_c = 0xffff;
            field_12 = false;
        }
    }
    if (field_14 != 0xffffffff) {
        u32 count = field_14 + step;
        if (count < field_14) {
            field_18 += 0xffffffff - field_14;
            field_14 = 0xffffffff;
        } else {
            field_14 = count;
            field_18 += step - 1;
        }
    }
    field_a = id;
    return true;
}

}  // namespace transport
}  // namespace pia
}  // namespace nn
