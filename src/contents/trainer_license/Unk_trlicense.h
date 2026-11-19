#pragma once
// The League Card apps (prog/contents/trainer_license: common/
// trainer_license.dat, bin/appli/trlicense_album; Game Freak spells them
// trlicense and trlicence): what their states use. Placeholder names: rename
// them once the classes are known.
#include <types.h>

#include "contents/common/framework.h"

// tools/leafgen.py's placeholders, with the objects as void* or u64.
void Unk_eb6230(void* view, u32 arg);
void Unk_14e1a30(u64 self, u32 arg);
void Unk_67bfa0(u64 self);

// A card's key (0x8 bytes).
struct Unk_1459e50_Key {
    u64 field_0;
};

// The album's background view (vtable 0x710243d1c8: "ViewBg").
class Unk_243d1c8 : public Unk_23f4660 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23f4660::Unk_GetType());
        return &type;
    }

    void Unk_145fcc0(u32 arg);
};

// The album's top view (vtable 0x710243d958: "ViewTop").
class Unk_243d958 : public Unk_23f4660 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23f4660::Unk_GetType());
        return &type;
    }
};

// The album's top menu (vtable 0x710243dc10: "ViewTopMenu").
class Unk_243dc10 : public Unk_23f4660 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23f4660::Unk_GetType());
        return &type;
    }

    void Unk_14705a0();
    void Unk_1470600();

    u8 _5d0[0x5e0 - 0x5d0];
    u32 field_5e0;
};
static_assert(__builtin_offsetof(Unk_243dc10, field_5e0) == 0x5e0, "Unk_243dc10::field_5e0");

// The card code view (vtable 0x710243d7a0: "ViewCardCode").
class Unk_243d7a0 : public Unk_23f4660 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23f4660::Unk_GetType());
        return &type;
    }

    void Unk_146b8b0(u32 mode);
    void Unk_146c040();
    void Unk_146c0a0();

    u32 field_5d0;
    u8 _5d4[0x5e0 - 0x5d4];
    void* field_5e0;
    u8 _5e8[0x600 - 0x5e8];
    void* field_600;
};
static_assert(__builtin_offsetof(Unk_243d7a0, field_5d0) == 0x5d0, "Unk_243d7a0::field_5d0");

// A card (vtable 0x710243cff8: "ViewCard").
class Unk_243cff8 : public Unk_23f4660 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23f4660::Unk_GetType());
        return &type;
    }
};

// The camp view (vtable 0x710243cee0: "ViewCamp").
class Unk_243cee0 : public Unk_23f4660 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23f4660::Unk_GetType());
        return &type;
    }
};

// The album's list (vtable 0x710243e198: "ViewList").
class Unk_243e198 : public Unk_23f4660 {
public:
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_23f4660::Unk_GetType());
        return &type;
    }

    void Unk_14758f0();
    void Unk_1475b00(u32 arg);
};

// The card pass menu view (vtable 0x710243e520: "ViewCardPassMenu").
class Unk_243e520 : public Unk_23f4660 {
public:
    static const Unk_239a418_Type* Unk_GetType();  // 0x7101478660

    void Unk_1478240();
    void Unk_1478290();
};

// The card info view (vtable 0x710243dd28: "ViewCardInfo").
class Unk_243dd28 : public Unk_23f4660 {
public:
    static const Unk_239a418_Type* Unk_GetType();

    void Unk_1470d30(const Unk_1459e50_Key& key);
    void Unk_1471d50(u32 arg);
    void Unk_1471dd0(u32 arg);
};

struct Unk_14cc6e0;
void Unk_14cc6e0_call(const Unk_14cc6e0* self);

struct Unk_14cc8c0;
void Unk_14cc8c0_call(const Unk_14cc8c0* self);

// What the album app keeps at +0x68 to +0x88.
class Unk_243d5a8_68 : public Unk_239a418 {
public:
    void Unk_Call14cc6e0() const { Unk_14cc6e0_call(reinterpret_cast<const Unk_14cc6e0*>(this)); }
};
class Unk_243d5a8_70 : public Unk_239a418 {
public:
    void Unk_Call14cc8c0() const { Unk_14cc8c0_call(reinterpret_cast<const Unk_14cc8c0*>(this)); }
};
class Unk_243d5a8_78 {
public:
    Unk_1459e50_Key Unk_1459e50(u32 arg1, u32 arg2) const;
};
class Unk_243d5a8_80 : public Unk_239a418 {
public:
    void Unk_1458310(u32 arg);
};
class Unk_243d5a8_88 {
public:
    void Unk_1341270(u32 arg);
};

// The album app (vtable 0x710243d5a8): its states reach it through their
// field_68 and dereference it.
class Unk_243d5a8 : public Unk_239a418 {
public:
    static const Unk_239a418_Type* Unk_GetType();  // 0x7101467080

    void Unk_1463730();

    u8 _60[0x68 - 0x60];
    Unk_239a418_Ref<Unk_243d5a8_68> field_68;
    Unk_239a418_Ref<Unk_243d5a8_70> field_70;
    Unk_243d5a8_78* field_78;
    Unk_239a418_Ref<Unk_243d5a8_80> field_80;
    Unk_243d5a8_88* field_88;
    u32 field_90;
    u32 field_94;
};
static_assert(__builtin_offsetof(Unk_243d5a8, field_80) == 0x80, "Unk_243d5a8::field_80");

inline Unk_243d5a8* Unk_AlbumApp(Unk_23f43c8* state) {
    return Unk_DynamicCast<Unk_243d5a8>(Unk_HandleObject(state->field_68));
}
