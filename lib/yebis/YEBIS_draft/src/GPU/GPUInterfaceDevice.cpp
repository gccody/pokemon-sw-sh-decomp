// Scope: common
// PPFX::IGPUDevice (GPUInterfaceDevice.cpp is the file its log lines name):
// YEBIS's device on SiSDK3's SiGfx. The functions that only return a
// constant are lib/yebis/class's.
#include <yebis/YEBIS_draft/src/GPU/Unk_Statics.h>
#include <yebis/YEBIS_draft/src/GPU/GPUInterfaceDevice.h>
#include <yebis/YEBIS_draft/src/GPU/GPUInterfaceTexture.h>

#include <string.h>

#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiGfx/Source/Unk_27703d8.h>

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

// 0x71024e1500: the settings the device is made with
PPFX::Unk_DeviceSettings Unk_24e1500;

namespace PPFX {

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
// 0x71004481c0, 0x71004486b0: a texture and a volume texture of a device
// texture there is
IGPUInterface* Unk_4481c0(IGPUDevice* device, void* deviceTexture, u32 width, u32 height, u32 arg4, s32 format,
                          u32 usage);
IGPUInterface* Unk_4486b0(IGPUDevice* device, void* deviceTexture, u32 width, u32 height, u32 depth, u32 arg5,
                          s32 format, u32 usage);

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

// 0x710043dc70
s32 GPUSiGfxLazyDrawCommand::Execute(Unk_SiGfxDrawContext* context) {
    if (field_0 != 0) {
        return -1;
    }
    void* target = field_10->vf25(field_1c);
    void* source = field_8->vf25(field_18);
    return context->vf71(source, target) ? 0 : -1;
}

// 0x710043dd00
IGPUDevice::IGPUDevice() : field_28(0), field_58(false), field_59(false) {
    field_14d10.field_0 = 0.0f;
    field_14d10.field_4 = 0.0f;
    field_14d10.field_8 = 0.0f;
    field_14d10.field_c = 0.0f;
    field_14d10.field_10 = 0.0f;
    field_14d10.field_14 = 1.0f;
    field_14d28 = 0;
    field_14d2c = 0;
    field_14d30 = 0;
    field_14d34 = 0;
    field_14db8 = 1.0f;
    field_14dbc = 0;
    field_14dc0 = 0xffff;
    for (s32 i = 0; i < 8; i++) {
        for (s32 j = 0; j < 4; j++) {
            field_14d38[i][j] = 0.0f;
        }
    }
    field_14fd4.field_0 = 0;
    field_14fd4.field_4 = 0;
    field_14fd4.field_8 = 0;
    field_14fd4.field_c = 0;
    field_14fd4.field_10 = 0.0f;
    field_14fd4.field_14 = 1.0f;
    field_30 = nullptr;
    field_38 = nullptr;
    field_40.clear();
    field_14d0c = 0;
    // (cleared again by the memset below: the store dies, but its address,
    // computed here, is what the memset is handed)
    field_14dc4 = -1;
    memset(field_88, 0, reinterpret_cast<u8*>(field_14d0a) - reinterpret_cast<u8*>(field_88));
    memset(&field_14dc4, 0, reinterpret_cast<u8*>(&field_14ef0) - reinterpret_cast<u8*>(&field_14dc4));
    field_10.clear();
    field_14fc8 = nullptr;
    field_14fd0 = 0;
    field_15000 = 0;
    for (s32 i = 0; i < 8; i++) {
        field_14f00[i] = nullptr;
    }
    field_14f40 = nullptr;
    for (s32 i = 0; i < 8; i++) {
        field_14f48[i] = nullptr;
    }
}

// 0x710043e640
bool IGPUDevice::Unk_PipelineKey::operator==(const Unk_PipelineKey& other) const {
    if (field_10 != other.field_10 || field_18 != other.field_18 || field_118 != other.field_118 ||
        field_fc != other.field_fc || field_110 != other.field_110) {
        return false;
    }
    for (s32 i = 0; i < field_fc; i++) {
        if (!(field_1c[i] == other.field_1c[i])) {
            return false;
        }
    }
    for (s32 i = 0; i < field_110; i++) {
        if (field_100[i] != other.field_100[i]) {
            return false;
        }
    }
    return true;
}

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

}  // namespace PPFX

