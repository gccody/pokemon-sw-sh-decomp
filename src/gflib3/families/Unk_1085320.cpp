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

// A value that may be absent: the flag first.
template <class T>
struct Unk_1085320_Optional {
    Unk_1085320_Optional() : m_has(false) {}
    Unk_1085320_Optional(const Unk_1085320_Optional& other) : m_has(false) {
        if (other.m_has) {
            m_value = other.m_value;
            m_has = true;
        }
    }
    Unk_1085320_Optional& operator=(const Unk_1085320_Optional& other) {
        if (m_has) {
            if (other.m_has)
                m_value = other.m_value;
            else
                m_has = false;
        } else if (other.m_has) {
            m_value = other.m_value;
            m_has = true;
        }
        return *this;
    }

    bool m_has;
    T m_value;
};

// The interface at +0x60 of a step of a request (the steps, below): what its
// owner is told when the step is done, fails (with what a failure leaves,
// `Code`) or is cancelled.
template <class Code>
class Unk_1085320_Step {
public:
    virtual void vf9() = 0;
    virtual void vf10(Code code) = 0;
    virtual void vf11() = 0;
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
class Unk_240b658 : public Unk_239a418, public Unk_1085320_Step<const Unk_1085320_Optional<u32>*> {
public:
    Unk_240b658(Unk_239a418_RefPair a0, const u32& a1) : field_68(a0), field_80(a1) {}
    ~Unk_240b658() override;
    virtual void vf6();
    virtual u64 vf7();
    virtual void vf8();
    void vf9() override;
    void vf10(const Unk_1085320_Optional<u32>* code) override;
    void vf11() override;

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
class Unk_240b970 : public Unk_239a418, public Unk_1085320_Step<const Unk_1085320_Optional<u32>*> {
public:
    Unk_240b970(Unk_239a418_RefPair a0, const u32& a1) : field_68(a0), field_80(a1) {}
    ~Unk_240b970() override;
    virtual void vf6();
    virtual u64 vf7();
    virtual void vf8();
    void vf9() override;
    void vf10(const Unk_1085320_Optional<u32>* code) override;
    void vf11() override;

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
class Unk_240bc60 : public Unk_239a418, public Unk_1085320_Step<const Unk_1085320_Optional<u32>*> {
public:
    Unk_240bc60(Unk_239a418_RefPair a0, const u32& a1) : field_68(a0), field_80(a1) {}
    ~Unk_240bc60() override;
    virtual void vf6();
    virtual u64 vf7();
    virtual void vf8();
    void vf9() override;
    void vf10(const Unk_1085320_Optional<u32>* code) override;
    void vf11() override;

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
class Unk_240bd60 : public Unk_239a418, public Unk_1085320_Step<u64> {
public:
    Unk_240bd60(Unk_239a418_RefPair a0, const Unk_1085320_Words3& a1)
        : field_68(a0), field_80(a1) {}
    ~Unk_240bd60() override;
    virtual void vf6();
    virtual u64 vf7();
    virtual void vf8();
    void vf9() override;
    void vf10(u64 code) override;
    void vf11() override;

    Unk_239a418_RefPair field_68;
    u64 field_78 = 0;
    Unk_1085320_Words3 field_80;
};
static_assert(sizeof(Unk_240bd60) == 0x98, "Unk_240bd60");
template Unk_240bd60* Unk_New::Create<Unk_240bd60>(Unk_239a418_Allocator*,
                                                   Unk_239a418_RefPair&&,
                                                   const Unk_1085320_Words3&);

// 0x710105a590
class Unk_240be88 : public Unk_239a418, public Unk_1085320_Step<const Unk_1085320_Optional<u32>*> {
public:
    Unk_240be88(Unk_239a418_RefPair a0) : field_68(a0) {}
    ~Unk_240be88() override;
    virtual void vf6();
    virtual u64 vf7();
    virtual void vf8();
    void vf9() override;
    void vf10(const Unk_1085320_Optional<u32>* code) override;
    void vf11() override;

    Unk_239a418_RefPair field_68;
    u64 field_78 = 0;
    u32 field_80 = 0;
};
static_assert(sizeof(Unk_240be88) == 0x88, "Unk_240be88");
template Unk_240be88* Unk_New::Create<Unk_240be88>(Unk_239a418_Allocator*, Unk_239a418_RefPair&&);

// 0x7101085320
class Unk_240d540 : public Unk_239a418, public Unk_1085320_Step<u64> {
public:
    Unk_240d540(Unk_239a418_RefPair a0, Unk_239a418_Ref2<Unk_239a418> a1)
        : field_68(a0), field_80(a1) {}
    ~Unk_240d540() override;
    virtual void vf6();
    virtual u64 vf7();
    virtual void vf8();
    void vf9() override;
    void vf10(u64 code) override;
    void vf11() override;

    Unk_239a418_RefPair field_68;
    u64 field_78 = 0;
    Unk_239a418_Ref2<Unk_239a418> field_80;
};
static_assert(sizeof(Unk_240d540) == 0x88, "Unk_240d540");
template Unk_240d540* Unk_New::Create<Unk_240d540>(Unk_239a418_Allocator*,
                                                   Unk_239a418_RefPair&&,
                                                   const Unk_Ref&);

// 0x7101085f00
class Unk_240d668 : public Unk_239a418, public Unk_1085320_Step<const Unk_1085320_Optional<u32>*> {
public:
    Unk_240d668(Unk_239a418_RefPair a0, const Unk_Ref& a1) : field_68(a0), field_80(a1) {}
    ~Unk_240d668() override;
    virtual void vf6();
    virtual u64 vf7();
    virtual void vf8();
    void vf9() override;
    void vf10(const Unk_1085320_Optional<u32>* code) override;
    void vf11() override;

    Unk_239a418_RefPair field_68;
    u64 field_78 = 0;
    Unk_239a418_Ref2<Unk_239a418> field_80;
};
static_assert(sizeof(Unk_240d668) == 0x88, "Unk_240d668");
template Unk_240d668* Unk_New::Create<Unk_240d668>(Unk_239a418_Allocator*,
                                                   Unk_239a418_RefPair&&,
                                                   const Unk_Ref&);

// 0x71010875e0
class Unk_240d8f0 : public Unk_239a418, public Unk_1085320_Step<u64> {
public:
    Unk_240d8f0(Unk_239a418_RefPair a0, Unk_239a418_Ref2<Unk_239a418> a1)
        : field_68(a0), field_80(a1) {}
    ~Unk_240d8f0() override;
    virtual void vf6();
    virtual u64 vf7();
    virtual void vf8();
    void vf9() override;
    void vf10(u64 code) override;
    void vf11() override;

    Unk_239a418_RefPair field_68;
    u64 field_78 = 0;
    Unk_239a418_Ref2<Unk_239a418> field_80;
};
static_assert(sizeof(Unk_240d8f0) == 0x88, "Unk_240d8f0");
template Unk_240d8f0* Unk_New::Create<Unk_240d8f0>(Unk_239a418_Allocator*,
                                                   Unk_239a418_RefPair&&,
                                                   const Unk_Ref&);

// 0x71010892f0
class Unk_240dc40 : public Unk_239a418, public Unk_1085320_Step<u64> {
public:
    Unk_240dc40(Unk_239a418_RefPair a0, const u32& a1) : field_68(a0), field_80(a1) {}
    ~Unk_240dc40() override;
    virtual void vf6();
    virtual u64 vf7();
    virtual void vf8();
    void vf9() override;
    void vf10(u64 code) override;
    void vf11() override;

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
class Unk_240dd68 : public Unk_239a418, public Unk_1085320_Step<const Unk_1085320_Optional<u32>*> {
public:
    Unk_240dd68(Unk_239a418_RefPair a0, const Unk_Ref& a1) : field_68(a0), field_80(a1) {}
    ~Unk_240dd68() override;
    virtual void vf6();
    virtual u64 vf7();
    virtual void vf8();
    void vf9() override;
    void vf10(const Unk_1085320_Optional<u32>* code) override;
    void vf11() override;

    Unk_239a418_RefPair field_68;
    u64 field_78 = 0;
    Unk_239a418_Ref2<Unk_239a418> field_80;
};
static_assert(sizeof(Unk_240dd68) == 0x88, "Unk_240dd68");
template Unk_240dd68* Unk_New::Create<Unk_240dd68>(Unk_239a418_Allocator*,
                                                   Unk_239a418_RefPair&&,
                                                   const Unk_Ref&);

// 0x710108b600
class Unk_240dfc8 : public Unk_239a418, public Unk_1085320_Step<const Unk_1085320_Optional<u32>*> {
public:
    Unk_240dfc8(Unk_239a418_RefPair a0, Unk_239a418_Ref2<Unk_239a418> a1)
        : field_68(a0), field_80(a1) {}
    ~Unk_240dfc8() override;
    virtual void vf6();
    virtual u64 vf7();
    virtual void vf8();
    void vf9() override;
    void vf10(const Unk_1085320_Optional<u32>* code) override;
    void vf11() override;

    Unk_239a418_RefPair field_68;
    u64 field_78 = 0;
    Unk_239a418_Ref2<Unk_239a418> field_80;
};
static_assert(sizeof(Unk_240dfc8) == 0x88, "Unk_240dfc8");
template Unk_240dfc8* Unk_New::Create<Unk_240dfc8>(Unk_239a418_Allocator*,
                                                   Unk_239a418_RefPair&&,
                                                   const Unk_Ref&);

// 0x710108c250
class Unk_240e0f0 : public Unk_239a418, public Unk_1085320_Step<const Unk_1085320_Optional<u32>*> {
public:
    Unk_240e0f0(Unk_239a418_RefPair a0, const Unk_Ref& a1) : field_68(a0), field_80(a1) {}
    ~Unk_240e0f0() override;
    virtual void vf6();
    virtual u64 vf7();
    virtual void vf8();
    void vf9() override;
    void vf10(const Unk_1085320_Optional<u32>* code) override;
    void vf11() override;

    Unk_239a418_RefPair field_68;
    u64 field_78 = 0;
    Unk_239a418_Ref2<Unk_239a418> field_80;
};
static_assert(sizeof(Unk_240e0f0) == 0x88, "Unk_240e0f0");
template Unk_240e0f0* Unk_New::Create<Unk_240e0f0>(Unk_239a418_Allocator*,
                                                   Unk_239a418_RefPair&&,
                                                   const Unk_Ref&);

// 0x710108dc90
class Unk_240e350 : public Unk_239a418, public Unk_1085320_Step<const Unk_1085320_Optional<u32>*> {
public:
    Unk_240e350(Unk_239a418_RefPair a0, Unk_239a418_Ref2<Unk_239a418> a1)
        : field_68(a0), field_80(a1) {}
    ~Unk_240e350() override;
    virtual void vf6();
    virtual u64 vf7();
    virtual void vf8();
    void vf9() override;
    void vf10(const Unk_1085320_Optional<u32>* code) override;
    void vf11() override;

    Unk_239a418_RefPair field_68;
    u64 field_78 = 0;
    Unk_239a418_Ref2<Unk_239a418> field_80;
};
static_assert(sizeof(Unk_240e350) == 0x88, "Unk_240e350");
template Unk_240e350* Unk_New::Create<Unk_240e350>(Unk_239a418_Allocator*,
                                                   Unk_239a418_RefPair&&,
                                                   const Unk_Ref&);

// 0x710108fb20
class Unk_240e6a0 : public Unk_239a418, public Unk_1085320_Step<u64> {
public:
    Unk_240e6a0(Unk_239a418_RefPair a0, Unk_239a418_Ref2<Unk_239a418> a1)
        : field_68(a0), field_80(a1) {}
    ~Unk_240e6a0() override;
    virtual void vf6();
    virtual u64 vf7();
    virtual void vf8();
    void vf9() override;
    void vf10(u64 code) override;
    void vf11() override;

    Unk_239a418_RefPair field_68;
    u64 field_78 = 0;
    Unk_239a418_Ref2<Unk_239a418> field_80;
};
static_assert(sizeof(Unk_240e6a0) == 0x88, "Unk_240e6a0");
template Unk_240e6a0* Unk_New::Create<Unk_240e6a0>(Unk_239a418_Allocator*,
                                                   Unk_239a418_RefPair&&,
                                                   const Unk_Ref&);

// 0x71010906f0
class Unk_240e7c8 : public Unk_239a418, public Unk_1085320_Step<const Unk_1085320_Optional<u32>*> {
public:
    Unk_240e7c8(Unk_239a418_RefPair a0, const Unk_Ref& a1) : field_68(a0), field_80(a1) {}
    ~Unk_240e7c8() override;
    virtual void vf6();
    virtual u64 vf7();
    virtual void vf8();
    void vf9() override;
    void vf10(const Unk_1085320_Optional<u32>* code) override;
    void vf11() override;

    Unk_239a418_RefPair field_68;
    u64 field_78 = 0;
    Unk_239a418_Ref2<Unk_239a418> field_80;
};
static_assert(sizeof(Unk_240e7c8) == 0x88, "Unk_240e7c8");
template Unk_240e7c8* Unk_New::Create<Unk_240e7c8>(Unk_239a418_Allocator*,
                                                   Unk_239a418_RefPair&&,
                                                   const Unk_Ref&);

// 0x7101092a10
class Unk_240eba0 : public Unk_239a418, public Unk_1085320_Step<u64> {
public:
    Unk_240eba0(Unk_239a418_RefPair a0, Unk_239a418_Ref2<Unk_239a418> a1)
        : field_68(a0), field_80(a1) {}
    ~Unk_240eba0() override;
    virtual void vf6();
    virtual u64 vf7();
    virtual void vf8();
    void vf9() override;
    void vf10(u64 code) override;
    void vf11() override;

    Unk_239a418_RefPair field_68;
    u64 field_78 = 0;
    Unk_239a418_Ref2<Unk_239a418> field_80;
};
static_assert(sizeof(Unk_240eba0) == 0x88, "Unk_240eba0");
template Unk_240eba0* Unk_New::Create<Unk_240eba0>(Unk_239a418_Allocator*,
                                                   Unk_239a418_RefPair&&,
                                                   const Unk_Ref&);

// 0x71010935e0
class Unk_240ecc8 : public Unk_239a418, public Unk_1085320_Step<const Unk_1085320_Optional<u32>*> {
public:
    Unk_240ecc8(Unk_239a418_RefPair a0, const Unk_Ref& a1) : field_68(a0), field_80(a1) {}
    ~Unk_240ecc8() override;
    virtual void vf6();
    virtual u64 vf7();
    virtual void vf8();
    void vf9() override;
    void vf10(const Unk_1085320_Optional<u32>* code) override;
    void vf11() override;

