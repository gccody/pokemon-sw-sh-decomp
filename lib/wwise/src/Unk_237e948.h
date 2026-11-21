#pragma once
// Wwise's Opus decoding thread ("AK::OpusDecodingThread"): 24 decoder slots
// served by one thread that drives the SDK's hardware Opus decoder.
// Placeholder names.
#include <nn/os.h>
#include <types.h>
#include "Unk_Thread.h"

namespace nn::codec {
class HardwareOpusDecoder {
public:
    explicit HardwareOpusDecoder(int option);
    virtual ~HardwareOpusDecoder();
    virtual size_t vf2(int sampleRate, int channelCount);
    virtual bool vf3();
    virtual int vf4(int sampleRate, int channelCount, void* buffer, size_t size);
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual int vf9(size_t* consumed, int* sampleCount, s16* output, size_t outputSize,
                    const void* input, size_t inputSize);

    u8 _8[0x38];
};
}  // namespace nn::codec

// A packet for a slot's decoder.
struct Unk_237e948_In {
    u8 field_0[0x5e4];
    u32 field_5e4;  // size
    u32 field_5e8;
    bool field_5ec;  // restart the decoder first
};
PKMN_SIZE_ASSERT(Unk_237e948_In, 0x5f0);

// What a packet decodes to.
struct Unk_237e948_Out {
    s16 field_0[0x780];
    s32 field_f00;  // number of samples
    u32 field_f04;
};
PKMN_SIZE_ASSERT(Unk_237e948_Out, 0xf08);

// What a slot decodes: 13 bytes.
struct Unk_237e948_Format {
    s32 field_0;  // sample rate
    s32 field_4;  // channels
    s32 field_8;  // samples in a packet
    bool field_c;  // the decoder failed
} __attribute__((packed));
PKMN_SIZE_ASSERT(Unk_237e948_Format, 13);

// 0x58 bytes: one decoder slot. The thread and its clients share the
// volatile fields.
struct Unk_237e948_Item {
    Unk_237e948_Item()
        : field_0(nullptr), field_8(nullptr), field_10(0), field_18(nullptr), field_20(0),
          field_22(0), field_24(0), field_28(0), field_30(nullptr), field_38(0), field_3a(0),
          field_3c(0), field_40(0), field_48() {}

    void Unk_333a30();
    bool Unk_334860();

    nn::codec::HardwareOpusDecoder* field_0;
    void* field_8;  // the decoder's work buffer
    u64 field_10;  // and its size
    Unk_237e948_In* field_18;  // packets to decode: a ring of field_28
    u16 field_20;
    u16 field_22;  // the next one to decode
    volatile s32 field_24;  // how many are waiting
    volatile u32 field_28;
    Unk_237e948_Out* volatile field_30;  // decoded packets: a ring of field_40
    u16 field_38;  // the next one to fill
    u16 field_3a;
    volatile s32 field_3c;  // how many are filled
    volatile u32 field_40;
    u32 field_44;
    Unk_237e948_Format field_48;
};
PKMN_SIZE_ASSERT(Unk_237e948_Item, 0x58);
PKMN_OFFSET_ASSERT(Unk_237e948_Item, field_48, 0x48);

class Unk_237e948 {
public:
    Unk_237e948();
    virtual void vf0();

    u32 Unk_3340a0();
    u32 Unk_3342b0();
    void Unk_334390();
    static void Unk_334720(void* arg);
    void Run();

    volatile u8 field_8[24];  // the slots' states
    Unk_237e948_Item field_20[24];
    u8 field_860[0x40];  // nn::os::ThreadType, 0x1c0 bytes
    u8 field_8a0;  // its state
    u8 _8a1[0x17f];
    void* field_a20;  // the thread's stack
    u32 field_a28;  // and its size
    alignas(8) u8 field_a30[0x28];  // nn::os::EventType
    volatile bool field_a58;  // set to stop the thread

    nn::os::EventType* Event() { return reinterpret_cast<nn::os::EventType*>(field_a30); }
    nn::os::ThreadType* Thread() { return reinterpret_cast<nn::os::ThreadType*>(field_860); }
};
PKMN_OFFSET_ASSERT(Unk_237e948, field_20, 0x20);
PKMN_OFFSET_ASSERT(Unk_237e948, field_860, 0x860);
PKMN_OFFSET_ASSERT(Unk_237e948, field_a20, 0xa20);
PKMN_OFFSET_ASSERT(Unk_237e948, field_a58, 0xa58);
