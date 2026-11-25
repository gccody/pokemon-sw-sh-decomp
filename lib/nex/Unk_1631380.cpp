// Scope: common
// NEX 4.6.8: the key derivation (RTTI: N2nn3nex13KeyDerivationE), its MD5
// implementation (N2nn3nex16MD5KeyDerivationE), the default instance and the
// functions that go through the current one, and two calls to an object made
// under the core's lock.
#include <nn/nex/InstanceTable.h>

#include "Unk_1630ba0.h"

namespace nn {
namespace nex {

// N2nn3nex13KeyDerivationE
class KeyDerivation : public RootObject {
public:
    virtual Key vf2(u64 pid, const char* password) = 0;
    virtual Key vf3(const char* password) = 0;
    virtual Key vf4(u64 pid, const Key& key) = 0;
    virtual bool vf5(void* arg1, u64 pid, void* arg3, void* arg4) = 0;
    virtual bool vf6(void* arg1, void* arg2, void* arg3) = 0;
};

// N2nn3nex16MD5KeyDerivationE
class MD5KeyDerivation : public KeyDerivation {
public:
    MD5KeyDerivation(u32 iterations, u32 field_c) : m_iterations(iterations), field_c(field_c) {}
    ~MD5KeyDerivation() override;
    Key vf2(u64 pid, const char* password) override;
    Key vf3(const char* password) override;
    Key vf4(u64 pid, const Key& key) override;
    bool vf5(void* arg1, u64 pid, void* arg3, void* arg4) override;
    bool vf6(void* arg1, void* arg2, void* arg3) override;

    u32 m_iterations;
    u32 field_c;
};
PKMN_SIZE_ASSERT(MD5KeyDerivation, 0x10);

}  // namespace nex
}  // namespace nn

// 0x71015c5520: derives with the checksum algorithm (which it takes).
bool Unk_15c5520(void* arg0, nn::nex::ChecksumAlgorithm* algorithm, void* arg2, u32 iterations,
                 u64 pid, u32 arg5, void* arg6, u32 arg7);

// The keys already derived, by PID and password.
struct Unk_27f9810_t;
// 0x71015c5f00: the key derived for the PID and password, if there's one.
bool Unk_15c5f00(Unk_27f9810_t* self, u64 pid, const char* password, nn::nex::Key* key);
// 0x71015c6100: keeps the key derived for the PID and password.
void Unk_15c6100(Unk_27f9810_t* self, u64 pid, const char* password, const nn::nex::Key& key);
extern Unk_27f9810_t* Unk_27f9810;

struct Unk_27f9818_t {
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4(void* arg);
    virtual bool vf5();
};
extern Unk_27f9818_t* Unk_27f9818;

// The default key derivation, and the current one.
static nn::nex::MD5KeyDerivation Unk_27f9a48(1, 1);
nn::nex::KeyDerivation* Unk_2454540 = &Unk_27f9a48;

// 0x7101631380
bool Unk_1631380(void* arg1, u64 pid, void* arg3, void* arg4) {
    return Unk_2454540->vf5(arg1, pid, arg3, arg4);
}

// 0x71016313b0: the key for the PID and password, from the keys already
// derived if they have it.
nn::nex::Key Unk_16313b0(u64 pid, const char* password) {
    if (Unk_2454540 == nullptr) {
        Unk_2454540 = &Unk_27f9a48;
    }
    if (Unk_27f9810 != nullptr) {
        nn::nex::Key key;
        if (!Unk_15c5f00(Unk_27f9810, pid, password, &key)) {
            key = Unk_2454540->vf2(pid, password);
            Unk_15c6100(Unk_27f9810, pid, password, key);
        }
        return key;
    }
    return Unk_2454540->vf2(pid, password);
}

// 0x71016315d0
void Unk_16315d0() {
    Unk_ScopedCoreLock lock;
    if (Unk_27f9818 != nullptr) {
        Unk_27f9818->vf3();
    }
}

// 0x71016316b0
void Unk_16316b0(void* arg) {
    Unk_ScopedCoreLock lock;
    Unk_27f9818_t* object = Unk_27f9818;
    if (object != nullptr && object->vf5()) {
        object->vf4(arg);
    }
}

namespace nn {
namespace nex {

// 0x71016317b0 (D2), 0x71016317c0 (D0)
MD5KeyDerivation::~MD5KeyDerivation() {}

// 0x71016317d0
Key MD5KeyDerivation::vf2(u64 pid, const char* password) {
    Key key = vf3(password);
    return vf4(pid, key);
}

// 0x7101631840
Key MD5KeyDerivation::vf3(const char* password) {
    u32 iterations = m_iterations;
    MD5Checksum checksum;
    return checksum.Unk_15c4f10(password, iterations);
}

// 0x71016319e0
// NON_MATCHING: the original checks the allocation for null before it
// constructs the checksum (NEX's operator new doesn't throw), but RootObject's
// operator new (nn/nex/RootObject.h) isn't declared non-throwing.
bool MD5KeyDerivation::vf5(void* arg1, u64 pid, void* arg3, void* arg4) {
    u32 iterations = m_iterations;
    u32 arg5 = field_c;
    return Unk_15c5520(arg1, new MD5Checksum, arg3, iterations, pid, arg5, arg4, 2);
}

// 0x7101631a60
// NON_MATCHING: the original checks the allocation for null before it
// constructs the checksum (NEX's operator new doesn't throw), but RootObject's
// operator new (nn/nex/RootObject.h) isn't declared non-throwing.
bool MD5KeyDerivation::vf6(void* arg1, void* arg2, void* arg3) {
    u32 iterations = m_iterations;
    return Unk_15c5520(arg1, new MD5Checksum, arg2, iterations, 0, 0, arg3, 2);
}

}  // namespace nex
}  // namespace nn
