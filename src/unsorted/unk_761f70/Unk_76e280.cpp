// Scope: common
//
// Four classes with nothing in their vtables but their destructors
// (0x71023a7a08, 0x71023a7a48, 0x71023a7a68, 0x71023a7a88), each owning an
// array of polymorphic elements, freed through an allocator. Their
// destructors are their key functions: their vtables are emitted here.
// Placeholder names: rename once the classes are known.
#include <memory>

#include "unsorted/Unk_23c9470.h"

// The elements: destroyed through their vtables.
class Unk_23a7a08_Element {
public:
    virtual ~Unk_23a7a08_Element();

    u8 _8[0x198];
};
static_assert(sizeof(Unk_23a7a08_Element) == 0x1a0, "Unk_23a7a08_Element");

class Unk_23a7a08 {
public:
    virtual ~Unk_23a7a08();

    std::unique_ptr<Unk_23a7a08_Element[], Unk_23c9470_ArrayDeleter> field_8;
};
static_assert(sizeof(Unk_23a7a08) == 0x28, "Unk_23a7a08");

// 0x710076e280, its D0
Unk_23a7a08::~Unk_23a7a08() {}

// The elements: destroyed through their vtables.
class Unk_23a7a48_Element {
public:
    virtual ~Unk_23a7a48_Element();

    u8 _8[0xb0];
};
static_assert(sizeof(Unk_23a7a48_Element) == 0xb8, "Unk_23a7a48_Element");

class Unk_23a7a48 {
public:
    virtual ~Unk_23a7a48();

    std::unique_ptr<Unk_23a7a48_Element[], Unk_23c9470_ArrayDeleter> field_8;
};
static_assert(sizeof(Unk_23a7a48) == 0x28, "Unk_23a7a48");

// 0x710076e9d0, its D0
Unk_23a7a48::~Unk_23a7a48() {}

// The elements: destroyed through their vtables.
class Unk_23a7a68_Element {
public:
    virtual ~Unk_23a7a68_Element();

    u8 _8[0x110];
};
static_assert(sizeof(Unk_23a7a68_Element) == 0x118, "Unk_23a7a68_Element");

class Unk_23a7a68 {
public:
    virtual ~Unk_23a7a68();

    std::unique_ptr<Unk_23a7a68_Element[], Unk_23c9470_ArrayDeleter> field_8;
};
static_assert(sizeof(Unk_23a7a68) == 0x28, "Unk_23a7a68");

// 0x710076ecd0, its D0
Unk_23a7a68::~Unk_23a7a68() {}

// The elements: destroyed through their vtables.
class Unk_23a7a88_Element {
public:
    virtual ~Unk_23a7a88_Element();

    u8 _8[0x28];
};
static_assert(sizeof(Unk_23a7a88_Element) == 0x30, "Unk_23a7a88_Element");

class Unk_23a7a88 {
public:
    virtual ~Unk_23a7a88();

    std::unique_ptr<Unk_23a7a88_Element[], Unk_23c9470_ArrayDeleter> field_8;
};
static_assert(sizeof(Unk_23a7a88) == 0x28, "Unk_23a7a88");

// 0x710076f140, its D0
Unk_23a7a88::~Unk_23a7a88() {}
