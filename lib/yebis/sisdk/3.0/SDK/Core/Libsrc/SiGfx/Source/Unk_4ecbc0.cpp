// Scope: common
// The settings the graphics kernel keeps (placeholder file and names: the
// translation unit's name isn't in the executable; its static initialiser is
// lib/yebis/static/Unk_4ecfe0.cpp's), and a table of formats.
#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/Unk_StringFuncs.h>
#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiGfx/Source/SiGfx_Kernel_Impl.h>

namespace SiSDK3 {

// 0x71004ecbc0
Unk_4ecbc0::Unk_4ecbc0(ISiAllocator* pAllocator)
    : field_0(pAllocator), field_30(pAllocator), field_60(true), field_61(true) {
    Unk_StringAssign(&field_0, "ShaderPackage");
    Unk_StringAssign(&field_30, "Font");
    field_62 = false;
    field_63 = false;
    field_64 = false;
    field_65 = false;
    field_66 = false;
    field_67 = false;
}

// 0x71004ecc80
Unk_4ecbc0::~Unk_4ecbc0() {}

// 0x71004ecd20
void Unk_4ecbc0::Unk_4ecd20(ISiAllocator* pAllocator) {
    field_0.Unk_Clear();
    field_30.Unk_Clear();
    field_0.Unk_SetAllocator(pAllocator);
    field_30.Unk_SetAllocator(pAllocator);
    Unk_StringAssign(&field_0, "shaderpkg");
    Unk_StringAssign(&field_30, "font");
}

}  // namespace SiSDK3

// 0x71004ecf40: one of seven formats of a kind (2 to 6), 0 for anything else
// (placeholder name). The inner switches became the tables.
u32 Unk_4ecf40(s32 kind, s32 index) {
    switch (kind) {
    case 2:
        switch (index) {
        case 0:
            return 13;
        case 1:
            return 14;
        case 2:
            return 15;
        case 3:
            return 16;
        case 4:
            return 17;
        case 5:
            return 18;
        case 6:
            return 79;
        }
        break;
    case 3:
        switch (index) {
        case 0:
            return 37;
        case 1:
            return 38;
        case 2:
            return 39;
        case 3:
            return 40;
        case 4:
            return 41;
        case 5:
            return 42;
        case 6:
            return 83;
        }
        break;
    case 4:
        switch (index) {
        case 0:
            return 25;
        case 1:
            return 26;
        case 2:
            return 27;
        case 3:
            return 28;
        case 4:
            return 29;
        case 5:
            return 30;
        case 6:
            return 81;
        }
        break;
    case 5:
        switch (index) {
        case 0:
            return 49;
        case 1:
            return 50;
        case 2:
            return 51;
        case 3:
            return 52;
        case 4:
            return 53;
        case 5:
            return 54;
        case 6:
            return 85;
        }
        break;
    case 6:
        switch (index) {
        case 0:
            return 61;
        case 1:
            return 62;
        case 2:
            return 63;
        case 3:
            return 64;
        case 4:
            return 65;
        case 5:
            return 66;
        case 6:
            return 87;
        }
        break;
    }
    return 0;
}
