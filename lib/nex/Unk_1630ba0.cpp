// Scope: common
// NEX 4.6.8: OnlineCore's result descriptions and error codes, its sleep,
// time and error report, its Log (RTTI: N2nn3nex3LogE, its TraceLog
// N2nn3nex8TraceLogE) and LockChecker (N2nn3nex11LockCheckerE); then a stream
// read, and the jobs that process a protocol's events and
// messages (RTTI: N2nn3nex23JobProcessProtocolEventE,
// N2nn3nex25JobProcessProtocolMessageE, both derived from N2nn3nex3JobE). A
// message job holds a CallProtocolMethodOperation (N2nn3nex27CallProtocolMethodOperationE,
// derived from N2nn3nex9OperationE) and a reference to a reference-counted object.
#include <stdarg.h>
#include <string.h>

#include <atomic>

#include <nn/err.h>
#include <nn/nex/ByteStream.h>
#include <nn/nex/Call.h>
#include <nn/nex/RefCountedObject.h>
#include <nn/nex/SharedPtr.h>

#include "Unk_1630ba0.h"

// 0x71015b8f50: the system tick (a wrapper of the SDK's, lib/nex/Unk_15b8f50.cpp).
u64 Unk_15b8f50();

// 0x71015d90b0, 0x71015d78a0: what a protocol job takes and gives back when
// it starts and ends (the object's slots 11 and 16 with itself).
struct Unk_15d90b0;
struct Unk_15d78a0;
void Unk_15d90b0_call(Unk_15d90b0* self);
void Unk_15d78a0_call(Unk_15d78a0* self);

// 0x71015ce0f0: sets a job's state (5: done, which calls its callback).
void Unk_15ce0f0(u64 job, u32 state);

// 0x71015bbbe0: a failure.
void Unk_15bbbe0(Unk_15bbc10* self);

// A flag the protocol jobs check before they take or give back their object.
extern bool Unk_27f9808;

// 0x71015ce860, 0x71015bbd10 (lib/nx_middleware/leaf)
struct Unk_15ce860 {
    u8 _0[0x38];
};
PKMN_SIZE_ASSERT(Unk_15ce860, 0x38);
struct Unk_15bbd10;
struct Unk_15bbd10_arg1 {
    u32 field_0;
    u64 field_8;
    u32 field_10;
};
PKMN_SIZE_ASSERT(Unk_15bbd10_arg1, 0x18);
u64 Unk_15ce860_get(const Unk_15ce860* self);
void Unk_15bbd10_set(Unk_15bbd10* self, Unk_15bbd10_arg1 value);

// A result code as a case label (the codes are signed: NEX compares them so).
#define UNK_CODE(code) static_cast<s32>(code)

