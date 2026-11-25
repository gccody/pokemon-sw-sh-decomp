// Scope: common
// The Battle Tower's view Unk_23bcc08 (src/unsorted/unk_8bf520/Unk_8e7dd0.h):
// its destructors, the slots that show it, what it shows for a selection and
// the callable its selection calls. Placeholder names: rename once the class
// is known.
#include <algorithm>
#include <new>
#include <utility>

#include "unsorted/unk_8bf520/Unk_8e7dd0.h"

struct Unk_14abe00_Parts;
void Unk_14ac370(Unk_14abe00_Parts* self, u64 key, u32 arg);
void Unk_1315b90(void* self, u64 arg1, u64 arg2, u32 arg3, u32 arg4, u32 arg5);
u64 Unk_e7f7c0_get(const struct Unk_e7f7c0* self);
void Unk_e806b0(Unk_23f4660* view, bool visible, bool children);
void Unk_e80580(u64 view, u32 arg1, u32 arg2);

// The parts the view's layout member (field_100) keeps at its +0x1b0.
class Unk_8e7dd0_Parts : public Unk_239a418 {
public:
    u8 _60[0x2e0 - 0x60];
    Unk_239a418_Ref<Unk_239a418> field_2e0;
    Unk_239a418_Ref<Unk_239a418> field_2e8;
};
PKMN_OFFSET_ASSERT(Unk_8e7dd0_Parts, field_2e0, 0x2e0);
PKMN_OFFSET_ASSERT(Unk_8e7dd0_Parts, field_2e8, 0x2e8);

inline Unk_239a418_Ref<Unk_8e7dd0_Parts>& Unk_8e7dd0_GetParts(Unk_23bcc08* view) {
    return *reinterpret_cast<Unk_239a418_Ref<Unk_8e7dd0_Parts>*>(view->field_100._8 + 0x1a8);
}

// What Unk_e7eb10 finds by index: what it holds at +0x60.
class Unk_8e7dd0_Entry : public Unk_239a418 {
public:
    Unk_239a418_Ref<Unk_239a418> field_60;
};
PKMN_OFFSET_ASSERT(Unk_8e7dd0_Entry, field_60, 0x60);

Unk_239a418_Ref<Unk_8e7dd0_Entry> Unk_e7eb10(u64 self, u32 index);
void Unk_67d450(Unk_239a418* object, u64* arg1, Unk_239a418* arg2);

// What Unk_e83e60 finds in a view's layout member by hash: its +0xf8, a name
// and a callable.
class Unk_8e7f30_Entry {
public:
    u8 _0[0xf8];
    u64 field_f8;
    u8 _100[0x20];
    u64 field_120;
    const char* field_128;
    u64 field_130;
    Unk_239a418_Ref<Unk_239a418> field_138;
    u8 _140[0x10];
    Unk_23bcc08_Callable field_150;
};
PKMN_OFFSET_ASSERT(Unk_8e7f30_Entry, field_f8, 0xf8);
PKMN_OFFSET_ASSERT(Unk_8e7f30_Entry, field_120, 0x120);
PKMN_OFFSET_ASSERT(Unk_8e7f30_Entry, field_138, 0x138);
PKMN_OFFSET_ASSERT(Unk_8e7f30_Entry, field_150, 0x150);

Unk_8e7f30_Entry* Unk_e83e60(Unk_23f4760* self, const u64& key);

// "Unk_23bcd08": a name of 21 characters.
extern const Unk_5cfad0_Literal Unk_23bcd08 __attribute__((visibility("hidden")));

// The callable's other functions (src/unsorted/leaf/Unk_8e6770.cpp).
struct Unk_8e85c0;
struct Unk_8e85d0;
void Unk_8e8560(Unk_23bcc08_Closure* closure) __attribute__((visibility("hidden")));
void Unk_8e85b0_update() __attribute__((visibility("hidden")));
void Unk_8e85c0_set(const Unk_8e85c0* self, Unk_8e85c0* value)
    __attribute__((visibility("hidden")));
void Unk_8e85d0_set(const Unk_8e85d0* self, Unk_8e85d0* value)
    __attribute__((visibility("hidden")));

