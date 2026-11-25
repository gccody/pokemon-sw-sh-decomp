#pragma once
// NEX 4.6.8's checksum and encryption algorithms (RTTI: N2nn3nex12PluginObjectE,
// N2nn3nex17ChecksumAlgorithmE, N2nn3nex11MD5ChecksumE,
// N2nn3nex22KeyedChecksumAlgorithmE, N2nn3nex18MD5ChecksumWithKeyE,
// N2nn3nex19EncryptionAlgorithmE, N2nn3nex13RC4EncryptionE) and the Key they
// take (N2nn3nex3KeyE), as lib/nex/Unk_15c64b0.cpp and Unk_15c6c50.cpp use them.
//
// The algorithms' constructors and destructors inline RefCountedObject's and
// Key's (the vtable stores, the reference count's release store), which
// <nn/nex/RefCountedObject.h> and lib/nex/Unk_1630ba0.h declare out of line:
// this header declares the two with inline ones instead, and doesn't include
// those.
#include <atomic>
#include <cstring>

#include <nn/nex/ByteStream.h>
#include <nn/nex/qVector.h>

// The SDK's MD5 (imports of `main`).
namespace nn {
namespace crypto {
namespace detail {
class Md5Impl {
public:
    Md5Impl() : field_58(0) {}
    ~Md5Impl();
    void Initialize();
    void Update(const void* data, size_t size);
    void GetHash(void* hash, size_t size);

    u8 _0[0x50];
    u64 field_50;
    u32 field_58;  // its state, 0 until initialized
};
PKMN_SIZE_ASSERT(Md5Impl, 0x60);
}  // namespace detail

void GenerateSha1Hash(void* hash, size_t hashSize, const void* data, size_t dataSize);
}  // namespace crypto
}  // namespace nn

// The MD5 context the checksums hash with: the SDK's, and the digest once it's
// been taken (the name isn't the executable's).
class Unk_15c64b0_Md5Context {
public:
    Unk_15c64b0_Md5Context() : m_done(false) { m_impl.Initialize(); }

    void Update(const void* data, size_t size) {
        if (!m_done) {
            m_impl.Update(data, size);
        }
    }
    const u8* GetDigest() {
        if (m_done) {
            return m_digest;
        }
        m_impl.GetHash(m_digest, sizeof(m_digest));
        m_done = true;
        return m_digest;
    }

    nn::crypto::detail::Md5Impl m_impl;
    u8 m_digest[0x10];
    bool m_done;
};
PKMN_OFFSET_ASSERT(Unk_15c64b0_Md5Context, m_digest, 0x60);
PKMN_OFFSET_ASSERT(Unk_15c64b0_Md5Context, m_done, 0x70);

// 0x71015c3ee0: writes `size` bytes at `data` into the buffer at `pos` (-1:
// its end).
bool Unk_15c3ee0(u64 buffer, void* data, u32 size, u64 pos);
// 0x71015c4e00: copies another buffer.
void Unk_15c4e00(nn::nex::Buffer* self, const nn::nex::Buffer& other);

// 0x71015b78f0: the lock the RC4 encryption takes (slot 2 enters it, slot 4
// leaves it).
class Unk_15b78f0 {
public:
    Unk_15b78f0(u32 arg, bool recursive);
    // 0x71015b9300
    ~Unk_15b78f0();
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();

    u8 _8[0x40];
};
PKMN_SIZE_ASSERT(Unk_15b78f0, 0x48);

// Holds the lock for its scope (an inline helper; the name isn't the executable's).
class Unk_15b78f0_Scope {
public:
    explicit Unk_15b78f0_Scope(Unk_15b78f0* lock) : m_lock(lock) { m_lock->vf2(); }
    ~Unk_15b78f0_Scope() { m_lock->vf4(); }

    Unk_15b78f0* m_lock;
};

// What a checksum's slot 3 writes: the digest and its length.
struct Unk_15c6560_Digest {
    u8 m_data[0x10];
    size_t m_size;
};
PKMN_OFFSET_ASSERT(Unk_15c6560_Digest, m_size, 0x10);

namespace nn {
namespace nex {

// N2nn3nex16RefCountedObjectE (see the top of the file). Its RTTI's base is
// N2nn3nex10RootObjectE, but RootObject's destructor is trivial here: with
// <nn/nex/RootObject.h>'s inline virtual one, clang replaces this inline
// destructor with RootObject's (an alias), and the derived classes'
// destructors lose its vtable store, which the original's keep (Key's
// 0x71015ce560, EncryptionAlgorithm's 0x71015c6b50). Its operator new and
// delete are RootObject's.
class RefCountedObject {
public:
    static void* operator new(size_t size) noexcept { return Unk_15b6dc0(size); }
    static void operator delete(void* p) { Unk_15b6e10(p); }

    RefCountedObject() {
        m_count = 1;
        m_deleting = false;
    }
    virtual ~RefCountedObject() {}

    // (an anonymous union: the empty destructor still stores the vtable)
    union {
        std::atomic<s32> m_count;
    };
    bool m_deleting;
};
PKMN_OFFSET_ASSERT(RefCountedObject, m_deleting, 0xc);
PKMN_SIZE_ASSERT(RefCountedObject, 0x10);

// N2nn3nex3KeyE
class Key : public RefCountedObject {
public:
    Key() {}
    ~Key() override {}
    Key& operator=(const Key& other) {
        m_data = other.m_data;
        return *this;
    }

    qVector<u8> m_data;
};
PKMN_SIZE_ASSERT(Key, 0x28);

// N2nn3nex12PluginObjectE
class PluginObject : public RootObject {};

// N2nn3nex17ChecksumAlgorithmE
class ChecksumAlgorithm : public PluginObject {
public:
    ChecksumAlgorithm() : field_8(0), field_10(0) {}

