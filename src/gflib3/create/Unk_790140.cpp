// Scope: common
//
// The creators' wrappers (Unk_790260_Owner::Unk_790140<T>, placeholder,
// src/gflib3/Unk_790260.h): each makes a T with its creator (Create<T>, in
// src/gflib3/families/Unk_790260.cpp when it's written) under a parent and
// hands it to a target. One template, an instance per class.
// Written by tools/creategen.py: regenerate, don't edit.
#include "gflib3/Unk_790260.h"

// 0x7100e809c0 (src/unsorted/leaf/Unk_e7c1a0.cpp): hands `value` to the
// object's field_5a0. The wrappers' target is that object, an Unk_23f4660.
struct Unk_e809c0;
void Unk_e809c0_call(const Unk_e809c0* self, void* value);

// NON_MATCHING: two of LLVM's block duplications differ from the original's.
// It threads the parent's copy past the copy's null test (as it does here for
// a copy made from the pointer, Unk_Ref(parent.m_ptr): Unk_239a418_Ref's copy
// tests the other reference's pointer through an i64 load, which LVI can't see
// through). And it computes the target's +0x48 interface again for the drop,
// where here GVN merges it with the add's, the drop's null test being folded
// before GVN runs (a copy of field_70 as a reference keeps the two apart, but
// then the test isn't folded at all).
template <class T>
Unk_239a418_Ref<T> Unk_790260_Owner::Unk_790140(Unk_Ref parent,
                                                Unk_23f4660* target,
                                                const char* name) {
    if (!parent.m_ptr)
        parent = field_58;
    Unk_239a418_Ref<T> result = Create<T>(parent, name);
    Unk_239a418_Ref<Unk_23f4660> to(target ? target : field_70);
    Unk_e809c0_call(reinterpret_cast<const Unk_e809c0*>(to.m_ptr), result.m_ptr);
    return result;
}

