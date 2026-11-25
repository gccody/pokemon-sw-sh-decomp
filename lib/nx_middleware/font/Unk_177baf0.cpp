// Scope: common
// NintendoWare Font 7.3.2: nn::font::ResFont (RTTI), its constructor,
// destructors and the function that takes a FFNT resource. Placeholder names
// (Unk_177baf0.h).
#include <nn/util.h>
#include <types.h>

#include "Unk_177baf0.h"

const void* Unk_177c800(const void* file, u32 kind);

// Checks a binary file's header: its signature, byte order, version (the same
// major one, a minor one not newer) and block count. Not internal: the
// original's version test was simplified before its constant arguments were
// known (an internal function gets them from IPSCCP first).
inline bool Unk_177baf0_IsValidFile(const Unk_177baf0_File* file, u32 signature, u32 version, u16 minBlocks) {
    if (file->signature != signature) {
        char message[0x100];
        nn::util::SNPrintf(message, sizeof(message), "Signature check failed ('%c%c%c%c' must be '%c%c%c%c').",
                           (file->signature >> 24) & 0xff, (file->signature >> 16) & 0xff,
                           (file->signature >> 8) & 0xff, file->signature & 0xff, (signature >> 24) & 0xff,
                           (signature >> 16) & 0xff, (signature >> 8) & 0xff, signature & 0xff);
        return false;
    }
    if (file->byteOrder != 0xfeff) {
        return false;
    }
    if (((file->version >> 24) & 0xff) != ((version >> 24) & 0xff)) {
        return false;
    }
    if (((file->version >> 16) & 0xff) > ((version >> 16) & 0xff)) {
        return false;
    }
    if (file->fileSize < sizeof(Unk_177baf0_File) + sizeof(Unk_177baf0_Block) * minBlocks) {
        return false;
    }
    if (file->blockCount < minBlocks) {
        return false;
    }
    return true;
}

namespace {

// 'FFNT', and the kinds of the blocks a FFNT file holds.
constexpr u32 kSignature = 0x544e4646;
constexpr u32 kInfo = 0x464e4946;     // FINF
constexpr u32 kKerning = 0x474e524b;  // KRGN
constexpr u32 kWidth = 0x48445743;    // CWDH
constexpr u32 kMap = 0x50414d43;      // CMAP
constexpr u32 kGlyph = 0x504c4754;    // TGLP
constexpr u32 kGlyphGroup = 0x52474c47;  // GLGR

// The FINF block's data, or null if the file has a block of an unknown kind.
Unk_177baf0_Info* FindInfo(void* resource) {
    Unk_177baf0_File* file = static_cast<Unk_177baf0_File*>(resource);
    Unk_177baf0_Info* info = nullptr;
    u8* block = static_cast<u8*>(resource) + file->headerSize;
    for (u32 i = 0; i < file->blockCount; i++) {
        Unk_177baf0_Block* header = reinterpret_cast<Unk_177baf0_Block*>(block);
        switch (header->kind) {
        case kInfo:
            info = reinterpret_cast<Unk_177baf0_Info*>(block + sizeof(Unk_177baf0_Block));
            break;
        case kKerning:
        case kWidth:
        case kMap:
        case kGlyph:
        case kGlyphGroup:
            break;
        default:
            return nullptr;
        }
        block += header->size;
    }
    return info;
}

}  // namespace

namespace nn {
namespace font {

// 0x710177baf0
ResFont::ResFont() {}

// NON_MATCHING: the original's D2 (0x710177bb20) and D0 (0x710177bb40) store
// ResFont's vtable before calling the base's D2. An empty body with nothing to
// destroy lets clang skip that store (CanSkipVTablePointerInitialization), so
// the original's destructor has a body or a member that compiles to nothing.
// 0x710177bb20
ResFont::~ResFont() {}

// 0x710177bb80
void ResFont::vf3(u64 arg) {
    if (field_10 != 0) {
        Unk_177c9e0_call(reinterpret_cast<Unk_177c9e0*>(this), arg);
        Unk_177c0d0_update(reinterpret_cast<Unk_177c0d0*>(this));
    }
}

// 0x710177bbb0
u64 ResFont::Unk_177bbb0(u64 arg) {
    if (field_10 == 0) {
        return 0;
    }
    Unk_177c9e0_call(reinterpret_cast<Unk_177c9e0*>(this), arg);
    return Unk_177c0d0_update(reinterpret_cast<Unk_177c0d0*>(this));
}

// NON_MATCHING: the FINF pointer's and the block counter's zero
// initialisations come out in the other order.
// 0x710177bbf0
bool ResFont::Unk_177bbf0(u64 arg, void* resource, u64 arg3, u64 arg4, u64 arg5) {
    if (field_10 != 0) {
        return false;
    }
    if (!Unk_177baf0_IsValidFile(static_cast<Unk_177baf0_File*>(resource), kSignature, 0x04010000, 2)) {
        return false;
    }
    Unk_177baf0_Info* info = FindInfo(resource);
    field_18 = static_cast<const u8*>(resource);
    if (info == nullptr) {
        return false;
    }
    const void* kerning = Unk_177c800(resource, kKerning);
    Unk_177c0b0_set(reinterpret_cast<Unk_177c0b0*>(this), reinterpret_cast<u64>(resource),
                    reinterpret_cast<u64>(info), reinterpret_cast<u64>(kerning), arg3, arg4, arg5);
    Unk_177c900(arg);
    return true;
}

}  // namespace font
}  // namespace nn
