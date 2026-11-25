// Scope: common
// pead's allocation (`new (heap) T`, freeing through the heap that holds the
// memory), a CRC-32, and pead::DelegateEvent<const PrintConfig::PrintEventArg&>
// (RTTI N4pead13DelegateEventIRKNS_11PrintConfig13PrintEventArgEEE): the global
// one this TU constructs, and its destructors. Names are placeholders
// (lib/pia/README.md).
#include "pia/common/Unk_17162d0.h"

namespace pead {

// RTTI N4pead4HeapE: the slots this file calls (placeholder names vf<slot>).
class Heap {
public:
    virtual ~Heap();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void* vf6(size_t size, int alignment);
    virtual void vf7(void* memory);
};

}  // namespace pead

// What Unk_27fb9a8 points to: it finds the current heap (0x710171ae70) and the
// heap that holds some memory (0x710171ab50).
struct Unk_27fb9a8_obj;
extern Unk_27fb9a8_obj* Unk_27fb9a8;
pead::Heap* Unk_171ae70(Unk_27fb9a8_obj* self);
pead::Heap* Unk_171ab50(Unk_27fb9a8_obj* self, void* memory);

// 0x71017162d0
void* operator new(size_t size, pead::Heap* heap) noexcept {
    if (heap == nullptr) {
        heap = Unk_171ae70(Unk_27fb9a8);
        if (heap == nullptr) {
            return nullptr;
        }
    }
    return heap->vf6(size, 4);
}

// 0x7101716330
void* operator new(size_t size, pead::Heap* heap, int alignment) noexcept {
    if (heap == nullptr) {
        heap = Unk_171ae70(Unk_27fb9a8);
        if (heap == nullptr) {
            return nullptr;
        }
    }
    return heap->vf6(size, alignment);
}

// 0x7101716390
void Unk_1716390(void* memory) {
    pead::Heap* heap = Unk_171ab50(Unk_27fb9a8, memory);
    if (heap != nullptr) {
        heap->vf7(memory);
    }
}

// The header in front of an array `new[]` allocated: bit 0 of the word right
// before the array says whether it is short (the word is the header's address
// plus one) or the 0x20 bytes before it.
struct Unk_17163e0_header {
    u8 _0[0x18];
    u64 field_18;
};
PKMN_OFFSET_ASSERT(Unk_17163e0_header, field_18, 0x18);

// 0x71017163e0
u64 Unk_17163e0(void* memory) {
    u64 word = reinterpret_cast<u64*>(memory)[-1];
    Unk_17163e0_header* header =
        (word & 1) != 0 ? reinterpret_cast<Unk_17163e0_header*>(word - 1)
                        : reinterpret_cast<Unk_17163e0_header*>(static_cast<u8*>(memory) - 0x20);
    return header->field_18;
}

// The CRC-32 table (polynomial 0xedb88320), filled on the first call.
extern bool Unk_27fb948;
extern u32 Unk_27fb548[0x100];

// 0x7101716400
u32 Unk_1716400(const u8* data, u32 size) {
    if (!Unk_27fb948) {
        for (u64 i = 0; i < 0x100; i++) {
            u32 crc = i;
            for (int bit = 0; bit < 8; bit++) {
                if (crc & 1) {
                    crc = (crc >> 1) ^ 0xedb88320;
                } else {
                    crc >>= 1;
                }
            }
            Unk_27fb548[i] = crc;
        }
        Unk_27fb948 = true;
    }
    if (size == 0) {
        return 0;
    }
    u32 crc = 0xffffffff;
    do {
        crc = Unk_27fb548[*data++ ^ (crc & 0xff)] ^ (crc >> 8);
    } while (--size != 0);
    return ~crc;
}

// pead's intrusive list (no RTTI; 0x71017166a0 unlinks a node).
struct Unk_17166a0_arg0 {
    Unk_17166a0_arg0* field_0;
    Unk_17166a0_arg0* field_8;
};
PKMN_SIZE_ASSERT(Unk_17166a0_arg0, 0x10);

