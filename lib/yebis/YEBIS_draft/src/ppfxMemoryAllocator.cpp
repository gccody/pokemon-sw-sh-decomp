// Scope: common
// PPFX::CPfxMemoryAllocator (RTTI) and the allocator every YEBIS allocation
// goes through. C:/workspace/YEBIS_draft/src/ppfxMemoryAllocator.cpp is the
// __FILE__ of its log lines, which name SetMemoryAllocator and
// CPfxMemoryAllocator::AllocMemory; the other names are placeholders.
#include <stdlib.h>

#include <miniz/miniz_yebis.h>
#include <yebis/YEBIS_draft/src/GPU/Unk_StaticsBase.h>

#define PPFX_FILE "C:/workspace/YEBIS_draft/src/ppfxMemoryAllocator.cpp"
#include <yebis/YEBIS_draft/src/GPU/Unk_Log.h>

namespace PPFX {

// (Unk_4b99a0_arg0 to the code that doesn't name it: lib/miniz, Unk_Array.h)
class CPfxMemoryAllocator {
public:
    CPfxMemoryAllocator();  // 0x71004b9980
    // 0x71004b9aa0 (deleting). The destructor itself is an empty inline
    // function, whose copy the linker kept is game code's (0x710069d640):
    // registering it for this file's own allocator is dropped as a no-op.
    virtual ~CPfxMemoryAllocator() {}
    virtual void vf2();                                                              // 0x71004b9a90
    virtual void* AllocMemory(size_t size, const char* file, int line, void* arg4);  // 0x71004b99d0
    virtual void vf4(void* p);                                                       // 0x71004b9a80: frees
};

// 0x71024e7970: how many allocations there are
static u32 Unk_24e7970;

// 0x71024e7978: the allocator that is used until another one is set
static CPfxMemoryAllocator Unk_24e7978;

// 0x71004b98f0
s32 SetMemoryAllocator(CPfxMemoryAllocator* allocator) {
    if (Unk_24e7970 != 0) {
#line 109
        PPFX_ERROR("SetMemoryAllocator(): Call when any pfx interface is not instantiated yet.\n");
        return -1;
    }
    Unk_238d5f8 = reinterpret_cast<Unk_4b99a0_arg0*>(allocator != nullptr ? allocator : &Unk_24e7978);
    return 0;
}

// 0x71004b9980
CPfxMemoryAllocator::CPfxMemoryAllocator() {}

}  // namespace PPFX

// 0x71004b99a0
void* Unk_4b99a0(Unk_4b99a0_arg0* self, size_t size, const char* file, int line, void* arg4) {
    void* p = reinterpret_cast<PPFX::CPfxMemoryAllocator*>(self)->AllocMemory(size, file, line, arg4);
    PPFX::Unk_24e7970 = PPFX::Unk_24e7970 + 1;
    return p;
}

namespace PPFX {

// 0x71004b99d0
void* CPfxMemoryAllocator::AllocMemory(size_t size, const char* file, int line, void* arg4) {
    void* p = malloc(size);
    if (p == nullptr) {
#line 275
        PPFX_ERROR("CPfxMemoryAllocator::AllocMemory(size: %d):\n\t%s(%d) : Out of memory.\n", size, file, line);
    }
    return p;
}

}  // namespace PPFX

// 0x71004b9a60
void Unk_4b9a60(Unk_4b99a0_arg0* self, void* p) {
    PPFX::Unk_24e7970 = PPFX::Unk_24e7970 - 1;
    reinterpret_cast<PPFX::CPfxMemoryAllocator*>(self)->vf4(p);
}

namespace PPFX {

// 0x71004b9a80
void CPfxMemoryAllocator::vf4(void* p) {
    free(p);
}

// 0x71004b9a90
void CPfxMemoryAllocator::vf2() {}

}  // namespace PPFX

// 0x71004b9ab0: _GLOBAL__sub_I_ppfxMemoryAllocator.cpp
