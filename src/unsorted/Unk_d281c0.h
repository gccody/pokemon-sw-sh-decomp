#pragma once
// 0x7100d281c0 starts an effect through a global effect manager (0x7100e43620):
// the type, the object the effect follows, the offset from it, ..., the
// effect's name and its scale. Placeholder names: rename once the manager is
// known.
#include <arm_neon.h>
#include <utility>

#include <types.h>

#include "gflib3/Unk_239a418.h"
#include "unsorted/Unk_d0c0.h"

// What an effect follows: an object's handle, taken over from the object's getter.
// The parameter's type isn't known; this one converts from the handle the way the
// original's call does (into a temporary of its own).
class Unk_d281c0_Target {
public:
    Unk_d281c0_Target(Unk_239a418_Ref<Unk_239a418_Handle>&& handle) : m_handle(std::move(handle)) {}

    Unk_239a418_Ref<Unk_239a418_Handle> m_handle;
};

void Unk_d281c0_call(u32 type,
                     Unk_d281c0_Target target,
                     const float32x4_t& offset,
                     const void* arg3,
                     Unk_5cfaf0_Name name,
                     float scale);
