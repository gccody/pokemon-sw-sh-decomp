// Scope: common
// SendThreadStream's packet pool, Unk_174bc30 (lib/pia/common/Unk_174aea0.h):
// the members that move its packets through the delay list, and
// transport::ReceiveThreadStream's constructor and destructor (its other
// members are in Unk_174c650.cpp, where its vtable is). Unk_174bc30::Unk_174c120, which
// these members call, has a file of its own.
#include "pia/common/Unk_174be20.h"

namespace nn {
namespace pia {
namespace transport {

using common::Unk_16580b0_node;

// 0x710174be20
void Unk_174bc30::Unk_174be20() {
    Unk_16580b0_node* node = m_List.m_Root.next;
    while (node != &m_List.m_Root) {
        Unk_16580b0_node* next = node->next;
        node->prev = nullptr;
        node->next = nullptr;
        m_Pool.Unk_16580f0(&m_Pool.m_Root, reinterpret_cast<Unk_16580b0_node*>(
                                               reinterpret_cast<uintptr_t>(node) + m_Pool.m_Offset));
        node = next;
    }
    m_List.Unk_16580b0_init();
}

// 0x710174be80
Unk_165e060 Unk_174bc30::Unk_174be80(Unk_1660390* packet) {
    if (packet == nullptr) {
        return Unk_165e060Value<0x10c07>();
    }
    if (field_48 == nullptr) {
        return Unk_165e060Value<0x10c08>();
    }
    if (m_List.m_Count == 0) {
        return Unk_165e060Value<0x2c09>();
    }
    Unk_165c600 now = {0};
    Unk_165c600_call(&now);
    for (Unk_16580b0_node* node = m_List.m_Root.next; node != &m_List.m_Root; node = node->next) {
        Entry* entry = reinterpret_cast<Entry*>(node);
        if (entry->data.field_658 < now.field_0) {
            packet->Unk_1660570(entry->data.packet);
            Free(&entry->data);
            return Unk_165e060Value<0>();
        }
    }
    return Unk_165e060Value<0x2c09>();
}

// 0x710174bfc0
// NON_MATCHING: scheduling: the original sets the address's vtable before
// keeping its pointer, and clears the result before taking its variant's
// address at the end; the same instructions otherwise.
Unk_165e060 Unk_174bc30::Unk_174bfc0(Unk_1660390* packet) {
    if (m_Pool.m_Count == 0) {
        return Unk_165e060Value<0x4c0d>();
    }
    Unk_174bc30_packet* entry = Alloc();
    field_88.packet.Unk_1660570(*packet);
    {
        Unk_165c600 now = {0};
        Unk_165c600_call(&now);
        Unk_1652c70 any(0xffffffff, 0);
        s32 delay = Unk_174c120(any);
        field_88.field_658 = *Unk_165c6b0() * delay + now.field_0;
    }
    entry->packet.Unk_1660570(field_88.packet);
    entry->field_658 = field_88.field_658;
    return Unk_165e060Value<0>();
}

// 0x710174c230
Unk_165e060 Unk_174bc30::Unk_174c230() {
    if (field_48 != nullptr) {
        if (field_50 == nullptr) {
            return Unk_174c420();
        }
    } else if (field_50 != nullptr) {
        return Unk_174c2d0();
    }
    return Unk_165e060Value<0x10c08>();
}

// 0x710174c2d0
Unk_165e060 Unk_174bc30::Unk_174c2d0() {
    Unk_165c600 now = {0};
    Unk_165c600_call(&now);
    Unk_165e060 result = Unk_165e060Value<0>();
    while (m_List.m_Count != 0) {
        Unk_174bc30_packet* entry = &reinterpret_cast<Entry*>(m_List.m_Root.next)->data;
        if (entry->field_658 >= now.field_0) {
            break;
        }
        result = field_50->vf4(&entry->packet);
        Free(entry);
        if (result.m_Value != 0) {
            if (result == Unk_165e060Value<0x4c0d>()) {
                result = Unk_165e060Value<0>();
            }
            break;
        }
    }
    return result;
}

// 0x710174c420
Unk_165e060 Unk_174bc30::Unk_174c420() {
    Unk_165c600 now = {0};
    Unk_165c600_call(&now);
    Unk_165e060 result = Unk_165e060Value<0>();
    while (m_Pool.m_Count != 0) {
        result = field_48->vf2(&field_88.packet);
        if (result.m_Value != 0) {
            if (result == Unk_165e060Value<0x2c09>()) {
                result = Unk_165e060Value<0>();
            }
            break;
        }
        s32 delay = Unk_174c120(field_88.packet.field_628.field_8);
        field_88.field_658 = *Unk_165c6b0() * delay + now.field_0;
        if (m_Pool.m_Count == 0) {
            break;
        }
        Unk_174bc30_packet* entry = Alloc();
        entry->packet.Unk_1660570(field_88.packet);
        entry->field_658 = field_88.field_658;
    }
    return result;
}

// 0x710174c5d0
ReceiveThreadStream::ReceiveThreadStream() : field_4f0(nullptr), field_4f8(0), field_500(0) {}

// 0x710174c610 (and 0x710174c620, deleting)
ReceiveThreadStream::~ReceiveThreadStream() {}

}  // namespace transport
}  // namespace pia
}  // namespace nn
