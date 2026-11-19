#pragma once
// What gflnet3's p2p channels send and receive their messages with: a
// protobuf message allocated from a gflib3 heap, accessed with that heap
// current, and a type-erased callable. Every data holder's channel uses them
// (gflnet3's sync, block and framework channels, and the game's in
// net_contents, battle_logic, btl_spot, pokecamp ...). Placeholder names:
// rename once the classes are known.
#include <memory>
#include <utility>

#include <types.h>

#include "gflib3/Unk_239a418.h"
#include "gflib3/Unk_65da00.h"
#include "unsorted/Unk_23f4660.h"
#include "unsorted/Unk_2771620.h"

// A message of type T and the heap it was made from (0x28 bytes). The
// message is accessed, and destroyed, with that heap current.
template <class T>
class Unk_6b8ad0_Message {
public:
    // The message with its heap current while the access lives.
    class Access {
    public:
        Access(T* ptr, Unk_239a418_Allocator* heap) : m_ptr(ptr), m_scope(heap, false, true) {}
        T* operator->() const { return m_ptr; }

    private:
        T* m_ptr;
        Unk_65da00_Scope m_scope;
    };

    explicit Unk_6b8ad0_Message(Unk_239a418_Allocator* heap) : m_heap(heap), m_ptr(Make(heap)) {}
    static std::unique_ptr<T, Unk_23f4660_Deleter> Make(Unk_239a418_Allocator* heap) {
        void* p = heap->vf2(sizeof(T), alignof(T));
        Unk_2771620_Scope scope(heap);
        return std::unique_ptr<T, Unk_23f4660_Deleter>(
            ::new (p) T(), Unk_23f4660_Deleter{heap, sizeof(T), alignof(T)});
    }
    Unk_6b8ad0_Message(Unk_6b8ad0_Message&& other) = default;
    ~Unk_6b8ad0_Message() {
        Unk_65da00_Scope scope(m_heap, false, true);
        m_ptr.reset();
    }

    Access operator->() const { return Access(m_ptr.get(), m_heap); }
    // The message itself, without the heap.
    T* get() const { return m_ptr.get(); }

    Unk_239a418_Allocator* m_heap;
    std::unique_ptr<T, Unk_23f4660_Deleter> m_ptr;
};

// A serialized message: bytes from a heap, freed with their size.
using Unk_6b8c00_Buffer = std::unique_ptr<u8[], Unk_23f4660_Deleter>;

// A type-erased callable, 0x80 bytes: an invoker (+0x0) that takes the
// storage (+0x20) and references to the arguments, and a manager (+0x8) like
// Unk_23d4470_Callable's (src/unsorted/Unk_23d4470.h), probably the same
// class. Callers test it before they call it.
template <class Signature>
class Unk_6b89b0_Callable;

template <class R, class... Args>
class Unk_6b89b0_Callable<R(Args...)> {
public:
    explicit operator bool() const { return field_0 != nullptr; }
    R operator()(Args... args) { return field_0(field_20, std::forward<Args>(args)...); }

    R (*field_0)(void* storage, Args&&... args);
    void (*field_8)(void*);
    u64 field_10;
    u64 field_18;
    u8 field_20[0x60];
};
