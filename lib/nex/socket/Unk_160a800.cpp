// Scope: common
// NEX 4.6.8: the PRUDPLite end point's flags, the stream template that holds one
// stream per type (N2nn3nex27MultiPRUDPStreamTemplateImpE) and the holder of the
// PRUDP message objects (N2nn3nex21ProtocolMessageHolderE).
#include <map>

#include <nn/nex/qVector.h>

#include "Unk_160a230.h"

// 0x71015b8dc0: reports an error (source file, line, result code).
void Unk_15b8dc0(const char* file, u32 line, u32 code, u32 arg);

// The calling thread's instance of NEX's core (as <nn/nex/InstanceTable.h>'s
// GetInstance, for the instance next to the one it reads), and what it holds.
struct Unk_160aab0_Context {
    u8 _0[0x1a8];
    nn::nex::PacketEncDecInf* m_encDec;      // the PRUDP streams'
    nn::nex::PacketEncDecInf* m_liteEncDec;  // the PRUDPLite streams'
};
PKMN_OFFSET_ASSERT(Unk_160aab0_Context, m_liteEncDec, 0x1b0);
struct Unk_160aab0_Instance {
    u8 _0[0x10];
    Unk_160aab0_Context* m_context;
};
struct Unk_160aab0_Entry {
    u8 _0[0x10];
    Unk_160aab0_Instance* m_instance;
};
// 0x71027f3770: the instances, the default one and one per thread.
struct Unk_160aab0_Table {
    u8 _0[0x18];
    Unk_160aab0_Instance* m_default;
    u8 _20[0x80];
    nn::nex::qVector<Unk_160aab0_Entry*>* m_threads;
};
PKMN_OFFSET_ASSERT(Unk_160aab0_Table, m_threads, 0xa0);
extern Unk_160aab0_Table Unk_27f3770;

inline Unk_160aab0_Instance* Unk_160aab0_GetInstance() {
    Unk_160aab0_Instance** slot = &Unk_27f3770.m_default;
    if (Unk_27f3838) {
        u32 index = *Unk_6a5230(Unk_27f3830);
        if (index != 0) {
            nn::nex::qVector<Unk_160aab0_Entry*>& threads = *Unk_27f3770.m_threads;
            if (index >= threads.size()) {
                Unk_15b8dc0("..\\..\\..\\..\\.\\OnlineCore/src/Core/InstanceTable.h", 71,
                            0xe0000003, 0);
                return nullptr;
            }
            slot = &threads[index]->m_instance;
        }
    }
    return *slot;
}

// A Mersenne Twister's state (lib/nex/include/nn/nex/Unk_15bb6c0.cpp).
struct Unk_15bb890 {
    Unk_15bb890();

    u32 m_state[624];
    u32 m_index;
    u32 m_mag01[2];
};
PKMN_SIZE_ASSERT(Unk_15bb890, 0x9cc);

// 0x71015bb890
void Unk_15bb890_init(Unk_15bb890* self);
// 0x71015bae60: seeds it (4357 for 0).
void Unk_15bae60_seed(Unk_15bb890* self, u32 seed);
// 0x71015baf90: a random u32.
u32 Unk_15baf90_call();

inline Unk_15bb890::Unk_15bb890() {
    Unk_15bb890_init(this);
}

namespace nn {
namespace nex {

// 0x710160a800
u64 PRUDPEndPointTemplatePRUDPLiteImp::vf3(u8 enabled, u32 info) {
    u64 flags = (info >> 8) | 0x3000000;
    if ((info & 0xff) > 4) {
        flags |= 0x4000000;
    }
    if ((info & 0xff) > 5) {
        flags |= 0x8000000;
    }
    return flags;
}

// N2nn3nex27MultiPRUDPStreamTemplateImpE: a stream template of each type, and
// the current one, which the other slots forward to.
class MultiPRUDPStreamTemplateImp : public PRUDPStreamTemplateInterface, public RootObject {
public:
    ~MultiPRUDPStreamTemplateImp() override;
    virtual void vf2();
    virtual void vf3(u64 value, u64 arg2);
    virtual void vf4(u64 value, u64 arg2, u64 arg3, u64 arg4);
    virtual u32 vf5(u64 arg1, u64 arg2, u64 arg3, Unk_160a230_Message* message, u64 arg5,
                    u64 arg6, u64 arg7, u32 arg8);
    virtual void vf6(u64 value, u64 arg2, u64 arg3, u64 arg4);
    virtual void vf7(const Unk_160aa00_arg1* value);
    virtual u32 vf8();
    // makes the stream template of the type current (creating it)
    virtual void vf9(u32 type);

