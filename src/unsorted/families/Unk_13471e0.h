#pragma once
// A store of scrambled blocks keyed by a u32 (game/unk_133d350, next to the
// flag and work tables): a sorted vector of entries, each the block's bytes in
// memory of its own, read and written through a stream that XORs every 32-bit
// word with an xorshift32 generator seeded by the key (advanced once per bit
// set in it). The templates are instantiated once per block type: their code
// doesn't depend on it. Placeholder names: rename once the classes are known.
#include <algorithm>
#include <atomic>
#include <bitset>
#include <cstring>
#include <vector>

#include <nn/os.h>
#include <types.h>

#include "unsorted/Unk_2771620.h"

// A generator of 32-bit words, by index: field_8 is the index of the current
// word.
class Unk_2431980_Base {
public:
    Unk_2431980_Base() : field_8(0) {}
    virtual void vf0() = 0;
    virtual u32 vf1() = 0;
    virtual void vf2() = 0;

    // The word at `index`: from the start again when it's behind.
    u32 Unk_Word(s64 index) {
        if (field_8 > index) {
            vf0();
            field_8 = 0;
        }
        while (field_8 < index) {
            vf2();
            field_8++;
        }
        return vf1();
    }

    s64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_2431980_Base, field_8, 0x8);

// The xorshift32 generator (vtable 0x7102431980): field_14 is the state,
// field_10 the state its words start from.
class Unk_2431980 : public Unk_2431980_Base {
public:
    explicit Unk_2431980(u32 seed) : field_10(0), field_14(seed) {
        for (size_t i = 0, n = std::bitset<32>(seed).count(); i != n; i++)
            vf2();
        field_10 = field_14;
    }
    void vf0() override { field_14 = field_10; }
    u32 vf1() override { return field_14; }
    void vf2() override {
        u32 x = field_14;
        x ^= x << 2;
        x ^= x >> 15;
        x ^= x << 13;
        field_14 = x;
    }

    u32 field_10;
    u32 field_14;
};
PKMN_SIZE_ASSERT(Unk_2431980, 0x18);
PKMN_OFFSET_ASSERT(Unk_2431980, field_14, 0x14);

// Bytes in memory (vtable 0x71024319a8): field_18 makes them read-only.
class Unk_24319a8 {
public:
    Unk_24319a8(u8* data, s64 size) : field_8(data), field_10(size), field_18(false) {}
    virtual ~Unk_24319a8() {}
    virtual bool vf2(s64 size, s64 offset) {
        if (field_8 == nullptr)
            return false;
        return size + offset <= vf4();
    }
    virtual bool vf3(s64 size, s64 offset) {
        if (field_18)
            return false;
        if (field_8 == nullptr)
            return false;
        return size + offset <= vf4();
    }
    virtual s64 vf4() { return field_10; }
    virtual bool vf5(void* dst, s64 size, s64 offset) {
        std::memcpy(dst, field_8 + offset, size);
        return true;
    }
    virtual bool vf6(const void* src, s64 size, s64 offset) {
        std::memcpy(field_8 + offset, src, size);
        return true;
    }

    bool Unk_Read(void* dst, s64 size, s64 offset) {
        if (size > 0 && dst != nullptr && offset >= 0 && vf2(size, offset))
            return vf5(dst, size, offset);
        return false;
    }
    bool Unk_Write(const void* src, s64 size, s64 offset) {
        if (size > 0 && src != nullptr && offset >= 0 && vf3(size, offset))
            return vf6(src, size, offset);
        return false;
    }

    u8* field_8;
    s64 field_10;
    bool field_18;
};
PKMN_SIZE_ASSERT(Unk_24319a8, 0x20);
PKMN_OFFSET_ASSERT(Unk_24319a8, field_18, 0x18);

// A stream: field_8 is where it starts in what it reads and writes.
class Unk_2431940_Base {
public:
    Unk_2431940_Base(u8* data, s64 size, const Unk_2431980& generator)
        : field_8(0), field_10(data, size), field_30(generator), field_48(0) {}
    virtual ~Unk_2431940_Base() {}
    virtual bool vf2(void* dst, s64 size, s64 offset) = 0;
    virtual bool vf3(const void* src, s64 size, s64 offset) = 0;
    virtual Unk_24319a8* vf4() = 0;
    virtual Unk_24319a8* vf5() = 0;

    s64 field_8;
    Unk_24319a8 field_10;
    Unk_2431980 field_30;
    s64 field_48;
};
PKMN_OFFSET_ASSERT(Unk_2431940_Base, field_8, 0x8);

