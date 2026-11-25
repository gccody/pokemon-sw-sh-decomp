// Scope: common
// Name getters and forwarders to the object behind Unk_24ba618 (the
// Unk_eaa5xx/Unk_eaa6xx calls, which act on the object at its +0x50).
// Placeholder types: rename them once the owning classes are known.
#include <string.h>

#include "types.h"

extern void* Unk_24ba618;

// A 0x20-byte fixed-size name buffer, returned by value.
struct Unk_ece010_Name {
    char str[0x20];
};
PKMN_SIZE_ASSERT(Unk_ece010_Name, 0x20);

// A 0x80-byte callable passed by value: a header of four words and 0x60
// bytes of inline storage for the callable itself. field_10 copies the
// storage into another object, field_8 destroys it.
struct Unk_eaa580_Func {
    struct Header {
        u64 field_0;
        void (*field_8)(void* storage);
        void (*field_10)(void* src, void* dst);
        u64 field_18;
    };

    Header header;
    u8 storage[0x60];

    Unk_eaa580_Func(const Unk_eaa580_Func& other) : header() {
        if (other.header.field_10 != nullptr) {
            other.header.field_10(const_cast<u8*>(other.storage), storage);
            header = other.header;
        }
    }

    ~Unk_eaa580_Func() {
        if (header.field_8 != nullptr) {
            void (*destroy)(void*) = header.field_8;
            header = {};
            destroy(storage);
        }
    }
};
PKMN_OFFSET_ASSERT(Unk_eaa580_Func::Header, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_eaa580_Func::Header, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_eaa580_Func::Header, field_18, 0x18);
PKMN_OFFSET_ASSERT(Unk_eaa580_Func, storage, 0x20);
PKMN_SIZE_ASSERT(Unk_eaa580_Func, 0x80);

struct Unk_eaa660;
struct Unk_eaa670;
struct Unk_eaa680;
struct Unk_eaa690;
struct Unk_eaa620;
struct Unk_eaa640;
struct Unk_eaa6d0;

void Unk_eaa510(void* self);
void Unk_eaa520(void* self);
void Unk_eaa560(void* self);
void Unk_eaa580(void* self, Unk_eaa580_Func func);
void Unk_eaa620_call(const Unk_eaa620* self, u32 value);
void Unk_eaa640_call(const Unk_eaa640* self, u32 value, void* arg2);
void Unk_eaa660_call(const Unk_eaa660* self);
void Unk_eaa670_call(const Unk_eaa670* self);
void Unk_eaa680_call(const Unk_eaa680* self, u32 value, u64 size);
void Unk_eaa690_call(const Unk_eaa690* self, u32 value, void* arg2, u64 size);
void Unk_eaa6d0_call(const Unk_eaa6d0* self);

// 0x7100ece010
Unk_ece010_Name Unk_ece010() {
    const char* src = "tower_double";
    Unk_ece010_Name name = {};
    memcpy(name.str, src, strlen(src));
    return name;
}

// 0x7100ece050
Unk_ece010_Name Unk_ece050() {
    const char* src = "tower_single";
    Unk_ece010_Name name = {};
    memcpy(name.str, src, strlen(src));
    return name;
}

// 0x7100ece090
void Unk_ece090() {
    Unk_eaa510(Unk_24ba618);
}

// 0x7100ece0a0
void Unk_ece0a0() {
    Unk_eaa520(Unk_24ba618);
}

// 0x7100ece0b0
void Unk_ece0b0() {
    Unk_eaa560(Unk_24ba618);
}

// 0x7100ece0c0
void Unk_ece0c0(Unk_eaa580_Func func) {
    Unk_eaa580(Unk_24ba618, func);
}

// 0x7100ece170
void Unk_ece170() {
    Unk_eaa6d0_call(static_cast<const Unk_eaa6d0*>(Unk_24ba618));
}

// 0x7100ece180
void Unk_ece180() {
    Unk_eaa660_call(static_cast<const Unk_eaa660*>(Unk_24ba618));
}

// 0x7100ece190
void Unk_ece190() {
    Unk_eaa670_call(static_cast<const Unk_eaa670*>(Unk_24ba618));
}

// 0x7100ece1a0
void Unk_ece1a0() {
    Unk_eaa680_call(static_cast<const Unk_eaa680*>(Unk_24ba618), 0, 0x38);
}

// 0x7100ece1c0
void Unk_ece1c0(void* arg) {
    Unk_eaa690_call(static_cast<const Unk_eaa690*>(Unk_24ba618), 0, arg, 0x38);
}

// 0x7100ece1e0
void Unk_ece1e0(u32 value) {
    Unk_eaa620_call(static_cast<const Unk_eaa620*>(Unk_24ba618), value);
}

// 0x7100ece200
void Unk_ece200(u32 value, void* arg) {
    Unk_eaa640_call(static_cast<const Unk_eaa640*>(Unk_24ba618), value, arg);
}
