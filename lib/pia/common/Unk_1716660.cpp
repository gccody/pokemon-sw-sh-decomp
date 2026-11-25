// Scope: common
// pead's intrusive list (no RTTI): linking and unlinking a node, clearing a
// list and sorting it. A TU of its own: pead::Thread (Unk_17219c0.cpp) and
// pead::ExpHeap (Unk_17167f0.cpp) call these out of line. Names are
// placeholders (lib/pia/README.md).
#include <types.h>

// A node: the previous one, then the next one.
struct Unk_17166a0_arg0 {
    Unk_17166a0_arg0* field_0;
    Unk_17166a0_arg0* field_8;
};
PKMN_SIZE_ASSERT(Unk_17166a0_arg0, 0x10);

// A list: its head (the first node is the head's next) and how many nodes it
// holds.
struct Unk_17166d0_arg0 {
    Unk_17166a0_arg0 field_0;
    int field_10;
};
PKMN_OFFSET_ASSERT(Unk_17166d0_arg0, field_10, 0x10);

// 0x7101716660: links `node` in after `self`.
void Unk_1716660(Unk_17166a0_arg0* self, Unk_17166a0_arg0* node) {
    Unk_17166a0_arg0* next = self->field_8;
    self->field_8 = node;
    node->field_0 = self;
    node->field_8 = next;
    if (next != nullptr) {
        next->field_0 = node;
    }
}

// 0x7101716680: links `node` in before `self`.
void Unk_1716680(Unk_17166a0_arg0* self, Unk_17166a0_arg0* node) {
    Unk_17166a0_arg0* prev = self->field_0;
    self->field_0 = node;
    node->field_0 = prev;
    node->field_8 = self;
    if (prev != nullptr) {
        prev->field_8 = node;
    }
}

// 0x71017166a0
void Unk_17166a0(Unk_17166a0_arg0* node) {
    Unk_17166a0_arg0* prev = node->field_0;
    if (prev != nullptr) {
        prev->field_8 = node->field_8;
    }
    Unk_17166a0_arg0* next = node->field_8;
    if (next != nullptr) {
        next->field_0 = prev;
    }
    node->field_0 = nullptr;
    node->field_8 = nullptr;
}

// 0x71017166d0
void Unk_17166d0(Unk_17166d0_arg0* self) {
    Unk_17166a0_arg0* node = self->field_0.field_8;
    while (node != &self->field_0) {
        Unk_17166a0_arg0* next = node->field_8;
        node->field_0 = nullptr;
        node->field_8 = nullptr;
        node = next;
    }
    self->field_10 = 0;
    self->field_0.field_0 = &self->field_0;
    self->field_0.field_8 = &self->field_0;
}

static inline const void* Unk_addOffset(const void* pointer, long offset) {
    return static_cast<const u8*>(pointer) + offset;
}

// NON_MATCHING: the original drops the moved node's previous link's reset
// (only `str xzr, [node, #8]` before it's relinked); this keeps both (`stp`).
// 0x7101716700: an insertion sort. `offset` is where the node is in the
// objects `compare` is given.
void Unk_1716700(Unk_17166d0_arg0* self, int offset, int (*compare)(const void*, const void*)) {
    if (self->field_10 < 2) {
        return;
    }
    Unk_17166a0_arg0* node = self->field_0.field_8->field_8;
    while (node != &self->field_0) {
        Unk_17166a0_arg0* next = node->field_8;
        Unk_17166a0_arg0* prev = node->field_0;
        const void* object = Unk_addOffset(node, -offset);
        if (compare(Unk_addOffset(prev, -offset), object) > 0) {
            do {
                prev = prev->field_0;
            } while (prev != &self->field_0 &&
                     compare(Unk_addOffset(prev, -offset), object) > 0);
            Unk_17166a0(node);
            Unk_1716660(prev, node);
        }
        node = next;
    }
}
