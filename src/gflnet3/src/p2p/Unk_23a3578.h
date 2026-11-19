#pragma once
// gflnet3's p2p channel (vtable 0x71023a3588, abstract): it sends a data
// holder message, serialized, through one of its two callables and hands the
// bytes it receives (slot 8) to its derived class, one per data holder
// (gflnet3's block and ping channels, the game's ...). The derived classes
// add no destructor and no type of their own: their vtables have the base's
// D2 (0x71006b7de0) and vf_type (0x71006b7f20). Placeholder names: rename
// once the classes are known.
#include <types.h>

#include "gflib3/Unk_239a418.h"
#include "gflnet3/src/p2p/Unk_6b8ad0.h"

class Unk_23a3578 : public Unk_239a418 {
public:
    ~Unk_23a3578() override;
    const Unk_239a418_Type* vf_type() override;
    virtual u16 vf7();
    // Receives a message's bytes from a peer.
    virtual void vf8(const void* data, int size, u64 peer) = 0;

    // Sends a message to one peer.
    template <class T>
    bool Unk_6b89b0(const Unk_6b8ad0_Message<T>& message, u64 peer);
    // Serializes a message into bytes from the channel's heap.
    template <class T>
    Unk_6b8c00_Buffer Unk_6b8c00(const Unk_6b8ad0_Message<T>& message);
    // Sends a message to every peer.
    template <class T>
    bool Unk_6b8d70(const Unk_6b8ad0_Message<T>& message);

    // Sends to one peer: the bytes, their size, the peer and vf7's id.
    Unk_6b89b0_Callable<bool(u8*, size_t, u64, u16)> field_60;
    // Sends to every peer.
    Unk_6b89b0_Callable<bool(u8*, size_t, u16)> field_e0;
    u16 field_160;
};
PKMN_OFFSET_ASSERT(Unk_23a3578, field_60, 0x60);
PKMN_OFFSET_ASSERT(Unk_23a3578, field_e0, 0xe0);
PKMN_OFFSET_ASSERT(Unk_23a3578, field_160, 0x160);

template <class T>
bool Unk_23a3578::Unk_6b8d70(const Unk_6b8ad0_Message<T>& message) {
    int size = message->ByteSize();
    Unk_6b8c00_Buffer buffer = Unk_6b8c00(message);
    if (!buffer)
        return false;
    if (!field_e0)
        return false;
    return field_e0(buffer.get(), size, vf7());
}
