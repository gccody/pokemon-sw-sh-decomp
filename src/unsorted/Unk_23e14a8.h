#pragma once
// The classes on Unk_23e14a8 (vtable 0x71023e14a8, abstract), in
// game/unk_bba3d0: each is made from a table of a serialized buffer
// (unsorted/Unk_Table.h) and makes an object of a class of its own, on
// Unk_23dc940, from its owner (Unk_ccb8c0_Owner), which it places with the
// table's position and rotation. 34 of them are one class but for the object
// they make (src/unsorted/Unk_23e14a8.cpp): 0x7100cb8960 makes them, from a
// switch. Placeholder names: rename once the classes are known.
//
// Don't include this with unsorted/Unk_23dc940.h: it declares Unk_23dc940
// again, with the members these classes set (two vectors, which need the
// class aligned to 16; that header's has them as words).
#include <arm_neon.h>
#include <memory>
#include <utility>
#include <vector>

#include "gflib3/Unk_239a418.h"
#include "gflib3/Unk_New.h"
#include "unsorted/Unk_23f4660.h"
#include "unsorted/Unk_2771620.h"
#include "unsorted/Unk_Table.h"

// The type 0x71027771d8: its getter is out of line.
struct Unk_27771d8 {
    static const Unk_239a418_Type* Unk_GetType();
};

// The type 0x71027771c8 (Unk_23c1a68's).
struct Unk_27771c8 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_27771d8::Unk_GetType());
        return &type;
    }
};

// What the classes make, as they use it: its type, its position (+0xb0) and
// rotation (+0xa0) with the flag that they changed, and three more members.
class Unk_23dc940 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_27771c8::Unk_GetType());
        return &type;
    }

    ~Unk_23dc940() override;
    const Unk_239a418_Type* vf_type() override;
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
    virtual void vf14();
    virtual void vf15();
    virtual void vf16();
    virtual bool vf17();
    virtual void vf18();
    virtual void vf19();
    virtual void vf20();
    virtual void vf21();
    virtual void vf22();
    virtual void vf23();
    virtual void vf24();
    virtual void vf25();
    virtual void vf26();
    virtual void vf27();
    virtual void vf28();
    virtual void vf29();
    virtual void vf30();
    virtual void vf31();
    virtual void vf32();
    virtual void vf33();
    virtual void vf34();
    virtual void vf35();
    virtual void vf36();
    virtual void vf37();
    virtual void vf38();
    virtual void vf39(const u64& a, const u64& b);

    void Unk_SetField360(f32 value) { field_360 = value; }
    void Unk_SetRotation(const float32x4_t& value) {
        field_a0 = value;
        field_c0 = true;
    }
    void Unk_SetPosition(const float32x4_t& value) {
        field_b0 = value;
        field_c0 = true;
    }

    u8 _60[0x40];
    float32x4_t field_a0;
    float32x4_t field_b0;
    bool field_c0;
    u8 _c1[0x12f];
    u64 field_1f0;
    u8 _1f8[0x168];
    f32 field_360;
};
PKMN_OFFSET_ASSERT(Unk_23dc940, field_a0, 0xa0);
PKMN_OFFSET_ASSERT(Unk_23dc940, field_c0, 0xc0);
PKMN_OFFSET_ASSERT(Unk_23dc940, field_1f0, 0x1f0);
PKMN_OFFSET_ASSERT(Unk_23dc940, field_360, 0x360);

// Whether an object's type is T's or one derived from it (the same template
// as tools/typegen.py's; 0x71013a6cd0 for Unk_23dc940).
template <class T>
bool Unk_61a530(Unk_239a498* object) {
    const Unk_239a418_Type* type = object->vf_type();
    const Unk_239a418_Type* kind = T::Unk_GetType();
    for (; type != nullptr; type = type->field_0)
        if (type == kind)
            return true;
    return false;
}

// Takes over the other's reference, letting go of its own first.
template <class T>
void Unk_23e14a8_Assign(Unk_239a418_Ref<T>& to, Unk_239a418_Ref<T>&& from) {
    if (to.m_ptr) {
        static_cast<Unk_239a458*>(to.m_ptr)->vf5();
        to.m_ptr = nullptr;
    }
    to.m_ptr = from.Release();
}

