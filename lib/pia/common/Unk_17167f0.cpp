// Scope: common
// pead::ExpHeap (RTTI N4pead7ExpHeapE, derived from pead::Heap, RTTI
// N4pead4HeapE): its destructors and the virtual functions that sit next to
// them. A TU of its own: it calls pead's list functions (Unk_1716660.cpp) out
// of line. Member names are placeholders (vf<slot>, Unk_<addr>;
// lib/pia/README.md).
#include <types.h>

namespace pead {

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

    u32 field_d4;
    u8 _d8[0x30];
};
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

}  // namespace pead
