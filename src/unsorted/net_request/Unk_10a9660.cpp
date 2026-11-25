// Scope: common
// A request step base and its derived step's destructors, the base's vf4
// and vf11, and the factory of the object the step makes
// (src/unsorted/net_request/Unk_10a9050.h). Placeholder names: rename once
// the classes are known.
#include "gflib3/Unk_New.h"
#include "unsorted/net_request/Unk_10a9050.h"

// 0x71010a96b0 (D2), 0x71010a9720 (D0)
Unk_2411420::~Unk_2411420() = default;

// 0x71010a9790
void Unk_2411490::vf4() {
    if (field_18.m_ptr != nullptr) {
        static_cast<Unk_239a458*>(field_18.m_ptr)->vf5();
        field_18.m_ptr = nullptr;
    }
    field_18.m_ptr = nullptr;
    field_20 = nullptr;
}

// 0x71010a9810 (D2), 0x71010a9860 (D0, a trap: the class is abstract)
Unk_2411490::~Unk_2411490() = default;

// 0x71010a98a0
template Unk_2411318* Unk_New::Create<Unk_2411318>(Unk_239a418_Allocator*);
