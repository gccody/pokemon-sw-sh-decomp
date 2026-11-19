# lib/nex: NEX 4.6.8

Nintendo's online library (`SDK MW+Nintendo+NEX-4_6_8`, the `NEX_DS-4_6_8`
tag), the first library of the `middleware` area of `data/areas.csv`. Its
source isn't public, so nothing here is upstream code: it is written from the
executable. Class names are NEX's own, from its RTTI (`N2nn3nex10ByteStreamE`
is `nn::nex::ByteStream`); everything the executable doesn't name keeps a
placeholder (`Unk_<addr>` functions and structs, `vf<slot>` virtual
functions, `m_`/`field_<offset>` members).

How it was built (clang 7.0.x `-O3`, the game's flags but strict aliasing,
libc++ 7.0.1's containers) is in `docs/compiler.md`, section "NEX 4.6.8", and
the `pkmn_library_settings(lib/nex ...)` entry of `CMakeLists.txt`.

## Layout

- `include/nn/nex/`: the reconstructed headers, only what the code here uses.
  `RootObject` (NEX's allocator through `operator new`/`delete`), `String`,
  `ByteStream`, `Buffer`, `Message`, `qVector`/`qList` (libc++'s containers
  with `MemAllocator`), the inline reads of the stream functions, the
  per-thread instance lookup of the protocol calls (`InstanceTable.h`) and
  what the calls use (`Call.h`).
- `DataStoreDDLDeclarations.cpp`: the destructors of
  `_DDL_DataStoreKeyValue` and `DataStoreKeyValue`, written by hand.
- `ddl/Streams.h`, `ddl/Streams.cpp`: the DDL stream functions, written by
  `tools/nexddl.py streams --write lib/nex/ddl/Streams.cpp`. Each writes
  (`Unk_<addr>_write`) or reads (`Unk_<addr>_read`) one structure to or from
  a `ByteStream`: a version and a length unless the stream leaves them out,
  then the fields. The structures are placeholders named after their
  function; which DDL class each is isn't known.
- `ddl/Calls.cpp`: the protocol clients' calls, written by
  `tools/nexddl.py calls --write lib/nex/ddl/Calls.cpp`. Each builds a
  `Message` under the core's lock (the protocol's and the method's IDs, then
  the inputs, each followed by a check of the message's error flag),
  registers where the results go and the method's result handler, and sends
  the message, after releasing the lock if the protocol defers it.

The generated files aren't edited by hand: change the generator (or the
headers) and write them again. `tools/nexddl.py names <objects>` prints the
`Name,Sword,Shield` CSV of the placeholder functions an object defines, for
`tools/funcs.py name --from-file`. Functions the generator recognizes but
that don't match are listed in `NOT_MATCHING` and `CALLS_NOT_MATCHING` with
the reason, and left out.

## Notes on the reconstruction

- The stream functions write the header in the function itself: a helper
  object's inlined constructor and destructor order the temporaries on the
  stack differently. A container's count is a local of an inlined helper
  (`WriteContainer`), whose stack slot comes first.
- A call's failed input ends the call with `Unk_15c9360(ctx,
  Unk_15bbc10(0x8001000a))`: the result is passed by value, so each such
  temporary keeps its own stack slot (clang 7 gives an argument's temporary
  no lifetime markers), as in the original.
- The calls return inside the lock's scope when they send the message there,
  and after it when the protocol defers sending: the two paths through the
  lock's destructor are the original's.
