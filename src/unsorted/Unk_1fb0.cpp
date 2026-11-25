// Scope: common
#include "Unk_1ec0.h"

extern boost::core::typeinfo Unk_24ba420;
extern u64 Unk_24ba428;

// 0x7100001fb0
void Unk_1fb0_init() {
    if ((Unk_24ba428 & 1) == 0) {
        Unk_24ba420 = boost::core::typeinfo(
            UNK_1EC0_TYPEID_NAME(UNK_1EC0_LAMBDA("detail\\signal_template.hpp", "402:15")));
        Unk_24ba428 = 1;
    }
}
