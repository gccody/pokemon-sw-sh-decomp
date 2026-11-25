// Scope: common
// The calls of the manager Unk_27ce848 points to: each takes its mutex (+0x90)
// and forwards to the object at +0x70 (Unk_675xxx), and the handles
// (Unk_23a8158, src/unsorted/Unk_7941a0.cpp) that address it by the index
// Unk_791a00 looks up for them. Placeholder names: rename once the classes
// are known.
#include <math.h>
#include <string.h>

#include <nn/os.h>
#include <types.h>

#include "unsorted/Unk_793990.h"

struct Unk_675720;
struct Unk_675750;
struct Unk_675750_arg1;
struct Unk_6757c0;
struct Unk_6757c0_arg1;
struct Unk_6757c0_arg2;
struct Unk_6757f0;
struct Unk_6757f0_arg1;
struct Unk_6757f0_arg2;

bool Unk_6753e0(void* self, s64 index, const Unk_5cfaf0_Name* name, f32 volume);
bool Unk_6755b0(void* self, u32 value);
bool Unk_675720_call(const Unk_675720* self, u64 value);
// These two pass the index on: their names have no parameter for it.
bool Unk_675750_call(const Unk_675750* self, const Unk_675750_arg1* value, s64 index);
bool Unk_6757c0_call(const Unk_6757c0* self,
                     const Unk_6757c0_arg1* value,
                     const Unk_6757c0_arg2* arg2,
                     s64 index);
bool Unk_6757f0_call(const Unk_6757f0* self,
                     const Unk_6757f0_arg1* value,
                     const Unk_6757f0_arg2* arg2);
bool Unk_675780(void* self, const Unk_5cfaf0_Name* name, s64 index, u32 arg3, f32 arg4);

// 0x7100793990
bool Unk_793990(Unk_793990_Manager* self, const Unk_5cfaf0_Name* name, f32 decibels, s64 index) {
    nn::os::LockMutex(&self->field_90);
    bool result = Unk_6753e0(self->field_70, index, name, powf(10.0f, decibels / 20.0f));
    nn::os::UnlockMutex(&self->field_90);
    return result;
}

// 0x7100793a10
bool Unk_793a10(Unk_793990_Manager* self, u32 value) {
    nn::os::LockMutex(&self->field_90);
    bool result = Unk_6755b0(self->field_70, value);
    nn::os::UnlockMutex(&self->field_90);
    return result;
}

// NON_MATCHING: written as Unk_793a60(void*, u32): its name
// (_Z10Unk_793a60PvS_) gives the value as a pointer, the original's is 32-bit
// (it tests and passes w1).
// 0x7100793a60
bool Unk_793a60(void* manager, u32 value) {
    Unk_793990_Manager* self = static_cast<Unk_793990_Manager*>(manager);
    nn::os::LockMutex(&self->field_90);
    bool result = false;
    if (value != 0)
        result = Unk_675720_call(static_cast<const Unk_675720*>(self->field_70), value);
    nn::os::UnlockMutex(&self->field_90);
    return result;
}

// NON_MATCHING: calls Unk_675750_call with the index as a third argument, as
// the original does, which its name has no parameter for.
// 0x7100793ac0
bool Unk_793ac0(u64 manager, u64 value, u64 index) {
    Unk_793990_Manager* self = reinterpret_cast<Unk_793990_Manager*>(manager);
    nn::os::LockMutex(&self->field_90);
    bool result =
        Unk_675750_call(static_cast<const Unk_675750*>(self->field_70),
                        reinterpret_cast<const Unk_675750_arg1*>(value), static_cast<s64>(index));
    nn::os::UnlockMutex(&self->field_90);
    return result;
}

// NON_MATCHING: written as Unk_793b20(u64, u64, f32, u64, u32): its name
// (_Z10Unk_793b20mmmj) has no float parameter, and the original passes s0 on
// (kept in d8, saved between the index and the name as its other float
// parameters are).
// 0x7100793b20
bool Unk_793b20(u64 manager, u64 name, f32 arg2, u64 index, u32 arg3) {
    Unk_793990_Manager* self = reinterpret_cast<Unk_793990_Manager*>(manager);
    nn::os::LockMutex(&self->field_90);
    bool result = Unk_675780(self->field_70, reinterpret_cast<const Unk_5cfaf0_Name*>(name),
                             static_cast<s64>(index), arg3, arg2);
    nn::os::UnlockMutex(&self->field_90);
    return result;
}

// NON_MATCHING: calls Unk_6757c0_call with the index as a fourth argument, as
// the original does, which its name has no parameter for.
// 0x7100793ba0
bool Unk_793ba0(Unk_793990_Manager* self,
                const Unk_5cfaf0_Name* name,
                const Unk_5cfaf0_Name* other,
                s64 index) {
    nn::os::LockMutex(&self->field_90);
    bool result = Unk_6757c0_call(static_cast<const Unk_6757c0*>(self->field_70),
                                  reinterpret_cast<const Unk_6757c0_arg1*>(name),
                                  reinterpret_cast<const Unk_6757c0_arg2*>(other), index);
    nn::os::UnlockMutex(&self->field_90);
    return result;
}

// 0x7100793c10
bool Unk_793c10(void* manager, void* value, void* arg2) {
    Unk_793990_Manager* self = static_cast<Unk_793990_Manager*>(manager);
    nn::os::LockMutex(&self->field_90);
    bool result = Unk_6757f0_call(static_cast<const Unk_6757f0*>(self->field_70),
                                  static_cast<const Unk_6757f0_arg1*>(value),
                                  static_cast<const Unk_6757f0_arg2*>(arg2));
    nn::os::UnlockMutex(&self->field_90);
    return result;
}

// 0x7100793c70
Unk_d0c0_String Unk_793c70(const char* prefix, const Unk_d0c0_String& suffix) {
    char* buffer = static_cast<char*>(
        __builtin_alloca(strlen(prefix) + (suffix.m_ptr ? suffix.m_ptr->field_68 : 0) + 1));
    buffer[0] = '\0';
    strcat(buffer, prefix);
    strcat(buffer, Unk_793990_CStr(suffix));
    return Unk_d0c0_String(buffer);
}
