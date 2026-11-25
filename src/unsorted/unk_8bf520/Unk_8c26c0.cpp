// Scope: common
// Conditions from a table of 129 (0x71023bad58), in the TU of
// 0x71008c26c0-0x71008c6550: 0x71008c2fe0 calls entry `type` of a record with
// the context registered for the record's index (0x71008c2fc0; the contexts
// are Unk_27d16e0) and the record's arguments, an array of 64-bit values.
// Each condition takes the context and the arguments and returns a 64-bit
// value (a flag or a number). The names are placeholders. The context is
// opaque here: its accessors (0x71008c1ee0-0x71008c2060) are tools/leafgen.py
// placeholders, each taking its own placeholder type.
//
// Not here yet: the dispatcher (the original compares the condition with
// the table's size in 64 bits), the table, and the conditions that call leaf
// placeholders with too few parameters (0x71007ef2b0, 0x71007ef630,
// 0x71007cc000, 0x71007cce80, 0x71008c6180, 0x71007fe220, 0x7100780d70) or
// with a u64 where the callers pass 32 bits (Unk_7dfdd0_call,
// Unk_7f7ae0_call).
//
// The leaf placeholders declared below are tools/leafgen.py's: their return
// types aren't part of their symbols, and a few that tools/leafgen.py
// declared void return what their callers here use, so they're declared
// with the type the callers show.
#include <types.h>

struct Unk_7efe00;
struct Unk_7ee6b0;
struct Unk_7f2520;
struct Unk_7fe340;
struct Unk_8c1ef0;
struct Unk_8c1f00;
struct Unk_8c1f10;
struct Unk_8c1f20;
struct Unk_8c1f30;
struct Unk_8c1f40;
struct Unk_8c1f50;
struct Unk_8c2050;
struct Unk_7fc2e0;
u8 Unk_7fc2e0_getField30(const Unk_7fc2e0* self);
u8 Unk_7efe00_getField33c(const Unk_7efe00* self);
u8 Unk_7ee6b0_getField7d(const Unk_7ee6b0* self);
u32 Unk_7f2520_getField34c(const Unk_7f2520* self);
void* Unk_7fe340_getField2a8(const Unk_7fe340* self);
void* Unk_8c1ef0_getField290Ptr(Unk_8c1ef0* self);
void* Unk_8c1f00_getField58(const Unk_8c1f00* self);
void* Unk_8c1f10_getField68(const Unk_8c1f10* self);
void* Unk_8c1f20_call(const Unk_8c1f20* self);
void* Unk_8c1f30_getField60(const Unk_8c1f30* self);
void* Unk_8c1f40_getField78(const Unk_8c1f40* self);
void* Unk_8c1f50_getField80(const Unk_8c1f50* self);
u32 Unk_8c2050_getField8c(const Unk_8c2050* self);
bool Unk_7dfdd0_call(void* self, u64 value, u64 arg2);

// the context's (0x71008c18d0-0x71008c26c0)
void* Unk_8c20a0(void* self, u32 index);
u32 Unk_8c20f0(void* self, u32 index);
u8 Unk_8c2270(void* self, u32 index);
u32 Unk_8c22a0(void* self, u32 index);

// 0x71007f8c20: xoroshiro128+, a number below `max`
u64 Unk_7f8c20(void* self, u64 max);