// The classes, declared only as far as a reference to one needs: classes on
// Unk_23f4660 (their members are in the creators' file, or unknown).
class Unk_23a8bd8 : public Unk_23f4660 {};
class Unk_23a8f48 : public Unk_23f4660 {};
class Unk_23a9048 : public Unk_23f4660 {};
class Unk_23a99d8 : public Unk_23f4660 {};
class Unk_23bbb80 : public Unk_23f4660 {};
class Unk_23bbd50 : public Unk_23f4660 {};
class Unk_23bbe68 : public Unk_23f4660 {};
class Unk_23bca18 : public Unk_23f4660 {};
class Unk_23bcc08 : public Unk_23f4660 {};
class Unk_23bd220 : public Unk_23f4660 {};
class Unk_23bd4b8 : public Unk_23f4660 {};
class Unk_23bd5b8 : public Unk_23f4660 {};
class Unk_23bd6b8 : public Unk_23f4660 {};
class Unk_23bd900 : public Unk_23f4660 {};
class Unk_23bda50 : public Unk_23f4660 {};
class Unk_23be058 : public Unk_23f4660 {};
class Unk_23be158 : public Unk_23f4660 {};
class Unk_23be300 : public Unk_23f4660 {};
class Unk_23be4d0 : public Unk_23f4660 {};
class Unk_23be868 : public Unk_23f4660 {};
class Unk_23bee08 : public Unk_23f4660 {};
class Unk_23bf300 : public Unk_23f4660 {};
class Unk_23bf6a8 : public Unk_23f4660 {};
class Unk_23bfd60 : public Unk_23f4660 {};
class Unk_23c0158 : public Unk_23f4660 {};
class Unk_23c0268 : public Unk_23f4660 {};
class Unk_23c0448 : public Unk_23f4660 {};
class Unk_23c0790 : public Unk_23f4660 {};
class Unk_23c6030 : public Unk_23f4660 {};
class Unk_23c7dd0 : public Unk_23f4660 {};
class Unk_23c7ed0 : public Unk_23f4660 {};
class Unk_23c81e8 : public Unk_23f4660 {};
class Unk_23c8530 : public Unk_23f4660 {};
class Unk_23c9028 : public Unk_23f4660 {};
class Unk_23c9150 : public Unk_23f4660 {};
class Unk_23c9278 : public Unk_23f4660 {};
class Unk_23c9660 : public Unk_23f4660 {};
class Unk_23c9788 : public Unk_23f4660 {};
class Unk_23c9988 : public Unk_23f4660 {};
class Unk_23c9c78 : public Unk_23f4660 {};
class Unk_23c9da0 : public Unk_23f4660 {};
class Unk_23c9ff0 : public Unk_23f4660 {};
class Unk_23ca1a8 : public Unk_23f4660 {};
class Unk_23ca2e0 : public Unk_23f4660 {};
class Unk_23ca420 : public Unk_23f4660 {};
class Unk_23cbbc8 : public Unk_23f4660 {};
class Unk_23cbe10 : public Unk_23f4660 {};
class Unk_23cc148 : public Unk_23f4660 {};
class Unk_23cc5a0 : public Unk_23f4660 {};
class Unk_23cc7a0 : public Unk_23f4660 {};
class Unk_23ccd60 : public Unk_23f4660 {};
class Unk_23d3008 : public Unk_23f4660 {};
class Unk_23d3240 : public Unk_23f4660 {};
class Unk_23d3368 : public Unk_23f4660 {};
class Unk_23da638 : public Unk_23f4660 {};
class Unk_23f2b90 : public Unk_23f4660 {};
class Unk_23f2cf0 : public Unk_23f4660 {};
class Unk_23f2f10 : public Unk_23f4660 {};
class Unk_23f3030 : public Unk_23f4660 {};
class Unk_23f3570 : public Unk_23f4660 {};
class Unk_23f3f48 : public Unk_23f4660 {};
class Unk_23f5fa8 : public Unk_23f4660 {};
class Unk_23f6118 : public Unk_23f4660 {};
class Unk_23f6218 : public Unk_23f4660 {};
class Unk_23f65d0 : public Unk_23f4660 {};
class Unk_23f67a0 : public Unk_23f4660 {};
class Unk_23f6a68 : public Unk_23f4660 {};
class Unk_23f6c80 : public Unk_23f4660 {};
class Unk_23f6de0 : public Unk_23f4660 {};
class Unk_23f8b08 : public Unk_23f4660 {};
class Unk_23f9048 : public Unk_23f4660 {};
class Unk_23fac70 : public Unk_23f4660 {};
class Unk_23fad70 : public Unk_23f4660 {};
class Unk_23faea0 : public Unk_23f4660 {};
class Unk_23fafb8 : public Unk_23f4660 {};
class Unk_23fb0b8 : public Unk_23f4660 {};
class Unk_23fb3d0 : public Unk_23f4660 {};
class Unk_23fbd40 : public Unk_23f4660 {};
class Unk_23fbe78 : public Unk_23f4660 {};
class Unk_23fc690 : public Unk_23f4660 {};
class Unk_23fd038 : public Unk_23f4660 {};
class Unk_23fd330 : public Unk_23f4660 {};
class Unk_23fd920 : public Unk_23f4660 {};
class Unk_23fdce0 : public Unk_23f4660 {};
class Unk_23fde10 : public Unk_23f4660 {};
class Unk_23fdf10 : public Unk_23f4660 {};
class Unk_23fe058 : public Unk_23f4660 {};
class Unk_23fe270 : public Unk_23f4660 {};
class Unk_23fe610 : public Unk_23f4660 {};
class Unk_23ff270 : public Unk_23f4660 {};
class Unk_23ff3d0 : public Unk_23f4660 {};
class Unk_23ff740 : public Unk_23f4660 {};
class Unk_23ff8e0 : public Unk_23f4660 {};
class Unk_23ffb78 : public Unk_23f4660 {};
class Unk_23ffe00 : public Unk_23f4660 {};
class Unk_2400128 : public Unk_23f4660 {};
class Unk_2400560 : public Unk_23f4660 {};
class Unk_2400900 : public Unk_23f4660 {};
class Unk_2400bd8 : public Unk_23f4660 {};
class Unk_24013c0 : public Unk_23f4660 {};
class Unk_2402ab0 : public Unk_23f4660 {};
class Unk_2402c18 : public Unk_23f4660 {};
class Unk_24033d0 : public Unk_23f4660 {};
class Unk_2403638 : public Unk_23f4660 {};
class Unk_24039e0 : public Unk_23f4660 {};
class Unk_2403b08 : public Unk_23f4660 {};
class Unk_2403c30 : public Unk_23f4660 {};
class Unk_2403e60 : public Unk_23f4660 {};
class Unk_24269d8 : public Unk_23f4660 {};
class Unk_2426be8 : public Unk_23f4660 {};
class Unk_2427748 : public Unk_23f4660 {};
class Unk_2427c48 : public Unk_23f4660 {};
class Unk_2427d58 : public Unk_23f4660 {};
class Unk_2427e68 : public Unk_23f4660 {};
class Unk_2428128 : public Unk_23f4660 {};
class Unk_2428680 : public Unk_23f4660 {};
class Unk_2428850 : public Unk_23f4660 {};
class Unk_2428b48 : public Unk_23f4660 {};
class Unk_2429118 : public Unk_23f4660 {};
class Unk_2429218 : public Unk_23f4660 {};
class Unk_24293e8 : public Unk_23f4660 {};
class Unk_242bf88 : public Unk_23f4660 {};
class Unk_242c0a0 : public Unk_23f4660 {};
class Unk_242c1b8 : public Unk_23f4660 {};
class Unk_242c2d0 : public Unk_23f4660 {};
class Unk_242c3e8 : public Unk_23f4660 {};
class Unk_242c500 : public Unk_23f4660 {};
class Unk_242c858 : public Unk_23f4660 {};
class Unk_242cae8 : public Unk_23f4660 {};
class Unk_242d2f8 : public Unk_23f4660 {};
class Unk_242d4f8 : public Unk_23f4660 {};
class Unk_242d838 : public Unk_23f4660 {};
class Unk_242d978 : public Unk_23f4660 {};
class Unk_242e438 : public Unk_23f4660 {};
class Unk_242e928 : public Unk_23f4660 {};
class Unk_242f1e0 : public Unk_23f4660 {};
class Unk_242f2e0 : public Unk_23f4660 {};
class Unk_242fed0 : public Unk_23f4660 {};
class Unk_24306f8 : public Unk_23f4660 {};
class Unk_2430ee0 : public Unk_23f4660 {};
class Unk_2431618 : public Unk_23f4660 {};
class Unk_24390d0 : public Unk_23f4660 {};
class Unk_2439200 : public Unk_23f4660 {};
class Unk_2439b60 : public Unk_23f4660 {};
class Unk_2439c60 : public Unk_23f4660 {};
class Unk_2439d60 : public Unk_23f4660 {};
class Unk_243a9d0 : public Unk_23f4660 {};
class Unk_243bf78 : public Unk_23f4660 {};
class Unk_243cee0 : public Unk_23f4660 {};
class Unk_243cff8 : public Unk_23f4660 {};
class Unk_243d1c8 : public Unk_23f4660 {};
class Unk_243d7a0 : public Unk_23f4660 {};
class Unk_243d958 : public Unk_23f4660 {};
class Unk_243dc10 : public Unk_23f4660 {};
class Unk_243dd28 : public Unk_23f4660 {};
class Unk_243e198 : public Unk_23f4660 {};
class Unk_243e520 : public Unk_23f4660 {};
class Unk_24415a8 : public Unk_23f4660 {};
class Unk_24416b0 : public Unk_23f4660 {};
class Unk_24417c0 : public Unk_23f4660 {};
class Unk_24418e0 : public Unk_23f4660 {};
class Unk_2441a00 : public Unk_23f4660 {};
class Unk_2441b28 : public Unk_23f4660 {};
class Unk_2441c98 : public Unk_23f4660 {};
class Unk_2441dc0 : public Unk_23f4660 {};
class Unk_2443818 : public Unk_23f4660 {};
class Unk_2443918 : public Unk_23f4660 {};
class Unk_2446c08 : public Unk_23f4660 {};
class Unk_2446d08 : public Unk_23f4660 {};
class Unk_2447498 : public Unk_23f4660 {};
class Unk_2447cf0 : public Unk_23f4660 {};
class Unk_2447e50 : public Unk_23f4660 {};
class Unk_2448020 : public Unk_23f4660 {};
class Unk_24482c0 : public Unk_23f4660 {};
class Unk_2448660 : public Unk_23f4660 {};
class Unk_2449670 : public Unk_23f4660 {};
class Unk_2449870 : public Unk_23f4660 {};
class Unk_2449970 : public Unk_23f4660 {};

// 0x7100790140
template Unk_239a418_Ref<Unk_23f5fa8> Unk_790260_Owner::Unk_790140<Unk_23f5fa8>(Unk_Ref parent,
                                                                                Unk_23f4660* target,
                                                                                const char* name);

// 0x7100799f80
template Unk_239a418_Ref<Unk_23a8bd8> Unk_790260_Owner::Unk_790140<Unk_23a8bd8>(Unk_Ref parent,
                                                                                Unk_23f4660* target,
                                                                                const char* name);

// 0x710079a420
template Unk_239a418_Ref<Unk_23a99d8> Unk_790260_Owner::Unk_790140<Unk_23a99d8>(Unk_Ref parent,
                                                                                Unk_23f4660* target,
                                                                                const char* name);

// 0x710079a790
template Unk_239a418_Ref<Unk_23a9048> Unk_790260_Owner::Unk_790140<Unk_23a9048>(Unk_Ref parent,
                                                                                Unk_23f4660* target,
                                                                                const char* name);

// 0x710079ab20
template Unk_239a418_Ref<Unk_23f6218> Unk_790260_Owner::Unk_790140<Unk_23f6218>(Unk_Ref parent,
                                                                                Unk_23f4660* target,
                                                                                const char* name);

// 0x710079af00
template Unk_239a418_Ref<Unk_23a8f48> Unk_790260_Owner::Unk_790140<Unk_23a8f48>(Unk_Ref parent,
                                                                                Unk_23f4660* target,
                                                                                const char* name);