// 0x71004cbf40: SiGfx's kernel (leafgen's name and type)
u64 Unk_4cbf40_get();

namespace PPFX {

// boost's hash_combine (inline)
static inline void Unk_HashCombine(u64& seed, u64 value) {
    seed ^= value + 0x9e3779b9 + (seed << 6) + (seed >> 2);
}

// the first render target's SiGfx resource: slot 35 gives its formats
struct Unk_SiGfxTargetResource {
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
    virtual const Unk_PipelineDesc::Unk_4ec* vf35();
};

// the SiGfx vertex format the effect set (field_14de0): slot 32 gives its
// vertex attributes
struct Unk_SiGfxVertexLayoutSource {
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
    virtual const Unk_PipelineDesc::Unk_VertexLayout* vf32();
};

// appends a pipeline state, growing the array by field_40 elements or to
// twice the room (inline: placeholder name; unlike SiCore_Array.h's Unk_Add
// each way of growing has its own call)
static inline bool Unk_AddState(IGPUDevice::Unk_PipelineStates* states, const IGPUDevice::PipelineStateData& value) {
    if (states->m_itemCount >= states->m_reservedCount) {
        if (states->field_40 != 0) {
            if (!states->Unk_4bf190(states->field_40 + states->m_reservedCount, true)) {
                states->m_itemCount = 0;
                states->field_30 = nullptr;
                states->field_38 = nullptr;
                return false;
            }
        } else {
            size_t count = states->m_reservedCount * 2;
            if (!states->Unk_4bf190(count != 0 ? count : 1, true)) {
                states->m_itemCount = 0;
                states->field_30 = nullptr;
                states->field_38 = nullptr;
                return false;
            }
        }
    }
    states->m_pData[states->m_itemCount] = value;
    states->m_itemCount++;
    states->field_30 = states->m_pData;
    states->field_38 = states->m_pData + states->m_itemCount;
    return true;
}

// a pipeline state of an array (inline: placeholder name)
static inline const IGPUDevice::PipelineStateData& Unk_StateAt(const IGPUDevice::Unk_PipelineStates* states,
                                                               size_t index) {
    return states->m_pData[index];
}

// SiGfx's kernel as the device asks it for its allocator (slot 6)
struct Unk_SiGfxKernel {
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual SiSDK3::ISiAllocator* vf6();
};

// 0x710043e780: hands the draw context the pipeline state of the blend
// state's description (made the first time, kept by the description's hash
// in field_60), the shaders, the viewport, the scissor rectangle and the
// effect's resources. The key it looks the states up with only has its hash
// when the array is searched (the original's order). The element accessor
// returns a reference: before it is inlined the state's load is speculated
// on its dereferenceable result, which gives the loop's select.
// NON_MATCHING: the same instructions and blocks but for register allocation
// (the blend state's index, field_14dc8's address and the description's
// pointer take other callee-saved registers; the original spills
// &desc->field_8 where it is made and keeps &key.field_8 in x24) and the
// order of vf19's argument addresses (the original computes field_14e70's and
// field_14eb0's first).
s32 IGPUDevice::SetupSiGfxDrawContext(s32 primitive) {
    Unk_SiGfxDrawContext* context = field_30;
    if (context == nullptr || !field_14d09) {
        return -1;
    }
    Unk_PipelineDesc* desc = &field_88[field_14dc4];
    Unk_SiGfxTargetResource* resource;
    Unk_SiGfxRenderTarget* target;
    if (field_14f00[0] != nullptr) {
        resource = reinterpret_cast<Unk_SiGfxTargetResource*>(field_14f00[0]->field_a8);
        target = field_14f00[0]->field_b8;
    } else {
        target = nullptr;
        resource = nullptr;
    }
    desc->field_0 = field_14dc8;
    desc->field_8 = field_14dd8;
    if (resource != nullptr) {
        desc->field_4ec = *resource->vf35();
    }
    if (field_14de0 != nullptr) {
        desc->field_168 = *reinterpret_cast<Unk_SiGfxVertexLayoutSource*>(field_14de0)->vf32();
    }
    desc->field_160 = primitive;
    desc->field_520 = target;
    u64 hash = 0;
    Unk_HashCombine(hash, reinterpret_cast<u64>(desc->field_0));
    Unk_HashCombine(hash, reinterpret_cast<u64>(desc->field_8));
    Unk_HashCombine(hash, reinterpret_cast<u64>(desc->field_520));
    Unk_HashCombine(hash, desc->field_4ec.field_4[0]);
    Unk_PipelineKey key;
    key.field_0 = hash;
    Unk_PipelineStates* states;
    Unk_PipelineStateMap::iterator it = field_60.find(key);
    if (it != field_60.end()) {
        states = it->second;
    } else {
        SiSDK3::ISiAllocator* allocator = reinterpret_cast<Unk_SiGfxKernel*>(Unk_4cbf40_get())->vf6();
#line 1270
        states = UNK_SI_NEW(allocator, -1) Unk_PipelineStates(allocator);
        states->Unk_ReserveAtLeast(1);
        field_60.insert(std::make_pair(key, states));
    }
    Unk_SiGfxInterface* pipeline;
    if (states->m_itemCount == 1) {
        pipeline = states->m_pData[0].field_120;
    } else {
        pipeline = nullptr;
        bool found = false;
        for (size_t i = 0; !found && i < states->m_itemCount; i++) {
            const PipelineStateData& data = Unk_StateAt(states, i);
            found = key == data.field_0;
            if (found) {
                pipeline = data.field_120;
            }
        }
        if (pipeline == nullptr) {
            Unk_SiGfxPipelineState* created = field_38->vf25(1, 0, nullptr);
            created->vf8();
            memcpy(created->vf10(), desc, 0x52d);
            created->vf9();
            pipeline = created;
            key.field_8 = desc->field_0;
            key.field_10 = desc->field_8;
            key.field_18 = desc->field_160;
            key.field_118 = desc->field_520;
            s32 elements = desc->field_168.field_380;
            key.field_fc = elements;
            for (s64 i = 0; i < elements; i++) {
                key.field_1c[i] = desc->field_168.field_0[i];
            }
            s32 formats = desc->field_4ec.field_0;
            key.field_110 = formats;
            for (s64 i = 0; i < formats; i++) {
                key.field_100[i] = desc->field_4ec.field_4[i];
            }
            PipelineStateData data;
            data.field_0 = key;
            data.field_120 = pipeline;
            Unk_AddState(states, data);
        }
    }
    context->vf16(pipeline);
    context->vf17(field_14dc8);
    context->vf23(field_14dd0);
    context->vf14(1, &field_14d10);
    context->vf15(1, &field_14d28);
    context->vf19(field_14de8, field_14dec, field_14df0, field_14e70, field_14eb0);
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

}  // namespace PPFX

// 0x7100446df0: a result's name
const char* Unk_446df0(s32 result);

namespace PPFX {

// what Unk_43f200 prints about one of the two surfaces (inline)
static inline void Unk_LogSurface(const char* name, IGPUSurface* surface, IGPUInterface* const& current) {
    const char* format = Unk_446b20(surface->field_44.field_0, nullptr);
    u32 samples = Unk_446e40(surface->field_44.field_10);
    const char* usage = Unk_446c40(static_cast<IGPUSurface*>(current)->field_24, true, nullptr);
    format = format != nullptr ? format : "";
    UNK_PPFX_INFO("%s %s:\t%4d x %4d,\t%s (0x%04x),\tMSAA(%2dx, %2d),\tUsage 0x%08x,\tFlags 0x%08x\n", name, usage,
                  surface->field_44.field_8, surface->field_44.field_c, format, surface->field_44.field_0, samples,
                  surface->field_44.field_14, static_cast<IGPUSurface*>(current)->field_24,
                  static_cast<IGPUSurface*>(current)->field_28);
}

// 0x710043f200: IGPUDevice::InitializeDeviceBuffers (its log lines): the
// surfaces of the back buffer (the settings' size, else the viewport's), the
// viewport and the targets set to them
s32 Unk_43f200(IGPUDevice* self) {
    self->field_14ff0 = nullptr;
    self->field_14ff8 = nullptr;
    Unk_Viewport viewport;
    self->vf17(&viewport);
    if (Unk_24e1500.field_0 == 0) {
        Unk_24e1500.field_0 = viewport.field_8;
    }
    if (Unk_24e1500.field_4 == 0) {
        Unk_24e1500.field_4 = viewport.field_c;
    }
    Unk_SiGfxRenderTarget* target = reinterpret_cast<Unk_SiGfxRenderTarget*>(Unk_24e1500.field_28);
    if (target == nullptr) {
        target = self->field_30->vf33()->field_18;
        if (target == nullptr) {
#line 1691
            PPFX_ERROR("IGPUDevice::InitializeDeviceBuffers(): GetSiGfxDeviceBackBuffer() failed (0x%x: %s).\nEffective backbuffer must be set as the render target.\n",
                       0, Unk_446df0(0));
            return -1;
        }
    }
    target->vf2();
    self->field_14ff0 = IGPUSurface::CreateSurface_SiGfxDefaultRenderTarget(self, 2, target);
    if (self->field_14ff0 == nullptr) {
#line 1708
        PPFX_ERROR("IGPUDevice::InitializeDeviceBuffers(): m_pGPUSurface_BackBuffer = IGPUSurface::CreateSurface_SiGfxDefaultRenderTarget() failed.\n");
    }
    self->field_14ff8 = IGPUSurface::CreateSurface_SiGfxDefaultRenderTarget(self, 3, target);
    target->vf3();
    IGPUSurface* back = static_cast<IGPUSurface*>(self->field_14ff0);
    Unk_Viewport backViewport;
    backViewport.field_0 = 0;
    backViewport.field_4 = 0;
    backViewport.field_8 = back->field_44.field_8;
    backViewport.field_c = back->field_44.field_c;
    backViewport.field_10 = 0.0f;
    backViewport.field_14 = 1.0f;
    self->field_14fd4 = backViewport;
    self->vf54(false, 0);
    self->vf55(0.0f, 0.0f);
    if (Unk_24e000c != 0) {
        Unk_LogSurface("DevBS", back, self->field_14ff0);
    }
    IGPUSurface* depth = static_cast<IGPUSurface*>(self->field_14ff8);
    if (depth != nullptr && Unk_24e000c != 0) {
        Unk_LogSurface("DevDS", depth, self->field_14ff8);
    }
    s32 result = 0;
    s32 r = self->vf7(0, self->field_14ff0, 0);
    if (r < 0) {
#line 1800
        PPFX_ERROR("IGPUDevice::InitializeDeviceBuffers(): SetRenderTarget() failed (0x%x: %s).\n", r, Unk_446df0(r));
        result = r;
    }
    r = self->vf8(self->field_14ff8);
    if (r < 0) {
#line 1806
        PPFX_ERROR("IGPUDevice::InitializeDeviceBuffers(): SetDepthStencilSurface() failed (0x%x: %s).\n", r,
                   Unk_446df0(r));
        result = r;
    }
    return result < 0 ? result : 0;
}

// 0x710043f940: IGPUDevice::InitializeDevice_CreateDeviceStates_SamplerStateMode
// (its log line): the sampler of a mode, bits 0 and 1 the filter and bits 2 and
// 3 the addressing
s32 Unk_43f940(IGPUDevice* self, s32 mode) {
    if (mode < 0 || mode > 15) {
        return -6;
    }
    Unk_27703d8_Item desc(12, 1);
    switch (mode & 3) {
    case 0:
        desc.field_0 = 3;
        desc.field_18 = 0.0f;
        break;
    case 1:
        desc.field_0 = 0;
        desc.field_18 = 0.0f;
        break;
    case 2:
        desc.field_0 = 10;
        desc.field_18 = 3.40282347e+38f;
        break;
    case 3:
        desc.field_0 = 11;
        desc.field_18 = 3.40282347e+38f;
        break;
    }
    desc.field_c = 3;
    u32 address;
    switch ((mode >> 2) & 3) {
    case 0:
        address = 4;
        break;
    case 1:
        address = 3;
        break;
    case 2:
        address = 2;
        break;
    case 3:
        address = 1;
        break;
    }
    desc.field_4 = address;
    desc.field_8 = address;
    Unk_SiGfxInterface* sampler = self->field_38->vf52(&desc, nullptr, 0, nullptr);
    if (sampler == nullptr) {
#line 3811
        PPFX_ERROR("IGPUDevice::InitializeDevice_CreateDeviceStates_SamplerStateMode(): pSiGfxDevice->CreateSampler() failed.\n");
        return -1;
    }
    self->field_14c88[mode] = sampler;
    return 0;
}

// 0x710043f670: the pipeline description of a blend state: bits 0 to 2 the
// blending (6 and 7 aren't one), bits 3 and 4 the channels written (3 isn't
// one), bit 5 alpha to coverage (placeholder reading of field_2d)
// NON_MATCHING: everything up to the fourth of the seven default colour
// targets; the stores of the fourth and the seventh are merged differently
// (the original pairs field_4 with field_8 in the fourth). Every order of the
// loop's assignments tried gives the same or worse.
s32 Unk_43f670(IGPUDevice* self, s32 state) {
    if (state < 0 || state > 63) {
        return -6;
    }
    switch (state & 7) {
    case 6:
    case 7:
        return 1;
    }
    if (((state >> 3) & 3) == 3) {
        return 1;
    }
    Unk_PipelineDesc& desc = self->field_88[state];
    const Unk_PipelineDesc::Unk_Depth depth = {8, false, false};
    desc.field_30 = depth;
    const Unk_PipelineDesc::Unk_Stencil stencil = {false, 0, 0, 0, 1, 1, 1, 8, 1, 1, 1, 8};
    desc.field_38 = stencil;
    const Unk_PipelineDesc::Unk_Raster raster = {1, 3, 0, 0, 0, 0, true, true};
    desc.field_10 = raster;
    if (state & 0x20) {
        desc.field_10.field_1d = true;
    }
    desc.field_514 = 0;
    desc.field_518 = 0;
    desc.field_51c = -1;
    const Unk_PipelineDesc::Unk_5c field_5c = {false, false};
    desc.field_5c = field_5c;
    Unk_PipelineDesc::Unk_Blend& blend = desc.field_60[0];
    blend.field_c = 1;
    blend.field_18 = 1;
    blend.field_1c[0] = 1;
    blend.field_1c[1] = 1;
    blend.field_1c[2] = 1;
    blend.field_1c[3] = 1;
    switch (state & 7) {
    case 0:
        blend.field_0 = false;
        blend.field_4 = 2;
        blend.field_8 = 2;
        blend.field_10 = 2;
        blend.field_14 = 2;
        break;
    case 1:
        blend.field_0 = true;
        blend.field_4 = 5;
        blend.field_8 = 6;
        blend.field_10 = 5;
        blend.field_14 = 6;
        break;
    case 2:
        blend.field_0 = true;
        blend.field_4 = 2;
        blend.field_8 = 2;
        blend.field_10 = 2;
        blend.field_14 = 2;
        break;
    case 3:
        blend.field_0 = true;
        blend.field_4 = 2;
        blend.field_8 = 6;
        blend.field_10 = 2;
        blend.field_14 = 6;
        break;
    case 4:
        blend.field_0 = true;
        blend.field_4 = 9;
        blend.field_8 = 1;
        blend.field_10 = 7;
        blend.field_14 = 1;
        break;
    case 5:
        blend.field_0 = true;
        blend.field_4 = 2;
        blend.field_8 = 14;
        blend.field_10 = 2;
        blend.field_14 = 14;
        break;
    }
    switch ((state >> 3) & 3) {
    case 0:
        blend.field_1c[0] = 1;
        blend.field_1c[1] = 1;
        blend.field_1c[2] = 1;
        blend.field_1c[3] = 1;
        break;
    case 1:
        blend.field_1c[0] = 1;
        blend.field_1c[1] = 1;
        blend.field_1c[2] = 1;
        blend.field_1c[3] = 0;
        break;
    case 2:
        blend.field_1c[0] = 0;
        blend.field_1c[1] = 0;
        blend.field_1c[2] = 0;
        blend.field_1c[3] = 1;
        break;
    }
    for (s32 i = 1; i < 8; i++) {
        desc.field_60[i].field_0 = false;
        desc.field_60[i].field_c = 1;
        desc.field_60[i].field_4 = 2;
        desc.field_60[i].field_8 = 1;
        desc.field_60[i].field_18 = 1;
        desc.field_60[i].field_10 = 2;
        desc.field_60[i].field_14 = 1;
        desc.field_60[i].field_1c[0] = 1;
        desc.field_60[i].field_1c[1] = 1;
        desc.field_60[i].field_1c[2] = 1;
        desc.field_60[i].field_1c[3] = 1;
    }
    return 0;
}

// 0x710043fac0: the device's blend states and samplers
s32 Unk_43fac0(IGPUDevice* self) {
    s32 result;
    for (u32 i = 0; i < 64; i++) {
        result = Unk_43f670(self, i);
        if (result < 0) {
            return result;
        }
    }
    for (s32 i = 0; i < 16; i++) {
        result = Unk_43f940(self, i);
        if (result < 0) {
            return result;
        }
    }
    return 0;
}

}  // namespace PPFX

// 0x7100446df0: a result's name
const char* Unk_446df0(s32 result);

namespace PPFX {

// 0x710043fdd0: IGPUDevice::InitializeDevice (its log lines): takes the draw
// context (the settings' one if they have another) and its device, keeps the
// settings, makes the device's states and buffers and sets the default states
// (the flags from the number of frame slots: one comparison kept in a local,
// stored last, gives the original's store order). The blend colour lives in
// a scope of its own: its lifetime ends before the last log line, so that
// line's tests branch to the return block with the 0 set before them.
s32 Unk_43fdd0(IGPUDevice* self, const Unk_DeviceSettings* settings, void* arg) {
#line 4284
    PPFX_LOG("==== IGPUDevice::InitializeDevice() ====\n");
    self->field_14ff8 = nullptr;
    self->field_14ff0 = nullptr;
    if (arg == nullptr) {
        return -6;
    }
    Unk_SiGfxDrawContext* context = static_cast<Unk_SiGfxDrawContext*>(arg);
    Unk_SiGfxDevice* device = context->vf5();
    if (settings != nullptr) {
        Unk_SiGfxDrawContext* other = reinterpret_cast<Unk_SiGfxDrawContext*>(settings->field_18);
        if (other != nullptr && other != context) {
            context = other;
        }
    }
    if (context != self->field_30) {
        if (self->field_30 != nullptr) {
            self->field_30->vf3();
            self->field_30 = nullptr;
        }
        self->field_30 = context;
        context->vf2();
    }
    self->field_38 = device;
    Unk_24e1500.field_0 = 0;
    Unk_24e1500.field_4 = 0;
    Unk_24e1500.field_8 = 0;
    Unk_24e1500.field_10 = 0;
    Unk_24e1500.field_20 = -1;
    Unk_24e1500.field_24 = -1;
    Unk_24e1500.field_28 = 0;
    if (settings != nullptr) {
        Unk_24e1500 = *settings;
    }
    self->field_28 = Unk_24e1500.field_10;
    Unk_43fac0(self);
    s32 result = Unk_43f200(self);
    if (result < 0) {
#line 4330
        PPFX_ERROR("IGPUDevice::InitializeDevice(): InitializeDeviceBuffers() failed (0x%x: %s).\n", result,
                   Unk_446df0(result));
        return result;
    }
#line 4335
    PPFX_LOG("IGPUDevice::InitializeDevice(): InitializeDeviceBuffers() succeeded.\n", result);
    Unk_24e14f8 = self;
    self->field_14efa = false;
    bool single = self->field_28 < 2;
    self->field_14efb = self->field_28 > 1;
    self->field_14ef0 = false;
    self->field_14ef1 = false;
    self->field_14ef2 = false;
    self->field_14ef3 = true;
    self->field_14ef4 = true;
    self->field_14ef5 = false;
    self->field_14ef6 = true;
    self->field_14ef7 = false;
    self->field_14ef9 = single;
    self->field_14ef8 = single;
    self->vf39();
    self->vf40(-1);
    self->vf42(0);
    {
        Unk_BlendColor color = {};
        self->vf50(&color);
    }
#line 4350
    PPFX_LOG("==== IGPUDevice::InitializeDevice() succeeded. ====\n");
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
    *texture = IGPUTexture::CreateTexture(this, width, height, arg3, format, msaa, arg7, usage, flags);
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
    *surface = IGPUSurface::CreateSurface(this, width, height, format, unordered ? 4 : 1, msaa, quality, flags, arg8, arg9);
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
    *surface = IGPUSurface::CreateSurface(this, width, height, format, 2, msaa, quality, flags, arg8, arg9);
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
    *surface = IGPUSurface::CreateSurface(this, width, height, format, 0, 0, 0, flags, nullptr, 0);
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

namespace PPFX {

// 0x710043fdd0: the device's set-up
s32 Unk_43fdd0(IGPUDevice* self, const Unk_DeviceSettings* settings, void* arg);

// 0x7100442c60
IGPUDevice* IGPUDevice::CreateDevice(const Unk_DeviceSettings* settings, void* arg) {
#line 13634
    IGPUDevice* device = UNK_NEW(IGPUDevice)();
    if (Unk_43fdd0(device, settings, arg) < 0) {
        PPFX_SAFE_RELEASE_INTERFACE(device);
        return nullptr;
    }
    bool lowerLeft;
    switch (settings->field_20) {
    case 0:
        lowerLeft = false;
        break;
    case 1:
        lowerLeft = true;
        break;
    case 3:
        lowerLeft = device->field_38->vf89() == 0;
        break;
    default:
#line 13681
        PPFX_ERROR("IGPUDevice::CreateDevice(): m_eViewportOriginMode is invalid.\n");
        return nullptr;
    }
    device->field_58 = lowerLeft;
    switch (settings->field_24) {
    case 0:
        device->field_59 = false;
        break;
    case 1:
        device->field_59 = true;
        break;
    case 3:
        device->field_59 = device->field_38->vf90() == 0;
        break;
    default:
#line 13727
        PPFX_ERROR("IGPUDevice::CreateDevice(): eClipVolumeNearPlaneMode is invalid.\n");
        return nullptr;
    }
    return device;
}

}  // namespace PPFX

// 0x71004431c0, 0x71004432d0: the pipeline states' table's rehash and
// __rehash (libc++'s), which SetupSiGfxDrawContext's insertion instantiates
template void PPFX::IGPUDevice::Unk_PipelineStateMap::__table::rehash(size_t);

// 0x7100442f60: the pipeline states' arrays' reserve (SiCore_Array.h), which
// SetupSiGfxDrawContext instantiates
template bool SiSDK3::SiArray<PPFX::IGPUDevice::PipelineStateData, 16>::Unk_4bf190(size_t, bool);