// 0x71015b8a50: a result code's description number (-1: none).
s32 Unk_15b8a50(s32 code) {
    s32 description = -1;
    switch (code) {
    case UNK_CODE(0xe0000000):
        description = 0x386;
        break;
    case UNK_CODE(0xe0000001):
        description = 0x387;
        break;
    case UNK_CODE(0xe0000002):
        description = 0x388;
        break;
    case UNK_CODE(0xe0000003):
        description = 0x389;
        break;
    case UNK_CODE(0xe0000008):
        description = 0x38e;
        break;
    case UNK_CODE(0xe0000009):
        description = 0x38f;
        break;
    case UNK_CODE(0xe000000c):
        description = 0x392;
        break;
    case UNK_CODE(0xe000000e):
        description = 0x394;
        break;
    case UNK_CODE(0xe000000f):
        description = 0x395;
        break;
    case UNK_CODE(0xe0000010):
        description = 0x396;
        break;
    case UNK_CODE(0xe0000011):
        description = 0x397;
        break;
    case UNK_CODE(0xe0000012):
        description = 0x398;
        break;
    case UNK_CODE(0xe0000013):
        description = 0x399;
        break;
    case UNK_CODE(0xe0000014):
        description = 0x39a;
        break;
    case UNK_CODE(0xe0000015):
        description = 0x39b;
        break;
    case UNK_CODE(0xe0000016):
        description = 0x39c;
        break;
    case UNK_CODE(0xe0000017):
        description = 0x39d;
        break;
    case UNK_CODE(0xe0000018):
        description = 0x39e;
        break;
    case UNK_CODE(0xe0000019):
        description = 0x39f;
        break;
    case UNK_CODE(0xe000001a):
        description = 0x3a0;
        break;
    case UNK_CODE(0xe000001b):
        description = 0x3a1;
        break;
    case UNK_CODE(0xe000001c):
        description = 0x3a2;
        break;
    case UNK_CODE(0xe0010000):
        description = 0x3b7;
        break;
    case UNK_CODE(0xe0010001):
        description = 0x3b8;
        break;
    case UNK_CODE(0xe0010002):
        description = 0x3b9;
        break;
    case UNK_CODE(0xe0010005):
        description = 0x3bc;
        break;
    case UNK_CODE(0xe0010006):
        description = 0x3bd;
        break;
    case UNK_CODE(0xe0010007):
        description = 0x3be;
        break;
    case UNK_CODE(0xe0010008):
        description = 0x3bf;
        break;
    case UNK_CODE(0xe0010009):
        description = 0x3c0;
        break;
    case UNK_CODE(0xe001000a):
        description = 0x3c1;
        break;
    case UNK_CODE(0xe001000b):
        description = 0x3c2;
        break;
    case UNK_CODE(0xe001000c):
        description = 0x3c3;
        break;
    case UNK_CODE(0xe001000d):
        description = 0x3c4;
        break;
    case UNK_CODE(0xe001000e):
        description = 0x3c5;
        break;
    case UNK_CODE(0xe0010010):
        description = 0x3c7;
        break;
    case UNK_CODE(0xe0010011):
        description = 0x3c8;
        break;
    case UNK_CODE(0xe0010012):
        description = 0x3c9;
        break;
    case UNK_CODE(0xe0010013):
        description = 0x3ca;
        break;
    case UNK_CODE(0x60010014):
        description = 0x3cb;
        break;
    case UNK_CODE(0xe0100000):
        description = 0x385;
        break;
    case UNK_CODE(0xe0010015):
        description = 0x3cc;
        break;
    case UNK_CODE(0xe0010016):
        description = 0x3cd;
        break;
    case UNK_CODE(0xe0010017):
        description = 0x3ce;
        break;
    case UNK_CODE(0xe0010018):
        description = 0x3cf;
        break;
    case UNK_CODE(0xe0010019):
        description = 0x3d0;
        break;
    case UNK_CODE(0xa0000004):
        description = 0x38a;
        break;
    case UNK_CODE(0xa0000005):
        description = 0x38b;
        break;
    case UNK_CODE(0xa0000006):
        description = 0x38c;
        break;
    case UNK_CODE(0xa0000007):
        description = 0x38d;
        break;
    case UNK_CODE(0xa000000a):
        description = 0x390;
        break;
    case UNK_CODE(0xa000000b):
        description = 0x391;
        break;
    case UNK_CODE(0xa000000d):
        description = 0x393;
        break;
    case UNK_CODE(0xa000001d):
        description = 0x3a3;
        break;
    case UNK_CODE(0xa0010003):
        description = 0x3ba;
        break;
    case UNK_CODE(0xa0010004):
        description = 0x3bb;
        break;
    case UNK_CODE(0xa001000f):
        description = 0x3c6;
        break;
    case UNK_CODE(0xa001001b):
        description = 0x3d2;
        break;
    }
    return description;
}
#undef UNK_CODE

// 0x71015b87f0: the result's description.
int Unk_15b87f0(const Unk_15bbc10* self);

// 0x71015b8cf0: the result as an error code (2306-xxxx, or 2307-xxxx for
// module 0x72).
nn::err::ErrorCode Unk_15b8cf0(const Unk_15bbc10* self) {
    int description = Unk_15b87f0(self);
    u32 value;
    if (description == 0) {
        value = 0;
    } else if (description < 0) {
        value = 23060000;
    } else {
        value = ((self->m_code & 0x7ff0000) == 0x720000 ? 23070000 : 23060000) + description;
    }
    nn::err::ErrorCode errorCode = {value / 10000, value % 10000};
    return errorCode;
}

