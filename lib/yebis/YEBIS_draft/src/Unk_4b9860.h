// PPFX::IPfxInterface (RTTI names the class; members are placeholders): the
// reference-counted base of YEBIS's contexts and render-to-texture objects.
// The header's name isn't in the executable (placeholder, after its
// translation unit's static initialiser).
#pragma once

#include <types.h>

namespace PPFX {

class IPfxInterface {
public:
    IPfxInterface();            // 0x71004b97d0
    virtual s32 vf0();          // 0x71004b9750: adds a reference
    virtual s32 vf1();          // 0x71004b9770: drops one, and deletes the object with the last
    virtual s32 vf2();          // 0x71004b9820: the count
    virtual ~IPfxInterface();   // 0x71004b97f0, 0x71004b9810
    virtual s32 vf5();          // 0x71004b9830: whether it holds anything

    s32 field_8;  // the reference count
    void* field_10;
};
PKMN_SIZE_ASSERT(IPfxInterface, 0x18);

}  // namespace PPFX
