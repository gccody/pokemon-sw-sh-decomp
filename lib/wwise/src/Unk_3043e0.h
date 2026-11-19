#pragma once
// Wwise's memory manager: an array of pools, each a TLSF heap (lib/tlsf) or a
// list of fixed-size blocks, locked by its own mutex. Placeholder names: the
// binary has no symbols for Wwise.
#include <nn/os.h>
#include <tlsf/tlsf.h>
#include <types.h>

// A free block of a fixed-size pool.
struct Unk_3043e0_Block {
    Unk_3043e0_Block* next;
};

// The free blocks of a fixed-size pool, taken from the front and returned at
// the back.
struct Unk_3043e0_List {
    Unk_3043e0_Block* field_0;  // last
    Unk_3043e0_Block* field_8;  // first

    void AddLast(Unk_3043e0_Block* block) {
        block->next = nullptr;
        if (field_8 == nullptr)
            field_8 = block;
        else
            field_0->next = block;
        field_0 = block;
    }
};

// 0x68 bytes: one entry of the pool array.
struct Unk_3043e0_Pool {
    u32 field_0;  // number of blocks; zero when the slot is free
    u32 field_4;  // block size
    void* field_8;  // memory allocated for the pool (field_2c bit 0)
    void* field_10;  // the pool's memory, aligned
    Unk_3043e0_List field_18;  // free blocks
    u32 field_28;  // attributes: bit 3 = fixed-size blocks
    u8 field_2c;
    u8 _2d[3];
    nn::os::MutexType field_30;
    tlsf_pool field_50;
    u32 field_58;  // alignment
    u32 field_5c;  // bytes in use
    u32 field_60;  // size
};
PKMN_SIZE_ASSERT(Unk_3043e0_Pool, 0x68);
PKMN_OFFSET_ASSERT(Unk_3043e0_Pool, field_18, 0x18);
PKMN_OFFSET_ASSERT(Unk_3043e0_Pool, field_28, 0x28);
PKMN_OFFSET_ASSERT(Unk_3043e0_Pool, field_2c, 0x2c);
PKMN_OFFSET_ASSERT(Unk_3043e0_Pool, field_30, 0x30);
PKMN_OFFSET_ASSERT(Unk_3043e0_Pool, field_50, 0x50);
PKMN_OFFSET_ASSERT(Unk_3043e0_Pool, field_58, 0x58);
PKMN_OFFSET_ASSERT(Unk_3043e0_Pool, field_60, 0x60);

// The pool array and its size, and the number of pools in use.
extern Unk_3043e0_Pool* Unk_24bb978;
extern int Unk_24bb970;
extern int Unk_24bb974;

// Allocation hooks the game provides.
void* Unk_6732e0(size_t size);
void Unk_673360(void* ptr);

struct Unk_3043c0;
void Unk_3043c0_set(Unk_3043c0* self);

u32 Unk_3043e0(int numPools, u32 a1);
bool Unk_3044e0(void*);
u32 Unk_304910(int poolId);
