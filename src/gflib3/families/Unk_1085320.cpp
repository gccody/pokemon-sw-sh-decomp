// Scope: common
//
// Unk_New::Create (src/gflib3/Unk_New.h) of classes derived directly from
// gflib3's object (src/gflib3/Unk_239a418.h), its constructor out of line
// (0x71005e2350) and theirs inline, and of classes on Unk_23f4660
// (src/unsorted/Unk_23f4660.h), which inherit its constructor. The classes are named after their
// vtables; their constructors take what the factories read from the arguments: a reference or a
// reference and a u64 (moved in, or copied from a const&), a scalar by value, or a const& read
// after the base is constructed; their members are what the factories store after the base: those
// parameters and constants. Written by tools/familygen.py: regenerate, don't edit.
#include <utility>

#include "gflib3/Unk_New.h"
#include "unsorted/Unk_23f4660.h"

using Unk_Ref = Unk_239a418_Ref<Unk_239a418>;

// A reference and a u64 passed together (moved: only the reference is cleared).
struct Unk_239a418_RefPair {
    Unk_Ref field_0;
    u64 field_8;
};

// Stands for the interface at +0x60 some of the classes have: each its own,
// only its vptr's place matters here.
class Unk_1085320_Interface {
public:
    virtual void vf0();
};

struct Unk_1085320_Words2 {
    u64 field_0;
    u64 field_8;
};

struct Unk_1085320_Words3 {
    u64 field_0;
    u64 field_8;
    u64 field_10;
};

struct Unk_1085320_Words5 {
    u64 field_0;
    u64 field_8;
    u64 field_10;
    u64 field_18;
    u64 field_20;
};

// 0x7100ac5f20
// Its members are its parent's: they're stored before its vptrs.
class alignas(16) Unk_23c9660_Parent : public Unk_23f4660 {
public:
    using Unk_23f4660::Unk_23f4660;
    ~Unk_23c9660_Parent() override;

    u8 field_5cb;
    u32 field_5cc;
    u64 field_5d0 = 0;
    u8 field_5d8 = 0x1;
    u8 field_5d9;
    u16 field_5da;
    u32 field_5dc;
    u64 field_5e0 = 0;
    u64 field_5e8 = 0;
    u64 field_5f0 = 0;
    u64 field_5f8 = 0;
    u64 field_600 = 0;
    u32 field_608 = 0;
    u32 field_60c;
    u64 field_610 = 0;
    u64 field_618 = 0;
    u64 field_620 = 0;
    u64 field_628 = 0;
    u64 field_630 = 0;
    u64 field_638 = 0;
    u32 field_640 = 0x8;
    u32 field_644;
    u64 field_648;
    u64 field_650;
    u64 field_658;
    u64 field_660;
    u64 field_668;
    u64 field_670 = 0;
    u64 field_678;
    u32 field_680 = 0x8;
    u32 field_684;
    u64 field_688;
    u64 field_690;
    u64 field_698;
    u64 field_6a0;
    u64 field_6a8;
    u64 field_6b0 = 0;
    u64 field_6b8;
    u32 field_6c0 = 0x8;
    u32 field_6c4;
    u64 field_6c8;
    u64 field_6d0;
    u64 field_6d8;
    u64 field_6e0;
    u64 field_6e8;
    u64 field_6f0 = 0;
    u64 field_6f8;
    u32 field_700 = 0x8;
    u32 field_704;
    u64 field_708;
    u64 field_710;
    u64 field_718;
    u64 field_720;
    u64 field_728;
    u64 field_730 = 0;
    u64 field_738;
    u32 field_740 = 0x8;
    u32 field_744;
    u64 field_748;
    u64 field_750;
    u64 field_758;
    u64 field_760;
    u64 field_768;
    u64 field_770 = 0;
    u64 field_778;
    u32 field_780 = 0x8;
    u32 field_784;
    u64 field_788;
    u64 field_790;
    u64 field_798;
    u64 field_7a0;
    u64 field_7a8;
    u64 field_7b0 = 0;
    u64 field_7b8;
    u32 field_7c0 = 0x8;
    u32 field_7c4;
    u64 field_7c8;
    u64 field_7d0;
    u64 field_7d8;
    u64 field_7e0;
    u64 field_7e8;
    u64 field_7f0 = 0;
    u64 field_7f8;
    u32 field_800 = 0x8;
    u32 field_804;
    u64 field_808;
    u64 field_810;
    u64 field_818;
    u64 field_820;
    u64 field_828;
    u64 field_830 = 0;
    u64 field_838;
    u64 field_840 = 0;
    u64 field_848;
};
class alignas(16) Unk_23c9660 : public Unk_23c9660_Parent {
public:
    using Unk_23c9660_Parent::Unk_23c9660_Parent;
    ~Unk_23c9660() override;
    virtual void vf17();
    virtual void vf18();
    virtual void vf19();
    virtual void vf20();
    virtual void vf21();
};
static_assert(sizeof(Unk_23c9660) == 0x850, "Unk_23c9660");
template Unk_23c9660* Unk_New::Create<Unk_23c9660>(Unk_239a418_Allocator*,
                                                   void* const&,
                                                   const u64&,
                                                   const u64&);

// 0x7100ac6330
// Its members are its parent's: they're stored before its vptrs.
class alignas(16) Unk_23c9788_Parent : public Unk_23f4660 {
public:
    using Unk_23f4660::Unk_23f4660;
    ~Unk_23c9788_Parent() override;

    u8 field_5cb;
    u32 field_5cc;
    u64 field_5d0 = 0;
    u8 field_5d8 = 0x1;
    u8 field_5d9;
    u16 field_5da;
    u32 field_5dc;
    u64 field_5e0 = 0;
    u64 field_5e8 = 0;
    u64 field_5f0 = 0;
    u64 field_5f8 = 0;
    u64 field_600 = 0;
    u32 field_608 = 0;
    u32 field_60c;
    u64 field_610 = 0;
    u64 field_618 = 0;
    u64 field_620 = 0;
    u64 field_628 = 0;
    u64 field_630 = 0;
    u64 field_638 = 0;
    u32 field_640 = 0x8;
    u32 field_644;
    u64 field_648;
    u64 field_650;
    u64 field_658;
    u64 field_660;
    u64 field_668;
    u64 field_670 = 0;
    u64 field_678;
    u32 field_680 = 0x8;
    u32 field_684;
    u64 field_688;
    u64 field_690;
    u64 field_698;
    u64 field_6a0;
    u64 field_6a8;
    u64 field_6b0 = 0;
    u64 field_6b8;
    u32 field_6c0 = 0x8;
    u32 field_6c4;
    u64 field_6c8;
    u64 field_6d0;
    u64 field_6d8;
    u64 field_6e0;
    u64 field_6e8;
    u64 field_6f0 = 0;
    u64 field_6f8;
    u32 field_700 = 0x8;
    u32 field_704;
    u64 field_708;
    u64 field_710;
    u64 field_718;
    u64 field_720;
    u64 field_728;
    u64 field_730 = 0;
    u64 field_738;
    u32 field_740 = 0x8;
    u32 field_744;
    u64 field_748;
    u64 field_750;
    u64 field_758;
    u64 field_760;
    u64 field_768;
    u64 field_770 = 0;
    u64 field_778;
    u32 field_780 = 0x8;
    u32 field_784;
    u64 field_788;
    u64 field_790;
    u64 field_798;
    u64 field_7a0;
    u64 field_7a8;
    u64 field_7b0 = 0;
    u64 field_7b8;
    u32 field_7c0 = 0x8;
    u32 field_7c4;
    u64 field_7c8;
    u64 field_7d0;
    u64 field_7d8;
    u64 field_7e0;
    u64 field_7e8;
    u64 field_7f0 = 0;
    u64 field_7f8;
    u32 field_800 = 0x8;
    u32 field_804;
    u64 field_808;
    u64 field_810;
    u64 field_818;
    u64 field_820;
    u64 field_828;
    u64 field_830 = 0;
    u64 field_838;
    u64 field_840 = 0;
    u64 field_848;
};
class alignas(16) Unk_23c9788 : public Unk_23c9788_Parent {
public:
    using Unk_23c9788_Parent::Unk_23c9788_Parent;
    ~Unk_23c9788() override;
    virtual void vf17();
    virtual void vf18();
    virtual void vf19();
    virtual void vf20();
    virtual void vf21();
};
static_assert(sizeof(Unk_23c9788) == 0x850, "Unk_23c9788");
template Unk_23c9788* Unk_New::Create<Unk_23c9788>(Unk_239a418_Allocator*,
                                                   void* const&,
                                                   const u64&,
                                                   const u64&);

// 0x7100ac6740
// Its members are its parent's: they're stored before its vptrs.
class alignas(16) Unk_23c9c78_Parent : public Unk_23f4660 {
public:
    using Unk_23f4660::Unk_23f4660;
    ~Unk_23c9c78_Parent() override;

    u8 field_5cb;
    u32 field_5cc;
    u64 field_5d0 = 0;
    u8 field_5d8 = 0x1;
    u8 field_5d9;
    u16 field_5da;
    u32 field_5dc;
    u64 field_5e0 = 0;
    u64 field_5e8 = 0;
    u64 field_5f0 = 0;
    u64 field_5f8 = 0;
    u64 field_600 = 0;
    u32 field_608 = 0;
    u32 field_60c;
    u64 field_610 = 0;
    u64 field_618 = 0;
    u64 field_620 = 0;
    u64 field_628 = 0;
    u64 field_630 = 0;
    u64 field_638 = 0;
    u32 field_640 = 0x8;
    u32 field_644;
    u64 field_648;
    u64 field_650;
    u64 field_658;
    u64 field_660;
    u64 field_668;
    u64 field_670 = 0;
    u64 field_678;
    u32 field_680 = 0x8;
    u32 field_684;
    u64 field_688;
    u64 field_690;
    u64 field_698;
    u64 field_6a0;
    u64 field_6a8;
    u64 field_6b0 = 0;
    u64 field_6b8;
    u32 field_6c0 = 0x8;
    u32 field_6c4;
    u64 field_6c8;
    u64 field_6d0;
    u64 field_6d8;
    u64 field_6e0;
    u64 field_6e8;
    u64 field_6f0 = 0;
    u64 field_6f8;
    u32 field_700 = 0x8;
    u32 field_704;
    u64 field_708;
    u64 field_710;
    u64 field_718;
    u64 field_720;
    u64 field_728;
    u64 field_730 = 0;
    u64 field_738;
    u32 field_740 = 0x8;
    u32 field_744;
    u64 field_748;
    u64 field_750;
    u64 field_758;
    u64 field_760;
    u64 field_768;
    u64 field_770 = 0;
    u64 field_778;
    u32 field_780 = 0x8;
    u32 field_784;
    u64 field_788;
    u64 field_790;
    u64 field_798;
    u64 field_7a0;
    u64 field_7a8;
    u64 field_7b0 = 0;
    u64 field_7b8;
    u32 field_7c0 = 0x8;
    u32 field_7c4;
    u64 field_7c8;
    u64 field_7d0;
    u64 field_7d8;
    u64 field_7e0;
    u64 field_7e8;
    u64 field_7f0 = 0;
    u64 field_7f8;
    u32 field_800 = 0x8;
    u32 field_804;
    u64 field_808;
    u64 field_810;
    u64 field_818;
    u64 field_820;
    u64 field_828;
    u64 field_830 = 0;
    u64 field_838;
    u64 field_840 = 0;
    u64 field_848;
};
class alignas(16) Unk_23c9c78 : public Unk_23c9c78_Parent {
public:
    using Unk_23c9c78_Parent::Unk_23c9c78_Parent;
    ~Unk_23c9c78() override;
    virtual void vf17();
    virtual void vf18();
    virtual void vf19();
    virtual void vf20();
    virtual void vf21();
};
static_assert(sizeof(Unk_23c9c78) == 0x850, "Unk_23c9c78");
template Unk_23c9c78* Unk_New::Create<Unk_23c9c78>(Unk_239a418_Allocator*,
                                                   void* const&,
                                                   const u64&,
                                                   const u64&);

