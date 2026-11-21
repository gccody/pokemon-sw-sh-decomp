// Scope: common
// Wwise's Opus decoding thread (Unk_237e948.h). Placeholder names.
#include "Unk_237e948.h"

#include "Unk_Thread.h"
#include "containers.h"

// The pool the decoders are allocated from.
extern int Unk_2381488;
u32 Unk_304740(int poolId, void* ptr);

// The largest work buffer a decoder needs, for one and for two channels.
extern u64 Unk_24bc840[2];

// 0x7100333a30
void Unk_237e948_Item::Unk_333a30() {
    if (field_0 != nullptr) {
        if (field_0->vf3())
            field_0->vf5();
        nn::codec::HardwareOpusDecoder* decoder = field_0;
        if (decoder != nullptr) {
            int pool = Unk_2381488;
            decoder->~HardwareOpusDecoder();
            Unk_3047c0(pool, decoder);
        }
        field_0 = nullptr;
    }
    if (field_8 != nullptr) {
        Unk_304740(Unk_2381488, field_8);
        field_8 = nullptr;
    }
    if (field_18 != nullptr) {
        Unk_3047c0(Unk_2381488, field_18);
        field_18 = nullptr;
    }
    Unk_237e948_Out* buffer = field_30;
    field_28 = 0;
    if (buffer != nullptr) {
        Unk_3047c0(Unk_2381488, buffer);
        field_30 = nullptr;
    }
    field_40 = 0;
}

// NON_MATCHING: the vtable's address is loaded after the first store (3 instructions swapped)
// 0x7100333b10
Unk_237e948::Unk_237e948() : field_a20(nullptr), field_a28(0) {
    for (int i = 0; i < 24; i++)
        field_8[i] = 0;
}

// 0x71003340a0
u32 Unk_237e948::Unk_3340a0() {
    if (Unk_24bc840[0] == 0) {
        nn::codec::HardwareOpusDecoder* decoder =
            new (Unk_2381488) nn::codec::HardwareOpusDecoder(0);
        if (decoder == nullptr)
            return 2;
        u64 size = decoder->vf2(8000, 1);
        u64 s = decoder->vf2(12000, 1);
        size = s > size ? s : size;
        s = decoder->vf2(16000, 1);
        size = s > size ? s : size;
        s = decoder->vf2(24000, 1);
        size = s > size ? s : size;
        s = decoder->vf2(48000, 1);
        size = s > size ? s : size;
        Unk_24bc840[0] = size;
        size = decoder->vf2(8000, 2);
        s = decoder->vf2(12000, 2);
        size = s > size ? s : size;
        s = decoder->vf2(16000, 2);
        size = s > size ? s : size;
        s = decoder->vf2(24000, 2);
        size = s > size ? s : size;
        s = decoder->vf2(48000, 2);
        size = s > size ? s : size;
        Unk_24bc840[1] = size;
        int pool = Unk_2381488;
        decoder->~HardwareOpusDecoder();
        Unk_3047c0(pool, decoder);
    }
    return Unk_3342b0();
}

// 0x71003342b0
u32 Unk_237e948::Unk_3342b0() {
    if (field_8a0 != 0)
        return 2;
    field_a58 = false;
    nn::os::InitializeEvent(Event(), false, static_cast<nn::os::EventClearMode>(1));
    field_a20 = Unk_673320(Unk_24bcb80.field_60.field_8, 0x1000);
    field_a28 = Unk_24bcb80.field_60.field_8;
    nn::os::CreateThread(Thread(), Unk_334720, this, field_a20, field_a28, Unk_24bcb80.field_60.field_0);
    nn::os::SetThreadName(Thread(), "AK::OpusDecodingThread");
    nn::os::SetThreadCoreMask(Thread(), Unk_24bcb80.field_60.field_10, Unk_24bcb80.field_60.field_18);
    nn::os::StartThread(Thread());
    return field_8a0 != 0 ? 1 : 2;
}

// 0x7100334390
void Unk_237e948::Unk_334390() {
    vf0();
    for (u32 i = 0; i < 24; i++) {
        if (field_8[i] == 2) {
            field_20[i].Unk_333a30();
            field_8[i] = 0;
        }
    }
}

// The thread's loop: serves every slot, and sleeps when none had work.
inline void Unk_237e948::Run() {
    nn::os::WaitEvent(Event());
    while (!field_a58) {
        bool busy;
        do {
            busy = false;
            for (u32 i = 0; i < 24; i++) {
                if (field_8[i] == 1) {
                    busy |= field_20[i].Unk_334860();
                } else if (field_8[i] == 2) {
                    field_20[i].Unk_333a30();
                    field_8[i] = 0;
                }
            }
        } while (busy);
        nn::os::WaitEvent(Event());
    }
}

// 0x7100334720
void Unk_237e948::Unk_334720(void* arg) {
    static_cast<Unk_237e948*>(arg)->Run();
}

// 0x71003347f0
void Unk_237e948::vf0() {
    field_a58 = true;
    if (field_8a0 != 0) {
        nn::os::SignalEvent(Event());
        nn::os::WaitThread(Thread());
        nn::os::DestroyThread(Thread());
        Unk_6733a0(reinterpret_cast<u64>(field_a20));
        field_a20 = nullptr;
    }
    if (field_a30[0x13] == 1)
        nn::os::FinalizeEvent(Event());
}

// 0x7100334860
bool Unk_237e948_Item::Unk_334860() {
    if (field_24 == 0 || static_cast<u32>(field_3c) >= field_40)
        return false;
    Unk_237e948_In* in = &field_18[field_22];
    Unk_237e948_Out* out = &field_30[field_38];
    int result = 0;
    if (in->field_5ec) {
        if (field_0->vf3())
            field_0->vf5();
        result = field_0->vf4(field_48.field_0, field_48.field_4, field_8, field_10);
    }
    if (result == 0) {
        size_t consumed;
        int sampleCount;
        result = field_0->vf9(&consumed, &sampleCount, out->field_0,
                              sizeof(s16) * (field_48.field_8 * field_48.field_4), in,
                              in->field_5e4);
        if (result == 0) {
            if (in->field_5e8 < static_cast<u32>(field_48.field_8)) {
                out->field_f00 = sampleCount;
                out->field_f04 = in->field_5e8;
                field_38 = (field_38 + 1) % field_40;
                __sync_fetch_and_add(&field_3c, 1);
            }
            field_22 = (field_22 + 1) % field_28;
            __sync_fetch_and_sub(&field_24, 1);
            return true;
        }
    }
    field_48.field_c = true;
    return false;
}

// The decoding thread.
Unk_237e948 Unk_24bbde0;
