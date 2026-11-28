#pragma once
// What gflnet3's sync ping thread is handed (src/gflnet3/src/p2p/sync/ping/
// Unk_6c2a10.h): 0x168 bytes of data and an optional value, behind an
// interface with two implementations: Unk_23a3d58 keeps a copy of the data,
// Unk_23a3d88 points at someone else's. The data starts with a header
// (Unk_6c2200_Header). Placeholder names: rename once the classes are known.
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

// The data's header.
struct Unk_6c2200_Header {
    u16 field_0;
    u16 field_2 : 12;
    bool field_4;
};
PKMN_SIZE_ASSERT(Unk_6c2200_Header, 0x6);

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
    Unk_23a3d58(const void* data, const u64* size);
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
