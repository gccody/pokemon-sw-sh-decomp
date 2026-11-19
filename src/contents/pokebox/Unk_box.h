#pragma once
// The box app (prog/contents/pokebox: common/box.dat, bin/appli/pokebox):
// what its states use. Placeholder names: rename them once the classes are
// known.
#include <types.h>

#include "contents/common/framework.h"

// tools/leafgen.py's placeholders for accessors of the box's classes: the
// classes below forward to them.
struct Unk_aab1b0;
bool Unk_aab1b0_getField620(const Unk_aab1b0* self);
struct Unk_aab8b0;
bool Unk_aab8b0_getField60c(const Unk_aab8b0* self);
struct Unk_aa89f0;
void Unk_aa89f0_call(const Unk_aa89f0* self);
struct Unk_aa3130;
u32 Unk_aa3130_call(const Unk_aa3130* self);
struct Unk_aa6650;
bool Unk_aa6650_check(const Unk_aa6650* self);
struct Unk_e807f0;
void Unk_e807f0_call(Unk_e807f0* self, bool value);
struct Unk_a96b10;
void Unk_a96b10_call(const Unk_a96b10* self);
struct Unk_aa75b0;
bool Unk_aa75b0_check(const Unk_aa75b0* self);
struct Unk_a96b30;
void Unk_a96b30_clearField608(Unk_a96b30* self);
struct Unk_aab2c0;
void Unk_aab2c0_set(Unk_aab2c0* self, bool value);
struct Unk_a77140;
u32 Unk_a77140_getField68(const Unk_a77140* self);
struct Unk_aa5440;
u32 Unk_aa5440_getField688(const Unk_aa5440* self);
struct Unk_aa4660;
u8 Unk_aa4660_getField681(const Unk_aa4660* self);
struct Unk_a94040;
u32 Unk_a94040_getField614(const Unk_a94040* self);
struct Unk_a96be0;
u32 Unk_a96be0_getField618(const Unk_a96be0* self);
struct Unk_a775f0;
void Unk_a775f0_call(const Unk_a775f0* self, bool value);
struct Unk_a8b810;
void Unk_a8b810_clearField5cc(Unk_a8b810* self);
void Unk_a8b7c0_call(void* self);
void Unk_a8b7d0_call(void* self);
struct Unk_a77150;
void Unk_a77150_setField64(Unk_a77150* self, u32 value);
struct Unk_a77160;
struct Unk_a77790;
void Unk_a77790_setFieldb0(Unk_a77790* self, u64 value);
u64 Unk_a77160_getField70(const Unk_a77160* self);
void Unk_a77610(void*, u64);

// The box's top view (vtable 0x71023c81e8, type 0x71027d7078: "View_Top").
class Unk_23c81e8 : public Unk_23f4660 {
public:
    // Its copy out of line is 0x7100a7e740 (tools/leafgen.py named it as a
    // function of the view's vf_type, which tail-calls it).
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23f4660::Unk_GetType());
        return &type;
    }

    void Unk_aa68c0();
    bool Unk_aa6f70();
    void Unk_aa70c0();
    bool Unk_aa74f0();
    bool Unk_aa8a00();
    void Unk_a96a70();
    void Unk_a96aa0();
    bool Unk_aa9920();
    bool Unk_aa9ba0(u32* state);
    u64 Unk_aab510();
    void Unk_aa3140();
    void Unk_aa4680(u32 arg1, bool arg2);
    bool Unk_aa6570();
    void Unk_aa6660();
    bool Unk_aa66e0();
    void Unk_aa59e0();
    bool Unk_aa5b30();
    Unk_239a418_Ref<Unk_239a418> Unk_aa5350();
    bool Unk_aa5c80();
    bool Unk_aa5e60();
    void Unk_aa5eb0();
    void Unk_aa50d0(bool value);
    void Unk_a96900();
    void Unk_a9bb00();
    void Unk_a94fd0(bool value);
    bool Unk_a99ce0();
    bool Unk_a99f70();
    bool Unk_a9adf0();
    bool Unk_a9aeb0();
    bool Unk_a9b100();
    bool Unk_a9b5f0();
    bool Unk_a9b6b0();
    bool Unk_a9b9c0();
    void Unk_aa7fd0();
    bool Unk_aa81f0();
    bool Unk_aaa5d0();
    void Unk_a94960(bool value);
    void Unk_aaaf10(u32* arg1, u32* arg2, u32* arg3);
    u64 Unk_aab420();
    void Unk_a95770(bool value);
    void Unk_a99330(bool value);
    u64 Unk_aab8c0();

    bool Unk_GetField620() const {
        return Unk_aab1b0_getField620(reinterpret_cast<const Unk_aab1b0*>(this));
    }
    bool Unk_GetField60c() const {
        return Unk_aab8b0_getField60c(reinterpret_cast<const Unk_aab8b0*>(this));
    }
    void Unk_CallAa89f0() const { Unk_aa89f0_call(reinterpret_cast<const Unk_aa89f0*>(this)); }
    u32 Unk_CallAa3130() const {
        return Unk_aa3130_call(reinterpret_cast<const Unk_aa3130*>(this));
    }
    bool Unk_CheckAa6650() const {
        return Unk_aa6650_check(reinterpret_cast<const Unk_aa6650*>(this));
    }
    void Unk_CallE807f0(bool value) { Unk_e807f0_call(reinterpret_cast<Unk_e807f0*>(this), value); }
    void Unk_CallA96b10() const { Unk_a96b10_call(reinterpret_cast<const Unk_a96b10*>(this)); }
    bool Unk_CheckAa75b0() const {
        return Unk_aa75b0_check(reinterpret_cast<const Unk_aa75b0*>(this));
    }
    u32 Unk_GetField688() const {
        return Unk_aa5440_getField688(reinterpret_cast<const Unk_aa5440*>(this));
    }
    bool Unk_GetField681() const {
        return Unk_aa4660_getField681(reinterpret_cast<const Unk_aa4660*>(this)) & 1;
    }
    u32 Unk_GetField614() const {
        return Unk_a94040_getField614(reinterpret_cast<const Unk_a94040*>(this));
    }
    u32 Unk_GetField618() const {
        return Unk_a96be0_getField618(reinterpret_cast<const Unk_a96be0*>(this));
    }
    void Unk_ClearField608() { Unk_a96b30_clearField608(reinterpret_cast<Unk_a96b30*>(this)); }
    void Unk_SetAab2c0(bool value) { Unk_aab2c0_set(reinterpret_cast<Unk_aab2c0*>(this), value); }
};

