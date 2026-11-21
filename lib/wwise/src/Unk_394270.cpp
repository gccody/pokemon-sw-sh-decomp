// Scope: common
// Two objects that are written to and read from a stream (the classes with
// the vtables 0x71023829b0 and 0x71023829f8): one with two bit arrays, a list
// of indices and a total, one with a flag and an index. Placeholder names; the
// members are vf<slot>, as in lib/wwise/class.
#include "Unk_PlacementNew.h"
#include "containers.h"

extern "C" void* memset(void* dest, int value, size_t size);

// What the objects are written to or read from: true when it worked.
struct Unk_394850_Stream {
    virtual bool vf0(void* data, u32 size, u32* done);
};

// Destroys and frees an object, if there is one.
template <class T>
static inline void Unk_394220_Delete(T* object) {
    if (object != nullptr)
        Unk_Delete(object);
}

// The state of a pseudo-random sequence (0x71024bbc28).
extern u64 Unk_24bbc28;

class Unk_23829b0 {
public:
    explicit Unk_23829b0(u16 count)
        : field_8(count * 50000), field_c(count * 50000), field_10(count), field_12(count),
          field_28(nullptr), field_30(nullptr) {
        field_18.field_0 = nullptr;
        field_18.field_8 = 0;
        field_18.field_c = 0;
    }
    virtual ~Unk_23829b0();
    virtual void vf2();
    virtual u32 vf3();
    virtual Unk_23829b0* vf4(u16 count);
    virtual u32 vf5(Unk_394850_Stream* stream, u16 count);
    virtual u32 vf6(Unk_394850_Stream* stream, u16 count);

    u32 Unk_3942b0(u16 count);
    void Unk_3946d0(u16 index);
    bool Unk_394700(u16 index);
    void Unk_394730(u64 count);
    void Unk_394770(u16 index);
    void Unk_3947a0(u16 index);
    bool Unk_3947d0(u16 index);
    u32 Unk_394810();

    u32 field_8;
    u32 field_c;  // the total
    u16 field_10;
    u16 field_12;  // the number of bits
    Unk_Array<u16> field_18;
    u8* field_28;  // a bit an index
    u8* field_30;  // a second bit an index, in the same allocation
};
PKMN_SIZE_ASSERT(Unk_23829b0, 0x38);

// 0x7100394270
void Unk_394270(Unk_23829b0* self, u16 count) {
    new (self) Unk_23829b0(count);
}

// 0x71003942b0: 1, 2 without memory for the bits, 0x34 without memory for
// the list.
u32 Unk_23829b0::Unk_3942b0(u16 count) {
    u32 size = (field_12 + 7) >> 3;
    field_28 = static_cast<u8*>(Unk_PoolDefault::Alloc(size * 2));
    if (field_28 == nullptr)
        return 2;
    field_30 = field_28 + size;
    memset(field_28, 0, size * 2);
    return field_18.Reserve(count < 4 ? count : 4);
}

// 0x7100394360 (and 0x71003943d0, the deleting destructor)
Unk_23829b0::~Unk_23829b0() {
    if (field_28 != nullptr)
        Unk_PoolDefault::Free(field_28);
    field_18.Term();
}

// 0x7100394220
void Unk_23829b0::vf2() {
    Unk_394220_Delete(this);
}

// 0x71003946d0
void Unk_23829b0::Unk_3946d0(u16 index) {
    field_28[index >> 3] |= 1 << (index & 7);
}

// 0x7100394700
bool Unk_23829b0::Unk_394700(u16 index) {
    return (field_28[index >> 3] & (1 << (index & 7))) != 0;
}

// 0x7100394730
void Unk_23829b0::Unk_394730(u64 count) {
    memset(field_28, 0, static_cast<u32>((count + 7) >> 3));
    field_10 = count;
}

// 0x7100394770
void Unk_23829b0::Unk_394770(u16 index) {
    field_30[index >> 3] |= 1 << (index & 7);
}

// 0x71003947a0
void Unk_23829b0::Unk_3947a0(u16 index) {
    field_30[index >> 3] &= ~(1 << (index & 7));
}

// 0x71003947d0
bool Unk_23829b0::Unk_3947d0(u16 index) {
    return (field_30[index >> 3] & (1 << (index & 7))) != 0;
}

// 0x7100394810: a number below the total.
u32 Unk_23829b0::Unk_394810() {
    Unk_24bbc28 = Unk_24bbc28 * 0x5851f42d4c957f2d + 1;
    return static_cast<u32>(Unk_24bbc28 >> 33) % field_c;
}

// 0x7100394850
// NON_MATCHING: the original sets the result of a failure before the first,
// third and fourth write only; here also before the fifth (one instruction
// more: the constant 2 that write's size and the result share).
u32 Unk_23829b0::vf5(Unk_394850_Stream* stream, u16 count) {
    u32 done;
    u16 written = count;
    u32 doneBits = 0;
    if (!stream->vf0(&written, 2, &done))
        return 2;
    if (!stream->vf0(&field_c, 4, &done))
        return 2;
    if (!stream->vf0(&field_10, 2, &done))
        return 2;
    if (!stream->vf0(&field_12, 2, &done))
        return 2;
    u16 length = field_18.Length();
    if (!stream->vf0(&length, 2, &done))
        return 2;
    u32 size = (count + 7) >> 3;
    if (!stream->vf0(field_28, size, &doneBits))
        return 2;
    if (!stream->vf0(field_30, size, &doneBits))
        return 2;
    if (field_18.Length() != 0) {
        if (!stream->vf0(field_18.field_0, field_18.Length() * 2, &doneBits))
            return 2;
    }
    return 1;
}

class Unk_23829f8 {
public:
    Unk_23829f8() : field_8(1), field_a(0xffff) {}
    virtual ~Unk_23829f8();
    virtual void vf2();
    virtual u32 vf3();
    virtual Unk_23829f8* vf4();
    virtual u32 vf5(Unk_394850_Stream* stream);
    virtual u32 vf6(Unk_394850_Stream* stream);

    u8 field_8;
    u16 field_a;
};
PKMN_SIZE_ASSERT(Unk_23829f8, 0x10);

// 0x7100394c80
void Unk_394c80(Unk_23829f8* self) {
    new (self) Unk_23829f8;
}

// 0x7100394cd0
void Unk_23829f8::vf2() {
    Unk_394220_Delete(this);
}

// 0x7100394d30: a copy, null without memory.
Unk_23829f8* Unk_23829f8::vf4() {
    Unk_23829f8* copy = new (Unk_237e820) Unk_23829f8;
    if (copy != nullptr) {
        copy->field_8 = field_8;
        copy->field_a = field_a;
    }
    return copy;
}

// 0x7100394da0
u32 Unk_23829f8::vf5(Unk_394850_Stream* stream) {
    u32 done2;
    u32 done;
    if (!stream->vf0(&field_8, 1, &done))
        return 2;
    return stream->vf0(&field_a, 2, &done2) ? 1 : 2;
}

// 0x7100394e30
u32 Unk_23829f8::vf6(Unk_394850_Stream* stream) {
    u32 done2;
    u32 done;
    if (!stream->vf0(&field_8, 1, &done))
        return 2;
    return stream->vf0(&field_a, 2, &done2) ? 1 : 2;
}
