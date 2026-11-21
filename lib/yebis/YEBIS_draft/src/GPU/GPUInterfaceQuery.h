// PPFX::IGPUBaseQuery and IGPUQueryOcclusion (RTTI names the classes, their
// log lines CreateDeviceQuery, Begin, End and UpdateInternalResult; the other
// members are placeholders).
#pragma once

#include <yebis/YEBIS_draft/src/GPU/GPUInterface.h>
#include <yebis/YEBIS_draft/src/GPU/Unk_SiGfx.h>

namespace PPFX {

class IGPUDevice;

class IGPUBaseQuery : public IGPUInterface {
public:
    IGPUBaseQuery(IGPUDevice* device)
        : field_10(device), field_18(-1), field_20(reinterpret_cast<Unk_SiGfxQuery*>(-1)), field_28(-1) {}
    virtual ~IGPUBaseQuery();  // 0x710044a050
    virtual s32 vf4();         // 0x710044a0d0: releases the device's query
    virtual void vf5() = 0;    // forgets the result
    virtual s32 UpdateInternalResult(bool flush) = 0;
    virtual s32 vf7();             // 0x710044a270: whether Begin may be called
    virtual u32 vf8();             // 0x710044a2c0: whether End may be called
    virtual s32 Begin();           // 0x710044a2f0
    virtual s32 End();             // 0x710044a3b0
    virtual s32 vf11(bool flush);  // 0x710044a470: asks for the result

    s32 CreateDeviceQuery();  // 0x710044a130

    IGPUDevice* field_10;
    s32 field_18;              // the kind of query: 1 is occlusion
    Unk_SiGfxQuery* field_20;  // -1 without one
    s32 field_28;              // 0 created, 1 begun, 2 ended, 3 flushed, 4 collected, 5 read
};
PKMN_OFFSET_ASSERT(IGPUBaseQuery, field_28, 0x28);

class IGPUQueryOcclusion : public IGPUBaseQuery {
public:
    IGPUQueryOcclusion(IGPUDevice* device) : IGPUBaseQuery(device) { field_18 = 1; }
    s32 vf4() override;                             // 0x710044a5b0
    void vf5() override;                            // 0x710044a650
    s32 UpdateInternalResult(bool flush) override;  // 0x710044a660
    virtual s32 vf12(u32* result, bool flush);      // 0x710044a7b0

    s32 field_2c;  // the samples that passed
};
PKMN_SIZE_ASSERT(IGPUQueryOcclusion, 0x30);

// 0x710044a880
IGPUQueryOcclusion* Unk_44a880(IGPUDevice* device);

}  // namespace PPFX
