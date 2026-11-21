// Scope: common
// The class with the vtable 0x7102383b58: the bank manager that does what it
// is asked on a thread of its own ("AK::BankManager"). Written from the
// executable. Placeholder names.
#include <string.h>
#include "Unk_Indexed.h"
#include "Unk_Thread.h"
#include "list2.h"

// A buffer the item owns or not.
struct Unk_341f80 {
    u64 field_0;
    u8 field_8;
};
void Unk_341f80_set(Unk_341f80* self);  // frees it (lib/wwise/leaf)

// What the thread is asked to do: 0x48 bytes.
struct Unk_2383b58_Item {
    u32 field_0;
    u32 field_4;
    Unk_341f80 field_8;
    void* field_18;  // who is told when it is done
    void* field_20;  // and with what
    u8 _28[0x20];

    Unk_2383b58_Item() : field_0(0xffffffff), field_4(0), field_18(nullptr), field_20(nullptr) {
        field_8.field_0 = 0;
        field_8.field_8 = 0;
    }
    ~Unk_2383b58_Item() { Unk_341f80_set(&field_8); }
};
PKMN_SIZE_ASSERT(Unk_2383b58_Item, 0x48);

// An nn::os::EventType: 0x28 bytes aligned like a pointer, the state in the
// byte 0x13.
struct Unk_2383b58_Event {
    alignas(8) u8 field_0[0x28];

    nn::os::EventType* Get() { return reinterpret_cast<nn::os::EventType*>(field_0); }
    void Create() { nn::os::InitializeEvent(Get(), false, static_cast<nn::os::EventClearMode>(1)); }
    void Destroy() {
        if (field_0[0x13] == 1)
            nn::os::FinalizeEvent(Get());
    }
};

struct Unk_2383b58 {
    u8 _0[0xd8];
    u8 field_d8[0x58];  // the users to tell
    Unk_2383b58_Event field_130;
    bool field_158;  // the thread stops
    u8 _159[7];
    nn::os::MutexType field_160;
    Unk_List2Ex<Unk_2383b58_Item> field_180;  // what is asked
};
PKMN_OFFSET_ASSERT(Unk_2383b58, field_130, 0x130);
PKMN_OFFSET_ASSERT(Unk_2383b58, field_160, 0x160);
PKMN_OFFSET_ASSERT(Unk_2383b58, field_180, 0x180);
PKMN_SIZE_ASSERT(Unk_2383b58, 0x1a8);

// A lock for a scope.
struct Unk_2383b58_Lock {
    nn::os::MutexType* field_0;

    explicit Unk_2383b58_Lock(nn::os::MutexType* mutex) : field_0(mutex) {
        nn::os::LockMutex(field_0);
    }
    ~Unk_2383b58_Lock() { nn::os::UnlockMutex(field_0); }
};

extern Unk_Thread Unk_24deed0;
extern nn::os::ThreadType* Unk_24df0a0;

// Functions of the base class.
u32 Unk_342ab0(Unk_2383b58* self);
void Unk_342af0(Unk_2383b58* self);
void Unk_342ea0(Unk_2383b58* self, Unk_2383b58_Item* item);
u32 Unk_34d0c0(void* self, void* arg1);
void Unk_34d280(void* self, void* arg1);
// 0x7100343eb0 has a generated name (lib/wwise/leaf).
void Unk_343eb0_update(u64 self, u64 item);

u32 Unk_3bcfd0(Unk_2383b58* self);
void Unk_3bd2c0(void* arg);
u32 Unk_3bd3a0(Unk_2383b58* self);

// 0x71003bcf30
u32 Unk_3bcf30(Unk_2383b58* self) {
    u32 result = Unk_342ab0(self);
    if (result == 1) {
        result = self->field_180.Init(10);
        if (result == 1)
            result = Unk_3bcfd0(self);
    }
    return result;
}

// 0x71003bcfd0: starts the thread
u32 Unk_3bcfd0(Unk_2383b58* self) {
    if (Unk_24deed0.field_40 != 0)
        return 2;
    self->field_158 = false;
    self->field_130.Create();
    Unk_24deed0.field_1c0 = Unk_673320(Unk_24bcb80.field_20.field_8, 0x1000);
    Unk_24deed0.field_1c8 = Unk_24bcb80.field_20.field_8;
    nn::os::CreateThread(Unk_24deed0.Get(), Unk_3bd2c0, self, Unk_24deed0.field_1c0,
                         Unk_24deed0.field_1c8, Unk_24bcb80.field_20.field_0);
    nn::os::SetThreadName(Unk_24deed0.Get(), "AK::BankManager");
    nn::os::SetThreadCoreMask(Unk_24deed0.Get(), Unk_24bcb80.field_20.field_10,
                              Unk_24bcb80.field_20.field_18);
    nn::os::StartThread(Unk_24deed0.Get());
    return Unk_24deed0.field_40 != 0 ? 1 : 2;
}

