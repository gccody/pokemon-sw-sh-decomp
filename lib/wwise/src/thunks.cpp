// Scope: common
// Wwise functions that adjust `this` (or load a member) and tail-call: the
// this-adjusting thunks of classes with several bases, and forwarders to a
// member. Placeholders: the classes aren't reconstructed yet.
#include <types.h>

struct Unk_38d2c0;
void Unk_38d2c0_set(Unk_38d2c0* self);
struct Unk_3c2c10;
void Unk_3c2c10_update(Unk_3c2c10* self);
void Unk_308750(void* self);
// The nodes' base class (Unk_237c170.h): only its destructor, 0x71003097b0.
class Unk_237c170 {
public:
    ~Unk_237c170();
};
void Unk_3101f0(void* self);
void Unk_313160(void* self);
void Unk_316ee0(void* self);
void Unk_3191e0(void* self);
void Unk_31b340(void* self);
void Unk_34d6a0(void* self);
void Unk_34fc00(void* self);
void Unk_34fc50(void* self);
void Unk_34fdc0(void* self);
void Unk_3518d0(void* self);
void Unk_3549e0(void* self);
void Unk_35d580(void* self);
void Unk_360ba0(void* self);
void Unk_3627c0(void* self);
void Unk_3636d0(void* self);
void Unk_369110(void* self);
void Unk_3791b0(void* self);
void Unk_379400(void* self);
void Unk_37e0e0(void* self);
void Unk_381d40(void* self);
void Unk_38b400(void* self);
void Unk_38c900(void* self);
void Unk_38d590(void* self);
void Unk_38dcd0(void* self);
void Unk_38ddf0(void* self);
void Unk_3a7f50(void* self);
void Unk_3b3970(void* self);
void Unk_3c2c30(void* self);
void Unk_3ce3e0(void* self);
void Unk_3ce490(void* self);
void Unk_3d17f0(void* self);
void Unk_3d4310(void* self);
void Unk_3d6cf0(void* self);
void Unk_3dfb80(void* self);
void Unk_3e03b0(void* self);
void Unk_3e1e50(void* self);
void Unk_3e25d0(void* self);
void Unk_3e5be0(void* self);
void Unk_3f4910(void* self);
void Unk_3fb3e0(void* self);
void Unk_3fc0a0(void* self);
void Unk_3fc760(void* self);
void Unk_3fcc60(void* self);
void Unk_3fcf30(void* self);
void Unk_3fd7a0(void* self);
void Unk_400590(void* self);
void Unk_400620(void* self);
void Unk_401d20(void* self);
void Unk_401e70(void* self);

// 0x7100309880
void Unk_309880(void* self) {
    reinterpret_cast<Unk_237c170*>(static_cast<u8*>(self) - 0x18)->~Unk_237c170();
}

// 0x710030ad40
void Unk_30ad40(void* self) {
    Unk_308750(static_cast<u8*>(self) - 0x18);
}

// 0x710030fd90
void Unk_30fd90(void* self) {
    Unk_3191e0(static_cast<u8*>(self) - 0x18);
}

// 0x71003102d0
void Unk_3102d0(void* self) {
    Unk_3101f0(static_cast<u8*>(self) - 0x18);
}

// 0x71003132f0
void Unk_3132f0(void* self) {
    Unk_313160(static_cast<u8*>(self) - 0x18);
}

// 0x710031a7d0
void Unk_31a7d0(void* self) {
    Unk_31b340(static_cast<u8*>(self) + 0x60);
}

// 0x710031c5d0
void Unk_31c5d0(void* self) {
    Unk_316ee0(static_cast<u8*>(self) + 0x98);
}

// 0x7100341c80
void Unk_341c80(void* self) {
    Unk_3791b0(static_cast<u8*>(self) + 0x110);
}

// 0x7100341c90
void Unk_341c90(void* self) {
    Unk_379400(static_cast<u8*>(self) + 0x110);
}

