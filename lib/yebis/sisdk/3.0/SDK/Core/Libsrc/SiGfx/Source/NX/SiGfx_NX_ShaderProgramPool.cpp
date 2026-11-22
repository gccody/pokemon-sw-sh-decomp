// Scope: common
// SiSDK3::SiGfxNXShaderProgramPool: its destruction and the slots that only
// call its base (the pool's constructor is in Unk_Pools.cpp; the functions
// that make and take programs aren't written yet).
#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiGfx/Source/NX/Unk_Pools.h>

namespace SiSDK3 {

// What field_248 points at, as the destructor releases it (placeholder name).
class Unk_5597d0_Object {
public:
    virtual void vf0();
    virtual void vf1();
    virtual u32 vf2();
    virtual u32 vf3();
};

// 0x71005597d0 (D2), 0x7100559820 (D0)
SiGfxNXShaderProgramPool::~SiGfxNXShaderProgramPool() {
    SiGfxShaderProgramPoolBase::vf6();
    Unk_5597d0_Object* object = static_cast<Unk_5597d0_Object*>(field_248);
    if (object != nullptr) {
        object->vf3();
        field_248 = nullptr;
    }
}

// 0x7100559880
bool SiGfxNXShaderProgramPool::vf5(s32 count) {
    SiGfxShaderProgramPoolBase::vf5(count);
    return true;
}

// 0x71005598a0
void SiGfxNXShaderProgramPool::vf6() {
    SiGfxShaderProgramPoolBase::vf6();
}

}  // namespace SiSDK3
