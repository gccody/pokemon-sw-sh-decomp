// Scope: common
//
// What makes Unk_23c9ec8's reference (src/unsorted/Unk_ada660.h), and slots
// of Unk_23c9ff0 (vtable 0x71023c9ff0), a class on Unk_23c9470 declared as
// in src/unsorted/virtual/Unk_adc7d0.cpp, which has its key function
// (vf_type). Placeholder names: rename once the classes are known.
#include "unsorted/Unk_2771620.h"
#include "unsorted/Unk_ada660.h"

struct Unk_ace0c0;
void Unk_ace0c0_call(Unk_ace0c0* self);

void Unk_ec3340(Unk_23bf428* self, const Unk_ec3340_Name& name, bool arg2, bool arg3);

// Unk_23f4660's member at +0x100 (Unk_23f4760) is opaque in its header: the
// reference it holds at +0x1b0 (Unk_23f4660's +0x2b0).
struct Unk_23f4760_View {
    void* vptr;
    u8 _8[0x1a8];
    Unk_239a418* field_1b0;
};
PKMN_OFFSET_ASSERT(Unk_23f4760_View, field_1b0, 0x1b0);

// 0x7100adaea0
// NON_MATCHING: scheduling: the store of field_10's reference after its add
// (at +0x94 in the original) sinks to just before field_0's store.
void Unk_23c9ec8::Unk_adaea0(const Unk_ec3340_Name& name) {
    Unk_2443e50_Desc desc;
    desc.field_8 = Unk_239a418_Ref<Unk_239a418>(
        reinterpret_cast<const Unk_23f4760_View*>(&field_100)->field_1b0);
    desc.field_10 = Unk_239a418_Ref<Unk_239a418>(field_5e0);
    desc.field_0 = field_8;
    desc.field_20[0] = 0x243241e1fbeefbd8;
    desc.field_20[1] = 0x243242e1fbeefd8b;
    desc.field_20[2] = 0x243243e1fbeeff3e;
    desc.field_20[3] = 0x243244e1fbef00f1;
    desc.field_20[4] = 0x243245e1fbef02a4;
    desc.field_20[5] = 0xdf290e6647987eef;
    desc.field_20[6] = 0xdf290d6647987d3c;
    desc.field_58 = name;

    Unk_239a418_Allocator* allocator = field_8;
    Unk_2443e50* object;
    {
        Unk_2771620_Scope scope(allocator);
        void* p = allocator->vf2(sizeof(Unk_2443e50), alignof(Unk_2443e50));
        if (p == nullptr)
            allocator->vf23();
        object = ::new (p) Unk_2443e50(desc);
        object->field_8 = allocator;
        object->field_10 = reinterpret_cast<u64>(object);
        object->field_18 = sizeof(Unk_2443e50);
        object->field_20 = alignof(Unk_2443e50);
    }
    field_848 = Unk_8c6550_Ref<Unk_2443e50>(object);
}

class Unk_23c9ff0 : public Unk_23c9470 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23c9470::Unk_GetType());
        return &type;
    }

    const Unk_239a418_Type* vf_type() override;
    void vf8() override;
    void vf15() override;
    void vf17() override;
    u32 vf18() override;
    void vf19() override;
};

// 0x7100adb130
void Unk_23c9ff0::vf8() {
    Unk_23c9470::vf8();
    Unk_ec3340(field_610.get(), Unk_ec3340_Name("L_license_btlteam_00"), false, false);
    field_630->field_58 &= ~1;
}

// 0x7100adb1c0
void Unk_23c9ff0::vf17() {
    if ((field_630->field_58 & 1) == 0) {
        field_630->field_58 |= 1;
        Unk_ace0c0_call(reinterpret_cast<Unk_ace0c0*>(this));
    }
}
