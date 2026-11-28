#pragma once
// What gflnet3's sync ping thread is handed (src/gflnet3/src/p2p/sync/ping/
// Unk_6c2a10.h): 0x168 bytes of data and an optional value, behind an
// interface with two implementations: Unk_23a3d58 keeps a copy of the data,
// Unk_23a3d88 points at someone else's. The data starts with a header
// (Unk_6c2200_Header). Placeholder names: rename once the classes are known.
#include <cstring>
#include <new>

#include <types.h>

// The optional value. Its members are initialised (not a POD), so assigning
// one copies 6 bytes, not the tail padding.
struct Unk_23a3d58_Value {
    u32 field_0 = 0;
    u16 field_4 = 0;
};
PKMN_SIZE_ASSERT(Unk_23a3d58_Value, 0x8);

inline bool operator==(const Unk_23a3d58_Value& a, const Unk_23a3d58_Value& b) {
    return a.field_0 == b.field_0 && a.field_4 == b.field_4;
}

// A value or none: the flag first, then the value (as in Unk_6c2a10.h).
template <class T>
class Unk_6c2200_Optional {
public:
    Unk_6c2200_Optional() : m_has(false) {}
    Unk_6c2200_Optional(const T& value) : m_has(false) { Construct(value); }
    Unk_6c2200_Optional(const Unk_6c2200_Optional& other) : m_has(false) {
        if (other.m_has)
            Construct(other.m_value);
    }
    ~Unk_6c2200_Optional() { Reset(); }

    Unk_6c2200_Optional& operator=(const Unk_6c2200_Optional& other) {
        if (m_has) {
            if (other.m_has)
                m_value = other.m_value;
            else
                Reset();
        } else if (other.m_has) {
            Construct(other.m_value);
        }
        return *this;
    }

    void Construct(const T& value) {
        ::new (&m_value) T(value);
        m_has = true;
    }

    void Reset() {
        if (m_has) {
            m_value.~T();
            m_has = false;
        }
    }

    explicit operator bool() const { return m_has; }
    const T& operator*() const { return m_value; }

    bool m_has;
    union {
        T m_value;
    };
};

template <class T>
bool operator==(const Unk_6c2200_Optional<T>& a, const Unk_6c2200_Optional<T>& b) {
    if (a && b)
        return *a == *b;
    return bool(a) == bool(b);
}

using Unk_23a3d58_OptionalValue = Unk_6c2200_Optional<Unk_23a3d58_Value>;
PKMN_SIZE_ASSERT(Unk_23a3d58_OptionalValue, 0xc);

// The data's header: the checksum of the rest, the 12-bit id (Unk_6c2a10.h's
// Unk_6c2b60) and a flag. The id and the flag are written a bit at a time
// (0x71006c1ce0), at the bits they have here.
struct Unk_6c2200_Header {
    u16 field_0;
    u16 field_2 : 12;
    u16 : 4;
    bool field_4 : 1;
};
PKMN_SIZE_ASSERT(Unk_6c2200_Header, 0x6);

// The id (Unk_6c2a10.h's Unk_6c2b60): 12 bits in four fields, which the
// serialiser writes one by one.
struct Unk_6c2450_Id {
    u16 field_0 : 3;
    u16 field_3 : 1;
    u16 field_4 : 4;
    u16 field_8 : 4;
};
PKMN_SIZE_ASSERT(Unk_6c2450_Id, 0x2);

// Where the serialiser writes a struct (it clears them first): its bytes, and a bit per field set
// when the field is written (in a bitmap of its own, or its parent's: a
// field's context starts at the parent's bit for it).
struct Unk_6c2450_Context {
    Unk_6c2450_Context(u8* data, u64 size)
        : m_data(data), m_size(size), m_own{}, m_written(m_own), m_index(0) {
        std::memset(m_data, 0, m_size);
    }
    Unk_6c2450_Context(const Unk_6c2450_Context& parent, u64 offset, u64 size, u64 index)
        : m_data(parent.m_data + offset),
          m_size(size),
          m_own{},
          m_written(parent.m_written),
          m_index(parent.m_index + index) {}

    // The context of the struct at the byte offset, the bitmap's bit index on.
    Unk_6c2200_Optional<Unk_6c2450_Context> Field(u64 offset, u64 size, u64 index) const {
        if (m_data == nullptr)
            return {};
        return Unk_6c2450_Context(*this, offset, size, index);
    }

    void Mark(u64 index) {
        u64 bit = m_index + index;
        m_written[bit / 8] |= 1 << (bit % 8);
    }

    // The bytes [offset, offset + size), marked written, if they fit.
    u8* Bytes(u64 offset, u64 size, u64 index) {
        if (m_data != nullptr && (offset + size) * 8 <= m_size * 8) {
            Mark(index);
            return m_data + offset;
        }
        return nullptr;
    }

    u8* m_data;
    u64 m_size;
    u8 m_own[1];
    u8* m_written;
    u64 m_index;
};
PKMN_OFFSET_ASSERT(Unk_6c2450_Context, m_own, 0x10);
PKMN_OFFSET_ASSERT(Unk_6c2450_Context, m_written, 0x18);
PKMN_SIZE_ASSERT(Unk_6c2450_Context, 0x28);

// The flags after the id.
struct Unk_6c2450_Flags {
    bool field_0 : 1;
};
PKMN_SIZE_ASSERT(Unk_6c2450_Flags, 0x1);

// The interface: the data (slot 2) and the value (slot 3).
class Unk_23a3d58_Base {
public:
    virtual ~Unk_23a3d58_Base() {}
    virtual const u8* vf2() const = 0;
    virtual Unk_23a3d58_OptionalValue vf3() const = 0;
};

// Its own copy of the data (vtable 0x71023a3d58).
class Unk_23a3d58 : public Unk_23a3d58_Base {
public:
    Unk_23a3d58() {}
    explicit Unk_23a3d58(const Unk_23a3d58_Base& other);
    ~Unk_23a3d58() override;
    const u8* vf2() const override;
    Unk_23a3d58_OptionalValue vf3() const override;

    u8 field_8[0x168];
    Unk_23a3d58_OptionalValue field_170;
};
PKMN_OFFSET_ASSERT(Unk_23a3d58, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_23a3d58, field_170, 0x170);
PKMN_SIZE_ASSERT(Unk_23a3d58, 0x180);

// Points at the data (vtable 0x71023a3d88).
class Unk_23a3d88 : public Unk_23a3d58_Base {
public:
    Unk_23a3d88(const u8* data, const Unk_23a3d58_OptionalValue& value);
    ~Unk_23a3d88() override;
    const u8* vf2() const override;
    Unk_23a3d58_OptionalValue vf3() const override;

    const u8* field_8;
    Unk_23a3d58_OptionalValue field_10;
};
PKMN_OFFSET_ASSERT(Unk_23a3d88, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_23a3d88, field_10, 0x10);
PKMN_SIZE_ASSERT(Unk_23a3d88, 0x20);
