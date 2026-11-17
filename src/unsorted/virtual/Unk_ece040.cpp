// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

class Unk_23f7190 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual const char* vf3();
};

// 0x7100ece040
const char* Unk_23f7190::vf3() {
    return "rank";
}

class Unk_23f71c0 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual const char* vf3();
};

// 0x7100ece080
const char* Unk_23f71c0::vf3() {
    return "rank";
}

class Unk_23f7268 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void* vf3();
};

// 0x7100ecf360
void* Unk_23f7268::vf3() {
    return nullptr;
}

class Unk_23f7298 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual const char* vf3();
};

// 0x7100ecf3a0
const char* Unk_23f7298::vf3() {
    return "my_name";
}

class Unk_23f7328 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual const char* vf3();
};

// 0x7100ecfdd0
const char* Unk_23f7328::vf3() {
    return "owner_name";
}

class Unk_23f7358 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual const char* vf3();
};

// 0x7100ecfe10
const char* Unk_23f7358::vf3() {
    return "place";
}

class Unk_23f7388 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void* vf3();
};

// 0x7100ecfe50
void* Unk_23f7388::vf3() {
    return nullptr;
}

class Unk_23f73b8 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void* vf3();
};

// 0x7100ecfe90
void* Unk_23f73b8::vf3() {
    return nullptr;
}

class Unk_23f73e8 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual const char* vf3();
};

// 0x7100ecfec0
const char* Unk_23f73e8::vf3() {
    return "rank";
}

class Unk_23f7418 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual const char* vf3();
};

// 0x7100ecfef0
const char* Unk_23f7418::vf3() {
    return "rank";
}

class Unk_23f7448 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual const char* vf3();
};

// 0x7100ecff30
const char* Unk_23f7448::vf3() {
    return "place";
}

class Unk_23f7478 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual const char* vf3();
};

// 0x7100ecff70
const char* Unk_23f7478::vf3() {
    return "place";
}

class Unk_23f74a8 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual const char* vf3();
};

// 0x7100ecffb0
const char* Unk_23f74a8::vf3() {
    return "place";
}
