// Scope: common
#include "Unk_1ec0.h"

extern boost::core::typeinfo Unk_24ba480;
extern u64 Unk_24ba488;

// 0x71000020d0
void Unk_20d0_init() {
    if ((Unk_24ba488 & 1) == 0) {
        Unk_24ba480 = boost::core::typeinfo(
            UNK_1EC0_TYPEID_NAME(UNK_1EC0_LAMBDA("detail\\signal_template.hpp", "497:15")));
        Unk_24ba488 = 1;
    }
}
