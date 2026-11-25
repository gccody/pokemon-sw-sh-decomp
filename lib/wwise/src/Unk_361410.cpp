// Scope: common
// A wrapper of Unk_361410 (lib/wwise/src/Unk_362360.cpp) for an object made
// without a sound. Placeholder names.
#include "types.h"

struct Unk_362360_T;
struct Unk_360c20_T;
struct Unk_360c20_Params;
struct Unk_369950_Sound;

Unk_360c20_Params* Unk_361410(Unk_362360_T* self, Unk_360c20_T* target, Unk_369950_Sound* sound,
                              void* a3, void* a4, bool a5);

// 0x7100361750
Unk_360c20_Params* Unk_361750(Unk_362360_T* self, Unk_360c20_T* target, void* a3, void* a4,
                              bool a5) {
    return Unk_361410(self, target, nullptr, a3, a4, a5);
}
