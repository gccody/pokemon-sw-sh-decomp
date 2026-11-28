// Scope: common
// A request step (Unk_24175f0, on an abstract base, Unk_24176a0) that makes a
// gflib3 object (Unk_24174f0) to hear the result, hands the session its weak
// reference and sends a NEX data object (Unk_2417660) with the step's
// parameters. src/unsorted/virtual/Unk_10f17b0.cpp writes the accessors the
// steps' vtables share (under Unk_24175f0's name) and two slots of
// Unk_24174f0's (as Unk_24174f0::vf7 and Unk_24175b0::vf0, its thunk);
// src/unsorted/types/Unk_10f1c10.cpp its type getter. Placeholder classes,
// named after their vtables.
#include <cstddef>

#include <types.h>

#include "gflib3/Unk_239a418.h"
#include "gflib3/Unk_New.h"

void Unk_15b6e10(void* p);

namespace nn {
namespace nex {

// As lib/nex/include/nn/nex/RootObject.h declares it (src/ doesn't have NEX's
// include path): D0s free through 0x71015b6e10.
class RootObject {
public:
    static void operator delete(void* p) { Unk_15b6e10(p); }
    virtual ~RootObject() {}
};
PKMN_SIZE_ASSERT(RootObject, 0x8);

// As lib/nex/include/nn/nex/RefCountedObject.h declares it.
class qBuffer : public RootObject {
public:
    virtual ~qBuffer();

    u8 _8[0x30];
};
PKMN_SIZE_ASSERT(qBuffer, 0x38);

}  // namespace nex
}  // namespace nn

// 0x71015cf190: a qBuffer of `capacity` bytes, its data starting `offset` in.
void Unk_15cf190(nn::nex::qBuffer* self, size_t capacity, size_t offset);
// 0x71015cf460: moves the qBuffer's positions back to where its data starts.
void Unk_15cf460(nn::nex::qBuffer* self);
// 0x71015cf570: appends `size` bytes.
void Unk_15cf570(nn::nex::qBuffer* self, const void* data, size_t size);

// A NEX data object's fields (vtable 0x7102417690). The qBuffer is
// constructed and destroyed by hand (the anonymous union keeps C++ from doing
// it: its constructors aren't declared).
class Unk_2417680 : public nn::nex::RootObject {
public:
    Unk_2417680() : field_8(0) { Unk_15cf190(&field_10, 0, 0); }
    // 0x71010f2010 (D0: 0x71010f2030)
    ~Unk_2417680() override { field_10.~qBuffer(); }

    u8 field_8;
    u8 field_9;
    u8 field_a;
    union {
        nn::nex::qBuffer field_10;
    };
};
PKMN_OFFSET_ASSERT(Unk_2417680, field_9, 0x9);
PKMN_OFFSET_ASSERT(Unk_2417680, field_a, 0xa);
PKMN_OFFSET_ASSERT(Unk_2417680, field_10, 0x10);
PKMN_SIZE_ASSERT(Unk_2417680, 0x48);

// The data object (vtable 0x7102417670). Its D2 is its base's.
class Unk_2417660 : public Unk_2417680 {
public:
    Unk_2417660() {
        field_9 = 0;
        field_a = 0;
        Unk_15cf460(&field_10);
    }
    // D0: 0x71010f1fd0
    ~Unk_2417660() override {}
};

struct Unk_15bbd10_arg1;

extern u64 Unk_24ba150;
// 0x710104c0e0 (it doesn't use the object)
void Unk_104c0e0(u64 self, const Unk_15bbd10_arg1& value);

// The interface at +0x60 of Unk_24174f0 (vtable 0x71024175c0).
class Unk_24175b0 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4(const Unk_15bbd10_arg1& value);
    virtual void vf5();
};

