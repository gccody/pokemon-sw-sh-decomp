// Scope: common
// A battle data exchange with the net peer (Unk_8974a0.h), 0x71008a7910 to
// 0x71008a7e70: a request packet to send and the reply that came, and the
// state of the exchange (sent, replied). Without a peer to talk to (a local
// battle, the flag at +0x4e61 clear) it answers itself: the reply is what
// was set aside for it. Part of the segment 0x71008a7910-0x71008a7f30.
// Placeholder names: rename once the classes are known.
#include "battle/battle_logic/source/netwatch/Unk_8a7910.h"

// The packet's accessors (src/unsorted/leaf/Unk_892310.cpp).
struct Unk_892310;
u16 Unk_892310_getField0(const Unk_892310* self);
struct Unk_892320;
u8 Unk_892320_getField6(const Unk_892320* self);
struct Unk_892330;
u8 Unk_892330_getField2(const Unk_892330* self);
struct Unk_892340;
u8* Unk_892340_getField8Ptr(Unk_892340* self);
struct Unk_892350;
u16 Unk_892350_getField4(const Unk_892350* self);
struct Unk_892380;
void Unk_892380_set(Unk_892380* self);
struct Unk_8923d0;
u8* Unk_8923d0_getField8Ptr(Unk_8923d0* self);
struct Unk_892490;
u16 Unk_892490_getField8(const Unk_892490* self);
struct Unk_8924a0;
u8 Unk_8924a0_getFielde(const Unk_8924a0* self);
struct Unk_8924b0;
u8 Unk_8924b0_getFielda(const Unk_8924b0* self);
struct Unk_8924c0;
u8* Unk_8924c0_getField10Ptr(Unk_8924c0* self);
struct Unk_8924d0;
u16 Unk_8924d0_getFieldc(const Unk_8924d0* self);
struct Unk_8924e0;
u32 Unk_8924e0_get(const Unk_8924e0* self);
struct Unk_8944f0;
void Unk_8944f0_clearField358(Unk_8944f0* self);

// The packet's setters: from the fields and the body, from another packet,
// from the header and body a peer sent.
void Unk_892400(Unk_23b7ea8* self, const Unk_23b7ea8* other);
void Unk_892430(Unk_23b7ea8* self, u16 arg1, u8 arg2, u8 arg3, const void* body, u32 size);
void Unk_892460(Unk_23b7ea8* self, const u8* data);

// The peer's side of the exchange (Unk_8974a0.h doesn't declare them).
bool Unk_895560(Unk_23b7ee8* self, u8 clientId, const u8* data, u64 size);
bool Unk_895b10(Unk_23b7ee8* self);
u32 Unk_895f90(Unk_23b7ee8* self, u8 clientId, const u8** data);
bool Unk_896190(Unk_23b7ee8* self);
u32 Unk_8961d0(Unk_23b7ee8* self, const u8** data);
bool Unk_896220(Unk_23b7ee8* self, const u8* data, u32 size);
void Unk_8965f0(Unk_23b7ee8* self);
void Unk_896720(Unk_23b7ee8* self, u8 value, u8 clientId);
u8 Unk_8969b0(Unk_23b7ee8* self, u8 clientId);

// 0x71008a7910
Unk_8a7ab0_Handle::Unk_8a7ab0_Handle(u8 clientId,
                                     bool remote,
                                     const Unk_239a418_Ref<Unk_23b7ee8>& peer)
    : field_0(peer),
      field_4e58(0),
      field_4e59(clientId),
      field_4e5c(0),
      field_4e60(false),
      field_4e61(remote),
      field_4e62(0) {}

// 0x71008a79a0
Unk_8a7ab0_Handle::~Unk_8a7ab0_Handle() {}

// 0x71008a79f0
void Unk_8a79f0(Unk_8a7ab0_Handle* self) {
    self->field_4e5c = 0;
    self->field_4e58 = 0;
    self->field_4e60 = false;
}

// 0x71008a7a10
void Unk_8a7a10(Unk_8a7ab0_Handle* self) {
    self->field_4e61 = false;
}

// 0x71008a7a20
bool Unk_8a7a20(Unk_8a7ab0_Handle* self) {
    return self->field_4e5c == 3;
}

// 0x71008a7a40
void Unk_8a7a40(Unk_8a7ab0_Handle* self, u16 arg1, u8 arg2, u8 arg3, const void* body, u32 size) {
    if (self->field_4e5c != 0)
        return;
    self->field_4e5c = 1;
    self->field_4e58 = arg3;
    Unk_892430(&self->field_8, arg1, arg2, arg3, body, size);
    Unk_892380_set(reinterpret_cast<Unk_892380*>(&self->field_2730));
    self->field_4e60 = false;
}