// The scrambled view of an Unk_24319a8 (vtable 0x7102431940): word i of the
// bytes from field_48 on is XORed with the generator's word i.
class Unk_2431940 : public Unk_2431940_Base {
public:
    Unk_2431940(u8* data, s64 size, const Unk_2431980& generator)
        : Unk_2431940_Base(data, size, generator) {}
    Unk_2431940(u8* data, s64 size, const u32& key) : Unk_2431940(data, size, Unk_2431980(key)) {}

    // 0x71013462b0
    // NON_MATCHING: register allocation: the word index and the chunk pointer
    // swap registers (x24/x25), and the chunk's size is computed after the
    // stream's vtable load instead of before it.
    bool vf2(void* dst, s64 size, s64 offset) override {
        u64 start = field_8 - field_48 + offset;
        u64 end = start + size;
        u64 words = end / 4 + (end % 4 != 0);
        u32 buffer[10] = {};
        bool ok = true;
        u64 word = start / 4;
        for (s64 done = 0; done < size;) {
            u32 skip = (start + done) & 3;
            u8* p = reinterpret_cast<u8*>(buffer) + skip;
            s64 n = std::min<s64>(sizeof(buffer) - skip, size - done);
            bool read = vf5()->Unk_Read(p, n, done + offset + field_8);
            for (u32* w = buffer;;) {
                *w++ ^= field_30.Unk_Word(word++);
                if (word >= words || w == buffer + 10)
                    break;
            }
            ok &= read;
            std::memcpy(static_cast<u8*>(dst) + done, p, n);
            done += n;
        }
        return ok;
    }
    // 0x71013464c0
    // NON_MATCHING: scheduling: the room left in the buffer is computed in
    // another temporary, and one zeroing store and two adds move.
    bool vf3(const void* src, s64 size, s64 offset) override {
        u64 start = field_8 - field_48 + offset;
        u64 end = start + size;
        u64 words = end / 4 + (end % 4 != 0);
        u32 buffer[10] = {};
        bool ok = true;
        u64 word = start / 4;
        for (s64 done = 0; done < size;) {
            std::memset(buffer, 0, sizeof(buffer));
            u32 skip = (start + done) & 3;
            u8* p = reinterpret_cast<u8*>(buffer) + skip;
            s64 n = std::min<s64>(sizeof(buffer) - skip, size - done);
            std::memcpy(p, static_cast<const u8*>(src) + done, n);
            for (u32* w = buffer;;) {
                *w++ ^= field_30.Unk_Word(word++);
                if (word >= words || w == buffer + 10)
                    break;
            }
            ok &= vf4()->Unk_Write(p, n, done + offset + field_8);
            done += n;
        }
        return ok;
    }
    Unk_24319a8* vf4() override { return &field_10; }
    Unk_24319a8* vf5() override { return &field_10; }
};
PKMN_SIZE_ASSERT(Unk_2431940, 0x50);
PKMN_OFFSET_ASSERT(Unk_2431940, field_30, 0x30);
PKMN_OFFSET_ASSERT(Unk_2431940, field_48, 0x48);

// What Unk_2431910::Unk_1346860 returns.
struct Unk_1346860_Result {
    bool field_0;
    u64 field_8;
};

// Reads a block (vtable 0x7102431910).
class Unk_2431910 {
public:
    Unk_2431910(u8* data, s64 size, const u32& key) : field_8(data, size, key) {}
    virtual ~Unk_2431910() {}
    virtual Unk_2431940* vf2() { return &field_8; }
    virtual Unk_2431940* vf3() { return &field_8; }

    Unk_1346860_Result Unk_1346860(void* dst, u64 size);

    Unk_2431940 field_8;
};
PKMN_SIZE_ASSERT(Unk_2431910, 0x58);

// Writes a block (vtable 0x71024319f0).
class Unk_24319f0 {
public:
    Unk_24319f0(u8* data, s64 size, const u32& key) : field_8(data, size, key) {}
    virtual ~Unk_24319f0() {}
    virtual Unk_2431940* vf2() { return &field_8; }
    virtual Unk_2431940* vf3() { return &field_8; }

    bool Unk_1347af0(const void* src, u64 size);

    Unk_2431940 field_8;
};
PKMN_SIZE_ASSERT(Unk_24319f0, 0x58);

// A block: its key, its bytes, how many there's room for and how many it uses.
struct Unk_13471e0_Entry {
    u32 field_0;
    u8* field_8;
    u64 field_10;
    u64 field_18;
};
PKMN_SIZE_ASSERT(Unk_13471e0_Entry, 0x20);

