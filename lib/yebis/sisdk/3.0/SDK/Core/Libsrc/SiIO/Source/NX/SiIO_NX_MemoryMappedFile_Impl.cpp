// Scope: common
// SiSDK3::SiIONXMemoryMappedFile: a file read whole into memory (the small
// accessors are lib/yebis/class's).
#define UNK_SIIO_NX_MEMORYMAPPEDFILE_IMPL
#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiIO/Source/NX/SiIO_NX_MemoryMappedFile_Impl.h>

#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/Unk_Alloc.h>
#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/Unk_StringFuncs.h>

// 0x7100582d60, 0x7100582d70: fopen and fclose
FILE* Unk_582d60(const char* path, const char* mode);
void Unk_582d70(FILE* file);
// 0x71004e4400: a path's file name
SiSDK3::SiString<char> Unk_4e4400(SiSDK3::SiString<char>* path, bool);

namespace SiSDK3 {

// 0x710058b8d0
SiIONXMemoryMappedFile::SiIONXMemoryMappedFile(ISiAllocator* pAllocator)
    : field_8(pAllocator), field_18(nullptr), field_20(0), field_28(pAllocator), field_58(pAllocator),
      field_88(nullptr) {}

// 0x710058b980 (D2), 0x710058ba80 (D0)
SiIONXMemoryMappedFile::~SiIONXMemoryMappedFile() {
    SiIONXMemoryMappedFile::vf6();
}

// 0x710058bab0
// NON_MATCHING: 2 instructions: the tail's two tests are in the other order.
// The original branches on the read's comparison first (`cset w0, eq; b.ne
// ret; tbz w19, #3, ret; mov w0, #1`). Here SimplifyCFG joins the two tests
// into one `and i1` and Reassociate puts the operand of lower rank first: the
// mode's test (computed from an argument) ranks below the read's (computed
// from a call), whatever the source order. The mode's test must stay the one
// the mode string's 'r' test uses (two uses keep that branch's polarity and so
// the blocks' layout at the top); a separate `(mode & 8) != 8` gives the
// tail's order but flips the top. With the mode string's scope ending before
// `return true` the test stays at all (without it clang folds the two results
// into one; 38 instructions off). Tried: the tests split, nested, joined
// either way, `!(a == b)`, a goto, the read as int/u8/size_t.
// (Round 14: the `and` is already there after the first InstCombine: the
// scope's returns become selects of the cleanup's destination in the first
// SimplifyCFG, whatever form the tests have; Reassociate then puts the mode's
// test first. Also tried: the mode's test as a bool local shared with the 'r'
// test, `return false` for the failed read, a u8 result.)
bool SiIONXMemoryMappedFile::vf5(const char* path, u32 mode) {
    vf6();
    {
        char modeString[16];
        u32 length = 0;
        if ((mode & 8) == 8) {
            modeString[length] = 'r';
            length++;
        }
        if ((mode & 1) == 1) {
            modeString[length] = 'b';
            length++;
        }
        if ((mode & 2) == 2) {
            modeString[length] = 't';
            length++;
        }
        modeString[length] = 0;
        field_18 = Unk_582d60(path, modeString);
        if (field_18 == nullptr) {
            return false;
        }
        Unk_StringAssign(&field_28, path);
        field_58 = Unk_4e4400(&field_28, true);
        s64 position = ftell(field_18);
        fseek(field_18, 0, SEEK_END);
        s64 size = ftell(field_18);
        fseek(field_18, position, SEEK_SET);
        field_20 = size;
        if (size != 0) {
    #line 144
            field_88 = UNK_ALLOC(Unk_Allocator(), size);
            if (field_88 == nullptr) {
                field_20 = 0;
                Unk_582d70(field_18);
                return false;
            }
            bool read = fread(field_88, field_20, 1, field_18) == 1;
            if (!(read && (mode & 8) == 8)) {
                return read;
            }
        }
    }
    return true;
}

// 0x710058bc70
void SiIONXMemoryMappedFile::vf6() {
    if (field_88 != nullptr) {
#line 179
        UNK_FREE(Unk_Allocator(), field_88);
        field_20 = 0;
    }
    if (field_18 != nullptr) {
        Unk_582d70(field_18);
        field_18 = nullptr;
    }
    field_20 = 0;
}

}  // namespace SiSDK3
