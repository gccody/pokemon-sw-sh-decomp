// Scope: common
// NEX 4.6.8: the thread-safe call policy's lock (RTTI
// N2nn3nex20ThreadSafeCallPolicyE), WorkerThreads (N2nn3nex13WorkerThreadsE:
// its destructor and what its threads run) and ChecksumAlgorithm's
// (N2nn3nex17ChecksumAlgorithmE) checksum of one block. The members without a
// name in the executable are placeholders.
#include <nn/nex/qVector.h>

#include "Unk_15d4120.h"

// 0x71015ba080: the calling thread's ID.
u64 Unk_15ba080();

// Whether NEX runs without threads: it then takes no locks.
extern bool Unk_27f2ad0;

namespace nn {
namespace nex {

bool ThreadSafeCallPolicy::vf3() {
    return m_owner == Unk_15ba080();
}

bool ThreadSafeCallPolicy::vf4() {
    if (m_owner == static_cast<u64>(-1)) {
        return false;
    }
    return m_owner != Unk_15ba080();
}

bool ThreadSafeCallPolicy::vf5() {
    if (!Unk_27f2ad0 && !nn::os::TryLockMutex(&m_cs.m_mutex.m_mutex)) {
        return false;
    }
    m_owner = Unk_15ba080();
    m_lockCount++;
    return true;
}

void ThreadSafeCallPolicy::vf6() {
    m_lockCount--;
    m_owner = static_cast<u64>(-1);
    if (!Unk_27f2ad0) {
        nn::os::UnlockMutex(&m_cs.m_mutex.m_mutex);
    }
}

}  // namespace nex
}  // namespace nn

// A NEX thread (the base of the class of vtable 0x7102450888, which
// WorkerThreads starts): the class isn't known.
class Unk_244ef28 : public nn::nex::RootObject {};

// 0x71015ba7a0: waits for the thread to end (-1: without a timeout).
bool Unk_15ba7a0(Unk_244ef28* thread, s32 timeout);

// Holds a critical section for its scope (an inline helper; the name isn't
// the executable's).
class Unk_15d4460_Lock {
public:
    explicit Unk_15d4460_Lock(nn::nex::CriticalSection* cs) : m_cs(cs) { m_cs->vf2(); }
    ~Unk_15d4460_Lock() { m_cs->vf4(); }

    void Leave() { m_cs->vf4(); }
    void Enter() { m_cs->vf2(); }

private:
    nn::nex::CriticalSection* m_cs;
};

namespace nn {
namespace nex {

// N2nn3nex13WorkerThreadsE (its slot 4 is pure).
class WorkerThreads : public RootObject {
public:
    // 0x71015d4460 (D2), 0x71015d4580 (D0: a trap, the class is abstract)
    ~WorkerThreads() override;
    // 0x71015d48d0 (lib/nx_middleware/class)
    virtual void vf2();
    // 0x71015d48e0 (lib/nx_middleware/class)
    virtual void vf3();
    virtual void vf4() = 0;

    // 0x71015d4590: what each thread runs (WorkerThreads gives it to the
    // thread as a member function pointer): vf4 until the threads stop.
    void Unk_15d4590();

    CriticalSection m_cs;
    // 0: running, 1: stopping, 2: stopped
    u32 m_state;
    qVector<Unk_244ef28*> m_threads;
};
PKMN_OFFSET_ASSERT(WorkerThreads, m_state, 0x50);
PKMN_OFFSET_ASSERT(WorkerThreads, m_threads, 0x58);
PKMN_SIZE_ASSERT(WorkerThreads, 0x70);

WorkerThreads::~WorkerThreads() {
    Unk_15d4460_Lock lock(&m_cs);
    if (m_state != 0) {
        return;
    }
    m_state = 1;
    lock.Leave();
    for (u32 i = 0; i < m_threads.size(); i++) {
        Unk_15ba7a0(m_threads[i], -1);
        delete m_threads[i];
    }
    m_threads.clear();
    lock.Enter();
    m_state = 2;
}

void WorkerThreads::Unk_15d4590() {
    vf2();
    while (m_state == 0) {
        vf4();
    }
    vf3();
}

}  // namespace nex
}  // namespace nn

struct Unk_15c6560_Digest;