// A time (a copy constructor of its own: returned through memory), as in
// lib/nex/include/nn/nex/Unk_15bbcf0.cpp.
struct Unk_244f0b0_Time {
    Unk_244f0b0_Time() : m_value(0) {}
    Unk_244f0b0_Time(const Unk_244f0b0_Time& other) : m_value(other.m_value) {}

    u64 m_value;
};
// 0x71015bde80
Unk_244f0b0_Time Unk_15bde80(u32 arg);
// 0x71015be030
Unk_244f0b0_Time Unk_15be030();
extern bool Unk_244f0f0;
extern Unk_244f0b0_Time Unk_27f3570;  // the last time read

// 0x71015b8d60: the time (and records it as the last one read).
Unk_244f0b0_Time Unk_15b8d60() {
    Unk_244f0b0_Time time = Unk_244f0f0 ? Unk_15bde80(0) : Unk_15be030();
    Unk_27f3570 = time;
    return time;
}

// 0x71015be1a0
void Unk_15be1a0(void* list, const u32* value);
// Where errors are reported.
struct Unk_27f35d8_t {
    u8 _0[0x38];
    u8 m_codes[0x80];
    u8 m_args[0x10];
};
PKMN_OFFSET_ASSERT(Unk_27f35d8_t, m_args, 0xb8);
extern Unk_27f35d8_t* Unk_27f35d8;

// 0x71015b8dc0: reports an error (the source file and line aren't used).
void Unk_15b8dc0(const char* file, u32 line, u32 code, u32 arg) {
    Unk_15be1a0(Unk_27f35d8->m_codes, &code);
    Unk_15be1a0(Unk_27f35d8->m_args, &arg);
}

// 0x71015b8e10: sleeps `ms` milliseconds (0: yields).
void Unk_15b8e10(u32 ms) {
    if (ms != 0) {
        nn::TimeSpan time = {static_cast<s64>(static_cast<u64>(ms) * 1000000)};
        nn::os::SleepThread(time);
    } else {
        nn::os::YieldThread();
    }
}

// 0x7101630ba0: a 32-bit value from the stream (zero, and the stream's error
// flag, when there isn't enough left).
u32 Unk_1630ba0(nn::nex::ByteStream* stream) {
    u32 value;
    nn::nex::ReadField(stream, value);
    return value;
}

struct Unk_1630bf0_58 {
    u8 _0[0x50];
    Unk_15ce860 field_50;
};
PKMN_OFFSET_ASSERT(Unk_1630bf0_58, field_50, 0x50);

struct Unk_1630bf0 {
    u8 _0[0x58];
    Unk_1630bf0_58* field_58;
};
PKMN_OFFSET_ASSERT(Unk_1630bf0, field_58, 0x58);

// 0x7101630bf0
void Unk_1630bf0(Unk_1630bf0* self, const Unk_15bbd10_arg1& value) {
    u64 target = Unk_15ce860_get(&self->field_58->field_50);
    Unk_15bbd10_set(reinterpret_cast<Unk_15bbd10*>(target + 0x40), value);
}

// What the Job constructor takes by value after the job's type: an empty
// object, passed by address because it isn't trivially destroyed.
struct Unk_15c5880_arg {
    ~Unk_15c5880_arg() {}
};

namespace nn {
namespace nex {

// N2nn3nex3JobE
class Job : public RefCountedObject {
public:
    // 0x71015c5880
    Job(u32 type, Unk_15c5880_arg arg);
    // 0x71015d46a0
    ~Job() override;
    virtual void vf2();
    virtual void vf3() = 0;
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();

    // 0x71015c5ee0: ends the job (state 5).
    void Unk_15c5ee0();

    u8 _10[0x34];
    u32 field_44;
    u8 _48[0x20];
};
PKMN_OFFSET_ASSERT(Job, field_44, 0x44);
PKMN_SIZE_ASSERT(Job, 0x68);

// N2nn3nex9OperationE
class Operation : public RootObject {
public:
    // 0x71015ce690
    Operation(u32 type);

