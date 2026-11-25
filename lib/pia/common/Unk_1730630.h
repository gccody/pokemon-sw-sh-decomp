#pragma once
// Pia's session jobs at 0x7101730630-0x71017315b0, all derived from
// common::StepSequenceJob (lib/pia/common/Unk_1654a80.h), with their RTTI
// names: session::OpenParticipationJob (vtable 0x710245f8f8),
// CloseParticipationJob (0x710245f958), CommunityManagementJob (0x710245f9b8),
// ClearMatchmakeSystemPasswordJob (0x710245fa48) and
// GenerateMatchmakeSystemPasswordJob (0x710245fab8). The last three are
// abstract (pure slots), so their deleting destructors are traps. Their vf5
// (empty) is in lib/nx_middleware/class. CloseParticipationJob's steps are
// named by the strings stored with them; other names are placeholders
// (lib/pia/README.md).
#include "pia/common/Unk_1654a80.h"

// The system tick (lib/nx_middleware/leaf/Unk_16598a0.cpp) and the ticks in a
// millisecond.
struct Unk_165c600 {
    u64 field_0;
};
PKMN_SIZE_ASSERT(Unk_165c600, 0x8);
void Unk_165c600_call(Unk_165c600* self);  // reads the tick
const s64* Unk_165c6b0();

namespace nn {
namespace pia {
namespace common {

// The peers' list (lib/pia/common/Unk_1734ed0.h has its other members).
class Unk_1734ed0 {
public:
    Unk_165e060 Unk_1734fd0(u64 id);
    bool Unk_1735640(u64 id) const;
};

// The mesh's stations (lib/pia/common/Unk_16c1200.h has the rest).
class Unk_16c1200 {
public:
    Unk_165e060 Unk_16c17e0(u64 field_0);
};

}  // namespace common
}  // namespace pia
}  // namespace nn

struct Unk_16c16d0_arg0 : nn::pia::common::Unk_16c1200 {};
struct Unk_16a8390;
extern Unk_16a8390* Unk_27fb2d8;
Unk_16c16d0_arg0* Unk_16a8390_get(const Unk_16a8390* self);

// The object behind the global Unk_27fc0a8 (placeholder; lib/pia/common/
// Unk_168f910.h and Unk_1734ed0.h have other fields of it).
struct Unk_27fc0a8_type {
    // What it holds at 0x8 (placeholder).
    class Unk_8 {
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
        virtual bool vf20(u32 id);
    };

    u8 _0[0x8];
    Unk_8* field_8;
    u8 _10[0xa0 - 0x10];
    void (*field_a0)(u32 kind, u64 id, void* arg);  // told about a peer leaving
    void* field_a8;
    u8 _b0[0xb8 - 0xb0];
    nn::pia::common::Unk_1734ed0* field_b8;
    u8 _c0[0x162 - 0xc0];
    u8 field_162;  // the current network's index (0 or 1)
    u8 _163[0x180 - 0x163];
    u32 field_180[3];
};
PKMN_OFFSET_ASSERT(Unk_27fc0a8_type, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_27fc0a8_type, field_a0, 0xa0);
PKMN_OFFSET_ASSERT(Unk_27fc0a8_type, field_a8, 0xa8);
PKMN_OFFSET_ASSERT(Unk_27fc0a8_type, field_b8, 0xb8);
PKMN_OFFSET_ASSERT(Unk_27fc0a8_type, field_162, 0x162);
PKMN_OFFSET_ASSERT(Unk_27fc0a8_type, field_180, 0x180);

extern Unk_27fc0a8_type* Unk_27fc0a8;

u32 Unk_172be20(void* self);  // its state (0, or 3 to 8)
void Unk_172c4a0(Unk_27fc0a8_type* self, u64 id);
void Unk_172e0d0(Unk_27fc0a8_type* self, u32 value);  // the current network's
void Unk_172e0e0(Unk_27fc0a8_type* self, u32 value);  // the other network's

// What CloseParticipationJob closes through (placeholder, after the function
// that takes it).
class Unk_1730910_arg3 {
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
    virtual nn::pia::Unk_165e060 vf18(Unk_1655080* context, u32 id);  // starts closing
    virtual bool vf19();                                               // done closing
    virtual void vf20();
    virtual void vf21();
    virtual void vf22();
    virtual void vf23();
    virtual void vf24();
    virtual void vf25();
    virtual void vf26();
    virtual void vf27();
    virtual bool vf28();  // whether it can close
};

nn::pia::Unk_165e060 Unk_1730630(void* self, u64 id);

namespace nn {
namespace pia {
namespace session {

class OpenParticipationJob : public common::StepSequenceJob {
public:
    OpenParticipationJob();
    ~OpenParticipationJob() override;

