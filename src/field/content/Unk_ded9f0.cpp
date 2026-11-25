// Scope: common
// HaxeVector3's factories, the start of its TU (HaxeVector3.h): its constructor is
// defined here, so they inline it.
#include <types.h>

#include "field/content/HaxeVector3.h"

namespace field {
namespace content {

// The constructor, 0x7100ded9e0: matched under its leaf placeholder name Unk_ded9e0_set
// (src/unsorted/leaf/Unk_de8ae0.cpp) until it's renamed. Defined here so the factories
// inline it, as the original's do.
HaxeVector3::HaxeVector3(float x, float y, float z) : X(x), Y(y), Z(z) {}

// 0x7100ded9f0
HaxeVector3 HaxeVector3::Create(float x, float y, float z) {
    return HaxeVector3(x, y, z);
}

// 0x7100deda00
HaxeVector3 HaxeVector3::CreateAdd(HaxeVector3 a, HaxeVector3 b) {
    return HaxeVector3(a.X + b.X, a.Y + b.Y, a.Z + b.Z);
}

// 0x7100deda10
HaxeVector3 HaxeVector3::CreateSub(HaxeVector3 a, HaxeVector3 b) {
    return HaxeVector3(a.X - b.X, a.Y - b.Y, a.Z - b.Z);
}

}  // namespace content
}  // namespace field
