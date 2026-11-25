// Scope: common
// NEX 4.6.8's "Gathering" data classes, continued (lib/nex/Unk_15b2f20.cpp):
// the stream-in and the factory of the class in vtable group 0x710244e768
// ("GameSession"), functions of the fields, and the constructor, destructor
// and virtual functions of the classes in vtable groups 0x710244e510 and
// 0x710244e318 ("Gathering").
#include "Unk_15b2f20.h"

using nn::nex::ReadField;
using nn::nex::ReadLength;

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

// 0x71015b3510
Unk_15b2f20* Unk_15b3510(const Unk_244e758* self) {
    return new Unk_244e758;
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

// 0x71015b37c0
Unk_244e308::Unk_244e308() {
    Unk_15b3830(this);
}

// 0x71015b4240 (D2), 0x71015b3860 (D0)
Unk_244e308::~Unk_244e308() {}

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

// 0x71015b3970
Unk_15b2f20* Unk_15b3970(const Unk_15b2f20* self) {
    return new Unk_244e308;
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
    Unk_15b2dc0_write(s, Unk_15b2f20_fields(*self));
}

// 0x71015b3a70
void Unk_15b3a70(Unk_15b2f20* self, nn::nex::ByteStream* s) {
    Unk_15b2f20_read(s, *self);
}

namespace nn {
namespace nex {

// N2nn3nex10StationURLE (0x70 bytes): 0x71015e9650 constructs one,
// 0x71015e9870 copies one, 0x71015e9a40 is its D2.
class StationURL : public RootObject {
public:
    StationURL();
    StationURL(const StationURL& other);
    virtual ~StationURL();
    u8 _8[0x68];
};
PKMN_SIZE_ASSERT(StationURL, 0x70);

}  // namespace nex
}  // namespace nn

// Whether `size` bytes are left to read; the error flag otherwise.
static inline bool Unk_HasLeft(nn::nex::ByteStream* s, size_t size) {
    if (s->m_buffer->m_size - s->m_pos < size) {
        s->m_error = true;
        return false;
    }
    return true;
}

// 0x71015b3a80: a list of StationURLs, which 0x710162d5a0 reads (as the stream
// generator's placeholder for them, Unk_162d5a0).
void Unk_15b3a80_read(nn::nex::ByteStream* s, nn::nex::qList<nn::nex::StationURL>& v) {
    v.clear();
    u32 count;
    ReadField(s, count);
    if (!Unk_HasLeft(s, count) || count >= 0x10000) {
        s->m_error = true;
        return;
    }
    for (u32 i = 0; i < count; i++) {
        nn::nex::StationURL url;
        Unk_162d5a0_read(s, reinterpret_cast<Unk_162d5a0&>(url));
        v.push_back(url);
    }
}