    void vf5() override;

    void Unk_17307e0();  // cancels and resets

    Unk_1655080* field_58;  // what started it
    Unk_1655080 m_Context;
    u32 field_90;
    void* field_98;
};
PKMN_OFFSET_ASSERT(OpenParticipationJob, field_58, 0x58);
PKMN_OFFSET_ASSERT(OpenParticipationJob, m_Context, 0x60);
PKMN_OFFSET_ASSERT(OpenParticipationJob, field_90, 0x90);
PKMN_OFFSET_ASSERT(OpenParticipationJob, field_98, 0x98);
PKMN_SIZE_ASSERT(OpenParticipationJob, 0xa0);

class CloseParticipationJob : public common::StepSequenceJob {
public:
    CloseParticipationJob();
    ~CloseParticipationJob() override;

    void vf5() override;

    Unk_165e060 Unk_1730910(Unk_1655080* caller, u32 id, Unk_1730910_arg3* target);  // starts it
    common::Unk_165bb20_result CloseParticipation();
    common::Unk_165bb20_result WaitCloseParticipation();
    common::Unk_165bb20_result WaitP2pStable();

    Unk_1655080* field_58;  // what started it
    Unk_1655080 m_Context;
    u32 field_90;
    Unk_1730910_arg3* field_98;
    Unk_165c600 field_a0;  // when closing ended
};
PKMN_OFFSET_ASSERT(CloseParticipationJob, field_58, 0x58);
PKMN_OFFSET_ASSERT(CloseParticipationJob, m_Context, 0x60);
PKMN_OFFSET_ASSERT(CloseParticipationJob, field_90, 0x90);
PKMN_OFFSET_ASSERT(CloseParticipationJob, field_98, 0x98);
PKMN_OFFSET_ASSERT(CloseParticipationJob, field_a0, 0xa0);
PKMN_SIZE_ASSERT(CloseParticipationJob, 0xa8);

class CommunityManagementJob : public common::StepSequenceJob {
public:
    CommunityManagementJob();
    ~CommunityManagementJob() override;

    void vf5() override;
    virtual void vf6();  // cancels and resets
    virtual void vf7() = 0;
    virtual void vf8() = 0;
    virtual void vf9() = 0;
    virtual void vf10() = 0;
    virtual void vf11() = 0;
    virtual void vf12() = 0;

    Unk_1655080* field_58;  // what started it
    Unk_1655080 m_Context;
};
PKMN_OFFSET_ASSERT(CommunityManagementJob, field_58, 0x58);
PKMN_OFFSET_ASSERT(CommunityManagementJob, m_Context, 0x60);
PKMN_SIZE_ASSERT(CommunityManagementJob, 0x90);

class ClearMatchmakeSystemPasswordJob : public common::StepSequenceJob {
public:
    ClearMatchmakeSystemPasswordJob();
    ~ClearMatchmakeSystemPasswordJob() override;

    void vf5() override;
    virtual void vf6();  // cancels and resets
    virtual void vf7() = 0;

    common::Unk_165bb20_result Unk_1731350();  // a step: reports success

    u32 field_58;
    Unk_1655080* field_60;  // what started it
    Unk_1655080 m_Context;
};
PKMN_OFFSET_ASSERT(ClearMatchmakeSystemPasswordJob, field_58, 0x58);
PKMN_OFFSET_ASSERT(ClearMatchmakeSystemPasswordJob, field_60, 0x60);
PKMN_OFFSET_ASSERT(ClearMatchmakeSystemPasswordJob, m_Context, 0x68);
PKMN_SIZE_ASSERT(ClearMatchmakeSystemPasswordJob, 0x98);

class GenerateMatchmakeSystemPasswordJob : public common::StepSequenceJob {
public:
    GenerateMatchmakeSystemPasswordJob();
    ~GenerateMatchmakeSystemPasswordJob() override;

    void vf5() override;
    virtual void vf6();  // cancels and resets
    virtual void vf7() = 0;

    u32 field_58;
    Unk_1655080* field_60;  // what started it
    Unk_1655080 m_Context;
};
PKMN_OFFSET_ASSERT(GenerateMatchmakeSystemPasswordJob, field_58, 0x58);
PKMN_OFFSET_ASSERT(GenerateMatchmakeSystemPasswordJob, field_60, 0x60);
PKMN_OFFSET_ASSERT(GenerateMatchmakeSystemPasswordJob, m_Context, 0x68);
PKMN_SIZE_ASSERT(GenerateMatchmakeSystemPasswordJob, 0x98);

}  // namespace session
}  // namespace pia
}  // namespace nn
