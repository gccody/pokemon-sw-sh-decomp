// Scope: common
// A function between two static initialisers (placeholder file and name);
// 0x71004cbbb0 is lib/yebis/leaf's.
#include <types.h>

// 0x71004c4290, 0x71004c5750: SiCore's string length and append
s64 Unk_4c4290(const char* s);
void Unk_4c5750(char* dst, s64 size, const char* src, s64 count);

// 0x71004cbae0: a path's extension (after its last '.', when no separator
// comes after it), copied into out (a size of -1: 0x400 characters); returns
// where it starts, or the path's end. The search reads the character before
// the path when it gets there, as the original does.
const char* Unk_4cbae0(const char* path, char* out, size_t size) {
    if (out == nullptr) {
        return nullptr;
    }
    out[0] = 0;
    s64 length = Unk_4c4290(path);
    if (length == 0) {
        return nullptr;
    }
    if (size < 2) {
        return path + length;
    }
    s64 i = length;
    while (!(path[i] == '.' || path[i] == '/' || path[i] == '\\' || path[i] == ':') && i >= 0) {
        i--;
    }
    if (i < 0 || path[i] != '.') {
        return path + length;
    }
    if (size == static_cast<size_t>(-1)) {
        size = 0x400;
    }
    Unk_4c5750(out, size, path + i + 1, size - 1);
    return path + i + 1;
}
