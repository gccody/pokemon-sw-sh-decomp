// Scope: common
// SiSDK3::ISiIOBinaryArchive, SiSDK3::ISiIOBinaryArchive::ChunkHandler: their functions, so far the reference counts
// their header defines.
#define UNK_ISIIO_BINARYARCHIVE_IMPL
#include <yebis/sisdk/3.0/SDK/Core/Include/SiIO/SiIO_BinaryArchive.h>

// Their destructors (inline, in the header; the deleting ones of these
// abstract classes are traps).
// 0x710057a440 = _ZN6SiSDK318ISiIOBinaryArchive12ChunkHandlerD2Ev
// 0x710057a570 = _ZN6SiSDK318ISiIOBinaryArchive12ChunkHandlerD0Ev
// 0x710057c680 = _ZN6SiSDK318ISiIOBinaryArchiveD2Ev
// 0x710057c6a0 = _ZN6SiSDK318ISiIOBinaryArchiveD0Ev