// 0x71008e7dd0
// NON_MATCHING: Unk_1315b90's name (_Z11Unk_1315b90Pvmmjjj) gives its second
// and third parameters as u64: the original passes u32s (mov w1, wzr; the
// callee reads w1 and w2), and the value's register differs. Declared with
// u32s, this matches.
void Unk_23bcc08::Unk_8e7dd0(u32 value) {
    Unk_239a418_Ref<Unk_8e7dd0_Parts> parts = Unk_8e7dd0_GetParts(this);
    Unk_239a418_Ref<Unk_239a418> a = parts.m_ptr->field_2e8;
    Unk_239a418_Ref<Unk_239a418> b = parts.m_ptr->field_2e0;
    {
        Unk_239a418_Ref<Unk_239a418> object;
        {
            Unk_239a418_Ref<Unk_8e7dd0_Entry> entry =
                Unk_e7eb10(Unk_e7f7c0_get(reinterpret_cast<const Unk_e7f7c0*>(this)), field_5e0);
            if (entry.m_ptr)
                object = Unk_239a418_Ref<Unk_239a418>(entry.m_ptr->field_60);
        }
        Unk_67d450(object.m_ptr, &field_690, a.m_ptr);
    }
    Unk_1315b90(b.m_ptr, 0, value, 7, 1, 1);
    static const u64 hash = 0x19c81756d1db1c35;
    Unk_14ac370(reinterpret_cast<Unk_14abe00_Parts*>(parts.m_ptr), reinterpret_cast<u64>(&hash),
                10);
}

// 0x71008e7f30
// NON_MATCHING: the original keeps the callable's and its storage's addresses
// in registers (x24, x23) across the dispose call and stores the closure
// before the four functions; this folds them into the entry's offsets and
// pairs the stores in another order.
void Unk_23bcc08::Unk_8e7f30(const u64& key, u32 value, const u64& arg) {
    Unk_8e7f30_Entry* entry = Unk_e83e60(&field_100, key);
    if (entry == nullptr)
        return;
    entry->field_150.Set(Unk_23bcc08_Closure{this, value}, &Unk_8e8560, &Unk_8e85b0_update,
                         &Unk_8e85c0_set, &Unk_8e85d0_set);
    entry->field_f8 = arg;
    if (arg == 0x2000000000000) {
        Unk_5cfaf0_Name name = Unk_23bcd08.Unk_5cfad0();
        entry->field_120 = name.field_0;
        entry->field_128 = name.field_8;
        entry->field_130 = name.field_10;
        Unk_239a418_Ref<Unk_239a418> held(reinterpret_cast<Unk_239a418*>(name.field_18));
        std::swap(entry->field_138.m_ptr, held.m_ptr);
    }
}

// 0x71008e8060
void Unk_8e8060(Unk_23bcc08* self, u32 state) {
    switch (state) {
        case 0:
            Unk_e806b0(self, true, true);
            break;
        case 1:
            Unk_e80580(reinterpret_cast<u64>(self), 0, 1);
            break;
        case 2:
            Unk_e806b0(self, true, true);
            break;
        case 3:
            Unk_e80580(reinterpret_cast<u64>(self), 0, 1);
            break;
    }
}

// 0x71008e80a0
void Unk_8e80a0(Unk_23bcc08* self, u32 state) {
    switch (state) {
        case 0:
            Unk_e80580(reinterpret_cast<u64>(self), 1, 1);
            break;
        case 1:
            Unk_e806b0(self, false, true);
            break;
        case 2:
            Unk_e80580(reinterpret_cast<u64>(self), 1, 1);
            break;
        case 3:
            Unk_e806b0(self, false, true);
            break;
    }
}

// 0x71008e8120; its D0 0x71008e8220 and thunks for +0x48 (0x71008e8240 D1,
// 0x71008e8250 D0) and +0x50 (0x71008e8280 D1, 0x71008e8290 D0)
Unk_23bcc08::~Unk_23bcc08() {}

// What the selection's callable gets: the selection and its kind.
struct Unk_8e83d0_Args {
    u32 field_0;
    u32 field_4;
};

void Unk_14d9790(u64 self, u32 arg1, u32 arg2, u32 arg3, u32 arg4);

// 0x71008e83d0
// NON_MATCHING: the two comparisons' results are and-ed in the other order
// (and w9, w10, w9 in the original).
void Unk_8e83d0(Unk_23bcc08** closure, const Unk_8e83d0_Args* args) {
    Unk_23bcc08* self = *closure;
    if (self->field_6e0.field_0 == nullptr)
        return;
    Unk_8e83d0_Args a = *args;
    self->field_6a8 = a.field_0 == 0 && a.field_4 == 1;
    self->field_6e0(self->field_6a8);
    if (self->field_698 == nullptr)
        return;
    const Unk_23bcc08_Count& count =
        self->field_6a8 == 0 ? self->field_698->field_0 : self->field_698->field_10;
    u32 value = count.field_0 + 1;
    f32 ratio = static_cast<f32>(count.field_8) / static_cast<f32>(std::max(count.field_4, 1));
    Unk_14d9790(reinterpret_cast<u64>(self->field_760.m_ptr), value,
                static_cast<u32>(std::clamp(ratio, 0.0f, 1.0f) * 100.0f), 0, 1);
    self->Unk_8e7dd0(count.field_c);
}
