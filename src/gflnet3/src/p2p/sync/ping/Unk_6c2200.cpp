// Scope: common
//
// What gflnet3's sync ping thread is handed (Unk_6c2200.h): its two
// implementations and the functions that compare them. Part of the segment
// 0x71006c1c70-0x71006c2920. Placeholder names: rename once the classes are
// known.
#include "gflnet3/src/p2p/sync/ping/Unk_6c2200.h"

#include <cstring>

// NON_MATCHING: the original reads the id and the flag a byte at a time
// (byte 2, the low 4 bits of byte 3, bit 0 of byte 4: the bit reader of the
// serialiser that writes them, 0x71006c1ce0, not recovered) and inserts them
// into the result with bfi; this loads them as one 32-bit word.
// 0x71006c2200
Unk_6c2200_Header Unk_6c2200(const Unk_23a3d58_Base& data) {
    const Unk_6c2200_Header* header = reinterpret_cast<const Unk_6c2200_Header*>(data.vf2());
    if (header == nullptr)
        return {};
    Unk_6c2200_Header result;
    result.field_0 = header->field_0;
    result.field_2 = header->field_2;
    result.field_4 = header->field_4;
    return result;
}

// 0x71006c2250
bool Unk_6c2250(const Unk_23a3d58_Base& a, const Unk_23a3d58_Base& b) {
    return std::memcmp(a.vf2(), b.vf2(), sizeof(Unk_23a3d58::field_8)) == 0 && a.vf3() == b.vf3();
}

// 0x71006c2350
bool Unk_6c2350(const Unk_23a3d58_Base& a, const Unk_23a3d58_Base& b) {
    return !Unk_6c2250(a, b);
}

// 0x71006c2700
Unk_23a3d58::Unk_23a3d58(const Unk_23a3d58_Base& other) {
    std::memcpy(field_8, other.vf2(), sizeof(field_8));
    field_170 = other.vf3();
}

// 0x71006c26e0 (and the deleting one, 0x71006c2870)
Unk_23a3d58::~Unk_23a3d58() {}

// 0x71006c27d0 is in src/unsorted/virtual/Unk_6c27d0.cpp.

// 0x71006c27e0
Unk_23a3d58_OptionalValue Unk_23a3d58::vf3() const {
    return field_170;
}

// 0x71006c2810
Unk_23a3d88::Unk_23a3d88(const u8* data, const Unk_23a3d58_OptionalValue& value)
    : field_8(data), field_10(value) {}

// 0x71006c2850
Unk_23a3d58_OptionalValue Unk_23a3d88::vf3() const {
    return field_10;
}

// 0x71006c2890 (and the deleting one, 0x71006c28b0)
Unk_23a3d88::~Unk_23a3d88() {}

// The gflnet3 object with a thread (Unk_6c2a10.h), which knows the id.
class Unk_23a3db8 {
public:
    const Unk_6c2450_Id& Unk_6c2b60();
};

// What holds it: its destructor is src/unsorted/leaf/Unk_6c2920.cpp's
// Unk_6c2920_call, reached without the GOT (it's in this TU).
struct Unk_6c2920 {
    Unk_23a3db8* field_0;
};
void Unk_6c2920_call(Unk_6c2920* self) __attribute__((visibility("hidden")));

// The holder, an inline variable or a template's static member: each TU that
// uses it registers its destructor, once, under the guard after it.
extern Unk_6c2920 Unk_27790f0;
extern u64 Unk_27790f8;

// The id when there's no object (all ones: src/unsorted/leaf/Unk_6c2920.cpp's
// Unk_6c2980_call sets it).
extern Unk_6c2450_Id Unk_27790e8;

// A flag 0x71006aed90 reads from the object at Unk_24ba170, when there's one.
extern u64 Unk_24ba170;
bool Unk_6aed90(u64 object);

// The checksum of the data after it.
u16 Unk_65c700(u64 data, u64 size);

// Writes the id (0x71006c1ce0), a bit at a time.
void Unk_6c1ce0(const Unk_6c2450_Id& id, Unk_6c2450_Context* context);

// Writes the flags.
static void Unk_6c2450_Write(const Unk_6c2450_Flags& flags, Unk_6c2450_Context* context) {
    if (context == nullptr || context->m_data == nullptr || context->m_size * 8 < 1)
        return;
    if (flags.field_0)
        context->m_data[0] |= 1;
    context->Mark(0);
}

// Writes the checksum, the first field.
static void Unk_6c2450_WriteChecksum(Unk_6c2450_Context& context, u16 checksum) {
    if (context.m_data != nullptr) {
        *reinterpret_cast<u16*>(context.m_data) = checksum;
        context.Mark(0);
    }
}

static u16 Unk_6c2450_Checksum(const Unk_23a3d58_Base& data) {
    return Unk_65c700(reinterpret_cast<u64>(data.vf2() + 2), sizeof(Unk_23a3d58::field_8) - 2);
}

// NON_MATCHING: the same instructions, but laid out differently: the original
// keeps marking the payload written in line (here it's moved after the
// function's end), and orders the id context's stores and its flag otherwise.
// 0x71006c2450: makes what the thread is handed: the checksum, the id, the
// flags and the payload.
Unk_23a3d58 Unk_6c2450(const void* data, const void* size) {
    Unk_23a3d58 result;
    Unk_6c2450_Context context(result.field_8, sizeof(result.field_8));
    Unk_23a3db8* object = Unk_27790f0.field_0;

    Unk_6c2450_Id id = object != nullptr ? object->Unk_6c2b60() : Unk_27790e8;
    Unk_6c2200_Optional<Unk_6c2450_Context> idContext = context.Field(2, 2, 1);
    Unk_6c1ce0(id, idContext ? &idContext.m_value : nullptr);

    Unk_6c2450_Flags flags;
    flags.field_0 = Unk_24ba170 != 0 && Unk_6aed90(Unk_24ba170);
    Unk_6c2200_Optional<Unk_6c2450_Context> flagsContext = context.Field(4, 1, 5);
    Unk_6c2450_Write(flags, flagsContext ? &flagsContext.m_value : nullptr);

    u8* payload = context.Bytes(5, sizeof(result.field_8) - 5, 6);
    u64 length = *static_cast<const u64*>(size);
    if (data != nullptr && payload != nullptr && length <= sizeof(result.field_8) - 5 &&
        Unk_27790f0.field_0 != nullptr) {
        std::memcpy(payload, data, length);
        Unk_6c2450_WriteChecksum(context, Unk_6c2450_Checksum(result));
    } else {
        Unk_6c2450_WriteChecksum(context, 0xffff);
    }
    return result;
}

extern "C" int __cxa_atexit(void (*function)(void*), void* object, void* dso);
extern "C" void* __dso_handle __attribute__((visibility("hidden")));

// 0x71006c28d0: the TU's static initialiser, as a function.
void Unk_6c28d0_init() {
    if (!(Unk_27790f8 & 1)) {
        __cxa_atexit(reinterpret_cast<void (*)(void*)>(Unk_6c2920_call), &Unk_27790f0,
                     &__dso_handle);
        Unk_27790f8 = 1;
    }
}
