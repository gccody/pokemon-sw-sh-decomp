// Scope: common
//
// Unk_23bde48's constructor and destructor, and Unk_23bdd98's destructor
// (src/unsorted/battle_app/Unk_90e980.h): the destructors are the key
// functions, so the vtables, D0s and thunks come out here, with the vtables
// and D0s of the small objects Unk_23bde48 constructs.
#include "unsorted/battle_app/Unk_90e980.h"

// 0x710090e980
Unk_23bde48::Unk_23bde48()
    : field_318(0),
      field_320(0),
      field_328(0),
      field_330(0),
      field_338(0),
      field_340(0),
      field_408(0),
      field_410(),
      field_420(0),
      field_428(0),
      field_42a(1) {}

// 0x710090ed90, 0x710090f010 (D0), thunks 0x710090f030/0x710090f040 (+0x48)
// and 0x710090f070/0x710090f080 (+0x50)
Unk_23bdd98::~Unk_23bdd98() {}

// 0x710090f180, 0x710090f1e0 (D0)
Unk_23bde48::~Unk_23bde48() {}