// 0x71003bd0b0
void Unk_3bd0b0(Unk_2383b58* self) {
    while (self->field_180.field_24 != 0) {
        Unk_2383b58_Item item = self->field_180.First();
        self->field_180.RemoveFirst();
    }
    self->field_180.Term();
    Unk_342af0(self);
}

// 0x71003bd1b0
template void Unk_List2Ex<Unk_2383b58_Item>::Term();

// 0x71003bd2c0: the thread
void Unk_3bd2c0(void* arg) {
    Unk_2383b58* self = static_cast<Unk_2383b58*>(arg);
    Unk_24df0a0 = nn::os::GetCurrentThread();
    nn::os::WaitEvent(self->field_130.Get());
    while (!self->field_158) {
        Unk_3bd3a0(self);
        nn::os::WaitEvent(self->field_130.Get());
    }
}

// 0x71003bd320: stops the thread
void Unk_3bd320(Unk_2383b58* self) {
    self->field_158 = true;
    if (Unk_24deed0.field_40 != 0) {
        nn::os::SignalEvent(self->field_130.Get());
        nn::os::WaitThread(Unk_24deed0.Get());
        nn::os::DestroyThread(Unk_24deed0.Get());
        Unk_6733a0(reinterpret_cast<u64>(Unk_24deed0.field_1c0));
        Unk_24deed0.field_1c0 = nullptr;
    }
    self->field_130.Destroy();
}

// 0x71003bd3a0: does what was asked
u32 Unk_3bd3a0(Unk_2383b58* self) {
    nn::os::LockMutex(&self->field_160);
    while (self->field_180.field_24 != 0) {
        {
            Unk_2383b58_Item item = self->field_180.First();
            self->field_180.RemoveFirst();
            nn::os::UnlockMutex(&self->field_160);
            Unk_342ea0(self, &item);
        }
        nn::os::LockMutex(&self->field_160);
    }
    nn::os::UnlockMutex(&self->field_160);
    return 1;
}

// 0x71003bd4c0: asks
u32 Unk_3bd4c0(Unk_2383b58* self, Unk_2383b58_Item* item) {
    Unk_2383b58_Lock lock(&self->field_160);
    u32 result = 1;
    if (item->field_18 != nullptr)
        result = Unk_34d0c0(self->field_d8, item->field_20);
    if (result == 1) {
        Unk_2383b58_Item* added = self->field_180.AddLast();
        if (added != nullptr) {
            *added = *item;
            Unk_343eb0_update(reinterpret_cast<u64>(self), reinterpret_cast<u64>(item));
            nn::os::SignalEvent(self->field_130.Get());
        } else {
            if (item->field_18 != nullptr)
                Unk_34d280(self->field_d8, item->field_20);
            result = 2;
        }
    }
    if (result != 1)
        Unk_341f80_set(&item->field_8);
    return result;
}

// What waits for the thread to have done something.
struct Unk_3bd5f0_Sync {
    u32 field_0;  // the result
    Unk_2383b58_Event field_8;
};

// 0x71003bd5f0
u32 Unk_3bd5f0(Unk_2383b58* /*self*/, Unk_3bd5f0_Sync* sync) {
    sync->field_8.Create();
    return 1;
}

// 0x71003bd620
u32 Unk_3bd620(Unk_2383b58* /*self*/, Unk_3bd5f0_Sync* sync, u32 result) {
    if (result == 1) {
        nn::os::WaitEvent(sync->field_8.Get());
        sync->field_8.Destroy();
        result = sync->field_0;
    } else {
        sync->field_8.Destroy();
    }
    return result;
}

// The class's vtable is data here.
extern void* Unk_2383b58_Vtable[];

// The base class's constructor and destructor.
void Unk_342920(Unk_2383b58* self);
void Unk_342990(Unk_2383b58* self);

// 0x71003bce40: the constructor
void Unk_3bce40(Unk_2383b58* self) {
    Unk_342920(self);
    Unk_SetVtable(self, Unk_2383b58_Vtable);
    self->field_158 = false;
    nn::os::InitializeMutex(&self->field_160, true, 0);
    new (&self->field_180) Unk_List2Ex<Unk_2383b58_Item>;
    memset(self->field_130.field_0, 0, sizeof(self->field_130.field_0));
    Unk_24deed0.field_40 = 0;
}

// 0x71003bceb0: the destructor
void Unk_3bceb0(Unk_2383b58* self) {
    Unk_SetVtable(self, Unk_2383b58_Vtable);
    nn::os::FinalizeMutex(&self->field_160);
    Unk_342990(self);
}

// 0x71003bcef0: the deleting destructor
void Unk_3bcef0(Unk_2383b58* self) {
    Unk_SetVtable(self, Unk_2383b58_Vtable);
    nn::os::FinalizeMutex(&self->field_160);
    Unk_342990(self);
    operator delete(self);
}
