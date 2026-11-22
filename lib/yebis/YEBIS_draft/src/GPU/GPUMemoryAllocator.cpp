// Scope: common
// PPFX::SiYebisAllocator: SiSDK3's allocator over PPFX's. The reference
// counts are its header's.
#define UNK_SIYEBISALLOCATOR_DEFINE
#include <yebis/YEBIS_draft/src/GPU/GPUMemoryAllocator.h>

namespace PPFX {

// 0x710043c210
void* SiYebisAllocator::vf7(size_t size, s32 alignment, const char* file, int line) {
    return vf8(size, 1, alignment, file, line);
}

// 0x710043c230: count elements, aligned (to field_18 for a negative
// alignment)
void* SiYebisAllocator::vf8(size_t elementSize, size_t count, s32 alignment, const char* file, int line) {
    s32 align = alignment;
    if (align < 0) {
        align = field_18;
    }
    size_t size = count * elementSize + align + 0x18;
    if (align > 1) {
        size = (size + (align - 1)) & -align;
    }
    Unk_Block* block = static_cast<Unk_Block*>(Unk_4b99a0(Unk_238d5f8, size, file, line, nullptr));
    u8* p = reinterpret_cast<u8*>(block) + 0x18;
    if (align > 0) {
        p = reinterpret_cast<u8*>((reinterpret_cast<size_t>(p) + (align - 1)) & -align);
    }
    block->field_0 = p;
    block->field_8 = count;
    reinterpret_cast<s64*>(p)[-1] = p - reinterpret_cast<u8*>(block);
    return block->field_0;
}

// 0x710043c2d0
void SiYebisAllocator::vf9(void* p) {
    u8* bytes = static_cast<u8*>(p);
    u8* block = bytes - reinterpret_cast<s64*>(bytes)[-1];
    Unk_4b9a60(Unk_238d5f8, block);
}

// 0x710043c2f0
size_t SiYebisAllocator::vf10(void* p) {
    u8* bytes = static_cast<u8*>(p);
    return reinterpret_cast<Unk_Block*>(bytes - reinterpret_cast<s64*>(bytes)[-1])->field_8;
}

}  // namespace PPFX
