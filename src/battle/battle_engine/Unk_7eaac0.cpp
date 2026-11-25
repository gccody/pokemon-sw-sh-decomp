// Scope: common
// The event system's handler pool (0x71007eab50 to 0x71007eb2f0): a fixed
// array of handler nodes, the list of registered handlers (sorted by
// priority) and the list of free nodes, then more 16-bit ID classifiers.
// Placeholder names: rename once the functions are known.
#include <types.h>

struct Unk_7e9b00_Node;

// One pooled node, and where it was allocated (gflib3), as in
// battle/battle_engine/Unk_7e89c0.h's Unk_7ea110_Entry.
struct Unk_7eaac0_Entry {
    Unk_7e9b00_Node* field_0;
    void* field_8;
    u64 field_10;
    u64 field_18;
};
PKMN_SIZE_ASSERT(Unk_7eaac0_Entry, 0x20);

// The pool (vtable 0x71023ac7f8).
struct Unk_7eaac0_Pool {
    void* field_0;
    Unk_7eaac0_Entry field_8[0xac];
    Unk_7e9b00_Node* field_1588;  // registered handlers, highest priority first
    Unk_7e9b00_Node* field_1590;  // free nodes
};
PKMN_OFFSET_ASSERT(Unk_7eaac0_Pool, field_1588, 0x1588);
PKMN_OFFSET_ASSERT(Unk_7eaac0_Pool, field_1590, 0x1590);

struct Unk_7e99b0_Self;
void Unk_7e99b0(Unk_7e99b0_Self* self, const Unk_7e99b0_Self* other);
void Unk_7e9b00(Unk_7e9b00_Node* self, Unk_7e9b00_Node* next);
void Unk_7e9b10(Unk_7e9b00_Node* self);
void Unk_7e9c80(Unk_7e9b00_Node* self, bool value);

// The node's leaf getters and setters (src/unsorted/leaf/Unk_7e89c0.cpp),
// with their own placeholder types.
struct Unk_7e9970;
void Unk_7e9970_set(Unk_7e9970* self);
struct Unk_7e99e0;
u16 Unk_7e99e0_getField8(const Unk_7e99e0* self);
struct Unk_7e9b30;
Unk_7e9b00_Node* Unk_7e9b30_getField18(const Unk_7e9b30* self);
struct Unk_7e9b40;
Unk_7e9b00_Node* Unk_7e9b40_getField10(const Unk_7e9b40* self);
struct Unk_7e9b60;
void Unk_7e9b60_setField3c(Unk_7e9b60* self, u16 value);
struct Unk_7e9b70;
u8 Unk_7e9b70_getField30(const Unk_7e9b70* self);
struct Unk_7e9b80;
u32 Unk_7e9b80_getField34(const Unk_7e9b80* self);
struct Unk_7e9b90;
u8 Unk_7e9b90_getField3a(const Unk_7e9b90* self);
struct Unk_7e9ba0;
u16 Unk_7e9ba0_getField38(const Unk_7e9ba0* self);
struct Unk_7e9bb0;
bool Unk_7e9bb0_get(const Unk_7e9bb0* self);
struct Unk_7e9bc0;
bool Unk_7e9bc0_get(const Unk_7e9bc0* self);
struct Unk_7e9c30;
void Unk_7e9c30_setField30(Unk_7e9c30* self, u8 value);
struct Unk_7e9c40;
void Unk_7e9c40_setField34(Unk_7e9c40* self, u32 value);
struct Unk_7e9c50;
void Unk_7e9c50_setField38(Unk_7e9c50* self, u16 value);
struct Unk_7e9c60;
void Unk_7e9c60_setField3a(Unk_7e9c60* self, u8 value);
struct Unk_7e9c70;
void Unk_7e9c70_setField3b(Unk_7e9c70* self, u8 value);
struct Unk_7e9ce0;
void Unk_7e9ce0_set(Unk_7e9ce0* self, u64 value, u8 arg2);

extern const u16 Unk_1f108fc[86] __attribute__((visibility("hidden")));

static inline Unk_7e9b00_Node* Unk_7eaac0_Next(const Unk_7e9b00_Node* node) {
    return Unk_7e9b30_getField18(reinterpret_cast<const Unk_7e9b30*>(node));
}

static inline Unk_7e9b00_Node* Unk_7eaac0_Prev(const Unk_7e9b00_Node* node) {
    return Unk_7e9b40_getField10(reinterpret_cast<const Unk_7e9b40*>(node));
}

static inline u32 Unk_7eaac0_Priority(const Unk_7e9b00_Node* node) {
    return Unk_7e9b80_getField34(reinterpret_cast<const Unk_7e9b80*>(node));
}

static inline u8 Unk_7eaac0_Kind(const Unk_7e9b00_Node* node) {
    return Unk_7e9b70_getField30(reinterpret_cast<const Unk_7e9b70*>(node));
}

static inline u8 Unk_7eaac0_Owner(const Unk_7e9b00_Node* node) {
    return Unk_7e9b90_getField3a(reinterpret_cast<const Unk_7e9b90*>(node));
}

