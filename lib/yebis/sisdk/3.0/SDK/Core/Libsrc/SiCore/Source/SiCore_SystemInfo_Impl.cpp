// Scope: common
// SiSDK3::SiSystemInfo: two names in buffers of its own, and what vf5 returns.
#include <string.h>

#include <nn/os.h>

#define UNK_SISYSTEMINFO_DEFINE
#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiCore/Source/SiCore_SystemInfo_Impl.h>

// 0x71004c54a0, 0x71004c5520: string copies
void Unk_4c54a0(char* dst, size_t size, const char* src);
void Unk_4c5520(char* dst, size_t size, const char* src, s64 count);

namespace SiSDK3 {

// 0x71004c88c0
SiSystemInfo::SiSystemInfo(ISiAllocator* pAllocator)
    : field_8(pAllocator), field_118(pAllocator, field_18, sizeof(field_18)),
      field_148(pAllocator, field_98, sizeof(field_98)) {
    memset(&field_178, 0, sizeof(field_178));
    Unk_4c5520(field_178.field_20, sizeof(field_178.field_20), "Unknown", -1);
    Unk_4c5520(field_178.field_30, sizeof(field_178.field_30), "Unknown", -1);
    field_178.field_10[0] = 1;
    field_178.field_10[1] = 1;
    field_178.field_10[2] = 1;
    field_178.field_10[3] = 1;
    field_178.field_0 = 1;
}

// 0x71004c89e0, 0x71004c8aa0
SiSystemInfo::~SiSystemInfo() {}

// 0x71004c8d40
void SiSystemInfo::vf6() {
    char text[0x400];
    Unk_4c54a0(text, sizeof(text), field_178.field_20);
    Unk_4c54a0(text, sizeof(text), field_178.field_30);
    vf8();
    vf9();
}

// 0x71004c8db0
void SiSystemInfo::vf7() {
    field_178.field_0 = nn::os::GetSystemTickFrequency();
    field_178.field_56 = true;
    field_178.field_50[0] = true;
    field_178.field_50[1] = true;
    field_178.field_50[2] = true;
    field_178.field_50[3] = true;
    field_178.field_54[0] = true;
    field_178.field_54[1] = true;
    field_178.field_59 = false;
    field_178.field_10[0] = 4;
    field_178.field_10[1] = 3;
    field_178.field_10[2] = 4;
    field_178.field_10[3] = 3;
}

}  // namespace SiSDK3
