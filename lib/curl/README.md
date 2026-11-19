# lib/curl: libcurl 7.55.1

Nintendo's SDK libcurl (`SDK MW+Nintendo+NintendoSDK_libcurl-7_3_2-Release`,
`libcurl/7.55.1`), which `main` links after Lua and the NEX/Pia libraries.
It's built with clang 7.0.x `-O3` and the game's global flags. See
`docs/compiler.md`, section "Nintendo SDK middleware", "libcurl 7.55.1".

What's here:

- `include/curl/`, `lib/*.h`, `lib/vtls/*.h`, `lib/vauth/*.h`: curl 7.55.1's
  headers (from `curl-7.55.1.tar.xz`), with Nintendo's changes (below).
- `lib/*.c`, `lib/vauth/digest.c`, `lib/vtls/vtls.c`: the 56 curl 7.55.1 TUs
  that have code in the binary, with Nintendo's changes. The TUs of protocols,
  auth methods and backends that aren't in it (FTP, SASL, NTLM,
  `curl_threads.c`, upstream's TLS backends ...) are left out.
- `lib/curl_config.h`: not from curl. It's the configuration reconstructed from
  the binary, with the evidence for each choice in its comments.
- `zlib/zlib.h`, `zlib/zconf.h`: zlib 1.2.11's headers (zlib license, in
  `zlib.h`), with the SDK's `ZLIB_VERSION`. The SDK's zlib is 1.2.11, and
  `HAVE_LIBZ` puts a `z_stream` in curl's structs.

`CMakeLists.txt` builds these with curl's defines for a static library
(`HAVE_CONFIG_H`, `BUILDING_LIBCURL`, `CURL_STATICLIB`) and
`lib/curl/include`, `lib/curl/lib`, `lib/curl/zlib` and `lib/curl/nnsocket`
as include directories (`pkmn_library_settings(lib/curl ...)`).

## Nintendo's changes

Nintendo changed curl in ways that aren't public. What the binary shows of
them is reconstructed here, and every change to an upstream file is marked
`Pokemon SwSh decomp` (the upstream code it replaces stays under `#if 0` or
`#else` where there was any). `docs/compiler.md`, section "Nintendo SDK
middleware", "libcurl 7.55.1", "Nintendo's changes", has the evidence. In
short:

- `lib/curl_memory.h`, `lib/easy.c`: curl allocates through Nintendo's wrapper
  functions and their table, not the `Curl_c*` pointers. `global_init` and
  `curl_global_cleanup` call Nintendo's functions.
- `lib/urldata.h`, `lib/url.c`: Nintendo's fields in `struct UserDefined`,
  `struct ssl_primary_config` and `struct ssl_connect_data`
  (`field_<offset>`: what they are isn't known).
- `lib/curl_config.h`, `lib/curl_setup.h`, `lib/vtls/vtls.h`,
  `lib/vtls/nnssl.h`, `lib/vtls/nnssl.c`, `lib/getinfo.c`: `USE_SSL` with
  Nintendo's `nn::ssl` backend (`USE_NINTENDO_SSL`). `nnssl.h` and `nnssl.c`
  aren't upstream's: they're the backend's API setup and the functions of it
  reconstructed so far.
- `nnsocket/`: not upstream's. It stands in for the SDK's socket headers
  (BSD-style `struct sockaddr`, BSD `SOL_SOCKET`/`SO_*` values, the
  `nnsocket*` functions), in place of musl's. `lib/curl_setup_once.h`,
  `lib/select.h` and `lib/nonblock.c` route `sclose`, `sfcntl`, `poll` and
  `SOCKERRNO` to the SDK.
- `lib/curl_nnstdio.h` (not upstream's), `lib/curl_printf.h`,
  `lib/timeval.c`, `lib/mprintf.c`, `lib/hostip.h`, `lib/hostip4.c`,
  `lib/asyn-thread.c`: curl's `time()`, stdio, `curlx_tvnow` and
  `gethostbyname` go to Nintendo's functions.
- `nintendo/`: not upstream's. Nintendo's own TUs, reconstructed (the memory
  functions, the SDK tag function, the time and stdio functions). Neither
  their names nor the files' names are known, so they're `Unk_<addr>` (Sword
  addresses).

The named functions that don't match have status `M` in `data/functions.csv`.
The section in `docs/compiler.md` lists what's still missing (the resolver
thread, Nintendo's options in `Curl_setopt`, the `nn::ssl` backend's
connection functions ...). These files are upstream's apart from the marked
changes, so the `// NON_MATCHING: <reason>` comments that `M` functions get
elsewhere can't go in them: that section is that comment for every `M`
function under `lib/curl`.

The compiled functions that have no original identified in the binary are in
`data/unidentified_functions.csv`: some may be in the binary, changed beyond
recognition, and the rest were dropped by the linker.

## License

curl: `COPYING` (MIT/X derivative, see https://curl.se/docs/copyright.html).
zlib headers: the zlib license at the top of `zlib/zlib.h`.
