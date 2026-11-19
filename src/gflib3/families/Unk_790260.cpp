// Scope: common
//
// The creators of an owner (Unk_790260_Owner, placeholder): each makes a class
// on Unk_23f4660 (src/unsorted/Unk_23f4660.h) with the owner's allocator,
// sets its parent, keeps a reference to it and returns one. One template, an
// instance per class; the classes are named after their vtables, their
// members are what the creators store after Unk_23f4660's constructor.
// Written by tools/familygen.py: regenerate, don't edit.
#include <nn/os.h>

#include "gflib3/Unk_New.h"
#include "unsorted/Unk_23f4660.h"
#include "unsorted/Unk_2771620.h"

using Unk_Ref = Unk_239a418_Ref<Unk_239a418>;

// The element of the owner's vector (its push_back's slow path is
// 0x7100790490, in Unk_5ac520.cpp).
struct Unk_790490 : Unk_239a418 {};

class Unk_790260_Owner {
public:
    template <class T>
    Unk_239a418_Ref<T> Create(const Unk_Ref& parent, u64 a2);

    u64 field_0;
    Unk_239a418_Allocator* field_8;
    u8 _10[0x68];
    std::vector<Unk_239a418_Ref<Unk_790490>, Unk_2771620_Allocator<Unk_239a418_Ref<Unk_790490>>>
        field_78;
    u64 field_a8;
    u8 _b0[0x10];
    bool field_c0;
};
PKMN_OFFSET_ASSERT(Unk_790260_Owner, field_78, 0x78);
PKMN_OFFSET_ASSERT(Unk_790260_Owner, field_a8, 0xa8);
PKMN_OFFSET_ASSERT(Unk_790260_Owner, field_c0, 0xc0);

template <class T>
Unk_239a418_Ref<T> Unk_790260_Owner::Create(const Unk_Ref& parent, u64 a2) {
    if (!parent.m_ptr)
        nn::diag::detail::AbortImpl("", "", "", 0);
    Unk_239a418_Ref<T> result(Unk_New().Create<T>(field_8, this, a2, u64(field_a8)));
    // Through the result, not the new object: clang then computes the
    // object's interface again for the vector's reference, as the original does.
    result.m_ptr->Unk_e7fe20(parent);
    field_78.push_back(Unk_239a418_Ref<Unk_790490>(
        static_cast<Unk_790490*>(static_cast<Unk_239a418*>(result.m_ptr))));
    field_c0 = false;
    return result;
}

// 0x7100790260
class alignas(16) Unk_23f5fa8 : public Unk_23f4660 {
public:
    using Unk_23f4660::Unk_23f4660;
    ~Unk_23f5fa8() override;

    u8 field_5cb;
    u32 field_5cc;
    u64 field_5d0 = 0;
    u64 field_5d8 = 0;
    u8 field_5e0 = 0;
    u8 field_5e1;
    u16 field_5e2;
    u32 field_5e4;
    u64 field_5e8;
};
static_assert(sizeof(Unk_23f5fa8) == 0x5f0, "Unk_23f5fa8");
template Unk_239a418_Ref<Unk_23f5fa8> Unk_790260_Owner::Create<Unk_23f5fa8>(const Unk_Ref& parent,
                                                                            u64 a2);

// 0x710079a540
class alignas(16) Unk_23a99d8 : public Unk_23f4660 {
public:
    using Unk_23f4660::Unk_23f4660;
    ~Unk_23a99d8() override;

    u8 field_5cb;
    u32 field_5cc;
    u64 field_5d0 = 0;
    u64 field_5d8 = 0;
    u64 field_5e0 = 0;
    u64 field_5e8 = 0;
    u64 field_5f0 = 0;
    u64 field_5f8 = 0;
    u64 field_600 = 0;
    u64 field_608 = 0;
    u64 field_610 = 0;
    u32 field_618 = 0x2;
};
static_assert(sizeof(Unk_23a99d8) == 0x620, "Unk_23a99d8");
template Unk_239a418_Ref<Unk_23a99d8> Unk_790260_Owner::Create<Unk_23a99d8>(const Unk_Ref& parent,
                                                                            u64 a2);

// 0x710079a8b0
class alignas(16) Unk_23a9048 : public Unk_23f4660 {
public:
    using Unk_23f4660::Unk_23f4660;
    ~Unk_23a9048() override;

    u8 field_5cb;
    u32 field_5cc;
    u64 field_5d0 = 0;
    u64 field_5d8 = 0;
    u64 field_5e0 = 0;
    u64 field_5e8 = 0;
    u64 field_5f0 = 0;
    u64 field_5f8 = 0;
    u64 field_600 = 0;
    u64 field_608 = 0;
    u64 field_610 = 0;
    u64 field_618 = 0;
    u64 field_620 = 0;
    u64 field_628 = 0;
    u32 field_630 = 0x2;
    u32 field_634;
    u64 field_638 = 0;
    u64 field_640 = 0;
    u32 field_648 = 0;
};
static_assert(sizeof(Unk_23a9048) == 0x650, "Unk_23a9048");
template Unk_239a418_Ref<Unk_23a9048> Unk_790260_Owner::Create<Unk_23a9048>(const Unk_Ref& parent,
                                                                            u64 a2);

// 0x710079b020
class alignas(16) Unk_23a8f48 : public Unk_23f4660 {
public:
    using Unk_23f4660::Unk_23f4660;
    ~Unk_23a8f48() override;

    u8 field_5cb;
};
static_assert(sizeof(Unk_23a8f48) == 0x5d0, "Unk_23a8f48");
template Unk_239a418_Ref<Unk_23a8f48> Unk_790260_Owner::Create<Unk_23a8f48>(const Unk_Ref& parent,
                                                                            u64 a2);

// 0x710079b370
class alignas(16) Unk_23f6118 : public Unk_23f4660 {
public:
    using Unk_23f4660::Unk_23f4660;
    ~Unk_23f6118() override;

    u8 field_5cb;
    u32 field_5cc;
    u64 field_5d0 = 0;
    u64 field_5d8;
};
static_assert(sizeof(Unk_23f6118) == 0x5e0, "Unk_23f6118");
template Unk_239a418_Ref<Unk_23f6118> Unk_790260_Owner::Create<Unk_23f6118>(const Unk_Ref& parent,
                                                                            u64 a2);

// 0x71008d3560
class alignas(16) Unk_23bbb80 : public Unk_23f4660 {
public:
    using Unk_23f4660::Unk_23f4660;
    ~Unk_23bbb80() override;

    u8 field_5cb;
    u32 field_5cc;
    u64 field_5d0 = 0;
    u8 field_5d8 = 0;
    u8 field_5d9;
    u16 field_5da = 0xffff;
};
static_assert(sizeof(Unk_23bbb80) == 0x5e0, "Unk_23bbb80");
template Unk_239a418_Ref<Unk_23bbb80> Unk_790260_Owner::Create<Unk_23bbb80>(const Unk_Ref& parent,
                                                                            u64 a2);

// 0x7100910950
class alignas(16) Unk_23be058 : public Unk_23f4660 {
public:
    using Unk_23f4660::Unk_23f4660;
    ~Unk_23be058() override;

