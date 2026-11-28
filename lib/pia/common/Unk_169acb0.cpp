// Scope: common
// Members of three of the local network's classes, after
// local::LdnSessionInfo's small slots:
//
// - two functions of a session's info and its search criteria (no vtable
//   slot, so their classes aren't known: placeholder free functions);
// - local::LocalUpdateSessionSetting's destructors and vf9 (RTTI
//   N2nn3pia5local25LocalUpdateSessionSettingE, vtable 0x710245b548: the
//   placeholder class Unk_245b538 its constructor already has, in
//   src/unsorted/ctor/Unk_168df70.cpp);
// - mesh::ConnectStationJob's constructor and destructors (RTTI
//   N2nn3pia4mesh17ConnectStationJobE, vtable 0x710245b5d8: the placeholder
//   class Unk_245b5c8, as lib/pia/gen/nn_pia_mesh_MeshNetworkFactory.cpp calls
//   it).
//
// Other names are placeholders (lib/pia/README.md).
#include "pia/common/Unk_165e060.h"

// What the global Unk_27fb2a8 points to (placeholder): its field_18's slot 32
// takes a session's field_9 and a value.
class Unk_169acc0_target {
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
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
    virtual void vf14();
    virtual void vf15();
    virtual void vf16();
    virtual void vf17();
    virtual void vf18();
    virtual void vf19();
    virtual void vf20();
    virtual void vf21();
    virtual void vf22();
    virtual void vf23();
    virtual void vf24();
    virtual void vf25();
    virtual void vf26();
    virtual void vf27();
    virtual void vf28();
    virtual void vf29();
    virtual void vf30();
    virtual void vf31();
    virtual nn::pia::Unk_165e060 vf32(const u8* data, u32 value);
};

struct Unk_169acc0_owner {
    u8 _0[0x18];
    Unk_169acc0_target* field_18;
};
PKMN_OFFSET_ASSERT(Unk_169acc0_owner, field_18, 0x18);

extern Unk_169acc0_owner* Unk_27fb2a8;

struct Unk_169acc0 {
    u8 _0[0x9];
    u8 field_9;
};
PKMN_OFFSET_ASSERT(Unk_169acc0, field_9, 0x9);

// 0x710169acc0
void Unk_169acc0_call(Unk_169acc0* self, u32 value) {
    Unk_169acc0_owner* owner = Unk_27fb2a8;
    if (owner != nullptr && owner->field_18 != nullptr) {
        owner->field_18->vf32(&self->field_9, value);
    }
}

// A session's info as the criteria see it (placeholder: slots 0 to 2).
class Unk_169ad60_arg1 {
public:
    virtual u16 vf0();
    virtual u16 vf1();
    virtual bool vf2();
};

// Search criteria (placeholder): a range for the info's vf1 (0xffff: any), and
// two flags.
struct Unk_169ad60 {
    u8 _0[0x14];
    u16 field_14;  // the most
    u16 field_16;  // the least
    bool field_18;
    bool field_19;
};
PKMN_OFFSET_ASSERT(Unk_169ad60, field_14, 0x14);
PKMN_OFFSET_ASSERT(Unk_169ad60, field_16, 0x16);
PKMN_OFFSET_ASSERT(Unk_169ad60, field_18, 0x18);
PKMN_OFFSET_ASSERT(Unk_169ad60, field_19, 0x19);

// 0x710169ad60
bool Unk_169ad60_check(const Unk_169ad60* self, Unk_169ad60_arg1* info) {
    if (info == nullptr) {
        return false;
    }
    if (self->field_16 != 0xffff && self->field_14 != 0xffff) {
        if (self->field_16 > info->vf1()) {
            return false;
        }
        if (self->field_14 < info->vf1()) {
            return false;
        }
    }
    if (self->field_18 && !info->vf2()) {
        return false;
    }
    if (self->field_19) {
        return info->vf0() != info->vf1();
    }
    return true;
}

namespace nn {
namespace pia {
namespace session {

// session::UpdateSessionSetting (placeholder Unk_245ffb8 for its constructor):
// abstract, its destructor is inline (and empty).
class UpdateSessionSetting {
public:
    virtual ~UpdateSessionSetting() {}

    virtual void vf2() = 0;
    virtual void vf3() = 0;
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();

    u8 _8[0x4];
};
PKMN_SIZE_ASSERT(UpdateSessionSetting, 0x10);

}  // namespace session

namespace common {

// common::StepSequenceJob (lib/pia/common/Unk_169a7e0.h has its members).
class StepSequenceJob {
public:
    StepSequenceJob();
    virtual ~StepSequenceJob();

    u8 _8[0x58 - 0x8];
};
PKMN_SIZE_ASSERT(StepSequenceJob, 0x58);

}  // namespace common
}  // namespace pia
}  // namespace nn

// local::LocalUpdateSessionSetting: abstract (slots 2, 3, 10 and 11 are pure),
// so its deleting destructor is a trap.
class Unk_245b538 : public nn::pia::session::UpdateSessionSetting {
public:
    Unk_245b538();
    ~Unk_245b538() override;

    void vf9() override;

    u32 field_c;
};
PKMN_OFFSET_ASSERT(Unk_245b538, field_c, 0xc);
PKMN_SIZE_ASSERT(Unk_245b538, 0x10);

// 0x710169aed0 (and 0x710169aee0, deleting: a trap, the class is abstract)
Unk_245b538::~Unk_245b538() {}

// 0x710169aef0
void Unk_245b538::vf9() {
    UpdateSessionSetting::vf9();
    field_c = 0;
}

// mesh::ConnectStationJob.
class Unk_245b5c8 : public nn::pia::common::StepSequenceJob {
public:
    Unk_245b5c8();
    ~Unk_245b5c8() override;

    void* field_58;
    u32 field_60;  // 10000
    u32 field_64;
    void* field_68;
    void* field_70;
    u8 field_78;
    u8 field_79;
    u32 field_7c;
};
PKMN_OFFSET_ASSERT(Unk_245b5c8, field_58, 0x58);
PKMN_OFFSET_ASSERT(Unk_245b5c8, field_60, 0x60);
PKMN_OFFSET_ASSERT(Unk_245b5c8, field_68, 0x68);
PKMN_OFFSET_ASSERT(Unk_245b5c8, field_70, 0x70);
PKMN_OFFSET_ASSERT(Unk_245b5c8, field_79, 0x79);
PKMN_OFFSET_ASSERT(Unk_245b5c8, field_7c, 0x7c);
PKMN_SIZE_ASSERT(Unk_245b5c8, 0x80);

// 0x710169af30
Unk_245b5c8::Unk_245b5c8()
    : field_58(nullptr), field_60(10000), field_64(0), field_68(nullptr), field_70(nullptr), field_7c(0) {
    field_79 = 0;
}

// 0x710169af80 (and 0x710169af90, deleting)
Unk_245b5c8::~Unk_245b5c8() {}