// 0x7100ac6f70
// Its members are its parent's: they're stored before its vptrs.
class alignas(16) Unk_23c9028_Parent : public Unk_23f4660 {
public:
    using Unk_23f4660::Unk_23f4660;
    ~Unk_23c9028_Parent() override;

    u8 field_5cb;
    u32 field_5cc;
    u64 field_5d0 = 0;
    u8 field_5d8 = 0x1;
    u8 field_5d9;
    u16 field_5da;
    u32 field_5dc;
    u64 field_5e0 = 0;
    u64 field_5e8 = 0;
    u64 field_5f0 = 0;
    u64 field_5f8 = 0;
    u64 field_600 = 0;
    u32 field_608 = 0;
    u32 field_60c;
    u64 field_610 = 0;
    u64 field_618 = 0;
    u64 field_620 = 0;
    u64 field_628 = 0;
    u64 field_630 = 0;
    u64 field_638 = 0;
    u32 field_640 = 0x8;
    u32 field_644;
    u64 field_648;
    u64 field_650;
    u64 field_658;
    u64 field_660;
    u64 field_668;
    u64 field_670 = 0;
    u64 field_678;
    u32 field_680 = 0x8;
    u32 field_684;
    u64 field_688;
    u64 field_690;
    u64 field_698;
    u64 field_6a0;
    u64 field_6a8;
    u64 field_6b0 = 0;
    u64 field_6b8;
    u32 field_6c0 = 0x8;
    u32 field_6c4;
    u64 field_6c8;
    u64 field_6d0;
    u64 field_6d8;
    u64 field_6e0;
    u64 field_6e8;
    u64 field_6f0 = 0;
    u64 field_6f8;
    u32 field_700 = 0x8;
    u32 field_704;
    u64 field_708;
    u64 field_710;
    u64 field_718;
    u64 field_720;
    u64 field_728;
    u64 field_730 = 0;
    u64 field_738;
    u32 field_740 = 0x8;
    u32 field_744;
    u64 field_748;
    u64 field_750;
    u64 field_758;
    u64 field_760;
    u64 field_768;
    u64 field_770 = 0;
    u64 field_778;
    u32 field_780 = 0x8;
    u32 field_784;
    u64 field_788;
    u64 field_790;
    u64 field_798;
    u64 field_7a0;
    u64 field_7a8;
    u64 field_7b0 = 0;
    u64 field_7b8;
    u32 field_7c0 = 0x8;
    u32 field_7c4;
    u64 field_7c8;
    u64 field_7d0;
    u64 field_7d8;
    u64 field_7e0;
    u64 field_7e8;
    u64 field_7f0 = 0;
    u64 field_7f8;
    u32 field_800 = 0x8;
    u32 field_804;
    u64 field_808;
    u64 field_810;
    u64 field_818;
    u64 field_820;
    u64 field_828;
    u64 field_830 = 0;
    u64 field_838;
    u64 field_840 = 0;
    u64 field_848;
};
class alignas(16) Unk_23c9028 : public Unk_23c9028_Parent {
public:
    using Unk_23c9028_Parent::Unk_23c9028_Parent;
    ~Unk_23c9028() override;
    virtual void vf17();
    virtual void vf18();
    virtual void vf19();
    virtual void vf20();
    virtual void vf21();
};
static_assert(sizeof(Unk_23c9028) == 0x850, "Unk_23c9028");
template Unk_23c9028* Unk_New::Create<Unk_23c9028>(Unk_239a418_Allocator*,
                                                   void* const&,
                                                   const u64&,
                                                   const u64&);

// 0x7100ac7e20
// Its members are its parent's: they're stored before its vptrs.
class alignas(16) Unk_23c9150_Parent : public Unk_23f4660 {
public:
    using Unk_23f4660::Unk_23f4660;
    ~Unk_23c9150_Parent() override;

    u8 field_5cb;
    u32 field_5cc;
    u64 field_5d0 = 0;
    u8 field_5d8 = 0x1;
    u8 field_5d9;
    u16 field_5da;
    u32 field_5dc;
    u64 field_5e0 = 0;
    u64 field_5e8 = 0;
    u64 field_5f0 = 0;
    u64 field_5f8 = 0;
    u64 field_600 = 0;
    u32 field_608 = 0;
    u32 field_60c;
    u64 field_610 = 0;
    u64 field_618 = 0;
    u64 field_620 = 0;
    u64 field_628 = 0;
    u64 field_630 = 0;
    u64 field_638 = 0;
    u32 field_640 = 0x8;
    u32 field_644;
    u64 field_648;
    u64 field_650;
    u64 field_658;
    u64 field_660;
    u64 field_668;
    u64 field_670 = 0;
    u64 field_678;
    u32 field_680 = 0x8;
    u32 field_684;
    u64 field_688;
    u64 field_690;
    u64 field_698;
    u64 field_6a0;
    u64 field_6a8;
    u64 field_6b0 = 0;
    u64 field_6b8;
    u32 field_6c0 = 0x8;
    u32 field_6c4;
    u64 field_6c8;
    u64 field_6d0;
    u64 field_6d8;
    u64 field_6e0;
    u64 field_6e8;
    u64 field_6f0 = 0;
    u64 field_6f8;
    u32 field_700 = 0x8;
    u32 field_704;
    u64 field_708;
    u64 field_710;
    u64 field_718;
    u64 field_720;
    u64 field_728;
    u64 field_730 = 0;
    u64 field_738;
    u32 field_740 = 0x8;
    u32 field_744;
    u64 field_748;
    u64 field_750;
    u64 field_758;
    u64 field_760;
    u64 field_768;
    u64 field_770 = 0;
    u64 field_778;
    u32 field_780 = 0x8;
    u32 field_784;
    u64 field_788;
    u64 field_790;
    u64 field_798;
    u64 field_7a0;
    u64 field_7a8;
    u64 field_7b0 = 0;
    u64 field_7b8;
    u32 field_7c0 = 0x8;
    u32 field_7c4;
    u64 field_7c8;
    u64 field_7d0;
    u64 field_7d8;
    u64 field_7e0;
    u64 field_7e8;
    u64 field_7f0 = 0;
    u64 field_7f8;
    u32 field_800 = 0x8;
    u32 field_804;
    u64 field_808;
    u64 field_810;
    u64 field_818;
    u64 field_820;
    u64 field_828;
    u64 field_830 = 0;
    u64 field_838;
    u64 field_840 = 0;
    u64 field_848;
};
class alignas(16) Unk_23c9150 : public Unk_23c9150_Parent {
public:
    using Unk_23c9150_Parent::Unk_23c9150_Parent;
    ~Unk_23c9150() override;
    virtual void vf17();
    virtual void vf18();
    virtual void vf19();
    virtual void vf20();
    virtual void vf21();
};
static_assert(sizeof(Unk_23c9150) == 0x850, "Unk_23c9150");
template Unk_23c9150* Unk_New::Create<Unk_23c9150>(Unk_239a418_Allocator*,
                                                   void* const&,
                                                   const u64&,
                                                   const u64&);

// 0x7100ac8490
// Its members are its parent's: they're stored before its vptrs.
class alignas(16) Unk_23cc7a0_Parent : public Unk_23f4660 {
public:
    using Unk_23f4660::Unk_23f4660;
    ~Unk_23cc7a0_Parent() override;

    u8 field_5cb;
    u32 field_5cc;
    u64 field_5d0 = 0;
    u8 field_5d8 = 0x1;
    u8 field_5d9;
    u16 field_5da;
    u32 field_5dc;
    u64 field_5e0 = 0;
    u64 field_5e8 = 0;
    u64 field_5f0 = 0;
    u64 field_5f8 = 0;
    u64 field_600 = 0;
    u32 field_608 = 0;
    u32 field_60c;
    u64 field_610 = 0;
    u64 field_618 = 0;
    u64 field_620 = 0;
    u64 field_628 = 0;
    u64 field_630 = 0;
    u64 field_638 = 0;
    u32 field_640 = 0x8;
    u32 field_644;
    u64 field_648;
    u64 field_650;
    u64 field_658;
    u64 field_660;
    u64 field_668;
    u64 field_670 = 0;
    u64 field_678;
    u32 field_680 = 0x8;
    u32 field_684;
    u64 field_688;
    u64 field_690;
    u64 field_698;
    u64 field_6a0;
    u64 field_6a8;
    u64 field_6b0 = 0;
    u64 field_6b8;
    u32 field_6c0 = 0x8;
    u32 field_6c4;
    u64 field_6c8;
    u64 field_6d0;
    u64 field_6d8;
    u64 field_6e0;
    u64 field_6e8;
    u64 field_6f0 = 0;
    u64 field_6f8;
    u32 field_700 = 0x8;
    u32 field_704;
    u64 field_708;
    u64 field_710;
    u64 field_718;
    u64 field_720;
    u64 field_728;
    u64 field_730 = 0;
    u64 field_738;
    u32 field_740 = 0x8;
    u32 field_744;
    u64 field_748;
    u64 field_750;
    u64 field_758;
    u64 field_760;
    u64 field_768;
    u64 field_770 = 0;
    u64 field_778;
    u32 field_780 = 0x8;
    u32 field_784;
    u64 field_788;
    u64 field_790;
    u64 field_798;
    u64 field_7a0;
    u64 field_7a8;
    u64 field_7b0 = 0;
    u64 field_7b8;
    u32 field_7c0 = 0x8;
    u32 field_7c4;
    u64 field_7c8;
    u64 field_7d0;
    u64 field_7d8;
    u64 field_7e0;
    u64 field_7e8;
    u64 field_7f0 = 0;
    u64 field_7f8;
    u32 field_800 = 0x8;
    u32 field_804;
    u64 field_808;
    u64 field_810;
    u64 field_818;
    u64 field_820;
    u64 field_828;
    u64 field_830 = 0;
    u64 field_838;
    u64 field_840 = 0;
    u64 field_848;
};
class alignas(16) Unk_23cc7a0 : public Unk_23cc7a0_Parent {
public:
    using Unk_23cc7a0_Parent::Unk_23cc7a0_Parent;
    ~Unk_23cc7a0() override;
    virtual void vf17();
    virtual void vf18();
    virtual void vf19();
    virtual void vf20();
    virtual void vf21();
};
static_assert(sizeof(Unk_23cc7a0) == 0x850, "Unk_23cc7a0");
template Unk_23cc7a0* Unk_New::Create<Unk_23cc7a0>(Unk_239a418_Allocator*,
                                                   void* const&,
                                                   const u64&,
                                                   const u64&);

// 0x7100ac88a0
// Its members are its parent's: they're stored before its vptrs.
class alignas(16) Unk_23c9278_Parent : public Unk_23f4660 {
public:
    using Unk_23f4660::Unk_23f4660;
    ~Unk_23c9278_Parent() override;

