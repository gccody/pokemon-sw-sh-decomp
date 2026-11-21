// Scope: common
// Families of Wwise functions with the same code except for constants (index
// offsets, adjustments, field offsets): one template per family, and each
// instance with the original's constants. Placeholder names.
#include "Unk_Indexed.h"

void operator delete(void* ptr) noexcept;

template <u32 Offset>
static inline u32 Unk_IndexedAddRef(Unk_Indexed* self) {
    Unk_Index* index = Unk_GetIndex<Offset>();
    nn::os::LockMutex(&index->field_0);
    u32 count = ++self->field_14;
    nn::os::UnlockMutex(&index->field_0);
    return count;
}

template <u32 Offset>
static inline u32 Unk_IndexedRelease(Unk_Indexed* self) {
    Unk_Index* index = Unk_GetIndex<Offset>();
    nn::os::LockMutex(&index->field_0);
    u32 count = --self->field_14;
    if (count == 0) {
        Unk_GetIndex<Offset>()->Remove(self->field_10);
        if (self != nullptr) {
            int pool = Unk_237e820;
            self->~Unk_Indexed();
            Unk_3047c0(pool, self);
        }
    }
    nn::os::UnlockMutex(&index->field_0);
    return count;
}

// A plugin and its allocator: plugins delete themselves through it.
struct Unk_PluginAlloc {
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3(void* ptr);  // free
};

struct Unk_Plugin {
    virtual ~Unk_Plugin();
};

void Unk_3101f0(void* self);
void Unk_313160(void* self);
void Unk_3191e0(void* self);
void Unk_3627c0(void* self);
void Unk_3d17f0(void* self);
void Unk_3d4310(void* self);
void Unk_3e1e50(void* self);
void Unk_3fb3e0(void* self);
void Unk_3fc0a0(void* self);

// 0x710033db90
u32 Unk_33db90(Unk_Indexed* self) {
    return Unk_IndexedAddRef<0xe0>(self);
}

// 0x710034cea0
u32 Unk_34cea0(Unk_Indexed* self) {
    return Unk_IndexedAddRef<0x150>(self);
}

// 0x710035c310
u32 Unk_35c310(Unk_Indexed* self) {
    return Unk_IndexedAddRef<0x1f8>(self);
}

// 0x710035f6f0
u32 Unk_35f6f0(Unk_Indexed* self) {
    return Unk_IndexedAddRef<0xa8>(self);
}

// 0x7100360d40
u32 Unk_360d40(Unk_Indexed* self) {
    return Unk_IndexedAddRef<0x230>(self);
}

// 0x7100360fe0
u32 Unk_360fe0(Unk_Indexed* self) {
    return Unk_IndexedAddRef<0x2a0>(self);
}

// 0x7100361280
u32 Unk_361280(Unk_Indexed* self) {
    return Unk_IndexedAddRef<0x268>(self);
}

// 0x7100366bc0
u32 Unk_366bc0(Unk_Indexed* self) {
    return Unk_IndexedAddRef<0x118>(self);
}

// 0x710036d3a0
u32 Unk_36d3a0(Unk_Indexed* self) {
    return Unk_IndexedAddRef<0x188>(self);
}

// 0x71003b1b00
u32 Unk_3b1b00(Unk_Indexed* self) {
    return Unk_IndexedAddRef<0x70>(self);
}

// 0x71003c1d70
u32 Unk_3c1d70(Unk_Indexed* self) {
    return Unk_IndexedAddRef<0x2d8>(self);
}

// 0x710034cf00
u32 Unk_34cf00(Unk_Indexed* self) {
    return Unk_IndexedRelease<0x150>(self);
}

// 0x710035c370
u32 Unk_35c370(Unk_Indexed* self) {
    return Unk_IndexedRelease<0x1f8>(self);
}

// 0x710035f750
u32 Unk_35f750(Unk_Indexed* self) {
    return Unk_IndexedRelease<0xa8>(self);
}

