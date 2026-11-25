// Scope: common
#include "Unk_1ec0.h"

extern boost::core::typeinfo Unk_24ba440;
extern u64 Unk_24ba448;

// 0x7100002010
void Unk_2010_init() {
    if ((Unk_24ba448 & 1) == 0) {
        Unk_24ba440 = boost::core::typeinfo(
            UNK_1EC0_TYPEID_NAME(UNK_1EC0_LAMBDA("detail\\signal_template.hpp", "402:15")));
        Unk_24ba448 = 1;
    }
}
