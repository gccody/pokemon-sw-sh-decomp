// Scope: common
#include "Unk_1ec0.h"

extern boost::core::typeinfo Unk_24ba4b0;
extern u64 Unk_24ba4b8;

// 0x7100002160
void Unk_2160_init() {
    if ((Unk_24ba4b8 & 1) == 0) {
        Unk_24ba4b0 = boost::core::typeinfo(
            UNK_1EC0_TYPEID_NAME(UNK_1EC0_LAMBDA("detail\\signal_template.hpp", "497:15")));
        Unk_24ba4b8 = 1;
    }
}