bool Unk_7ef4c0(const Unk_7ee6b0* object, u32 index);
u64 Unk_7ef750(const Unk_7ee6b0* object, u32 index);
u8 Unk_7ef760(const Unk_7ee6b0* object, u32 index);
bool Unk_7f05a0(const Unk_7ee6b0* object, u32 index);
bool Unk_7f0500(void* object, u32 index);
u16 Unk_7f0160(void* object, u32 index);
s32 Unk_7f0bb0(const Unk_7ee6b0* object);
u8 Unk_7f8960(const u64* value);
u16 Unk_7f89e0(const u64* value);
u32 Unk_7efef0(void* object, u32 index);
u16 Unk_780d10(u32 id);
s32 Unk_781210(u32 value);
s64 Unk_7ff460(void* object, u8 value);
void* Unk_7c58c0(void* self, u8 value);
u16 Unk_8a85b0(void* self, void* object, bool value);
u8 Unk_7cb660(void* self, u8 value);
struct Unk_7ecc90_Con;
void* Unk_7ed1b0(const Unk_7ecc90_Con* self, u32 index);
struct Unk_7c2d80_Main;
u8 Unk_7cbf20(const Unk_7c2d80_Main* self, u8 value);
struct Unk_7fc430_Party;
void* Unk_7fc450(Unk_7fc430_Party* self, u8 index);
bool Unk_7ef580(Unk_7ee6b0* self);
bool Unk_780ec0(u32 id);
s32 Unk_8a8770(void* self, u8 id1, u8 id2, u32 id, u32 arg4);
bool Unk_8c6230(void* self, u32 index);
bool Unk_8c62f0(void* self, u32 index, u32 value);
s32 Unk_7eef50(void* self, u32 index);
u8 Unk_8a8550(void* self);
u8 Unk_7f0ba0(const Unk_7ee6b0* object, u32 index);
u8 Unk_780d40(u32 id);
struct Unk_7f09c0;
struct Unk_7f24b0;
struct Unk_7ca1c0;
struct Unk_7c58b0;
struct Unk_8c2620;
u16 Unk_7f09c0_getField76(const Unk_7f09c0* self);
u16 Unk_7f24b0_getField78(const Unk_7f24b0* self);
u32 Unk_7ca1c0_getField150(const Unk_7ca1c0* self);
u32 Unk_7c58b0_get(const Unk_7c58b0* self);
void Unk_8c2620_set(Unk_8c2620* self);
s32 Unk_7f7ae0_call(u16 self, u32 value);
u32 Unk_8c1f60(void* self);
u32 Unk_8c1fd0(void* self);
u32 Unk_7f05d0(void* object);
struct Unk_7ee6b0_Field;
bool Unk_7ffe20(const Unk_7ee6b0_Field* self, u32 value);
u16 Unk_7f0130(const Unk_7ee6b0* object, u8 index);
u8 Unk_7efe60(void* object);
u16 Unk_8a8620(void* self, void* object, u32 value);
struct Unk_7cb3f0;
struct Unk_7fe1f0;
struct Unk_8c2040;
struct Unk_7f0a90;
bool Unk_7cb3f0_call(const Unk_7cb3f0* self, u32 value, u32 arg2);
void* Unk_7fe1f0_getField28(const Unk_7fe1f0* self);
u8 Unk_8c2040_getField88(const Unk_8c2040* self);
u16 Unk_7f0a90_getField344(const Unk_7f0a90* self);
bool Unk_8a8690(void* self, u32 index, u32 value);
bool Unk_7f0ad0(const Unk_7ee6b0* object, u32 index);
bool Unk_800130(void* self, u32 kind, u16 value);
u8 Unk_764ca0(void* self);
struct Unk_7eef40;
struct Unk_7f2340;
struct Unk_7f2580;
struct Unk_7cb2e0;
struct Unk_7ef330;
struct Unk_7f2e70;
u16 Unk_7eef40_getField70(const Unk_7eef40* self);
u8 Unk_7f2340_getField2ae(const Unk_7f2340* self);
u16 Unk_7f2580_getField33a(const Unk_7f2580* self);
bool Unk_7cb2e0_check(const Unk_7cb2e0* self);
void* Unk_7ef330_getField60(const Unk_7ef330* self);
bool Unk_7f2e70_check(const Unk_7f2e70* self);
// what 0x71007f2650 fills in (0x71008c5d90 reads only the first u16)
struct Unk_7f2650_Out {
    u16 field_0;
    u8 _2[0xe];
};
PKMN_SIZE_ASSERT(Unk_7f2650_Out, 0x10);
struct Unk_7ee6b0_Action;
bool Unk_7f2650(const Unk_7ee6b0* object, u8 arg1, u8 arg2, Unk_7ee6b0_Action* out);
u32 Unk_8c2420(void* self, void* object1, void* object2, bool flag);
s32 Unk_7fc4a0(const Unk_7fc430_Party* self, const Unk_7ee6b0* object);
u32 Unk_7f75d0(u32 power, s32 value);
u16 Unk_8a86e0(void* self, u8 id1, u8 id2, u32 id, u32 arg4, bool flag);
bool Unk_800680(void* self, u8 id, u32 arg2, u32 arg3);
u8 Unk_7fc630(Unk_7fc430_Party* self);
u32 Unk_7f8070(u32 value, const Unk_7ee6b0* object);
bool Unk_786d90(u16 id);
void* Unk_8c2070(void* self, u32 index);
u8 Unk_7cb490(u8 id);
bool Unk_7cd440(void* self, u8 id);
struct Unk_8c2060;
struct Unk_7fe290;
struct Unk_7ee6c0;
struct Unk_7fc800;
struct Unk_7ee810;
struct Unk_7f36f0;
struct Unk_7c56e0;
struct Unk_8c1ee0;
u16 Unk_8c2060_getField90(const Unk_8c2060* self);
void* Unk_7fe290_getField128(const Unk_7fe290* self);
bool Unk_7ee6c0_getField298(const Unk_7ee6c0* self);
bool Unk_7fc800_check(const Unk_7fc800* self);
u64 Unk_7ee810_getField278(const Unk_7ee810* self);
u64 Unk_7f36f0_getField0(const Unk_7f36f0* self);
bool Unk_7c56e0_check(const Unk_7c56e0* self, u32 value);

// what 0x71008c1ee0 returns a pointer to (the context's field_70)
struct Unk_8c6160_Data {
    u8 _0[0x30];
    u8 field_30;
};
PKMN_OFFSET_ASSERT(Unk_8c6160_Data, field_30, 0x30);
Unk_8c6160_Data* Unk_8c1ee0_getField70Ptr(Unk_8c1ee0* self);

// what 0x71008c5800 reads of the objects 0x71008c20a0 returns
struct Unk_8c5800_Object {
    u8 _0[0x33d];
    u8 field_33d;
};
PKMN_OFFSET_ASSERT(Unk_8c5800_Object, field_33d, 0x33d);

static void* Unk_8c26c0_Random(void* self) {
    return Unk_8c1ef0_getField290Ptr(static_cast<Unk_8c1ef0*>(self));
}

// 0x71008c3020
s64 Unk_8c3020(void* self, const s64* args) {
    return Unk_7f8c20(Unk_8c26c0_Random(self), 0x100) < static_cast<u32>(args[0]);
}

// 0x71008c3060
s64 Unk_8c3060(void* self, const s64* args) {
    return Unk_7f8c20(Unk_8c26c0_Random(self), 0x100) > static_cast<u32>(args[0]);
}

