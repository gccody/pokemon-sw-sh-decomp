// Scope: common
#include "Unk_1ec0.h"

extern boost::core::typeinfo Unk_24ba460;
extern u64 Unk_24ba468;

// 0x7100002070
void Unk_2070_init() {
    if ((Unk_24ba468 & 1) == 0) {
        Unk_24ba460 = boost::core::typeinfo(
            UNK_1EC0_TYPEID_NAME(UNK_1EC0_LAMBDA("detail\\signal_template.hpp", "402:15")));
        Unk_24ba468 = 1;
    }
}
