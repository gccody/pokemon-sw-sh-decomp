// Scope: common
// A step on Unk_23f4e40 (vtable 0x71023bc760): what starts one on a manager
// and hands back its handle, its destructor and thunks, and its vf8, which
// takes its context's reference and makes the object (Unk_23a7be8) its
// member at +0xa8 holds. Its factory (0x71008e3540) is in another unit, and
// its vf7, vf9, vf10 and type getter are defined elsewhere. Placeholder
// names: rename once the classes are known.
#include <utility>

#include <types.h>

#include "gflib3/Unk_239a418.h"
#include "gflib3/Unk_239a4c0.h"
#include "gflib3/Unk_New.h"
#include "unsorted/Unk_23f4e40.h"

// A reference to an object on Unk_239a4c0: added and dropped through its
// +0x48 interface, as Unk_239a418_Ref does for Unk_239a418's.
template <class T>
class Unk_8e1cf0_Ref {
public:
    explicit Unk_8e1cf0_Ref(T* ptr) : m_ptr(ptr) {
        if (m_ptr)
            static_cast<Unk_239a4f8*>(m_ptr)->vf3();
    }
    Unk_8e1cf0_Ref(Unk_8e1cf0_Ref&& other) : m_ptr(other.Release()) {}
    ~Unk_8e1cf0_Ref() {
        if (m_ptr) {
            static_cast<Unk_239a4f8*>(m_ptr)->vf4();
            m_ptr = nullptr;
        }
    }

    Unk_8e1cf0_Ref& operator=(Unk_8e1cf0_Ref&& other) {
        if (m_ptr) {
            static_cast<Unk_239a4f8*>(m_ptr)->vf4();
            m_ptr = nullptr;
        }
        m_ptr = other.Release();
        return *this;
    }

    T* Release() {
        T* p = m_ptr;
        m_ptr = nullptr;
        return p;
    }

    T* m_ptr;
};

// The object vf8 makes (src/unsorted/virtual/Unk_7816d0.cpp has its
// destructor and slots).
class Unk_23a7be8 : public Unk_239a4c0 {
public:
    explicit Unk_23a7be8(Unk_239a418_Allocator* allocator);
    ~Unk_23a7be8() override;

    u8 _58[0x38];
};
static_assert(sizeof(Unk_23a7be8) == 0x90, "Unk_23a7be8");

// A member with an out-of-line destructor (0x7100fc25f0).
struct Unk_fc25f0 {
    ~Unk_fc25f0();

    u64 field_0;
    Unk_8e1cf0_Ref<Unk_23a7be8> field_8;
    u8 _10[0x88];
};
static_assert(__builtin_offsetof(Unk_fc25f0, field_8) == 0x8, "Unk_fc25f0::field_8");

// What a step is started with.
struct Unk_8e1e50_Context {
    u8 _0[0x68];
    Unk_239a418_Ref<Unk_239a418> field_68;
};
static_assert(__builtin_offsetof(Unk_8e1e50_Context, field_68) == 0x68,
              "Unk_8e1e50_Context::field_68");

class Unk_23bc760 : public Unk_23f4e40 {
public:
    ~Unk_23bc760() override;
    const Unk_239a418_Type* vf_type() override;
    u32 vf7() override;
    void vf8() override;
    u32 vf9() override;
    void vf10() override;

    u32 field_88;
    u32 field_8c;
    Unk_8e1e50_Context* field_90;
    Unk_239a418_Ref<Unk_239a418> field_98;
    Unk_239a418_Ref<Unk_239a418> field_a0;
    Unk_fc25f0 field_a8;
    Unk_239a418_Ref<Unk_239a418> field_140;
    u8 _148[0x20];
    Unk_239a418_Ref<Unk_239a418> field_168;
    Unk_239a418_Ref<Unk_239a418> field_170;
    u8 _178[0x18];
    Unk_239a418_Ref<Unk_239a418> field_190;
    Unk_239a418_Ref<Unk_239a418> field_198;
    Unk_8e1e50_Context* field_1a0;
    Unk_239a418_Ref<Unk_239a418> field_1a8;
    u8 _1b0[0x8];
    Unk_239a418_Ref<Unk_239a418> field_1b8;
    u8 _1c0[0x8];
    Unk_239a418_Ref<Unk_239a418> field_1c8;
    u8 _1d0[0x18];
    Unk_239a418_Ref<Unk_239a418> field_1e8;
    u8 _1f0[0x8];
    Unk_239a418_Ref<Unk_239a418> field_1f8;
    u8 _200[0x138];
    Unk_239a418_Ref<Unk_239a418> field_338;
};
static_assert(sizeof(Unk_23bc760) == 0x340, "Unk_23bc760");
static_assert(__builtin_offsetof(Unk_23bc760, field_a8) == 0xa8, "Unk_23bc760::field_a8");
static_assert(__builtin_offsetof(Unk_23bc760, field_140) == 0x140, "Unk_23bc760::field_140");
static_assert(__builtin_offsetof(Unk_23bc760, field_1a0) == 0x1a0, "Unk_23bc760::field_1a0");
static_assert(__builtin_offsetof(Unk_23bc760, field_338) == 0x338, "Unk_23bc760::field_338");

