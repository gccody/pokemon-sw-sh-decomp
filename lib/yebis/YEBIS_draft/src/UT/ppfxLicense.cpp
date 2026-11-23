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
