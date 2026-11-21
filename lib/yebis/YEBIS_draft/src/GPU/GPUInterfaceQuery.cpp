// Scope: common
// PPFX::IGPUBaseQuery and IGPUQueryOcclusion
// (C:/workspace/YEBIS_draft/src/GPU/GPUInterfaceQuery.cpp, the __FILE__ of
// its log lines).
#include <yebis/YEBIS_draft/src/GPU/Unk_Statics.h>
#include <yebis/YEBIS_draft/src/GPU/GPUInterfaceDevice.h>
#include <yebis/YEBIS_draft/src/GPU/GPUInterfaceQuery.h>

#define PPFX_FILE "C:/workspace/YEBIS_draft/src/GPU/GPUInterfaceQuery.cpp"
#include <yebis/YEBIS_draft/src/GPU/Unk_Log.h>

// 0x710238cc68: whether a query's result is collected without waiting
extern bool Unk_238cc68;

namespace PPFX {

#define UNK_INVALID_QUERY reinterpret_cast<Unk_SiGfxQuery*>(-1)

// 0x710044a050, 0x710044a0c0 (deleting: the class is abstract)
IGPUBaseQuery::~IGPUBaseQuery() {
    IGPUBaseQuery::vf4();
}

// 0x710044a0d0
s32 IGPUBaseQuery::vf4() {
    if (field_20 != UNK_INVALID_QUERY) {
        if (field_20 != nullptr) {
            field_20->vf3();
            field_20 = nullptr;
        }
        field_20 = UNK_INVALID_QUERY;
    }
    field_10 = nullptr;
    field_18 = -1;
    field_28 = -1;
    return 0;
}

// 0x710044a130
s32 IGPUBaseQuery::CreateDeviceQuery() {
    Unk_SiGfxQuery* query = field_10->field_38->vf66(nullptr, 0, nullptr);
    if (query == nullptr) {
#line 222
        PPFX_ERROR("IGPUBaseQuery::CreateDeviceQuery(): ISiGfxDevice::CreateQuery() failed.\n");
        return -1;
    }
    Unk_SiGfxQueryDesc desc;
    desc.field_0 = field_18;
    desc.field_4 = 0;
    if (!query->vf18(&desc)) {
#line 235
        PPFX_ERROR("IGPUBaseQuery::CreateDeviceQuery(): ISiGfxQuery::Create() failed.\n");
        query->vf3();
        return -1;
    }
    field_20 = query;
    field_28 = 0;
    return 0;
}

// 0x710044a270
s32 IGPUBaseQuery::vf7() {
    if (field_18 != 1) {
        return -3;
    }
    if (field_20 == UNK_INVALID_QUERY) {
        return -4;
    }
    if (field_28 == 0) {
        return 0;
    }
    if (field_28 > 1) {
        return 0;
    }
    return -3;
}

// 0x710044a2f0
s32 IGPUBaseQuery::Begin() {
    s32 result = vf7();
    if (result < 0) {
        return result;
    }
    if (!field_10->field_30->vf61(field_20)) {
#line 476
        PPFX_ERROR("IGPUBaseQuery::Begin(): pSiGfxDrawContext->BeginQuery(GetSiGfxQuery()) failed.\n");
        return -1;
    }
    vf5();
    field_28 = 1;
    return 0;
}

// 0x710044a3b0
s32 IGPUBaseQuery::End() {
    s32 result = vf8();
    if (result < 0) {
        return result;
    }
    if (!field_10->field_30->vf62(field_20)) {
#line 623
        PPFX_ERROR("IGPUBaseQuery::End(): pSiGfxDrawContext->EndQuery(GetSiGfxQuery()) failed.\n");
        return -1;
    }
    vf5();
    field_28 = 2;
    return 0;
}

// 0x710044a470
s32 IGPUBaseQuery::vf11(bool flush) {
    if (field_28 == 1) {
        return -3;
    }
    if (field_28 > 4) {
        return 0;
    }
    bool flushed = false;
    s32 wait = true;
    if (field_28 == 2 && flush) {
        wait = !Unk_238cc68;
        flushed = true;
    }
    if (field_10->field_30->vf64(field_20, wait)) {
        field_28 = 4;
        return 0;
    }
    if (flushed) {
        field_28 = 3;
        return 1;
    }
    field_28 = 2;
    return 1;
}

// 0x710044a540: IGPUQueryOcclusion's deleting destructor

// 0x710044a5b0
s32 IGPUQueryOcclusion::vf4() {
    if (field_28 > 0) {
        if (field_28 == 1) {
            End();
        }
        if (field_28 < 5) {
            vf12(nullptr, true);
        }
    }
    return IGPUBaseQuery::vf4();
}

// 0x710044a660
s32 IGPUQueryOcclusion::UpdateInternalResult(bool flush) {
    s32 wait;
    if (flush) {
        wait = !Unk_238cc68;
    } else {
        wait = true;
    }
    Unk_SiGfxQuery* query = field_20;
    Unk_SiGfxDrawContext* context = field_10->field_30;
    bool collected = context->vf64(query, wait);
    if (!collected) {
#line 1009
        PPFX_ERROR("IGPUQueryOcclusion::UpdateInternalResult(): ISiGfxQuery::CollectQueryData() failed.\n");
        return -1;
    }
    u32* data = context->vf65(query);
    if (data == nullptr) {
#line 1019
        PPFX_ERROR("IGPUQueryOcclusion::UpdateInternalResult(): ISiGfxQuery::GetQueryData() failed.\n");
        return -1;
    }
    field_2c = *data < 0x7fffffff ? *data : 0x7fffffff;
    field_28 = 5;
    return 0;
}

// 0x710044a7b0
s32 IGPUQueryOcclusion::vf12(u32* result, bool flush) {
    if (field_28 < 2) {
        return -3;
    }
    if (field_28 == 5) {
        if (result != nullptr) {
            *result = field_2c;
        }
        return 0;
    }
    s32 state;
    do {
        state = vf11(flush);
    } while (state == 1);
    if (state < 0) {
        return state;
    }
    UpdateInternalResult(false);
    if (result != nullptr) {
        *result = field_2c;
    }
    return 0;
}

// 0x710044a880
IGPUQueryOcclusion* Unk_44a880(IGPUDevice* device) {
#line 1209
    IGPUQueryOcclusion* query = UNK_NEW(IGPUQueryOcclusion)(device);
    query->CreateDeviceQuery();
    query->vf5();
    return query;
}

}  // namespace PPFX

// 0x710044a910: _GLOBAL__sub_I_GPUInterfaceQuery.cpp
