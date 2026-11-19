// Scope: common
// NEX 4.6.8's PseudoGlobalVariableRoot (RTTI: N2nn3nex24PseudoGlobalVariableRootE):
// its destructor, which the variables' D2s call (it isn't inlined: another TU).
#include <nn/nex/PseudoGlobalVariable.h>

namespace nn {
namespace nex {

// 0x71015cefa0 (D2), 0x71015cefb0 (D0)
PseudoGlobalVariableRoot::~PseudoGlobalVariableRoot() {}

}  // namespace nex
}  // namespace nn