// A rotation from three angles, in radians (0x7100972c70, not decompiled).
float32x4_t Unk_972c70(f32 a, f32 b, f32 c);

// A member of Unk_23e14a8 (vtable 0x71023e15a8): tables, each with a number.
// Its destructor is inline (D2 0x7100ccb4b0, D0 0x7100ccb4f0).
struct Unk_23e15a8_Entry {
    const Unk_Table* field_0;
    s32 field_8;
};

class Unk_23e15a8 {
public:
    virtual ~Unk_23e15a8() {}

    // The table to use (0x7100c840d0, not decompiled), null when there's none.
    const Unk_Table* Unk_c840d0();

    u64 field_8 = 0;
    std::vector<Unk_23e15a8_Entry, Unk_2771620_Allocator<Unk_23e15a8_Entry>> field_10;
};
PKMN_SIZE_ASSERT(Unk_23e15a8, 0x40);

// What an object is made from: the owner's field_78 and what the class was
// made with.
struct Unk_ccb8c0_Arg;
struct Unk_ccb8c0_Field78 {
    u8 _0[0x38];
};

// The element of the owner's vector (its push_back's slow path is
// 0x7100cca0a0, in src/gflib3/families/Unk_5ac520.cpp).
struct Unk_cca0a0 : Unk_239a418 {};

// What makes the objects, with its allocator, and keeps a reference to each.
class Unk_ccb8c0_Owner {
public:
    template <class T>
    T* Create(Unk_ccb8c0_Arg* arg) {
        if (arg == nullptr)
            return nullptr;
        T* object = Unk_New().Create<T>(field_48, field_48, field_78, arg);
        if (object != nullptr) {
            // The reference is made on the object, then handed to the vector's
            // element: the original stores the element after it adds the reference.
            Unk_239a418_Ref<T> ref(object);
            Unk_239a418_Ref2<Unk_cca0a0> element(nullptr);
            element.m_ptr = static_cast<Unk_cca0a0*>(static_cast<Unk_239a418*>(ref.Release()));
            field_b0.push_back(std::move(element));
        }
        return object;
    }

    u8 _0[0x48];
    Unk_239a418_Allocator* field_48;
    u8 _50[0x28];
    Unk_ccb8c0_Field78 field_78;
    std::vector<Unk_239a418_Ref2<Unk_cca0a0>, Unk_2771620_Allocator<Unk_239a418_Ref2<Unk_cca0a0>>>
        field_b0;
};
PKMN_OFFSET_ASSERT(Unk_ccb8c0_Owner, field_48, 0x48);
PKMN_OFFSET_ASSERT(Unk_ccb8c0_Owner, field_78, 0x78);
PKMN_OFFSET_ASSERT(Unk_ccb8c0_Owner, field_b0, 0xb0);

// A type-erased callable, 0x80 bytes, like Unk_23d4470_Callable
// (src/unsorted/Unk_23d4470.h): an invoker (+0x0) that takes the storage
// (+0x20) and references to the arguments, what disposes of the storage
// (+0x8), and what copies and moves it. The functions of the ones here are
// decompiled as functions of their own (src/unsorted/leaf), so Set takes them.
template <class Signature>
class Unk_23e14a8_Callable;

template <class R, class... Args>
class Unk_23e14a8_Callable<R(Args...)> {
public:
    using Invoke = R (*)(void* storage, Args&&... args);
    using Dispose = void (*)(void* storage);
    using Copy = void (*)(const void* from, void* to);

    ~Unk_23e14a8_Callable() {
        if (Dispose dispose = field_8) {
            field_18 = nullptr;
            field_10 = nullptr;
            field_8 = nullptr;
            field_0 = nullptr;
            dispose(field_20);
        }
    }

    // Holds a callable that captures one pointer.
    template <class A, class B, class C, class D>
    void Set(void* captured, A invoke, B dispose, C copy, D move) {
        *reinterpret_cast<void**>(field_20) = captured;
        field_0 = reinterpret_cast<Invoke>(invoke);
        field_8 = reinterpret_cast<Dispose>(dispose);
        field_10 = reinterpret_cast<Copy>(copy);
        field_18 = reinterpret_cast<Copy>(move);
    }