    u8 _8[0x18];
};
PKMN_SIZE_ASSERT(Operation, 0x20);

// N2nn3nex27CallProtocolMethodOperationE
class CallProtocolMethodOperation : public Operation {
public:
    CallProtocolMethodOperation() : Operation(0), field_30(0) {
        Unk_15bbbe0(&m_result);
        field_20 = 0;
        field_28 = false;
        field_38 = 0;
    }
    virtual void vf2();
    virtual u32 vf3();
    virtual const char* vf4();
    virtual void vf5();

    u64 field_20;
    bool field_28;
    u8 _29[0x7];
    u32 field_30;
    u8 _34[0x4];
    u32 field_38;
    union {
        Unk_15bbc10 m_result;
    };
};
PKMN_OFFSET_ASSERT(CallProtocolMethodOperation, field_30, 0x30);
PKMN_OFFSET_ASSERT(CallProtocolMethodOperation, m_result, 0x40);
PKMN_SIZE_ASSERT(CallProtocolMethodOperation, 0x58);

// What a message job processes the message with (its slot 2).
class Unk_1630d30_68 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2(CallProtocolMethodOperation* operation, void* object, void* message);
};

// The reference-counted object a message job holds (a RefCountedObject's
// count and the flag set when it's deleted).
class Unk_1630d30_e0 : public RootObject {
public:
    std::atomic<s32> m_count;
    bool m_deleting;
};
PKMN_OFFSET_ASSERT(Unk_1630d30_e0, m_deleting, 0xc);

// N2nn3nex23JobProcessProtocolEventE
class JobProcessProtocolEvent : public Job {
public:
    JobProcessProtocolEvent(Unk_1630d30_68* handler, void* object)
        : Job(2, Unk_15c5880_arg()), field_68(handler), field_70(object) {
        field_80 = 0;
        if (!Unk_27f9808) {
            Unk_15d90b0_call(static_cast<Unk_15d90b0*>(object));
            u64 tick = Unk_15b8f50() * 1000000;
            field_78 = tick / nn::os::GetSystemTickFrequency();
        }
    }
    ~JobProcessProtocolEvent() override;
    virtual void vf12();

    Unk_1630d30_68* field_68;
    void* field_70;
    u64 field_78;
    u64 field_80;
};
PKMN_SIZE_ASSERT(JobProcessProtocolEvent, 0x88);

// N2nn3nex25JobProcessProtocolMessageE
class JobProcessProtocolMessage : public JobProcessProtocolEvent {
public:
    JobProcessProtocolMessage(Unk_1630d30_68* handler, void* object, Unk_1630d30_e0* message);
    ~JobProcessProtocolMessage() override;
    void vf3() override;
    void vf12() override;

    CallProtocolMethodOperation m_operation;
    Unk_1630d30_e0* m_message;
};
PKMN_OFFSET_ASSERT(JobProcessProtocolMessage, m_message, 0xe0);

// 0x7101630cc0 (D2), 0x7101630d20 (D0: a trap, the class is abstract)
JobProcessProtocolEvent::~JobProcessProtocolEvent() {
    if (!Unk_27f9808) {
        Unk_15d78a0_call(static_cast<Unk_15d78a0*>(field_70));
    }
}

// 0x7101630d30
JobProcessProtocolMessage::JobProcessProtocolMessage(Unk_1630d30_68* handler, void* object,
                                                     Unk_1630d30_e0* message)
    : JobProcessProtocolEvent(handler, object), m_message(message) {
    s32 count = message->m_count.load();
    while (!message->m_count.compare_exchange_weak(count, count + 1)) {
    }
}

// 0x7101630e80 (D2), 0x7101630f80 (D0)
JobProcessProtocolMessage::~JobProcessProtocolMessage() {
    Unk_1630d30_e0* message = m_message;
    if (Decrement(message->m_count) == 0 && !message->m_deleting) {
        message->m_deleting = true;
        delete message;
    }
}

// 0x7101631080
void JobProcessProtocolMessage::vf3() {
    field_68->vf2(&m_operation, field_70, m_message);
    if (m_operation.field_28) {
        u32 result = m_operation.field_38;
        Unk_15ce0f0(reinterpret_cast<u64>(this), 1);
        field_44 = result;
    } else {
        Unk_15c5ee0();
    }
}

// N2nn3nex19EncryptionAlgorithmE
class EncryptionAlgorithm : public PluginObject {
public:
    // 0x71015c6bc0: takes the key if its length is in the algorithm's range.
    bool Unk_15c6bc0(const Key& key);

