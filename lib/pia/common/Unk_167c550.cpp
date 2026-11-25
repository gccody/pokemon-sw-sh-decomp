// Scope: common
// LdnNetworkFactory's overrides that forward to LocalNetworkFactory's (Unk_167c550.h), and
// its vf10, which creates a new LdnNetworkFactory.
// RTTI: N2nn3pia5local17LdnNetworkFactoryE
#include "pia/common/Unk_167c550.h"
#include "pia/common/Unk_17162d0.h"

// The placement form, as libc++'s <new> has it (lib/pia doesn't get the
// libc++ headers).
inline void* operator new(size_t, void* place) noexcept {
    return place;
}

// LocalNetworkFactory's vtable's placeholder class (its constructor is
// 0x710168df70, in src/unsorted/ctor/Unk_168df70.cpp) and LdnNetworkFactory's
// (vtable 0x7102458be8: the RTTI is LdnNetworkFactory's, but data_symbols.csv
// names the vtable after this placeholder). Only the vptr, 8 bytes.
class Unk_245a3d8 {
public:
    Unk_245a3d8();
    virtual ~Unk_245a3d8();
};

class Unk_2458be8 : public Unk_245a3d8 {
public:
    Unk_2458be8() {}
    ~Unk_2458be8() override;
};
PKMN_SIZE_ASSERT(Unk_2458be8, 0x8);

// What vf12 creates: 0x8440 bytes, built by 0x710167f1d0 (vtable 0x71024592d8).
class Unk_24592d8 {
public:
    Unk_24592d8();
    virtual ~Unk_24592d8();

    u8 _8[0x8440 - 0x8];
};
PKMN_SIZE_ASSERT(Unk_24592d8, 0x8440);

// What holds the objects vf12 creates: zeroed memory for one (Unk_173d700), an
// id for one (Unk_173d790: Unk_1f452f4 when there's none left) and freeing it
// (Unk_173d6d0).
class Unk_173d6d0 {
public:
    void* Unk_173d700(u32 size);
    u32 Unk_173d790(Unk_24592d8* object, u32 id);
    void Unk_173d6d0_free(Unk_24592d8* object);
};

// The object behind the global Unk_27fc2d8 (lib/pia/common/Unk_1735510.cpp).
struct Unk_27fc2d8_object {
    u8 _0[0x10];
    Unk_173d6d0 field_10;
    u8 _11[0x38 - 0x11];
    bool field_38;
};
PKMN_OFFSET_ASSERT(Unk_27fc2d8_object, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_27fc2d8_object, field_38, 0x38);

extern Unk_27fc2d8_object* Unk_27fc2d8;
extern u32 Unk_1f452f4;

// 0x710167c580
Unk_2458be8* nn::pia::local::LdnNetworkFactory::vf10() {
    return new (Unk_1652bd0()) Unk_2458be8();
}

// 0x710167c560
u32 nn::pia::local::LdnNetworkFactory::vf36() {
    return LocalNetworkFactory::vf36();
}

// 0x710167c570
u32 nn::pia::local::LdnNetworkFactory::vf55() {
    return LocalNetworkFactory::vf55();
}

// 0x710167c710
Unk_245bc18* nn::pia::local::LdnNetworkFactory::vf15() {
    return LocalNetworkFactory::vf15();
}

// 0x710167c720
void nn::pia::local::LdnNetworkFactory::vf17(Unk_168e090_arg1* object) {
    LocalNetworkFactory::vf17(object);
}

// 0x710167c730
Unk_245bb18* nn::pia::local::LdnNetworkFactory::vf16() {
    return LocalNetworkFactory::vf16();
}

// 0x710167c740
void nn::pia::local::LdnNetworkFactory::vf18(Unk_168e110_arg1* object) {
    LocalNetworkFactory::vf18(object);
}

// 0x710167c850
Unk_245be98* nn::pia::local::LdnNetworkFactory::vf23() {
    return LocalNetworkFactory::vf23();
}

// 0x710167c860
void nn::pia::local::LdnNetworkFactory::vf26(Unk_16a8f30_arg1* object) {
    LocalNetworkFactory::vf26(object);
}

// 0x710167c610
nn::pia::Unk_165e060 nn::pia::local::LdnNetworkFactory::vf12() {
    Unk_27fc2d8_object* owner = Unk_27fc2d8;
    if (owner == nullptr) {
        return Unk_165e060Value<0x10c08>();
    }
    if (!owner->field_38) {
        Unk_173d6d0* holder = &owner->field_10;
        Unk_24592d8* object = new (holder->Unk_173d700(sizeof(Unk_24592d8))) Unk_24592d8();
        if (holder->Unk_173d790(object, 0x24000000) == Unk_1f452f4) {
            object->~Unk_24592d8();
            holder->Unk_173d6d0_free(object);
        }
    }
    return NetworkFactory::vf12();
}
