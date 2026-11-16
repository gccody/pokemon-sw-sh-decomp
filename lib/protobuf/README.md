# lib/protobuf: Protocol Buffers 3.0.0

Google's protobuf runtime, which Game Freak's network library vendors
(`RomBuild/program/lib/gflnet3/external/include/google/protobuf/*.cc` in the
`__FILE__` literals). Every generated message's `AddDescriptors` calls
`VerifyVersion` with `3000000`, so it's 3.0.0. It's built with the game's clang
7.0.x and global flags. See `docs/compiler.md`, section "Protocol Buffers
3.0.0".

What's here, from the `v3.0.0` tag's `src/`, unchanged (BSD-3-Clause, `LICENSE`):

- `google/protobuf/**/*.cc`: the 30 TUs of `libprotobuf` that have code in
  `main`. The rest of upstream's library (`arena.cc`, the well-known types'
  `*.pb.cc` other than `descriptor.pb.cc`, `compiler/`, `util/`,
  `io/printer.cc`, `io/gzip_stream.cc`, `stubs/bytestream.cc`, ...) has none:
  the linker dropped it.
- `google/protobuf/**/*.h`: the headers those TUs read.

The layout is the original's: the TUs sit next to their headers, and
`lib/protobuf` is the include directory (`-I`), as `external/include` was.
`data/source_paths.csv` maps the `__FILE__` literals onto it.

`CMakeLists.txt` builds them with `NDEBUG`, `HAVE_PTHREAD` and
`GOOGLE_PROTOBUF_NO_RTTI` (`pkmn_library_settings(lib/protobuf ...)`).
libc++ 7.0.1 (`include/libcxx`) supplies the standard library.