// 0x710079b250
template Unk_239a418_Ref<Unk_23f6118> Unk_790260_Owner::Unk_790140<Unk_23f6118>(Unk_Ref parent,
                                                                                Unk_23f4660* target,
                                                                                const char* name);

// 0x71008d2d20
template Unk_239a418_Ref<Unk_23bbd50> Unk_790260_Owner::Unk_790140<Unk_23bbd50>(Unk_Ref parent,
                                                                                Unk_23f4660* target,
                                                                                const char* name);

// 0x71008d30e0
template Unk_239a418_Ref<Unk_23bbe68> Unk_790260_Owner::Unk_790140<Unk_23bbe68>(Unk_Ref parent,
                                                                                Unk_23f4660* target,
                                                                                const char* name);

// 0x71008d3440
template Unk_239a418_Ref<Unk_23bbb80> Unk_790260_Owner::Unk_790140<Unk_23bbb80>(Unk_Ref parent,
                                                                                Unk_23f4660* target,
                                                                                const char* name);

// 0x71008e59a0
template Unk_239a418_Ref<Unk_23bcc08> Unk_790260_Owner::Unk_790140<Unk_23bcc08>(Unk_Ref parent,
                                                                                Unk_23f4660* target,
                                                                                const char* name);

// 0x71008e5d80
template Unk_239a418_Ref<Unk_23bca18> Unk_790260_Owner::Unk_790140<Unk_23bca18>(Unk_Ref parent,
                                                                                Unk_23f4660* target,
                                                                                const char* name);

// 0x71008e6310
template Unk_239a418_Ref<Unk_23f65d0> Unk_790260_Owner::Unk_790140<Unk_23f65d0>(Unk_Ref parent,
                                                                                Unk_23f4660* target,
                                                                                const char* name);

// 0x710090f5d0
template Unk_239a418_Ref<Unk_23bda50> Unk_790260_Owner::Unk_790140<Unk_23bda50>(Unk_Ref parent,
                                                                                Unk_23f4660* target,
                                                                                const char* name);

// 0x710090f930
template Unk_239a418_Ref<Unk_23bd220> Unk_790260_Owner::Unk_790140<Unk_23bd220>(Unk_Ref parent,
                                                                                Unk_23f4660* target,
                                                                                const char* name);

// 0x710090fcd0
template Unk_239a418_Ref<Unk_23be300> Unk_790260_Owner::Unk_790140<Unk_23be300>(Unk_Ref parent,
                                                                                Unk_23f4660* target,
                                                                                const char* name);

// 0x7100910090
template Unk_239a418_Ref<Unk_23bf6a8> Unk_790260_Owner::Unk_790140<Unk_23bf6a8>(Unk_Ref parent,
                                                                                Unk_23f4660* target,
                                                                                const char* name);

// 0x71009104b0
template Unk_239a418_Ref<Unk_23be868> Unk_790260_Owner::Unk_790140<Unk_23be868>(Unk_Ref parent,
                                                                                Unk_23f4660* target,
                                                                                const char* name);

// 0x7100910830
template Unk_239a418_Ref<Unk_23be058> Unk_790260_Owner::Unk_790140<Unk_23be058>(Unk_Ref parent,
                                                                                Unk_23f4660* target,
                                                                                const char* name);

// 0x7100910ba0
template Unk_239a418_Ref<Unk_23bd4b8> Unk_790260_Owner::Unk_790140<Unk_23bd4b8>(Unk_Ref parent,
                                                                                Unk_23f4660* target,
                                                                                const char* name);

// 0x7100910ef0
template Unk_239a418_Ref<Unk_23bfd60> Unk_790260_Owner::Unk_790140<Unk_23bfd60>(Unk_Ref parent,
                                                                                Unk_23f4660* target,
                                                                                const char* name);

// 0x71009113f0
template Unk_239a418_Ref<Unk_23bd900> Unk_790260_Owner::Unk_790140<Unk_23bd900>(Unk_Ref parent,
                                                                                Unk_23f4660* target,
                                                                                const char* name);

// 0x71009117e0
template Unk_239a418_Ref<Unk_23be4d0> Unk_790260_Owner::Unk_790140<Unk_23be4d0>(Unk_Ref parent,
                                                                                Unk_23f4660* target,
                                                                                const char* name);

// 0x7100911b30
template Unk_239a418_Ref<Unk_23bee08> Unk_790260_Owner::Unk_790140<Unk_23bee08>(Unk_Ref parent,
                                                                                Unk_23f4660* target,
                                                                                const char* name);

// 0x7100911ec0
template Unk_239a418_Ref<Unk_23bf300> Unk_790260_Owner::Unk_790140<Unk_23bf300>(Unk_Ref parent,
                                                                                Unk_23f4660* target,
                                                                                const char* name);

// 0x7100912230
template Unk_239a418_Ref<Unk_23be158> Unk_790260_Owner::Unk_790140<Unk_23be158>(Unk_Ref parent,
                                                                                Unk_23f4660* target,
                                                                                const char* name);

// 0x7100912610
template Unk_239a418_Ref<Unk_23f6c80> Unk_790260_Owner::Unk_790140<Unk_23f6c80>(Unk_Ref parent,
                                                                                Unk_23f4660* target,
                                                                                const char* name);

// 0x7100913160
template Unk_239a418_Ref<Unk_23bd6b8> Unk_790260_Owner::Unk_790140<Unk_23bd6b8>(Unk_Ref parent,
                                                                                Unk_23f4660* target,
                                                                                const char* name);

// 0x7100913520
template Unk_239a418_Ref<Unk_23bd5b8> Unk_790260_Owner::Unk_790140<Unk_23bd5b8>(Unk_Ref parent,
                                                                                Unk_23f4660* target,
                                                                                const char* name);

// 0x710093ea20
template Unk_239a418_Ref<Unk_23c0448> Unk_790260_Owner::Unk_790140<Unk_23c0448>(Unk_Ref parent,
                                                                                Unk_23f4660* target,
                                                                                const char* name);

// 0x710093ed70
template Unk_239a418_Ref<Unk_23c0158> Unk_790260_Owner::Unk_790140<Unk_23c0158>(Unk_Ref parent,
                                                                                Unk_23f4660* target,
                                                                                const char* name);

// 0x710093f1b0
template Unk_239a418_Ref<Unk_23c0268> Unk_790260_Owner::Unk_790140<Unk_23c0268>(Unk_Ref parent,
                                                                                Unk_23f4660* target,
                                                                                const char* name);

// 0x710093f5f0
template Unk_239a418_Ref<Unk_23c0790> Unk_790260_Owner::Unk_790140<Unk_23c0790>(Unk_Ref parent,
                                                                                Unk_23f4660* target,
                                                                                const char* name);

// 0x7100a708b0
template Unk_239a418_Ref<Unk_23c6030> Unk_790260_Owner::Unk_790140<Unk_23c6030>(Unk_Ref parent,
                                                                                Unk_23f4660* target,
                                                                                const char* name);

// 0x7100a7a9b0
template Unk_239a418_Ref<Unk_23c81e8> Unk_790260_Owner::Unk_790140<Unk_23c81e8>(Unk_Ref parent,
                                                                                Unk_23f4660* target,
                                                                                const char* name);

