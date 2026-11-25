// Scope: common
// NEX 4.6.8: LogDeviceConsole's output (RTTI: N2nn3nex16LogDeviceConsoleE,
// derived from N2nn3nex9LogDeviceE; the source file and function come from its
// log call), CriticalSection's destructor (N2nn3nex15CriticalSectionE, with a
// N2nn3nex14MutexPrimitiveE and a N2nn3nex11LockCheckerE), the copies of
// NEX's allocator that its containers use, the core's standard allocator, and
// PacketBufferManager (N2nn3nex19PacketBufferManagerE, a
// N2nn3nex15PseudoSingletonE, derived from N2nn3nex15InstanceControlE).
#include <stddef.h>

#include <nn/nex/qVector.h>
#include <nn/os.h>

extern "C" void* malloc(size_t size);
extern "C" void free(void* p);

namespace nn {
namespace mem {

// Only addressed: its size isn't known.
class StandardAllocator {
public:
    void* Allocate(size_t size) noexcept;
    void Free(void* p) noexcept;
};

}  // namespace mem
}  // namespace nn

#define UNK_LOG_DEVICE_CONSOLE_FILE \
    "C:/home/ws/hac-appor/Pack/7923402a/OnlineCore/src/Platform/Core/LogDeviceConsole.cpp"

// The allocator and the free function NEX's blocks record (null: malloc and
// free), as in lib/nex/include/nn/nex/Unk_15bbcf0.cpp.
extern void* (*Unk_27f2a70)(size_t size);
extern void (*Unk_27f2a78)(void* block);

// A block: the function that frees it, then the data at +0x10.
struct Unk_15b9340_Block {
    void (*m_free)(void* block);
    u8 _8[0x8];
};
PKMN_SIZE_ASSERT(Unk_15b9340_Block, 0x10);

inline void* Unk_Allocate(size_t size) {
    size_t blockSize = (size + sizeof(Unk_15b9340_Block) + 7) & ~static_cast<size_t>(7);
    Unk_15b9340_Block* block;
    if (Unk_27f2a70 != nullptr) {
        block = static_cast<Unk_15b9340_Block*>(Unk_27f2a70(blockSize));
    } else {
        block = static_cast<Unk_15b9340_Block*>(malloc(blockSize));
    }
    block->m_free = Unk_27f2a78;
    return block + 1;
}

inline void Unk_Free(void* p) {
    Unk_15b9340_Block* block = static_cast<Unk_15b9340_Block*>(p) - 1;
    if (block->m_free != nullptr) {
        block->m_free(block);
    } else {
        free(block);
    }
}

// 0x71015be1a0
void Unk_15be1a0(void* list, const u32* value);
// Where errors are reported, and the core's allocator.
struct Unk_27f35d8_t {
    u8 _0[0x38];
    u8 m_codes[0x80];
    u8 m_args[0x120];
    nn::mem::StandardAllocator m_allocator;
};
PKMN_OFFSET_ASSERT(Unk_27f35d8_t, m_args, 0xb8);
PKMN_OFFSET_ASSERT(Unk_27f35d8_t, m_allocator, 0x1d8);
extern Unk_27f35d8_t* Unk_27f35d8;

inline void Unk_ReportError(u32 code, u32 arg) {
    Unk_15be1a0(Unk_27f35d8->m_codes, &code);
    Unk_15be1a0(Unk_27f35d8->m_args, &arg);
}

namespace nn {
namespace nex {

// N2nn3nex9LogDeviceE
class LogDevice : public RootObject {
public:
    virtual void Output(const char* text) = 0;
};

// N2nn3nex16LogDeviceConsoleE
class LogDeviceConsole : public LogDevice {
public:
    ~LogDeviceConsole() override;
    // 0x71015b9290
    void Output(const char* text) override;
};

void LogDeviceConsole::Output(const char* text) {
    nn::diag::LogMetaData logMetaData;
    logMetaData.field_0 = 47;
    logMetaData.field_8 = UNK_LOG_DEVICE_CONSOLE_FILE;
    logMetaData.field_10 = __func__;
    logMetaData.field_18 = "";
    logMetaData.field_20 = 1;
    logMetaData.field_24 = 0;
    logMetaData.field_28 = false;
    logMetaData.field_30 = nullptr;
    logMetaData.field_38 = 0;
    nn::diag::detail::LogImpl(logMetaData, "%s\n", text);
}

// N2nn3nex14MutexPrimitiveE (its RTTI has no base)
class MutexPrimitive {
public:
    // 0x71015b9e70
    virtual ~MutexPrimitive() { nn::os::FinalizeMutex(&m_mutex); }

    nn::os::MutexType m_mutex;
};
PKMN_SIZE_ASSERT(MutexPrimitive, 0x28);

// N2nn3nex11LockCheckerE (lib/nex/Unk_1630ba0.cpp emits its destructors; here
// they're inline, as the original TU's are)
class LockChecker : public RootObject {
public:
    ~LockChecker() override {}

