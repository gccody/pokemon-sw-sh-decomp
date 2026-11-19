// Scope: common
// NEX 4.6.8's InetAddress (RTTI: N2nn3nex11InetAddressE): a socket address.
#include <nn/nex/RootObject.h>
#include <string.h>

namespace nn {
namespace nex {

class InetAddress : public RootObject {
public:
    InetAddress();
    virtual ~InetAddress();
    void Unk_1618170();

    u8 m_sockaddr[16];  // a sockaddr_in: length, family, port, address
    u8 _18[0x70];
    u32 field_88;
};
PKMN_OFFSET_ASSERT(InetAddress, field_88, 0x88);

// 0x7101618170
void InetAddress::Unk_1618170() {
    memset(m_sockaddr, 0, sizeof(m_sockaddr));
    field_88 = 0;
    m_sockaddr[1] = 2;  // AF_INET
}

// 0x7101618120
InetAddress::InetAddress() {
    Unk_1618170();
}

// 0x71016184e0 (D2), 0x71016184f0 (D0)
InetAddress::~InetAddress() {}

}  // namespace nex
}  // namespace nn
