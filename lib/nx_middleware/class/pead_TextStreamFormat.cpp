// Scope: common
// Small virtual functions of a library class (tools/leafgen.py members): placeholder
// member names vf<slot>, placeholder structs. The class's name is its RTTI's.
// RTTI: N4pead16TextStreamFormatE
#include <types.h>

struct Unk_1720920_arg1 {
    virtual void vf0();
    virtual void vf1(void*, u32);
};

struct Unk_17209b0_arg1 {
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
};

namespace pead {
class TextStreamFormat {
public:
    void vf25(Unk_1720920_arg1* value);
    void vf27();
    void vf28(Unk_17209b0_arg1* value);
};
}  // namespace pead

// 0x7101720920
void pead::TextStreamFormat::vf25(Unk_1720920_arg1* value) {
    u8 l4;
    l4 = 0;
    value->vf1(&l4, 1);
}

// 0x71017209b0
void pead::TextStreamFormat::vf28(Unk_17209b0_arg1* value) {
    value->vf3();
}

// 0x71017209c0
void pead::TextStreamFormat::vf27() {
}