    Unk_239a418_RefPair field_68;
    u64 field_78 = 0;
    Unk_239a418_Ref2<Unk_239a418> field_80;
};
static_assert(sizeof(Unk_240ecc8) == 0x88, "Unk_240ecc8");
template Unk_240ecc8* Unk_New::Create<Unk_240ecc8>(Unk_239a418_Allocator*,
                                                   Unk_239a418_RefPair&&,
                                                   const Unk_Ref&);

// 0x7101094dd0
class Unk_240ef28 : public Unk_239a418, public Unk_1085320_Step<const Unk_1085320_Optional<u32>*> {
public:
    Unk_240ef28(Unk_239a418_RefPair a0, Unk_239a418_Ref2<Unk_239a418> a1)
        : field_68(a0), field_80(a1) {}
    ~Unk_240ef28() override;
    virtual void vf6();
    virtual u64 vf7();
    virtual void vf8();
    void vf9() override;
    void vf10(const Unk_1085320_Optional<u32>* code) override;
    void vf11() override;

    Unk_239a418_RefPair field_68;
    u64 field_78 = 0;
    Unk_239a418_Ref2<Unk_239a418> field_80;
};
static_assert(sizeof(Unk_240ef28) == 0x88, "Unk_240ef28");
template Unk_240ef28* Unk_New::Create<Unk_240ef28>(Unk_239a418_Allocator*,
                                                   Unk_239a418_RefPair&&,
                                                   const Unk_Ref&);

// 0x7101096980
class Unk_240f1b0 : public Unk_239a418, public Unk_1085320_Step<const Unk_1085320_Optional<u32>*> {
public:
    Unk_240f1b0(Unk_239a418_RefPair a0, Unk_239a418_Ref2<Unk_239a418> a1)
        : field_68(a0), field_80(a1) {}
    ~Unk_240f1b0() override;
    virtual void vf6();
    virtual u64 vf7();
    virtual void vf8();
    void vf9() override;
    void vf10(const Unk_1085320_Optional<u32>* code) override;
    void vf11() override;

    Unk_239a418_RefPair field_68;
    u64 field_78 = 0;
    Unk_239a418_Ref2<Unk_239a418> field_80;
};
static_assert(sizeof(Unk_240f1b0) == 0x88, "Unk_240f1b0");
template Unk_240f1b0* Unk_New::Create<Unk_240f1b0>(Unk_239a418_Allocator*,
                                                   Unk_239a418_RefPair&&,
                                                   const Unk_Ref&);

// 0x7101097c40
class Unk_240f388 : public Unk_239a418, public Unk_1085320_Step<const Unk_1085320_Optional<u32>*> {
public:
    Unk_240f388(Unk_239a418_RefPair a0, Unk_239a418_Ref2<Unk_239a418> a1)
        : field_68(a0), field_80(a1) {}
    ~Unk_240f388() override;
    virtual void vf6();
    virtual u64 vf7();
    virtual void vf8();
    void vf9() override;
    void vf10(const Unk_1085320_Optional<u32>* code) override;
    void vf11() override;

    Unk_239a418_RefPair field_68;
    u64 field_78 = 0;
    Unk_239a418_Ref2<Unk_239a418> field_80;
};
static_assert(sizeof(Unk_240f388) == 0x88, "Unk_240f388");
template Unk_240f388* Unk_New::Create<Unk_240f388>(Unk_239a418_Allocator*,
                                                   Unk_239a418_RefPair&&,
                                                   const Unk_Ref&);

// 0x710109a750
class Unk_240f840 : public Unk_239a418, public Unk_1085320_Step<u64> {
public:
    Unk_240f840(Unk_239a418_RefPair a0, Unk_239a418_Ref2<Unk_239a418> a1)
        : field_68(a0), field_80(a1) {}
    ~Unk_240f840() override;
    virtual void vf6();
    virtual u64 vf7();
    virtual void vf8();
    void vf9() override;
    void vf10(u64 code) override;
    void vf11() override;

    Unk_239a418_RefPair field_68;
    u64 field_78 = 0;
    Unk_239a418_Ref2<Unk_239a418> field_80;
};
static_assert(sizeof(Unk_240f840) == 0x88, "Unk_240f840");
template Unk_240f840* Unk_New::Create<Unk_240f840>(Unk_239a418_Allocator*,
                                                   Unk_239a418_RefPair&&,
                                                   const Unk_Ref&);

// 0x710109b320
class Unk_240f968 : public Unk_239a418, public Unk_1085320_Step<const Unk_1085320_Optional<u32>*> {
public:
    Unk_240f968(Unk_239a418_RefPair a0, const Unk_Ref& a1) : field_68(a0), field_80(a1) {}
    ~Unk_240f968() override;
    virtual void vf6();
    virtual u64 vf7();
    virtual void vf8();
    void vf9() override;
    void vf10(const Unk_1085320_Optional<u32>* code) override;
    void vf11() override;

    Unk_239a418_RefPair field_68;
    u64 field_78 = 0;
    Unk_239a418_Ref2<Unk_239a418> field_80;
};
static_assert(sizeof(Unk_240f968) == 0x88, "Unk_240f968");
template Unk_240f968* Unk_New::Create<Unk_240f968>(Unk_239a418_Allocator*,
                                                   Unk_239a418_RefPair&&,
                                                   const Unk_Ref&);

// 0x710109ca30
class Unk_240fbc8 : public Unk_239a418, public Unk_1085320_Step<const Unk_1085320_Optional<u32>*> {
public:
    Unk_240fbc8(Unk_239a418_RefPair a0, Unk_239a418_Ref2<Unk_239a418> a1)
        : field_68(a0), field_80(a1) {}
    ~Unk_240fbc8() override;
    virtual void vf6();
    virtual u64 vf7();
    virtual void vf8();
    void vf9() override;
    void vf10(const Unk_1085320_Optional<u32>* code) override;
    void vf11() override;

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
class Unk_24117b0 : public Unk_239a418, public Unk_1085320_Step<const Unk_1085320_Optional<u32>*> {
public:
    Unk_24117b0(Unk_239a418_RefPair a0) : field_68(a0) {}
    ~Unk_24117b0() override;
    virtual void vf6();
    virtual u64 vf7();
    virtual void vf8();
    void vf9() override;
    void vf10(const Unk_1085320_Optional<u32>* code) override;
    void vf11() override;

    Unk_239a418_RefPair field_68;
    u64 field_78 = 0;
    u32 field_80 = 0;
};
static_assert(sizeof(Unk_24117b0) == 0x88, "Unk_24117b0");
template Unk_24117b0* Unk_New::Create<Unk_24117b0>(Unk_239a418_Allocator*, Unk_239a418_RefPair&&);

// 0x71010af0c0
class Unk_24118b0 : public Unk_239a418, public Unk_1085320_Step<const Unk_1085320_Optional<u32>*> {
public:
    Unk_24118b0(Unk_239a418_RefPair a0) : field_68(a0) {}
    ~Unk_24118b0() override;
    virtual void vf6();
    virtual u64 vf7();
    virtual void vf8();
    void vf9() override;
    void vf10(const Unk_1085320_Optional<u32>* code) override;
    void vf11() override;

    Unk_239a418_RefPair field_68;
    u64 field_78 = 0;
    u32 field_80 = 0;
};
static_assert(sizeof(Unk_24118b0) == 0x88, "Unk_24118b0");
template Unk_24118b0* Unk_New::Create<Unk_24118b0>(Unk_239a418_Allocator*, Unk_239a418_RefPair&&);

// 0x71010afbb0
class Unk_24119b0 : public Unk_239a418, public Unk_1085320_Step<const Unk_1085320_Optional<u32>*> {
public:
    Unk_24119b0(Unk_239a418_RefPair a0) : field_68(a0) {}
    ~Unk_24119b0() override;
    virtual void vf6();
    virtual u64 vf7();
    virtual void vf8();
    void vf9() override;
    void vf10(const Unk_1085320_Optional<u32>* code) override;
    void vf11() override;

    Unk_239a418_RefPair field_68;
    u64 field_78 = 0;
    u32 field_80 = 0;
};
static_assert(sizeof(Unk_24119b0) == 0x88, "Unk_24119b0");
template Unk_24119b0* Unk_New::Create<Unk_24119b0>(Unk_239a418_Allocator*, Unk_239a418_RefPair&&);

// 0x71010b06a0
class Unk_2411ab0 : public Unk_239a418, public Unk_1085320_Step<const Unk_1085320_Optional<u32>*> {
public:
    Unk_2411ab0(Unk_239a418_RefPair a0) : field_68(a0) {}
    ~Unk_2411ab0() override;
    virtual void vf6();
    virtual u64 vf7();
    virtual void vf8();
    void vf9() override;
    void vf10(const Unk_1085320_Optional<u32>* code) override;
    void vf11() override;

    Unk_239a418_RefPair field_68;
    u64 field_78 = 0;
    u32 field_80 = 0;
};
static_assert(sizeof(Unk_2411ab0) == 0x88, "Unk_2411ab0");
template Unk_2411ab0* Unk_New::Create<Unk_2411ab0>(Unk_239a418_Allocator*, Unk_239a418_RefPair&&);

// 0x71010b1240
class Unk_2411bb0 : public Unk_239a418, public Unk_1085320_Step<const Unk_1085320_Optional<u32>*> {
public:
    Unk_2411bb0(Unk_239a418_RefPair a0) : field_68(a0) {}
    ~Unk_2411bb0() override;
    virtual void vf6();
    virtual u64 vf7();
    virtual void vf8();
    void vf9() override;
    void vf10(const Unk_1085320_Optional<u32>* code) override;
    void vf11() override;

    Unk_239a418_RefPair field_68;
    u64 field_78 = 0;
    u32 field_80 = 0;
};
static_assert(sizeof(Unk_2411bb0) == 0x88, "Unk_2411bb0");
template Unk_2411bb0* Unk_New::Create<Unk_2411bb0>(Unk_239a418_Allocator*, Unk_239a418_RefPair&&);

// 0x71010b1d30
class Unk_2411cb0 : public Unk_239a418, public Unk_1085320_Step<const Unk_1085320_Optional<u32>*> {
public:
    Unk_2411cb0(Unk_239a418_RefPair a0) : field_68(a0) {}
    ~Unk_2411cb0() override;
    virtual void vf6();
    virtual u64 vf7();
    virtual void vf8();
    void vf9() override;
    void vf10(const Unk_1085320_Optional<u32>* code) override;
    void vf11() override;

    Unk_239a418_RefPair field_68;
    u64 field_78 = 0;
    u32 field_80 = 0;
};
static_assert(sizeof(Unk_2411cb0) == 0x88, "Unk_2411cb0");
template Unk_2411cb0* Unk_New::Create<Unk_2411cb0>(Unk_239a418_Allocator*, Unk_239a418_RefPair&&);

// 0x71010b2820
class Unk_2411db0 : public Unk_239a418, public Unk_1085320_Step<const Unk_1085320_Optional<u32>*> {
public:
    Unk_2411db0(Unk_239a418_RefPair a0, const Unk_1085320_Words2& a1)
        : field_68(a0), field_80(a1) {}
    ~Unk_2411db0() override;
    virtual void vf6();
    virtual u64 vf7();
    virtual void vf8();
    void vf9() override;
    void vf10(const Unk_1085320_Optional<u32>* code) override;
    void vf11() override;

    Unk_239a418_RefPair field_68;
    u64 field_78 = 0;
    Unk_1085320_Words2 field_80;
};
static_assert(sizeof(Unk_2411db0) == 0x90, "Unk_2411db0");
template Unk_2411db0* Unk_New::Create<Unk_2411db0>(Unk_239a418_Allocator*,
                                                   Unk_239a418_RefPair&&,
                                                   const Unk_1085320_Words2&);

// 0x71010b3360
class Unk_2411ed8 : public Unk_239a418, public Unk_1085320_Step<const Unk_1085320_Optional<u32>*> {
public:
    Unk_2411ed8(Unk_239a418_RefPair a0) : field_68(a0) {}
    ~Unk_2411ed8() override;
    virtual void vf6();
    virtual u64 vf7();
    virtual void vf8();
    void vf9() override;
    void vf10(const Unk_1085320_Optional<u32>* code) override;
    void vf11() override;

    Unk_239a418_RefPair field_68;
    u64 field_78 = 0;
    u32 field_80 = 0;
};
static_assert(sizeof(Unk_2411ed8) == 0x88, "Unk_2411ed8");
template Unk_2411ed8* Unk_New::Create<Unk_2411ed8>(Unk_239a418_Allocator*, Unk_239a418_RefPair&&);

// 0x71010b3e50
class Unk_2411fd8 : public Unk_239a418, public Unk_1085320_Step<const Unk_1085320_Optional<u32>*> {
public:
    Unk_2411fd8(Unk_239a418_RefPair a0, const u32& a1) : field_68(a0), field_80(a1) {}
    ~Unk_2411fd8() override;
    virtual void vf6();
    virtual u64 vf7();
    virtual void vf8();
    void vf9() override;
    void vf10(const Unk_1085320_Optional<u32>* code) override;
    void vf11() override;

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
class Unk_2412100 : public Unk_239a418, public Unk_1085320_Step<const Unk_1085320_Optional<u32>*> {
public:
    Unk_2412100(Unk_239a418_RefPair a0, u32 a1) : field_68(a0), field_80(a1) {}
    ~Unk_2412100() override;
    virtual void vf6();
    virtual u64 vf7();
    virtual void vf8();
    void vf9() override;
    void vf10(const Unk_1085320_Optional<u32>* code) override;
    void vf11() override;

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
class Unk_2412228 : public Unk_239a418, public Unk_1085320_Step<const Unk_1085320_Optional<u32>*> {
public:
    Unk_2412228(Unk_239a418_RefPair a0, const Unk_1085320_Words2& a1)
        : field_68(a0), field_80(a1) {}
    ~Unk_2412228() override;
    virtual void vf6();
    virtual u64 vf7();
    virtual void vf8();
    void vf9() override;
    void vf10(const Unk_1085320_Optional<u32>* code) override;
    void vf11() override;

    Unk_239a418_RefPair field_68;
    u64 field_78 = 0;
    Unk_1085320_Words2 field_80;
};
static_assert(sizeof(Unk_2412228) == 0x90, "Unk_2412228");
template Unk_2412228* Unk_New::Create<Unk_2412228>(Unk_239a418_Allocator*,
                                                   Unk_239a418_RefPair&&,
                                                   const Unk_1085320_Words2&);

// 0x71010b6310
class Unk_2412328 : public Unk_239a418, public Unk_1085320_Step<const Unk_1085320_Optional<u32>*> {
public:
    Unk_2412328(Unk_239a418_RefPair a0) : field_68(a0) {}
    ~Unk_2412328() override;
    virtual void vf6();
    virtual u64 vf7();
    virtual void vf8();
    void vf9() override;
    void vf10(const Unk_1085320_Optional<u32>* code) override;
    void vf11() override;

