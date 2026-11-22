// Scope: common
// PPFX::IGPUDevice (GPUInterfaceDevice.cpp is the file its log lines name):
// YEBIS's device on SiSDK3's SiGfx. The functions that only return a
// constant are lib/yebis/class's.
#include <yebis/YEBIS_draft/src/GPU/GPUInterfaceDevice.h>

#include <string.h>

#define PPFX_FILE "C:/workspace/YEBIS_draft/src/GPU/GPUInterfaceDevice.cpp"
#include <yebis/YEBIS_draft/src/GPU/Unk_Log.h>

// A warning that is printed the first time and then every hundredth time
// from the 25th on (placeholder name).
#define UNK_PPFX_WARNING_SOMETIMES(...)              \
    do {                                             \
        static s32 unk_count = 0;                    \
        if (unk_count == 0 || unk_count % 100 == 25) { \
            PPFX_WARNING(__VA_ARGS__);               \
        }                                            \
        unk_count++;                                 \
    } while (0)

// 0x710238c3f8: whether the device remembers the states it has applied
extern bool Unk_238c3f8;

// 0x71004486a0 (leafgen's name and types): a new volume texture, which this
// build doesn't make
u64 Unk_4486a0_get(u64 device, u32 width, u32 height, u32 depth, u32 arg4, u32 format, u32 usage, u32 flags);

// 0x7100445af0 (leafgen's name and types): a new surface of a device surface
// there is
void* Unk_445af0_call(void* device, void* deviceSurface, u32 width, u32 height, u32 format, u32 msaa, u32 quality);

// 0x7100446b10 (leafgen's name and type)
bool Unk_446b10_get(u32 format);