// 0x7100a7ae20
template Unk_239a418_Ref<Unk_23c7ed0> Unk_790260_Owner::Unk_790140<Unk_23c7ed0>(Unk_Ref parent,
                                                                                Unk_23f4660* target,
                                                                                const char* name);

// 0x7100a7b1b0
template Unk_239a418_Ref<Unk_23c8530> Unk_790260_Owner::Unk_790140<Unk_23c8530>(Unk_Ref parent,
                                                                                Unk_23f4660* target,
                                                                                const char* name);

// 0x7100a7b500
template Unk_239a418_Ref<Unk_23c7dd0> Unk_790260_Owner::Unk_790140<Unk_23c7dd0>(Unk_Ref parent,
                                                                                Unk_23f4660* target,
                                                                                const char* name);

// 0x7100ac5c80
template Unk_239a418_Ref<Unk_23c9660> Unk_790260_Owner::Unk_790140<Unk_23c9660>(Unk_Ref parent,
                                                                                Unk_23f4660* target,
                                                                                const char* name);

// 0x7100ac6090
template Unk_239a418_Ref<Unk_23c9788> Unk_790260_Owner::Unk_790140<Unk_23c9788>(Unk_Ref parent,
                                                                                Unk_23f4660* target,
                                                                                const char* name);

// 0x7100ac64a0
template Unk_239a418_Ref<Unk_23c9c78> Unk_790260_Owner::Unk_790140<Unk_23c9c78>(Unk_Ref parent,
                                                                                Unk_23f4660* target,
                                                                                const char* name);

// 0x7100ac68b0
template Unk_239a418_Ref<Unk_23cc148> Unk_790260_Owner::Unk_790140<Unk_23cc148>(Unk_Ref parent,
                                                                                Unk_23f4660* target,
                                                                                const char* name);

// 0x7100ac6cd0
template Unk_239a418_Ref<Unk_23c9028> Unk_790260_Owner::Unk_790140<Unk_23c9028>(Unk_Ref parent,
                                                                                Unk_23f4660* target,
                                                                                const char* name);

// 0x7100ac7760
template Unk_239a418_Ref<Unk_23cbe10> Unk_790260_Owner::Unk_790140<Unk_23cbe10>(Unk_Ref parent,
                                                                                Unk_23f4660* target,
                                                                                const char* name);

// 0x7100ac7b80
template Unk_239a418_Ref<Unk_23c9150> Unk_790260_Owner::Unk_790140<Unk_23c9150>(Unk_Ref parent,
                                                                                Unk_23f4660* target,
                                                                                const char* name);

// 0x7100ac81f0
template Unk_239a418_Ref<Unk_23cc7a0> Unk_790260_Owner::Unk_790140<Unk_23cc7a0>(Unk_Ref parent,
                                                                                Unk_23f4660* target,
                                                                                const char* name);

// 0x7100ac8600
template Unk_239a418_Ref<Unk_23c9278> Unk_790260_Owner::Unk_790140<Unk_23c9278>(Unk_Ref parent,
                                                                                Unk_23f4660* target,
                                                                                const char* name);

// 0x7100ac8c70
template Unk_239a418_Ref<Unk_23ccd60> Unk_790260_Owner::Unk_790140<Unk_23ccd60>(Unk_Ref parent,
                                                                                Unk_23f4660* target,
                                                                                const char* name);

// 0x7100ac90c0
template Unk_239a418_Ref<Unk_23c9988> Unk_790260_Owner::Unk_790140<Unk_23c9988>(Unk_Ref parent,
                                                                                Unk_23f4660* target,
                                                                                const char* name);

// 0x7100ac94e0
template Unk_239a418_Ref<Unk_23cbbc8> Unk_790260_Owner::Unk_790140<Unk_23cbbc8>(Unk_Ref parent,
                                                                                Unk_23f4660* target,
                                                                                const char* name);

// 0x7100ac9910
template Unk_239a418_Ref<Unk_23c9da0> Unk_790260_Owner::Unk_790140<Unk_23c9da0>(Unk_Ref parent,
                                                                                Unk_23f4660* target,
                                                                                const char* name);

// 0x7100ac9d30
template Unk_239a418_Ref<Unk_23cc5a0> Unk_790260_Owner::Unk_790140<Unk_23cc5a0>(Unk_Ref parent,
                                                                                Unk_23f4660* target,
                                                                                const char* name);

// 0x7100aca150
template Unk_239a418_Ref<Unk_23ca2e0> Unk_790260_Owner::Unk_790140<Unk_23ca2e0>(Unk_Ref parent,
                                                                                Unk_23f4660* target,
                                                                                const char* name);

// 0x7100aca580
template Unk_239a418_Ref<Unk_23c9ff0> Unk_790260_Owner::Unk_790140<Unk_23c9ff0>(Unk_Ref parent,
                                                                                Unk_23f4660* target,
                                                                                const char* name);

// 0x7100aca990
template Unk_239a418_Ref<Unk_23ca420> Unk_790260_Owner::Unk_790140<Unk_23ca420>(Unk_Ref parent,
                                                                                Unk_23f4660* target,
                                                                                const char* name);

// 0x7100acb060
template Unk_239a418_Ref<Unk_23ca1a8> Unk_790260_Owner::Unk_790140<Unk_23ca1a8>(Unk_Ref parent,
                                                                                Unk_23f4660* target,
                                                                                const char* name);

// 0x7100ba47c0
template Unk_239a418_Ref<Unk_23d3240> Unk_790260_Owner::Unk_790140<Unk_23d3240>(Unk_Ref parent,
                                                                                Unk_23f4660* target,
                                                                                const char* name);

// 0x7100ba4b50
template Unk_239a418_Ref<Unk_23d3368> Unk_790260_Owner::Unk_790140<Unk_23d3368>(Unk_Ref parent,
                                                                                Unk_23f4660* target,
                                                                                const char* name);

// 0x7100ba4f60
template Unk_239a418_Ref<Unk_23d3008> Unk_790260_Owner::Unk_790140<Unk_23d3008>(Unk_Ref parent,
                                                                                Unk_23f4660* target,
                                                                                const char* name);

// 0x7100c24ab0
template Unk_239a418_Ref<Unk_23da638> Unk_790260_Owner::Unk_790140<Unk_23da638>(Unk_Ref parent,
                                                                                Unk_23f4660* target,
                                                                                const char* name);

// 0x7100e612a0
template Unk_239a418_Ref<Unk_23f2b90> Unk_790260_Owner::Unk_790140<Unk_23f2b90>(Unk_Ref parent,
                                                                                Unk_23f4660* target,
                                                                                const char* name);

// 0x7100e616c0
template Unk_239a418_Ref<Unk_23f2cf0> Unk_790260_Owner::Unk_790140<Unk_23f2cf0>(Unk_Ref parent,
                                                                                Unk_23f4660* target,
                                                                                const char* name);

// 0x7100e67ad0
template Unk_239a418_Ref<Unk_23f2f10> Unk_790260_Owner::Unk_790140<Unk_23f2f10>(Unk_Ref parent,
                                                                                Unk_23f4660* target,
                                                                                const char* name);