    // the checksum of `in`, written to `out`
    virtual bool vf2(const Buffer& in, Buffer* out) = 0;
    // the checksum of `count` blocks
    virtual bool vf3(const void* const* data, const size_t* sizes, size_t count,
                     Unk_15c6560_Digest* out) = 0;
    virtual u32 vf4() = 0;
    // 0x71015d4600: vf6 of one block
    virtual u32 vf5(const void* data, size_t size);
    // a 32-bit checksum of `count` blocks
    virtual u32 vf6(const void* const* data, const size_t* sizes, size_t count) = 0;
    virtual u32 vf7() = 0;

    u64 field_8;
    u8 field_10;
};
PKMN_OFFSET_ASSERT(ChecksumAlgorithm, field_10, 0x10);

// N2nn3nex11MD5ChecksumE
class MD5Checksum : public ChecksumAlgorithm {
public:
    // 0x71015c6480
    MD5Checksum();
    // 0x71015c3ed0
    ~MD5Checksum() override;
    bool vf2(const Buffer& in, Buffer* out) override;
    bool vf3(const void* const* data, const size_t* sizes, size_t count,
             Unk_15c6560_Digest* out) override;
    u32 vf4() override;
    u32 vf6(const void* const* data, const size_t* sizes, size_t count) override;
    u32 vf7() override;
};
PKMN_SIZE_ASSERT(MD5Checksum, 0x18);

// N2nn3nex22KeyedChecksumAlgorithmE
class KeyedChecksumAlgorithm : public ChecksumAlgorithm {
public:
    KeyedChecksumAlgorithm(size_t minKeyLength, size_t maxKeyLength)
        : m_minKeyLength(minKeyLength), m_maxKeyLength(maxKeyLength) {}
    ~KeyedChecksumAlgorithm() override {}
    // 0x71015c63b0: takes the key if its length is in the algorithm's range.
    bool Unk_15c63b0(const Key& key);

    // called when the key changes
    virtual void vf8();

    Key m_key;
    size_t m_minKeyLength;
    size_t m_maxKeyLength;
};
PKMN_OFFSET_ASSERT(KeyedChecksumAlgorithm, m_key, 0x18);
PKMN_SIZE_ASSERT(KeyedChecksumAlgorithm, 0x50);

// N2nn3nex18MD5ChecksumWithKeyE: MD5 of the data and the key after it.
class MD5ChecksumWithKey : public KeyedChecksumAlgorithm {
public:
    MD5ChecksumWithKey();
    ~MD5ChecksumWithKey() override;
    bool vf2(const Buffer& in, Buffer* out) override;
    bool vf3(const void* const* data, const size_t* sizes, size_t count,
             Unk_15c6560_Digest* out) override;
    u32 vf4() override;
    u32 vf6(const void* const* data, const size_t* sizes, size_t count) override;
    u32 vf7() override;
};
PKMN_SIZE_ASSERT(MD5ChecksumWithKey, 0x50);

// N2nn3nex19EncryptionAlgorithmE
class EncryptionAlgorithm : public PluginObject {
public:
    EncryptionAlgorithm(size_t minKeyLength, size_t maxKeyLength)
        : field_8(0), m_minKeyLength(minKeyLength), m_maxKeyLength(maxKeyLength) {}
    // 0x71015c6b50 (D2), 0x71015c6bb0 (D0: a trap, the class is abstract)
    ~EncryptionAlgorithm() override;

    // 0x71015c6bc0: takes the key if its length is in the algorithm's range.
    bool Unk_15c6bc0(const Key& key);

    // encrypts `in` into `out`
    virtual u32 vf2(const Buffer& in, Buffer* out) = 0;
    // encrypts the buffer in place
    virtual u32 vf3(Buffer* buffer);
    // decrypts `in` into `out`
    virtual u32 vf4(const Buffer& in, Buffer* out) = 0;
    // decrypts the buffer in place
    virtual u32 vf5(Buffer* buffer);
    // the error's message
    virtual bool vf6(u32 error, char* message, size_t size);
    // called when the key changes
    virtual void vf7();

    u64 field_8;
    Key m_key;
    size_t m_minKeyLength;
    size_t m_maxKeyLength;
};
PKMN_OFFSET_ASSERT(EncryptionAlgorithm, m_key, 0x10);
PKMN_SIZE_ASSERT(EncryptionAlgorithm, 0x48);

// N2nn3nex13RC4EncryptionE
class RC4Encryption : public EncryptionAlgorithm {
public:
    RC4Encryption();
    ~RC4Encryption() override;
    u32 vf2(const Buffer& in, Buffer* out) override;
    u32 vf3(Buffer* buffer) override;
    u32 vf4(const Buffer& in, Buffer* out) override;
    u32 vf5(Buffer* buffer) override;
    // the key schedule
    void vf7() override;

    // 0x71015c73b0: whether each buffer starts again from the key schedule's state.
    void Unk_15c73b0(bool reset);

    // the state back to the key schedule's
    void Reset() {
        m_i = 0;
        m_j = 0;
        memcpy(m_state, m_initialState, sizeof(m_state));
    }

    // the state (RC4's S) after the key schedule, and the current one, with its indices
    u8 m_initialState[0x100];
    u8 m_state[0x100];
    u8 m_i;
    u8 m_j;
    bool m_reset;
    Unk_15b78f0 m_lock;
};
PKMN_OFFSET_ASSERT(RC4Encryption, m_state, 0x148);
PKMN_OFFSET_ASSERT(RC4Encryption, m_reset, 0x24a);
PKMN_OFFSET_ASSERT(RC4Encryption, m_lock, 0x250);
PKMN_SIZE_ASSERT(RC4Encryption, 0x298);

}  // namespace nex
}  // namespace nn
