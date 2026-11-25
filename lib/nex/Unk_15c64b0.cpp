// Scope: common
// NEX 4.6.8: MD5Checksum's and MD5ChecksumWithKey's checksums (RTTI:
// N2nn3nex11MD5ChecksumE, N2nn3nex18MD5ChecksumWithKeyE), a SHA-1, and
// EncryptionAlgorithm's destructor and key (N2nn3nex19EncryptionAlgorithmE).
#include "Unk_15c64b0.h"

namespace nn {
namespace nex {

// 0x71015c64b0
bool MD5Checksum::vf2(const Buffer& in, Buffer* out) {
    Unk_15c64b0_Md5Context context;
    context.Update(in.m_data + in.m_offset, in.m_size);
    Unk_15c3ee0(reinterpret_cast<u64>(out), const_cast<u8*>(context.GetDigest()), 0x10, -1);
    return true;
}

// 0x71015c6560
bool MD5Checksum::vf3(const void* const* data, const size_t* sizes, size_t count,
                      Unk_15c6560_Digest* out) {
    Unk_15c64b0_Md5Context context;
    for (size_t i = 0; i < count; i++) {
        if (data[i] != nullptr && sizes[i] != 0) {
            context.Update(data[i], sizes[i]);
        }
    }
    memcpy(out->m_data, context.GetDigest(), 0x10);
    out->m_size = 0x10;
    return true;
}

// 0x71015c6630
u32 MD5Checksum::vf6(const void* const* data, const size_t* sizes, size_t count) {
    Unk_15c64b0_Md5Context context;
    for (size_t i = 0; i < count; i++) {
        if (data[i] != nullptr && sizes[i] != 0) {
            context.Update(data[i], sizes[i]);
        }
    }
    u32 checksum;
    memcpy(&checksum, context.GetDigest(), sizeof(checksum));
    return checksum;
}

// 0x71015c6700
MD5ChecksumWithKey::MD5ChecksumWithKey() : KeyedChecksumAlgorithm(6, 0x40) {}

// 0x71015c4050 (D2, the same code as KeyedChecksumAlgorithm's), 0x71015c6770 (D0)
MD5ChecksumWithKey::~MD5ChecksumWithKey() {}

// 0x71015c67d0
bool MD5ChecksumWithKey::vf3(const void* const* data, const size_t* sizes, size_t count,
                             Unk_15c6560_Digest* out) {
    Unk_15c64b0_Md5Context context;
    size_t keyLength = m_key.m_data.size();
    for (size_t i = 0; i < count; i++) {
        if (data[i] != nullptr && sizes[i] != 0) {
            context.Update(data[i], sizes[i]);
        }
    }
    if (keyLength != 0) {
        context.Update(m_key.m_data.empty() ? nullptr : &m_key.m_data[0], keyLength);
    }
    memcpy(out->m_data, context.GetDigest(), 0x10);
    out->m_size = 0x10;
    return true;
}

// 0x71015c68d0
bool MD5ChecksumWithKey::vf2(const Buffer& in, Buffer* out) {
    Unk_15c64b0_Md5Context context;
    size_t keyLength = m_key.m_data.size();
    if (in.m_size != 0 && in.m_data + in.m_offset != nullptr) {
        context.Update(in.m_data + in.m_offset, in.m_size);
    }
    if (keyLength != 0) {
        context.Update(m_key.m_data.empty() ? nullptr : &m_key.m_data[0], keyLength);
    }
    Unk_15c3ee0(reinterpret_cast<u64>(out), const_cast<u8*>(context.GetDigest()), 0x10, -1);
    return true;
}

// 0x71015c69b0
u32 MD5ChecksumWithKey::vf6(const void* const* data, const size_t* sizes, size_t count) {
    Unk_15c64b0_Md5Context context;
    size_t keyLength = m_key.m_data.size();
    for (size_t i = 0; i < count; i++) {
        if (data[i] != nullptr && sizes[i] != 0) {
            context.Update(data[i], sizes[i]);
        }
    }
    if (keyLength != 0) {
        context.Update(m_key.m_data.empty() ? nullptr : &m_key.m_data[0], keyLength);
    }
    u32 checksum;
    memcpy(&checksum, context.GetDigest(), sizeof(checksum));
    return checksum;
}

}  // namespace nex
}  // namespace nn

// 0x71015c6b40
void Unk_15c6b40(void* hash, size_t hashSize, const void* data, size_t dataSize) {
    nn::crypto::GenerateSha1Hash(hash, hashSize, data, dataSize);
}

namespace nn {
namespace nex {

// 0x71015c6bc0
bool EncryptionAlgorithm::Unk_15c6bc0(const Key& key) {
    size_t length = key.m_data.size();
    if (length < m_minKeyLength) {
        return false;
    }
    if (length > m_maxKeyLength) {
        return false;
    }
    m_key = key;
    vf7();
    return true;
}

}  // namespace nex
}  // namespace nn
