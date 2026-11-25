// Scope: common
#include "Unk_1ec0.h"

extern boost::core::typeinfo Unk_24ba470;
extern u64 Unk_24ba478;

// 0x71000020a0
void Unk_20a0_init() {
    if ((Unk_24ba478 & 1) == 0) {
        Unk_24ba470 = boost::core::typeinfo(
            UNK_1EC0_TYPEID_NAME(UNK_1EC0_LAMBDA("detail\\signal_template.hpp", "521:15")));
        Unk_24ba478 = 1;
    }
}
