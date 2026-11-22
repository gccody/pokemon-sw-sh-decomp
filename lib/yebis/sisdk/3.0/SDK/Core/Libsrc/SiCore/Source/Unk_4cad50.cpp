// Scope: common
// SiCore's initialisation and exit (placeholder file and names: the functions
// of a translation unit of their own, which lock around the kernel's), with
// the translation unit's static objects.
#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/SiCore_CriticalSection.h>
#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/SiCore_Reflection.h>
#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiCore/Source/SiCore_Kernel_Impl.h>

// 0x71004bf730: the kernel
SiSDK3::SiKernel* Unk_4bf730();

// 0x710276ccc8
static SiSDK3::SiReflectionPropertyHandle Unk_276ccc8;

// 0x710276cc98: what the two functions lock
SiSDK3::SiCoreCriticalSection Unk_276cc98;

// 0x710276ccc0: a number that the static initialiser sets to 0 (placeholder
// type). It is next to the handle, so it is the translation unit's own, and
// nothing in the executable reads or changes it: what did was dropped by the
// linker. Unk_276ccc0_add stands for that (data/absent_functions.csv): the
// compiler only keeps the variable and the initialiser's store if something
// changes it.
struct Unk_276ccc0_t {
    Unk_276ccc0_t() : field_0(0) {}

    s32 field_0;
};
static Unk_276ccc0_t Unk_276ccc0;

s32 Unk_276ccc0_add() {
    return ++Unk_276ccc0.field_0;
}

// 0x71004cad50
bool Unk_4cad50(SiSDK3::ISiAllocator* pAllocator) {
    Unk_4c87b0 lock(&Unk_276cc98, true);
    return Unk_4bf730()->Unk_4bffc0(pAllocator);
}

// 0x71004cadb0
void Unk_4cadb0() {
    Unk_4c87b0 lock(&Unk_276cc98, true);
    Unk_4bf730()->Unk_4c04e0();
}

// 0x71004cadf0: _GLOBAL__sub_I_Unk_4cad50.cpp
