// PPFX::VerifyFeatureLicense (RTTI) and what checks a license with it
// (C:/workspace/YEBIS_draft/src/UT/ppfxLicense.cpp is the __FILE__ of their
// allocations). The license is a text of nine "key=value" fields separated by
// commas (the keys' table, 0x7101eea621, names them: FeatureId, BeginYear,
// BeginMonth, BeginDay, EndYear, EndMonth, EndDay, MacAddress, License).
// Placeholder members; the header's name isn't in the executable.
#pragma once

#include <map>

#include <yebis/YEBIS_draft/src/GPU/GPUMemoryAllocator.h>
#include <yebis/YEBIS_draft/src/GPU/TinyEffect/TFXString.h>

// 0x7100452800 (TFXString.cpp, lib/yebis/leaf's name): the strings' order.
// Its callers here test the whole register (`cmp w0, #0`), so the result is
// an int to them.
struct Unk_452800;
s32 Unk_452800_less(const Unk_452800* a, const Unk_452800* b);

namespace PPFX {

// the keys of a license's fields, 12 characters each
extern const char Unk_1eea621[9][12];

// The order of the fields' map: the strings' (an out-of-line function)
struct Unk_LicenseLess {
    bool operator()(const Unk_TFXString& a, const Unk_TFXString& b) const {
        return Unk_452800_less(reinterpret_cast<const Unk_452800*>(&a), reinterpret_cast<const Unk_452800*>(&b)) != 0;
    }
};
typedef std::map<Unk_TFXString, Unk_TFXString, Unk_LicenseLess,
                 Unk_StlAllocator<std::pair<const Unk_TFXString, Unk_TFXString>>>
    Unk_LicenseMap;

// The end of what a signature says (0x24 bytes): the last day (year, month,
// day) and the machine's address (17 characters)
struct Unk_LicenseSigned {
    s32 field_0;
    s32 field_4;
    s32 field_8;
    s32 field_c;
    char field_10[0x14];
};
PKMN_SIZE_ASSERT(Unk_LicenseSigned, 0x24);

// What a license says (0x48 bytes): the first and last day it is valid
// (year, month, day; all zero for no limit), the machine and feature it is
// for, and the signature, as hex digits.
struct Unk_LicenseInfo {
    Unk_LicenseInfo() : field_0(2000), field_4(1), field_8(1), field_c(2000), field_10(1), field_14(1) {}

    s32 field_0;
    s32 field_4;
    s32 field_8;
    s32 field_c;
    s32 field_10;
    s32 field_14;
    Unk_TFXString field_18;  // MacAddress
    Unk_TFXString field_28;  // FeatureId
    Unk_TFXString field_38;  // License
};
PKMN_SIZE_ASSERT(Unk_LicenseInfo, 0x48);

// What the signature is decoded with: an object without members whose
// functions the license check calls on a local.
struct Unk_4ba5a0_Self {
    // 0x71004ba5a0: decodes a signature with a key: the first day (year,
    // month, day) and the rest of what it says (`out`, `outSize` bytes)
    bool Unk_4ba5a0(s32* year, s32* month, s32* day, u8** out, size_t* outSize, const u8* data, size_t size,
                    const char* key, size_t keySize);
    // 0x71004bb390: a copy of `size` bytes (and a zero after them), each
    // combined with the key's bytes in turn (inverted without a key)
    void Unk_4bb390(u8** out, size_t* outSize, const void* data, size_t size, const u8* key, size_t keySize);
    // 0x71004baf20: splits `size` bytes of nibbles into two bit streams (each
    // nibble: the direction of the next one, the stream, the bit)
    void Unk_4baf20(u8** out0, size_t* outSize0, u8** out1, size_t* outSize1, const u8* data, size_t size);
};

class VerifyFeatureLicense {
public:
    VerifyFeatureLicense();           // 0x71004bb4d0
    virtual ~VerifyFeatureLicense();  // 0x71004bb530, 0x71004bb580

    // 0x71004bb5f0: checks the license text; 0 or -3
    s32 Unk_4bb5f0();
    // 0x71004bb6e0: reads the fields into `info`
    s32 Unk_4bb6e0(Unk_LicenseInfo* info);
    // 0x71004bbe40: checks the signature and the dates
    s32 Unk_4bbe40(Unk_LicenseInfo* info);
    // 0x71004bc0d0: splits the text into its fields
    s32 Unk_4bc0d0(Unk_LicenseMap* map);

    Unk_TFXString field_8;   // the license text
    Unk_TFXString field_18;  // the key its signature is checked with
    s32 field_28;            // why it failed: 1 not valid, 2 expired
    s32 field_2c;            // the last day: year, month, day
    s32 field_30;
    s32 field_34;
    Unk_TFXString field_38;  // the feature
};
PKMN_OFFSET_ASSERT(VerifyFeatureLicense, field_28, 0x28);
PKMN_OFFSET_ASSERT(VerifyFeatureLicense, field_38, 0x38);
PKMN_SIZE_ASSERT(VerifyFeatureLicense, 0x48);

}  // namespace PPFX