// 0x710034b260
void Unk_34b260(void* self) {
    Unk_3b3970(static_cast<u8*>(self) + 0x18);
}

// 0x710034d770
void Unk_34d770(void* self) {
    Unk_3518d0(static_cast<u8*>(self) - 0x18);
}

// 0x7100351ea0
void Unk_351ea0(void* self) {
    Unk_3518d0(static_cast<u8*>(self) - 0x18);
}

// 0x7100354bc0
void Unk_354bc0(void* self) {
    Unk_3549e0(static_cast<u8*>(self) - 0x18);
}

// 0x710035d720
void Unk_35d720(void* self) {
    Unk_35d580(static_cast<u8*>(self) - 0x18);
}

// 0x710035ff00
void Unk_35ff00(void* self) {
    Unk_3627c0(static_cast<u8*>(self) - 0x18);
}

// 0x7100362780
void Unk_362780(void* self) {
    Unk_3627c0(static_cast<u8*>(self) - 0x18);
}

// 0x7100362920
void Unk_362920(void* self) {
    Unk_3627c0(static_cast<u8*>(self) - 0x18);
}

// 0x71003629a0
void Unk_3629a0(void* self) {
    Unk_3627c0(static_cast<u8*>(self) - 0x18);
}

// 0x7100362c60
void Unk_362c60(void* self) {
    Unk_360ba0(static_cast<u8*>(self) - 0x18);
}

// 0x7100362c70
void Unk_362c70(void* self) {
    Unk_360ba0(static_cast<u8*>(self) - 0x18);
}

// 0x7100363790
void Unk_363790(void* self) {
    Unk_3636d0(static_cast<u8*>(self) - 0x18);
}

// 0x710037e190
void Unk_37e190(void* self) {
    Unk_37e0e0(static_cast<u8*>(self) - 0x18);
}

// 0x71003820c0
void Unk_3820c0(void* self) {
    Unk_381d40(static_cast<u8*>(self) - 0x18);
}

// 0x710038b5c0
void Unk_38b5c0(void* self) {
    Unk_38b400(static_cast<u8*>(self) - 0x18);
}

// 0x710038ca60
void Unk_38ca60(void* self) {
    Unk_38c900(static_cast<u8*>(self) - 0x18);
}

// 0x710038dcc0
void Unk_38dcc0(void* self) {
    Unk_38d590(static_cast<u8*>(self) - 0x18);
}

// 0x710038dde0
void Unk_38dde0(void* self) {
    Unk_38dcd0(static_cast<u8*>(self) - 0x18);
}

// 0x71003a6f90
void Unk_3a6f90(void* self) {
    Unk_3a7f50(static_cast<u8*>(self) + 0xb8);
}

// 0x71003a7310
void Unk_3a7310(void* self) {
    Unk_37e0e0(static_cast<u8*>(self) - 0x18);
}

// 0x71003bd690
void Unk_3bd690(void* self) {
    Unk_34d6a0(static_cast<u8*>(self) + 0xd8);
}

// 0x71003cbcd0
void Unk_3cbcd0(void* self) {
    Unk_369110(static_cast<u8*>(self) + 0x40);
}

// 0x71003d11e0
void Unk_3d11e0(void* self) {
    Unk_34fdc0(reinterpret_cast<void**>(self)[4]);
}

// 0x71003d1210
void Unk_3d1210(void* self) {
    Unk_34fc00(reinterpret_cast<void**>(self)[4]);
}

// 0x71003d1300
void Unk_3d1300(void* self) {
    Unk_34fc50(reinterpret_cast<void**>(self)[4]);
}

// 0x71003d1350
void Unk_3d1350(void* self) {
    Unk_3ce490(static_cast<u8*>(self) + 0x10);
}

// 0x71003d1360
void Unk_3d1360(void* self) {
    Unk_3ce3e0(static_cast<u8*>(self) + 0x10);
}

