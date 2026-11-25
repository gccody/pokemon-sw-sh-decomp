#pragma once
// Pia's station address and the classes around it, as their members use them.
//
// Unk_165fb30 is common::StationAddress (its vtable's RTTI,
// N2nn3pia6common14StationAddressE) and Unk_1652c70 is common::InetAddress
// (N2nn3pia6common11InetAddressE). Both keep the placeholder names their
// members already have; pia/common/Unk_1749cd0.h declares the same two
// classes with fewer members, so a file includes one header or the other.
#include "pia/common/Unk_165e060.h"

struct Unk_1653890_arg0;
struct Unk_165be90;

bool Unk_1653890(const Unk_1653890_arg0* self);                                // set host and port
bool Unk_1653b50(const Unk_1653890_arg0* self, const Unk_1653890_arg0* other);  // equal
u64 Unk_165be90_get(const Unk_165be90* self);                                  // the string's buffer

// A string over a buffer of its own (placeholder name after its vtable,
// 0x71023a2ca8): the buffer, its capacity and two counts.
class Unk_23a2c98 {
public:
    Unk_23a2c98() : field_18(0) {}
    virtual ~Unk_23a2c98() {}
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();

    void Unk_165c560(const char* format, ...);  // formats into the string

    char* field_8;
    u32 field_10;
    u32 field_14;
    u32 field_18;
};
PKMN_OFFSET_ASSERT(Unk_23a2c98, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_23a2c98, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_23a2c98, field_18, 0x18);

namespace nn {
namespace pia {
namespace common {

// RTTI N2nn3pia6common11FixedStringILj48EEE: a string of up to N characters
// of up to 4 bytes each, in the object.
template <u32 N>
class FixedString : public Unk_23a2c98 {
public:
    FixedString() {
        field_8 = m_Buffer;
        field_10 = N * 4;
        field_14 = 0;
        for (u32 i = 0; i < sizeof(m_Buffer); ++i) {
            m_Buffer[i] = '\0';
        }
        field_14 = 0;
        field_18 = 0;
    }
    virtual ~FixedString() {}
    virtual void vf3();
    virtual void vf5();

    char m_Buffer[N * 4 + 1];
};

// RTTI N2nn3pia6common16SocketStreamBaseE. Its member at 0x710165ffd0
// (clearing field_8) is Unk_165ffd0_set, a leaf function.
class SocketStreamBase {
public:
    SocketStreamBase();
    virtual ~SocketStreamBase();

    Unk_165e060 Unk_165ff70();             // sets field_8
    Unk_165e060 Unk_165ffe0(void* value);  // sets field_10

    bool field_8;
    void* field_10;
};
PKMN_OFFSET_ASSERT(SocketStreamBase, field_8, 0x8);
PKMN_OFFSET_ASSERT(SocketStreamBase, field_10, 0x10);
PKMN_SIZE_ASSERT(SocketStreamBase, 0x18);

}  // namespace common

// A polymorphic 0x20-byte value: 16 bytes compared with memcmp
// (0x7101653860) and a u16.
class Unk_1652c70 {
public:
    Unk_1652c70();
    Unk_1652c70(const Unk_1652c70& other);
    virtual ~Unk_1652c70();

    Unk_1652c70& operator=(const Unk_1652c70& other);  // copies both fields
    void Unk_1652fe0(Unk_23a2c98* out) const;            // writes itself as text
    u32 Unk_16532e0() const;                             // its serialized size
    Unk_165e060 Unk_1653370(u8* buffer, u32* size, u32 capacity) const;
    Unk_165e060 Unk_1653520(const u8* buffer, u32 size);
    void Unk_16538d0();  // clears both fields

    u8 field_8[0x10];
    u16 field_18;
};
PKMN_OFFSET_ASSERT(Unk_1652c70, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_1652c70, field_18, 0x18);
PKMN_SIZE_ASSERT(Unk_1652c70, 0x20);

// A polymorphic wrapper of one Unk_1652c70, which it serializes.
class Unk_165fb30 {
public:
    Unk_165fb30();
    Unk_165fb30(const Unk_165fb30& other);
    virtual ~Unk_165fb30() {}
    virtual Unk_165e060 vf2(u8* buffer, u32* size, u32 capacity);
    virtual Unk_165e060 vf3(const u8* buffer, u32 size);
    virtual u32 vf4();
    virtual void vf5();

    Unk_165fb30& operator=(const Unk_165fb30& other);
    void Unk_165fb70();
    bool Unk_165fd30() const;
    bool Unk_165fd40(const Unk_165fb30& other) const;
    Unk_165e060 Unk_165fd90(const Unk_1652c70& value);  // sets field_8
    void Unk_165fdf0(Unk_23a2c98* out) const;           // writes field_8 as text

    Unk_1652c70 field_8;
};
PKMN_OFFSET_ASSERT(Unk_165fb30, field_8, 0x8);
PKMN_SIZE_ASSERT(Unk_165fb30, 0x28);

}  // namespace pia
}  // namespace nn
