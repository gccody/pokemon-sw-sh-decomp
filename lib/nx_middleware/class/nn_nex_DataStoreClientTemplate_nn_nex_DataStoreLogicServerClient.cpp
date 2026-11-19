// Scope: common
// Small virtual functions of a library class (tools/leafgen.py members): placeholder
// member names vf<slot>, placeholder structs. The class's name is its RTTI's.
// RTTI: N2nn3nex23DataStoreClientTemplateINS0_26DataStoreLogicServerClientEEE
#include <types.h>

namespace nn { namespace nex { class DataStoreLogicServerClient; } }
namespace nn { namespace nex { template <class T0> class DataStoreClientTemplate; } }

namespace nn {
namespace nex {
template <> class DataStoreClientTemplate<nn::nex::DataStoreLogicServerClient> {
public:
    u32 vf45();
};
}  // namespace nex
}  // namespace nn

// 0x7101591b70
u32 nn::nex::DataStoreClientTemplate<nn::nex::DataStoreLogicServerClient>::vf45() {
    return 1;
}
