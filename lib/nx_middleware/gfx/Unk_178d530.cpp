// Scope: common
// NintendoSDK_gfx 7.3.2 for NVN: checks that do nothing in this build (each a
// `ret`). Placeholder names (gfx.h).
#include "nx_middleware/gfx/gfx.h"

// 0x710178d530: called with the NVN API version (53.311) the SDK was built
// against.
void Unk_178d530(int major, int minor) {
}

// 0x71017911b0: sets a texture view's format (the texture is only checked in
// a debug build).
void Unk_17911b0(void* view, int format, const void* texture) {
    nvnTextureViewSetFormat(view, format);
}
