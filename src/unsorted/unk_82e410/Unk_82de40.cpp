// Scope: common
// Unk_23ace78's functions (the TU of 0x710082de40-0x710082dfe0), see
// Handler.h.
#include "unsorted/unk_82e410/Handler.h"

struct Unk_7ee6b0;
struct Unk_813270;
void Unk_812ee0(Unk_813270* self);
void Unk_812f00_add(Unk_813270* self, const Unk_7ee6b0* item);

// What Unk_82a790 (Unk_23acc78's) takes.
struct Unk_82a790_Arg {
    Unk_813270* field_0;
};
void Unk_82a790(Unk_23acc78* self, Unk_23acc98_Result& result, const Unk_82a790_Arg& arg);

// What Unk_82de70 takes.
struct Unk_82de70_Arg {
    Unk_813270* field_0;
};

// 0x710082dec0
void Unk_82dec0(Unk_23ace78* self, Unk_813270* list) {
    Unk_812ee0(list);
    void* poke;
    Unk_804200_Iterator it;
    Unk_804200(&it, Unk_23acc98_Field8(self), Unk_23acc98_Field10(self));
    while (Unk_804480(&it, &poke))
        Unk_812f00_add(list, static_cast<const Unk_7ee6b0*>(poke));
}

// 0x710082de70
void Unk_82de70(Unk_23ace78* self, Unk_23acc98_Result& /*result*/, const Unk_82de70_Arg& arg) {
    Unk_82dec0(self, arg.field_0);
    Unk_82a790_Arg next;
    next.field_0 = arg.field_0;
    Unk_23acc98_Result result;
    Unk_82a790(Unk_7e0080_Get18c0(Unk_23acc98_Holder(self)), result, next);
}
