// Scope: common
// Type getters of classes on gflib3's object (tools/typegen.py, generated: rewrite,
// don't edit). Placeholder classes, named after their vtables, and types, named
// after their type objects where no class is known: rename them once they are.
#include <types.h>

#include "gflib3/Unk_239a418.h"

// vtable 0x710240d3d8: vf_type, its key function, so its vtable is emitted
// here, with the D0 and the destructor thunks below: its destructor is implicit,
// and they are copies of the object's D2. vf_type's thunks come out as calls:
// the original's vf_type is inline (emitted with the vtable where the class is
// constructed), and they tail-call it with the adjustment.
// 0x7101084aa0
// 0x7101084be0
// 0x7101084c30
// 0x7101084ca0
// 0x7101084cf0
class Unk_240d3c8 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_239a418_GetType());
        return &type;
    }

    const Unk_239a418_Type* vf_type() override;
};

// vtable 0x710240d850: vf_type, its key function, so its vtable is emitted
// here, with the D0 and the destructor thunks below: its destructor is implicit,
// and they are copies of the object's D2. vf_type's thunks come out as calls:
// the original's vf_type is inline (emitted with the vtable where the class is
// constructed), and they tail-call it with the adjustment.
// 0x7101087340
// 0x7101087480
// 0x71010874d0
// 0x7101087540
// 0x7101087590
class Unk_240d840 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_239a418_GetType());
        return &type;
    }

    const Unk_239a418_Type* vf_type() override;
};

// vtable 0x710240df28: vf_type (its thunks 0x710108b4a0 (+0x48), 0x710108b4b0 (+0x50) aren't
// written: they call it, and the original's is inline, emitted with the class's vtable). Declared
// without its bases or its vtable: vf_type doesn't use them.
struct Unk_240df18 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_239a418_GetType());
        return &type;
    }

    const Unk_239a418_Type* vf_type();
};

// vtable 0x710240e2b0: vf_type (its thunks 0x710108daf0 (+0x48), 0x710108db00 (+0x50) aren't
// written: they call it, and the original's is inline, emitted with the class's vtable). Declared
// without its bases or its vtable: vf_type doesn't use them.
struct Unk_240e2a0 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_239a418_GetType());
        return &type;
    }

    const Unk_239a418_Type* vf_type();
};

// vtable 0x710240e538: vf_type (its thunks 0x710108f3e0 (+0x48), 0x710108f3f0 (+0x50) aren't
// written: they call it, and the original's is inline, emitted with the class's vtable). Declared
// without its bases or its vtable: vf_type doesn't use them.
struct Unk_240e528 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_239a418_GetType());
        return &type;
    }

    const Unk_239a418_Type* vf_type();
};

// vtable 0x710240ea38: vf_type (its thunks 0x7101092310 (+0x48), 0x7101092320 (+0x50) aren't
// written: they call it, and the original's is inline, emitted with the class's vtable). Declared
// without its bases or its vtable: vf_type doesn't use them.
struct Unk_240ea28 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_239a418_GetType());
        return &type;
    }

    const Unk_239a418_Type* vf_type();
};

// vtable 0x710240f110: vf_type (its thunks 0x7101096760 (+0x48), 0x7101096770 (+0x50) aren't
// written: they call it, and the original's is inline, emitted with the class's vtable). Declared
// without its bases or its vtable: vf_type doesn't use them.
struct Unk_240f100 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_239a418_GetType());
        return &type;
    }

    const Unk_239a418_Type* vf_type();
};

// vtable 0x710240f2e8: vf_type, its key function, so its vtable is emitted
// here, with the D0 and the destructor thunks below: its destructor is implicit,
// and they are copies of the object's D2. vf_type's thunks come out as calls:
// the original's vf_type is inline (emitted with the vtable where the class is
// constructed), and they tail-call it with the adjustment.
// 0x71010979a0
// 0x7101097ae0
// 0x7101097b30
// 0x7101097ba0
// 0x7101097bf0
class Unk_240f2d8 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_239a418_GetType());
        return &type;
    }

    const Unk_239a418_Type* vf_type() override;
};

// vtable 0x710240f6d8: vf_type, its key function, so its vtable is emitted
// here, with the D0 and the destructor thunks below: its destructor is implicit,
// and they are copies of the object's D2. vf_type's thunks come out as calls:
// the original's vf_type is inline (emitted with the vtable where the class is
// constructed), and they tail-call it with the adjustment.
// 0x7101099ed0
// 0x710109a010
// 0x710109a060
// 0x710109a0d0
// 0x710109a120
class Unk_240f6c8 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_239a418_GetType());
        return &type;
    }

    const Unk_239a418_Type* vf_type() override;
};

// vtable 0x710240fb28: vf_type, its key function, so its vtable is emitted
// here, with the D0 and the destructor thunks below: its destructor is implicit,
// and they are copies of the object's D2. vf_type's thunks come out as calls:
// the original's vf_type is inline (emitted with the vtable where the class is
// constructed), and they tail-call it with the adjustment.
// 0x710109c790
// 0x710109c8d0
// 0x710109c920
// 0x710109c990
// 0x710109c9e0
class Unk_240fb18 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_239a418_GetType());
        return &type;
    }

    const Unk_239a418_Type* vf_type() override;
};

// 0x7101084af0
// 0x7101084c80
// 0x7101084c90
const Unk_239a418_Type* Unk_240d3c8::vf_type() {
    return Unk_GetType();
}

// 0x7101087390
// 0x7101087520
// 0x7101087530
const Unk_239a418_Type* Unk_240d840::vf_type() {
    return Unk_GetType();
}

// 0x710108b270
const Unk_239a418_Type* Unk_240df18::vf_type() {
    return Unk_GetType();
}

// 0x710108d880
const Unk_239a418_Type* Unk_240e2a0::vf_type() {
    return Unk_GetType();
}

// 0x710108f1b0
const Unk_239a418_Type* Unk_240e528::vf_type() {
    return Unk_GetType();
}

// 0x7101092120
const Unk_239a418_Type* Unk_240ea28::vf_type() {
    return Unk_GetType();
}

// 0x7101096470
const Unk_239a418_Type* Unk_240f100::vf_type() {
    return Unk_GetType();
}

// 0x71010979f0
// 0x7101097b80
// 0x7101097b90
const Unk_239a418_Type* Unk_240f2d8::vf_type() {
    return Unk_GetType();
}

// 0x7101099f20
// 0x710109a0b0
// 0x710109a0c0
const Unk_239a418_Type* Unk_240f6c8::vf_type() {
    return Unk_GetType();
}

// 0x710109c7e0
// 0x710109c970
// 0x710109c980
const Unk_239a418_Type* Unk_240fb18::vf_type() {
    return Unk_GetType();
}