// What hears the result (vtable 0x7102417500), on gflib3's object.
class Unk_24174f0 : public Unk_239a418, public Unk_24175b0 {
public:
    Unk_24174f0() : field_68(false) {}
    // The key function: the vtables, the thunks at +0x48 (0x71010f1d00,
    // 0x71010f1d50) and +0x50 (0x71010f1dc0, 0x71010f1e10) and vf_type's
    // (0x71010f1da0, 0x71010f1db0) come from here. The D0 deletes nothing (the
    // family's operator delete is empty); the D2 is Unk_239a418's.
    ~Unk_24174f0() override;

    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_239a418_GetType());
        return &type;
    }
    // 0x71010f1c10 (written by src/unsorted/types/Unk_10f1c10.cpp too)
    const Unk_239a418_Type* vf_type() override { return Unk_GetType(); }
    // 0x71010f17b0 (its thunk: 0x71010f17c0)
    void vf0() override;
    // 0x71010f17d0 (its thunk: 0x71010f1810)
    void vf4(const Unk_15bbd10_arg1& value) override {
        Unk_104c0e0(Unk_24ba150, value);
        field_68 = true;
        field_69 = false;
    }

    bool field_68;
    bool field_69;
};
PKMN_OFFSET_ASSERT(Unk_24174f0, field_68, 0x68);
PKMN_OFFSET_ASSERT(Unk_24174f0, field_69, 0x69);
PKMN_SIZE_ASSERT(Unk_24174f0, 0x70);

// 0x71010f1bc0
Unk_24174f0::~Unk_24174f0() {}

// 0x71010f2100
template Unk_24174f0* Unk_New::Create<Unk_24174f0>(Unk_239a418_Allocator* allocator);

// An object it doesn't keep alive: the handle it counts in, and the object.
// Null once the handle's count is down to zero.
template <class T>
struct Unk_10f17b0_Weak {
    Unk_10f17b0_Weak() : m_ptr(nullptr) {}
    Unk_10f17b0_Weak(const Unk_239a418_Ref2<Unk_239a418_Handle>& handle, T* ptr)
        : m_handle(handle.m_ptr), m_ptr(ptr) {}

    T* Get() const {
        if (m_handle.m_ptr == nullptr)
            return nullptr;
        if (m_handle.m_ptr->field_54.load() == 0)
            return nullptr;
        return m_ptr;
    }

    Unk_239a418_Ref<Unk_239a418_Handle> m_handle;
    T* m_ptr;
};

// A flag the listener may set, cleared when it goes.
struct Unk_10f17b0_Flag {
    Unk_10f17b0_Flag() : m_set(false) {}
    ~Unk_10f17b0_Flag() {
        if (m_set)
            m_set = false;
    }

    bool m_set;
};

// What a step tells when it's done (vf0 or vf1).
class Unk_10f17b0_Listener {
public:
    virtual void vf0();
    virtual void vf1(Unk_10f17b0_Flag* flag);
};

// vtable 0x71024176b0 (abstract: slots 2 and 3 are pure).
class Unk_24176a0 {
public:
    // 0x71010f2070 (its D0, 0x71010f20c0, traps: the class is abstract)
    virtual ~Unk_24176a0();
    virtual bool vf2() = 0;
    virtual u32 vf3() = 0;
    virtual void vf4();
    virtual void vf5();
    virtual void vf6(u64 value);
    virtual u64 vf7();
    virtual u8 vf8();
    virtual void vf9(u32 value);
    virtual u32 vf10();
    virtual Unk_10f17b0_Listener* vf11();

    u64 field_8;
    u8 field_10;
    u32 field_14;
    Unk_10f17b0_Weak<Unk_10f17b0_Listener> field_18;
};
PKMN_OFFSET_ASSERT(Unk_24176a0, field_14, 0x14);
PKMN_OFFSET_ASSERT(Unk_24176a0, field_18, 0x18);
PKMN_SIZE_ASSERT(Unk_24176a0, 0x28);

Unk_24176a0::~Unk_24176a0() {}

// 0x71010f1f50
void Unk_24176a0::vf4() {
    field_18 = Unk_10f17b0_Weak<Unk_10f17b0_Listener>();
}

// 0x71010f20d0
Unk_10f17b0_Listener* Unk_24176a0::vf11() {
    return field_18.Get();
}

