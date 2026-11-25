// Scope: common
// LdnNetworkFactory's overrides that forward to LocalNetworkFactory's
// function in the same vtable slot (Ldn slot N -> Local slot N). Placeholder
// member names vf<slot> (lib/pia/README.md).
// RTTI: N2nn3pia5local17LdnNetworkFactoryE, N2nn3pia5local19LocalNetworkFactoryE
#include <types.h>

struct Unk_168e350_arg1;
struct Unk_168e3e0_arg1;
struct Unk_168e470_arg1;
struct Unk_168e520_arg1;
struct Unk_168e5b0_arg1;
struct Unk_168e640_arg1;
struct Unk_168e920;
struct Unk_168f110;
struct Unk_168f1e0;
struct Unk_168fb10;
struct Unk_16903c0;
struct Unk_1690ec0;
struct Unk_16a8eb0_arg1;
struct Unk_245b728;

namespace nn {
namespace pia {
namespace local {
class LocalNetworkFactory {
public:
    Unk_245b728* vf43();
    void vf50(Unk_16a8eb0_arg1* object);
    Unk_1690ec0* vf51();
    void vf53(Unk_168e350_arg1* object);
    Unk_16903c0* vf52();
    void vf54(Unk_168e3e0_arg1* object);
    Unk_168f1e0* vf56();
    void vf64(Unk_168e470_arg1* object);
    u64 vf57();
    void vf65();
    Unk_168fb10* vf58();
    void vf66(Unk_168e520_arg1* object);
    Unk_168e920* vf59();
    void vf67(Unk_168e5b0_arg1* object);
    Unk_168f110* vf60();
    void vf68(Unk_168e640_arg1* object);
};

class LdnNetworkFactory : public LocalNetworkFactory {
public:
    Unk_245b728* vf43();
    void vf50(Unk_16a8eb0_arg1* object);
    Unk_1690ec0* vf51();
    void vf53(Unk_168e350_arg1* object);
    Unk_16903c0* vf52();
    void vf54(Unk_168e3e0_arg1* object);
    Unk_168f1e0* vf56();
    void vf64(Unk_168e470_arg1* object);
    u64 vf57();
    void vf65();
    Unk_168fb10* vf58();
    void vf66(Unk_168e520_arg1* object);
    Unk_168e920* vf59();
    void vf67(Unk_168e5b0_arg1* object);
    Unk_168f110* vf60();
    void vf68(Unk_168e640_arg1* object);
};
}  // namespace local
}  // namespace pia
}  // namespace nn

// 0x710167c970
Unk_245b728* nn::pia::local::LdnNetworkFactory::vf43() {
    return LocalNetworkFactory::vf43();
}

// 0x710167c980
void nn::pia::local::LdnNetworkFactory::vf50(Unk_16a8eb0_arg1* object) {
    LocalNetworkFactory::vf50(object);
}

// 0x710167c990
Unk_1690ec0* nn::pia::local::LdnNetworkFactory::vf51() {
    return LocalNetworkFactory::vf51();
}

// 0x710167c9a0
void nn::pia::local::LdnNetworkFactory::vf53(Unk_168e350_arg1* object) {
    LocalNetworkFactory::vf53(object);
}

// 0x710167c9b0
Unk_16903c0* nn::pia::local::LdnNetworkFactory::vf52() {
    return LocalNetworkFactory::vf52();
}

// 0x710167c9c0
void nn::pia::local::LdnNetworkFactory::vf54(Unk_168e3e0_arg1* object) {
    LocalNetworkFactory::vf54(object);
}

// 0x710167c9d0
Unk_168f1e0* nn::pia::local::LdnNetworkFactory::vf56() {
    return LocalNetworkFactory::vf56();
}

// 0x710167c9e0
void nn::pia::local::LdnNetworkFactory::vf64(Unk_168e470_arg1* object) {
    LocalNetworkFactory::vf64(object);
}

// 0x710167c9f0
u64 nn::pia::local::LdnNetworkFactory::vf57() {
    return LocalNetworkFactory::vf57();
}

// 0x710167ca00
void nn::pia::local::LdnNetworkFactory::vf65() {
    LocalNetworkFactory::vf65();
}

// 0x710167ca10
Unk_168fb10* nn::pia::local::LdnNetworkFactory::vf58() {
    return LocalNetworkFactory::vf58();
}

// 0x710167ca20
void nn::pia::local::LdnNetworkFactory::vf66(Unk_168e520_arg1* object) {
    LocalNetworkFactory::vf66(object);
}

// 0x710167ca30
Unk_168e920* nn::pia::local::LdnNetworkFactory::vf59() {
    return LocalNetworkFactory::vf59();
}

// 0x710167ca40
void nn::pia::local::LdnNetworkFactory::vf67(Unk_168e5b0_arg1* object) {
    LocalNetworkFactory::vf67(object);
}

// 0x710167ca50
Unk_168f110* nn::pia::local::LdnNetworkFactory::vf60() {
    return LocalNetworkFactory::vf60();
}

// 0x710167ca60
void nn::pia::local::LdnNetworkFactory::vf68(Unk_168e640_arg1* object) {
    LocalNetworkFactory::vf68(object);
}
