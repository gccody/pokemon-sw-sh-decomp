// Scope: common
// The smallest Wwise functions: empty functions, deleting destructors of
// abstract classes (a trap), functions that return a constant and functions
// that only tail-call another. Placeholders: most are virtual functions of
// classes not reconstructed yet.
#include <nn/os.h>
#include <types.h>

struct Unk_368b00;
void Unk_368b00_set(Unk_368b00* self);
struct Unk_3c2c10;
void Unk_3c2c10_update(Unk_3c2c10* self);
void Unk_37cdf0_call();
void operator delete(void* ptr) noexcept;
void Unk_308750(void* a0);
void Unk_308eb0(void* a0);
void Unk_308fa0(void* a0);
void Unk_30a520(void* a0);
void Unk_3191e0(void* a0);
void Unk_32ee10(void* a0);
void Unk_3338a0(void* a0);
void Unk_33d330(void* a0);
void Unk_33d8a0(void* a0);
void Unk_3463b0(void* a0);
void Unk_349ab0(void* a0);
void Unk_34e6e0(void* a0);
void Unk_3518d0(void* a0);
void Unk_37e0e0(void* a0);
void Unk_37e350(void* a0);
void Unk_3862d0(void* a0);
void Unk_3a44a0(void* a0);
void Unk_3c2c30(void* a0);
void Unk_3cc3a0(void* a0);
void Unk_3cf7b0(void* a0);
void Unk_3fa180(void* a0);
void Unk_3fa1d0(void* a0);
void Unk_3fb3e0(void* a0);
void Unk_3fc0a0(void* a0);

// 0x7100303670
void Unk_303670() {
}

// 0x7100303680
void Unk_303680(void* self) {
    operator delete(self);
}

// 0x7100304240
void Unk_304240() {
}

// 0x7100304250
void Unk_304250(void* self) {
    operator delete(self);
}

// 0x71003086b0
void Unk_3086b0() {
}

// 0x71003086c0
void Unk_3086c0(void* self) {
    operator delete(self);
}

// 0x7100308f90
void Unk_308f90(void* a0) {
    Unk_308fa0(a0);
}

// 0x71003095e0
void Unk_3095e0() {
}

// 0x71003096e0
void Unk_3096e0() {
}

// 0x7100309720
void Unk_309720() {
    __builtin_trap();
}

// 0x7100309890
void Unk_309890() {
    __builtin_trap();
}

// 0x71003098a0
void Unk_3098a0() {
    __builtin_trap();
}

// 0x710030a6e0
void Unk_30a6e0(void* a0) {
    Unk_37e350(a0);
}

// 0x710030ad30
void Unk_30ad30(void* a0) {
    Unk_308750(a0);
}

// 0x710030ad50
void Unk_30ad50() {
    __builtin_trap();
}

// 0x710030ad60
void Unk_30ad60() {
    __builtin_trap();
}

// 0x710030d560
void Unk_30d560() {
}

// 0x710030d580
void Unk_30d580() {
}

// 0x710030d8a0
void Unk_30d8a0() {
}

// 0x710030f220
void Unk_30f220(void* a0) {
    Unk_30a520(a0);
}

// 0x710030fd80
void Unk_30fd80(void* a0) {
    Unk_3191e0(a0);
}

// 0x7100315270
void Unk_315270() {
    __builtin_trap();
}

// 0x7100315280
void Unk_315280() {
    __builtin_trap();
}

// 0x71003192e0
void Unk_3192e0() {
    __builtin_trap();
}

// 0x71003192f0
void Unk_3192f0() {
    __builtin_trap();
}

// 0x710031b150
void Unk_31b150(void* self) {
    operator delete(self);
}

// 0x710031b170
void Unk_31b170() {
}

// 0x710031b180
void Unk_31b180(void* self) {
    operator delete(self);
}

// 0x710031b1e0
void Unk_31b1e0(void* self) {
    operator delete(self);
}

// 0x710031d4d0
void Unk_31d4d0(void* a0) {
    Unk_308eb0(a0);
}

// 0x710031de10
void Unk_31de10(void* self) {
    operator delete(self);
}

// 0x710031e560
void Unk_31e560(void* self) {
    operator delete(self);
}

// 0x710031f820
void Unk_31f820() {
}

// 0x710031f830
void Unk_31f830(void* self) {
    operator delete(self);
}

// 0x710031fc10
void Unk_31fc10() {
}

// 0x710031fc20
void Unk_31fc20(void* self) {
    operator delete(self);
}

// 0x7100321b20
void Unk_321b20() {
}

// 0x7100321b30
void Unk_321b30(void* self) {
    operator delete(self);
}

// 0x7100321f00
void Unk_321f00() {
}

