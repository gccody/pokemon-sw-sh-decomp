// Scope: common
// NEX 4.6.8's "Gathering" data classes (Unk_15b2f20.h): the reader of their
// fields, and virtual functions of the classes in vtable groups 0x710244e5a8
// ("DynamicGathering"; 0x710244e6f8 shares its slots 2 and 4-7) and
// 0x710244e768 ("GameSession").
#include "Unk_15b2f20.h"

using nn::nex::EndStructure;
using nn::nex::ReadField;
using nn::nex::ReadLength;

void Unk_162d790_write(nn::nex::ByteStream* s, const nn::nex::Buffer& v);
void Unk_162d7d0_read(nn::nex::ByteStream* s, nn::nex::Buffer& v);

// 0x71015b2f20
void Unk_15b2f20_read(nn::nex::ByteStream* s, Unk_15b2f20& v) {
    v.m_version = 0;
    bool noHeader = s->m_noHeader;
    u32 length = 0;
    if (!noHeader) {
        ReadField(s, v.m_version);
        if (s->m_error) return;
        if (!ReadLength(s, length)) return;
    }
    size_t start = s->m_pos;
    if (s->m_error) return;
    if (!ReadField(s, v.field_c)) return;
    if (!ReadField(s, v.field_10)) return;
    if (!ReadField(s, v.field_18)) return;
    if (!ReadField(s, v.field_20)) return;
    if (!ReadField(s, v.field_22)) return;
    if (!ReadField(s, v.field_24)) return;
    if (!ReadField(s, v.field_28)) return;
    if (!ReadField(s, v.field_2c)) return;
    if (!ReadField(s, v.field_30)) return;
    Unk_162d000_read(s, v.field_38);
    bool err = s->m_error;
    if (noHeader | err) return;
    EndStructure(s, start, length);
}

// 0x71015b33b0
nn::nex::String Unk_15b33b0(const Unk_244e598* self) {
    nn::nex::String name;
    Unk_15bc1e0(&name, "DynamicGathering", static_cast<size_t>(-1));
    return name;
}

// 0x71015b33f0
bool Unk_15b33f0(const Unk_244e598* self, const nn::nex::String& name) {
    return Unk_15bc5d0(name.m_ptr, "DynamicGathering");
}

// 0x71015b3410
bool Unk_15b3410(const Unk_244e598* self, const nn::nex::String& name) {
    return Unk_15bc5d0(name.m_ptr, "DynamicGathering") || Unk_15bc5d0(name.m_ptr, "Gathering");
}

// 0x71015b3460
bool Unk_15b3460(const Unk_15b2f20* self, const nn::nex::String& name) {
    return Unk_15bc5d0(name.m_ptr, "Gathering");
}

// 0x71015b3480
void Unk_15b3480(const Unk_244e598* self, nn::nex::ByteStream* s) {
    Unk_15b2dc0_write(s, Unk_15b2f20_fields(*self));
    Unk_162d790_write(s, self->field_68);
}

// 0x71015b34c0
void Unk_15b34c0(Unk_244e598* self, nn::nex::ByteStream* s) {
    Unk_15b2f20_read(s, *self);
    if (s->m_error) return;
    self->field_60 = 0;
    Unk_162d7d0_read(s, self->field_68);
}

// 0x71015b35b0
nn::nex::String Unk_15b35b0(const Unk_244e758* self) {
    nn::nex::String name;
    Unk_15bc1e0(&name, "GameSession", static_cast<size_t>(-1));
    return name;
}

// 0x71015b35f0
bool Unk_15b35f0(const Unk_244e758* self, const nn::nex::String& name) {
    return Unk_15bc5d0(name.m_ptr, "GameSession");
}

// 0x71015b3610
bool Unk_15b3610(const Unk_244e758* self, const nn::nex::String& name) {
    return Unk_15bc5d0(name.m_ptr, "GameSession") || Unk_15bc5d0(name.m_ptr, "Gathering");
}

// 0x71015b3660
void Unk_15b3660(const Unk_244e758* self, nn::nex::ByteStream* s) {
    Unk_15b2dc0_write(s, Unk_15b2f20_fields(*self));
    if (s->m_noHeader) return;
    u8 version = self->field_60;
    s->Write(std::min(version, (u8)0));
    s->Write((u32)0);
}
