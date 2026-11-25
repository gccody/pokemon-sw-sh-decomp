// Scope: common
// The application's slots (src/unsorted/Unk_5650.h): the sound system told
// whether the console plays through its speaker, the system singletons made
// from the application's heaps, and what shutting down finalises.
// Placeholder names: rename once the classes are known.
#include <cstring>
#include <memory>

#include <nn/time.h>
#include <types.h>

#include "gflib3/Unk_239a418.h"
#include "unsorted/Unk_5650.h"
#include "unsorted/Unk_d0c0.h"

namespace nn {
namespace audio {

struct AudioDeviceName {
    char name[256];
};

void GetActiveAudioDeviceName(AudioDeviceName* outName);

}  // namespace audio

}  // namespace nn

// src/gflib3/Unk_New.h (declared here: its inline body would be inlined).
struct Unk_New {
    template <class T, class... Args>
    T* Create(Unk_239a418_Allocator* allocator, Args&&... args);
};

// The singletons (src/gflib3/families/Unk_7c20.cpp): their primary base,
// laid out like Unk_239a418_Base, and the interface at +0x48.
class Unk_7c20_Base {
public:
    virtual ~Unk_7c20_Base();
    virtual void vf2();
    virtual void vf3();

    Unk_239a418_Allocator* field_8;
    u64 field_10;
    u64 field_18;
    u64 field_20;
    u64 field_28;
    u64 field_30;
    u64 field_38;
    u64 field_40;
};
static_assert(sizeof(Unk_7c20_Base) == 0x48, "Unk_7c20_Base");

class Unk_7c20_Interface {
public:
    virtual void vf2();
    virtual void vf3();
};

class Unk_236d838 : public Unk_7c20_Base, public Unk_7c20_Interface {
public:
    ~Unk_236d838() override;
    void vf3() override;
};

class Unk_239a528 : public Unk_7c20_Base, public Unk_7c20_Interface {
public:
    ~Unk_239a528() override;
    void vf3() override;
};

class Unk_239a7d0 : public Unk_7c20_Base, public Unk_7c20_Interface {
public:
    ~Unk_239a7d0() override;
    void vf3() override;
};

class Unk_23a10b8 : public Unk_7c20_Base, public Unk_7c20_Interface {
public:
    ~Unk_23a10b8() override;
    void vf3() override;
};

// What a singleton's global does with what it holds: destroys it and hands
// its allocation back to the allocator it keeps.
struct Unk_5650_Deleter {
    template <class T>
    void operator()(T* p) const {
        Unk_239a418_Allocator* allocator = p->field_8;
        u64 arg1 = p->field_10;
        u64 arg2 = p->field_18;
        u64 arg3 = p->field_20;
        p->~T();
        allocator->vf3(arg1, arg2, arg3);
    }
};

template <class T>
using Unk_5650_Unique = std::unique_ptr<T, Unk_5650_Deleter>;

extern Unk_5650_Unique<Unk_236d838> Unk_24ba100;
extern Unk_5650_Unique<Unk_239a528> Unk_24ba738;
extern Unk_5650_Unique<Unk_239a7d0> Unk_24ba728;
extern Unk_5650_Unique<Unk_23a10b8> Unk_24ba130;

// Records a singleton (up to 1024) to be destroyed at shutdown.
void Unk_5cf9c0(Unk_7c20_Interface* object);

// A heap of the application's: the allocator, where it is allocated from,
// and its block.
struct Unk_5650_Heap {
    Unk_239a418_Allocator* field_0;
    Unk_239a418_Allocator* field_8;
    void* field_10;
    u64 field_18;
};
static_assert(sizeof(Unk_5650_Heap) == 0x20, "Unk_5650_Heap");

// The application's data (what Unk_24ba560 points to): its heaps.
struct Unk_5650_Data {
    u8 _0[0x1a8];
    Unk_5650_Heap field_1a8[5];
};
PKMN_OFFSET_ASSERT(Unk_5650_Data, field_1a8, 0x1a8);

extern Unk_5650_Data* Unk_24ba560;

// The sound handle class (src/unsorted/virtual/Unk_792950.cpp).
class Unk_23a8100 {
public:
    virtual ~Unk_23a8100();
    virtual void vf2();
    virtual void vf3(u64 value, u32 arg2, f32 arg3);
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7(u64 value);
    virtual void vf8();
};

