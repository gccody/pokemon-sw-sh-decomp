// Scope: common
// Unk_23acfd8's functions (the TU of 0x7100830050-0x7100830560). Its first,
// 0x7100830080, calls 0x710082ad60, whose leaf placeholder takes too few
// parameters.
#include "unsorted/unk_82e410/Handler.h"

struct Unk_7ee6b0;
struct Unk_82b0e0;
struct Unk_82ccb0;
struct Unk_812e20;
u8 Unk_7ee6b0_getField7d(const Unk_7ee6b0* self);
bool Unk_82b0e0_check(const Unk_82b0e0* self);
u8 Unk_82ccb0_getFieldb48(const Unk_82ccb0* self);
bool Unk_812e20_getFielda(const Unk_812e20* self);
s32 Unk_7eef50(void* self, u32 index);

// An entry of what field_8.field_0[8] holds (0x710082ce80 returns one)
struct Unk_830320_Entry {
    void* field_0;
};
Unk_830320_Entry* Unk_82ce80(void* self, u32 index);
struct Unk_82d7e0_Arg;
u32 Unk_82d7e0(const Unk_82d7e0_Arg* self);
bool Unk_8124b0(void* self, u8 id, u32 value, s32 arg3);
struct Unk_804630_Flow;
void Unk_80b430(Unk_804630_Flow* self, const Unk_7ee6b0* object, u32 value);
void Unk_812520(void* self, u8 id, u32 value);
void Unk_830e20(void* self, Unk_82aa30_Data* data, u8* arg2);

static u8 Unk_830320_Count(Unk_23acfd8* self) {
    return Unk_82ccb0_getFieldb48(static_cast<const Unk_82ccb0*>(Unk_23acc98_Field48(self)));
}

// 0x7100830320
void Unk_830320(Unk_23acfd8* self) {
    for (u32 i = 0; i < Unk_830320_Count(self); i++) {
        Unk_830320_Entry* entry = Unk_82ce80(Unk_23acc98_Field48(self), i);
        u32 value = Unk_82d7e0(reinterpret_cast<const Unk_82d7e0_Arg*>(entry));
        if (!value)
            continue;
        void* object = entry->field_0;
        u8 id = Unk_7ee6b0_getField7d(static_cast<const Unk_7ee6b0*>(object));
        void* target = Unk_23acc98_Field20(self);
        if (Unk_8124b0(target, id, value, Unk_7eef50(object, 0xc))) {
            Unk_80b430(static_cast<Unk_804630_Flow*>(Unk_23acc98_Field38(self)),
                       static_cast<const Unk_7ee6b0*>(object), value);
            Unk_812520(Unk_23acc98_Field20(self), id, value);
        }
    }
}

// 0x7100830400
void Unk_830400(Unk_23acfd8* self, void* object, const Unk_830400_Arg& arg, u8 flag) {
    if (!Unk_82b0e0_check(reinterpret_cast<const Unk_82b0e0*>(Unk_23acc98_Data(self))))
        return;
    Unk_82aa30_Data* data = Unk_23acc98_Data(self);
    u8* data2 = Unk_23acc98_Data(self)->field_10;
    data->field_c = Unk_7ee6b0_getField7d(static_cast<const Unk_7ee6b0*>(object));
    data->field_8 = arg.field_0;
    data->field_d = flag;
    data->field_e = arg.field_0 == 0x90 ||
                    !Unk_812e20_getFielda(
                        reinterpret_cast<const Unk_812e20*>(Unk_23acc98_Data(self)->field_10));
    Unk_830e20(Unk_23acc98_Field28(self), data, data2);
}
