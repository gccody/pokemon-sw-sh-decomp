// Scope: common
//
// More script commands on the objects of src/unsorted/unk_133d350/Unk_13b0640.h
// (0x71013b0e80-0x71013b1150), and the helpers after them that read and write
// a command's string arguments (0x71013b1210-0x71013b14c0). Placeholder names:
// rename once the classes are known.
#include "unsorted/Unk_d0c0.h"
#include "unsorted/unk_133d350/Unk_13b0640.h"

bool Unk_ca49c0(Unk_13b0640_Object* self);
s64 Unk_ca4a70(Unk_13b0640_Object* self);
void Unk_ca4b40(Unk_13b0640_Object* self);

// Leaf placeholders (src/unsorted/leaf/Unk_c9be80.cpp) over the same object.
struct Unk_ca4e10;
struct Unk_ca4e20;
void Unk_ca4e10_call(const Unk_ca4e10* self);
bool Unk_ca4e20_check(const Unk_ca4e20* self);

// Where the script's argument `index` is (0 when it's found).
u32 Unk_66efe0(Unk_66efd0* self, s64 index, u64** out);
// Unpacks the string at `src` into `dst` (`size` characters at most, of 32
// bits when `wide`, else of 8).
u32 Unk_66f050(void* dst, const u64* src, bool wide, u64 size);
// Packs the string at `src` into `dst`.
u32 Unk_66c710(u64* dst, const void* src, bool arg2, bool arg3, s64 size);

// 0x71013b0e80
s64 Unk_13b0e80(Unk_66efd0* self, const Unk_13f1360_Args* args) {
    Unk_239a418_Ref2<Unk_13b0640_Object> object = Unk_13b0640_GetInner()->field_668;
    return Unk_ca49c0(object.m_ptr);
}

// 0x71013b0f40
s64 Unk_13b0f40(Unk_66efd0* self, const Unk_13f1360_Args* args) {
    Unk_239a418_Ref2<Unk_13b0640_Object> object = Unk_13b0640_GetInner()->field_668;
    return Unk_ca4a70(object.m_ptr);
}

// 0x71013b0ff0
s64 Unk_13b0ff0(Unk_66efd0* self, const Unk_13f1360_Args* args) {
    Unk_239a418_Ref2<Unk_13b0640_Object> object = Unk_13b0640_GetInner()->field_668;
    Unk_ca4b40(object.m_ptr);
    return 1;
}

// 0x71013b10a0
s64 Unk_13b10a0(Unk_66efd0* self, const Unk_13f1360_Args* args) {
    Unk_239a418_Ref2<Unk_13b0640_Object> object = Unk_13b0640_GetInner()->field_668;
    Unk_ca4e10_call(reinterpret_cast<const Unk_ca4e10*>(object.m_ptr));
    return 1;
}

// 0x71013b1150
s64 Unk_13b1150(Unk_66efd0* self, const Unk_13f1360_Args* args) {
    Unk_239a418_Ref2<Unk_13b0640_Object> object = Unk_13b0640_GetInner()->field_668;
    return Unk_ca4e20_check(reinterpret_cast<const Unk_ca4e20*>(object.m_ptr));
}

// 0x71013b12d0: the hash of the string argument `index`.
u64 Unk_13b12d0(Unk_66efd0* self, s64 index) {
    char str[0x80] = {};
    u64* arg = nullptr;
    Unk_66efe0(self, index, &arg);
    Unk_66f050(str, arg, false, sizeof(str));
    return Unk_5cfaf0_Name::Hash(str);
}

// 0x71013b1370: sets the string argument `index` to `str`.
u32 Unk_13b1370(Unk_66efd0* self, s64 index, const char* str) {
    u64* arg = nullptr;
    Unk_66efe0(self, index, &arg);
    return Unk_66c710(arg, str, true, false, 0x7fffffff);
}