    u8 field_5cb;
    u32 field_5cc;
    u64 field_5d0 = 0;
    u8 field_5d8 = 0x1;
    u8 field_5d9;
    u16 field_5da;
    u32 field_5dc;
    u64 field_5e0 = 0;
    u64 field_5e8 = 0;
    u64 field_5f0 = 0;
    u64 field_5f8 = 0;
    u64 field_600 = 0;
    u32 field_608 = 0;
    u32 field_60c;
    u64 field_610 = 0;
    u64 field_618 = 0;
    u64 field_620 = 0;
    u64 field_628 = 0;
    u64 field_630 = 0;
    u64 field_638 = 0;
    u32 field_640 = 0x8;
    u32 field_644;
    u64 field_648;
    u64 field_650;
    u64 field_658;
    u64 field_660;
    u64 field_668;
    u64 field_670 = 0;
    u64 field_678;
    u32 field_680 = 0x8;
    u32 field_684;
    u64 field_688;
    u64 field_690;
    u64 field_698;
    u64 field_6a0;
    u64 field_6a8;
    u64 field_6b0 = 0;
    u64 field_6b8;
    u32 field_6c0 = 0x8;
    u32 field_6c4;
    u64 field_6c8;
    u64 field_6d0;
    u64 field_6d8;
    u64 field_6e0;
    u64 field_6e8;
    u64 field_6f0 = 0;
    u64 field_6f8;
    u32 field_700 = 0x8;
    u32 field_704;
    u64 field_708;
    u64 field_710;
    u64 field_718;
    u64 field_720;
    u64 field_728;
    u64 field_730 = 0;
    u64 field_738;
    u32 field_740 = 0x8;
    u32 field_744;
    u64 field_748;
    u64 field_750;
    u64 field_758;
    u64 field_760;
    u64 field_768;
    u64 field_770 = 0;
    u64 field_778;
    u32 field_780 = 0x8;
    u32 field_784;
    u64 field_788;
    u64 field_790;
    u64 field_798;
    u64 field_7a0;
    u64 field_7a8;
    u64 field_7b0 = 0;
    u64 field_7b8;
    u32 field_7c0 = 0x8;
    u32 field_7c4;
    u64 field_7c8;
    u64 field_7d0;
    u64 field_7d8;
    u64 field_7e0;
    u64 field_7e8;
    u64 field_7f0 = 0;
    u64 field_7f8;
    u32 field_800 = 0x8;
    u32 field_804;
    u64 field_808;
    u64 field_810;
    u64 field_818;
    u64 field_820;
    u64 field_828;
    u64 field_830 = 0;
    u64 field_838;
    u64 field_840 = 0;
    u64 field_848;
};
class alignas(16) Unk_23c9278 : public Unk_23c9278_Parent {
public:
    using Unk_23c9278_Parent::Unk_23c9278_Parent;
    ~Unk_23c9278() override;
    virtual void vf17();
    virtual void vf18();
    virtual void vf19();
    virtual void vf20();
    virtual void vf21();
};
static_assert(sizeof(Unk_23c9278) == 0x850, "Unk_23c9278");
template Unk_23c9278* Unk_New::Create<Unk_23c9278>(Unk_239a418_Allocator*,
                                                   void* const&,
                                                   const u64&,
                                                   const u64&);

// 0x7100aca820
// Its members are its parent's: they're stored before its vptrs.
class alignas(16) Unk_23c9ff0_Parent : public Unk_23f4660 {
public:
    using Unk_23f4660::Unk_23f4660;
    ~Unk_23c9ff0_Parent() override;

    u8 field_5cb;
    u32 field_5cc;
    u64 field_5d0 = 0;
    u8 field_5d8 = 0x1;
    u8 field_5d9;
    u16 field_5da;
    u32 field_5dc;
    u64 field_5e0 = 0;
    u64 field_5e8 = 0;
    u64 field_5f0 = 0;
    u64 field_5f8 = 0;
    u64 field_600 = 0;
    u32 field_608 = 0;
    u32 field_60c;
    u64 field_610 = 0;
    u64 field_618 = 0;
    u64 field_620 = 0;
    u64 field_628 = 0;
    u64 field_630 = 0;
    u64 field_638 = 0;
    u32 field_640 = 0x8;
    u32 field_644;
    u64 field_648;
    u64 field_650;
    u64 field_658;
    u64 field_660;
    u64 field_668;
    u64 field_670 = 0;
    u64 field_678;
    u32 field_680 = 0x8;
    u32 field_684;
    u64 field_688;
    u64 field_690;
    u64 field_698;
    u64 field_6a0;
    u64 field_6a8;
    u64 field_6b0 = 0;
    u64 field_6b8;
    u32 field_6c0 = 0x8;
    u32 field_6c4;
    u64 field_6c8;
    u64 field_6d0;
    u64 field_6d8;
    u64 field_6e0;
    u64 field_6e8;
    u64 field_6f0 = 0;
    u64 field_6f8;
    u32 field_700 = 0x8;
    u32 field_704;
    u64 field_708;
    u64 field_710;
    u64 field_718;
    u64 field_720;
    u64 field_728;
    u64 field_730 = 0;
    u64 field_738;
    u32 field_740 = 0x8;
    u32 field_744;
    u64 field_748;
    u64 field_750;
    u64 field_758;
    u64 field_760;
    u64 field_768;
    u64 field_770 = 0;
    u64 field_778;
    u32 field_780 = 0x8;
    u32 field_784;
    u64 field_788;
    u64 field_790;
    u64 field_798;
    u64 field_7a0;
    u64 field_7a8;
    u64 field_7b0 = 0;
    u64 field_7b8;
    u32 field_7c0 = 0x8;
    u32 field_7c4;
    u64 field_7c8;
    u64 field_7d0;
    u64 field_7d8;
    u64 field_7e0;
    u64 field_7e8;
    u64 field_7f0 = 0;
    u64 field_7f8;
    u32 field_800 = 0x8;
    u32 field_804;
    u64 field_808;
    u64 field_810;
    u64 field_818;
    u64 field_820;
    u64 field_828;
    u64 field_830 = 0;
    u64 field_838;
    u64 field_840 = 0;
    u64 field_848;
};
class alignas(16) Unk_23c9ff0 : public Unk_23c9ff0_Parent {
public:
    using Unk_23c9ff0_Parent::Unk_23c9ff0_Parent;
    ~Unk_23c9ff0() override;
    virtual void vf17();
    virtual void vf18();
    virtual void vf19();
    virtual void vf20();
    virtual void vf21();
};
static_assert(sizeof(Unk_23c9ff0) == 0x850, "Unk_23c9ff0");
template Unk_23c9ff0* Unk_New::Create<Unk_23c9ff0>(Unk_239a418_Allocator*,
                                                   void* const&,
                                                   const u64&,
                                                   const u64&);

// 0x7100cfc840
class Unk_23e52a8 : public Unk_239a418 {
public:
    Unk_23e52a8(Unk_239a418_Ref2<Unk_239a418> a0) : field_60(a0) {}
    ~Unk_23e52a8() override;
    virtual void vf6();
    virtual void vf7();

    Unk_239a418_Ref2<Unk_239a418> field_60;
};
static_assert(sizeof(Unk_23e52a8) == 0x68, "Unk_23e52a8");
template Unk_23e52a8* Unk_New::Create<Unk_23e52a8>(Unk_239a418_Allocator*, const Unk_Ref&);

// 0x7101054340
class Unk_240b658 : public Unk_239a418, public Unk_1085320_Interface {
public:
    Unk_240b658(Unk_239a418_RefPair a0, const u32& a1) : field_68(a0), field_80(a1) {}
    ~Unk_240b658() override;
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();

    Unk_239a418_RefPair field_68;
    u64 field_78 = 0;
    u32 field_80;
    u32 field_84;
};
static_assert(sizeof(Unk_240b658) == 0x88, "Unk_240b658");
template Unk_240b658* Unk_New::Create<Unk_240b658>(Unk_239a418_Allocator*,
                                                   Unk_239a418_RefPair&&,
                                                   const u32&);

// 0x71010569b0
class Unk_240b970 : public Unk_239a418, public Unk_1085320_Interface {
public:
    Unk_240b970(Unk_239a418_RefPair a0, const u32& a1) : field_68(a0), field_80(a1) {}
    ~Unk_240b970() override;
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();

    Unk_239a418_RefPair field_68;
    u64 field_78 = 0;
    u32 field_80;
    u32 field_84;
};
static_assert(sizeof(Unk_240b970) == 0x88, "Unk_240b970");
template Unk_240b970* Unk_New::Create<Unk_240b970>(Unk_239a418_Allocator*,
                                                   Unk_239a418_RefPair&&,
                                                   const u32&);

// 0x7101058c30
class Unk_240bc60 : public Unk_239a418, public Unk_1085320_Interface {
public:
    Unk_240bc60(Unk_239a418_RefPair a0, const u32& a1) : field_68(a0), field_80(a1) {}
    ~Unk_240bc60() override;
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();

    Unk_239a418_RefPair field_68;
    u64 field_78 = 0;
    u32 field_80;
    u32 field_84;
};
static_assert(sizeof(Unk_240bc60) == 0x88, "Unk_240bc60");
template Unk_240bc60* Unk_New::Create<Unk_240bc60>(Unk_239a418_Allocator*,
                                                   Unk_239a418_RefPair&&,
                                                   const u32&);

// 0x7101059740
class Unk_240bd60 : public Unk_239a418, public Unk_1085320_Interface {
public:
    Unk_240bd60(Unk_239a418_RefPair a0, const Unk_1085320_Words3& a1)
        : field_68(a0), field_80(a1) {}
    ~Unk_240bd60() override;
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();

    Unk_239a418_RefPair field_68;
    u64 field_78 = 0;
    Unk_1085320_Words3 field_80;
};
static_assert(sizeof(Unk_240bd60) == 0x98, "Unk_240bd60");
template Unk_240bd60* Unk_New::Create<Unk_240bd60>(Unk_239a418_Allocator*,
                                                   Unk_239a418_RefPair&&,
                                                   const Unk_1085320_Words3&);

// 0x710105a590
class Unk_240be88 : public Unk_239a418, public Unk_1085320_Interface {
public:
    Unk_240be88(Unk_239a418_RefPair a0) : field_68(a0) {}
    ~Unk_240be88() override;
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();

    Unk_239a418_RefPair field_68;
    u64 field_78 = 0;
    u32 field_80 = 0;
};
static_assert(sizeof(Unk_240be88) == 0x88, "Unk_240be88");
template Unk_240be88* Unk_New::Create<Unk_240be88>(Unk_239a418_Allocator*, Unk_239a418_RefPair&&);

// 0x7101085320
class Unk_240d540 : public Unk_239a418, public Unk_1085320_Interface {
public:
    Unk_240d540(Unk_239a418_RefPair a0, Unk_239a418_Ref2<Unk_239a418> a1)
        : field_68(a0), field_80(a1) {}
    ~Unk_240d540() override;
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();

    Unk_239a418_RefPair field_68;
    u64 field_78 = 0;
    Unk_239a418_Ref2<Unk_239a418> field_80;
};
static_assert(sizeof(Unk_240d540) == 0x88, "Unk_240d540");
template Unk_240d540* Unk_New::Create<Unk_240d540>(Unk_239a418_Allocator*,
                                                   Unk_239a418_RefPair&&,
                                                   const Unk_Ref&);

// 0x7101085f00
class Unk_240d668 : public Unk_239a418, public Unk_1085320_Interface {
public:
    Unk_240d668(Unk_239a418_RefPair a0, const Unk_Ref& a1) : field_68(a0), field_80(a1) {}
    ~Unk_240d668() override;
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();

    Unk_239a418_RefPair field_68;
    u64 field_78 = 0;
    Unk_239a418_Ref2<Unk_239a418> field_80;
};
static_assert(sizeof(Unk_240d668) == 0x88, "Unk_240d668");
template Unk_240d668* Unk_New::Create<Unk_240d668>(Unk_239a418_Allocator*,
                                                   Unk_239a418_RefPair&&,
                                                   const Unk_Ref&);

// 0x71010875e0
class Unk_240d8f0 : public Unk_239a418, public Unk_1085320_Interface {
public:
    Unk_240d8f0(Unk_239a418_RefPair a0, Unk_239a418_Ref2<Unk_239a418> a1)
        : field_68(a0), field_80(a1) {}
    ~Unk_240d8f0() override;
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();