// The sound system (Unk_24ba4f0's): a handle at +0x108.
struct Unk_5650_Sound {
    u8 _0[0x108];
    Unk_23a8100 field_108;
};
PKMN_OFFSET_ASSERT(Unk_5650_Sound, field_108, 0x108);

extern Unk_5650_Sound* Unk_24ba4f0;

// The other singletons' globals, and what shuts them down.
extern void* Unk_24ba588;
extern void* Unk_24ba698;
extern void* Unk_24ba688;
extern void* Unk_24ba608;
extern void* Unk_24ba5c8;
extern void* Unk_24ba5a8;
extern void* Unk_24ba6b8;
extern void* Unk_24ba6c8;
extern void* Unk_24ba6d8;

void Unk_eadcc0(void* self);
void Unk_1306ce0_call(void* self);
void Unk_13184b0(void* self);
void Unk_791b70(void* self);
void Unk_ea2fe0(void* object);
void Unk_130e090(void* self);
void Unk_e9f980(void* self);
void Unk_e87c50(void* self);
void Unk_e88360(void* self);
void Unk_e89880(void* self);

// The base class's (Unk_239a068's) vf3 and vf8.
void Unk_5dfda0(void* self);
void Unk_5df950(void* self);

// What 0x7100005ab0 gives Unk_24ba728's object: constructed out of line,
// then filled in. Placeholder fields.
struct Unk_5e8ef0_Desc {
    Unk_5e8ef0_Desc();

    u64 field_0;
    u64 field_8;
    u64 field_10;
    u32 field_18;
    u32 field_1c;
    u32 field_20;
    u64 field_28;
    u64 field_30;
    u64 field_38;
    u64 field_40;
    u64 field_48;
    u64 field_50;
    u32 field_58;
    u8 _5c[0x14];
    u32 field_70;
    u8 _74[0x8];
    u32 field_7c;
    u8 _80[0x20];
};
PKMN_OFFSET_ASSERT(Unk_5e8ef0_Desc, field_20, 0x20);
PKMN_OFFSET_ASSERT(Unk_5e8ef0_Desc, field_58, 0x58);
PKMN_OFFSET_ASSERT(Unk_5e8ef0_Desc, field_70, 0x70);
PKMN_OFFSET_ASSERT(Unk_5e8ef0_Desc, field_7c, 0x7c);
static_assert(sizeof(Unk_5e8ef0_Desc) == 0xa0, "Unk_5e8ef0_Desc");

namespace nn {
namespace oe {
int GetPerformanceMode();
}  // namespace oe
}  // namespace nn

extern u64 Unk_236d008;
extern u64 Unk_24ba0d8;

void Unk_5e98e0(Unk_239a7d0* self, const Unk_5e8ef0_Desc* desc);
void Unk_5e3e80(Unk_239a528* self, u32 size);

// What 0x7100005d50 gives Unk_24ba130's object. Placeholder fields.
struct Unk_681320_Arg {
    u32 field_0;
    u32 field_4;
    u32 field_8;
    u32 field_c;
    u32 field_10;
};
static_assert(sizeof(Unk_681320_Arg) == 0x14, "Unk_681320_Arg");

void Unk_681320(Unk_23a10b8* self, const Unk_681320_Arg* arg);

// NON_MATCHING: ordering: the original computes the handle's address before
// it builds the name, as for a name passed as a temporary; Unk_23a8100::vf3's
// placeholder name takes it as a u64.
// 0x7100005650
void Unk_5650() {
    nn::audio::AudioDeviceName device;
    device.name[0] = '\0';
    nn::audio::GetActiveAudioDeviceName(&device);
    s32 output;
    if (strncmp(device.name, "AudioStereoJackOutput", 0x15) == 0)
        output = 0;
    else if (strncmp(device.name, "AudioTvOutput", 0xd) == 0)
        output = 1;
    else if (strncmp(device.name, "AudioUsbDeviceOutput", 0x14) == 0)
        output = 2;
    else if (strncmp(device.name, "AudioBuiltInSpeakerOutput", 0x19) == 0)
        output = 3;
    else
        return;
    static const s32 kHandDockMode[] = {0, 0, 0, 1};
    Unk_5650_Sound* sound = Unk_24ba4f0;
    Unk_5cfaf0_Name name("HandDockMode");
    f32 value = kHandDockMode[output];
    sound->field_108.vf3(reinterpret_cast<u64>(&name), 0, value);
}

