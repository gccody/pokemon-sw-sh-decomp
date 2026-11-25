// Scope: common
#include "Unk_1ec0.h"

extern boost::core::typeinfo Unk_24ba400;
extern u64 Unk_24ba408;

// 0x7100001f50
void Unk_1f50_init() {
    if ((Unk_24ba408 & 1) == 0) {
        Unk_24ba400 = boost::core::typeinfo(
            UNK_1EC0_TYPEID_NAME(UNK_1EC0_LAMBDA("detail\\signal_template.hpp", "164:13")));
        Unk_24ba408 = 1;
    }
}