static inline void Unk_7eaac0_Reset(Unk_7e9b00_Node* node) {
    Unk_7e9970_set(reinterpret_cast<Unk_7e9970*>(node));
}

void Unk_7eac70(Unk_7eaac0_Pool* self, Unk_7e9b00_Node* node);

// 0x71007eab50
void Unk_7eab50(Unk_7eaac0_Pool* self, const Unk_7eaac0_Pool* other) {
    self->field_1590 = nullptr;
    self->field_1588 = nullptr;
    for (s32 i = 0; i < 0xac; i++) {
        Unk_7e9b00_Node* node = self->field_8[i].field_0;
        Unk_7e9b10(node);
        Unk_7eaac0_Reset(node);
        Unk_7e9b00(node, self->field_1590);
        self->field_1590 = node;
    }
    for (s32 i = 0; i < 0xac; i++) {
        Unk_7e99b0(reinterpret_cast<Unk_7e99b0_Self*>(self->field_8[i].field_0),
                   reinterpret_cast<const Unk_7e99b0_Self*>(other->field_8[i].field_0));
    }
    for (Unk_7e9b00_Node* node = other->field_1588; node != nullptr; node = Unk_7eaac0_Next(node)) {
        u16 label = Unk_7e99e0_getField8(reinterpret_cast<const Unk_7e99e0*>(node));
        for (Unk_7e9b00_Node* free = self->field_1590; free != nullptr;
             free = Unk_7eaac0_Next(free)) {
            if (Unk_7e99e0_getField8(reinterpret_cast<const Unk_7e99e0*>(free)) == label) {
                if (self->field_1590 == free)
                    self->field_1590 = Unk_7eaac0_Next(free);
                Unk_7e9b10(free);
                Unk_7eac70(self, free);
                break;
            }
        }
    }
}

// NON_MATCHING: register allocation: the original keeps the walked node in
// x20 and self in x21, without the copy between them in the loop.
// 0x71007eac70
void Unk_7eac70(Unk_7eaac0_Pool* self, Unk_7e9b00_Node* node) {
    if (self->field_1588 != nullptr) {
        if (Unk_7eaac0_Priority(self->field_1588) >= Unk_7eaac0_Priority(node)) {
            Unk_7e9b00_Node* current = self->field_1588;
            Unk_7e9b00_Node* next;
            while ((next = Unk_7eaac0_Next(current)) != nullptr) {
                if (Unk_7eaac0_Priority(next) < Unk_7eaac0_Priority(node)) {
                    Unk_7e9b00(Unk_7eaac0_Prev(next), node);
                    Unk_7e9b00(node, next);
                    return;
                }
                current = next;
            }
            Unk_7e9b00(current, node);
            return;
        }
        Unk_7e9b00(node, self->field_1588);
    }
    self->field_1588 = node;
}

// 0x71007ead40
void Unk_7ead40(Unk_7eaac0_Pool* self) {
    Unk_7e9b00_Node* node = self->field_1588;
    while (node != nullptr) {
        Unk_7e9b00_Node* next = Unk_7eaac0_Next(node);
        Unk_7e9b10(node);
        Unk_7eaac0_Reset(node);
        Unk_7e9b00(node, self->field_1590);
        self->field_1590 = node;
        node = next;
    }
    self->field_1588 = nullptr;
}

// NON_MATCHING: the original computes the priority as 0xa000000 + (~arg3 << 24)
// (mvn/add), and doesn't duplicate the Unk_7e9970_set call into the paths of
// the switch.
// 0x71007eadb0
Unk_7e9b00_Node* Unk_7eadb0(void* self,
                            u32 arg1,
                            u32 arg2,
                            u32 arg3,
                            u32 arg4,
                            u32 arg5,
                            void* arg6,
                            u32 arg7,
                            u16 depth) {
    Unk_7eaac0_Pool* pool = static_cast<Unk_7eaac0_Pool*>(self);
    Unk_7e9b00_Node* node = pool->field_1590;
    if (node == nullptr)
        return nullptr;
    pool->field_1590 = Unk_7eaac0_Next(node);
    Unk_7e9b10(node);
    u32 priority = ((9 - arg3) << 24) | arg4;

    u8 field_3b = 0x1f;
    switch (static_cast<u8>(arg1)) {
        case 0:
        case 4:
        case 5:
            field_3b = arg5;
            break;
    }
    Unk_7eaac0_Reset(node);
    Unk_7e9c40_setField34(reinterpret_cast<Unk_7e9c40*>(node), priority);
    Unk_7e9c30_setField30(reinterpret_cast<Unk_7e9c30*>(node), arg1);
    Unk_7e9ce0_set(reinterpret_cast<Unk_7e9ce0*>(node), reinterpret_cast<u64>(arg6), arg7);
    Unk_7e9c60_setField3a(reinterpret_cast<Unk_7e9c60*>(node), arg5);
    Unk_7e9c50_setField38(reinterpret_cast<Unk_7e9c50*>(node), arg2);
    Unk_7e9c70_setField3b(reinterpret_cast<Unk_7e9c70*>(node), field_3b);
    Unk_7e9b60_setField3c(reinterpret_cast<Unk_7e9b60*>(node), depth);
    Unk_7e9c80(node, true);
    Unk_7eac70(pool, node);
    return node;
}