    Unk_239a418_RefPair field_68;
    u64 field_78 = 0;
    Unk_239a418_Ref2<Unk_239a418> field_80;
};
static_assert(sizeof(Unk_240d8f0) == 0x88, "Unk_240d8f0");
template Unk_240d8f0* Unk_New::Create<Unk_240d8f0>(Unk_239a418_Allocator*,
                                                   Unk_239a418_RefPair&&,
                                                   const Unk_Ref&);

// 0x71010892f0
class Unk_240dc40 : public Unk_239a418, public Unk_1085320_Interface {
public:
    Unk_240dc40(Unk_239a418_RefPair a0, const u32& a1) : field_68(a0), field_80(a1) {}
    ~Unk_240dc40() override;
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();

    Unk_239a418_RefPair field_68;
    u64 field_78 = 0;
    u32 field_80;
    u32 field_84;
};
static_assert(sizeof(Unk_240dc40) == 0x88, "Unk_240dc40");
template Unk_240dc40* Unk_New::Create<Unk_240dc40>(Unk_239a418_Allocator*,
                                                   Unk_239a418_RefPair&&,
                                                   const u32&);

// 0x7101089dc0
class Unk_240dd68 : public Unk_239a418, public Unk_1085320_Interface {
public:
    Unk_240dd68(Unk_239a418_RefPair a0, const Unk_Ref& a1) : field_68(a0), field_80(a1) {}
    ~Unk_240dd68() override;
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();

    Unk_239a418_RefPair field_68;
    u64 field_78 = 0;
    Unk_239a418_Ref2<Unk_239a418> field_80;
};
static_assert(sizeof(Unk_240dd68) == 0x88, "Unk_240dd68");
template Unk_240dd68* Unk_New::Create<Unk_240dd68>(Unk_239a418_Allocator*,
                                                   Unk_239a418_RefPair&&,
                                                   const Unk_Ref&);

// 0x710108b600
class Unk_240dfc8 : public Unk_239a418, public Unk_1085320_Interface {
public:
    Unk_240dfc8(Unk_239a418_RefPair a0, Unk_239a418_Ref2<Unk_239a418> a1)
        : field_68(a0), field_80(a1) {}
    ~Unk_240dfc8() override;
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();

    Unk_239a418_RefPair field_68;
    u64 field_78 = 0;
    Unk_239a418_Ref2<Unk_239a418> field_80;
};
static_assert(sizeof(Unk_240dfc8) == 0x88, "Unk_240dfc8");
template Unk_240dfc8* Unk_New::Create<Unk_240dfc8>(Unk_239a418_Allocator*,
                                                   Unk_239a418_RefPair&&,
                                                   const Unk_Ref&);

// 0x710108c250
class Unk_240e0f0 : public Unk_239a418, public Unk_1085320_Interface {
public:
    Unk_240e0f0(Unk_239a418_RefPair a0, const Unk_Ref& a1) : field_68(a0), field_80(a1) {}
    ~Unk_240e0f0() override;
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();

    Unk_239a418_RefPair field_68;
    u64 field_78 = 0;
    Unk_239a418_Ref2<Unk_239a418> field_80;
};
static_assert(sizeof(Unk_240e0f0) == 0x88, "Unk_240e0f0");
template Unk_240e0f0* Unk_New::Create<Unk_240e0f0>(Unk_239a418_Allocator*,
                                                   Unk_239a418_RefPair&&,
                                                   const Unk_Ref&);

// 0x710108dc90
class Unk_240e350 : public Unk_239a418, public Unk_1085320_Interface {
public:
    Unk_240e350(Unk_239a418_RefPair a0, Unk_239a418_Ref2<Unk_239a418> a1)
        : field_68(a0), field_80(a1) {}
    ~Unk_240e350() override;
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();

    Unk_239a418_RefPair field_68;
    u64 field_78 = 0;
    Unk_239a418_Ref2<Unk_239a418> field_80;
};
static_assert(sizeof(Unk_240e350) == 0x88, "Unk_240e350");
template Unk_240e350* Unk_New::Create<Unk_240e350>(Unk_239a418_Allocator*,
                                                   Unk_239a418_RefPair&&,
                                                   const Unk_Ref&);

// 0x710108fb20
class Unk_240e6a0 : public Unk_239a418, public Unk_1085320_Interface {
public:
    Unk_240e6a0(Unk_239a418_RefPair a0, Unk_239a418_Ref2<Unk_239a418> a1)
        : field_68(a0), field_80(a1) {}
    ~Unk_240e6a0() override;
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();

    Unk_239a418_RefPair field_68;
    u64 field_78 = 0;
    Unk_239a418_Ref2<Unk_239a418> field_80;
};
static_assert(sizeof(Unk_240e6a0) == 0x88, "Unk_240e6a0");
template Unk_240e6a0* Unk_New::Create<Unk_240e6a0>(Unk_239a418_Allocator*,
                                                   Unk_239a418_RefPair&&,
                                                   const Unk_Ref&);

// 0x71010906f0
class Unk_240e7c8 : public Unk_239a418, public Unk_1085320_Interface {
public:
    Unk_240e7c8(Unk_239a418_RefPair a0, const Unk_Ref& a1) : field_68(a0), field_80(a1) {}
    ~Unk_240e7c8() override;
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();

    Unk_239a418_RefPair field_68;
    u64 field_78 = 0;
    Unk_239a418_Ref2<Unk_239a418> field_80;
};
static_assert(sizeof(Unk_240e7c8) == 0x88, "Unk_240e7c8");
template Unk_240e7c8* Unk_New::Create<Unk_240e7c8>(Unk_239a418_Allocator*,
                                                   Unk_239a418_RefPair&&,
                                                   const Unk_Ref&);

// 0x7101092a10
class Unk_240eba0 : public Unk_239a418, public Unk_1085320_Interface {
public:
    Unk_240eba0(Unk_239a418_RefPair a0, Unk_239a418_Ref2<Unk_239a418> a1)
        : field_68(a0), field_80(a1) {}
    ~Unk_240eba0() override;
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();

    Unk_239a418_RefPair field_68;
    u64 field_78 = 0;
    Unk_239a418_Ref2<Unk_239a418> field_80;
};
static_assert(sizeof(Unk_240eba0) == 0x88, "Unk_240eba0");
template Unk_240eba0* Unk_New::Create<Unk_240eba0>(Unk_239a418_Allocator*,
                                                   Unk_239a418_RefPair&&,
                                                   const Unk_Ref&);

// 0x71010935e0
class Unk_240ecc8 : public Unk_239a418, public Unk_1085320_Interface {
public:
    Unk_240ecc8(Unk_239a418_RefPair a0, const Unk_Ref& a1) : field_68(a0), field_80(a1) {}
    ~Unk_240ecc8() override;
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();

    Unk_239a418_RefPair field_68;
    u64 field_78 = 0;
    Unk_239a418_Ref2<Unk_239a418> field_80;
};
static_assert(sizeof(Unk_240ecc8) == 0x88, "Unk_240ecc8");
template Unk_240ecc8* Unk_New::Create<Unk_240ecc8>(Unk_239a418_Allocator*,
                                                   Unk_239a418_RefPair&&,
                                                   const Unk_Ref&);

// 0x7101094dd0
class Unk_240ef28 : public Unk_239a418, public Unk_1085320_Interface {
public:
    Unk_240ef28(Unk_239a418_RefPair a0, Unk_239a418_Ref2<Unk_239a418> a1)
        : field_68(a0), field_80(a1) {}
    ~Unk_240ef28() override;
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();

    Unk_239a418_RefPair field_68;
    u64 field_78 = 0;
    Unk_239a418_Ref2<Unk_239a418> field_80;
};
static_assert(sizeof(Unk_240ef28) == 0x88, "Unk_240ef28");
template Unk_240ef28* Unk_New::Create<Unk_240ef28>(Unk_239a418_Allocator*,
                                                   Unk_239a418_RefPair&&,
                                                   const Unk_Ref&);

// 0x7101096980
class Unk_240f1b0 : public Unk_239a418, public Unk_1085320_Interface {
public:
    Unk_240f1b0(Unk_239a418_RefPair a0, Unk_239a418_Ref2<Unk_239a418> a1)
        : field_68(a0), field_80(a1) {}
    ~Unk_240f1b0() override;
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();

    Unk_239a418_RefPair field_68;
    u64 field_78 = 0;
    Unk_239a418_Ref2<Unk_239a418> field_80;
};
static_assert(sizeof(Unk_240f1b0) == 0x88, "Unk_240f1b0");
template Unk_240f1b0* Unk_New::Create<Unk_240f1b0>(Unk_239a418_Allocator*,
                                                   Unk_239a418_RefPair&&,
                                                   const Unk_Ref&);

// 0x7101097c40
class Unk_240f388 : public Unk_239a418, public Unk_1085320_Interface {
public:
    Unk_240f388(Unk_239a418_RefPair a0, Unk_239a418_Ref2<Unk_239a418> a1)
        : field_68(a0), field_80(a1) {}
    ~Unk_240f388() override;
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();

    Unk_239a418_RefPair field_68;
    u64 field_78 = 0;
    Unk_239a418_Ref2<Unk_239a418> field_80;
};
static_assert(sizeof(Unk_240f388) == 0x88, "Unk_240f388");
template Unk_240f388* Unk_New::Create<Unk_240f388>(Unk_239a418_Allocator*,
                                                   Unk_239a418_RefPair&&,
                                                   const Unk_Ref&);

// 0x710109a750
class Unk_240f840 : public Unk_239a418, public Unk_1085320_Interface {
public:
    Unk_240f840(Unk_239a418_RefPair a0, Unk_239a418_Ref2<Unk_239a418> a1)
        : field_68(a0), field_80(a1) {}
    ~Unk_240f840() override;
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();

    Unk_239a418_RefPair field_68;
    u64 field_78 = 0;
    Unk_239a418_Ref2<Unk_239a418> field_80;
};
static_assert(sizeof(Unk_240f840) == 0x88, "Unk_240f840");
template Unk_240f840* Unk_New::Create<Unk_240f840>(Unk_239a418_Allocator*,
                                                   Unk_239a418_RefPair&&,
                                                   const Unk_Ref&);

// 0x710109b320
class Unk_240f968 : public Unk_239a418, public Unk_1085320_Interface {
public:
    Unk_240f968(Unk_239a418_RefPair a0, const Unk_Ref& a1) : field_68(a0), field_80(a1) {}
    ~Unk_240f968() override;
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();

    Unk_239a418_RefPair field_68;
    u64 field_78 = 0;
    Unk_239a418_Ref2<Unk_239a418> field_80;
};
static_assert(sizeof(Unk_240f968) == 0x88, "Unk_240f968");
template Unk_240f968* Unk_New::Create<Unk_240f968>(Unk_239a418_Allocator*,
                                                   Unk_239a418_RefPair&&,
                                                   const Unk_Ref&);

// 0x710109ca30
class Unk_240fbc8 : public Unk_239a418, public Unk_1085320_Interface {
public:
    Unk_240fbc8(Unk_239a418_RefPair a0, Unk_239a418_Ref2<Unk_239a418> a1)
        : field_68(a0), field_80(a1) {}
    ~Unk_240fbc8() override;
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();

    Unk_239a418_RefPair field_68;
    u64 field_78 = 0;
    Unk_239a418_Ref2<Unk_239a418> field_80;
};
static_assert(sizeof(Unk_240fbc8) == 0x88, "Unk_240fbc8");
template Unk_240fbc8* Unk_New::Create<Unk_240fbc8>(Unk_239a418_Allocator*,
                                                   Unk_239a418_RefPair&&,
                                                   const Unk_Ref&);