    bool field_8;
    u32 field_c;
    u32 field_10;
    u32 field_14;
};
PKMN_SIZE_ASSERT(LockChecker, 0x18);

// N2nn3nex15CriticalSectionE
class CriticalSection : public RootObject {
public:
    // The original TU defines NEX's allocator, so its D0 frees inline.
    static void operator delete(void* p) {
        if (p != nullptr) {
            Unk_Free(p);
        }
    }

    // 0x71015b9300 (D2), 0x71015b7a00 (D0)
    ~CriticalSection() override;
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual u32 vf5();
    virtual u32 vf6();

    MutexPrimitive m_mutex;
    LockChecker m_checker;
};
PKMN_OFFSET_ASSERT(CriticalSection, m_checker, 0x30);
PKMN_SIZE_ASSERT(CriticalSection, 0x48);

// NON_MATCHING: the original folds the `this + 0x10` for FinalizeMutex into the
// vtables' stp (`stp x8, x9, [x0], #0x10`); with -g, LLVM 7 leaves a DBG_VALUE
// of ~MutexPrimitive's `this` between them, which stops that fold (-g0 gives
// the original's code).
CriticalSection::~CriticalSection() {}

}  // namespace nex
}  // namespace nn

// 0x71015b9340
void* Unk_15b9340(size_t size) {
    return Unk_Allocate(size);
}

// 0x71015b9390
void Unk_15b9390(u64 p) {
    if (p != 0) {
        Unk_Free(reinterpret_cast<void*>(p));
    }
}

// 0x71015b93b0
void* Unk_15b93b0(size_t size) {
    return Unk_27f35d8->m_allocator.Allocate(size);
}

// 0x71015b93d0
void Unk_15b93d0(void* p) {
    Unk_27f35d8->m_allocator.Free(p);
}

// 0x71006a5230: the calling thread's instance index, in a thread-local table.
u32* Unk_6a5230(void* key);

// 0x71027f3770: each instance's pseudo-singletons (by their ID), the default
// instance's and each thread's.
struct Unk_27f3770_Entry {
    u8 _0[0x8];
    void* m_singletons[18];
};
struct Unk_27f3770_t {
    u8 _0[0x10];
    void* m_singletons[18];
    nn::nex::qVector<Unk_27f3770_Entry*>* m_threads;
};
PKMN_OFFSET_ASSERT(Unk_27f3770_t, m_threads, 0xa0);
extern Unk_27f3770_t Unk_27f3770;
extern bool Unk_27f3838;   // more than one instance
extern void* Unk_27f3830;  // the thread-local key of the instance index

inline void* Unk_GetPseudoSingleton(u32 id) {
    void** slot = &Unk_27f3770.m_singletons[id];
    if (Unk_27f3838) {
        u32 index = *Unk_6a5230(Unk_27f3830);
        if (index != 0) {
            nn::nex::qVector<Unk_27f3770_Entry*>& threads = *Unk_27f3770.m_threads;
            if (index >= threads.size()) {
                Unk_ReportError(0xe0000003, 0);
                return nullptr;
            }
            slot = &threads[index]->m_singletons[id];
        }
    }
    return *slot;
}

namespace nn {
namespace nex {

// N2nn3nex15InstanceControlE
class InstanceControl : public RootObject {
public:
    // 0x71015cdd00
    ~InstanceControl() override;

    u32 field_8;
    u32 field_c;
    u64 field_10;
    bool field_18;
};
PKMN_SIZE_ASSERT(InstanceControl, 0x20);

// N2nn3nex15PseudoSingletonE
class PseudoSingleton : public InstanceControl {
public:
    // 0x71015cefc0
    PseudoSingleton(u32 id);
};

// An element of a packet buffer pool (0x68 bytes).
struct Unk_15b9490_Element {
    static void operator delete[](void* p) { Unk_Free(p); }
    ~Unk_15b9490_Element() {}

    u8 _0[0x20];
    u64 field_20;
    u8 _28[0x40];
};
PKMN_SIZE_ASSERT(Unk_15b9490_Element, 0x68);

// A packet buffer pool: its elements and the buffer they're in.
struct Unk_15b9490_Pool {
    static void operator delete(void* p) {
        if (p != nullptr) {
            Unk_Free(p);
        }
    }

    void Unk_Release() {
        if (m_allocated) {
            m_allocated = false;
            for (u64 i = 0; i < m_count; i++) {
                m_elements[i].field_20 = 0;
            }
            delete[] m_elements;
            m_elements = nullptr;
            if (m_buffer != nullptr) {
                delete m_buffer;
                m_buffer = nullptr;
            }
        }
    }