// 0x71008c30a0
s64 Unk_8c30a0(void* self, const s64* args) {
    s32 value = Unk_7f8c20(Unk_8c26c0_Random(self), 0x100);
    return value == args[0];
}

// 0x71008c30e0
s64 Unk_8c30e0(void* self, const s64* args) {
    s32 value = Unk_7f8c20(Unk_8c26c0_Random(self), 0x100);
    return value != args[0];
}

// 0x71008c3120
s64 Unk_8c3120(void* self, const s64* args) {
    s32 value = Unk_7f0bb0(static_cast<const Unk_7ee6b0*>(Unk_8c20a0(self, args[0])));
    return (value >> 12) < args[1];
}

// 0x71008c3160
s64 Unk_8c3160(void* self, const s64* args) {
    s32 value = Unk_7f0bb0(static_cast<const Unk_7ee6b0*>(Unk_8c20a0(self, args[0])));
    return (value >> 12) > args[1];
}

// 0x71008c31a0
s64 Unk_8c31a0(void* self, const s64* args) {
    s32 value = Unk_7f0bb0(static_cast<const Unk_7ee6b0*>(Unk_8c20a0(self, args[0])));
    return (value >> 12) + ((value & 0xfff) != 0) == args[1];
}

// 0x71008c31e0
s64 Unk_8c31e0(void* self, const s64* args) {
    s32 value = Unk_7f0bb0(static_cast<const Unk_7ee6b0*>(Unk_8c20a0(self, args[0])));
    return (value >> 12) + ((value & 0xfff) != 0) != args[1];
}

// 0x71008c3280
s64 Unk_8c3280(void* self, const s64* args) {
    return Unk_7ef4c0(static_cast<const Unk_7ee6b0*>(Unk_8c20a0(self, args[0])), args[1]);
}

// 0x71008c32b0
s64 Unk_8c32b0(void* self, const s64* args) {
    return !Unk_7ef4c0(static_cast<const Unk_7ee6b0*>(Unk_8c20a0(self, args[0])), args[1]);
}

// 0x71008c3340
s64 Unk_8c3340(void* self, const s64* args) {
    return Unk_7f05a0(static_cast<const Unk_7ee6b0*>(Unk_8c20a0(self, args[0])), args[1]);
}

// 0x71008c3370
s64 Unk_8c3370(void* self, const s64* args) {
    return !Unk_7f05a0(static_cast<const Unk_7ee6b0*>(Unk_8c20a0(self, args[0])), args[1]);
}

// 0x71008c3740
s64 Unk_8c3740(void* self, const s64* args) {
    void* object = Unk_8c20a0(self, args[0]);
    if (!Unk_7ef4c0(static_cast<const Unk_7ee6b0*>(object), 0x14))
        return 0;
    u64 value = Unk_7ef750(static_cast<const Unk_7ee6b0*>(object), 0x14);
    return Unk_7f8960(&value);
}

// 0x71008c37a0
s64 Unk_8c37a0(void* self, const s64* args) {
    void* object = Unk_8c20a0(self, args[0]);
    if (!Unk_7ef4c0(static_cast<const Unk_7ee6b0*>(object), 0x14))
        return 0;
    return Unk_7ef760(static_cast<const Unk_7ee6b0*>(object), 0x14);
}

// 0x71008c37f0
s64 Unk_8c37f0(void* self, const s64* args) {
    void* object = Unk_8c20a0(self, args[0]);
    if (!object)
        return 0;
    if (!Unk_7ef4c0(static_cast<const Unk_7ee6b0*>(object), 0x1c))
        return 0;
    u64 value = Unk_7ef750(static_cast<const Unk_7ee6b0*>(object), 0x1c);
    return Unk_7f89e0(&value);
}

// 0x71008c3850
s64 Unk_8c3850(void* self, const s64* /*args*/) {
    void* object = Unk_8c1f40_getField78(static_cast<const Unk_8c1f40*>(self));
    if (object) {
        u8 n = Unk_7efe00_getField33c(static_cast<const Unk_7efe00*>(object));
        for (u32 i = 0; i < n; i++)
            if (Unk_780d10(Unk_7efef0(object, i)))
                return 1;
    }
    return 0;
}

// 0x71008c38c0
s64 Unk_8c38c0(void* self, const s64* /*args*/) {
    void* object = Unk_8c1f40_getField78(static_cast<const Unk_8c1f40*>(self));
    if (object) {
        u8 n = Unk_7efe00_getField33c(static_cast<const Unk_7efe00*>(object));
        for (u32 i = 0; i < n; i++)
            if (Unk_780d10(Unk_7efef0(object, i)))
                return 0;
    }
    return 1;
}

// 0x71008c3940
s64 Unk_8c3940(void* self, const s64* /*args*/) {
    return Unk_7ff460(Unk_7fe340_getField2a8(static_cast<const Unk_7fe340*>(
                          Unk_8c1f30_getField60(static_cast<const Unk_8c1f30*>(self)))),
                      0);
}

// 0x71008c3ba0
s64 Unk_8c3ba0(void* self, const s64* /*args*/) {
    return Unk_780d10(Unk_8c2050_getField8c(static_cast<const Unk_8c2050*>(self)));
}

// 0x71008c3d20
s64 Unk_8c3d20(void* self, const s64* args) {
    return Unk_7f2520_getField34c(static_cast<const Unk_7f2520*>(Unk_8c20a0(self, args[0])));
}

