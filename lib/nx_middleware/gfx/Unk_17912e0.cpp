// Scope: common
// NintendoSDK_gfx 7.3.2 for NVN: the addresses of the GLSLC entry points,
// imports of `main` (the names are the imports'; their parameters aren't
// needed here). Placeholder names (gfx.h).
#include "nx_middleware/gfx/gfx.h"

extern "C" {
void glslcCompilePreSpecialized();
void glslcCompileSpecialized();
void glslcInitialize();
void glslcFinalize();
void glslcCompile();
void glslcGetVersion();
void glslcSetAllocator();
void glslcGetDefaultOptions();
}

using Unk_17911f0_Proc = void (*)();

// 0x71017912e0
Unk_17911f0_Proc Unk_17912e0() {
    return glslcCompilePreSpecialized;
}

// 0x71017912f0
Unk_17911f0_Proc Unk_17912f0() {
    return glslcCompileSpecialized;
}

// 0x7101791300
Unk_17911f0_Proc Unk_1791300() {
    return glslcInitialize;
}

// 0x7101791310
Unk_17911f0_Proc Unk_1791310() {
    return glslcFinalize;
}

// 0x7101791320
Unk_17911f0_Proc Unk_1791320() {
    return glslcCompile;
}

// 0x7101791330
Unk_17911f0_Proc Unk_1791330() {
    return glslcGetVersion;
}

// 0x7101791340
Unk_17911f0_Proc Unk_1791340() {
    return glslcSetAllocator;
}

// 0x7101791350
Unk_17911f0_Proc Unk_1791350() {
    return glslcGetDefaultOptions;
}
