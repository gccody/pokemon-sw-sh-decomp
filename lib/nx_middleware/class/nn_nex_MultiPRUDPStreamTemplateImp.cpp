// Scope: common
// Small virtual functions of a library class (tools/leafgen.py members): placeholder
// member names vf<slot>, placeholder structs. The class's name is its RTTI's.
// RTTI: N2nn3nex27MultiPRUDPStreamTemplateImpE
#include <types.h>

struct Unk_160a9a0_10 {
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

struct Unk_160a9a0 {
    u8 _0[0x10];
    Unk_160a9a0_10* field_10;
};
PKMN_OFFSET_ASSERT(Unk_160a9a0, field_10, 0x10);

struct Unk_160a9b0_10 {
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3(u64, u64);
};

struct Unk_160a9b0 {
    u8 _0[0x10];
    Unk_160a9b0_10* field_10;
};
PKMN_OFFSET_ASSERT(Unk_160a9b0, field_10, 0x10);

struct Unk_160a9c0_10 {
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4(u64, u64, u64, u64);
};

struct Unk_160a9c0 {
    u8 _0[0x10];
    Unk_160a9c0_10* field_10;
};
PKMN_OFFSET_ASSERT(Unk_160a9c0, field_10, 0x10);

struct Unk_160a9f0_10 {
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6(u64, u64, u64, u64);
};

struct Unk_160a9f0 {
    u8 _0[0x10];
    Unk_160a9f0_10* field_10;
};
PKMN_OFFSET_ASSERT(Unk_160a9f0, field_10, 0x10);

struct Unk_1610050 {
    u8 _0[0x8];
    u32 field_8;
};
PKMN_OFFSET_ASSERT(Unk_1610050, field_8, 0x8);

namespace nn {
namespace nex {
class MultiPRUDPStreamTemplateImp {
public:
    void vf2();
    void vf3(u64 value, u64 arg2);
    void vf4(u64 value, u64 arg2, u64 arg3, u64 arg4);
    void vf6(u64 value, u64 arg2, u64 arg3, u64 arg4);
    u32 vf8();
};
}  // namespace nex
}  // namespace nn

// 0x710160a9a0
void nn::nex::MultiPRUDPStreamTemplateImp::vf2() {
    const Unk_160a9a0* self = reinterpret_cast<const Unk_160a9a0*>(this);
    self->field_10->vf2();
}

// 0x710160a9b0
void nn::nex::MultiPRUDPStreamTemplateImp::vf3(u64 value, u64 arg2) {
    const Unk_160a9b0* self = reinterpret_cast<const Unk_160a9b0*>(this);
    self->field_10->vf3(value, arg2);
}

// 0x710160a9c0
void nn::nex::MultiPRUDPStreamTemplateImp::vf4(u64 value, u64 arg2, u64 arg3, u64 arg4) {
    const Unk_160a9c0* self = reinterpret_cast<const Unk_160a9c0*>(this);
    self->field_10->vf4(value, arg2, arg3, arg4);
}

// 0x710160a9f0
void nn::nex::MultiPRUDPStreamTemplateImp::vf6(u64 value, u64 arg2, u64 arg3, u64 arg4) {
    const Unk_160a9f0* self = reinterpret_cast<const Unk_160a9f0*>(this);
    self->field_10->vf6(value, arg2, arg3, arg4);
}

// 0x7101610050
u32 nn::nex::MultiPRUDPStreamTemplateImp::vf8() {
    const Unk_1610050* self = reinterpret_cast<const Unk_1610050*>(this);
    return self->field_8;
}
