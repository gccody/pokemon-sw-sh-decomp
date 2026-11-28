// Scope: common
// The Battle Tower's states on Unk_23bcdf0 (src/unsorted/unk_8bf520/Unk_8e9610.h):
// looking up the views they keep, the views' lookups it instantiates, and
// the state "statebattletowerout" (Unk_23bcec0): its vf7 and vf8, and with
// its vtable, its D0 and thunks. Its vf9 is in
// src/unsorted/virtual/Unk_8e4150.cpp. Placeholder names: rename once the
// classes are known.
#include <utility>

#include "contents/common/views.h"
#include "unsorted/unk_8bf520/Unk_8e9610.h"

// The names of the views (Unk_5cfad0_Literal, at their addresses).
extern const Unk_5cfad0_Literal Unk_23bcbf0;
extern const Unk_5cfad0_Literal Unk_23bcb28;
extern const Unk_5cfad0_Literal Unk_23bc830;
extern const Unk_5cfad0_Literal Unk_23bc848;

// The view the states keep in field_78 (vtable 0x71023bcc18; its type getter
// is in src/unsorted/types/Unk_8e8230.cpp).
class Unk_23bcc08 : public Unk_23f4660 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23f4660::Unk_GetType());
        return &type;
    }
};

// The view they keep in field_80 (vtable 0x71023bca28; its type getter is in
// src/unsorted/types/Unk_8e5040.cpp).
class Unk_23bca18 : public Unk_23f4660 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23f4660::Unk_GetType());
        return &type;
    }
};

// The view they keep in field_88 is a Unk_23f65d0: its lookup (0x71008e4900)
// is out of line, in another TU.
template <>
Unk_23f65d0* Unk_a7bb80_Views::Unk_a7bb80<Unk_23f65d0>(const Unk_5cfaf0_Name& name);
// The option bar's lookup (0x7100795bc0) is out of line too.
template <>
Unk_23f6118* Unk_a7bb80_Views::Unk_a7bb80<Unk_23f6118>(const Unk_5cfaf0_Name& name);

// tools/leafgen.py's placeholders.
bool Unk_eb6530(void* view);
void Unk_eb6230(void* view, u32 arg);
struct Unk_8e6f20;
void Unk_8e6f20_call(Unk_8e6f20* self);

// The state "statebattletowerout" (vtable 0x71023bced0).
class Unk_23bcec0 : public Unk_23bcdf0 {
public:
    void vf7() override;
    u32 vf8() override;
    void vf9() override;
};

// `ref` takes a reference to `view` (swapped in, its old one let go of).
template <class T>
static void Unk_SetView(Unk_239a418_Ref<Unk_239a418>& ref, T* view) {
    Unk_239a418_Ref<Unk_239a418> held(view);
    std::swap(ref.m_ptr, held.m_ptr);
}

// 0x71008e8f80
void Unk_23bcdf0::Unk_8e8f80() {
    Unk_a7bb80_Views* views = Unk_StateViews(this);
    Unk_SetView(field_78, views->Unk_a7bb80<Unk_23bcc08>(Unk_23bcbf0.Unk_5cfad0()));
    UNK_CHECK(field_78.m_ptr != nullptr);
    Unk_SetView(field_80, views->Unk_a7bb80<Unk_23bca18>(Unk_23bcb28.Unk_5cfad0()));
    UNK_CHECK(field_80.m_ptr != nullptr);
    Unk_SetView(field_88, views->Unk_a7bb80<Unk_23f65d0>(Unk_23bc830.Unk_5cfad0()));
    UNK_CHECK(field_88.m_ptr != nullptr);
    Unk_SetView(field_90, views->Unk_a7bb80<Unk_23f6118>(Unk_23bc848.Unk_5cfad0()));
    UNK_CHECK(field_90.m_ptr != nullptr);
}

// Unk_8e8f80 instantiates the lookups of contents/common/views.h for its
// first two views: 0x71008e9210 (Unk_a7bb80<Unk_23bcc08>) and 0x71008e9360
// (Unk_a7bb80<Unk_23bca18>).

// 0x71008e94b0; the vtable's D0 0x71008e9570 and thunks for +0x48
// (0x71008e9610 D1, 0x71008e96b0 D0) and +0x50 (0x71008e9750 D1,
// 0x71008e97f0 D0)
void Unk_23bcec0::vf7() {
    field_70 = Unk_d0c0_String("statebattletowerout");
    Unk_8e8f80();
    Unk_eb6230(field_78.m_ptr, 1);
    Unk_8e6f20_call(reinterpret_cast<Unk_8e6f20*>(field_80.m_ptr));
    Unk_eb77f0(static_cast<Unk_23f6118*>(field_90.m_ptr));
}

// 0x71008e9520
// NON_MATCHING: Unk_eb7830 is declared bool (framework.h) and vf8 u32, so the
// result is masked (and w0, #1) where the original tail-calls it.
u32 Unk_23bcec0::vf8() {
    if (Unk_eb6530(field_78.m_ptr))
        return 0;
    return Unk_eb7830(static_cast<Unk_23f6118*>(field_90.m_ptr));
}
