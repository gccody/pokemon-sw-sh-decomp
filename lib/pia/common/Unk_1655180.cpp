// Scope: common
// common::MonitoringServerAddressResolveJob, the FixedString<256> it holds and
// the jobs' base, common::Job (Unk_1655760), as lib/pia/common/Unk_1654a80.h
// declares them.
#include "pia/common/Unk_1654a80.h"

namespace nn {
namespace pia {
namespace common {

// 0x7101655340
MonitoringServerAddressResolveJob::MonitoringServerAddressResolveJob()
    : field_88(nullptr), field_4b0(nullptr) {
    m_Name.vf3();
    m_Context.Unk_1655110();
}

// 0x7101655410
template <u32 N>
void FixedString<N>::vf3() {
    for (u32 i = 0; i < sizeof(m_Buffer); ++i) {
        m_Buffer[i] = '\0';
    }
    field_14 = 0;
    field_18 = 0;
}

// 0x7101655450 (and 0x7101655490, deleting)
MonitoringServerAddressResolveJob::~MonitoringServerAddressResolveJob() {
    Unk_1655170_update(reinterpret_cast<u64>(&m_Context));
}

// 0x71016554d0
void MonitoringServerAddressResolveJob::Unk_16554d0() {
    while (m_Context.m_State == 1) {
        Cancel(5);
    }
    m_Name.vf3();
    m_Context.Unk_1655110();
    field_88 = nullptr;
    field_4b0 = nullptr;
}

// 0x7101655570: FixedString<256>'s deleting destructor

// 0x7101655580: copies a string (1 UTF-8, 2 UTF-16) into the buffer
// NON_MATCHING: the copy loops are rotated differently: the original tests the
// first character before its loop and each later one at the loop's end.
template <u32 N>
Unk_165e060 FixedString<N>::vf5(const void* text, u32 length, u32 encoding) {
    if (text == nullptr || field_10 < length) {
        return Unk_165e060Value<0x10c07>();
    }
    if (encoding == 2) {
        if (field_10 / 4 * 2 < length) {
            return Unk_165e060Value<0x10c07>();
        }
    } else if (encoding == 1) {
        if (Unk_165c200(static_cast<const char*>(text), length) > field_10 / 4) {
            return Unk_165e060Value<0x10c07>();
        }
    } else {
        return Unk_165e060Value<0x10c07>();
    }
    for (u32 i = 0; i < field_10; i++) {
        m_Buffer[i] = '\0';
    }
    u32 size = 0;
    if (encoding == 1) {
        const char* src = static_cast<const char*>(text);
        u32 i = 0;
        while (i < field_10 && src[i] != '\0') {
            m_Buffer[i] = src[i];
            i++;
        }
        m_Buffer[i] = '\0';
        size = i;
    } else if (encoding == 2) {
        const u16* src = static_cast<const u16*>(text);
        u16* dst = reinterpret_cast<u16*>(m_Buffer);
        u32 i = 0;
        while (src[i] != 0 && i < field_10 / 4) {
            dst[i] = src[i];
            i++;
        }
        size = i * 2;
        m_Buffer[size] = '\0';
        m_Buffer[size + 1] = '\0';
    }
    field_14 = size;
    field_18 = encoding;
    return Unk_165e060Value<0>();
}

// 0x7101655760
// NON_MATCHING: the original stores field_8 and field_c separately (as it would
// atomic or volatile members), after the vtable; here they're paired.
Unk_1655760::Unk_1655760()
    : field_8(0), field_c(0), field_10(nullptr), field_18(nullptr), field_20(nullptr) {}

// 0x7101655790 (and 0x71016557d0, deleting: a trap, the class is abstract)
Unk_1655760::~Unk_1655760() {
    if (field_18 != nullptr && field_20 != nullptr) {
        Unk_1657ba0_type* scheduler = Unk_27fa890;
        if (scheduler != nullptr) {
            scheduler->Unk_1657ba0(this);
        }
    }
}

}  // namespace common
}  // namespace pia
}  // namespace nn
