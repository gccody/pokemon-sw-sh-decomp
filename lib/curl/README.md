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
  aren't upstream's: they're the backend's API setup and its functions.
- `include/curl/curl.h`, `lib/url.c`, `lib/getinfo.c`: Nintendo's options
  (`CURLOPT_PROXYAUTOCONFIG` and eight `CURLOPT_Unk_<value>`) and one more
  `CURLINFO`; `CURLOPT_URL`'s host from `nn::nsd` and `create_conn`'s proxy
  from `nn::nifm` (`lib/curl_nnnet.h`, not upstream's).
- `nnsocket/`: not upstream's. It stands in for the SDK's socket headers
  (BSD-style `struct sockaddr`, BSD `SOL_SOCKET`/`SO_*` values, the
  `nnsocket*` functions), in place of musl's. `lib/curl_setup_once.h`,
  `lib/select.h` and `lib/nonblock.c` route `sclose`, `sfcntl`, `poll` and
  `SOCKERRNO` to the SDK.
- `lib/curl_nnstdio.h` (not upstream's), `lib/curl_printf.h`,
  `lib/timeval.c`, `lib/mprintf.c`, `lib/hostip.h`, `lib/hostip4.c`,
  `lib/asyn-thread.c`: curl's `time()`, stdio, `curlx_tvnow` and
  `gethostbyname` go to Nintendo's functions.
- `lib/curl_threads.h`, `lib/curl_nnos.h` (not upstream's),
  `lib/asyn-thread.c`: the resolver's threads and mutexes are `nn::os`'s,
  with three options of the SDK's resolver per lookup.
- `lib/sendf.c`, `lib/cookie.c`, `lib/select.c`, `lib/progress.c`,
  `lib/http.c`: smaller changes (`showit()` writes nothing, one `fclose`
  that's the SDK's, `Curl_wait_ms` inlined), and two fixes from later curl
  versions, 7.58.0's and 7.61.1's.
- `nintendo/`: not upstream's. Nintendo's own TUs, reconstructed (the memory
  functions, the SDK tag function, the time and stdio functions, the
  `nn::nsd` and `nn::nifm` glue, the resolver threads). Neither their names
  nor the files' names are known, so they're `Unk_<addr>` (Sword
  addresses).

All 395 functions of the libcurl area match, in both games. The last three
were Nintendo's (the backend's connect and close, the resolver's thread
creation): the section in `docs/compiler.md` ("The last three") has what
made them match.

The compiled functions that have no original identified in the binary are in
`data/unidentified_functions.csv`: some may be in the binary, changed beyond
recognition, and the rest were dropped by the linker.

## License

curl: `COPYING` (MIT/X derivative, see https://curl.se/docs/copyright.html).
zlib headers: the zlib license at the top of `zlib/zlib.h`.
