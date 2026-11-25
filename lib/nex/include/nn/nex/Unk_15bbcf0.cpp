// Scope: common
// NEX 4.6.8: the rest of OnlineCore's Platform/Core/Result.cpp, then a mutex
// and condition variable's wrappers, the allocator's out-of-line copies, a
// timeout and nn::nex::String's buffer. Everything the executable doesn't
// name keeps a placeholder.
#include <stddef.h>
#include <string.h>

#include <atomic>

#include <nn/nex/Call.h>
#include <nn/nex/String.h>
#include <nn/os.h>

extern "C" void* malloc(size_t size);
extern "C" void free(void* p);

namespace nn {
namespace os {

void SignalConditionVariable(ConditionVariableType* cv) noexcept;

}  // namespace os
}  // namespace nn

#define UNK_RESULT_FILE "C:/home/ws/hac-appor/Pack/7923402a/OnlineCore/src/Platform/Core/Result.cpp"

// 0x71015bbcf0
void Unk_15bbcf0(Unk_15bbc10* self, const u32& code) {
    self->m_code = code;
    self->m_file = UNK_RESULT_FILE;
    self->m_line = 161;
}

// The result's safe bool: a pointer to a member function (its code, an empty
// function, folded by the linker with the others at 0x71006a5220).
struct Unk_15bbd30_Bool {
    void Unk_6a5220() const;
};
typedef void (Unk_15bbd30_Bool::*Unk_15bbd30_SafeBool)() const;

inline Unk_15bbd30_SafeBool Unk_15bbd30_ToBool(const Unk_15bbc10* self) {
    return static_cast<s32>(self->m_code) >= 0 ? &Unk_15bbd30_Bool::Unk_6a5220 : nullptr;
}

// 0x71015b87f0: the result's description.
int Unk_15b87f0(const Unk_15bbc10* self);

// 0x71015bbd30: the result as an nn::Result value (module and description).
u64 Unk_15bbd30(const Unk_15bbc10* self) {
    u32 code = self->m_code;
    if (Unk_15bbd30_ToBool(self)) {
        return code == 0x10002 ? static_cast<u64>(0x3e8132) : 0;
    }
    int description = Unk_15b87f0(self);
    if (description < 0) {
        description = 0;
    }
    u32 module = (code & 0x7ff0000) == 0x720000 ? 0x133 : 0x132;
    return module | (description << 9);
}

// A mutex.
struct Unk_15bbda0 {
    u8 _0[0x10];
    nn::os::MutexType m_mutex;
};
PKMN_OFFSET_ASSERT(Unk_15bbda0, m_mutex, 0x10);

// 0x71015bbda0
void Unk_15bbda0_lock(Unk_15bbda0* self) {
    nn::os::LockMutex(&self->m_mutex);
}

// 0x71015bbee0
void Unk_15bbee0_unlock(Unk_15bbda0* self) {
    nn::os::UnlockMutex(&self->m_mutex);
}

// A condition variable, with how many threads wait on it.
struct Unk_15bbdb0 {
    nn::os::ConditionVariableType* m_cv;
    std::atomic<s32> m_waiters;
    bool m_broadcast;
};
PKMN_OFFSET_ASSERT(Unk_15bbdb0, m_waiters, 0x8);
PKMN_OFFSET_ASSERT(Unk_15bbdb0, m_broadcast, 0xc);

// 0x71015bbdb0: waits (at most `timeoutMs` milliseconds, -1: no limit).
bool Unk_15bbdb0_wait(Unk_15bbdb0* self, Unk_15bbda0* mutex, u32 timeoutMs) {
    s32 waiters = self->m_waiters.load();
    while (!self->m_waiters.compare_exchange_weak(waiters, waiters + 1)) {
    }
    nn::os::ConditionVariableType* cv = self->m_cv;
    nn::os::MutexType* osMutex = &mutex->m_mutex;
    if (timeoutMs == static_cast<u32>(-1)) {
        nn::os::WaitConditionVariable(cv, osMutex);
    } else {
        nn::TimeSpan timeout = {static_cast<s64>(timeoutMs) * 1000 * 1000};
        nn::os::TimedWaitConditionVariable(cv, osMutex, timeout);
    }
    waiters = self->m_waiters.load();
    while (!self->m_waiters.compare_exchange_weak(waiters, waiters - 1)) {
    }
    return true;
}

// 0x71015bbef0
void Unk_15bbef0_signal(Unk_15bbdb0* self) {
    if (self->m_broadcast) {
        nn::os::BroadcastConditionVariable(self->m_cv);
    } else {
        nn::os::SignalConditionVariable(self->m_cv);
    }
}

