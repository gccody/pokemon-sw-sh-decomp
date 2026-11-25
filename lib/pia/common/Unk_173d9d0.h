#pragma once
// transport::ProtocolManager (vtable 0x7102460818, RTTI
// N2nn3pia9transport15ProtocolManagerE) and transport::Protocol (vtable
// 0x7102460788, RTTI N2nn3pia9transport8ProtocolE), as the manager's members
// use them. Member names are placeholders (lib/pia/README.md); the members
// tools/leafgen.py matched are in lib/nx_middleware/class.
#include "pia/common/Unk_165e060.h"
#include "pia/common/Unk_1734ed0.h"

// What ProtocolManager::Unk_173e0c0 hands each protocol (Protocol's vf10;
// the base's reads a field at 0x30).
struct Unk_173e0c0_arg1;

// A protocol's id, what Protocol's vf3 returns (placeholder): a 4-byte value
// passed and returned in a 64-bit register, its top byte the protocol's type.
struct Unk_173db30_arg1 {
    u32 value;
};

namespace nn {
namespace pia {
namespace common {

// An Unk_16580b0 of T: the node sits m_Offset bytes into each element. The
// iterator reads the offset from the list at each step, and the element
// from a node as an integer (the original doesn't fold node - offset +
// offset back into the node).
template <class T>
class Unk_16580b0_list : public Unk_16580b0 {
public:
    class iterator {
    public:
        iterator(Unk_16580b0_list* list, T* element) : m_List(list), m_Element(element) {}

        T* operator*() const { return m_Element; }
        bool operator!=(const iterator& other) const { return m_Element != other.m_Element; }
        iterator& operator++() {
            m_Element = m_List->ToElement(m_List->ToNode(m_Element)->next);
            return *this;
        }

    private:
        Unk_16580b0_list* m_List;
        T* m_Element;
    };

    iterator begin() { return iterator(this, ToElement(m_Root.next)); }
    iterator end() { return iterator(this, ToElement(&m_Root)); }

    T* ToElement(Unk_16580b0_node* node) {
        return reinterpret_cast<T*>(reinterpret_cast<uintptr_t>(node) + -m_Offset);
    }
    Unk_16580b0_node* ToNode(T* element) {
        return reinterpret_cast<Unk_16580b0_node*>(reinterpret_cast<uintptr_t>(element) + m_Offset);
    }
};

}  // namespace common

namespace transport {

// A protocol a ProtocolManager runs: its id (the top byte is its type) and
// the two objects the manager hands it.
class Protocol {
public:
    virtual ~Protocol();
    virtual void vf2();
    virtual Unk_173db30_arg1 vf3();  // the id
    virtual u32 vf4() = 0;
    virtual Unk_165e060 vf5();
    virtual void vf6();
    virtual Unk_165e060 vf7(u64 arg);
    virtual void vf8();
    virtual Unk_165e060 vf9();
    virtual Unk_165e060 vf10(Unk_173e0c0_arg1* arg);
    virtual bool vf11();
    virtual u64 vf12();
    virtual void vf13(u64 value);

    void* field_8;
    void* field_10;
};
PKMN_OFFSET_ASSERT(Protocol, field_8, 0x8);
PKMN_OFFSET_ASSERT(Protocol, field_10, 0x10);

class ProtocolManager {
public:
    typedef common::Unk_16580b0_list<Protocol> List;

    virtual ~ProtocolManager();
    virtual void vf2();

    void Unk_173d9d0(u32 id);  // destroys the protocol with this id
    Protocol* Unk_173db30(Unk_173db30_arg1 id, u8 type);
    Unk_165e060 Unk_173dbc0(void* arg1, void* arg2);
    void Unk_173dc90();
    Unk_165e060 Unk_173dcd0(u64 arg);
    void Unk_173ddf0();
    Unk_165e060 Unk_173de60();
    void Unk_173df80();
    Unk_165e060 Unk_173dff0();
    Unk_165e060 Unk_173e0c0(Unk_173e0c0_arg1* arg);
    bool Unk_173e1e0(u8 type) const;  // the type isn't in field_29

    void* field_8;
    List m_List;
    bool field_28;   // the protocols have field_8 and field_10
    u8 field_29[0x20];  // protocol types
    s32 field_4c;       // the types in field_29
};
PKMN_OFFSET_ASSERT(ProtocolManager, field_8, 0x8);
PKMN_OFFSET_ASSERT(ProtocolManager, m_List, 0x10);
PKMN_OFFSET_ASSERT(ProtocolManager, field_28, 0x28);
PKMN_OFFSET_ASSERT(ProtocolManager, field_29, 0x29);
PKMN_OFFSET_ASSERT(ProtocolManager, field_4c, 0x4c);
PKMN_SIZE_ASSERT(ProtocolManager, 0x50);

}  // namespace transport
}  // namespace pia
}  // namespace nn
