// Scope: common
// SiCore's CRC-32 (the reflected polynomial 0xedb88320): the table and the
// sums of a buffer, a C string and a SiString, forwards and backwards. The
// file's name isn't in the executable; its static initialiser (0x71004c35c0)
// is lib/yebis/static/Unk_4c35c0.cpp, whose handle is the TU's other static
// object: the table is declared here as the hidden global it is reached as.
#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/Unk_StringFuncs.h>

// 0x71024e9458
u32 Unk_24e9458[256] __attribute__((visibility("hidden")));

// 0x71004c3360
void Unk_4c3360() {
    for (u32 i = 0; i < 256; i++) {
        u32 value = i;
        for (int j = 0; j < 8; j++) {
            value = (value & 1) ? (value >> 1) ^ 0xedb88320 : value >> 1;
        }
        Unk_24e9458[i] = value;
    }
}

// 0x71004c3410 (the size is a 64-bit parameter, converted to an int as the
// string hashes below convert theirs: the callers pass it sign-extended,
// `ldrsw x0` or a 64-bit `mul`)
u32 Unk_4c3410(s64 length, const u8* data) {
    int size = static_cast<int>(length);
    if (size < 1) {
        return 0;
    }
    u32 crc = 0xffffffff;
    for (int i = 0; i < size; i++) {
        crc = Unk_24e9458[(crc ^ *data++) & 0xff] ^ (crc >> 8);
    }
    return ~crc;
}

// 0x71004c3450
u32 Unk_4c3450(s64 length, const u8* data) {
    int size = static_cast<int>(length);
    if (size < 1) {
        return 0;
    }
    u32 crc = 0xffffffff;
    for (int i = size - 1; i >= 0; i--) {
        crc = Unk_24e9458[(crc ^ data[i]) & 0xff] ^ (crc >> 8);
    }
    return ~crc;
}

// 0x71004c34a0
u32 Unk_4c34a0(const char* s) {
    int size = static_cast<int>(Unk_4c4290(s));
    if (size < 1) {
        return 0;
    }
    const u8* data = reinterpret_cast<const u8*>(s);
    u32 crc = 0xffffffff;
    for (int i = 0; i < size; i++) {
        crc = Unk_24e9458[(crc ^ *data++) & 0xff] ^ (crc >> 8);
    }
    return ~crc;
}

// 0x71004c3510
u32 Unk_4c3510(const SiSDK3::SiString<char>* s) {
    int size = static_cast<int>(s->field_10);
    if (size < 1) {
        return 0;
    }
    const u8* data = reinterpret_cast<const u8*>(s->m_pBuffer);
    u32 crc = 0xffffffff;
    for (int i = 0; i < size; i++) {
        crc = Unk_24e9458[(crc ^ *data++) & 0xff] ^ (crc >> 8);
    }
    return ~crc;
}

// 0x71004c3560
u32 Unk_4c3560(const SiSDK3::SiString<char>* s) {
    return Unk_4c3450(s->field_10, reinterpret_cast<const u8*>(s->m_pBuffer));
}
