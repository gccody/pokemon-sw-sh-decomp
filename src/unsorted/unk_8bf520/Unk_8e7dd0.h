#pragma once
// The view the Battle Tower's states keep in field_78 (Unk_23bcc08, vtable
// 0x71023bcc18, named "Unk_23bcbf0" in src/unsorted/unk_8bf520/Unk_8e8e50.cpp):
// a view (Unk_23f4660) with what it shows, the references it keeps and a
// callable it calls with the selection. Its type getter and vf_type are in
// src/unsorted/types/Unk_8e8230.cpp. Placeholder names: rename once the class
// is known.
#include <types.h>

#include "unsorted/Unk_23f4660.h"

// A callable, 0x80 bytes, as Unk_23d4470_Callable (src/unsorted/Unk_23d4470.h):
// an invoker (+0x0) that takes the storage (+0x20) and the arguments, what
// disposes of it (+0x8), what copies it (+0x10) and what moves it (+0x18).
class Unk_23bcc08_Callable {
public:
    using Invoke = void (*)(void* storage, void* args);
    using Dispose = void (*)(void* storage);
    using Copy = void (*)(const void* from, void* to);

    ~Unk_23bcc08_Callable() { Reset(); }

    void Reset() {
        if (Dispose dispose = field_8) {
            field_18 = nullptr;
            field_10 = nullptr;
            field_8 = nullptr;
            field_0 = nullptr;
            dispose(field_20);
        }
    }

    // Holds a callable that captures a pointer and a u32.
    template <class A, class B, class C, class D>
    void Set(void* captured, u32 value, A invoke, B dispose, C copy, D move) {
        Reset();
        *reinterpret_cast<void**>(field_20) = captured;
        *reinterpret_cast<u32*>(field_20 + 8) = value;
        field_0 = reinterpret_cast<Invoke>(invoke);
        field_8 = reinterpret_cast<Dispose>(dispose);
        field_10 = reinterpret_cast<Copy>(copy);
        field_18 = reinterpret_cast<Copy>(move);
    }

    Invoke field_0;
    Dispose field_8;
    Copy field_10;
    Copy field_18;
    alignas(16) u8 field_20[0x60];
};
static_assert(sizeof(Unk_23bcc08_Callable) == 0x80, "Unk_23bcc08_Callable");

// One of the four modes (the selected one goes to Unk_23bcb40's field_60), or
// none.
struct Unk_23bcc08_Mode {
    bool field_0;
    u32 field_4;
};
static_assert(sizeof(Unk_23bcc08_Mode) == 0x8, "Unk_23bcc08_Mode");

inline Unk_23bcc08_Mode Unk_23bcc08_ToMode(u32 value) {
    if (value < 4)
        return {true, value};
    return {false, 0};
}

// What was selected: the selection and its mode.
struct Unk_23bcc08_Result {
    u32 field_0;
    Unk_23bcc08_Mode field_4;
};
static_assert(sizeof(Unk_23bcc08_Result) == 0xc, "Unk_23bcc08_Result");

// A result, or none yet (the flag first).
class Unk_23bcc08_Optional {
public:
    ~Unk_23bcc08_Optional() { Reset(); }

    void Reset() {
        if (field_0)
            field_0 = false;
    }

    Unk_23bcc08_Optional& operator=(const Unk_23bcc08_Result& value) {
        field_4 = value;
        if (!field_0)
            field_0 = true;
        return *this;
    }

    bool field_0;
    Unk_23bcc08_Result field_4;
};
static_assert(sizeof(Unk_23bcc08_Optional) == 0x10, "Unk_23bcc08_Optional");

// A count it shows (field_698 points to two): field_8 of field_4, as a gauge.
struct Unk_23bcc08_Count {
    u32 field_0;
    s32 field_4;
    s32 field_8;
    u32 field_c;
};
static_assert(sizeof(Unk_23bcc08_Count) == 0x10, "Unk_23bcc08_Count");

struct Unk_23bcc08_Counts {
    Unk_23bcc08_Count field_0;
    Unk_23bcc08_Count field_10;
};

class Unk_23bcc08 : public Unk_23f4660 {
public:
    ~Unk_23bcc08() override;
    const Unk_239a418_Type* vf_type() override;

    // 0x71008e7c70, not decompiled.
    void Unk_8e7c70();
    void Unk_8e7dd0(u32 value);
    void Unk_8e7f30(const u64& key, u32 value, const u64& arg);
    // 0x71008e7080, not decompiled: shows the mode.
    void Unk_8e7080(u32 mode);

    u8 _5cb;
    Unk_23bcc08_Optional field_5cc;
    u8 _5dc[4];
    u32 field_5e0;
    u8 _5e4[0x690 - 0x5e4];
    u64 field_690;
    Unk_23bcc08_Counts* field_698;
    Unk_239a418_Ref<Unk_239a418> field_6a0;
    u32 field_6a8;
    u8 _6ac[0x6b8 - 0x6ac];
    Unk_239a418_Ref<Unk_239a418> field_6b8;
    Unk_239a418_Ref<Unk_239a418> field_6c0;
    Unk_239a418_Ref<Unk_239a418> field_6c8;
    Unk_239a418_Ref<Unk_239a418> field_6d0;
    u8 _6d8[8];
    Unk_23bcc08_Callable field_6e0;
    Unk_239a418_Ref<Unk_239a418> field_760;
};
PKMN_OFFSET_ASSERT(Unk_23bcc08, field_5cc, 0x5cc);
PKMN_OFFSET_ASSERT(Unk_23bcc08, field_5e0, 0x5e0);
PKMN_OFFSET_ASSERT(Unk_23bcc08, field_690, 0x690);
PKMN_OFFSET_ASSERT(Unk_23bcc08, field_6a0, 0x6a0);
PKMN_OFFSET_ASSERT(Unk_23bcc08, field_6a8, 0x6a8);
PKMN_OFFSET_ASSERT(Unk_23bcc08, field_6b8, 0x6b8);
PKMN_OFFSET_ASSERT(Unk_23bcc08, field_6d0, 0x6d0);
PKMN_OFFSET_ASSERT(Unk_23bcc08, field_6e0, 0x6e0);
PKMN_OFFSET_ASSERT(Unk_23bcc08, field_760, 0x760);

// What its callables capture: the view and a value.
struct Unk_23bcc08_Closure {
    Unk_23bcc08* field_0;
    u32 field_8;
};

// The callables' invokers (their other functions are in
// src/unsorted/leaf/Unk_8e6770.cpp).
void Unk_8e84d0(Unk_23bcc08_Closure* closure);
void Unk_8e8560(Unk_23bcc08_Closure* closure);
void Unk_8e85e0(Unk_23bcc08_Closure* closure);
