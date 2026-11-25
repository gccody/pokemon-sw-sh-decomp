// Scope: common
// mesh::SyncClockProtocol's members (RTTI N2nn3pia4mesh17SyncClockProtocolE, derived
// from transport::Protocol, RTTI N2nn3pia9transport8ProtocolE, whose
// constructor is named Unk_2460778 here). Member names are placeholders
// (vf<slot>, lib/pia/README.md).
#include "pia/common/Unk_16c1b90.h"
#include "pia/common/Unk_165e060.h"

// What the global Unk_27fc2d8 points to (lib/pia/common/Unk_1735510.cpp):
// Unk_174de50_get gives an object whose slot 11 looks a station up by id.
struct Unk_174de50;
extern Unk_174de50* Unk_27fc2d8;

struct Unk_16c1d00_station {
    u8 _0[0x38];
    u8 field_38;  // below 0x20 for a valid one
};
PKMN_OFFSET_ASSERT(Unk_16c1d00_station, field_38, 0x38);

class Unk_16c1d00_lookup {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual Unk_16c1d00_station* vf11(u64 id);
};

// Declared in lib/nx_middleware/leaf with the u64 field it returns.
Unk_16c1d00_lookup* Unk_174de50_get(const Unk_174de50* self);


// transport::Protocol (placeholder name: its constructor's).
class Unk_2460778 {
public:
    Unk_2460778();
    virtual ~Unk_2460778();
    virtual void vf2();
    virtual u32 vf3();
    virtual u32 vf4() = 0;
    virtual nn::pia::Unk_165e060 vf5();
    virtual void vf6();
    virtual nn::pia::Unk_165e060 vf7(u64 id);
    virtual void vf8();
    virtual nn::pia::Unk_165e060 vf9();
    virtual nn::pia::Unk_165e060 vf10();
    virtual u32 vf11();
    virtual u64 vf12();
    virtual void vf13(u64 value);

    void* field_8;
    void* field_10;
    u64 field_18;
    u64 field_20;
    u32 field_28;
    u64 field_30;
    u8 field_38;  // the station index, 0xfd when unset
    u64 field_40;
};
PKMN_OFFSET_ASSERT(Unk_2460778, field_28, 0x28);
PKMN_OFFSET_ASSERT(Unk_2460778, field_38, 0x38);
PKMN_SIZE_ASSERT(Unk_2460778, 0x48);

namespace nn {
namespace pia {
namespace mesh {

class SyncClockProtocol : public Unk_2460778 {
public:
    SyncClockProtocol();
    ~SyncClockProtocol() override;
    void vf2() override;
    u32 vf4() override;
    Unk_165e060 vf7(u64 id) override;
    void vf8() override;
    Unk_165e060 vf9() override;
    Unk_165e060 vf10() override;

    Unk_16c1b90 field_48;
    s32 field_58;  // 2000
    u64 field_60;
    bool field_68;
    bool field_69;
    u32 field_6c;
    u32 field_70;
    u8 _74[0x98 - 0x74];
    u64 field_98;
};
PKMN_OFFSET_ASSERT(SyncClockProtocol, field_48, 0x48);
PKMN_OFFSET_ASSERT(SyncClockProtocol, field_58, 0x58);
PKMN_OFFSET_ASSERT(SyncClockProtocol, field_60, 0x60);
PKMN_OFFSET_ASSERT(SyncClockProtocol, field_68, 0x68);
PKMN_OFFSET_ASSERT(SyncClockProtocol, field_6c, 0x6c);
PKMN_OFFSET_ASSERT(SyncClockProtocol, field_98, 0x98);

// 0x71016c1c30
SyncClockProtocol::SyncClockProtocol()
    : field_58(2000), field_60(0), field_68(false), field_69(false) {
    field_98 = 0;
    field_6c = 0;
    field_70 = 0;
}

// 0x71016c1c80 (and 0x71016c1cc0, deleting)
SyncClockProtocol::~SyncClockProtocol() {}

// 0x71016c1d00
Unk_165e060 SyncClockProtocol::vf7(u64 id) {
    Unk_16c1d00_station* station = Unk_174de50_get(Unk_27fc2d8)->vf11(id);
    if (station == nullptr || station->field_38 >= 0x20) {
        return Unk_165e060Value<0x10c07>();
    }
    if (field_38 != 0xfd) {
        return Unk_165e060Value<0x10c08>();
    }
    return Unk_2460778::vf7(id);
}

// 0x71016c1de0
// NON_MATCHING: the same instructions, but transport::Protocol's vf8 is named as LanProtocol's
// (_ZN2nn3pia3lan11LanProtocol3vf8Ev, which inherits it) until it's renamed.
void SyncClockProtocol::vf8() {
    field_98 = 0;
    field_6c = 0;
    field_70 = 0;
    Unk_2460778::vf8();
}

}  // namespace mesh
}  // namespace pia
}  // namespace nn
