// Scope: common
// The battle scene's scene (unsorted/Unk_98a420.h): functions that forward
// to what its +0x38 and +0x58 objects lead to. Placeholder names and types:
// rename and move once the classes are known. Some of their callees were
// matched first as tools/leafgen.py's placeholders, each with its own type:
// the objects are passed as those.
#include <types.h>

#include "unsorted/Unk_98a420.h"

// What the +0x58 object leads to: at +0x58.
inline u8* Unk_98a420_Sub58(const Unk_23c4ef0_Scene* scene) {
    return Unk_98adb0(reinterpret_cast<u64>(scene->field_58)) + 0x58;
}

// What the +0x38 object leads to: at +0x470.
inline u8* Unk_98a420_Sub470(u64 scene) {
    const Unk_23c4ef0_Scene* self = reinterpret_cast<const Unk_23c4ef0_Scene*>(scene);
    return Unk_98ab90(reinterpret_cast<u64>(self->field_38)) + 0x470;
}

void Unk_939330(u64 self, u32 arg1, u64 arg2);

// 0x710098a440
void Unk_23c4ef0_Scene::Unk_98a440(bool arg1, u32 arg2) {
    Unk_939330(reinterpret_cast<u64>(Unk_98a420_Sub58(this)), arg1, arg2);
}

struct Unk_8ec680;
struct Unk_8ec680_Value;
struct Unk_8ec6b0_Out;
void Unk_8ec680_set(Unk_8ec680* self, const Unk_8ec680_Value* value);
bool Unk_8ec6b0_get(const Unk_8ec680* self, Unk_8ec6b0_Out* out);
void Unk_8ec6f0(Unk_8ec680* self);

// NON_MATCHING: the placeholder name (_Z10Unk_98a4b0m) has no second
// parameter, which the original passes on: see the unit's report.
// 0x710098a4b0
void Unk_98a4b0(u64 scene, const Unk_8ec680_Value* value) {
    Unk_8ec680_set(reinterpret_cast<Unk_8ec680*>(Unk_98a420_Sub470(scene)), value);
}

// NON_MATCHING: the placeholder name (_Z10Unk_98a4e0m) has no second
// parameter, which the original passes on: see the unit's report.
// 0x710098a4e0
bool Unk_98a4e0(u64 scene, Unk_8ec6b0_Out* out) {
    return Unk_8ec6b0_get(reinterpret_cast<Unk_8ec680*>(Unk_98a420_Sub470(scene)), out);
}

// NON_MATCHING: the callee's placeholder name (_Z10Unk_8ec6f0v) has no
// parameter, and the original passes it the object: see the unit's report.
// 0x710098a510
void Unk_98a510(u64 scene) {
    Unk_8ec6f0(reinterpret_cast<Unk_8ec680*>(Unk_98a420_Sub470(scene)));
}

void Unk_938ab0(void* self, u64 arg1, u32 arg2, u32 arg3);

// 0x710098a530
void Unk_23c4ef0_Scene::Unk_98a530(u64 arg1, bool arg2) {
    Unk_938ab0(Unk_98a420_Sub58(this), arg1, arg2, 0);
}

void Unk_9394d0(void* self, u64 arg1, u32 arg2, u32 arg3);

// 0x710098a570
void Unk_23c4ef0_Scene::Unk_98a570(u64 arg1, bool arg2) {
    Unk_9394d0(Unk_98a420_Sub58(this), arg1, arg2, 0);
}

void Unk_939600_call(void* self, u64 arg1, bool arg2);
void Unk_939610_call(void* self, u64 arg1, bool arg2);
void Unk_939620_call(void* self, u64 arg1, bool arg2);

// 0x710098a5b0
void Unk_23c4ef0_Scene::Unk_98a5b0(u64 arg1, bool arg2) {
    Unk_939600_call(Unk_98a420_Sub58(this), arg1, arg2);
}

// 0x710098a5f0
void Unk_23c4ef0_Scene::Unk_98a5f0(u64 arg1, bool arg2) {
    Unk_939610_call(Unk_98a420_Sub58(this), arg1, arg2);
}

// 0x710098a630
void Unk_23c4ef0_Scene::Unk_98a630(u64 arg1, bool arg2) {
    Unk_939620_call(Unk_98a420_Sub58(this), arg1, arg2);
}

void Unk_938fa0(void* self);

// 0x710098a670
void Unk_98a670(u64 scene) {
    Unk_938fa0(Unk_98a420_Sub58(reinterpret_cast<const Unk_23c4ef0_Scene*>(scene)));
}

void Unk_939630(void* self, bool arg1);

// 0x710098a690
void Unk_23c4ef0_Scene::Unk_98a690(bool arg1) {
    Unk_939630(Unk_98a420_Sub58(this), arg1);
}

struct Unk_939650;
void Unk_939650_setField38(Unk_939650* self, u64 value);

// 0x710098a6c0
void Unk_23c4ef0_Scene::Unk_98a6c0(u64 arg1) {
    Unk_939650_setField38(reinterpret_cast<Unk_939650*>(Unk_98a420_Sub58(this)), arg1);
}

void Unk_939660(void* self);

// 0x710098a6f0
void Unk_98a6f0(void* scene) {
    Unk_939660(Unk_98a420_Sub58(static_cast<const Unk_23c4ef0_Scene*>(scene)));
}
