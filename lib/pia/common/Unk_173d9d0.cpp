// Scope: common
// transport::ProtocolManager's members over its list of protocols
// (lib/pia/common/Unk_173d9d0.h). Member names are placeholders
// (lib/pia/README.md).
#include "pia/common/Unk_173d9d0.h"

u64 Unk_17163e0(void* memory);
void Unk_1716390(void* memory);

namespace nn {
namespace pia {
namespace transport {

// 0x710173d9d0
// NON_MATCHING: the original shifts the id inside the search loop (cmp w11,
// w0, lsr #24); this hoists the shift out of it.
void ProtocolManager::Unk_173d9d0(u32 id) {
    List::iterator end = m_List.end();
    for (List::iterator it = m_List.begin(); it != end; ++it) {
        Protocol* protocol = *it;
        if (protocol->vf3().value != id) {
            continue;
        }
        if (!protocol->vf11()) {
            u32 protocolId = protocol->vf3().value;
            s32 count = field_4c;
            if (count != 0) {
                s32 i;
                for (i = 0; i < count; ++i) {
                    if (field_29[i] == protocolId >> 24) {
                        break;
                    }
                }
                if (i != count) {
                    for (; i < field_4c - 1; ++i) {
                        field_29[i] = field_29[i + 1];
                    }
                    --field_4c;
                }
            }
        }
        m_List.Unk_1658120(m_List.ToNode(protocol));
        protocol->~Protocol();
        Unk_17163e0(protocol);
        Unk_1716390(protocol);
        return;
    }
}

// 0x710173db30
Protocol* ProtocolManager::Unk_173db30(Unk_173db30_arg1 id, u8 type) {
    if (static_cast<u8>(id.value >> 24) != type) {
        return nullptr;
    }
    List::iterator end = m_List.end();
    for (List::iterator it = m_List.begin(); it != end; ++it) {
        Protocol* protocol = *it;
        if (id.value == protocol->vf3().value) {
            return protocol;
        }
    }
    return nullptr;
}

// 0x710173dbc0
// NON_MATCHING: the original reads the list's offset once; the list iterator
// reads it again after the stores to each protocol.
Unk_165e060 ProtocolManager::Unk_173dbc0(void* arg1, void* arg2) {
    if (arg1 == nullptr || arg2 == nullptr) {
        return Unk_165e060Value<0x10c07>();
    }
    if (field_28) {
        return Unk_165e060Value<0x10c08>();
    }
    List::iterator end = m_List.end();
    for (List::iterator it = m_List.begin(); it != end; ++it) {
        Protocol* protocol = *it;
        protocol->field_8 = arg1;
        protocol->field_10 = arg2;
    }
    field_28 = true;
    return Unk_165e060Value<0>();
}

// 0x710173dc90
// NON_MATCHING: as Unk_173dbc0, the list's offset is read again after the
// stores.
void ProtocolManager::Unk_173dc90() {
    List::iterator end = m_List.end();
    for (List::iterator it = m_List.begin(); it != end; ++it) {
        Protocol* protocol = *it;
        protocol->field_8 = nullptr;
        protocol->field_10 = nullptr;
    }
    field_28 = false;
}

// 0x710173dcd0
Unk_165e060 ProtocolManager::Unk_173dcd0(u64 arg) {
    if (!field_28) {
        return Unk_165e060Value<0x10c08>();
    }
    List::iterator end = m_List.end();
    for (List::iterator it = m_List.begin(); it != end; ++it) {
        Protocol* protocol = *it;
        Unk_165e060 result = protocol->vf7(arg);
        if (result.m_Value != 0) {
            List::iterator otherEnd = m_List.end();
            for (List::iterator other = m_List.begin(); other != otherEnd; ++other) {
                (*other)->vf8();
            }
            return result;
        }
    }
    return Unk_165e060Value<0>();
}

// 0x710173ddf0
void ProtocolManager::Unk_173ddf0() {
    List::iterator end = m_List.end();
    for (List::iterator it = m_List.begin(); it != end; ++it) {
        Protocol* protocol = *it;
        protocol->vf8();
    }
}

// 0x710173de60
Unk_165e060 ProtocolManager::Unk_173de60() {
    if (!field_28) {
        return Unk_165e060Value<0x10c08>();
    }
    List::iterator end = m_List.end();
    for (List::iterator it = m_List.begin(); it != end; ++it) {
        Protocol* protocol = *it;
        Unk_165e060 result = protocol->vf5();
        if (result.m_Value != 0) {
            List::iterator otherEnd = m_List.end();
            for (List::iterator other = m_List.begin(); other != otherEnd; ++other) {
                (*other)->vf6();
            }
            return result;
        }
    }
    return Unk_165e060Value<0>();
}

// 0x710173df80
void ProtocolManager::Unk_173df80() {
    List::iterator end = m_List.end();
    for (List::iterator it = m_List.begin(); it != end; ++it) {
        Protocol* protocol = *it;
        protocol->vf6();
    }
}

// 0x710173dff0
Unk_165e060 ProtocolManager::Unk_173dff0() {
    if (!field_28) {
        return Unk_165e060Value<0x10c08>();
    }
    List::iterator end = m_List.end();
    for (List::iterator it = m_List.begin(); it != end; ++it) {
        Protocol* protocol = *it;
        Unk_165e060 result = protocol->vf9();
        if (result.m_Value != 0) {
            return result;
        }
    }
    return Unk_165e060Value<0>();
}

// 0x710173e0c0
Unk_165e060 ProtocolManager::Unk_173e0c0(Unk_173e0c0_arg1* arg) {
    if (!field_28) {
        return Unk_165e060Value<0x10c08>();
    }
    Unk_165e060 result = Unk_165e060Value<0>();
    List::iterator end = m_List.end();
    for (List::iterator it = m_List.begin(); it != end; ++it) {
        Protocol* protocol = *it;
        Unk_165e060 protocolResult = protocol->vf10(arg);
        if (protocolResult.m_Value != 0 && result.m_Value == 0) {
            result = protocolResult;
        }
    }
    return result;
}

}  // namespace transport
}  // namespace pia
}  // namespace nn
