// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

void Unk_905af0(void*, void*, u32, void*);

// 0x71009059f0
void Unk_9059f0_call(void* self, void* value, u32 arg2, void* arg3) {
    if (arg2 != 0) {
        if (arg2 == 1) {
            Unk_905af0(self, value, arg2, arg3);
            Unk_905af0(self, value, 3, arg3);
            Unk_905af0(self, value, 5, arg3);
            return;
        }
        Unk_905af0(self, value, 0, arg3);
        Unk_905af0(self, value, 1, arg3);
        Unk_905af0(self, value, 2, arg3);
        Unk_905af0(self, value, 3, arg3);
        Unk_905af0(self, value, 4, arg3);
        Unk_905af0(self, value, 5, arg3);
        Unk_905af0(self, value, 6, arg3);
        return;
    }
    Unk_905af0(self, value, arg2, arg3);
    Unk_905af0(self, value, 2, arg3);
    Unk_905af0(self, value, 4, arg3);
    Unk_905af0(self, value, 6, arg3);
}

void Unk_906480(void*, u32);

// 0x7100906540
void Unk_906540_call(void* self) {
    Unk_906480(self, 0xff);
}
