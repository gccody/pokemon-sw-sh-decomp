// Scope: common
#include "pia/common/Unk_1659750.h"

namespace nn {
namespace pia {

// 0x7101659940
Unk_165e060 Unk_1659940_arg0::Unk_1659940(u8* buffer, u32* size, u32 bufferSize) const {
    if (buffer == nullptr || size == nullptr) {
        return Unk_165e060Value<0x10c07>();
    }
    if (bufferSize < Unk_1659bf0_get() + Unk_1659730()) {
        return Unk_165e060Value<0x10c07>();
    }
    u32 written = 0;
    Unk_165e060 result(0);
    result = field_0.Unk_1659aa0(buffer, &written, bufferSize);
    if (result.m_Value != 0) {
        return result;
    }
    u8* p = buffer + written;
    bufferSize -= written;
    result = field_10.Unk_16585a0(p, &written, bufferSize);
    if (result.m_Value != 0) {
        return result;
    }
    *size = p + written - buffer;
    return Unk_165e060Value<0>();
}

// 0x7101659aa0
Unk_165e060 Unk_1659aa0_arg0::Unk_1659aa0(u8* buffer, u32* size, u32 bufferSize) const {
    if (buffer == nullptr || size == nullptr) {
        return Unk_165e060Value<0x10c07>();
    }
    if (bufferSize < 0x10) {
        return Unk_165e060Value<0x10c07>();
    }
    u8* p = buffer;
    Unk_165ca00_set(reinterpret_cast<Unk_165ca00*>(&p[0x0]), field_0);
    Unk_165ca00_set(reinterpret_cast<Unk_165ca00*>(&p[0x1]), field_1);
    Unk_165ca00_set(reinterpret_cast<Unk_165ca00*>(&p[0x2]), field_2);
    Unk_165ca00_set(reinterpret_cast<Unk_165ca00*>(&p[0x3]), field_3);
    Unk_165c9e0_set(reinterpret_cast<Unk_165c9e0*>(&p[0x4]), field_4);
    Unk_165ca00_set(reinterpret_cast<Unk_165ca00*>(&p[0x6]), field_6);
    Unk_165ca00_set(reinterpret_cast<Unk_165ca00*>(&p[0x7]), field_7);
    Unk_165ca00_set(reinterpret_cast<Unk_165ca00*>(&p[0x8]), field_8);
    Unk_165ca00_set(reinterpret_cast<Unk_165ca00*>(&p[0x9]), field_9);
    Unk_165ca00_set(reinterpret_cast<Unk_165ca00*>(&p[0xa]), field_a);
    Unk_165ca00_set(reinterpret_cast<Unk_165ca00*>(&p[0xb]), field_b);
    Unk_165ca00_set(reinterpret_cast<Unk_165ca00*>(&p[0xc]), field_c);
    Unk_165ca00_set(reinterpret_cast<Unk_165ca00*>(&p[0xd]), field_d);
    Unk_165ca00_set(reinterpret_cast<Unk_165ca00*>(&p[0xe]), field_e);
    Unk_165ca00_set(reinterpret_cast<Unk_165ca00*>(&p[0xf]), field_f);
    *size = 0x10;
    return Unk_165e060Value<0>();
}

// 0x7101659ca0
Unk_165e060 Unk_1659ca0_arg0::Unk_1659ca0(u8* buffer, u32* size, u32 bufferSize) const {
    if (buffer == nullptr || size == nullptr) {
        return Unk_165e060Value<0x10c07>();
    }
    if (bufferSize < Unk_1659bf0_get() + Unk_1659730() + Unk_165ad50()) {
        return Unk_165e060Value<0x10c07>();
    }
    u32 written = 0;
    Unk_165e060 result(0);
    result = field_0.Unk_1659aa0(buffer, &written, bufferSize);
    if (result.m_Value != 0) {
        return result;
    }
    u8* p = buffer + written;
    bufferSize -= written;
    result = field_10.Unk_16585a0(p, &written, bufferSize);
    if (result.m_Value != 0) {
        return result;
    }
    p += written;
    bufferSize -= written;
    result = field_390.Unk_165a070(p, &written, bufferSize);
    if (result.m_Value != 0) {
        return result;
    }
    *size = p + written - buffer;
    return Unk_165e060Value<0>();
}

}  // namespace pia
}  // namespace nn
