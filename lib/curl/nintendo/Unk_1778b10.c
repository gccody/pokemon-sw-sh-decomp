/*
 * Pokemon SwSh decomp: Nintendo's threads for libcurl's resolver, not
 * public, reconstructed from the binary (Sword 0x7101778b10 to
 * 0x7101779270, the last of the libcurl area).
 *
 * Nintendo's SDK build has no curl_threads.c: Curl_thread_create starts an
 * nn::os thread (named "LibcurlResolver") for each lookup, and a manager
 * thread that global_init() starts (Unk_1778ce0) waits for the lookups that
 * have finished and frees their threads. curl_global_cleanup() stops it
 * (Unk_1779030). The manager keeps the running and finished threads in two
 * curl lists. Curl_thread_destroy does nothing and Curl_thread_join only
 * checks the handle: the manager does both. The names of the file and of
 * all but the Curl_thread_* functions (which asyn-thread.c calls) aren't
 * known.
 */

#include "curl_setup.h"

#include <errno.h>
#include <stddef.h>
#include <string.h>

#include "llist.h"
#include "curl_threads.h"
#include "curl_memory.h"

/* The SDK's abort (an NN_ABORT whose strings a release build empties). */
void nndetailDiagAbortFormatImpl(const char *condition, const char *function,
                                 const char *file, int line,
                                 const char *format, ...)
  __attribute__((noreturn));
#define NN_ABORT() nndetailDiagAbortFormatImpl("", "", "", 0, "")

void nnsocketSetLastErrno(int error);

/* Nintendo's aligned allocation pair (lib/curl/nintendo/Unk_17782a0.c). */
void *Unk_1778380(size_t alignment, size_t size);
void Unk_17783e0(void *ptr);

/* A thread (curl_thread_t), 0x1f0 bytes (malloc'd and zeroed). */
struct Unk_1778b10_Thread {
  /* the SDK's thread object: nnosCreateThread and the others take the
     thread's address */
  unsigned char thread[0x1c0];
  unsigned int (*func)(void *);
  void *arg;
  void *stack;
  struct curl_llist_element elem; /* in the manager's lists */
};
_Static_assert(sizeof(struct Unk_1778b10_Thread) == 0x1f0, "Thread");
_Static_assert(offsetof(struct Unk_1778b10_Thread, func) == 0x1c0, "func");
_Static_assert(offsetof(struct Unk_1778b10_Thread, stack) == 0x1d0, "stack");
_Static_assert(offsetof(struct Unk_1778b10_Thread, elem) == 0x1d8, "elem");

/* Sword 0x71027fc4a8: the manager. */
struct Unk_27fc4a8 {
  int state; /* 0 before init, 1 init, 2 started, 3 running, 4 done */
  int refcount;
  struct Unk_1778b10_Thread *thread;
  nnosEventType event;   /* signaled when a thread finishes, and to stop */
  nnosMutexType mutex;
  struct curl_llist *running;
  struct curl_llist *finished;
  nnosEventType started;
} Unk_27fc4a8;
_Static_assert(sizeof(Unk_27fc4a8) == 0x90, "Unk_27fc4a8");
_Static_assert(offsetof(struct Unk_27fc4a8, event) == 0x10, "event");
_Static_assert(offsetof(struct Unk_27fc4a8, mutex) == 0x38, "mutex");
_Static_assert(offsetof(struct Unk_27fc4a8, running) == 0x58, "running");
_Static_assert(offsetof(struct Unk_27fc4a8, started) == 0x68, "started");

unsigned int Unk_1778e40(void *arg);
void Unk_1778c90(void *arg);
int Unk_1778f90(struct Unk_1778b10_Thread *t);
static void Unk_1778f30(void *user, void *ptr);
static void Unk_1778f40(void *user, void *ptr);

static void free_thread(struct Unk_1778b10_Thread *t)
{
  nnosDestroyThread((nnosThreadType *)t->thread);
  if(t->stack) {
    Unk_17783e0(t->stack);
    t->stack = NULL;
  }
  t->func = NULL;
  t->arg = NULL;
  free(t);
}