    u8 field_5cb;
    u32 field_5cc;
    u64 field_5d0 = 0;
    u64 field_5d8 = 0;
    u64 field_5e0 = 0;
    u64 field_5e8 = 0;
    u8 field_5f0 = 0;
    u8 field_5f1;
    u16 field_5f2;
    u32 field_5f4 = 0xffffffff;
    u64 field_5f8 = 0;
};
static_assert(sizeof(Unk_23be058) == 0x600, "Unk_23be058");
template Unk_239a418_Ref<Unk_23be058> Unk_790260_Owner::Create<Unk_23be058>(const Unk_Ref& parent,
                                                                            u64 a2);

// 0x7100910cc0
class alignas(16) Unk_23bd4b8 : public Unk_23f4660 {
public:
    using Unk_23f4660::Unk_23f4660;
    ~Unk_23bd4b8() override;

    u8 field_5cb = 0;
};
static_assert(sizeof(Unk_23bd4b8) == 0x5d0, "Unk_23bd4b8");
template Unk_239a418_Ref<Unk_23bd4b8> Unk_790260_Owner::Create<Unk_23bd4b8>(const Unk_Ref& parent,
                                                                            u64 a2);

// 0x7100911900
class alignas(16) Unk_23be4d0 : public Unk_23f4660 {
public:
    using Unk_23f4660::Unk_23f4660;
    ~Unk_23be4d0() override;

    u8 field_5cb;
};
static_assert(sizeof(Unk_23be4d0) == 0x5d0, "Unk_23be4d0");
template Unk_239a418_Ref<Unk_23be4d0> Unk_790260_Owner::Create<Unk_23be4d0>(const Unk_Ref& parent,
                                                                            u64 a2);

// 0x7100911c50
class alignas(16) Unk_23bee08 : public Unk_23f4660 {
public:
    using Unk_23f4660::Unk_23f4660;
    ~Unk_23bee08() override;

    u8 field_5cb;
    u32 field_5cc = 0;
    u64 field_5d0 = 0;
    u32 field_5d8 = 0;
    u32 field_5dc;
    u32 field_5e0 = 0;
    u32 field_5e4;
    u64 field_5e8 = 0;
    u64 field_5f0 = 0;
    u64 field_5f8 = 0;
    u32 field_600 = 0;
    u32 field_604;
    u64 field_608 = 0;
    u64 field_610 = 0;
    u64 field_618 = 0;
    u32 field_620 = 0;
    u32 field_624;
    u64 field_628 = 0;
    u64 field_630 = 0;
    u64 field_638 = 0;
};
static_assert(sizeof(Unk_23bee08) == 0x640, "Unk_23bee08");
template Unk_239a418_Ref<Unk_23bee08> Unk_790260_Owner::Create<Unk_23bee08>(const Unk_Ref& parent,
                                                                            u64 a2);

// 0x7100913280
class alignas(16) Unk_23bd6b8 : public Unk_23f4660 {
public:
    using Unk_23f4660::Unk_23f4660;
    ~Unk_23bd6b8() override;

    u8 field_5cb;
    u32 field_5cc;
    u64 field_5d0 = 0;
    u64 field_5d8 = 0;
    u64 field_5e0 = 0;
    u64 field_5e8 = 0;
    u64 field_5f0 = 0;
    u64 field_5f8 = 0;
    u64 field_600;
    u64 field_608;
    u64 field_610;
    u64 field_618;
    u64 field_620;
    u64 field_628;
    u64 field_630;
    u64 field_638;
    u64 field_640;
    u64 field_648;
    u64 field_650;
    u64 field_658;
    u64 field_660 = 0;
    u64 field_668 = 0;
    u64 field_670 = 0;
    u64 field_678 = 0;
    u64 field_680 = 0;
    u64 field_688 = 0;
    u64 field_690 = 0;
    u64 field_698 = 0;
    u64 field_6a0 = 0;
    u64 field_6a8 = 0;
    u64 field_6b0 = 0;
    u64 field_6b8 = 0;
    u64 field_6c0 = 0;
    u64 field_6c8 = 0;
    u64 field_6d0 = 0;
    u64 field_6d8 = 0;
    u64 field_6e0 = 0;
    u64 field_6e8 = 0;
    u64 field_6f0 = 0;
    u64 field_6f8 = 0;
    u64 field_700 = 0;
    u64 field_708 = 0;
    u64 field_710 = 0;
    u64 field_718;
};
static_assert(sizeof(Unk_23bd6b8) == 0x720, "Unk_23bd6b8");
template Unk_239a418_Ref<Unk_23bd6b8> Unk_790260_Owner::Create<Unk_23bd6b8>(const Unk_Ref& parent,
                                                                            u64 a2);

// 0x7100913640
class alignas(16) Unk_23bd5b8 : public Unk_23f4660 {
public:
    using Unk_23f4660::Unk_23f4660;
    ~Unk_23bd5b8() override;

    u8 field_5cb;
};
static_assert(sizeof(Unk_23bd5b8) == 0x5d0, "Unk_23bd5b8");
template Unk_239a418_Ref<Unk_23bd5b8> Unk_790260_Owner::Create<Unk_23bd5b8>(const Unk_Ref& parent,
                                                                            u64 a2);

// 0x710093eb40
class alignas(16) Unk_23c0448 : public Unk_23f4660 {
public:
    using Unk_23f4660::Unk_23f4660;
    ~Unk_23c0448() override;

    u8 field_5cb;
    u32 field_5cc;
    u64 field_5d0 = 0;
    u64 field_5d8;
};
static_assert(sizeof(Unk_23c0448) == 0x5e0, "Unk_23c0448");
template Unk_239a418_Ref<Unk_23c0448> Unk_790260_Owner::Create<Unk_23c0448>(const Unk_Ref& parent,
                                                                            u64 a2);

// 0x710093f710
class alignas(16) Unk_23c0790 : public Unk_23f4660 {
public:
    using Unk_23f4660::Unk_23f4660;
    ~Unk_23c0790() override;

    u8 field_5cb;
    u32 field_5cc = 0xffffffff;
    u8 field_5d0 = 0;
    u8 field_5d1;
    u16 field_5d2;
    u32 field_5d4;
    u64 field_5d8;
};
static_assert(sizeof(Unk_23c0790) == 0x5e0, "Unk_23c0790");
template Unk_239a418_Ref<Unk_23c0790> Unk_790260_Owner::Create<Unk_23c0790>(const Unk_Ref& parent,
                                                                            u64 a2);

// 0x7100a7af40
class alignas(16) Unk_23c7ed0 : public Unk_23f4660 {
public:
    using Unk_23f4660::Unk_23f4660;
    ~Unk_23c7ed0() override;

    u8 field_5cb;
    u32 field_5cc = 0;
    u64 field_5d0 = 0;
    u64 field_5d8 = 0;
    u64 field_5e0 = 0;
    u64 field_5e8 = 0;
    u64 field_5f0 = 0;
    u64 field_5f8 = 0;
    u32 field_600 = 0xb;
    u32 field_604;
    u64 field_608 = 0;
    u32 field_610 = 0;
    u32 field_614;
    u64 field_618;
};
static_assert(sizeof(Unk_23c7ed0) == 0x620, "Unk_23c7ed0");
template Unk_239a418_Ref<Unk_23c7ed0> Unk_790260_Owner::Create<Unk_23c7ed0>(const Unk_Ref& parent,
                                                                            u64 a2);

