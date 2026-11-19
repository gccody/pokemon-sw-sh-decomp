#ifndef HEADER_CURL_NNOS_H
#define HEADER_CURL_NNOS_H
/*
 * Pokemon SwSh decomp: not upstream's. The parts of the SDK's nn::os C API
 * that Nintendo's SDK build of libcurl calls for its threads and locks
 * (curl_threads.h, lib/curl/nintendo/Unk_1778b10.c). The SDK's headers
 * aren't public: every function here is an import of main (nnos*, nnResult*)
 * and the parameters are what the callers pass. The types are only as large
 * as the callers show.
 */
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

/* nn::Result: one 32-bit value, passed and returned in a register. */
typedef struct {
  uint32_t value;
} nnResult;

/* 0x20 bytes: init_thread_sync_data allocates one (malloc(0x20)). */
typedef struct {
  unsigned char field_0[0x20];
} nnosMutexType;

/* 0x28 bytes: Nintendo's resolver thread manager keeps two (Sword
   0x71027fc4b8 and 0x71027fc510), with its mutex right after the first. */
typedef struct {
  unsigned char field_0[0x28];
} nnosEventType;

_Static_assert(sizeof(nnResult) == 4, "nnResult");
_Static_assert(sizeof(nnosMutexType) == 0x20, "nnosMutexType");
_Static_assert(sizeof(nnosEventType) == 0x28, "nnosEventType");

/* Only used by pointer; the thread objects of the resolver threads keep
   their own fields from 0x1c0 on (Unk_1778b10.c). */
typedef struct nnosThreadType nnosThreadType;

typedef void (*nnosThreadFunction)(void *arg);

bool nnResultIsFailure(nnResult result);

void nnosInitializeMutex(nnosMutexType *mutex, bool recursive, int lockLevel);
void nnosFinalizeMutex(nnosMutexType *mutex);
void nnosLockMutex(nnosMutexType *mutex);
void nnosUnlockMutex(nnosMutexType *mutex);

void nnosInitializeEvent(nnosEventType *event, bool signaled, int clearMode);
void nnosFinalizeEvent(nnosEventType *event);
void nnosSignalEvent(nnosEventType *event);
void nnosWaitEvent(nnosEventType *event);

nnResult nnosCreateThread(nnosThreadType *thread, nnosThreadFunction function,
                          void *arg, void *stack, size_t stackSize,
                          int priority);
void nnosDestroyThread(nnosThreadType *thread);
void nnosStartThread(nnosThreadType *thread);
void nnosWaitThread(nnosThreadType *thread);
nnosThreadType *nnosGetCurrentThread(void);
int nnosGetThreadPriority(const nnosThreadType *thread);
void nnosGetThreadCoreMask(int *idealCore, uint64_t *affinityMask,
                           const nnosThreadType *thread);
void nnosSetThreadCoreMask(nnosThreadType *thread, int idealCore,
                           uint64_t affinityMask);
void nnosSetThreadNamePointer(nnosThreadType *thread, const char *name);
/* A TimeSpan: nanoseconds. */
void nnosSleepThread(int64_t ns);

#endif /* HEADER_CURL_NNOS_H */