    Unk_239a418_RefPair field_68;
    u64 field_78 = 0;
    u32 field_80 = 0;
};
static_assert(sizeof(Unk_2412328) == 0x88, "Unk_2412328");
template Unk_2412328* Unk_New::Create<Unk_2412328>(Unk_239a418_Allocator*, Unk_239a418_RefPair&&);

// 0x71010b6e00
class Unk_2412428 : public Unk_239a418, public Unk_1085320_Step<const Unk_1085320_Optional<u32>*> {
public:
    Unk_2412428(Unk_239a418_RefPair a0) : field_68(a0) {}
    ~Unk_2412428() override;
    virtual void vf6();
    virtual u64 vf7();
    virtual void vf8();
    void vf9() override;
    void vf10(const Unk_1085320_Optional<u32>* code) override;
    void vf11() override;

    Unk_239a418_RefPair field_68;
    u64 field_78 = 0;
    u32 field_80 = 0;
};
static_assert(sizeof(Unk_2412428) == 0x88, "Unk_2412428");
template Unk_2412428* Unk_New::Create<Unk_2412428>(Unk_239a418_Allocator*, Unk_239a418_RefPair&&);

// 0x71010b78f0
class Unk_2412528 : public Unk_239a418, public Unk_1085320_Step<const Unk_1085320_Optional<u32>*> {
public:
    Unk_2412528(Unk_239a418_RefPair a0) : field_68(a0) {}
    ~Unk_2412528() override;
    virtual void vf6();
    virtual u64 vf7();
    virtual void vf8();
    void vf9() override;
    void vf10(const Unk_1085320_Optional<u32>* code) override;
    void vf11() override;

    Unk_239a418_RefPair field_68;
    u64 field_78 = 0;
    u32 field_80 = 0;
};
static_assert(sizeof(Unk_2412528) == 0x88, "Unk_2412528");
template Unk_2412528* Unk_New::Create<Unk_2412528>(Unk_239a418_Allocator*, Unk_239a418_RefPair&&);

// 0x71010bcdc0
class Unk_2412c88 : public Unk_239a418, public Unk_1085320_Step<const Unk_1085320_Optional<u32>*> {
public:
    Unk_2412c88(Unk_239a418_RefPair a0, Unk_239a418_Ref2<Unk_239a418> a1)
        : field_68(a0), field_80(a1) {}
    ~Unk_2412c88() override;
    virtual void vf6();
    virtual u64 vf7();
    virtual void vf8();
    void vf9() override;
    void vf10(const Unk_1085320_Optional<u32>* code) override;
    void vf11() override;

    Unk_239a418_RefPair field_68;
    u64 field_78 = 0;
    Unk_239a418_Ref2<Unk_239a418> field_80;
};
static_assert(sizeof(Unk_2412c88) == 0x88, "Unk_2412c88");
template Unk_2412c88* Unk_New::Create<Unk_2412c88>(Unk_239a418_Allocator*,
                                                   Unk_239a418_RefPair&&,
                                                   const Unk_Ref&);

// 0x71010be6e0
class Unk_2412f10 : public Unk_239a418, public Unk_1085320_Step<const Unk_1085320_Optional<u32>*> {
public:
    Unk_2412f10(Unk_239a418_RefPair a0, Unk_239a418_Ref2<Unk_239a418> a1)
        : field_68(a0), field_80(a1) {}
    ~Unk_2412f10() override;
    virtual void vf6();
    virtual u64 vf7();
    virtual void vf8();
    void vf9() override;
    void vf10(const Unk_1085320_Optional<u32>* code) override;
    void vf11() override;

    Unk_239a418_RefPair field_68;
    u64 field_78 = 0;
    Unk_239a418_Ref2<Unk_239a418> field_80;
};
static_assert(sizeof(Unk_2412f10) == 0x88, "Unk_2412f10");
template Unk_2412f10* Unk_New::Create<Unk_2412f10>(Unk_239a418_Allocator*,
                                                   Unk_239a418_RefPair&&,
                                                   const Unk_Ref&);

// 0x71010bfde0
class Unk_2413198 : public Unk_239a418, public Unk_1085320_Step<const Unk_1085320_Optional<u32>*> {
public:
    Unk_2413198(Unk_239a418_RefPair a0, Unk_239a418_Ref2<Unk_239a418> a1)
        : field_68(a0), field_80(a1) {}
    ~Unk_2413198() override;
    virtual void vf6();
    virtual u64 vf7();
    virtual void vf8();
    void vf9() override;
    void vf10(const Unk_1085320_Optional<u32>* code) override;
    void vf11() override;

    Unk_239a418_RefPair field_68;
    u64 field_78 = 0;
    Unk_239a418_Ref2<Unk_239a418> field_80;
};
static_assert(sizeof(Unk_2413198) == 0x88, "Unk_2413198");
template Unk_2413198* Unk_New::Create<Unk_2413198>(Unk_239a418_Allocator*,
                                                   Unk_239a418_RefPair&&,
                                                   const Unk_Ref&);

// 0x71010c10a0
class Unk_2413370 : public Unk_239a418, public Unk_1085320_Step<const Unk_1085320_Optional<u32>*> {
public:
    Unk_2413370(Unk_239a418_RefPair a0, Unk_239a418_Ref2<Unk_239a418> a1)
        : field_68(a0), field_80(a1) {}
    ~Unk_2413370() override;
    virtual void vf6();
    virtual u64 vf7();
    virtual void vf8();
    void vf9() override;
    void vf10(const Unk_1085320_Optional<u32>* code) override;
    void vf11() override;

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
class Unk_2413d48 : public Unk_239a418, public Unk_1085320_Step<const Unk_1085320_Optional<u32>*> {
public:
    Unk_2413d48(Unk_239a418_RefPair a0, Unk_239a418_Ref2<Unk_239a418> a1)
        : field_68(a0), field_80(a1) {}
    ~Unk_2413d48() override;
    virtual void vf6();
    virtual u64 vf7();
    virtual void vf8();
    void vf9() override;
    void vf10(const Unk_1085320_Optional<u32>* code) override;
    void vf11() override;

    Unk_239a418_RefPair field_68;
    u64 field_78 = 0;
    Unk_239a418_Ref2<Unk_239a418> field_80;
};
static_assert(sizeof(Unk_2413d48) == 0x88, "Unk_2413d48");
template Unk_2413d48* Unk_New::Create<Unk_2413d48>(Unk_239a418_Allocator*,
                                                   Unk_239a418_RefPair&&,
                                                   const Unk_Ref&);

// 0x71010c9360
class Unk_2413fd0 : public Unk_239a418, public Unk_1085320_Step<const Unk_1085320_Optional<u32>*> {
public:
    Unk_2413fd0(Unk_239a418_RefPair a0, Unk_239a418_Ref2<Unk_239a418> a1)
        : field_68(a0), field_80(a1) {}
    ~Unk_2413fd0() override;
    virtual void vf6();
    virtual u64 vf7();
    virtual void vf8();
    void vf9() override;
    void vf10(const Unk_1085320_Optional<u32>* code) override;
    void vf11() override;

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
class Unk_2414608 : public Unk_239a418, public Unk_1085320_Step<const Unk_1085320_Optional<u32>*> {
public:
    Unk_2414608(Unk_239a418_RefPair a0) : field_68(a0) {}
    ~Unk_2414608() override;
    virtual void vf6();
    virtual u64 vf7();
    virtual void vf8();
    void vf9() override;
    void vf10(const Unk_1085320_Optional<u32>* code) override;
    void vf11() override;

    Unk_239a418_RefPair field_68;
    u64 field_78 = 0;
    u32 field_80 = 0;
};
static_assert(sizeof(Unk_2414608) == 0x88, "Unk_2414608");
template Unk_2414608* Unk_New::Create<Unk_2414608>(Unk_239a418_Allocator*, Unk_239a418_RefPair&&);

// 0x71010d13f0
class Unk_24147b8 : public Unk_239a418, public Unk_1085320_Step<const Unk_1085320_Optional<u32>*> {
public:
    Unk_24147b8(Unk_239a418_RefPair a0) : field_68(a0) {}
    ~Unk_24147b8() override;
    virtual void vf6();
    virtual u64 vf7();
    virtual void vf8();
    void vf9() override;
    void vf10(const Unk_1085320_Optional<u32>* code) override;
    void vf11() override;

    Unk_239a418_RefPair field_68;
    u64 field_78 = 0;
    u32 field_80 = 0;
};
static_assert(sizeof(Unk_24147b8) == 0x88, "Unk_24147b8");
template Unk_24147b8* Unk_New::Create<Unk_24147b8>(Unk_239a418_Allocator*, Unk_239a418_RefPair&&);

// 0x71010d1ee0
class Unk_24148b8 : public Unk_239a418, public Unk_1085320_Step<const Unk_1085320_Optional<u32>*> {
public:
    Unk_24148b8(Unk_239a418_RefPair a0, Unk_239a418_Ref2<Unk_239a418> a1)
        : field_68(a0), field_80(a1) {}
    ~Unk_24148b8() override;
    virtual void vf6();
    virtual u64 vf7();
    virtual void vf8();
    void vf9() override;
    void vf10(const Unk_1085320_Optional<u32>* code) override;
    void vf11() override;

    Unk_239a418_RefPair field_68;
    u64 field_78 = 0;
    Unk_239a418_Ref2<Unk_239a418> field_80;
};
static_assert(sizeof(Unk_24148b8) == 0x88, "Unk_24148b8");
template Unk_24148b8* Unk_New::Create<Unk_24148b8>(Unk_239a418_Allocator*,
                                                   Unk_239a418_RefPair&&,
                                                   const Unk_Ref&);

// 0x71010d5c70
class Unk_2414d00 : public Unk_239a418, public Unk_1085320_Step<const Unk_1085320_Optional<u32>*> {
public:
    Unk_2414d00(Unk_239a418_RefPair a0, Unk_239a418_Ref2<Unk_239a418> a1)
        : field_68(a0), field_80(a1) {}
    ~Unk_2414d00() override;
    virtual void vf6();
    virtual u64 vf7();
    virtual void vf8();
    void vf9() override;
    void vf10(const Unk_1085320_Optional<u32>* code) override;
    void vf11() override;

    Unk_239a418_RefPair field_68;
    u64 field_78 = 0;
    Unk_239a418_Ref2<Unk_239a418> field_80;
};
static_assert(sizeof(Unk_2414d00) == 0x88, "Unk_2414d00");
template Unk_2414d00* Unk_New::Create<Unk_2414d00>(Unk_239a418_Allocator*,
                                                   Unk_239a418_RefPair&&,
                                                   const Unk_Ref&);

// 0x71010d7fe0
class Unk_2415100 : public Unk_239a418, public Unk_1085320_Step<u64> {
public:
    Unk_2415100(Unk_239a418_RefPair a0, Unk_239a418_Ref2<Unk_239a418> a1)
        : field_68(a0), field_80(a1) {}
    ~Unk_2415100() override;
    virtual void vf6();
    virtual u64 vf7();
    virtual void vf8();
    void vf9() override;
    void vf10(u64 code) override;
    void vf11() override;

    Unk_239a418_RefPair field_68;
    u64 field_78 = 0;
    Unk_239a418_Ref2<Unk_239a418> field_80;
};
static_assert(sizeof(Unk_2415100) == 0x88, "Unk_2415100");
template Unk_2415100* Unk_New::Create<Unk_2415100>(Unk_239a418_Allocator*,
                                                   Unk_239a418_RefPair&&,
                                                   const Unk_Ref&);

// 0x71010d8bb0
class Unk_2415228 : public Unk_239a418, public Unk_1085320_Step<const Unk_1085320_Optional<u32>*> {
public:
    Unk_2415228(Unk_239a418_RefPair a0, const Unk_Ref& a1) : field_68(a0), field_80(a1) {}
    ~Unk_2415228() override;
    virtual void vf6();
    virtual u64 vf7();
    virtual void vf8();
    void vf9() override;
    void vf10(const Unk_1085320_Optional<u32>* code) override;
    void vf11() override;

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
class Unk_2415868 : public Unk_239a418, public Unk_1085320_Step<u64> {
public:
    Unk_2415868(Unk_239a418_RefPair a0, Unk_239a418_Ref2<Unk_239a418> a1)
        : field_68(a0), field_80(a1) {}
    ~Unk_2415868() override;
    virtual void vf6();
    virtual u64 vf7();
    virtual void vf8();
    void vf9() override;
    void vf10(u64 code) override;
    void vf11() override;

    Unk_239a418_RefPair field_68;
    u64 field_78 = 0;
    Unk_239a418_Ref2<Unk_239a418> field_80;
};
static_assert(sizeof(Unk_2415868) == 0x88, "Unk_2415868");
template Unk_2415868* Unk_New::Create<Unk_2415868>(Unk_239a418_Allocator*,
                                                   Unk_239a418_RefPair&&,
                                                   const Unk_Ref&);

// 0x71010dfee0
class Unk_2415a40 : public Unk_239a418, public Unk_1085320_Step<u64> {
public:
    Unk_2415a40(Unk_239a418_RefPair a0, Unk_239a418_Ref2<Unk_239a418> a1)
        : field_68(a0), field_80(a1) {}
    ~Unk_2415a40() override;
    virtual void vf6();
    virtual u64 vf7();
    virtual void vf8();
    void vf9() override;
    void vf10(u64 code) override;
    void vf11() override;

    Unk_239a418_RefPair field_68;
    u64 field_78 = 0;
    Unk_239a418_Ref2<Unk_239a418> field_80;
};
static_assert(sizeof(Unk_2415a40) == 0x88, "Unk_2415a40");
template Unk_2415a40* Unk_New::Create<Unk_2415a40>(Unk_239a418_Allocator*,
                                                   Unk_239a418_RefPair&&,
                                                   const Unk_Ref&);

// 0x71010e0d50
class Unk_2415b68 : public Unk_239a418, public Unk_1085320_Step<u64> {
public:
    Unk_2415b68(Unk_239a418_RefPair a0, const u64& a1) : field_68(a0), field_80(a1) {}
    ~Unk_2415b68() override;
    virtual void vf6();
    virtual u64 vf7();
    virtual void vf8();
    void vf9() override;
    void vf10(u64 code) override;
    void vf11() override;

    Unk_239a418_RefPair field_68;
    u64 field_78 = 0;
    u64 field_80;
};
static_assert(sizeof(Unk_2415b68) == 0x88, "Unk_2415b68");
template Unk_2415b68* Unk_New::Create<Unk_2415b68>(Unk_239a418_Allocator*,
                                                   Unk_239a418_RefPair&&,
                                                   const u64&);

// 0x71010e22b0
class Unk_2415df0 : public Unk_239a418, public Unk_1085320_Step<u64> {
public:
    Unk_2415df0(Unk_239a418_RefPair a0, Unk_239a418_Ref2<Unk_239a418> a1)
        : field_68(a0), field_80(a1) {}
    ~Unk_2415df0() override;
    virtual void vf6();
    virtual u64 vf7();
    virtual void vf8();
    void vf9() override;
    void vf10(u64 code) override;
    void vf11() override;