// 0x7100a7b2d0
class alignas(16) Unk_23c8530 : public Unk_23f4660 {
public:
    using Unk_23f4660::Unk_23f4660;
    ~Unk_23c8530() override;

    u8 field_5cb;
    u32 field_5cc = 0;
    u32 field_5d0 = 0;
    u32 field_5d4;
    u64 field_5d8 = 0;
};
static_assert(sizeof(Unk_23c8530) == 0x5e0, "Unk_23c8530");
template Unk_239a418_Ref<Unk_23c8530> Unk_790260_Owner::Create<Unk_23c8530>(const Unk_Ref& parent,
                                                                            u64 a2);

// 0x7100a7b620
class alignas(16) Unk_23c7dd0 : public Unk_23f4660 {
public:
    using Unk_23f4660::Unk_23f4660;
    ~Unk_23c7dd0() override;

    u8 field_5cb;
    u32 field_5cc = 0;
    u8 field_5d0 = 0;
    u8 field_5d1;
    u16 field_5d2;
    u32 field_5d4;
    u64 field_5d8;
};
static_assert(sizeof(Unk_23c7dd0) == 0x5e0, "Unk_23c7dd0");
template Unk_239a418_Ref<Unk_23c7dd0> Unk_790260_Owner::Create<Unk_23c7dd0>(const Unk_Ref& parent,
                                                                            u64 a2);

// 0x7100e617e0
class alignas(16) Unk_23f2cf0 : public Unk_23f4660 {
public:
    using Unk_23f4660::Unk_23f4660;
    ~Unk_23f2cf0() override;

    u8 field_5cb = 0;
};
static_assert(sizeof(Unk_23f2cf0) == 0x5d0, "Unk_23f2cf0");
template Unk_239a418_Ref<Unk_23f2cf0> Unk_790260_Owner::Create<Unk_23f2cf0>(const Unk_Ref& parent,
                                                                            u64 a2);

// 0x7100e67bf0
class alignas(16) Unk_23f2f10 : public Unk_23f4660 {
public:
    using Unk_23f4660::Unk_23f4660;
    ~Unk_23f2f10() override;

    u8 field_5cb;
};
static_assert(sizeof(Unk_23f2f10) == 0x5d0, "Unk_23f2f10");
template Unk_239a418_Ref<Unk_23f2f10> Unk_790260_Owner::Create<Unk_23f2f10>(const Unk_Ref& parent,
                                                                            u64 a2);

// 0x7100e696e0
class alignas(16) Unk_23f3030 : public Unk_23f4660 {
public:
    using Unk_23f4660::Unk_23f4660;
    ~Unk_23f3030() override;

    u8 field_5cb;
    u32 field_5cc;
    u64 field_5d0 = 0;
    u64 field_5d8 = 0;
    u64 field_5e0 = 0;
    u64 field_5e8 = 0;
    u64 field_5f0 = 0;
    u64 field_5f8 = 0;
    u16 field_600 = 0;
    u16 field_602;
    u32 field_604;
    u64 field_608;
};
static_assert(sizeof(Unk_23f3030) == 0x610, "Unk_23f3030");
template Unk_239a418_Ref<Unk_23f3030> Unk_790260_Owner::Create<Unk_23f3030>(const Unk_Ref& parent,
                                                                            u64 a2);

// 0x7100e756c0
class alignas(16) Unk_23f3f48 : public Unk_23f4660 {
public:
    using Unk_23f4660::Unk_23f4660;
    ~Unk_23f3f48() override;

    u8 field_5cb;
    u32 field_5cc = 0xffffffff;
    u64 field_5d0 = 0;
    u64 field_5d8;
};
static_assert(sizeof(Unk_23f3f48) == 0x5e0, "Unk_23f3f48");
template Unk_239a418_Ref<Unk_23f3f48> Unk_790260_Owner::Create<Unk_23f3f48>(const Unk_Ref& parent,
                                                                            u64 a2);

// 0x7100eee5f0
class alignas(16) Unk_23f8b08 : public Unk_23f4660 {
public:
    using Unk_23f4660::Unk_23f4660;
    ~Unk_23f8b08() override;

    u8 field_5cb;
    u32 field_5cc = 0xffffffff;
    u64 field_5d0 = 0;
    u64 field_5d8;
};
static_assert(sizeof(Unk_23f8b08) == 0x5e0, "Unk_23f8b08");
template Unk_239a418_Ref<Unk_23f8b08> Unk_790260_Owner::Create<Unk_23f8b08>(const Unk_Ref& parent,
                                                                            u64 a2);

// 0x7100ef2eb0
class alignas(16) Unk_23f9048 : public Unk_23f4660 {
public:
    using Unk_23f4660::Unk_23f4660;
    ~Unk_23f9048() override;

    u8 field_5cb;
    u32 field_5cc;
    u64 field_5d0 = 0;
    u64 field_5d8 = 0x900000001;
    u32 field_5e0 = 0x9;
    u32 field_5e4;
    u64 field_5e8 = 0;
    u64 field_5f0 = 0;
    u64 field_5f8 = 0;
    u64 field_600 = 0;
    u64 field_608 = 0;
    u64 field_610;
    u64 field_618;
    u64 field_620;
    u64 field_628;
    u64 field_630;
    u64 field_638 = 0;
    u64 field_640 = 0;
    u64 field_648 = 0;
    u64 field_650 = 0;
    u64 field_658 = 0;
    u64 field_660 = 0;
    u64 field_668 = 0;
    u64 field_670 = 0;
    u64 field_678 = 0;
    u64 field_680 = 0;
    u64 field_688 = 0;
    u8 field_690 = 0;
    u8 field_691;
    u16 field_692;
    u32 field_694;
    u64 field_698 = 0xd009f2ab0d98b2d7;
};
static_assert(sizeof(Unk_23f9048) == 0x6a0, "Unk_23f9048");
template Unk_239a418_Ref<Unk_23f9048> Unk_790260_Owner::Create<Unk_23f9048>(const Unk_Ref& parent,
                                                                            u64 a2);

// 0x7100f01c30
class alignas(16) Unk_23fac70 : public Unk_23f4660 {
public:
    using Unk_23f4660::Unk_23f4660;
    ~Unk_23fac70() override;

    u8 field_5cb;
};
static_assert(sizeof(Unk_23fac70) == 0x5d0, "Unk_23fac70");
template Unk_239a418_Ref<Unk_23fac70> Unk_790260_Owner::Create<Unk_23fac70>(const Unk_Ref& parent,
                                                                            u64 a2);

// 0x7100f01f80
class alignas(16) Unk_23fafb8 : public Unk_23f4660 {
public:
    using Unk_23f4660::Unk_23f4660;
    ~Unk_23fafb8() override;

    u8 field_5cb;
    u32 field_5cc = 0;
    u64 field_5d0 = 0;
    u64 field_5d8 = 0;
    u64 field_5e0 = 0;
    u64 field_5e8 = 0;
    u64 field_5f0 = 0;
    u64 field_5f8;
};
static_assert(sizeof(Unk_23fafb8) == 0x600, "Unk_23fafb8");
template Unk_239a418_Ref<Unk_23fafb8> Unk_790260_Owner::Create<Unk_23fafb8>(const Unk_Ref& parent,
                                                                            u64 a2);

// 0x7100f02640
class alignas(16) Unk_23fad70 : public Unk_23f4660 {
public:
    using Unk_23f4660::Unk_23f4660;
    ~Unk_23fad70() override;

