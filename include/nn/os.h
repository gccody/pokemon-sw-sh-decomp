#pragma once

// Declarations for the parts of the Nintendo SDK (nn::os, nn::diag, nn::util)
// that decompiled code calls. The SDK headers aren't public: every function
// here is an import of `main`, and its name and parameter types come from the
// import's mangled name (e.g. _ZN2nn2os15InitializeMutexEPNS0_9MutexTypeEbi).
// Return types aren't part of a mangled name; they follow from how the callers
// use the result. They're noexcept, as the SDK declares its API: PhysX's
// RAII locks around them leave no unwind cleanup. Struct layouts are only what the callers show
// (sizes and the offsets they touch), so the fields are placeholders.

#include <stddef.h>
#include <stdint.h>

namespace nn {

// nn::TimeSpan, passed in one register: a 64-bit count of nanoseconds.
struct TimeSpan {
    int64_t field_0;
};
static_assert(sizeof(TimeSpan) == 0x8, "TimeSpan");

// The result of an SDK call that can fail: zero means success.
struct Result {
    uint32_t field_0;

    bool IsSuccess() const { return field_0 == 0; }
};
static_assert(sizeof(Result) == 0x4, "Result");

namespace os {

// 0x20 bytes: PhysX's MutexImpl (0x28 bytes) keeps its owner right after it.
struct MutexType {
    uint8_t field_0[0x20];
};
static_assert(sizeof(MutexType) == 0x20, "MutexType");

// 8 bytes: PhysX's SyncImpl keeps a MutexType right after it.
struct ConditionVariableType {
    uint8_t field_0[8];
};
static_assert(sizeof(ConditionVariableType) == 0x8, "ConditionVariableType");

// 0x1a8 bytes: PhysX's ThreadImpl keeps its own fields from 0x1a8 on. Before
// creating the thread, PhysX stores the priority it passes to CreateThread at
// 0x44 (field_44).
struct ThreadType {
    uint8_t field_0[0x44];
    int32_t field_44;
    uint8_t field_48[0x160];
};
static_assert(sizeof(ThreadType) == 0x1a8, "ThreadType");
static_assert(offsetof(ThreadType, field_44) == 0x44, "ThreadType::field_44");

// Only passed by pointer so far: no caller shows its size.
struct EventType;

// 0xc bytes, 4-aligned: gflib3 keeps one at +0x4 with a pointer at +0x10
// (0x710065f110) and one at +0xa4 with a pointer at +0xb0 (0x710065f1c0).
struct LightEventType {
    uint32_t field_0[3];
};
static_assert(sizeof(LightEventType) == 0xc, "LightEventType");

// How an event clears: an enum, from the imports' mangled names. Its
// enumerators aren't known.
enum EventClearMode : int {};

// nn::os::Tick, passed in one register: a 64-bit system tick count.
struct Tick {
    int64_t field_0;
};
static_assert(sizeof(Tick) == 0x8, "Tick");

// nn::os::TlsSlot, passed in one register: a 32-bit slot index.
struct TlsSlot {
    uint32_t field_0;
};
static_assert(sizeof(TlsSlot) == 0x4, "TlsSlot");

// nn::os::DefaultThreadPriority: the priority PhysX's threads get unless set.
const int DefaultThreadPriority = 16;

void InitializeMutex(MutexType* mutex, bool recursive, int lockLevel) noexcept;
void FinalizeMutex(MutexType* mutex) noexcept;
void LockMutex(MutexType* mutex) noexcept;
bool TryLockMutex(MutexType* mutex) noexcept;
void UnlockMutex(MutexType* mutex) noexcept;

void InitializeConditionVariable(ConditionVariableType* cv) noexcept;
void FinalizeConditionVariable(ConditionVariableType* cv) noexcept;
void BroadcastConditionVariable(ConditionVariableType* cv) noexcept;
void WaitConditionVariable(ConditionVariableType* cv, MutexType* mutex) noexcept;
int TimedWaitConditionVariable(ConditionVariableType* cv,
                               MutexType* mutex,
                               TimeSpan timeout) noexcept;

void InitializeEvent(EventType* event, bool signaled, EventClearMode clearMode) noexcept;
void FinalizeEvent(EventType* event) noexcept;
void SignalEvent(EventType* event) noexcept;
void ClearEvent(EventType* event) noexcept;
bool TryWaitEvent(EventType* event) noexcept;

void InitializeLightEvent(LightEventType* event, bool signaled, EventClearMode clearMode) noexcept;
void FinalizeLightEvent(LightEventType* event) noexcept;
void SignalLightEvent(LightEventType* event) noexcept;
void WaitLightEvent(LightEventType* event) noexcept;

int64_t GetSystemTickFrequency() noexcept;
Tick GetSystemTick() noexcept;
TimeSpan ConvertToTimeSpan(Tick tick) noexcept;

typedef void (*ThreadFunction)(void* argument);
Result CreateThread(ThreadType* thread,
                    ThreadFunction function,
                    void* argument,
                    void* stack,
                    size_t stackSize,
                    int priority) noexcept;
void DestroyThread(ThreadType* thread) noexcept;
void StartThread(ThreadType* thread) noexcept;
void WaitThread(ThreadType* thread) noexcept;
void YieldThread() noexcept;
void SleepThread(TimeSpan time) noexcept;
ThreadType* GetCurrentThread() noexcept;
uint64_t GetThreadId(const ThreadType* thread) noexcept;
void SetThreadNamePointer(ThreadType* thread, const char* name) noexcept;
void SetThreadCoreMask(ThreadType* thread, int idealCore, uint64_t affinityMask) noexcept;
void GetThreadCoreMask(int* idealCore, uint64_t* affinityMask, const ThreadType* thread) noexcept;
uint64_t GetThreadAvailableCoreMask() noexcept;

// nn::os::Mutex, the SDK's inline wrapper of a MutexType. Its destructor is
// emitted where its address is taken: _ZN2nn2os5MutexD2Ev at 0x710065d670,
// `b FinalizeMutex`, registered with __cxa_atexit for gflib3's static mutex.
class Mutex {
public:
    explicit Mutex(bool recursive) noexcept { InitializeMutex(&m_mutex, recursive, 0); }
    ~Mutex() noexcept { FinalizeMutex(&m_mutex); }