    R operator()(Args... args) { return field_0(field_20, std::forward<Args>(args)...); }

    Invoke field_0;
    Dispose field_8;
    Copy field_10;
    Copy field_18;
    alignas(16) u8 field_20[0x60];
};

// The base, 0x80 bytes. Its own virtual functions (slots 4 to 25) aren't
// decompiled; its destructor is inline.
class Unk_23e14a8 {
public:
    Unk_23e14a8(const Unk_Table& table, const u64& value)
        : field_8(&table),
          field_10(value),
          field_18(table.Get<u64>(0x18, 0)),
          field_20(0),
          field_24(false),
          field_25(false),
          field_28(nullptr),
          field_78(false) {}
    virtual ~Unk_23e14a8() {}
    virtual void vf2(u64 value) = 0;
    virtual void vf3(u64 value) = 0;
    virtual void vf4();
    virtual bool vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual bool vf13(Unk_ccb8c0_Arg* const& arg);
    virtual bool vf14();
    virtual void vf15();
    virtual void vf16();
    virtual void vf17();
    virtual void vf18();
    virtual void vf19();
    virtual void vf20();
    virtual void vf21();
    virtual void vf22();
    virtual void vf23();
    virtual void vf24();
    virtual void vf25();
    virtual u32 vf26() = 0;
    virtual void vf27() = 0;
    virtual void vf28() = 0;
    virtual bool vf29() = 0;

    // Whether the object it made is gone (or it has made none).
    bool Unk_IsGone() const {
        return field_70.m_ptr == nullptr || field_70.m_ptr->field_54.load() == 0;
    }
    // The object it made, null when it's gone.
    Unk_23dc940* Unk_Object() const {
        if (field_70.m_ptr == nullptr)
            return nullptr;
        Unk_239a498* object = reinterpret_cast<Unk_239a498*>(field_70.m_ptr->field_60);
        if (object == nullptr)
            return nullptr;
        return Unk_61a530<Unk_23dc940>(object) ? static_cast<Unk_23dc940*>(object) : nullptr;
    }

    const Unk_Table* field_8;
    u64 field_10;
    u64 field_18;
    f32 field_20;
    bool field_24;
    bool field_25;
    const Unk_Table* field_28;
    Unk_23e15a8 field_30;
    Unk_239a418_Ref<Unk_239a418_Handle> field_70;
    bool field_78;
};
PKMN_OFFSET_ASSERT(Unk_23e14a8, field_30, 0x30);
PKMN_OFFSET_ASSERT(Unk_23e14a8, field_70, 0x70);
PKMN_SIZE_ASSERT(Unk_23e14a8, 0x80);

// What vf3 of each class calls with the owner and the class's field_80: the
// object the class made, made first if there's none (or it's gone) and
// placed as the table says: a position, and a rotation in degrees. `static`
// (a function of each TU): it is the body of a function of each class.
template <class Object>
static Unk_23dc940* Unk_23e14a8_Make(Unk_23e14a8* self,
                                     Unk_ccb8c0_Owner* owner,
                                     Unk_ccb8c0_Arg* arg) {
    if (self->Unk_IsGone()) {
        Unk_23e14a8_Assign(self->field_70, owner->Create<Object>(arg)->vf2());
        self->Unk_Object()->field_1f0 = self->field_10;
        self->Unk_Object()->Unk_SetField360(self->field_20);
        if (const Unk_Table* table = self->field_30.Unk_c840d0()) {
            const Unk_Table* placement = table->GetPointer<Unk_Table>(4);
            f32 px = placement->Get<f32>(4, 0);
            f32 py = placement->Get<f32>(6, 0);
            f32 pz = placement->Get<f32>(8, 0);
            float32x4_t position = {px, py, pz, 0};
            f32 rx = placement->Get<f32>(0xa, 0);
            f32 ry = placement->Get<f32>(0xc, 0);
            f32 rz = placement->Get<f32>(0xe, 0);
            float32x4_t rotation = Unk_972c70(ry * 3.1415927f / 180.0f, rx * 3.1415927f / 180.0f,
                                              rz * 3.1415927f / 180.0f);
            u64 a = placement->Get<u64>(0x1a, 0);
            u64 b = table->Get<u64>(8, 0);
            self->Unk_Object()->Unk_SetPosition(position);
            self->Unk_Object()->Unk_SetRotation(rotation);
            self->Unk_Object()->vf39(a, b);
        }
    }
    return self->Unk_Object();
}

