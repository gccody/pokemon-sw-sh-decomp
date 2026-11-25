// Scope: common
// The rest of Unk_23a7b38's accessors (src/unsorted/unk_761f70/Unk_7814e0.h):
// fields of the root table of its holder's data.
#include <algorithm>

#include "unsorted/unk_761f70/Unk_7814e0.h"

// 0x7100781ac0
u8 Unk_23a7b38::Unk_781ac0() const {
    return Unk_Root()->Get<u8>(24, 0);
}

// 0x7100781b20
u8 Unk_23a7b38::Unk_781b20() const {
    return Unk_Root()->Get<u8>(40, 0);
}

// 0x7100781b80
u16 Unk_23a7b38::Unk_781b80() const {
    return Unk_Root()->Get<u16>(28, 0);
}

// 0x7100781be0
u8 Unk_23a7b38::Unk_781be0() const {
    return Unk_Root()->Get<u8>(30, 0);
}

// 0x7100781c40
u32 Unk_23a7b38::Unk_781c40() const {
    return Unk_Root()->Get<u8>(32, 0);
}

// 0x7100781ca0
u8 Unk_23a7b38::Unk_781ca0() const {
    return Unk_Root()->Get<u8>(36, 0);
}

// 0x7100781d00
u8 Unk_23a7b38::Unk_781d00() const {
    return Unk_Root()->Get<u8>(34, 0);
}

// 0x7100781d60
u16 Unk_23a7b38::Unk_781d60() const {
    return Unk_Root()->Get<u16>(42, 0);
}

// 0x7100781dc0
u32 Unk_23a7b38::Unk_781dc0(u8 kind) const {
    switch (kind) {
        case 0:
            return Unk_Root()->Get<u8>(50, 0);
        case 1:
            return Unk_Root()->Get<u8>(52, 0);
        case 2:
            return Unk_Root()->Get<u8>(54, 0);
    }
    return 0;
}

// 0x7100781ee0
s32 Unk_23a7b38::Unk_781ee0(u8 kind) const {
    switch (kind) {
        case 0:
            return Unk_Root()->Get<s8>(56, 0);
        case 1:
            return Unk_Root()->Get<s8>(58, 0);
        case 2:
            return Unk_Root()->Get<s8>(60, 0);
    }
    return 0;
}

// 0x7100782000
u8 Unk_23a7b38::Unk_782000(u8 kind) const {
    switch (kind) {
        case 0:
            return Unk_Root()->Get<u8>(62, 0);
        case 1:
            return Unk_Root()->Get<u8>(64, 0);
        case 2:
            return Unk_Root()->Get<u8>(66, 0);
    }
    return 0;
}

// 0x7100782120
u32 Unk_23a7b38::Unk_782120() const {
    return Unk_Root()->Get<u8>(68, 0);
}

// 0x7100782180: the field's value when it's positive, 0 otherwise.
// NON_MATCHING: the original shares one `return 0` between the two absent-field
// paths; this has one each (the rest is the same, the and #0xff included).
s32 Unk_23a7b38::Unk_782180() const {
    s8 value = Unk_Root()->Get<s8>(44, 0);
    return std::max<s8>(value, 0);
}

// 0x71007821e0: its magnitude when it's negative, 0 otherwise.
s32 Unk_23a7b38::Unk_7821e0() const {
    s8 value = Unk_Root()->Get<s8>(44, 0);
    return value < 0 ? -value : 0;
}

// 0x7100782240: the field's value when it's positive, 0 otherwise.
// NON_MATCHING: the original shares one `return 0` between the two absent-field
// paths; this has one each (the rest is the same, the and #0xff included).
s32 Unk_23a7b38::Unk_782240() const {
    s8 value = Unk_Root()->Get<s8>(46, 0);
    return std::max<s8>(value, 0);
}

// 0x71007822a0
s32 Unk_23a7b38::Unk_7822a0() const {
    s8 value = Unk_Root()->Get<s8>(46, 0);
    return value < 0 ? -value : 0;
}
