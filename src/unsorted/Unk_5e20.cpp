// Scope: common
// The application's slots 5 and 6 (src/unsorted/Unk_5650.h), the paths made
// from a C string (one outside the "data:/" mount resolved first), and the guarded
// static whose destructor Unk_61f0_call is. Placeholder names: rename once
// the classes are known.
#include <cstring>

#include <types.h>

#include "unsorted/Unk_5650.h"
#include "unsorted/Unk_d0c0.h"

// A string's hash, characters and count: the static empty string's when it
// has none (as Unk_d0c0_String::Unk_5cfaf0 reads them).
extern const u64 Unk_1b14200;
extern const char* const Unk_236d888;

inline const u64& Unk_5e20_Hash(const Unk_d0c0_String& str) {
    return str.m_ptr ? str.m_ptr->field_58 : Unk_1b14200;
}

inline const char* const& Unk_5e20_Chars(const Unk_d0c0_String& str) {
    return str.m_ptr ? str.m_ptr->field_60 : Unk_236d888;
}

inline u64 Unk_5e20_Length(const Unk_d0c0_String& str) {
    return str.m_ptr ? str.m_ptr->field_68 : 0;
}

// A reference to a string object: added through slot 2 of its +0x48
// interface, dropped through slot 3.
class Unk_5e20_StringRef {
public:
    Unk_5e20_StringRef() : m_ptr(nullptr) {}

    // Holds the string's object too: tested as the string holds it.
    Unk_5e20_StringRef& operator=(const Unk_d0c0_String& str) {
        Unk_2399470* ptr = str.m_ptr;
        if (str.m_ptr)
            static_cast<Unk_239a4f8*>(str.m_ptr)->vf3();
        Unk_2399470* old = m_ptr;
        m_ptr = ptr;
        if (old)
            static_cast<Unk_239a4f8*>(old)->vf4();
        return *this;
    }

    Unk_2399470* m_ptr;
};

// A string's name: its hash, characters and count, and the string object
// that keeps them alive.
class Unk_5e20_Name {
public:
    Unk_5e20_Name(u64 hash, const char* chars, u64 length, const Unk_d0c0_String& str)
        : field_0(hash), field_8(chars), field_10(length) {
        field_18 = str;
    }

    u64 field_0;
    const char* field_8;
    u64 field_10;
    Unk_5e20_StringRef field_18;
};
static_assert(sizeof(Unk_5e20_Name) == 0x20, "Unk_5e20_Name");

// A path: its string, the string's name and a flag.
class Unk_5e20_Path {
public:
    explicit Unk_5e20_Path(const char* path)
        : field_0(path),
          field_8(Unk_5e20_Hash(field_0),
                  Unk_5e20_Chars(field_0),
                  Unk_5e20_Length(field_0),
                  field_0),
          field_28(0) {
        Unk_105b0();
    }
    Unk_5e20_Path(const Unk_d0c0_String& path, bool arg);  // 0x71005e6180

    void Unk_105b0();

    Unk_d0c0_String field_0;
    Unk_5e20_Name field_8;
    u32 field_28;
};
PKMN_OFFSET_ASSERT(Unk_5e20_Path, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_5e20_Path, field_28, 0x28);

// The "data:/" mount's name.
extern const char Unk_239a578[];

// What a path outside the mount resolves to.
Unk_d0c0_String Unk_10530(const char* mount, const char* path);
Unk_d0c0_String Unk_10910(const char* mount, const char* path);

// NON_MATCHING: one register: where the string has no object, the original
// stores the (null) pointer's register into the name, this stores xzr.
// 0x7100005e20
Unk_5e20_Path Unk_5e20(const char* path) {
    if (strncmp(path, Unk_239a578, strlen(Unk_239a578)) != 0)
        return Unk_5e20_Path(Unk_10530(Unk_239a578, path), false);
    return Unk_5e20_Path(path);
}

// NON_MATCHING: one register: where the string has no object, the original
// stores the (null) pointer's register into the name, this stores xzr.
// 0x7100005f50
Unk_5e20_Path Unk_5f50(const char* path) {
    if (strncmp(path, Unk_239a578, strlen(Unk_239a578)) != 0)
        return Unk_5e20_Path(Unk_10910(Unk_239a578, path), false);
    return Unk_5e20_Path(path);
}

// 0x7100006080
void Unk_6080(Unk_236d258_Self* self) {
    self->field_140->vf1(true, true);
}

// 0x71000060a0
void Unk_60a0(Unk_236d258_Self* self) {
    self->field_140->vf1(false, true);
}

struct Unk_61f0;
void Unk_61f0_call(Unk_61f0* self) __attribute__((visibility("hidden")));

extern "C" int __cxa_atexit(void (*function)(void*), void* object, void* dso);
extern "C" void* __dso_handle __attribute__((visibility("hidden")));

extern Unk_61f0 Unk_24ba588;
extern u64 Unk_24ba590;

// A guarded static with a destructor: its storage is constant-initialised, so
// the init function only registers the destructor.
// 0x71000061a0
void Unk_61a0_init() {
    if ((Unk_24ba590 & 1) == 0) {
        __cxa_atexit(reinterpret_cast<void (*)(void*)>(Unk_61f0_call), &Unk_24ba588, &__dso_handle);
        Unk_24ba590 = 1;
    }
}