// The class of an object, 16-byte aligned: only its size and its constructor
// are known.
#define UNK_23E14A8_OBJECT(Object, size)            \
    class alignas(16) Object : public Unk_239a418 { \
    public:                                         \
        Object(Unk_239a418_Allocator* allocator,    \
               Unk_ccb8c0_Field78& field_78,        \
               Unk_ccb8c0_Arg* arg);                \
        ~Object() override;                         \
                                                    \
        u8 _60[(size) - 0x60];                      \
    };                                              \
    PKMN_SIZE_ASSERT(Object, size)

// One of the 34 classes, 0x110 bytes: what it was made with (+0x80) and a
// callable that calls its vf13 (+0x90), which vf14 calls with it. A macro,
// not a template: the classes are named after their vtables, and their vf2,
// vf3 and vf26 to vf29 are written under those names by tools/vtables.py
// (src/unsorted/virtual/Unk_cc9be0.cpp). `Make` is the function vf3 calls and
// the last four are the callable's functions (src/unsorted/leaf), by the
// names they were decompiled under.
#define UNK_23E14A8_CLASS(Class, Object, Make, Call, Dispose, Copy, Move)                  \
    struct Call;                                                                           \
    void Call##_call(const Call* self);                                                    \
    void Dispose##_update();                                                               \
    struct Copy;                                                                           \
    struct Copy##_arg1;                                                                    \
    void Copy##_set(const Copy* self, Copy##_arg1* value);                                 \
    struct Move;                                                                           \
    struct Move##_arg1;                                                                    \
    void Move##_set(const Move* self, Move##_arg1* value);                                 \
                                                                                           \
    class Class : public Unk_23e14a8 {                                                     \
    public:                                                                                \
        Class(Unk_ccb8c0_Arg& arg, const Unk_Table& table, const u64& value)               \
            : Unk_23e14a8(table, value), field_80(&arg) {                                  \
            field_90.Set(this, &Call##_call, &Dispose##_update, &Copy##_set, &Move##_set); \
        }                                                                                  \
        ~Class() override;                                                                 \
        void vf2(u64 value) override;                                                      \
        void vf3(u64 value) override;                                                      \
        bool vf14() override {                                                             \
            return field_90(field_80);                                                     \
        }                                                                                  \
        u32 vf26() override;                                                               \
        void vf27() override;                                                              \
        void vf28() override;                                                              \
        bool vf29() override;                                                              \
                                                                                           \
        Unk_ccb8c0_Arg* field_80;                                                          \
        Unk_23e14a8_Callable<bool(Unk_ccb8c0_Arg*)> field_90;                              \
    };                                                                                     \
    PKMN_SIZE_ASSERT(Class, 0x110);                                                        \
                                                                                           \
    Class::~Class() {}                                                                     \
                                                                                           \
    Unk_23dc940* Make(void* self, u64 a1, u64 a2) {                                        \
        return Unk_23e14a8_Make<Object>(static_cast<Class*>(self),                         \
                                        reinterpret_cast<Unk_ccb8c0_Owner*>(a1),           \
                                        reinterpret_cast<Unk_ccb8c0_Arg*>(a2));            \
    }                                                                                      \
                                                                                           \
    template std::unique_ptr<Class, Unk_23f4660_Deleter>                                   \
    Unk_2771620_MakeUnique<Class, Unk_ccb8c0_Arg&, const Unk_Table&, u64&>(                \
        Unk_239a418_Allocator*, Unk_ccb8c0_Arg&, const Unk_Table&, u64&)