    virtual u32 vf2(const Buffer& in, Buffer* out) = 0;
    virtual void vf3(Buffer* buffer);
    virtual u32 vf4(const Buffer& in, Buffer* out) = 0;

    u64 field_8;
    Key m_key;
    u64 m_minKeyLength;
    u64 m_maxKeyLength;
};
PKMN_SIZE_ASSERT(EncryptionAlgorithm, 0x48);

// N2nn3nex13RC4EncryptionE
class RC4Encryption : public EncryptionAlgorithm {
public:
    // 0x71015c6e50
    RC4Encryption();
    // 0x71015c6f50
    ~RC4Encryption() override;
    // 0x71015c7210: copies `in` to `out` and encrypts it there.
    u32 vf2(const Buffer& in, Buffer* out) override;
    // 0x71015c7370: copies `in` to `out` and decrypts it there.
    u32 vf4(const Buffer& in, Buffer* out) override;

    u8 _48[0x250];
};
PKMN_SIZE_ASSERT(RC4Encryption, 0x298);

// N2nn3nex22KeyedChecksumAlgorithmE
class KeyedChecksumAlgorithm : public ChecksumAlgorithm {
public:
    // 0x71015c63b0: takes the key if its length is in the algorithm's range.
    bool Unk_15c63b0(const Key& key);

    Key m_key;
    u64 m_minKeyLength;
    u64 m_maxKeyLength;
};
PKMN_SIZE_ASSERT(KeyedChecksumAlgorithm, 0x50);

// N2nn3nex12HMACChecksumE
class HMACChecksum : public KeyedChecksumAlgorithm {
public:
    // 0x71015c3fe0
    HMACChecksum();
    // 0x71015c40b0
    ~HMACChecksum() override;
    // 0x71015c4620: appends the buffer's checksum to it.
    bool Unk_15c4620(Buffer* buffer);

    u8 _50[0x88];
};
PKMN_SIZE_ASSERT(HMACChecksum, 0xd8);

}  // namespace nex
}  // namespace nn

// What encrypts and checksums with one key: RC4 and an HMAC.
struct Unk_16310f0 {
    Unk_16310f0();
    ~Unk_16310f0();
    void Unk_1631150(const nn::nex::Key& key);
    bool Unk_1631200(const nn::nex::Buffer& in, nn::nex::Buffer* out, const nn::nex::Key& key);

    u64 field_0;
    nn::nex::RC4Encryption m_encryption;
    nn::nex::HMACChecksum m_checksum;
    nn::nex::Key m_key;
};
PKMN_OFFSET_ASSERT(Unk_16310f0, m_checksum, 0x2a0);
PKMN_OFFSET_ASSERT(Unk_16310f0, m_key, 0x378);
PKMN_SIZE_ASSERT(Unk_16310f0, 0x3a0);

// 0x71016310f0
Unk_16310f0::Unk_16310f0() {}

// 0x7101631120
Unk_16310f0::~Unk_16310f0() {}

// 0x7101631150
void Unk_16310f0::Unk_1631150(const nn::nex::Key& key) {
    m_encryption.Unk_15c6bc0(key);
    m_checksum.Unk_15c63b0(key);
    m_key = key;
}

// 0x7101631200: `in` encrypted with the key into `out`, its checksum after it.
bool Unk_16310f0::Unk_1631200(const nn::nex::Buffer& in, nn::nex::Buffer* out,
                              const nn::nex::Key& key) {
    nn::nex::RC4Encryption encryption;
    nn::nex::HMACChecksum checksum;
    if (!checksum.Unk_15c63b0(key) || !encryption.Unk_15c6bc0(key)) {
        return false;
    }
    if (encryption.vf2(in, out) != 0) {
        return false;
    }
    return checksum.Unk_15c4620(out);
}
