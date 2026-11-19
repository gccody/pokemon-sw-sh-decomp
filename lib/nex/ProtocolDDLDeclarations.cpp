// Scope: common
// The protocols' DDL declarations (RTTI: N2nn3nex24DataStoreDDLDeclarationsE
// ...): each one's D0 calls DDLDeclarations' D2, which is defined with the
// OnlineCore library's (lib/nex/DDLDeclarations.cpp); the implicit
// destructors' D2 is DDLDeclarations'.
#include <nn/nex/DDLDeclarations.h>
#include <nn/nex/PseudoGlobalVariable.h>

namespace nn {
namespace nex {

// 0x710163a5d0 (slot 2; the class's key function, so its vtable and D0 are here)
void AccountManagementServiceDDLDeclarations::vf2() {}

// 0x710162ee30 (slot 2; the class's key function, so its vtable and D0 are here)
void AuthenticationFoundationDDLDeclarations::vf2() {}

// 0x710158a780 (slot 2; the class's key function, so its vtable and D0 are here)
void DataStoreDDLDeclarations::vf2() {}

// 0x7101630cb0 (slot 2; the class's key function, so its vtable and D0 are here)
void HealthServiceDDLDeclarations::vf2() {}

// 0x71015b40e0 (slot 2; the class's key function, so its vtable and D0 are here)
void MatchMakingServiceDDLDeclarations::vf2() {}

// 0x71015a3960 (slot 2; the class's key function, so its vtable and D0 are here)
void MatchmakeExtensionDDLDeclarations::vf2() {}

// 0x71015af2d0 (slot 2; the class's key function, so its vtable and D0 are here)
void MatchmakeRefereeDDLDeclarations::vf2() {}

// 0x71015b58c0 (slot 2; the class's key function, so its vtable and D0 are here)
void NATTraversalDDLDeclarations::vf2() {}

// 0x7101570e40 (slot 2; the class's key function, so its vtable and D0 are here)
void NintendoAuthenticationDDLDeclarations::vf2() {}

// 0x7101632860 (slot 2; the class's key function, so its vtable and D0 are here)
void NintendoProtocolFoundationDDLDeclarations::vf2() {}

// 0x7101634130 (slot 2; the class's key function, so its vtable and D0 are here)
void ProtocolFoundationDDLDeclarations::vf2() {}

// 0x7101635d80 (slot 2; the class's key function, so its vtable and D0 are here)
void SecureConnectionServiceDDLDeclarations::vf2() {}

// 0x710164e5f0 (slot 2; the class's key function, so its vtable and D0 are here)
void SubscriptionDDLDeclarations::vf2() {}

// 0x7101650a60 (slot 2; the class's key function, so its vtable and D0 are here)
void UtilityDDLDeclarations::vf2() {}

// Their pseudo-global variables.
template class PseudoGlobalVariable<AccountManagementServiceDDLDeclarations>;
template class PseudoGlobalVariable<AuthenticationFoundationDDLDeclarations>;
template class PseudoGlobalVariable<DataStoreDDLDeclarations>;
template class PseudoGlobalVariable<HealthServiceDDLDeclarations>;
template class PseudoGlobalVariable<MatchMakingServiceDDLDeclarations>;
template class PseudoGlobalVariable<MatchmakeExtensionDDLDeclarations>;
template class PseudoGlobalVariable<MatchmakeRefereeDDLDeclarations>;
template class PseudoGlobalVariable<NATTraversalDDLDeclarations>;
template class PseudoGlobalVariable<NintendoAuthenticationDDLDeclarations>;
template class PseudoGlobalVariable<NintendoProtocolFoundationDDLDeclarations>;
template class PseudoGlobalVariable<ProtocolFoundationDDLDeclarations>;
template class PseudoGlobalVariable<SecureConnectionServiceDDLDeclarations>;
template class PseudoGlobalVariable<SubscriptionDDLDeclarations>;
template class PseudoGlobalVariable<UtilityDDLDeclarations>;

}  // namespace nex
}  // namespace nn