    Unk_239a418_RefPair field_68;
    u64 field_78 = 0;
    Unk_239a418_Ref2<Unk_239a418> field_80;
};
static_assert(sizeof(Unk_2415df0) == 0x88, "Unk_2415df0");
template Unk_2415df0* Unk_New::Create<Unk_2415df0>(Unk_239a418_Allocator*,
                                                   Unk_239a418_RefPair&&,
                                                   const Unk_Ref&);

// 0x71010e6dd0
class Unk_2416438 : public Unk_239a418, public Unk_1085320_Step<u64> {
public:
    Unk_2416438(Unk_239a418_RefPair a0, Unk_239a418_Ref2<Unk_239a418> a1)
        : field_68(a0), field_80(a1) {}
    ~Unk_2416438() override;
    virtual void vf6();
    virtual u64 vf7();
    virtual void vf8();
    void vf9() override;
    void vf10(u64 code) override;
    void vf11() override;

    Unk_239a418_RefPair field_68;
    u64 field_78 = 0;
    Unk_239a418_Ref2<Unk_239a418> field_80;
};
static_assert(sizeof(Unk_2416438) == 0x88, "Unk_2416438");
template Unk_2416438* Unk_New::Create<Unk_2416438>(Unk_239a418_Allocator*,
                                                   Unk_239a418_RefPair&&,
                                                   const Unk_Ref&);

// 0x71010e8530
class Unk_24166c0 : public Unk_239a418, public Unk_1085320_Step<u64> {
public:
    Unk_24166c0(Unk_239a418_RefPair a0, Unk_239a418_Ref2<Unk_239a418> a1)
        : field_68(a0), field_80(a1) {}
    ~Unk_24166c0() override;
    virtual void vf6();
    virtual u64 vf7();
    virtual void vf8();
    void vf9() override;
    void vf10(u64 code) override;
    void vf11() override;

    Unk_239a418_RefPair field_68;
    u64 field_78 = 0;
    Unk_239a418_Ref2<Unk_239a418> field_80;
};
static_assert(sizeof(Unk_24166c0) == 0x88, "Unk_24166c0");
template Unk_24166c0* Unk_New::Create<Unk_24166c0>(Unk_239a418_Allocator*,
                                                   Unk_239a418_RefPair&&,
                                                   const Unk_Ref&);

// 0x71010e93a0
class Unk_24167e8 : public Unk_239a418, public Unk_1085320_Step<u64> {
public:
    Unk_24167e8(Unk_239a418_RefPair a0, const u64& a1) : field_68(a0), field_80(a1) {}
    ~Unk_24167e8() override;
    virtual void vf6();
    virtual u64 vf7();
    virtual void vf8();
    void vf9() override;
    void vf10(u64 code) override;
    void vf11() override;

    Unk_239a418_RefPair field_68;
    u64 field_78 = 0;
    u64 field_80;
};
static_assert(sizeof(Unk_24167e8) == 0x88, "Unk_24167e8");
template Unk_24167e8* Unk_New::Create<Unk_24167e8>(Unk_239a418_Allocator*,
                                                   Unk_239a418_RefPair&&,
                                                   const u64&);

// 0x71010ec9f0
class Unk_2416cc8 : public Unk_239a418, public Unk_1085320_Step<const Unk_1085320_Optional<u32>*> {
public:
    Unk_2416cc8(Unk_239a418_RefPair a0, const Unk_1085320_Words5& a1)
        : field_68(a0), field_80(a1) {}
    ~Unk_2416cc8() override;
    virtual void vf6();
    virtual u64 vf7();
    virtual void vf8();
    void vf9() override;
    void vf10(const Unk_1085320_Optional<u32>* code) override;
    void vf11() override;

    Unk_239a418_RefPair field_68;
    u64 field_78 = 0;
    Unk_1085320_Words5 field_80;
};
static_assert(sizeof(Unk_2416cc8) == 0xa8, "Unk_2416cc8");
template Unk_2416cc8* Unk_New::Create<Unk_2416cc8>(Unk_239a418_Allocator*,
                                                   Unk_239a418_RefPair&&,
                                                   const Unk_1085320_Words5&);

// 0x71010eec20
class Unk_24170c8 : public Unk_239a418, public Unk_1085320_Step<u64> {
public:
    Unk_24170c8(Unk_239a418_RefPair a0, Unk_239a418_Ref2<Unk_239a418> a1)
        : field_68(a0), field_80(a1) {}
    ~Unk_24170c8() override;
    virtual void vf6();
    virtual u64 vf7();
    virtual void vf8();
    void vf9() override;
    void vf10(u64 code) override;
    void vf11() override;

    Unk_239a418_RefPair field_68;
    u64 field_78 = 0;
    Unk_239a418_Ref2<Unk_239a418> field_80;
};
static_assert(sizeof(Unk_24170c8) == 0x88, "Unk_24170c8");
template Unk_24170c8* Unk_New::Create<Unk_24170c8>(Unk_239a418_Allocator*,
                                                   Unk_239a418_RefPair&&,
                                                   const Unk_Ref&);

// 0x71010ef7f0
class Unk_24171f0 : public Unk_239a418, public Unk_1085320_Step<const Unk_1085320_Optional<u32>*> {
public:
    Unk_24171f0(Unk_239a418_RefPair a0, const Unk_Ref& a1) : field_68(a0), field_80(a1) {}
    ~Unk_24171f0() override;
    virtual void vf6();
    virtual u64 vf7();
    virtual void vf8();
    void vf9() override;
    void vf10(const Unk_1085320_Optional<u32>* code) override;
    void vf11() override;

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
class Unk_2417870 : public Unk_239a418, public Unk_1085320_Step<const Unk_1085320_Optional<u32>*> {
public:
    Unk_2417870(Unk_239a418_RefPair a0, Unk_239a418_Ref2<Unk_239a418> a1)
        : field_68(a0), field_80(a1) {}
    ~Unk_2417870() override;
    virtual void vf6();
    virtual u64 vf7();
    virtual void vf8();
    void vf9() override;
    void vf10(const Unk_1085320_Optional<u32>* code) override;
    void vf11() override;

    Unk_239a418_RefPair field_68;
    u64 field_78 = 0;
    Unk_239a418_Ref2<Unk_239a418> field_80;
};
static_assert(sizeof(Unk_2417870) == 0x88, "Unk_2417870");
template Unk_2417870* Unk_New::Create<Unk_2417870>(Unk_239a418_Allocator*,
                                                   Unk_239a418_RefPair&&,
                                                   const Unk_Ref&);

// 0x71011026d0
class Unk_24184a0 : public Unk_239a418, public Unk_1085320_Step<const Unk_1085320_Optional<u32>*> {
public:
    Unk_24184a0(Unk_239a418_RefPair a0, Unk_239a418_Ref2<Unk_239a418> a1)
        : field_68(a0), field_80(a1) {}
    ~Unk_24184a0() override;
    virtual void vf6();
    virtual u64 vf7();
    virtual void vf8();
    void vf9() override;
    void vf10(const Unk_1085320_Optional<u32>* code) override;
    void vf11() override;

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
struct Unk_6ce3c0;
void Unk_6ce3c0_setField110(Unk_6ce3c0* self, u32 value);

// A type-erased callable, 0x80 bytes, like Unk_23d4470_Callable
// (src/unsorted/Unk_23d4470.h): an invoker (+0x0) that takes the storage
// (+0x20) and references to the arguments. Callers test it before they call it.
template <class Signature>
class Unk_1050c60_Callable;

template <class R, class... Args>
class Unk_1050c60_Callable<R(Args...)> {
public:
    explicit operator bool() const { return field_0 != nullptr; }
    R operator()(Args... args) { return field_0(field_20, std::forward<Args>(args)...); }

    R (*field_0)(void* storage, Args&&... args);
    void (*field_8)(void*);
    u64 field_10;
    u64 field_18;
    u8 field_20[0x60];
};

// An owner's result (+0x320): each kind of owner has its own.
struct Unk_1050c60_Result;

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

    void Unk_6ce580();
    void Unk_SetState(u32 state) {
        Unk_6ce3c0_setField110(reinterpret_cast<Unk_6ce3c0*>(this), state);
    }
    void Unk_Cancel() {
        Unk_6ce580();
        Unk_SetState(6);
        if (field_2a0)
            field_2a0();
        if (field_1a0)
            field_1a0();
    }

    Unk_239a418_Allocator* field_60;
    u8 _68[0x48];
    Unk_1054f70_List field_b0;
    u32 field_110;
    u8 _114[0x8c];
    alignas(16) Unk_1050c60_Callable<void()> field_1a0;
    Unk_1050c60_Callable<void(Unk_1050c60_Result&)> field_220;
    Unk_1050c60_Callable<void()> field_2a0;
};
PKMN_OFFSET_ASSERT(Unk_1050c60_Owner, field_b0, 0xb0);
PKMN_OFFSET_ASSERT(Unk_1050c60_Owner, field_110, 0x110);
PKMN_OFFSET_ASSERT(Unk_1050c60_Owner, field_1a0, 0x1a0);
PKMN_SIZE_ASSERT(Unk_1050c60_Owner, 0x320);

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

// The steps: the classes the adders make are the steps of a request, and four
// of their virtual functions are the same in every one of them (so are the
// interface's thunks, which inline them). vf7 makes what the step runs, once
// (a function of its own per class, not decompiled). The other three are the
// interface: they tell the owner, if the weak reference still has one, that
// the step is done (a function of the owner's, not decompiled), that it
// failed (the owner keeps what the failure leaves, stops, goes to state 4 and
// calls its failure callable with its result, then its last one) or that it
// was cancelled (state 6, the cancel callable, the last one). The owners
// differ by their result, at +0x320: three kinds are known by their steps.

// The weak reference's object, while its handle counts references.
template <class T>
inline T* Unk_WeakGet(const Unk_239a418_RefPair& weak) {
    Unk_239a418_Handle* handle = reinterpret_cast<Unk_239a418_Handle*>(weak.field_0.m_ptr);
    if (handle != nullptr && handle->field_54.load() != 0)
        return reinterpret_cast<T*>(weak.field_8);
    return nullptr;
}

class Unk_1054690_Owner : public Unk_1050c60_Owner {
public:
    void Unk_Fail(Unk_1085320_Optional<u32> code) {
        field_35c = code;
        Unk_6ce580();
        Unk_SetState(4);
        if (field_220)
            field_220(reinterpret_cast<Unk_1050c60_Result&>(field_320));
        if (field_1a0)
            field_1a0();
    }

    u8 field_320[0x3c];
    Unk_1085320_Optional<u32> field_35c;
};

class Unk_1056d00_Owner : public Unk_1050c60_Owner {
public:
    void Unk_Fail(Unk_1085320_Optional<u32> code) {
        field_354 = code;
        Unk_6ce580();
        Unk_SetState(4);
        if (field_220)
            field_220(reinterpret_cast<Unk_1050c60_Result&>(field_320));
        if (field_1a0)
            field_1a0();
    }

    u8 field_320[0x34];
    Unk_1085320_Optional<u32> field_354;
};

class Unk_1059aa0_Owner : public Unk_1050c60_Owner {
public:
    void Unk_Fail(u64 code) {
        field_320 = code;
        Unk_6ce580();
        Unk_SetState(4);
        if (field_220)
            field_220(reinterpret_cast<Unk_1050c60_Result&>(field_320));
        if (field_1a0)
            field_1a0();
    }