// 0x71008c3d40
s64 Unk_8c3d40(void* self, const s64* args) {
    void* object1 = Unk_8c1f40_getField78(static_cast<const Unk_8c1f40*>(self));
    void* object2 = Unk_8c1f50_getField80(static_cast<const Unk_8c1f50*>(self));
    if (!object1 || !object2)
        return 0;
    u32 mode = args[0];
    u16 value1 =
        Unk_8a85b0(Unk_8c1f10_getField68(static_cast<const Unk_8c1f10*>(self)), object1, 1);
    u16 value2 =
        Unk_8a85b0(Unk_8c1f10_getField68(static_cast<const Unk_8c1f10*>(self)), object2, 1);
    switch (mode) {
        case 0:
            return value1 > value2;
        case 1:
            return value1 < value2;
        case 2:
            return value1 == value2;
        default:
            return 0;
    }
}

// 0x71008c3e30
s64 Unk_8c3e30(void* self, const s64* args) {
    u32 index = Unk_8c20f0(self, args[0]);
    u8 id = Unk_7cb660(Unk_8c1f00_getField58(static_cast<const Unk_8c1f00*>(self)), index);
    void* party = Unk_7ed1b0(
        static_cast<const Unk_7ecc90_Con*>(Unk_8c1f20_call(static_cast<const Unk_8c1f20*>(self))),
        id);
    u8 first = Unk_7cbf20(static_cast<const Unk_7c2d80_Main*>(
                              Unk_8c1f00_getField58(static_cast<const Unk_8c1f00*>(self))),
                          id);
    u8 count = Unk_7fc2e0_getField30(static_cast<const Unk_7fc2e0*>(party));
    if (first >= count)
        return 0;
    u32 n = 0;
    for (u32 i = first; i != count; i++)
        n += Unk_7ef580(
            static_cast<Unk_7ee6b0*>(Unk_7fc450(static_cast<Unk_7fc430_Party*>(party), i)));
    return n;
}

// 0x71008c3ef0
s64 Unk_8c3ef0(void* self, const s64* /*args*/) {
    return Unk_781210(Unk_8c2050_getField8c(static_cast<const Unk_8c2050*>(self)));
}

// 0x71008c3f10
s64 Unk_8c3f10(void* self, const s64* args) {
    return Unk_8c22a0(self, args[0]);
}

// 0x71008c4420
s64 Unk_8c4420(void* self, const s64* args) {
    return !Unk_8c6230(self, args[0]);
}

// 0x71008c4440
s64 Unk_8c4440(void* self, const s64* /*args*/) {
    return Unk_8a8550(Unk_8c1f10_getField68(static_cast<const Unk_8c1f10*>(self)));
}

// 0x71008c4460
s64 Unk_8c4460(void* self, const s64* args) {
    u32 index = args[0];
    u32 which = args[1];
    s32 value = Unk_7eef50(Unk_8c20a0(self, index), which);
    return args[2] > value;
}

// 0x71008c44a0
s64 Unk_8c44a0(void* self, const s64* args) {
    u32 index = args[0];
    u32 which = args[1];
    s32 value = Unk_7eef50(Unk_8c20a0(self, index), which);
    return args[2] < value;
}

// 0x71008c44e0
s64 Unk_8c44e0(void* self, const s64* args) {
    u32 index = args[0];
    u32 which = args[1];
    s32 value = Unk_7eef50(Unk_8c20a0(self, index), which);
    return args[2] == value;
}

// 0x71008c4520
s64 Unk_8c4520(void* self, const s64* args) {
    u32 index = args[0];
    u32 which = args[1];
    s32 value = Unk_7eef50(Unk_8c20a0(self, index), which);
    return args[2] != value;
}

// 0x71008c4740
s64 Unk_8c4740(void* self, const s64* args) {
    return !Unk_8c62f0(self, args[0], args[1]);
}

// 0x71008c4770
s64 Unk_8c4770(void* self, const s64* /*args*/) {
    Unk_8c2620_set(static_cast<Unk_8c2620*>(self));
    return 0;
}

// 0x71008c4790
s64 Unk_8c4790(void* self, const s64* args) {
    return Unk_7f09c0_getField76(static_cast<const Unk_7f09c0*>(Unk_8c20a0(self, args[0])));
}

// 0x71008c47f0
s64 Unk_8c47f0(void* self, const s64* args) {
    return Unk_7eef50(Unk_8c20a0(self, args[0]), 0x14);
}

// 0x71008c4820
s64 Unk_8c4820(void* self, const s64* args) {
    return Unk_7f05a0(static_cast<const Unk_7ee6b0*>(Unk_8c20a0(self, args[0])), 0);
}

// 0x71008c4850
s64 Unk_8c4850(void* self, const s64* args) {
    return Unk_7f0ba0(static_cast<const Unk_7ee6b0*>(Unk_8c20a0(self, args[0])), 0);
}

// 0x71008c4880
s64 Unk_8c4880(void* self, const s64* /*args*/) {
    return Unk_7ca1c0_getField150(static_cast<const Unk_7ca1c0*>(
        Unk_8c1f00_getField58(static_cast<const Unk_8c1f00*>(self))));
}

// 0x71008c48a0
s64 Unk_8c48a0(void* self, const s64* /*args*/) {
    return Unk_7c58b0_get(static_cast<const Unk_7c58b0*>(
        Unk_8c1f00_getField58(static_cast<const Unk_8c1f00*>(self))));
}

