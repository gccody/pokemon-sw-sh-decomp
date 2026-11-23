// Scope: common
// The function that loads NVN's entry points for SiGfx's NX device
// (placeholder file and names: the translation unit's name isn't in the
// executable; its other functions are 0x7100539890, lib/yebis/leaf, and the
// static initialiser 0x71005398a0, lib/yebis/static).
#include <nx_middleware/gfx/nvn.h>

#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/SiCore_Memory.h>

// The NVN bootstrap loader, an import of `main`.
extern "C" NvnProc nvnBootstrapLoader(const char* name);

using Unk_1789d10_GetProc = NvnProc (*)(void* device, const char* name);
void Unk_1789d10(void* device, Unk_1789d10_GetProc getProc);

// 0x710276edb0: the bootstrap loader, 0x710276edb8: the device's
// GetProcAddress (placeholder names)
NvnProc (*Unk_276edb0)(const char* name);
Unk_1789d10_GetProc Unk_276edb8;

// 0x7100539840 (the device passes it an allocator and 0, which it doesn't use)
bool Unk_539840(SiSDK3::ISiAllocator*, s32) {
    Unk_276edb0 = nvnBootstrapLoader;
    Unk_276edb8 = reinterpret_cast<Unk_1789d10_GetProc>(nvnBootstrapLoader("nvnDeviceGetProcAddress"));
    Unk_1789d10(nullptr, Unk_276edb8);
    return true;
}