// 0x7100005840
void Unk_5840() {
    for (s32 i = 4; i >= 0; --i) {
        Unk_5650_Heap& heap = Unk_24ba560->field_1a8[i];
        heap.field_0->vf0();
        heap.field_0 = nullptr;
        heap.field_8->vf3(reinterpret_cast<u64>(heap.field_10), heap.field_18, 8);
        heap.field_10 = nullptr;
        heap.field_18 = 0;
        heap.field_8 = nullptr;
    }
}

// 0x7100005770
void Unk_5770(Unk_236d258_Self* self) {
    Unk_eadcc0(Unk_24ba588);
    Unk_1306ce0_call(Unk_24ba698);
    Unk_13184b0(Unk_24ba688);
    Unk_791b70(Unk_24ba4f0);
    Unk_ea2fe0(Unk_24ba608);
    Unk_130e090(Unk_24ba5c8);
    Unk_e9f980(Unk_24ba5a8);
    Unk_e87c50(Unk_24ba6b8);
    Unk_e88360(Unk_24ba6c8);
    Unk_e89880(Unk_24ba6d8);
    Unk_5df950(self);
    Unk_5840();
    nn::time::Finalize();
}

// 0x71000059c0
void Unk_59c0(Unk_236d258_Self* self) {
    for (s32 i = 0; i < 12; ++i) {
        if (!nn::os::TryWaitSystemEvent(&self->field_1050))
            return;
        Unk_5650();
    }
}

// 0x7100005990
void Unk_5990(Unk_236d258_Self* self) {
    Unk_59c0(self);
    Unk_5dfda0(self);
}

// 0x7100005ab0
void Unk_5ab0(Unk_236d258_Self* self) {
    Unk_24ba728.reset(Unk_New().Create<Unk_239a7d0>(Unk_24ba560->field_1a8[0].field_0));
    Unk_5cf9c0(Unk_24ba728.get());
    Unk_5e8ef0_Desc desc;
    desc.field_58 = 0x3000;
    desc.field_30 = 0x3000000;
    desc.field_50 = 0xa000;
    desc.field_40 = 0x500000;
    desc.field_28 = 0xc00000;
    desc.field_38 = Unk_24ba0d8 + 0x2000000;
    desc.field_0 = Unk_236d008 + 0xbe00000;
    desc.field_8 = 0x2200000000;
    desc.field_10 = 0x13900000;
    desc.field_18 = 1;
    desc.field_1c = 0xa1;
    desc.field_20 = nn::oe::GetPerformanceMode() == 1;
    desc.field_70 = 0xb06;
    desc.field_7c = 0xb06;
    Unk_5e98e0(Unk_24ba728.get(), &desc);
}

// 0x7100005c00
void Unk_5c00(Unk_236d258_Self* self) {
    Unk_24ba100.reset(Unk_New().Create<Unk_236d838>(Unk_24ba560->field_1a8[1].field_0));
    Unk_5cf9c0(Unk_24ba100.get());
}

// 0x7100005ca0
void Unk_5ca0(Unk_236d258_Self* self) {
    Unk_24ba738.reset(Unk_New().Create<Unk_239a528>(Unk_24ba560->field_1a8[2].field_0));
    Unk_5cf9c0(Unk_24ba738.get());
    Unk_5e3e80(Unk_24ba738.get(), 0x10000);
}

// 0x7100005d50
void Unk_5d50(Unk_236d258_Self* self) {
    Unk_24ba130.reset(Unk_New().Create<Unk_23a10b8>(Unk_24ba560->field_1a8[3].field_0));
    Unk_5cf9c0(Unk_24ba130.get());
    Unk_681320_Arg arg;
    arg.field_0 = 1;
    arg.field_4 = 0x20;
    arg.field_8 = 8;
    arg.field_c = 0x80;
    arg.field_10 = 4;
    Unk_681320(Unk_24ba130.get(), &arg);
}