/* Sword 0x7101778b10 */
// NON_MATCHING: the same instructions but for the cleanup's two tests:
// the original tests the result's failure before the handle, and copies the
// allocation into the handle on the malloc failure path, where this keeps
// NULL.
struct Unk_1778b10_Thread *Unk_1778b10(size_t stackSize,
                                       unsigned int (*func)(void *),
                                       void *arg)
{
  nnResult result = { (uint32_t)-1 };
  struct Unk_1778b10_Thread *hnd = NULL;
  struct Unk_1778b10_Thread *t = malloc(sizeof(*t));
  if(t) {
    void *stack;
    memset(t, 0, sizeof(*t));
    stack = Unk_1778380(0x1000, stackSize);
    t->stack = stack;
    if(!stack) {
      free(t);
      t = NULL;
      result.value = (uint32_t)-1;
    }
    else {
      result = nnosCreateThread((nnosThreadType *)t->thread, Unk_1778c90, t,
                                stack, stackSize,
                                nnosGetThreadPriority(nnosGetCurrentThread()));
      if(!nnResultIsFailure(result)) {
        int core = -1;
        uint64_t mask = 0;
        nnosGetThreadCoreMask(&core, &mask, nnosGetCurrentThread());
        nnosSetThreadCoreMask((nnosThreadType *)t->thread, core, mask);
        nnosSetThreadNamePointer((nnosThreadType *)t->thread,
                                 "LibcurlResolver");
        hnd = t;
        hnd->func = func;
        hnd->arg = arg;
      }
      else
        hnd = t;
    }
  }
  if(nnResultIsFailure(result) && hnd) {
    nnosDestroyThread((nnosThreadType *)hnd->thread);
    if(hnd->stack) {
      Unk_17783e0(hnd->stack);
      hnd->stack = NULL;
    }
    hnd->func = NULL;
    hnd->arg = NULL;
    free(t);
    hnd = NULL;
  }
  return hnd;
}

/* Sword 0x7101778c90: every thread's entry */
void Unk_1778c90(void *arg)
{
  struct Unk_1778b10_Thread *t = arg;
  t->func(t->arg);
  if(t->func != Unk_1778e40)
    Unk_1778f90(t);
}

/* Sword 0x7101778ce0: global_init() starts the manager */
void *Unk_1778ce0(void)
{
  struct Unk_27fc4a8 *m = &Unk_27fc4a8;
  if(m->state)
    goto fail;
  m->state = 1;
  m->refcount++;
  m->thread = Unk_1778b10(0x4000, Unk_1778e40, NULL);
  if(!m->thread)
    goto fail;
  m->running = malloc(sizeof(struct curl_llist));
  if(!m->running)
    goto fail;
  Curl_llist_init(m->running, Unk_1778f30);
  m->finished = malloc(sizeof(struct curl_llist));
  if(!m->finished)
    goto fail;
  Curl_llist_init(m->finished, Unk_1778f40);
  nnosInitializeMutex(&m->mutex, true, 0);
  nnosInitializeEvent(&m->event, false, 1);
  nnosInitializeEvent(&m->started, false, 1);
  nnosStartThread((nnosThreadType *)m->thread->thread);
  nnosWaitEvent(&m->started);
  nnosFinalizeEvent(&m->started);
  return m;

fail:
  if(m->finished)
    Curl_llist_destroy(m->finished, NULL);
  if(m->running)
    Curl_llist_destroy(m->running, NULL);
  if(m->thread)
    free_thread(m->thread);
  m->state = 0;
  memset(&m->event, 0, sizeof(m->event));
  memset(&m->mutex, 0, sizeof(m->mutex));
  m->running = NULL;
  m->finished = NULL;
  return NULL;
}

/* Sword 0x7101778e40: the manager thread */
unsigned int Unk_1778e40(void *arg)
{
  struct Unk_27fc4a8 *m = &Unk_27fc4a8;
  (void)arg;
  m->state = 2;
  nnosSignalEvent(&m->started);
  for(;;) {
    struct curl_llist_element *e;
    nnosWaitEvent(&m->event);
    nnosLockMutex(&m->mutex);
    m->state = 3;
    e = m->finished->head;
    while(e) {
      struct curl_llist_element *next = e->next;
      struct Unk_1778b10_Thread *t = e->ptr;
      nnosUnlockMutex(&m->mutex);
      nnosWaitThread((nnosThreadType *)t->thread);
      nnosLockMutex(&m->mutex);
      Curl_llist_remove(m->finished, e, NULL);
      e = next;
    }
    if(!m->refcount &&
       !(Curl_llist_count(m->running) + Curl_llist_count(m->finished)))
      break;
    nnosUnlockMutex(&m->mutex);
  }
  m->state = 4;
  nnosUnlockMutex(&m->mutex);
  return 0;
}

