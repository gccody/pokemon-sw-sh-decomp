// Scope: common
// Small members of the class with the vtables 0x7102381490 and 0x71023815b0
// (what a plug-in gets to ask about the sound it is in) that lib/wwise/class
// doesn't have: the ones whose slot number is taken by the other vtable's,
// and the ones with more than a load. Free functions with placeholder names;
// `Unk_369950_Base2` is the object seen from its second base, 8 bytes in.
#include <types.h>

// What the context refers to.
struct Unk_369950_Sound {
    struct Params {
        u8 _0[0x4c];
        u8 field_4c_0 : 3;
    };

    u8 _0[0x110];
    f32 field_110;
    f32 field_114;
    f32 field_118;
    u8 field_11c;
    u8 _11d[0x23];
    Params* field_140;
    u8 _148[0xc];
    u16 field_154_0 : 2;
    u16 field_154_2 : 2;
    u16 field_154_4 : 12;
};
PKMN_OFFSET_ASSERT(Unk_369950_Sound, field_140, 0x140);

struct Unk_369950_Owner {
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6(u64 a1, u64 a2);
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();

    struct A {
        u8 _0[0x10];
        struct B {
            u8 _0[0x38];
            struct C {
                struct D {
                    u8 _0[0x38];
                    u16 field_38;
                }* field_0;
            }* field_38;
        }* field_10;
    };

    u8 _8[0x18];
    union {
        Unk_369950_Sound* field_20;
        A* field_20_a;
    };
};

struct Unk_369950_T {
    u8 _0[0x48];
    Unk_369950_Owner* field_48;
    u8 _50[0x78];
    u64 field_c8;
};
PKMN_OFFSET_ASSERT(Unk_369950_T, field_c8, 0xc8);

struct Unk_369950_Base2 {
    u8 _0[0x40];
    Unk_369950_Owner* field_40;
    u8 _48[0x78];
    u64 field_c0;
};
PKMN_OFFSET_ASSERT(Unk_369950_Base2, field_c0, 0xc0);

void Unk_34fd40(void* sound, u64 a1, u64 a2, u64 a3);
void Unk_34fc50(void* sound);

// 0x7100369950
void Unk_369950(Unk_369950_Base2* self) {
    self->field_40->vf11();
}

// 0x71003699e0
u16 Unk_3699e0(Unk_369950_Base2* self) {
    return self->field_40->field_20_a->field_10->field_38->field_0->field_38;
}

// 0x7100369a00
void Unk_369a00(Unk_369950_T* self, u64 a1, u64 a2) {
    Unk_34fd40(self->field_48->field_20, a1, self->field_c8, a2);
}

// 0x7100369a20
void Unk_369a20(Unk_369950_Base2* self, u64 a1, u64 a2) {
    Unk_34fd40(self->field_40->field_20, a1, self->field_c0, a2);
}

// 0x7100369a50
void Unk_369a50(Unk_369950_Base2* self) {
    self->field_40->vf5();
}

// 0x7100369a70
void Unk_369a70(Unk_369950_Base2* self) {
    self->field_40->vf7();
}

// 0x7100369ab0
void Unk_369ab0(Unk_369950_Base2* self, u64 a1, u64 a2) {
    self->field_40->vf6(a1, a2);
}

// 0x7100369b20
void Unk_369b20(Unk_369950_T* self) {
    Unk_34fc50(self->field_48->field_20);
}

// 0x7100369b30
void Unk_369b30(Unk_369950_Base2* self) {
    Unk_34fc50(self->field_40->field_20);
}

// 0x7100369c50
// NON_MATCHING: the original branches on the second case's last test and
// returns 1 or 0; here the test's result is returned (cset), 4 bytes less.
bool Unk_369c50(Unk_369950_T* self) {
    Unk_369950_Sound* sound = self->field_48->field_20;
    u32 mode = sound->field_154_0;
    if (mode == 0)
        return sound->field_11c != 0;
    if (mode == 1) {
        if (sound->field_140 != nullptr && sound->field_140->field_4c_0 != 0)
            return true;
    }
    return false;
}

// 0x7100369cd0
u32 Unk_369cd0(Unk_369950_T* self) {
    Unk_369950_Sound* sound = self->field_48->field_20;
    return sound->field_154_0 != 0 ? sound->field_154_2 : 0;
}

// 0x7100369cf0
f32 Unk_369cf0(Unk_369950_T* self) {
    return self->field_48->field_20->field_118 * 0.01f;
}

struct Unk_369d10_Out {
    f32 field_0;
    f32 field_4;
    f32 field_8;
};

static inline f32 Unk_369d10_Clamp(f32 value) {
    value = value < 1.0f ? value : 1.0f;
    return value > -1.0f ? value : -1.0f;
}

// 0x7100369d10
void Unk_369d10(Unk_369950_T* self, Unk_369d10_Out* out) {
    Unk_369950_Sound* sound = self->field_48->field_20;
    if (sound->field_11c && sound->field_154_0 == 0) {
        out->field_0 = Unk_369d10_Clamp(sound->field_110 * 0.01f);
        out->field_4 = Unk_369d10_Clamp(sound->field_114 * 0.01f);
        out->field_8 = 0.0f;
    } else {
        out->field_0 = 0.0f;
        out->field_4 = 0.0f;
        out->field_8 = 0.0f;
    }
}