namespace nn {
namespace nex {

// N2nn3nex17ChecksumAlgorithmE, as lib/nex/Unk_15c64b0.h declares it (that
// header's CriticalSection is another declaration of this file's): only its
// slots.
class ChecksumAlgorithm : public RootObject {
public:
    virtual bool vf2(const Buffer& in, Buffer* out) = 0;
    virtual bool vf3(const void* const* data, const size_t* sizes, size_t count,
                     Unk_15c6560_Digest* out) = 0;
    virtual u32 vf4() = 0;
    virtual u32 vf5(const void* data, size_t size);
    // a 32-bit checksum of `count` blocks
    virtual u32 vf6(const void* const* data, const size_t* sizes, size_t count) = 0;
    virtual u32 vf7() = 0;
};

// 0x71015d4600: vf6 of one block
u32 ChecksumAlgorithm::vf5(const void* data, size_t size) {
    return vf6(&data, &size, 1);
}

}  // namespace nex
}  // namespace nn

// Compares the first `n` characters of two strings, as strncmp (an inline
// helper; the name isn't the executable's).
inline int Unk_15d4220_Compare(const char* a, const char* b, size_t n) {
    const unsigned char* l = reinterpret_cast<const unsigned char*>(a);
    const unsigned char* r = reinterpret_cast<const unsigned char*>(b);
    if (n-- == 0) {
        return 0;
    }
    for (; *r != 0 && *l != 0 && n != 0 && *l == *r; l++, r++, n--) {
    }
    return *l - *r;
}

// The first `pattern` (`length` characters) in the first `size` characters of
// `text`, or null (an inline helper; the name isn't the executable's).
inline const char* Unk_15d4220_Find(const char* text, const char* pattern, size_t length,
                                    size_t size = static_cast<size_t>(-1)) {
    for (size_t i = 0; text[i] != '\0' && i < size; i++) {
        if (Unk_15d4220_Compare(text + i, pattern, length) == 0) {
            return text + i;
        }
    }
    return nullptr;
}

// A URL's parts, `scheme://user:password@host:port/path`: each one's begin and
// end in the text, null when it's missing.
struct Unk_15d4220_Url {
    const char* m_scheme;
    const char* m_schemeEnd;
    const char* m_user;
    const char* m_userEnd;
    const char* m_password;
    const char* m_passwordEnd;
    const char* m_host;
    const char* m_hostEnd;
    const char* m_port;
    const char* m_portEnd;
    const char* m_path;
};
PKMN_OFFSET_ASSERT(Unk_15d4220_Url, m_host, 0x30);
PKMN_SIZE_ASSERT(Unk_15d4220_Url, 0x58);

// 0x71015d4220: splits `text`; false without a path or a host.
// NON_MATCHING: the inlined compare. The original tests the last character of
// "://" for 0 before comparing it (a csel) and doesn't peel the first
// character of the one-character searches; musl's order of strncmp's tests
// (`*l && *r && n`) gives other code still, and testing `*r` first (here)
// matches the scheme's search up to that last character only.
bool Unk_15d4220(Unk_15d4220_Url* url, const char* text) {
    url->m_scheme = nullptr;
    url->m_schemeEnd = nullptr;
    url->m_user = nullptr;
    url->m_userEnd = nullptr;
    url->m_password = nullptr;
    url->m_passwordEnd = nullptr;
    url->m_host = nullptr;
    url->m_hostEnd = nullptr;
    url->m_port = nullptr;
    url->m_portEnd = nullptr;
    url->m_path = nullptr;
    url->m_schemeEnd = Unk_15d4220_Find(text, "://", 3);
    if (url->m_schemeEnd != nullptr) {
        url->m_scheme = text;
        text = url->m_schemeEnd + 3;
    } else {
        url->m_scheme = nullptr;
    }
    url->m_path = Unk_15d4220_Find(text, "/", 1);
    if (url->m_path == nullptr) {
        return false;
    }
    const char* at = Unk_15d4220_Find(text, "@", 1);
    if (at != nullptr) {
        url->m_user = text;
        const char* colon = Unk_15d4220_Find(text, ":", 1);
        url->m_userEnd = colon <= at ? colon : nullptr;
        if (url->m_userEnd != nullptr) {
            url->m_password = url->m_userEnd + 1;
            url->m_passwordEnd = at;
        } else {
            url->m_userEnd = at;
            url->m_password = nullptr;
            url->m_passwordEnd = nullptr;
        }
        text = at + 1;
    } else {
        url->m_user = nullptr;
        url->m_userEnd = nullptr;
        url->m_password = nullptr;
        url->m_passwordEnd = nullptr;
    }
    url->m_host = text;
    url->m_hostEnd = Unk_15d4220_Find(text, ":", 1, url->m_path - text);
    if (url->m_hostEnd != nullptr) {
        url->m_port = url->m_hostEnd + 1;
        url->m_portEnd = url->m_path;
    } else {
        url->m_hostEnd = url->m_path;
        url->m_port = nullptr;
        url->m_portEnd = nullptr;
    }
    return url->m_host != url->m_hostEnd;
}
