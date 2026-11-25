// Scope: common
#include "Unk_1ec0.h"

extern boost::core::typeinfo Unk_24ba3f0;
extern u64 Unk_24ba3f8;

// 0x7100001f20
void Unk_1f20_init() {
    if ((Unk_24ba3f8 & 1) == 0) {
        Unk_24ba3f0 = boost::core::typeinfo(
            UNK_1EC0_TYPEID_NAME(UNK_1EC0_LAMBDA("detail\\signal_template.hpp", "160:13")));
        Unk_24ba3f8 = 1;
    }
}
