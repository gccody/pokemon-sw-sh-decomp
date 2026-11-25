// Scope: common
#include "Unk_1ec0.h"

extern boost::core::typeinfo Unk_24ba490;
extern u64 Unk_24ba498;

// 0x7100002100
void Unk_2100_init() {
    if ((Unk_24ba498 & 1) == 0) {
        Unk_24ba490 = boost::core::typeinfo(
            UNK_1EC0_TYPEID_NAME(UNK_1EC0_LAMBDA("connection.hpp", "149:13")));
        Unk_24ba498 = 1;
    }
}