    u8 field_5cb;
    u32 field_5cc;
    u64 field_5d0 = 0;
    u64 field_5d8 = 0;
    u64 field_5e0 = 0;
    u32 field_5e8 = 0;
};
static_assert(sizeof(Unk_23fad70) == 0x5f0, "Unk_23fad70");
template Unk_239a418_Ref<Unk_23fad70> Unk_790260_Owner::Create<Unk_23fad70>(const Unk_Ref& parent,
                                                                            u64 a2);

// 0x7100f029a0
class alignas(16) Unk_23faea0 : public Unk_23f4660 {
public:
    using Unk_23f4660::Unk_23f4660;
    ~Unk_23faea0() override;

    u8 field_5cb;
};
static_assert(sizeof(Unk_23faea0) == 0x5d0, "Unk_23faea0");
template Unk_239a418_Ref<Unk_23faea0> Unk_790260_Owner::Create<Unk_23faea0>(const Unk_Ref& parent,
                                                                            u64 a2);

// 0x7100f21ee0
class alignas(16) Unk_23fbe78 : public Unk_23f4660 {
public:
    using Unk_23f4660::Unk_23f4660;
    ~Unk_23fbe78() override;

    u8 field_5cb;
};
static_assert(sizeof(Unk_23fbe78) == 0x5d0, "Unk_23fbe78");
template Unk_239a418_Ref<Unk_23fbe78> Unk_790260_Owner::Create<Unk_23fbe78>(const Unk_Ref& parent,
                                                                            u64 a2);

// 0x7100f3f770
class alignas(16) Unk_23fd920 : public Unk_23f4660 {
public:
    using Unk_23f4660::Unk_23f4660;
    ~Unk_23fd920() override;

    u8 field_5cb = 0;
    u32 field_5cc = 0;
    u8 field_5d0 = 0;
    u8 field_5d1;
    u16 field_5d2;
    u32 field_5d4;
    u64 field_5d8 = 0;
    u64 field_5e0 = 0;
    u64 field_5e8 = 0;
};
static_assert(sizeof(Unk_23fd920) == 0x5f0, "Unk_23fd920");
template Unk_239a418_Ref<Unk_23fd920> Unk_790260_Owner::Create<Unk_23fd920>(const Unk_Ref& parent,
                                                                            u64 a2);

// 0x7100f3fad0
class alignas(16) Unk_23fdf10 : public Unk_23f4660 {
public:
    using Unk_23f4660::Unk_23f4660;
    ~Unk_23fdf10() override;

    u8 field_5cb = 0;
    u32 field_5cc = 0;
    u8 field_5d0 = 0;
    u8 field_5d1;
    u16 field_5d2;
    u32 field_5d4;
    u64 field_5d8;
};
static_assert(sizeof(Unk_23fdf10) == 0x5e0, "Unk_23fdf10");
template Unk_239a418_Ref<Unk_23fdf10> Unk_790260_Owner::Create<Unk_23fdf10>(const Unk_Ref& parent,
                                                                            u64 a2);

// 0x7100f3fe20
class alignas(16) Unk_23fe058 : public Unk_23f4660 {
public:
    using Unk_23f4660::Unk_23f4660;
    ~Unk_23fe058() override;

    u8 field_5cb = 0;
    u32 field_5cc = 0;
    u8 field_5d0 = 0;
    u8 field_5d1;
    u16 field_5d2;
    u32 field_5d4;
    u64 field_5d8;
};
static_assert(sizeof(Unk_23fe058) == 0x5e0, "Unk_23fe058");
template Unk_239a418_Ref<Unk_23fe058> Unk_790260_Owner::Create<Unk_23fe058>(const Unk_Ref& parent,
                                                                            u64 a2);

// 0x7100f40640
class alignas(16) Unk_23fe610 : public Unk_23f4660 {
public:
    using Unk_23f4660::Unk_23f4660;
    ~Unk_23fe610() override;

    u8 field_5cb = 0;
    u32 field_5cc = 0;
    u64 field_5d0 = 0;
    u64 field_5d8 = 0;
    u8 field_5e0 = 0;
    u8 field_5e1;
    u16 field_5e2;
    u32 field_5e4;
    u64 field_5e8;
};
static_assert(sizeof(Unk_23fe610) == 0x5f0, "Unk_23fe610");
template Unk_239a418_Ref<Unk_23fe610> Unk_790260_Owner::Create<Unk_23fe610>(const Unk_Ref& parent,
                                                                            u64 a2);

// 0x7100f409a0
class alignas(16) Unk_23fde10 : public Unk_23f4660 {
public:
    using Unk_23f4660::Unk_23f4660;
    ~Unk_23fde10() override;

    u8 field_5cb = 0;
};
static_assert(sizeof(Unk_23fde10) == 0x5d0, "Unk_23fde10");
template Unk_239a418_Ref<Unk_23fde10> Unk_790260_Owner::Create<Unk_23fde10>(const Unk_Ref& parent,
                                                                            u64 a2);

// 0x7100f40cf0
class alignas(16) Unk_23fdce0 : public Unk_23f4660 {
public:
    using Unk_23f4660::Unk_23f4660;
    ~Unk_23fdce0() override;

    u8 field_5cb = 0;
    u32 field_5cc = 0;
    u64 field_5d0 = 0;
    u64 field_5d8 = 0;
    u8 field_5e0 = 0;
    u8 field_5e1;
    u16 field_5e2;
    u32 field_5e4 = 0;
    u32 field_5e8 = 0;
};
static_assert(sizeof(Unk_23fdce0) == 0x5f0, "Unk_23fdce0");
template Unk_239a418_Ref<Unk_23fdce0> Unk_790260_Owner::Create<Unk_23fdce0>(const Unk_Ref& parent,
                                                                            u64 a2);

// 0x7100fa4620
class alignas(16) Unk_2402c18 : public Unk_23f4660 {
public:
    using Unk_23f4660::Unk_23f4660;
    ~Unk_2402c18() override;

    u8 field_5cb;
    u32 field_5cc;
    u64 field_5d0 = 0;
    u64 field_5d8;
};
static_assert(sizeof(Unk_2402c18) == 0x5e0, "Unk_2402c18");
template Unk_239a418_Ref<Unk_2402c18> Unk_790260_Owner::Create<Unk_2402c18>(const Unk_Ref& parent,
                                                                            u64 a2);

// 0x710125e710
class alignas(16) Unk_2428128 : public Unk_23f4660 {
public:
    using Unk_23f4660::Unk_23f4660;
    ~Unk_2428128() override;

    u8 field_5cb;
};
static_assert(sizeof(Unk_2428128) == 0x5d0, "Unk_2428128");
template Unk_239a418_Ref<Unk_2428128> Unk_790260_Owner::Create<Unk_2428128>(const Unk_Ref& parent,
                                                                            u64 a2);

// 0x710125edf0
class alignas(16) Unk_2429118 : public Unk_23f4660 {
public:
    using Unk_23f4660::Unk_23f4660;
    ~Unk_2429118() override;

