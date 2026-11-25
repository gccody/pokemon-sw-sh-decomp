// Scope: common
#include "Unk_1ec0.h"

extern boost::core::typeinfo Unk_24ba4c0;
extern u64 Unk_24ba4c8;

// 0x7100002190
void Unk_2190_init() {
    if ((Unk_24ba4c8 & 1) == 0) {
        Unk_24ba4c0 = boost::core::typeinfo(
            UNK_1EC0_TYPEID_NAME(UNK_1EC0_LAMBDA("connection.hpp", "149:13")));
        Unk_24ba4c8 = 1;
    }
}
