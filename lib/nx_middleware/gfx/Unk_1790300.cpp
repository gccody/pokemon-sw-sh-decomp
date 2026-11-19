// Scope: common
// NintendoSDK_gfx 7.3.2 for NVN: swap chain memory sizes. Placeholder names
// (gfx.h).
#include "nx_middleware/gfx/gfx.h"

size_t Unk_1790a50(const Unk_1791080_Device* device, const Unk_178dac0_Info& info);
size_t Unk_1790ab0(const Unk_1791080_Device* device, const Unk_178dac0_Info& info);

// A color target view's info: its image format and size.
struct Unk_178d740_In;
void Unk_178d740(Unk_178dac0_Info* out, const Unk_178d740_In* in);

// 0x7101790300
size_t Unk_1790300(const Unk_1791080_Device* device, const Unk_178d740_In* in) {
    Unk_178dac0_Info info = {};
    Unk_178d740(&info, in);
    return Unk_1790a50(device, info);
}

// What a swap chain is made from: the number of scan buffers first.
struct Unk_1790350_Info {
    u8 field_0;
};

// 0x7101790350
size_t Unk_1790350(const Unk_1791080_Device* device, const Unk_1790350_Info* in) {
    Unk_178dac0_Info alignmentInfo;
    Unk_178dac0_Info sizeInfo = {};
    Unk_178d740(&sizeInfo, reinterpret_cast<const Unk_178d740_In*>(in));
    size_t size = Unk_1790ab0(device, sizeInfo);
    alignmentInfo = {};
    Unk_178d740(&alignmentInfo, reinterpret_cast<const Unk_178d740_In*>(in));
    size_t alignment = Unk_1790a50(device, alignmentInfo);
    return ((size + alignment - 1) & -alignment) * in->field_0;
}
