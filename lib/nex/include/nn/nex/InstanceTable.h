#pragma once
// The lookup of the calling thread's instance of NEX's core that the protocol
// calls inline (N2nn3nex13InstanceTableE is a class of NEX's; its error names
// OnlineCore/src/Core/InstanceTable.h, line 71). The structs are placeholders.
#include <nn/nex/qVector.h>

#define NEX_INSTANCE_TABLE_H "..\\..\\..\\..\\.\\OnlineCore/src/Core/InstanceTable.h"

// 0x71015b8dc0: reports an error (source file, line, result code).
void Unk_15b8dc0(const char* file, u32 line, u32 code, u32 arg);
// 0x71006a5230: the calling thread's instance index, in a thread-local table.
u32* Unk_6a5230(void* key);

namespace nn {
namespace nex {

// N2nn3nex15CriticalSectionE (vf<slot>: placeholder names of its virtual functions).
class CriticalSection : public RootObject {
public:
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
};

}  // namespace nex
}  // namespace nn

struct Unk_Core {
    u8 _0[0x78];
    nn::nex::CriticalSection m_cs;
};
struct Unk_CoreHolder {
    u8 _0[0x10];
    Unk_Core* m_core;
};
struct Unk_Instance {
    u8 _0[0x10];
    Unk_CoreHolder* m_holder;
};
struct Unk_InstanceEntry {
    u8 _0[0x20];
    Unk_Instance* m_instance;
};
// 0x71027f3770: the instances, the default one and one per thread.
struct Unk_27f3770_t {
    u8 _0[0x28];
    Unk_Instance* m_default;
    u8 _30[0x70];
    nn::nex::qVector<Unk_InstanceEntry*>* m_threads;
};
PKMN_OFFSET_ASSERT(Unk_27f3770_t, m_threads, 0xa0);
extern Unk_27f3770_t Unk_27f3770;
extern bool Unk_27f3838;   // more than one instance
extern void* Unk_27f3830;  // the thread-local key of the instance index

inline Unk_Instance* GetInstance() {
    Unk_Instance** slot = &Unk_27f3770.m_default;
    if (Unk_27f3838) {
        u32 index = *Unk_6a5230(Unk_27f3830);
        if (index != 0) {
            nn::nex::qVector<Unk_InstanceEntry*>& threads = *Unk_27f3770.m_threads;
            if (index >= threads.size()) {
                Unk_15b8dc0(NEX_INSTANCE_TABLE_H, 71, 0xe0000003, 0);
                return nullptr;
            }
            slot = &threads[index]->m_instance;
        }
    }
    return *slot;
}

// The core's lock, held for the scope.
class Unk_ScopedCoreLock {
public:
    Unk_ScopedCoreLock() {
        Unk_Instance* instance = GetInstance();
        Unk_Core* core = nullptr;
        if (instance != nullptr && instance->m_holder != nullptr) {
            core = instance->m_holder->m_core;
        }
        m_cs = &core->m_cs;
        m_cs->vf2();
    }
    ~Unk_ScopedCoreLock() { m_cs->vf4(); }

private:
    nn::nex::CriticalSection* m_cs;
};
