// Scope: common
// Unk_23acf18's function (the TU of 0x710082f0d0-0x710082f1e0).
#include "unsorted/unk_82e410/Handler.h"

bool Unk_7ef540_call(void* self);
bool Unk_7ef580(void* self);

// 0x710082f100
void Unk_82f100(Unk_23acf18* /*self*/, Unk_23acc98_Result& result, const Unk_82f100_Arg& arg) {
    result.field_0 = false;
    if (!Unk_7ef580(arg.field_0) || Unk_7ef540_call(arg.field_0))
        result.field_0 = true;
}
