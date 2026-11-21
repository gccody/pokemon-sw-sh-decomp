// PPFX::IGPUInterface, the reference-counted base of YEBIS's GPU objects
// (RTTI names the class; its members are placeholders), and the release
// macros of YEBIS's reference-counted objects (Unk_Array.h has its new and
// delete).
#pragma once

#include <types.h>
#include <yebis/YEBIS_draft/src/GPU/Unk_Array.h>

namespace PPFX {

class IGPUInterface {
public:
    IGPUInterface();  // 0x7100445dc0
    virtual s32 vf0();  // 0x7100445e00: adds a reference
    virtual s32 vf1();  // 0x7100445e20: drops one, and deletes the object with the last
    virtual ~IGPUInterface();  // 0x7100445de0, 0x7100445df0

    s32 field_8;  // the reference count
};
PKMN_SIZE_ASSERT(IGPUInterface, 0x10);

}  // namespace PPFX

// One reference less for a CGPUResourceManage (its release is inline in every
// user), and for an IGPUInterface (whose release is virtual); the pointer is
// cleared.
#define PPFX_SAFE_RELEASE(p)        do {                                if ((p) != nullptr) {               (p)->Unk_Release();             (p) = nullptr;              }                           } while (0)
#define PPFX_SAFE_RELEASE_INTERFACE(p)     do {                                       if ((p) != nullptr) {                      (p)->vf1();                            (p) = nullptr;                     }                                  } while (0)
