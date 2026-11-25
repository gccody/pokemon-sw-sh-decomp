// Scope: common
// NintendoWare ui2d 7.3.2: the descriptor slots of an object that owns 37
// texture views, and the named objects of Unk_179c420.h and their lists.
// Placeholder names.
#include "nx_middleware/gfx/Unk_179c420.h"

// Called for each view and its descriptor slot.
using Unk_179c420_SlotFunction = void (*)(u64* slot, const void* view, void* userData);

void Unk_177ae80(void* self, Unk_179c420_SlotFunction function, void* userData);
void Unk_177aea0(void* self, Unk_179c420_SlotFunction function, void* userData);

// A texture view: only its size is known.
struct Unk_179c420_View {
    u8 _0[0x78];
};
PKMN_SIZE_ASSERT(Unk_179c420_View, 0x78);

struct Unk_179c420_Resource {
    u8 _0[0x80];
    void* field_80;
    u8 _88[0x258 - 0x88];
    Unk_179c420_View* views;
    u64* slots;
};
PKMN_OFFSET_ASSERT(Unk_179c420_Resource, field_80, 0x80);
PKMN_OFFSET_ASSERT(Unk_179c420_Resource, views, 0x258);
PKMN_OFFSET_ASSERT(Unk_179c420_Resource, slots, 0x260);

static const int Unk_179c420_ViewCount = 37;

// NON_MATCHING: instruction scheduling: the original computes each view's address before it loads the slot array
// 0x710179c420
void Unk_179c420(Unk_179c420_Resource* self, Unk_179c420_SlotFunction function, void* userData) {
    Unk_177ae80(self->field_80, function, userData);
    for (int i = 0; i < Unk_179c420_ViewCount; i++) {
        const Unk_179c420_View* view = &self->views[i];
        function(&self->slots[i], view, userData);
    }
}

// NON_MATCHING: instruction scheduling: the original computes each view's address before it loads the slot array
// 0x710179c860
void Unk_179c860(Unk_179c420_Resource* self, Unk_179c420_SlotFunction function, void* userData) {
    Unk_177aea0(self->field_80, function, userData);
    for (int i = 0; i < Unk_179c420_ViewCount; i++) {
        const Unk_179c420_View* view = &self->views[i];
        u64* slot = &self->slots[i];
        function(slot, view, userData);
        *slot = ~0ull;
    }
}

// 0x710179c8e0
u64* Unk_179c8e0(Unk_179c420_Resource* self, int a, int b, int c, int d) {
    int index = a * 12 + b * 4 + c + d * 2;
    return &self->slots[index];
}

// 0x710179c900
u64* Unk_179c900(Unk_179c420_Resource* self, int index) {
    return &self->slots[index];
}

// 0x710179c910
Unk_24931a0::Unk_24931a0() : name(""), field_30(false) {}

// 0x710179c940
Unk_24931a0::Unk_24931a0(const Unk_179c940_Res* res, Unk_179c940_Finder* finder) : name(res->name), field_30(false) {
    for (int i = 0; i < res->count; i++) {
        void* target = finder->vf12(res->elementNames[i], true);
        if (target != nullptr) {
            Unk_179ca10(target);
        }
    }
}

// 0x710179ca10
void Unk_24931a0::Unk_179ca10(void* target) {
    Element* element = static_cast<Element*>(Unk_179cd10(sizeof(Element)));
    if (element != nullptr) {
        element->link.InitializeLinks();
        element->target = target;
        elements.push_back(&element->link);
    }
}

// NON_MATCHING: the original keeps the erase's end() check before each unlink; clang folds it here, as the loop condition implies it (and so in the deleting destructor, 0x710179cad0)
// 0x710179ca60
Unk_24931a0::~Unk_24931a0() {
    for (Unk_179cc10_ListNode* node = elements.begin(); elements.end() != node;) {
        Unk_179cc10_ListNode* current = node;
        node = elements.erase(current);
        Unk_179cd30(reinterpret_cast<u64>(current));
    }
}

// NON_MATCHING: the original keeps the erase's end() check before each unlink; clang folds it here, as the loop condition implies it
// 0x710179cb50
void Unk_179cb50(Unk_179cc10_List* list) {
    for (Unk_179cc10_ListNode* node = list->begin(); list->end() != node;) {
        Unk_179cc10_ListNode* current = node;
        node = list->erase(current);
        Unk_24931a0* object = Unk_24931a0::FromLink(current);
        if (!object->field_30) {
            object->~Unk_24931a0();
            Unk_179cd30(reinterpret_cast<u64>(object));
        }
    }
}

// 0x710179cbf0
void Unk_179cbf0(Unk_179cc10_List* list, Unk_24931a0* object) {
    list->push_back(&object->link);
}
