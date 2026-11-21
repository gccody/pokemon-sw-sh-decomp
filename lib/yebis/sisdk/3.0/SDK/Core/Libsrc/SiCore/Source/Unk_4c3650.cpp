// Scope: common
// SiSDK3::SiMemorySystem (RTTI): the process's heap. Every block is malloc'ed
// with a header (SiSDK3::SiMemoryBlock, RTTI-named as its lists' element) in
// front, and listed by the low 16 bits of its address. The file's name isn't
// in the executable.
#include <stdlib.h>

#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/SiCore_CriticalSection.h>
#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/SiCore_LinkedList.h>
#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/SiCore_Reflection.h>

// 0x7102769960, 0x7102769961: whether the memory system exists, and whether
// it is bypassed
bool Unk_2769960;
bool Unk_2769961;

// what an allocator tells about itself (lib/yebis/class names the type after
// 0x71004be540, its first user)
struct Unk_4be540_arg1 {
    u64 field_0;
    u64 field_8;
    u64 field_10;
    u64 field_18;
    u64 field_20;
    u64 field_28;
    u64 field_30;
};

namespace SiSDK3 {

// the kernel and its system info, as far as this file calls them
class Unk_SystemInfo {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual u64 vf9();
};
class Unk_Kernel {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
    virtual void vf14();
    virtual Unk_SystemInfo* vf15();
};

}  // namespace SiSDK3

// 0x71004bf730: the kernel
SiSDK3::Unk_Kernel* Unk_4bf730();
// 0x71004c54a0, 0x71004c5520: string copies
void Unk_4c54a0(char* dst, size_t size, const char* src);
void Unk_4c5520(char* dst, size_t size, const char* src, s64 count);

namespace SiSDK3 {

struct SiMemoryBlock {
    SiMemoryBlock* m_pPrev;
    SiMemoryBlock* m_pNext;
    u8* field_10;          // the memory
    u64 field_18;          // the allocation's number
    size_t field_20;       // its size
    size_t field_28;       // its element count
    const char* field_30;  // its file
    s64 field_38;          // its line
};

class SiMemorySystem {
public:
    SiMemorySystem() : field_30(0x10000) {
        field_280038 = 0;
        field_280040 = 0;
        field_280048 = 0;
        field_280050 = 0;
        field_280058 = 0;
        field_280060 = 0;
        field_280068 = 0;
        field_280070 = nullptr;
        field_280078 = static_cast<u64>(-1);
        field_280080 = nullptr;
        field_280088 = -1;
        Unk_2769960 = true;
    }
    virtual ~SiMemorySystem();  // 0x71004c3650, 0x71004c39b0

    // sorts blocks by their allocations' numbers
    struct Unk_Sorter {
        bool Unk_4c3e40(s64 count, SiMemoryBlock** blocks);  // 0x71004c3e40
    };

    void Unk_4c3740();                                                                       // 0x71004c3740
    void* Unk_4c39e0(size_t size, size_t count, int alignment, const char* file, int line);  // 0x71004c39e0
    bool Unk_4c3c70(void* p, const char* file, int line);                                    // 0x71004c3c70
    size_t Unk_4c3da0(void* p);                                                              // 0x71004c3da0
    size_t Unk_4c3df0(void* p);                                                              // 0x71004c3df0
    void Unk_4c3f80(Unk_4be540_arg1* value);                                                 // 0x71004c3f80
    void Unk_4c4040(u64 value);                                                              // 0x71004c4040
    u64 Unk_4c4050();                                                                        // 0x71004c4050
    void Unk_4c4060(u64 value);                                                              // 0x71004c4060
    u64 Unk_4c4070();                                                                        // 0x71004c4070
    u64 Unk_4c4080();                                                                        // 0x71004c4080

    // the critical section as the destructor's lock takes it: by its offset,
    // an address the compiler doesn't share with the member's own
    ISiCriticalSection* Unk_CriticalSection() {
        return reinterpret_cast<ISiCriticalSection*>(reinterpret_cast<u8*>(this) + 8);
    }
    // the header of a block's memory, by the offset kept before it
    static SiMemoryBlock* Unk_Block(void* p) {
        return reinterpret_cast<SiMemoryBlock*>(static_cast<u8*>(p) - static_cast<int*>(p)[-3]);
    }

