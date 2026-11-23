// YEBIS's log lines: every one is two calls of the log's printf
// (0x7100417a30), the first with the file and line. Four kinds, each with its
// switch, under one master switch. The macros' names are the tags they print;
// the header's name isn't in the executable (placeholder). A file defines
// PPFX_FILE, the path its lines print, before it includes this.
#pragma once

#include <types.h>

// log switches: all messages, PPFX_WARNING's, PPFX_ERROR's, PPFX_LOG's and PPFX_FN's
extern s32 Unk_238c1e0;
extern s32 Unk_238c1e4;
extern s32 Unk_238c1e8;
extern s32 Unk_24e0008;
extern s32 Unk_24e0014;

// the switch of the lines that describe what is created (PPFX_INFO)
extern s32 Unk_24e000c;

// 0x7100417a30: printf to the log
s32 Unk_417a30(const char* format, ...);

#define UNK_PPFX_PRINT(enabled, tag, ...)                   \
    do {                                                    \
        if (Unk_238c1e0 != 0 && (enabled) != 0) {           \
            Unk_417a30(PPFX_FILE "(%d) : " tag, __LINE__);  \
            Unk_417a30(__VA_ARGS__);                        \
        }                                                   \
    } while (0)
#define PPFX_LOG(...) UNK_PPFX_PRINT(Unk_24e0008, "PPFX: ", __VA_ARGS__)
#define PPFX_FN(...) UNK_PPFX_PRINT(Unk_24e0014, "PPFX FN: ", __VA_ARGS__)
#define PPFX_WARNING(...) UNK_PPFX_PRINT(Unk_238c1e4, "PPFX WARNING: ", __VA_ARGS__)
#define PPFX_ERROR(...) UNK_PPFX_PRINT(Unk_238c1e8, "PPFX ERROR: ", __VA_ARGS__)
// A line without file and line (placeholder name): the code that makes its
// arguments is itself under `if (Unk_24e000c != 0)`.
#define UNK_PPFX_INFO(...)                                  \
    do {                                                    \
        if (Unk_238c1e0 != 0 && Unk_24e000c != 0) {         \
            Unk_417a30("PPFX: ");                           \
            Unk_417a30(__VA_ARGS__);                        \
        }                                                   \
    } while (0)