// 0x710109e7f0
class Unk_240fcf0 : public Unk_239a418, public Unk_1085320_Interface {
public:
    Unk_240fcf0(Unk_239a418_Ref2<Unk_239a418> a0) : field_70(a0) {}
    ~Unk_240fcf0() override;
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();

    u8 field_68 = 0;
    Unk_239a418_Ref2<Unk_239a418> field_70;
};
static_assert(sizeof(Unk_240fcf0) == 0x78, "Unk_240fcf0");
template Unk_240fcf0* Unk_New::Create<Unk_240fcf0>(Unk_239a418_Allocator*, const Unk_Ref&);

// 0x710109f840
class Unk_240ff08 : public Unk_239a418, public Unk_1085320_Interface {
public:
    Unk_240ff08(Unk_239a418_Ref2<Unk_239a418> a0) : field_70(a0) {}
    ~Unk_240ff08() override;
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();

    u8 field_68 = 0;
    Unk_239a418_Ref2<Unk_239a418> field_70;
};
static_assert(sizeof(Unk_240ff08) == 0x78, "Unk_240ff08");
template Unk_240ff08* Unk_New::Create<Unk_240ff08>(Unk_239a418_Allocator*, const Unk_Ref&);

// 0x71010a0a60
class Unk_2410140 : public Unk_239a418, public Unk_1085320_Interface {
public:
    Unk_2410140(Unk_239a418_Ref2<Unk_239a418> a0) : field_70(a0) {}
    ~Unk_2410140() override;
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();

    u8 field_68 = 0;
    Unk_239a418_Ref2<Unk_239a418> field_70;
    u32 field_78 = 0;
};
static_assert(sizeof(Unk_2410140) == 0x80, "Unk_2410140");
template Unk_2410140* Unk_New::Create<Unk_2410140>(Unk_239a418_Allocator*, const Unk_Ref&);

// 0x71010a2f00
class Unk_24105d0 : public Unk_239a418, public Unk_1085320_Interface {
public:
    Unk_24105d0(Unk_239a418_Ref2<Unk_239a418> a0) : field_70(a0) {}
    ~Unk_24105d0() override;
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();

    u8 field_68 = 0;
    Unk_239a418_Ref2<Unk_239a418> field_70;
};
static_assert(sizeof(Unk_24105d0) == 0x78, "Unk_24105d0");
template Unk_24105d0* Unk_New::Create<Unk_24105d0>(Unk_239a418_Allocator*, const Unk_Ref&);

// 0x71010a3e60
class Unk_24107e8 : public Unk_239a418, public Unk_1085320_Interface {
public:
    Unk_24107e8(Unk_239a418_Ref2<Unk_239a418> a0) : field_70(a0) {}
    ~Unk_24107e8() override;
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();

    u8 field_68 = 0;
    Unk_239a418_Ref2<Unk_239a418> field_70;
    u32 field_78 = 0;
};
static_assert(sizeof(Unk_24107e8) == 0x80, "Unk_24107e8");
template Unk_24107e8* Unk_New::Create<Unk_24107e8>(Unk_239a418_Allocator*, const Unk_Ref&);

// 0x71010a5950
class Unk_24109d0 : public Unk_239a418, public Unk_1085320_Interface {
public:
    Unk_24109d0(Unk_239a418_Ref2<Unk_239a418> a0) : field_70(a0) {}
    ~Unk_24109d0() override;
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();

    u8 field_68 = 0;
    Unk_239a418_Ref2<Unk_239a418> field_70;
};
static_assert(sizeof(Unk_24109d0) == 0x78, "Unk_24109d0");
template Unk_24109d0* Unk_New::Create<Unk_24109d0>(Unk_239a418_Allocator*, const Unk_Ref&);

// 0x71010a6860
class Unk_2410c28 : public Unk_239a418, public Unk_1085320_Interface {
public:
    Unk_2410c28(Unk_239a418_Ref2<Unk_239a418> a0) : field_70(a0) {}
    ~Unk_2410c28() override;
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();

    u8 field_68 = 0;
    Unk_239a418_Ref2<Unk_239a418> field_70;
    u32 field_78 = 0;
};
static_assert(sizeof(Unk_2410c28) == 0x80, "Unk_2410c28");
template Unk_2410c28* Unk_New::Create<Unk_2410c28>(Unk_239a418_Allocator*, const Unk_Ref&);

// 0x71010a7de0
class Unk_2410e10 : public Unk_239a418, public Unk_1085320_Interface {
public:
    Unk_2410e10(Unk_239a418_Ref2<Unk_239a418> a0) : field_70(a0) {}
    ~Unk_2410e10() override;
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();

    u8 field_68 = 0;
    Unk_239a418_Ref2<Unk_239a418> field_70;
};
static_assert(sizeof(Unk_2410e10) == 0x78, "Unk_2410e10");
template Unk_2410e10* Unk_New::Create<Unk_2410e10>(Unk_239a418_Allocator*, const Unk_Ref&);

// 0x71010aa640
class Unk_2411500 : public Unk_239a418, public Unk_1085320_Interface {
public:
    Unk_2411500(Unk_239a418_Ref2<Unk_239a418> a0) : field_70(a0) {}
    ~Unk_2411500() override;
    virtual void vf6();
    virtual void vf7();

    u8 field_68 = 0;
    Unk_239a418_Ref2<Unk_239a418> field_70;
};
static_assert(sizeof(Unk_2411500) == 0x78, "Unk_2411500");
template Unk_2411500* Unk_New::Create<Unk_2411500>(Unk_239a418_Allocator*, const Unk_Ref&);

// 0x71010ae5d0
class Unk_24117b0 : public Unk_239a418, public Unk_1085320_Interface {
public:
    Unk_24117b0(Unk_239a418_RefPair a0) : field_68(a0) {}
    ~Unk_24117b0() override;
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();

    Unk_239a418_RefPair field_68;
    u64 field_78 = 0;
    u32 field_80 = 0;
};
static_assert(sizeof(Unk_24117b0) == 0x88, "Unk_24117b0");
template Unk_24117b0* Unk_New::Create<Unk_24117b0>(Unk_239a418_Allocator*, Unk_239a418_RefPair&&);

// 0x71010af0c0
class Unk_24118b0 : public Unk_239a418, public Unk_1085320_Interface {
public:
    Unk_24118b0(Unk_239a418_RefPair a0) : field_68(a0) {}
    ~Unk_24118b0() override;
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();

    Unk_239a418_RefPair field_68;
    u64 field_78 = 0;
    u32 field_80 = 0;
};
static_assert(sizeof(Unk_24118b0) == 0x88, "Unk_24118b0");
template Unk_24118b0* Unk_New::Create<Unk_24118b0>(Unk_239a418_Allocator*, Unk_239a418_RefPair&&);

// 0x71010afbb0
class Unk_24119b0 : public Unk_239a418, public Unk_1085320_Interface {
public:
    Unk_24119b0(Unk_239a418_RefPair a0) : field_68(a0) {}
    ~Unk_24119b0() override;
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();

    Unk_239a418_RefPair field_68;
    u64 field_78 = 0;
    u32 field_80 = 0;
};
static_assert(sizeof(Unk_24119b0) == 0x88, "Unk_24119b0");
template Unk_24119b0* Unk_New::Create<Unk_24119b0>(Unk_239a418_Allocator*, Unk_239a418_RefPair&&);

// 0x71010b06a0
class Unk_2411ab0 : public Unk_239a418, public Unk_1085320_Interface {
public:
    Unk_2411ab0(Unk_239a418_RefPair a0) : field_68(a0) {}
    ~Unk_2411ab0() override;
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();

    Unk_239a418_RefPair field_68;
    u64 field_78 = 0;
    u32 field_80 = 0;
};
static_assert(sizeof(Unk_2411ab0) == 0x88, "Unk_2411ab0");
template Unk_2411ab0* Unk_New::Create<Unk_2411ab0>(Unk_239a418_Allocator*, Unk_239a418_RefPair&&);

// 0x71010b1240
class Unk_2411bb0 : public Unk_239a418, public Unk_1085320_Interface {
public:
    Unk_2411bb0(Unk_239a418_RefPair a0) : field_68(a0) {}
    ~Unk_2411bb0() override;
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();

    Unk_239a418_RefPair field_68;
    u64 field_78 = 0;
    u32 field_80 = 0;
};
static_assert(sizeof(Unk_2411bb0) == 0x88, "Unk_2411bb0");
template Unk_2411bb0* Unk_New::Create<Unk_2411bb0>(Unk_239a418_Allocator*, Unk_239a418_RefPair&&);

// 0x71010b1d30
class Unk_2411cb0 : public Unk_239a418, public Unk_1085320_Interface {
public:
    Unk_2411cb0(Unk_239a418_RefPair a0) : field_68(a0) {}
    ~Unk_2411cb0() override;
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();

    Unk_239a418_RefPair field_68;
    u64 field_78 = 0;
    u32 field_80 = 0;
};
static_assert(sizeof(Unk_2411cb0) == 0x88, "Unk_2411cb0");
template Unk_2411cb0* Unk_New::Create<Unk_2411cb0>(Unk_239a418_Allocator*, Unk_239a418_RefPair&&);

// 0x71010b2820
class Unk_2411db0 : public Unk_239a418, public Unk_1085320_Interface {
public:
    Unk_2411db0(Unk_239a418_RefPair a0, const Unk_1085320_Words2& a1)
        : field_68(a0), field_80(a1) {}
    ~Unk_2411db0() override;
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();

    Unk_239a418_RefPair field_68;
    u64 field_78 = 0;
    Unk_1085320_Words2 field_80;
};
static_assert(sizeof(Unk_2411db0) == 0x90, "Unk_2411db0");
template Unk_2411db0* Unk_New::Create<Unk_2411db0>(Unk_239a418_Allocator*,
                                                   Unk_239a418_RefPair&&,
                                                   const Unk_1085320_Words2&);

// 0x71010b3360
class Unk_2411ed8 : public Unk_239a418, public Unk_1085320_Interface {
public:
    Unk_2411ed8(Unk_239a418_RefPair a0) : field_68(a0) {}
    ~Unk_2411ed8() override;
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();

    Unk_239a418_RefPair field_68;
    u64 field_78 = 0;
    u32 field_80 = 0;
};
static_assert(sizeof(Unk_2411ed8) == 0x88, "Unk_2411ed8");
template Unk_2411ed8* Unk_New::Create<Unk_2411ed8>(Unk_239a418_Allocator*, Unk_239a418_RefPair&&);

// 0x71010b3e50
class Unk_2411fd8 : public Unk_239a418, public Unk_1085320_Interface {
public:
    Unk_2411fd8(Unk_239a418_RefPair a0, const u32& a1) : field_68(a0), field_80(a1) {}
    ~Unk_2411fd8() override;
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();

    Unk_239a418_RefPair field_68;
    u64 field_78 = 0;
    u32 field_80;
    u32 field_84;
};
static_assert(sizeof(Unk_2411fd8) == 0x88, "Unk_2411fd8");
template Unk_2411fd8* Unk_New::Create<Unk_2411fd8>(Unk_239a418_Allocator*,
                                                   Unk_239a418_RefPair&&,
                                                   const u32&);

// 0x71010b4b90
class Unk_2412100 : public Unk_239a418, public Unk_1085320_Interface {
public:
    Unk_2412100(Unk_239a418_RefPair a0, u32 a1) : field_68(a0), field_80(a1) {}
    ~Unk_2412100() override;
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();

    Unk_239a418_RefPair field_68;
    u64 field_78 = 0;
    u32 field_80;
    u32 field_84;
};
static_assert(sizeof(Unk_2412100) == 0x88, "Unk_2412100");
template Unk_2412100* Unk_New::Create<Unk_2412100>(Unk_239a418_Allocator*,
                                                   Unk_239a418_RefPair&&,
                                                   const u32&);