struct Unk_6a43a0;
extern Unk_6a43a0* Unk_2778bf8;
// 0x71006a4320
bool Unk_6a4320(Unk_6a43a0* self);
// 0x71006a43a0
u64 Unk_6a43a0_getFieldd8(const Unk_6a43a0* self);
// 0x71006a43b0
bool Unk_6a43b0(Unk_6a43a0* self);
// 0x71006a6530: keeps the weak reference.
void Unk_6a6530(u64 self, const Unk_10f17b0_Weak<Unk_24175b0>& listener);
// 0x71006a6590
bool Unk_6a6590(u64 self, const Unk_2417660& data);

// vtable 0x7102417600.
class Unk_24175f0 : public Unk_24176a0 {
public:
    // 0x71010f1e70 (D0: 0x71010f1ee0)
    ~Unk_24175f0() override;
    bool vf2() override;
    u32 vf3() override;
    Unk_10f17b0_Listener* vf11() override;

    Unk_239a418_Allocator* field_28;
    u8 field_30;
    u8 _31[0x7];
    u32 field_38;
    const void* field_40;
    size_t field_48;
    Unk_10f17b0_Listener field_50;
    Unk_239a418_Ref<Unk_24174f0> field_58;
    bool field_60;
    bool field_61;
};
PKMN_OFFSET_ASSERT(Unk_24175f0, field_28, 0x28);
PKMN_OFFSET_ASSERT(Unk_24175f0, field_30, 0x30);
PKMN_OFFSET_ASSERT(Unk_24175f0, field_38, 0x38);
PKMN_OFFSET_ASSERT(Unk_24175f0, field_40, 0x40);
PKMN_OFFSET_ASSERT(Unk_24175f0, field_48, 0x48);
PKMN_OFFSET_ASSERT(Unk_24175f0, field_50, 0x50);
PKMN_OFFSET_ASSERT(Unk_24175f0, field_58, 0x58);
PKMN_OFFSET_ASSERT(Unk_24175f0, field_60, 0x60);
PKMN_OFFSET_ASSERT(Unk_24175f0, field_61, 0x61);
PKMN_SIZE_ASSERT(Unk_24175f0, 0x68);

Unk_24175f0::~Unk_24175f0() {}

// 0x71010f1b50
Unk_10f17b0_Listener* Unk_24175f0::vf11() {
    Unk_10f17b0_Listener* listener = field_18.Get();
    return listener != nullptr ? listener : &field_50;
}

// 0x71010f1850
bool Unk_24175f0::vf2() {
    Unk_10f17b0_Listener* listener = Unk_24175f0::vf11();
    switch (field_14) {
        case 0: {
            field_60 = Unk_6a4320(Unk_2778bf8);
            if (!field_60 || field_28 == nullptr || field_30 > 0x10 || field_48 > 0x400)
                break;
            Unk_239a418_Allocator* allocator = field_28;
            u8 type = field_30;
            u32 mode = field_38;
            const void* data = field_40;
            size_t size = field_48;
            u64 session = Unk_6a43a0_getFieldd8(Unk_2778bf8);
            field_58 = Unk_239a418_Ref<Unk_24174f0>(Unk_New().Create<Unk_24174f0>(allocator));
            if (field_58.m_ptr == nullptr)
                break;
            Unk_24174f0* object = field_58.m_ptr;
            Unk_239a418_Ref2<Unk_239a418_Handle> handle(static_cast<Unk_239a418*>(object)->vf2());
            Unk_6a6530(session, Unk_10f17b0_Weak<Unk_24175b0>(handle, object));
            Unk_2417660 request;
            request.field_9 = type;
            request.field_a = mode == 1 ? 2 : 1;
            Unk_15cf460(&request.field_10);
            if (data != nullptr)
                Unk_15cf570(&request.field_10, data, size);
            field_14 = Unk_6a6590(session, request) ? 1 : 2;
            return false;
        }
        case 1:
            if (field_58.m_ptr->field_68) {
                field_61 = field_58.m_ptr->field_69;
                break;
            }
            return false;
        case 2:
            if (field_60)
                Unk_6a43b0(Unk_2778bf8);
            if (field_61) {
                listener->vf0();
            } else {
                Unk_10f17b0_Flag flag;
                listener->vf1(&flag);
            }
            return true;
        default:
            return false;
    }
    field_14 = 2;
    return false;
}