    u64 field_320;
};

u64 Unk_1054d30(Unk_240b658* self, void* arg);
u64 Unk_10572b0(Unk_240b970* self, void* arg);
u64 Unk_1059530(Unk_240bc60* self, void* arg);
u64 Unk_1059fd0(Unk_240bd60* self, void* arg);
u64 Unk_105ae70(Unk_240be88* self, void* arg);
u64 Unk_1085c80(Unk_240d540* self, void* arg);
u64 Unk_10868c0(Unk_240d668* self, void* arg);
u64 Unk_1087f40(Unk_240d8f0* self, void* arg);
u64 Unk_1089b70(Unk_240dc40* self, void* arg);
u64 Unk_108a780(Unk_240dd68* self, void* arg);
u64 Unk_108bfe0(Unk_240dfc8* self, void* arg);
u64 Unk_108cc10(Unk_240e0f0* self, void* arg);
u64 Unk_108e670(Unk_240e350* self, void* arg);
u64 Unk_1090480(Unk_240e6a0* self, void* arg);
u64 Unk_10910b0(Unk_240e7c8* self, void* arg);
u64 Unk_1093370(Unk_240eba0* self, void* arg);
u64 Unk_1093fa0(Unk_240ecc8* self, void* arg);
u64 Unk_10957b0(Unk_240ef28* self, void* arg);
u64 Unk_1097360(Unk_240f1b0* self, void* arg);
u64 Unk_1098620(Unk_240f388* self, void* arg);
u64 Unk_109b0b0(Unk_240f840* self, void* arg);
u64 Unk_109bce0(Unk_240f968* self, void* arg);
u64 Unk_109d410(Unk_240fbc8* self, void* arg);
u64 Unk_10aeeb0(Unk_24117b0* self, void* arg);
u64 Unk_10af9a0(Unk_24118b0* self, void* arg);
u64 Unk_10b0490(Unk_24119b0* self, void* arg);
u64 Unk_10b0f80(Unk_2411ab0* self, void* arg);
u64 Unk_10b1b20(Unk_2411bb0* self, void* arg);
u64 Unk_10b2610(Unk_2411cb0* self, void* arg);
u64 Unk_10b3120(Unk_2411db0* self, void* arg);
u64 Unk_10b3c40(Unk_2411ed8* self, void* arg);
u64 Unk_10b4750(Unk_2411fd8* self, void* arg);
u64 Unk_10b5480(Unk_2412100* self, void* arg);
u64 Unk_10b6100(Unk_2412228* self, void* arg);
u64 Unk_10b6bf0(Unk_2412328* self, void* arg);
u64 Unk_10b76e0(Unk_2412428* self, void* arg);
u64 Unk_10b81d0(Unk_2412528* self, void* arg);
u64 Unk_10bd7a0(Unk_2412c88* self, void* arg);
u64 Unk_10bf0c0(Unk_2412f10* self, void* arg);
u64 Unk_10c07c0(Unk_2413198* self, void* arg);
u64 Unk_10c1a80(Unk_2413370* self, void* arg);
u64 Unk_10c8240(Unk_2413d48* self, void* arg);
u64 Unk_10c9d40(Unk_2413fd0* self, void* arg);
u64 Unk_10d0c00(Unk_2414608* self, void* arg);
u64 Unk_10d1cd0(Unk_24147b8* self, void* arg);
u64 Unk_10d28c0(Unk_24148b8* self, void* arg);
u64 Unk_10d6650(Unk_2414d00* self, void* arg);
u64 Unk_10d8940(Unk_2415100* self, void* arg);
u64 Unk_10d9570(Unk_2415228* self, void* arg);
u64 Unk_10df620(Unk_2415868* self, void* arg);
u64 Unk_10e0840(Unk_2415a40* self, void* arg);
u64 Unk_10e15d0(Unk_2415b68* self, void* arg);
u64 Unk_10e2c10(Unk_2415df0* self, void* arg);
u64 Unk_10e7730(Unk_2416438* self, void* arg);
u64 Unk_10e8e90(Unk_24166c0* self, void* arg);
u64 Unk_10e9c20(Unk_24167e8* self, void* arg);
u64 Unk_10ed310(Unk_2416cc8* self, void* arg);
u64 Unk_10ef580(Unk_24170c8* self, void* arg);
u64 Unk_10f01b0(Unk_24171f0* self, void* arg);
u64 Unk_10f4080(Unk_2417870* self, void* arg);
u64 Unk_11030b0(Unk_24184a0* self, void* arg);
void Unk_1053f20(Unk_1050c60_Owner* owner);
void Unk_1056680(Unk_1050c60_Owner* owner);
void Unk_1058900(Unk_1050c60_Owner* owner);
void Unk_1084ff0(Unk_1050c60_Owner* owner);
void Unk_1088fc0(Unk_1050c60_Owner* owner);
void Unk_108f7f0(Unk_1050c60_Owner* owner);
void Unk_10926e0(Unk_1050c60_Owner* owner);
void Unk_109a420(Unk_1050c60_Owner* owner);
void Unk_10d7cb0(Unk_1050c60_Owner* owner);
void Unk_10ee8f0(Unk_1050c60_Owner* owner);

// 0x7101054610
u64 Unk_240b658::vf7() {
    if (field_78 == 0)
        field_78 = Unk_1054d30(this, &field_80);
    return field_78;
}

// 0x7101054660
// 0x7101054ae0
void Unk_240b658::vf9() {
    if (Unk_1050c60_Owner* owner = Unk_WeakGet<Unk_1050c60_Owner>(field_68))
        Unk_1053f20(owner);
}

// 0x7101054690
// 0x7101054b10
void Unk_240b658::vf10(const Unk_1085320_Optional<u32>* code) {
    if (Unk_1054690_Owner* owner = Unk_WeakGet<Unk_1054690_Owner>(field_68))
        owner->Unk_Fail(*code);
}

// 0x7101054750
// 0x7101054bd0
void Unk_240b658::vf11() {
    if (Unk_1050c60_Owner* owner = Unk_WeakGet<Unk_1050c60_Owner>(field_68))
        owner->Unk_Cancel();
}

// 0x7101056c80
u64 Unk_240b970::vf7() {
    if (field_78 == 0)
        field_78 = Unk_10572b0(this, &field_80);
    return field_78;
}

// 0x7101056cd0
// 0x7101057150
void Unk_240b970::vf9() {
    if (Unk_1050c60_Owner* owner = Unk_WeakGet<Unk_1050c60_Owner>(field_68))
        Unk_1056680(owner);
}

// 0x7101056d00
// 0x7101057180
void Unk_240b970::vf10(const Unk_1085320_Optional<u32>* code) {
    if (Unk_1056d00_Owner* owner = Unk_WeakGet<Unk_1056d00_Owner>(field_68))
        owner->Unk_Fail(*code);
}

// 0x7101056dc0
// 0x7101057240
void Unk_240b970::vf11() {
    if (Unk_1050c60_Owner* owner = Unk_WeakGet<Unk_1050c60_Owner>(field_68))
        owner->Unk_Cancel();
}

// 0x7101058f00
u64 Unk_240bc60::vf7() {
    if (field_78 == 0)
        field_78 = Unk_1059530(this, &field_80);
    return field_78;
}

// 0x7101058f50
// 0x71010593d0
void Unk_240bc60::vf9() {
    if (Unk_1050c60_Owner* owner = Unk_WeakGet<Unk_1050c60_Owner>(field_68))
        Unk_1058900(owner);
}

// 0x7101058f80
// 0x7101059400
void Unk_240bc60::vf10(const Unk_1085320_Optional<u32>* code) {
    if (Unk_1054690_Owner* owner = Unk_WeakGet<Unk_1054690_Owner>(field_68))
        owner->Unk_Fail(*code);
}

// 0x7101059040
// 0x71010594c0
void Unk_240bc60::vf11() {
    if (Unk_1050c60_Owner* owner = Unk_WeakGet<Unk_1050c60_Owner>(field_68))
        owner->Unk_Cancel();
}

// 0x7101059a20
u64 Unk_240bd60::vf7() {
    if (field_78 == 0)
        field_78 = Unk_1059fd0(this, &field_80);
    return field_78;
}

// 0x7101059a70
// 0x7101059eb0
void Unk_240bd60::vf9() {
    if (Unk_1050c60_Owner* owner = Unk_WeakGet<Unk_1050c60_Owner>(field_68))
        Unk_1058900(owner);
}

// 0x7101059aa0
// 0x7101059ee0
void Unk_240bd60::vf10(u64 code) {
    if (Unk_1059aa0_Owner* owner = Unk_WeakGet<Unk_1059aa0_Owner>(field_68))
        owner->Unk_Fail(code);
}

// 0x7101059b20
// 0x7101059f60
void Unk_240bd60::vf11() {
    if (Unk_1050c60_Owner* owner = Unk_WeakGet<Unk_1050c60_Owner>(field_68))
        owner->Unk_Cancel();
}

// 0x710105a840
u64 Unk_240be88::vf7() {
    if (field_78 == 0)
        field_78 = Unk_105ae70(this, &field_80);
    return field_78;
}

// 0x710105a890
// 0x710105ad10
void Unk_240be88::vf9() {
    if (Unk_1050c60_Owner* owner = Unk_WeakGet<Unk_1050c60_Owner>(field_68))
        Unk_1056680(owner);
}

// 0x710105a8c0
// 0x710105ad40
void Unk_240be88::vf10(const Unk_1085320_Optional<u32>* code) {
    if (Unk_1056d00_Owner* owner = Unk_WeakGet<Unk_1056d00_Owner>(field_68))
        owner->Unk_Fail(*code);
}

// 0x710105a980
// 0x710105ae00
void Unk_240be88::vf11() {
    if (Unk_1050c60_Owner* owner = Unk_WeakGet<Unk_1050c60_Owner>(field_68))
        owner->Unk_Cancel();
}

// 0x7101085650
u64 Unk_240d540::vf7() {
    if (field_78 == 0)
        field_78 = Unk_1085c80(this, &field_80);
    return field_78;
}

// 0x71010856a0
// 0x7101085b60
void Unk_240d540::vf9() {
    if (Unk_1050c60_Owner* owner = Unk_WeakGet<Unk_1050c60_Owner>(field_68))
        Unk_1084ff0(owner);
}

// 0x71010856d0
// 0x7101085b90
void Unk_240d540::vf10(u64 code) {
    if (Unk_1059aa0_Owner* owner = Unk_WeakGet<Unk_1059aa0_Owner>(field_68))
        owner->Unk_Fail(code);
}

// 0x7101085750
// 0x7101085c10
void Unk_240d540::vf11() {
    if (Unk_1050c60_Owner* owner = Unk_WeakGet<Unk_1050c60_Owner>(field_68))
        owner->Unk_Cancel();
}

// 0x7101086210
u64 Unk_240d668::vf7() {
    if (field_78 == 0)
        field_78 = Unk_10868c0(this, &field_80);
    return field_78;
}

// 0x7101086260
// 0x7101086760
void Unk_240d668::vf9() {
    if (Unk_1050c60_Owner* owner = Unk_WeakGet<Unk_1050c60_Owner>(field_68))
        Unk_1084ff0(owner);
}

// 0x7101086290
// 0x7101086790
void Unk_240d668::vf10(const Unk_1085320_Optional<u32>* code) {
    if (Unk_1054690_Owner* owner = Unk_WeakGet<Unk_1054690_Owner>(field_68))
        owner->Unk_Fail(*code);
}

// 0x7101086350
// 0x7101086850
void Unk_240d668::vf11() {
    if (Unk_1050c60_Owner* owner = Unk_WeakGet<Unk_1050c60_Owner>(field_68))
        owner->Unk_Cancel();
}

// 0x7101087910
u64 Unk_240d8f0::vf7() {
    if (field_78 == 0)
        field_78 = Unk_1087f40(this, &field_80);
    return field_78;
}

// 0x7101087960
// 0x7101087e20
void Unk_240d8f0::vf9() {
    if (Unk_1050c60_Owner* owner = Unk_WeakGet<Unk_1050c60_Owner>(field_68))
        Unk_1084ff0(owner);
}

// 0x7101087990
// 0x7101087e50
void Unk_240d8f0::vf10(u64 code) {
    if (Unk_1059aa0_Owner* owner = Unk_WeakGet<Unk_1059aa0_Owner>(field_68))
        owner->Unk_Fail(code);
}

// 0x7101087a10
// 0x7101087ed0
void Unk_240d8f0::vf11() {
    if (Unk_1050c60_Owner* owner = Unk_WeakGet<Unk_1050c60_Owner>(field_68))
        owner->Unk_Cancel();
}

// 0x71010895c0
u64 Unk_240dc40::vf7() {
    if (field_78 == 0)
        field_78 = Unk_1089b70(this, &field_80);
    return field_78;
}

// 0x7101089610
// 0x7101089a50
void Unk_240dc40::vf9() {
    if (Unk_1050c60_Owner* owner = Unk_WeakGet<Unk_1050c60_Owner>(field_68))
        Unk_1088fc0(owner);
}

// 0x7101089640
// 0x7101089a80
void Unk_240dc40::vf10(u64 code) {
    if (Unk_1059aa0_Owner* owner = Unk_WeakGet<Unk_1059aa0_Owner>(field_68))
        owner->Unk_Fail(code);
}

// 0x71010896c0
// 0x7101089b00
void Unk_240dc40::vf11() {
    if (Unk_1050c60_Owner* owner = Unk_WeakGet<Unk_1050c60_Owner>(field_68))
        owner->Unk_Cancel();
}

// 0x710108a0d0
u64 Unk_240dd68::vf7() {
    if (field_78 == 0)
        field_78 = Unk_108a780(this, &field_80);
    return field_78;
}

// 0x710108a120
// 0x710108a620
void Unk_240dd68::vf9() {
    if (Unk_1050c60_Owner* owner = Unk_WeakGet<Unk_1050c60_Owner>(field_68))
        Unk_1088fc0(owner);
}

// 0x710108a150
// 0x710108a650
void Unk_240dd68::vf10(const Unk_1085320_Optional<u32>* code) {
    if (Unk_1054690_Owner* owner = Unk_WeakGet<Unk_1054690_Owner>(field_68))
        owner->Unk_Fail(*code);
}

// 0x710108a210
// 0x710108a710
void Unk_240dd68::vf11() {
    if (Unk_1050c60_Owner* owner = Unk_WeakGet<Unk_1050c60_Owner>(field_68))
        owner->Unk_Cancel();
}

// 0x710108b930
u64 Unk_240dfc8::vf7() {
    if (field_78 == 0)
        field_78 = Unk_108bfe0(this, &field_80);
    return field_78;
}

// 0x710108b980
// 0x710108be80
void Unk_240dfc8::vf9() {
    if (Unk_1050c60_Owner* owner = Unk_WeakGet<Unk_1050c60_Owner>(field_68))
        Unk_1056680(owner);
}

// 0x710108b9b0
// 0x710108beb0
void Unk_240dfc8::vf10(const Unk_1085320_Optional<u32>* code) {
    if (Unk_1056d00_Owner* owner = Unk_WeakGet<Unk_1056d00_Owner>(field_68))
        owner->Unk_Fail(*code);
}

// 0x710108ba70
// 0x710108bf70
void Unk_240dfc8::vf11() {
    if (Unk_1050c60_Owner* owner = Unk_WeakGet<Unk_1050c60_Owner>(field_68))
        owner->Unk_Cancel();
}

// 0x710108c560
u64 Unk_240e0f0::vf7() {
    if (field_78 == 0)
        field_78 = Unk_108cc10(this, &field_80);
    return field_78;
}

// 0x710108c5b0
// 0x710108cab0
void Unk_240e0f0::vf9() {
    if (Unk_1050c60_Owner* owner = Unk_WeakGet<Unk_1050c60_Owner>(field_68))
        Unk_1056680(owner);
}

// 0x710108c5e0
// 0x710108cae0
void Unk_240e0f0::vf10(const Unk_1085320_Optional<u32>* code) {
    if (Unk_1056d00_Owner* owner = Unk_WeakGet<Unk_1056d00_Owner>(field_68))
        owner->Unk_Fail(*code);
}

// 0x710108c6a0
// 0x710108cba0
void Unk_240e0f0::vf11() {
    if (Unk_1050c60_Owner* owner = Unk_WeakGet<Unk_1050c60_Owner>(field_68))
        owner->Unk_Cancel();
}

// 0x710108dfc0
u64 Unk_240e350::vf7() {
    if (field_78 == 0)
        field_78 = Unk_108e670(this, &field_80);
    return field_78;
}

// 0x710108e010
// 0x710108e510
void Unk_240e350::vf9() {
    if (Unk_1050c60_Owner* owner = Unk_WeakGet<Unk_1050c60_Owner>(field_68))
        Unk_1056680(owner);
}

// 0x710108e040
// 0x710108e540
void Unk_240e350::vf10(const Unk_1085320_Optional<u32>* code) {
    if (Unk_1056d00_Owner* owner = Unk_WeakGet<Unk_1056d00_Owner>(field_68))
        owner->Unk_Fail(*code);
}

// 0x710108e100
// 0x710108e600
void Unk_240e350::vf11() {
    if (Unk_1050c60_Owner* owner = Unk_WeakGet<Unk_1050c60_Owner>(field_68))
        owner->Unk_Cancel();
}

// 0x710108fe50
u64 Unk_240e6a0::vf7() {
    if (field_78 == 0)
        field_78 = Unk_1090480(this, &field_80);
    return field_78;
}

// 0x710108fea0
// 0x7101090360
void Unk_240e6a0::vf9() {
    if (Unk_1050c60_Owner* owner = Unk_WeakGet<Unk_1050c60_Owner>(field_68))
        Unk_108f7f0(owner);
}

// 0x710108fed0
// 0x7101090390
void Unk_240e6a0::vf10(u64 code) {
    if (Unk_1059aa0_Owner* owner = Unk_WeakGet<Unk_1059aa0_Owner>(field_68))
        owner->Unk_Fail(code);
}

// 0x710108ff50
// 0x7101090410
void Unk_240e6a0::vf11() {
    if (Unk_1050c60_Owner* owner = Unk_WeakGet<Unk_1050c60_Owner>(field_68))
        owner->Unk_Cancel();
}

// 0x7101090a00
u64 Unk_240e7c8::vf7() {
    if (field_78 == 0)
        field_78 = Unk_10910b0(this, &field_80);
    return field_78;
}

// 0x7101090a50
// 0x7101090f50
void Unk_240e7c8::vf9() {
    if (Unk_1050c60_Owner* owner = Unk_WeakGet<Unk_1050c60_Owner>(field_68))
        Unk_108f7f0(owner);
}

// 0x7101090a80
// 0x7101090f80
void Unk_240e7c8::vf10(const Unk_1085320_Optional<u32>* code) {
    if (Unk_1054690_Owner* owner = Unk_WeakGet<Unk_1054690_Owner>(field_68))
        owner->Unk_Fail(*code);
}

// 0x7101090b40
// 0x7101091040
void Unk_240e7c8::vf11() {
    if (Unk_1050c60_Owner* owner = Unk_WeakGet<Unk_1050c60_Owner>(field_68))
        owner->Unk_Cancel();
}

// 0x7101092d40
u64 Unk_240eba0::vf7() {
    if (field_78 == 0)
        field_78 = Unk_1093370(this, &field_80);
    return field_78;
}

// 0x7101092d90
// 0x7101093250
void Unk_240eba0::vf9() {
    if (Unk_1050c60_Owner* owner = Unk_WeakGet<Unk_1050c60_Owner>(field_68))
        Unk_10926e0(owner);
}

// 0x7101092dc0
// 0x7101093280
void Unk_240eba0::vf10(u64 code) {
    if (Unk_1059aa0_Owner* owner = Unk_WeakGet<Unk_1059aa0_Owner>(field_68))
        owner->Unk_Fail(code);
}

// 0x7101092e40
// 0x7101093300
void Unk_240eba0::vf11() {
    if (Unk_1050c60_Owner* owner = Unk_WeakGet<Unk_1050c60_Owner>(field_68))
        owner->Unk_Cancel();
}

// 0x71010938f0
u64 Unk_240ecc8::vf7() {
    if (field_78 == 0)
        field_78 = Unk_1093fa0(this, &field_80);
    return field_78;
}

// 0x7101093940
// 0x7101093e40
void Unk_240ecc8::vf9() {
    if (Unk_1050c60_Owner* owner = Unk_WeakGet<Unk_1050c60_Owner>(field_68))
        Unk_10926e0(owner);
}

// 0x7101093970
// 0x7101093e70
void Unk_240ecc8::vf10(const Unk_1085320_Optional<u32>* code) {
    if (Unk_1054690_Owner* owner = Unk_WeakGet<Unk_1054690_Owner>(field_68))
        owner->Unk_Fail(*code);
}

// 0x7101093a30
// 0x7101093f30
void Unk_240ecc8::vf11() {
    if (Unk_1050c60_Owner* owner = Unk_WeakGet<Unk_1050c60_Owner>(field_68))
        owner->Unk_Cancel();
}

// 0x7101095100
u64 Unk_240ef28::vf7() {
    if (field_78 == 0)
        field_78 = Unk_10957b0(this, &field_80);
    return field_78;
}

// 0x7101095150
// 0x7101095650
void Unk_240ef28::vf9() {
    if (Unk_1050c60_Owner* owner = Unk_WeakGet<Unk_1050c60_Owner>(field_68))
        Unk_1056680(owner);
}

// 0x7101095180
// 0x7101095680
void Unk_240ef28::vf10(const Unk_1085320_Optional<u32>* code) {
    if (Unk_1056d00_Owner* owner = Unk_WeakGet<Unk_1056d00_Owner>(field_68))
        owner->Unk_Fail(*code);
}

// 0x7101095240
// 0x7101095740
void Unk_240ef28::vf11() {
    if (Unk_1050c60_Owner* owner = Unk_WeakGet<Unk_1050c60_Owner>(field_68))
        owner->Unk_Cancel();
}

// 0x7101096cb0
u64 Unk_240f1b0::vf7() {
    if (field_78 == 0)
        field_78 = Unk_1097360(this, &field_80);
    return field_78;
}

// 0x7101096d00
// 0x7101097200
void Unk_240f1b0::vf9() {
    if (Unk_1050c60_Owner* owner = Unk_WeakGet<Unk_1050c60_Owner>(field_68))
        Unk_1056680(owner);
}

// 0x7101096d30
// 0x7101097230
void Unk_240f1b0::vf10(const Unk_1085320_Optional<u32>* code) {
    if (Unk_1056d00_Owner* owner = Unk_WeakGet<Unk_1056d00_Owner>(field_68))
        owner->Unk_Fail(*code);
}

// 0x7101096df0
// 0x71010972f0
void Unk_240f1b0::vf11() {
    if (Unk_1050c60_Owner* owner = Unk_WeakGet<Unk_1050c60_Owner>(field_68))
        owner->Unk_Cancel();
}

// 0x7101097f70
u64 Unk_240f388::vf7() {
    if (field_78 == 0)
        field_78 = Unk_1098620(this, &field_80);
    return field_78;
}

// 0x7101097fc0
// 0x71010984c0
void Unk_240f388::vf9() {
    if (Unk_1050c60_Owner* owner = Unk_WeakGet<Unk_1050c60_Owner>(field_68))
        Unk_1056680(owner);
}

// 0x7101097ff0
// 0x71010984f0
void Unk_240f388::vf10(const Unk_1085320_Optional<u32>* code) {
    if (Unk_1056d00_Owner* owner = Unk_WeakGet<Unk_1056d00_Owner>(field_68))
        owner->Unk_Fail(*code);
}

// 0x71010980b0
// 0x71010985b0
void Unk_240f388::vf11() {
    if (Unk_1050c60_Owner* owner = Unk_WeakGet<Unk_1050c60_Owner>(field_68))
        owner->Unk_Cancel();
}

// 0x710109aa80
u64 Unk_240f840::vf7() {
    if (field_78 == 0)
        field_78 = Unk_109b0b0(this, &field_80);
    return field_78;
}

// 0x710109aad0
// 0x710109af90
void Unk_240f840::vf9() {
    if (Unk_1050c60_Owner* owner = Unk_WeakGet<Unk_1050c60_Owner>(field_68))
        Unk_109a420(owner);
}

// 0x710109ab00
// 0x710109afc0
void Unk_240f840::vf10(u64 code) {
    if (Unk_1059aa0_Owner* owner = Unk_WeakGet<Unk_1059aa0_Owner>(field_68))
        owner->Unk_Fail(code);
}

// 0x710109ab80
// 0x710109b040
void Unk_240f840::vf11() {
    if (Unk_1050c60_Owner* owner = Unk_WeakGet<Unk_1050c60_Owner>(field_68))
        owner->Unk_Cancel();
}

// 0x710109b630
u64 Unk_240f968::vf7() {
    if (field_78 == 0)
        field_78 = Unk_109bce0(this, &field_80);
    return field_78;
}

// 0x710109b680
// 0x710109bb80
void Unk_240f968::vf9() {
    if (Unk_1050c60_Owner* owner = Unk_WeakGet<Unk_1050c60_Owner>(field_68))
        Unk_109a420(owner);
}

// 0x710109b6b0
// 0x710109bbb0
void Unk_240f968::vf10(const Unk_1085320_Optional<u32>* code) {
    if (Unk_1054690_Owner* owner = Unk_WeakGet<Unk_1054690_Owner>(field_68))
        owner->Unk_Fail(*code);
}

// 0x710109b770
// 0x710109bc70
void Unk_240f968::vf11() {
    if (Unk_1050c60_Owner* owner = Unk_WeakGet<Unk_1050c60_Owner>(field_68))
        owner->Unk_Cancel();
}

// 0x710109cd60
u64 Unk_240fbc8::vf7() {
    if (field_78 == 0)
        field_78 = Unk_109d410(this, &field_80);
    return field_78;
}

// 0x710109cdb0
// 0x710109d2b0
void Unk_240fbc8::vf9() {
    if (Unk_1050c60_Owner* owner = Unk_WeakGet<Unk_1050c60_Owner>(field_68))
        Unk_1056680(owner);
}

// 0x710109cde0
// 0x710109d2e0
void Unk_240fbc8::vf10(const Unk_1085320_Optional<u32>* code) {
    if (Unk_1056d00_Owner* owner = Unk_WeakGet<Unk_1056d00_Owner>(field_68))
        owner->Unk_Fail(*code);
}

// 0x710109cea0
// 0x710109d3a0
void Unk_240fbc8::vf11() {
    if (Unk_1050c60_Owner* owner = Unk_WeakGet<Unk_1050c60_Owner>(field_68))
        owner->Unk_Cancel();
}

// 0x71010ae880
u64 Unk_24117b0::vf7() {
    if (field_78 == 0)
        field_78 = Unk_10aeeb0(this, &field_80);
    return field_78;
}

// 0x71010ae8d0
// 0x71010aed50
void Unk_24117b0::vf9() {
    if (Unk_1050c60_Owner* owner = Unk_WeakGet<Unk_1050c60_Owner>(field_68))
        Unk_1056680(owner);
}

// 0x71010ae900
// 0x71010aed80
void Unk_24117b0::vf10(const Unk_1085320_Optional<u32>* code) {
    if (Unk_1056d00_Owner* owner = Unk_WeakGet<Unk_1056d00_Owner>(field_68))
        owner->Unk_Fail(*code);
}

// 0x71010ae9c0
// 0x71010aee40
void Unk_24117b0::vf11() {
    if (Unk_1050c60_Owner* owner = Unk_WeakGet<Unk_1050c60_Owner>(field_68))
        owner->Unk_Cancel();
}

// 0x71010af370
u64 Unk_24118b0::vf7() {
    if (field_78 == 0)
        field_78 = Unk_10af9a0(this, &field_80);
    return field_78;
}

// 0x71010af3c0
// 0x71010af840
void Unk_24118b0::vf9() {
    if (Unk_1050c60_Owner* owner = Unk_WeakGet<Unk_1050c60_Owner>(field_68))
        Unk_1056680(owner);
}

// 0x71010af3f0
// 0x71010af870
void Unk_24118b0::vf10(const Unk_1085320_Optional<u32>* code) {
    if (Unk_1056d00_Owner* owner = Unk_WeakGet<Unk_1056d00_Owner>(field_68))
        owner->Unk_Fail(*code);
}

// 0x71010af4b0
// 0x71010af930
void Unk_24118b0::vf11() {
    if (Unk_1050c60_Owner* owner = Unk_WeakGet<Unk_1050c60_Owner>(field_68))
        owner->Unk_Cancel();
}

// 0x71010afe60
u64 Unk_24119b0::vf7() {
    if (field_78 == 0)
        field_78 = Unk_10b0490(this, &field_80);
    return field_78;
}

// 0x71010afeb0
// 0x71010b0330
void Unk_24119b0::vf9() {
    if (Unk_1050c60_Owner* owner = Unk_WeakGet<Unk_1050c60_Owner>(field_68))
        Unk_1056680(owner);
}

// 0x71010afee0
// 0x71010b0360
void Unk_24119b0::vf10(const Unk_1085320_Optional<u32>* code) {
    if (Unk_1056d00_Owner* owner = Unk_WeakGet<Unk_1056d00_Owner>(field_68))
        owner->Unk_Fail(*code);
}

// 0x71010affa0
// 0x71010b0420
void Unk_24119b0::vf11() {
    if (Unk_1050c60_Owner* owner = Unk_WeakGet<Unk_1050c60_Owner>(field_68))
        owner->Unk_Cancel();
}

// 0x71010b0950
u64 Unk_2411ab0::vf7() {
    if (field_78 == 0)
        field_78 = Unk_10b0f80(this, &field_80);
    return field_78;
}

// 0x71010b09a0
// 0x71010b0e20
void Unk_2411ab0::vf9() {
    if (Unk_1050c60_Owner* owner = Unk_WeakGet<Unk_1050c60_Owner>(field_68))
        Unk_1056680(owner);
}

// 0x71010b09d0
// 0x71010b0e50
void Unk_2411ab0::vf10(const Unk_1085320_Optional<u32>* code) {
    if (Unk_1056d00_Owner* owner = Unk_WeakGet<Unk_1056d00_Owner>(field_68))
        owner->Unk_Fail(*code);
}

// 0x71010b0a90
// 0x71010b0f10
void Unk_2411ab0::vf11() {
    if (Unk_1050c60_Owner* owner = Unk_WeakGet<Unk_1050c60_Owner>(field_68))
        owner->Unk_Cancel();
}

// 0x71010b14f0
u64 Unk_2411bb0::vf7() {
    if (field_78 == 0)
        field_78 = Unk_10b1b20(this, &field_80);
    return field_78;
}

// 0x71010b1540
// 0x71010b19c0
void Unk_2411bb0::vf9() {
    if (Unk_1050c60_Owner* owner = Unk_WeakGet<Unk_1050c60_Owner>(field_68))
        Unk_1056680(owner);
}

// 0x71010b1570
// 0x71010b19f0
void Unk_2411bb0::vf10(const Unk_1085320_Optional<u32>* code) {
    if (Unk_1056d00_Owner* owner = Unk_WeakGet<Unk_1056d00_Owner>(field_68))
        owner->Unk_Fail(*code);
}

// 0x71010b1630
// 0x71010b1ab0
void Unk_2411bb0::vf11() {
    if (Unk_1050c60_Owner* owner = Unk_WeakGet<Unk_1050c60_Owner>(field_68))
        owner->Unk_Cancel();
}

// 0x71010b1fe0
u64 Unk_2411cb0::vf7() {
    if (field_78 == 0)
        field_78 = Unk_10b2610(this, &field_80);
    return field_78;
}

// 0x71010b2030
// 0x71010b24b0
void Unk_2411cb0::vf9() {
    if (Unk_1050c60_Owner* owner = Unk_WeakGet<Unk_1050c60_Owner>(field_68))
        Unk_1056680(owner);
}

// 0x71010b2060
// 0x71010b24e0
void Unk_2411cb0::vf10(const Unk_1085320_Optional<u32>* code) {
    if (Unk_1056d00_Owner* owner = Unk_WeakGet<Unk_1056d00_Owner>(field_68))
        owner->Unk_Fail(*code);
}

// 0x71010b2120
// 0x71010b25a0
void Unk_2411cb0::vf11() {
    if (Unk_1050c60_Owner* owner = Unk_WeakGet<Unk_1050c60_Owner>(field_68))
        owner->Unk_Cancel();
}

// 0x71010b2af0
u64 Unk_2411db0::vf7() {
    if (field_78 == 0)
        field_78 = Unk_10b3120(this, &field_80);
    return field_78;
}

// 0x71010b2b40
// 0x71010b2fc0
void Unk_2411db0::vf9() {
    if (Unk_1050c60_Owner* owner = Unk_WeakGet<Unk_1050c60_Owner>(field_68))
        Unk_1056680(owner);
}

// 0x71010b2b70
// 0x71010b2ff0
void Unk_2411db0::vf10(const Unk_1085320_Optional<u32>* code) {
    if (Unk_1056d00_Owner* owner = Unk_WeakGet<Unk_1056d00_Owner>(field_68))
        owner->Unk_Fail(*code);
}

// 0x71010b2c30
// 0x71010b30b0
void Unk_2411db0::vf11() {
    if (Unk_1050c60_Owner* owner = Unk_WeakGet<Unk_1050c60_Owner>(field_68))
        owner->Unk_Cancel();
}

// 0x71010b3610
u64 Unk_2411ed8::vf7() {
    if (field_78 == 0)
        field_78 = Unk_10b3c40(this, &field_80);
    return field_78;
}

// 0x71010b3660
// 0x71010b3ae0
void Unk_2411ed8::vf9() {
    if (Unk_1050c60_Owner* owner = Unk_WeakGet<Unk_1050c60_Owner>(field_68))
        Unk_1056680(owner);
}

// 0x71010b3690
// 0x71010b3b10
void Unk_2411ed8::vf10(const Unk_1085320_Optional<u32>* code) {
    if (Unk_1056d00_Owner* owner = Unk_WeakGet<Unk_1056d00_Owner>(field_68))
        owner->Unk_Fail(*code);
}

// 0x71010b3750
// 0x71010b3bd0
void Unk_2411ed8::vf11() {
    if (Unk_1050c60_Owner* owner = Unk_WeakGet<Unk_1050c60_Owner>(field_68))
        owner->Unk_Cancel();
}

// 0x71010b4120
u64 Unk_2411fd8::vf7() {
    if (field_78 == 0)
        field_78 = Unk_10b4750(this, &field_80);
    return field_78;
}

// 0x71010b4170
// 0x71010b45f0
void Unk_2411fd8::vf9() {
    if (Unk_1050c60_Owner* owner = Unk_WeakGet<Unk_1050c60_Owner>(field_68))
        Unk_1056680(owner);
}

// 0x71010b41a0
// 0x71010b4620
void Unk_2411fd8::vf10(const Unk_1085320_Optional<u32>* code) {
    if (Unk_1056d00_Owner* owner = Unk_WeakGet<Unk_1056d00_Owner>(field_68))
        owner->Unk_Fail(*code);
}

// 0x71010b4260
// 0x71010b46e0
void Unk_2411fd8::vf11() {
    if (Unk_1050c60_Owner* owner = Unk_WeakGet<Unk_1050c60_Owner>(field_68))
        owner->Unk_Cancel();
}

// 0x71010b4e50
u64 Unk_2412100::vf7() {
    if (field_78 == 0)
        field_78 = Unk_10b5480(this, &field_80);
    return field_78;
}

// 0x71010b4ea0
// 0x71010b5320
void Unk_2412100::vf9() {
    if (Unk_1050c60_Owner* owner = Unk_WeakGet<Unk_1050c60_Owner>(field_68))
        Unk_1056680(owner);
}

// 0x71010b4ed0
// 0x71010b5350
void Unk_2412100::vf10(const Unk_1085320_Optional<u32>* code) {
    if (Unk_1056d00_Owner* owner = Unk_WeakGet<Unk_1056d00_Owner>(field_68))
        owner->Unk_Fail(*code);
}

// 0x71010b4f90
// 0x71010b5410
void Unk_2412100::vf11() {
    if (Unk_1050c60_Owner* owner = Unk_WeakGet<Unk_1050c60_Owner>(field_68))
        owner->Unk_Cancel();
}

// 0x71010b5ad0
u64 Unk_2412228::vf7() {
    if (field_78 == 0)
        field_78 = Unk_10b6100(this, &field_80);
    return field_78;
}

// 0x71010b5b20
// 0x71010b5fa0
void Unk_2412228::vf9() {
    if (Unk_1050c60_Owner* owner = Unk_WeakGet<Unk_1050c60_Owner>(field_68))
        Unk_1056680(owner);
}

// 0x71010b5b50
// 0x71010b5fd0
void Unk_2412228::vf10(const Unk_1085320_Optional<u32>* code) {
    if (Unk_1056d00_Owner* owner = Unk_WeakGet<Unk_1056d00_Owner>(field_68))
        owner->Unk_Fail(*code);
}

// 0x71010b5c10
// 0x71010b6090
void Unk_2412228::vf11() {
    if (Unk_1050c60_Owner* owner = Unk_WeakGet<Unk_1050c60_Owner>(field_68))
        owner->Unk_Cancel();
}

// 0x71010b65c0
u64 Unk_2412328::vf7() {
    if (field_78 == 0)
        field_78 = Unk_10b6bf0(this, &field_80);
    return field_78;
}

// 0x71010b6610
// 0x71010b6a90
void Unk_2412328::vf9() {
    if (Unk_1050c60_Owner* owner = Unk_WeakGet<Unk_1050c60_Owner>(field_68))
        Unk_1056680(owner);
}

// 0x71010b6640
// 0x71010b6ac0
void Unk_2412328::vf10(const Unk_1085320_Optional<u32>* code) {
    if (Unk_1056d00_Owner* owner = Unk_WeakGet<Unk_1056d00_Owner>(field_68))
        owner->Unk_Fail(*code);
}

// 0x71010b6700
// 0x71010b6b80
void Unk_2412328::vf11() {
    if (Unk_1050c60_Owner* owner = Unk_WeakGet<Unk_1050c60_Owner>(field_68))
        owner->Unk_Cancel();
}

// 0x71010b70b0
u64 Unk_2412428::vf7() {
    if (field_78 == 0)
        field_78 = Unk_10b76e0(this, &field_80);
    return field_78;
}

// 0x71010b7100
// 0x71010b7580
void Unk_2412428::vf9() {
    if (Unk_1050c60_Owner* owner = Unk_WeakGet<Unk_1050c60_Owner>(field_68))
        Unk_1056680(owner);
}

// 0x71010b7130
// 0x71010b75b0
void Unk_2412428::vf10(const Unk_1085320_Optional<u32>* code) {
    if (Unk_1056d00_Owner* owner = Unk_WeakGet<Unk_1056d00_Owner>(field_68))
        owner->Unk_Fail(*code);
}

// 0x71010b71f0
// 0x71010b7670
void Unk_2412428::vf11() {
    if (Unk_1050c60_Owner* owner = Unk_WeakGet<Unk_1050c60_Owner>(field_68))
        owner->Unk_Cancel();
}

// 0x71010b7ba0
u64 Unk_2412528::vf7() {
    if (field_78 == 0)
        field_78 = Unk_10b81d0(this, &field_80);
    return field_78;
}

// 0x71010b7bf0
// 0x71010b8070
void Unk_2412528::vf9() {
    if (Unk_1050c60_Owner* owner = Unk_WeakGet<Unk_1050c60_Owner>(field_68))
        Unk_1056680(owner);
}

// 0x71010b7c20
// 0x71010b80a0
void Unk_2412528::vf10(const Unk_1085320_Optional<u32>* code) {
    if (Unk_1056d00_Owner* owner = Unk_WeakGet<Unk_1056d00_Owner>(field_68))
        owner->Unk_Fail(*code);
}

// 0x71010b7ce0
// 0x71010b8160
void Unk_2412528::vf11() {
    if (Unk_1050c60_Owner* owner = Unk_WeakGet<Unk_1050c60_Owner>(field_68))
        owner->Unk_Cancel();
}

// 0x71010bd0f0
u64 Unk_2412c88::vf7() {
    if (field_78 == 0)
        field_78 = Unk_10bd7a0(this, &field_80);
    return field_78;
}

// 0x71010bd140
// 0x71010bd640
void Unk_2412c88::vf9() {
    if (Unk_1050c60_Owner* owner = Unk_WeakGet<Unk_1050c60_Owner>(field_68))
        Unk_1056680(owner);
}

// 0x71010bd170
// 0x71010bd670
void Unk_2412c88::vf10(const Unk_1085320_Optional<u32>* code) {
    if (Unk_1056d00_Owner* owner = Unk_WeakGet<Unk_1056d00_Owner>(field_68))
        owner->Unk_Fail(*code);
}

// 0x71010bd230
// 0x71010bd730
void Unk_2412c88::vf11() {
    if (Unk_1050c60_Owner* owner = Unk_WeakGet<Unk_1050c60_Owner>(field_68))
        owner->Unk_Cancel();
}

// 0x71010bea10
u64 Unk_2412f10::vf7() {
    if (field_78 == 0)
        field_78 = Unk_10bf0c0(this, &field_80);
    return field_78;
}

// 0x71010bea60
// 0x71010bef60
void Unk_2412f10::vf9() {
    if (Unk_1050c60_Owner* owner = Unk_WeakGet<Unk_1050c60_Owner>(field_68))
        Unk_1056680(owner);
}

// 0x71010bea90
// 0x71010bef90
void Unk_2412f10::vf10(const Unk_1085320_Optional<u32>* code) {
    if (Unk_1056d00_Owner* owner = Unk_WeakGet<Unk_1056d00_Owner>(field_68))
        owner->Unk_Fail(*code);
}

// 0x71010beb50
// 0x71010bf050
void Unk_2412f10::vf11() {
    if (Unk_1050c60_Owner* owner = Unk_WeakGet<Unk_1050c60_Owner>(field_68))
        owner->Unk_Cancel();
}

// 0x71010c0110
u64 Unk_2413198::vf7() {
    if (field_78 == 0)
        field_78 = Unk_10c07c0(this, &field_80);
    return field_78;
}

// 0x71010c0160
// 0x71010c0660
void Unk_2413198::vf9() {
    if (Unk_1050c60_Owner* owner = Unk_WeakGet<Unk_1050c60_Owner>(field_68))
        Unk_1056680(owner);
}

// 0x71010c0190
// 0x71010c0690
void Unk_2413198::vf10(const Unk_1085320_Optional<u32>* code) {
    if (Unk_1056d00_Owner* owner = Unk_WeakGet<Unk_1056d00_Owner>(field_68))
        owner->Unk_Fail(*code);
}

// 0x71010c0250
// 0x71010c0750
void Unk_2413198::vf11() {
    if (Unk_1050c60_Owner* owner = Unk_WeakGet<Unk_1050c60_Owner>(field_68))
        owner->Unk_Cancel();
}

// 0x71010c13d0
u64 Unk_2413370::vf7() {
    if (field_78 == 0)
        field_78 = Unk_10c1a80(this, &field_80);
    return field_78;
}

// 0x71010c1420
// 0x71010c1920
void Unk_2413370::vf9() {
    if (Unk_1050c60_Owner* owner = Unk_WeakGet<Unk_1050c60_Owner>(field_68))
        Unk_1056680(owner);
}

// 0x71010c1450
// 0x71010c1950
void Unk_2413370::vf10(const Unk_1085320_Optional<u32>* code) {
    if (Unk_1056d00_Owner* owner = Unk_WeakGet<Unk_1056d00_Owner>(field_68))
        owner->Unk_Fail(*code);
}

// 0x71010c1510
// 0x71010c1a10
void Unk_2413370::vf11() {
    if (Unk_1050c60_Owner* owner = Unk_WeakGet<Unk_1050c60_Owner>(field_68))
        owner->Unk_Cancel();
}

// 0x71010c7b90
u64 Unk_2413d48::vf7() {
    if (field_78 == 0)
        field_78 = Unk_10c8240(this, &field_80);
    return field_78;
}

// 0x71010c7be0
// 0x71010c80e0
void Unk_2413d48::vf9() {
    if (Unk_1050c60_Owner* owner = Unk_WeakGet<Unk_1050c60_Owner>(field_68))
        Unk_1056680(owner);
}

// 0x71010c7c10
// 0x71010c8110
void Unk_2413d48::vf10(const Unk_1085320_Optional<u32>* code) {
    if (Unk_1056d00_Owner* owner = Unk_WeakGet<Unk_1056d00_Owner>(field_68))
        owner->Unk_Fail(*code);
}

// 0x71010c7cd0
// 0x71010c81d0
void Unk_2413d48::vf11() {
    if (Unk_1050c60_Owner* owner = Unk_WeakGet<Unk_1050c60_Owner>(field_68))
        owner->Unk_Cancel();
}

// 0x71010c9690
u64 Unk_2413fd0::vf7() {
    if (field_78 == 0)
        field_78 = Unk_10c9d40(this, &field_80);
    return field_78;
}

// 0x71010c96e0
// 0x71010c9be0
void Unk_2413fd0::vf9() {
    if (Unk_1050c60_Owner* owner = Unk_WeakGet<Unk_1050c60_Owner>(field_68))
        Unk_1056680(owner);
}

// 0x71010c9710
// 0x71010c9c10
void Unk_2413fd0::vf10(const Unk_1085320_Optional<u32>* code) {
    if (Unk_1056d00_Owner* owner = Unk_WeakGet<Unk_1056d00_Owner>(field_68))
        owner->Unk_Fail(*code);
}

// 0x71010c97d0
// 0x71010c9cd0
void Unk_2413fd0::vf11() {
    if (Unk_1050c60_Owner* owner = Unk_WeakGet<Unk_1050c60_Owner>(field_68))
        owner->Unk_Cancel();
}

// 0x71010d05d0
u64 Unk_2414608::vf7() {
    if (field_78 == 0)
        field_78 = Unk_10d0c00(this, &field_80);
    return field_78;
}

// 0x71010d0620
// 0x71010d0aa0
void Unk_2414608::vf9() {
    if (Unk_1050c60_Owner* owner = Unk_WeakGet<Unk_1050c60_Owner>(field_68))
        Unk_1056680(owner);
}

// 0x71010d0650
// 0x71010d0ad0
void Unk_2414608::vf10(const Unk_1085320_Optional<u32>* code) {
    if (Unk_1056d00_Owner* owner = Unk_WeakGet<Unk_1056d00_Owner>(field_68))
        owner->Unk_Fail(*code);
}

// 0x71010d0710
// 0x71010d0b90
void Unk_2414608::vf11() {
    if (Unk_1050c60_Owner* owner = Unk_WeakGet<Unk_1050c60_Owner>(field_68))
        owner->Unk_Cancel();
}

// 0x71010d16a0
u64 Unk_24147b8::vf7() {
    if (field_78 == 0)
        field_78 = Unk_10d1cd0(this, &field_80);
    return field_78;
}

// 0x71010d16f0
// 0x71010d1b70
void Unk_24147b8::vf9() {
    if (Unk_1050c60_Owner* owner = Unk_WeakGet<Unk_1050c60_Owner>(field_68))
        Unk_1056680(owner);
}

// 0x71010d1720
// 0x71010d1ba0
void Unk_24147b8::vf10(const Unk_1085320_Optional<u32>* code) {
    if (Unk_1056d00_Owner* owner = Unk_WeakGet<Unk_1056d00_Owner>(field_68))
        owner->Unk_Fail(*code);
}

// 0x71010d17e0
// 0x71010d1c60
void Unk_24147b8::vf11() {
    if (Unk_1050c60_Owner* owner = Unk_WeakGet<Unk_1050c60_Owner>(field_68))
        owner->Unk_Cancel();
}

// 0x71010d2210
u64 Unk_24148b8::vf7() {
    if (field_78 == 0)
        field_78 = Unk_10d28c0(this, &field_80);
    return field_78;
}

// 0x71010d2260
// 0x71010d2760
void Unk_24148b8::vf9() {
    if (Unk_1050c60_Owner* owner = Unk_WeakGet<Unk_1050c60_Owner>(field_68))
        Unk_1056680(owner);
}

// 0x71010d2290
// 0x71010d2790
void Unk_24148b8::vf10(const Unk_1085320_Optional<u32>* code) {
    if (Unk_1056d00_Owner* owner = Unk_WeakGet<Unk_1056d00_Owner>(field_68))
        owner->Unk_Fail(*code);
}

// 0x71010d2350
// 0x71010d2850
void Unk_24148b8::vf11() {
    if (Unk_1050c60_Owner* owner = Unk_WeakGet<Unk_1050c60_Owner>(field_68))
        owner->Unk_Cancel();
}

// 0x71010d5fa0
u64 Unk_2414d00::vf7() {
    if (field_78 == 0)
        field_78 = Unk_10d6650(this, &field_80);
    return field_78;
}

// 0x71010d5ff0
// 0x71010d64f0
void Unk_2414d00::vf9() {
    if (Unk_1050c60_Owner* owner = Unk_WeakGet<Unk_1050c60_Owner>(field_68))
        Unk_1056680(owner);
}

// 0x71010d6020
// 0x71010d6520
void Unk_2414d00::vf10(const Unk_1085320_Optional<u32>* code) {
    if (Unk_1056d00_Owner* owner = Unk_WeakGet<Unk_1056d00_Owner>(field_68))
        owner->Unk_Fail(*code);
}

// 0x71010d60e0
// 0x71010d65e0
void Unk_2414d00::vf11() {
    if (Unk_1050c60_Owner* owner = Unk_WeakGet<Unk_1050c60_Owner>(field_68))
        owner->Unk_Cancel();
}

// 0x71010d8310
u64 Unk_2415100::vf7() {
    if (field_78 == 0)
        field_78 = Unk_10d8940(this, &field_80);
    return field_78;
}

// 0x71010d8360
// 0x71010d8820
void Unk_2415100::vf9() {
    if (Unk_1050c60_Owner* owner = Unk_WeakGet<Unk_1050c60_Owner>(field_68))
        Unk_10d7cb0(owner);
}

// 0x71010d8390
// 0x71010d8850
void Unk_2415100::vf10(u64 code) {
    if (Unk_1059aa0_Owner* owner = Unk_WeakGet<Unk_1059aa0_Owner>(field_68))
        owner->Unk_Fail(code);
}

// 0x71010d8410
// 0x71010d88d0
void Unk_2415100::vf11() {
    if (Unk_1050c60_Owner* owner = Unk_WeakGet<Unk_1050c60_Owner>(field_68))
        owner->Unk_Cancel();
}

// 0x71010d8ec0
u64 Unk_2415228::vf7() {
    if (field_78 == 0)
        field_78 = Unk_10d9570(this, &field_80);
    return field_78;
}

// 0x71010d8f10
// 0x71010d9410
void Unk_2415228::vf9() {
    if (Unk_1050c60_Owner* owner = Unk_WeakGet<Unk_1050c60_Owner>(field_68))
        Unk_10d7cb0(owner);
}

// 0x71010d8f40
// 0x71010d9440
void Unk_2415228::vf10(const Unk_1085320_Optional<u32>* code) {
    if (Unk_1054690_Owner* owner = Unk_WeakGet<Unk_1054690_Owner>(field_68))
        owner->Unk_Fail(*code);
}

// 0x71010d9000
// 0x71010d9500
void Unk_2415228::vf11() {
    if (Unk_1050c60_Owner* owner = Unk_WeakGet<Unk_1050c60_Owner>(field_68))
        owner->Unk_Cancel();
}

// 0x71010deff0
u64 Unk_2415868::vf7() {
    if (field_78 == 0)
        field_78 = Unk_10df620(this, &field_80);
    return field_78;
}

// 0x71010df040
// 0x71010df500
void Unk_2415868::vf9() {
    if (Unk_1050c60_Owner* owner = Unk_WeakGet<Unk_1050c60_Owner>(field_68))
        Unk_1084ff0(owner);
}

// 0x71010df070
// 0x71010df530
void Unk_2415868::vf10(u64 code) {
    if (Unk_1059aa0_Owner* owner = Unk_WeakGet<Unk_1059aa0_Owner>(field_68))
        owner->Unk_Fail(code);
}

// 0x71010df0f0
// 0x71010df5b0
void Unk_2415868::vf11() {
    if (Unk_1050c60_Owner* owner = Unk_WeakGet<Unk_1050c60_Owner>(field_68))
        owner->Unk_Cancel();
}

// 0x71010e0210
u64 Unk_2415a40::vf7() {
    if (field_78 == 0)
        field_78 = Unk_10e0840(this, &field_80);
    return field_78;
}

// 0x71010e0260
// 0x71010e0720
void Unk_2415a40::vf9() {
    if (Unk_1050c60_Owner* owner = Unk_WeakGet<Unk_1050c60_Owner>(field_68))
        Unk_1084ff0(owner);
}

// 0x71010e0290
// 0x71010e0750
void Unk_2415a40::vf10(u64 code) {
    if (Unk_1059aa0_Owner* owner = Unk_WeakGet<Unk_1059aa0_Owner>(field_68))
        owner->Unk_Fail(code);
}

// 0x71010e0310
// 0x71010e07d0
void Unk_2415a40::vf11() {
    if (Unk_1050c60_Owner* owner = Unk_WeakGet<Unk_1050c60_Owner>(field_68))
        owner->Unk_Cancel();
}

// 0x71010e1020
u64 Unk_2415b68::vf7() {
    if (field_78 == 0)
        field_78 = Unk_10e15d0(this, &field_80);
    return field_78;
}

// 0x71010e1070
// 0x71010e14b0
void Unk_2415b68::vf9() {
    if (Unk_1050c60_Owner* owner = Unk_WeakGet<Unk_1050c60_Owner>(field_68))
        Unk_1084ff0(owner);
}

// 0x71010e10a0
// 0x71010e14e0
void Unk_2415b68::vf10(u64 code) {
    if (Unk_1059aa0_Owner* owner = Unk_WeakGet<Unk_1059aa0_Owner>(field_68))
        owner->Unk_Fail(code);
}

// 0x71010e1120
// 0x71010e1560
void Unk_2415b68::vf11() {
    if (Unk_1050c60_Owner* owner = Unk_WeakGet<Unk_1050c60_Owner>(field_68))
        owner->Unk_Cancel();
}

// 0x71010e25e0
u64 Unk_2415df0::vf7() {
    if (field_78 == 0)
        field_78 = Unk_10e2c10(this, &field_80);
    return field_78;
}

// 0x71010e2630
// 0x71010e2af0
void Unk_2415df0::vf9() {
    if (Unk_1050c60_Owner* owner = Unk_WeakGet<Unk_1050c60_Owner>(field_68))
        Unk_1084ff0(owner);
}

// 0x71010e2660
// 0x71010e2b20
void Unk_2415df0::vf10(u64 code) {
    if (Unk_1059aa0_Owner* owner = Unk_WeakGet<Unk_1059aa0_Owner>(field_68))
        owner->Unk_Fail(code);
}

// 0x71010e26e0
// 0x71010e2ba0
void Unk_2415df0::vf11() {
    if (Unk_1050c60_Owner* owner = Unk_WeakGet<Unk_1050c60_Owner>(field_68))
        owner->Unk_Cancel();
}

// 0x71010e7100
u64 Unk_2416438::vf7() {
    if (field_78 == 0)
        field_78 = Unk_10e7730(this, &field_80);
    return field_78;
}

// 0x71010e7150
// 0x71010e7610
void Unk_2416438::vf9() {
    if (Unk_1050c60_Owner* owner = Unk_WeakGet<Unk_1050c60_Owner>(field_68))
        Unk_1084ff0(owner);
}

// 0x71010e7180
// 0x71010e7640
void Unk_2416438::vf10(u64 code) {
    if (Unk_1059aa0_Owner* owner = Unk_WeakGet<Unk_1059aa0_Owner>(field_68))
        owner->Unk_Fail(code);
}

// 0x71010e7200
// 0x71010e76c0
void Unk_2416438::vf11() {
    if (Unk_1050c60_Owner* owner = Unk_WeakGet<Unk_1050c60_Owner>(field_68))
        owner->Unk_Cancel();
}

// 0x71010e8860
u64 Unk_24166c0::vf7() {
    if (field_78 == 0)
        field_78 = Unk_10e8e90(this, &field_80);
    return field_78;
}

// 0x71010e88b0
// 0x71010e8d70
void Unk_24166c0::vf9() {
    if (Unk_1050c60_Owner* owner = Unk_WeakGet<Unk_1050c60_Owner>(field_68))
        Unk_1084ff0(owner);
}

// 0x71010e88e0
// 0x71010e8da0
void Unk_24166c0::vf10(u64 code) {
    if (Unk_1059aa0_Owner* owner = Unk_WeakGet<Unk_1059aa0_Owner>(field_68))
        owner->Unk_Fail(code);
}

// 0x71010e8960
// 0x71010e8e20
void Unk_24166c0::vf11() {
    if (Unk_1050c60_Owner* owner = Unk_WeakGet<Unk_1050c60_Owner>(field_68))
        owner->Unk_Cancel();
}

// 0x71010e9670
u64 Unk_24167e8::vf7() {
    if (field_78 == 0)
        field_78 = Unk_10e9c20(this, &field_80);
    return field_78;
}

// 0x71010e96c0
// 0x71010e9b00
void Unk_24167e8::vf9() {
    if (Unk_1050c60_Owner* owner = Unk_WeakGet<Unk_1050c60_Owner>(field_68))
        Unk_1084ff0(owner);
}

// 0x71010e96f0
// 0x71010e9b30
void Unk_24167e8::vf10(u64 code) {
    if (Unk_1059aa0_Owner* owner = Unk_WeakGet<Unk_1059aa0_Owner>(field_68))
        owner->Unk_Fail(code);
}

// 0x71010e9770
// 0x71010e9bb0
void Unk_24167e8::vf11() {
    if (Unk_1050c60_Owner* owner = Unk_WeakGet<Unk_1050c60_Owner>(field_68))
        owner->Unk_Cancel();
}

// 0x71010ecce0
u64 Unk_2416cc8::vf7() {
    if (field_78 == 0)
        field_78 = Unk_10ed310(this, &field_80);
    return field_78;
}

// 0x71010ecd30
// 0x71010ed1b0
void Unk_2416cc8::vf9() {
    if (Unk_1050c60_Owner* owner = Unk_WeakGet<Unk_1050c60_Owner>(field_68))
        Unk_1056680(owner);
}

// 0x71010ecd60
// 0x71010ed1e0
void Unk_2416cc8::vf10(const Unk_1085320_Optional<u32>* code) {
    if (Unk_1056d00_Owner* owner = Unk_WeakGet<Unk_1056d00_Owner>(field_68))
        owner->Unk_Fail(*code);
}

// 0x71010ece20
// 0x71010ed2a0
void Unk_2416cc8::vf11() {
    if (Unk_1050c60_Owner* owner = Unk_WeakGet<Unk_1050c60_Owner>(field_68))
        owner->Unk_Cancel();
}

// 0x71010eef50
u64 Unk_24170c8::vf7() {
    if (field_78 == 0)
        field_78 = Unk_10ef580(this, &field_80);
    return field_78;
}

// 0x71010eefa0
// 0x71010ef460
void Unk_24170c8::vf9() {
    if (Unk_1050c60_Owner* owner = Unk_WeakGet<Unk_1050c60_Owner>(field_68))
        Unk_10ee8f0(owner);
}

// 0x71010eefd0
// 0x71010ef490
void Unk_24170c8::vf10(u64 code) {
    if (Unk_1059aa0_Owner* owner = Unk_WeakGet<Unk_1059aa0_Owner>(field_68))
        owner->Unk_Fail(code);
}

// 0x71010ef050
// 0x71010ef510
void Unk_24170c8::vf11() {
    if (Unk_1050c60_Owner* owner = Unk_WeakGet<Unk_1050c60_Owner>(field_68))
        owner->Unk_Cancel();
}

// 0x71010efb00
u64 Unk_24171f0::vf7() {
    if (field_78 == 0)
        field_78 = Unk_10f01b0(this, &field_80);
    return field_78;
}

// 0x71010efb50
// 0x71010f0050
void Unk_24171f0::vf9() {
    if (Unk_1050c60_Owner* owner = Unk_WeakGet<Unk_1050c60_Owner>(field_68))
        Unk_10ee8f0(owner);
}

// 0x71010efb80
// 0x71010f0080
void Unk_24171f0::vf10(const Unk_1085320_Optional<u32>* code) {
    if (Unk_1054690_Owner* owner = Unk_WeakGet<Unk_1054690_Owner>(field_68))
        owner->Unk_Fail(*code);
}

// 0x71010efc40
// 0x71010f0140
void Unk_24171f0::vf11() {
    if (Unk_1050c60_Owner* owner = Unk_WeakGet<Unk_1050c60_Owner>(field_68))
        owner->Unk_Cancel();
}

// 0x71010f39d0
u64 Unk_2417870::vf7() {
    if (field_78 == 0)
        field_78 = Unk_10f4080(this, &field_80);
    return field_78;
}

// 0x71010f3a20
// 0x71010f3f20
void Unk_2417870::vf9() {
    if (Unk_1050c60_Owner* owner = Unk_WeakGet<Unk_1050c60_Owner>(field_68))
        Unk_1056680(owner);
}

// 0x71010f3a50
// 0x71010f3f50
void Unk_2417870::vf10(const Unk_1085320_Optional<u32>* code) {
    if (Unk_1056d00_Owner* owner = Unk_WeakGet<Unk_1056d00_Owner>(field_68))
        owner->Unk_Fail(*code);
}

// 0x71010f3b10
// 0x71010f4010
void Unk_2417870::vf11() {
    if (Unk_1050c60_Owner* owner = Unk_WeakGet<Unk_1050c60_Owner>(field_68))
        owner->Unk_Cancel();
}

// 0x7101102a00
u64 Unk_24184a0::vf7() {
    if (field_78 == 0)
        field_78 = Unk_11030b0(this, &field_80);
    return field_78;
}

// 0x7101102a50
// 0x7101102f50
void Unk_24184a0::vf9() {
    if (Unk_1050c60_Owner* owner = Unk_WeakGet<Unk_1050c60_Owner>(field_68))
        Unk_1056680(owner);
}

// 0x7101102a80
// 0x7101102f80
void Unk_24184a0::vf10(const Unk_1085320_Optional<u32>* code) {
    if (Unk_1056d00_Owner* owner = Unk_WeakGet<Unk_1056d00_Owner>(field_68))
        owner->Unk_Fail(*code);
}

// 0x7101102b40
// 0x7101103040
void Unk_24184a0::vf11() {
    if (Unk_1050c60_Owner* owner = Unk_WeakGet<Unk_1050c60_Owner>(field_68))
        owner->Unk_Cancel();
}
