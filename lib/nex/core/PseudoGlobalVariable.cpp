// Scope: common
// NEX 4.6.8's pseudo-global variables (RTTI: N2nn3nex24PseudoGlobalVariableRootE,
// N2nn3nex20PseudoGlobalVariableIbEE ...): the variables of scalars and
// pointers. Their D2s call the root's (PseudoGlobalVariableRoot.cpp).
#include <nn/nex/PseudoGlobalVariable.h>

namespace nn {
namespace nex {

class DDLDeclarations;
class DynamicRunTimeInterface;

template class PseudoGlobalVariable<bool>;
template class PseudoGlobalVariable<u8>;
template class PseudoGlobalVariable<u16>;
template class PseudoGlobalVariable<u32>;
template class PseudoGlobalVariable<const char*>;
template class PseudoGlobalVariable<DDLDeclarations*>;
template class PseudoGlobalVariable<DynamicRunTimeInterface*>;

}  // namespace nex
}  // namespace nn