// The allocator and the free function NEX's blocks record (null: malloc and
// free).
extern void* (*Unk_27f2a70)(size_t size);
extern void (*Unk_27f2a78)(void* block);

// A block: the function that frees it, then the data at +0x10.
struct Unk_15bbf10_Block {
    void (*m_free)(void* block);
    u8 _8[0x8];
};
PKMN_SIZE_ASSERT(Unk_15bbf10_Block, 0x10);

inline void* Unk_Allocate(size_t size) {
    size_t blockSize = (size + sizeof(Unk_15bbf10_Block) + 7) & ~static_cast<size_t>(7);
    Unk_15bbf10_Block* block;
    if (Unk_27f2a70 != nullptr) {
        block = static_cast<Unk_15bbf10_Block*>(Unk_27f2a70(blockSize));
    } else {
        block = static_cast<Unk_15bbf10_Block*>(malloc(blockSize));
    }
    block->m_free = Unk_27f2a78;
    return block + 1;
}

inline void Unk_Free(void* p) {
    Unk_15bbf10_Block* block = static_cast<Unk_15bbf10_Block*>(p) - 1;
    if (block->m_free != nullptr) {
        block->m_free(block);
    } else {
        free(block);
    }
}

// 0x71015bbf10
void* Unk_15bbf10(size_t size) {
    return Unk_Allocate(size);
}

// 0x71015bbf60
void Unk_15bbf60(void* p) {
    if (p != nullptr) {
        Unk_Free(p);
    }
}

// An instance's allocator.
struct Unk_15bbf80_Allocator {
    u8 _0[0x28];
    void* (*m_allocate)(size_t size);
};
PKMN_OFFSET_ASSERT(Unk_15bbf80_Allocator, m_allocate, 0x28);
// InstanceTable.h's table and its entries also hold each instance's allocator
// (the table's default one at 0x80, a thread's at 0x78 of its entry), which
// that header's views don't have yet.
struct Unk_15bbf80_Entry {
    u8 _0[0x78];
    Unk_15bbf80_Allocator* m_allocator;
};
PKMN_OFFSET_ASSERT(Unk_15bbf80_Entry, m_allocator, 0x78);
struct Unk_15bbf80_Table {
    u8 _0[0x80];
    Unk_15bbf80_Allocator* m_default;
};
PKMN_OFFSET_ASSERT(Unk_15bbf80_Table, m_default, 0x80);

// 0x71015be1a0
void Unk_15be1a0(void* list, const u32* value);
// Where errors are reported (0x71015b8dc0 is the out-of-line copy of
// Unk_ReportError, with a source file and line it doesn't use).
struct Unk_27f35d8_t {
    u8 _0[0x38];
    u8 m_codes[0x80];
    u8 m_args[0x10];
};
extern Unk_27f35d8_t* Unk_27f35d8;

inline void Unk_ReportError(u32 code, u32 arg) {
    Unk_15be1a0(Unk_27f35d8->m_codes, &code);
    Unk_15be1a0(Unk_27f35d8->m_args, &arg);
}

inline Unk_15bbf80_Allocator* Unk_GetAllocator() {
    Unk_15bbf80_Allocator** slot = &reinterpret_cast<Unk_15bbf80_Table&>(Unk_27f3770).m_default;
    if (Unk_27f3838) {
        u32 index = *Unk_6a5230(Unk_27f3830);
        if (index != 0) {
            nn::nex::qVector<Unk_InstanceEntry*>& threads = *Unk_27f3770.m_threads;
            if (index >= threads.size()) {
                Unk_ReportError(0xe0000003, 0);
                return nullptr;
            }
            slot = &reinterpret_cast<Unk_15bbf80_Entry*>(threads[index])->m_allocator;
        }
    }
    return *slot;
}

// 0x71015bbf80
void* Unk_15bbf80(size_t size, u32 flag) {
    if (flag != 0) {
        return nullptr;
    }
    Unk_15bbf80_Allocator* allocator = Unk_GetAllocator();
    if (allocator->m_allocate != nullptr) {
        return allocator->m_allocate(size);
    }
    return Unk_Allocate(size);
}

// A time (a copy constructor of its own: returned through memory).
struct Unk_244f0b0_Time {
    Unk_244f0b0_Time() : m_value(0) {}
    Unk_244f0b0_Time(const Unk_244f0b0_Time& other) : m_value(other.m_value) {}

    u64 m_value;
};
// 0x71015bde80
Unk_244f0b0_Time Unk_15bde80(u32 arg);
// 0x71015be030
Unk_244f0b0_Time Unk_15be030();
extern bool Unk_244f0f0;
extern Unk_244f0b0_Time Unk_27f3570;  // the last time read