void Unk_a96ad0_call(void* self);
void Unk_a96ae0_call(void* self);
void Unk_a8c930_call(void* self);
void Unk_a8c940_call(void* self);

// The box's search view (vtable 0x71023c7ed0: "View_Search"). Its getter's
// copy out of line is 0x7100a91120.
class Unk_23c7ed0 : public Unk_23f4660 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23f4660::Unk_GetType());
        return &type;
    }

    void Unk_a8c870();
    void Unk_a8c8d0();
    void Unk_a8ca80();
};

void Unk_ab3ab0_call(void* self);
void Unk_ab3ac0_call(void* self);

// The box's wallpaper view (vtable 0x71023c8530: "View_Wallpaper").
class Unk_23c8530 : public Unk_23f4660 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23f4660::Unk_GetType());
        return &type;
    }

    void Unk_ab3760();
    void Unk_ab3b10();
};

// The box's model view (vtable 0x71023c7dd0: "View_Model").
class Unk_23c7dd0 : public Unk_23f4660 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23f4660::Unk_GetType());
        return &type;
    }

    void Unk_a8b790();
    u64 Unk_a8b820();
    void Unk_ClearField5cc() { Unk_a8b810_clearField5cc(reinterpret_cast<Unk_a8b810*>(this)); }
};

// The box app's data (its field_70).
struct Unk_23c63c8_Data {
    u32 field_0;
    u8 _4[0x12 - 0x4];
    bool field_12;
    u8 _13[0x4c - 0x13];
    u32 field_4c;
    u16 field_50;
    u16 field_52;
    u8 _54[0x188 - 0x54];
    // Flags the app's functions test and clear (Unk_23c63c8::Unk_a77470).
    bool field_188[9];
    u8 _191[0x19c - 0x191];
    u32 field_19c;
    bool field_1a0;
    u32 field_1a4;
};
static_assert(__builtin_offsetof(Unk_23c63c8_Data, field_1a4) == 0x1a4, "Unk_23c63c8_Data");

// The box app (vtable 0x71023c63c8): the states get it from their field_68.
class Unk_23c63c8 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType();  // 0x7100a7a700

    bool Unk_a77470(u32 flag) const;
    void Unk_a774a0(u32 flag);

    u32 Unk_GetField68() const {
        return Unk_a77140_getField68(reinterpret_cast<const Unk_a77140*>(this));
    }
    void Unk_CallA775f0(bool value) const {
        Unk_a775f0_call(reinterpret_cast<const Unk_a775f0*>(this), value);
    }
    // The state to go to next.
    void Unk_SetField64(u32 value) {
        Unk_a77150_setField64(reinterpret_cast<Unk_a77150*>(this), value);
    }
    void Unk_SetFieldB0(u64 value) {
        Unk_a77790_setFieldb0(reinterpret_cast<Unk_a77790*>(this), value);
    }
    // Its tips (0x7100a777a0).
    Unk_239a418_Ref<Unk_239a418> Unk_a777a0() const;
    Unk_23c63c8_Data* Unk_GetField70() const {
        return reinterpret_cast<Unk_23c63c8_Data*>(
            Unk_a77160_getField70(reinterpret_cast<const Unk_a77160*>(this)));
    }

    u8 _60[0x70 - 0x60];
    Unk_23c63c8_Data* field_70;
};

// A state's app, or null.
inline Unk_23c63c8* Unk_BoxApp(Unk_23f43c8* state) {
    return Unk_DynamicCast<Unk_23c63c8>(Unk_HandleObject(state->field_68));
}

// A state's top view.
inline Unk_23c81e8* Unk_BoxTopView(Unk_23f43c8* state) {
    return Unk_StateView<Unk_23c81e8>(state, "View_Top");
}
