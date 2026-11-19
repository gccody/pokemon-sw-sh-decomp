// Scope: common
// The memory manager (Unk_3043e0.h), the TU before TLSF's.
#include "Unk_3043e0.h"

Unk_3043e0_Pool* Unk_24bb978;
int Unk_24bb970;
int Unk_24bb974;
u32 Unk_24bb980;
static bool s_initialized;

// 0x71003043e0
u32 Unk_3043e0(int numPools, u32 a1) {
    Unk_24bb978 = static_cast<Unk_3043e0_Pool*>(Unk_6732e0(numPools * sizeof(Unk_3043e0_Pool)));
    if (Unk_24bb978 == nullptr)
        return 2;
    for (int i = 0; i < numPools; i++) {
        Unk_3043e0_Pool* pool = &Unk_24bb978[i];
        if (pool == nullptr)
            continue;
        pool->field_18.field_0 = nullptr;
        pool->field_18.field_8 = nullptr;
        nn::os::InitializeMutex(&pool->field_30, true, 0);
        pool->field_8 = nullptr;
        pool->field_10 = nullptr;
        pool->field_0 = 0;
        pool->field_4 = 0;
        pool->field_28 = 1;
        pool->field_60 = 0;
        pool->field_50 = nullptr;
        pool->field_58 = 0;
        pool->field_5c = 0;
    }
    Unk_24bb970 = numPools;
    Unk_24bb974 = 0;
    Unk_24bb980 = a1;
    s_initialized = true;
    return 1;
}

// 0x71003044e0
bool Unk_3044e0(void*) {
    return s_initialized;
}



// 0x71003045b0
u32 Unk_3045b0(int poolId) {
    return Unk_24bb978[poolId].field_28;
}

// 0x71003045e0
void* Unk_3045e0(int poolId, size_t size) {
    if (size == 0)
        return nullptr;
    Unk_3043e0_Pool* pools = Unk_24bb978;
    Unk_3043e0_Pool* pool = &pools[poolId];
    nn::os::LockMutex(&pool->field_30);
    void* ptr;
    if (pool->field_58 > 4)
        ptr = tlsf_memalign(pool->field_50, pool->field_58, size);
    else
        ptr = tlsf_malloc(pool->field_50, size);
    if (ptr != nullptr)
        pools[poolId].field_5c += tlsf_block_size(ptr) + 8;
    nn::os::UnlockMutex(&pool->field_30);
    return ptr;
}

// 0x71003046a0
void* Unk_3046a0(int poolId, size_t size, u32 align) {
    if (size == 0)
        return nullptr;
    Unk_3043e0_Pool* pools = Unk_24bb978;
    Unk_3043e0_Pool* pool = &pools[poolId];
    nn::os::LockMutex(&pool->field_30);
    void* ptr = tlsf_memalign(pool->field_50, align, size);
    if (ptr != nullptr)
        pools[poolId].field_5c += tlsf_block_size(ptr) + 8;
    nn::os::UnlockMutex(&pool->field_30);
    return ptr;
}

// 0x7100304740
u32 Unk_304740(int poolId, void* ptr) {
    if (ptr == nullptr)
        return 1;
    Unk_3043e0_Pool* pool = &Unk_24bb978[poolId];
    nn::os::LockMutex(&pool->field_30);
    pool->field_5c -= tlsf_block_size(ptr) + 8;
    tlsf_free(pool->field_50, ptr);
    nn::os::UnlockMutex(&pool->field_30);
    return 1;
}

// 0x71003047c0
u32 Unk_3047c0(int poolId, void* ptr) {
    if (ptr == nullptr)
        return 1;
    Unk_3043e0_Pool* pool = &Unk_24bb978[poolId];
    nn::os::LockMutex(&pool->field_30);
    pool->field_5c -= tlsf_block_size(ptr) + 8;
    tlsf_free(pool->field_50, ptr);
    nn::os::UnlockMutex(&pool->field_30);
    return 1;
}



// 0x71003048a0
u32 Unk_3048a0(int poolId, void* ptr) {
    Unk_3043e0_Pool* pool = &Unk_24bb978[poolId];
    pool->field_5c -= pool->field_4;
    pool->field_18.AddLast(static_cast<Unk_3043e0_Block*>(ptr));
    return 1;
}

// 0x71003048f0
u32 Unk_3048f0(int poolId) {
    return Unk_24bb978[poolId].field_4;
}

// 0x7100304910
u32 Unk_304910(int poolId) {
    if (poolId < Unk_24bb970 && Unk_24bb978[poolId].field_0 != 0)
        return 1;
    return 14;
}

// 0x7100304950
void Unk_304950(int poolId, u32* stats) {
    Unk_3043e0_Pool* pool = &Unk_24bb978[poolId];
    nn::os::LockMutex(&pool->field_30);
    stats[1] = pool->field_5c;
    stats[0] = pool->field_60;
    nn::os::UnlockMutex(&pool->field_30);
}
