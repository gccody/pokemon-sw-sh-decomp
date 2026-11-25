// Scope: common
#include "Unk_1ec0.h"

extern boost::core::typeinfo Unk_24ba430;
extern u64 Unk_24ba438;

// 0x7100001fe0
void Unk_1fe0_init() {
    if ((Unk_24ba438 & 1) == 0) {
        Unk_24ba430 = boost::core::typeinfo(
            UNK_1EC0_TYPEID_NAME(UNK_1EC0_LAMBDA("detail\\signal_template.hpp", "521:15")));
        Unk_24ba438 = 1;
    }
}
