// Scope: common
//
// The gflnet3 object with a thread (Unk_6c2a10.h): its setters, the
// requests' getters, its vf2 and its destructor. Part of the segment
// 0x71006c2a10-0x71006c3810 (one or more TUs). Placeholder names: rename once
// the classes are known.
#include "gflnet3/src/p2p/sync/ping/Unk_6c2a10.h"

using nn::pia::Unk_165e060;

// 0x71006c3260
void Unk_23a3db8::Unk_6c3260(const Unk_239a418_Ref<Unk_239a418>& ref) {
    Unk_23a3db8_Assign(field_150, ref);
    if (field_50)
        field_50->Unk_6c3a70(ref);
}

// 0x71006c32e0
void Unk_23a3db8::Unk_6c32e0(const Unk_23a3db8_Weak<Unk_23a3db8_Listener>& listener) {
    field_158 = listener;
}

// 0x71006c3340, its thunk from +0x48 0x71006c3390
void Unk_23a3db8::vf2() {
    if (field_50)
        Unk_5d0e50(field_50.m_ptr);
    field_158 = Unk_23a3db8_Weak<Unk_23a3db8_Listener>();
}

// 0x71006c33e0
Unk_23a3db8_Request Unk_23a3db8::Unk_6c33e0() {
    Unk_23a3db8_Lock lock(field_b0);
    return field_a8;
}

// 0x71006c3420
Unk_23a3db8_Request Unk_23a3db8::Unk_6c3420() {
    Unk_23a3db8_Lock lock(field_d8);
    return field_d0;
}

// Bits 13-17 of a result rank it: a result is kept until one ranked as high
// comes.
static u32 Unk_6c3460_Rank(const Unk_165e060& result) {
    return (result.m_Value >> 13) & 0x1f;
}

// 0x71006c3460
// NON_MATCHING: register allocation. The original keeps the two values'
// addresses in x23 (the kept one) and x22 (the new one); here they're swapped,
// and the original recomputes the kept one's address on its last path.
void Unk_23a3db8::Unk_6c3460(const Unk_23a3db8_Optional<Unk_165e060>& result) {
    Unk_23a3db8_Lock lock(field_188);
    if (!result || !field_168) {
        field_168 = result;
        return;
    }
    Unk_165e060 kept = *field_168;
    Unk_165e060 other = *result;
    if (Unk_6c3460_Rank(other) >= Unk_6c3460_Rank(kept))
        field_168 = result;
}

// 0x71006c3550
// NON_MATCHING: ordering. The original loads the other value's flag before its
// own (and tests its own first); here the loads come the other way round.
// Testing the other one's first, in the assignment, swaps the branches too.
void Unk_23a3db8::Unk_6c3550(const Unk_23a3db8_Optional<u32>& value) {
    Unk_23a3db8_Lock lock(field_188);
    field_17c = value;
}

// 0x71006c35c0 (D0 0x71006c36a0)
Unk_23a3db8::~Unk_23a3db8() {}