// 0x7100321f10
void Unk_321f10(void* self) {
    operator delete(self);
}

// 0x710032a1b0
void Unk_32a1b0() {
}

// 0x710032a1c0
void Unk_32a1c0(void* self) {
    operator delete(self);
}

// 0x710032b750
void Unk_32b750() {
}

// 0x710032b760
void Unk_32b760(void* self) {
    operator delete(self);
}

// 0x710032b8d0
void Unk_32b8d0() {
}

// 0x710032b8e0
void Unk_32b8e0(void* self) {
    operator delete(self);
}

// 0x710032bbf0
f32 Unk_32bbf0() {
    return 1.0f;
}

// 0x710032ec70
void Unk_32ec70(nn::os::MutexType* mutex) {
    nn::os::FinalizeMutex(mutex);
}

// 0x710032fdc0
void Unk_32fdc0(u64 a0) {
    Unk_3338a0(reinterpret_cast<void*>(a0));
}

// 0x710032fdf0
void Unk_32fdf0() {
}

// 0x7100332b30
void Unk_332b30(void* self) {
    operator delete(self);
}

// 0x7100333930
void Unk_333930(Unk_368b00* self) {
    Unk_368b00_set(self);
}

// 0x710033cfe0
void Unk_33cfe0(void* a0) {
    Unk_33d330(a0);
}

// 0x710033cff0
void Unk_33cff0() {
    __builtin_trap();
}

// 0x710033d390
void Unk_33d390() {
    __builtin_trap();
}

// 0x710033d910
void Unk_33d910() {
    __builtin_trap();
}

// 0x710033ebe0
void Unk_33ebe0(void* a0) {
    Unk_33d330(a0);
}

// 0x710033ebf0
void Unk_33ebf0() {
    __builtin_trap();
}

// 0x710033f0d0
void Unk_33f0d0(void* a0) {
    Unk_33d8a0(a0);
}

// 0x710033f500
void Unk_33f500(void* a0) {
    Unk_33d330(a0);
}

// 0x710033f8e0
void Unk_33f8e0(void* a0) {
    Unk_33d8a0(a0);
}

// 0x710033ff50
void Unk_33ff50(void* a0) {
    Unk_33d8a0(a0);
}

// 0x7100340030
void Unk_340030(void* a0) {
    Unk_33d330(a0);
}

// 0x7100340400
void Unk_340400(void* a0) {
    Unk_33d8a0(a0);
}

// 0x7100340530
void Unk_340530(void* a0) {
    Unk_33d8a0(a0);
}

// 0x7100340640
void Unk_340640(void* a0) {
    Unk_33d8a0(a0);
}

// 0x7100340c50
void Unk_340c50(void* a0) {
    Unk_33d8a0(a0);
}

// 0x7100349ef0
void Unk_349ef0(void* a0) {
    Unk_3463b0(a0);
}

// 0x710034c290
void Unk_34c290() {
    __builtin_trap();
}

// 0x710034c320
void Unk_34c320() {
    __builtin_trap();
}

// 0x710034d760
void Unk_34d760(void* a0) {
    Unk_3518d0(a0);
}

// 0x7100356f70
void Unk_356f70(void* a0) {
    Unk_3862d0(a0);
}

// 0x71003579d0
void Unk_3579d0() {
    __builtin_trap();
}

// 0x7100357a50
void Unk_357a50() {
    __builtin_trap();
}

// 0x7100357af0
void Unk_357af0(void* a0) {
    Unk_33d8a0(a0);
}

// 0x710035ff10
void Unk_35ff10() {
    __builtin_trap();
}

// 0x710035ff20
void Unk_35ff20() {
    __builtin_trap();
}

// 0x7100362c80
void Unk_362c80() {
}

// 0x7100362cb0
void Unk_362cb0(void* self) {
    operator delete(self);
}

// 0x7100363550
void Unk_363550() {
    __builtin_trap();
}

// 0x7100365fc0
void Unk_365fc0() {
    __builtin_trap();
}

// 0x7100365fd0
void Unk_365fd0() {
    __builtin_trap();
}

// 0x7100368b10
void Unk_368b10() {
    Unk_37cdf0_call();
}

// 0x710036a9e0
void Unk_36a9e0() {
    __builtin_trap();
}

// 0x710036d780
void Unk_36d780(void* self) {
    operator delete(self);
}

// 0x710036e290
void Unk_36e290(void* self) {
    operator delete(self);
}

// 0x710036ff80
void Unk_36ff80(void* self) {
    operator delete(self);
}

// 0x710036ffb0
void Unk_36ffb0(void* self) {
    operator delete(self);
}