    u32 field_8;
    u32 m_type;
    PRUDPStreamTemplateBase* m_current;
    std::map<u32, PRUDPStreamTemplateBase*, std::less<u32>,
             MemAllocator<std::pair<const u32, PRUDPStreamTemplateBase*>>>
        m_streams;
    Unk_160aa00_arg1 field_30;
};
PKMN_OFFSET_ASSERT(MultiPRUDPStreamTemplateImp, m_current, 0x10);
PKMN_OFFSET_ASSERT(MultiPRUDPStreamTemplateImp, m_streams, 0x18);
PKMN_OFFSET_ASSERT(MultiPRUDPStreamTemplateImp, field_30, 0x30);

// 0x710160a830 (D2), 0x710160a8e0 (D0). The loops compare with end() first (the
// original's cmp order).
MultiPRUDPStreamTemplateImp::~MultiPRUDPStreamTemplateImp() {
    for (auto it = m_streams.begin(); m_streams.end() != it; ++it) {
        delete it->second;
    }
}

// 0x710160a9d0
u32 MultiPRUDPStreamTemplateImp::vf5(u64 arg1, u64 arg2, u64 arg3, Unk_160a230_Message* message,
                                     u64 arg5, u64 arg6, u64 arg7, u32 arg8) {
    return m_current->vf5(arg1, arg2, arg3, message, arg5, arg6, arg7, arg8);
}

// 0x710160aa00
void MultiPRUDPStreamTemplateImp::vf7(const Unk_160aa00_arg1* value) {
    field_30 = *value;
    for (auto it = m_streams.begin(); m_streams.end() != it; ++it) {
        it->second->vf7(value);
    }
}

// 0x710160aab0
void MultiPRUDPStreamTemplateImp::vf9(u32 type) {
    if (m_streams[type] == nullptr) {
        Unk_160aab0_Instance* instance = Unk_160aab0_GetInstance();
        Unk_160aab0_Context* context = instance != nullptr ? instance->m_context : nullptr;
        PacketEncDecInf* encDec =
            type == 1 || type == 2 ? context->m_liteEncDec : context->m_encDec;
        PRUDPStreamTemplateBase* stream;
        if (type == 0) {
            stream = new PRUDPStreamTemplateImp(field_8, encDec);
        } else {
            stream = new PRUDPStreamTemplatePRUDPLiteImp(field_8, encDec);
        }
        if (field_30.field_0 != 0) {
            stream->vf7(&field_30);
        }
        m_streams[type] = stream;
    }
    m_current = m_streams[type];
    m_type = type;
}

// N2nn3nex21PRUDPMessageInterfaceE (see Unk_160a230.h)
class PRUDPMessageInterface {};

// N2nn3nex20PRUDPMessageSelectorE
class PRUDPMessageSelector : public PRUDPMessageInterface, public RootObject {
public:
    // 0x7101605f80
    PRUDPMessageSelector();
    ~PRUDPMessageSelector() override;

    u8 _8[0x20];
};
PKMN_SIZE_ASSERT(PRUDPMessageSelector, 0x28);

// N2nn3nex18PRUDPLiteMessageV1E
class PRUDPLiteMessageV1 : public PRUDPMessageInterface, public RootObject {
public:
    PRUDPLiteMessageV1() : m_lock(1, true) { Unk_15bae60_seed(&m_random, Unk_15baf90_call()); }
    // 0x71016092c0 (D2), 0x7101609300 (D0)
    ~PRUDPLiteMessageV1() override;

    Unk_15bb890 m_random;
    nn::nex::CriticalSection m_lock;
};
PKMN_OFFSET_ASSERT(PRUDPLiteMessageV1, m_lock, 0x9d8);
PKMN_SIZE_ASSERT(PRUDPLiteMessageV1, 0xa20);

// N2nn3nex21ProtocolMessageHolderE
class ProtocolMessageHolder : public RootObject {
public:
    ProtocolMessageHolder();
    ~ProtocolMessageHolder() override;

    PRUDPMessageSelector* m_selector;
    PRUDPLiteMessageV1* m_liteMessage;
};
PKMN_SIZE_ASSERT(ProtocolMessageHolder, 0x18);

// 0x710160ae90
ProtocolMessageHolder::ProtocolMessageHolder() {
    m_selector = new PRUDPMessageSelector;
    m_liteMessage = new PRUDPLiteMessageV1;
}

// 0x710160af30 (D2), 0x710160af90 (D0)
ProtocolMessageHolder::~ProtocolMessageHolder() {
    delete m_selector;
    delete m_liteMessage;
}

}  // namespace nex
}  // namespace nn
