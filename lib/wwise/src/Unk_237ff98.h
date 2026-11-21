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

// An item of the list at 0xd8: another node of the class and what to do to it.
struct Unk_237ff98_Item18 {
    u32 field_0;  // the node's ID
    f32 field_4;
    u32 field_8;
    u32 field_c;
    u32 field_10;
    u32 field_14;
};
PKMN_SIZE_ASSERT(Unk_237ff98_Item18, 0x18);

struct Unk_35c6b0;
void Unk_35c6b0_get(Unk_35c6b0* self);

// What an item of the lists at 0x100 and 0x128 has at 8: an object that is
// told a value.
struct Unk_237ff98_Item28_8 {
    virtual void vf0(u32 a1, bool a2, f32 a3);

    u64 field_8;
};

// An item of the lists at 0x100 and 0x128: what another node of the class
// (field_0, its ID) does to this one's value.
struct Unk_237ff98_Item28 {
    // The object as its users see it: a pointer, so that the call is virtual.
    Unk_237ff98_Item28_8* User() { return &field_8; }

    u32 field_0;
    Unk_237ff98_Item28_8 field_8;  // an Unk_35c6b0
    void* field_18;  // what changes the value over time
    f32 field_20;  // the value
    bool field_24;
};
PKMN_SIZE_ASSERT(Unk_237ff98_Item28, 0x28);

// The argument of slot 25 when the node calls it for itself.
struct Unk_237ff98_Arg25 {
    void* field_0;
    bool field_8;
};

// A channel configuration: the number of channels, the kind of configuration
// and, for kind 1, a bit for each channel.
struct Unk_237ff98_Config {
    u32 field_0_0 : 8;
    u32 field_0_8 : 4;
    u32 field_0_12 : 20;
};

struct Unk_237ff98_c8 {
    u32 field_0;
    Unk_237ff98_Config field_4;
};

// What says whose parameter a notification is about.
struct Unk_NodeTarget {
    Unk_NodeC* field_0;
    void* field_8;
    u32 field_10;
    u32 field_14;
};

// What field_b0 points at: 0xc bytes.
struct Unk_237ff98_b0 {
    Unk_237ff98_b0() : field_0(0), field_4(0), field_9(true) {}

    s32 field_0;
    u32 field_4;
    u8 field_8;
    bool field_9;
};
PKMN_SIZE_ASSERT(Unk_237ff98_b0, 0xc);

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

void Unk_3be290(void* self, void* change, u64 prop, u32 a3, u32 a4, bool a5, f32 a6);
extern void* Unk_24bbbe8;

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
    u32 vf11(Unk_NodeId id) override;
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
    Unk_2382098* vf33() override;
    void vf34(u32 a1) override;
    u32 vf35(Unk_NodeArg35* a1, bool a2, bool a3) override;
    void vf36(void* a1) override;
    bool vf37(bool a1) override;
    void vf38(bool a1) override;
    void vf41(void* a1, void* a2, bool a3) override;
    void vf42() override;
    void vf43(f32 a1, u32 a2, void* a3, u32 a4, u32 a5, u32 a6) override;
    void vf45(void* a1, u32 a2, u32 a3) override;
    void vf47(u32 a1, u32 a2) override;
    void vf48(bool a1) override;
    void vf52() override;
    u32 vf55(u32 a1, bool a2, s32 a3) override;
    void vf57() override;
    void vf58() override;
    void vf59() override;
    void vf60() override;
    void vf64() override;
    u32 vf65(u8*& data) override;
    void* vf68(void* a1) override;
    u32 p_vf0() override { return children.field_8 + field_b8.field_8; }  // 0x710034dc10
    u32 p_vf1(Unk_2382098* child) override;
    // Slots 73 to 76 are those of the base at 0x18.
    void b_vf6(u32 a1, void* a2, bool a3) override;
    void* b_vf12(u32 a1, bool a2) override;
    void b_vf11(u32 a1, bool a2) override;
    u32 b_vf13(u32 a1, void* a2, void* a3) override;
    virtual void vf77();
    // Slots 78 to 80 are those of the base at 0x30.
    void c_vf0(u32 a1, Unk_NodeKey* a2, void* a3, f32 a4, f32 a5) override;
    void c_vf1(bool a1, u32 a2) override;
    void c_vf2(bool a1, u32 a2) override;

    void Unk_351b20();

    // Tells the node (slot 25) the value of its property 0xb, or `value`.
    void Unk_351b20_Tell(f32 value) {
        Unk_237ff98_Arg25 arg;
        arg.field_8 = true;
        arg.field_0 = this;
        if (field_50 != nullptr) {
            Unk_PropValue16* prop = field_50->field_18.FindProp(0xb);
            if (prop != nullptr)
                value = prop->field_0;
        }
        vf25(&arg, true, value);
    }
    f32 Unk_352da0(u32 a1);
    u32 Unk_352df0(Unk_352df0_Out* out, Unk_NodeKey* key);
    f32 Unk_353010(Unk_NodeKey key, f32* out);
    f32 Unk_353330(Unk_NodeKey key, u32 prop);
    bool Unk_3536a0();
    void Unk_355510(u32 id, u32 a2, u32 a3, u32 prop);
    void Unk_3552e0(u32 id, f32 a2, u32 a3, u32 a4, u32 a5);
    void Unk_355640();
    bool Unk_356720(u32 a1, void* a2);
    u32 Unk_357310();
    void Unk_357370(f32* value);
    void Unk_357650(u32 a1);
    void Unk_355690(u32 id);

    // Ends what the item does to the value of `prop`.
    void Unk_355690_End(Unk_237ff98_Item28& item, u32 prop) {
        f32 value = item.field_20;
        void* change = item.field_18;
        item.field_24 = false;
        if (change != nullptr)
            Unk_3be290(Unk_24bbbe8, change, prop, 0, 4, true, value);
        else
            item.User()->vf0(prop, true, value);
    }
    u32 Unk_355880();
    void Unk_355c10(Unk_237ff98_Config config);

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

    Unk_237ff98_b0* field_b0;
    Unk_NodeChildren field_b8;  // the children of this class
    Unk_237ff98_c8 field_c8;
    f32 field_d0;
    Unk_List2<Unk_237ff98_Item18> field_d8;
    Unk_List2<Unk_237ff98_Item28> field_100;
    Unk_List2<Unk_237ff98_Item28> field_128;
    Unk_2382e40 field_150;
    u32 field_160;
    u8 field_164_0 : 3;
    u8 field_164_3 : 1;
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
extern bool Unk_24bcab8;