// 0x71010b5800
class Unk_2412228 : public Unk_239a418, public Unk_1085320_Interface {
public:
    Unk_2412228(Unk_239a418_RefPair a0, const Unk_1085320_Words2& a1)
        : field_68(a0), field_80(a1) {}
    ~Unk_2412228() override;
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();

    Unk_239a418_RefPair field_68;
    u64 field_78 = 0;
    Unk_1085320_Words2 field_80;
};
static_assert(sizeof(Unk_2412228) == 0x90, "Unk_2412228");
template Unk_2412228* Unk_New::Create<Unk_2412228>(Unk_239a418_Allocator*,
                                                   Unk_239a418_RefPair&&,
                                                   const Unk_1085320_Words2&);

// 0x71010b6310
class Unk_2412328 : public Unk_239a418, public Unk_1085320_Interface {
public:
    Unk_2412328(Unk_239a418_RefPair a0) : field_68(a0) {}
    ~Unk_2412328() override;
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();

    Unk_239a418_RefPair field_68;
    u64 field_78 = 0;
    u32 field_80 = 0;
};
static_assert(sizeof(Unk_2412328) == 0x88, "Unk_2412328");
template Unk_2412328* Unk_New::Create<Unk_2412328>(Unk_239a418_Allocator*, Unk_239a418_RefPair&&);

// 0x71010b6e00
class Unk_2412428 : public Unk_239a418, public Unk_1085320_Interface {
public:
    Unk_2412428(Unk_239a418_RefPair a0) : field_68(a0) {}
    ~Unk_2412428() override;
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();

    Unk_239a418_RefPair field_68;
    u64 field_78 = 0;
    u32 field_80 = 0;
};
static_assert(sizeof(Unk_2412428) == 0x88, "Unk_2412428");
template Unk_2412428* Unk_New::Create<Unk_2412428>(Unk_239a418_Allocator*, Unk_239a418_RefPair&&);

// 0x71010b78f0
class Unk_2412528 : public Unk_239a418, public Unk_1085320_Interface {
public:
    Unk_2412528(Unk_239a418_RefPair a0) : field_68(a0) {}
    ~Unk_2412528() override;
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();

    Unk_239a418_RefPair field_68;
    u64 field_78 = 0;
    u32 field_80 = 0;
};
static_assert(sizeof(Unk_2412528) == 0x88, "Unk_2412528");
template Unk_2412528* Unk_New::Create<Unk_2412528>(Unk_239a418_Allocator*, Unk_239a418_RefPair&&);

// 0x71010bcdc0
class Unk_2412c88 : public Unk_239a418, public Unk_1085320_Interface {
public:
    Unk_2412c88(Unk_239a418_RefPair a0, Unk_239a418_Ref2<Unk_239a418> a1)
        : field_68(a0), field_80(a1) {}
    ~Unk_2412c88() override;
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();

    Unk_239a418_RefPair field_68;
    u64 field_78 = 0;
    Unk_239a418_Ref2<Unk_239a418> field_80;
};
static_assert(sizeof(Unk_2412c88) == 0x88, "Unk_2412c88");
template Unk_2412c88* Unk_New::Create<Unk_2412c88>(Unk_239a418_Allocator*,
                                                   Unk_239a418_RefPair&&,
                                                   const Unk_Ref&);

// 0x71010be6e0
class Unk_2412f10 : public Unk_239a418, public Unk_1085320_Interface {
public:
    Unk_2412f10(Unk_239a418_RefPair a0, Unk_239a418_Ref2<Unk_239a418> a1)
        : field_68(a0), field_80(a1) {}
    ~Unk_2412f10() override;
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();

    Unk_239a418_RefPair field_68;
    u64 field_78 = 0;
    Unk_239a418_Ref2<Unk_239a418> field_80;
};
static_assert(sizeof(Unk_2412f10) == 0x88, "Unk_2412f10");
template Unk_2412f10* Unk_New::Create<Unk_2412f10>(Unk_239a418_Allocator*,
                                                   Unk_239a418_RefPair&&,
                                                   const Unk_Ref&);

// 0x71010bfde0
class Unk_2413198 : public Unk_239a418, public Unk_1085320_Interface {
public:
    Unk_2413198(Unk_239a418_RefPair a0, Unk_239a418_Ref2<Unk_239a418> a1)
        : field_68(a0), field_80(a1) {}
    ~Unk_2413198() override;
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();

    Unk_239a418_RefPair field_68;
    u64 field_78 = 0;
    Unk_239a418_Ref2<Unk_239a418> field_80;
};
static_assert(sizeof(Unk_2413198) == 0x88, "Unk_2413198");
template Unk_2413198* Unk_New::Create<Unk_2413198>(Unk_239a418_Allocator*,
                                                   Unk_239a418_RefPair&&,
                                                   const Unk_Ref&);

// 0x71010c10a0
class Unk_2413370 : public Unk_239a418, public Unk_1085320_Interface {
public:
    Unk_2413370(Unk_239a418_RefPair a0, Unk_239a418_Ref2<Unk_239a418> a1)
        : field_68(a0), field_80(a1) {}
    ~Unk_2413370() override;
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();

    Unk_239a418_RefPair field_68;
    u64 field_78 = 0;
    Unk_239a418_Ref2<Unk_239a418> field_80;
};
static_assert(sizeof(Unk_2413370) == 0x88, "Unk_2413370");
template Unk_2413370* Unk_New::Create<Unk_2413370>(Unk_239a418_Allocator*,
                                                   Unk_239a418_RefPair&&,
                                                   const Unk_Ref&);

// 0x71010c2ce0
class Unk_2413498 : public Unk_239a418, public Unk_1085320_Interface {
public:
    Unk_2413498(Unk_239a418_Ref2<Unk_239a418> a0) : field_68(a0) {}
    ~Unk_2413498() override;
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();

    Unk_239a418_Ref2<Unk_239a418> field_68;
    u8 field_70 = 0;
};
static_assert(sizeof(Unk_2413498) == 0x78, "Unk_2413498");
template Unk_2413498* Unk_New::Create<Unk_2413498>(Unk_239a418_Allocator*, const Unk_Ref&);

// 0x71010c4850
class Unk_2413788 : public Unk_239a418, public Unk_1085320_Interface {
public:
    Unk_2413788(Unk_239a418_Ref2<Unk_239a418> a0) : field_70(a0) {}
    ~Unk_2413788() override;
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();

    u8 field_68 = 0;
    Unk_239a418_Ref2<Unk_239a418> field_70;
};
static_assert(sizeof(Unk_2413788) == 0x78, "Unk_2413788");
template Unk_2413788* Unk_New::Create<Unk_2413788>(Unk_239a418_Allocator*, const Unk_Ref&);

// 0x71010c5690
class Unk_2413960 : public Unk_239a418, public Unk_1085320_Interface {
public:
    Unk_2413960(Unk_239a418_Ref2<Unk_239a418> a0) : field_70(a0) {}
    ~Unk_2413960() override;
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();

    u8 field_68 = 0;
    Unk_239a418_Ref2<Unk_239a418> field_70;
};
static_assert(sizeof(Unk_2413960) == 0x78, "Unk_2413960");
template Unk_2413960* Unk_New::Create<Unk_2413960>(Unk_239a418_Allocator*, const Unk_Ref&);

// 0x71010c7860
class Unk_2413d48 : public Unk_239a418, public Unk_1085320_Interface {
public:
    Unk_2413d48(Unk_239a418_RefPair a0, Unk_239a418_Ref2<Unk_239a418> a1)
        : field_68(a0), field_80(a1) {}
    ~Unk_2413d48() override;
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();

    Unk_239a418_RefPair field_68;
    u64 field_78 = 0;
    Unk_239a418_Ref2<Unk_239a418> field_80;
};
static_assert(sizeof(Unk_2413d48) == 0x88, "Unk_2413d48");
template Unk_2413d48* Unk_New::Create<Unk_2413d48>(Unk_239a418_Allocator*,
                                                   Unk_239a418_RefPair&&,
                                                   const Unk_Ref&);

// 0x71010c9360
class Unk_2413fd0 : public Unk_239a418, public Unk_1085320_Interface {
public:
    Unk_2413fd0(Unk_239a418_RefPair a0, Unk_239a418_Ref2<Unk_239a418> a1)
        : field_68(a0), field_80(a1) {}
    ~Unk_2413fd0() override;
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();

    Unk_239a418_RefPair field_68;
    u64 field_78 = 0;
    Unk_239a418_Ref2<Unk_239a418> field_80;
};
static_assert(sizeof(Unk_2413fd0) == 0x88, "Unk_2413fd0");
template Unk_2413fd0* Unk_New::Create<Unk_2413fd0>(Unk_239a418_Allocator*,
                                                   Unk_239a418_RefPair&&,
                                                   const Unk_Ref&);

// 0x71010cccf0
class Unk_24141d8 : public Unk_239a418 {
public:
    Unk_24141d8(Unk_239a418_Ref2<Unk_239a418> a0) : field_60(a0) {}
    ~Unk_24141d8() override;
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();

    Unk_239a418_Ref2<Unk_239a418> field_60;
    u32 field_68 = 0;
};
static_assert(sizeof(Unk_24141d8) == 0x70, "Unk_24141d8");
template Unk_24141d8* Unk_New::Create<Unk_24141d8>(Unk_239a418_Allocator*, const Unk_Ref&);

// 0x71010ccf80
class Unk_24142a0 : public Unk_239a418 {
public:
    Unk_24142a0(Unk_239a418_Ref2<Unk_239a418> a0) : field_60(a0) {}
    ~Unk_24142a0() override;
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();

    Unk_239a418_Ref2<Unk_239a418> field_60;
    u64 field_68 = 0;
};
static_assert(sizeof(Unk_24142a0) == 0x70, "Unk_24142a0");
template Unk_24142a0* Unk_New::Create<Unk_24142a0>(Unk_239a418_Allocator*, const Unk_Ref&);

// 0x71010d0320
class Unk_2414608 : public Unk_239a418, public Unk_1085320_Interface {
public:
    Unk_2414608(Unk_239a418_RefPair a0) : field_68(a0) {}
    ~Unk_2414608() override;
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();

    Unk_239a418_RefPair field_68;
    u64 field_78 = 0;
    u32 field_80 = 0;
};
static_assert(sizeof(Unk_2414608) == 0x88, "Unk_2414608");
template Unk_2414608* Unk_New::Create<Unk_2414608>(Unk_239a418_Allocator*, Unk_239a418_RefPair&&);

// 0x71010d13f0
class Unk_24147b8 : public Unk_239a418, public Unk_1085320_Interface {
public:
    Unk_24147b8(Unk_239a418_RefPair a0) : field_68(a0) {}
    ~Unk_24147b8() override;
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();

    Unk_239a418_RefPair field_68;
    u64 field_78 = 0;
    u32 field_80 = 0;
};
static_assert(sizeof(Unk_24147b8) == 0x88, "Unk_24147b8");
template Unk_24147b8* Unk_New::Create<Unk_24147b8>(Unk_239a418_Allocator*, Unk_239a418_RefPair&&);

// 0x71010d1ee0
class Unk_24148b8 : public Unk_239a418, public Unk_1085320_Interface {
public:
    Unk_24148b8(Unk_239a418_RefPair a0, Unk_239a418_Ref2<Unk_239a418> a1)
        : field_68(a0), field_80(a1) {}
    ~Unk_24148b8() override;
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();

    Unk_239a418_RefPair field_68;
    u64 field_78 = 0;
    Unk_239a418_Ref2<Unk_239a418> field_80;
};
static_assert(sizeof(Unk_24148b8) == 0x88, "Unk_24148b8");
template Unk_24148b8* Unk_New::Create<Unk_24148b8>(Unk_239a418_Allocator*,
                                                   Unk_239a418_RefPair&&,
                                                   const Unk_Ref&);

