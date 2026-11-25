// Scope: common
//
// Script commands of game/unk_133d350 (0x71013b0640-0x71013b0dc0), entries of
// a command table that take the script's context and its arguments (as
// src/field/content/Unk_13f1360.h): each takes a reference to an object the
// globals Unk_24ba5a8 and Unk_24ba4e0 hold and calls one of its functions.
// Placeholder names: rename once the classes are known.
#include "unsorted/unk_133d350/Unk_13b0640.h"

void Unk_13b19d0(Unk_13b0640_Inner* self, Unk_239a418_Allocator* allocator);

void Unk_ca42d0(Unk_13b0640_Object* self);
bool Unk_ca4370(Unk_13b0640_Object* self);
void Unk_ca43b0(Unk_13b0640_Object* self);
bool Unk_ca45b0(Unk_13b0640_Object* self);

s32 Unk_134c550(Unk_13b09f0_Object* self, s32 value);
s32 Unk_134c6e0(Unk_13b09f0_Object* self, s32 value);
void Unk_134c7a0(Unk_13b09f0_Object* self, s32 value);
s32 Unk_134c880(Unk_13b09f0_Object* self, s32 value);
s32 Unk_134c8a0(Unk_13b09f0_Object* self, s32 value);
void Unk_134c8c0(Unk_13b09f0_Object* self, s32 value);
void Unk_134c8e0(Unk_13b09f0_Object* self, s32 value);
void Unk_134c970(Unk_13b09f0_Object* self, s32 value);

// 0x71013b0640
s64 Unk_13b0640(Unk_66efd0* self, const Unk_13f1360_Args* args) {
    Unk_239a418_Allocator* allocator = Unk_24ba560->field_68;
    Unk_13b19d0(Unk_13b0640_GetInner(), allocator);
    return 1;
}

// 0x71013b06d0
s64 Unk_13b06d0(Unk_66efd0* self, const Unk_13f1360_Args* args) {
    Unk_239a418_Ref2<Unk_13b0640_Object> object = Unk_13b0640_GetInner()->field_668;
    return Unk_ca4370(object.m_ptr);
}

// 0x71013b0790
s64 Unk_13b0790(Unk_66efd0* self, const Unk_13f1360_Args* args) {
    Unk_13b0640_Inner* inner = Unk_13b0640_GetInner();
    Unk_ca42d0(inner->field_668.m_ptr);
    inner->field_668.Reset();
    return 1;
}

// 0x71013b0810
s64 Unk_13b0810(Unk_66efd0* self, const Unk_13f1360_Args* args) {
    Unk_239a418_Ref2<Unk_13b0640_Object> object = Unk_13b0640_GetInner()->field_668;
    return object.m_ptr->field_b0;
}

// 0x71013b08c0
s64 Unk_13b08c0(Unk_66efd0* self, const Unk_13f1360_Args* args) {
    s32 value = args->field_8;
    Unk_239a418_Ref2<Unk_13b09f0_Object> object = Unk_24ba4e0->field_290;
    return Unk_134c550(object.m_ptr, value);
}

// 0x71013b0950
s64 Unk_13b0950(Unk_66efd0* self, const Unk_13f1360_Args* args) {
    s32 value = args->field_8;
    Unk_239a418_Ref2<Unk_13b09f0_Object> object = Unk_24ba4e0->field_290;
    return Unk_134c6e0(object.m_ptr, value);
}

// 0x71013b09f0
s64 Unk_13b09f0(Unk_66efd0* self, const Unk_13f1360_Args* args) {
    s32 value = args->field_8;
    Unk_239a418_Ref2<Unk_13b09f0_Object> object = Unk_24ba4e0->field_290;
    Unk_134c8e0(object.m_ptr, value);
    return 1;
}

// 0x71013b0a70
s64 Unk_13b0a70(Unk_66efd0* self, const Unk_13f1360_Args* args) {
    s32 value = args->field_8;
    Unk_239a418_Ref2<Unk_13b09f0_Object> object = Unk_24ba4e0->field_290;
    Unk_134c970(object.m_ptr, value);
    return 1;
}

// 0x71013b0af0
s64 Unk_13b0af0(Unk_66efd0* self, const Unk_13f1360_Args* args) {
    s32 value = args->field_8;
    Unk_239a418_Ref2<Unk_13b09f0_Object> object = Unk_24ba4e0->field_290;
    Unk_134c7a0(object.m_ptr, value);
    return 1;
}

// 0x71013b0b70
s64 Unk_13b0b70(Unk_66efd0* self, const Unk_13f1360_Args* args) {
    s32 value = args->field_8;
    Unk_239a418_Ref2<Unk_13b09f0_Object> object = Unk_24ba4e0->field_290;
    return Unk_134c880(object.m_ptr, value);
}

// 0x71013b0c00
s64 Unk_13b0c00(Unk_66efd0* self, const Unk_13f1360_Args* args) {
    s32 value = args->field_8;
    Unk_239a418_Ref2<Unk_13b09f0_Object> object = Unk_24ba4e0->field_290;
    return Unk_134c8a0(object.m_ptr, value);
}

// 0x71013b0c90
s64 Unk_13b0c90(Unk_66efd0* self, const Unk_13f1360_Args* args) {
    s32 value = args->field_8;
    Unk_239a418_Ref2<Unk_13b09f0_Object> object = Unk_24ba4e0->field_290;
    Unk_134c8c0(object.m_ptr, value);
    return 1;
}

// 0x71013b0d10
s64 Unk_13b0d10(Unk_66efd0* self, const Unk_13f1360_Args* args) {
    Unk_239a418_Ref2<Unk_13b0640_Object> object = Unk_13b0640_GetInner()->field_668;
    Unk_ca43b0(object.m_ptr);
    return 1;
}

// 0x71013b0dc0
s64 Unk_13b0dc0(Unk_66efd0* self, const Unk_13f1360_Args* args) {
    Unk_239a418_Ref2<Unk_13b0640_Object> object = Unk_13b0640_GetInner()->field_668;
    return Unk_ca45b0(object.m_ptr);
}
