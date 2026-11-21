#pragma once
// An object of game/pokecamp that keeps callables by the hash of a name
// (messages: "OnCookingRequestClosed", "NoBerryMessage", ...), under a lock:
// sixteen entries of a hash and a callable from +0x80, so the entry a search
// returns for a name that isn't there is at +0x980. The camp's classes reach
// it through their owner (Unk_24284d0::Unk_126aca0's and
// Unk_2423ec8::Unk_12164a0's result, +0x60). Placeholder names.
#include "gflib3/Unk_2399590.h"
#include "unsorted/Unk_23d4470.h"

// The four functions of a callable that does nothing, all empty (written as
// leaves), and such a callable.
void Unk_1260810_update();
void Unk_1260820_update();
void Unk_1260830_update();
void Unk_1260840_update();

class Unk_1260810_Callable : public Unk_23d4470_Callable {
public:
    Unk_1260810_Callable() {
        field_0 = reinterpret_cast<u64>(&Unk_1260810_update);
        field_8 = reinterpret_cast<void (*)(void*)>(&Unk_1260820_update);
        field_10 = reinterpret_cast<u64>(&Unk_1260830_update);
        field_18 = reinterpret_cast<u64>(&Unk_1260840_update);
    }
};

// The four functions of a callable that holds a flag (0x7101278660 gives it
// to what its argument points at; the others are written as leaves), and such
// a callable.
void Unk_1278660(const bool* captured, bool** out);
void Unk_1278670_update();
struct Unk_1278680;
struct Unk_1278680_arg1;
void Unk_1278680_set(const Unk_1278680*, Unk_1278680_arg1*);
struct Unk_1278690;
struct Unk_1278690_arg1;
void Unk_1278690_set(const Unk_1278690*, Unk_1278690_arg1*);

class Unk_1278660_Callable : public Unk_23d4470_Callable {
public:
    // What it holds goes in first, then its functions.
    explicit Unk_1278660_Callable(const bool& flag) {
        field_20[0] = flag;
        field_0 = reinterpret_cast<u64>(&Unk_1278660);
        field_8 = reinterpret_cast<void (*)(void*)>(&Unk_1278670_update);
        field_10 = reinterpret_cast<u64>(&Unk_1278680_set);
        field_18 = reinterpret_cast<u64>(&Unk_1278690_set);
    }
};

struct Unk_1127d00_Entry {
    u64 field_0;
    Unk_23d4470_Callable field_10;
};
static_assert(sizeof(Unk_1127d00_Entry) == 0x90, "Unk_1127d00_Entry");

class Unk_1127d00_Owner {
public:
    // Keeps `callable` under `hash` (0x7101127d00, not decompiled).
    void Unk_1127d00(u64 hash, Unk_23d4470_Callable& callable, bool arg3);
    // The entry of `hash`, or the end of the entries (0x7101127fc0, not decompiled).
    Unk_1127d00_Entry* Unk_1127fc0(u64 hash);

    // Keeps a callable that does nothing under `hash`.
    void Unk_Register(u64 hash, bool arg) {
        field_60.Lock();
        {
            Unk_1260810_Callable callable;
            Unk_1127d00(hash, callable, arg);
        }
        field_60.Unlock();
    }

    // Keeps a callable that holds `flag` under `hash`.
    void Unk_Register(u64 hash, const bool& flag, bool arg) {
        field_60.Lock();
        {
            Unk_1278660_Callable callable(flag);
            Unk_1127d00(hash, callable, arg);
        }
        field_60.Unlock();
    }

    // Lets go of the callable kept under `hash`: whether there was one. The
    // lock is released on each way out (the original has the release twice;
    // a guard object's destructor comes out once, after both).
    bool Unk_Take(u64 hash) {
        field_60.Lock();
        Unk_1127d00_Entry* entry = Unk_1127fc0(hash);
        if (entry != field_80 + 16) {
            entry->field_10.~Unk_23d4470_Callable();
            field_60.Unlock();
            return true;
        }
        field_60.Unlock();
        return false;
    }

    u8 _0[0x60];
    Unk_2399590_Lock field_60;
    u8 _78[0x8];
    Unk_1127d00_Entry field_80[16];
};
PKMN_OFFSET_ASSERT(Unk_1127d00_Owner, field_60, 0x60);
PKMN_OFFSET_ASSERT(Unk_1127d00_Owner, field_80, 0x80);
static_assert(__builtin_offsetof(Unk_1127d00_Owner, field_80) + sizeof(Unk_1127d00_Entry) * 16 ==
                  0x980,
              "Unk_1127d00_Owner::field_80");

// The hash of a name: 64-bit FNV-1a from the basis the camp uses.
inline u64 Unk_1127d00_Hash(const char* name) {
    u64 hash = 0xcbf29ce484222645;
    for (; *name != '\0'; ++name)
        hash = (hash ^ static_cast<u8>(*name)) * 0x100000001b3;
    return hash;
}

namespace {

// What an object does with a message's name: its hash is kept with a callable
// that does nothing, or taken out. `target` is what the object's owner gives
// (Unk_24284d0::Unk_126aca0, Unk_2423ec8::Unk_12164a0), read after the hash is
// computed. N is the size of the name: the original has an instance per size
// (0x7101286ed0 gets the names of 14 characters of its TU, 0x7101287c80 the
// one of 15), so the name is taken as an array there.
template <u64 N, class Target>
void Unk_1127d00_Send(Target* target, const char* name, bool arg) {
    u64 hash = Unk_1127d00_Hash(name);
    target->field_60->Unk_Register(hash, arg);
}

template <u64 N, class Target>
void Unk_1127d00_Send(Target* target, const char* name, const bool& flag, bool arg) {
    u64 hash = Unk_1127d00_Hash(name);
    target->field_60->Unk_Register(hash, flag, arg);
}

template <u64 N, class Target>
bool Unk_1127d00_Take(Target* target, const char* name) {
    u64 hash = Unk_1127d00_Hash(name);
    return target->field_60->Unk_Take(hash);
}

}  // namespace