// 0x71003705d0
void Unk_3705d0(void* self) {
    operator delete(self);
}

// 0x71003705e0
void Unk_3705e0(void* self) {
    operator delete(self);
}

// 0x7100370b00
void Unk_370b00(void* self) {
    operator delete(self);
}

// 0x7100370b30
void Unk_370b30(void* self) {
    operator delete(self);
}

// 0x7100371070
void Unk_371070(void* self) {
    operator delete(self);
}

// 0x7100371080
void Unk_371080(void* self) {
    operator delete(self);
}

// 0x7100371510
void Unk_371510(void* self) {
    operator delete(self);
}

// 0x7100371520
void Unk_371520(void* self) {
    operator delete(self);
}

// 0x7100373c00
void Unk_373c00() {
    __builtin_trap();
}

// 0x7100379f10
void Unk_379f10() {
    __builtin_trap();
}

// 0x7100379f20
void Unk_379f20() {
    __builtin_trap();
}

// 0x710037aa30
f32 Unk_37aa30() {
    return 1.0f;
}

// 0x710037df30
void Unk_37df30(void* a0) {
    Unk_32ee10(a0);
}

// 0x710037e1a0
void Unk_37e1a0() {
    __builtin_trap();
}

// 0x710037e1b0
void Unk_37e1b0() {
    __builtin_trap();
}

// 0x71003820d0
void Unk_3820d0() {
    __builtin_trap();
}

// 0x71003820e0
void Unk_3820e0() {
    __builtin_trap();
}

// 0x7100388e60
void Unk_388e60(void* a0) {
    Unk_3a44a0(a0);
}

// 0x710038e960
void Unk_38e960() {
}

// 0x710038e970
void Unk_38e970() {
    __builtin_trap();
}

// 0x710038e990
void Unk_38e990() {
    __builtin_trap();
}

// 0x7100394cb0
void Unk_394cb0() {
}

// 0x7100394cc0
void Unk_394cc0(void* self) {
    operator delete(self);
}

// 0x7100394f00
void Unk_394f00(void* self) {
    operator delete(self);
}

// 0x71003953d0
void Unk_3953d0(void* self) {
    operator delete(self);
}

// 0x710039f670
void Unk_39f670(void* self) {
    operator delete(self);
}

// 0x710039f680
void Unk_39f680(void* self) {
    operator delete(self);
}

// 0x71003a1d50
void Unk_3a1d50(void* self) {
    operator delete(self);
}

// 0x71003a1d60
void Unk_3a1d60(void* self) {
    operator delete(self);
}

// 0x71003a2360
void Unk_3a2360(void* self) {
    operator delete(self);
}

// 0x71003a2390
void Unk_3a2390(void* self) {
    operator delete(self);
}

// 0x71003a28c0
void Unk_3a28c0(void* self) {
    operator delete(self);
}

// 0x71003a28d0
void Unk_3a28d0(void* self) {
    operator delete(self);
}

// 0x71003a2e00
void Unk_3a2e00(void* self) {
    operator delete(self);
}

// 0x71003a2e10
void Unk_3a2e10(void* self) {
    operator delete(self);
}

// 0x71003a32a0
void Unk_3a32a0(void* self) {
    operator delete(self);
}

// 0x71003a32b0
void Unk_3a32b0(void* self) {
    operator delete(self);
}

// 0x71003a4550
void Unk_3a4550() {
    __builtin_trap();
}

// 0x71003a5d50
void Unk_3a5d50(void* self) {
    operator delete(self);
}

// 0x71003a5de0
void Unk_3a5de0() {
}

// 0x71003a5df0
void Unk_3a5df0() {
    __builtin_trap();
}

// 0x71003a7300
void Unk_3a7300(void* a0) {
    Unk_37e0e0(a0);
}

// 0x71003a7320
void Unk_3a7320() {
    __builtin_trap();
}

// 0x71003a7330
void Unk_3a7330() {
    __builtin_trap();
}

// 0x71003b1cc0
void Unk_3b1cc0() {
}

// 0x71003b1cd0
void Unk_3b1cd0() {
    __builtin_trap();
}

// 0x71003bd6a0
void Unk_3bd6a0(void* a0) {
    Unk_349ab0(a0);
}

// 0x71003c28f0
void Unk_3c28f0() {
}

// 0x71003c2a40
void Unk_3c2a40() {
    __builtin_trap();
}

// 0x71003c8ec0
void Unk_3c8ec0(void* a0) {
    Unk_34e6e0(a0);
}

// 0x71003c9990
void Unk_3c9990() {
    __builtin_trap();
}

// 0x71003ca200
void Unk_3ca200(void* a0) {
    Unk_32ee10(a0);
}

