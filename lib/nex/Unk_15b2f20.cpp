// Scope: common
// NEX 4.6.8's matchmaking data classes whose type names are "Gathering",
// "DynamicGathering" and "GameSession" (the strings their type functions
// return and compare): the reader of their common structure, and virtual
// functions of the classes in vtable groups 0x710244e5a8 (and 0x710244e6f8,
// which shares slots 2 and 4-7) and 0x710244e768. The classes have no RTTI, so
// the functions are placeholders over self structures.
#include "Unk_15b2f20.h"

using nn::nex::EndStructure;
using nn::nex::ReadField;
using nn::nex::ReadLength;

// 0x71015bc5d0: whether two C strings are equal (a null one is "").
bool Unk_15bc5d0(const char* a, const char* b);
// 0x71015bc1e0: assigns `length` characters of `str` (all of it for -1).
void Unk_15bc1e0(nn::nex::String* self, const char* str, size_t length);
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
    Unk_15b2dc0_write(s, *self);
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
    Unk_15b2dc0_write(s, *self);
    if (s->m_noHeader) return;
    u8 version = self->field_60;
    s->Write(std::min(version, (u8)0));
    s->Write((u32)0);
}
