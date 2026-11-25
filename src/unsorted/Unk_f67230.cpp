// Scope: common
// Unk_23ff270, one of the mystery gift app's views (src/unsorted/Unk_f67230.h):
// its destructor, its layout file and the sound its states play, with the
// common base's slots its vtable is the first to emit.
#include "unsorted/Unk_f67230.h"

struct Unk_e83430;
u32 Unk_e83430_call(const Unk_e83430* self, void* arg);

// 0x7100f673c0 (its D2: the base's, shared by the four vtables), its D0
// (0x7100f673d0) and thunks for +0x48 (0x7100f674d0, 0x7100f674e0), +0x50
// (0x7100f675d0, 0x7100f675e0) and +0x5d0 (0x7100f67670, 0x7100f67680)
Unk_23ff270::~Unk_23ff270() {}

// 0x7100f67230
void Unk_f67230(Unk_23ff270*, Unk_27e15e0_Layout* layout) {
    Unk_27e15e0_MoveName(layout->field_0,
                         Unk_c46830("bin/appli/mystery/bin/mystery_bg_00_lyt.bin"));
    layout->field_60 = false;
}

// 0x7100f67340
void Unk_23ff270::Unk_f67340() {
    if (field_5e0 != 0) {
        static const u64 hash = 0xda74cfea38becf9f;
        Unk_e83430_call(reinterpret_cast<const Unk_e83430*>(&field_100), const_cast<u64*>(&hash));
        field_5e0 = 0;
    }
}

// 0x7100f67380
void Unk_23ff270::Unk_f67380() {
    if (field_5e0 != 1) {
        static const u64 hash = 0x5deb53e286553cde;
        Unk_e83430_call(reinterpret_cast<const Unk_e83430*>(&field_100), const_cast<u64*>(&hash));
        field_5e0 = 1;
    }
}