// 0x71008a7ab0
bool Unk_8a7ab0(Unk_8a7ab0_Handle* self) {
    switch (self->field_4e5c) {
        case 1:
            if (self->field_4e61) {
                u8* data = Unk_8923d0_getField8Ptr(reinterpret_cast<Unk_8923d0*>(&self->field_8));
                u32 size = Unk_8924e0_get(reinterpret_cast<const Unk_8924e0*>(&self->field_8));
                if (!Unk_895560(self->field_0.m_ptr, self->field_4e59, data, size))
                    break;
            }
            self->field_4e5c = 3;
            // fall through
        case 3:
            if (self->field_4e61) {
                if (!Unk_895b10(self->field_0.m_ptr))
                    break;
                const u8* reply;
                if (Unk_895f90(self->field_0.m_ptr, self->field_4e59, &reply) == 0)
                    break;
                Unk_892460(&self->field_2730, reply);
                self->field_4e60 = true;
            } else if (!self->field_4e60) {
                break;
            }
            self->field_4e5c = 4;
            return true;
        case 4:
            return true;
    }
    return false;
}

// 0x71008a7be0
void Unk_8a7be0(Unk_8a7ab0_Handle* self) {
    self->field_4e5c = 0;
    if (self->field_4e61)
        Unk_8965f0(self->field_0.m_ptr);
}

// 0x71008a7c00
void Unk_8a7c00(Unk_8a7ab0_Handle* self) {
    Unk_892380_set(reinterpret_cast<Unk_892380*>(&self->field_8));
}

// 0x71008a7c10
void Unk_8a7c10(Unk_8a7ab0_Handle* self, u8* arg1, u16* arg2, u8* arg3) {
    if (self->field_4e61) {
        if (Unk_896190(self->field_0.m_ptr)) {
            const u8* data;
            Unk_8961d0(self->field_0.m_ptr, &data);
            *arg1 = Unk_892330_getField2(reinterpret_cast<const Unk_892330*>(data));
            *arg2 = Unk_892310_getField0(reinterpret_cast<const Unk_892310*>(data));
            *arg3 = Unk_892320_getField6(reinterpret_cast<const Unk_892320*>(data));
            return;
        }
    } else if (!self->field_4e60) {
        const Unk_23b7ea8* packet = &self->field_8;
        *arg1 = Unk_8924b0_getFielda(reinterpret_cast<const Unk_8924b0*>(packet));
        *arg2 = Unk_892490_getField8(reinterpret_cast<const Unk_892490*>(packet));
        *arg3 = Unk_8924a0_getFielde(reinterpret_cast<const Unk_8924a0*>(packet));
        return;
    }
    *arg1 = 0;
    *arg2 = 0;
    *arg3 = 0x33;
}

// 0x71008a7ce0
u16 Unk_8a7ce0(Unk_8a7ab0_Handle* self, u8** body) {
    if (self->field_4e61) {
        const u8* data = nullptr;
        Unk_8961d0(self->field_0.m_ptr, &data);
        if (data == nullptr)
            return 0;
        *body = Unk_892340_getField8Ptr(reinterpret_cast<Unk_892340*>(const_cast<u8*>(data)));
        return Unk_892350_getField4(reinterpret_cast<const Unk_892350*>(data));
    }
    *body = Unk_8924c0_getField10Ptr(reinterpret_cast<Unk_8924c0*>(&self->field_8));
    return Unk_8924d0_getFieldc(reinterpret_cast<const Unk_8924d0*>(&self->field_8));
}

// 0x71008a7d60
bool Unk_8a7d60(Unk_8a7ab0_Handle* self, Unk_23b7ea8* packet) {
    if (self->field_4e61) {
        u8* data = Unk_8923d0_getField8Ptr(reinterpret_cast<Unk_8923d0*>(packet));
        u32 size = Unk_8924e0_get(reinterpret_cast<const Unk_8924e0*>(packet));
        return Unk_896220(self->field_0.m_ptr, data, size);
    }
    if (!self->field_4e60) {
        Unk_892400(&self->field_2730, packet);
        self->field_4e60 = true;
    }
    return true;
}

// 0x71008a7df0
u8 Unk_8a7df0(void* self, u8 clientId) {
    Unk_8a7ab0_Handle* handle = static_cast<Unk_8a7ab0_Handle*>(self);
    if (handle->field_0.m_ptr != nullptr)
        return Unk_8969b0(handle->field_0.m_ptr, clientId);
    return handle->field_4e62;
}

// 0x71008a7e10
void Unk_8a7e10(Unk_8a7ab0_Handle* self, u8 value) {
    if (self->field_0.m_ptr != nullptr) {
        Unk_896720(self->field_0.m_ptr, value, self->field_4e59);
        return;
    }
    self->field_4e62 = value;
}

// 0x71008a7e40
void Unk_8a7e40(Unk_8a7ab0_Handle* self) {
    if (self->field_0.m_ptr != nullptr)
        Unk_8944f0_clearField358(reinterpret_cast<Unk_8944f0*>(self->field_0.m_ptr));
    self->field_4e62 = 0;
}
