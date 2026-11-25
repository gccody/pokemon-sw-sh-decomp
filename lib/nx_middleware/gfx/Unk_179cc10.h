#pragma once

// NintendoWare ui2d 7.3.2 (its SDK MW tag is referenced from Sword
// 0x710179cc70): the allocator that nn::ui2d::Layout's static functions
// use, and the list nodes of its objects. Placeholder names.
#include <types.h>

using Unk_179cc10_AllocateFunction = void* (*)(size_t size, size_t alignment, void* userData);
using Unk_179cc10_FreeFunction = void (*)(void* ptr, void* userData);

extern Unk_179cc10_AllocateFunction Unk_27fd788;
extern Unk_179cc10_FreeFunction Unk_27fd790;
extern void* Unk_27fd798;

void Unk_179ccc0(Unk_179cc10_AllocateFunction allocateFunction, Unk_179cc10_FreeFunction freeFunction,
                 void* userData);
void* Unk_179ccf0(size_t size, size_t alignment);
void* Unk_179cd10(size_t size);
void Unk_179cd30(u64 ptr);

// A node of a circular doubly linked list. A list is a node of its own (its
// root), which links its first and last elements.
struct Unk_179cc10_ListNode {
    Unk_179cc10_ListNode* prev;
    Unk_179cc10_ListNode* next;

    Unk_179cc10_ListNode() { InitializeLinks(); }

    void InitializeLinks() {
        prev = this;
        next = this;
    }

    // Links the ring that starts at `first` in before this node.
    void LinkPrev(Unk_179cc10_ListNode* first) {
        Unk_179cc10_ListNode* last = first->prev;
        first->prev = prev;
        last->next = this;
        prev->next = first;
        prev = last;
    }

    // Unlinks this node up to `end` (excluded), into a ring of its own.
    void Unlink(Unk_179cc10_ListNode* end) {
        Unk_179cc10_ListNode* last = end->prev;
        prev->next = end;
        end->prev = prev;
        last->next = this;
        prev = last;
    }
};
PKMN_SIZE_ASSERT(Unk_179cc10_ListNode, 0x10);

struct Unk_179cc10_List {
    Unk_179cc10_ListNode root;

    Unk_179cc10_ListNode* begin() { return root.next; }
    Unk_179cc10_ListNode* end() { return &root; }
    bool empty() const { return root.next == &root; }
    void push_back(Unk_179cc10_ListNode* node) { root.LinkPrev(node); }

    Unk_179cc10_ListNode* erase(Unk_179cc10_ListNode* node) {
        Unk_179cc10_ListNode* next = node->next;
        if (node != end()) {
            node->Unlink(next);
        }
        return next;
    }
};
PKMN_SIZE_ASSERT(Unk_179cc10_List, 0x10);
