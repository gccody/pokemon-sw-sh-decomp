// Scope: common
// NEX 4.6.8: the PRUDP stream templates' signature checks and the end point
// templates (see Unk_160a230.h).
#include <string.h>

#include "Unk_160a230.h"

// The values an end point gives its streams (pseudo-global: one per context).
extern nn::nex::PseudoGlobalVariable<u8> Unk_27f9070;
extern nn::nex::PseudoGlobalVariable<u8> Unk_27f9090;
// The flags an end point gives its streams.
extern u32 Unk_24517d0;
extern u32 Unk_27f90b0;

// A transport's settings, as the end point reads them.
struct Unk_27f3b38_t {
    u8 _0[0xf8];
    u8 field_f8;
    u8 _f9[3];
    u32 field_fc;
    u8 _100[0x48];
};
PKMN_OFFSET_ASSERT(Unk_27f3b38_t, field_fc, 0xfc);
PKMN_SIZE_ASSERT(Unk_27f3b38_t, 0x148);
// The settings of each transport (field_8 of an end point).
extern nn::nex::PseudoGlobalVariable<Unk_27f3b38_t> Unk_27f3b38[];

namespace nn {
namespace nex {

// 0x710160a230
u32 PRUDPStreamTemplateImp::vf5(u64 arg1, u64 arg2, u64 arg3, Unk_160a230_Message* message,
                                u64 arg5, u64 arg6, u64 arg7, u32 arg8) {
    Unk_15c6560_Digest digest;
    digest.m_size = 0;
    u32 result = m_encDec->vf5(message, arg8, arg5, arg6, arg7, &digest);
    if (result == 3) {
        return result;
    }
    if ((digest.m_size != message->m_signature.m_size ||
         memcmp(digest.m_data, message->m_signature.m_data, digest.m_size) != 0) &&
        (message->field_60 & 0xf) != 5) {
        return 2;
    }
    return 1;
}

// 0x710160a2f0 (D2), 0x710160a310 (D0)
PRUDPEndPointTemplateImp::~PRUDPEndPointTemplateImp() {}

// 0x710160a350
// NON_MATCHING: the value's store after the lookup is a byte store (strb) here and
// a word store (str) in the original, which doesn't reload the zeroed word.
void PRUDPEndPointTemplateImp::vf2(Unk_160a350_Info* info, u16* arg2) {
    *info = Unk_160a350_Info();
    info->m_value = Unk_160a230_Get(Unk_27f9070);
    info->m_flags = Unk_24517d0;
    if ((field_8 != 2 && field_8 != 10) || Unk_160a230_Get(Unk_27f3b38[field_8]).field_fc != 2) {
        info->m_flags &= ~1u;
    }
    *arg2 = Unk_160a230_Get(Unk_27f3b38[field_8]).field_f8;
}

// 0x710160a4e0
u64 PRUDPEndPointTemplateImp::vf3(u8 enabled, u32 info) {
    u32 value = info & 0xff;
    u64 flags = (info >> 8) | 0x1000000;
    if (value > 4) {
        flags |= 0x8000000;
    }
    return enabled ? flags : 0;
}

// 0x710160a510 (D2), 0x710160a520 (D0)
PRUDPStreamTemplatePRUDPLiteImp::~PRUDPStreamTemplatePRUDPLiteImp() {}

// 0x710160a530
u32 PRUDPStreamTemplatePRUDPLiteImp::vf2() {
    if (field_8 == 2 || field_8 == 10) {
        return 0x80;
    }
    return 0;
}

// 0x710160a550
// NON_MATCHING: register allocation: the original masks the value again for the
// comparison with the limit (cmp w8, w21, uxtb) instead of keeping the masked
// value in a callee-saved register (one register fewer saved).
bool PRUDPStreamTemplatePRUDPLiteImp::vf3(const Unk_160a230_Message* message,
                                          Unk_160a230_Message* out) {
    if (message->field_40 != 0x80) {
        return false;
    }
    Unk_160a350_Info info = message->field_d0;
    if (info.m_value < 5) {
        return false;
    }
    u8 limit = Unk_160a230_Get(Unk_27f9090);
    if (info.m_value > limit) {
        info.m_value = limit;
    }
    info.m_flags = message->field_d0.m_flags & Unk_27f90b0;
    out->field_d0 = info;
    return true;
}

// 0x710160a610
bool PRUDPStreamTemplatePRUDPLiteImp::vf4(Unk_160a230_Message* message, u64 arg2, u64 arg3,
                                          u64 arg4) {
    m_encDec->vf3(message, 1, nullptr, message->field_42, arg2, nullptr, arg4);
    return true;
}

// 0x710160a690
// NON_MATCHING: block layout: the signature's match returns 1 through a block of
// its own here; the original shares the first check's return.
u32 PRUDPStreamTemplatePRUDPLiteImp::vf5(u64 arg1, u64 arg2, u64 arg3,
                                         Unk_160a230_Message* message, u64 arg5, u64 arg6,
                                         u64 arg7, u32 arg8) {
    if ((message->field_60 & 0xf) == 1) {
        if (arg8 != 8 || (message->field_60 & 0x10) != 0) {
            return 1;
        }
        Unk_15c6560_Digest digest;
        digest.m_size = 0;
        u32 result = m_encDec->vf5(message, 8, arg5, arg6, arg7, &digest);
        if (result == 3) {
            return result;
        }
        if (digest.m_size == message->m_signature.m_size &&
            memcmp(digest.m_data, message->m_signature.m_data, digest.m_size) == 0) {
            return 1;
        }
        return 2;
    }
    return 1;
}

// 0x710160a650
bool PRUDPStreamTemplatePRUDPLiteImp::vf6(Unk_160a230_Message* message, u64 arg2, u64 arg3,
                                          u64 arg4) {
    m_encDec->vf3(message, 1, nullptr, message->field_42, arg2, nullptr, arg4);
    return true;
}

// 0x710160a750 (D2), 0x710160a760 (D0)
PRUDPEndPointTemplatePRUDPLiteImp::~PRUDPEndPointTemplatePRUDPLiteImp() {}

// 0x710160a770
// NON_MATCHING: as 0x710160a350, the value's store is strb here and str there.
void PRUDPEndPointTemplatePRUDPLiteImp::vf2(Unk_160a350_Info* info, u16* arg2) {
    *info = Unk_160a350_Info();
    info->m_value = Unk_160a230_Get(Unk_27f9090);
    info->m_flags = Unk_27f90b0;
    *arg2 = 0;
}

}  // namespace nex
}  // namespace nn