    u8 field_5cb;
    u32 field_5cc;
    u64 field_5d0 = 0;
    u64 field_5d8 = 0;
    u64 field_5e0 = 0;
    u64 field_5e8 = 0;
    u64 field_5f0;
    u64 field_5f8;
    u64 field_600;
    u64 field_608;
    u64 field_610;
    u64 field_618;
    u64 field_620;
    u64 field_628;
    u64 field_630;
    u64 field_638;
    u64 field_640;
    u64 field_648;
};
static_assert(sizeof(Unk_2429118) == 0x650, "Unk_2429118");
template Unk_239a418_Ref<Unk_2429118> Unk_790260_Owner::Create<Unk_2429118>(const Unk_Ref& parent,
                                                                            u64 a2);

// 0x710125f150
class alignas(16) Unk_2429218 : public Unk_23f4660 {
public:
    using Unk_23f4660::Unk_23f4660;
    ~Unk_2429218() override;

    u8 field_5cb;
    u32 field_5cc;
    u64 field_5d0 = 0;
    u64 field_5d8 = 0;
    u64 field_5e0 = 0;
    u64 field_5e8 = 0;
    u64 field_5f0;
    u64 field_5f8;
    u64 field_600;
    u64 field_608;
    u64 field_610;
    u64 field_618;
    u64 field_620;
    u64 field_628;
    u64 field_630;
    u64 field_638;
    u64 field_640;
    u64 field_648;
    u8 field_650 = 0x1;
    u8 field_651;
    u16 field_652;
    u32 field_654;
    u64 field_658;
};
static_assert(sizeof(Unk_2429218) == 0x660, "Unk_2429218");
template Unk_239a418_Ref<Unk_2429218> Unk_790260_Owner::Create<Unk_2429218>(const Unk_Ref& parent,
                                                                            u64 a2);

// 0x71012ce240
class alignas(16) Unk_242d2f8 : public Unk_23f4660 {
public:
    using Unk_23f4660::Unk_23f4660;
    ~Unk_242d2f8() override;

    u8 field_5cb = 0;
    u32 field_5cc = 0;
    u8 field_5d0 = 0;
    u8 field_5d1;
    u16 field_5d2;
    u32 field_5d4;
    u64 field_5d8 = 0;
    u64 field_5e0 = 0;
    u64 field_5e8 = 0;
    u64 field_5f0 = 0;
    u64 field_5f8 = 0;
    u64 field_600 = 0;
    u64 field_608 = 0;
    u64 field_610 = 0;
    u64 field_618 = 0;
    u64 field_620 = 0;
    u64 field_628 = 0;
    u64 field_630 = 0;
    u64 field_638 = 0;
    u64 field_640 = 0;
    u64 field_648 = 0;
    u32 field_650 = 0;
    u32 field_654;
    u64 field_658;
};
static_assert(sizeof(Unk_242d2f8) == 0x660, "Unk_242d2f8");
template Unk_239a418_Ref<Unk_242d2f8> Unk_790260_Owner::Create<Unk_242d2f8>(const Unk_Ref& parent,
                                                                            u64 a2);

// 0x71012ce5d0
class alignas(16) Unk_242e928 : public Unk_23f4660 {
public:
    using Unk_23f4660::Unk_23f4660;
    ~Unk_242e928() override;

    u8 field_5cb;
    u32 field_5cc;
    u64 field_5d0 = 0;
    u16 field_5d8 = 0;
    u16 field_5da;
    u32 field_5dc;
    u32 field_5e0;
    u16 field_5e4;
    u16 field_5e6 = 0;
    u64 field_5e8 = 0;
    u64 field_5f0 = 0;
    u64 field_5f8 = 0;
    u32 field_600 = 0xffffffff;
    u32 field_604;
    u64 field_608;
};
static_assert(sizeof(Unk_242e928) == 0x610, "Unk_242e928");
template Unk_239a418_Ref<Unk_242e928> Unk_790260_Owner::Create<Unk_242e928>(const Unk_Ref& parent,
                                                                            u64 a2);

// 0x71012ce940
class alignas(16) Unk_242d838 : public Unk_23f4660 {
public:
    using Unk_23f4660::Unk_23f4660;
    ~Unk_242d838() override;

    u8 field_5cb = 0;
    u32 field_5cc;
    u64 field_5d0 = 0;
    u64 field_5d8 = 0;
    u64 field_5e0 = 0;
    u64 field_5e8 = 0;
    u64 field_5f0 = 0;
    u8 field_5f8 = 0;
    u8 field_5f9;
    u16 field_5fa;
    u32 field_5fc;
    u64 field_600 = 0;
    u64 field_608 = 0;
};
static_assert(sizeof(Unk_242d838) == 0x610, "Unk_242d838");
template Unk_239a418_Ref<Unk_242d838> Unk_790260_Owner::Create<Unk_242d838>(const Unk_Ref& parent,
                                                                            u64 a2);

// 0x71012cecb0
class alignas(16) Unk_242d4f8 : public Unk_23f4660 {
public:
    using Unk_23f4660::Unk_23f4660;
    ~Unk_242d4f8() override;

    u8 field_5cb = 0;
    u32 field_5cc;
    u64 field_5d0 = 0;
    u64 field_5d8 = 0;
    u8 field_5e0 = 0;
    u8 field_5e1;
    u16 field_5e2;
    u32 field_5e4;
    u64 field_5e8 = 0;
    u64 field_5f0 = 0;
    u64 field_5f8 = 0;
    u64 field_600 = 0;
    u64 field_608 = 0;
    u64 field_610 = 0;
    u64 field_618 = 0;
    u64 field_620 = 0;
    u64 field_628 = 0;
    u64 field_630 = 0;
    u64 field_638 = 0;
    u64 field_640 = 0;
    u16 field_648 = 0x101;
};
static_assert(sizeof(Unk_242d4f8) == 0x650, "Unk_242d4f8");
template Unk_239a418_Ref<Unk_242d4f8> Unk_790260_Owner::Create<Unk_242d4f8>(const Unk_Ref& parent,
                                                                            u64 a2);

// 0x71012cf920
class alignas(16) Unk_242d978 : public Unk_23f4660 {
public:
    using Unk_23f4660::Unk_23f4660;
    ~Unk_242d978() override;

    u8 field_5cb = 0;
    u8 field_5cc = 0;
    u8 field_5cd;
    u16 field_5ce;
    u64 field_5d0 = 0;
    u64 field_5d8 = 0;
};
static_assert(sizeof(Unk_242d978) == 0x5e0, "Unk_242d978");
template Unk_239a418_Ref<Unk_242d978> Unk_790260_Owner::Create<Unk_242d978>(const Unk_Ref& parent,
                                                                            u64 a2);

// 0x7101304410
class alignas(16) Unk_242f2e0 : public Unk_23f4660 {
public:
    using Unk_23f4660::Unk_23f4660;
    ~Unk_242f2e0() override;

    u8 field_5cb;
};
static_assert(sizeof(Unk_242f2e0) == 0x5d0, "Unk_242f2e0");
template Unk_239a418_Ref<Unk_242f2e0> Unk_790260_Owner::Create<Unk_242f2e0>(const Unk_Ref& parent,
                                                                            u64 a2);

// 0x7101304760
class alignas(16) Unk_242f1e0 : public Unk_23f4660 {
public:
    using Unk_23f4660::Unk_23f4660;
    ~Unk_242f1e0() override;

    u8 field_5cb;
};
static_assert(sizeof(Unk_242f1e0) == 0x5d0, "Unk_242f1e0");
template Unk_239a418_Ref<Unk_242f1e0> Unk_790260_Owner::Create<Unk_242f1e0>(const Unk_Ref& parent,
                                                                            u64 a2);

