#pragma once
// gflib3's nn::os event and TLS wrappers (src/gflib3/Unk_5cf850.cpp).
#include <nn/os.h>
#include <types.h>

void Unk_5cf870(nn::os::EventType* event, nn::os::EventClearMode clearMode, bool signaled);
void Unk_5cf880(nn::os::EventType* event);
bool Unk_5cf890(nn::os::EventType* event);
void Unk_5cf8a0(nn::os::EventType* event);
void Unk_5cf8b0(nn::os::EventType* event);
void Unk_5cf8c0(nn::os::LightEventType* event, nn::os::EventClearMode clearMode, bool signaled);
void Unk_5cf8d0(nn::os::LightEventType* event);
void Unk_5cf8e0(nn::os::LightEventType* event);
void Unk_5cf8f0(nn::os::LightEventType* event);
void Unk_5cf900(const nn::os::TlsSlot* slot);
void Unk_5cf920(uintptr_t value);