void Unk_17166a0(Unk_17166a0_arg0* node);

namespace pead {

struct Unk_1716500_list;

// A list node that points to its data and to the list that holds it.
template <class T>
struct Unk_1716500_node : Unk_17166a0_arg0 {
    T m_data;
    Unk_1716500_list* m_list;

    void Unk_erase();
};

struct Unk_1716500_list {
    Unk_1716500_list() : m_count(0) {
        m_head.field_0 = m_head.field_8 = &m_head;
    }

    Unk_17166a0_arg0 m_head;
    int m_count;
};
PKMN_SIZE_ASSERT(Unk_1716500_list, 0x18);

template <class T>
inline void Unk_1716500_node<T>::Unk_erase() {
    Unk_1716500_list* list = m_list;
    if (list != nullptr) {
        m_list = nullptr;
        Unk_17166a0(this);
        list->m_count--;
    }
}

class PrintConfig {
public:
    struct PrintEventArg;
};

template <class T>
class DelegateEvent {
public:
    // A delegate connected to the event: its node in the event's list is at
    // 0x20.
    struct Unk_slot {
        void Unk_release() {
            if (m_connected) {
                m_node.Unk_erase();
                m_connected = false;
            }
        }

        u8 _0[0x20];
        Unk_1716500_node<Unk_slot*> m_node;
        u8 _40[0x28];
        bool m_connected;
    };
    PKMN_OFFSET_ASSERT(Unk_slot, m_node, 0x20);
    PKMN_OFFSET_ASSERT(Unk_slot, m_connected, 0x68);

    virtual ~DelegateEvent() {
        Unk_17166a0_arg0* node = m_slots.m_head.field_8;
        while (node != &m_slots.m_head) {
            Unk_slot* slot = static_cast<Unk_1716500_node<Unk_slot*>*>(node)->m_data;
            node = node->field_8;
            slot->Unk_release();
        }
    }

    Unk_1716500_list m_slots;
};

}  // namespace pead

// 0x71027fb950: the event, constructed by this TU's static initialiser
// (0x7101716620). Its destructors are 0x7101716500 and 0x7101716590
// (deleting).
pead::DelegateEvent<const pead::PrintConfig::PrintEventArg&> Unk_27fb950;

extern void* Unk_27fb970;

// 0x7101716580
void Unk_1716580(void* value) {
    Unk_27fb970 = value;
}

// The object 0x710170e8e0 asks (no RTTI here): its state at 0x628 and six
// flags at 0x30; vf7 is called with true.
struct Unk_1716190_arg0 {
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual bool vf7(bool value);

    u8 _8[0x28];
    bool field_30;
    bool field_31;
    bool field_32;
    bool field_33;
    bool field_34;
    bool field_35;
    u8 _36[0x628 - 0x36];
    u32 field_628;
};
PKMN_OFFSET_ASSERT(Unk_1716190_arg0, field_30, 0x30);
PKMN_OFFSET_ASSERT(Unk_1716190_arg0, field_628, 0x628);

// NON_MATCHING: the original keeps the result in x19 across the call and
// branches on it (a phi of constants); this folds it into `eor`/`and`.
// 0x7101716190
bool Unk_1716190(Unk_1716190_arg0* self) {
    return self->field_628 == 1 && !self->vf7(true);
}

// NON_MATCHING: the original tests bit 0 of the state where `== 0` was
// expected, ORs the flags the other way round and lays the blocks out
// differently; this is its logic, read from the asm.
// 0x71017161e0
bool Unk_17161e0(Unk_1716190_arg0* self) {
    bool any = self->field_30 | self->field_31 | self->field_32 | self->field_33 |
               self->field_34 | self->field_35;
    if (any && (self->field_628 & 1) == 0) {
        if (self->vf7(true) || self->field_628 != 0) {
            return false;
        }
    } else if (self->field_628 != 0) {
        return true;
    }
    return self->vf7(true) || any;
}
