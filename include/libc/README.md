# include/libc: musl 1.1.24's headers, as the SDK's libc

Nintendo's libc is musl-based (`main` imports `__nnmusl_init_dso`), and its
headers aren't public. musl 1.1.24's aarch64 headers stand in for them (MIT,
`COPYRIGHT`). `CMakeLists.txt` puts them on every TU's search path, after the
other include directories (`-isystem`).

They're upstream's, unchanged, except where the binary shows that the SDK's
header differs. Each change has an `NX:` comment at the place it's made:

| Header | Change | Evidence |
|---|---|---|
| `errno.h` | `__errno_location` isn't `__attribute__((const))` | protobuf's `FloatToBuffer` (Sword `0x71006fee00`) calls it again after `strtof` to read `errno`, where a `const` function's result would be reused. libcurl's `curl_getdate` (`0x7101764750`) matches only without it too |
| `bits/alltypes.h` | `pthread_mutex_t` is `0x20` bytes, not 40 | protobuf's `Mutex::Mutex` (`0x71006fff70`) allocates its `Internal`, which holds only a `pthread_mutex_t`, with `operator new(0x20)`. So do `InitLogSilencerCount` and `InitShutdownFunctions` |

The layout of `pthread_mutex_t` beyond its size isn't visible, so the union
keeps musl's shape with 8 ints. With both changes, `tools/check.py` gives the
same results for every other function in both games. Details are in
`docs/compiler.md`, "Protocol Buffers 3.0.0".

Change a header here only on evidence like this, with an `NX:` comment and a
row in this table, and run `tools/check.py` over everything: every TU reads
these headers.
