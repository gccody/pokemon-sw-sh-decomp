#pragma once
// The node class with two sets of children (vtables at 0x710237ff98, 0x168
// bytes): the root's children template, and a second array of children of its
// own class. Unk_237fbc0 derives from it. Placeholder names.
#include <nn/os.h>
#include "Unk_237c170.h"

// The class with the vtable at 0x7102382e40, 0x10 bytes (constructor
// 0x71003a45f0, destructor 0x71003a4610): the root's base at 0x30 is one too.
class Unk_2382e40 {
public:
    Unk_2382e40();
    ~Unk_2382e40();

    virtual void vf0();
    virtual void vf1();
    virtual void vf2();

    void* field_8;
};

struct Unk_237ff98_Item18 {
    u8 _0[0x18];
};

struct Unk_35c6b0;
void Unk_35c6b0_get(Unk_35c6b0* self);

struct Unk_237ff98_Item28 {
    u64 field_0;
    u8 field_8[0x18];  // an Unk_35c6b0
    f32 field_20;
};
PKMN_SIZE_ASSERT(Unk_237ff98_Item28, 0x28);

// The argument of slot 25 when the node calls it for itself.
struct Unk_237ff98_Arg25 {
    void* field_0;
    bool field_8;
};

struct Unk_237ff98_c8 {
    u32 field_0;
    bool field_4;
};

// What 0x7100352df0 fills in.
struct Unk_352df0_Out {
    f32 field_0;
    u8 _4[0x24];
    f32 field_28;
    f32 field_2c;
    f32 field_30;
    f32 field_34[12];
    u32 field_64[4];
    f32 field_74;
    f32 field_78;
    f32 field_7c;
    bool field_80;
};
PKMN_OFFSET_ASSERT(Unk_352df0_Out, field_64, 0x64);
PKMN_OFFSET_ASSERT(Unk_352df0_Out, field_80, 0x80);

class Unk_237ff98 : public Unk_NodeActiveParent<Unk_NodeParent<Unk_2382098>> {
public:
    // Both sets of children, the second set first.
    struct Iterator {
        Unk_NodeChildren* array;
        Unk_NodeA** item;

        Unk_2382098* operator*() const { return static_cast<Unk_2382098*>(*item); }
    };

    explicit Unk_237ff98(u32 id);  // 0x7100351840
    ~Unk_237ff98() override;  // 0x71003518d0

    // The slots this class overrides. Those not written yet have the
    // signature of their placeholder in Unk_NodeA.
    u32 vf10(Unk_2382098* child) override;
    u32 vf11(u32 id) override;
    void vf12(Unk_NodeA* child) override;
    void vf13(u32 id) override;
    u32 vf17() override { return 0; }  // 0x7100352000
    void vf19(Unk_NodeArg19* a1) override;
    void vf20(Unk_NodeArg19* a1) override;
    void vf22(void* a1, void* a2, u32 a3) override;
    void vf23(Unk_NodeArg23* a1) override;
    void vf25(void* a1, bool a2, f32 a3) override;
    void vf27(f32 a1, u32 a2, void* a3, void* a4) override;
    void vf29() override;
    void vf30(void* a1, void* a2, void* a3) override;
    void vf31(u32 a1, u32 a2, void* a3, void* a4) override;
    void vf33() override;
    void vf34(u32 a1) override;
    void vf35() override;
    void vf36() override;
    void vf37() override;
    void vf38() override;
    void vf41() override;
    void vf42() override;
    void vf43() override;
    void vf45() override;
    void vf47() override;
    void vf48(bool a1) override;
    void vf52() override;
    void vf55() override;
    void vf57() override;
    void vf58() override;
    void vf59() override;
    void vf60() override;
    void vf64() override;
    void vf65() override;
    void vf68() override;
    u32 p_vf0() override { return children.field_8 + field_b8.field_8; }  // 0x710034dc10
    u32 p_vf1(Unk_2382098* child) override;
    virtual void vf73();
    virtual void vf74();
    virtual void vf75();
    virtual void vf76();
    virtual void vf77();
    // Slots 78 to 80 are those of the base at 0x30.
    void c_vf0(u32 a1, Unk_NodeKey* a2, void* a3, f32 a4, f32 a5) override;
    void c_vf1(bool a1, u32 a2) override;
    void c_vf2(bool a1, u32 a2) override;

    void Unk_351b20();
    f32 Unk_352da0(u32 a1);
    u32 Unk_352df0(Unk_352df0_Out* out, Unk_NodeKey* key);
    f32 Unk_353010(Unk_NodeKey key, f32* out);
    f32 Unk_353330(Unk_NodeKey key, u32 prop);
    bool Unk_3536a0();

    Iterator Begin() {
        Iterator it;
        it.array = field_b8.field_8 != 0 ? &field_b8 : &children;
        it.item = it.array->field_0;
        return it;
    }
    bool IsEnd(const Iterator& it) { return it.item == it.array->field_0 + it.array->field_8; }
    void Next(Iterator& it) {
        ++it.item;
        if (IsEnd(it) && it.array != &children) {
            it.array = &children;
            it.item = children.field_0;
        }
    }

    void* field_b0;
    Unk_NodeChildren field_b8;  // the children of this class
    Unk_237ff98_c8 field_c8;
    f32 field_d0;
    Unk_List2<Unk_237ff98_Item18> field_d8;
    Unk_List2<Unk_237ff98_Item28> field_100;
    Unk_List2<Unk_237ff98_Item28> field_128;
    Unk_2382e40 field_150;
    u32 field_160;
    u8 field_164_0 : 4;
    u8 field_164_4 : 1;
    u8 field_164_5 : 1;
    u8 field_164_6 : 1;
    u8 field_164_7 : 1;
};
PKMN_SIZE_ASSERT(Unk_237ff98, 0x168);
PKMN_OFFSET_ASSERT(Unk_237ff98, field_d8, 0xd8);
PKMN_OFFSET_ASSERT(Unk_237ff98, field_150, 0x150);

// The nodes of this class (0x71024bcaa8), and those with field_164_6 set
// (0x71024bca98, under the lock at 0x71024bcac0).
extern Unk_Array<Unk_237ff98*> Unk_24bcaa8;
extern Unk_Array<Unk_237ff98*> Unk_24bca98;
extern nn::os::MutexType Unk_24bcac0;
extern nn::os::MutexType Unk_24bbc90;
extern bool Unk_24bcab9;