// 0x71007eaee0
void Unk_7eaee0(void* self, Unk_7e9b00_Node* node) {
    Unk_7eaac0_Pool* pool = static_cast<Unk_7eaac0_Pool*>(self);
    if (pool->field_1588 == node)
        pool->field_1588 = Unk_7eaac0_Next(node);
    Unk_7e9b10(node);
    Unk_7eaac0_Reset(node);
    Unk_7e9b00(node, pool->field_1590);
    pool->field_1590 = node;
}

// 0x71007eaf50
Unk_7e9b00_Node* Unk_7eaf50(const Unk_7eaac0_Pool* self, u8 kind) {
    for (Unk_7e9b00_Node* node = self->field_1588; node != nullptr; node = Unk_7eaac0_Next(node)) {
        if (Unk_7e9bb0_get(reinterpret_cast<const Unk_7e9bb0*>(node)) &&
            Unk_7eaac0_Kind(node) == kind &&
            !Unk_7e9bc0_get(reinterpret_cast<const Unk_7e9bc0*>(node)))
            return node;
    }
    return nullptr;
}

// 0x71007eafc0
Unk_7e9b00_Node* Unk_7eafc0(const Unk_7eaac0_Pool* self, u8 kind, u8 owner) {
    for (Unk_7e9b00_Node* node = self->field_1588; node != nullptr; node = Unk_7eaac0_Next(node)) {
        if (Unk_7e9bb0_get(reinterpret_cast<const Unk_7e9bb0*>(node)) &&
            Unk_7eaac0_Kind(node) == kind && Unk_7eaac0_Owner(node) == owner &&
            !Unk_7e9bc0_get(reinterpret_cast<const Unk_7e9bc0*>(node)))
            return node;
    }
    return nullptr;
}

// 0x71007eb050
Unk_7e9b00_Node* Unk_7eb050(const Unk_7eaac0_Pool* /*self*/,
                            Unk_7e9b00_Node* after,
                            bool anyOwner) {
    if (after == nullptr)
        return nullptr;
    u8 kind = Unk_7eaac0_Kind(after);
    u8 owner = Unk_7eaac0_Owner(after);
    for (Unk_7e9b00_Node* node = Unk_7eaac0_Next(after); node != nullptr;
         node = Unk_7eaac0_Next(node)) {
        if (Unk_7eaac0_Kind(node) == kind && (anyOwner || Unk_7eaac0_Owner(node) == owner) &&
            !Unk_7e9bc0_get(reinterpret_cast<const Unk_7e9bc0*>(node)))
            return node;
    }
    return nullptr;
}

// 0x71007eb130
u32 Unk_7eb130(void* self, u8 arg1, u8 arg2, u32 arg3) {
    const Unk_7eaac0_Pool* pool = static_cast<const Unk_7eaac0_Pool*>(self);
    for (Unk_7e9b00_Node* node = pool->field_1588; node != nullptr; node = Unk_7eaac0_Next(node)) {
        if (Unk_7eaac0_Kind(node) == 2 &&
            Unk_7e9ba0_getField38(reinterpret_cast<const Unk_7e9ba0*>(node)) == arg3) {
            u8 owner = Unk_7eaac0_Owner(node);
            if (owner == arg1)
                Unk_7e9c60_setField3a(reinterpret_cast<Unk_7e9c60*>(node), arg2);
            else if (owner == arg2)
                Unk_7e9c60_setField3a(reinterpret_cast<Unk_7e9c60*>(node), arg1);
        }
    }
    return 0;
}

// 0x71007eb1e0
bool Unk_7eb1e0(u16 value) {
    for (u32 i = 0; i < 86; i++) {
        if (Unk_1f108fc[i] == value)
            return true;
    }
    return false;
}

// 0x71007eb230
bool Unk_7eb230(u16 value) {
    static const u16 kValues[] = {0, 0x161, 0xf8};
    for (u32 i = 0; i < 3; i++) {
        if (kValues[i] == value)
            return true;
    }
    return false;
}

// NON_MATCHING: the orr takes its operands the other way round.
// 0x71007eb260
bool Unk_7eb260(u32 value) {
    u16 id = value;
    return (id >= 0x2f5 && id <= 0x306) || id == 0x2e7;
}

// 0x71007eb290
bool Unk_7eb290(u16 value) {
    return value >= 0x2f5 && value <= 0x306;
}

// NON_MATCHING: the original tests the upper three cases as 0x121, 0x1be,
// 0x186 (this clang sorts them by value).
// 0x71007eb2b0
bool Unk_7eb2b0(u16 value) {
    switch (value) {
        case 0xbf:
        case 0x11e:
        case 0x121:
        case 0x186:
        case 0x1be:
            return true;
    }
    return false;
}
