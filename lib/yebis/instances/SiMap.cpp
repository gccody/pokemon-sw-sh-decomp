// Scope: common
// SiSDK3::SiMap's destructors (its virtual D1 and D0) and its nodes' delete,
// one explicit instantiation per instance the executable has (the vtables'
// RTTI names). Key and value types only need their sizes here.
#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/SiCore_Map.h>

namespace SiSDK3 {
class SiReflectionObject;
class SiKernel {
public:
    struct ReflectionCompare;
};
template <class T, int ALIGN>
struct SiMapCompareLess;
class SiGfxShaderEffect {
public:
    struct ShaderProgramKey {
        u64 field_0[3];
    };
    struct ShaderProgramCompileEntry;
};
}  // namespace SiSDK3

using namespace SiSDK3;

// 0x71004bfdb0 (D1), 0x71004c24f0 (D0), 0x71004c25a0 (the nodes' delete)
template SiSDK3::SiMap<const char*, SiReflectionObject*, SiKernel::ReflectionCompare, 16>::~SiMap();
// (0x710050aff0 (D1), 0x710050c3c0 (D0) and 0x710050c410, the map of
// FreeType's faces, come with SiGfx_FreeType_Manager.cpp, whose destructor
// has the map's inline.)
// 0x710056dc00 (D1), 0x710056dc60 (D0), 0x710056dcb0
template SiSDK3::SiMap<SiGfxShaderEffect::ShaderProgramKey, SiGfxShaderEffect::ShaderProgramCompileEntry*,
                       SiMapCompareLess<SiGfxShaderEffect::ShaderProgramKey, 16>, 16>::~SiMap();