namespace PPFX {

// 0x71024e1500: the settings the device is made with
extern Unk_DeviceSettings Unk_24e1500;

// 0x7100446c40, 0x7100446d60: the names of a usage and of an index format
// (the last argument is a buffer to copy the name to)
const char* Unk_446c40(u32 usage, bool shortNames, char* buffer);
const char* Unk_446d60(s32 format, char* buffer);
// 0x710044a880: a new occlusion query, 0x7100449450: a new vertex buffer,
// 0x7100449600: a new index buffer
IGPUQueryOcclusion* Unk_44a880(IGPUDevice* device);
IGPUBuffer* Unk_449450(IGPUDevice* device, u32 count, u32 stride, u32 usage, u32 flags, void* arg5);
IGPUBuffer* Unk_449600(IGPUDevice* device, u32 count, u32 stride, s32 format, u32 usage, u32 flags, void* arg6);

// 0x7100446b20: a texture format's name, 0x7100446e40: a multisample type's
// sample count
const char* Unk_446b20(s32 format, char* buffer);
u32 Unk_446e40(s32 msaa);
// 0x7100447da0: a new texture
IGPUInterface* Unk_447da0(IGPUDevice* device, u32 width, u32 height, u32 arg3, s32 format, s32 msaa, u32 arg6,
                          u32 usage, u32 flags);

// 0x71004481c0, 0x71004486b0: a texture and a volume texture of a device
// texture there is
IGPUInterface* Unk_4481c0(IGPUDevice* device, void* deviceTexture, u32 width, u32 height, u32 arg4, s32 format,
                          u32 usage);
IGPUInterface* Unk_4486b0(IGPUDevice* device, void* deviceTexture, u32 width, u32 height, u32 depth, u32 arg5,
                          s32 format, u32 usage);

// 0x7100445740: a new surface of a kind (1 a render target, 2 a depth
// target, 4 one with unordered access)
IGPUInterface* Unk_445740(IGPUDevice* device, u32 width, u32 height, s32 format, s32 kind, s32 msaa, u32 quality,
                          u32 flags, void* arg8, u32 arg9);

// 0x7100447010
void Unk_447010(s32 arg0, s32 arg1);

// 0x7100449cc0: a new input attribute
IGPUInterface* Unk_449cc0(IGPUDevice* device, const Unk_InputElement* elements, s32 count, void* arg3, s32 arg4);

// 0x710043e2b0, 0x710043f080, 0x710043f200: parts of the device's set-up
s32 Unk_43e2b0(IGPUDevice* self);
s32 Unk_43f080(IGPUDevice* self);
// 0x710043e410
s32 Unk_43e410(IGPUDevice* self);

// 0x71024e14f8: the device there is
extern IGPUDevice* Unk_24e14f8;

// 0x710043e170
IGPUDevice::~IGPUDevice() {
    Unk_43e2b0(this);
    Unk_43e410(this);
    if (field_30 != nullptr) {
        field_30->vf3();
        field_30 = nullptr;
    }
    field_40.clear();
    Unk_24e14f8 = nullptr;
    u32 allocated = field_15000;
    if (allocated != 0) {
#line 866
        PPFX_LOG("IGPUDevice::~IGPUDevice(): uiGPUAllocatedMemorySizeInBytes: %d\n", allocated);
    }
}

// 0x710043e2b0: releases the targets and the index buffer
s32 Unk_43e2b0(IGPUDevice* self) {
    for (s32 i = 0; i < 8; i++) {
        PPFX_SAFE_RELEASE_INTERFACE(self->field_14f00[i]);
    }
    PPFX_SAFE_RELEASE_INTERFACE(self->field_14f40);
    PPFX_SAFE_RELEASE_INTERFACE(self->field_14fc8);
    PPFX_SAFE_RELEASE_INTERFACE(self->field_14ff0);
    PPFX_SAFE_RELEASE_INTERFACE(self->field_14ff8);
    return 0;
}

s32 Unk_43f200(IGPUDevice* self);

// 0x710043e410: releases the pipeline states and the SiGfx objects
s32 Unk_43e410(IGPUDevice* self) {
    Unk_43f080(self);
    for (s32 i = 0; i < 16; i++) {
        if (self->field_14c88[i] != nullptr) {
            self->field_14c88[i]->vf3();
            self->field_14c88[i] = nullptr;
        }
    }
    return 0;
}

// 0x710043f080: releases the pipeline states
s32 Unk_43f080(IGPUDevice* self) {
    for (IGPUDevice::Unk_PipelineStateMap::iterator it = self->field_60.begin(); it != self->field_60.end(); ++it) {
        IGPUDevice::Unk_PipelineStates* states = it->second;
        for (IGPUDevice::PipelineStateData* p = states->field_30; p != states->field_38; p++) {
            if (p->field_120 != nullptr) {
                p->field_120->vf3();
                p->field_120 = nullptr;
            }
        }
#line 1363
        SI_DELETE(states->m_pAllocator, states);
    }
    self->field_60.clear();
    return 0;
}

// 0x71004400a0
s32 IGPUDevice::vf4(IGPUDevice* other) {
    if (other != nullptr && this != other) {
        return -1;
    }
    return 0;
}

// 0x71004400d0
s32 IGPUDevice::vf6(const Unk_DeviceSettings* settings) {
    if (settings != nullptr) {
        Unk_24e1500 = *settings;
    }
    Unk_43e2b0(this);
    Unk_43f080(this);
    s32 result = Unk_43f200(this);
    return result < 0 ? result : 0;
}

// 0x7100440130
s32 IGPUDevice::vf7(u32 index, void* target, s32 arg3) {
    Unk_PixelContainer* pTarget = static_cast<Unk_PixelContainer*>(target);
    PPFX_SAFE_RELEASE_INTERFACE(field_14f00[index]);
    if (pTarget != nullptr) {
        field_14d08 = true;
        field_14f00[index] = pTarget;
        pTarget->vf0();
        field_14d10.field_0 = 0.0f;
        field_14d10.field_4 = 0.0f;
        field_14d10.field_8 = static_cast<f32>(pTarget->field_4c);
        field_14d10.field_c = static_cast<f32>(pTarget->field_50);
        field_14d10.field_10 = 0.0f;
        field_14d10.field_14 = 1.0f;
        field_14d28 = 0;
        field_14d2c = pTarget->field_4c;
        field_14d30 = 0;
        field_14d34 = pTarget->field_50;
    }
    return 0;
}

// 0x7100440230
s32 IGPUDevice::vf8(void* target) {
    IGPUInterface* pTarget = static_cast<IGPUInterface*>(target);
    if (field_14f40 != pTarget) {
        PPFX_SAFE_RELEASE_INTERFACE(field_14f40);
        if (pTarget != nullptr) {
            field_14d08 = true;
            field_14f40 = pTarget;
            pTarget->vf0();
        }
    }
    return 0;
}

// 0x71004402b0
s32 IGPUDevice::vf9(void* object, s32 arg2) {
    Unk_IndexBuffer* pObject = static_cast<Unk_IndexBuffer*>(object);
    field_14fd0 = arg2;
    if (field_14fc8 != pObject) {
        PPFX_SAFE_RELEASE_INTERFACE(field_14fc8);
        if (pObject != nullptr) {
            field_14fc8 = pObject;
            pObject->vf0();
        }
    }
    return 0;
}

// 0x7100440320
s32 IGPUDevice::vf10(u32 index, Unk_PixelContainer** target) {
    if (index >= 8 || target == nullptr) {
        return -6;
    }
    *target = field_14f00[index];
    if (*target == nullptr) {
        return -0x100;
    }
    (*target)->vf0();
    return 0;
}

// 0x7100440380
s32 IGPUDevice::vf11(IGPUInterface** target) {
    if (target == nullptr) {
        return -6;
    }
    *target = field_14f40;
    if (*target == nullptr) {
        return -0x100;
    }
    (*target)->vf0();
    return 0;
}

// 0x71004403d0
s32 IGPUDevice::vf13(IGPUInterface** object) {
    if (object == nullptr) {
        return -6;
    }
    *object = field_14fc8;
    if (*object == nullptr) {
        return -0x100;
    }
    (*object)->vf0();
    return 0;
}

// 0x7100440420
s32 IGPUDevice::vf12(IGPUInterface** object) {
    if (object != nullptr) {
        *object = field_14ff0;
        field_14ff0->vf0();
    }
    return 0;
}

// 0x7100440460
s32 IGPUDevice::vf14(u32 index, IGPUInterface* texture) {
    PPFX_SAFE_RELEASE_INTERFACE(field_14f48[index]);
    if (texture != nullptr) {
        field_14f48[index] = texture;
        texture->vf0();
    }
    return 0;
}

// 0x71004404c0
s32 IGPUDevice::vf15(u32 index, IGPUInterface** texture) {
    if (index >= 16 || texture == nullptr) {
        return -6;
    }
    *texture = field_14f48[index];
    if (*texture == nullptr) {
        return -0x100;
    }
    (*texture)->vf0();
    return 0;
}

// 0x7100440520
s32 IGPUDevice::vf16(const Unk_Viewport* viewport) {
    if (viewport == nullptr) {
        return -6;
    }
    Unk_ViewportF value;
    value.field_0 = static_cast<f32>(static_cast<u32>(viewport->field_0));
    value.field_4 = static_cast<f32>(static_cast<u32>(viewport->field_4));
    value.field_8 = static_cast<f32>(viewport->field_8);
    value.field_c = static_cast<f32>(viewport->field_c);
    value.field_10 = viewport->field_10;
    value.field_14 = viewport->field_14;
    field_14d10 = value;
    return 0;
}

// 0x71004405a0
s32 IGPUDevice::vf17(Unk_Viewport* viewport) {
    if (viewport == nullptr) {
        return -6;
    }
    viewport->field_0 = static_cast<u32>(field_14d10.field_0 + 0.499999f);
    viewport->field_4 = static_cast<u32>(field_14d10.field_4 + 0.499999f);
    viewport->field_8 = static_cast<u32>(field_14d10.field_8 + 0.499999f);
    viewport->field_c = static_cast<u32>(field_14d10.field_c + 0.499999f);
    viewport->field_10 = field_14d10.field_10;
    viewport->field_14 = field_14d10.field_14;
    return 0;
}

// 0x7100440640
s32 IGPUDevice::vf18(const Unk_Viewport* rect) {
    if (rect != nullptr) {
        field_14d28 = rect->field_0;
        field_14d30 = rect->field_4;
        field_14d2c = rect->field_0 + rect->field_8;
        field_14d34 = rect->field_4 + rect->field_c;
    } else {
        Unk_Viewport viewport;
        vf17(&viewport);
        vf18(&viewport);
    }
    return 0;
}

// 0x71004406f0
s32 IGPUDevice::vf19(const Unk_ScissorRect* rect) {
    if (rect != nullptr) {
        field_14d28 = rect->field_0;
        field_14d30 = rect->field_8;
        field_14d2c = rect->field_10;
        field_14d34 = rect->field_18;
    } else {
        Unk_Viewport viewport;
        vf17(&viewport);
        vf18(&viewport);
    }
    return 0;
}

// 0x7100440790
s32 IGPUDevice::vf51(u32 flags, const f32* color, f32 depth, u32 stencil) {
    f32 r;
    f32 g;
    f32 b;
    f32 a;
    if (color != nullptr) {
        r = color[0];
        g = color[1];
        b = color[2];
        a = color[3];
    } else {
        r = 0.0f;
        g = 0.0f;
        b = 0.0f;
        a = 0.0f;
    }
    for (s32 i = 0; i < 8; i++) {
        field_14d38[i][0] = r;
        field_14d38[i][1] = g;
        field_14d38[i][2] = b;
        field_14d38[i][3] = a;
    }
    field_14db8 = depth;
    field_14dbc = stencil;
    field_14dc0 = flags;
    Unk_BeginTarget();
    return 0;
}

// 0x7100440a20
s32 IGPUDevice::vf52(u32 flags, u32 color, f32 depth, u32 stencil) {
    f32 rgba[4];
    rgba[0] = static_cast<f32>((color >> 16) & 0xff) * (1.0f / 255.0f);
    rgba[1] = static_cast<f32>((color >> 8) & 0xff) * (1.0f / 255.0f);
    rgba[2] = static_cast<f32>(color & 0xff) * (1.0f / 255.0f);
    rgba[3] = static_cast<f32>(color >> 24) * (1.0f / 255.0f);
    return vf51(flags, rgba, depth, stencil);
}

// 0x7100440aa0
s32 IGPUDevice::vf22() {
#line 7247
    UNK_PPFX_WARNING_SOMETIMES("IGPUDevice::ApplyRenderState_DepthTestEnable() is not supported.\n");
    return -4;
}

// 0x7100440b50
s32 IGPUDevice::vf23() {
#line 7350
    UNK_PPFX_WARNING_SOMETIMES("IGPUDevice::ApplyRenderState_DepthFunc() is not supported.\n");
    return -4;
}

// 0x7100440d60
s32 IGPUDevice::vf39() {
    field_15014 = -1;
    return 0;
}

// 0x7100440d90
s32 IGPUDevice::vf41(s32 state, bool cached) {
    if (state == -1) {
        state = field_15018;
    }
    if (static_cast<u32>(state) > 0x3f) {
        return -6;
    }
    if (!Unk_238c3f8) {
        field_15014 = -1;
    }
    s32 applied = field_15014;
    if (Unk_238c3f8 && cached) {
        if (state == applied) {
            field_15018 = state;
            return 1;
        }
        field_15018 = state;
    } else {
        field_15018 = state;
    }
    if (applied == -1 || (((applied & 7) ^ (state & 7)) | (((applied >> 3) & 3) ^ ((state >> 3) & 3)) |
                          (((applied >> 5) & 1) ^ ((state >> 5) & 1))) != 0) {
        field_14dc4 = state;
        u32 color[4];
        color[0] = field_1501c.field_0[0];
        color[1] = field_1501c.field_0[1];
        color[2] = field_1501c.field_0[2];
        color[3] = field_1501c.field_0[3];
        field_30->vf21(color);
    }
    if (Unk_238c3f8) {
        field_15014 = state;
    }
    return 0;
}

// 0x7100440ed0
s32 IGPUDevice::vf42(s32 state) {
    if (static_cast<u32>(state) > 0x3f) {
        return -6;
    }
    field_15018 = state;
    return 0;
}

// 0x7100440f00
s32 IGPUDevice::vf43() {
    return field_15018;
}

// 0x7100440f10
s32 IGPUDevice::vf44(s32 arg) {
    if (static_cast<u32>(arg) > 5) {
        return -6;
    }
    return vf42((field_15018 & ~7) | arg);
}

// 0x7100440f40
s32 IGPUDevice::vf47() {
    return field_15018 & 7;
}

// 0x7100440f60
s32 IGPUDevice::vf50(const Unk_BlendColor* color) {
    field_1501c = *color;
    vf39();
    return 0;
}

// 0x7100440fa0
s32 IGPUDevice::vf45(s32 arg) {
    if (static_cast<u32>(arg) > 2) {
        return -6;
    }
    return vf42((field_15018 & ~0x18) | (arg << 3));
}

// 0x7100440fd0
s32 IGPUDevice::vf48() {
    return (field_15018 >> 3) & 3;
}

// 0x7100440ff0
s32 IGPUDevice::vf46(s32 arg) {
    if (static_cast<u32>(arg) > 1) {
        return -6;
    }
    return vf42((field_15018 & ~0x20) | (arg << 5));
}

// 0x7100441020
s32 IGPUDevice::vf49() {
    return (field_15018 >> 5) & 1;
}

// 0x7100441050
s32 IGPUDevice::vf57(s32 primitive, u32 arg2, u32 arg3) {
    Unk_BeginTarget();
    s32 result = SetupSiGfxDrawContext(primitive);
    if (result >= 0) {
        field_30->vf24(arg2, arg3, 1, 0);
    } else {
#line 9995
        PPFX_ERROR("IGPUDevice::DrawVertices(): SetupSiGfxDrawContext() failed.\n");
    }
    return result;
}

// 0x71004411e0
s32 IGPUDevice::vf58(s32 primitive, s32 count, s32 arg3, s32 arg4, s32 arg5) {
    Unk_IndexBuffer* indexBuffer = field_14fc8;
    if (indexBuffer == nullptr) {
#line 10031
        PPFX_ERROR("IGPUDevice::DrawIndices(): Index buffer is not set yet.");
        return -3;
    }
    Unk_BeginTarget();
    s32 result = SetupSiGfxDrawContext(primitive);
    if (result >= 0) {
        field_30->vf20(indexBuffer->field_50[indexBuffer->field_58], field_14fd0);
        field_30->vf25(count, arg3, 0, 1, 0);
    } else {
#line 10078
        PPFX_ERROR("IGPUDevice::DrawIndices(): SetupSiGfxDrawContext() failed.\n");
    }
    return result;
}

// 0x71004413d0
s32 IGPUDevice::vf59(s32 primitive, u32 arg2, u32 instances, u32 arg4) {
    Unk_IndexBuffer* indexBuffer = field_14fc8;
    if (indexBuffer == nullptr) {
#line 10266
        PPFX_ERROR("IGPUDevice::DrawIndicesInstanced(): Index buffer is not set yet.");
        return -3;
    }
    Unk_BeginTarget();
    s32 result = SetupSiGfxDrawContext(primitive);
    if (result >= 0) {
        field_30->vf20(indexBuffer->field_50[indexBuffer->field_58], field_14fd0);
        field_30->vf25(arg2, arg4, 0, instances, 0);
    } else {
#line 10308
        PPFX_ERROR("IGPUDevice::DrawIndicesInstanced(): SetupSiGfxDrawContext() failed.\n");
    }
    return result;
}

// 0x71004415d0
s32 IGPUDevice::vf60(u32 width, u32 height, u32 arg3, u32 usage, s32 format, s32 msaa, u32 arg7,
                     IGPUInterface** texture, u32 flags) {
#line 10664
    PPFX_LOG("==== IGPUDevice::CreateTexture() ====\n");
    if (Unk_24e000c != 0) {
        const char* formatName = Unk_446b20(format, nullptr);
        u32 samples = Unk_446e40(msaa);
        const char* usageName = Unk_446c40(usage, true, nullptr);
        if (formatName == nullptr) {
            formatName = "";
        }
        UNK_PPFX_INFO("%s %s:\t%4d x %4d,\t%s (0x%04x),\tMSAA(%2dx, %2d),\tUsage 0x%08x,\tFlags 0x%08x\n", "Tex2D",
                      usageName, width, height, formatName, format, samples, arg7, usage, flags);
    }
    if (texture == nullptr || width == 0 || height == 0) {
        return -6;
    }
    *texture = Unk_447da0(this, width, height, arg3, format, msaa, arg7, usage, flags);
    if (*texture != nullptr) {
        return 0;
    }
#line 10685
    PPFX_ERROR("IGPUDevice::CreateTexture(): IGPUTexture::CreateTexture() failed.\n");
    return -1;
}

// 0x71004417b0
s32 IGPUDevice::vf61(u32 width, u32 height, u32 depth, u32 arg4, u32 usage, s32 format, IGPUInterface** texture,
                     u32 flags) {
#line 10705
    PPFX_LOG("==== IGPUDevice::CreateVolumeTexture() ====\n");
    if (Unk_24e000c != 0) {
        const char* formatName = Unk_446b20(format, nullptr);
        const char* usageName = Unk_446c40(usage, true, nullptr);
        if (formatName == nullptr) {
            formatName = "";
        }
        UNK_PPFX_INFO("%s %s:\t%4d x %4d x %4d,\t%s (0x%04x),\tUsage 0x%08x,\tFlags 0x%08x\n", "Tex3D", usageName,
                      width, height, depth, formatName, format, usage, flags);
    }
    if (texture == nullptr || width == 0 || height == 0 || depth == 0) {
        return -6;
    }
    *texture = reinterpret_cast<IGPUInterface*>(
        Unk_4486a0_get(reinterpret_cast<u64>(this), width, height, depth, arg4, format, usage, flags));
    if (*texture != nullptr) {
        return 0;
    }
#line 10723
    PPFX_ERROR("IGPUDevice::CreateVolumeTexture(): IGPUTexture::CreateVolumeTexture() failed.\n");
    return -1;
}

// 0x7100441980
s32 IGPUDevice::vf62(u32 width, u32 height, u32 arg3, u32 usage, s32 format, void* deviceTexture,
                     IGPUInterface** texture) {
#line 10742
    PPFX_LOG("==== IGPUDevice::CreateTexture() ====\n");
    if (Unk_24e000c != 0) {
        const char* formatName = Unk_446b20(format, nullptr);
        u32 samples = Unk_446e40(0);
        const char* usageName = Unk_446c40(usage, true, nullptr);
        if (formatName == nullptr) {
            formatName = "";
        }
        UNK_PPFX_INFO("%s %s:\t%4d x %4d,\t%s (0x%04x),\tMSAA(%2dx, %2d),\tUsage 0x%08x,\tFlags 0x%08x\n", "Ref2D",
                      usageName, width, height, formatName, format, samples, 0, usage, 0);
    }
    if (texture == nullptr || width == 0 || height == 0) {
        return -6;
    }
    *texture = Unk_4481c0(this, deviceTexture, width, height, arg3, format, usage);
    if (*texture != nullptr) {
        return 0;
    }
#line 10761
    PPFX_ERROR("IGPUDevice::CreateTexture(): IGPUTexture::CreateTexture_GPUDEVICETEXTURE() failed.\n");
    return -1;
}

// 0x7100441b50
s32 IGPUDevice::vf63(u32 width, u32 height, u32 depth, u32 arg4, u32 usage, s32 format, void* deviceTexture,
                     IGPUInterface** texture) {
#line 10780
    PPFX_LOG("==== IGPUDevice::CreateVolumeTexture() ====\n");
    if (Unk_24e000c != 0) {
        const char* formatName = Unk_446b20(format, nullptr);
        const char* usageName = Unk_446c40(usage, true, nullptr);
        if (formatName == nullptr) {
            formatName = "";
        }
        UNK_PPFX_INFO("%s %s:\t%4d x %4d x %4d,\t%s (0x%04x),\tUsage 0x%08x,\tFlags 0x%08x\n", "Ref3D", usageName,
                      width, height, depth, formatName, format, usage, 0);
    }
    if (texture == nullptr || width == 0 || height == 0 || depth == 0) {
        return -6;
    }
    *texture = Unk_4486b0(this, deviceTexture, width, height, depth, arg4, format, usage);
    if (*texture != nullptr) {
        return 0;
    }
#line 10799
    PPFX_ERROR("IGPUDevice::CreateVolumeTexture(): IGPUTexture::CreateVolumeTexture_GPUDEVICETEXTURE() failed.\n");
    return -1;
}

// What the functions that make a surface print for it.
#define UNK_SURFACE_INFO(kindName, msaa, quality, usage, flags)                                                       \
    if (Unk_24e000c != 0) {                                                                                           \
        const char* formatName = Unk_446b20(format, nullptr);                                                         \
        u32 samples = Unk_446e40(msaa);                                                                               \
        const char* usageName = Unk_446c40(usage, true, nullptr);                                                        \
        if (formatName == nullptr) {                                                                                  \
            formatName = "";                                                                                          \
        }                                                                                                             \
        UNK_PPFX_INFO("%s %s:\t%4d x %4d,\t%s (0x%04x),\tMSAA(%2dx, %2d),\tUsage 0x%08x,\tFlags 0x%08x\n", kindName, \
                      usageName, width, height, formatName, format, samples, quality, usage, flags);                  \
    }

// 0x7100441d20
s32 IGPUDevice::vf64(u32 width, u32 height, s32 format, s32 msaa, u32 quality, IGPUInterface** surface, u32 flags,
                     void* arg8, u32 arg9, bool unordered) {
#line 10820
    PPFX_LOG("==== IGPUDevice::CreateRenderTarget() ====\n");
    if (unordered) {
        UNK_SURFACE_INFO("UA   ", msaa, quality, 1, flags)
    } else {
        UNK_SURFACE_INFO("RT   ", msaa, quality, 1, flags)
    }
    if (surface == nullptr || width == 0 || height == 0) {
        return -6;
    }
    *surface = Unk_445740(this, width, height, format, unordered ? 4 : 1, msaa, quality, flags, arg8, arg9);
    return *surface != nullptr ? 0 : -1;
}

// 0x7100441f50
s32 IGPUDevice::vf65(u32 width, u32 height, s32 format, s32 msaa, u32 quality, IGPUInterface** surface, u32 flags,
                     void* arg8, u32 arg9) {
#line 10860
    PPFX_LOG("==== IGPUDevice::CreateDepthStencilSurface() ====\n");
    UNK_SURFACE_INFO("DS   ", msaa, quality, 2, flags)
    if (surface == nullptr || width == 0 || height == 0) {
        return -6;
    }
    *surface = Unk_445740(this, width, height, format, 2, msaa, quality, flags, arg8, arg9);
    if (*surface != nullptr) {
        return 0;
    }
#line 10884
    PPFX_ERROR("IGPUDevice::CreateDepthStencilSurface(): IGPUSurface::CreateSurface() failed.\n");
    return -1;
}

// 0x7100442140
s32 IGPUDevice::vf66(u32 width, u32 height, s32 format, IGPUInterface** surface, u32 flags) {
#line 10919
    PPFX_LOG("==== IGPUDevice::CreateSurface() ====\n");
    UNK_SURFACE_INFO("PSURF", 0, 0, 0, flags)
    if (surface == nullptr || width == 0 || height == 0) {
        return -6;
    }
    *surface = Unk_445740(this, width, height, format, 0, 0, 0, flags, nullptr, 0);
    if (*surface != nullptr) {
        return 0;
    }
#line 10949
    PPFX_ERROR("IGPUDevice::CreateSurface(): IGPUSurface::CreateSurface() failed.\n");
    return -1;
}

// 0x7100442320
s32 IGPUDevice::vf67(u32 width, u32 height, s32 format, s32 msaa, u32 quality, void* deviceSurface,
                     IGPUInterface** surface) {
#line 10991
    PPFX_LOG("==== IGPUDevice::CreateSurface() ====\n");
    UNK_SURFACE_INFO("RefRT", msaa, quality, 1, 0)
    if (surface == nullptr || width == 0 || height == 0) {
        return -6;
    }
    *surface = static_cast<IGPUInterface*>(Unk_445af0_call(this, deviceSurface, width, height, format, msaa, quality));
    if (*surface != nullptr) {
        return 0;
    }
#line 11010
    PPFX_ERROR("IGPUDevice::CreateSurface(): IGPUSurface::CreateSurface_GPUDEVICESURFACE() failed.\n");
    return -1;
}

// 0x7100442930
s32 IGPUDevice::vf70(const Unk_InputElement* elements, s32 count, void* arg3, s32 arg4, IGPUInterface** attribute) {
#line 11134
    PPFX_LOG("==== IGPUDevice::CreateInputAttribute() ====\n");
    *attribute = Unk_449cc0(this, elements, count, arg3, arg4);
    if (*attribute != nullptr) {
        return 0;
    }
#line 11144
    PPFX_ERROR("IGPUDevice::CreateInputAttribute(): IGPUInputAttribute::CreateInputAttribute() failed.\n");
    return -1;
}

// 0x71004424f0
s32 IGPUDevice::vf71(IGPUQueryOcclusion** query) {
#line 11023
    PPFX_LOG("==== IGPUDevice::CreateQueryOcclusion() ====\n");
    *query = Unk_44a880(this);
    if (*query != nullptr) {
        return 0;
    }
#line 11036
    PPFX_ERROR("IGPUDevice::CreateQueryOcclusion(): IGPUQueryOcclusion::CreateQueryOcclusion() failed.\n");
    return -1;
}

// 0x71004425c0
s32 IGPUDevice::vf68(u32 count, u32 stride, u32 usage, IGPUBuffer** buffer, u32 flags, void* arg6) {
#line 11068
    PPFX_LOG("==== IGPUDevice::CreateVertexBuffer() ====\n");
    if (Unk_24e000c != 0) {
        const char* formatName = Unk_446d60(-1, nullptr);
        const char* usageName = Unk_446c40(usage, true, nullptr);
        if (formatName == nullptr) {
            formatName = "";
        }
        UNK_PPFX_INFO("%s %s:\t%6d x %3d (%8d),\t%s (0x%04x),\tUsage 0x%08x,\tFlags 0x%08x\n", "VB", usageName, count,
                      stride, stride * count, formatName, -1, usage, flags);
    }
    *buffer = Unk_449450(this, count, stride, usage, flags, arg6);
    if (*buffer != nullptr) {
        return 0;
    }
#line 11082
    PPFX_ERROR("IGPUDevice::CreateVertexBuffer(): IGPUVertexBuffer::CreateVertexBuffer() failed.\n");
    return -1;
}

// 0x7100442770
s32 IGPUDevice::vf69(u32 count, u32 stride, s32 format, u32 usage, IGPUBuffer** buffer, u32 flags, void* arg7) {
#line 11102
    PPFX_LOG("==== IGPUDevice::CreateIndexBuffer() ====\n");
    if (Unk_24e000c != 0) {
        const char* formatName = Unk_446d60(format, nullptr);
        const char* usageName = Unk_446c40(usage, true, nullptr);
        if (formatName == nullptr) {
            formatName = "";
        }
        UNK_PPFX_INFO("%s %s:\t%6d x %3d (%8d),\t%s (0x%04x),\tUsage 0x%08x,\tFlags 0x%08x\n", "IB", usageName, count,
                      stride, stride * count, formatName, format, usage, flags);
    }
    *buffer = Unk_449600(this, count, stride, format, usage, flags, arg7);
    if (*buffer != nullptr) {
        return 0;
    }
#line 11117
    PPFX_ERROR("IGPUDevice::CreateIndexBuffer(): IGPUIndexBuffer::CreateIndexBuffer() failed.\n");
    return -1;
}

// 0x7100442a20
s32 IGPUDevice::vf72(s32 arg1, s32 arg2, s32 arg3) {
    return -1;
}

// 0x7100442a30
s32 IGPUDevice::vf74(s32 arg1, s32 arg2, s32 arg3) {
    Unk_447010(arg2, arg3);
    return vf72(arg1, arg2, arg3);
}

// Formats that vf73 gives fewer uses (inline in it).
static inline bool Unk_IsFormatA(s32 format) {
    switch (format) {
    case 2:
    case 6:
    case 16:
    case 20:
    case 21:
    case 40:
    case 41:
        return true;
    default:
        return false;
    }
}

// Formats that vf73 gives more uses (inline in it).
static inline bool Unk_IsFormatC(s32 format) {
    switch (format) {
    case 29:
    case 72:
    case 75:
    case 78:
    case 91:
    case 93:
    case 99:
        return true;
    default:
        return false;
    }
}

// 0x7100442a90: what a format can be used for
u32 IGPUDevice::vf73(s32 type, s32 format) {
    switch (type) {
    case 3:
    case 4:
    case 5:
    case 6:
        break;
    default:
        return 0;
    }
    u32 flags = Unk_IsFormatA(format) ? 0 : 0xa0000;
    switch (format) {
    case 20:
    case 40:
    case 45:
    case 55:
        flags |= 2;
        break;
    default:
        flags |= 1;
        break;
    }
    if (format != 0 && Unk_IsFormatC(format)) {
        flags |= 0x50000;
    }
    if (Unk_446b10_get(format)) {
        flags |= 0x40000;
    }
    return flags;
}

// 0x7100442b70
s32 IGPUDevice::vf75(s32 arg1, s32 arg2, s32 arg3) {
    switch (arg2) {
    case 3:
    case 4:
    case 5:
    case 6:
        return (arg1 & ~vf73(arg2, arg3)) != 0 ? -1 : 0;
    default:
        return -4;
    }
}

// 0x7100442bc0: the first of some formats that a usage can have, or a
// fallback
s32 Unk_442bc0(IGPUDevice* self, s32 usage, s32 type, const s32* formats, s32 count, s32 fallback) {
    for (s32 i = 0; i < count; i++) {
        if ((usage & ~self->vf73(type, formats[i])) == 0) {
            if (formats[i] != 0) {
                return formats[i];
            }
            break;
        }
    }
    return fallback;
}

// 0x7100442de0
s32 IGPUDevice::vf54(bool enable, s32 value) {
    field_15004 = enable;
    field_15008 = value;
    return 0;
}

// 0x7100442e10
s32 IGPUDevice::vf55(f32 a, f32 b) {
    field_1500c = Unk_Float2(a, b);
    return 0;
}

// 0x710043e600, 0x710043e620: a count the device's resources add to and take from
s32 Unk_43e600(IGPUDevice* self, s32 n) {
    return self->field_15000 += n;
}

s32 Unk_43e620(IGPUDevice* self, s32 n) {
    return self->field_15000 -= n;
}

}  // namespace PPFX

