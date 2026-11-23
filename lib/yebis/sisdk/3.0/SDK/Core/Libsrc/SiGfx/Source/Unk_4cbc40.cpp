// Scope: common
// A translation unit of its own between two static initialisers (placeholder
// file and names): the comparison of two versions, and its statics, a
// reflection handle and two versions (3.0.0.160).
#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/SiCore_Reflection.h>
#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/Unk_Version.h>

// 0x710276ce50
static SiSDK3::SiReflectionPropertyHandle Unk_276ce50;

// 0x710276ce30, 0x710276ce40: two versions next to the handle, so the
// translation unit's own. Nothing in the executable reads them: what did was
// dropped by the linker. Unk_276ce30_get stands for that
// (data/absent_functions.csv): the compiler only keeps the variables and the
// initialiser's stores if something reads them.
static SiSDK3::Unk_567750_Version Unk_276ce30(3, 0, 0, 160);
static SiSDK3::Unk_567750_Version Unk_276ce40(3, 0, 0, 160);

const SiSDK3::Unk_567750_Version* Unk_276ce30_get(bool second) {
    return second ? &Unk_276ce40 : &Unk_276ce30;
}

// 0x71004cbc40: compares two versions of four numbers each (-1, 0 or 1)
s32 Unk_4cbc40(s32 a0, s32 a1, s32 a2, s32 a3, s32 b0, s32 b1, s32 b2, s32 b3) {
    if (a0 < b0) {
        return -1;
    }
    if (a0 > b0) {
        return 1;
    }
    if (a1 < b1) {
        return -1;
    }
    if (a1 > b1) {
        return 1;
    }
    if (a2 < b2) {
        return -1;
    }
    if (a2 > b2) {
        return 1;
    }
    if (a3 < b3) {
        return -1;
    }
    return a3 > b3;
}

// 0x71004cbcb0: _GLOBAL__sub_I_Unk_4cbc40.cpp
