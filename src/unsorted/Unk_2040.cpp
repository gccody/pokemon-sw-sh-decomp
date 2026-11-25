// Scope: common
#include "Unk_1ec0.h"

extern boost::core::typeinfo Unk_24ba450;
extern u64 Unk_24ba458;

// 0x7100002040
void Unk_2040_init() {
    if ((Unk_24ba458 & 1) == 0) {
        Unk_24ba450 = boost::core::typeinfo(
            UNK_1EC0_TYPEID_NAME(UNK_1EC0_LAMBDA("detail\\signal_template.hpp", "521:15")));
        Unk_24ba458 = 1;
    }
}
