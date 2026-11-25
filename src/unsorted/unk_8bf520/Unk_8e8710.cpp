// Scope: common
// A Battle Tower state on Unk_23bcdf0 (src/unsorted/unk_8bf520/Unk_8e9610.h):
// its vf8. Its vf7 (0x71008e8660) is its vtable's key function: the vtable's
// D0 (0x71008e8740) and thunks for +0x48 (0x71008e87f0 D1, 0x71008e8890 D0)
// and +0x50 (0x71008e8950 D1, 0x71008e89f0 D0) are emitted with it, in that
// function's TU. Its vf9 is in src/unsorted/virtual/Unk_8e4150.cpp.
// Placeholder names: rename once the class is known.
#include "unsorted/unk_8bf520/Unk_8e9610.h"

// tools/leafgen.py's placeholder.
bool Unk_eb6530(void* view);

// The state (vtable 0x71023bcd30).
class Unk_23bcd20 : public Unk_23bcdf0 {
public:
    void vf7() override;
    u32 vf8() override;
    void vf9() override;
};

// 0x71008e8710
u32 Unk_23bcd20::vf8() {
    return !Unk_eb6530(field_78.m_ptr);
}
