// Scope: common
// Small virtual functions of a library class (tools/leafgen.py members): placeholder
// member names vf<slot>, placeholder structs. The class's name is its RTTI's.
// RTTI: N2nn3nex23DataStoreProtocolClientE
#include <types.h>

struct Unk_16339e0_58 {
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5(void*);
};

struct Unk_16339e0 {
    u8 _0[0x58];
    Unk_16339e0_58* field_58;
    u8 field_60;
};
PKMN_OFFSET_ASSERT(Unk_16339e0, field_58, 0x58);
PKMN_OFFSET_ASSERT(Unk_16339e0, field_60, 0x60);

struct Unk_1633a10_58 {
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6(void*);
};

struct Unk_1633a10 {
    u8 _0[0x58];
    Unk_1633a10_58* field_58;
    u8 field_60;
};
PKMN_OFFSET_ASSERT(Unk_1633a10, field_58, 0x58);
PKMN_OFFSET_ASSERT(Unk_1633a10, field_60, 0x60);

namespace nn {
namespace nex {
class DataStoreProtocolClient {
public:
    const char* vf2();
    void vf4();
    u32 vf8();
    u32 vf10();
    u32 vf16();
    void vf17();
    void vf18();
    u64 vf19();
    u32 vf20();
};
}  // namespace nex
}  // namespace nn

// 0x71015a9170
void nn::nex::DataStoreProtocolClient::vf17() {
}

// 0x71015a9180
void nn::nex::DataStoreProtocolClient::vf18() {
}

// 0x71015a9190
u64 nn::nex::DataStoreProtocolClient::vf19() {
    return 0;
}

// 0x71015a91a0
u32 nn::nex::DataStoreProtocolClient::vf20() {
    return 1;
}

// 0x71015a9270
const char* nn::nex::DataStoreProtocolClient::vf2() {
    return "ClientProtocol";
}

// 0x71015a9300
void nn::nex::DataStoreProtocolClient::vf4() {
}

// 0x71015a9310
u32 nn::nex::DataStoreProtocolClient::vf16() {
    return 0;
}

// 0x71016339e0
u32 nn::nex::DataStoreProtocolClient::vf8() {
    Unk_16339e0* self = reinterpret_cast<Unk_16339e0*>(this);
    if ((self->field_60 & 1) != 0) {
        self->field_58->vf5(self);
    }
    return 1;
}

// 0x7101633a10
u32 nn::nex::DataStoreProtocolClient::vf10() {
    Unk_1633a10* self = reinterpret_cast<Unk_1633a10*>(this);
    if ((self->field_60 & 1) != 0) {
        self->field_58->vf6(self);
    }
    return 1;
}