// 0x710131c120
class alignas(16) Unk_242fed0 : public Unk_23f4660 {
public:
    using Unk_23f4660::Unk_23f4660;
    ~Unk_242fed0() override;

    u8 field_5cb;
};
static_assert(sizeof(Unk_242fed0) == 0x5d0, "Unk_242fed0");
template Unk_239a418_Ref<Unk_242fed0> Unk_790260_Owner::Create<Unk_242fed0>(const Unk_Ref& parent,
                                                                            u64 a2);

// 0x7101327e50
class alignas(16) Unk_24306f8 : public Unk_23f4660 {
public:
    using Unk_23f4660::Unk_23f4660;
    ~Unk_24306f8() override;

    u8 field_5cb;
    u32 field_5cc;
    u32 field_5d0 = 0xffffffff;
    u32 field_5d4;
    u64 field_5d8 = 0;
    u64 field_5e0 = 0;
    u8 field_5e8 = 0;
    u8 field_5e9;
    u16 field_5ea;
    u32 field_5ec;
    u64 field_5f0 = 0;
    u64 field_5f8 = 0;
};
static_assert(sizeof(Unk_24306f8) == 0x600, "Unk_24306f8");
template Unk_239a418_Ref<Unk_24306f8> Unk_790260_Owner::Create<Unk_24306f8>(const Unk_Ref& parent,
                                                                            u64 a2);

// 0x7101328380
class alignas(16) Unk_2430ee0 : public Unk_23f4660 {
public:
    using Unk_23f4660::Unk_23f4660;
    ~Unk_2430ee0() override;

    u8 field_5cb;
    u32 field_5cc;
    u64 field_5d0 = 0;
    u64 field_5d8 = 0;
    u64 field_5e0 = 0;
    u64 field_5e8 = 0;
    u64 field_5f0 = 0;
    u8 field_5f8 = 0;
    u8 field_5f9;
    u16 field_5fa;
    u32 field_5fc;
    u64 field_600 = 0;
    u32 field_608 = 0xffffffff;
    u32 field_60c;
    u64 field_610 = 0;
    u64 field_618 = 0;
    u64 field_620 = 0;
    u64 field_628 = 0;
    u64 field_630 = 0;
    u64 field_638 = 0;
    u64 field_640 = 0;
    u64 field_648 = 0;
    u64 field_650 = 0;
    u64 field_658;
};
static_assert(sizeof(Unk_2430ee0) == 0x660, "Unk_2430ee0");
template Unk_239a418_Ref<Unk_2430ee0> Unk_790260_Owner::Create<Unk_2430ee0>(const Unk_Ref& parent,
                                                                            u64 a2);

// 0x7101425ca0
class alignas(16) Unk_2439b60 : public Unk_23f4660 {
public:
    using Unk_23f4660::Unk_23f4660;
    ~Unk_2439b60() override;

    u8 field_5cb;
};
static_assert(sizeof(Unk_2439b60) == 0x5d0, "Unk_2439b60");
template Unk_239a418_Ref<Unk_2439b60> Unk_790260_Owner::Create<Unk_2439b60>(const Unk_Ref& parent,
                                                                            u64 a2);

// 0x7101426350
class alignas(16) Unk_2439c60 : public Unk_23f4660 {
public:
    using Unk_23f4660::Unk_23f4660;
    ~Unk_2439c60() override;

    u8 field_5cb;
};
static_assert(sizeof(Unk_2439c60) == 0x5d0, "Unk_2439c60");
template Unk_239a418_Ref<Unk_2439c60> Unk_790260_Owner::Create<Unk_2439c60>(const Unk_Ref& parent,
                                                                            u64 a2);

// 0x7101440ae0
class alignas(16) Unk_243bf78 : public Unk_23f4660 {
public:
    using Unk_23f4660::Unk_23f4660;
    ~Unk_243bf78() override;

    u8 field_5cb;
    u32 field_5cc;
    u64 field_5d0 = 0;
    u64 field_5d8;
};
static_assert(sizeof(Unk_243bf78) == 0x5e0, "Unk_243bf78");
template Unk_239a418_Ref<Unk_243bf78> Unk_790260_Owner::Create<Unk_243bf78>(const Unk_Ref& parent,
                                                                            u64 a2);

// 0x7101456e20
class alignas(16) Unk_243d1c8 : public Unk_23f4660 {
public:
    using Unk_23f4660::Unk_23f4660;
    ~Unk_243d1c8() override;

    u8 field_5cb;
};
static_assert(sizeof(Unk_243d1c8) == 0x5d0, "Unk_243d1c8");
template Unk_239a418_Ref<Unk_243d1c8> Unk_790260_Owner::Create<Unk_243d1c8>(const Unk_Ref& parent,
                                                                            u64 a2);

// 0x7101457170
class alignas(16) Unk_243cff8 : public Unk_23f4660 {
public:
    using Unk_23f4660::Unk_23f4660;
    ~Unk_243cff8() override;

    u8 field_5cb;
};
static_assert(sizeof(Unk_243cff8) == 0x5d0, "Unk_243cff8");
template Unk_239a418_Ref<Unk_243cff8> Unk_790260_Owner::Create<Unk_243cff8>(const Unk_Ref& parent,
                                                                            u64 a2);

// 0x71014672d0
class alignas(16) Unk_243d958 : public Unk_23f4660 {
public:
    using Unk_23f4660::Unk_23f4660;
    ~Unk_243d958() override;

    u8 field_5cb;
};
static_assert(sizeof(Unk_243d958) == 0x5d0, "Unk_243d958");
template Unk_239a418_Ref<Unk_243d958> Unk_790260_Owner::Create<Unk_243d958>(const Unk_Ref& parent,
                                                                            u64 a2);

// 0x7101467620
class alignas(16) Unk_243dc10 : public Unk_23f4660 {
public:
    using Unk_23f4660::Unk_23f4660;
    ~Unk_243dc10() override;

    u8 field_5cb;
    u32 field_5cc;
    u64 field_5d0 = 0;
    u64 field_5d8 = 0;
    u32 field_5e0 = 0;
    u32 field_5e4;
    u64 field_5e8;
};
static_assert(sizeof(Unk_243dc10) == 0x5f0, "Unk_243dc10");
template Unk_239a418_Ref<Unk_243dc10> Unk_790260_Owner::Create<Unk_243dc10>(const Unk_Ref& parent,
                                                                            u64 a2);

// 0x7101467970
class alignas(16) Unk_243e198 : public Unk_23f4660 {
public:
    using Unk_23f4660::Unk_23f4660;
    ~Unk_243e198() override;

    u8 field_5cb;
    u32 field_5cc;
    u64 field_5d0 = 0;
    u64 field_5d8 = 0;
    u64 field_5e0 = 0;
    u64 field_5e8 = 0;
    u64 field_5f0 = 0;
    u64 field_5f8 = 0;
    u64 field_600 = 0;
    u64 field_608 = 0;
    u64 field_610 = 0;
    u64 field_618 = 0;
    u64 field_620 = 0;
    u64 field_628 = 0;
    u64 field_630 = 0;
    u64 field_638 = 0;
    u64 field_640 = 0;
    u64 field_648 = 0;
    u64 field_650 = 0;
    u64 field_658 = 0;
    u64 field_660 = 0;
    u64 field_668 = 0;
    u64 field_670 = 0;
    u64 field_678 = 0;
    u64 field_680 = 0xa;
    u64 field_688 = 0;
};
static_assert(sizeof(Unk_243e198) == 0x690, "Unk_243e198");
template Unk_239a418_Ref<Unk_243e198> Unk_790260_Owner::Create<Unk_243e198>(const Unk_Ref& parent,
                                                                            u64 a2);

