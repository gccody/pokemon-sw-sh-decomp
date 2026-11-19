// Scope: common
//
// A class on gflib3's reference-counted object (vtable 0x7102433ac0): a
// holder (Unk_236d3d8) it owns, words, a list and three references. Its
// destructor is its key function: its vtable and thunks are emitted here.
// Placeholder names: rename once the classes are known.
#include <memory>

#include "unsorted/Unk_236d3d8.h"
#include "unsorted/Unk_23f4660.h"
#include "unsorted/Unk_2438308.h"

struct Unk_2433ac0_Node {
    Unk_2433ac0_Node* m_next;
    u64 field_8;
    u64 field_10;
    u64 field_18;
    u64 field_20;
    u64 field_28;
    Unk_239a418_Ref<Unk_239a418> field_30;
    u64 field_38;
    u64 field_40;
    u64 field_48;
    Unk_239a418_Ref<Unk_239a418> field_50;
};
static_assert(sizeof(Unk_2433ac0_Node) == 0x58, "Unk_2433ac0_Node");

class Unk_2433ac0 : public Unk_239a418 {
public:
    ~Unk_2433ac0() override;
    const Unk_239a418_Type* vf_type() override;

    std::unique_ptr<Unk_236d3d8, Unk_23f4660_Deleter> field_60;
    Unk_2438308_Words<u64> field_80;
    u64 field_98;
    u64 field_a0;
    Unk_2438308_List<Unk_2433ac0_Node> field_a8;
    u64 field_b8;
    u64 field_c0;
    u64 field_c8;
    u64 field_d0;
    u64 field_d8;
    u64 field_e0;
    u64 field_e8;
    Unk_239a418_Ref<Unk_239a418> field_f0;
    u64 field_f8;
    u64 field_100;
    u64 field_108;
    Unk_239a418_Ref<Unk_239a418> field_110;
    u64 field_118;
    u64 field_120;
    u64 field_128;
    Unk_239a418_Ref<Unk_239a418> field_130;
};
static_assert(sizeof(Unk_2433ac0) == 0x138, "Unk_2433ac0");
static_assert(__builtin_offsetof(Unk_2433ac0, field_a8) == 0xa8, "Unk_2433ac0::field_a8");
static_assert(__builtin_offsetof(Unk_2433ac0, field_130) == 0x130, "Unk_2433ac0::field_130");

// 0x71013a1e10, its D0 and thunks for +0x48 and +0x50
Unk_2433ac0::~Unk_2433ac0() {}
