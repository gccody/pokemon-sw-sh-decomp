// Scope: common
// A class template whose instances keep themselves in a list of all objects
// of their type: the base of several Wwise classes, one instance per derived
// class. Each instance's list is a static data member (initialised in every
// TU that uses it, under a guard) and its destructor removes the object from
// the list. Placeholder names; Unk_Registered's tag types name the vtables.
#include <types.h>

// The list of all objects of one type.
struct Unk_RegisteredList {
    u32 field_0;  // number of objects
    void* field_8;  // first
    void* field_10;  // last

    Unk_RegisteredList() : field_0(0), field_8(nullptr), field_10(nullptr) {}
};

template <class Tag>
struct Unk_Registered {
    static Unk_RegisteredList s_list;

    virtual ~Unk_Registered() {
        if (field_10 != nullptr)
            field_10->field_18 = field_18;
        Unk_Registered* prev = field_10;
        Unk_Registered* next = field_18;
        if (s_list.field_10 == this)
            s_list.field_10 = prev;
        else
            next->field_10 = prev;
        if (s_list.field_8 == this)
            s_list.field_8 = next;
        s_list.field_0--;
    }

    u64 field_8;
    Unk_Registered* field_10;  // previous
    Unk_Registered* field_18;  // next
};

template <class Tag>
Unk_RegisteredList Unk_Registered<Tag>::s_list;

// The instances, by vtable.
struct Unk_237e7f8 {};
struct Unk_2382ba8 {};
struct Unk_2382bd0 {};
struct Unk_2382c20 {};
struct Unk_2385850 {};
struct Unk_2385878 {};
struct Unk_23858a0 {};
struct Unk_23858f0 {};

// 0x710032eb60, 0x710032ebe0, 0x710032e690
template struct Unk_Registered<Unk_237e7f8>;
// 0x7100397350, 0x71003973d0, 0x710033f060
template struct Unk_Registered<Unk_2382ba8>;
// 0x7100397450, 0x71003974d0, 0x7100396f40
template struct Unk_Registered<Unk_2382bd0>;
// 0x7100399b50, 0x7100399bd0, 0x7100403960
template struct Unk_Registered<Unk_2382c20>;
// 0x71003e6da0, 0x71003e6e20, 0x7100403930
template struct Unk_Registered<Unk_2385850>;
// 0x71003e7010, 0x71003e7090, 0x71003e6ab0
template struct Unk_Registered<Unk_2385878>;
// 0x71003e7110, 0x71003e7190, 0x71003e6a80
template struct Unk_Registered<Unk_23858a0>;
// 0x71003ea290, 0x71003ea310, 0x71003e6ae0
template struct Unk_Registered<Unk_23858f0>;