    Unk_15b9490_Element* m_elements;
    u64 m_count;
    u8 _10[0x8];
    bool m_allocated;
    RootObject* m_buffer;
};
PKMN_OFFSET_ASSERT(Unk_15b9490_Pool, m_allocated, 0x18);
PKMN_OFFSET_ASSERT(Unk_15b9490_Pool, m_buffer, 0x20);

// N2nn3nex19PacketBufferManagerE (its ID is 14)
class PacketBufferManager : public PseudoSingleton {
public:
    // The original TU defines NEX's allocator, so its D0 frees inline.
    static void operator delete(void* p) {
        if (p != nullptr) {
            Unk_Free(p);
        }
    }

    // 0x71015b93f0
    PacketBufferManager();
    // 0x71015b9450 (D2), 0x71015b97f0 (D0)
    ~PacketBufferManager() override;
    // 0x71015b9490: releases the buffers (unless field_40 is set).
    void Unk_15b9490();
    // 0x71015b99c0
    void Unk_15b99c0();

    u64 field_20;
    u64 field_28;
    u8* field_30;
    u64 field_38;
    u64 field_40;
    u64 field_48;
    u64 field_50;
    u32 field_58;
    bool field_5c;
    Unk_15b9490_Pool* field_60;
    Unk_15b9490_Pool* field_68;
};
PKMN_OFFSET_ASSERT(PacketBufferManager, field_5c, 0x5c);
PKMN_OFFSET_ASSERT(PacketBufferManager, field_68, 0x68);
PKMN_SIZE_ASSERT(PacketBufferManager, 0x70);

PacketBufferManager::PacketBufferManager()
    : PseudoSingleton(14), field_20(0), field_28(0), field_30(nullptr), field_38(0), field_40(0),
      field_48(8), field_50(4), field_58(0), field_5c(false), field_60(nullptr),
      field_68(nullptr) {}

PacketBufferManager::~PacketBufferManager() {
    field_40 = 0;
    Unk_15b9490();
}

// What guards the packet buffers.
extern CriticalSection Unk_27f2a80;

}  // namespace nex
}  // namespace nn

// A critical section, held for the scope.
class Unk_15b9860_Lock {
public:
    Unk_15b9860_Lock(nn::nex::CriticalSection* cs) : m_cs(cs) { m_cs->vf2(); }
    ~Unk_15b9860_Lock() { m_cs->vf4(); }

private:
    nn::nex::CriticalSection* m_cs;
};

// 0x71015b9860
bool Unk_15b9860() {
    Unk_15b9860_Lock lock(&nn::nex::Unk_27f2a80);
    nn::nex::PacketBufferManager* manager =
        static_cast<nn::nex::PacketBufferManager*>(Unk_GetPseudoSingleton(14));
    return manager != nullptr && manager->field_5c;
}

extern bool Unk_244eee8 __attribute__((visibility("hidden")));

// 0x71015b9950: sets the flag, unless the manager's field_5c is set.
bool Unk_15b9950(bool flag) {
    Unk_15b9860_Lock lock(&nn::nex::Unk_27f2a80);
    if (Unk_15b9860()) {
        return false;
    }
    Unk_244eee8 = flag;
    return true;
}

// What pseudo-singleton 1's field_10 holds at 0xe8 (its slot 20 is called
// before the packet buffers are released).
class Unk_15b9490_e8 {
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
    virtual void vf15();
    virtual void vf16();
    virtual void vf17();
    virtual void vf18();
    virtual void vf19();
    virtual void vf20();
};
struct Unk_15b9490_10 {
    u8 _0[0xe8];
    Unk_15b9490_e8* field_e8;
};
struct Unk_15b9490_1 {
    u8 _0[0x10];
    Unk_15b9490_10* field_10;
};

inline bool Unk_GetFlag() {
    Unk_15b9860_Lock lock(&nn::nex::Unk_27f2a80);
    return Unk_244eee8;
}

void nn::nex::PacketBufferManager::Unk_15b9490() {
    Unk_15b9860_Lock lock(&Unk_27f2a80);
    if (field_40 != 0) {
        return;
    }
    if (!Unk_GetFlag() || !Unk_15b9860()) {
        return;
    }
    Unk_15b9490_1* singleton = static_cast<Unk_15b9490_1*>(Unk_GetPseudoSingleton(1));
    if (singleton != nullptr && singleton->field_10 != nullptr &&
        singleton->field_10->field_e8 != nullptr) {
        singleton->field_10->field_e8->vf20();
    }
    Unk_15b99c0();
    if (field_68 != nullptr) {
        field_68->Unk_Release();
    }
    if (field_68 != nullptr) {
        delete field_68;
        field_68 = nullptr;
    }
    if (field_60 != nullptr) {
        field_60->Unk_Release();
    }
    if (field_60 != nullptr) {
        delete field_60;
        field_60 = nullptr;
    }
    if (field_30 != nullptr) {
        Unk_Free(field_30);
    }
    field_30 = nullptr;
    field_28 = 0;
    field_20 = 0;
    field_5c = false;
}
