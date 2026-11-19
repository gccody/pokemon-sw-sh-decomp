#pragma once
// A family of 45 pairs of classes (the first: Unk_23aa2c8 and Unk_23aa308,
// in game/bag), the same code for each pair (tools/registrygen.py):
//
// - the outer class, on Unk_23daca0: 11 entries, each of which can hold a
//   TLSF pool resource (Unk_239f910) made in a block of its memory resource.
//   vf2 makes entry 0's (0x71007bec20 is the function that does it), vf4
//   frees it and vf5 frees the other ten's. Its member at +0x28 is
// - the inner class, a registered object (Unk_236d228): one record of the
//   block (the resource made in it, the memory resource, the block and its
//   size), reached through a static pointer of its own while it lives.
//
// The originals are all inline, emitted in the TU of a factory that makes an
// object holding the outer class (0x71007be520 for the first). There the
// outer constructor and D2 are inline functions with callers, so LLVM 7's
// inliner defers (shouldBeDeferred) inlining the inner constructor into the
// outer one and Unk_236d228's D2 into the outer D2; the D0 inlines the D2
// and then Unk_236d228's D2 too. Here the outer class's key function is vf2
// (its vtable, D2, D0, vf4 and vf5 are emitted with it), its D2 is inline
// and the D0 calls it, which defers the same way; its constructor is out of
// line, and the inner constructor is defined in another TU so that it calls
// it. The outer destructor is user-declared: an implicit one gets clang's
// inline hint (threshold 325, not 250), and then nothing is deferred.
#include <new>

#include "unsorted/registry/Unk_236d228.h"
#include "unsorted/registry/Unk_23daca0.h"

// An entry of the outer class: what kind of resource it holds (only 0 is
// handled), the resource and a handle to it.
struct Unk_7be640_Entry {
    Unk_7be640_Entry() : field_8(nullptr) { Unk_7c2da0_set(&field_10); }

    u32 field_0;
    Unk_239f910* field_8;
    Unk_7c2da0 field_10;
};
PKMN_OFFSET_ASSERT(Unk_7be640_Entry, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_7be640_Entry, field_10, 0x10);
PKMN_SIZE_ASSERT(Unk_7be640_Entry, 0x20);

// The inner class's record: the resource, the memory resource its block
// came from, the block and its size (vf1, vf2 and vf3 of the inner class
// return or free them: src/unsorted/virtual).
struct Unk_7be720_Entry {
    Unk_239f910* field_0;
    Unk_239f910_Base* field_8;
    void* field_10;
    u64 field_18;
};
PKMN_OFFSET_ASSERT(Unk_7be720_Entry, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_7be720_Entry, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_7be720_Entry, field_18, 0x18);
PKMN_SIZE_ASSERT(Unk_7be720_Entry, 0x20);

// The inner destructor's body.
inline void Unk_7be720_Release(Unk_7be720_Entry& record) {
    if (record.field_10)
        record.field_0->vf23();
}

// 0x71007bec20's body: allocates the block, makes the resource at its start
// to manage the rest, and records both.
template <typename T>
inline Unk_239f910* Unk_7bec20_Body(T* const& instance,
                                    Unk_7be640_Entry* entry,
                                    const u32& kind,
                                    u64 size,
                                    Unk_239f910_Base* resource) {
    if (entry->field_8)
        nn::diag::detail::AbortImpl("", "", "", 0);
    entry->field_0 = kind;
    if (entry->field_0 != 0)
        abort();
    Unk_7be720_Entry& record = instance->m_entries[0];
    record.field_8 = resource;
    record.field_18 = size;
    record.field_10 = resource->vf2(size, 8);
    if (!record.field_10)
        record.field_8->vf23();
    Unk_239f910* pool =
        new (record.field_10) Unk_239f910(static_cast<u8*>(record.field_10) + sizeof(Unk_239f910),
                                          size - sizeof(Unk_239f910), nullptr);
    record.field_0 = pool;
    entry->field_8 = pool;
    Unk_7c2d90 handle;
    Unk_7c2d90_set(&handle, reinterpret_cast<u64>(pool));
    entry->field_10 = reinterpret_cast<Unk_7c2da0&>(handle);
    return entry->field_8;
}

// Destroys an entry's resource and frees its block.
template <typename T>
inline void Unk_7be640_Free(T* const& instance, Unk_7be640_Entry& entry) {
    if (entry.field_0 != 0)
        abort();
    Unk_7be720_Entry& record = instance->m_entries[0];
    record.field_0->~Unk_239f910();
    record.field_0 = nullptr;
    record.field_8->vf3(record.field_10, record.field_18, 8);
    record.field_10 = nullptr;
    record.field_18 = 0;
    record.field_8 = nullptr;
    entry.field_8 = nullptr;
}

// vf4's body (0x71007bea70): frees entry 0's resource if its handle lets go.
template <typename T>
inline bool Unk_7bea70_Body(T* const& instance, Unk_7be640_Entry& entry) {
    if (!entry.field_8)
        return true;
    if (!Unk_7c2db0(&entry.field_10, 0))
        return false;
    Unk_7be640_Free(instance, entry);
    return true;
}

// vf5's body (0x71007beb10): the same for the other ten, until one doesn't
// let go (each handle is still polled).
template <typename T>
inline bool Unk_7beb10_Body(T* const& instance, Unk_7be640_Entry (&entries)[10]) {
    bool ok = true;
    for (Unk_7be640_Entry& entry : entries) {
        if (!entry.field_8)
            continue;
        ok &= Unk_7c2db0(&entry.field_10, 0);
        if (ok)
            Unk_7be640_Free(instance, entry);
    }
    return ok;
}
