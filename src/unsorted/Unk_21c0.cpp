// Scope: common
#include "Unk_1ec0.h"

extern boost::core::typeinfo Unk_24ba4d0;
extern u64 Unk_24ba4d8;

// 0x71000021c0
void Unk_21c0_init() {
    if ((Unk_24ba4d8 & 1) == 0) {
        Unk_24ba4d0 = boost::core::typeinfo(
            UNK_1EC0_TYPEID_NAME(UNK_1EC0_LAMBDA("detail\\signal_template.hpp", "537:13")));
        Unk_24ba4d8 = 1;
    }
}
