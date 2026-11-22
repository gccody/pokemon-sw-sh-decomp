// SiSDK3::ISiNamedObject (RTTI: the second base, at offset 8, of the SiGfx
// resources' interfaces) for a class whose vtable has the three functions at
// other slots than SiStringTable's (Unk_Interface.h's ISiNamedObject has
// those): the class overrides them, so they're slots of its own vtable, named
// vf<slot> there, and the second vtable has `_ZThn8_` thunks of them.
// Placeholder header and names: UNK_NAMED_OBJECT(Name, a, b, c) declares the
// interface as Name with the three functions under the class's slot names
// (the base's name isn't part of any symbol).
#pragma once

#include "SiCore_String.h"

#define UNK_NAMED_OBJECT(Name, vfSetName, vfName, vfHash)               \
    class Name {                                                        \
    public:                                                             \
        virtual ~Name() {}                                              \
        virtual bool vfSetName(const char* name) = 0;                   \
        virtual const ::SiSDK3::SiString<char>* vfName() = 0;           \
        virtual u32 vfHash() = 0; /* the name's hash */                 \
    }