// 0x71008c48c0
s64 Unk_8c48c0(void* self, const s64* args) {
    return Unk_7f24b0_getField78(static_cast<const Unk_7f24b0*>(Unk_8c20a0(self, args[0])));
}

// 0x71008c48e0
s64 Unk_8c48e0(void* self, const s64* /*args*/) {
    return Unk_780d40(Unk_8c2050_getField8c(static_cast<const Unk_8c2050*>(self)));
}

// 0x71008c4900
s64 Unk_8c4900(void* self, const s64* /*args*/) {
    return Unk_780d10(Unk_8c2050_getField8c(static_cast<const Unk_8c2050*>(self)));
}

// 0x71008c4920
s64 Unk_8c4920(void* self, const s64* /*args*/) {
    return Unk_781210(Unk_8c2050_getField8c(static_cast<const Unk_8c2050*>(self)));
}

// 0x71008c4940
s64 Unk_8c4940(void* self, const s64* args) {
    return Unk_7f0ba0(static_cast<const Unk_7ee6b0*>(Unk_8c20a0(self, args[0])), 3);
}

// 0x71008c4970
s64 Unk_8c4970(void* self, const s64* args) {
    void* object1 = Unk_8c1f40_getField78(static_cast<const Unk_8c1f40*>(self));
    void* object2 = Unk_8c1f50_getField80(static_cast<const Unk_8c1f50*>(self));
    if (!object1 || !object2)
        return 0;
    s32 value1 = Unk_7eef50(object1, 0x11);
    s32 value2 = Unk_7eef50(object2, 0x11);
    switch (args[0]) {
        case 0:
            return value1 > value2;
        case 2:
            return value1 == value2;
        default:
            return value1 < value2;
    }
}

// 0x71008c4a20
s64 Unk_8c4a20(void* self, const s64* /*args*/) {
    void* object = Unk_8c1f50_getField80(static_cast<const Unk_8c1f50*>(self));
    if (!object)
        return 0;
    return Unk_7ef4c0(static_cast<const Unk_7ee6b0*>(object), 0xb);
}

// 0x71008c4a50
s64 Unk_8c4a50(void* self, const s64* /*args*/) {
    void* object = Unk_8c1f50_getField80(static_cast<const Unk_8c1f50*>(self));
    if (!object)
        return 0;
    return Unk_7ef4c0(static_cast<const Unk_7ee6b0*>(object), 0xb);
}

// 0x71008c4b10
s64 Unk_8c4b10(void* self, const s64* args) {
    void* object = Unk_8c20a0(self, args[0]);
    u8 type = args[1];
    u32 types = Unk_7f05d0(object);
    if (type != 0x12 &&
        ((types & 0x1f) == type || (types >> 5 & 0x1f) == type || (types >> 10 & 0x1f) == type))
        return 1;
    return 0;
}

// 0x71008c4ba0
s64 Unk_8c4ba0(void* self, const s64* args) {
    u32 index = args[0];
    u32 value = args[1];
    return Unk_8c22a0(self, index) == value;
}

// 0x71008c4bd0
s64 Unk_8c4bd0(void* self, const s64* args) {
    return Unk_7f05a0(static_cast<const Unk_7ee6b0*>(Unk_8c20a0(self, args[0])), 0xd);
}

// 0x71008c4c00
s64 Unk_8c4c00(void* self, const s64* args) {
    void* object = Unk_8c20a0(self, args[0]);
    u32 value = args[1];
    return Unk_7f09c0_getField76(static_cast<const Unk_7f09c0*>(object)) == value;
}

// 0x71008c4c40
s64 Unk_8c4c40(void* self, const s64* args) {
    u32 value = args[0];
    return Unk_7ffe20(
        static_cast<const Unk_7ee6b0_Field*>(Unk_7fe1f0_getField28(static_cast<const Unk_7fe1f0*>(
            Unk_8c1f30_getField60(static_cast<const Unk_8c1f30*>(self))))),
        value);
}

// 0x71008c4ee0
s64 Unk_8c4ee0(void* self, const s64* /*args*/) {
    void* object = Unk_8c1f40_getField78(static_cast<const Unk_8c1f40*>(self));
    if (!object)
        return 0;
    return Unk_7f0130(static_cast<const Unk_7ee6b0*>(object),
                      Unk_8c2040_getField88(static_cast<const Unk_8c2040*>(self)));
}

// 0x71008c4fc0
s64 Unk_8c4fc0(void* self, const s64* args) {
    void* object = Unk_8c20a0(self, args[0]);
    return Unk_8a8620(Unk_8c1f10_getField68(static_cast<const Unk_8c1f10*>(self)), object, 1);
}

// 0x71008c5000
s64 Unk_8c5000(void* self, const s64* args) {
    return Unk_7f0a90_getField344(static_cast<const Unk_7f0a90*>(Unk_8c20a0(self, args[0])));
}

// 0x71008c5400
s64 Unk_8c5400(void* self, const s64* args) {
    void* object1 = Unk_8c1f40_getField78(static_cast<const Unk_8c1f40*>(self));
    if (!object1)
        return 0;
    void* object2 = Unk_8c20a0(self, args[0]);
    u32 index = args[1];
    return Unk_7eef50(object2, index) - Unk_7eef50(object1, index);
}

// 0x71008c5470
s64 Unk_8c5470(void* self, const s64* args) {
    return Unk_7eef50(Unk_8c20a0(self, args[0]), args[1]);
}

// 0x71008c5790
s64 Unk_8c5790(void* self, const s64* args) {
    return Unk_7eef50(Unk_8c20a0(self, args[0]), 0x13);
}

