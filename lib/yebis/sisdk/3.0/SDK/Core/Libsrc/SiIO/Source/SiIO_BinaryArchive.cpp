// Scope: common
// SiSDK3::ISiIOBinaryArchive, SiSDK3::ISiIOBinaryArchive::ChunkHandler: their functions, so far the reference counts
// their header defines.
#define UNK_ISIIO_BINARYARCHIVE_IMPL
#include <yebis/sisdk/3.0/SDK/Core/Include/SiIO/SiIO_BinaryArchive.h>

// Their destructors (the archive's is inline, in the header; the deleting
// ones of these abstract classes are traps).
// 0x710057a570 = _ZN6SiSDK318ISiIOBinaryArchive12ChunkHandlerD0Ev
// 0x710057c680 = _ZN6SiSDK318ISiIOBinaryArchiveD2Ev
// 0x710057c6a0 = _ZN6SiSDK318ISiIOBinaryArchiveD0Ev

#include <string.h>

#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/SiCore_String.h>

// 0x71004c9090: formats a string
void Unk_4c9090(SiSDK3::SiString<char>* self, const char* format, ...);

namespace SiSDK3 {

// 0x710057a3a0
ISiIOBinaryArchive::ChunkHandler::ChunkHandler(ISiAllocator* pAllocator)
    : field_8(pAllocator), field_18(), field_88(pAllocator), field_b0(0) {
    memset(&field_28, 0, sizeof(field_28));
    field_28.field_20 = sizeof(field_28);
    field_28.field_10.field_0 = 2;
    field_28.field_10.field_4 = 1;
    field_28.field_10.field_8 = 0;
    field_28.field_10.field_c = 0;
}

// 0x710057a440 = _ZN6SiSDK318ISiIOBinaryArchive12ChunkHandlerD2Ev: releases
// the chunks inside it
ISiIOBinaryArchive::ChunkHandler::~ChunkHandler() {
    while (field_88.m_count != 0) {
        ChunkHandler* handler = field_88.m_pHead;
        if (handler != nullptr) {
            field_88.Remove(handler);
            handler->vf3();
        }
    }
}

// 0x710057a580
bool ISiIOBinaryArchive::ChunkHandler::vf7(ISiIOBinaryArchive* archive, Unk_ChunkHeader* header,
                                           SiString<char>* error) {
    if (field_28.field_10.field_0 == header->field_10.field_0 && field_28.field_10.field_4 == header->field_10.field_4 &&
        field_28.field_10.field_8 == header->field_10.field_8 && field_28.field_10.field_c == header->field_10.field_c) {
        return true;
    }
    Unk_4c9090(error,
               "SiIOBinaryArchive::ChunkHandler::ValidateChunkHeader --> <%s> chunk version mismatch : File = ( %d, %d, "
               "%d, %d ), Runtime = ( %d, %d, %d, %d )",
               vf5(), header->field_10.field_0, header->field_10.field_4, header->field_10.field_8,
               header->field_10.field_c, field_28.field_10.field_0, field_28.field_10.field_4,
               field_28.field_10.field_8, field_28.field_10.field_c);
    return false;
}

}  // namespace SiSDK3
