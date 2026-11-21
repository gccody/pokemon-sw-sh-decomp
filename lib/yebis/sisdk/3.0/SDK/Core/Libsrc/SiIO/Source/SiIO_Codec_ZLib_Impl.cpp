// Scope: common
// SiSDK3::SiIOCodecZLib.
#define UNK_SIIO_CODEC_ZLIB_IMPL
#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiIO/Source/SiIO_Codec_ZLib_Impl.h>

extern "C" {
int compress2(unsigned char* dest, unsigned long* destLen, const unsigned char* source, unsigned long sourceLen, int level);
int uncompress(unsigned char* dest, unsigned long* destLen, const unsigned char* source, unsigned long sourceLen);
}

namespace SiSDK3 {

// 0x710057de20
SiIOCodecZLib::SiIOCodecZLib(ISiAllocator* pAllocator) : field_8(pAllocator) {}

// 0x710057de40 (D2), 0x710057de60 (D0)
SiIOCodecZLib::~SiIOCodecZLib() {}

// 0x710057dea0
s64 SiIOCodecZLib::vf5(const void* /*src*/, s64 size) {
    return static_cast<s64>(static_cast<float>(size) * 1.0001f) + 16;
}

// 0x710057dec0
bool SiIOCodecZLib::vf6(const void* src, s64 size, void* dst, s64* dstSize) {
    unsigned long length = *dstSize;
    int result = compress2(static_cast<unsigned char*>(dst), &length, static_cast<const unsigned char*>(src), size, 9);
    *dstSize = result == 0 ? length : 0;
    return result == 0;
}

// 0x710057df10
bool SiIOCodecZLib::vf7(const void* src, s64 size, void* dst, s64 dstSize) {
    unsigned long length = dstSize;
    return uncompress(static_cast<unsigned char*>(dst), &length, static_cast<const unsigned char*>(src), size) == 0;
}

}  // namespace SiSDK3
