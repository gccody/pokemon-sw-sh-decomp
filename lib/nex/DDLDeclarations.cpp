// Scope: common
// NEX 4.6.8's DDLDeclarations and the OnlineCore library's declarations
// (RTTI: N2nn3nex15DDLDeclarationsE ...). Their D0s inline the empty D2.
#include <nn/nex/DDLDeclarations.h>
#include <nn/nex/PseudoGlobalVariable.h>

namespace nn {
namespace nex {

// 0x710162ce30
DDLDeclarations::DDLDeclarations(bool b) : field_18(b) {
    field_c = 0;
    field_8 = 0;
    field_10 = 0;
}

// 0x710162d880 (D2), 0x710162ce60 (D0)
DDLDeclarations::~DDLDeclarations() {}

// 0x710162cd20 (slot 2; the class's key function, so its vtable and D0 are here)
void OnlineCoreDDLDeclarations::vf2() {}

// 0x710162cd80 (slot 2; the class's key function, so its vtable and D0 are here)
void STLExtDDLDeclarations::vf2() {}

// Their pseudo-global variables (the D2s inline DDLDeclarations').
template class PseudoGlobalVariable<OnlineCoreDDLDeclarations>;
template class PseudoGlobalVariable<STLExtDDLDeclarations>;

}  // namespace nex
}  // namespace nn
