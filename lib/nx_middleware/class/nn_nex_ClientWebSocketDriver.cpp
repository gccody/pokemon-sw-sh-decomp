// Scope: common
// Small virtual functions of a library class (tools/leafgen.py members): placeholder
// member names vf<slot>, placeholder structs. The class's name is its RTTI's.
// RTTI: N2nn3nex21ClientWebSocketDriverE
#include <types.h>

struct Unk_1617ed0_arg1 {
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
    virtual void vf14();
    virtual void vf15();
    virtual void vf16();
    virtual void vf17();
    virtual void vf18();
    virtual void vf19();
    virtual void vf20();
    virtual void vf21();
    virtual void vf22(void*);
};

struct Unk_1622040 {
    u8 _0[0x8];
    bool field_8;
};
PKMN_OFFSET_ASSERT(Unk_1622040, field_8, 0x8);

struct Unk_1622050 {
    u8 _0[0x8];
    u8 field_8;
};
PKMN_OFFSET_ASSERT(Unk_1622050, field_8, 0x8);

namespace nn {
namespace nex {
class ClientWebSocketDriver {
public:
    void vf3(Unk_1617ed0_arg1* value);
    void vf7(bool value);
    u8 vf8();
    void vf11();
    void vf12();
    void vf13();
    void vf14();
    void vf15();
    u32 vf16();
};
}  // namespace nex
}  // namespace nn

// 0x7101617ed0
void nn::nex::ClientWebSocketDriver::vf3(Unk_1617ed0_arg1* value) {
    if (value != nullptr) {
        value->vf22(value);
    }
}

// 0x7101622040
void nn::nex::ClientWebSocketDriver::vf7(bool value) {
    Unk_1622040* self = reinterpret_cast<Unk_1622040*>(this);
    self->field_8 = value;
}

// 0x7101622050
u8 nn::nex::ClientWebSocketDriver::vf8() {
    const Unk_1622050* self = reinterpret_cast<const Unk_1622050*>(this);
    return self->field_8;
}

// 0x71016220a0
void nn::nex::ClientWebSocketDriver::vf11() {
}

// 0x71016220b0
void nn::nex::ClientWebSocketDriver::vf12() {
}

// 0x71016220c0
void nn::nex::ClientWebSocketDriver::vf13() {
}

// 0x71016220d0
void nn::nex::ClientWebSocketDriver::vf14() {
}

// 0x71016220e0
void nn::nex::ClientWebSocketDriver::vf15() {
}

// 0x71016220f0
u32 nn::nex::ClientWebSocketDriver::vf16() {
    return 0;
}
