// Scope: common
// SiSDK3::SiGfxNXCanvas: its name, the accessors of its buffers and of its
// window's textures, and the reference counts its header defines. (Its
// constructor, destructor and the functions that make and resize it aren't
// written yet; its other small accessors are lib/yebis/class's.)
#define UNK_SIGFX_NX_CANVAS_IMPL
#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiGfx/Source/NX/SiGfx_NX_Canvas_Impl.h>

#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/Unk_StringFuncs.h>

namespace SiSDK3 {

// 0x71004fcaa0 (0x71004fcae0: its thunk)
bool SiGfxNXCanvas::vf51(const char* name) {
    Unk_4c4700(&field_38, const_cast<char*>(name));
    field_68 = Unk_4c3510(&field_38);
    return true;
}

// 0x71004fcb20 (0x71004fcb30: its thunk)
const SiString<char>* SiGfxNXCanvas::vf52() {
    return &field_38;
}

// 0x71004fcb40 (0x71004fcb50: its thunk)
u32 SiGfxNXCanvas::vf53() {
    return field_68;
}

// 0x71004fd030
Unk_NXCanvasBuffer* SiGfxNXCanvas::vf24(s32 index) {
    if (index < 0) {
        return nullptr;
    }
    if ((index > 3) | (index >= field_11c)) {
        return nullptr;
    }
    return field_120[index];
}

// 0x71004fdce0
void* SiGfxNXCanvas::vf32(s32 index) {
    return Unk_Get150(index);
}

// 0x71004fdd20
void* SiGfxNXCanvas::vf33(s32 index) {
    return Unk_Get150(index);
}

// 0x71004fdd60
void* SiGfxNXCanvas::vf34() {
    return Unk_Get150(field_114);
}

// 0x71004fdda0
void* SiGfxNXCanvas::vf35() {
    return Unk_Get150(field_114);
}

// 0x71004fdde0
void* SiGfxNXCanvas::vf36() {
    return Unk_Get150(field_118);
}

// 0x71004fde20
void* SiGfxNXCanvas::vf37() {
    return Unk_Get150(field_118);
}

// 0x71004fde60
void* SiGfxNXCanvas::vf38(s32 index) {
    return Unk_Get178(index);
}

// 0x71004fdea0
void* SiGfxNXCanvas::vf39(s32 index) {
    return Unk_Get178(index);
}

// 0x71004fdee0
void* SiGfxNXCanvas::vf40() {
    return Unk_Get178(field_114);
}

// 0x71004fdf20
void* SiGfxNXCanvas::vf41() {
    return Unk_Get178(field_114);
}

// 0x71004fdf60
void* SiGfxNXCanvas::vf42() {
    return Unk_Get178(field_118);
}

// 0x71004fdfa0
void* SiGfxNXCanvas::vf43() {
    return Unk_Get178(field_118);
}

// 0x71004fdfe0
u32 SiGfxNXCanvas::vf44(u64 a1, s32 index) {
    if (index < 0 || field_11c <= index) {
        return 0;
    }
    Unk_NXCanvasBuffer* pBuffer = field_120[index];
    if (pBuffer == nullptr) {
        return 0;
    }
    return pBuffer->vf24(a1);
}

// 0x71004fe130
void* SiGfxNXCanvas::vf49(s32 index) {
    if (index < 0 || field_1a0.m_itemCount < static_cast<size_t>(index)) {
        return nullptr;
    }
    return field_1a0.m_pData[index];
}

// 0x71004fe160
void* SiGfxNXCanvas::vf50(s32 index) {
    if (index < 0 || field_1f0.m_itemCount < static_cast<size_t>(index)) {
        return nullptr;
    }
    return field_1f0.m_pData[index];
}

}  // namespace SiSDK3
