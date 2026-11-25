// Scope: common
#include "Unk_1ec0.h"

extern boost::core::typeinfo Unk_24ba3e0;
extern u64 Unk_24ba3e8;

// 0x7100001ef0
void Unk_1ef0_init() {
    if ((Unk_24ba3e8 & 1) == 0) {
        Unk_24ba3e0 = boost::core::typeinfo(
            UNK_1EC0_TYPEID_NAME(UNK_1EC0_LAMBDA("detail\\signal_template.hpp", "397:15")));
        Unk_24ba3e8 = 1;
    }
}