// 0x7100360da0
u32 Unk_360da0(Unk_Indexed* self) {
    return Unk_IndexedRelease<0x230>(self);
}

// 0x7100361040
u32 Unk_361040(Unk_Indexed* self) {
    return Unk_IndexedRelease<0x2a0>(self);
}

// 0x71003612e0
u32 Unk_3612e0(Unk_Indexed* self) {
    return Unk_IndexedRelease<0x268>(self);
}

// 0x7100366c20
u32 Unk_366c20(Unk_Indexed* self) {
    return Unk_IndexedRelease<0x118>(self);
}

// 0x710036d400
u32 Unk_36d400(Unk_Indexed* self) {
    return Unk_IndexedRelease<0x188>(self);
}

// 0x71003b1b60
u32 Unk_3b1b60(Unk_Indexed* self) {
    return Unk_IndexedRelease<0x70>(self);
}

// 0x71003c1dd0
u32 Unk_3c1dd0(Unk_Indexed* self) {
    return Unk_IndexedRelease<0x2d8>(self);
}

// 0x710030fdd0
void Unk_30fdd0(void* self) {
    void* object = static_cast<u8*>(self) - 0x18;
    Unk_3191e0(object);
    operator delete(object);
}

// 0x7100310310
void Unk_310310(void* self) {
    void* object = static_cast<u8*>(self) - 0x18;
    Unk_3101f0(object);
    operator delete(object);
}

// 0x7100313330
void Unk_313330(void* self) {
    void* object = static_cast<u8*>(self) - 0x18;
    Unk_313160(object);
    operator delete(object);
}

// 0x7100362790
void Unk_362790(void* self) {
    void* object = static_cast<u8*>(self) - 0x18;
    Unk_3627c0(object);
    operator delete(object);
}

// 0x7100362930
void Unk_362930(void* self) {
    void* object = static_cast<u8*>(self) - 0x18;
    Unk_3627c0(object);
    operator delete(object);
}

// 0x71003629b0
void Unk_3629b0(void* self) {
    void* object = static_cast<u8*>(self) - 0x18;
    Unk_3627c0(object);
    operator delete(object);
}

// 0x71003d1bf0
void Unk_3d1bf0(void* self) {
    void* object = static_cast<u8*>(self) - 0xc0;
    Unk_3d17f0(object);
    operator delete(object);
}

// 0x71003d4400
void Unk_3d4400(void* self) {
    void* object = static_cast<u8*>(self) - 0xc0;
    Unk_3d4310(object);
    operator delete(object);
}

// 0x71003e2000
void Unk_3e2000(void* self) {
    void* object = static_cast<u8*>(self) - 0x58;
    Unk_3e1e50(object);
    operator delete(object);
}

// 0x71003e2030
void Unk_3e2030(void* self) {
    void* object = static_cast<u8*>(self) - 0x70;
    Unk_3e1e50(object);
    operator delete(object);
}

// 0x7100400560
void Unk_400560(void* self) {
    void* object = static_cast<u8*>(self) - 0x70;
    Unk_3fb3e0(object);
    operator delete(object);
}

// 0x71004009b0
void Unk_4009b0(void* self) {
    void* object = static_cast<u8*>(self) - 0x70;
    Unk_3fc0a0(object);
    operator delete(object);
}

struct Unk_31b540 {
    Unk_Array<void*> field_0;
};
PKMN_OFFSET_ASSERT(Unk_31b540, field_0, 0x0);

// 0x710031b540
void Unk_31b540_call(Unk_31b540* self) {
    self->field_0.Term();
}

struct Unk_335900 {
    u8 _0[0xa0];
    Unk_Array<void*> field_a0;
};
PKMN_OFFSET_ASSERT(Unk_335900, field_a0, 0xa0);

// 0x7100335900
void Unk_335900_call(Unk_335900* self) {
    self->field_a0.Term();
}

struct Unk_34a7c0 {
    Unk_Array<void*> field_0;
};
PKMN_OFFSET_ASSERT(Unk_34a7c0, field_0, 0x0);

