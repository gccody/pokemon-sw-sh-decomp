// Scope: common
// The round-trip time entry's members (lib/pia/common/Unk_1748ae0.h), the
// setters of the two timeouts Unk_1748de0 compares with, and
// transport::SequenceIdController's constructor and destructors
// (lib/pia/common/Unk_1749070.h; its other members are in
// lib/pia/common/Unk_1749070.cpp). 0x7101748ae0, 0x7101748d10-0x7101748d40
// and 0x7101748e60 are leaves (lib/nx_middleware/leaf/Unk_1721740.cpp).
#include "pia/common/Unk_1748ae0.h"
#include "pia/common/Unk_1749070.h"

// std::sort(int*, int*) as libc++ 7.0.1's <algorithm> writes it: a call of
// the __sort instance libc++ builds (an extern template, an import of the
// executable). lib/pia's settings don't put include/libcxx on its include
// path, so this is the part of <algorithm> the sort below uses.
namespace std {
inline namespace __1 {
template <class T1, class T2 = T1>
struct __less {
    bool operator()(const T1& x, const T2& y) const { return x < y; }
};
template <class Compare, class RandomAccessIterator>
void __sort(RandomAccessIterator first, RandomAccessIterator last, Compare comp);
extern template void __sort<__less<int>&, int*>(int*, int*, __less<int>&);
template <class T>
inline void sort(T* first, T* last) {
    __less<T> comp;
    __sort<__less<T>&>(first, last, comp);
}
}  // namespace __1
}  // namespace std

// What Unk_27fc2d8 points to: its first word is the current tick
// (lib/pia/common/Unk_174aea0.h has the rest).
struct Unk_174de50 {
    s64 field_0;
};
extern Unk_174de50* Unk_27fc2d8;

const s64* Unk_165c6b0();  // the ticks in a millisecond

// The timeouts, in milliseconds, before and after the ring is full.
extern s64 Unk_2460c18;
extern s64 Unk_2460c20;

// 0x7101748af0
s32 Unk_1748ab0::Unk_1748af0() {
    return Unk_1748c00(9);
}

// 0x7101748c00
s32 Unk_1748ab0::Unk_1748c00(u32 count) {
    if (!field_0 || field_1c.count == 0) {
        return -1;
    }
    if (field_48 == count) {
        return field_4c;
    }
    u32 n = field_1c.count < count ? field_1c.count : count;
    s32 samples[9];
    for (u32 i = 0; i < n; ++i) {
        samples[i] = field_1c.At(field_1c.count - 1 - i);
    }
    std::sort(samples, samples + n);
    s32 middle = n / 2;
    s32 median;
    if (n % 2 == 0) {
        median = (samples[middle - 1] + samples[middle]) / 2;
    } else {
        median = samples[middle];
    }
    field_48 = count;
    field_4c = median;
    return median;
}

// 0x7101748d60
void Unk_1748ab0::Unk_1748d60() {
    if (field_0) {
        return;
    }
    field_0 = true;
    field_4 = -1;
    field_8 = -1;
    field_10 = 0;
    field_18 = false;
    field_48 = 0;
    field_4c = 0;
    field_1c.Clear();
    field_c = -1;
    field_50 = 0;
}

// 0x7101748da0
void Unk_1748ab0::Unk_1748da0() {
    if (!field_0) {
        return;
    }
    field_0 = false;
    field_4 = -1;
    field_8 = -1;
    field_10 = 0;
    field_18 = false;
    field_48 = 0;
    field_4c = 0;
    field_1c.Clear();
    field_c = -1;
    field_50 = 0;
}

// 0x7101748de0
bool Unk_1748ab0::Unk_1748de0() {
    if (!field_18) {
        return true;
    }
    s64 timeout = field_1c.count == 9 ? Unk_2460c18 : Unk_2460c20;
    return (Unk_27fc2d8->field_0 - field_10) / *Unk_165c6b0() >= timeout;
}

// 0x7101748e80
void Unk_1748ab0::Unk_1748e80(s32 sample) {
    field_4 = sample;
    field_48 = 0;
    field_4c = 0;
    field_1c.Push(sample);
    ++field_50;
    if (field_8 == -1 || field_8 > sample) {
        field_8 = sample;
    }
    if (field_c == -1 || field_c < sample) {
        field_c = sample;
    }
}

// 0x7101748f30
nn::pia::Unk_165e060 Unk_1748f30(s64 timeout) {
    if (timeout <= 0) {
        return nn::pia::Unk_165e060Value<0x10c07>();
    }
    Unk_2460c18 = timeout;
    return nn::pia::Unk_165e060Value<0>();
}

// 0x7101748fb0
nn::pia::Unk_165e060 Unk_1748fb0(s64 timeout) {
    if (timeout <= 0) {
        return nn::pia::Unk_165e060Value<0x10c07>();
    }
    Unk_2460c20 = timeout;
    return nn::pia::Unk_165e060Value<0>();
}

namespace nn {
namespace pia {
namespace transport {

// 0x7101749030
SequenceIdController::SequenceIdController()
    : field_8(0), field_a(0), field_c(0), field_e(0), field_10(0), field_12(false), field_14(0), field_18(0) {}

// 0x7101749050 (and 0x7101749060, deleting)
SequenceIdController::~SequenceIdController() {}

}  // namespace transport
}  // namespace pia
}  // namespace nn
