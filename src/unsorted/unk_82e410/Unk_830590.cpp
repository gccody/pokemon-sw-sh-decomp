// Scope: common
// Unk_23acff8's functions (the TU of 0x7100830560-0x7100830880).
#include "unsorted/unk_82e410/Handler.h"

struct Unk_7ee6b0;
struct Unk_7fe2a0;
struct Unk_803c60;
struct Unk_82d670;
u8 Unk_7ee6b0_getField7d(const Unk_7ee6b0* self);
void* Unk_7fe2a0_getField148(const Unk_7fe2a0* self);
void Unk_803c60_set(Unk_803c60* self);
void Unk_82d670_set(Unk_82d670* self);
s32 Unk_7eef50(void* self, u32 index);
bool Unk_7ef4c0(void* object, u32 index);
bool Unk_8124b0(void* self, u8 id, u32 value, s32 arg3);
void Unk_812570(void* self, u8 id, u32 value);
void Unk_812ec0(Unk_830590_Info* self);
void Unk_808230(void* self, void* object, void* arg2, u32 arg3);
void Unk_804ad0(void* self,
                u32 arg1,
                u32 arg2,
                u32 arg3,
                u32 arg4,
                void* object,
                Unk_830590_Value* value);
bool Unk_780c60(u32 id, u32 kind);
void Unk_80e920(void* self, void* object, u32 id, u32 arg3);
void Unk_8025a0(void* self, Unk_8306f0_Block* block);

// 0x7100830590
void Unk_830590(Unk_23acff8* self, Unk_23acc98_Result& /*result*/, const Unk_830590_Arg& arg) {
    if (!arg.field_0->field_0)
        return;
    Unk_842150_Arg a;
    Unk_23acc98_Result done;
    Unk_830590_Value value;
    Unk_830590_Info info;
    void* object = Unk_23acc98_Object(self, arg.field_0->field_1);
    void* arg2 = arg.field_8;
    u32 arg3 = arg.field_10;
    Unk_808230(Unk_23acc98_Field38(self), object, arg2, arg3);
    Unk_812ec0(&info);
    u32 n = arg.field_10;
    Unk_804ad0(Unk_23acc98_Field38(self), n, n, n, 0, object, &value);
    u8 kind = arg.field_0->field_6;
    a.field_11 = 0x1f;
    a.field_10 = kind;
    a.field_0 = object;
    a.field_8 = &value;
    a.field_18 = &info;
    Unk_842150(Unk_7e0080_Get1760(Unk_23acc98_Holder(self)), done, a);
    if (Unk_7ef4c0(object, 0xf) && Unk_780c60(value.field_0, 0xc))
        Unk_80e920(Unk_23acc98_Field20(self), object, value.field_0, 0xd);
    else if (Unk_7ef4c0(object, 0x18) && Unk_780c60(value.field_0, 8))
        Unk_80e920(Unk_23acc98_Field20(self), object, value.field_0, 0x21);
    else
        Unk_8306f0(self, object, &value, &info);
}

// 0x71008306f0
void Unk_8306f0(Unk_23acff8* self, void* object, Unk_830590_Value* value, Unk_830590_Info* info) {
    Unk_23acc98_Result done;
    Unk_8306f0_Block block;
    Unk_8308b0_Arg a;
    Unk_8124b0(Unk_23acc98_Field20(self),
               Unk_7ee6b0_getField7d(static_cast<const Unk_7ee6b0*>(object)), value->field_0,
               Unk_7eef50(object, 0xc));
    Unk_803c60_set(reinterpret_cast<Unk_803c60*>(&block.field_c));
    Unk_82d670_set(reinterpret_cast<Unk_82d670*>(&block));
    Unk_8025a0(Unk_7fe2a0_getField148(static_cast<const Unk_7fe2a0*>(Unk_23acc98_Field10(self))),
               &block);
    block.field_4 |= 2;
    a.field_0 = object;
    a.field_8 = &block;
    a.field_10 = value;
    a.field_18 = info;
    Unk_8308b0(Unk_7e0080_Get1b60(Unk_23acc98_Holder(self)), done, a);
    Unk_812570(Unk_23acc98_Field20(self),
               Unk_7ee6b0_getField7d(static_cast<const Unk_7ee6b0*>(object)), value->field_0);
}