// 0x71008c57c0
s64 Unk_8c57c0(void* self, const s64* args) {
    return Unk_7f2e70_check(static_cast<const Unk_7f2e70*>(Unk_8c20a0(self, args[0])));
}

// 0x71008c57e0
s64 Unk_8c57e0(void* self, const s64* args) {
    return Unk_7eef40_getField70(static_cast<const Unk_7eef40*>(Unk_8c20a0(self, args[0])));
}

// 0x71008c5800
s64 Unk_8c5800(void* self, const s64* args) {
    return static_cast<const Unk_8c5800_Object*>(Unk_8c20a0(self, args[0]))->field_33d;
}

// 0x71008c58e0
s64 Unk_8c58e0(void* self, const s64* args) {
    u32 index = Unk_8c20f0(self, args[0]);
    return Unk_8a8690(Unk_8c1f10_getField68(static_cast<const Unk_8c1f10*>(self)), index, 3);
}

// 0x71008c5920
s64 Unk_8c5920(void* self, const s64* args) {
    void* object = Unk_8c20a0(self, args[0]);
    s32 value = Unk_7eef50(object, 8);
    return value < Unk_7eef50(object, 0xa);
}

// 0x71008c5970
s64 Unk_8c5970(void* self, const s64* args) {
    void* object = Unk_8c20a0(self, args[0]);
    s32 value = Unk_7eef50(object, 8);
    return value > Unk_7eef50(object, 0xa);
}

// 0x71008c59c0
s64 Unk_8c59c0(void* self, const s64* args) {
    void* object = Unk_8c20a0(self, args[0]);
    s32 value = Unk_7eef50(object, 8);
    return value != Unk_7eef50(object, 0xa);
}

// 0x71008c5a10
s64 Unk_8c5a10(void* self, const s64* args) {
    return Unk_7f0ad0(static_cast<const Unk_7ee6b0*>(Unk_8c20a0(self, args[0])), 0);
}

// 0x71008c5a40
s64 Unk_8c5a40(void* self, const s64* args) {
    u8 value = Unk_7f2340_getField2ae(static_cast<const Unk_7f2340*>(Unk_8c20a0(self, args[0])));
    return args[1] == value;
}

// 0x71008c5a80
s64 Unk_8c5a80(void* self, const s64* args) {
    void* object = Unk_7fe1f0_getField28(static_cast<const Unk_7fe1f0*>(
        Unk_8c1f30_getField60(static_cast<const Unk_8c1f30*>(self))));
    if (!object)
        return 0;
    return Unk_800130(object, 8, static_cast<u16>(args[0]));
}

// 0x71008c5ac0
s64 Unk_8c5ac0(void* self, const s64* args) {
    return Unk_7f2580_getField33a(static_cast<const Unk_7f2580*>(Unk_8c20a0(self, args[0])));
}

// 0x71008c5ae0
s64 Unk_8c5ae0(void* self, const s64* /*args*/) {
    return Unk_7cb2e0_check(static_cast<const Unk_7cb2e0*>(
        Unk_8c1f00_getField58(static_cast<const Unk_8c1f00*>(self))));
}

// 0x71008c5b50
s64 Unk_8c5b50(void* self, const s64* args) {
    return Unk_764ca0(
        Unk_7ef330_getField60(static_cast<const Unk_7ef330*>(Unk_8c20a0(self, args[0]))));
}

// 0x71008c5b80
s64 Unk_8c5b80(void* self, const s64* /*args*/) {
    return Unk_7c58b0_get(static_cast<const Unk_7c58b0*>(
               Unk_8c1f00_getField58(static_cast<const Unk_8c1f00*>(self)))) == 1;
}

// 0x71008c5d90
s64 Unk_8c5d90(void* self, const s64* args) {
    void* object = Unk_8c20a0(self, args[0]);
    if (!object)
        return 0;
    Unk_7f2650_Out out;
    bool found = Unk_7f2650(static_cast<const Unk_7ee6b0*>(object), 1, 0,
                            reinterpret_cast<Unk_7ee6b0_Action*>(&out));
    return found ? out.field_0 : 0;
}

// 0x71008c5dd0
s64 Unk_8c5dd0(void* self, const s64* /*args*/) {
    return Unk_8c2050_getField8c(static_cast<const Unk_8c2050*>(self));
}

// 0x71008c5df0
s64 Unk_8c5df0(void* self, const s64* /*args*/) {
    return Unk_8c2060_getField90(static_cast<const Unk_8c2060*>(self));
}

// 0x71008c5ea0
s64 Unk_8c5ea0(void* self, const s64* args) {
    u8 slot = Unk_8c2270(self, args[0]);
    return Unk_7fc630(static_cast<Unk_7fc430_Party*>(Unk_7ed1b0(
        static_cast<const Unk_7ecc90_Con*>(Unk_8c1f20_call(static_cast<const Unk_8c1f20*>(self))),
        slot)));
}

// 0x71008c5ee0
s64 Unk_8c5ee0(void* self, const s64* /*args*/) {
    void* object = Unk_8c1f40_getField78(static_cast<const Unk_8c1f40*>(self));
    return Unk_7f8070(Unk_8c2050_getField8c(static_cast<const Unk_8c2050*>(self)),
                      static_cast<const Unk_7ee6b0*>(object));
}