/* Sword 0x7101778f30: the running list's destructor */
static void Unk_1778f30(void *user, void *ptr)
{
  (void)user;
  (void)ptr;
}

/* Sword 0x7101778f40: the finished list's destructor */
static void Unk_1778f40(void *user, void *ptr)
{
  (void)user;
  if(ptr)
    free_thread(ptr);
}

/* Sword 0x7101778f90: a thread has finished */
int Unk_1778f90(struct Unk_1778b10_Thread *t)
{
  struct Unk_27fc4a8 *m = &Unk_27fc4a8;
  struct curl_llist_element *e;
  if(!m->state)
    NN_ABORT();
  nnosLockMutex(&m->mutex);
  for(e = m->running->head; e; e = e->next)
    if(e->ptr == t)
      break;
  if(!e)
    NN_ABORT();
  Curl_llist_remove(m->running, e, NULL);
  Curl_llist_insert_next(m->finished, m->finished->tail, t, &t->elem);
  nnosSignalEvent(&m->event);
  nnosUnlockMutex(&m->mutex);
  return 0;
}

/* Sword 0x7101779030: curl_global_cleanup() stops the manager */
void Unk_1779030(void)
{
  struct Unk_27fc4a8 *m = &Unk_27fc4a8;
  if(!m->state)
    NN_ABORT();
  nnosLockMutex(&m->mutex);
  m->refcount--;
  nnosUnlockMutex(&m->mutex);
  nnosSignalEvent(&m->event);
  nnosWaitThread((nnosThreadType *)m->thread->thread);
  if(m->finished) {
    Curl_llist_destroy(m->finished, NULL);
    free(m->finished);
    m->finished = NULL;
  }
  if(m->running) {
    Curl_llist_destroy(m->running, NULL);
    free(m->running);
    m->running = NULL;
  }
  nnosFinalizeMutex(&m->mutex);
  nnosFinalizeEvent(&m->event);
  if(m->thread) {
    free_thread(m->thread);
    m->thread = NULL;
  }
  m->state = 0;
  memset(&m->event, 0, sizeof(m->event));
  memset(&m->mutex, 0, sizeof(m->mutex));
  m->running = NULL;
  m->finished = NULL;
}

static int thread_count(void)
{
  struct Unk_27fc4a8 *m = &Unk_27fc4a8;
  int n;
  if(!m->state)
    return -1;
  nnosLockMutex(&m->mutex);
  n = (int)(Curl_llist_count(m->running) + Curl_llist_count(m->finished));
  nnosUnlockMutex(&m->mutex);
  return n;
}

static void add_running(struct Unk_1778b10_Thread *t)
{
  struct Unk_27fc4a8 *m = &Unk_27fc4a8;
  if(!m->state)
    NN_ABORT();
  nnosLockMutex(&m->mutex);
  Curl_llist_insert_next(m->running, m->running->tail, t, &t->elem);
  nnosUnlockMutex(&m->mutex);
}

/* Sword 0x7101779140: at most 50 threads */
curl_thread_t Curl_thread_create(unsigned int (*func)(void *), void *arg)
{
  struct Unk_1778b10_Thread *t;
  int n = thread_count();
  if(n == -1)
    return NULL;
  if(n >= 50) {
    nnsocketSetLastErrno(EAGAIN);
    return NULL;
  }
  t = Unk_1778b10(0x1000, func, arg);
  if(t) {
    add_running(t);
    nnosStartThread((nnosThreadType *)t->thread);
  }
  return t;
}

/* Sword 0x7101779240 */
void Curl_thread_destroy(curl_thread_t hnd)
{
  (void)hnd;
}

/* Sword 0x7101779250 */
int Curl_thread_join(curl_thread_t *hnd)
{
  if(!hnd || !*hnd)
    return -1;
  return 0;
}