    void Lock() noexcept { LockMutex(&m_mutex); }
    void Unlock() noexcept { UnlockMutex(&m_mutex); }

private:
    MutexType m_mutex;
};
static_assert(sizeof(Mutex) == 0x20, "Mutex");

typedef void (*TlsDestructor)(uintptr_t value);
Result AllocateTlsSlot(TlsSlot* slot, TlsDestructor destructor) noexcept;
void FreeTlsSlot(TlsSlot slot) noexcept;
uintptr_t GetTlsValue(TlsSlot slot) noexcept;
void SetTlsValue(TlsSlot slot, uintptr_t value) noexcept;

}  // namespace os

namespace diag {

// 0x40 bytes, built on the stack for each LogImpl call.
struct LogMetaData {
    int32_t field_0;       // __LINE__
    const char* field_8;   // __FILE__
    const char* field_10;  // __func__
    const char* field_18;  // "" in PhysX
    int32_t field_20;      // 1 in PhysX
    int32_t field_24;      // 0 in PhysX
    bool field_28;         // false in PhysX
    const void* field_30;  // null in PhysX
    size_t field_38;       // 0 in PhysX
};
static_assert(sizeof(LogMetaData) == 0x40, "LogMetaData");
static_assert(offsetof(LogMetaData, field_8) == 0x8, "LogMetaData::field_8");
static_assert(offsetof(LogMetaData, field_10) == 0x10, "LogMetaData::field_10");
static_assert(offsetof(LogMetaData, field_18) == 0x18, "LogMetaData::field_18");
static_assert(offsetof(LogMetaData, field_20) == 0x20, "LogMetaData::field_20");
static_assert(offsetof(LogMetaData, field_24) == 0x24, "LogMetaData::field_24");
static_assert(offsetof(LogMetaData, field_28) == 0x28, "LogMetaData::field_28");
static_assert(offsetof(LogMetaData, field_30) == 0x30, "LogMetaData::field_30");
static_assert(offsetof(LogMetaData, field_38) == 0x38, "LogMetaData::field_38");

namespace detail {
void LogImpl(const LogMetaData& metaData, const char* format, ...) noexcept;
// Doesn't return: nothing follows its calls. Game code passes "" for each
// string and 0 for the int (src/unsorted/registry).
[[noreturn]] void AbortImpl(const char*, const char*, const char*, int) noexcept;
}  // namespace detail

}  // namespace diag

namespace util {
// Keeps `symbol` referenced, so the linker can't drop it.
void ReferSymbol(const void* symbol) noexcept;
}  // namespace util

}  // namespace nn
