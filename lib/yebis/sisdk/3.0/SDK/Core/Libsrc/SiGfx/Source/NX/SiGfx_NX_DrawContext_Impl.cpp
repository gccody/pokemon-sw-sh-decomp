// Scope: common
// SiSDK3::SiGfxNXDrawContext: the slots that pass their arguments on to its
// two helpers, its queries' and its command buffer's small functions, and
// the reference counts its header defines. (Its other small accessors are
// lib/yebis/class's; most of its functions aren't written yet.)
#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiGfx/Source/NX/SiGfx_NX_DrawContext_Impl.h>

namespace SiSDK3 {

// 0x710053c9c0
void SiGfxNXDrawContext::vf12() {
    Unk_53c340();
    field_68 = nullptr;
}

// 0x710053c9f0
void SiGfxNXDrawContext::vf14(s32 count, const Unk_Viewport* viewports) {
    if (count < 0 || count > 15) {
        return;
    }
    field_78 = count;
    field_538 = count;
    for (s32 i = 0; i < count; i++) {
        field_544[i].field_0 = viewports[i].field_0;
        field_544[i].field_4 = viewports[i].field_4;
        field_544[i].field_8 = viewports[i].field_8;
        field_544[i].field_c = viewports[i].field_c;
        field_644[i].field_0 = viewports[i].field_10;
        field_644[i].field_4 = viewports[i].field_14;
    }
    field_30 |= 2;
}

// NON_MATCHING: the same instructions with the loop's two pointers in each
// other's registers (the original has the scissors' in x10 and the
// rectangles' in x11).
// 0x710053ca70
void SiGfxNXDrawContext::vf15(s32 count, const Unk_Scissor* scissors) {
    if (count < 0 || count > 15) {
        return;
    }
    field_1fc = count;
    field_53c = count;
    for (s32 i = 0; i < count; i++) {
        field_6c4[i].field_0 = scissors[i].field_0;
        field_6c4[i].field_4 = scissors[i].field_8;
        field_6c4[i].field_8 = scissors[i].field_4 - scissors[i].field_0;
        field_6c4[i].field_c = scissors[i].field_c - scissors[i].field_8;
    }
    field_30 |= 4;
}

// 0x7100540750
void SiGfxNXDrawContext::vf34() {
    Unk_55ba30(&field_30);
}

// 0x7100540630
void SiGfxNXDrawContext::vf35() {
    field_2c70.Unk_5472d0();
}

// 0x7100540640
void SiGfxNXDrawContext::vf36() {
    Unk_5474b0_get(reinterpret_cast<Unk_5474b0*>(&field_2c70));
}

// 0x7100540650
void SiGfxNXDrawContext::vf37() {
    field_2c70.Unk_547760();
}

// 0x7100540660
void SiGfxNXDrawContext::vf38() {
    field_2c70.Unk_547810();
}

// 0x7100540670
void SiGfxNXDrawContext::vf39() {
    field_2c70.Unk_5478f0();
}

// 0x7100540680
void SiGfxNXDrawContext::vf40() {
    field_2c70.Unk_547930();
}

// 0x7100540690
void SiGfxNXDrawContext::vf41() {
    field_2c70.Unk_547a40();
}

// 0x71005406a0
void SiGfxNXDrawContext::vf42() {
    field_2c70.Unk_547b60();
}

// 0x71005406b0
void SiGfxNXDrawContext::vf43() {
    field_2c70.Unk_547ca0();
}

// 0x71005406c0
void SiGfxNXDrawContext::vf44() {
    field_2c70.Unk_547df0();
}

// 0x71005406d0
void SiGfxNXDrawContext::vf45() {
    field_2c70.Unk_547f50();
}

// 0x71005406e0
void SiGfxNXDrawContext::vf46() {
    field_2c70.Unk_5480c0();
}

// 0x71005406f0
void SiGfxNXDrawContext::vf47() {
    field_2c70.Unk_548230();
}

// 0x7100540700
void SiGfxNXDrawContext::vf48() {
    field_2c70.Unk_548380();
}

// 0x7100540710
void SiGfxNXDrawContext::vf49() {
    field_2c70.Unk_5484f0();
}

// NON_MATCHING: the original tests the index type for 0, 1 and 2 in that
// order and gives the other types a block of their own; this tests 0, 2 and
// 1 and shares the other types' block with the null buffer's (268 bytes for
// 292).
// 0x710053d490
void SiGfxNXDrawContext::vf20(Unk_NXDrawIndirect* pBuffer, s32 offset) {
    u64 address = 0;
    s32 type = 0;
    s32 size = 0;
    if (pBuffer != nullptr) {
        address = pBuffer->vf27();
        type = pBuffer->vf28();
        switch (type) {
        case 0:
            size = 1;
            break;
        case 1:
            size = 2;
            break;
        case 2:
            size = 4;
            break;
        default:
            size = 0;
            break;
        }
    }
    address += offset;
    if (field_400 != pBuffer || field_8d0 != type || field_8c8 != address || field_8d4 != size) {
        field_400 = pBuffer;
        field_8d0 = type;
        field_8c8 = address;
        field_8d4 = size;
    }
    field_30 |= 8;
}

// 0x7100540080
bool SiGfxNXDrawContext::vf24(s32 count, s32 first, s32 instances, s32 baseInstance) {
    Unk_53c340();
    if (instances <= 1) {
        nvnCommandBufferDrawArrays(field_3a60, field_8d8, first, count);
    } else {
        nvnCommandBufferDrawArraysInstanced(field_3a60, field_8d8, first, count, baseInstance, instances);
    }
    Unk_NXDrawCommandList* pList = field_28;
    pList->field_128++;
    s32 n = instances > 1 ? instances : 1;
    pList->field_144 += n * count;
    Unk_CountPrimitives(pList, count, n);
    return true;
}

// 0x71005401c0
bool SiGfxNXDrawContext::vf25(s32 count, s32 first, s32 baseVertex, s32 instances, s32 baseInstance) {
    Unk_53c340();
    u64 indexBuffer = static_cast<s64>(field_8d4) * first + field_8c8;
    if (instances <= 1) {
        nvnCommandBufferDrawElementsBaseVertex(field_3a60, field_8d8, field_8d0, count, indexBuffer, baseVertex);
    } else {
        nvnCommandBufferDrawElementsInstanced(field_3a60, field_8d8, field_8d0, count, indexBuffer, baseVertex,
                                              baseInstance, instances);
    }
    Unk_NXDrawCommandList* pList = field_28;
    pList->field_128++;
    s32 n = instances > 1 ? instances : 1;
    pList->field_144 += n * count;
    pList->field_148 += n * count;
    Unk_CountPrimitives(pList, count, n);
    return true;
}

// 0x7100540320
u32 SiGfxNXDrawContext::vf26(Unk_NXDrawIndirect* pBuffer) {
    Unk_53c340();
    nvnCommandBufferBarrier(field_3a60, 8);
    nvnCommandBufferDrawElementsIndirect(field_3a60, field_8d8, field_8d0, field_8c8, pBuffer->vf27());
    return 0;
}

// 0x71005403c0
u32 SiGfxNXDrawContext::vf28(s32 x, s32 y, s32 z) {
    Unk_53c340();
    nvnCommandBufferDispatchCompute(field_3a60, x, y, z);
    field_28->field_134++;
    return 0;
}

// 0x71005405c0
void SiGfxNXDrawContext::vf31(const char* description) {
    if (field_3a60 != nullptr) {
        char buffer[0x100];
        Unk_4c4cf0_update(reinterpret_cast<u64>(description), reinterpret_cast<u64>(buffer), sizeof(buffer));
        nvnCommandBufferInsertDebugMarker(field_3a60, buffer);
    }
}

// 0x7100540760
void SiGfxNXDrawContext::vf50(u32 index) {
    void* font = field_18->vf56(index);
    field_3780.Unk_544010(font);
}

// 0x71005407a0
void SiGfxNXDrawContext::vf51(void* font) {
    field_3780.Unk_544010(font);
}

// 0x71005407b0
void SiGfxNXDrawContext::vf52() {
    Unk_544280_get(reinterpret_cast<const Unk_544280*>(&field_3780));
}

// 0x71005407c0
void SiGfxNXDrawContext::vf53() {
    field_3780.Unk_544290();
}

// 0x71005407d0
void SiGfxNXDrawContext::vf54() {
    field_3780.Unk_544540();
}

// 0x71005407e0
void SiGfxNXDrawContext::vf55() {
    field_3780.Unk_544610();
}

// 0x71005407f0
void SiGfxNXDrawContext::vf56() {
    field_3780.Unk_544b00();
}

// 0x7100540800
void SiGfxNXDrawContext::vf57() {
    field_3780.Unk_545910();
}

// 0x7100540810
void SiGfxNXDrawContext::vf58() {
    field_2c70.Unk_548640();
}

// 0x7100540820
void SiGfxNXDrawContext::vf59() {
    field_2c70.Unk_54cab0();
}

// 0x7100540840
bool SiGfxNXDrawContext::vf61(Unk_NXDrawQuery* query) {
    void* commandBuffer = field_3a60;
    if (query->field_78 == 1) {
        nvnCommandBufferResetCounter(commandBuffer, 1);
    } else {
        nvnCommandBufferResetCounter(commandBuffer, 0);
    }
    return true;
}

// 0x7100540890
bool SiGfxNXDrawContext::vf62(Unk_NXDrawQuery* query) {
    nvnCommandBufferReportCounter(field_3a60, query->field_78 == 1, query->field_b8);
    return true;
}

// 0x71005408e0
bool SiGfxNXDrawContext::vf64(Unk_NXDrawQuery* query) {
    void* result = nvnBufferMap(query->field_88);
    nvnBufferInvalidateMappedRange(query->field_88, 0, query->field_80);
    memcpy(query->field_d8, result, query->field_80);
    return true;
}

// 0x7100541db0
void SiGfxNXDrawContext::vf98(Unk_NXDrawCommandList* pCommandList) {
    if (pCommandList != nullptr) {
        field_28 = pCommandList;
        field_3a60 = pCommandList->vf15();
    } else {
        field_28 = nullptr;
        field_3a60 = nullptr;
    }
}

// 0x7100541e00
void SiGfxNXDrawContext::vf99(const void* pool) {
    nvnCommandBufferSetTexturePool(field_3a60, pool);
}

// 0x7100541e20
void SiGfxNXDrawContext::vf100(const void* pool) {
    nvnCommandBufferSetSamplerPool(field_3a60, pool);
}

// 0x7100541e40
void SiGfxNXDrawContext::vf101() {
    Unk_4fb320_update(reinterpret_cast<const Unk_4fb320*>(field_18), reinterpret_cast<u64>(field_3a60));
}

// 0x7100542260
void SiGfxNXDrawContext::vf83(bool more) {
    if (more) {
        field_3a68++;
    } else if (field_3a68 > 0) {
        field_3a68--;
    }
}

// Where a kind's values are in field_2188 (inline in slot 95: placeholder
// name).
static inline size_t Unk_ValuesIndex(u32 kind) {
    switch (kind) {
    case 2:
        return 1;
    case 3:
        return 2;
    case 4:
        return 4;
    case 5:
        return 3;
    case 6:
        return 5;
    default:
        return 0;
    }
}

// 0x7100542840
void SiGfxNXDrawContext::vf95(u32 kind, s32 index, s32 count, const u32* values) {
    memcpy(&field_2188[Unk_ValuesIndex(kind)][index], values, count * sizeof(u32));
}

}  // namespace SiSDK3