inline Unk_244f0b0_Time Unk_GetTime() {
    Unk_244f0b0_Time time = Unk_244f0f0 ? Unk_15bde80(0) : Unk_15be030();
    Unk_27f3570 = time;
    return time;
}

// A timeout: how long it lasts and when it started (vtable 0x710244f0b0).
class Unk_244f0b0 {
public:
    static void operator delete(void* p) {
        if (p != nullptr) {
            Unk_Free(p);
        }
    }

    Unk_244f0b0(u32 arg, u32 timeout);
    virtual ~Unk_244f0b0();

    u16 field_8;
    u32 m_timeout;
    Unk_244f0b0_Time m_start;
    u32 m_elapsed;
    u32 field_1c;
    u32 field_20;
    u32 field_24;
    u32 field_28;
    u32 field_2c;
    bool field_30;
};
PKMN_OFFSET_ASSERT(Unk_244f0b0, m_timeout, 0xc);
PKMN_OFFSET_ASSERT(Unk_244f0b0, m_start, 0x10);
PKMN_OFFSET_ASSERT(Unk_244f0b0, field_28, 0x28);
PKMN_OFFSET_ASSERT(Unk_244f0b0, field_30, 0x30);

// 0x71015bc0a0
Unk_244f0b0::Unk_244f0b0(u32 arg, u32 timeout) {
    field_1c = arg;
    m_timeout = timeout;
    Unk_244f0b0_Time now = Unk_GetTime();
    field_8 = 1;
    m_start.m_value = now.m_value;
    m_elapsed = 0;
    field_20 = 0;
    field_30 = false;
    field_28 = 0;
    field_2c = 8;
}

// 0x71015bc130 (the D0 at 0x71015bc140 frees it)
Unk_244f0b0::~Unk_244f0b0() {}

// NON_MATCHING: register allocation: the original loads the time it read
// before the last-time global's address (the constructor's order is the other
// way round, as here).
// 0x71015bc160: the time left (-1: no limit).
u32 Unk_15bc160(Unk_244f0b0* self) {
    if (self->m_timeout == static_cast<u32>(-1)) {
        return static_cast<u32>(-1);
    }
    Unk_244f0b0_Time now = Unk_GetTime();
    self->m_elapsed = static_cast<u32>(now.m_value - self->m_start.m_value);
    return self->m_timeout > self->m_elapsed ? self->m_timeout - self->m_elapsed : 0;
}

// A string's buffer: a block (see Unk_Allocate) with its size before the
// characters.
struct Unk_15bc1e0_Block {
    void (*m_free)(void* block);
    u8 _8[0x8];
    u32 m_size;
    char m_data[1];
};
PKMN_OFFSET_ASSERT(Unk_15bc1e0_Block, m_size, 0x10);
PKMN_OFFSET_ASSERT(Unk_15bc1e0_Block, m_data, 0x14);

inline char* Unk_AllocateString(size_t size) {
    size_t blockSize = (offsetof(Unk_15bc1e0_Block, m_data) + size + 7) & ~static_cast<size_t>(7);
    Unk_15bc1e0_Block* block;
    if (Unk_27f2a70 != nullptr) {
        block = static_cast<Unk_15bc1e0_Block*>(Unk_27f2a70(blockSize));
    } else {
        block = static_cast<Unk_15bc1e0_Block*>(malloc(blockSize));
    }
    block->m_free = Unk_27f2a78;
    block->m_size = static_cast<u32>(size);
    return block->m_data;
}

// 0x71015bc1e0: copies at most `length` characters of `str` (all of it for
// -1) into the string, growing its buffer when needed.
void Unk_15bc1e0(nn::nex::String* self, const char* str, size_t length) {
    char empty = '\0';
    const char* src = str != nullptr ? str : &empty;
    size_t limit = length == static_cast<size_t>(-1) ? length : length + 1;
    size_t size = strlen(src) + 1;
    if (limit < size) {
        size = limit;
    }
    if (size == 0) {
        size = 1;
    }
    if (size > self->m_capacity) {
        self->Unk_15bc310();
        self->m_ptr = Unk_AllocateString(size);
        self->m_capacity = size;
    }
    char* dst = self->m_ptr;
    for (; size > 1 && *src != '\0'; size--) {
        *dst++ = *src++;
    }
    for (; size != 0; size--) {
        *dst++ = '\0';
    }
}

// 0x71015bc310
void nn::nex::String::Unk_15bc310() {
    if (m_ptr != nullptr && m_ptr != m_buf) {
        Unk_Free(m_ptr - 4);
    }
}
