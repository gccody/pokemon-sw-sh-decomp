#pragma once
// NEX 4.6.8's matchmaking data classes whose type names are "Gathering",
// "DynamicGathering" and "GameSession" (the strings their type functions
// return and compare). They have no RTTI: the classes are placeholders named
// after their vtables (Unk_15b2f20, the root, after the function that reads
// its fields). Their slots are written as placeholder free functions
// (lib/nex/Unk_15b2f20.cpp, lib/nex/Unk_15b36f0.cpp); the virtual functions
// declared here only give each class its vtable, which none of these files
// emits.
#include "ddl/Streams.h"

// 0x71015bc5d0: whether two C strings are equal (a null one is "").
bool Unk_15bc5d0(const char* a, const char* b);
// 0x71015bc1e0: assigns `length` characters of `str` (all of it for -1).
void Unk_15bc1e0(nn::nex::String* self, const char* str, size_t length);
// 0x71015bb6c0: assigns a C string.
nn::nex::String* Unk_15bb6c0(nn::nex::String* self, const char* str);

// Vtable 0x710244e510 (8 slots): type name "Gathering". The fields are the
// structure 0x71015b2f20 reads; 0x71015b2dc0 writes the same fields (its
// parameter is the stream generator's placeholder for them, Unk_15b2dc0).
class Unk_15b2f20 : public nn::nex::RootObject {
public:
    Unk_15b2f20() : m_version(0) {}
    // The factories null-check what `new` returns, so NEX's allocation is
    // non-throwing: RootObject's (include/nn/nex/RootObject.h, shared) is
    // declared without throw(), so the classes here declare their own.
    static void* operator new(size_t size) throw() { return Unk_15b6dc0(size); }
    ~Unk_15b2f20() override {}
    virtual Unk_15b2f20* vf2() const;
    virtual nn::nex::String vf3() const;
    virtual bool vf4(const nn::nex::String& name) const;
    virtual bool vf5(const nn::nex::String& name) const;
    virtual void vf6(nn::nex::ByteStream* s) const;
    virtual void vf7(nn::nex::ByteStream* s);

    u8 m_version;
    u32 field_c;
    u64 field_10;
    u64 field_18;
    u16 field_20;
    u16 field_22;
    u32 field_24;
    u32 field_28;
    u32 field_2c;
    u32 field_30;
    nn::nex::String field_38;
};
PKMN_SIZE_ASSERT(Unk_15b2f20, 0x60);
PKMN_OFFSET_ASSERT(Unk_15b2f20, m_version, 0x8);
PKMN_OFFSET_ASSERT(Unk_15b2f20, field_c, 0xc);
PKMN_OFFSET_ASSERT(Unk_15b2f20, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_15b2f20, field_20, 0x20);
PKMN_OFFSET_ASSERT(Unk_15b2f20, field_30, 0x30);
PKMN_OFFSET_ASSERT(Unk_15b2f20, field_38, 0x38);

// The fields as 0x71015b2dc0 takes them.
inline const Unk_15b2dc0& Unk_15b2f20_fields(const Unk_15b2f20& v) {
    return reinterpret_cast<const Unk_15b2dc0&>(v);
}

// Vtable 0x710244e318 (9 slots), derived from Unk_15b2f20: "Gathering" too.
class Unk_244e308 : public Unk_15b2f20 {
public:
    Unk_244e308();
    virtual void vf8();
    ~Unk_244e308() override;
};

// Vtable 0x710244e768: type name "GameSession", then the version of a
// structure without fields.
class Unk_244e758 : public Unk_244e308 {
public:
    Unk_244e758() : field_60(0) {}
    nn::nex::String vf3() const override;
    ~Unk_244e758() override {}

    u8 field_60;
};
PKMN_OFFSET_ASSERT(Unk_244e758, field_60, 0x60);

// Vtable 0x710244e5a8: type name "DynamicGathering", then a byte cleared
// before the buffer is read and a Buffer.
class Unk_244e598 : public Unk_244e308 {
public:
    nn::nex::String vf3() const override;
    ~Unk_244e598() override;

    u8 field_60;
    nn::nex::Buffer field_68;
};
PKMN_OFFSET_ASSERT(Unk_244e598, field_60, 0x60);
PKMN_OFFSET_ASSERT(Unk_244e598, field_68, 0x68);

void Unk_15b2f20_read(nn::nex::ByteStream* s, Unk_15b2f20& v);