// Where the blocks' bytes come from.
class Unk_13471e0_Allocator {
public:
    virtual void vf0();
    virtual void vf1();
    virtual u8* vf2(u64 size);
    virtual void vf3(u8* p, u64 size);
};

// Told about what the store does.
class Unk_13471e0_Listener {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3(Unk_13471e0_Entry* entry);
    virtual void vf4(Unk_13471e0_Entry* entry);
    virtual void vf5(const u32* key);
    virtual void vf6(Unk_13471e0_Entry* entry);
    virtual void vf7(const u32* key);
    virtual void vf8();
    virtual void vf9();
    virtual void vf10(const u32* key);
    virtual void vf11(const u32* key);
    virtual void vf12();
};

// What Unk_13471e0::Unk_1347cd0 returns.
struct Unk_1347cd0_Result {
    ~Unk_1347cd0_Result() {}
    Unk_13471e0_Entry* field_0;
};

// Orders the entries by key.
struct Unk_13471e0_Less {
    bool operator()(const Unk_13471e0_Entry& a, const Unk_13471e0_Entry& b) const {
        return a.field_0 < b.field_0;
    }
};

class Unk_13471e0_Store {
public:
    using Entries = std::vector<Unk_13471e0_Entry, Unk_2771620_Allocator<Unk_13471e0_Entry>>;

    // The entry of `key`, null if there's none.
    Unk_13471e0_Entry* Unk_Find(const u32& key) {
        nn::os::LockMutex(&field_78);
        Entries::iterator first = field_8.begin();
        Entries::iterator last = field_8.end();
        Entries::iterator it = field_8.end();
        while (last - first > 0) {
            Entries::iterator mid = first + (last - first) / 2;
            if (mid->field_0 == key) {
                it = mid;
                break;
            }
            if (mid->field_0 < key)
                first = mid + 1;
            else
                last = mid;
        }
        Unk_13471e0_Entry* entry = it != field_8.end() ? &*it : nullptr;
        nn::os::UnlockMutex(&field_78);
        return entry;
    }

    void Unk_Sort() {
        nn::os::LockMutex(&field_78);
        std::sort(field_8.begin(), field_8.end(), Unk_13471e0_Less());
        nn::os::UnlockMutex(&field_78);
    }

    // A reader and a writer of an entry's bytes.
    static Unk_2431910 Unk_Reader(const Unk_13471e0_Entry* entry) {
        return Unk_2431910(entry->field_8, entry->field_18, entry->field_0);
    }
    static Unk_24319f0 Unk_Writer(const Unk_13471e0_Entry* entry) {
        return Unk_24319f0(entry->field_8, entry->field_18, entry->field_0);
    }

    // Makes room for `size` bytes in an entry.
    bool Unk_Resize(Unk_13471e0_Entry* entry, u64 size) {
        if (entry->field_10 < size) {
            if (field_58 != nullptr)
                field_58->vf3(entry);
            u8* p = field_38->vf2(size);
            if (p == nullptr) {
                return false;
            }
            std::memcpy(p, entry->field_8, entry->field_18);
            field_38->vf3(entry->field_8, entry->field_10);
            entry->field_8 = p;
            entry->field_10 = size;
            entry->field_18 = size;
        } else if (entry->field_10 > size && entry->field_18 != size) {
            if (field_58 != nullptr)
                field_58->vf4(entry);
            entry->field_18 = size;
        }
        return true;
    }

    bool Unk_13471e0(const Unk_13471e0_Entry* entry);
    Unk_1347cd0_Result Unk_1347cd0(const u32& key, u64 size);

    // Writes a block, adding it if it's not there.
    template <class T>
    bool Unk_13456e0(const u32& key, T* const& data, const u64& size) {
        nn::os::LockMutex(&field_78);
        bool ok;
        if (field_98.load()) {
            if (field_58 != nullptr)
                field_58->vf12();
            ok = false;
        } else if (Unk_13471e0_Entry* entry = Unk_Find(key)) {
            if (!Unk_13471e0(entry) && field_58 != nullptr)
                field_58->vf11(&key);
            ok = Unk_1347350(entry, data, size);
        } else {
            ok = Unk_13475a0(key, data, size);
        }
        nn::os::UnlockMutex(&field_78);
        return ok;
    }

    // Writes over a block, with room for it.
    template <class T>
    bool Unk_1347350(Unk_13471e0_Entry* entry, T* const& data, const u64& size) {
        nn::os::LockMutex(&field_78);
        if (field_58 != nullptr)
            field_58->vf6(entry);
        bool ok = false;
        if (Unk_Resize(entry, size + 5)) {
            Unk_24319f0 writer = Unk_Writer(entry);
            ok = writer.Unk_1347af0(data, size);
        }
        nn::os::UnlockMutex(&field_78);
        return ok;
    }

