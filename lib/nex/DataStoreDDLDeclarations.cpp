// Scope: common
// NEX 4.6.8's DataStore DDL data classes (RTTI: N2nn3nex22_DDL_DataStoreKeyValueE ...).
#include <nn/nex/String.h>

namespace nn {
namespace nex {

class _DDL_DataStoreKeyValue : public RootObject {
public:
    virtual ~_DDL_DataStoreKeyValue();

    u8 _8[0x8];
    String m_key;
    String m_value;
};
PKMN_SIZE_ASSERT(_DDL_DataStoreKeyValue, 0x60);

class DataStoreKeyValue : public _DDL_DataStoreKeyValue {
public:
    virtual ~DataStoreKeyValue();
};

// 0x71015922b0 (D2), 0x7101592300 (D0)
_DDL_DataStoreKeyValue::~_DDL_DataStoreKeyValue() {}

// 0x7101592260 (D0; the D1 is _DDL_DataStoreKeyValue's D2)
DataStoreKeyValue::~DataStoreKeyValue() {}

}  // namespace nex
}  // namespace nn
