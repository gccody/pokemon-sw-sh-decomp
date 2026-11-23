// Scope: common
// SiSDK3::SiFixedHeapAllocator2 (C:/workspace/sisdk/3.0/SDK/Core/Libsrc/SiCore/
// Source/SiCore_FixedHeapAllocator2.cpp is the __FILE__ of its pool's
// allocation), and its instance of SiSDK3::SiPool.
#include <stdlib.h>

#define UNK_SIFIXEDHEAPALLOCATOR2_IMPL
#define UNK_SIPOOL_CLEAR
#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/SiCore_FixedHeapAllocator2.h>

// 0x71004c54a0, 0x71004c5520: string copies
void Unk_4c54a0(char* dst, size_t size, const char* src);
void Unk_4c5520(char* dst, size_t size, const char* src, s64 count);

namespace SiSDK3 {

// 0x71004bd0e0, 0x71004bec50, 0x71004bcfa0, 0x71004be3f0
// NON_MATCHING (0x71004bcfa0, Unk_4bcfa0): two instructions swapped where the
// first list takes the allocator (a register copy before the stores).
// Tried: every order of SiDirectLinkedList::Unk_SetAllocator's four stores,
// its allocator as if/else, a swapped ternary, a local, or assigned then
// tested; m_pAllocator or field_120 set first.
template bool SiPool<SiFixedHeapAllocator2::MemoryBlockHeader, 16>::vf2(size_t count);
template bool SiPool<SiFixedHeapAllocator2::MemoryBlockHeader, 16>::vf5(size_t count);
template void SiPool<SiFixedHeapAllocator2::MemoryBlockHeader, 16>::Unk_4bcfa0(ISiAllocator* pAllocator);
template void SiPool<SiFixedHeapAllocator2::MemoryBlockHeader, 16>::Unk_4be3f0(
    SiFixedHeapAllocator2::MemoryBlockHeader* item);
// 0x71004be7d0
template void SiPool<SiFixedHeapAllocator2::MemoryBlockHeader, 16>::Unk_4be7d0();
// 0x71004bf330
template bool SiArray<SiFixedHeapAllocator2::MemoryBlockHeader, 16>::Unk_4bf190(size_t count, bool keep);

// 0x71004bc7f0: SiPool's, with a block's links to itself
bool SiFixedHeapAllocator2::MemoryBlockHeaderPool::vf5(size_t count) {
    if (field_118 == count) {
        return true;
    }
    if (field_118 > count) {
        return false;
    }
    int blockCount = static_cast<int>(count + (static_cast<int>(field_110) - 1)) / static_cast<int>(field_110);
    int oldBlockCount = static_cast<int>(m_blocks.m_itemCount);
    if (blockCount == oldBlockCount) {
        return true;
    }
    if (!m_blocks.Unk_SetCount(blockCount)) {
        return false;
    }
    int index = static_cast<int>(field_110) * oldBlockCount;
    for (s64 i = oldBlockCount; i < blockCount; i++) {
#line 122
        DataArray* block = UNK_SI_NEW(m_pAllocator, 16) DataArray(m_pAllocator);
        if (block == nullptr) {
            return false;
        }
        m_blocks.m_pData[i] = block;
        block->field_8 = index;
        block->m_items.Unk_SetCount(field_110);
        for (s64 j = 0; j < static_cast<s64>(field_110); j++) {
            MemoryBlockHeader* item = &block->m_items.m_pData[j];
            item->field_10 = index + j;
            item->m_pNext = nullptr;
            item->field_18 = false;
            item->m_pPrev = nullptr;
            item->field_20.m_pHeader = item;
            item->field_38.m_pHeader = item;
            m_freeList.AddTail(item);
        }
        index += static_cast<int>(field_110);
    }
    field_118 = field_110 * blockCount;
    return true;
}

// 0x71004bca60
// NON_MATCHING: the order of the stores after the last call (the allocator, the
// zeroes of field_48, field_240 and field_2a0, the pool's vtable): every
// order of these statements tried leaves 11 to 25 instructions in other places.
SiFixedHeapAllocator2::SiFixedHeapAllocator2(ISiAllocator* pAllocator)
    : field_8(pAllocator), field_18(nullptr), field_20(nullptr), field_28(0), field_30(0), field_38(0), field_40(0),
      field_44(0), field_48(), field_60(nullptr), field_68(0), field_70(0), field_78(0), field_80(nullptr),
      field_88(0), field_90(0), field_98(0), field_a0(-1), field_a8(0), field_b0(-1), field_b8(nullptr), field_240(),
      field_2a0() {
    field_8.m_pAllocator = pAllocator != nullptr ? pAllocator : reinterpret_cast<ISiAllocator*>(this);
    field_48.field_0 = nullptr;
    field_48.field_8 = 0;
    new (Unk_Placement(), field_240) SiCoreCriticalSection;
}

// 0x71004bcc40, 0x71004bcda0
SiFixedHeapAllocator2::~SiFixedHeapAllocator2() {
    if (field_b8 != nullptr) {
        field_b8->vf3();
        field_b8 = nullptr;
    }
    Unk_CriticalSection()->~ISiCriticalSection();
}

// 0x71004bcdd0
bool SiFixedHeapAllocator2::vf21(ISiAllocator* pAllocator, int headerCount, u8* memory, size_t size) {
    field_18 = pAllocator;
    field_110.Unk_4bcfa0(pAllocator);
    field_110.vf2(headerCount);
    field_110.field_128 = this;
    field_48.field_0 = memory;
    field_20 = &field_48;
    field_28 = 1;
    field_48.field_8 = size;
    field_60 = memory;
    field_30 = size;
    MemoryBlockHeader* block = field_110.Unk_Alloc();
    block->Unk_Reset();
    block->field_50 = memory;
    block->field_60 = size;
    block->field_78 = 1;
    field_c0.AddTail(&block->field_20);
    field_e8.AddTail(&block->field_38);
    return true;
}

// 0x71004bd310
bool SiFixedHeapAllocator2::vf22(ISiAllocator* pAllocator, int headerCount, size_t regionCount, Unk_Region* regions) {
    field_18 = pAllocator;
    field_110.Unk_4bcfa0(pAllocator);
    field_110.vf2(headerCount);
    field_110.field_128 = this;
    field_20 = regions;
    field_28 = regionCount;
    field_30 = 0;
    for (size_t i = 0; i < regionCount; i++) {
        Unk_Region* region = &field_20[i];
        field_30 += region->field_8;
        MemoryBlockHeader* block = field_110.Unk_Alloc();
        block->Unk_Reset();
        block->field_50 = region->field_0;
        block->field_78 = 1;
        block->field_60 = region->field_8 - sizeof(MemoryBlockHeader);
        field_c0.AddTail(&block->field_20);
        field_e8.AddTail(&block->field_38);
        if (i == 0) {
            field_60 = region->field_0;
        } else {
            u8* memory = region->field_0;
            field_60 = field_60 < memory ? field_60 : memory;
        }
    }
    return true;
}

// 0x71004bd550
void SiFixedHeapAllocator2::vf23() {
    if (field_88 >= 1) {
        Unk_4bd610(0, true);
    }
    field_c0.RemoveAll();
    field_e8.RemoveAll();
    field_110.Unk_4bd7e0();
}

// 0x71004bd610 (inline: its unused argument reaches it from both callers).
// The load-free `n < field_88` is written last: SimplifyCFG puts it second.
inline void SiFixedHeapAllocator2::Unk_4bd610(s64 number, bool) {
    char text[0x400];
    if (field_88 < 1) {
        return;
    }
    MemoryBlockHeader** blocks = static_cast<MemoryBlockHeader**>(malloc(field_88 * sizeof(MemoryBlockHeader*)));
    if (blocks == nullptr) {
        return;
    }
    s64 n = 0;
    for (MemoryBlockPtr* node = field_c0.m_pHead; node != nullptr; node = node->m_pNext) {
        MemoryBlockHeader* block = node->m_pHeader;
        if (block->field_80 > number && block->field_58 != nullptr && n < field_88) {
            blocks[n++] = block;
        }
    }
    s64 limit = n > 255 ? 256 : n;
    Unk_Sorter sorter;
    sorter.Unk_4be580(n, blocks);
    for (s64 i = 0, lines = 0; i < limit; i++) {
        MemoryBlockHeader* block = blocks[i];
        if (block->field_84 >= 1) {
            if (block->field_88 != nullptr) {
                Unk_4c54a0(text, sizeof(text), block->field_88);
            } else {
                Unk_4c5520(text, sizeof(text), "Unknown File", -1);
            }
            if (++lines >= 100) {
                break;
            }
        }
    }
    for (s64 i = 0, lines = 0; i < limit; i++) {
        MemoryBlockHeader* block = blocks[i];
        if (block->field_84 == 0) {
            if (block->field_88 != nullptr) {
                Unk_4c54a0(text, sizeof(text), block->field_88);
            } else {
                Unk_4c5520(text, sizeof(text), "Unknown File", -1);
            }
            if (++lines >= 100) {
                break;
            }
        }
    }
    free(blocks);
}

// 0x71004bd8e0
void* SiFixedHeapAllocator2::vf7(size_t size, int alignment, const char* file, int line) {
    return vf8(size, 1, alignment, file, line);
}

// 0x71004bd900: the first free block that holds the allocation, split when
// it has room left
// NON_MATCHING: register allocation in three places (the unlink of the block
// that isn't split: prev and next swapped; the new header's reset: one store
// scheduled the other way; the insert after the block in the list of every
// block: the list's head loaded before the block's next link). Same
// instructions otherwise.
void* SiFixedHeapAllocator2::vf8(size_t elementSize, size_t count, int alignment, const char* file, int line) {
    Unk_4c87b0 lock(Unk_CriticalSection(), true);
    if (alignment < 0) {
        alignment = field_40;
    }
    size_t size = count * elementSize;
    MemoryBlockHeader* block = nullptr;
    if (field_e8.m_count != 0) {
        for (MemoryBlockPtr* node = field_e8.m_pHead; node != nullptr; node = node->m_pNext) {
            MemoryBlockHeader* header = node->m_pHeader;
            u8* base = header->field_50;
            size_t mask = static_cast<size_t>(alignment) - 1;
            u8* p = reinterpret_cast<u8*>((reinterpret_cast<size_t>(base) + mask) & ~mask);
            if (header->field_60 >=
                (alignment == 0 ? size : size - reinterpret_cast<size_t>(base) + reinterpret_cast<size_t>(p))) {
                header->field_58 = alignment == 0 ? base : p;
                block = header;
                break;
            }
        }
    }
    if (block == nullptr) {
        if (field_b8 != nullptr) {
            field_b8->vf5(this, elementSize, count, alignment, file, line);
        }
        return nullptr;
    }
    size_t index = block->field_10;
    size_t used;
    if (alignment > 0) {
        used = (size + (alignment - 1)) & ~(alignment - 1);
    } else {
        used = size + (block->field_58 - block->field_50);
    }
    if (block->field_60 > used) {
        MemoryBlockHeader* rest = field_110.Unk_Alloc();
        if (rest == nullptr) {
            return nullptr;
        }
        block = field_110.Unk_Get(index);
        rest->Unk_Reset();
        rest->field_50 = block->field_50 + used;
        rest->field_60 = block->field_60 - used;
        block->field_60 = used;
        block->field_68 = size;
        field_e8.Unk_InsertBefore(&block->field_38, &rest->field_38);
        field_e8.Remove(&block->field_38);
        field_c0.Unk_InsertAfter(&block->field_20, &rest->field_20);
    } else {
        block->field_68 = size;
        field_e8.Remove(&block->field_38);
    }
    block->field_70 = count;
    block->field_88 = file;
    block->field_84 = line;
    block->field_80 = static_cast<int>(field_68);
    field_68++;
    field_70 += block->field_60;
    field_78 = field_78 > field_70 ? field_78 : field_70;
    u8* end = block->field_50 + block->field_60;
    field_80 = field_80 > end ? field_80 : end;
    field_88++;
    field_90 = field_90 > field_88 ? field_90 : field_88;
    if (field_98 < static_cast<s64>(block->field_60)) {
        field_98 = block->field_60;
    }
    if (field_a0 != 0 && field_a0 == block->field_80) {
        __builtin_debugtrap();
    }
    if (field_a8 != 0 && reinterpret_cast<s64>(block->field_58) == field_a8) {
        __builtin_debugtrap();
    }
    if (field_b0 >= 0 && static_cast<s64>(block->field_68) == field_b0) {
        __builtin_debugtrap();
    }
    return block->field_58;
}

// 0x71004bde60: frees the block of p, merged with free neighbours
// NON_MATCHING: the original calls SiPool::Unk_4be3f0 out of line (three
// calls); here clang inlines it (cost 210 to 220 of 250). With the calls kept
// out of line the rest is two register choices away (the loop's free block).
void SiFixedHeapAllocator2::vf9(void* p, const char*, int) {
    if (p == nullptr) {
        return;
    }
    Unk_4c87b0 lock(Unk_CriticalSection(), true);
    if (field_c0.m_count == 0) {
        return;
    }
    MemoryBlockPtr* node = field_c0.m_pHead;
    MemoryBlockHeader* block = nullptr;
    for (; node != nullptr; node = node->m_pNext) {
        block = node->m_pHeader;
        if (block->field_58 == p) {
            break;
        }
    }
    if (node == nullptr) {
        return;
    }
    field_88 = field_88 - 1 < 0 ? 0 : field_88 - 1;
    field_70 = field_70 - block->field_60;
    MemoryBlockPtr* prevLink = block->field_20.m_pPrev;
    MemoryBlockHeader* prev = prevLink != nullptr ? prevLink->m_pHeader : nullptr;
    MemoryBlockPtr* nextLink = block->field_20.m_pNext;
    MemoryBlockHeader* next = nextLink != nullptr ? nextLink->m_pHeader : nullptr;
    if (prev != nullptr && prev->field_58 == nullptr && (block->field_78 & 1) == 0) {
        if (next != nullptr && next->field_58 == nullptr && (next->field_78 & 1) == 0) {
            prev->field_60 = next->field_50 + next->field_60 - prev->field_50;
            field_c0.Remove(&block->field_20);
            field_c0.Remove(&next->field_20);
            field_e8.Remove(&next->field_38);
            field_110.Unk_4be3f0(next);
            field_110.Unk_4be3f0(block);
        } else {
            prev->field_60 = block->field_50 + block->field_60 - prev->field_50;
            field_c0.Remove(&block->field_20);
            field_110.Unk_4be3f0(block);
        }
    } else if (next != nullptr && next->field_58 == nullptr && (next->field_78 & 1) == 0) {
        block->field_60 = next->field_50 + next->field_60 - block->field_50;
        field_e8.Unk_InsertBefore(&next->field_38, &block->field_38);
        block->field_58 = nullptr;
        block->field_88 = nullptr;
        block->field_84 = 0;
        block->field_68 = 0;
        block->field_70 = 0;
        field_c0.Remove(&next->field_20);
        field_e8.Remove(&next->field_38);
        field_110.Unk_4be3f0(next);
    } else {
        // the nearest free block in front or behind decides where it goes in
        // the free list
        MemoryBlockPtr* back = prevLink;
        MemoryBlockPtr* front = nextLink;
        MemoryBlockPtr* where = nullptr;
        while (back != nullptr || front != nullptr) {
            if (back != nullptr) {
                MemoryBlockHeader* header = back->m_pHeader;
                if (header->field_58 == nullptr) {
                    MemoryBlockPtr* after = header->field_38.m_pNext;
                    if (after != nullptr) {
                        where = &after->m_pHeader->field_38;
                    }
                    break;
                }
                back = back->m_pPrev;
            }
            if (front != nullptr) {
                MemoryBlockHeader* header = front->m_pHeader;
                if (header->field_58 == nullptr) {
                    where = &header->field_38;
                    break;
                }
                front = front->m_pNext;
            }
        }
        if (where != nullptr) {
            field_e8.Unk_InsertBefore(where, &block->field_38);
        } else {
            field_e8.AddTail(&block->field_38);
        }
        block->field_58 = nullptr;
        block->field_88 = nullptr;
        block->field_84 = 0;
        block->field_68 = 0;
        block->field_70 = 0;
    }
}

// 0x71004be4c0
size_t SiFixedHeapAllocator2::vf10(void* p) {
    if (p == nullptr) {
        return 0;
    }
    Unk_4c87b0 lock(Unk_CriticalSection(), true);
    if (field_c0.m_count != 0) {
        for (MemoryBlockPtr* node = field_c0.m_pHead; node != nullptr; node = node->m_pNext) {
            MemoryBlockHeader* block = node->m_pHeader;
            if (block->field_58 == p) {
                return block->field_70;
            }
        }
    }
    return 0;
}

// 0x71004be580
bool SiFixedHeapAllocator2::Unk_Sorter::Unk_4be580(s64 count, MemoryBlockHeader** blocks) {
    if (count < 2) {
        return true;
    }
    s64 middle;
    s64 pivot = count / 2;
    if (pivot < count) {
        MemoryBlockHeader* t = blocks[0];
        blocks[0] = blocks[pivot];
        blocks[pivot] = t;
        MemoryBlockHeader* first = blocks[0];
        s64 i = 1;
        s64 j = count - 1;
        while (i <= j) {
            // (the scans, bottom-tested as the original's are)
            if (first->field_80 > blocks[i]->field_80) {
                do {
                    if (++i >= j) {
                        break;
                    }
                } while (first->field_80 > blocks[i]->field_80);
            }
            if (first->field_80 <= blocks[j]->field_80) {
                do {
                    if (--j <= i) {
                        break;
                    }
                } while (first->field_80 <= blocks[j]->field_80);
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
    Unk_4be580(middle, blocks);
    Unk_4be580(count - middle - 1, &blocks[middle + 1]);
    return true;
}

// 0x71004be700
size_t SiFixedHeapAllocator2::vf16(void* p) {
    MemoryBlockHeader* block = reinterpret_cast<MemoryBlockHeader*>(static_cast<u8*>(p) - static_cast<int*>(p)[-1]);
    if (block == nullptr) {
        return 0;
    }
    return block->field_68;
}

// 0x71004be730
void SiFixedHeapAllocator2::vf18(s64 number) {
    Unk_4bd610(number, false);
}

// 0x71004be740
void SiFixedHeapAllocator2::vf19(Unk_Handler* handler) {
    if (handler != nullptr) {
        handler->vf2();
    }
    if (field_b8 != nullptr) {
        field_b8->vf3();
    }
    field_b8 = handler;
}

}  // namespace SiSDK3
