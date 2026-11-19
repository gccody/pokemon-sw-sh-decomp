#pragma once
// Pia's result type (placeholder name: its copy constructor's address). Not
// polymorphic, so it has no RTTI. A 32-bit value (0 is success; the low byte
// is the description, the rest the module), and the SDK error behind it for
// the two values that carry one (0xe437, 0xa46e).
#include <nn/err.h>
#include <types.h>

namespace nn {
namespace pia {

class Unk_165e060 {
public:
    Unk_165e060(u32 value) : m_Value(value) { m_Variant = nn::Result(); }
    Unk_165e060(const Unk_165e060& other);
    Unk_165e060& operator=(const Unk_165e060& other);

    bool operator==(const Unk_165e060& other) const { return m_Value == other.m_Value; }

    u32 Unk_165e380() const;  // the error code's number (2-618-xxxx is 26180000 + xxxx)
    Unk_165e060 Unk_165e210(nn::err::ErrorResultVariant* error) const;  // the SDK error
    void Unk_165fb10(const nn::err::ErrorResultVariant& variant);

    u32 m_Value;
    nn::err::ErrorResultVariant m_Variant;
};
PKMN_OFFSET_ASSERT(Unk_165e060, m_Variant, 0x4);
PKMN_SIZE_ASSERT(Unk_165e060, 0x10);

// A result with a fixed value. Returning one copies it into the caller's
// Unk_165e060 (the copy constructor), as Pia's code does.
template <u32 Value>
class Unk_165e060Value : public Unk_165e060 {
public:
    Unk_165e060Value() : Unk_165e060(Value) {}
};

Unk_165e060 Unk_165dfb0(s32 id);

}  // namespace pia
}  // namespace nn