    // Adds a block.
    // NON_MATCHING: the original takes the address of field_78 again for
    // Unk_Sort's lock (`add x21, x20, #0x78`) instead of reusing the outer
    // lock's, and keeps the result in w20, which lets the failure paths share
    // their `mov w20, wzr`. Every spelling tried here (lock wrappers, the mutex
    // in a base class, other result shapes) shares the address.
    template <class T>
    bool Unk_13475a0(const u32& key, T* const& data, const u64& size) {
        nn::os::LockMutex(&field_78);
        if (field_58 != nullptr)
            field_58->vf7(&key);
        bool ok = false;
        Unk_1347cd0_Result added = Unk_1347cd0(key, size + 5);
        if (Unk_13471e0_Entry* entry = added.field_0) {
            Unk_24319f0 writer = Unk_Writer(entry);
            if (writer.Unk_1347af0(data, size)) {
                Unk_Sort();
                ok = true;
            } else {
                field_38->vf3(added.field_0->field_8, added.field_0->field_10);
                field_8.pop_back();
            }
        }
        nn::os::UnlockMutex(&field_78);
        return ok;
    }

    // The same, for a block passed by reference (the bytes of `data`).
    template <class T>
    bool Unk_13456e0(const u32& key, const T& data, const u64& size) {
        nn::os::LockMutex(&field_78);
        bool ok;
        if (field_98.load()) {
            if (field_58 != nullptr)
                field_58->vf12();
            ok = false;
        } else if (Unk_13471e0_Entry* entry = Unk_Find(key)) {
            if (!Unk_13471e0(entry) && field_58 != nullptr)
                field_58->vf11(&key);
            ok = Unk_1347350(entry, data, size);
        } else {
            ok = Unk_13475a0(key, data, size);
        }
        nn::os::UnlockMutex(&field_78);
        return ok;
    }

    template <class T>
    bool Unk_1347350(Unk_13471e0_Entry* entry, const T& data, const u64& size) {
        nn::os::LockMutex(&field_78);
        if (field_58 != nullptr)
            field_58->vf6(entry);
        bool ok = false;
        if (Unk_Resize(entry, size + 5)) {
            Unk_24319f0 writer = Unk_Writer(entry);
            ok = writer.Unk_1347af0(&data, size);
        }
        nn::os::UnlockMutex(&field_78);
        return ok;
    }

    // NON_MATCHING: as the add above.
    template <class T>
    bool Unk_13475a0(const u32& key, const T& data, const u64& size) {
        nn::os::LockMutex(&field_78);
        if (field_58 != nullptr)
            field_58->vf7(&key);
        bool ok = false;
        Unk_1347cd0_Result added = Unk_1347cd0(key, size + 5);
        if (Unk_13471e0_Entry* entry = added.field_0) {
            Unk_24319f0 writer = Unk_Writer(entry);
            if (writer.Unk_1347af0(&data, size)) {
                Unk_Sort();
                ok = true;
            } else {
                field_38->vf3(added.field_0->field_8, added.field_0->field_10);
                field_8.pop_back();
            }
        }
        nn::os::UnlockMutex(&field_78);
        return ok;
    }

    // Reads a block.
    template <class T>
    Unk_1346860_Result Unk_1346030(const u32& key, T* const& data, const u64& size) {
        nn::os::LockMutex(&field_78);
        if (field_58 != nullptr)
            field_58->vf5(&key);
        Unk_1346860_Result result;
        result.field_0 = false;
        if (Unk_13471e0_Entry* entry = Unk_Find(key)) {
            Unk_2431910 reader = Unk_Reader(entry);
            result = reader.Unk_1346860(data, size);
        }
        nn::os::UnlockMutex(&field_78);
        return result;
    }

    u8 _0[0x8];
    Entries field_8;
    Unk_13471e0_Allocator* field_38;
    u8 _40[0x18];
    Unk_13471e0_Listener* field_58;
    u8 _60[0x18];
    nn::os::MutexType field_78;
    std::atomic<bool> field_98;
};
PKMN_OFFSET_ASSERT(Unk_13471e0_Store, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_13471e0_Store, field_38, 0x38);
PKMN_OFFSET_ASSERT(Unk_13471e0_Store, field_58, 0x58);
PKMN_OFFSET_ASSERT(Unk_13471e0_Store, field_78, 0x78);
PKMN_OFFSET_ASSERT(Unk_13471e0_Store, field_98, 0x98);