// 0x71003ca210
void Unk_3ca210(void* a0) {
    Unk_32ee10(a0);
}

// 0x71003cbcc0
void Unk_3cbcc0() {
    __builtin_trap();
}

// 0x71003cc410
void Unk_3cc410() {
    __builtin_trap();
}

// 0x71003cd320
void Unk_3cd320(void* self) {
    operator delete(self);
}

// 0x71003cfa70
void Unk_3cfa70() {
    __builtin_trap();
}

// 0x71003d1320
f32 Unk_3d1320() {
    return 0.0f;
}

// 0x71003d14c0
void Unk_3d14c0(void* a0) {
    Unk_3cf7b0(a0);
}

// 0x71003d14d0
void Unk_3d14d0() {
    __builtin_trap();
}

// 0x71003d57c0
void Unk_3d57c0(void* a0) {
    Unk_32ee10(a0);
}

// 0x71003d5810
void Unk_3d5810(void* a0) {
    Unk_32ee10(a0);
}

// 0x71003d6310
void Unk_3d6310() {
}

// 0x71003da620
void Unk_3da620() {
    __builtin_trap();
}

// 0x71003dce70
void Unk_3dce70() {
    __builtin_trap();
}

// 0x71003ddd50
void Unk_3ddd50() {
    __builtin_trap();
}

// 0x71003ddd80
f32 Unk_3ddd80() {
    return 0.0f;
}

// 0x71003de1a0
void Unk_3de1a0(void* a0) {
    Unk_3cc3a0(a0);
}

// 0x71003e05e0
f32 Unk_3e05e0() {
    return 1.0f;
}

// 0x71003e05f0
f32 Unk_3e05f0() {
    return 1.0f;
}

// 0x71003e0700
void Unk_3e0700(void* a0) {
    Unk_32ee10(a0);
}

// 0x71003e08d0
void Unk_3e08d0(void* a0) {
    Unk_32ee10(a0);
}

// 0x71003e0ab0
void Unk_3e0ab0() {
}

// 0x71003e0ac0
void Unk_3e0ac0(void* self) {
    operator delete(self);
}

// 0x71003e2c00
void Unk_3e2c00(Unk_3c2c10* self) {
    Unk_3c2c10_update(self);
}

// 0x71003e2c10
void Unk_3e2c10(void* a0) {
    Unk_3c2c30(a0);
}

// 0x71003e2c20
void Unk_3e2c20() {
}

// 0x71003e2c40
void Unk_3e2c40() {
}

// 0x71003e2c50
void Unk_3e2c50() {
}

// 0x71003e2c90
void Unk_3e2c90() {
}

// 0x71003e2ca0
void Unk_3e2ca0() {
}

// 0x71003e2d10
void Unk_3e2d10() {
}

// 0x71003e2d20
void Unk_3e2d20(void* self) {
    operator delete(self);
}

// 0x71003f5540
void Unk_3f5540() {
}

// 0x71003f5550
void Unk_3f5550(void* self) {
    operator delete(self);
}

// 0x71003f7650
void Unk_3f7650() {
}

// 0x71003f7660
void Unk_3f7660(void* self) {
    operator delete(self);
}

// 0x71003fa1c0
void Unk_3fa1c0() {
    __builtin_trap();
}

// 0x71003fb210
void Unk_3fb210() {
    __builtin_trap();
}

// 0x71003fb480
void Unk_3fb480() {
    __builtin_trap();
}

// 0x71003fb490
void Unk_3fb490() {
    __builtin_trap();
}

// 0x71003fc140
void Unk_3fc140() {
    __builtin_trap();
}

// 0x71003fc150
void Unk_3fc150() {
    __builtin_trap();
}

// 0x71003fe250
void Unk_3fe250(void* self) {
    operator delete(self);
}

// 0x71003ff900
void Unk_3ff900(void* self) {
    operator delete(self);
}

// 0x71003ffa10
void Unk_3ffa10() {
    __builtin_trap();
}

// 0x71003fff20
void Unk_3fff20(void* a0) {
    Unk_3fa180(a0);
}

// 0x71003fff60
void Unk_3fff60(void* a0) {
    Unk_3fa1d0(a0);
}

// 0x7100400510
void Unk_400510(void* a0) {
    Unk_3fb3e0(a0);
}

// 0x7100400960
void Unk_400960(void* a0) {
    Unk_3fc0a0(a0);
}

// 0x7100403520
void Unk_403520() {
    __builtin_trap();
}

// 0x7100403560
void Unk_403560() {
    __builtin_trap();
}

// 0x71004035a0
void Unk_4035a0() {
    __builtin_trap();
}

// 0x71004035e0
void Unk_4035e0() {
    __builtin_trap();
}
