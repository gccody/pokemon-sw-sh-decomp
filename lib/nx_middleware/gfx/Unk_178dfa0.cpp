// Scope: common
// NintendoSDK_gfx 7.3.2 for NVN: queues. Placeholder names (gfx.h).
#include "nx_middleware/gfx/gfx.h"

// A queue: its NVN queue.
struct Unk_178dfa0_Queue {
    u8 _0[0x8];
    void* field_8;
};
PKMN_OFFSET_ASSERT(Unk_178dfa0_Queue, field_8, 0x8);

// A fence or semaphore: its NVN sync object (in field_10).
struct Unk_178dfa0_Sync {
    u8 _0[0x8];
    void* field_8;
    u8 field_10[0x20];
};
PKMN_OFFSET_ASSERT(Unk_178dfa0_Sync, field_10, 0x10);

// 0x710178dfa0
void Unk_178dfa0(Unk_178dfa0_Queue* self, const Unk_1787d90_CommandBuffer* commands,
                 Unk_178dfa0_Sync* fence) {
    nvnQueueSubmitCommands(self->field_8, 1, &commands->field_c0);
    if (fence != nullptr) {
        fence->field_8 = fence->field_10;
        nvnQueueFenceSync(self->field_8, fence->field_8, 0, 1);
    }
}

// 0x710178e010
void Unk_178e010(Unk_178dfa0_Queue* self) {
    nvnQueueFinish(self->field_8);
}

// 0x710178e030
void Unk_178e030(Unk_178dfa0_Queue* self, const Unk_178dfa0_Sync* semaphore) {
    nvnQueueWaitSync(self->field_8, semaphore->field_8);
}

// A swap chain: its NVN window, flags (bit 0: no texture acquired yet, bit 1:
// don't acquire after presenting) and the acquired texture's index.
struct Unk_178e050_SwapChain {
    u8 _0[0x8];
    void* field_8;
    u8 _10[0x181];
    Unk_1787ac0_Flags field_191;
    u8 _192[0x2];
    s32 field_194;
};
PKMN_OFFSET_ASSERT(Unk_178e050_SwapChain, field_191, 0x191);
PKMN_OFFSET_ASSERT(Unk_178e050_SwapChain, field_194, 0x194);

// 0x710178e050
void Unk_178e050(Unk_178dfa0_Queue* self, Unk_178e050_SwapChain* swapChain, int presentInterval) {
    if (nvnWindowGetPresentInterval(swapChain->field_8) != presentInterval) {
        nvnWindowSetPresentInterval(swapChain->field_8, presentInterval);
    }
    if (swapChain->field_191.Test(1) && !swapChain->field_191.Test(2)) {
        swapChain->field_191.Set(1, false);
        int index = -1;
        nvnQueueAcquireTexture(self->field_8, swapChain->field_8, &index);
        swapChain->field_194 = index;
    }
    nvnQueuePresentTexture(self->field_8, swapChain->field_8, swapChain->field_194);
    if (!swapChain->field_191.Test(2)) {
        int index = -1;
        nvnQueueAcquireTexture(self->field_8, swapChain->field_8, &index);
        swapChain->field_194 = index;
    }
}
