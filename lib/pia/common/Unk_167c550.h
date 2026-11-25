#pragma once
// LdnNetworkFactory's overrides that forward to LocalNetworkFactory's function
// in the same vtable slot (Ldn slot N -> Local slot N), and the
// LocalNetworkFactory members they call. Most of those are themselves a lone
// `b` to MeshNetworkFactory's function in the same slot, so their parameter
// types are MeshNetworkFactory's (lib/pia/gen/nn_pia_mesh_MeshNetworkFactory.cpp).
// Placeholder member names vf<slot> (lib/pia/README.md).
// RTTI: N2nn3pia5local17LdnNetworkFactoryE, N2nn3pia5local19LocalNetworkFactoryE
#include <types.h>

struct Unk_168e090_arg1;
struct Unk_168e110_arg1;
struct Unk_168e240_arg1;
struct Unk_16a8bb0_arg1;
struct Unk_16a8c30_arg1;
struct Unk_16a8cb0_arg1;
struct Unk_16a8db0_arg1;
struct Unk_16a8e30_arg1;
struct Unk_16a8f30_arg1;
struct Unk_16a8fb0_arg1;
struct Unk_16a9030_arg1;
struct Unk_245b5c8;
struct Unk_245b638;
struct Unk_245b6a8;
struct Unk_245b808;
struct Unk_245bb18;
struct Unk_245bc18;
struct Unk_245bdf8;
struct Unk_245be98;
struct Unk_245c008;
struct Unk_245c228;

// LdnNetworkFactory's vtable's placeholder class (Unk_167c550.cpp).
class Unk_2458be8;

// What LocalNetworkFactory's vf39 creates: 0x1b8 bytes, built by 0x710168e840.
struct Unk_168e840;

namespace nn {
namespace pia {
namespace local {

class LocalNetworkFactory {
public:
    Unk_245bc18* vf15();
    Unk_245bb18* vf16();
    void vf17(Unk_168e090_arg1* object);
    void vf18(Unk_168e110_arg1* object);
    Unk_245be98* vf23();
    Unk_245bdf8* vf24();
    Unk_245c008* vf25();
    void vf26(Unk_16a8f30_arg1* object);
    void vf27(Unk_16a8fb0_arg1* object);
    void vf28(Unk_16a9030_arg1* object);
    u32 vf36();
    Unk_245b638* vf37();
    Unk_245b6a8* vf38();
    Unk_168e840* vf39();
    Unk_245b808* vf40();
    Unk_245c228* vf41();
    Unk_245b5c8* vf42();
    void vf44(Unk_16a8bb0_arg1* object);
    void vf45(Unk_16a8c30_arg1* object);
    void vf46(Unk_168e240_arg1* object);
    void vf47(Unk_16a8cb0_arg1* object);
    void vf48(Unk_16a8db0_arg1* object);
    void vf49(Unk_16a8e30_arg1* object);
    u32 vf55();
};

class LdnNetworkFactory : public LocalNetworkFactory {
public:
    Unk_2458be8* vf10();
    Unk_245bc18* vf15();
    Unk_245bb18* vf16();
    void vf17(Unk_168e090_arg1* object);
    void vf18(Unk_168e110_arg1* object);
    Unk_245be98* vf23();
    Unk_245bdf8* vf24();
    Unk_245c008* vf25();
    void vf26(Unk_16a8f30_arg1* object);
    void vf27(Unk_16a8fb0_arg1* object);
    void vf28(Unk_16a9030_arg1* object);
    u32 vf36();
    Unk_245b638* vf37();
    Unk_245b6a8* vf38();
    Unk_168e840* vf39();
    Unk_245b808* vf40();
    Unk_245c228* vf41();
    Unk_245b5c8* vf42();
    void vf44(Unk_16a8bb0_arg1* object);
    void vf45(Unk_16a8c30_arg1* object);
    void vf46(Unk_168e240_arg1* object);
    void vf47(Unk_16a8cb0_arg1* object);
    void vf48(Unk_16a8db0_arg1* object);
    void vf49(Unk_16a8e30_arg1* object);
    u32 vf55();
};

}  // namespace local
}  // namespace pia
}  // namespace nn
