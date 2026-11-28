// Scope: common
// The destructors of two LDN jobs, each derived from its local-network job:
//
// - local::LdnEventCheckBackgroundJob (RTTI N2nn3pia5local26LdnEventCheckBackgroundJobE,
//   vtable 0x7102459708) from local::LocalEventCheckBackgroundJob (RTTI
//   N2nn3pia5local28LocalEventCheckBackgroundJobE, vtable 0x7102459e98);
// - local::LdnForceDisconnectNetworkJob (RTTI N2nn3pia5local28LdnForceDisconnectNetworkJobE,
//   vtable 0x7102459768) from local::LocalForceDisconnectNetworkJob (RTTI
//   N2nn3pia5local30LocalForceDisconnectNetworkJobE, vtable 0x7102459f68).
//
// Their constructors keep the placeholder names after their vtables
// (src/unsorted/ctor/Unk_1685480.cpp). The derived destructors are empty, so
// they only call the base's (lib/pia/common/Unk_1697a00.h declares
// LocalEventCheckBackgroundJob's other members).
#include <types.h>

namespace nn {
namespace pia {
namespace common {

// RTTI N2nn3pia6common15StepSequenceJobE: only its slots, as these classes'
// vtables have them.
class StepSequenceJob {
public:
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

class LocalEventCheckBackgroundJob : public common::StepSequenceJob {
public:
    ~LocalEventCheckBackgroundJob() override;

    void vf5() override;

    u8 _58[0x60 - 0x58];
    void* field_60;  // cleared by the destructor
};
PKMN_OFFSET_ASSERT(LocalEventCheckBackgroundJob, field_60, 0x60);

class LdnEventCheckBackgroundJob : public LocalEventCheckBackgroundJob {
public:
    ~LdnEventCheckBackgroundJob() override;

    void vf5() override;
};

class LocalForceDisconnectNetworkJob : public common::StepSequenceJob {
public:
    ~LocalForceDisconnectNetworkJob() override;

    u8 _58[0x60 - 0x58];
    void* field_60;  // cleared by the destructor
};
PKMN_OFFSET_ASSERT(LocalForceDisconnectNetworkJob, field_60, 0x60);

class LdnForceDisconnectNetworkJob : public LocalForceDisconnectNetworkJob {
public:
    ~LdnForceDisconnectNetworkJob() override;
};

// 0x71016854b0 (D2), 0x71016854c0 (D0)
LdnEventCheckBackgroundJob::~LdnEventCheckBackgroundJob() {}

// 0x71016854f0
void LdnEventCheckBackgroundJob::vf5() {
    LocalEventCheckBackgroundJob::vf5();
}

// 0x7101685530 (D2), 0x7101685540 (D0)
LdnForceDisconnectNetworkJob::~LdnForceDisconnectNetworkJob() {}

}  // namespace local
}  // namespace pia
}  // namespace nn
