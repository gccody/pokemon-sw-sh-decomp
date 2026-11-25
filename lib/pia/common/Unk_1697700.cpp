// Scope: common
// local::LocalEventJob (RTTI N2nn3pia5local13LocalEventJobE), derived from
// common::StepSequenceJob (RTTI N2nn3pia6common15StepSequenceJobE): its
// constructor and destructors, and a buffer setter after LocalMessage's file.
// Member names are placeholders (vf<slot>, lib/pia/README.md). Its vf5 is in
// lib/nx_middleware/class/nn_pia_local_LocalEventJob.cpp.
#include <string.h>

#include <types.h>

// A buffer and the size written to it (placeholder type, after its setter;
// lib/nx_middleware/leaf/Unk_168ab60.cpp).
struct Unk_1697830 {
    void* field_0;
    u32 field_8;
    u16 field_c;
    u32 field_10;
};
PKMN_OFFSET_ASSERT(Unk_1697830, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_1697830, field_c, 0xc);
PKMN_OFFSET_ASSERT(Unk_1697830, field_10, 0x10);

// 0x7101697840
void Unk_1697840(Unk_1697830* self, const void* data, u16 size, u32 arg3) {
    memcpy(self->field_0, data, size);
    self->field_c = size;
    self->field_10 = arg3;
}

// What a LocalEventJob takes its event from (placeholder: only its slots 53 and
// 54 are called, to get the event and give it back).
class Unk_16978e0_arg1 {
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
    virtual void vf32();
    virtual void vf33();
    virtual void vf34();
    virtual void vf35();
    virtual void vf36();
    virtual void vf37();
    virtual void vf38();
    virtual void vf39();
    virtual void vf40();
    virtual void vf41();
    virtual void vf42();
    virtual void vf43();
    virtual void vf44();
    virtual void vf45();
    virtual void vf46();
    virtual void vf47();
    virtual void vf48();
    virtual void vf49();
    virtual void vf50();
    virtual void vf51();
    virtual void vf52();
    virtual void* vf53();
    virtual void vf54(void* event);
};

// A member of LocalEventJob (placeholder type, after its constructor). What
// releases it (0x7101655170, an empty function) has a free function's
// placeholder name, so the destructor calls it by that name.
struct Unk_1655080 {
    Unk_1655080();

    u8 _0[0x30];
};
void Unk_1655170_update(u64 self);

namespace nn {
namespace pia {
namespace common {

class StepSequenceJob {
public:
    StepSequenceJob();
    virtual ~StepSequenceJob();

    virtual void vf2(bool arg);
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();

    u8 _8[0x58 - 0x8];
};
PKMN_SIZE_ASSERT(StepSequenceJob, 0x58);

}  // namespace common

namespace local {

class LocalEventJob : public common::StepSequenceJob {
public:
    explicit LocalEventJob(Unk_16978e0_arg1* source);
    ~LocalEventJob() override;

    void vf5() override;

    Unk_1655080 field_58;
    void* field_88;
    Unk_16978e0_arg1* field_90;
};
PKMN_OFFSET_ASSERT(LocalEventJob, field_58, 0x58);
PKMN_OFFSET_ASSERT(LocalEventJob, field_88, 0x88);
PKMN_OFFSET_ASSERT(LocalEventJob, field_90, 0x90);
PKMN_SIZE_ASSERT(LocalEventJob, 0x98);

// 0x71016978e0
LocalEventJob::LocalEventJob(Unk_16978e0_arg1* source) {
    field_90 = source;
    field_88 = source->vf53();
}

// 0x7101697940 (and 0x71016979a0, deleting)
LocalEventJob::~LocalEventJob() {
    if (field_88 != nullptr) {
        field_90->vf54(field_88);
        field_88 = nullptr;
    }
    field_90 = nullptr;
    Unk_1655170_update(reinterpret_cast<u64>(&field_58));
}

}  // namespace local
}  // namespace pia
}  // namespace nn