// 0x710034a7c0
void Unk_34a7c0_call(Unk_34a7c0* self) {
    self->field_0.Term();
}

struct Unk_379fa0 {
    u8 _0[0xc8];
    Unk_Array<void*> field_c8;
};
PKMN_OFFSET_ASSERT(Unk_379fa0, field_c8, 0xc8);

// 0x7100379fa0
void Unk_379fa0_call(Unk_379fa0* self) {
    self->field_c8.Term();
}

struct Unk_38ebd0 {
    Unk_Array<void*> field_0;
};
PKMN_OFFSET_ASSERT(Unk_38ebd0, field_0, 0x0);

// 0x710038ebd0
void Unk_38ebd0_call(Unk_38ebd0* self) {
    self->field_0.Term();
}

struct Unk_397570 {
    u8 _0[0x30];
    Unk_Array<void*> field_30;
};
PKMN_OFFSET_ASSERT(Unk_397570, field_30, 0x30);

// 0x7100397570
void Unk_397570_call(Unk_397570* self) {
    self->field_30.Term();
}

struct Unk_3bd6f0 {
    u8 _0[0x28];
    Unk_Array<void*> field_28;
};
PKMN_OFFSET_ASSERT(Unk_3bd6f0, field_28, 0x28);

// 0x71003bd6f0
void Unk_3bd6f0_call(Unk_3bd6f0* self) {
    self->field_28.Term();
}

// 0x7100303710
u32 Unk_303710(Unk_Plugin* self, Unk_PluginAlloc* alloc) {
    if (self != nullptr) {
        self->~Unk_Plugin();
        alloc->vf3(self);
    }
    return 1;
}

// 0x71003042e0
u32 Unk_3042e0(Unk_Plugin* self, Unk_PluginAlloc* alloc) {
    if (self != nullptr) {
        self->~Unk_Plugin();
        alloc->vf3(self);
    }
    return 1;
}

// 0x710031f940
u32 Unk_31f940(Unk_Plugin* self, Unk_PluginAlloc* alloc) {
    if (self != nullptr) {
        self->~Unk_Plugin();
        alloc->vf3(self);
    }
    return 1;
}

// 0x7100321c20
u32 Unk_321c20(Unk_Plugin* self, Unk_PluginAlloc* alloc) {
    if (self != nullptr) {
        self->~Unk_Plugin();
        alloc->vf3(self);
    }
    return 1;
}

// 0x710032a3a0
u32 Unk_32a3a0(Unk_Plugin* self, Unk_PluginAlloc* alloc) {
    if (self != nullptr) {
        self->~Unk_Plugin();
        alloc->vf3(self);
    }
    return 1;
}

// 0x710032b800
u32 Unk_32b800(Unk_Plugin* self, Unk_PluginAlloc* alloc) {
    if (self != nullptr) {
        self->~Unk_Plugin();
        alloc->vf3(self);
    }
    return 1;
}

// 0x710032b9b0
u32 Unk_32b9b0(Unk_Plugin* self, Unk_PluginAlloc* alloc) {
    if (self != nullptr) {
        self->~Unk_Plugin();
        alloc->vf3(self);
    }
    return 1;
}

// 0x71003a5b50
u32 Unk_3a5b50(Unk_Plugin* self, Unk_PluginAlloc* alloc) {
    if (self != nullptr) {
        self->~Unk_Plugin();
        alloc->vf3(self);
    }
    return 1;
}

// 0x71003a5d00
u32 Unk_3a5d00(Unk_Plugin* self, Unk_PluginAlloc* alloc) {
    if (self != nullptr) {
        self->~Unk_Plugin();
        alloc->vf3(self);
    }
    return 1;
}

// 0x71003f7750
u32 Unk_3f7750(Unk_Plugin* self, Unk_PluginAlloc* alloc) {
    if (self != nullptr) {
        self->~Unk_Plugin();
        alloc->vf3(self);
    }
    return 1;
}