// 0x71010d5c70
class Unk_2414d00 : public Unk_239a418, public Unk_1085320_Interface {
public:
    Unk_2414d00(Unk_239a418_RefPair a0, Unk_239a418_Ref2<Unk_239a418> a1)
        : field_68(a0), field_80(a1) {}
    ~Unk_2414d00() override;
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();

    Unk_239a418_RefPair field_68;
    u64 field_78 = 0;
    Unk_239a418_Ref2<Unk_239a418> field_80;
};
static_assert(sizeof(Unk_2414d00) == 0x88, "Unk_2414d00");
template Unk_2414d00* Unk_New::Create<Unk_2414d00>(Unk_239a418_Allocator*,
                                                   Unk_239a418_RefPair&&,
                                                   const Unk_Ref&);

// 0x71010d7fe0
class Unk_2415100 : public Unk_239a418, public Unk_1085320_Interface {
public:
    Unk_2415100(Unk_239a418_RefPair a0, Unk_239a418_Ref2<Unk_239a418> a1)
        : field_68(a0), field_80(a1) {}
    ~Unk_2415100() override;
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();

    Unk_239a418_RefPair field_68;
    u64 field_78 = 0;
    Unk_239a418_Ref2<Unk_239a418> field_80;
};
static_assert(sizeof(Unk_2415100) == 0x88, "Unk_2415100");
template Unk_2415100* Unk_New::Create<Unk_2415100>(Unk_239a418_Allocator*,
                                                   Unk_239a418_RefPair&&,
                                                   const Unk_Ref&);

// 0x71010d8bb0
class Unk_2415228 : public Unk_239a418, public Unk_1085320_Interface {
public:
    Unk_2415228(Unk_239a418_RefPair a0, const Unk_Ref& a1) : field_68(a0), field_80(a1) {}
    ~Unk_2415228() override;
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();

    Unk_239a418_RefPair field_68;
    u64 field_78 = 0;
    Unk_239a418_Ref2<Unk_239a418> field_80;
};
static_assert(sizeof(Unk_2415228) == 0x88, "Unk_2415228");
template Unk_2415228* Unk_New::Create<Unk_2415228>(Unk_239a418_Allocator*,
                                                   Unk_239a418_RefPair&&,
                                                   const Unk_Ref&);

// 0x71010dab20
class Unk_2415328 : public Unk_239a418, public Unk_1085320_Interface {
public:
    Unk_2415328(Unk_239a418_Ref2<Unk_239a418> a0) : field_70(a0) {}
    ~Unk_2415328() override;
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();

    u8 field_68 = 0;
    Unk_239a418_Ref2<Unk_239a418> field_70;
};
static_assert(sizeof(Unk_2415328) == 0x78, "Unk_2415328");
template Unk_2415328* Unk_New::Create<Unk_2415328>(Unk_239a418_Allocator*, const Unk_Ref&);

// 0x71010dbda0
class Unk_2415538 : public Unk_239a418, public Unk_1085320_Interface {
public:
    Unk_2415538(Unk_239a418_Ref2<Unk_239a418> a0) : field_70(a0) {}
    ~Unk_2415538() override;
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();

    u8 field_68 = 0;
    Unk_239a418_Ref2<Unk_239a418> field_70;
    u32 field_78 = 0;
};
static_assert(sizeof(Unk_2415538) == 0x80, "Unk_2415538");
template Unk_2415538* Unk_New::Create<Unk_2415538>(Unk_239a418_Allocator*, const Unk_Ref&);

// 0x71010decc0
class Unk_2415868 : public Unk_239a418, public Unk_1085320_Interface {
public:
    Unk_2415868(Unk_239a418_RefPair a0, Unk_239a418_Ref2<Unk_239a418> a1)
        : field_68(a0), field_80(a1) {}
    ~Unk_2415868() override;
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();

    Unk_239a418_RefPair field_68;
    u64 field_78 = 0;
    Unk_239a418_Ref2<Unk_239a418> field_80;
};
static_assert(sizeof(Unk_2415868) == 0x88, "Unk_2415868");
template Unk_2415868* Unk_New::Create<Unk_2415868>(Unk_239a418_Allocator*,
                                                   Unk_239a418_RefPair&&,
                                                   const Unk_Ref&);

// 0x71010dfee0
class Unk_2415a40 : public Unk_239a418, public Unk_1085320_Interface {
public:
    Unk_2415a40(Unk_239a418_RefPair a0, Unk_239a418_Ref2<Unk_239a418> a1)
        : field_68(a0), field_80(a1) {}
    ~Unk_2415a40() override;
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();

    Unk_239a418_RefPair field_68;
    u64 field_78 = 0;
    Unk_239a418_Ref2<Unk_239a418> field_80;
};
static_assert(sizeof(Unk_2415a40) == 0x88, "Unk_2415a40");
template Unk_2415a40* Unk_New::Create<Unk_2415a40>(Unk_239a418_Allocator*,
                                                   Unk_239a418_RefPair&&,
                                                   const Unk_Ref&);

// 0x71010e0d50
class Unk_2415b68 : public Unk_239a418, public Unk_1085320_Interface {
public:
    Unk_2415b68(Unk_239a418_RefPair a0, const u64& a1) : field_68(a0), field_80(a1) {}
    ~Unk_2415b68() override;
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();

    Unk_239a418_RefPair field_68;
    u64 field_78 = 0;
    u64 field_80;
};
static_assert(sizeof(Unk_2415b68) == 0x88, "Unk_2415b68");
template Unk_2415b68* Unk_New::Create<Unk_2415b68>(Unk_239a418_Allocator*,
                                                   Unk_239a418_RefPair&&,
                                                   const u64&);

// 0x71010e22b0
class Unk_2415df0 : public Unk_239a418, public Unk_1085320_Interface {
public:
    Unk_2415df0(Unk_239a418_RefPair a0, Unk_239a418_Ref2<Unk_239a418> a1)
        : field_68(a0), field_80(a1) {}
    ~Unk_2415df0() override;
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();

    Unk_239a418_RefPair field_68;
    u64 field_78 = 0;
    Unk_239a418_Ref2<Unk_239a418> field_80;
};
static_assert(sizeof(Unk_2415df0) == 0x88, "Unk_2415df0");
template Unk_2415df0* Unk_New::Create<Unk_2415df0>(Unk_239a418_Allocator*,
                                                   Unk_239a418_RefPair&&,
                                                   const Unk_Ref&);

// 0x71010e6dd0
class Unk_2416438 : public Unk_239a418, public Unk_1085320_Interface {
public:
    Unk_2416438(Unk_239a418_RefPair a0, Unk_239a418_Ref2<Unk_239a418> a1)
        : field_68(a0), field_80(a1) {}
    ~Unk_2416438() override;
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();

    Unk_239a418_RefPair field_68;
    u64 field_78 = 0;
    Unk_239a418_Ref2<Unk_239a418> field_80;
};
static_assert(sizeof(Unk_2416438) == 0x88, "Unk_2416438");
template Unk_2416438* Unk_New::Create<Unk_2416438>(Unk_239a418_Allocator*,
                                                   Unk_239a418_RefPair&&,
                                                   const Unk_Ref&);

// 0x71010e8530
class Unk_24166c0 : public Unk_239a418, public Unk_1085320_Interface {
public:
    Unk_24166c0(Unk_239a418_RefPair a0, Unk_239a418_Ref2<Unk_239a418> a1)
        : field_68(a0), field_80(a1) {}
    ~Unk_24166c0() override;
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();

    Unk_239a418_RefPair field_68;
    u64 field_78 = 0;
    Unk_239a418_Ref2<Unk_239a418> field_80;
};
static_assert(sizeof(Unk_24166c0) == 0x88, "Unk_24166c0");
template Unk_24166c0* Unk_New::Create<Unk_24166c0>(Unk_239a418_Allocator*,
                                                   Unk_239a418_RefPair&&,
                                                   const Unk_Ref&);

// 0x71010e93a0
class Unk_24167e8 : public Unk_239a418, public Unk_1085320_Interface {
public:
    Unk_24167e8(Unk_239a418_RefPair a0, const u64& a1) : field_68(a0), field_80(a1) {}
    ~Unk_24167e8() override;
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();

    Unk_239a418_RefPair field_68;
    u64 field_78 = 0;
    u64 field_80;
};
static_assert(sizeof(Unk_24167e8) == 0x88, "Unk_24167e8");
template Unk_24167e8* Unk_New::Create<Unk_24167e8>(Unk_239a418_Allocator*,
                                                   Unk_239a418_RefPair&&,
                                                   const u64&);

// 0x71010ec9f0
class Unk_2416cc8 : public Unk_239a418, public Unk_1085320_Interface {
public:
    Unk_2416cc8(Unk_239a418_RefPair a0, const Unk_1085320_Words5& a1)
        : field_68(a0), field_80(a1) {}
    ~Unk_2416cc8() override;
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();

    Unk_239a418_RefPair field_68;
    u64 field_78 = 0;
    Unk_1085320_Words5 field_80;
};
static_assert(sizeof(Unk_2416cc8) == 0xa8, "Unk_2416cc8");
template Unk_2416cc8* Unk_New::Create<Unk_2416cc8>(Unk_239a418_Allocator*,
                                                   Unk_239a418_RefPair&&,
                                                   const Unk_1085320_Words5&);

// 0x71010eec20
class Unk_24170c8 : public Unk_239a418, public Unk_1085320_Interface {
public:
    Unk_24170c8(Unk_239a418_RefPair a0, Unk_239a418_Ref2<Unk_239a418> a1)
        : field_68(a0), field_80(a1) {}
    ~Unk_24170c8() override;
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();

    Unk_239a418_RefPair field_68;
    u64 field_78 = 0;
    Unk_239a418_Ref2<Unk_239a418> field_80;
};
static_assert(sizeof(Unk_24170c8) == 0x88, "Unk_24170c8");
template Unk_24170c8* Unk_New::Create<Unk_24170c8>(Unk_239a418_Allocator*,
                                                   Unk_239a418_RefPair&&,
                                                   const Unk_Ref&);

// 0x71010ef7f0
class Unk_24171f0 : public Unk_239a418, public Unk_1085320_Interface {
public:
    Unk_24171f0(Unk_239a418_RefPair a0, const Unk_Ref& a1) : field_68(a0), field_80(a1) {}
    ~Unk_24171f0() override;
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();

    Unk_239a418_RefPair field_68;
    u64 field_78 = 0;
    Unk_239a418_Ref2<Unk_239a418> field_80;
};
static_assert(sizeof(Unk_24171f0) == 0x88, "Unk_24171f0");
template Unk_24171f0* Unk_New::Create<Unk_24171f0>(Unk_239a418_Allocator*,
                                                   Unk_239a418_RefPair&&,
                                                   const Unk_Ref&);

// 0x71010f1600
class Unk_24172f0 : public Unk_239a418, public Unk_1085320_Interface {
public:
    Unk_24172f0(Unk_239a418_Ref2<Unk_239a418> a0) : field_70(a0) {}
    ~Unk_24172f0() override;
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();

    u8 field_68 = 0;
    Unk_239a418_Ref2<Unk_239a418> field_70;
    u32 field_78 = 0;
};
static_assert(sizeof(Unk_24172f0) == 0x80, "Unk_24172f0");
template Unk_24172f0* Unk_New::Create<Unk_24172f0>(Unk_239a418_Allocator*, const Unk_Ref&);

// 0x71010f36a0
class Unk_2417870 : public Unk_239a418, public Unk_1085320_Interface {
public:
    Unk_2417870(Unk_239a418_RefPair a0, Unk_239a418_Ref2<Unk_239a418> a1)
        : field_68(a0), field_80(a1) {}
    ~Unk_2417870() override;
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();