// 0x7101467d20
class alignas(16) Unk_243dd28 : public Unk_23f4660 {
public:
    using Unk_23f4660::Unk_23f4660;
    ~Unk_243dd28() override;

    u8 field_5cb;
    u32 field_5cc;
    u64 field_5d0 = 0;
    u64 field_5d8 = 0;
    u64 field_5e0 = 0;
    u64 field_5e8 = 0;
    u64 field_5f0 = 0;
    u64 field_5f8 = 0;
    u64 field_600 = 0;
    u64 field_608 = 0;
    u64 field_610 = 0;
    u64 field_618 = 0;
};
static_assert(sizeof(Unk_243dd28) == 0x620, "Unk_243dd28");
template Unk_239a418_Ref<Unk_243dd28> Unk_790260_Owner::Create<Unk_243dd28>(const Unk_Ref& parent,
                                                                            u64 a2);

// 0x7101468090
class alignas(16) Unk_243e520 : public Unk_23f4660 {
public:
    using Unk_23f4660::Unk_23f4660;
    ~Unk_243e520() override;

    u8 field_5cb;
    u32 field_5cc = 0x3;
    u64 field_5d0 = 0;
    u64 field_5d8 = 0;
    u64 field_5e0 = 0;
    u64 field_5e8;
};
static_assert(sizeof(Unk_243e520) == 0x5f0, "Unk_243e520");
template Unk_239a418_Ref<Unk_243e520> Unk_790260_Owner::Create<Unk_243e520>(const Unk_Ref& parent,
                                                                            u64 a2);

// 0x71014898a0
class alignas(16) Unk_24415a8 : public Unk_23f4660 {
public:
    using Unk_23f4660::Unk_23f4660;
    ~Unk_24415a8() override;

    u8 field_5cb;
    u32 field_5cc;
    u64 field_5d0 = 0xcbf29ce484222645;
    u64 field_5d8;
};
static_assert(sizeof(Unk_24415a8) == 0x5e0, "Unk_24415a8");
template Unk_239a418_Ref<Unk_24415a8> Unk_790260_Owner::Create<Unk_24415a8>(const Unk_Ref& parent,
                                                                            u64 a2);

// 0x7101489c00
class alignas(16) Unk_2441c98 : public Unk_23f4660 {
public:
    using Unk_23f4660::Unk_23f4660;
    ~Unk_2441c98() override;

    u8 field_5cb;
    u32 field_5cc;
    u64 field_5d0 = 0;
    u64 field_5d8 = 0;
    u32 field_5e0 = 0;
    u32 field_5e4;
    u64 field_5e8;
};
static_assert(sizeof(Unk_2441c98) == 0x5f0, "Unk_2441c98");
template Unk_239a418_Ref<Unk_2441c98> Unk_790260_Owner::Create<Unk_2441c98>(const Unk_Ref& parent,
                                                                            u64 a2);

// 0x710148a7e0
class alignas(16) Unk_2441a00 : public Unk_23f4660 {
public:
    using Unk_23f4660::Unk_23f4660;
    ~Unk_2441a00() override;

    u8 field_5cb;
    u32 field_5cc;
    u64 field_5d0 = 0;
    u64 field_5d8 = 0;
    u64 field_5e0 = 0;
    u64 field_5e8 = 0;
    u64 field_5f0 = 0;
    u64 field_5f8 = 0;
    u64 field_600 = 0;
    u64 field_608 = 0;
    u64 field_610 = 0;
    u64 field_618 = 0;
    u64 field_620 = 0;
    u64 field_628 = 0;
    u64 field_630 = 0;
    u64 field_638 = 0;
    u64 field_640 = 0;
    u64 field_648 = 0;
    u64 field_650 = 0;
    u64 field_658 = 0;
    u64 field_660 = 0;
    u64 field_668 = 0;
    u64 field_670 = 0;
    u64 field_678;
    u32 field_680;
    u32 field_684 = 0;
    u16 field_688 = 0;
    u16 field_68a;
    u32 field_68c = 0;
    u64 field_690 = 0;
    u64 field_698 = 0;
    u64 field_6a0 = 0;
    u64 field_6a8 = 0;
    u64 field_6b0;
    u64 field_6b8;
    u64 field_6c0;
    u64 field_6c8;
    u64 field_6d0;
    u64 field_6d8;
    u64 field_6e0;
    u64 field_6e8;
    u64 field_6f0;
    u64 field_6f8;
    u64 field_700;
    u64 field_708;
    u64 field_710 = 0;
    u64 field_718 = 0;
    u64 field_720 = 0;
    u64 field_728 = 0;
    u64 field_730 = 0;
    u64 field_738 = 0;
    u64 field_740 = 0;
    u64 field_748 = 0;
    u64 field_750 = 0;
    u64 field_758 = 0;
    u64 field_760 = 0;
    u64 field_768 = 0;
    u64 field_770 = 0;
    u8 field_778 = 0;
};
static_assert(sizeof(Unk_2441a00) == 0x780, "Unk_2441a00");
template Unk_239a418_Ref<Unk_2441a00> Unk_790260_Owner::Create<Unk_2441a00>(const Unk_Ref& parent,
                                                                            u64 a2);

// 0x710148abe0
class alignas(16) Unk_2441dc0 : public Unk_23f4660 {
public:
    using Unk_23f4660::Unk_23f4660;
    ~Unk_2441dc0() override;

    u8 field_5cb;
    u32 field_5cc;
    u64 field_5d0 = 0;
    u64 field_5d8 = 0;
    u64 field_5e0 = 0;
    u32 field_5e8 = 0;
    u32 field_5ec;
    u64 field_5f0 = 0;
    u64 field_5f8 = 0;
    u64 field_600 = 0;
    u64 field_608 = 0;
    u8 field_610 = 0;
    u8 field_611;
    u16 field_612;
    u32 field_614;
    u64 field_618;
};
static_assert(sizeof(Unk_2441dc0) == 0x620, "Unk_2441dc0");
template Unk_239a418_Ref<Unk_2441dc0> Unk_790260_Owner::Create<Unk_2441dc0>(const Unk_Ref& parent,
                                                                            u64 a2);

// 0x710148af50
class alignas(16) Unk_24418e0 : public Unk_23f4660 {
public:
    using Unk_23f4660::Unk_23f4660;
    ~Unk_24418e0() override;

    u8 field_5cb;
    u32 field_5cc;
    u64 field_5d0 = 0;
    u64 field_5d8 = 0;
};
static_assert(sizeof(Unk_24418e0) == 0x5e0, "Unk_24418e0");
template Unk_239a418_Ref<Unk_24418e0> Unk_790260_Owner::Create<Unk_24418e0>(const Unk_Ref& parent,
                                                                            u64 a2);

// 0x710148b2a0
class alignas(16) Unk_24416b0 : public Unk_23f4660 {
public:
    using Unk_23f4660::Unk_23f4660;
    ~Unk_24416b0() override;

