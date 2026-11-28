// Scope: common
// More ID classifiers (0x71007ebdb0 to 0x71007ebf50, in the style of
// Unk_7eb5d0.cpp), what makes the object Unk_27cec58 holds (0x71007ec0c0 lets
// it go: src/unsorted/leaf/Unk_7e89c0.cpp), and a constructor that makes 30
// Unk_23ac818s. Placeholder names: rename once the functions are known.
#include <types.h>

#include "gflib3/Unk_239a418.h"
#include "gflib3/Unk_239a4c0.h"
#include "gflib3/Unk_New.h"

extern const u16 Unk_1f11454[92] __attribute__((visibility("hidden")));

// 0x71007ebdb0
bool Unk_7ebdb0(u16 value) {
    for (u32 i = 0; i < 92; i++) {
        if (Unk_1f11454[i] == value)
            return true;
    }
    return false;
}

// 0x71007ebe00
bool Unk_7ebe00(u16 value) {
    static const u16 kValues[] = {0xc,   0x20,  0x31,  0x44,  0x45,  0x52,  0x5a,  0x65,
                                  0x75,  0x95,  0xa2,  0xf3,  0x11b, 0x149, 0x170, 0x203,
                                  0x2ba, 0x2cd, 0x2eb, 0x2ec, 0x2ed, 0x2ee, 0x2f0, 0x2f1,
                                  0x2f4, 0x307, 0x309, 0x317, 0x318};
    for (u32 i = 0; i < 29; i++) {
        if (kValues[i] == value)
            return true;
    }
    return false;
}

// 0x71007ebec0
bool Unk_7ebec0(u16 value) {
    static const u16 kValues[] = {0x122, 0x296, 0x298, 0x2a5, 0x2bf, 0x30a,
                                  0x30c, 0x310, 0x313, 0x314, 0x315, 0x316};
    for (u32 i = 0; i < 12; i++) {
        if (kValues[i] == value)
            return true;
    }
    return false;
}

// 0x71007ebf20
bool Unk_7ebf20(u16 value) {
    switch (value) {
        case 0x6:
        case 0x7:
        case 0x8:
        case 0xe:
        case 0x13:
            return true;
    }
    return false;
}

// 0x71007ebf50
bool Unk_7ebf50(u16 value) {
    switch (value) {
        case 0x0:
        case 0x1:
        case 0x2:
        case 0x3:
        case 0x6:
        case 0x7:
        case 0x8:
        case 0xe:
        case 0x11:
        case 0x13:
            return true;
    }
    return false;
}

// A reference to an object on Unk_239a4c0: added and dropped through its
// +0x48 interface (as src/unsorted/unk_8bf520/Unk_8e1cf0.cpp's).
template <class T>
class Unk_7ebdb0_Ref {
public:
    Unk_7ebdb0_Ref() : m_ptr(nullptr) {}
    explicit Unk_7ebdb0_Ref(T* ptr) : m_ptr(ptr) {
        if (m_ptr)
            static_cast<Unk_239a4f8*>(m_ptr)->vf3();
    }
    Unk_7ebdb0_Ref(Unk_7ebdb0_Ref&& other) : m_ptr(other.Release()) {}
    ~Unk_7ebdb0_Ref() {
        if (m_ptr) {
            static_cast<Unk_239a4f8*>(m_ptr)->vf4();
            m_ptr = nullptr;
        }
    }

    Unk_7ebdb0_Ref& operator=(Unk_7ebdb0_Ref&& other) {
        if (m_ptr) {
            static_cast<Unk_239a4f8*>(m_ptr)->vf4();
            m_ptr = nullptr;
        }
        m_ptr = other.Release();
        return *this;
    }

    // Lets go of the object: cleared first, then released.
    void Reset() {
        T* p = m_ptr;
        m_ptr = nullptr;
        if (p)
            static_cast<Unk_239a4f8*>(p)->vf4();
    }
    T* Release() {
        T* p = m_ptr;
        m_ptr = nullptr;
        return p;
    }

    T* m_ptr;
};
static_assert(sizeof(Unk_7ebdb0_Ref<Unk_239a4c0>) == 0x8, "Unk_7ebdb0_Ref");

// The object (src/unsorted/unk_8bf520/Unk_8e1cf0.cpp makes one too).
class Unk_23a7be8 : public Unk_239a4c0 {
public:
    explicit Unk_23a7be8(Unk_239a418_Allocator* allocator);
    ~Unk_23a7be8() override;

    u8 _58[0x38];
};
static_assert(sizeof(Unk_23a7be8) == 0x90, "Unk_23a7be8");

extern Unk_7ebdb0_Ref<Unk_23a7be8> Unk_27cec58;

// Makes the object, unless there is one.
// 0x71007ebfc0
void Unk_7ebfc0(Unk_239a418_Allocator* allocator) {
    if (Unk_27cec58.m_ptr != nullptr)
        return;
    Unk_27cec58 = Unk_7ebdb0_Ref<Unk_23a7be8>(Unk_New().Create<Unk_23a7be8>(allocator, allocator));
}

// 0x470 bytes, allocated 16-aligned (its constructor, 0x71007ed820, stores the
// vtable 0x71023ac818 and keeps its last argument at +0x460).
class Unk_23ac818 : public Unk_239a4c0 {
public:
    Unk_23ac818(Unk_239a418_Allocator* allocator, void* arg);

    alignas(16) u8 _60[0x410];
};
static_assert(sizeof(Unk_23ac818) == 0x470, "Unk_23ac818");
static_assert(alignof(Unk_23ac818) == 0x10, "Unk_23ac818");

// Cleared by 0x71007fc1c0 (src/unsorted/leaf/Unk_7f8780.cpp).
struct Unk_7fc1c0 {
    Unk_7fc1c0();

    u64 field_0;
    u64 field_8;
    u64 field_10;
    u64 field_18;
    u64 field_20;
    u64 field_28;
    u8 field_30;
};
PKMN_SIZE_ASSERT(Unk_7fc1c0, 0x38);

void Unk_7fc1c0_set(Unk_7fc1c0* self);

inline Unk_7fc1c0::Unk_7fc1c0() {
    Unk_7fc1c0_set(this);
}

struct Unk_7ec0f0 {
    Unk_7ec0f0(Unk_239a418_Allocator* allocator, u64 value, void* arg);

    u64 field_0;
    Unk_7fc1c0 field_8[5];
    Unk_7ebdb0_Ref<Unk_239a4c0> field_120[30];
    Unk_7ebdb0_Ref<Unk_23ac818> field_210[30];
};
PKMN_OFFSET_ASSERT(Unk_7ec0f0, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_7ec0f0, field_120, 0x120);
PKMN_OFFSET_ASSERT(Unk_7ec0f0, field_210, 0x210);
PKMN_SIZE_ASSERT(Unk_7ec0f0, 0x300);

// 0x71007ec0f0
Unk_7ec0f0::Unk_7ec0f0(Unk_239a418_Allocator* allocator, u64 value, void* arg) : field_0(value) {
    for (u32 i = 0; i < 30; i++) {
        field_120[i].Reset();
        field_210[i] =
            Unk_7ebdb0_Ref<Unk_23ac818>(Unk_New().Create<Unk_23ac818>(allocator, allocator, arg));
    }
}
