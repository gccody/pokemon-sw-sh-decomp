// Scope: common
// NintendoWare Font 7.3.2 (its SDK MW tag is referenced from 0x710177b2a0):
// functions that read UTF-8 characters through nn::util. Placeholder names.
#include <nn/util.h>
#include <types.h>

// 0x710177cf20
u32 Unk_177cf20(const char** str) {
    u32 code;
    char utf8[4];
    nn::util::PickOutCharacterFromUtf8String(utf8, str);
    code = 0;
    nn::util::ConvertCharacterUtf8ToUtf32(&code, utf8);
    return code;
}

// 0x710177dcf0
const char* Unk_177dcf0(void* self, bool* isPrintable, const char* str) {
    char utf8[4] = {};
    nn::util::PickOutCharacterFromUtf8String(utf8, &str);
    *isPrintable = true;
    return str;
}
