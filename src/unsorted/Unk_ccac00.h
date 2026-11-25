#pragma once
// Unk_23e14a8 (vtable 0x71023e14a8, abstract), the base of the classes in
// unsorted/Unk_23e14a8.h, as its own virtual functions use it
// (src/unsorted/Unk_ccac00.cpp and Unk_ccb040.cpp): what it was made from (a
// table of a serialized buffer, unsorted/Unk_Table.h), the object it made, and
// the members its setters and getters reach. Placeholder names: rename once
// the classes are known.
//
// Don't include this with unsorted/Unk_23e14a8.h: that header declares the
// class too, from what the derived classes use. The signatures here are the
// ones these functions show (vf6 returns the object, vf12 takes a reference,
// vf13 and vf14 take nothing, the setters take a value).
#include <arm_neon.h>
#include <vector>

#include "gflib3/Unk_239a418.h"
#include "unsorted/Unk_2771620.h"
#include "unsorted/Unk_Table.h"

// A vector of tables in a table: its length, then the offset of each, from
// where the offset is. Walked with iterators.
struct Unk_ccac00_Tables {
    class Iterator {
    public:
        explicit Iterator(const u8* p) : m_p(p) {}
        const Unk_Table* operator*() const {
            return reinterpret_cast<const Unk_Table*>(m_p + *reinterpret_cast<const u32*>(m_p));
        }
        Iterator& operator++() {
            m_p += sizeof(u32);
            return *this;
        }
        bool operator!=(const Iterator& other) const { return m_p != other.m_p; }

    private:
        const u8* m_p;
    };

    // Where the offsets start.
    const u8* Data() const { return reinterpret_cast<const u8*>(&m_size + 1); }
    Iterator begin() const { return Iterator(Data()); }
    Iterator end() const { return Iterator(Data() + m_size * sizeof(u32)); }

    u32 m_size;
};

// A field stored out of line that the code takes as always there: read
// without the vtable's size or a zero offset checked.
template <class T>
const T* Unk_ccac00_GetRequired(const Unk_Table* table, u16 field) {
    const u8* vtable = reinterpret_cast<const u8*>(table) - *reinterpret_cast<const s32*>(table);
    const u8* p =
        reinterpret_cast<const u8*>(table) + *reinterpret_cast<const u16*>(vtable + field);
    return reinterpret_cast<const T*>(p + *reinterpret_cast<const u32*>(p));
}

// The sum of a vector's four squared components.
inline f32 Unk_ccac00_LengthSq(float32x4_t v) {
    float32x4_t sq = vmulq_f32(v, v);
    float32x2_t sum = vadd_f32(vget_high_f32(sq), vget_low_f32(sq));
    sum = vpadd_f32(sum, sum);
    return vget_lane_f32(sum, 0);
}

// The object the classes make, as these functions use it.
class Unk_23dc940 : public Unk_239a418 {
public:
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
};
// vf_type is its slot 6 (the primary base doesn't have it): vf16 and vf17 are
// at +0x80 and +0x88.

// Whether an object's type is T's or one derived from it (0x71013a6cd0 for
// Unk_23dc940, src/unsorted/types/Unk_13a6cd0.cpp).
template <class T>
bool Unk_61a530(Unk_239a498* object);

struct Unk_23e15a8_Entry {
    const Unk_Table* field_0;
    s32 field_8;
};

// A member of Unk_23e14a8 (vtable 0x71023e15a8): tables, each with a number.
class Unk_23e15a8 {
public:
    virtual ~Unk_23e15a8() {}

    // The table to use (0x7100c840d0, not decompiled), null when there's none.
    const Unk_Table* Unk_c840d0();
    // 0x7100c83e50, not decompiled.
    void Unk_c83e50(const Unk_Table* table);

    u64 field_8;
    std::vector<Unk_23e15a8_Entry, Unk_2771620_Allocator<Unk_23e15a8_Entry>> field_10;
};
PKMN_SIZE_ASSERT(Unk_23e15a8, 0x40);

// The base, 0x80 bytes. Its destructors (D2 0x7100ccb410; D0 0x7100ccb490, a
// trap: the class is abstract) and vf14 (0x7100ccb4a0) are inline.
class Unk_23e14a8 {
public:
    virtual ~Unk_23e14a8() {}
    virtual void vf2(u64 value) = 0;
    virtual void vf3(u64 value) = 0;
    virtual void vf4();
    virtual bool vf5();
    virtual Unk_23dc940* vf6();
    virtual u64 vf7();
    virtual u64 vf8();
    virtual u64 vf9();
    virtual float32x4_t vf10();
    virtual u64 vf11();
    virtual void vf12(const u64& value);
    virtual bool vf13();
    virtual bool vf14() { return vf13(); }
    virtual bool vf15();
    virtual void vf16(bool value);
    virtual bool vf17();
    virtual void vf18(bool value);
    virtual void vf19(const Unk_Table* table);
    virtual void vf20(const Unk_Table& table);
    virtual void vf21(f32 value);
    virtual f32 vf22(const float32x4_t& position);
    virtual bool vf23();
    virtual void vf24(bool value);
    virtual u64 vf25();
    virtual u32 vf26() = 0;
    virtual void vf27() = 0;
    virtual void vf28() = 0;
    virtual bool vf29() = 0;

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
PKMN_OFFSET_ASSERT(Unk_23e14a8, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_23e14a8, field_18, 0x18);
PKMN_OFFSET_ASSERT(Unk_23e14a8, field_20, 0x20);
PKMN_OFFSET_ASSERT(Unk_23e14a8, field_24, 0x24);
PKMN_OFFSET_ASSERT(Unk_23e14a8, field_25, 0x25);
PKMN_OFFSET_ASSERT(Unk_23e14a8, field_28, 0x28);
PKMN_OFFSET_ASSERT(Unk_23e14a8, field_30, 0x30);
PKMN_OFFSET_ASSERT(Unk_23e14a8, field_70, 0x70);
PKMN_OFFSET_ASSERT(Unk_23e14a8, field_78, 0x78);
PKMN_SIZE_ASSERT(Unk_23e14a8, 0x80);