// 0x71003d1bb0
void Unk_3d1bb0(void* self) {
    Unk_3d17f0(static_cast<u8*>(self) - 0xc0);
}

// 0x71003d43c0
void Unk_3d43c0(void* self) {
    Unk_3d4310(static_cast<u8*>(self) - 0xc0);
}

// 0x71003dc6d0
void Unk_3dc6d0(void* self) {
    Unk_3d6cf0(static_cast<u8*>(self) + 0xa0);
}

// 0x71003ddb80
void Unk_3ddb80(void* self) {
    Unk_38d2c0_set(reinterpret_cast<Unk_38d2c0*>(reinterpret_cast<void**>(self)[3]));
}

// 0x71003dfc50
void Unk_3dfc50(void* self) {
    Unk_3dfb80(static_cast<u8*>(self) - 0x28);
}

// 0x71003dfc60
void Unk_3dfc60(void* self) {
    Unk_3dfb80(static_cast<u8*>(self) - 0x30);
}

// 0x71003e0550
void Unk_3e0550(void* self) {
    Unk_3e03b0(static_cast<u8*>(self) - 0x28);
}

// 0x71003e0770
void Unk_3e0770(void* self) {
    Unk_38ddf0(reinterpret_cast<void**>(self)[3]);
}

// 0x71003e1fb0
void Unk_3e1fb0(void* self) {
    Unk_3e1e50(static_cast<u8*>(self) - 0x58);
}

// 0x71003e1fc0
void Unk_3e1fc0(void* self) {
    Unk_3e1e50(static_cast<u8*>(self) - 0x70);
}

// 0x71003e2690
void Unk_3e2690(void* self) {
    Unk_3e25d0(static_cast<u8*>(self) - 0x58);
}

// 0x71003e2c60
void Unk_3e2c60(void* self) {
    Unk_3c2c10_update(reinterpret_cast<Unk_3c2c10*>(static_cast<u8*>(self) - 0x58));
}

// 0x71003e2c70
void Unk_3e2c70(void* self) {
    Unk_3c2c30(static_cast<u8*>(self) - 0x58);
}

// 0x71003f4900
void Unk_3f4900(void* self) {
    Unk_3f4910(static_cast<u8*>(self) + 0xe0);
}

// 0x71003f4c70
void Unk_3f4c70(void* self) {
    Unk_3e5be0(static_cast<u8*>(self) + 0xf0);
}

// 0x71003fcc50
void Unk_3fcc50(void* self) {
    Unk_3fc760(static_cast<u8*>(self) - 0x70);
}

// 0x71003fcda0
void Unk_3fcda0(void* self) {
    Unk_3fcc60(static_cast<u8*>(self) - 0x70);
}

// 0x71003fcfe0
void Unk_3fcfe0(void* self) {
    Unk_3fcf30(static_cast<u8*>(self) - 0x70);
}

// 0x71003fd880
void Unk_3fd880(void* self) {
    Unk_3fd7a0(static_cast<u8*>(self) - 0x70);
}

// 0x7100400520
void Unk_400520(void* self) {
    Unk_3fb3e0(static_cast<u8*>(self) - 0x70);
}

// 0x7100400610
void Unk_400610(void* self) {
    Unk_400590(static_cast<u8*>(self) - 0x70);
}

// 0x7100400690
void Unk_400690(void* self) {
    Unk_400620(static_cast<u8*>(self) - 0x70);
}

// 0x7100400970
void Unk_400970(void* self) {
    Unk_3fc0a0(static_cast<u8*>(self) - 0x70);
}

// 0x7100401dc0
void Unk_401dc0(void* self) {
    Unk_401d20(static_cast<u8*>(self) - 0x70);
}

// 0x7100401f10
void Unk_401f10(void* self) {
    Unk_401e70(static_cast<u8*>(self) - 0x70);
}