    u8 field_5cb;
};
static_assert(sizeof(Unk_24416b0) == 0x5d0, "Unk_24416b0");
template Unk_239a418_Ref<Unk_24416b0> Unk_790260_Owner::Create<Unk_24416b0>(const Unk_Ref& parent,
                                                                            u64 a2);

// 0x71014c3780
class alignas(16) Unk_2443818 : public Unk_23f4660 {
public:
    using Unk_23f4660::Unk_23f4660;
    ~Unk_2443818() override;

    u8 field_5cb;
    u32 field_5cc;
    u64 field_5d0 = 0;
    u64 field_5d8;
};
static_assert(sizeof(Unk_2443818) == 0x5e0, "Unk_2443818");
template Unk_239a418_Ref<Unk_2443818> Unk_790260_Owner::Create<Unk_2443818>(const Unk_Ref& parent,
                                                                            u64 a2);

// 0x71014c39b0
class alignas(16) Unk_2443918 : public Unk_23f4660 {
public:
    using Unk_23f4660::Unk_23f4660;
    ~Unk_2443918() override;

    u8 field_5cb;
    u32 field_5cc;
    u64 field_5d0 = 0;
    u32 field_5d8 = 0;
    u32 field_5dc;
    u64 field_5e0 = 0;
    u64 field_5e8 = 0;
    u64 field_5f0 = 0;
    u64 field_5f8 = 0;
    u64 field_600 = 0;
    u64 field_608 = 0;
    u64 field_610 = 0;
    u64 field_618 = 0;
    u64 field_620 = 0;
    u64 field_628 = 0;
};
static_assert(sizeof(Unk_2443918) == 0x630, "Unk_2443918");
template Unk_239a418_Ref<Unk_2443918> Unk_790260_Owner::Create<Unk_2443918>(const Unk_Ref& parent,
                                                                            u64 a2);

// 0x7101508750
class alignas(16) Unk_2446d08 : public Unk_23f4660 {
public:
    using Unk_23f4660::Unk_23f4660;
    ~Unk_2446d08() override;

    u8 field_5cb;
    u32 field_5cc;
    u64 field_5d0 = 0;
    u64 field_5d8;
};
static_assert(sizeof(Unk_2446d08) == 0x5e0, "Unk_2446d08");
template Unk_239a418_Ref<Unk_2446d08> Unk_790260_Owner::Create<Unk_2446d08>(const Unk_Ref& parent,
                                                                            u64 a2);

// 0x71015138a0
class alignas(16) Unk_2447498 : public Unk_23f4660 {
public:
    using Unk_23f4660::Unk_23f4660;
    ~Unk_2447498() override;

    u8 field_5cb;
    u32 field_5cc = 0;
    u64 field_5d0 = 0;
    u64 field_5d8 = 0;
    u64 field_5e0 = 0;
    u64 field_5e8 = 0;
    u64 field_5f0 = 0;
    u32 field_5f8 = 0;
};
static_assert(sizeof(Unk_2447498) == 0x600, "Unk_2447498");
template Unk_239a418_Ref<Unk_2447498> Unk_790260_Owner::Create<Unk_2447498>(const Unk_Ref& parent,
                                                                            u64 a2);

// 0x7101520e30
class alignas(16) Unk_2448020 : public Unk_23f4660 {
public:
    using Unk_23f4660::Unk_23f4660;
    ~Unk_2448020() override;

    u8 field_5cb = 0;
};
static_assert(sizeof(Unk_2448020) == 0x5d0, "Unk_2448020");
template Unk_239a418_Ref<Unk_2448020> Unk_790260_Owner::Create<Unk_2448020>(const Unk_Ref& parent,
                                                                            u64 a2);

// 0x71015214e0
class alignas(16) Unk_24482c0 : public Unk_23f4660 {
public:
    using Unk_23f4660::Unk_23f4660;
    ~Unk_24482c0() override;

    u8 field_5cb;
    u32 field_5cc = 0;
    u64 field_5d0 = 0;
    u32 field_5d8 = 0;
    u32 field_5dc;
    u64 field_5e0 = 0;
    u8 field_5e8 = 0;
    u8 field_5e9;
    u16 field_5ea;
    u32 field_5ec = 0;
    u8 field_5f0 = 0;
    u8 field_5f1;
    u16 field_5f2;
    u32 field_5f4;
    u64 field_5f8;
};
static_assert(sizeof(Unk_24482c0) == 0x600, "Unk_24482c0");
template Unk_239a418_Ref<Unk_24482c0> Unk_790260_Owner::Create<Unk_24482c0>(const Unk_Ref& parent,
                                                                            u64 a2);

// 0x7101521be0
class alignas(16) Unk_2448660 : public Unk_23f4660 {
public:
    using Unk_23f4660::Unk_23f4660;
    ~Unk_2448660() override;

    u8 field_5cb;
    u32 field_5cc = 0;
    u8 field_5d0 = 0;
    u8 field_5d1;
    u16 field_5d2;
    u32 field_5d4 = 0;
    u64 field_5d8 = 0;
    u8 field_5e0 = 0;
    u8 field_5e1;
    u16 field_5e2;
    u32 field_5e4;
    u64 field_5e8 = 0;
    u64 field_5f0 = 0;
    u8 field_5f8 = 0;
};
static_assert(sizeof(Unk_2448660) == 0x600, "Unk_2448660");
template Unk_239a418_Ref<Unk_2448660> Unk_790260_Owner::Create<Unk_2448660>(const Unk_Ref& parent,
                                                                            u64 a2);

// 0x710153ea40
class alignas(16) Unk_2449870 : public Unk_23f4660 {
public:
    using Unk_23f4660::Unk_23f4660;
    ~Unk_2449870() override;

    u8 field_5cb = 0;
};
static_assert(sizeof(Unk_2449870) == 0x5d0, "Unk_2449870");
template Unk_239a418_Ref<Unk_2449870> Unk_790260_Owner::Create<Unk_2449870>(const Unk_Ref& parent,
                                                                            u64 a2);

// 0x710153ed90
class alignas(16) Unk_2449970 : public Unk_23f4660 {
public:
    using Unk_23f4660::Unk_23f4660;
    ~Unk_2449970() override;

    u8 field_5cb;
};
static_assert(sizeof(Unk_2449970) == 0x5d0, "Unk_2449970");
template Unk_239a418_Ref<Unk_2449970> Unk_790260_Owner::Create<Unk_2449970>(const Unk_Ref& parent,
                                                                            u64 a2);

// 0x710153f0e0
class alignas(16) Unk_2449670 : public Unk_23f4660 {
public:
    using Unk_23f4660::Unk_23f4660;
    ~Unk_2449670() override;

    u8 field_5cb;
    u32 field_5cc = 0;
    u8 field_5d0 = 0;
    u8 field_5d1;
    u16 field_5d2;
    u32 field_5d4;
    u64 field_5d8 = 0;
    u64 field_5e0 = 0;
    u64 field_5e8 = 0;
    u64 field_5f0 = 0;
    u64 field_5f8 = 0;
};
static_assert(sizeof(Unk_2449670) == 0x600, "Unk_2449670");
template Unk_239a418_Ref<Unk_2449670> Unk_790260_Owner::Create<Unk_2449670>(const Unk_Ref& parent,
                                                                            u64 a2);
