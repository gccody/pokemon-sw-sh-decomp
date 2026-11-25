// Scope: common
// Two sets of timing statistics (count, total, maximum, minimum and the 8
// largest samples, each with its index), and common::MonitoringDataSendJob
// (lib/pia/common/Unk_1654a80.h).
#include "pia/common/Unk_1654a80.h"

using nn::pia::Unk_165e060;
using nn::pia::Unk_165e060Value;

// One of the largest samples: which one it was and its value.
struct Unk_2456c88_entry {
    u32 m_Index;
    u64 m_Value;
};
PKMN_SIZE_ASSERT(Unk_2456c88_entry, 0x10);

// Timing statistics (placeholder type, after the first of its two globals).
struct Unk_2456c88_type {
    u32 m_Count;
    u64 m_Total;
    u64 m_Max;
    u64 m_Min;
    Unk_2456c88_entry m_Largest[8];
};
PKMN_OFFSET_ASSERT(Unk_2456c88_type, m_Total, 0x8);
PKMN_OFFSET_ASSERT(Unk_2456c88_type, m_Max, 0x10);
PKMN_OFFSET_ASSERT(Unk_2456c88_type, m_Min, 0x18);
PKMN_OFFSET_ASSERT(Unk_2456c88_type, m_Largest, 0x20);
PKMN_SIZE_ASSERT(Unk_2456c88_type, 0xa0);

extern Unk_2456c88_type Unk_2456c88 __attribute__((visibility("hidden")));
extern Unk_2456c88_type Unk_2456d28 __attribute__((visibility("hidden")));

const s64& Unk_165c630();  // the unit samples are divided by (computed once)

// 0x7101654a80
void Unk_1654a80(const s64* time) {
    Unk_2456c88_type& stats = Unk_2456c88;
    u64 value = *time / Unk_165c630();
    stats.m_Total += value;
    if (stats.m_Min > value) {
        stats.m_Min = value;
    }
    if (stats.m_Max < value) {
        stats.m_Max = value;
    }
    u32 index = stats.m_Count++;
    for (s32 i = 0; i < 8; i++) {
        if (stats.m_Largest[i].m_Value < value) {
            for (s32 j = 7; j > i; j--) {
                stats.m_Largest[j].m_Index = stats.m_Largest[j - 1].m_Index;
                stats.m_Largest[j].m_Value = stats.m_Largest[j - 1].m_Value;
            }
            stats.m_Largest[i].m_Index = index;
            stats.m_Largest[i].m_Value = value;
            return;
        }
    }
}

// 0x7101654cb0
u64 Unk_1654cb0() {
    if (Unk_2456c88.m_Count == 0) {
        return 0;
    }
    return Unk_2456c88.m_Total / Unk_2456c88.m_Count;
}

// 0x7101654cf0
void Unk_1654cf0() {
    Unk_2456c88_type& stats = Unk_2456d28;
    stats.m_Count = 0;
    stats.m_Total = 0;
    stats.m_Max = 0;
    stats.m_Min = ~0ul;
    for (s32 i = 0; i < 8; i++) {
        stats.m_Largest[i].m_Index = ~0u;
        stats.m_Largest[i].m_Value = 0;
    }
}

// 0x7101654d50
u64 Unk_1654d50() {
    if (Unk_2456d28.m_Count == 0) {
        return 0;
    }
    return Unk_2456d28.m_Total / Unk_2456d28.m_Count;
}

namespace nn {
namespace pia {
namespace common {

// 0x7101654d90
MonitoringDataSendJob::MonitoringDataSendJob() {
    m_Context.Unk_1655110();
}

// 0x7101654dd0 (and 0x7101654e10, deleting)
MonitoringDataSendJob::~MonitoringDataSendJob() {
    Unk_1655170_update(reinterpret_cast<u64>(&m_Context));
}

// 0x7101654e50
Unk_165e060 MonitoringDataSendJob::Unk_1654e50(Unk_1654e50_arg1* data) {
    if (data == nullptr) {
        return Unk_165e060Value<0x10c07>();
    }
    if (m_Context.m_State == 1) {
        return Unk_165e060Value<0x10c08>();
    }
    m_Data = data;
    StepSequenceJob::vf2(true);
    SetStep(&MonitoringDataSendJob::StepSendReport, "MonitoringDataSendJob::StepSendReport");
    Unk_1655190_update(reinterpret_cast<Unk_1655190*>(&m_Context));
    return Unk_165e060Value<0>();
}

// 0x7101654f20
Unk_165bb20_result MonitoringDataSendJob::StepSendReport() {
    if (Unk_1654860(m_Data)) {
        return {5};
    }
    if (!Unk_1654290_get(reinterpret_cast<const Unk_1654290*>(m_Data))->Unk_1652f60()) {
        m_Context.Unk_1655220(Unk_165e060Value<0x6436>());
        return {1};
    }
    if (Unk_1654870_get(reinterpret_cast<const Unk_1654870*>(m_Data))) {
        return {5};
    }
    Unk_1654720(m_Data);
    m_Context.Unk_16551b0(Unk_165e060Value<0>());
    return {1};
}

// 0x7101655030
void MonitoringDataSendJob::Unk_1655030() {
    if (m_Context.m_State == 1) {
        Unk_1655290(&m_Context);
    }
    m_Context.Unk_1655110();
    m_Data = nullptr;
}

}  // namespace common
}  // namespace pia
}  // namespace nn
