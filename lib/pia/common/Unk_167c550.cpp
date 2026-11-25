// Scope: common
// LdnNetworkFactory's overrides that forward to LocalNetworkFactory's (Unk_167c550.h), and
// its vf10, which creates a new LdnNetworkFactory.
// RTTI: N2nn3pia5local17LdnNetworkFactoryE
#include "pia/common/Unk_167c550.h"
#include "pia/common/Unk_17162d0.h"

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