    Unk_239a418_RefPair field_68;
    u64 field_78 = 0;
    Unk_239a418_Ref2<Unk_239a418> field_80;
};
static_assert(sizeof(Unk_2417870) == 0x88, "Unk_2417870");
template Unk_2417870* Unk_New::Create<Unk_2417870>(Unk_239a418_Allocator*,
                                                   Unk_239a418_RefPair&&,
                                                   const Unk_Ref&);

// 0x71011026d0
class Unk_24184a0 : public Unk_239a418, public Unk_1085320_Interface {
public:
    Unk_24184a0(Unk_239a418_RefPair a0, Unk_239a418_Ref2<Unk_239a418> a1)
        : field_68(a0), field_80(a1) {}
    ~Unk_24184a0() override;
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();

    Unk_239a418_RefPair field_68;
    u64 field_78 = 0;
    Unk_239a418_Ref2<Unk_239a418> field_80;
};
static_assert(sizeof(Unk_24184a0) == 0x88, "Unk_24184a0");
template Unk_24184a0* Unk_New::Create<Unk_24184a0>(Unk_239a418_Allocator*,
                                                   Unk_239a418_RefPair&&,
                                                   const Unk_Ref&);

// The adders. An owner of such objects (a class on the object, with its
// allocator at +0x60 and a list of references at +0xb0) makes one with a weak
// reference to itself (its handle and itself) and what it is given, keeps a
// reference to it in the list and returns a reference to itself: one member
// template, an instance per class. A set flag (+0x110, through the leaf getter
// 0x71006ce100) skips the rest. The list's emplace (0x7101054f70) isn't
// decompiled.
struct Unk_6ce100;
u32 Unk_6ce100_getField110(const Unk_6ce100* self);

struct Unk_1054f70_List {
    void Unk_1054f70(Unk_Ref&& ref);

    u8 _0[0x60];
};

// A weak reference to an object: its handle, and the object itself.
inline Unk_239a418_RefPair Unk_Weak(Unk_239a418* object) {
    if (object == nullptr)
        return Unk_239a418_RefPair{Unk_Ref(), 0};
    Unk_239a418_Ref<Unk_239a418_Handle> handle(object->m_handle);
    return Unk_239a418_RefPair{Unk_Ref(reinterpret_cast<Unk_239a418*>(handle.m_ptr)),
                               reinterpret_cast<u64>(object)};
}

class Unk_1050c60_Owner : public Unk_239a418 {
public:
    template <class T, class... Args>
    Unk_Ref Unk_Add(const Args&... args) {
        if (Unk_6ce100_getField110(reinterpret_cast<const Unk_6ce100*>(this)))
            return Unk_Ref(this);
        Unk_239a418_Allocator* allocator = field_60;
        Unk_Ref object(Unk_New().Create<T>(allocator, Unk_Weak(this), args...));
        field_b0.Unk_1054f70(Unk_Ref(object));
        return Unk_Ref(this);
    }

    Unk_239a418_Allocator* field_60;
    u8 _68[0x48];
    Unk_1054f70_List field_b0;
};
PKMN_OFFSET_ASSERT(Unk_1050c60_Owner, field_b0, 0xb0);

// 0x7101050c60
template Unk_Ref Unk_1050c60_Owner::Unk_Add<Unk_240b658>(const u32&);

// 0x71010519e0
template Unk_Ref Unk_1050c60_Owner::Unk_Add<Unk_240b970>(const u32&);

// 0x7101052410
template Unk_Ref Unk_1050c60_Owner::Unk_Add<Unk_240bc60>(const u32&);

// 0x7101052590
template Unk_Ref Unk_1050c60_Owner::Unk_Add<Unk_240bd60>(const Unk_1085320_Words3&);

// 0x7101052df0
template Unk_Ref Unk_1050c60_Owner::Unk_Add<Unk_240be88>();

// 0x710107c6f0
template Unk_Ref Unk_1050c60_Owner::Unk_Add<Unk_240d540>(const Unk_Ref&);

// 0x710107c870
template Unk_Ref Unk_1050c60_Owner::Unk_Add<Unk_240d668>(const Unk_Ref&);

// 0x710107d200
template Unk_Ref Unk_1050c60_Owner::Unk_Add<Unk_240d8f0>(const Unk_Ref&);

// 0x710107db80
template Unk_Ref Unk_1050c60_Owner::Unk_Add<Unk_240dc40>(const u32&);

// 0x710107dd00
template Unk_Ref Unk_1050c60_Owner::Unk_Add<Unk_240dd68>(const Unk_Ref&);

// 0x710107e610
template Unk_Ref Unk_1050c60_Owner::Unk_Add<Unk_240dfc8>(const Unk_Ref&);

// 0x710107e790
template Unk_Ref Unk_1050c60_Owner::Unk_Add<Unk_240e0f0>(const Unk_Ref&);

// 0x710107f090
template Unk_Ref Unk_1050c60_Owner::Unk_Add<Unk_240e350>(const Unk_Ref&);

// 0x710107fa20
template Unk_Ref Unk_1050c60_Owner::Unk_Add<Unk_240e6a0>(const Unk_Ref&);

// 0x710107fba0
template Unk_Ref Unk_1050c60_Owner::Unk_Add<Unk_240e7c8>(const Unk_Ref&);

// 0x7101080530
template Unk_Ref Unk_1050c60_Owner::Unk_Add<Unk_240eba0>(const Unk_Ref&);

// 0x71010806b0
template Unk_Ref Unk_1050c60_Owner::Unk_Add<Unk_240ecc8>(const Unk_Ref&);

// 0x7101080f80
template Unk_Ref Unk_1050c60_Owner::Unk_Add<Unk_240ef28>(const Unk_Ref&);

// 0x7101081860
template Unk_Ref Unk_1050c60_Owner::Unk_Add<Unk_240f1b0>(const Unk_Ref&);

// 0x7101082150
template Unk_Ref Unk_1050c60_Owner::Unk_Add<Unk_240f388>(const Unk_Ref&);

// 0x71010832c0
template Unk_Ref Unk_1050c60_Owner::Unk_Add<Unk_240f840>(const Unk_Ref&);

// 0x7101083440
template Unk_Ref Unk_1050c60_Owner::Unk_Add<Unk_240f968>(const Unk_Ref&);

// 0x7101083d10
template Unk_Ref Unk_1050c60_Owner::Unk_Add<Unk_240fbc8>(const Unk_Ref&);

// 0x71010aacf0
template Unk_Ref Unk_1050c60_Owner::Unk_Add<Unk_24117b0>();

// 0x71010aae70
template Unk_Ref Unk_1050c60_Owner::Unk_Add<Unk_24118b0>();

// 0x71010aaff0
template Unk_Ref Unk_1050c60_Owner::Unk_Add<Unk_24119b0>();

// 0x71010abac0
template Unk_Ref Unk_1050c60_Owner::Unk_Add<Unk_2411ab0>();

// 0x71010abc40
template Unk_Ref Unk_1050c60_Owner::Unk_Add<Unk_2411bb0>();

// 0x71010abdc0
template Unk_Ref Unk_1050c60_Owner::Unk_Add<Unk_2411cb0>();

// 0x71010abf40
template Unk_Ref Unk_1050c60_Owner::Unk_Add<Unk_2411db0>(const Unk_1085320_Words2&);

// 0x71010ac0c0
template Unk_Ref Unk_1050c60_Owner::Unk_Add<Unk_2411ed8>();

// 0x71010ac240
template Unk_Ref Unk_1050c60_Owner::Unk_Add<Unk_2411fd8>(const u32&);

// 0x71010ace90
template Unk_Ref Unk_1050c60_Owner::Unk_Add<Unk_2412100>(const u32&);

// 0x71010ad010
template Unk_Ref Unk_1050c60_Owner::Unk_Add<Unk_2412228>(const Unk_1085320_Words2&);

// 0x71010ad190
template Unk_Ref Unk_1050c60_Owner::Unk_Add<Unk_2412328>();

// 0x71010ad310
template Unk_Ref Unk_1050c60_Owner::Unk_Add<Unk_2412428>();

// 0x71010ad490
template Unk_Ref Unk_1050c60_Owner::Unk_Add<Unk_2412528>();

// 0x71010bab80
template Unk_Ref Unk_1050c60_Owner::Unk_Add<Unk_2412c88>(const Unk_Ref&);

// 0x71010bb510
template Unk_Ref Unk_1050c60_Owner::Unk_Add<Unk_2412f10>(const Unk_Ref&);

// 0x71010bbe90
template Unk_Ref Unk_1050c60_Owner::Unk_Add<Unk_2413198>(const Unk_Ref&);

// 0x71010bc820
template Unk_Ref Unk_1050c60_Owner::Unk_Add<Unk_2413370>(const Unk_Ref&);

// 0x71010c6090
template Unk_Ref Unk_1050c60_Owner::Unk_Add<Unk_2413d48>(const Unk_Ref&);

// 0x71010c6a40
template Unk_Ref Unk_1050c60_Owner::Unk_Add<Unk_2413fd0>(const Unk_Ref&);

// 0x71010ce480
template Unk_Ref Unk_1050c60_Owner::Unk_Add<Unk_2414608>();

// 0x71010cedf0
template Unk_Ref Unk_1050c60_Owner::Unk_Add<Unk_24147b8>();

// 0x71010cef70
template Unk_Ref Unk_1050c60_Owner::Unk_Add<Unk_24148b8>(const Unk_Ref&);

// 0x71010d43f0
template Unk_Ref Unk_1050c60_Owner::Unk_Add<Unk_2414d00>(const Unk_Ref&);

// 0x71010d4d90
template Unk_Ref Unk_1050c60_Owner::Unk_Add<Unk_2415100>(const Unk_Ref&);

// 0x71010d4f10
template Unk_Ref Unk_1050c60_Owner::Unk_Add<Unk_2415228>(const Unk_Ref&);

// 0x71010dc800
template Unk_Ref Unk_1050c60_Owner::Unk_Add<Unk_2415868>(const Unk_Ref&);

// 0x71010dd1a0
template Unk_Ref Unk_1050c60_Owner::Unk_Add<Unk_2415a40>(const Unk_Ref&);

// 0x71010ddab0
template Unk_Ref Unk_1050c60_Owner::Unk_Add<Unk_2415b68>(const u64&);

// 0x71010de430
template Unk_Ref Unk_1050c60_Owner::Unk_Add<Unk_2415df0>(const Unk_Ref&);

// 0x71010e5530
template Unk_Ref Unk_1050c60_Owner::Unk_Add<Unk_2416438>(const Unk_Ref&);

// 0x71010e5ec0
template Unk_Ref Unk_1050c60_Owner::Unk_Add<Unk_24166c0>(const Unk_Ref&);

// 0x71010e67d0
template Unk_Ref Unk_1050c60_Owner::Unk_Add<Unk_24167e8>(const u64&);

// 0x71010ebd60
template Unk_Ref Unk_1050c60_Owner::Unk_Add<Unk_2416cc8>(const Unk_1085320_Words5&);

// 0x71010ec6f0
template Unk_Ref Unk_1050c60_Owner::Unk_Add<Unk_24170c8>(const Unk_Ref&);

// 0x71010ec870
template Unk_Ref Unk_1050c60_Owner::Unk_Add<Unk_24171f0>(const Unk_Ref&);

// 0x71010f2b30
template Unk_Ref Unk_1050c60_Owner::Unk_Add<Unk_2417870>(const Unk_Ref&);

// 0x7101101cd0
template Unk_Ref Unk_1050c60_Owner::Unk_Add<Unk_24184a0>(const Unk_Ref&);
