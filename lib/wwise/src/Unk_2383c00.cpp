// Scope: common
// The class with the vtable 0x7102383c00: an object that opens a stream by
// name, reads or writes it at once and closes it. Written from the
// executable. Placeholder names.
#include "Unk_Indexed.h"

// A stream, as far as this class calls it.
struct Unk_2383c00_Stream {
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();  // closes it
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual u32 vf8(void* buffer, u32 size, bool wait, u32 priority, f32 deadline, u32* done);
    virtual void vf9();
    virtual u32 vf10(void* arg1, u32 arg2, void* arg3);
};

// How a stream is opened: 0x28 bytes (the last 8 aren't set here).
struct Unk_2383c00_Flags {
    u32 field_0;
    u32 field_4;
    u32 field_8;
    u64 field_10;
    bool field_18;
    u32 field_1c;
    u64 field_20;
};
PKMN_SIZE_ASSERT(Unk_2383c00_Flags, 0x28);

// What opens the streams.
struct Unk_24df328_T {
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual u32 vf4(void* name, Unk_2383c00_Flags* flags, u32 mode, Unk_2383c00_Stream** stream,
                    bool wait);
};
extern Unk_24df328_T* Unk_24df328;

struct Unk_2383c00_T {
    void** field_0;  // vptr
    Unk_2383c00_Stream* field_8;

    void Close() {
        if (field_8 != nullptr) {
            field_8->vf2();
            field_8 = nullptr;
        }
    }
};

extern void* Unk_2383c00[];

// 0x71003c2120: opens the stream and does the first transfer
u32 Unk_3c2120(Unk_2383c00_T* self, void* name, void* buffer, u32 size) {
    if (self->field_8 != nullptr)
        return 1;
    Unk_2383c00_Flags flags;
    flags.field_1c = 0xffffffff;
    flags.field_0 = 0;
    flags.field_4 = 1;
    flags.field_18 = false;
    flags.field_10 = 0;
    flags.field_8 = 0;
    u32 result = Unk_24df328->vf4(name, &flags, 2, &self->field_8, true);
    if (result == 1) {
        u32 done;
        result = self->field_8->vf8(buffer, size, true, 100, 0, &done);
        if (result != 1) {
            self->field_8->vf2();
            self->field_8 = nullptr;
        }
    }
    return result;
}

// 0x71003c2200: the last transfer, and closes the stream
u32 Unk_3c2200(Unk_2383c00_T* self, void* buffer, u32 size) {
    if (self->field_8 == nullptr)
        return 2;
    u32 result = self->field_8->vf10(nullptr, 0, nullptr);
    if (result == 1) {
        u32 done;
        result = self->field_8->vf8(buffer, size, true, 0, 0, &done);
    }
    self->field_8->vf2();
    self->field_8 = nullptr;
    return result;
}

// 0x71003c22b0
u32 Unk_3c22b0(Unk_2383c00_T* self, void* buffer, u32 size) {
    u32 done;
    return self->field_8->vf8(buffer, size, true, 0, 0, &done);
}

// 0x71003c22f0
u32 Unk_3c22f0(Unk_2383c00_T* self, void* buffer, u32 size) {
    u32 done;
    return self->field_8->vf8(buffer, size, true, 0, 0, &done);
}

// 0x71003c2330: destroys it
void Unk_3c2330(Unk_2383c00_T* self) {
    if (self != nullptr) {
        int pool = Unk_237e820;
        Unk_SetVtable(self, Unk_2383c00);
        self->Close();
        Unk_3047c0(pool, self);
    }
}

// 0x71003c23b0: a new one
Unk_2383c00_T* Unk_3c23b0() {
    Unk_2383c00_T* self =
        static_cast<Unk_2383c00_T*>(Unk_3045e0(Unk_237e820, sizeof(Unk_2383c00_T)));
    if (self != nullptr) {
        Unk_SetVtable(self, Unk_2383c00);
        self->field_8 = nullptr;
    }
    return self;
}
