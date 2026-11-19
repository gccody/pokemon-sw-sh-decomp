// Scope: common
// The memory manager's initialisation and pool creation (Unk_3043e0.h), in
// the TU after TLSF's.
#include "Unk_3043e0.h"

// 0x7100305410
u32 Unk_305410(uintptr_t settings) {
    const u32* s = reinterpret_cast<const u32*>(settings);
    // Unk_3044e0 takes no argument: x0 still holds `settings` when it's called.
    if (!Unk_3044e0(const_cast<u32*>(s)) && s != nullptr)
        return Unk_3043e0(s[0], s[1]);
    return 2;
}

// 0x7100305450
int Unk_305450(void* mem, u32 size, u32 blockSize, u32 attributes, u32 align) {
    if (mem == nullptr && !(attributes & 1))
        return -1;
    if (Unk_24bb974 >= Unk_24bb970)
        return -1;
    Unk_3043e0_Pool* pool = Unk_24bb978;
    int i = 0;
    for (; i < Unk_24bb970; i++, pool++) {
        nn::os::LockMutex(&pool->field_30);
        if (pool->field_0 == 0)
            break;
        nn::os::UnlockMutex(&pool->field_30);
    }
    if (i >= Unk_24bb970)
        return -1;
    u32 numBlocks = size / blockSize;
    u32 total = numBlocks * blockSize;
    if (mem != nullptr) {
        pool->field_10 = mem;
        pool->field_2c &= ~1;
    } else {
        u32 allocSize = total + align;
        if (allocSize != 0)
            pool->field_8 = Unk_6732e0(allocSize);
        pool->field_10 = pool->field_8;
        if (pool->field_10 == nullptr) {
            nn::os::UnlockMutex(&pool->field_30);
            return -1;
        }
        mem = pool->field_10;
        if (align != 0) {
            uintptr_t rem = reinterpret_cast<uintptr_t>(mem) % align;
            if (rem != 0) {
                mem = static_cast<u8*>(mem) + (align - rem);
                pool->field_10 = mem;
            }
        }
        pool->field_2c |= 1;
    }
    pool->field_28 = attributes;
    pool->field_60 = total;
    if (attributes & 8) {
        u8* p = static_cast<u8*>(mem);
        u8* end = p + total;
        for (; total != 0 && p != end; p += blockSize) {
            pool->field_18.AddLast(reinterpret_cast<Unk_3043e0_Block*>(p));
        }
    } else {
        pool->field_50 = tlsf_create(mem, total);
        if (pool->field_50 == nullptr) {
            Unk_673360(pool->field_8);
            pool->field_8 = nullptr;
            pool->field_10 = nullptr;
            nn::os::UnlockMutex(&pool->field_30);
            return -1;
        }
        pool->field_60 -= tlsf_overhead();
    }
    pool->field_0 = numBlocks;
    pool->field_4 = blockSize;
    pool->field_58 = align;
    Unk_24bb974++;
    nn::os::UnlockMutex(&pool->field_30);
    return i;
}

// 0x7100305660
u32 Unk_305660(int poolId) {
    u32 result = Unk_304910(poolId);
    if (result != 1)
        return result;
    Unk_3043e0_Pool* pools = Unk_24bb978;
    Unk_3043e0_Pool* pool = &pools[poolId];
    nn::os::LockMutex(&pool->field_30);
    if (pool->field_28 & 8) {
        pools[poolId].field_18.field_0 = nullptr;
        pools[poolId].field_18.field_8 = nullptr;
    }
    if (pools[poolId].field_2c & 1) {
        Unk_673360(pools[poolId].field_8);
        pools[poolId].field_8 = nullptr;
        pools[poolId].field_10 = nullptr;
    }
    Unk_3043c0_set(reinterpret_cast<Unk_3043c0*>(pool));
    Unk_24bb974--;
    nn::os::UnlockMutex(&pool->field_30);
    return result;
}
