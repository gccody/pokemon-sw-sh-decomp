// Scope: common
// Small virtual functions of a library class (tools/leafgen.py members): placeholder
// member names vf<slot>, placeholder structs. The class's name is its RTTI's.
#include <types.h>

struct Unk_1689f80_18 {
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
    virtual void vf22();
    virtual void vf23();
    virtual void vf24();
    virtual void vf25();
    virtual void vf26();
    virtual void vf27();
    virtual void vf28();
    virtual void vf29();
    virtual void vf30();
    virtual void vf31();
    virtual void vf32();
    virtual void vf33();
    virtual void vf34();
    virtual void vf35();
    virtual void vf36();
    virtual void vf37();
    virtual void vf38();
    virtual void vf39();
    virtual void vf40();
    virtual void vf41();
    virtual void vf42();
    virtual void vf43();
    virtual void vf44();
    virtual void vf45(u64, u64, u64);
};

struct Unk_1689f80 {
    u8 _0[0x18];
    Unk_1689f80_18* field_18;
};
PKMN_OFFSET_ASSERT(Unk_1689f80, field_18, 0x18);

namespace nn {
namespace pia {
namespace local {
class LocalFacade {
public:
    void vf2();
    void vf4();
    void vf6();
    void vf9(u64 value, u32 /*unused*/, u64 arg3, u64 arg4);
};
}  // namespace local
}  // namespace pia
}  // namespace nn

// 0x7101689150
void nn::pia::local::LocalFacade::vf4() {
}

// 0x7101689330
void nn::pia::local::LocalFacade::vf6() {
}

// 0x7101689f80
void nn::pia::local::LocalFacade::vf9(u64 value, u32 /*unused*/, u64 arg3, u64 arg4) {
    const Unk_1689f80* self = reinterpret_cast<const Unk_1689f80*>(this);
    self->field_18->vf45(value, arg4, arg3);
}

// 0x710168a430
void nn::pia::local::LocalFacade::vf2() {
}