    SiCoreCriticalSection field_8;
    u32 field_30;  // how many lists
    SiDirectLinkedList<SiMemoryBlock*> field_38[0x10000];
    size_t field_280038;  // bytes allocated
    size_t field_280040;  // the most there were
    size_t field_280048;  // allocations
    u64 field_280050;     // allocations so far
    size_t field_280058;  // the most there were
    size_t field_280060;  // bytes taken, headers and all
    size_t field_280068;  // the most there were
    u8* field_280070;     // the highest end of a block
    u64 field_280078;     // traps at this allocation,
    u8* field_280080;     // at this address
    s64 field_280088;     // and at this size
};
PKMN_SIZE_ASSERT(SiMemoryBlock, 0x40);
PKMN_OFFSET_ASSERT(SiMemorySystem, field_38, 0x38);
PKMN_OFFSET_ASSERT(SiMemorySystem, field_280038, 0x280038);
PKMN_SIZE_ASSERT(SiMemorySystem, 0x280090);

// 0x71004c3650, 0x71004c39b0
SiMemorySystem::~SiMemorySystem() {
    { Unk_4c87b0 lock(Unk_CriticalSection(), true); }
    if (field_280048 != 0) {
        Unk_4c3740();
    }
    Unk_2769960 = false;
}

// 0x7102769968: the blocks that 0x71004c3740 goes through
SiMemoryBlock* Unk_2769968[1000];

// 0x71004c3740: goes through the blocks still allocated, the first thousand
void SiMemorySystem::Unk_4c3740() {
    char text[0x400];
    size_t i;
    int n = 0;
    for (i = 0; i < field_30; i++) {
        for (SiMemoryBlock* block = field_38[i].m_pHead; block != nullptr; block = block->m_pNext) {
            n++;
        }
    }
    int limit = n > 999 ? 1000 : n;
    if (limit < 1) {
        return;
    }
    int count = 0;
    for (i = 0; i < field_30; i++) {
        for (SiMemoryBlock* block = field_38[i].m_pHead; count < limit && block != nullptr; block = block->m_pNext) {
            Unk_2769968[count] = block;
            count++;
        }
    }
    Unk_Sorter sorter;
    sorter.Unk_4c3e40(count, Unk_2769968);
    int lines = 0;
    for (s64 j = 0; j < limit; j++) {
        SiMemoryBlock* block = Unk_2769968[j];
        if (block->field_38 >= 1) {
            if (block->field_30 != nullptr) {
                Unk_4c54a0(text, sizeof(text), block->field_30);
            } else {
                Unk_4c5520(text, sizeof(text), "Unknown File", -1);
            }
            if (++lines >= 100) {
                break;
            }
        }
    }
    lines = 0;
    for (s64 j = 0; j < limit; j++) {
        SiMemoryBlock* block = Unk_2769968[j];
        if (block->field_38 == 0) {
            if (block->field_30 != nullptr) {
                Unk_4c54a0(text, sizeof(text), block->field_30);
            } else {
                Unk_4c5520(text, sizeof(text), "Unknown File", -1);
            }
            if (++lines >= 100) {
                break;
            }
        }
    }
}

// 0x71004c3e40
bool SiMemorySystem::Unk_Sorter::Unk_4c3e40(s64 count, SiMemoryBlock** blocks) {
    if (count < 2) {
        return true;
    }
    s64 middle;
    s64 pivot = count / 2;
    if (pivot < count) {
        SiMemoryBlock* t = blocks[0];
        blocks[0] = blocks[pivot];
        blocks[pivot] = t;
        SiMemoryBlock* first = blocks[0];
        s64 i = 1;
        s64 j = count - 1;
        while (i <= j) {
            // (the scans, bottom-tested as the original's are)
            if (first->field_18 > blocks[i]->field_18) {
                do {
                    if (++i >= j) {
                        break;
                    }
                } while (first->field_18 > blocks[i]->field_18);
            }
            if (first->field_18 <= blocks[j]->field_18) {
                do {
                    if (--j <= i) {
                        break;
                    }
                } while (first->field_18 <= blocks[j]->field_18);
            }
            if (i < j) {
                t = blocks[i];
                blocks[i] = blocks[j];
                blocks[j] = t;
            }
        }
        middle = i - 1;
        t = blocks[0];
        blocks[0] = blocks[middle];
        blocks[middle] = t;
    } else {
        middle = 0;
    }
    Unk_4c3e40(middle, blocks);
    Unk_4c3e40(count - middle - 1, &blocks[middle + 1]);
    return true;
}

// 0x71004c39e0
void* SiMemorySystem::Unk_4c39e0(size_t size, size_t count, int alignment, const char* file, int line) {
    Unk_4c87b0 lock(&field_8, true);
    if (!Unk_2769960 || Unk_2769961) {
        return malloc(size);
    }
    if (size == 0) {
        return nullptr;
    }
    size_t total = size + alignment + 0x4c;
    if (alignment >= 2) {
        total = (total + (alignment - 1)) & -alignment;
    }
    SiMemoryBlock* block = static_cast<SiMemoryBlock*>(malloc(total));
    if (block == nullptr) {
        return nullptr;
    }
    u64 number = field_280050;
    block->field_30 = file;
    block->m_pPrev = nullptr;
    block->m_pNext = nullptr;
    u8* p = reinterpret_cast<u8*>(block) + 0x4c;
    if (alignment >= 1) {
        p = reinterpret_cast<u8*>((reinterpret_cast<size_t>(p) + (alignment - 1)) & -alignment);
    }
    block->field_10 = p;
    block->field_18 = number;
    block->field_20 = size;
    block->field_28 = count;
    block->field_38 = line;
    reinterpret_cast<int*>(p)[-3] = static_cast<int>(p - reinterpret_cast<u8*>(block));
    reinterpret_cast<void**>(block->field_10)[-1] = nullptr;
    field_280050++;
    if (field_280078 != 0 && block->field_18 == field_280078) {
        __builtin_debugtrap();
    }
    if (field_280080 != nullptr && block->field_10 == field_280080) {
        __builtin_debugtrap();
    }
    if (field_280088 >= 0 && block->field_20 == static_cast<size_t>(field_280088)) {
        __builtin_debugtrap();
    }
    field_38[reinterpret_cast<size_t>(block->field_10) & 0xffff].AddTail(block);
    field_280038 += size;
    field_280060 += total;
    if (field_280038 > field_280040) {
        field_280040 = field_280038;
    }
    if (field_280060 > field_280068) {
        field_280068 = field_280060;
    }
    field_280070 = field_280070 > block->field_10 + block->field_20 ? field_280070 : block->field_10 + block->field_20;
    field_280048++;
    if (field_280048 > field_280058) {
        field_280058 = field_280048;
    }
    return block->field_10;
}

// 0x71004c3c70
bool SiMemorySystem::Unk_4c3c70(void* p, const char*, int) {
    Unk_4c87b0 lock(&field_8, true);
    if (p == nullptr) {
        return false;
    }
    s64 offset = static_cast<int*>(p)[-3];
    SiMemoryBlock* block = reinterpret_cast<SiMemoryBlock*>(static_cast<u8*>(p) - offset);
    field_38[reinterpret_cast<size_t>(p) & 0xffff].Remove(block);
    field_280038 -= block->field_20;
    field_280048--;
    field_280060 -= block->field_20 + offset;
    free(block);
    return true;
}

// 0x71004c3da0
size_t SiMemorySystem::Unk_4c3da0(void* p) {
    Unk_4c87b0 lock(&field_8, true);
    if (p == nullptr) {
        return 0;
    }
    return Unk_Block(p)->field_28;
}

// 0x71004c3df0
size_t SiMemorySystem::Unk_4c3df0(void* p) {
    Unk_4c87b0 lock(&field_8, true);
    if (p == nullptr) {
        return 0;
    }
    return Unk_Block(p)->field_20;
}

// 0x71004c3f80
void SiMemorySystem::Unk_4c3f80(Unk_4be540_arg1* value) {
    Unk_4c87b0 lock(&field_8, true);
    if (value != nullptr) {
        u64 total = Unk_4bf730()->vf15()->vf9();
        value->field_0 = total;
        value->field_28 = field_280048;
        size_t used = field_280038;
        value->field_8 = used;
        value->field_20 = total - used;
        value->field_10 = field_280040;
        value->field_18 = reinterpret_cast<u64>(field_280070);
        value->field_30 = field_280058;
    }
}

// 0x71004c4040
void SiMemorySystem::Unk_4c4040(u64 value) {
    field_280078 = value;
}

// 0x71004c4050
u64 SiMemorySystem::Unk_4c4050() {
    return field_280078;
}

// 0x71004c4060
void SiMemorySystem::Unk_4c4060(u64 value) {
    field_280088 = value;
}

// 0x71004c4070
u64 SiMemorySystem::Unk_4c4070() {
    return field_280088;
}

// 0x71004c4080
u64 SiMemorySystem::Unk_4c4080() {
    return field_280050;
}

}  // namespace SiSDK3

// 0x71024e9858
static SiSDK3::SiReflectionPropertyHandle Unk_24e9858;

// 0x71024e98d0: the memory system (lib/yebis/leaf's 0x71004c3640 returns it)
SiSDK3::SiMemorySystem Unk_24e98d0 __attribute__((visibility("hidden")));