// 0x7100e695c0
template Unk_239a418_Ref<Unk_23f3030> Unk_790260_Owner::Unk_790140<Unk_23f3030>(Unk_Ref parent,
                                                                                Unk_23f4660* target,
                                                                                const char* name);

// 0x7100e6d510
template Unk_239a418_Ref<Unk_23f6de0> Unk_790260_Owner::Unk_790140<Unk_23f6de0>(Unk_Ref parent,
                                                                                Unk_23f4660* target,
                                                                                const char* name);

// 0x7100e6db90
template Unk_239a418_Ref<Unk_23f3570> Unk_790260_Owner::Unk_790140<Unk_23f3570>(Unk_Ref parent,
                                                                                Unk_23f4660* target,
                                                                                const char* name);

// 0x7100e755a0
template Unk_239a418_Ref<Unk_23f3f48> Unk_790260_Owner::Unk_790140<Unk_23f3f48>(Unk_Ref parent,
                                                                                Unk_23f4660* target,
                                                                                const char* name);

// 0x7100eee4d0
template Unk_239a418_Ref<Unk_23f8b08> Unk_790260_Owner::Unk_790140<Unk_23f8b08>(Unk_Ref parent,
                                                                                Unk_23f4660* target,
                                                                                const char* name);

// 0x7100ef2d90
template Unk_239a418_Ref<Unk_23f9048> Unk_790260_Owner::Unk_790140<Unk_23f9048>(Unk_Ref parent,
                                                                                Unk_23f4660* target,
                                                                                const char* name);

// 0x7100f01b10
template Unk_239a418_Ref<Unk_23fac70> Unk_790260_Owner::Unk_790140<Unk_23fac70>(Unk_Ref parent,
                                                                                Unk_23f4660* target,
                                                                                const char* name);

// 0x7100f01e60
template Unk_239a418_Ref<Unk_23fafb8> Unk_790260_Owner::Unk_790140<Unk_23fafb8>(Unk_Ref parent,
                                                                                Unk_23f4660* target,
                                                                                const char* name);

// 0x7100f021d0
template Unk_239a418_Ref<Unk_23fb0b8> Unk_790260_Owner::Unk_790140<Unk_23fb0b8>(Unk_Ref parent,
                                                                                Unk_23f4660* target,
                                                                                const char* name);

// 0x7100f02520
template Unk_239a418_Ref<Unk_23fad70> Unk_790260_Owner::Unk_790140<Unk_23fad70>(Unk_Ref parent,
                                                                                Unk_23f4660* target,
                                                                                const char* name);

// 0x7100f02880
template Unk_239a418_Ref<Unk_23faea0> Unk_790260_Owner::Unk_790140<Unk_23faea0>(Unk_Ref parent,
                                                                                Unk_23f4660* target,
                                                                                const char* name);

// 0x7100f0e550
template Unk_239a418_Ref<Unk_23fb3d0> Unk_790260_Owner::Unk_790140<Unk_23fb3d0>(Unk_Ref parent,
                                                                                Unk_23f4660* target,
                                                                                const char* name);

// 0x7100f0e970
template Unk_239a418_Ref<Unk_23f67a0> Unk_790260_Owner::Unk_790140<Unk_23f67a0>(Unk_Ref parent,
                                                                                Unk_23f4660* target,
                                                                                const char* name);

// 0x7100f21dc0
template Unk_239a418_Ref<Unk_23fbe78> Unk_790260_Owner::Unk_790140<Unk_23fbe78>(Unk_Ref parent,
                                                                                Unk_23f4660* target,
                                                                                const char* name);

// 0x7100f22110
template Unk_239a418_Ref<Unk_23fc690> Unk_790260_Owner::Unk_790140<Unk_23fc690>(Unk_Ref parent,
                                                                                Unk_23f4660* target,
                                                                                const char* name);

// 0x7100f22590
template Unk_239a418_Ref<Unk_23fd038> Unk_790260_Owner::Unk_790140<Unk_23fd038>(Unk_Ref parent,
                                                                                Unk_23f4660* target,
                                                                                const char* name);

// 0x7100f22960
template Unk_239a418_Ref<Unk_23fd330> Unk_790260_Owner::Unk_790140<Unk_23fd330>(Unk_Ref parent,
                                                                                Unk_23f4660* target,
                                                                                const char* name);

// 0x7100f22d60
template Unk_239a418_Ref<Unk_23fbd40> Unk_790260_Owner::Unk_790140<Unk_23fbd40>(Unk_Ref parent,
                                                                                Unk_23f4660* target,
                                                                                const char* name);

// 0x7100f3f650
template Unk_239a418_Ref<Unk_23fd920> Unk_790260_Owner::Unk_790140<Unk_23fd920>(Unk_Ref parent,
                                                                                Unk_23f4660* target,
                                                                                const char* name);

// 0x7100f3f9b0
template Unk_239a418_Ref<Unk_23fdf10> Unk_790260_Owner::Unk_790140<Unk_23fdf10>(Unk_Ref parent,
                                                                                Unk_23f4660* target,
                                                                                const char* name);

// 0x7100f3fd00
template Unk_239a418_Ref<Unk_23fe058> Unk_790260_Owner::Unk_790140<Unk_23fe058>(Unk_Ref parent,
                                                                                Unk_23f4660* target,
                                                                                const char* name);

// 0x7100f40050
template Unk_239a418_Ref<Unk_23fe270> Unk_790260_Owner::Unk_790140<Unk_23fe270>(Unk_Ref parent,
                                                                                Unk_23f4660* target,
                                                                                const char* name);

// 0x7100f40520
template Unk_239a418_Ref<Unk_23fe610> Unk_790260_Owner::Unk_790140<Unk_23fe610>(Unk_Ref parent,
                                                                                Unk_23f4660* target,
                                                                                const char* name);

// 0x7100f40880
template Unk_239a418_Ref<Unk_23fde10> Unk_790260_Owner::Unk_790140<Unk_23fde10>(Unk_Ref parent,
                                                                                Unk_23f4660* target,
                                                                                const char* name);

// 0x7100f40bd0
template Unk_239a418_Ref<Unk_23fdce0> Unk_790260_Owner::Unk_790140<Unk_23fdce0>(Unk_Ref parent,
                                                                                Unk_23f4660* target,
                                                                                const char* name);

// 0x7100f60270
template Unk_239a418_Ref<Unk_23ff270> Unk_790260_Owner::Unk_790140<Unk_23ff270>(Unk_Ref parent,
                                                                                Unk_23f4660* target,
                                                                                const char* name);

// 0x7100f605d0
template Unk_239a418_Ref<Unk_2400bd8> Unk_790260_Owner::Unk_790140<Unk_2400bd8>(Unk_Ref parent,
                                                                                Unk_23f4660* target,
                                                                                const char* name);

// 0x7100f60940
template Unk_239a418_Ref<Unk_23ffb78> Unk_790260_Owner::Unk_790140<Unk_23ffb78>(Unk_Ref parent,
                                                                                Unk_23f4660* target,
                                                                                const char* name);

