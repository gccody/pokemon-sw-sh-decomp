#pragma once
// The message board views (their layouts are msg_kanban_00.bflyt,
// msg_sys_00.bflyt and msg_sys_03.bflyt): classes on Unk_2441f08 (vtable
// 0x7102441f18, game/trainer_license), a view on gflib3's reference-counted
// object that drives a layout (+0xc0) through its animations. Placeholder
// names: rename once the classes are known.
//
// Unk_24428a8 (vtable 0x71024428b8) derives from it directly. Unk_2442a00
// (vtable 0x7102442a10) and Unk_2442b78 (vtable 0x7102442b88) derive from
// Unk_27e0b00, named after its type (0x71027e0b00, the parent of both their
// types): the two vtables share its slots 13, 16, 18-21 and 24-26 and its
// interface's overrides. It has no vtable of its own in the executable.
#include <types.h>

#include "gflib3/Unk_239a418.h"
#include "unsorted/Unk_23f4660.h"

// A pane of the layout: bit 0 of +0x58 shows it.
struct Unk_14b6680_Pane {
    u8 _0[0x58];
    u8 field_58;
};
PKMN_OFFSET_ASSERT(Unk_14b6680_Pane, field_58, 0x58);

// gflib3's layout (placeholders: the signatures are what the calls pass).
struct Unk_685250;
// The pane of that name (a leaf, src/unsorted/leaf/Unk_67bdb0.cpp: its name
// takes the name as a u64).
Unk_14b6680_Pane* Unk_685250_call(const Unk_685250* layout, u64 name);
void Unk_6855a0(void* layout, u32 index, const char* name, bool arg);
void* Unk_685360(void* layout, const char* name);
void Unk_6856d0(void* layout, void* pane, u32 index, const char* name, bool arg);
void Unk_6859b0(void* layout, u64 index);
bool Unk_685a50(void* layout, u32 index);
bool Unk_685c60(u64 layout, u32 index);

// A name for a file path (0x7100c46830).
Unk_23f4660_Name Unk_c46830(const char* const& path);

// The interface at +0x60 (vtable 0x7102442048): its own versions return 0
// and do nothing. Named after the primary vtable's slots its overrides get.
class Unk_2442038 {
public:
    virtual u32 vf24();
    virtual void vf25(bool value);
    virtual bool vf26();
};

class Unk_2441f08 : public Unk_239a418, public Unk_2442038 {
public:
    // 0x71014a7eb0
    explicit Unk_2441f08(void* arg);
    // 0x71014a7fd0
    ~Unk_2441f08() override;
    const Unk_239a418_Type* vf_type() override;
    virtual void vf7();
    virtual void vf8(u32 state) = 0;
    virtual u32 vf9();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual bool vf13() = 0;
    virtual void vf14();
    virtual u32 vf15();
    // 0x71014a9370
    virtual void vf16();
    virtual void vf17() = 0;
    virtual void vf18() = 0;
    virtual void vf19() = 0;
    virtual void vf20() = 0;
    virtual void vf21() = 0;
    virtual u32 vf22() = 0;

    u8 _68[0xc0 - 0x68];
    void* field_c0;
    u8 _c8[0x380 - 0xc8];
    u32 field_380;
};
PKMN_OFFSET_ASSERT(Unk_2441f08, field_c0, 0xc0);
PKMN_OFFSET_ASSERT(Unk_2441f08, field_380, 0x380);

// What it does with the layout (placeholders, over the view): sets its
// layout file up (0x71014a82b0), plays an animation (0x71014a94a0), stops
// one (0x71014a9520).
void Unk_14a82b0(void* self,
                 u64 arg,
                 Unk_239a418_Ref<Unk_239a418> parent,
                 const Unk_23f4660_Name& file,
                 const char* layout,
                 bool flag);
void Unk_14a94a0(void* self, u32 index, f32 frame, bool arg2, bool arg3);
void Unk_14a9520(void* self, u32 index);
// A leaf (src/unsorted/leaf/Unk_1489740.cpp): stops an animation.
struct Unk_14a9570;
void Unk_14a9570_call(const Unk_14a9570* self, u64 index);

// Final: its slot 8 is inlined into 0x71014b6680.
class Unk_24428a8 final : public Unk_2441f08 {
public:
    void Unk_14b6680(u32 state, u64 arg, const Unk_239a418_Ref<Unk_239a418>& parent);

    ~Unk_24428a8() override;
    const Unk_239a418_Type* vf_type() override;
    void vf8(u32 state) override;
    bool vf13() override;
    void vf17() override;
    void vf18() override;
    void vf19() override;
    void vf20() override;
    void vf21() override;
    u32 vf22() override;
};

class Unk_27e0b00 : public Unk_2441f08 {
public:
    explicit Unk_27e0b00(void* arg)
        : Unk_2441f08(arg), field_384(false), field_388(nullptr), field_390(false) {}

    bool vf13() override;
    void vf16() override;
    void vf18() override;
    void vf19() override;
    void vf20() override;
    void vf21() override;
    // The animation for a state.
    virtual u32 vf23(u32 state) = 0;
    u32 vf24() override;
    void vf25(bool value) override;
    bool vf26() override;

    bool field_384;
    Unk_14b6680_Pane* field_388;
    bool field_390;
};
PKMN_OFFSET_ASSERT(Unk_27e0b00, field_384, 0x384);
PKMN_OFFSET_ASSERT(Unk_27e0b00, field_388, 0x388);
PKMN_OFFSET_ASSERT(Unk_27e0b00, field_390, 0x390);

class Unk_2442a00 : public Unk_27e0b00 {
public:
    explicit Unk_2442a00(void* arg);
    ~Unk_2442a00() override;

    void Unk_14b6f40(u32 state, u32 kind, u64 arg, const Unk_239a418_Ref<Unk_239a418>& parent);

    const Unk_239a418_Type* vf_type() override;
    void vf8(u32 state) override;
    void vf17() override;
    u32 vf22() override;
    u32 vf23(u32 state) override;

    u32 field_394;
};
PKMN_OFFSET_ASSERT(Unk_2442a00, field_394, 0x394);
