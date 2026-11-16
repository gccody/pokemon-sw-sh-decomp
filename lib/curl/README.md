# lib/curl: libcurl 7.55.1

Nintendo's SDK libcurl (`SDK MW+Nintendo+NintendoSDK_libcurl-7_3_2-Release`,
`libcurl/7.55.1`), which `main` links after Lua and the NEX/Pia libraries.
It's built with clang 7.0.x `-O3` and the game's global flags. See
`docs/compiler.md`, section "Nintendo SDK middleware", "libcurl 7.55.1".

What's here:

- `include/curl/`, `lib/*.h`, `lib/vtls/*.h`, `lib/vauth/*.h`: curl 7.55.1's
  headers, unchanged (from `curl-7.55.1.tar.xz`).
- `lib/*.c`, `lib/vauth/digest.c`: the 55 curl 7.55.1 TUs that have code in
  the binary, unchanged. The TUs of protocols, auth methods and backends that
  aren't in it (FTP, SASL, NTLM, `curl_threads.c`, the vtls backends ...) are
  left out.
- `lib/curl_config.h`: not from curl. It's the configuration reconstructed from
  the binary, with the evidence for each choice in its comments.
- `zlib/zlib.h`, `zlib/zconf.h`: zlib 1.2.11's headers, unchanged (zlib
  license, in `zlib.h`). The SDK's zlib is 1.2.11, and `HAVE_LIBZ` puts a
  `z_stream` in curl's structs.

`CMakeLists.txt` builds these with curl's defines for a static library
(`HAVE_CONFIG_H`, `BUILDING_LIBCURL`, `CURL_STATICLIB`) and
`lib/curl/include`, `lib/curl/lib` and `lib/curl/zlib` as include
directories (`pkmn_library_settings(lib/curl ...)`).

## What doesn't match

Nintendo changed curl in ways that aren't public, and an unmodified source
tree can't reproduce them. The named functions that don't match have status
`M` in `data/functions.csv`. The reasons:

- **Allocation.** `malloc()`, `free()`, `strdup()` ... in curl's code call
  Nintendo's wrapper functions directly (Sword `0x7101778330`-`0x7101778370`),
  not through the `Curl_cmalloc`/`Curl_cfree`/... pointers that
  `curl_memory.h` declares.
- **`struct Curl_easy`.** Nintendo's `struct UserDefined` has 0x68 bytes
  more than upstream's (three byte fields right after `proxyauth`, and more
  later), so every `data->set` field after `proxyauth`, and everything after
  `set`, has another offset.
- **SSL.** The binary has a TLS backend over `nn::ssl` (`USE_SSL`, which adds
  fields to `struct ssl_connect_data` in `urldata.h`, and an HTTPS handler).
  Upstream 7.55.1 has no such backend, so `USE_SSL` isn't defined here and
  `struct connectdata` has other offsets.
- **Sockets, time, files.** Sockets go through the SDK's `nnsocket*`
  functions (and `SOCKERRNO` through `nnsocketGetLastErrno`), time through
  `nn::os` ticks, the resolver through `nn::nsd::ResolveEx` and
  `nnsocketGetHostByNameWithOptions`, and `fopen`/`fread`/`fclose` through
  stubs that abort.
- **zlib.** `ZLIB_VERSION` is `"1.2.11.f-NINTENDO-SDK-v1"` in the SDK's
  `zlib.h`, and the zlib calls go to YEBIS's zlib in `main`
  (`inflateEnd` is Sword `0x7100593530`).

These files are upstream's, unchanged, so the `// NON_MATCHING: <reason>`
comments that `M` functions get elsewhere can't go in them: this section is
that comment for every `M` function under `lib/curl`. Reproducing Nintendo's
changes (as `lib/lua` does under `#if 0 /* not in Pokémon SwSh */`) is the
next step for them.

The compiled functions that have no original identified in the binary are in
`data/unidentified_functions.csv`: some may be in the binary, changed beyond
recognition.

## License

curl: `COPYING` (MIT/X derivative, see https://curl.se/docs/copyright.html).
zlib headers: the zlib license at the top of `zlib/zlib.h`.