// 0x7100f60cd0
template Unk_239a418_Ref<Unk_23ff740> Unk_790260_Owner::Unk_790140<Unk_23ff740>(Unk_Ref parent,
                                                                                Unk_23f4660* target,
                                                                                const char* name);

// 0x7100f61080
template Unk_239a418_Ref<Unk_23ffe00> Unk_790260_Owner::Unk_790140<Unk_23ffe00>(Unk_Ref parent,
                                                                                Unk_23f4660* target,
                                                                                const char* name);

// 0x7100f61430
template Unk_239a418_Ref<Unk_2400560> Unk_790260_Owner::Unk_790140<Unk_2400560>(Unk_Ref parent,
                                                                                Unk_23f4660* target,
                                                                                const char* name);

// 0x7100f61790
template Unk_239a418_Ref<Unk_24013c0> Unk_790260_Owner::Unk_790140<Unk_24013c0>(Unk_Ref parent,
                                                                                Unk_23f4660* target,
                                                                                const char* name);

// 0x7100f61b20
template Unk_239a418_Ref<Unk_2400900> Unk_790260_Owner::Unk_790140<Unk_2400900>(Unk_Ref parent,
                                                                                Unk_23f4660* target,
                                                                                const char* name);

// 0x7100f61e80
template Unk_239a418_Ref<Unk_23ff3d0> Unk_790260_Owner::Unk_790140<Unk_23ff3d0>(Unk_Ref parent,
                                                                                Unk_23f4660* target,
                                                                                const char* name);

// 0x7100f621e0
template Unk_239a418_Ref<Unk_2400128> Unk_790260_Owner::Unk_790140<Unk_2400128>(Unk_Ref parent,
                                                                                Unk_23f4660* target,
                                                                                const char* name);

// 0x7100f62550
template Unk_239a418_Ref<Unk_23ff8e0> Unk_790260_Owner::Unk_790140<Unk_23ff8e0>(Unk_Ref parent,
                                                                                Unk_23f4660* target,
                                                                                const char* name);

// 0x7100fa1510
template Unk_239a418_Ref<Unk_2402ab0> Unk_790260_Owner::Unk_790140<Unk_2402ab0>(Unk_Ref parent,
                                                                                Unk_23f4660* target,
                                                                                const char* name);

// 0x7100fa4500
template Unk_239a418_Ref<Unk_2402c18> Unk_790260_Owner::Unk_790140<Unk_2402c18>(Unk_Ref parent,
                                                                                Unk_23f4660* target,
                                                                                const char* name);

// 0x7100fc7c50
template Unk_239a418_Ref<Unk_24033d0> Unk_790260_Owner::Unk_790140<Unk_24033d0>(Unk_Ref parent,
                                                                                Unk_23f4660* target,
                                                                                const char* name);

// 0x7100fc7fd0
template Unk_239a418_Ref<Unk_24039e0> Unk_790260_Owner::Unk_790140<Unk_24039e0>(Unk_Ref parent,
                                                                                Unk_23f4660* target,
                                                                                const char* name);

// 0x7100fc83a0
template Unk_239a418_Ref<Unk_2403638> Unk_790260_Owner::Unk_790140<Unk_2403638>(Unk_Ref parent,
                                                                                Unk_23f4660* target,
                                                                                const char* name);

// 0x7100fc87b0
template Unk_239a418_Ref<Unk_2403c30> Unk_790260_Owner::Unk_790140<Unk_2403c30>(Unk_Ref parent,
                                                                                Unk_23f4660* target,
                                                                                const char* name);

// 0x7100fc8b90
template Unk_239a418_Ref<Unk_2403e60> Unk_790260_Owner::Unk_790140<Unk_2403e60>(Unk_Ref parent,
                                                                                Unk_23f4660* target,
                                                                                const char* name);

// 0x7100fc9260
template Unk_239a418_Ref<Unk_2403b08> Unk_790260_Owner::Unk_790140<Unk_2403b08>(Unk_Ref parent,
                                                                                Unk_23f4660* target,
                                                                                const char* name);

// 0x7101247210
template Unk_239a418_Ref<Unk_2426be8> Unk_790260_Owner::Unk_790140<Unk_2426be8>(Unk_Ref parent,
                                                                                Unk_23f4660* target,
                                                                                const char* name);

// 0x7101247660
template Unk_239a418_Ref<Unk_24269d8> Unk_790260_Owner::Unk_790140<Unk_24269d8>(Unk_Ref parent,
                                                                                Unk_23f4660* target,
                                                                                const char* name);

// 0x7101255a90
template Unk_239a418_Ref<Unk_2427748> Unk_790260_Owner::Unk_790140<Unk_2427748>(Unk_Ref parent,
                                                                                Unk_23f4660* target,
                                                                                const char* name);

// 0x710125df30
template Unk_239a418_Ref<Unk_2428850> Unk_790260_Owner::Unk_790140<Unk_2428850>(Unk_Ref parent,
                                                                                Unk_23f4660* target,
                                                                                const char* name);

// 0x710125e290
template Unk_239a418_Ref<Unk_24293e8> Unk_790260_Owner::Unk_790140<Unk_24293e8>(Unk_Ref parent,
                                                                                Unk_23f4660* target,
                                                                                const char* name);

// 0x710125e5f0
template Unk_239a418_Ref<Unk_2428128> Unk_790260_Owner::Unk_790140<Unk_2428128>(Unk_Ref parent,
                                                                                Unk_23f4660* target,
                                                                                const char* name);

// 0x710125e940
template Unk_239a418_Ref<Unk_2428680> Unk_790260_Owner::Unk_790140<Unk_2428680>(Unk_Ref parent,
                                                                                Unk_23f4660* target,
                                                                                const char* name);

// 0x710125ecd0
template Unk_239a418_Ref<Unk_2429118> Unk_790260_Owner::Unk_790140<Unk_2429118>(Unk_Ref parent,
                                                                                Unk_23f4660* target,
                                                                                const char* name);

// 0x710125f030
template Unk_239a418_Ref<Unk_2429218> Unk_790260_Owner::Unk_790140<Unk_2429218>(Unk_Ref parent,
                                                                                Unk_23f4660* target,
                                                                                const char* name);

// 0x710125f390
template Unk_239a418_Ref<Unk_2427c48> Unk_790260_Owner::Unk_790140<Unk_2427c48>(Unk_Ref parent,
                                                                                Unk_23f4660* target,
                                                                                const char* name);

// 0x710125f910
template Unk_239a418_Ref<Unk_2427d58> Unk_790260_Owner::Unk_790140<Unk_2427d58>(Unk_Ref parent,
                                                                                Unk_23f4660* target,
                                                                                const char* name);

// 0x710125fd70
template Unk_239a418_Ref<Unk_2428b48> Unk_790260_Owner::Unk_790140<Unk_2428b48>(Unk_Ref parent,
                                                                                Unk_23f4660* target,
                                                                                const char* name);

// 0x71012604a0
template Unk_239a418_Ref<Unk_2427e68> Unk_790260_Owner::Unk_790140<Unk_2427e68>(Unk_Ref parent,
                                                                                Unk_23f4660* target,
                                                                                const char* name);

