// Scope: common
// Small virtual functions of a library class (tools/leafgen.py members): placeholder
// member names vf<slot>, placeholder structs. The class's name is its RTTI's.
// RTTI: N2nn3nex13MethodCallJobINS0_19CallContextRegisterEiNS0_11PeriodicJobEEE
#include <types.h>

struct Unk_15cedf0 {
    u8 _0[0x64];
    u32 field_64;
};
PKMN_OFFSET_ASSERT(Unk_15cedf0, field_64, 0x64);

namespace nn { namespace nex { class CallContextRegister; } }
namespace nn { namespace nex { class PeriodicJob; } }
namespace nn { namespace nex { template <class T0, class T1, class T2> class MethodCallJob; } }

namespace nn {
namespace nex {
template <> class MethodCallJob<nn::nex::CallContextRegister, int, nn::nex::PeriodicJob> {
public:
    bool vf8();
};
}  // namespace nex
}  // namespace nn

// 0x71015cedf0
bool nn::nex::MethodCallJob<nn::nex::CallContextRegister, int, nn::nex::PeriodicJob>::vf8() {
    const Unk_15cedf0* self = reinterpret_cast<const Unk_15cedf0*>(this);
    return self->field_64 == 0;
}
