// Scope: common
#include "pia/common/Unk_165e060.h"

extern s32 Unk_27fb084;    // the stack's depth
extern s32 Unk_27fb018[];  // a stack of ids

namespace nn {
namespace pia {

// 0x710165dfb0
Unk_165e060 Unk_165dfb0(s32 id) {
    if (static_cast<u32>(id - 2) >= 25) {
        return Unk_165e060Value<0x10c07>();
    }
    if (Unk_27fb084 <= 0) {
        return Unk_165e060Value<0x10c08>();
    }
    if (Unk_27fb018[Unk_27fb084 - 1] != id) {
        return Unk_165e060Value<0x10c08>();
    }
    Unk_27fb084--;
    return Unk_165e060Value<0>();
}

// 0x710165e060
Unk_165e060::Unk_165e060(const Unk_165e060& other) : m_Value(other.m_Value) {
    if (other == Unk_165e060(0xe437) || other == Unk_165e060(0xa46e)) {
        m_Variant = other.m_Variant;
    } else {
        m_Variant = nn::Result();
    }
}

// 0x710165e140
Unk_165e060& Unk_165e060::operator=(const Unk_165e060& other) {
    m_Value = other.m_Value;
    if (other == Unk_165e060(0xe437) || other == Unk_165e060(0xa46e)) {
        m_Variant = other.m_Variant;
    } else {
        m_Variant = nn::Result();
    }
    return *this;
}

// 0x710165e380
u32 Unk_165e060::Unk_165e380() const {
    if (m_Value == 0) {
        return 0;
    }
    if (*this == Unk_165e060(0xe437)) {
        nn::err::ErrorCode code = m_Variant;
        return code.field_0 * 10000 + code.field_4;
    }
    if (*this == Unk_165e060(0xa46e)) {
        return static_cast<nn::Result>(m_Variant).field_0;
    }
    if (*this == Unk_165e060(0x10c01)) {
        return 26180001;
    }
    if (*this == Unk_165e060(0x10c02)) {
        return 26180002;
    }
    if (*this == Unk_165e060(0x10c04)) {
        return 26180003;
    }
    if (*this == Unk_165e060(0x2c03)) {
        return 26180004;
    }
    if (*this == Unk_165e060(0x6c05)) {
        return 26180005;
    }
    if (*this == Unk_165e060(0xc406)) {
        return 26180006;
    }
    if (*this == Unk_165e060(0x10c07)) {
        return 26180007;
    }
    if (*this == Unk_165e060(0x10c08)) {
        return 26180008;
    }
    if (*this == Unk_165e060(0x2c09)) {
        return 26180009;
    }
    if (*this == Unk_165e060(0x2c0a)) {
        return 26180010;
    }
    if (*this == Unk_165e060(0xc0b)) {
        return 26180011;
    }
    if (*this == Unk_165e060(0x10c0c)) {
        return 26180012;
    }
    if (*this == Unk_165e060(0x4c0d)) {
        return 26180013;
    }
    if (*this == Unk_165e060(0x6c0e)) {
        return 26180014;
    }
    if (*this == Unk_165e060(0x10c0f)) {
        return 26180015;
    }
    if (*this == Unk_165e060(0xc10)) {
        return 26180016;
    }
    if (*this == Unk_165e060(0x4c11)) {
        return 26180017;
    }
    if (*this == Unk_165e060(0x10c13)) {
        return 26180019;
    }
    if (*this == Unk_165e060(0x10c14)) {
        return 26180101;
    }
    if (*this == Unk_165e060(0x6434)) {
        return 26180201;
    }
    if (*this == Unk_165e060(0xc35)) {
        return 26180202;
    }
    if (*this == Unk_165e060(0x6436)) {
        return 26180203;
    }
    if (*this == Unk_165e060(0xc16)) {
        return 26180302;
    }
    if (*this == Unk_165e060(0x2c18)) {
        return 26180304;
    }
    if (*this == Unk_165e060(0x6c19)) {
        return 26180305;
    }
    if (*this == Unk_165e060(0x6c1b)) {
        return 26180308;
    }
    if (*this == Unk_165e060(0x6c1c)) {
        return 26180309;
    }
    if (*this == Unk_165e060(0x6c1d)) {
        return 26180310;
    }
    if (*this == Unk_165e060(0x641e)) {
        return 26180311;
    }
    if (*this == Unk_165e060(0x641f)) {
        return 26180312;
    }
    if (*this == Unk_165e060(0xc420)) {
        return 26180313;
    }
    if (*this == Unk_165e060(0xc421)) {
        return 26180314;
    }
    if (*this == Unk_165e060(0x6422)) {
        return 26180315;
    }
    if (*this == Unk_165e060(0xc24)) {
        return 26180401;
    }
    if (*this == Unk_165e060(0xc25)) {
        return 26180402;
    }
    if (*this == Unk_165e060(0x10c26)) {
        return 26180403;
    }
    if (*this == Unk_165e060(0x2c27)) {
        return 26180404;
    }
    if (*this == Unk_165e060(0xc28)) {
        return 26180405;
    }
    if (*this == Unk_165e060(0x6838)) {
        return 26180501;
    }
    if (*this == Unk_165e060(0x6439)) {
        return 26180502;
    }
    if (*this == Unk_165e060(0x6c3d)) {
        return 26180506;
    }
    if (*this == Unk_165e060(0x10c3e)) {
        return 26180507;
    }
    if (*this == Unk_165e060(0x643f)) {
        return 26180510;
    }
    if (*this == Unk_165e060(0x6442)) {
        return 26180513;
    }
    if (*this == Unk_165e060(0x6445)) {
        return 26180514;
    }
    if (*this == Unk_165e060(0x6443)) {
        return 26180515;
    }
    if (*this == Unk_165e060(0x6444)) {
        return 26180516;
    }
    if (*this == Unk_165e060(0x6846)) {
        return 26180517;
    }
    if (*this == Unk_165e060(0x6847)) {
        return 26180518;
    }
    if (*this == Unk_165e060(0x6848)) {
        return 26180519;
    }
    if (*this == Unk_165e060(0x6849)) {
        return 26180520;
    }
    if (*this == Unk_165e060(0x644a)) {
        return 26180521;
    }
    if (*this == Unk_165e060(0x6c4b)) {
        return 26180541;
    }
    if (*this == Unk_165e060(0x6c4c)) {
        return 26180542;
    }
    if (*this == Unk_165e060(0x6c4d)) {
        return 26180543;
    }
    if (*this == Unk_165e060(0x6c4e)) {
        return 26180544;
    }
    if (*this == Unk_165e060(0x6c51)) {
        return 26180545;
    }
    if (*this == Unk_165e060(0x6c52)) {
        return 26180546;
    }
    if (*this == Unk_165e060(0x6c50)) {
        return 26180547;
    }
    if (*this == Unk_165e060(0x6c53)) {
        return 26180548;
    }
    if (*this == Unk_165e060(0x6c54)) {
        return 26180549;
    }
    if (*this == Unk_165e060(0x6c55)) {
        return 26180550;
    }
    if (*this == Unk_165e060(0x8c56)) {
        return 26180551;
    }
    if (*this == Unk_165e060(0x6c57)) {
        return 26180552;
    }
    if (*this == Unk_165e060(0x6c59)) {
        return 26180554;
    }
    if (*this == Unk_165e060(0x6c5b)) {
        return 26180555;
    }
    if (*this == Unk_165e060(0xa44f)) {
        return 26180561;
    }
    if (*this == Unk_165e060(0xac5a)) {
        return 26180562;
    }
    if (*this == Unk_165e060(0x8c78)) {
        return 26180563;
    }
    if (*this == Unk_165e060(0x8c76)) {
        return 26180564;
    }
    if (*this == Unk_165e060(0x8c77)) {
        return 26180565;
    }
    if (*this == Unk_165e060(0x8c7a)) {
        return 26180566;
    }
    if (*this == Unk_165e060(0x8c79)) {
        return 26180567;
    }
    if (*this == Unk_165e060(0x6c5f)) {
        return 26180571;
    }
    if (*this == Unk_165e060(0x6c60)) {
        return 26180572;
    }
    if (*this == Unk_165e060(0x6c61)) {
        return 26180573;
    }
    if (*this == Unk_165e060(0x6c62)) {
        return 26180574;
    }
    if (*this == Unk_165e060(0x6c63)) {
        return 26180575;
    }
    if (*this == Unk_165e060(0x6c66)) {
        return 26180576;
    }
    if (*this == Unk_165e060(0x2c64)) {
        return 26180577;
    }
    if (*this == Unk_165e060(0x6c65)) {
        return 26180578;
    }
    if (*this == Unk_165e060(0xa471)) {
        return 26180579;
    }
    if (*this == Unk_165e060(0x6467)) {
        return 26180583;
    }
    if (*this == Unk_165e060(0x646a)) {
        return 26180584;
    }
    if (*this == Unk_165e060(0x6468)) {
        return 26180585;
    }
    if (*this == Unk_165e060(0x6469)) {
        return 26180586;
    }
    if (*this == Unk_165e060(0xa472)) {
        return 26180590;
    }
    if (*this == Unk_165e060(0xa473)) {
        return 26180591;
    }
    if (*this == Unk_165e060(0xa474)) {
        return 26180592;
    }
    if (*this == Unk_165e060(0xa475)) {
        return 26180593;
    }
    if (*this == Unk_165e060(0x4c2c)) {
        return 26180602;
    }
    if (*this == Unk_165e060(0x10c32)) {
        return 26180606;
    }
    if (*this == Unk_165e060(0x646f)) {
        return 26180701;
    }
    if (*this == Unk_165e060(0x6470)) {
        return 26180702;
    }
    if (*this == Unk_165e060(0xec6b)) {
        return 26181001;
    }
    if (*this == Unk_165e060(0xac6d)) {
        return 26181003;
    }
    if (*this == Unk_165e060(0xec7b)) {
        return 26181101;
    }
    return 26180000;
}

// 0x710165e210
// NON_MATCHING: the stack slots of the comparisons' temporaries, and 9 more
// instructions.
Unk_165e060 Unk_165e060::Unk_165e210(nn::err::ErrorResultVariant* error) const {
    if (error == nullptr) {
        return Unk_165e060Value<0x10c07>();
    }
    if (m_Value != 0) {
        if (*this == Unk_165e060(0xe437)) {
            if (m_Variant.GetState() == 2) {
                *error = m_Variant;
                return Unk_165e060Value<0>();
            }
        } else if (*this == Unk_165e060(0xa46e)) {
            if (m_Variant.GetState() == 1) {
                *error = m_Variant;
                return Unk_165e060Value<0>();
            }
            return Unk_165e060Value<0x10c08>();
        }
    }
    u32 number = Unk_165e380();
    nn::err::ErrorCode code;
    code.field_0 = number / 10000;
    code.field_4 = number % 10000;
    *error = code;
    return Unk_165e060Value<0>();
}

// 0x710165fb10
void Unk_165e060::Unk_165fb10(const nn::err::ErrorResultVariant& variant) {
    m_Variant = variant;
}

}  // namespace pia
}  // namespace nn
