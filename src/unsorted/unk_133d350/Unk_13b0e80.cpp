// Scope: common
//
// More script commands on the objects of src/unsorted/unk_133d350/Unk_13b0640.h
// (0x71013b0e80-0x71013b1150), two helpers after them that read and write a
// command's string arguments, and a step's factory (0x71013b14c0).
// 0x71013b1210 and 0x71013b13b0 aren't here: they inline Unk_d0c0_String's
// constructor from a C string (src/unsorted/Unk_d0c0.h), which that header
// declares out of line. Placeholder names: rename once the classes are known.
#include <utility>

#include "gflib3/Unk_New.h"
#include "unsorted/Unk_23f4e40.h"
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
u32 Unk_66f050(void* dst, const u64* src, u32 wide, u64 size);
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

// 0x71013b14c0 makes a step and adds it to a manager, as
// src/unsorted/unk_8bf520/Unk_8e1cf0.cpp's Unk_8e1ef0 does: the step class
// (as declared in src/unsorted/virtual/Unk_da2e20.cpp) and copies of that
// file's manager, pair and template. Move them to a shared header once one
// holds them.
class Unk_23eeaf0 : public Unk_23f4e40 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23f4e40::Unk_GetType());
        return &type;
    }

    ~Unk_23eeaf0() override;
    const Unk_239a418_Type* vf_type() override;
    u32 vf7() override;
    void vf8() override;
    u32 vf9() override;
    void vf10() override;
};

class Unk_8e1ef0_Manager : public Unk_239a418 {};

struct Unk_c38350_Pair {
    Unk_c38350_Pair(Unk_239a418_Ref<Unk_239a418> first, Unk_239a418_Ref<Unk_239a418> second)
        : field_0(first.m_ptr), field_8(second.m_ptr) {}
    Unk_c38350_Pair(const Unk_c38350_Pair& other)
        : field_0(other.field_0), field_8(other.field_8) {}

    Unk_239a418* field_0;
    Unk_239a418* field_8;
};

void Unk_c38350(Unk_8e1ef0_Manager* self, Unk_c38350_Pair pair);
void Unk_e9db40(Unk_8e1ef0_Manager* self, Unk_239a418_Ref<Unk_23f4e40> step);

// 0x71013b1ac0, not decompiled (the step's constructor, 0x7100da2de0, isn't
// inlined into it). Declared as a specialization so it isn't instantiated
// here: the original calls it.
template <>
Unk_23eeaf0* Unk_New::Create<Unk_23eeaf0>(Unk_239a418_Allocator* allocator);

inline Unk_239a418_Ref<Unk_239a418_Handle> Unk_8e1ef0_Add(Unk_8e1ef0_Manager* self,
                                                          Unk_239a418_Ref<Unk_23f4e40> step) {
    Unk_c38350_Pair pair(step.m_ptr->field_70, step.m_ptr->field_78);
    Unk_c38350(self, pair);
    Unk_239a418_Ref<Unk_239a418_Handle> handle(step.m_ptr->m_handle);
    Unk_e9db40(self, std::move(step));
    // Moved, not named-return optimized (as in Unk_8e1cf0.cpp).
    return std::move(handle);
}

template <class T, class... Args>
Unk_239a418_Ref<Unk_239a418_Handle> Unk_8e1ef0(Unk_8e1ef0_Manager* self, Args&&... args) {
    T* step = Unk_New().Create<T>(Unk_24ba560->field_68, std::forward<Args>(args)...);
    return Unk_8e1ef0_Add(self, Unk_239a418_Ref<Unk_23f4e40>(step));
}

// 0x71013b14c0
template Unk_239a418_Ref<Unk_239a418_Handle> Unk_8e1ef0<Unk_23eeaf0>(Unk_8e1ef0_Manager* self);