struct Unk_24ba560_Object {
    u8 _0[0x68];
    Unk_239a418_Allocator* field_68;
};
static_assert(__builtin_offsetof(Unk_24ba560_Object, field_68) == 0x68,
              "Unk_24ba560_Object::field_68");

extern Unk_24ba560_Object* Unk_24ba560;

// What runs the steps.
class Unk_8e1ef0_Manager : public Unk_239a418 {};

// The two references Unk_c38350 takes, as pointers. Passed by value, and
// not trivially copyable (its copy is the caller's temporary, stored after
// the references it was made from are dropped).
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

// 0x71008e3540, not decompiled yet (the step's constructor is inlined into
// it). Declared as a specialization so it isn't instantiated here: the
// original calls it.
template <>
Unk_23bc760* Unk_New::Create<Unk_23bc760, Unk_239a418_Allocator*&, Unk_8e1e50_Context*&>(
    Unk_239a418_Allocator* allocator,
    Unk_239a418_Allocator*& arg1,
    Unk_8e1e50_Context*& arg2);

// Adds a step to the manager and hands back its handle.
inline Unk_239a418_Ref<Unk_239a418_Handle> Unk_8e1ef0_Add(Unk_8e1ef0_Manager* self,
                                                          Unk_239a418_Ref<Unk_23f4e40> step) {
    Unk_c38350_Pair pair(step.m_ptr->field_70, step.m_ptr->field_78);
    Unk_c38350(self, pair);
    Unk_239a418_Ref<Unk_239a418_Handle> handle(step.m_ptr->m_handle);
    Unk_e9db40(self, std::move(step));
    // Moved, not named-return optimized: the original keeps the handle in a
    // register and stores it to the result last.
    return std::move(handle);
}

// Makes a T on the steps' allocator and adds it to the manager.
template <class T, class... Args>
Unk_239a418_Ref<Unk_239a418_Handle> Unk_8e1ef0(Unk_8e1ef0_Manager* self, Args&&... args) {
    T* step = Unk_New().Create<T>(Unk_24ba560->field_68, std::forward<Args>(args)...);
    return Unk_8e1ef0_Add(self, Unk_239a418_Ref<Unk_23f4e40>(step));
}

struct Unk_8e1e50_Self {
    u8 _0[0x68];
    Unk_239a418_Ref<Unk_8e1ef0_Manager> field_68;
};
static_assert(__builtin_offsetof(Unk_8e1e50_Self, field_68) == 0x68, "Unk_8e1e50_Self::field_68");

// 0x71008e1e50
Unk_239a418_Ref<Unk_239a418_Handle> Unk_8e1e50(Unk_8e1e50_Self* self, Unk_8e1e50_Context* context) {
    Unk_239a418_Allocator* allocator = Unk_24ba560->field_68;
    // Tests its own copy of the pointer: a null manager is passed as zero.
    Unk_239a418_Ref2<Unk_8e1ef0_Manager> manager(self->field_68);
    return Unk_8e1ef0<Unk_23bc760>(manager.m_ptr, allocator, context);
}

// 0x71008e1ef0
template Unk_239a418_Ref<Unk_239a418_Handle> Unk_8e1ef0<Unk_23bc760>(
    Unk_8e1ef0_Manager* self,
    Unk_239a418_Allocator*& allocator,
    Unk_8e1e50_Context*& context);

// 0x71008e2010 (D2, its D1), its thunks for +0x48 (0x71008e21b0 D1,
// 0x71008e21e0 D0) and +0x50 (0x71008e21c0 D1, 0x71008e21f0 D0), and the D0
// 0x71008e21d0
Unk_23bc760::~Unk_23bc760() {
    field_1b8.Reset();
}

// 0x71008e2210
void Unk_23bc760::vf8() {
    field_8c = 0;
    field_90 = field_1a0;
    {
        Unk_239a418_Ref<Unk_239a418> context(field_1a0->field_68);
        std::swap(field_98.m_ptr, context.m_ptr);
    }
    Unk_239a418_Allocator* allocator = field_8;
    field_a8.field_8 =
        Unk_8e1cf0_Ref<Unk_23a7be8>(Unk_New().Create<Unk_23a7be8>(allocator, allocator));
}