// 0x71012a1040
template Unk_239a418_Ref<Unk_242bf88> Unk_790260_Owner::Unk_790140<Unk_242bf88>(Unk_Ref parent,
                                                                                Unk_23f4660* target,
                                                                                const char* name);

// 0x71012a13b0
template Unk_239a418_Ref<Unk_242c3e8> Unk_790260_Owner::Unk_790140<Unk_242c3e8>(Unk_Ref parent,
                                                                                Unk_23f4660* target,
                                                                                const char* name);

// 0x71012a1720
template Unk_239a418_Ref<Unk_242c500> Unk_790260_Owner::Unk_790140<Unk_242c500>(Unk_Ref parent,
                                                                                Unk_23f4660* target,
                                                                                const char* name);

// 0x71012a1b30
template Unk_239a418_Ref<Unk_242c1b8> Unk_790260_Owner::Unk_790140<Unk_242c1b8>(Unk_Ref parent,
                                                                                Unk_23f4660* target,
                                                                                const char* name);

// 0x71012a1ec0
template Unk_239a418_Ref<Unk_242c0a0> Unk_790260_Owner::Unk_790140<Unk_242c0a0>(Unk_Ref parent,
                                                                                Unk_23f4660* target,
                                                                                const char* name);

// 0x71012a2240
template Unk_239a418_Ref<Unk_242c2d0> Unk_790260_Owner::Unk_790140<Unk_242c2d0>(Unk_Ref parent,
                                                                                Unk_23f4660* target,
                                                                                const char* name);

// 0x71012baa80
template Unk_239a418_Ref<Unk_242c858> Unk_790260_Owner::Unk_790140<Unk_242c858>(Unk_Ref parent,
                                                                                Unk_23f4660* target,
                                                                                const char* name);

// 0x71012bae30
template Unk_239a418_Ref<Unk_242cae8> Unk_790260_Owner::Unk_790140<Unk_242cae8>(Unk_Ref parent,
                                                                                Unk_23f4660* target,
                                                                                const char* name);

// 0x71012ce120
template Unk_239a418_Ref<Unk_242d2f8> Unk_790260_Owner::Unk_790140<Unk_242d2f8>(Unk_Ref parent,
                                                                                Unk_23f4660* target,
                                                                                const char* name);

// 0x71012ce4b0
template Unk_239a418_Ref<Unk_242e928> Unk_790260_Owner::Unk_790140<Unk_242e928>(Unk_Ref parent,
                                                                                Unk_23f4660* target,
                                                                                const char* name);

// 0x71012ce820
template Unk_239a418_Ref<Unk_242d838> Unk_790260_Owner::Unk_790140<Unk_242d838>(Unk_Ref parent,
                                                                                Unk_23f4660* target,
                                                                                const char* name);

// 0x71012ceb90
template Unk_239a418_Ref<Unk_242d4f8> Unk_790260_Owner::Unk_790140<Unk_242d4f8>(Unk_Ref parent,
                                                                                Unk_23f4660* target,
                                                                                const char* name);

// 0x71012cef20
template Unk_239a418_Ref<Unk_242e438> Unk_790260_Owner::Unk_790140<Unk_242e438>(Unk_Ref parent,
                                                                                Unk_23f4660* target,
                                                                                const char* name);

// 0x71012cf800
template Unk_239a418_Ref<Unk_242d978> Unk_790260_Owner::Unk_790140<Unk_242d978>(Unk_Ref parent,
                                                                                Unk_23f4660* target,
                                                                                const char* name);

// 0x71013042f0
template Unk_239a418_Ref<Unk_242f2e0> Unk_790260_Owner::Unk_790140<Unk_242f2e0>(Unk_Ref parent,
                                                                                Unk_23f4660* target,
                                                                                const char* name);

// 0x7101304640
template Unk_239a418_Ref<Unk_242f1e0> Unk_790260_Owner::Unk_790140<Unk_242f1e0>(Unk_Ref parent,
                                                                                Unk_23f4660* target,
                                                                                const char* name);

// 0x710131c000
template Unk_239a418_Ref<Unk_242fed0> Unk_790260_Owner::Unk_790140<Unk_242fed0>(Unk_Ref parent,
                                                                                Unk_23f4660* target,
                                                                                const char* name);

// 0x7101327d30
template Unk_239a418_Ref<Unk_24306f8> Unk_790260_Owner::Unk_790140<Unk_24306f8>(Unk_Ref parent,
                                                                                Unk_23f4660* target,
                                                                                const char* name);

// 0x7101328260
template Unk_239a418_Ref<Unk_2430ee0> Unk_790260_Owner::Unk_790140<Unk_2430ee0>(Unk_Ref parent,
                                                                                Unk_23f4660* target,
                                                                                const char* name);

// 0x710133ede0
template Unk_239a418_Ref<Unk_2431618> Unk_790260_Owner::Unk_790140<Unk_2431618>(Unk_Ref parent,
                                                                                Unk_23f4660* target,
                                                                                const char* name);

// 0x7101419be0
template Unk_239a418_Ref<Unk_2439200> Unk_790260_Owner::Unk_790140<Unk_2439200>(Unk_Ref parent,
                                                                                Unk_23f4660* target,
                                                                                const char* name);

// 0x7101419f70
template Unk_239a418_Ref<Unk_24390d0> Unk_790260_Owner::Unk_790140<Unk_24390d0>(Unk_Ref parent,
                                                                                Unk_23f4660* target,
                                                                                const char* name);

// 0x7101425b80
template Unk_239a418_Ref<Unk_2439b60> Unk_790260_Owner::Unk_790140<Unk_2439b60>(Unk_Ref parent,
                                                                                Unk_23f4660* target,
                                                                                const char* name);

// 0x7101425ed0
template Unk_239a418_Ref<Unk_2439d60> Unk_790260_Owner::Unk_790140<Unk_2439d60>(Unk_Ref parent,
                                                                                Unk_23f4660* target,
                                                                                const char* name);

// 0x7101426230
template Unk_239a418_Ref<Unk_2439c60> Unk_790260_Owner::Unk_790140<Unk_2439c60>(Unk_Ref parent,
                                                                                Unk_23f4660* target,
                                                                                const char* name);

// 0x71014303f0
template Unk_239a418_Ref<Unk_243a9d0> Unk_790260_Owner::Unk_790140<Unk_243a9d0>(Unk_Ref parent,
                                                                                Unk_23f4660* target,
                                                                                const char* name);

// 0x71014409c0
template Unk_239a418_Ref<Unk_243bf78> Unk_790260_Owner::Unk_790140<Unk_243bf78>(Unk_Ref parent,
                                                                                Unk_23f4660* target,
                                                                                const char* name);

// 0x7101440d10
template Unk_239a418_Ref<Unk_23f6a68> Unk_790260_Owner::Unk_790140<Unk_23f6a68>(Unk_Ref parent,
                                                                                Unk_23f4660* target,
                                                                                const char* name);

// 0x7101456d00
template Unk_239a418_Ref<Unk_243d1c8> Unk_790260_Owner::Unk_790140<Unk_243d1c8>(Unk_Ref parent,
                                                                                Unk_23f4660* target,
                                                                                const char* name);

