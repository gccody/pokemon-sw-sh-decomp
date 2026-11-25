// Scope: common
#include "Unk_1ec0.h"

extern boost::core::typeinfo Unk_24ba4a0;
extern u64 Unk_24ba4a8;

// 0x7100002130
void Unk_2130_init() {
    if ((Unk_24ba4a8 & 1) == 0) {
        Unk_24ba4a0 = boost::core::typeinfo(
            UNK_1EC0_TYPEID_NAME(UNK_1EC0_LAMBDA("detail\\signal_template.hpp", "537:13")));
        Unk_24ba4a8 = 1;
    }
}