// 0x71008c5f20
s64 Unk_8c5f20(void* self, const s64* args) {
    void* object1 = Unk_8c20a0(self, args[0]);
    void* object2 = Unk_8c20a0(self, args[1]);
    if (!object1 || !object2)
        return 0;
    u8 n = Unk_7efe00_getField33c(static_cast<const Unk_7efe00*>(object1));
    for (u32 i = 0; i < n; i++) {
        u32 id = Unk_7efef0(object1, i);
        void* calc = Unk_8c1f10_getField68(static_cast<const Unk_8c1f10*>(self));
        if (Unk_8a8770(calc, Unk_7ee6b0_getField7d(static_cast<const Unk_7ee6b0*>(object1)),
                       Unk_7ee6b0_getField7d(static_cast<const Unk_7ee6b0*>(object2)), id, 0) >= 8)
            return 1;
    }
    return 0;
}

// 0x71008c6010
s64 Unk_8c6010(void* self, const s64* args) {
    void* object = Unk_8c20a0(self, args[0]);
    if (!object)
        return 0;
    return Unk_7ee6c0_getField298(static_cast<const Unk_7ee6c0*>(object));
}

// 0x71008c6040
s64 Unk_8c6040(void* self, const s64* args) {
    return Unk_786d90(
        Unk_7f09c0_getField76(static_cast<const Unk_7f09c0*>(Unk_8c20a0(self, args[0]))));
}

// 0x71008c6070
s64 Unk_8c6070(void* self, const s64* /*args*/) {
    void* object = Unk_8c2070(self, 4);
    if (!object)
        return 0;
    return Unk_7fc800_check(reinterpret_cast<const Unk_7fc800*>(
        Unk_7f36f0_getField0(reinterpret_cast<const Unk_7f36f0*>(
            Unk_7ee810_getField278(static_cast<const Unk_7ee810*>(object))))));
}

// 0x71008c60a0
s64 Unk_8c60a0(void* self, const s64* /*args*/) {
    if (!Unk_7c56e0_check(static_cast<const Unk_7c56e0*>(
                              Unk_8c1f00_getField58(static_cast<const Unk_8c1f00*>(self))),
                          0x1000))
        return 0;
    u8 id = Unk_7ee6b0_getField7d(static_cast<const Unk_7ee6b0*>(
        Unk_8c1f40_getField78(static_cast<const Unk_8c1f40*>(self))));
    Unk_8c1f00_getField58(static_cast<const Unk_8c1f00*>(self));
    return (Unk_7cb490(id) & 0xfe) == 2;
}

// 0x71008c6110
s64 Unk_8c6110(void* self, const s64* args) {
    void* object = Unk_8c20a0(self, args[0]);
    void* table = Unk_8c1f00_getField58(static_cast<const Unk_8c1f00*>(self));
    return Unk_7cd440(table, Unk_7ee6b0_getField7d(static_cast<const Unk_7ee6b0*>(object)));
}

// 0x71008c6160
s64 Unk_8c6160(void* self, const s64* /*args*/) {
    return Unk_8c1ee0_getField70Ptr(static_cast<Unk_8c1ee0*>(self))->field_30;
}

// The contexts by index (0x71027d16e0), set by 0x71008c2fc0
void* Unk_27d16e0[5];

// 0x71008c2fc0
void Unk_8c2fc0(u8 index, void* context) {
    if (index <= 4)
        Unk_27d16e0[index] = context;
}

// 0x71008c3bc0
s64 Unk_8c3bc0(void* self, const s64* args) {
    s64 mode = args[0];
    void* object1 = Unk_8c1f40_getField78(static_cast<const Unk_8c1f40*>(self));
    void* object2 = Unk_8c1f50_getField80(static_cast<const Unk_8c1f50*>(self));
    if (!object1 || !object2)
        return 0;
    bool flag = mode != 0;
    u8 id1 = Unk_7ee6b0_getField7d(static_cast<const Unk_7ee6b0*>(object1));
    u8 id2 = Unk_7ee6b0_getField7d(static_cast<const Unk_7ee6b0*>(object2));
    u16 base = Unk_8a86e0(Unk_8c1f10_getField68(static_cast<const Unk_8c1f10*>(self)), id1, id2,
                          Unk_8c2050_getField8c(static_cast<const Unk_8c2050*>(self)), 1, flag);
    if (!base)
        return 0;
    u8 n = Unk_7efe00_getField33c(static_cast<const Unk_7efe00*>(object1));
    for (u32 i = 0; i < n; i++) {
        u32 id = Unk_7efef0(object1, i);
        if (i == Unk_8c2040_getField88(static_cast<const Unk_8c2040*>(self)))
            continue;
        if (Unk_8a86e0(Unk_8c1f10_getField68(static_cast<const Unk_8c1f10*>(self)), id1, id2, id, 1,
                       mode != 0) > base)
            return 1;
    }
    return 2;
}

// 0x71008c5160
s64 Unk_8c5160(void* self, const s64* args) {
    u32 index1 = args[0];
    u32 index2 = args[1];
    void* object1 = Unk_8c20a0(self, index1);
    void* object2 = Unk_8c20a0(self, index2);
    if (!object1 || !object2)
        return 0;
    u8 n = Unk_7efe00_getField33c(static_cast<const Unk_7efe00*>(object1));
    for (u32 i = 0; i < n; i++) {
        u32 id = Unk_7efef0(object1, i);
        void* calc = Unk_8c1f10_getField68(static_cast<const Unk_8c1f10*>(self));
        if (Unk_8a8770(calc, Unk_7ee6b0_getField7d(static_cast<const Unk_7ee6b0*>(object1)),
                       Unk_7ee6b0_getField7d(static_cast<const Unk_7ee6b0*>(object2)), id, 0) >= 8)
            return 1;
    }
    return 0;
}

