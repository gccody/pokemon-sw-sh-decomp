// Scope: common
// NEX 4.6.8: a stream read, and the jobs that process a protocol's events and
// messages (RTTI: N2nn3nex23JobProcessProtocolEventE,
// N2nn3nex25JobProcessProtocolMessageE, both derived from N2nn3nex3JobE). A
// message job holds a CallProtocolMethodOperation (N2nn3nex27CallProtocolMethodOperationE,
// derived from N2nn3nex9OperationE) and a reference to a reference-counted object.
#include <atomic>

#include <nn/nex/ByteStream.h>
#include <nn/nex/Call.h>
#include <nn/nex/RefCountedObject.h>
#include <nn/nex/SharedPtr.h>

// 0x71015b8f50: the system tick (a wrapper of the SDK's).
u64 Unk_15b8f50();
namespace nn {
namespace os {
u64 GetSystemTickFrequency();
}  // namespace os
}  // namespace nn

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
// NON_MATCHING: the code is the original's, but it passes the value to
// Unk_15bbd10_set by value (copied to the stack), which the existing name
// (`PK16Unk_15bbd10_arg1`) gives as a pointer: the callee's symbol differs.
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

}  // namespace nex
}  // namespace nn