// 0x7101457050
template Unk_239a418_Ref<Unk_243cff8> Unk_790260_Owner::Unk_790140<Unk_243cff8>(Unk_Ref parent,
                                                                                Unk_23f4660* target,
                                                                                const char* name);

// 0x71014573a0
template Unk_239a418_Ref<Unk_243cee0> Unk_790260_Owner::Unk_790140<Unk_243cee0>(Unk_Ref parent,
                                                                                Unk_23f4660* target,
                                                                                const char* name);

// 0x71014671b0
template Unk_239a418_Ref<Unk_243d958> Unk_790260_Owner::Unk_790140<Unk_243d958>(Unk_Ref parent,
                                                                                Unk_23f4660* target,
                                                                                const char* name);

// 0x7101467500
template Unk_239a418_Ref<Unk_243dc10> Unk_790260_Owner::Unk_790140<Unk_243dc10>(Unk_Ref parent,
                                                                                Unk_23f4660* target,
                                                                                const char* name);

// 0x7101467850
template Unk_239a418_Ref<Unk_243e198> Unk_790260_Owner::Unk_790140<Unk_243e198>(Unk_Ref parent,
                                                                                Unk_23f4660* target,
                                                                                const char* name);

// 0x7101467c00
template Unk_239a418_Ref<Unk_243dd28> Unk_790260_Owner::Unk_790140<Unk_243dd28>(Unk_Ref parent,
                                                                                Unk_23f4660* target,
                                                                                const char* name);

// 0x7101467f70
template Unk_239a418_Ref<Unk_243e520> Unk_790260_Owner::Unk_790140<Unk_243e520>(Unk_Ref parent,
                                                                                Unk_23f4660* target,
                                                                                const char* name);

// 0x71014682d0
template Unk_239a418_Ref<Unk_243d7a0> Unk_790260_Owner::Unk_790140<Unk_243d7a0>(Unk_Ref parent,
                                                                                Unk_23f4660* target,
                                                                                const char* name);

// 0x7101489780
template Unk_239a418_Ref<Unk_24415a8> Unk_790260_Owner::Unk_790140<Unk_24415a8>(Unk_Ref parent,
                                                                                Unk_23f4660* target,
                                                                                const char* name);

// 0x7101489ae0
template Unk_239a418_Ref<Unk_2441c98> Unk_790260_Owner::Unk_790140<Unk_2441c98>(Unk_Ref parent,
                                                                                Unk_23f4660* target,
                                                                                const char* name);

// 0x7101489e30
template Unk_239a418_Ref<Unk_24417c0> Unk_790260_Owner::Unk_790140<Unk_24417c0>(Unk_Ref parent,
                                                                                Unk_23f4660* target,
                                                                                const char* name);

// 0x710148a270
template Unk_239a418_Ref<Unk_2441b28> Unk_790260_Owner::Unk_790140<Unk_2441b28>(Unk_Ref parent,
                                                                                Unk_23f4660* target,
                                                                                const char* name);

// 0x710148a6c0
template Unk_239a418_Ref<Unk_2441a00> Unk_790260_Owner::Unk_790140<Unk_2441a00>(Unk_Ref parent,
                                                                                Unk_23f4660* target,
                                                                                const char* name);

// 0x710148aac0
template Unk_239a418_Ref<Unk_2441dc0> Unk_790260_Owner::Unk_790140<Unk_2441dc0>(Unk_Ref parent,
                                                                                Unk_23f4660* target,
                                                                                const char* name);

// 0x710148ae30
template Unk_239a418_Ref<Unk_24418e0> Unk_790260_Owner::Unk_790140<Unk_24418e0>(Unk_Ref parent,
                                                                                Unk_23f4660* target,
                                                                                const char* name);

// 0x710148b180
template Unk_239a418_Ref<Unk_24416b0> Unk_790260_Owner::Unk_790140<Unk_24416b0>(Unk_Ref parent,
                                                                                Unk_23f4660* target,
                                                                                const char* name);

// 0x71014c3540
template Unk_239a418_Ref<Unk_2443818> Unk_790260_Owner::Unk_790140<Unk_2443818>(Unk_Ref parent,
                                                                                Unk_23f4660* target,
                                                                                const char* name);

// 0x71014c3660
template Unk_239a418_Ref<Unk_2443918> Unk_790260_Owner::Unk_790140<Unk_2443918>(Unk_Ref parent,
                                                                                Unk_23f4660* target,
                                                                                const char* name);

// 0x7101508630
template Unk_239a418_Ref<Unk_2446d08> Unk_790260_Owner::Unk_790140<Unk_2446d08>(Unk_Ref parent,
                                                                                Unk_23f4660* target,
                                                                                const char* name);

// 0x7101508980
template Unk_239a418_Ref<Unk_2446c08> Unk_790260_Owner::Unk_790140<Unk_2446c08>(Unk_Ref parent,
                                                                                Unk_23f4660* target,
                                                                                const char* name);

// 0x7101513780
template Unk_239a418_Ref<Unk_2447498> Unk_790260_Owner::Unk_790140<Unk_2447498>(Unk_Ref parent,
                                                                                Unk_23f4660* target,
                                                                                const char* name);

// 0x7101520d10
template Unk_239a418_Ref<Unk_2448020> Unk_790260_Owner::Unk_790140<Unk_2448020>(Unk_Ref parent,
                                                                                Unk_23f4660* target,
                                                                                const char* name);

// 0x7101521060
template Unk_239a418_Ref<Unk_2447e50> Unk_790260_Owner::Unk_790140<Unk_2447e50>(Unk_Ref parent,
                                                                                Unk_23f4660* target,
                                                                                const char* name);

// 0x71015213c0
template Unk_239a418_Ref<Unk_24482c0> Unk_790260_Owner::Unk_790140<Unk_24482c0>(Unk_Ref parent,
                                                                                Unk_23f4660* target,
                                                                                const char* name);

// 0x7101521730
template Unk_239a418_Ref<Unk_2447cf0> Unk_790260_Owner::Unk_790140<Unk_2447cf0>(Unk_Ref parent,
                                                                                Unk_23f4660* target,
                                                                                const char* name);

// 0x7101521ac0
template Unk_239a418_Ref<Unk_2448660> Unk_790260_Owner::Unk_790140<Unk_2448660>(Unk_Ref parent,
                                                                                Unk_23f4660* target,
                                                                                const char* name);

// 0x710153e920
template Unk_239a418_Ref<Unk_2449870> Unk_790260_Owner::Unk_790140<Unk_2449870>(Unk_Ref parent,
                                                                                Unk_23f4660* target,
                                                                                const char* name);

// 0x710153ec70
template Unk_239a418_Ref<Unk_2449970> Unk_790260_Owner::Unk_790140<Unk_2449970>(Unk_Ref parent,
                                                                                Unk_23f4660* target,
                                                                                const char* name);

// 0x710153efc0
template Unk_239a418_Ref<Unk_2449670> Unk_790260_Owner::Unk_790140<Unk_2449670>(Unk_Ref parent,
                                                                                Unk_23f4660* target,
                                                                                const char* name);
