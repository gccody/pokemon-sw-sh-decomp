// Scope: common
// NintendoWare Font 7.3.2: the base of nn::font::ResFont (vtable
// 0x710246a5c8, no RTTI): its constructor, destructors and the functions that
// hand its texture's descriptor slot to a callback. Placeholder names
// (Unk_177baf0.h).
#include <types.h>

#include "Unk_177baf0.h"

// 0x710177bef0
Unk_246a5b8::Unk_246a5b8()
    : field_10(0), field_18(nullptr), field_20(nullptr), field_60(0), field_68(0), field_70(0), field_78(0),
      rangeCount(0) {
    vf25(true, true);
}

// 0x710177bfd0
Unk_246a5b8::~Unk_246a5b8() {}

// 0x710177c0f0
void Unk_246a5b8::Unk_177c0f0(Callback callback, void* arg) {
    callback(&field_28.field_20, field_28.field_28->field_88, arg);
}

// 0x710177c120
void Unk_246a5b8::Unk_177c120(Callback callback, void* arg) {
    callback(&field_28.field_20, field_28.field_28->field_88, arg);
}
