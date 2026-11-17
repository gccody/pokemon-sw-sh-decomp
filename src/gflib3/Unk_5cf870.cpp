// Scope: common
//
// gflib3's thin wrappers around nn::os events, light events and TLS. Each
// passes its object straight on, so it is a member of a class whose first
// field is the nn::os object; the classes aren't known, so these are
// placeholder functions of the object. The initializers take the clear mode
// before the initial state, the other way round from the SDK.
#include "gflib3/Unk_5cf870.h"

struct Unk_5cf910 {
    u8 _0[0x80];
    u64 field_80;
    void* field_88;
    s32 field_90;
};
PKMN_OFFSET_ASSERT(Unk_5cf910, field_80, 0x80);
PKMN_OFFSET_ASSERT(Unk_5cf910, field_88, 0x88);
PKMN_OFFSET_ASSERT(Unk_5cf910, field_90, 0x90);

nn::os::TlsSlot Unk_2771620;

// 0x71005cf870
void Unk_5cf870(nn::os::EventType* event, nn::os::EventClearMode clearMode, bool signaled) {
    nn::os::InitializeEvent(event, signaled, clearMode);
}

// 0x71005cf880
void Unk_5cf880(nn::os::EventType* event) {
    nn::os::FinalizeEvent(event);
}

// 0x71005cf890
bool Unk_5cf890(nn::os::EventType* event) {
    return nn::os::TryWaitEvent(event);
}

// 0x71005cf8a0
void Unk_5cf8a0(nn::os::EventType* event) {
    nn::os::SignalEvent(event);
}

// 0x71005cf8b0
void Unk_5cf8b0(nn::os::EventType* event) {
    nn::os::ClearEvent(event);
}

// 0x71005cf8c0
void Unk_5cf8c0(nn::os::LightEventType* event, nn::os::EventClearMode clearMode, bool signaled) {
    nn::os::InitializeLightEvent(event, signaled, clearMode);
}

// 0x71005cf8d0
void Unk_5cf8d0(nn::os::LightEventType* event) {
    nn::os::FinalizeLightEvent(event);
}

// 0x71005cf8e0
void Unk_5cf8e0(nn::os::LightEventType* event) {
    nn::os::SignalLightEvent(event);
}

// 0x71005cf8f0
void Unk_5cf8f0(nn::os::LightEventType* event) {
    nn::os::WaitLightEvent(event);
}

// 0x71005cf900
void Unk_5cf900(const nn::os::TlsSlot* slot) {
    nn::os::FreeTlsSlot(*slot);
}

// 0x71005cf910
void Unk_5cf910_set(Unk_5cf910* self, void* value) {
    self->field_80 = 0;
    self->field_88 = value;
    self->field_90 = -1;
}

// 0x71005cf920
void Unk_5cf920(uintptr_t value) {
    nn::os::SetTlsValue(Unk_2771620, value);
}
