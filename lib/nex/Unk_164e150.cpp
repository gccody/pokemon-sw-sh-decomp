// Scope: common
// NEX 4.6.8's "LocationData" and "SubscriptionData" data classes
// (lib/nex/Unk_164e150.h): LocationData's stream-in, both classes' virtual
// functions (vtables 0x7102417e78 and 0x7102417e28: clone, type name, type
// checks, stream-out and stream-in), and the constructor of their protocol's
// client.
#include "Unk_164e150.h"

using nn::nex::ReadField;
using nn::nex::ReadLength;

// 0x71015bc5d0: whether two C strings are equal (a null one is "").
bool Unk_15bc5d0(const char* a, const char* b);
// 0x71015bc1e0: assigns `length` characters of `str` (all of it for -1).
void Unk_15bc1e0(nn::nex::String* self, const char* str, size_t length);

// 0x71016307d0: reads the base's fields (its version and length).
void Unk_16307d0(nn::nex::ByteStream* s, void* v);
// 0x71016309f0: the base's type check ("Data").
bool Unk_16309f0(const void* self, const nn::nex::String& name);

// The qBuffers' stream functions (as the stream generator's placeholders).
struct Unk_162d6a0;
void Unk_162d6a0_read(nn::nex::ByteStream* s, Unk_162d6a0& v);

void Unk_164e020_write(nn::nex::ByteStream* s, const Unk_164e020& v);
void Unk_164da60_write(nn::nex::ByteStream* s, const Unk_164da60& v);
// 0x710164dc90
void Unk_164dc90_read(nn::nex::ByteStream* s, Unk_164da60& v);

// 0x710164e150
// NON_MATCHING: the length's check is compiled as `>= 4` (cmp #4, b.hs; the original's
// cmp #3, b.hi) and the read position's store is scheduled after the last byte's insert.
void Unk_164e150_read(nn::nex::ByteStream* s, Unk_164e020& v) {
    Unk_16307d0(s, &v);
    if (s->m_error) return;
    v.m_version = 0;
    bool noHeader = s->m_noHeader;
    u32 length = 0;
    if (!noHeader) {
        ReadField(s, v.m_version);
        if (s->m_error) return;
        if (!ReadLength(s, length)) return;
    }
    size_t start = s->m_pos;
    if (!ReadField(s, v.field_10)) return;
    if (!ReadField(s, v.field_18)) return;
    if (!ReadField(s, v.field_1c)) return;
    if (!ReadField(s, v.field_20)) return;
    if (!ReadField(s, v.field_24)) return;
    Unk_162d6a0_read(s, reinterpret_cast<Unk_162d6a0&>(v.field_28));
    bool err = s->m_error;
    if (noHeader | err) return;
    nn::nex::EndStructure(s, start, length);
}

// 0x710164e3e0
Unk_164e020* Unk_164e3e0(const Unk_164e020* self) {
    Unk_164e020* copy = new Unk_164e020;
    *copy = *self;
    return copy;
}

// 0x710164e4b0
nn::nex::String Unk_164e4b0(const Unk_164e020* self) {
    nn::nex::String name;
    Unk_15bc1e0(&name, "LocationData", static_cast<size_t>(-1));
    return name;
}

// 0x710164e4f0
bool Unk_164e4f0(const Unk_164e020* self, const nn::nex::String& name) {
    return Unk_15bc5d0(name.m_ptr, "LocationData");
}

// 0x710164e530
bool Unk_164e530(const Unk_164e020* self, const nn::nex::String& name) {
    return Unk_15bc5d0(name.m_ptr, "LocationData") || Unk_16309f0(self, name);
}

// 0x710164e510
void Unk_164e510(const Unk_164e020* self, nn::nex::ByteStream* s) {
    Unk_164e020_write(s, *self);
}

// 0x710164e520
void Unk_164e520(Unk_164e020* self, nn::nex::ByteStream* s) {
    Unk_164e150_read(s, *self);
}

// 0x710164e600
Unk_164da60* Unk_164e600(const Unk_164da60* self) {
    Unk_164da60* copy = new Unk_164da60;
    *copy = *self;
    return copy;
}

// 0x710164e6a0
nn::nex::String Unk_164e6a0(const Unk_164da60* self) {
    nn::nex::String name;
    Unk_15bc1e0(&name, "SubscriptionData", static_cast<size_t>(-1));
    return name;
}

// 0x710164e6e0
bool Unk_164e6e0(const Unk_164da60* self, const nn::nex::String& name) {
    return Unk_15bc5d0(name.m_ptr, "SubscriptionData");
}

// 0x710164e700
void Unk_164e700(const Unk_164da60* self, nn::nex::ByteStream* s) {
    Unk_164da60_write(s, *self);
}

// 0x710164e710
void Unk_164e710(Unk_164da60* self, nn::nex::ByteStream* s) {
    Unk_164dc90_read(s, *self);
}

// 0x710164e720
void Unk_164e720(nn::nex::ClientProtocol* self, u32 protocolId) {
    Unk_164e720_init(self, protocolId);
}
