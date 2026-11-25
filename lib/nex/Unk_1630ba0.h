#pragma once
// NEX 4.6.8's Key and the bases of its encryption and checksum algorithms (RTTI:
// N2nn3nex3KeyE, N2nn3nex12PluginObjectE, N2nn3nex17ChecksumAlgorithmE,
// N2nn3nex11MD5ChecksumE), as lib/nex/Unk_1630ba0.cpp and Unk_1631380.cpp use them.
#include <nn/nex/RefCountedObject.h>
#include <nn/nex/qVector.h>

namespace nn {
namespace nex {

// N2nn3nex3KeyE (lib/nex/core/RefCountedObject.cpp)
class Key : public RefCountedObject {
public:
    // 0x71015ce120
    Key();
    // 0x71015ce560
    ~Key() override;
    // 0x71015c5ea0
    Key& operator=(const Key& other);

    qVector<u8> m_data;
};
PKMN_SIZE_ASSERT(Key, 0x28);

// N2nn3nex12PluginObjectE
class PluginObject : public RootObject {};

// N2nn3nex17ChecksumAlgorithmE
class ChecksumAlgorithm : public PluginObject {
public:
    u64 field_8;
    u8 field_10;
};

// N2nn3nex11MD5ChecksumE
class MD5Checksum : public ChecksumAlgorithm {
public:
    // 0x71015c6480
    MD5Checksum();
    // 0x71015c3ed0
    ~MD5Checksum() override;
    // 0x71015c4f10: the key derived from a password, hashed `iterations` times.
    Key Unk_15c4f10(const char* password, u32 iterations);
};
PKMN_SIZE_ASSERT(MD5Checksum, 0x18);

}  // namespace nex
}  // namespace nn
