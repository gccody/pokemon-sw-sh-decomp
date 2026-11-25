// Scope: common
// NEX 4.6.8's "Gathering" data classes, continued (lib/nex/Unk_15b2f20.cpp):
// the stream-in of the class in vtable group 0x710244e768 ("GameSession"),
// functions of the common structure, and virtual functions of the classes in
// vtable groups 0x710244e510 and 0x710244e318 ("Gathering"). The classes have
// no RTTI, so the functions are placeholders over self structures.
#include "Unk_15b2f20.h"

using nn::nex::ReadField;
using nn::nex::ReadLength;

// 0x71015bc5d0: whether two C strings are equal (a null one is "").
bool Unk_15bc5d0(const char* a, const char* b);
// 0x71015bc1e0: assigns `length` characters of `str` (all of it for -1).
void Unk_15bc1e0(nn::nex::String* self, const char* str, size_t length);
// 0x71015bb6c0: assigns a C string.
void Unk_15bb6c0(nn::nex::String* self, const char* str);
// 0x71015bab00: assigns another String.
void Unk_15bab00(nn::nex::String* self, const nn::nex::String& other);

// 0x71015b36f0
void Unk_15b36f0(Unk_244e758* self, nn::nex::ByteStream* s) {
    Unk_15b2f20_read(s, *self);
    if (s->m_error) return;
    self->field_60 = 0;
    if (s->m_noHeader) return;
    ReadField(s, self->field_60);
    if (s->m_error) return;
    u32 length;
    ReadLength(s, length);
}

// 0x71015b3830
void Unk_15b3830(Unk_15b2f20* self) {
    self->field_c = 0;
    self->field_10 = 0;
    self->field_18 = 0;
    self->field_20 = 0;
    self->field_22 = 0;
    self->field_24 = 1;
    self->field_28 = 0;
    self->field_2c = 0x200;
    self->field_30 = 0;
    Unk_15bb6c0(&self->field_38, "");
}

// 0x71015b38d0
void Unk_15b38d0(Unk_15b2f20* self, const nn::nex::String& value) {
    Unk_15bab00(&self->field_38, value);
}

// 0x71015b38f0
Unk_15b2f20& Unk_15b38f0(Unk_15b2f20* self, const Unk_15b2f20& other) {
    self->m_version = other.m_version;
    self->field_c = other.field_c;
    self->field_10 = other.field_10;
    self->field_18 = other.field_18;
    self->field_20 = other.field_20;
    self->field_22 = other.field_22;
    self->field_24 = other.field_24;
    self->field_28 = other.field_28;
    self->field_2c = other.field_2c;
    self->field_30 = other.field_30;
    Unk_15bab00(&self->field_38, other.field_38);
    return *self;
}

// 0x71015b3a00
nn::nex::String Unk_15b3a00(const Unk_15b2f20* self) {
    nn::nex::String name;
    Unk_15bc1e0(&name, "Gathering", static_cast<size_t>(-1));
    return name;
}

// 0x71015b3a40
bool Unk_15b3a40(const Unk_15b2f20* self, const nn::nex::String& name) {
    return Unk_15bc5d0(name.m_ptr, "Gathering");
}

// 0x71015b3a60
void Unk_15b3a60(const Unk_15b2f20* self, nn::nex::ByteStream* s) {
    Unk_15b2dc0_write(s, *self);
}

// 0x71015b3a70
void Unk_15b3a70(Unk_15b2f20* self, nn::nex::ByteStream* s) {
    Unk_15b2f20_read(s, *self);
}
