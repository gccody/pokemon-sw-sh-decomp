// Scope: common
// Small virtual functions of a library class (tools/leafgen.py members): placeholder
// member names vf<slot>, placeholder structs. The class's name is its RTTI's.
// RTTI: N2nn3nex19ClientStreamManagerE
#include <types.h>

struct Unk_1641380_28 {
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
};

struct Unk_1641380_68 {
    u8 _0[0x90];
    u32 field_90;
};
PKMN_OFFSET_ASSERT(Unk_1641380_68, field_90, 0x90);

struct Unk_1641380 {
    u8 _0[0x28];
    Unk_1641380_28* field_28;
    u8 _30[0x38];
    Unk_1641380_68* field_68;
};
PKMN_OFFSET_ASSERT(Unk_1641380, field_28, 0x28);
PKMN_OFFSET_ASSERT(Unk_1641380, field_68, 0x68);

struct Unk_1641370_28 {
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
    virtual void vf16(u64);
};

struct Unk_1641370 {
    u8 _0[0x28];
    Unk_1641370_28* field_28;
};
PKMN_OFFSET_ASSERT(Unk_1641370, field_28, 0x28);

namespace nn {
namespace nex {
class ClientStreamManager {
public:
    void vf3(u32 /*unused*/, u32 arg2);
    void vf4(u64 value);
};
}  // namespace nex
}  // namespace nn

// 0x7101641370
void nn::nex::ClientStreamManager::vf4(u64 value) {
    const Unk_1641370* self = reinterpret_cast<const Unk_1641370*>(this);
    self->field_28->vf16(value);
}

// 0x7101641380
void nn::nex::ClientStreamManager::vf3(u32 /*unused*/, u32 arg2) {
    const Unk_1641380* self = reinterpret_cast<const Unk_1641380*>(this);
    self->field_28->vf17();
    if (self->field_68 != nullptr) {
        self->field_68->field_90 = arg2;
    }
}
