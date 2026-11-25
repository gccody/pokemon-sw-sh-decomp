// Scope: common
// LdnNetworkFactory's overrides that forward to LocalNetworkFactory's
// function in the same vtable slot (Ldn slot N -> Local slot N). Placeholder
// member names vf<slot> (lib/pia/README.md).
// RTTI: N2nn3pia5local17LdnNetworkFactoryE, N2nn3pia5local19LocalNetworkFactoryE
#include <types.h>

struct Unk_168e6c0_arg1;
struct Unk_168e740_arg1;
struct Unk_168e800_arg1;
struct Unk_245a928;
struct Unk_245aa88;
struct Unk_245f6a8;

namespace nn {
namespace pia {
namespace local {
class LocalNetworkFactory {
public:
    Unk_245a928* vf61();
    void vf69(Unk_168e6c0_arg1* object);
    Unk_245aa88* vf62();
    void vf70(Unk_168e740_arg1* object);
    u64 vf63();
    void vf71();
    Unk_245f6a8* vf74();
    void vf77(Unk_168e800_arg1* object);
};

class LdnNetworkFactory : public LocalNetworkFactory {
public:
    Unk_245a928* vf61();
    void vf69(Unk_168e6c0_arg1* object);
    Unk_245aa88* vf62();
    void vf70(Unk_168e740_arg1* object);
    u64 vf63();
    void vf71();
    Unk_245f6a8* vf74();
    void vf77(Unk_168e800_arg1* object);
};
}  // namespace local
}  // namespace pia
}  // namespace nn

// 0x710167ca70
Unk_245a928* nn::pia::local::LdnNetworkFactory::vf61() {
    return LocalNetworkFactory::vf61();
}

// 0x710167ca80
void nn::pia::local::LdnNetworkFactory::vf69(Unk_168e6c0_arg1* object) {
    LocalNetworkFactory::vf69(object);
}

// 0x710167ca90
Unk_245aa88* nn::pia::local::LdnNetworkFactory::vf62() {
    return LocalNetworkFactory::vf62();
}

// 0x710167caa0
void nn::pia::local::LdnNetworkFactory::vf70(Unk_168e740_arg1* object) {
    LocalNetworkFactory::vf70(object);
}

// 0x710167cab0
u64 nn::pia::local::LdnNetworkFactory::vf63() {
    return LocalNetworkFactory::vf63();
}

// 0x710167cac0
void nn::pia::local::LdnNetworkFactory::vf71() {
    LocalNetworkFactory::vf71();
}

// 0x710167cbf0
Unk_245f6a8* nn::pia::local::LdnNetworkFactory::vf74() {
    return LocalNetworkFactory::vf74();
}

// 0x710167cc00
void nn::pia::local::LdnNetworkFactory::vf77(Unk_168e800_arg1* object) {
    LocalNetworkFactory::vf77(object);
}
