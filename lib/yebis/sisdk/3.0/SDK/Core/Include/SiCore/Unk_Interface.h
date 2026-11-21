// SiSDK3::ISiInterface and SiSDK3::ISiNamedObject (RTTI: the bases of the
// SiSDK3 classes' interfaces). The header's name isn't in the executable, and
// the slots' names are placeholders: an interface's reference count (vf2, vf3:
// Unk_RefCount.h), and a named object's three functions under the names the
// last slots of SiStringTable's vtable have (it overrides them).
#pragma once

#include "SiCore_String.h"

namespace SiSDK3 {

class ISiInterface {
public:
    virtual ~ISiInterface() {}
    virtual u32 vf2() = 0;  // one reference more
    virtual u32 vf3() = 0;  // one less
    virtual u32 vf4() = 0;  // how many there are
};

class ISiNamedObject {
public:
    virtual ~ISiNamedObject() {}
    virtual bool vf18(const char* name) = 0;
    virtual const SiString<char>* vf19() = 0;  // the name
    virtual u32 vf20() = 0;                    // its hash
};

}  // namespace SiSDK3
