// Scope: common
#include "Unk_1ec0.h"

extern boost::core::typeinfo Unk_24ba410;
extern u64 Unk_24ba418;

// 0x7100001f80
void Unk_1f80_init() {
    if ((Unk_24ba418 & 1) == 0) {
        Unk_24ba410 = boost::core::typeinfo(
            UNK_1EC0_TYPEID_NAME(UNK_1EC0_LAMBDA("detail\\signal_template.hpp", "692:11")));
        Unk_24ba418 = 1;
    }
}
