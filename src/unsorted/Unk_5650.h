#pragma once
// The application (vtable 0x710236d268, class Unk_236d258 of
// src/unsorted/virtual/Unk_5df990.cpp, on gflib3's Unk_239a068): its slots
// are written as free functions over the fields they use (src/unsorted/
// Unk_5650.cpp and Unk_5e20.cpp). Placeholder names: rename once the class
// is known.
#include <types.h>

namespace nn {
namespace os {

// Only its size: the application keeps one at +0x1050.
struct SystemEventType {
    u8 _0[0x28];
};

bool TryWaitSystemEvent(SystemEventType* event);
void DestroySystemEvent(SystemEventType* event);

}  // namespace os
}  // namespace nn

// What the application's slots 5 and 6 forward to (slot 1).
class Unk_236d258_Target {
public:
    virtual void vf0();
    virtual void vf1(bool arg1, bool arg2);
};

// The application's fields: what slots 5 and 6 forward to, and the event that
// tells it the audio output changed.
struct Unk_236d258_Self {
    u8 _0[0x140];
    Unk_236d258_Target* field_140;
    u8 _148[0x1050 - 0x148];
    nn::os::SystemEventType field_1050;
};
PKMN_OFFSET_ASSERT(Unk_236d258_Self, field_140, 0x140);
PKMN_OFFSET_ASSERT(Unk_236d258_Self, field_1050, 0x1050);
