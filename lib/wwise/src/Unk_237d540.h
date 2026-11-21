#pragma once
// A base class of the sound engine's nodes (vtables at 0x710237d540): three
// vtables of 83, 17 and 3 slots, at 0, 0x18 and 0x30. Its own bases aren't
// reconstructed: Unk_NodeA, Unk_NodeB and Unk_NodeC only give the vtables their
// shape. Placeholder names.
#include <types.h>

#define UNK_VF10(p)                                                                              \
    virtual void vf##p##0();                                                                     \
    virtual void vf##p##1();                                                                     \
    virtual void vf##p##2();                                                                     \
    virtual void vf##p##3();                                                                     \
    virtual void vf##p##4();                                                                     \
    virtual void vf##p##5();                                                                     \
    virtual void vf##p##6();                                                                     \
    virtual void vf##p##7();                                                                     \
    virtual void vf##p##8();                                                                     \
    virtual void vf##p##9();

struct Unk_NodeA {
    virtual ~Unk_NodeA();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    UNK_VF10(1)
    UNK_VF10(2)
    UNK_VF10(3)
    UNK_VF10(4)
    UNK_VF10(5)
    UNK_VF10(6)
    UNK_VF10(7)
    virtual void vf80();
    virtual void vf81();
    virtual void vf82();

    void* field_8;  // next in the index's hash chain
    u32 field_10;  // ID
    u32 field_14;  // reference count
};

struct Unk_NodeB {
    virtual ~Unk_NodeB();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
    virtual void vf14();
    virtual void vf15();
    virtual void vf16();

    u64 field_8;
    u64 field_10;
};

struct Unk_NodeC {
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

class Unk_237d540 : public Unk_NodeA, public Unk_NodeB, public Unk_NodeC {
public:
    explicit Unk_237d540(u32 id);  // 0x71003150a0
    ~Unk_237d540() override;  // 0x71003150f0

    u8 _38[0x64];
    u32 field_9c;  // flags
    u8 _a0[0x48];
    u64 field_e8;
    u64 field_f0;
};
PKMN_SIZE_ASSERT(Unk_237d540, 0xf8);
PKMN_OFFSET_ASSERT(Unk_237d540, field_9c, 0x9c);
