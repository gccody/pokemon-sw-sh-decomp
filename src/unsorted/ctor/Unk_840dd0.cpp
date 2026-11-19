// Scope: common
// Constructors that call their base's and set the vptr: `Unk_D::Unk_D() {}`.
// Placeholder classes, named after their vtables: only what the constructors
// need (a base constructor to call, and a key function elsewhere, so that the
// vtable is another TU's).
// A class with nothing but its destructors has no key function: its destructor
// is implicit, and its vtable and D0 are emitted here, with its constructor.
#include "unsorted/ctor/Unk_23acc98.h"

// 0x7100840dd0
Unk_23adb18::Unk_23adb18(const Unk_23acc98_Arg& arg) : Unk_23acc98(arg) {}
