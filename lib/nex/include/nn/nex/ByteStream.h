#pragma once
#include <algorithm>
#include <nn/nex/RootObject.h>

// 0x71015c8ad0: appends `size` bytes at `data` to the stream's buffer.
bool Unk_15c8ad0(void* stream, u64 data, u64 size);

namespace nn {
namespace nex {

// N2nn3nex6BufferE (a RefCountedObject): the bytes a ByteStream reads and writes.
// NEX is built with strict aliasing, and its inlined reads keep m_size across
// any store but a 64-bit one, but load m_data and m_offset again after every
// store, as if they could alias anything: the anonymous unions model that
// (an access through a union member may alias any type).
class Buffer {
public:
    u8 _0[0x10];
    union {
        u8* m_data;
    };
    size_t m_size;
    size_t m_capacity;
    union {
        size_t m_offset;  // where the data starts in m_data
    };
};
PKMN_OFFSET_ASSERT(Buffer, m_offset, 0x28);

// N2nn3nex10ByteStreamE: (de)serialises NEX's types into a Buffer.
class ByteStream : public RootObject {
public:
    bool Write(const void* data, size_t size) { return Unk_15c8ad0(this, (u64)data, size); }
    template <class T>
    bool Write(const T& v) {
        return Write(&v, sizeof(T));
    }
    // 0x71015c8aa0: moves the write position (the buffer's size).
    bool Unk_15c8aa0(size_t pos);

    bool m_error;
    Buffer* m_buffer;
    size_t m_pos;  // the read position
    u8 _20[0x49];
    bool m_noHeader;  // structures are written without their version and length
};
PKMN_OFFSET_ASSERT(ByteStream, m_buffer, 0x10);
PKMN_OFFSET_ASSERT(ByteStream, m_noHeader, 0x69);

}  // namespace nex
}  // namespace nn

// The inline reads of the DDL stream-in functions (helpers; the names aren't
// the executable's).
namespace nn {
namespace nex {

// A scalar; zero and the stream's error flag when there isn't enough left.
template <class T>
inline bool ReadField(ByteStream* s, T& v) {
    Buffer* b = s->m_buffer;
    if (b->m_size - s->m_pos < sizeof(T)) {
        s->m_error = true;
        v = 0;
        return false;
    }
    v = *reinterpret_cast<const T*>(b->m_data + b->m_offset + s->m_pos);
    s->m_pos += sizeof(T);
    return true;
}

// A structure's length, after its version.
inline bool ReadLength(ByteStream* s, u32& length) {
    Buffer* b = s->m_buffer;
    if (b->m_size - s->m_pos < 4) {
        s->m_error = true;
        return false;
    }
    const u8* p = b->m_data + b->m_offset + s->m_pos;
    length = p[0] | (p[1] << 8) | (p[2] << 16) | (p[3] << 24);
    s->m_pos += 4;
    return true;
}

// Skips to the end of a structure that started at `start`, if it is inside
// what was read and the buffer.
inline void EndStructure(ByteStream* s, size_t start, u32 length) {
    size_t pos = s->m_pos;
    size_t end = start + length;
    if (pos > end || s->m_buffer->m_size < end) {
        s->m_error = true;
        return;
    }
    s->m_pos = end;
}

}  // namespace nex
}  // namespace nn
