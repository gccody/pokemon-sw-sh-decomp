// Scope: common
// The tables of registered plugins and codecs: a key built from the plugin's
// type, company and ID, and two creation functions each. Placeholder names.
#include "Unk_KeyArray.h"

struct Unk_35f000_Obj {
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4(void* a1);
};

struct Unk_35ead0_Plugin {
    Unk_35f000_Obj* (*field_0)(void* allocator);
    void* (*field_8)(void* allocator);
};

struct Unk_35ead0_Codec {
    void* (*field_0)(void* a0);
    void* (*field_8)(void* a0);
};

Unk_KeyArray<u32, Unk_35ead0_Plugin> Unk_24bcb00;
Unk_KeyArray<u32, Unk_35ead0_Codec> Unk_24bcb10;
void* Unk_24bcb20;
// The allocator the plugins are created with.
extern u8 Unk_2380d10;

static inline u32 Unk_35ead0_Key(u32 type, u32 company, u32 id) {
    return (type & 0xf) + (company << 4) + (id << 16);
}

// 0x710035ead0
u32 Unk_35ead0(u32 company, u32 id, void* (*create0)(void*), void* (*create1)(void*)) {
    u32 key = Unk_35ead0_Key(1, company, id);
    if (Unk_24bcb10.Exists(key) != nullptr)
        return 2;
    if (create0 == nullptr || create1 == nullptr)
        return 0x1f;
    Unk_35ead0_Codec codec;
    codec.field_0 = create0;
    codec.field_8 = create1;
    return Unk_24bcb10.Set(key, codec) != nullptr ? 1 : 2;
}

// 0x710035ed20
u32 Unk_35ed20(u32 type, u32 company, u32 id, Unk_35f000_Obj* (*create)(void*),
               void* (*createParams)(void*)) {
    u32 key = Unk_35ead0_Key(type, company, id);
    if (Unk_24bcb00.Exists(key) != nullptr)
        return 1;
    Unk_35ead0_Plugin plugin;
    plugin.field_0 = create;
    plugin.field_8 = createParams;
    return Unk_24bcb00.Set(key, plugin) != nullptr ? 1 : 2;
}

// 0x710035ef60
u32 Unk_35ef60() {
    Unk_24bcb00.Term();
    Unk_24bcb10.Term();
    if (Unk_24bcb20 != nullptr) {
        Unk_3047c0(Unk_237e820, Unk_24bcb20);
        Unk_24bcb20 = nullptr;
    }
    return 1;
}

// 0x710035f000
u32 Unk_35f000(u32 id, Unk_35f000_Obj** out, void* a2) {
    *out = nullptr;
    Unk_35ead0_Plugin* item = Unk_24bcb00.Exists(id);
    if (item == nullptr)
        return 0x58;
    *out = item->field_0(&Unk_2380d10);
    if (*out == nullptr)
        return 2;
    (*out)->vf4(a2);
    return 1;
}

// 0x710035f0e0
u32 Unk_35f0e0(void* allocator, u32 id, void** out) {
    *out = nullptr;
    Unk_35ead0_Plugin* item = Unk_24bcb00.Exists(id);
    if (item == nullptr)
        return 0x58;
    u32 result = 1;
    if (item->field_8 != nullptr) {
        void* params = item->field_8(allocator);
        result = params != nullptr ? 1 : 2;
        *out = params;
    }
    return result;
}

// 0x710035f190
void* Unk_35f190(void* a0, u32 kind, u32 id) {
    Unk_35ead0_Codec* item = Unk_24bcb10.Exists(id);
    if (item == nullptr)
        return nullptr;
    if (kind == 1)
        return item->field_0(a0);
    return item->field_8(a0);
}

// 0x710035f210
void* Unk_35f210(u32 id) {
    Unk_35ead0_Plugin* item = Unk_24bcb00.Exists(id);
    if (item == nullptr)
        return nullptr;
    return reinterpret_cast<void*>(item->field_0);
}

// 0x710035f280
u32 Unk_35f280(void*, u32 id, const u32* info) {
    if (info[1] < 0x7e101 || info[1] > 0x7e102)
        return 0x2e;
    return info[0] == id ? 0 : 10;
}


