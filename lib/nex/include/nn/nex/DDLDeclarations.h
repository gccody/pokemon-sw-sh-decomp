#pragma once
#include <nn/nex/RootObject.h>

namespace nn {
namespace nex {

// N2nn3nex15DDLDeclarationsE: the base of each protocol's DDL declarations
// (RTTI: N2nn3nex<n><Protocol>DDLDeclarationsE, derived from it). Its
// destructor is empty; slot 2 is pure.
class DDLDeclarations : public RootObject {
public:
    explicit DDLDeclarations(bool b);
    virtual ~DDLDeclarations();
    virtual void vf2() = 0;

    u32 field_8;
    u8 field_c;
    u64 field_10;
    bool field_18;
};
PKMN_SIZE_ASSERT(DDLDeclarations, 0x20);

class AccountManagementServiceDDLDeclarations : public DDLDeclarations {
public:
    void vf2() override;
};

class AuthenticationFoundationDDLDeclarations : public DDLDeclarations {
public:
    void vf2() override;
};

class DataStoreDDLDeclarations : public DDLDeclarations {
public:
    void vf2() override;
};

class HealthServiceDDLDeclarations : public DDLDeclarations {
public:
    void vf2() override;
};

class MatchMakingServiceDDLDeclarations : public DDLDeclarations {
public:
    void vf2() override;
};

class MatchmakeExtensionDDLDeclarations : public DDLDeclarations {
public:
    void vf2() override;
};

class MatchmakeRefereeDDLDeclarations : public DDLDeclarations {
public:
    void vf2() override;
};

class NATTraversalDDLDeclarations : public DDLDeclarations {
public:
    void vf2() override;
};

class NintendoAuthenticationDDLDeclarations : public DDLDeclarations {
public:
    void vf2() override;
};

class NintendoProtocolFoundationDDLDeclarations : public DDLDeclarations {
public:
    void vf2() override;
};

class OnlineCoreDDLDeclarations : public DDLDeclarations {
public:
    void vf2() override;
};

class ProtocolFoundationDDLDeclarations : public DDLDeclarations {
public:
    void vf2() override;
};

class STLExtDDLDeclarations : public DDLDeclarations {
public:
    void vf2() override;
};

class SecureConnectionServiceDDLDeclarations : public DDLDeclarations {
public:
    void vf2() override;
};

class SubscriptionDDLDeclarations : public DDLDeclarations {
public:
    void vf2() override;
};

class UtilityDDLDeclarations : public DDLDeclarations {
public:
    void vf2() override;
};

}  // namespace nex
}  // namespace nn
