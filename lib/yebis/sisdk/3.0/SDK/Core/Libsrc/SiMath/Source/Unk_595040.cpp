// Scope: common
// SiMath's vector constants (placeholder file name, after its static
// initialiser): for each of four element types, the zero and all-ones vectors
// of two, three and four elements and the three unit vectors of three. The
// class templates are named by RTTI (SiSDK3::SiMathVector3D<float> is a
// reflected property's type); the constants' names aren't in the executable,
// and neither is the second integer type (unsigned here).
#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/SiCore_Reflection.h>

namespace SiSDK3 {

template <class T>
struct SiMathVector2D {
    SiMathVector2D(T x, T y) : field_0(x), field_1(y) {}

    T field_0;
    T field_1;
};

template <class T>
struct SiMathVector3D {
    SiMathVector3D(T x, T y, T z) : field_0(x), field_1(y), field_2(z) {}

    T field_0;
    T field_1;
    T field_2;
};

template <class T>
struct SiMathVector4D {
    SiMathVector4D(T x, T y, T z, T w) : field_0(x), field_1(y), field_2(z), field_3(w) {}

    T field_0;
    T field_1;
    T field_2;
    T field_3;
};

}  // namespace SiSDK3

// 0x7102770f10
static SiSDK3::SiReflectionPropertyHandle Unk_2770f10;

SiSDK3::SiMathVector2D<int> Unk_2770f88(0, 0);
SiSDK3::SiMathVector2D<int> Unk_2770f90(1, 1);
SiSDK3::SiMathVector2D<unsigned int> Unk_2770f98(0, 0);
SiSDK3::SiMathVector2D<unsigned int> Unk_2770fa0(1, 1);
SiSDK3::SiMathVector3D<int> Unk_2770fa8(0, 0, 0);
SiSDK3::SiMathVector3D<int> Unk_2770fb4(1, 0, 0);
SiSDK3::SiMathVector3D<int> Unk_2770fc0(0, 1, 0);
SiSDK3::SiMathVector3D<int> Unk_2770fcc(0, 0, 1);
SiSDK3::SiMathVector3D<int> Unk_2770fd8(1, 1, 1);
SiSDK3::SiMathVector3D<unsigned int> Unk_2770fe4(0, 0, 0);
SiSDK3::SiMathVector3D<unsigned int> Unk_2770ff0(1, 0, 0);
SiSDK3::SiMathVector3D<unsigned int> Unk_2770ffc(0, 1, 0);
SiSDK3::SiMathVector3D<unsigned int> Unk_2771008(0, 0, 1);
SiSDK3::SiMathVector3D<unsigned int> Unk_2771014(1, 1, 1);
SiSDK3::SiMathVector4D<int> Unk_2771020(0, 0, 0, 0);
SiSDK3::SiMathVector4D<int> Unk_2771030(1, 1, 1, 1);
SiSDK3::SiMathVector4D<unsigned int> Unk_2771040(0, 0, 0, 0);
SiSDK3::SiMathVector4D<unsigned int> Unk_2771050(1, 1, 1, 1);
SiSDK3::SiMathVector2D<float> Unk_2771060(0.0f, 0.0f);
SiSDK3::SiMathVector2D<float> Unk_2771068(1.0f, 1.0f);
SiSDK3::SiMathVector3D<float> Unk_2771070(0.0f, 0.0f, 0.0f);
SiSDK3::SiMathVector3D<float> Unk_277107c(1.0f, 0.0f, 0.0f);
SiSDK3::SiMathVector3D<float> Unk_2771088(0.0f, 1.0f, 0.0f);
SiSDK3::SiMathVector3D<float> Unk_2771094(0.0f, 0.0f, 1.0f);
SiSDK3::SiMathVector3D<float> Unk_27710a0(1.0f, 1.0f, 1.0f);
SiSDK3::SiMathVector4D<float> Unk_27710ac(0.0f, 0.0f, 0.0f, 0.0f);
SiSDK3::SiMathVector4D<float> Unk_27710bc(1.0f, 1.0f, 1.0f, 1.0f);
SiSDK3::SiMathVector2D<double> Unk_27710d0(0.0, 0.0);
SiSDK3::SiMathVector2D<double> Unk_27710e0(1.0, 1.0);
SiSDK3::SiMathVector3D<double> Unk_27710f0(0.0, 0.0, 0.0);
SiSDK3::SiMathVector3D<double> Unk_2771108(1.0, 0.0, 0.0);
SiSDK3::SiMathVector3D<double> Unk_2771120(0.0, 1.0, 0.0);
SiSDK3::SiMathVector3D<double> Unk_2771138(0.0, 0.0, 1.0);
SiSDK3::SiMathVector3D<double> Unk_2771150(1.0, 1.0, 1.0);
SiSDK3::SiMathVector4D<double> Unk_2771168(0.0, 0.0, 0.0, 0.0);
SiSDK3::SiMathVector4D<double> Unk_2771188(1.0, 1.0, 1.0, 1.0);

// 0x7100595040: _GLOBAL__sub_I_Unk_595040.cpp
