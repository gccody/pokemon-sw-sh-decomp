// Scope: common
// PPFX::VerifyFeatureLicense (lib/yebis/YEBIS_draft/src/UT/ppfxLicense.h):
// the license check (0x71004ba5a0 to 0x71004bc640). Its fields' getters
// (0x71004bb5d0, 0x71004bb5e0) are lib/yebis/leaf's.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <nn/time.h>
#include <yebis/YEBIS_draft/src/GPU/Unk_StaticsBase.h>
#include <yebis/YEBIS_draft/src/UT/ppfxLicense.h>

namespace PPFX {

// bytes from UNK_NEW_ARRAY (without the destructors' loop)
static inline void Unk_DeleteBytes(u8* bytes) {
    if (bytes != nullptr)
        Unk_4b9a60(Unk_238d5f8, reinterpret_cast<u64*>(bytes) - 1);
}

// the first four bytes of `bits` as a little-endian value, bit by bit
static inline void Unk_ReadBits(s32* value, const u8* bits) {
    *value = 0;
    for (s32 i = 0; i < 32; i++) {
        u8 bit = bits[i / 8] & (1 << (7 - i % 8));
        *value |= bit << (i / 8 * 8);
    }
}

// 0x71004ba5a0: splits the signature (Unk_4baf20) into a tree of streams; one
// leaf is what it says (`out`), three are the first day's year, month and
// day, and four more leaves, decoded with the key (Unk_4bb390), have to be
// copies of those four.
bool Unk_4ba5a0_Self::Unk_4ba5a0(s32* year, s32* month, s32* day, u8** out, size_t* outSize, const u8* data,
                                 size_t size, const char* key, size_t keySize) {
    u8* a0 = nullptr;
    u8* a1 = nullptr;
    size_t a0Size = 0;
    size_t a1Size = 0;
    Unk_4baf20(&a0, &a0Size, &a1, &a1Size, data, size);
    u8* b0 = nullptr;
    u8* b1 = nullptr;
    u8* c0 = nullptr;
    u8* c1 = nullptr;
    size_t b0Size = 0;
    size_t b1Size = 0;
    size_t c0Size = 0;
    size_t c1Size = 0;
    Unk_4baf20(&b0, &b0Size, &b1, &b1Size, a0, a0Size);
    Unk_4baf20(&c0, &c0Size, &c1, &c1Size, a1, a1Size);
    u8* d = nullptr;
    size_t dSize = 0;
    Unk_4bb390(&d, &dSize, c1, c1Size, reinterpret_cast<const u8*>(key), keySize);
    u8* f0 = nullptr;
    u8* f1 = nullptr;
    u8* e1 = nullptr;
    u8* e0 = nullptr;
    u8* h0 = nullptr;
    u8* h1 = nullptr;
    u8* g1 = nullptr;
    u8* g0 = nullptr;
    size_t f0Size = 0;
    size_t f1Size = 0;
    size_t e1Size = 0;
    size_t e0Size = 0;
    size_t h0Size = 0;
    size_t h1Size = 0;
    size_t g1Size = 0;
    size_t g0Size = 0;
    Unk_4baf20(&e0, &e0Size, &e1, &e1Size, b0, b0Size);
    Unk_4baf20(&f0, &f0Size, &f1, &f1Size, e0, e0Size);
    Unk_4baf20(&g0, &g0Size, &g1, &g1Size, c0, c0Size);
    Unk_4baf20(&h0, &h0Size, &h1, &h1Size, g0, g0Size);
    u8* dh0 = nullptr;
    u8* dh1 = nullptr;
    u8* dg1 = nullptr;
    size_t dh0Size = 0;
    size_t dh1Size = 0;
    size_t dg1Size = 0;
    Unk_4bb390(&dh0, &dh0Size, h0, h0Size, reinterpret_cast<const u8*>(key), keySize);
    Unk_4bb390(&dh1, &dh1Size, h1, h1Size, reinterpret_cast<const u8*>(key), keySize);
    Unk_4bb390(&dg1, &dg1Size, g1, g1Size, reinterpret_cast<const u8*>(key), keySize);
    bool result;
    if (b1Size != 0 && f0Size != 0 && f1Size != 0 && e1Size != 0 && memcmp(b1, d, b1Size) == 0 &&
        memcmp(f0, dh0, f0Size) == 0 && memcmp(f1, dh1, f1Size) == 0 && memcmp(e1, dg1, e1Size) == 0) {
#line 107
        *out = UNK_NEW_ARRAY(u8, b1Size);
        memcpy(*out, b1, b1Size);
        *outSize = b1Size;
        Unk_ReadBits(year, f0);
        Unk_ReadBits(month, f1);
        Unk_ReadBits(day, e1);
        result = true;
    } else {
        *year = 0;
        *month = 0;
        *day = 0;
        result = false;
    }
    Unk_DeleteBytes(a0);
    Unk_DeleteBytes(a1);
    Unk_DeleteBytes(b0);
    Unk_DeleteBytes(b1);
    Unk_DeleteBytes(c0);
    Unk_DeleteBytes(c1);
    Unk_DeleteBytes(d);
    Unk_DeleteBytes(f0);
    Unk_DeleteBytes(f1);
    Unk_DeleteBytes(e1);
    Unk_DeleteBytes(e0);
    Unk_DeleteBytes(h0);
    Unk_DeleteBytes(h1);
    Unk_DeleteBytes(g1);
    Unk_DeleteBytes(g0);
    Unk_DeleteBytes(dh0);
    Unk_DeleteBytes(dh1);
    Unk_DeleteBytes(dg1);
    return result;
}

// 0x71004baf20
// NON_MATCHING: the same loop; the original spills the out-parameters at the
// entry (here they get callee-saved registers first), and its selects of the
// nibble's position test the direction the other way round.
void Unk_4ba5a0_Self::Unk_4baf20(u8** out0, size_t* outSize0, u8** out1, size_t* outSize1, const u8* data,
                                 size_t size) {
#line 195
    size_t* counts = UNK_NEW_ARRAY(size_t, 2);
    counts[0] = 0;
    counts[1] = 0;
#line 198
    u8** buffers = UNK_NEW_ARRAY(u8*, 2);
    buffers[0] = nullptr;
    buffers[1] = nullptr;
#line 200
    size_t* sizes = UNK_NEW_ARRAY(size_t, 2);
    sizes[0] = 0;
    sizes[1] = 0;
    size_t end = size * 8;
    size_t pos = 0;
    bool backward = false;
    while (pos < end) {
        size_t index;
        size_t shift;
        if (backward) {
            index = end - 1;
            shift = end;
            end -= 4;
        } else {
            index = pos;
            shift = pos + 4;
            pos += 4;
        }
        shift &= 7;
        index >>= 3;
        backward = Unk_NibbleBit(data, index, shift, 3);
        s32 which = Unk_NibbleBit(data, index, shift, 2);
        size_t n = counts[which]++;
        if (n >= sizes[which] * 8) {
            u8* old = nullptr;
            if (sizes[which] != 0) {
#line 245
                old = UNK_NEW_ARRAY(u8, sizes[which]);
                memcpy(old, buffers[which], sizes[which]);
                Unk_DeleteBytes(buffers[which]);
            }
#line 249
            buffers[which] = UNK_NEW_ARRAY(u8, sizes[which] + 1);
            if (sizes[which] != 0) {
                memcpy(buffers[which], old, sizes[which]);
                Unk_DeleteBytes(old);
            }
            buffers[which][sizes[which]] = 0;
            sizes[which]++;
        }
        u32 bit = Unk_NibbleBit(data, index, shift, 1);
        buffers[which][n >> 3] |= bit << (7 - (n & 7));
    }
#line 274
    *out0 = UNK_NEW_ARRAY(u8, sizes[0] + 1);
    memset(*out0, 0, sizes[0] + 1);
    memcpy(*out0, buffers[0], sizes[0]);
    *outSize0 = sizes[0];
#line 279
    *out1 = UNK_NEW_ARRAY(u8, sizes[1] + 1);
    memset(*out1, 0, sizes[1] + 1);
    memcpy(*out1, buffers[1], sizes[1]);
    *outSize1 = sizes[1];
    UNK_DELETE_ARRAY(counts);
    Unk_DeleteBytes(buffers[0]);
    Unk_DeleteBytes(buffers[1]);
    UNK_DELETE_ARRAY(buffers);
    UNK_DELETE_ARRAY(sizes);
}

// 0x71004bb390
void Unk_4ba5a0_Self::Unk_4bb390(u8** out, size_t* outSize, const void* data, size_t size, const u8* key,
                                 size_t keySize) {
    if (size == 0)
        return;
#line 157
    *out = UNK_NEW_ARRAY(u8, size + 1);
    memset(*out, 0, size + 1);
    memcpy(*out, data, size);
    *outSize = size;
    if (keySize != 0) {
        size_t j = 0;
        for (size_t i = 0; i < size; i++) {
            j = j == keySize ? 0 : j;
            (*out)[i] = (*out)[i] ^ key[j++];
        }
    } else {
        for (size_t i = 0; i < size; i++)
            (*out)[i] = ~(*out)[i];
    }
}

// 0x71004bb4d0
VerifyFeatureLicense::VerifyFeatureLicense()
    : field_8(""), field_18(""), field_28(0), field_2c(0), field_30(0), field_34(0), field_38("") {}

// 0x71004bb530, 0x71004bb580 (deleting)
VerifyFeatureLicense::~VerifyFeatureLicense() {
    ;
}

// 0x71004bb5f0
s32 VerifyFeatureLicense::Unk_4bb5f0() {
    Unk_LicenseInfo info;
    field_28 = 0;
    field_2c = 0;
    field_30 = 0;
    field_34 = 0;
    s32 result = Unk_4bb6e0(&info);
    if (result == 0) {
        result = Unk_4bbe40(&info);
        if (result == 0) {
            field_2c = info.field_c;
            field_30 = info.field_10;
            field_34 = info.field_14;
            field_38 = info.field_28;
        }
    }
    return result;
}

// 0x71004bb6e0
s32 VerifyFeatureLicense::Unk_4bb6e0(Unk_LicenseInfo* info) {
    char feature[128] = {};
    char mac[32] = {};
    char license[12000] = {};
    Unk_LicenseMap map;
    if (Unk_4bc0d0(&map) != 0) {
        field_28 = 1;
        return -3;
    }
    for (s32 i = 0; i < 9; i++) {
        Unk_TFXString key(Unk_1eea621[i], strlen(Unk_1eea621[i]), -1);
        if (map.find(key) == map.end()) {
            field_28 = 1;
            return -3;
        }
    }
    strcpy(feature, map[Unk_TFXString(Unk_1eea621[0])].field_8);
    s32 beginYear = atoi(map[Unk_TFXString(Unk_1eea621[1])].field_8);
    s32 beginMonth = atoi(map[Unk_TFXString(Unk_1eea621[2])].field_8);
    s32 beginDay = atoi(map[Unk_TFXString(Unk_1eea621[3])].field_8);
    s32 endYear = atoi(map[Unk_TFXString(Unk_1eea621[4])].field_8);
    s32 endMonth = atoi(map[Unk_TFXString(Unk_1eea621[5])].field_8);
    s32 endDay = atoi(map[Unk_TFXString(Unk_1eea621[6])].field_8);
    strcpy(mac, map[Unk_TFXString(Unk_1eea621[7])].field_8);
    strcpy(license, map[Unk_TFXString(Unk_1eea621[8])].field_8);
    info->field_0 = beginYear;
    info->field_4 = beginMonth;
    info->field_8 = beginDay;
    info->field_c = endYear;
    info->field_10 = endMonth;
    info->field_14 = endDay;
    info->field_28 = Unk_TFXString(feature);
    info->field_18 = Unk_TFXString(mac);
    info->field_38 = Unk_TFXString(license);
    return 0;
}

// 0x71004bbe40
s32 VerifyFeatureLicense::Unk_4bbe40(Unk_LicenseInfo* info) {
    s32 beginYear;
    Unk_4ba5a0_Self codec;
    s32 beginMonth;
    s32 beginDay;
    s32 length = info->field_38.field_0;
    s32 count = length / 2;
#line 535
    u8* data = UNK_NEW_ARRAY(u8, count);
    const char* text = info->field_38.field_8;
    for (s32 i = 0; i < count; i++) {
        u32 value;
        sscanf(&text[i * 2], "%02x", &value);
        data[i] = value;
    }
    Unk_TFXString mac;
    u8* out = nullptr;
    size_t outSize = 0;
    bool ok = codec.Unk_4ba5a0(&beginYear, &beginMonth, &beginDay, &out, &outSize, data, count, field_18.field_8,
                               field_18.field_0);
    Unk_DeleteBytes(data);
    if (!ok) {
        field_28 = 1;
        return -3;
    }
    u8* signedData = out;
    Unk_LicenseSigned end;
    memcpy(&end, signedData, sizeof(end));
    s32 endYear = end.field_0;
    s32 endMonth = end.field_4;
    s32 endDay = end.field_8;
    end.field_10[0x11] = '\0';
    mac = end.field_10;
    Unk_DeleteBytes(signedData);
    s32 day = info->field_8;
    s32 year = info->field_0;
    s32 month = info->field_4;
    if (day != beginDay || year != beginYear || month != beginMonth || info->field_c != endYear ||
        info->field_10 != endMonth || info->field_14 != endDay || info->field_18 != mac) {
        field_28 = 1;
        return -3;
    }
    if (year == 0 && month == 0 && day == 0 && endYear == 0 && endMonth == 0 && endDay == 0)
        return 0;
    bool initialized = nn::time::IsInitialized();
    if (!initialized)
        nn::time::Initialize();
    nn::time::PosixTime now;
    nn::time::CalendarTime first = {};
    first.field_0 = year;
    first.field_2 = month;
    first.field_3 = day;
    nn::time::PosixTime begin = nn::time::ToPosixTimeFromUtc(first);
    nn::time::StandardUserSystemClock::GetCurrentTime(&now);
    nn::time::CalendarTime last = {0, 0, 0, 23, 59, 59};
    last.field_0 = endYear;
    last.field_2 = endMonth;
    last.field_3 = endDay;
    nn::time::PosixTime finish = nn::time::ToPosixTimeFromUtc(last);
    if (!initialized)
        nn::time::Finalize();
    if (now.field_0 < begin.field_0 || now.field_0 > finish.field_0) {
        field_28 = 2;
        return -3;
    }
    return 0;
}

// 0x71004bc0d0
s32 VerifyFeatureLicense::Unk_4bc0d0(Unk_LicenseMap* map) {
    char text[12000] = {};
    char* fields[9] = {};
    char* save = nullptr;
    memcpy(text, field_8.field_8, field_8.field_0);
    fields[0] = text;
    s32 count = 0;
    char* field = strtok_r(text, ",", &save);
    while (field != nullptr) {
        if (count > 8)
            return -3;
        fields[count] = field;
        field = strtok_r(nullptr, ",", &save);
        count++;
    }
    if (count != 9)
        return -3;
    for (size_t i = 0; i < 9; i++) {
        char* name = strtok_r(fields[i], "=", &save);
        char* value = strtok_r(nullptr, "=", &save);
        while (*name == ' ')
            name++;
        char* end = name;
        while (*end != ' ' && *end != '\0')
            end++;
        *end = '\0';
        while (*value == ' ')
            value++;
        end = value;
        while (*end != ' ' && *end != '\0')
            end++;
        *end = '\0';
        Unk_TFXString key(name);
        Unk_TFXString text(value);
        map->insert(std::pair<Unk_TFXString, Unk_TFXString>(key, text));
    }
    return 0;
}

}  // namespace PPFX

// 0x71004bc5b0: _GLOBAL__sub_I_ppfxLicense.cpp