// The functions PPFX::IGPUEffect and lib/yebis/leaf call under these names
// and types.

// 0x710043fa90
u64 Unk_43fa90(u64 self, u32 index) {
    if (index > 15) {
        return 0;
    }
    return reinterpret_cast<u64>(reinterpret_cast<PPFX::IGPUDevice*>(self)->field_14c88[static_cast<s32>(index)]);
}

// 0x710043fc00
s32 Unk_43fc00(void* self, u32 pass) {
    PPFX::IGPUDevice* device = static_cast<PPFX::IGPUDevice*>(self);
    device->field_14d08 = true;
    device->field_14d0c = pass;
    return 0;
}

// 0x710043fc30
s32 Unk_43fc30(void* self) {
    PPFX::IGPUDevice* device = static_cast<PPFX::IGPUDevice*>(self);
    if (device->field_14d09) {
        if (device->field_30 != nullptr) {
            device->field_30->vf12();
        }
        device->field_14d09 = false;
        device->field_14d08 = false;
    }
    return 0;
}

// 0x710043fd20
s32 Unk_43fd20(void* self, u32 arg1, u32 count, void* a, void* b, void* c) {
    PPFX::IGPUDevice* device = static_cast<PPFX::IGPUDevice*>(self);
    device->field_14de8 = arg1;
    device->field_14dec = count;
    if (a != nullptr) {
        memcpy(device->field_14df0, a, count * sizeof(u64));
    }
    if (b != nullptr) {
        memcpy(device->field_14e70, b, count * sizeof(u32));
    }
    if (c != nullptr) {
        memcpy(device->field_14eb0, c, count * sizeof(u32));
    }
    return 0;
}

// 0x710043fca0, 0x710043fcc0, 0x710043fce0, 0x710043fd00
s32 Unk_43fca0(void* self, void* value) {
    static_cast<PPFX::IGPUDevice*>(self)->field_14dc8 = value;
    return 0;
}

s32 Unk_43fcc0(void* self, void* value) {
    static_cast<PPFX::IGPUDevice*>(self)->field_14dd0 = value;
    return 0;
}

s32 Unk_43fce0(void* self, void* value) {
    static_cast<PPFX::IGPUDevice*>(self)->field_14dd8 = value;
    return 0;
}

s32 Unk_43fd00(void* self, void* value) {
    static_cast<PPFX::IGPUDevice*>(self)->field_14de0 = value;
    return 0;
}
