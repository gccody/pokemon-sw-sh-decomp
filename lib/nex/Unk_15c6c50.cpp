// Scope: common
// NEX 4.6.8: EncryptionAlgorithm (RTTI: N2nn3nex19EncryptionAlgorithmE) and
// its RC4 implementation (N2nn3nex13RC4EncryptionE).
#include "Unk_15c64b0.h"

namespace nn {
namespace nex {

// 0x71015c6b50 (D2), 0x71015c6bb0 (D0: a trap, the class is abstract)
EncryptionAlgorithm::~EncryptionAlgorithm() {}

// 0x71015c6df0
bool EncryptionAlgorithm::vf6(u32 error, char* message, size_t size) {
    if (strlen("Encryption Error") < size) {
        strcpy(message, "Encryption Error");
        return true;
    }
    return false;
}

// 0x71015c6e50
RC4Encryption::RC4Encryption()
    : EncryptionAlgorithm(5, 0x40), m_reset(true), m_lock(0x20000000, true) {
    const char* defaultKey = "CD&ML";
    std::vector<u8, MemAllocator<u8>> key(defaultKey, defaultKey + 5);
    if (key.size() >= m_minKeyLength && key.size() <= m_maxKeyLength) {
        m_key.m_data.assign(key.data(), key.data() + key.size());
        vf7();
    }
}

// 0x71015c6f50 (D2), 0x71015c6fd0 (D0)
RC4Encryption::~RC4Encryption() {}

// 0x71015c7050
void RC4Encryption::vf7() {
    for (u32 i = 0; i < 0x100; i++) {
        m_initialState[i] = i;
    }
    m_i = 0;
    m_j = 0;
    const u8* key = m_key.m_data.empty() ? nullptr : &m_key.m_data[0];
    size_t length = m_key.m_data.size();
    u8 k = 0;
    u32 j = 0;
    for (u32 i = 0; i < 0x100; i++) {
        j = (j + key[k] + m_initialState[i]) & 0xff;
        u8 t = m_initialState[i];
        m_initialState[i] = m_initialState[j];
        m_initialState[j] = t;
        k = (k + 1) % length;
    }
    Reset();
}

// 0x71015c70f0
// NON_MATCHING: the original keeps the addresses of m_i and m_j in two more
// callee-saved registers (computed in both branches of the m_reset check, and
// the loads after it duplicated into both); the rest is the same.
u32 RC4Encryption::vf3(Buffer* buffer) {
    u8* data = buffer->m_data + buffer->m_offset;
    size_t size = buffer->m_size;
    Unk_15b78f0_Scope lock(&m_lock);
    if (m_key.m_data.size() != 0) {
        if (m_reset) {
            Reset();
        }
        u8 i = m_i;
        u8 j = m_j;
        for (u32 n = 0; n < size; n++) {
            i++;
            j += m_state[i];
            u8 t = m_state[i];
            m_state[i] = m_state[j];
            m_state[j] = t;
            data[n] ^= m_state[static_cast<u8>(m_state[i] + m_state[j])];
        }
        m_i = i;
        m_j = j;
    }
    return 0;
}

// 0x71015c7210
u32 RC4Encryption::vf2(const Buffer& in, Buffer* out) {
    Unk_15c4e00(out, in);
    vf3(out);
    return 0;
}

// 0x71015c7250
// NON_MATCHING: the original keeps the addresses of m_i and m_j in two more
// callee-saved registers (computed in both branches of the m_reset check, and
// the loads after it duplicated into both); the rest is the same.
u32 RC4Encryption::vf5(Buffer* buffer) {
    u8* data = buffer->m_data + buffer->m_offset;
    size_t size = buffer->m_size;
    Unk_15b78f0_Scope lock(&m_lock);
    if (m_key.m_data.size() != 0) {
        if (m_reset) {
            Reset();
        }
        u8 i = m_i;
        u8 j = m_j;
        for (u32 n = 0; n < size; n++) {
            i++;
            j += m_state[i];
            u8 t = m_state[i];
            m_state[i] = m_state[j];
            m_state[j] = t;
            data[n] ^= m_state[static_cast<u8>(m_state[i] + m_state[j])];
        }
        m_i = i;
        m_j = j;
    }
    return 0;
}

// 0x71015c7370
u32 RC4Encryption::vf4(const Buffer& in, Buffer* out) {
    Unk_15c4e00(out, in);
    vf5(out);
    return 0;
}

// 0x71015c73b0
void RC4Encryption::Unk_15c73b0(bool reset) {
    Unk_15b78f0_Scope lock(&m_lock);
    m_reset = reset;
}

}  // namespace nex
}  // namespace nn