// 0x71008c5250
s64 Unk_8c5250(void* self, const s64* args) {
    void* object1 = Unk_8c1f40_getField78(static_cast<const Unk_8c1f40*>(self));
    void* object2 = Unk_8c1f50_getField80(static_cast<const Unk_8c1f50*>(self));
    if (!object1 || !object2)
        return 0;
    void* object = Unk_8c20a0(self, args[0]);
    bool flag = args[1] != 0;
    u32 value = Unk_8c2420(self, object1, object2, flag);
    void* calc = Unk_8c1f10_getField68(static_cast<const Unk_8c1f10*>(self));
    u8 id1 = Unk_7ee6b0_getField7d(static_cast<const Unk_7ee6b0*>(object));
    u8 id2 = Unk_7ee6b0_getField7d(static_cast<const Unk_7ee6b0*>(object2));
    return value < Unk_8a86e0(calc, id1, id2,
                              Unk_7f2520_getField34c(static_cast<const Unk_7f2520*>(object)), 1,
                              flag);
}

// 0x71008c54a0
s64 Unk_8c54a0(void* self, const s64* args) {
    void* object1 = Unk_8c1f40_getField78(static_cast<const Unk_8c1f40*>(self));
    void* object2 = Unk_8c1f50_getField80(static_cast<const Unk_8c1f50*>(self));
    if (!object1 || !object2)
        return 0;
    s64 mode = args[0];
    bool flag = mode != 0;
    u16 base = Unk_8a86e0(Unk_8c1f10_getField68(static_cast<const Unk_8c1f10*>(self)),
                          Unk_7ee6b0_getField7d(static_cast<const Unk_7ee6b0*>(object1)),
                          Unk_7ee6b0_getField7d(static_cast<const Unk_7ee6b0*>(object2)),
                          Unk_8c2050_getField8c(static_cast<const Unk_8c2050*>(self)), 1, flag);
    u8 side =
        Unk_7cb660(Unk_8c1f00_getField58(static_cast<const Unk_8c1f00*>(self)), Unk_8c1f60(self));
    void* party = Unk_7ed1b0(
        static_cast<const Unk_7ecc90_Con*>(Unk_8c1f20_call(static_cast<const Unk_8c1f20*>(self))),
        side);
    s32 position = Unk_7fc4a0(static_cast<const Unk_7fc430_Party*>(party),
                              static_cast<const Unk_7ee6b0*>(object1));
    if (!base || position < 0)
        return 0;
    u8 count = Unk_7cbf20(static_cast<const Unk_7c2d80_Main*>(
                              Unk_8c1f00_getField58(static_cast<const Unk_8c1f00*>(self))),
                          side);
    for (u32 i = 0; i < count; i++) {
        void* member = Unk_7fc450(static_cast<Unk_7fc430_Party*>(party), i);
        if (!Unk_7ef580(static_cast<Unk_7ee6b0*>(member)))
            continue;
        u32 n = Unk_7efe00_getField33c(static_cast<const Unk_7efe00*>(member));
        if (!n)
            continue;
        if (i == static_cast<u32>(position)) {
            for (u32 j = 0; j < n; j++) {
                if (j == Unk_8c2040_getField88(static_cast<const Unk_8c2040*>(self)))
                    continue;
                u32 id = Unk_7efef0(member, j);
                if (Unk_8a86e0(Unk_8c1f10_getField68(static_cast<const Unk_8c1f10*>(self)),
                               Unk_7ee6b0_getField7d(static_cast<const Unk_7ee6b0*>(member)),
                               Unk_7ee6b0_getField7d(static_cast<const Unk_7ee6b0*>(object2)), id,
                               1, mode != 0) > base)
                    return 1;
            }
        } else {
            for (u32 j = 0; j < n; j++) {
                u32 id = Unk_7efef0(member, j);
                if (Unk_8a86e0(Unk_8c1f10_getField68(static_cast<const Unk_8c1f10*>(self)),
                               Unk_7ee6b0_getField7d(static_cast<const Unk_7ee6b0*>(member)),
                               Unk_7ee6b0_getField7d(static_cast<const Unk_7ee6b0*>(object2)), id,
                               1, mode != 0) > base)
                    return 1;
            }
        }
    }
    return 2;
}

// 0x71008c63e0
u32 Unk_8c63e0(void* /*self*/, void* calc, void* object1, void* object2) {
    u32 best = 0;
    u8 n = Unk_7efe00_getField33c(static_cast<const Unk_7efe00*>(object1));
    for (u32 i = 0; i < n; i++) {
        if (!Unk_7f0130(static_cast<const Unk_7ee6b0*>(object1), i))
            continue;
        u32 id = Unk_7efef0(object1, i);
        if (!Unk_780ec0(id))
            continue;
        u32 power = Unk_780d10(id);
        s32 value =
            Unk_8a8770(calc, Unk_7ee6b0_getField7d(static_cast<const Unk_7ee6b0*>(object1)),
                       Unk_7ee6b0_getField7d(static_cast<const Unk_7ee6b0*>(object2)), id, 0);
        u32 damage = Unk_7f75d0(power, value);
        if (best < damage)
            best = damage;
    }
    return best;
}
