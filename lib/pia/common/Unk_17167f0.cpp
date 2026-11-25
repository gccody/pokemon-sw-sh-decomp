// Scope: common
// pead::ExpHeap (RTTI N4pead7ExpHeapE, derived from pead::Heap, RTTI
// N4pead4HeapE): its destructors and the virtual functions that sit next to
// them. A TU of its own: it calls pead's list functions (Unk_1716660.cpp) out
// of line. Member names are placeholders (vf<slot>, Unk_<addr>;
// lib/pia/README.md).
#include <types.h>

// pead's intrusive list (lib/pia/common/Unk_1716660.cpp).
struct Unk_17166a0_arg0 {
    Unk_17166a0_arg0* field_0;
    Unk_17166a0_arg0* field_8;
};
PKMN_SIZE_ASSERT(Unk_17166a0_arg0, 0x10);
void Unk_17166a0(Unk_17166a0_arg0* node);
void Unk_1716680(Unk_17166a0_arg0* self, Unk_17166a0_arg0* node);

namespace pead {

// A block of an ExpHeap's memory: its node in the heap's lists, the padding
// in front of its data and the data's size. The data follows it.
struct Unk_1716c20_block {
    u8* Unk_end() { return reinterpret_cast<u8*>(this) + sizeof(*this) + m_offset + m_size; }

    Unk_17166a0_arg0 m_node;
    u16 field_10;
    u16 m_offset;
    size_t m_size;
};
PKMN_OFFSET_ASSERT(Unk_1716c20_block, m_offset, 0x12);
PKMN_OFFSET_ASSERT(Unk_1716c20_block, m_size, 0x18);
PKMN_SIZE_ASSERT(Unk_1716c20_block, 0x20);

// A list of blocks, by their node at `m_offset`.
struct Unk_1716c20_list {
    Unk_1716c20_block* Unk_object(Unk_17166a0_arg0* node) {
        return reinterpret_cast<Unk_1716c20_block*>(reinterpret_cast<u8*>(node) - m_offset);
    }
    Unk_17166a0_arg0* Unk_node(Unk_1716c20_block* block) {
        return reinterpret_cast<Unk_17166a0_arg0*>(reinterpret_cast<u8*>(block) + m_offset);
    }
    void Unk_pushBack(Unk_1716c20_block* block) {
        Unk_1716680(&m_head, Unk_node(block));
        m_count++;
    }
    void Unk_insertBefore(Unk_1716c20_block* next, Unk_1716c20_block* block) {
        Unk_1716680(Unk_node(next), Unk_node(block));
        m_count++;
    }
    void Unk_erase(Unk_1716c20_block* block) {
        Unk_17166a0(Unk_node(block));
        m_count--;
    }

    Unk_17166a0_arg0 m_head;
    int m_count;
    int m_offset;
};
PKMN_SIZE_ASSERT(Unk_1716c20_list, 0x18);

class Heap {
public:
    virtual ~Heap();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void* vf6(size_t size, int alignment);
    virtual void vf7(void* memory);
    virtual void vf8();
    virtual void vf9();
    virtual u64 vf10();
    virtual void vf11();
    virtual u64 vf12();
    virtual void vf13();
    virtual u64 vf14();
    virtual void vf15();
    virtual size_t vf16(int alignment);
    virtual bool vf17(const void* memory) const;
    virtual bool vf18();
    virtual bool vf19();
    virtual u32 vf20();
    virtual u32 vf21();
    virtual void vf22();
    virtual void vf23();
    virtual void vf24(Heap* child);

    // 0x71017195a0, called by ExpHeap's destructor.
    void Unk_17195a0();

    u8 _8[0x28];
    u8* m_start;
    size_t m_size;
    Heap* m_parent;
    u8 _48[0x40];
    int m_direction;  // 1: from the start
    u8 _8c[0x44];
    u16 m_flags;  // bit 0: locked with the critical section at 0x90
};
PKMN_OFFSET_ASSERT(Heap, m_start, 0x30);
PKMN_OFFSET_ASSERT(Heap, m_size, 0x38);
PKMN_OFFSET_ASSERT(Heap, m_parent, 0x40);
PKMN_OFFSET_ASSERT(Heap, m_direction, 0x88);
PKMN_OFFSET_ASSERT(Heap, m_flags, 0xd0);

class ExpHeap : public Heap {
public:
    ~ExpHeap() override;
    void vf4() override;
    bool vf17(const void* memory) const override;
    virtual void vf25(u32 value);
    virtual u32 vf26();

    // 0x7101716c20: gives `block` back to the free list, in address order,
    // merging it with its neighbours.
    void Unk_1716c20(Unk_1716c20_block* block);

    u32 field_d4;
    Unk_1716c20_list m_freeList;
    Unk_1716c20_list m_usedList;
};
PKMN_OFFSET_ASSERT(ExpHeap, m_freeList, 0xd8);
PKMN_OFFSET_ASSERT(ExpHeap, field_d4, 0xd4);
PKMN_SIZE_ASSERT(ExpHeap, 0x108);

// 0x71017167f0 (and 0x7101716830, deleting)
ExpHeap::~ExpHeap() {
    Unk_17195a0();
}

// 0x7101716dd0
void ExpHeap::vf4() {
    Heap* parent = m_parent;
    u8* start = m_start;
    this->~ExpHeap();
    if (parent != nullptr && parent->vf19()) {
        parent->vf7(start);
    }
}

// 0x7101716e30: whether `memory` is in the heap's blocks (the heap object
// sits at one end of its memory, by its direction).
bool ExpHeap::vf17(const void* memory) const {
    uintptr_t start = reinterpret_cast<uintptr_t>(m_start);
    uintptr_t begin;
    uintptr_t end;
    if (m_direction == 1) {
        begin = start + sizeof(ExpHeap);
        end = start + m_size;
    } else {
        begin = start;
        end = start + m_size - sizeof(ExpHeap);
    }
    return reinterpret_cast<const void*>(begin) <= memory &&
           memory < reinterpret_cast<const void*>(end);
}

// NON_MATCHING: the original walks the list by block (comparing each with the
// head's block) and lays the merge paths out differently; this walks it by node.
// 0x7101716c20
void ExpHeap::Unk_1716c20(Unk_1716c20_block* block) {
    Unk_1716c20_block* prev = nullptr;
    Unk_1716c20_block* end = m_freeList.Unk_object(&m_freeList.m_head);
    for (Unk_1716c20_block* next = m_freeList.Unk_object(m_freeList.m_head.field_8); next != end;
         next = m_freeList.Unk_object(m_freeList.Unk_node(next)->field_8)) {
        if (next <= block) {
            prev = next;
            continue;
        }
        bool merged = false;
        if (prev != nullptr && prev->Unk_end() == reinterpret_cast<u8*>(block)) {
            prev->m_size += sizeof(Unk_1716c20_block) + block->m_offset + block->m_size;
            block = prev;
            merged = true;
        }
        if (block->Unk_end() == reinterpret_cast<u8*>(next)) {
            if (!merged) {
                m_freeList.Unk_insertBefore(next, block);
            }
            block->m_size += sizeof(Unk_1716c20_block) + next->m_offset + next->m_size;
            m_freeList.Unk_erase(next);
            return;
        }
        if (!merged) {
            m_freeList.Unk_insertBefore(next, block);
        }
        return;
    }
    if (m_freeList.m_count != 0 && prev->Unk_end() == reinterpret_cast<u8*>(block)) {
        prev->m_size += sizeof(Unk_1716c20_block) + block->m_offset + block->m_size;
        return;
    }
    m_freeList.Unk_pushBack(block);
}

}  // namespace pead
